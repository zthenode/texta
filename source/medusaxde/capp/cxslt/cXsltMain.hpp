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
//   File: cXsltMain.hpp
//
// Author: $author$
//   Date: 7/7/2011
///////////////////////////////////////////////////////////////////////
#if !defined(_CXSLTMAIN_HPP) || defined(CXSLTMAIN_MEMBERS_ONLY)
#if !defined(_CXSLTMAIN_HPP) && !defined(CXSLTMAIN_MEMBERS_ONLY)
#define _CXSLTMAIN_HPP
#endif // !defined(_CXSLTMAIN_HPP) && !defined(CXSLTMAIN_MEMBERS_ONLY) 

#if !defined(CXSLTMAIN_MEMBERS_ONLY)
#include "cXsltProcessorInterface.hpp"
#include "cXsltParams.hpp"
#include "cOptMain.hpp"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

///////////////////////////////////////////////////////////////////////
// Typedef: cXsltMainExtend
//
//  Author: $author$
//    Date: 7/7/2011
///////////////////////////////////////////////////////////////////////
typedef cOptMain
cXsltMainExtend;
///////////////////////////////////////////////////////////////////////
//  Class: cXsltMain
//
// Author: $author$
//   Date: 7/7/2011
///////////////////////////////////////////////////////////////////////
class c_INSTANCE_CLASS cXsltMain
: //virtual public cXsltMainImplement,
  public cXsltMainExtend
{
public:
    //typedef cXsltMainImplement cImplements;
    typedef cXsltMainExtend cExtends;

    cXsltParams m_params;

    ///////////////////////////////////////////////////////////////////////
    //  Constructor: cXsltMain
    //
    //       Author: $author$
    //         Date: 7/7/2011
    ///////////////////////////////////////////////////////////////////////
    cXsltMain()
    {
    }
    ///////////////////////////////////////////////////////////////////////
    //  Destructor: ~cXsltMain
    //
    //      Author: $author$
    //        Date: 7/7/2011
    ///////////////////////////////////////////////////////////////////////
    virtual ~cXsltMain()
    {
    }
#else // !defined(CXSLTMAIN_MEMBERS_ONLY) 
#endif // !defined(CXSLTMAIN_MEMBERS_ONLY) 

#if !defined(CXSLTMAIN_MEMBERS_ONLY)
    ///////////////////////////////////////////////////////////////////////
    //  Function: Run
    //
    //    Author: $author$
    //      Date: 6/7/2011
    ///////////////////////////////////////////////////////////////////////
    virtual int Run
    (int argc,
     char** argv,
     char** env)
    {
        int errn = 0;
        cCharWriterInterface* out = &m_out;
        cCharWriterInterface* err = &m_err;
        const char* xsltFileName = 0;
        const char* xmlFileName = 0;
        cXsltProcessorInterface* xslt;
        int arg;
        eError error;

        if (argc > (arg = optind))
            xmlFileName = (xsltFileName = argv[arg++]);

        if (argc > (arg))
        if (!(xmlFileName = argv[arg]))
            xmlFileName = xsltFileName;

        if ((!xsltFileName) || (!xmlFileName))
            errn = Usage(argc, argv, env);
        else
        if ((xslt = cXsltProcessorInterface::GetInstance(error)))
        {
            if (!(error = xslt->Init()))
            {
                xslt->SetParameters(m_params);
                xslt->ProcessFiles(*err, *out, xsltFileName, xmlFileName);
                xslt->Finish();
            }
            cXsltProcessorInterface::FreeInstance(xslt);
        }
        return errn;
    }
    ///////////////////////////////////////////////////////////////////////
    //  Function: OnOutputOption
    //
    //    Author: $author$
    //      Date: 7/25/2011
    ///////////////////////////////////////////////////////////////////////
    virtual int OnOutputOption
    (int optval, const char* optarg,
     const char* optname, int optind,
     int argc,
     char_t** argv,
     char_t** env)
    {
        int err = 0;
        return err;
    }
    ///////////////////////////////////////////////////////////////////////
    //  Function: OnLiteralParamOption
    //
    //    Author: $author$
    //      Date: 7/25/2011
    ///////////////////////////////////////////////////////////////////////
    virtual int OnLiteralParamOption
    (int optval, const char* optarg,
     const char* optname, int optind,
     int argc,
     char_t** argv,
     char_t** env)
    {
        int err = 0;
        cString name;
        cString expr;
        eError error;
        if (!(OnParamOptarg
            (name, expr, optval, optarg, 
             optname, optind, argc, argv, env)))
            m_params.AddLiteral(error, name, expr);
        return err;
    }
    ///////////////////////////////////////////////////////////////////////
    //  Function: OnParamOption
    //
    //    Author: $author$
    //      Date: 7/25/2011
    ///////////////////////////////////////////////////////////////////////
    virtual int OnParamOption
    (int optval, const char* optarg,
     const char* optname, int optind,
     int argc,
     char_t** argv,
     char_t** env)
    {
        int err = 0;
        cString name;
        cString expr;
        eError error;
        if (!(OnParamOptarg
            (name, expr, optval, optarg, 
             optname, optind, argc, argv, env)))
            m_params.Add(error, name, expr);
        return err;
    }
    ///////////////////////////////////////////////////////////////////////
    //  Function: OnParamOptarg
    //
    //    Author: $author$
    //      Date: 7/25/2011
    ///////////////////////////////////////////////////////////////////////
    virtual int OnParamOptarg
    (cString& name, cString& expr,
     int optval, const char* optarg,
     const char* optname, int optind,
     int argc,
     char_t** argv,
     char_t** env)
    {
        int err = 1;
        ssize_t nameLen;
        const char* nameChars;
        const char* exprChars;
        if ((nameChars = optarg))
        if ((exprChars = strchr(nameChars,'=')))
        if (0 < (nameLen = exprChars-nameChars))
        if ((++exprChars)[0])
        if (0 < (name.Assign(nameChars, nameLen)))
        if (0 < (expr.Assign(exprChars)))
            err = 0;
        return err;
    }

    ///////////////////////////////////////////////////////////////////////
    //  Function: OnOption
    //
    //    Author: $author$
    //      Date: 7/25/2011
    ///////////////////////////////////////////////////////////////////////
    virtual int OnOption
    (int optval, const char* optarg,
     const char* optname, int optind,
     int argc,
     char_t** argv,
     char_t** env)
    {
        int err = 0;
        switch(optval)
        {
        case 'o':
            err = OnOutputOption
            (optval, optarg, optname, optind, argc, argv, env);
            break;

        case 'l':
            err = OnLiteralParamOption
            (optval, optarg, optname, optind, argc, argv, env);
            break;
            
        case 'p':
            err = OnParamOption
            (optval, optarg, optname, optind, argc, argv, env);
            break;
            
        default:
            err = cExtends::OnOption
            (optval, optarg, optname, optind, argc, argv, env);
        }
        return err;
    }
    ///////////////////////////////////////////////////////////////////////
    //  Function: OptionUsage
    //
    //    Author: $author$
    //      Date: 7/25/2011
    ///////////////////////////////////////////////////////////////////////
    virtual const char_t* OptionUsage
    (const char_t*& optarg, const struct option* longopt)
    {
        const char_t* chars = "";
        switch(longopt->val)
        {
        case 'o':
            optarg = "<filename>";
            chars = "Output to <filename>";
            break;
        case 'l':
            optarg = "<name>=<value>";
            chars = "Set param <name> to literal <value>";
            break;
        case 'p':
            optarg = "<name>=<expression>";
            chars = "Set param <name> to <expression>";
            break;
        default:
            cExtends::OptionUsage(optarg, longopt);
        }
        return chars;
    }
    ///////////////////////////////////////////////////////////////////////
    //  Function: Options
    //
    //    Author: $author$
    //      Date: 7/25/2011
    ///////////////////////////////////////////////////////////////////////
    virtual const char_t* Options
    (const struct option*& longopts)
    {
        static const char* chars = "o:l:p:d:h";
        static struct option optstruct[]= {
            {"output-file", e_MAIN_OPT_ARGUMENT_REQUIRED, 0, 'o'},
            {"literal-param", e_MAIN_OPT_ARGUMENT_REQUIRED, 0, 'l'},
            {"param", e_MAIN_OPT_ARGUMENT_REQUIRED, 0, 'p'},
            {"debug-levels", e_MAIN_OPT_ARGUMENT_REQUIRED, 0, 'd'},
            {"help", e_MAIN_OPT_ARGUMENT_NONE, 0, 'h'},
            {0, 0, 0, 0}};
        longopts = optstruct;
        return chars;
    }
    ///////////////////////////////////////////////////////////////////////
    //  Function: Arguments
    //
    //    Author: $author$
    //      Date: 7/19/2011
    ///////////////////////////////////////////////////////////////////////
    virtual const char_t* Arguments()
    {
        static const char_t* chars = "<xslt filename> [<xml filename>]";
        return chars;
    }
};


#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#else // !defined(CXSLTMAIN_MEMBERS_ONLY) 
#endif // !defined(CXSLTMAIN_MEMBERS_ONLY) 

#endif // !defined(_CXSLTMAIN_HPP) || defined(CXSLTMAIN_MEMBERS_ONLY) 
