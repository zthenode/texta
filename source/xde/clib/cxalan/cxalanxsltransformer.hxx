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
 *   File: cxalanxsltransformer.hxx
 *
 * Author: $author$
 *   Date: 3/13/2008
 **********************************************************************
 */
#ifndef _CXALANXSLTRANSFORMER_HXX
#define _CXALANXSLTRANSFORMER_HXX

#include "cxsltransformer.hxx"
#include "cxalantransformer.hxx"
#include "cxalanxsltresulttarget.hxx"
#include "cxalanxsltinputsource.hxx"

/**
 **********************************************************************
 *  Class: cXalanXSLTransformer
 *
 * Author: $author$
 *   Date: 3/13/2008
 **********************************************************************
 */
class cXalanXSLTransformer
: public cXSLTransformer
{
public:
    typedef cXSLTransformer cExtends;
    typedef cXalanXSLTransformer cDerives;

    cXalanTransformer m_xalan;
    cCharString m_xalanErrors;
    bool m_xalanInitialized;

    /**
     **********************************************************************
     * Constructor: cXalanXSLTransformer
     *
     *      Author: $author$
     *        Date: 3/13/2008
     **********************************************************************
     */
    cXalanXSLTransformer
    (bool isStaticInstance=true) 
    : cExtends(isStaticInstance),
      m_xalanInitialized(false)
    {
    }
    /**
     **********************************************************************
     * Destructor: cXalanXSLTransformer
     *
     *     Author: $author$
     *       Date: 3/13/2008
     **********************************************************************
     */
    virtual ~cXalanXSLTransformer()
    {
        eError error;
        if (m_xalanInitialized)
        if ((error = m_xalan.Finalize(m_xalanInitialized)))
            throw(error);
    }
    /**
     **********************************************************************
     * Function: Initialize
     *
     *   Author: $author$
     *     Date: 3/13/2008
     **********************************************************************
     */
    virtual eError Initialize() 
    {
        eError error;
        if (!(error = m_xalan.Initialize()))
            m_xalanInitialized = true;
        return error;
    }
    /**
     **********************************************************************
     * Function: Finalize
     *
     *   Author: $author$
     *     Date: 3/13/2008
     **********************************************************************
     */
    virtual eError Finalize() 
    {
        eError error = m_xalan.Finalize(m_xalanInitialized);
        m_xalanInitialized = false;
        return error;
    }
    /**
     **********************************************************************
     * Function: SetLiteralParameter
     *
     *   Author: $author$
     *     Date: 3/14/2008
     **********************************************************************
     */
    virtual eError SetLiteralParameter
    (const char* name, const char* value, 
     const char* literalQuoteChars=0) 
    {
        eError error = e_ERROR_NOT_IMPLEMENTED;
        if (!m_xalanInitialized)
            error = e_ERROR_NOT_INITIALIZED;
        else 
        error = m_xalan.SetLiteralParameter
        (name, value, literalQuoteChars);
        return error;
    }
    /**
     **********************************************************************
     * Function: TransformFile
     *
     *   Author: $author$
     *     Date: 3/13/2008
     **********************************************************************
     */
    virtual eError TransformFile
    (cCharWriterInterface& errors, 
     cCharWriterInterface& result,
     const char* xslFilename, const char* xmlFilename) 
    {
        cXalanXSLTResultTarget output(result);
        eError error = e_ERROR_NOT_IMPLEMENTED;
        const char* chars;
        TLENGTH length;

        if (!m_xalanInitialized)
            error = e_ERROR_NOT_INITIALIZED;
        else
        if (0 > (length = m_xalanErrors.Clear()))
            error = -length;
        else
        if ((error = m_xalan.Transform
            (xmlFilename, xslFilename, output, &m_xalanErrors)))
        {
            if ((chars = m_xalanErrors.HasChars(length)))
                errors.Write(chars, length);
        }
        return error;
    }
    /**
     **********************************************************************
     * Function: TransformXSLFile
     *
     *   Author: $author$
     *     Date: 3/14/2008
     **********************************************************************
     */
    virtual eError TransformXSLFile
    (cCharWriterInterface& errors, 
     cCharWriterInterface& result, 
     const char* xslFilename,
     cCharReaderInterface& xml, const char* xmlFilename) 
    {
        cXalanXSLTResultTarget output(result);
	    cXalanXSLTInputSource xmlInput(xml);
        eError error = e_ERROR_NOT_IMPLEMENTED;
        const char* chars;
        TLENGTH length;

        if (!m_xalanInitialized)
            error = e_ERROR_NOT_INITIALIZED;
        else
        if (0 > (length = m_xalanErrors.Clear()))
            error = -length;
        else
        if ((error = m_xalan.Transform
            (xmlInput, xslFilename, output, &m_xalanErrors)))
        {
            if ((chars = m_xalanErrors.HasChars(length)))
                errors.Write(chars, length);
        }
        return error;
    }
    /**
     **********************************************************************
     * Function: TransformXMLFile
     *
     *   Author: $author$
     *     Date: 3/14/2008
     **********************************************************************
     */
    virtual eError TransformXMLFile
    (cCharWriterInterface& errors, 
     cCharWriterInterface& result,
     cCharReaderInterface& xsl, const char* xslFilename,
     const char* xmlFilename) 
    {
        cXalanXSLTResultTarget output(result);
	    cXalanXSLTInputSource xslInput(xsl);
        eError error = e_ERROR_NOT_IMPLEMENTED;
        const char* chars;
        TLENGTH length;

        if (!m_xalanInitialized)
            error = e_ERROR_NOT_INITIALIZED;
        else
        if (0 > (length = m_xalanErrors.Clear()))
            error = -length;
        else
        if ((error = m_xalan.Transform
            (xmlFilename, xslInput, output, &m_xalanErrors)))
        {
            if ((chars = m_xalanErrors.HasChars(length)))
                errors.Write(chars, length);
        }
        return error;
    }
    /**
     **********************************************************************
     * Function: Transform
     *
     *   Author: $author$
     *     Date: 3/13/2008
     **********************************************************************
     */
    virtual eError Transform
    (cCharWriterInterface& errors, 
     cCharWriterInterface& result,
     cCharReaderInterface& xsl, const char* xslFilename,
     cCharReaderInterface& xml, const char* xmlFilename) 
    {
        cXalanXSLTResultTarget output(result);
	    cXalanXSLTInputSource xslInput(xsl);
	    cXalanXSLTInputSource xmlInput(xml);
        eError error = e_ERROR_NOT_IMPLEMENTED;
        const char* chars;
        TLENGTH length;

        if (!m_xalanInitialized)
            error = e_ERROR_NOT_INITIALIZED;
        else
        if (0 > (length = m_xalanErrors.Clear()))
            error = -length;
        else
        if ((error = m_xalan.Transform
            (xmlInput, xslInput, output, &m_xalanErrors)))
        {
            if ((chars = m_xalanErrors.HasChars(length)))
                errors.Write(chars, length);
        }
        return error;
    }
    /**
     **********************************************************************
     * Function: DeleteThis
     *
     *   Author: $author$
     *     Date: 3/13/2008
     **********************************************************************
     */
    virtual eError DeleteThis()
    {
        eError error = e_ERROR_NONE;
        bool isStaticInstance;
        if ((isStaticInstance = GetIsStaticInstance()))
            return e_ERROR_STATIC_INSTANCE;
        delete this;
        return error;
    }
};

#endif /* _CXALANXSLTRANSFORMER_HXX */
