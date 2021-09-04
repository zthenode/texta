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
//   File: cOptMain.hpp
//
// Author: $author$
//   Date: 6/2/2011
///////////////////////////////////////////////////////////////////////
#if !defined(_COPTMAIN_HPP) || defined(COPTMAIN_MEMBERS_ONLY)
#if !defined(_COPTMAIN_HPP) && !defined(COPTMAIN_MEMBERS_ONLY)
#define _COPTMAIN_HPP
#endif // !defined(_COPTMAIN_HPP) && !defined(COPTMAIN_MEMBERS_ONLY) 

#if !defined(COPTMAIN_MEMBERS_ONLY)
#include "cOptMainInterface.hpp"
#include "cMain.hpp"
#include "cDebug.hpp"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

///////////////////////////////////////////////////////////////////////
// Typedef: cOptMainExtend
//
//  Author: $author$
//    Date: 6/2/2011
///////////////////////////////////////////////////////////////////////
typedef cMain
cOptMainExtend;
///////////////////////////////////////////////////////////////////////
//  Class: cOptMain
//
// Author: $author$
//   Date: 6/2/2011
///////////////////////////////////////////////////////////////////////
class c_INSTANCE_CLASS cOptMain
: virtual public cOptMainImplement,
  public cOptMainExtend
{
public:
    typedef cOptMainImplement cImplements;
    typedef cOptMainExtend cExtends;

    bool m_didUsage;

    ///////////////////////////////////////////////////////////////////////
    //  Constructor: cOptMain
    //
    //       Author: $author$
    //         Date: 6/2/2011
    ///////////////////////////////////////////////////////////////////////
    cOptMain()
    : m_didUsage(false)
    {
    }
    ///////////////////////////////////////////////////////////////////////
    //  Destructor: ~cOptMain
    //
    //      Author: $author$
    //        Date: 6/2/2011
    ///////////////////////////////////////////////////////////////////////
    virtual ~cOptMain()
    {
    }
#else // !defined(COPTMAIN_MEMBERS_ONLY) 
#endif // !defined(COPTMAIN_MEMBERS_ONLY) 

    ///////////////////////////////////////////////////////////////////////
    //  Function: Main
    //
    //    Author: $author$
    //      Date: 6/2/2011
    ///////////////////////////////////////////////////////////////////////
    virtual int Main
    (int argc,
     char_t** argv,
     char_t** env)
#if defined(COPTMAIN_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(COPTMAIN_MEMBER_FUNCS_INTERFACE) 
    {
        int err = 0;
#if !defined(COPTMAIN_MEMBER_FUNCS_IMPLEMENT)
        m_stdIn.Attach(stdin);
        m_stdOut.Attach(stdout);
        m_stdErr.Attach(stderr);
        if (!(err = GetOptions(argc, argv, env)))
        if (!(GetDidUsage()))
            err = cExtends::Main(argc, argv, env);
#else // !defined(COPTMAIN_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(COPTMAIN_MEMBER_FUNCS_IMPLEMENT) 
        return err;
    }
#endif // defined(COPTMAIN_MEMBER_FUNCS_INTERFACE) 

    ///////////////////////////////////////////////////////////////////////
    //  Function: Usage
    //
    //    Author: $author$
    //      Date: 6/2/2011
    ///////////////////////////////////////////////////////////////////////
    virtual int Usage
    (int argc,
     char_t** argv,
     char_t** env)
#if defined(COPTMAIN_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(COPTMAIN_MEMBER_FUNCS_INTERFACE) 
    {
        int err = 0;
#if !defined(COPTMAIN_MEMBER_FUNCS_IMPLEMENT)
        const char* arguments = Arguments();
        const char* optstring = 0;
        const struct option* longopts = 0;

        SetDidUsage(true);

        OutFormatted
        ("Usage: %s [options]%s%s\n", argv[0], 
         (arguments)?((arguments[0])?(" "):("")):(""),
         (arguments)?(arguments):(""));

        if ((optstring = Options(longopts)) && (longopts))
        {
            OutFormatted("Options:\n");

            while ((longopts->name))
            {
                const char* optarg =
                (e_MAIN_OPT_ARGUMENT_REQUIRED == longopts->has_arg)?(" arg"):
                ((e_MAIN_OPT_ARGUMENT_OPTIONAL == longopts->has_arg)?(" [arg]"):(""));
                const char* optusage = OptionUsage(optarg, longopts);
                const char* optargSeparator = (optarg[0])?(" "):("");
                const char* optusageSeparator = "  ";

                OutFormatted
                (" -%c --%s%s%s%s%s\n",
                 longopts->val, longopts->name,
                 optargSeparator, optarg, optusageSeparator, optusage);
                longopts++;
            }
        }
#else // !defined(COPTMAIN_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(COPTMAIN_MEMBER_FUNCS_IMPLEMENT) 
        return err;
    }
#endif // defined(COPTMAIN_MEMBER_FUNCS_INTERFACE) 

    ///////////////////////////////////////////////////////////////////////
    //  Function: GetOptions
    //
    //    Author: $author$
    //      Date: 6/2/2011
    ///////////////////////////////////////////////////////////////////////
    virtual int GetOptions
    (int argc,
     char_t** argv,
     char_t** env)
#if defined(COPTMAIN_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(COPTMAIN_MEMBER_FUNCS_INTERFACE) 
    {
        int err = 0;
#if !defined(COPTMAIN_MEMBER_FUNCS_IMPLEMENT)
        int longindex = 0;
        const struct option* longopts = 0;
        char_t optvaluename[2] = {0,0};
        const char_t* optname = optvaluename;
        const char_t* optstring;
        int optvalue;

        if ((optstring = Options(longopts)) && (longopts))
        while (0 <= (optvalue = getopt_long
               (argc, argv, optstring, longopts, &longindex)))
        {
            optvaluename[0] = optvalue;
            optname = (longindex)?(longopts[longindex].name):(optvaluename);

            //c_DB_TRACE(("() optname = \"%s\" optarg = \"%s\"", optname, ((optarg)?(optarg):(""))));

            if ((err = OnOption
               (optvalue, optarg, optname, longindex, argc, argv, env)))
                break;
        }
#else // !defined(COPTMAIN_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(COPTMAIN_MEMBER_FUNCS_IMPLEMENT) 
        return err;
    }
#endif // defined(COPTMAIN_MEMBER_FUNCS_INTERFACE) 

    ///////////////////////////////////////////////////////////////////////
    //  Function: OnDebugOption
    //
    //    Author: $author$
    //      Date: 6/2/2011
    ///////////////////////////////////////////////////////////////////////
    virtual int OnDebugOption
    (int optval, const char* optarg,
     const char* optname, int optind,
     int argc,
     char_t** argv,
     char_t** env)
#if defined(COPTMAIN_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(COPTMAIN_MEMBER_FUNCS_INTERFACE) 
    {
        int err = 0;
#if !defined(COPTMAIN_MEMBER_FUNCS_IMPLEMENT)
        char c;

        switch(optval)
        {
        case 'd':
            if ((optarg))
            if ((c = optarg[0]))
            if (!(optarg[1]))
            {
                err = 0;
                switch(c)
                {
                case '0':
                    c_DEBUG_SET_LEVELS(e_DEBUG_LEVELS_NONE);
                    break;
 
                case '1':
                case 'e':
                    c_DEBUG_SET_LEVELS(e_DEBUG_LEVELS_ERROR);
                    break;
 
                case '2':
                case 'w':
                    c_DEBUG_SET_LEVELS(e_DEBUG_LEVELS_WARNING);
                    break;
 
                case '3':
                case 'i':
                    c_DEBUG_SET_LEVELS(e_DEBUG_LEVELS_INFO);
                    break;
 
                case '4':
                case 'f':
                    c_DEBUG_SET_LEVELS(e_DEBUG_LEVELS_FUNC);
                    break;
 
                case '5':
                case 't':
                    c_DEBUG_SET_LEVELS(e_DEBUG_LEVELS_TRACE);
                    break;
 
                default:
                    if ((c >= '0') && (c <= '9'))
                        c_DEBUG_SET_LEVELS((c-'0'));
                    else
                    err = 1;
                }
            }
            break;
        }
#else // !defined(COPTMAIN_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(COPTMAIN_MEMBER_FUNCS_IMPLEMENT) 
        return err;
    }
#endif // defined(COPTMAIN_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    //  Function: OnUsageOption
    //
    //    Author: $author$
    //      Date: 6/2/2011
    ///////////////////////////////////////////////////////////////////////
    virtual int OnUsageOption
    (int optval, const char* optarg,
     const char* optname, int optind,
     int argc,
     char_t** argv,
     char_t** env)
#if defined(COPTMAIN_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(COPTMAIN_MEMBER_FUNCS_INTERFACE) 
    {
        int err = 0;
#if !defined(COPTMAIN_MEMBER_FUNCS_IMPLEMENT)
        err = Usage(argc, argv, env);
#else // !defined(COPTMAIN_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(COPTMAIN_MEMBER_FUNCS_IMPLEMENT) 
        return err;
    }
#endif // defined(COPTMAIN_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    //  Function: OnOption
    //
    //    Author: $author$
    //      Date: 6/2/2011
    ///////////////////////////////////////////////////////////////////////
    virtual int OnOption
    (int optval, const char* optarg,
     const char* optname, int optind,
     int argc,
     char_t** argv,
     char_t** env)
#if defined(COPTMAIN_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(COPTMAIN_MEMBER_FUNCS_INTERFACE) 
    {
        int err = 0;
#if !defined(COPTMAIN_MEMBER_FUNCS_IMPLEMENT)
        switch(optval)
        {
        case 'd':
            err = OnDebugOption
            (optval, optarg, optname, optind, argc, argv, env);
            break;

        case 'h':
            err = OnUsageOption
            (optval, optarg, optname, optind, argc, argv, env);
            break;
            
        default:
            err = 1;
        }
#else // !defined(COPTMAIN_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(COPTMAIN_MEMBER_FUNCS_IMPLEMENT) 
        return err;
    }
#endif // defined(COPTMAIN_MEMBER_FUNCS_INTERFACE) 

    ///////////////////////////////////////////////////////////////////////
    //  Function: OptionUsage
    //
    //    Author: $author$
    //      Date: 6/2/2011
    ///////////////////////////////////////////////////////////////////////
    virtual const char_t* OptionUsage
    (const char_t*& optarg, const struct option* longopt)
#if defined(COPTMAIN_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(COPTMAIN_MEMBER_FUNCS_INTERFACE) 
    {
        const char_t* chars = "";
#if !defined(COPTMAIN_MEMBER_FUNCS_IMPLEMENT)
        switch(longopt->val)
        {
        case 'd':
            optarg = "{(e)error|(w)waring|(i)info|(f)function|(t)trace}";
            break;
        case 'h':
            chars = "Usage options";
            break;
        }
#else // !defined(COPTMAIN_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(COPTMAIN_MEMBER_FUNCS_IMPLEMENT) 
        return chars;
    }
#endif // defined(COPTMAIN_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    //  Function: Options
    //
    //    Author: $author$
    //      Date: 6/2/2011
    ///////////////////////////////////////////////////////////////////////
    virtual const char_t* Options
    (const struct option*& longopts)
#if defined(COPTMAIN_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(COPTMAIN_MEMBER_FUNCS_INTERFACE) 
    {
#if !defined(COPTMAIN_MEMBER_FUNCS_IMPLEMENT)
        static const char* chars = "d:h";
        static struct option optstruct[]= {
            {"debug-levels", e_MAIN_OPT_ARGUMENT_REQUIRED, 0, 'd'},
            {"help", e_MAIN_OPT_ARGUMENT_NONE, 0, 'h'},
            {0, 0, 0, 0}};
        longopts = optstruct;
#else // !defined(COPTMAIN_MEMBER_FUNCS_IMPLEMENT) 
        static const char_t* chars = "";
#endif // !defined(COPTMAIN_MEMBER_FUNCS_IMPLEMENT) 
        return chars;
    }
#endif // defined(COPTMAIN_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    //  Function: Arguments
    //
    //    Author: $author$
    //      Date: 7/19/2011
    ///////////////////////////////////////////////////////////////////////
    virtual const char_t* Arguments()
#if defined(COPTMAIN_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(COPTMAIN_MEMBER_FUNCS_INTERFACE) 
    {
        static const char_t* chars = "";
#if !defined(COPTMAIN_MEMBER_FUNCS_IMPLEMENT)
#else // !defined(COPTMAIN_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(COPTMAIN_MEMBER_FUNCS_IMPLEMENT) 
        return chars;
    }
#endif // defined(COPTMAIN_MEMBER_FUNCS_INTERFACE) 

    ///////////////////////////////////////////////////////////////////////
    //  Function: SetDidUsage
    //
    //    Author: $author$
    //      Date: 6/2/2011
    ///////////////////////////////////////////////////////////////////////
    virtual bool SetDidUsage
    (bool isTrue=true)
#if defined(COPTMAIN_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(COPTMAIN_MEMBER_FUNCS_INTERFACE) 
    {
        bool didUsage = false;
#if !defined(COPTMAIN_MEMBER_FUNCS_IMPLEMENT)
        didUsage = (m_didUsage = isTrue);
#else // !defined(COPTMAIN_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(COPTMAIN_MEMBER_FUNCS_IMPLEMENT) 
        return didUsage;
    }
#endif // defined(COPTMAIN_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    //  Function: GetDidUsage
    //
    //    Author: $author$
    //      Date: 6/2/2011
    ///////////////////////////////////////////////////////////////////////
    virtual bool GetDidUsage() const
#if defined(COPTMAIN_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(COPTMAIN_MEMBER_FUNCS_INTERFACE) 
    {
        bool didUsage = false;
#if !defined(COPTMAIN_MEMBER_FUNCS_IMPLEMENT)
        didUsage = (m_didUsage);
#else // !defined(COPTMAIN_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(COPTMAIN_MEMBER_FUNCS_IMPLEMENT) 
        return didUsage;
    }
#endif // defined(COPTMAIN_MEMBER_FUNCS_INTERFACE) 

#if !defined(COPTMAIN_MEMBERS_ONLY)
};


#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#else // !defined(COPTMAIN_MEMBERS_ONLY) 
#endif // !defined(COPTMAIN_MEMBERS_ONLY) 

#endif // !defined(_COPTMAIN_HPP) || defined(COPTMAIN_MEMBERS_ONLY) 

