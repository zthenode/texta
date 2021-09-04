/**
 **********************************************************************
 * Copyright (c) 1988-2017 $organization$
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
 *   File: cxsltransformerinterface.hxx
 *
 * Author: $author$
 *   Date: 12/10/2017
 **********************************************************************
 */
#ifndef _CXSLTRANSFORMERINTERFACE_HXX
#define _CXSLTRANSFORMERINTERFACE_HXX

#include "cinstanceinterface.hxx"
#include "cwriterinterface.hxx"
#include "creaderinterface.hxx"
#include "cdebug.hxx"

/**
 **********************************************************************
 *  Class: cXSLTransformerInterface
 *
 * Author: $author$
 *   Date: 3/13/2008
 **********************************************************************
 */
class c_INTERFACE_CLASS cXSLTransformerInterface
: virtual public cInstanceInterface
{
public:
    typedef cInstanceInterface cImplements;
    typedef cXSLTransformerInterface cDerives;
    /**
     **********************************************************************
     * Function: Initialize
     *
     *   Author: $author$
     *     Date: 3/13/2008
     **********************************************************************
     */
    virtual eError Initialize() = 0;
    /**
     **********************************************************************
     * Function: Finalize
     *
     *   Author: $author$
     *     Date: 3/13/2008
     **********************************************************************
     */
    virtual eError Finalize() = 0;
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
     const char* literalQuoteChars=0) = 0;
    /**
     **********************************************************************
     * Function: SetParameter
     *
     *   Author: $author$
     *     Date: 3/14/2008
     **********************************************************************
     */
    virtual eError SetParameter
    (const char* name, const char* value) = 0;
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
     cCharReaderInterface& xml, const char* xmlFilename) = 0;
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
     const char* xmlFilename) = 0;
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
     const char* xslFilename, const char* xmlFilename) = 0;
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
     cCharReaderInterface& xml, const char* xmlFilename) = 0;
    /**
     **********************************************************************
     * Function: CreateInstance
     *
     *   Author: $author$
     *     Date: 3/13/2008
     **********************************************************************
     */
    static cXSLTransformerInterface* 
    CreateInstance(eError& error);
    /**
     **********************************************************************
     * Function: DestroyInstance
     *
     *   Author: $author$
     *     Date: 3/13/2008
     **********************************************************************
     */
    static eError DestroyInstance
    (cXSLTransformerInterface* instance);
};

typedef cInstanceImplementT
<cXSLTransformerInterface> cXSLTransformerImplementImplements;
/**
 **********************************************************************
 *  Class: cXSLTransformerImplement
 *
 * Author: $author$
 *   Date: 12/10/2017
 **********************************************************************
 */
class cXSLTransformerImplement
: virtual public cXSLTransformerImplementImplements
{
public:
    typedef cXSLTransformerImplementImplements cImplements;
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
        return e_ERROR_NONE;
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
        return e_ERROR_NONE;
    };
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
        return e_ERROR_FAILED;
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
        return e_ERROR_FAILED;
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
        return e_ERROR_FAILED;
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
        return e_ERROR_FAILED;
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
        errors.WriteL
       ("TransformFile(errors, ", "result, ", 
        "xslFilename = \"", xslFilename, "\", xmlFilename = \"", xmlFilename, "\") is unimplemented", NULL_POINTER);
        return e_ERROR_FAILED;
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
        return e_ERROR_FAILED;
    }
};

/**
 **********************************************************************
 *  Class: cXSLTransformerBase
 *
 * Author: $author$
 *   Date: 12/10/2017
 **********************************************************************
 */
class cXSLTransformerBase
: virtual public cXSLTransformerImplement,
  public cInstanceBase
{
public:
    typedef cXSLTransformerImplement cImplements;
    typedef cInstanceBase cExtends;
    /**
     **********************************************************************
     * Constructor: cXSLTransformerBase
     *
     *      Author: $author$
     *        Date: 12/10/2017
     **********************************************************************
     */
    cXSLTransformerBase()
    {
    }
    /**
     **********************************************************************
     * Destructor: ~cXSLTransformerBase
     *
     *     Author: $author$
     *       Date: 12/10/2017
     **********************************************************************
     */
    virtual ~cXSLTransformerBase()
    {
    }
};

#endif /* _CXSLTRANSFORMERINTERFACE_HXX */
