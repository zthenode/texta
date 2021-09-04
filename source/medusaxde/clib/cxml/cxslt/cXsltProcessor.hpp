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
//   File: cXsltProcessor.hpp
//
// Author: $author$
//   Date: 7/1/2011
///////////////////////////////////////////////////////////////////////
#if !defined(_CXSLTPROCESSOR_HPP) || defined(CXSLTPROCESSOR_MEMBERS_ONLY)
#if !defined(_CXSLTPROCESSOR_HPP) && !defined(CXSLTPROCESSOR_MEMBERS_ONLY)
#define _CXSLTPROCESSOR_HPP
#endif // !defined(_CXSLTPROCESSOR_HPP) && !defined(CXSLTPROCESSOR_MEMBERS_ONLY) 

#if !defined(CXSLTPROCESSOR_MEMBERS_ONLY)
#include "cXsltProcessorInterface.hpp"
#include "cInstanceBase.hpp"
#include "cDebug.hpp"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

typedef cInstanceBase cXsltProcessorExtend;
///////////////////////////////////////////////////////////////////////
//  Class: cXsltProcessor
//
// Author: $author$
//   Date: 7/1/2011
///////////////////////////////////////////////////////////////////////
class c_INSTANCE_CLASS cXsltProcessor
: virtual public cXsltProcessorImplement,
  public cXsltProcessorExtend
{
public:
    typedef cXsltProcessorImplement cImplements;
    typedef cXsltProcessorExtend cExtends;
    ///////////////////////////////////////////////////////////////////////
    //  Constructor: cXsltProcessor
    //
    //       Author: $author$
    //         Date: 7/1/2011
    ///////////////////////////////////////////////////////////////////////
    cXsltProcessor()
    {
    }
    ///////////////////////////////////////////////////////////////////////
    //  Destructor: ~cXsltProcessor
    //
    //      Author: $author$
    //        Date: 7/1/2011
    ///////////////////////////////////////////////////////////////////////
    virtual ~cXsltProcessor()
    {
    }
#else // !defined(CXSLTPROCESSOR_MEMBERS_ONLY) 
#endif // !defined(CXSLTPROCESSOR_MEMBERS_ONLY) 

    ///////////////////////////////////////////////////////////////////////
    //  Function: Init
    //
    //    Author: $author$
    //      Date: 7/1/2011
    ///////////////////////////////////////////////////////////////////////
    virtual eError Init()
#if defined(CXSLTPROCESSOR_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CXSLTPROCESSOR_MEMBER_FUNCS_INTERFACE) 
    {
        eError error = e_ERROR_NONE;
#if !defined(CXSLTPROCESSOR_MEMBER_FUNCS_IMPLEMENT)
#else // !defined(CXSLTPROCESSOR_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CXSLTPROCESSOR_MEMBER_FUNCS_IMPLEMENT) 
        return error;
    }
#endif // defined(CXSLTPROCESSOR_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    //  Function: Finish
    //
    //    Author: $author$
    //      Date: 7/1/2011
    ///////////////////////////////////////////////////////////////////////
    virtual eError Finish()
#if defined(CXSLTPROCESSOR_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CXSLTPROCESSOR_MEMBER_FUNCS_INTERFACE) 
    {
        eError error = e_ERROR_NONE;
#if !defined(CXSLTPROCESSOR_MEMBER_FUNCS_IMPLEMENT)
#else // !defined(CXSLTPROCESSOR_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CXSLTPROCESSOR_MEMBER_FUNCS_IMPLEMENT) 
        return error;
    }
#endif // defined(CXSLTPROCESSOR_MEMBER_FUNCS_INTERFACE) 

    ///////////////////////////////////////////////////////////////////////
    //  Function: SetParameters
    //
    //    Author: $author$
    //      Date: 7/25/2011
    ///////////////////////////////////////////////////////////////////////
    virtual eError SetParameters
    (const cXsltParamsInterface& params)
#if defined(CXSLTPROCESSOR_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CXSLTPROCESSOR_MEMBER_FUNCS_INTERFACE) 
    {
        eError error = e_ERROR_FAILED;
#if !defined(CXSLTPROCESSOR_MEMBER_FUNCS_IMPLEMENT)
        cXsltParamsIterator& i = params.Iterator();
        const cXsltParamInterface* p;
        for (error = e_ERROR_NONE, 
             p = params.GetFirst(i); p; p = params.GetNext(i))
        {
            bool isLiteral = false;
            const cString& expression = p->GetExpression(isLiteral);
            const cString& name = p->GetName();

            c_DB_TRACE("() name = \"" << name << "\" expression = \"" << expression << "\"");

            if ((isLiteral))
            {
                if ((error = SetLiteralParameter(name, expression)))
                {
                    c_DB_ERROR("() failed on SetLiteralParameter(\"" << name << "\",\"" << expression << "\")");
                    break;
                }
            }
            else
            if ((error = SetLiteralParameter(name, expression)))
            {
                c_DB_ERROR("() failed on SetLiteralParameter(\"" << name << "\",\"" << expression << "\")");
                break;
            }
        }
#else // !defined(CXSLTPROCESSOR_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CXSLTPROCESSOR_MEMBER_FUNCS_IMPLEMENT) 
        return error;
    }
#endif // defined(CXSLTPROCESSOR_MEMBER_FUNCS_INTERFACE) 

    ///////////////////////////////////////////////////////////////////////
    //  Function: SetLiteralParameter
    //
    //    Author: $author$
    //      Date: 7/1/2011
    ///////////////////////////////////////////////////////////////////////
    virtual eError SetLiteralParameter
    (const cString& name,
     const cString& value)
#if defined(CXSLTPROCESSOR_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CXSLTPROCESSOR_MEMBER_FUNCS_INTERFACE) 
    {
        eError error = e_ERROR_FAILED;
#if !defined(CXSLTPROCESSOR_MEMBER_FUNCS_IMPLEMENT)
        c_DB_ERROR("() not implemented");
#else // !defined(CXSLTPROCESSOR_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CXSLTPROCESSOR_MEMBER_FUNCS_IMPLEMENT) 
        return error;
    }
#endif // defined(CXSLTPROCESSOR_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    //  Function: SetParameter
    //
    //    Author: $author$
    //      Date: 7/1/2011
    ///////////////////////////////////////////////////////////////////////
    virtual eError SetParameter
    (const cString& name,
     const cString& expression)
#if defined(CXSLTPROCESSOR_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CXSLTPROCESSOR_MEMBER_FUNCS_INTERFACE) 
    {
        eError error = e_ERROR_FAILED;
#if !defined(CXSLTPROCESSOR_MEMBER_FUNCS_IMPLEMENT)
        c_DB_ERROR("() not implemented");
#else // !defined(CXSLTPROCESSOR_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CXSLTPROCESSOR_MEMBER_FUNCS_IMPLEMENT) 
        return error;
    }
#endif // defined(CXSLTPROCESSOR_MEMBER_FUNCS_INTERFACE) 

    ///////////////////////////////////////////////////////////////////////
    //  Function: ProcessXsltFile
    //
    //    Author: $author$
    //      Date: 7/1/2011
    ///////////////////////////////////////////////////////////////////////
    virtual eError ProcessXsltFile
    (cCharWriterInterface& errors,
     cCharWriterInterface& result,
     const cString& xsltFileName,
     cCharReaderInterface& xml, const cString& xmlFileNameOrUrl)
#if defined(CXSLTPROCESSOR_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CXSLTPROCESSOR_MEMBER_FUNCS_INTERFACE) 
    {
        eError error = e_ERROR_FAILED;
#if !defined(CXSLTPROCESSOR_MEMBER_FUNCS_IMPLEMENT)
        error = Process(errors, result, xsltFileName, xml, xmlFileNameOrUrl);
#else // !defined(CXSLTPROCESSOR_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CXSLTPROCESSOR_MEMBER_FUNCS_IMPLEMENT) 
        return error;
    }
#endif // defined(CXSLTPROCESSOR_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    //  Function: ProcessXmlFile
    //
    //    Author: $author$
    //      Date: 7/1/2011
    ///////////////////////////////////////////////////////////////////////
    virtual eError ProcessXmlFile
    (cCharWriterInterface& errors,
     cCharWriterInterface& result,
     cCharReaderInterface& xslt, const cString& xsltFileNameOrUrl,
     const cString& xmlFileName)
#if defined(CXSLTPROCESSOR_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CXSLTPROCESSOR_MEMBER_FUNCS_INTERFACE) 
    {
        eError error = e_ERROR_FAILED;
#if !defined(CXSLTPROCESSOR_MEMBER_FUNCS_IMPLEMENT)
        error = Process(errors, result, xslt, xsltFileNameOrUrl, xmlFileName);
#else // !defined(CXSLTPROCESSOR_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CXSLTPROCESSOR_MEMBER_FUNCS_IMPLEMENT) 
        return error;
    }
#endif // defined(CXSLTPROCESSOR_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    //  Function: ProcessFiles
    //
    //    Author: $author$
    //      Date: 7/1/2011
    ///////////////////////////////////////////////////////////////////////
    virtual eError ProcessFiles
    (cCharWriterInterface& errors,
     cCharWriterInterface& result, 
     const cString& xsltFileName, 
     const cString& xmlFileName)
#if defined(CXSLTPROCESSOR_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CXSLTPROCESSOR_MEMBER_FUNCS_INTERFACE) 
    {
        eError error = e_ERROR_FAILED;
#if !defined(CXSLTPROCESSOR_MEMBER_FUNCS_IMPLEMENT)
        error = Process(errors, result, xsltFileName, xmlFileName);
#else // !defined(CXSLTPROCESSOR_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CXSLTPROCESSOR_MEMBER_FUNCS_IMPLEMENT) 
        return error;
    }
#endif // defined(CXSLTPROCESSOR_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    //  Function: Process
    //
    //    Author: $author$
    //      Date: 7/1/2011
    ///////////////////////////////////////////////////////////////////////
    virtual eError Process
    (cCharWriterInterface& errors,
     cCharWriterInterface& result,
     const cString& xsltFileNameOrUrl,
     const cString& xmlFileNameOrUrl)
#if defined(CXSLTPROCESSOR_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CXSLTPROCESSOR_MEMBER_FUNCS_INTERFACE) 
    {
        eError error = e_ERROR_FAILED;
#if !defined(CXSLTPROCESSOR_MEMBER_FUNCS_IMPLEMENT)
        c_DB_ERROR("() not implemented");
#else // !defined(CXSLTPROCESSOR_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CXSLTPROCESSOR_MEMBER_FUNCS_IMPLEMENT) 
        return error;
    }
#endif // defined(CXSLTPROCESSOR_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    //  Function: Process
    //
    //    Author: $author$
    //      Date: 7/1/2011
    ///////////////////////////////////////////////////////////////////////
    virtual eError Process
    (cCharWriterInterface& errors,
     cCharWriterInterface& result,
     const cString& xsltFileNameOrUrl,
     cCharReaderInterface& xml, const cString& xmlFileNameOrUrl)
#if defined(CXSLTPROCESSOR_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CXSLTPROCESSOR_MEMBER_FUNCS_INTERFACE) 
    {
        eError error = e_ERROR_FAILED;
#if !defined(CXSLTPROCESSOR_MEMBER_FUNCS_IMPLEMENT)
        c_DB_ERROR("() not implemented");
#else // !defined(CXSLTPROCESSOR_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CXSLTPROCESSOR_MEMBER_FUNCS_IMPLEMENT) 
        return error;
    }
#endif // defined(CXSLTPROCESSOR_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    //  Function: Process
    //
    //    Author: $author$
    //      Date: 7/1/2011
    ///////////////////////////////////////////////////////////////////////
    virtual eError Process
    (cCharWriterInterface& errors,
     cCharWriterInterface& result,
     cCharReaderInterface& xslt, const cString& xsltFileNameOrUrl,
     const cString& xmlFileNameOrUrl)
#if defined(CXSLTPROCESSOR_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CXSLTPROCESSOR_MEMBER_FUNCS_INTERFACE) 
    {
        eError error = e_ERROR_FAILED;
#if !defined(CXSLTPROCESSOR_MEMBER_FUNCS_IMPLEMENT)
        c_DB_ERROR("() not implemented");
#else // !defined(CXSLTPROCESSOR_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CXSLTPROCESSOR_MEMBER_FUNCS_IMPLEMENT) 
        return error;
    }
#endif // defined(CXSLTPROCESSOR_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    //  Function: Process
    //
    //    Author: $author$
    //      Date: 7/1/2011
    ///////////////////////////////////////////////////////////////////////
    virtual eError Process
    (cCharWriterInterface& errors,
     cCharWriterInterface& result,
     cCharReaderInterface& xslt, const cString& xsltFileNameOrUrl,
     cCharReaderInterface& xml, const cString& xmlFileNameOrUrl)
#if defined(CXSLTPROCESSOR_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CXSLTPROCESSOR_MEMBER_FUNCS_INTERFACE) 
    {
        eError error = e_ERROR_FAILED;
#if !defined(CXSLTPROCESSOR_MEMBER_FUNCS_IMPLEMENT)
        c_DB_ERROR("() not implemented");
#else // !defined(CXSLTPROCESSOR_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CXSLTPROCESSOR_MEMBER_FUNCS_IMPLEMENT) 
        return error;
    }
#endif // defined(CXSLTPROCESSOR_MEMBER_FUNCS_INTERFACE) 

    ///////////////////////////////////////////////////////////////////////
    //  Function: LoadStyleSheetFile
    //
    //    Author: $author$
    //      Date: 7/1/2011
    ///////////////////////////////////////////////////////////////////////
    virtual cXsltStyleSheetInterface* LoadStyleSheetFile
    (const cString& fileName)
#if defined(CXSLTPROCESSOR_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CXSLTPROCESSOR_MEMBER_FUNCS_INTERFACE) 
    {
        cXsltStyleSheetInterface* styleSheet = 0;
#if !defined(CXSLTPROCESSOR_MEMBER_FUNCS_IMPLEMENT)
        c_DB_ERROR("() not implemented");
#else // !defined(CXSLTPROCESSOR_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CXSLTPROCESSOR_MEMBER_FUNCS_IMPLEMENT) 
        return styleSheet;
    }
#endif // defined(CXSLTPROCESSOR_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    //  Function: LoadStyleSheet
    //
    //    Author: $author$
    //      Date: 7/1/2011
    ///////////////////////////////////////////////////////////////////////
    virtual cXsltStyleSheetInterface* LoadStyleSheet
    (const cString& fileNameOrUrl)
#if defined(CXSLTPROCESSOR_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CXSLTPROCESSOR_MEMBER_FUNCS_INTERFACE) 
    {
        cXsltStyleSheetInterface* styleSheet = 0;
#if !defined(CXSLTPROCESSOR_MEMBER_FUNCS_IMPLEMENT)
        c_DB_ERROR("() not implemented");
#else // !defined(CXSLTPROCESSOR_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CXSLTPROCESSOR_MEMBER_FUNCS_IMPLEMENT) 
        return styleSheet;
    }
#endif // defined(CXSLTPROCESSOR_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    //  Function: LoadStyleSheet
    //
    //    Author: $author$
    //      Date: 7/1/2011
    ///////////////////////////////////////////////////////////////////////
    virtual cXsltStyleSheetInterface* LoadStyleSheet
    (cCharReaderInterface& reader, const cString& fileNameOrUrl)
#if defined(CXSLTPROCESSOR_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CXSLTPROCESSOR_MEMBER_FUNCS_INTERFACE) 
    {
        cXsltStyleSheetInterface* styleSheet = 0;
#if !defined(CXSLTPROCESSOR_MEMBER_FUNCS_IMPLEMENT)
        c_DB_ERROR("() not implemented");
#else // !defined(CXSLTPROCESSOR_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CXSLTPROCESSOR_MEMBER_FUNCS_IMPLEMENT) 
        return styleSheet;
    }
#endif // defined(CXSLTPROCESSOR_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    //  Function: UnloadStyleSheet
    //
    //    Author: $author$
    //      Date: 7/1/2011
    ///////////////////////////////////////////////////////////////////////
    virtual eError UnloadStyleSheet
    (cXsltStyleSheetInterface* styleSheet)
#if defined(CXSLTPROCESSOR_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CXSLTPROCESSOR_MEMBER_FUNCS_INTERFACE) 
    {
        eError error = e_ERROR_FAILED;
#if !defined(CXSLTPROCESSOR_MEMBER_FUNCS_IMPLEMENT)
        c_DB_ERROR("() not implemented");
#else // !defined(CXSLTPROCESSOR_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CXSLTPROCESSOR_MEMBER_FUNCS_IMPLEMENT) 
        return error;
    }
#endif // defined(CXSLTPROCESSOR_MEMBER_FUNCS_INTERFACE) 

    ///////////////////////////////////////////////////////////////////////
    //  Function: LoadDocumentFile
    //
    //    Author: $author$
    //      Date: 7/1/2011
    ///////////////////////////////////////////////////////////////////////
    virtual cXsltDocumentInterface* LoadDocumentFile
    (const cString& fileName)
#if defined(CXSLTPROCESSOR_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CXSLTPROCESSOR_MEMBER_FUNCS_INTERFACE) 
    {
        cXsltDocumentInterface* document = 0;
#if !defined(CXSLTPROCESSOR_MEMBER_FUNCS_IMPLEMENT)
        c_DB_ERROR("() not implemented");
#else // !defined(CXSLTPROCESSOR_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CXSLTPROCESSOR_MEMBER_FUNCS_IMPLEMENT) 
        return document;
    }
#endif // defined(CXSLTPROCESSOR_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    //  Function: LoadDocument
    //
    //    Author: $author$
    //      Date: 7/1/2011
    ///////////////////////////////////////////////////////////////////////
    virtual cXsltDocumentInterface* LoadDocument
    (const cString& fileNameOrUrl)
#if defined(CXSLTPROCESSOR_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CXSLTPROCESSOR_MEMBER_FUNCS_INTERFACE) 
    {
        cXsltDocumentInterface* document = 0;
#if !defined(CXSLTPROCESSOR_MEMBER_FUNCS_IMPLEMENT)
        c_DB_ERROR("() not implemented");
#else // !defined(CXSLTPROCESSOR_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CXSLTPROCESSOR_MEMBER_FUNCS_IMPLEMENT) 
        return document;
    }
#endif // defined(CXSLTPROCESSOR_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    //  Function: LoadDocument
    //
    //    Author: $author$
    //      Date: 7/1/2011
    ///////////////////////////////////////////////////////////////////////
    virtual cXsltDocumentInterface* LoadDocument
    (cCharReaderInterface& reader, const cString& fileNameOrUrl)
#if defined(CXSLTPROCESSOR_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CXSLTPROCESSOR_MEMBER_FUNCS_INTERFACE) 
    {
        cXsltDocumentInterface* document = 0;
#if !defined(CXSLTPROCESSOR_MEMBER_FUNCS_IMPLEMENT)
        c_DB_ERROR("() not implemented");
#else // !defined(CXSLTPROCESSOR_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CXSLTPROCESSOR_MEMBER_FUNCS_IMPLEMENT) 
        return document;
    }
#endif // defined(CXSLTPROCESSOR_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    //  Function: UnloadDocument
    //
    //    Author: $author$
    //      Date: 7/1/2011
    ///////////////////////////////////////////////////////////////////////
    virtual eError UnloadDocument
    (cXsltDocumentInterface* document)
#if defined(CXSLTPROCESSOR_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CXSLTPROCESSOR_MEMBER_FUNCS_INTERFACE) 
    {
        eError error = e_ERROR_FAILED;
#if !defined(CXSLTPROCESSOR_MEMBER_FUNCS_IMPLEMENT)
        c_DB_ERROR("() not implemented");
#else // !defined(CXSLTPROCESSOR_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CXSLTPROCESSOR_MEMBER_FUNCS_IMPLEMENT) 
        return error;
    }
#endif // defined(CXSLTPROCESSOR_MEMBER_FUNCS_INTERFACE) 

    ///////////////////////////////////////////////////////////////////////
    //  Function: LoadExtensionFunction
    //
    //    Author: $author$
    //      Date: 7/1/2011
    ///////////////////////////////////////////////////////////////////////
    virtual cXsltExtensionFunctionInterface* LoadExtensionFunction
    (const cString& namespaceUri,
     const cString& functionName,
     const cString& fileName)
#if defined(CXSLTPROCESSOR_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CXSLTPROCESSOR_MEMBER_FUNCS_INTERFACE) 
    {
        cXsltExtensionFunctionInterface* extensionFunction = 0;
#if !defined(CXSLTPROCESSOR_MEMBER_FUNCS_IMPLEMENT)
        c_DB_ERROR("() not implemented");
#else // !defined(CXSLTPROCESSOR_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CXSLTPROCESSOR_MEMBER_FUNCS_IMPLEMENT) 
        return extensionFunction;
    }
#endif // defined(CXSLTPROCESSOR_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    //  Function: UnloadExtensionFunction
    //
    //    Author: $author$
    //      Date: 7/1/2011
    ///////////////////////////////////////////////////////////////////////
    virtual eError UnloadExtensionFunction
    (cXsltExtensionFunctionInterface* extensionFunction)
#if defined(CXSLTPROCESSOR_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CXSLTPROCESSOR_MEMBER_FUNCS_INTERFACE) 
    {
        eError error = e_ERROR_FAILED;
#if !defined(CXSLTPROCESSOR_MEMBER_FUNCS_IMPLEMENT)
        c_DB_ERROR("() not implemented");
#else // !defined(CXSLTPROCESSOR_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CXSLTPROCESSOR_MEMBER_FUNCS_IMPLEMENT) 
        return error;
    }
#endif // defined(CXSLTPROCESSOR_MEMBER_FUNCS_INTERFACE) 

    ///////////////////////////////////////////////////////////////////////
    //  Function: LoadExtensionModule
    //
    //    Author: $author$
    //      Date: 7/1/2011
    ///////////////////////////////////////////////////////////////////////
    virtual cXsltExtensionModuleInterface* LoadExtensionModule
    (const cString& namespaceUri,
     const cString& fileName)
#if defined(CXSLTPROCESSOR_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CXSLTPROCESSOR_MEMBER_FUNCS_INTERFACE) 
    {
        cXsltExtensionModuleInterface* extensionModule = 0;
#if !defined(CXSLTPROCESSOR_MEMBER_FUNCS_IMPLEMENT)
        c_DB_ERROR("() not implemented");
#else // !defined(CXSLTPROCESSOR_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CXSLTPROCESSOR_MEMBER_FUNCS_IMPLEMENT) 
        return extensionModule;
    }
#endif // defined(CXSLTPROCESSOR_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    //  Function: UnloadExtensionModule
    //
    //    Author: $author$
    //      Date: 7/1/2011
    ///////////////////////////////////////////////////////////////////////
    virtual eError UnloadExtensionModule
    (cXsltExtensionModuleInterface* extensionModule)
#if defined(CXSLTPROCESSOR_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CXSLTPROCESSOR_MEMBER_FUNCS_INTERFACE) 
    {
        eError error = e_ERROR_FAILED;
#if !defined(CXSLTPROCESSOR_MEMBER_FUNCS_IMPLEMENT)
        c_DB_ERROR("() not implemented");
#else // !defined(CXSLTPROCESSOR_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CXSLTPROCESSOR_MEMBER_FUNCS_IMPLEMENT) 
        return error;
    }
#endif // defined(CXSLTPROCESSOR_MEMBER_FUNCS_INTERFACE) 

#if defined(CXSLTPROCESSOR_MEMBER_FUNCS_INTERFACE)
    ///////////////////////////////////////////////////////////////////////
    //  Function: Implemented
    //
    //    Author: $author$
    //      Date: 7/1/2011
    ///////////////////////////////////////////////////////////////////////
    virtual cXsltProcessorImplemented* Implemented() const
    = 0;
#else // defined(CXSLTPROCESSOR_MEMBER_FUNCS_INTERFACE) 
#endif // defined(CXSLTPROCESSOR_MEMBER_FUNCS_INTERFACE) 
#if defined(CXSLTPROCESSOR_MEMBER_FUNCS_INTERFACE)
    ///////////////////////////////////////////////////////////////////////
    //  Function: GetInstance
    //
    //    Author: $author$
    //      Date: 7/1/2011
    ///////////////////////////////////////////////////////////////////////
    static cXsltProcessorInterface* GetInstance(eError& error);
#else // defined(CXSLTPROCESSOR_MEMBER_FUNCS_INTERFACE) 
#endif // defined(CXSLTPROCESSOR_MEMBER_FUNCS_INTERFACE) 
#if defined(CXSLTPROCESSOR_MEMBER_FUNCS_INTERFACE)
    ///////////////////////////////////////////////////////////////////////
    //  Function: FreeInstance
    //
    //    Author: $author$
    //      Date: 7/1/2011
    ///////////////////////////////////////////////////////////////////////
    static eError FreeInstance(cXsltProcessorInterface* instance);
#else // defined(CXSLTPROCESSOR_MEMBER_FUNCS_INTERFACE) 
#endif // defined(CXSLTPROCESSOR_MEMBER_FUNCS_INTERFACE) 

#if !defined(CXSLTPROCESSOR_MEMBERS_ONLY)
};


#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#else // !defined(CXSLTPROCESSOR_MEMBERS_ONLY) 
#endif // !defined(CXSLTPROCESSOR_MEMBERS_ONLY) 

#endif // !defined(_CXSLTPROCESSOR_HPP) || defined(CXSLTPROCESSOR_MEMBERS_ONLY) 
