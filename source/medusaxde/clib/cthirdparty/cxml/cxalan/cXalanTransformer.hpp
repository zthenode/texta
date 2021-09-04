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
//   File: cXalanTransformer.hpp
//
// Author: $author$
//   Date: 7/18/2011
///////////////////////////////////////////////////////////////////////
#ifndef _CXALANTRANSFORMER_HPP
#define _CXALANTRANSFORMER_HPP

#include <XercesParserLiaison/XercesParserLiaison.hpp>
#include <XalanTransformer/XalanTransformer.hpp>

#include "cXalanXSLTResultTarget.hpp"
#include "cXalanXSLTInputSource.hpp"
#include "cXalanTransformerInitializer.hpp"
#include "cXercesErrorHandler.hpp"
#include "cDebug.hpp"

#define CXALANTRANSFORMER_LITERAL_QUOTE_CHARS "'"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

///////////////////////////////////////////////////////////////////////
// Typedef: cXalanTransformerExtend
//
//  Author: $author$
//    Date: 7/18/2011
///////////////////////////////////////////////////////////////////////
typedef nsXalan::XalanTransformer
cXalanTransformerExtend;
///////////////////////////////////////////////////////////////////////
//  Class: cXalanTransformer
//
// Author: $author$
//   Date: 7/18/2011
///////////////////////////////////////////////////////////////////////
class c_INSTANCE_CLASS cXalanTransformer
: //virtual public cXalanTransformerImplement,
  public cXalanTransformerExtend
{
public:
    //typedef cXalanTransformerImplement cImplements;
    typedef cXalanTransformerExtend cExtends;

    cXalanTransformerInitializerInterface *m_initializer;
    nsXerces::ErrorHandler *m_oldErrorHandler;
    cXercesErrorHandler m_errorHandler;

    nsXalan::XalanDOMString m_literalQuote;
    nsXalan::XalanDOMString m_paramName;
    nsXalan::XalanDOMString m_paramExpression;

    ///////////////////////////////////////////////////////////////////////
    //  Constructor: cXalanTransformer
    //
    //       Author: $author$
    //         Date: 7/18/2011
    ///////////////////////////////////////////////////////////////////////
    cXalanTransformer()
    : m_initializer(0),
      m_oldErrorHandler(0),
      m_literalQuote(CXALANTRANSFORMER_LITERAL_QUOTE_CHARS)
    {
    }
    ///////////////////////////////////////////////////////////////////////
    //  Destructor: ~cXalanTransformer
    //
    //      Author: $author$
    //        Date: 7/18/2011
    ///////////////////////////////////////////////////////////////////////
    virtual ~cXalanTransformer()
    {
        eError error;
        if ((error = Finalize()))
            throw (error);
    }

    ///////////////////////////////////////////////////////////////////////
    //  Function: Initialize
    //
    //    Author: $author$
    //      Date: 7/18/2011
    ///////////////////////////////////////////////////////////////////////
    virtual eError Initialize()
    {
        eError error = e_ERROR_FAILED;

        if (m_initializer)
            return e_ERROR_ALREADY_INITIALIZED;

		if (!(m_initializer = cXalanTransformerInitializer::GetInstance(error)))
            return error;

        m_oldErrorHandler = getErrorHandler();
        setErrorHandler(&m_errorHandler);
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    //  Function: Finalize
    //
    //    Author: $author$
    //      Date: 7/18/2011
    ///////////////////////////////////////////////////////////////////////
    virtual eError Finalize
    (bool onlyInitialized=false)
    {
        eError error = e_ERROR_FAILED;

        if (!m_initializer)
        if (onlyInitialized)
            return e_ERROR_NOT_INITIALIZED;
        else return e_ERROR_NONE;

        setErrorHandler(m_oldErrorHandler);
        m_oldErrorHandler = 0;

        error = cXalanTransformerInitializer::FreeInstance(m_initializer);
        m_initializer = 0;
        return error;
    }

    ///////////////////////////////////////////////////////////////////////
    //  Function: Transform
    //
    //    Author: $author$
    //      Date: 7/18/2011
    ///////////////////////////////////////////////////////////////////////
    virtual eError Transform
    (cCharReaderInterface& inputReader, const char* inputFileName, 
     cCharReaderInterface& stylesheetInputReader, const char* stylesheetInputFileName,
     cCharWriterInterface& output,
     cCharWriterInterface& errorMessage) 
    {
        eError error = e_ERROR_FAILED;
        cXalanXSLTInputSource input(inputReader, inputFileName);
        cXalanXSLTInputSource stylesheetInput(stylesheetInputReader, stylesheetInputFileName);
        cXalanXSLTResultTarget result(output);
        error = Transform
        (input, stylesheetInput, result, errorMessage);
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    //  Function: Transform
    //
    //    Author: $author$
    //      Date: 7/18/2011
    ///////////////////////////////////////////////////////////////////////
    virtual eError Transform
    (const char* inputFileName, 
     cCharReaderInterface& stylesheetInputReader, const char* stylesheetInputFileName,
     cCharWriterInterface& output,
     cCharWriterInterface& errorMessage) 
    {
        eError error = e_ERROR_FAILED;
        nsXalan::XSLTInputSource input(inputFileName);
        cXalanXSLTInputSource stylesheetInput(stylesheetInputReader, stylesheetInputFileName);
        cXalanXSLTResultTarget result(output);
        error = Transform
        (input, stylesheetInput, result, errorMessage);
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    //  Function: Transform
    //
    //    Author: $author$
    //      Date: 7/18/2011
    ///////////////////////////////////////////////////////////////////////
    virtual eError Transform
    (cCharReaderInterface& inputReader, const char* inputFileName, 
     const char* stylesheetInputFileName,
     cCharWriterInterface& output,
     cCharWriterInterface& errorMessage) 
    {
        eError error = e_ERROR_FAILED;
        cXalanXSLTInputSource input(inputReader, inputFileName);
        nsXalan::XSLTInputSource stylesheetInput(stylesheetInputFileName);
        cXalanXSLTResultTarget result(output);
        error = Transform
        (input, stylesheetInput, result, errorMessage);
        return error;
    }

    ///////////////////////////////////////////////////////////////////////
    //  Function: Transform
    //
    //    Author: $author$
    //      Date: 7/18/2011
    ///////////////////////////////////////////////////////////////////////
    virtual eError Transform
    (const char* inputFileName, 
     const char* stylesheetInputFileName,
     cCharWriterInterface& output,
     cCharWriterInterface& errorMessage) 
    {
        eError error = e_ERROR_FAILED;
        nsXalan::XSLTInputSource input(inputFileName);
        nsXalan::XSLTInputSource stylesheetInput(stylesheetInputFileName);
        cXalanXSLTResultTarget result(output);
        error = Transform
        (input, stylesheetInput, result, errorMessage);
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    //  Function: Transform
    //
    //    Author: $author$
    //      Date: 7/18/2011
    ///////////////////////////////////////////////////////////////////////
    virtual eError Transform
    (const nsXalan::XSLTInputSource &input, 
     const char* stylesheetInputFileName,
     cCharWriterInterface& output,
     cCharWriterInterface& errorMessage) 
    {
        eError error = e_ERROR_FAILED;
        nsXalan::XSLTInputSource stylesheetInput(stylesheetInputFileName);
        cXalanXSLTResultTarget result(output);
        error = Transform
        (input, stylesheetInput, result, errorMessage);
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    //  Function: Transform
    //
    //    Author: $author$
    //      Date: 7/18/2011
    ///////////////////////////////////////////////////////////////////////
    virtual eError Transform
    (const char* inputFileName, 
     const nsXalan::XSLTInputSource &stylesheetInput,
     cCharWriterInterface& output,
     cCharWriterInterface& errorMessage) 
    {
        eError error = e_ERROR_FAILED;
        nsXalan::XSLTInputSource input(inputFileName);
        cXalanXSLTResultTarget result(output);
        error = Transform
        (input, stylesheetInput, result, errorMessage);
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    //  Function: Transform
    //
    //    Author: $author$
    //      Date: 7/18/2011
    ///////////////////////////////////////////////////////////////////////
    virtual eError Transform
    (const nsXalan::XSLTInputSource &input, 
     const nsXalan::XSLTInputSource &stylesheetInput,
     nsXalan::XSLTResultTarget& result,
     cCharWriterInterface& errorMessage) 
    {
        eError error = e_ERROR_FAILED;

        try
        {
            int err;
            if ((err = transform(input, stylesheetInput, result)))
            {
                c_DB_ERROR("() err = " << err << " on transform()");
                const char* errorString;
                if ((errorString = getLastError()))
                    errorMessage.Write(errorString);
            }
            else
            error = e_ERROR_NONE;
        }
        catch (cXercesException& e)
        {
            c_DB_ERROR("() caught cXercesException");
            e.Write(errorMessage);
        }
        return error;
    }

    ///////////////////////////////////////////////////////////////////////
    //  Function: SetLiteralParameter
    //
    //    Author: $author$
    //      Date: 7/21/2011
    ///////////////////////////////////////////////////////////////////////
    virtual eError SetLiteralParameter
    (const char* name, const char* value)
    {
        eError error = e_ERROR_FAILED;
        if ((name) && (value))
        {
            m_paramName.assign(name);
            m_paramExpression.assign(m_literalQuote);
            m_paramExpression.append(value);
            m_paramExpression.append(m_literalQuote);
            error = SetParameter(m_paramName, m_paramExpression);
        }
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    //  Function: SetParameter
    //
    //    Author: $author$
    //      Date: 7/21/2011
    ///////////////////////////////////////////////////////////////////////
    virtual eError SetParameter
    (const char* name, const char* expression)
    {
        eError error = e_ERROR_FAILED;
        if ((name) && (expression))
        {
            m_paramName.assign(name);
            m_paramExpression.assign(expression);
            error = SetParameter(m_paramName, m_paramExpression);
        }
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    //  Function: SetParameter
    //
    //    Author: $author$
    //      Date: 7/21/2011
    ///////////////////////////////////////////////////////////////////////
    virtual eError SetParameter
    (const nsXalan::XalanDOMString& name, 
     const nsXalan::XalanDOMString& expression)
    {
        eError error = e_ERROR_NONE;
        setStylesheetParam(name, expression);
        return error;
    }
};

#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#endif // _CXALANTRANSFORMER_HPP 
