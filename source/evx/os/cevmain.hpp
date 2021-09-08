///////////////////////////////////////////////////////////////////////
//   File: cevmain.hpp
//
// Author: $author$
//   Date: 4/3/2007
//
//    $Id$
///////////////////////////////////////////////////////////////////////

#ifndef _CEVMAIN_HPP
#define _CEVMAIN_HPP

#include "evmain.hpp"
#include "cevmainarg.hpp"
#include "cevstring.hpp"
#include "cevcharfile.hpp"
#include "cevbase.hpp"

///////////////////////////////////////////////////////////////////////
//  Class: CEvMain
//
// Author: $author$
//   Date: 4/3/2007
///////////////////////////////////////////////////////////////////////
class CEvMain
: virtual public EvMain,
  public CEvBase
{
public:
    typedef EvMain CImplements;
    typedef CEvBase CExtends;
    typedef CEvMain CDerives;

	static CEvMain* m_main;
	CEvMain* m_oldMain;

    bool m_didMainArg;
    bool m_didMain;
    int m_mainArgn;
    int m_mainArgs;

    CEvString m_helpProduct;
    CEvString m_helpVersion;
    CEvString m_helpArgn;

    CEvCharFile m_stdIn;
    CEvCharFile m_stdOut;
    CEvCharFile m_stdErr;

    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvMain
    //
    //       Author: $author$
    //         Date: 4/3/2007
    ///////////////////////////////////////////////////////////////////////
	CEvMain() 
	: m_oldMain(m_main),
      m_didMainArg(false),
      m_didMain(false),
      m_mainArgn(0),
      m_mainArgs(0)
    {
		m_main = this;
    }
    ///////////////////////////////////////////////////////////////////////
    // Destructor: ~CEvMain
    //
    //      Author: $author$
    //        Date: 4/3/2007
    ///////////////////////////////////////////////////////////////////////
    virtual ~CEvMain()
    {
		if (this == m_main)
			m_main = m_oldMain;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: Main
    //
    //    Author: $author$
    //      Date: 4/3/2007
    ///////////////////////////////////////////////////////////////////////
    virtual int Main
    (int argc, const char** argv, const char** env) 
    {
        int err = 1;
        int args;
        EvError error;
        FILE* stdFile;
        
        if (!(error = m_stdIn.Attach(stdin)))
        {
            if (!(error = m_stdOut.Attach(stdout)))
            {
                if (!(error = m_stdErr.Attach(stderr)))
                {
                    if (0 <= (args = MainArgs(argc, argv, env)))
                        err = Run(argc, argv, env);

                    m_stdErr.Detach(stdFile);
                }
                m_stdOut.Detach(stdFile);
            }
            m_stdIn.Detach(stdFile);
        }
        return err;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: Run
    //
    //    Author: $author$
    //      Date: 4/3/2007
    ///////////////////////////////////////////////////////////////////////
    virtual int Run
    (int argc, const char** argv, const char** env) 
    {
        int err = 0;
        return err;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: Help
    //
    //    Author: $author$
    //      Date: 4/3/2007
    ///////////////////////////////////////////////////////////////////////
    virtual int Help
    (int argc, const char** argv, const char** env) 
    {
        int err = 0;
        int argn;
        int length;
        LONG llength;
        const char* chars;
        const char* next;
        const char* name;
        EvMainArg *mainArg;
        CEvMainArgItem* mainArgItem;

        if ((chars = GetHelpProduct(llength)) && (0 < llength))
        {
            printf("%s\n", chars);

            if ((chars = GetHelpVersion(llength)) && (0 < llength))
                printf("%s\n", chars);

            printf("\n");
        }
        printf("usage: %s", GetUsageName(argv[0]));

        if ((mainArg = CEvMainArg::m_list.GetFirstArg(mainArgItem)))
        do
        {
            printf(" [");
            if ((chars = mainArg->GetLongNamei(length)) && (0 < length))
            {
                printf("--%s", chars);
                if ((chars = mainArg->GetShortNamei(length)) && (0 < length))
                    printf("(-%s)", chars);
            }
            else if ((chars = mainArg->GetShortNamei(length)) && (0 < length))
                    printf("-%s", chars);

            if ((chars = mainArg->GetFirstParameter(next, length)) && (0 < length))
            do
            {
                if ((name = mainArg->GetParameterName(chars, length)) && (0 < length))
                    printf(" %s", name);
            }
            while ((chars = mainArg->GetNextParameter(next, length)) && (0 < length));
            printf("]");
        }
        while ((mainArg = CEvMainArg::m_list.GetNextArg(mainArgItem)));

        for (argn = 1; (chars = GetHelpArgn(argn)); argn++)
        {
            if ((name = strchr(chars, ':')))
            {
                m_helpArgn.Assign(chars, (LONG)(name-chars));
                name = m_helpArgn.Chars(llength);
            }
            else name = chars;
            printf(" %s", name);
        }
        printf("\n");
        return err;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: MainArgs
    //
    //   Author: $author$
    //     Date: 4/4/2007
    ///////////////////////////////////////////////////////////////////////
    virtual int MainArgs
    (int argc, const char** argv, const char** env) 
    {
        int argn, argon, args=0;
        const char *arg;

        for (argon = argn = 0; argn < argc; argon = ++argn)
        {
            if (!(arg = argv[argn]))
                return -EV_ERROR_NULL_PARAMETER;

            if ((argn = MainArg
                (args, argn, arg, argc, argv, env)) < argon)
            {
                if (argn >= 0)
                    return -EV_ERROR_INVALID_RETURN;

                return argn;
            }
            ++args;
        }
        return args;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: MainArg
    //
    //   Author: $author$
    //     Date: 4/4/2007
    ///////////////////////////////////////////////////////////////////////
    virtual int MainArg
    (int args, int argn, const char *arg, 
     int argc, const char** argv, const char** env) 
    {
        char equal;
        const char* found;

        if (1 > argn)
            return MainArg0
            (args, argn, arg, argc, argv, env);

        switch(arg[0])
        {
        case '-':
            return MainArgSwitch
            (args, argn, arg+1, argc, argv, env);
        }

        equal = '=';

        if ((found = strchr(arg, equal)))
            return MainArgEqual
            (args, argn, found, argc, argv, env);

        argn = MainArgn
        (args, argn, arg, argc, argv, env);
        return argn;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: MainArgSwitch
    //
    //   Author: $author$
    //     Date: 4/4/2007
    ///////////////////////////////////////////////////////////////////////
    virtual int MainArgSwitch
    (int args, int argn, const char *arg, 
     int argc, const char** argv, const char** env) 
    {
        switch(arg[0])
        {
        case '-':
            return MainArgLong
            (args, argn, arg+1, argc, argv, env);
        }

        argn = MainArgShort
        (args, argn, arg, argc, argv, env);
        return argn;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: MainArg0
    //
    //   Author: $author$
    //     Date: 4/4/2007
    ///////////////////////////////////////////////////////////////////////
    virtual int MainArg0
    (int args, int argn, const char *arg, 
     int argc, const char** argv, const char** env) 
    {
        return argn;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: MainArgn
    //
    //   Author: $author$
    //     Date: 4/4/2007
    ///////////////////////////////////////////////////////////////////////
    virtual int MainArgn
    (int args, int argn, const char *arg, 
     int argc, const char** argv, const char** env) 
    {
        return argn;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: MainArgShort
    //
    //   Author: $author$
    //     Date: 4/4/2007
    ///////////////////////////////////////////////////////////////////////
    virtual int MainArgShort
    (int args, int argn, const char *arg, 
     int argc, const char** argv, const char** env) 
    {
        int argon = argn;
        EvMainArg* mainArg;
        char argChar;
        const char* nameChars;
        LONG nameLength;
        CEvString name;

        name.Assign(arg, 1);

        if ((nameChars = name.Chars(nameLength)))
        {
            if (!(argChar = *(++arg)))
                arg = 0;
            if ((mainArg = CEvMainArg::m_list.FindFirstArgByShortName(nameChars)))
            if (argon <= (argn = mainArg->MainArg(args, argn, arg, argc, argv, env)))
                SetDidMainArg();
        }
        return argn;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: MainArgLong
    //
    //   Author: $author$
    //     Date: 4/4/2007
    ///////////////////////////////////////////////////////////////////////
    virtual int MainArgLong
    (int args, int argn, const char *arg, 
     int argc, const char** argv, const char** env) 
    {
        int argon = argn;
        EvMainArg* mainArg;
        const char* nameChars;
        LONG nameLength;
        CEvString name;

        name.Assign(arg);

        if ((nameChars = name.Chars(nameLength)))
        {
            arg = 0;
            if ((mainArg = CEvMainArg::m_list.FindFirstArgByLongName(nameChars)))
            if (argon <= (argn = mainArg->MainArg(args, argn, arg, argc, argv, env)))
                SetDidMainArg();
        }
        return argn;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: MainArgEqual
    //
    //   Author: $author$
    //     Date: 4/4/2007
    ///////////////////////////////////////////////////////////////////////
    virtual int MainArgEqual
    (int args, int argn, const char *arg, 
     int argc, const char** argv, const char** env) 
    {
        return argn;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: SetDidMainArg
    //
    //   Author: $author$
    //     Date: 4/4/2007
    ///////////////////////////////////////////////////////////////////////
    virtual bool SetDidMainArg(bool did=true) 
    {
        return m_didMainArg = did;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: GetDidMainArg
    //
    //   Author: $author$
    //     Date: 4/4/2007
    ///////////////////////////////////////////////////////////////////////
    virtual bool GetDidMainArg(bool did=true) const 
    {
        return m_didMainArg;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: SetDidMain
    //
    //   Author: $author$
    //     Date: 4/4/2007
    ///////////////////////////////////////////////////////////////////////
    virtual bool SetDidMain(bool did=true) 
    {
        return m_didMain = did;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: GetDidMain
    //
    //   Author: $author$
    //     Date: 4/4/2007
    ///////////////////////////////////////////////////////////////////////
    virtual bool GetDidMain(bool did=true) const 
    {
        return m_didMain;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: SetHelpProduct
    //
    //   Author: $author$
    //     Date: 5/11/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG SetHelpProduct
    (const char* chars,
     LONG length=-1) 
    {
        length = m_helpProduct.Assign(chars, length);
        return length;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: GetHelpProduct
    //
    //   Author: $author$
    //     Date: 5/11/2007
    ///////////////////////////////////////////////////////////////////////
    virtual const char* GetHelpProduct
    (LONG& length) const 
    {
        const char* chars = m_helpProduct.Chars(length);
        return chars;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: SetHelpVersion
    //
    //   Author: $author$
    //     Date: 5/11/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG SetHelpVersion
    (const char* chars,
     LONG length=-1) 
    {
        length = m_helpVersion.Assign(chars, length);
        return length;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: GetHelpVersion
    //
    //   Author: $author$
    //     Date: 5/11/2007
    ///////////////////////////////////////////////////////////////////////
    virtual const char* GetHelpVersion
    (LONG& length) const 
    {
        const char* chars = m_helpVersion.Chars(length);
        return chars;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: GetHelpArgn
    //
    //   Author: $author$
    //     Date: 7/23/2007
    ///////////////////////////////////////////////////////////////////////
    virtual const char* GetHelpArgn(int arg) const 
    {
        const char* chars = 0;
        return chars;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: GetUsageName
    //
    //   Author: $author$
    //     Date: 10/16/2020
    ///////////////////////////////////////////////////////////////////////
    virtual const char* GetUsageName(const char* arg) const 
    {
        const char* chars = 0;
        if ((chars = arg)) {
            for (char c = *arg; c; c = *(++arg)) {
                switch (c) {
                case ':':
                case '\\':
                case '/':
                    chars = arg + 1;
                    break;
                }
            }
        }
        return chars;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: GetIn
    //
    //   Author: $author$
    //     Date: 9/2/2007
    ///////////////////////////////////////////////////////////////////////
    virtual CEvCharFile& GetIn() const 
    {
        return (CEvCharFile&)m_stdIn;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: GetOut
    //
    //   Author: $author$
    //     Date: 9/2/2007
    ///////////////////////////////////////////////////////////////////////
    virtual CEvCharFile& GetOut() const 
    {
        return (CEvCharFile&)m_stdOut;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: GetErr
    //
    //   Author: $author$
    //     Date: 9/2/2007
    ///////////////////////////////////////////////////////////////////////
    virtual CEvCharFile& GetErr() const 
    {
        return (CEvCharFile&)m_stdErr;
    }
};
#endif // _CEVMAIN_HPP
