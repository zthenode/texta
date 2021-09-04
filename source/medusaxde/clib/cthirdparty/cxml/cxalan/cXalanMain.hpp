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
//   File: cXalanMain.hpp
//
// Author: $author$
//   Date: 7/18/2011
///////////////////////////////////////////////////////////////////////
#if !defined(_CXALANMAIN_HPP) || defined(CXALANMAIN_MEMBERS_ONLY)
#if !defined(_CXALANMAIN_HPP) && !defined(CXALANMAIN_MEMBERS_ONLY)
#define _CXALANMAIN_HPP
#endif // !defined(_CXALANMAIN_HPP) && !defined(CXALANMAIN_MEMBERS_ONLY) 

#if !defined(CXALANMAIN_MEMBERS_ONLY)
#include "cOptMain.hpp"
#include "cXalanTransformer.hpp"
#include "cStringReader.hpp"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

///////////////////////////////////////////////////////////////////////
// Typedef: cXalanMainExtend
//
//  Author: $author$
//    Date: 7/18/2011
///////////////////////////////////////////////////////////////////////
typedef cOptMain
cXalanMainExtend;
///////////////////////////////////////////////////////////////////////
//  Class: cXalanMain
//
// Author: $author$
//   Date: 7/18/2011
///////////////////////////////////////////////////////////////////////
class c_INSTANCE_CLASS cXalanMain
: //virtual public cXalanMainImplement,
  public cXalanMainExtend
{
public:
    //typedef cXalanMainImplement cImplements;
    typedef cXalanMainExtend cExtends;

    cXalanTransformer m_xalan;

    ///////////////////////////////////////////////////////////////////////
    //  Constructor: cXalanMain
    //
    //       Author: $author$
    //         Date: 7/18/2011
    ///////////////////////////////////////////////////////////////////////
    cXalanMain()
    {
    }
    ///////////////////////////////////////////////////////////////////////
    //  Destructor: ~cXalanMain
    //
    //      Author: $author$
    //        Date: 7/18/2011
    ///////////////////////////////////////////////////////////////////////
    virtual ~cXalanMain()
    {
    }
#else // !defined(CXALANMAIN_MEMBERS_ONLY) 
#endif // !defined(CXALANMAIN_MEMBERS_ONLY) 

#if !defined(CXALANMAIN_MEMBERS_ONLY)
    ///////////////////////////////////////////////////////////////////////
    //  Function: Run
    //
    //    Author: $author$
    //      Date: 7/18/2011
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
        if (!(error = m_xalan.Initialize()))
        {
            cString xsltString
            ("<xsl:stylesheet xmlns:xsl='http://www.w3.org/1999/XSL/Transform' version='1.0'>"
             "<xsl:include href='xslt.xslt'/>"
             "</xsl:stylesheet>");
            cStringReader xsltReader(xsltString);

            cString xmlString("<document/>");
            cStringReader xmlReader(xmlString);

            m_xalan.Transform(xmlReader, xmlFileName, xsltReader, xsltFileName, *out, *err);
            m_xalan.Finalize();
        }
        return errn;
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

#else // !defined(CXALANMAIN_MEMBERS_ONLY) 
#endif // !defined(CXALANMAIN_MEMBERS_ONLY) 

#endif // !defined(_CXALANMAIN_HPP) || defined(CXALANMAIN_MEMBERS_ONLY) 
        

