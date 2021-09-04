///////////////////////////////////////////////////////////////////////
// Copyright (c) 1988-2011 $organization$
//
// This software is provided by the author and contributors ``as is'' 
// and any express or implied warranties, including, but not limited to, 
// the implied warranties of merchantability and fitness for a particular 
// purpose are disclaimed. In no event shall the author or contributors 
// be liable for any direct, indirect, incidental, special, exemplary, 
// or consequential damages (including, but not limited to, procurement 
// of substitute goods or services; loss of use, data, or profits; or 
// business interruption) however caused and on any theory of liability, 
// whether in contract, strict liability, or tort (including negligence 
// or otherwise) arising in any way out of the use of this software, 
// even if advised of the possibility of such damage.
//
//   File: cMain.hpp
//
// Author: $author$
//   Date: 6/1/2011
///////////////////////////////////////////////////////////////////////
#if !defined(_CMAIN_HPP) || defined(CMAINT_MEMBERS_ONLY)
#if !defined(_CMAIN_HPP) && !defined(CMAINT_MEMBERS_ONLY)
#define _CMAIN_HPP
#endif // !defined(_CMAIN_HPP) && !defined(CMAINT_MEMBERS_ONLY) 

#if !defined(CMAINT_MEMBERS_ONLY)
#include "cMainInterface.hpp"
#include "cInstanceBase.hpp"
#include "cCharFile.hpp"
#include "cCharStream.hpp"
#include "cDebug.hpp"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

class c_INSTANCE_CLASS cMain;

#undef CDB_CLASS
#define CDB_CLASS "cMainT"
///////////////////////////////////////////////////////////////////////
//  Class: cMainT
//
// Author: $author$
//   Date: 6/1/2011
///////////////////////////////////////////////////////////////////////
template
<class TImplement=cMainImplement,
 class TInterface=cMainInterface,
 class TCharFile=cCharFile,
 class TCharStream=cCharStream,
 class TCharStreamInterface=cCharStreamInterface,
 class TChar=char,
 class TExtend=cInstanceBase>

class c_INSTANCE_CLASS cMainT
: virtual public TImplement,
  public TExtend
{
public:
    typedef TImplement cImplements;
    typedef TExtend cExtends;

// include cMainT interface member definitions
//
#define CMAININTERFACET_MEMBERS_ONLY
#include "cMainInterface.hpp"
#undef CMAININTERFACET_MEMBERS_ONLY

    typedef TInterface tMainInterface;
    typedef TCharFile tCharFile;
    typedef TCharStream tCharStream;
    typedef TCharStreamInterface tCharStreamInterface;

    static tMainInterface* m_theMain;
    tMainInterface* m_theOldMain;

    tCharFile m_stdIn, m_stdOut, m_stdErr;
    tCharStream m_in, m_out, m_err;

    ///////////////////////////////////////////////////////////////////////
    //  Constructor: cMainT
    //
    //       Author: $author$
    //         Date: 6/1/2011
    ///////////////////////////////////////////////////////////////////////
    cMainT()
    : m_theOldMain(m_theMain),
      m_in(&m_stdIn),
      m_out(&m_stdOut),
      m_err(&m_stdErr)
    {
        m_theMain = (tMainInterface*)(this);
    }
    ///////////////////////////////////////////////////////////////////////
    //  Destructor: ~cMainT
    //
    //      Author: $author$
    //        Date: 6/1/2011
    ///////////////////////////////////////////////////////////////////////
    virtual ~cMainT()
    {
        if ((tMainInterface*)(this) == m_theMain)
            m_theMain = m_theOldMain;
    }
#else // !defined(CMAINT_MEMBERS_ONLY) 
#endif // !defined(CMAINT_MEMBERS_ONLY) 

    ///////////////////////////////////////////////////////////////////////
    //  Function: Main
    //
    //    Author: $author$
    //      Date: 6/1/2011
    ///////////////////////////////////////////////////////////////////////
    virtual int Main
    (int argc,
     char_t** argv,
     char_t** env)
#if defined(CMAINT_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CMAINT_MEMBER_FUNCS_INTERFACE) 
    {
        int err = 0;
#if !defined(CMAINT_MEMBER_FUNCS_IMPLEMENT)
        int err2;
        
        m_stdIn.Attach(stdin);
        m_stdOut.Attach(stdout);
        m_stdErr.Attach(stderr);

        if (!(err = BeforeRun(argc, argv, env)))
        {
            err = Run(argc, argv, env);

            if ((err2 = AfterRun(argc, argv, env)))
            if (!(err))
                err = err2;
        }
#else // !defined(CMAINT_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CMAINT_MEMBER_FUNCS_IMPLEMENT) 
        return err;
    }
#endif // defined(CMAINT_MEMBER_FUNCS_INTERFACE) 

    ///////////////////////////////////////////////////////////////////////
    //  Function: Run
    //
    //    Author: $author$
    //      Date: 6/1/2011
    ///////////////////////////////////////////////////////////////////////
    virtual int Run
    (int argc,
     char_t** argv,
     char_t** env)
#if defined(CMAINT_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CMAINT_MEMBER_FUNCS_INTERFACE) 
    {
        int err = 0;
#if !defined(CMAINT_MEMBER_FUNCS_IMPLEMENT)
#else // !defined(CMAINT_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CMAINT_MEMBER_FUNCS_IMPLEMENT) 
        return err;
    }
#endif // defined(CMAINT_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    //  Function: BeforeRun
    //
    //    Author: $author$
    //      Date: 6/1/2011
    ///////////////////////////////////////////////////////////////////////
    virtual int BeforeRun
    (int argc,
     char_t** argv,
     char_t** env)
#if defined(CMAINT_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CMAINT_MEMBER_FUNCS_INTERFACE) 
    {
        int err = 0;
#if !defined(CMAINT_MEMBER_FUNCS_IMPLEMENT)
#else // !defined(CMAINT_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CMAINT_MEMBER_FUNCS_IMPLEMENT) 
        return err;
    }
#endif // defined(CMAINT_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    //  Function: AfterRun
    //
    //    Author: $author$
    //      Date: 6/1/2011
    ///////////////////////////////////////////////////////////////////////
    virtual int AfterRun
    (int argc,
     char_t** argv,
     char_t** env)
#if defined(CMAINT_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CMAINT_MEMBER_FUNCS_INTERFACE) 
    {
        int err = 0;
#if !defined(CMAINT_MEMBER_FUNCS_IMPLEMENT)
#else // !defined(CMAINT_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CMAINT_MEMBER_FUNCS_IMPLEMENT) 
        return err;
    }
#endif // defined(CMAINT_MEMBER_FUNCS_INTERFACE) 

    ///////////////////////////////////////////////////////////////////////
    //  Function: InFormatted
    //
    //    Author: $author$
    //      Date: 6/3/2011
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t InFormatted
    (const char_t* format,
     ...)
#if defined(CMAINT_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CMAINT_MEMBER_FUNCS_INTERFACE) 
    {
        ssize_t count = -e_ERROR_FAILED;
#if !defined(CMAINT_MEMBER_FUNCS_IMPLEMENT)
        va_list va;
        va_start(va, format);
        count = InFormattedV(format, va);
        va_end(va);
#else // !defined(CMAINT_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CMAINT_MEMBER_FUNCS_IMPLEMENT) 
        return count;
    }
#endif // defined(CMAINT_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    //  Function: InFormattedV
    //
    //    Author: $author$
    //      Date: 6/3/2011
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t InFormattedV
    (const char_t* format,
     va_list va)
#if defined(CMAINT_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CMAINT_MEMBER_FUNCS_INTERFACE) 
    {
        ssize_t count = -e_ERROR_FAILED;
#if !defined(CMAINT_MEMBER_FUNCS_IMPLEMENT)
        count = m_in.ReadFormattedV(format, va);
#else // !defined(CMAINT_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CMAINT_MEMBER_FUNCS_IMPLEMENT) 
        return count;
    }
#endif // defined(CMAINT_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    //  Function: In
    //
    //    Author: $author$
    //      Date: 11/20/2012
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t In
    (char_t* chars, size_t size)
#if defined(CMAINT_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CMAINT_MEMBER_FUNCS_INTERFACE) 
    {
        ssize_t count = -e_ERROR_FAILED;
#if !defined(CMAINT_MEMBER_FUNCS_IMPLEMENT)
        count = m_in.Read(chars, size);
#else // !defined(CMAINT_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CMAINT_MEMBER_FUNCS_IMPLEMENT) 
        return count;
    }
#endif // defined(CMAINT_MEMBER_FUNCS_INTERFACE) 

    ///////////////////////////////////////////////////////////////////////
    //  Function: OutFormatted
    //
    //    Author: $author$
    //      Date: 6/3/2011
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t OutFormatted
    (const char_t* format,
     ...)
#if defined(CMAINT_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CMAINT_MEMBER_FUNCS_INTERFACE) 
    {
        ssize_t count = -e_ERROR_FAILED;
#if !defined(CMAINT_MEMBER_FUNCS_IMPLEMENT)
        va_list va;
        va_start(va, format);
        count = OutFormattedV(format, va);
        va_end(va);
#else // !defined(CMAINT_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CMAINT_MEMBER_FUNCS_IMPLEMENT) 
        return count;
    }
#endif // defined(CMAINT_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    //  Function: OutFormattedV
    //
    //    Author: $author$
    //      Date: 6/3/2011
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t OutFormattedV
    (const char_t* format,
     va_list va)
#if defined(CMAINT_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CMAINT_MEMBER_FUNCS_INTERFACE) 
    {
        ssize_t count = -e_ERROR_FAILED;
#if !defined(CMAINT_MEMBER_FUNCS_IMPLEMENT)
        count = m_out.WriteFormattedV(format, va);
#else // !defined(CMAINT_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CMAINT_MEMBER_FUNCS_IMPLEMENT) 
        return count;
    }
#endif // defined(CMAINT_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    //  Function: Out
    //
    //    Author: $author$
    //      Date: 11/20/2012
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t Out
    (const char_t* chars, ssize_t length = -1)
#if defined(CMAINT_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CMAINT_MEMBER_FUNCS_INTERFACE) 
    {
        ssize_t count = -e_ERROR_FAILED;
#if !defined(CMAINT_MEMBER_FUNCS_IMPLEMENT)
        count = m_out.Write(chars, length);
#else // !defined(CMAINT_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CMAINT_MEMBER_FUNCS_IMPLEMENT) 
        return count;
    }
#endif // defined(CMAINT_MEMBER_FUNCS_INTERFACE) 

    ///////////////////////////////////////////////////////////////////////
    //  Function: ErrFormatted
    //
    //    Author: $author$
    //      Date: 6/3/2011
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t ErrFormatted
    (const char_t* format,
     ...)
#if defined(CMAINT_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CMAINT_MEMBER_FUNCS_INTERFACE) 
    {
        ssize_t count = -e_ERROR_FAILED;
#if !defined(CMAINT_MEMBER_FUNCS_IMPLEMENT)
        va_list va;
        va_start(va, format);
        count = ErrFormattedV(format, va);
        va_end(va);
#else // !defined(CMAINT_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CMAINT_MEMBER_FUNCS_IMPLEMENT) 
        return count;
    }
#endif // defined(CMAINT_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    //  Function: ErrFormattedV
    //
    //    Author: $author$
    //      Date: 6/3/2011
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t ErrFormattedV
    (const char_t* format,
     va_list va)
#if defined(CMAINT_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CMAINT_MEMBER_FUNCS_INTERFACE) 
    {
        ssize_t count = -e_ERROR_FAILED;
#if !defined(CMAINT_MEMBER_FUNCS_IMPLEMENT)
        count = m_err.WriteFormattedV(format, va);
#else // !defined(CMAINT_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CMAINT_MEMBER_FUNCS_IMPLEMENT) 
        return count;
    }
#endif // defined(CMAINT_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    //  Function: Err
    //
    //    Author: $author$
    //      Date: 11/20/2012
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t Err
    (const char_t* chars, ssize_t length = -1)
#if defined(CMAINT_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CMAINT_MEMBER_FUNCS_INTERFACE) 
    {
        ssize_t count = -e_ERROR_FAILED;
#if !defined(CMAINT_MEMBER_FUNCS_IMPLEMENT)
        count = m_err.Write(chars, length);
#else // !defined(CMAINT_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CMAINT_MEMBER_FUNCS_IMPLEMENT) 
        return count;
    }
#endif // defined(CMAINT_MEMBER_FUNCS_INTERFACE) 

#if !defined(CMAINT_MEMBERS_ONLY)
    ///////////////////////////////////////////////////////////////////////
    //  Function: TheMain
    //
    //    Author: $author$
    //      Date: 6/1/2011
    ///////////////////////////////////////////////////////////////////////
    static int TheMain
    (int argc,
     char_t** argv,
     char_t** env)
    {
        int err = 0;
        
        c_DEBUG_INIT();

        if ((m_theMain))
            err = m_theMain->Main(argc, argv, env);
        else
        c_DB_ERROR("() m_theMain == 0");

        c_DEBUG_FINISH();
        return err;
    }
};
#undef CDB_CLASS

///////////////////////////////////////////////////////////////////////
//  Class: cMainT
//
// Author: $author$
//   Date: 6/1/2011
///////////////////////////////////////////////////////////////////////
template
<class TImplement,
 class TInterface,
 class TCharFile,
 class TCharStream,
 class TCharStreamInterface,
 class TChar,
 class TExtend>

TInterface* cMainT
<TImplement,
 TInterface,
 TCharFile,
 TCharStream,
 TCharStreamInterface,
 TChar,
 TExtend>
::m_theMain = 0;

///////////////////////////////////////////////////////////////////////
// Typedef: cMainExtends
//
//  Author: $author$
//    Date: 6/2/2011
///////////////////////////////////////////////////////////////////////
typedef cMainT
<cMainImplement,cMainInterface,
 cCharFile,cCharStream,cCharStreamInterface,char>
cMainExtends;
///////////////////////////////////////////////////////////////////////
//  Class: cMain
//
// Author: $author$
//   Date: 6/2/2011
///////////////////////////////////////////////////////////////////////
class c_INSTANCE_CLASS cMain
: public cMainExtends
{
public:
    typedef cMainExtends cExtends;
    ///////////////////////////////////////////////////////////////////////
    //  Constructor: cMain
    //
    //       Author: $author$
    //         Date: 6/2/2011
    ///////////////////////////////////////////////////////////////////////
    cMain()
    {
    }
    ///////////////////////////////////////////////////////////////////////
    //  Destructor: ~cMain
    //
    //      Author: $author$
    //        Date: 6/2/2011
    ///////////////////////////////////////////////////////////////////////
    virtual ~cMain()
    {
    }
};

#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#else // !defined(CMAINT_MEMBERS_ONLY) 
#endif // !defined(CMAINT_MEMBERS_ONLY) 

#endif // !defined(_CMAIN_HPP) || defined(CMAINT_MEMBERS_ONLY) 
        

