/**
 **********************************************************************
 * Copyright (c) 1988-2008 $organization$
 *
 * This software is provided by the author and contributors ``as is'' 
 * and any express or implied warranties, including, but not limited to, 
 * the implied warranties of merchantability and fitness for a particular 
 * purpose are disclaimed. In no event shall the author or contributors 
 * be liable for any direct, indirect, incidental, special, exemplary, 
 * or consequential damages (including, but not limited to, procurement 
 * of substitute goods or services; loss of use, data, or profits; or 
 * business interruption) however caused and on any theory of liability, 
 * whether in contract, strict liability, or tort (including negligence 
 * or otherwise) arising in any way out of the use of this software, 
 * even if advised of the possibility of such damage.
 *
 *   File: cxalantransformer.hxx
 *
 * Author: $author$
 *   Date: 3/9/2008
 **********************************************************************
 */
#ifndef _CXALANTRANSFORMER_HXX
#define _CXALANTRANSFORMER_HXX

#include <XercesParserLiaison/XercesParserLiaison.hpp>
#include <XalanTransformer/XalanTransformer.hpp>

#include "cxalantransformerinitializer.hxx"
#include "cxerceserrorhandler.hxx"
#include "cxalanparameter.hxx"

#define CXALANTRANSFORMER_LITERAL_QUOTE_CHARS "'"

/**
 **********************************************************************
 *  Class: cXalanTransformer
 *
 * Author: $author$
 *   Date: 3/9/2008
 **********************************************************************
 */
class cXalanTransformer
: public nsXalan::XalanTransformer
{
public:
    typedef nsXalan::XalanTransformer cExtends;
    typedef cXalanTransformer cDerives;

    const char* m_literalQuoteChars;
    cXalanTransformerInitializer *m_initializer;
    nsXerces::ErrorHandler *m_oldErrorHandler;
    cXercesErrorHandler m_errorHandler;

    cCharString m_literalExpression;

    /**
     **********************************************************************
     * Constructor: cXalanTransformer
     *
     *      Author: $author$
     *        Date: 3/9/2008
     **********************************************************************
     */
    cXalanTransformer() 
    : m_literalQuoteChars(CXALANTRANSFORMER_LITERAL_QUOTE_CHARS),
      m_initializer(0),
      m_oldErrorHandler(0)
    {
    }
    /**
     **********************************************************************
     * Destructor: cXalanTransformer
     *
     *     Author: $author$
     *       Date: 3/9/2008
     **********************************************************************
     */
    virtual ~cXalanTransformer()
    {
        eError error;
        if (m_initializer)
        if ((error = Finalize(true)))
            throw(error);
    }
    /**
     **********************************************************************
     * Function: Initialize
     *
     *   Author: $author$
     *     Date: 3/9/2008
     **********************************************************************
     */
    virtual eError Initialize() 
    {
        eError error = e_ERROR_NONE;

        if (m_initializer)
            return e_ERROR_ALREADY_INITIALIZED;

		if (!(m_initializer = cXalanTransformerInitializer::GetInstance(error)))
            return error;

        m_oldErrorHandler = getErrorHandler();
        setErrorHandler(&m_errorHandler);
        return error;
    }
    /**
     **********************************************************************
     * Function: Finalize
     *
     *   Author: $author$
     *     Date: 3/9/2008
     **********************************************************************
     */
    virtual eError Finalize
    (bool onlyInitialized=false) 
    {
        eError error = e_ERROR_NONE;

        if (!m_initializer)
        if (onlyInitialized)
            return e_ERROR_NOT_INITIALIZED;
        else return e_ERROR_NONE;

        setErrorHandler(m_oldErrorHandler);
        m_oldErrorHandler = 0;

        error = m_initializer->FreeInstance();
        m_initializer = 0;
        return error;
    }
    /**
     **********************************************************************
     * Function: Transform
     *
     *   Author: $author$
     *     Date: 3/11/2008
     **********************************************************************
     */
    virtual eError Transform
    (const char* inputFilename, 
     const char* stylesheetInputFilename,
     nsXalan::XSLTResultTarget& output,
     cCharString* errorMessage=0) 
    {
        nsXalan::XSLTInputSource input(inputFilename);
        nsXalan::XSLTInputSource stylesheetInput(stylesheetInputFilename);
        eError error = Transform
        (input, stylesheetInput, output, errorMessage);
        return error;
    }
    /**
     **********************************************************************
     * Function: Transform
     *
     *   Author: $author$
     *     Date: 3/11/2008
     **********************************************************************
     */
    virtual eError Transform
    (const nsXalan::XSLTInputSource &input, 
     const char* stylesheetInputFilename,
     nsXalan::XSLTResultTarget& output,
     cCharString* errorMessage=0) 
    {
        nsXalan::XSLTInputSource stylesheetInput(stylesheetInputFilename);
        eError error = Transform
        (input, stylesheetInput, output, errorMessage);
        return error;
    }
    /**
     **********************************************************************
     * Function: Transform
     *
     *   Author: $author$
     *     Date: 3/11/2008
     **********************************************************************
     */
    virtual eError Transform
    (const nsXalan::XSLTInputSource &input, 
     const nsXalan::XSLTInputSource &stylesheetInput,
     nsXalan::XSLTResultTarget& output,
     cCharString* errorMessage=0) 
    {
        const char* errorString;
        int err;

        try
        {
            err = transform(input, stylesheetInput, output);

            if (err)
            {
                if (errorMessage)
                if ((errorString = getLastError()))
                    errorMessage->append(errorString);

                return e_ERROR_FAILED;
            }
        }
        catch(cXercesException& e)
        {
            if (errorMessage)
                e.ToString(*errorMessage);
            return e_ERROR_FAILED;
        }
        return e_ERROR_NONE;
    }
    /**
     **********************************************************************
     * Function: SetLiteralParameters
     *
     *   Author: $author$
     *     Date: 3/13/2008
     **********************************************************************
     */
    virtual eError SetLiteralParameters
    (const cXalanParameters& params) 
    {
        eError error = e_ERROR_NONE;
		cXalanParameters::const_iterator i;

		for (i=params.begin(); i!=params.end(); i++)
			if ((error = SetLiteralParameter(**i)))
                break;
        return error;
    }
    /**
     **********************************************************************
     * Function: SetParameters
     *
     *   Author: $author$
     *     Date: 3/13/2008
     **********************************************************************
     */
    virtual eError SetParameters
    (const cXalanParameters& params) 
    {
        eError error = e_ERROR_NONE;
		cXalanParameters::const_iterator i;

		for (i=params.begin(); i!=params.end(); i++)
			if ((error = SetParameter(**i)))
                break;
        return error;
    }
    /**
     **********************************************************************
     * Function: SetLiteralParameter
     *
     *   Author: $author$
     *     Date: 3/13/2008
     **********************************************************************
     */
    virtual eError SetLiteralParameter
    (const cXalanParameter& param) 
    {
        eError error = e_ERROR_FAILED;
        const char* name;
        const char* value;
        TLENGTH count;
        if ((name = param.GetName(count)))
        if ((value = param.GetValue(count)))
            error = SetLiteralParameter(name, value);
        return error;
    }
    /**
     **********************************************************************
     * Function: SetParameter
     *
     *   Author: $author$
     *     Date: 3/13/2008
     **********************************************************************
     */
    virtual eError SetParameter
    (const cXalanParameter& param) 
    {
        eError error = e_ERROR_FAILED;
        const char* name;
        const char* value;
        TLENGTH count;
        if ((name = param.GetName(count)))
        if ((value = param.GetValue(count)))
            error = SetParameter(name, value);
        return error;
    }
    /**
     **********************************************************************
     * Function: SetLiteralParameter
     *
     *   Author: $author$
     *     Date: 3/13/2008
     **********************************************************************
     */
    virtual eError SetLiteralParameter
    (const char* name, const char* value, 
     const char* literalQuoteChars=0) 
    {
        eError error = e_ERROR_FAILED;
        const char* literalExpressionChars;
        TLENGTH count;

        if (!literalQuoteChars)
            literalQuoteChars = m_literalQuoteChars;

        if (!literalQuoteChars)
            error = SetParameter(name, value);
        else
        {
            if (0 <= (count = m_literalExpression.Assign(literalQuoteChars)))
            if (0 <= (count = m_literalExpression.Append(value)))
            if (0 <= (count = m_literalExpression.Append(literalQuoteChars)))
            if ((literalExpressionChars = m_literalExpression.Chars(count)))
                error = SetParameter(name, literalExpressionChars);
        }
        return error;
    }
    /**
     **********************************************************************
     * Function: SetParameter
     *
     *   Author: $author$
     *     Date: 3/13/2008
     **********************************************************************
     */
    virtual eError SetParameter
    (const char* name, const char* value) 
    {
        eError error = e_ERROR_NONE;
        setStylesheetParam(name, value);
        return error;
    }
};
#endif /* _CXALANTRANSFORMER_HXX */
