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
 *   File: cxsltransformer.hxx
 *
 * Author: $author$
 *   Date: 3/13/2008
 **********************************************************************
 */
#ifndef _CXSLTRANSFORMER_HXX
#define _CXSLTRANSFORMER_HXX

#include "cxsltransformerinterface.hxx"
#include "cinstance.hxx"

/**
 **********************************************************************
 *  Class: cXSLTransformer
 *
 * Author: $author$
 *   Date: 3/13/2008
 **********************************************************************
 */
class cXSLTransformer
: virtual public cXSLTransformerInterface,
  public cInstance
{
public:
    typedef cXSLTransformerInterface cImplements;
    typedef cInstance cExtends;
    typedef cXSLTransformer cDerives;
    /**
     **********************************************************************
     * Constructor: cXSLTransformer
     *
     *      Author: $author$
     *        Date: 3/13/2008
     **********************************************************************
     */
    cXSLTransformer
    (bool isStaticInstance=true) 
    : cExtends(isStaticInstance) 
    {
    }
    /**
     **********************************************************************
     * Destructor: cXSLTransformer
     *
     *     Author: $author$
     *       Date: 3/13/2008
     **********************************************************************
     */
    virtual ~cXSLTransformer()
    {
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
        eError error = e_ERROR_NONE;
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
        eError error = e_ERROR_NONE;
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
        return error;
    }
    /**
     **********************************************************************
     * Function: SetParameter
     *
     *   Author: $author$
     *     Date: 3/14/2008
     **********************************************************************
     */
    virtual eError SetParameter
    (const char* name, const char* value) 
    {
        eError error = e_ERROR_NOT_IMPLEMENTED;
        return error;
    }
    /**
     **********************************************************************
     * Function: TransformXSLFile
     *
     *   Author: $author$
     *     Date: 3/13/2008
     **********************************************************************
     */
    virtual eError TransformXSLFile
    (cCharWriterInterface& errors, 
     cCharWriterInterface& result, 
     const char* xslFilename,
     cCharReaderInterface& xml, const char* xmlFilename) 
    {
        eError error = e_ERROR_NOT_IMPLEMENTED;
        return error;
    }
    /**
     **********************************************************************
     * Function: TransformXMLFile
     *
     *   Author: $author$
     *     Date: 3/13/2008
     **********************************************************************
     */
    virtual eError TransformXMLFile
    (cCharWriterInterface& errors, 
     cCharWriterInterface& result,
     cCharReaderInterface& xsl, const char* xslFilename,
     const char* xmlFilename) 
    {
        eError error = e_ERROR_NOT_IMPLEMENTED;
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
        eError error = e_ERROR_NOT_IMPLEMENTED;
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
        eError error = e_ERROR_NOT_IMPLEMENTED;
        return error;
    }
};

#endif /* _CXSLTRANSFORMER_HXX */
