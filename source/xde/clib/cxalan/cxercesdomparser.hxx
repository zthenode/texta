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
 *   File: cxercesdomparser.hxx
 *
 * Author: $author$
 *   Date: 3/15/2008
 **********************************************************************
 */
#ifndef _CXERCESDOMPARSER_HXX
#define _CXERCESDOMPARSER_HXX

#include <parsers/XercesDOMParser.hpp>

#include "cxerceserrorhandler.hxx"
#include "cxercesinputsource.hxx"

/**
 **********************************************************************
 *   Enum:  eXercesDOMParserValidate
 *
 * Author: $author$
 *   Date: 3/15/2008
 **********************************************************************
 */
typedef int eXercesDOMParserValidate;
enum
{
    e_FIRST_XERCES_DOM_PARSER_VALIDATE = 0,

    e_XERCES_DOM_PARSER_VALIDATE_NEVER = e_FIRST_XERCES_DOM_PARSER_VALIDATE,
    e_XERCES_DOM_PARSER_VALIDATE_ALWAYS,
    e_XERCES_DOM_PARSER_VALIDATE_AUTO,

    e_NEXT_XERCES_DOM_PARSER_VALIDATE,
    e_LAST_XERCES_DOM_PARSER_VALIDATE = e_NEXT_XERCES_DOM_PARSER_VALIDATE-1,
    e_COUNT_XERCES_DOM_PARSER_VALIDATE = e_LAST_XERCES_DOM_PARSER_VALIDATE-e_FIRST_XERCES_DOM_PARSER_VALIDATE+1
};

#define e_XERCES_DOM_PARSER_VALIDATE_NAME_NEVER "NEVER"
#define e_XERCES_DOM_PARSER_VALIDATE_NAME_ALWAYS "ALWAYS"
#define e_XERCES_DOM_PARSER_VALIDATE_NAME_AUTO "AUTO"

extern const char* eXercesDOMParserValidateName[e_COUNT_XERCES_DOM_PARSER_VALIDATE];

/**
 **********************************************************************
 *  Class: cXercesDOMParser
 *
 * Author: $author$
 *   Date: 3/15/2008
 **********************************************************************
 */
class cXercesDOMParser
: public nsXerces::XercesDOMParser
{
public:
    typedef nsXerces::XercesDOMParser cExtends;
    typedef cXercesDOMParser cDerives;

    cXercesErrorHandler m_errorHandler;

    /**
     **********************************************************************
     * Constructor: cXercesDOMParser
     *
     *      Author: $author$
     *        Date: 3/15/2008
     **********************************************************************
     */
    cXercesDOMParser() 
    {
    }
    /**
     **********************************************************************
     * Destructor: cXercesDOMParser
     *
     *     Author: $author$
     *       Date: 3/15/2008
     **********************************************************************
     */
    virtual ~cXercesDOMParser()
    {
    }
    /**
     **********************************************************************
     * Function: ParseFile
     *
     *   Author: $author$
     *     Date: 3/15/2008
     **********************************************************************
     */
    virtual eError ParseFile
    (cCharWriterInterface& errors,
     const char* filename,
     eXercesDOMParserValidate validate=e_XERCES_DOM_PARSER_VALIDATE_AUTO,
     bool includeWhitespace=false, bool includeComments=false,
     bool processNamespaces=false, bool processSchema=false, 
     bool processSchemaFullChecking=false, bool expandEntityReferences=false) 
    {
        nsXerces::ErrorHandler* errorHandler = getErrorHandler();
        ValSchemes valScheme = 
        (e_XERCES_DOM_PARSER_VALIDATE_AUTO!=validate)
        ?((e_XERCES_DOM_PARSER_VALIDATE_ALWAYS!=validate)
          ?Val_Never:Val_Always)
        :Val_Auto;
        eError error = e_ERROR_NONE;

        setValidationScheme(valScheme);
        setIncludeIgnorableWhitespace(includeWhitespace);
        setCreateCommentNodes(includeComments);
        setDoNamespaces(processNamespaces);
        setDoSchema(processSchema);
        setValidationSchemaFullChecking(processSchemaFullChecking);
        setCreateEntityReferenceNodes(expandEntityReferences);

        setErrorHandler(&m_errorHandler);
        try
        {
            parse(filename);
        }
        catch(cXercesException& e)
        {
            e.Write(errors);
            error = e_ERROR_FAILED;
        }
        setErrorHandler(errorHandler);
        return error;
    }
    /**
     **********************************************************************
     * Function: Parse
     *
     *   Author: $author$
     *     Date: 3/15/2008
     **********************************************************************
     */
    virtual eError Parse
    (cCharWriterInterface& errors,
     cCharReaderInterface& input,
     eXercesDOMParserValidate validate=e_XERCES_DOM_PARSER_VALIDATE_AUTO,
     bool includeWhitespace=false, bool includeComments=false,
     bool processNamespaces=false, bool processSchema=false, 
     bool processSchemaFullChecking=false, bool expandEntityReferences=false) 
    {
        cXercesInputSource inputSource(input);
        nsXerces::ErrorHandler* errorHandler = getErrorHandler();
        ValSchemes valScheme = 
        (e_XERCES_DOM_PARSER_VALIDATE_AUTO!=validate)
        ?((e_XERCES_DOM_PARSER_VALIDATE_ALWAYS!=validate)
          ?Val_Never:Val_Always)
        :Val_Auto;
        eError error = e_ERROR_NONE;

        setValidationScheme(valScheme);
        setIncludeIgnorableWhitespace(includeWhitespace);
        setCreateCommentNodes(includeComments);
        setDoNamespaces(processNamespaces);
        setDoSchema(processSchema);
        setValidationSchemaFullChecking(processSchemaFullChecking);
        setCreateEntityReferenceNodes(expandEntityReferences);

        setErrorHandler(&m_errorHandler);
        try
        {
            parse(inputSource);
        }
        catch(cXercesException& e)
        {
            e.Write(errors);
            error = e_ERROR_FAILED;
        }
        setErrorHandler(errorHandler);
        return error;
    }
};
#endif /* _CXERCESDOMPARSER_HXX */
