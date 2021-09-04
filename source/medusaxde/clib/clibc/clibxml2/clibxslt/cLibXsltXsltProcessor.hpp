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
//   File: cLibXsltXsltProcessor.hpp
//
// Author: $author$
//   Date: 7/1/2011
///////////////////////////////////////////////////////////////////////
#if !defined(_CLIBXSLTXSLTPROCESSOR_HPP) || defined(CLIBXSLTXSLTPROCESSOR_MEMBERS_ONLY)
#if !defined(_CLIBXSLTXSLTPROCESSOR_HPP) && !defined(CLIBXSLTXSLTPROCESSOR_MEMBERS_ONLY)
#define _CLIBXSLTXSLTPROCESSOR_HPP
#endif // !defined(_CLIBXSLTXSLTPROCESSOR_HPP) && !defined(CLIBXSLTXSLTPROCESSOR_MEMBERS_ONLY) 

#if !defined(CLIBXSLTXSLTPROCESSOR_MEMBERS_ONLY)
#include "cLibXsltXsltProcessorInterface.hpp"
#include "cLibXsltXsltParams.hpp"
#include "cXsltProcessor.hpp"
#include "cDebug.hpp"

#include <libxslt/xslt.h>
#include <libxslt/transform.h>
#include <libxslt/xsltutils.h>
#include <libxslt/extensions.h>
#include <libxslt/security.h>
//#include <libxslt/xsltInternals.h>
//#include <libexslt/exsltconfig.h>
#include <libexslt/exslt.h>

#define DEFAULT_XSLT_PARSE_OPTIONS_XML_PARSE_NOERROR XML_PARSE_NOERROR
#define DEFAULT_XSLT_PARSE_OPTIONS_XML_PARSE_NOWARNING XML_PARSE_NOWARNING

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

///////////////////////////////////////////////////////////////////////
// Typedef: cLibXsltXsltProcessorExtend
//
//  Author: $author$
//    Date: 7/1/2011
///////////////////////////////////////////////////////////////////////
typedef cXsltProcessor
cLibXsltXsltProcessorExtend;
///////////////////////////////////////////////////////////////////////
//  Class: cLibXsltXsltProcessor
//
// Author: $author$
//   Date: 7/1/2011
///////////////////////////////////////////////////////////////////////
class c_INSTANCE_CLASS cLibXsltXsltProcessor
: virtual public cLibXsltXsltProcessorImplement,
  public cLibXsltXsltProcessorExtend
{
public:
    typedef cLibXsltXsltProcessorImplement cImplements;
    typedef cLibXsltXsltProcessorExtend cExtends;

    xsltSecurityPrefsPtr m_secPrefs;
    xmlExternalEntityLoader m_entLoader;
    int m_xsltParseOptions;
    int m_xmlParseOptions;

    cLibXsltXsltParams m_xsltParams;

    ///////////////////////////////////////////////////////////////////////
    //  Constructor: cLibXsltXsltProcessor
    //
    //       Author: $author$
    //         Date: 7/1/2011
    ///////////////////////////////////////////////////////////////////////
    cLibXsltXsltProcessor()
    : m_secPrefs(0),
      m_entLoader(0),
      m_xsltParseOptions(XSLT_PARSE_OPTIONS | DEFAULT_XSLT_PARSE_OPTIONS_XML_PARSE_NOERROR | DEFAULT_XSLT_PARSE_OPTIONS_XML_PARSE_NOWARNING),
      m_xmlParseOptions(XML_PARSE_NOENT | XML_PARSE_NOCDATA | XML_PARSE_NOWARNING)
    {
    }
    ///////////////////////////////////////////////////////////////////////
    //  Destructor: ~cLibXsltXsltProcessor
    //
    //      Author: $author$
    //        Date: 7/1/2011
    ///////////////////////////////////////////////////////////////////////
    virtual ~cLibXsltXsltProcessor()
    {
    }
#else // !defined(CLIBXSLTXSLTPROCESSOR_MEMBERS_ONLY) 
#endif // !defined(CLIBXSLTXSLTPROCESSOR_MEMBERS_ONLY) 

#if !defined(CLIBXSLTXSLTPROCESSOR_MEMBERS_ONLY)
    ///////////////////////////////////////////////////////////////////////
    //  Function: Init
    //
    //    Author: $author$
    //      Date: 7/2/2011
    ///////////////////////////////////////////////////////////////////////
    virtual eError Init()
    {
        eError error = e_ERROR_FAILED;
        int err;
        
        if (!(err = xmlInitMemory()))
        {
            if ((m_secPrefs = xsltNewSecurityPrefs()))
            {
                xsltSetDefaultSecurityPrefs(m_secPrefs);

                if ((m_entLoader = xmlGetExternalEntityLoader()))
                {
                    exsltRegisterAll();
                    return error = e_ERROR_NONE;

                    xmlSetExternalEntityLoader(m_entLoader);
                    m_entLoader = 0;
                }
                else
                c_DB_ERROR("() failed on xmlGetExternalEntityLoader()");

                xsltFreeSecurityPrefs(m_secPrefs);
                m_secPrefs = 0;
            }
            else
            c_DB_ERROR("() failed on xsltNewSecurityPrefs()");

            xmlCleanupMemory();
        }
        else
        c_DB_ERROR("() failed on xmlInitMemory()");
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    //  Function: Finish
    //
    //    Author: $author$
    //      Date: 7/2/2011
    ///////////////////////////////////////////////////////////////////////
    virtual eError Finish()
    {
        eError error = e_ERROR_NONE;
        m_xsltParams.Clear();
        xmlSetExternalEntityLoader(m_entLoader);
        m_entLoader = 0;
        xsltFreeSecurityPrefs(m_secPrefs);
        m_secPrefs = 0;
        xsltCleanupGlobals();
        xmlCleanupParser();
        xmlCleanupMemory();
        return error;
    }

    ///////////////////////////////////////////////////////////////////////
    //  Function: ProcessFiles
    //
    //    Author: $author$
    //      Date: 7/2/2011
    ///////////////////////////////////////////////////////////////////////
    virtual eError ProcessFiles
    (cCharWriterInterface& errors,
     cCharWriterInterface& result,
     const cString& xsltFileName,
     const cString& xmlFileName)
    {
        eError error = e_ERROR_FAILED;
        static const char* nullParams = 0;
        const char** xsltParams = &nullParams;
        const char* xsltFileNameChars;
        const char* xmlFileNameChars;
        xmlDocPtr xsltDoc;
        xmlDocPtr xmlDoc;
        xmlDocPtr resDoc;
        xmlOutputBufferPtr resOutput;
        xmlCharEncodingHandlerPtr resEncoder;
        xsltStylesheetPtr xsltStyle;
        xsltTransformContextPtr xsltCtxt;
        xmlParserCtxtPtr xmlCtxt;
        xmlGenericErrorFunc xsltErrorFunc;
        xmlGenericErrorFunc xmlErrorFunc;

        xsltErrorFunc = XsltGenericError;
        xmlErrorFunc = XmlGenericError;
        xmlSetGenericErrorFunc(&errors, xmlErrorFunc);
        xsltSetGenericErrorFunc(&errors, xsltErrorFunc);

        if ((xmlCtxt = xmlNewParserCtxt()))
        {
        xmlInitParserCtxt(xmlCtxt);
        if ((xsltFileNameChars = xsltFileName.HasChars()))
        if ((xsltDoc = xmlReadFile
            (xsltFileNameChars, 0, m_xsltParseOptions)))
        //if ((xsltDoc = xmlCtxtReadFile
        //    (xmlCtxt, xsltFileNameChars, 0, m_xsltParseOptions)))
        {
            if ((xmlFileNameChars = xmlFileName.HasChars()))
            if ((xmlDoc = xmlReadFile
                (xmlFileNameChars, 0, m_xmlParseOptions)))
            //if ((xmlDoc = xmlCtxtReadFile
            //    (xmlCtxt, xmlFileNameChars, 0, m_xmlParseOptions)))
            {
                if ((xsltStyle = xsltParseStylesheetDoc(xsltDoc)))
                {
                    if ((xsltCtxt = xsltNewTransformContext(xsltStyle, xmlDoc)))
                    {
                        if (0 <= (xsltSetCtxtParseOptions(xsltCtxt, m_xsltParseOptions)))
                        {
                            m_xsltParams.AddEnd();
                            if (!(xsltParams = m_xsltParams.ParamsChars()))
                                xsltParams = &nullParams;

                            if ((resDoc = xsltApplyStylesheetUser
                                (xsltStyle, xmlDoc, xsltParams, 0, 0, xsltCtxt)))
                            {
                                resEncoder = 0;
                                if ((resOutput = xmlOutputBufferCreateIO
                                    (CharWriterIoWrite, CharWriterIoClose, &result, resEncoder)))
                                {
                                    if (0 <= (xsltSaveResultTo(resOutput, resDoc, xsltStyle)))
                                        error = e_ERROR_NONE;
                                    else
                                    c_DB_ERROR("() failed on xsltSaveResultTo()");

                                    xmlOutputBufferClose(resOutput);
                                }
                                else
                                c_DB_ERROR("() failed on xmlOutputBufferCreateIO()");

                                xmlFreeDoc(resDoc);
                            }
                            else
                            c_DB_ERROR("() failed on xsltApplyStylesheetUser()");
                        }
                        else
                        c_DB_ERROR("() failed on xsltSetCtxtParseOptions()");

                        xsltFreeTransformContext(xsltCtxt);
                    }
                    else
                    c_DB_ERROR("() failed on xsltNewTransformContext()");

                    xsltFreeStylesheet(xsltStyle);
                    xsltDoc = 0;
                }
                else
                c_DB_ERROR("() failed on xsltParseStylesheetDoc()");

                xmlFreeDoc(xmlDoc);
            }
            else
            c_DB_ERROR("() failed on xmlReadFile()");

            if ((xsltDoc))
                xmlFreeDoc(xsltDoc);
        }
        else
        c_DB_ERROR("() failed on xmlReadFile()");

        xmlFreeParserCtxt(xmlCtxt);
        }
        xsltSetGenericErrorFunc(0,0);
        xmlSetGenericErrorFunc(0,0);
        return error;
    }

    ///////////////////////////////////////////////////////////////////////
    //  Function: SetLiteralParameter
    //
    //    Author: $author$
    //      Date: 8/13/2011
    ///////////////////////////////////////////////////////////////////////
    virtual eError SetLiteralParameter
    (const cString& name,
     const cString& value)
    {
        eError error = e_ERROR_FAILED;
        if ((error = m_xsltParams.AddLiteral(name, value)))
            c_DB_ERROR("() failed on m_xsltParams.AddLiteral(\"" << name << "\", \"" << value << "\")");
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    //  Function: SetParameter
    //
    //    Author: $author$
    //      Date: 8/13/2011
    ///////////////////////////////////////////////////////////////////////
    virtual eError SetParameter
    (const cString& name,
     const cString& expression)
    {
        eError error = e_ERROR_FAILED;
        if ((error = m_xsltParams.Add(name, expression)))
            c_DB_ERROR("() failed on m_xsltParams.Add(\"" << name << "\", \"" << expression << "\")");
        return error;
    }

    ///////////////////////////////////////////////////////////////////////
    //  Function: XsltGenericError
    //
    //    Author: $author$
    //      Date: 8/11/2011
    ///////////////////////////////////////////////////////////////////////
    static void XsltGenericError
    (void* context, const char* message, ...)
    {
        cCharWriterInterface* errors = 0;
        va_list va;
        va_start(va, message);
        if ((errors = (cCharWriterInterface*)(context)))
            errors->WriteFormattedV(message, va);
        va_end(va);
    }
    ///////////////////////////////////////////////////////////////////////
    //  Function: XmlGenericError
    //
    //    Author: $author$
    //      Date: 12/19/2012
    ///////////////////////////////////////////////////////////////////////
    static void XmlGenericError
    (void* context, const char* message, ...)
    {
        cCharWriterInterface* errors = 0;
        va_list va;
        va_start(va, message);
        if ((errors = (cCharWriterInterface*)(context)))
        if (!(DEFAULT_XSLT_PARSE_OPTIONS_XML_PARSE_NOERROR))
            errors->WriteFormattedV(message, va);
        va_end(va);
    }

    ///////////////////////////////////////////////////////////////////////
    //  Function: CharReaderIoRead
    //
    //    Author: $author$
    //      Date: 8/11/2011
    ///////////////////////////////////////////////////////////////////////
    static int CharReaderIoRead
    (void* context, char* buffer, int len)
    {
        int count = -1;
        cCharReaderInterface* reader;
        if ((buffer) && (0 <= len))
        if ((reader = (cCharReaderInterface*)(context)))
        if ((len))
            count = (int)(reader->Read(buffer, len));
        else count = 0;
        return count;
    }
    ///////////////////////////////////////////////////////////////////////
    //  Function: CharReaderIoClose
    //
    //    Author: $author$
    //      Date: 8/11/2011
    ///////////////////////////////////////////////////////////////////////
    static int CharReaderIoClose
    (void* context)
    {
        int err = 0;
        cCharReaderInterface* reader;
        if ((reader = (cCharReaderInterface*)(context)))
            reader->Fill();
        return err;
    }

    ///////////////////////////////////////////////////////////////////////
    //  Function: CharWriterIoWrite
    //
    //    Author: $author$
    //      Date: 7/6/2011
    ///////////////////////////////////////////////////////////////////////
    static int CharWriterIoWrite
    (void* context, const char* buffer, int len)
    {
        int count = -1;
        cCharWriterInterface* writer;
        if ((buffer) && (0 <= len))
        if ((writer = (cCharWriterInterface*)(context)))
        if ((count = len))
            len = (int)(writer->Write(buffer, len));
        return count;
    }
    ///////////////////////////////////////////////////////////////////////
    //  Function: CharWriterIoClose
    //
    //    Author: $author$
    //      Date: 7/6/2011
    ///////////////////////////////////////////////////////////////////////
    static int CharWriterIoClose
    (void* context)
    {
        int err = 0;
        cCharWriterInterface* writer;
        if ((writer = (cCharWriterInterface*)(context)))
            writer->Flush();
        return err;
    }
};


#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#else // !defined(CLIBXSLTXSLTPROCESSOR_MEMBERS_ONLY) 
#endif // !defined(CLIBXSLTXSLTPROCESSOR_MEMBERS_ONLY) 

#endif // !defined(_CLIBXSLTXSLTPROCESSOR_HPP) || defined(CLIBXSLTXSLTPROCESSOR_MEMBERS_ONLY) 
