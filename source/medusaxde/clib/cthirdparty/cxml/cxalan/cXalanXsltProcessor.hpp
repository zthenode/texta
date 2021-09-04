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
//   File: cXalanXsltProcessor.hpp
//
// Author: $author$
//   Date: 7/23/2011
///////////////////////////////////////////////////////////////////////
#if !defined(_CXALANXSLTPROCESSOR_HPP) || defined(CXALANXSLTPROCESSOR_MEMBERS_ONLY)
#if !defined(_CXALANXSLTPROCESSOR_HPP) && !defined(CXALANXSLTPROCESSOR_MEMBERS_ONLY)
#define _CXALANXSLTPROCESSOR_HPP
#endif // !defined(_CXALANXSLTPROCESSOR_HPP) && !defined(CXALANXSLTPROCESSOR_MEMBERS_ONLY) 

#if !defined(CXALANXSLTPROCESSOR_MEMBERS_ONLY)
#include "cXalanXsltProcessorInterface.hpp"
#include "cXsltProcessor.hpp"
#include "cXalanTransformer.hpp"
#include "cDebug.hpp"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

///////////////////////////////////////////////////////////////////////
// Typedef: cXalanXsltProcessorExtend
//
//  Author: $author$
//    Date: 7/23/2011
///////////////////////////////////////////////////////////////////////
typedef cXsltProcessor
cXalanXsltProcessorExtend;
///////////////////////////////////////////////////////////////////////
//  Class: cXalanXsltProcessor
//
// Author: $author$
//   Date: 7/23/2011
///////////////////////////////////////////////////////////////////////
class c_INSTANCE_CLASS cXalanXsltProcessor
: virtual public cXalanXsltProcessorImplement,
  public cXalanXsltProcessorExtend
{
public:
    typedef cXalanXsltProcessorImplement cImplements;
    typedef cXalanXsltProcessorExtend cExtends;

    cXalanTransformer m_xalan;

    ///////////////////////////////////////////////////////////////////////
    //  Constructor: cXalanXsltProcessor
    //
    //       Author: $author$
    //         Date: 7/23/2011
    ///////////////////////////////////////////////////////////////////////
    cXalanXsltProcessor()
    {
    }
    ///////////////////////////////////////////////////////////////////////
    //  Destructor: ~cXalanXsltProcessor
    //
    //      Author: $author$
    //        Date: 7/23/2011
    ///////////////////////////////////////////////////////////////////////
    virtual ~cXalanXsltProcessor()
    {
    }
#else // !defined(CXALANXSLTPROCESSOR_MEMBERS_ONLY) 
#endif // !defined(CXALANXSLTPROCESSOR_MEMBERS_ONLY) 

#if !defined(CXALANXSLTPROCESSOR_MEMBERS_ONLY)
    ///////////////////////////////////////////////////////////////////////
    //  Function: Init
    //
    //    Author: $author$
    //      Date: 7/24/2011
    ///////////////////////////////////////////////////////////////////////
    virtual eError Init()
    {
        eError error = e_ERROR_FAILED;
        if ((error = m_xalan.Initialize()))
            c_DB_ERROR("() failed on m_xalan.Initialize()");
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    //  Function: Finish
    //
    //    Author: $author$
    //      Date: 7/24/2011
    ///////////////////////////////////////////////////////////////////////
    virtual eError Finish()
    {
        eError error = e_ERROR_FAILED;
        if ((error = m_xalan.Finalize()))
            c_DB_ERROR("() failed on m_xalan.Finalize()");
        return error;
    }

    ///////////////////////////////////////////////////////////////////////
    //  Function: SetLiteralParameter
    //
    //    Author: $author$
    //      Date: 7/25/2011
    ///////////////////////////////////////////////////////////////////////
    virtual eError SetLiteralParameter
    (const cString& name,
     const cString& value)
    {
        eError error = e_ERROR_FAILED;
        const char* nameChars;
        const char* valueChars;
        if ((nameChars = name.HasChars()))
        if ((valueChars = value.Chars()))
        if ((error = m_xalan.SetLiteralParameter(nameChars, valueChars)))
            c_DB_ERROR("() failed on m_xalan.SetLiteralParameter(\"" << name << "\",\"" << value << "\")");
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    //  Function: SetParameter
    //
    //    Author: $author$
    //      Date: 7/25/2011
    ///////////////////////////////////////////////////////////////////////
    virtual eError SetParameter
    (const cString& name,
     const cString& expression)
    {
        eError error = e_ERROR_FAILED;
        const char* nameChars;
        const char* expressionChars;
        if ((nameChars = name.HasChars()))
        if ((expressionChars = expression.HasChars()))
        if ((error = m_xalan.SetParameter(nameChars, expressionChars)))
            c_DB_ERROR("() failed on m_xalan.SetParameter(\"" << name << "\", \"" << expression << "\")");
        return error;
    }

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
    {
        eError error = e_ERROR_FAILED;
        const char* xmlFileNameOrUrlChars;
        const char* xsltFileNameOrUrlChars;

        if ((xmlFileNameOrUrlChars = xmlFileNameOrUrl.Chars()))
        if ((xsltFileNameOrUrlChars = xsltFileNameOrUrl.Chars()))
        if ((error = m_xalan.Transform
            (xmlFileNameOrUrlChars, xsltFileNameOrUrlChars, result, errors)))
            c_DB_ERROR("() failed on m_xalan.Transform()");

        return error;
    }
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
    {
        eError error = e_ERROR_FAILED;
        const char* xmlFileNameOrUrlChars;
        const char* xsltFileNameOrUrlChars;

        if ((xmlFileNameOrUrlChars = xmlFileNameOrUrl.Chars()))
        if ((xsltFileNameOrUrlChars = xsltFileNameOrUrl.Chars()))
        if ((error = m_xalan.Transform
            (xmlFileNameOrUrlChars, xslt, xsltFileNameOrUrlChars, result, errors)))
            c_DB_ERROR("() failed on m_xalan.Transform()");

        return error;
    }
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
    {
        eError error = e_ERROR_FAILED;
        const char* xmlFileNameOrUrlChars;
        const char* xsltFileNameOrUrlChars;

        if ((xmlFileNameOrUrlChars = xmlFileNameOrUrl.Chars()))
        if ((xsltFileNameOrUrlChars = xsltFileNameOrUrl.Chars()))
        if ((error = m_xalan.Transform
            (xml, xmlFileNameOrUrlChars, xsltFileNameOrUrlChars, result, errors)))
            c_DB_ERROR("() failed on m_xalan.Transform()");

        return error;
    }
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
    {
        eError error = e_ERROR_FAILED;
        const char* xmlFileNameOrUrlChars;
        const char* xsltFileNameOrUrlChars;

        if ((xmlFileNameOrUrlChars = xmlFileNameOrUrl.Chars()))
        if ((xsltFileNameOrUrlChars = xsltFileNameOrUrl.Chars()))
        if ((error = m_xalan.Transform
            (xml, xmlFileNameOrUrlChars, 
             xslt, xsltFileNameOrUrlChars, result, errors)))
            c_DB_ERROR("() failed on m_xalan.Transform()");

        return error;
    }
};

#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#else // !defined(CXALANXSLTPROCESSOR_MEMBERS_ONLY) 
#endif // !defined(CXALANXSLTPROCESSOR_MEMBERS_ONLY) 

#endif // !defined(_CXALANXSLTPROCESSOR_HPP) || defined(CXALANXSLTPROCESSOR_MEMBERS_ONLY) 
