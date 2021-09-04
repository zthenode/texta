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
 *   File: cxmlparserevents.hxx
 *
 * Author: $author$
 *   Date: 11/6/2008
 **********************************************************************
 */
#ifndef _CXMLPARSEREVENTS_HXX
#define _CXMLPARSEREVENTS_HXX

#include "cxmlchar.hxx"

/**
 **********************************************************************
 *  Class: cXMLParserEventsInterface
 *
 * Author: $author$
 *   Date: 11/6/2008
 **********************************************************************
 */
class c_INTERFACE_CLASS cXMLParserEventsInterface
{
public:
    typedef cXMLParserEventsInterface cDerives;

    /**
     **********************************************************************
     * Function: OnBeginXMLProcessor
     *
     *   Author: $author$
     *     Date: 11/6/2008
     **********************************************************************
     */
    virtual eError OnBeginXMLProcessor() = 0;
    /**
     **********************************************************************
     * Function: OnEndXMLProcessor
     *
     *   Author: $author$
     *     Date: 11/6/2008
     **********************************************************************
     */
    virtual const cXMLChar* OnEndXMLProcessor
    (TLENGTH& length) = 0;
    /**
     **********************************************************************
     * Function: OnBeginXMLProcessorString
     *
     *   Author: $author$
     *     Date: 11/11/2008
     **********************************************************************
     */
    virtual eError OnBeginXMLProcessorString() = 0;
    /**
     **********************************************************************
     * Function: OnEndXMLProcessorString
     *
     *   Author: $author$
     *     Date: 11/11/2008
     **********************************************************************
     */
    virtual const cXMLChar* OnEndXMLProcessorString
    (TLENGTH& length) = 0;

    /**
     **********************************************************************
     * Function: OnBeginXMLComment
     *
     *   Author: $author$
     *     Date: 11/6/2008
     **********************************************************************
     */
    virtual eError OnBeginXMLComment() = 0;
    /**
     **********************************************************************
     * Function: OnEndXMLComment
     *
     *   Author: $author$
     *     Date: 11/6/2008
     **********************************************************************
     */
    virtual const cXMLChar* OnEndXMLComment
    (TLENGTH& length) = 0;
    /**
     **********************************************************************
     * Function: OnBeginXMLCommentString
     *
     *   Author: $author$
     *     Date: 11/11/2008
     **********************************************************************
     */
    virtual eError OnBeginXMLCommentString() = 0;
    /**
     **********************************************************************
     * Function: OnEndXMLCommentString
     *
     *   Author: $author$
     *     Date: 11/11/2008
     **********************************************************************
     */
    virtual const cXMLChar* OnEndXMLCommentString
    (TLENGTH& length) = 0;

    /**
     **********************************************************************
     * Function: OnBeginXMLDeclaration
     *
     *   Author: $author$
     *     Date: 11/11/2008
     **********************************************************************
     */
    virtual eError OnBeginXMLDeclaration() = 0;
    /**
     **********************************************************************
     * Function: OnEndXMLDeclaration
     *
     *   Author: $author$
     *     Date: 11/11/2008
     **********************************************************************
     */
    virtual const cXMLChar* OnEndXMLDeclaration
    (TLENGTH& length) = 0;
    /**
     **********************************************************************
     * Function: OnBeginXMLDeclarationString
     *
     *   Author: $author$
     *     Date: 11/11/2008
     **********************************************************************
     */
    virtual eError OnBeginXMLDeclarationString() = 0;
    /**
     **********************************************************************
     * Function: OnEndXMLDeclarationString
     *
     *   Author: $author$
     *     Date: 11/11/2008
     **********************************************************************
     */
    virtual const cXMLChar* OnEndXMLDeclarationString
    (TLENGTH& length) = 0;

    /**
     **********************************************************************
     * Function: OnBeginXMLSection
     *
     *   Author: $author$
     *     Date: 11/11/2008
     **********************************************************************
     */
    virtual eError OnBeginXMLSection() = 0;
    /**
     **********************************************************************
     * Function: OnEndXMLSection
     *
     *   Author: $author$
     *     Date: 11/11/2008
     **********************************************************************
     */
    virtual const cXMLChar* OnEndXMLSection
    (TLENGTH& length) = 0;
    /**
     **********************************************************************
     * Function: OnBeginXMLSectionString
     *
     *   Author: $author$
     *     Date: 11/11/2008
     **********************************************************************
     */
    virtual eError OnBeginXMLSectionString() = 0;
    /**
     **********************************************************************
     * Function: OnEndXMLSectionString
     *
     *   Author: $author$
     *     Date: 11/11/2008
     **********************************************************************
     */
    virtual const cXMLChar* OnEndXMLSectionString
    (TLENGTH& length) = 0;

    /**
     **********************************************************************
     * Function: OnBeginXMLTag
     *
     *   Author: $author$
     *     Date: 11/6/2008
     **********************************************************************
     */
    virtual eError OnBeginXMLTag() = 0;
    /**
     **********************************************************************
     * Function: OnEndXMLTag
     *
     *   Author: $author$
     *     Date: 11/6/2008
     **********************************************************************
     */
    virtual const cXMLChar* OnEndXMLTag
    (TLENGTH& length) = 0;
    /**
     **********************************************************************
     * Function: OnEndXMLBeginTag
     *
     *   Author: $author$
     *     Date: 11/8/2008
     **********************************************************************
     */
    virtual const cXMLChar* OnEndXMLBeginTag
    (TLENGTH& length) = 0;
    /**
     **********************************************************************
     * Function: OnBeginXMLEndTag
     *
     *   Author: $author$
     *     Date: 11/8/2008
     **********************************************************************
     */
    virtual eError OnBeginXMLEndTag() = 0;
    /**
     **********************************************************************
     * Function: OnEndXMLEndTag
     *
     *   Author: $author$
     *     Date: 11/8/2008
     **********************************************************************
     */
    virtual const cXMLChar* OnEndXMLEndTag
    (TLENGTH& length) = 0;
    /**
     **********************************************************************
     * Function: OnBeginXMLTagPrefix
     *
     *   Author: $author$
     *     Date: 11/10/2008
     **********************************************************************
     */
    virtual eError OnBeginXMLTagPrefix() = 0;
    /**
     **********************************************************************
     * Function: OnEndXMLTagPrefix
     *
     *   Author: $author$
     *     Date: 11/10/2008
     **********************************************************************
     */
    virtual const cXMLChar* OnEndXMLTagPrefix
    (TLENGTH& length) = 0;
    /**
     **********************************************************************
     * Function: OnBeginXMLTagName
     *
     *   Author: $author$
     *     Date: 11/10/2008
     **********************************************************************
     */
    virtual eError OnBeginXMLTagName() = 0;
    /**
     **********************************************************************
     * Function: OnEndXMLTagName
     *
     *   Author: $author$
     *     Date: 11/10/2008
     **********************************************************************
     */
    virtual const cXMLChar* OnEndXMLTagName
    (TLENGTH& length) = 0;
    /**
     **********************************************************************
     * Function: OnBeginXMLTagString
     *
     *   Author: $author$
     *     Date: 11/9/2008
     **********************************************************************
     */
    virtual eError OnBeginXMLTagString() = 0;
    /**
     **********************************************************************
     * Function: OnEndXMLTagString
     *
     *   Author: $author$
     *     Date: 11/9/2008
     **********************************************************************
     */
    virtual const cXMLChar* OnEndXMLTagString
    (TLENGTH& length) = 0;

    /**
     **********************************************************************
     * Function: OnBeginXMLAttributeName
     *
     *   Author: $author$
     *     Date: 11/10/2008
     **********************************************************************
     */
    virtual eError OnBeginXMLAttributeName() = 0;
    /**
     **********************************************************************
     * Function: OnEndXMLAttributeName
     *
     *   Author: $author$
     *     Date: 11/10/2008
     **********************************************************************
     */
    virtual const cXMLChar* OnEndXMLAttributeName
    (TLENGTH& length) = 0;
    /**
     **********************************************************************
     * Function: OnBeginXMLAttributePrefix
     *
     *   Author: $author$
     *     Date: 11/10/2008
     **********************************************************************
     */
    virtual eError OnBeginXMLAttributePrefix() = 0;
    /**
     **********************************************************************
     * Function: OnEndXMLAttributePrefix
     *
     *   Author: $author$
     *     Date: 11/10/2008
     **********************************************************************
     */
    virtual const cXMLChar* OnEndXMLAttributePrefix
    (TLENGTH& length) = 0;
    /**
     **********************************************************************
     * Function: OnBeginXMLAttributeValue
     *
     *   Author: $author$
     *     Date: 1/3/2009
     **********************************************************************
     */
    virtual eError OnBeginXMLAttributeValue() = 0;
    /**
     **********************************************************************
     * Function: OnEndXMLAttributeValue
     *
     *   Author: $author$
     *     Date: 1/3/2009
     **********************************************************************
     */
    virtual const cXMLChar* OnEndXMLAttributeValue
    (TLENGTH& length) = 0;
    /**
     **********************************************************************
     * Function: OnBeginXMLAttributeValueName
     *
     *   Author: $author$
     *     Date: 11/10/2008
     **********************************************************************
     */
    virtual eError OnBeginXMLAttributeValueName() = 0;
    /**
     **********************************************************************
     * Function: OnEndXMLAttributeValueName
     *
     *   Author: $author$
     *     Date: 11/10/2008
     **********************************************************************
     */
    virtual const cXMLChar* OnEndXMLAttributeValueName
    (TLENGTH& length) = 0;
    /**
     **********************************************************************
     * Function: OnBeginXMLAttributeValuePrefix
     *
     *   Author: $author$
     *     Date: 11/10/2008
     **********************************************************************
     */
    virtual eError OnBeginXMLAttributeValuePrefix() = 0;
    /**
     **********************************************************************
     * Function: OnEndXMLAttributeValuePrefix
     *
     *   Author: $author$
     *     Date: 11/10/2008
     **********************************************************************
     */
    virtual const cXMLChar* OnEndXMLAttributeValuePrefix
    (TLENGTH& length) = 0;
    /**
     **********************************************************************
     * Function: OnBeginXMLAttributeValueString
     *
     *   Author: $author$
     *     Date: 11/10/2008
     **********************************************************************
     */
    virtual eError OnBeginXMLAttributeValueString() = 0;
    /**
     **********************************************************************
     * Function: OnEndXMLAttributeValueString
     *
     *   Author: $author$
     *     Date: 11/10/2008
     **********************************************************************
     */
    virtual const cXMLChar* OnEndXMLAttributeValueString
    (TLENGTH& length) = 0;
    /**
     **********************************************************************
     * Function: OnBeginXMLAttributeValueStringPrefix
     *
     *   Author: $author$
     *     Date: 11/10/2008
     **********************************************************************
     */
    virtual eError OnBeginXMLAttributeValueStringPrefix() = 0;
    /**
     **********************************************************************
     * Function: OnEndXMLAttributeValueStringPrefix
     *
     *   Author: $author$
     *     Date: 11/10/2008
     **********************************************************************
     */
    virtual const cXMLChar* OnEndXMLAttributeValueStringPrefix
    (TLENGTH& length) = 0;

    /**
     **********************************************************************
     * Function: OnBeginXMLText
     *
     *   Author: $author$
     *     Date: 11/6/2008
     **********************************************************************
     */
    virtual eError OnBeginXMLText() = 0;
    /**
     **********************************************************************
     * Function: OnEndXMLText
     *
     *   Author: $author$
     *     Date: 11/6/2008
     **********************************************************************
     */
    virtual const cXMLChar* OnEndXMLText
    (TLENGTH& length) = 0;
    /**
     **********************************************************************
     * Function: OnBeginXMLTextString
     *
     *   Author: $author$
     *     Date: 11/11/2008
     **********************************************************************
     */
    virtual eError OnBeginXMLTextString() = 0;
    /**
     **********************************************************************
     * Function: OnEndXMLTextString
     *
     *   Author: $author$
     *     Date: 11/11/2008
     **********************************************************************
     */
    virtual const cXMLChar* OnEndXMLTextString
    (TLENGTH& length) = 0;
    /**
     **********************************************************************
     * Function: OnBeginXMLTextEntity
     *
     *   Author: $author$
     *     Date: 12/15/2008
     **********************************************************************
     */
    virtual eError OnBeginXMLTextEntity() = 0;
    /**
     **********************************************************************
     * Function: OnEndXMLTextEntity
     *
     *   Author: $author$
     *     Date: 12/15/2008
     **********************************************************************
     */
    virtual const cXMLChar* OnEndXMLTextEntity
    (TLENGTH& length) = 0;

    /**
     **********************************************************************
     * Function: OnProcessorXMLChar
     *
     *   Author: $author$
     *     Date: 11/6/2008
     **********************************************************************
     */
    virtual TLENGTH OnProcessorXMLChar
    (cXMLChar& xmlChar) = 0;
    /**
     **********************************************************************
     * Function: OnProcessorStringXMLChar
     *
     *   Author: $author$
     *     Date: 11/11/2008
     **********************************************************************
     */
    virtual TLENGTH OnProcessorStringXMLChar
    (cXMLChar& xmlChar) = 0;

    /**
     **********************************************************************
     * Function: OnCommentXMLChar
     *
     *   Author: $author$
     *     Date: 11/6/2008
     **********************************************************************
     */
    virtual TLENGTH OnCommentXMLChar
    (cXMLChar& xmlChar) = 0;
    /**
     **********************************************************************
     * Function: OnCommentStringXMLChar
     *
     *   Author: $author$
     *     Date: 11/11/2008
     **********************************************************************
     */
    virtual TLENGTH OnCommentStringXMLChar
    (cXMLChar& xmlChar) = 0;

    /**
     **********************************************************************
     * Function: OnDeclarationXMLChar
     *
     *   Author: $author$
     *     Date: 11/6/2008
     **********************************************************************
     */
    virtual TLENGTH OnDeclarationXMLChar
    (cXMLChar& xmlChar) = 0;
    /**
     **********************************************************************
     * Function: OnDeclarationStringXMLChar
     *
     *   Author: $author$
     *     Date: 11/11/2008
     **********************************************************************
     */
    virtual TLENGTH OnDeclarationStringXMLChar
    (cXMLChar& xmlChar) = 0;

    /**
     **********************************************************************
     * Function: OnSectionXMLChar
     *
     *   Author: $author$
     *     Date: 11/6/2008
     **********************************************************************
     */
    virtual TLENGTH OnSectionXMLChar
    (cXMLChar& xmlChar) = 0;
    /**
     **********************************************************************
     * Function: OnSectionStringXMLChar
     *
     *   Author: $author$
     *     Date: 11/11/2008
     **********************************************************************
     */
    virtual TLENGTH OnSectionStringXMLChar
    (cXMLChar& xmlChar) = 0;

    /**
     **********************************************************************
     * Function: OnTagXMLChar
     *
     *   Author: $author$
     *     Date: 11/6/2008
     **********************************************************************
     */
    virtual TLENGTH OnTagXMLChar
    (cXMLChar& xmlChar) = 0;
    /**
     **********************************************************************
     * Function: OnTagNameXMLChar
     *
     *   Author: $author$
     *     Date: 11/10/2008
     **********************************************************************
     */
    virtual TLENGTH OnTagNameXMLChar
    (cXMLChar& xmlChar) = 0;
    /**
     **********************************************************************
     * Function: OnTagStringXMLChar
     *
     *   Author: $author$
     *     Date: 11/11/2008
     **********************************************************************
     */
    virtual TLENGTH OnTagStringXMLChar
    (cXMLChar& xmlChar) = 0;

    /**
     **********************************************************************
     * Function: OnAttributeNameXMLChar
     *
     *   Author: $author$
     *     Date: 11/10/2008
     **********************************************************************
     */
    virtual TLENGTH OnAttributeNameXMLChar
    (cXMLChar& xmlChar) = 0;
    /**
     **********************************************************************
     * Function: OnAttributeValueXMLChar
     *
     *   Author: $author$
     *     Date: 11/10/2008
     **********************************************************************
     */
    virtual TLENGTH OnAttributeValueXMLChar
    (cXMLChar& xmlChar) = 0;
    /**
     **********************************************************************
     * Function: OnAttributeValueStringXMLChar
     *
     *   Author: $author$
     *     Date: 11/10/2008
     **********************************************************************
     */
    virtual TLENGTH OnAttributeValueStringXMLChar
    (cXMLChar& xmlChar) = 0;

    /**
     **********************************************************************
     * Function: OnTextXMLChar
     *
     *   Author: $author$
     *     Date: 11/6/2008
     **********************************************************************
     */
    virtual TLENGTH OnTextXMLChar
    (cXMLChar& xmlChar) = 0;
    /**
     **********************************************************************
     * Function: OnTextStringXMLChar
     *
     *   Author: $author$
     *     Date: 11/10/2008
     **********************************************************************
     */
    virtual TLENGTH OnTextStringXMLChar
    (cXMLChar& xmlChar) = 0;
    /**
     **********************************************************************
     * Function: OnTextEntityXMLChar
     *
     *   Author: $author$
     *     Date: 12/15/2008
     **********************************************************************
     */
    virtual TLENGTH OnTextEntityXMLChar
    (cXMLChar& xmlChar) = 0;
};

/**
 **********************************************************************
 *  Class: cXMLParserEventsImplement
 *
 * Author: $author$
 *   Date: 11/6/2008
 **********************************************************************
 */
class cXMLParserEventsImplement
: virtual public cXMLParserEventsInterface
{
public:
    typedef cXMLParserEventsInterface cImplements;
    typedef cXMLParserEventsImplement cDerives;

    /**
     **********************************************************************
     * Function: OnBeginXMLProcessor
     *
     *   Author: $author$
     *     Date: 11/6/2008
     **********************************************************************
     */
    virtual eError OnBeginXMLProcessor() 
    {
        eError error = e_ERROR_NONE;
        return error;
    }
    /**
     **********************************************************************
     * Function: OnEndXMLProcessor
     *
     *   Author: $author$
     *     Date: 11/6/2008
     **********************************************************************
     */
    virtual const cXMLChar* OnEndXMLProcessor
    (TLENGTH& length) 
    {
        const cXMLChar* xmlChars = 0;
        return xmlChars;
    }
    /**
     **********************************************************************
     * Function: OnBeginXMLProcessorString
     *
     *   Author: $author$
     *     Date: 11/11/2008
     **********************************************************************
     */
    virtual eError OnBeginXMLProcessorString() 
    {
        eError error = e_ERROR_NONE;
        return error;
    }
    /**
     **********************************************************************
     * Function: OnEndXMLProcessorString
     *
     *   Author: $author$
     *     Date: 11/11/2008
     **********************************************************************
     */
    virtual const cXMLChar* OnEndXMLProcessorString
    (TLENGTH& length) 
    {
        const cXMLChar* xmlChars = 0;
        return xmlChars;
    }

    /**
     **********************************************************************
     * Function: OnBeginXMLComment
     *
     *   Author: $author$
     *     Date: 11/6/2008
     **********************************************************************
     */
    virtual eError OnBeginXMLComment() 
    {
        eError error = e_ERROR_NONE;
        return error;
    }
    /**
     **********************************************************************
     * Function: OnEndXMLComment
     *
     *   Author: $author$
     *     Date: 11/6/2008
     **********************************************************************
     */
    virtual const cXMLChar* OnEndXMLComment
    (TLENGTH& length) 
    {
        const cXMLChar* xmlChars = 0;
        return xmlChars;
    }
    /**
     **********************************************************************
     * Function: OnBeginXMLCommentString
     *
     *   Author: $author$
     *     Date: 11/11/2008
     **********************************************************************
     */
    virtual eError OnBeginXMLCommentString() 
    {
        eError error = e_ERROR_NONE;
        return error;
    }
    /**
     **********************************************************************
     * Function: OnEndXMLCommentString
     *
     *   Author: $author$
     *     Date: 11/11/2008
     **********************************************************************
     */
    virtual const cXMLChar* OnEndXMLCommentString
    (TLENGTH& length) 
    {
        const cXMLChar* xmlChars = 0;
        return xmlChars;
    }

    /**
     **********************************************************************
     * Function: OnBeginXMLDeclaration
     *
     *   Author: $author$
     *     Date: 11/11/2008
     **********************************************************************
     */
    virtual eError OnBeginXMLDeclaration() 
    {
        eError error = e_ERROR_NONE;
        return error;
    }
    /**
     **********************************************************************
     * Function: OnEndXMLDeclaration
     *
     *   Author: $author$
     *     Date: 11/11/2008
     **********************************************************************
     */
    virtual const cXMLChar* OnEndXMLDeclaration
    (TLENGTH& length) 
    {
        const cXMLChar* xmlChars = 0;
        return xmlChars;
    }
    /**
     **********************************************************************
     * Function: OnBeginXMLDeclarationString
     *
     *   Author: $author$
     *     Date: 11/11/2008
     **********************************************************************
     */
    virtual eError OnBeginXMLDeclarationString() 
    {
        eError error = e_ERROR_NONE;
        return error;
    }
    /**
     **********************************************************************
     * Function: OnEndXMLDeclarationString
     *
     *   Author: $author$
     *     Date: 11/11/2008
     **********************************************************************
     */
    virtual const cXMLChar* OnEndXMLDeclarationString
    (TLENGTH& length) 
    {
        const cXMLChar* xmlChars = 0;
        return xmlChars;
    }

    /**
     **********************************************************************
     * Function: OnBeginXMLSection
     *
     *   Author: $author$
     *     Date: 11/11/2008
     **********************************************************************
     */
    virtual eError OnBeginXMLSection() 
    {
        eError error = e_ERROR_NONE;
        return error;
    }
    /**
     **********************************************************************
     * Function: OnEndXMLSection
     *
     *   Author: $author$
     *     Date: 11/11/2008
     **********************************************************************
     */
    virtual const cXMLChar* OnEndXMLSection
    (TLENGTH& length) 
    {
        const cXMLChar* xmlChars = 0;
        return xmlChars;
    }
    /**
     **********************************************************************
     * Function: OnBeginXMLSectionString
     *
     *   Author: $author$
     *     Date: 11/11/2008
     **********************************************************************
     */
    virtual eError OnBeginXMLSectionString() 
    {
        eError error = e_ERROR_NONE;
        return error;
    }
    /**
     **********************************************************************
     * Function: OnEndXMLSectionString
     *
     *   Author: $author$
     *     Date: 11/11/2008
     **********************************************************************
     */
    virtual const cXMLChar* OnEndXMLSectionString
    (TLENGTH& length) 
    {
        const cXMLChar* xmlChars = 0;
        return xmlChars;
    }

    /**
     **********************************************************************
     * Function: OnBeginXMLTag
     *
     *   Author: $author$
     *     Date: 11/6/2008
     **********************************************************************
     */
    virtual eError OnBeginXMLTag() 
    {
        eError error = e_ERROR_NONE;
        return error;
    }
    /**
     **********************************************************************
     * Function: OnEndXMLTag
     *
     *   Author: $author$
     *     Date: 11/6/2008
     **********************************************************************
     */
    virtual const cXMLChar* OnEndXMLTag
    (TLENGTH& length) 
    {
        const cXMLChar* xmlChars = 0;
        return xmlChars;
    }
    /**
     **********************************************************************
     * Function: OnEndXMLBeginTag
     *
     *   Author: $author$
     *     Date: 11/8/2008
     **********************************************************************
     */
    virtual const cXMLChar* OnEndXMLBeginTag
    (TLENGTH& length) 
    {
        const cXMLChar* xmlChars = 0;
        return xmlChars;
    }
    /**
     **********************************************************************
     * Function: OnBeginXMLEndTag
     *
     *   Author: $author$
     *     Date: 11/8/2008
     **********************************************************************
     */
    virtual eError OnBeginXMLEndTag() 
    {
        eError error = e_ERROR_NONE;
        return error;
    }
    /**
     **********************************************************************
     * Function: OnEndXMLEndTag
     *
     *   Author: $author$
     *     Date: 11/8/2008
     **********************************************************************
     */
    virtual const cXMLChar* OnEndXMLEndTag
    (TLENGTH& length) 
    {
        const cXMLChar* xmlChars = 0;
        return xmlChars;
    }
    /**
     **********************************************************************
     * Function: OnBeginXMLTagPrefix
     *
     *   Author: $author$
     *     Date: 11/10/2008
     **********************************************************************
     */
    virtual eError OnBeginXMLTagPrefix() 
    {
        eError error = e_ERROR_NONE;
        return error;
    }
    /**
     **********************************************************************
     * Function: OnEndXMLTagPrefix
     *
     *   Author: $author$
     *     Date: 11/10/2008
     **********************************************************************
     */
    virtual const cXMLChar* OnEndXMLTagPrefix
    (TLENGTH& length) 
    {
        const cXMLChar* xmlChars = 0;
        return xmlChars;
    }
    /**
     **********************************************************************
     * Function: OnBeginXMLTagName
     *
     *   Author: $author$
     *     Date: 11/10/2008
     **********************************************************************
     */
    virtual eError OnBeginXMLTagName() 
    {
        eError error = e_ERROR_NONE;
        return error;
    }
    /**
     **********************************************************************
     * Function: OnEndXMLTagName
     *
     *   Author: $author$
     *     Date: 11/10/2008
     **********************************************************************
     */
    virtual const cXMLChar* OnEndXMLTagName
    (TLENGTH& length) 
    {
        const cXMLChar* xmlChars = 0;
        return xmlChars;
    }
    /**
     **********************************************************************
     * Function: OnBeginXMLTagString
     *
     *   Author: $author$
     *     Date: 11/9/2008
     **********************************************************************
     */
    virtual eError OnBeginXMLTagString() 
    {
        eError error = e_ERROR_NONE;
        return error;
    }
    /**
     **********************************************************************
     * Function: OnEndXMLTagString
     *
     *   Author: $author$
     *     Date: 11/9/2008
     **********************************************************************
     */
    virtual const cXMLChar* OnEndXMLTagString
    (TLENGTH& length) 
    {
        const cXMLChar* xmlChars = 0;
        return xmlChars;
    }

    /**
     **********************************************************************
     * Function: OnBeginXMLAttributeName
     *
     *   Author: $author$
     *     Date: 11/10/2008
     **********************************************************************
     */
    virtual eError OnBeginXMLAttributeName() 
    {
        eError error = e_ERROR_NONE;
        return error;
    }
    /**
     **********************************************************************
     * Function: OnEndXMLAttributeName
     *
     *   Author: $author$
     *     Date: 11/10/2008
     **********************************************************************
     */
    virtual const cXMLChar* OnEndXMLAttributeName
    (TLENGTH& length) 
    {
        const cXMLChar* xmlChars = 0;
        return xmlChars;
    }
    /**
     **********************************************************************
     * Function: OnBeginXMLAttributePrefix
     *
     *   Author: $author$
     *     Date: 11/10/2008
     **********************************************************************
     */
    virtual eError OnBeginXMLAttributePrefix() 
    {
        eError error = e_ERROR_NONE;
        return error;
    }
    /**
     **********************************************************************
     * Function: OnEndXMLAttributePrefix
     *
     *   Author: $author$
     *     Date: 11/10/2008
     **********************************************************************
     */
    virtual const cXMLChar* OnEndXMLAttributePrefix
    (TLENGTH& length) 
    {
        const cXMLChar* xmlChars = 0;
        return xmlChars;
    }
    /**
     **********************************************************************
     * Function: OnBeginXMLAttributeValue
     *
     *   Author: $author$
     *     Date: 1/3/2009
     **********************************************************************
     */
    virtual eError OnBeginXMLAttributeValue() 
    {
        eError error = e_ERROR_NONE;
        return error;
    }
    /**
     **********************************************************************
     * Function: OnEndXMLAttributeValue
     *
     *   Author: $author$
     *     Date: 1/3/2009
     **********************************************************************
     */
    virtual const cXMLChar* OnEndXMLAttributeValue
    (TLENGTH& length) 
    {
        const cXMLChar* xmlChars = 0;
        return xmlChars;
    }
    /**
     **********************************************************************
     * Function: OnBeginXMLAttributeValueName
     *
     *   Author: $author$
     *     Date: 11/10/2008
     **********************************************************************
     */
    virtual eError OnBeginXMLAttributeValueName() 
    {
        eError error = OnBeginXMLAttributeValue();
        return error;
    }
    /**
     **********************************************************************
     * Function: OnEndXMLAttributeValueName
     *
     *   Author: $author$
     *     Date: 11/10/2008
     **********************************************************************
     */
    virtual const cXMLChar* OnEndXMLAttributeValueName
    (TLENGTH& length) 
    {
        const cXMLChar* xmlChars = OnEndXMLAttributeValue(length);
        return xmlChars;
    }
    /**
     **********************************************************************
     * Function: OnBeginXMLAttributeValuePrefix
     *
     *   Author: $author$
     *     Date: 11/10/2008
     **********************************************************************
     */
    virtual eError OnBeginXMLAttributeValuePrefix() 
    {
        eError error = e_ERROR_NONE;
        return error;
    }
    /**
     **********************************************************************
     * Function: OnEndXMLAttributeValuePrefix
     *
     *   Author: $author$
     *     Date: 11/10/2008
     **********************************************************************
     */
    virtual const cXMLChar* OnEndXMLAttributeValuePrefix
    (TLENGTH& length) 
    {
        const cXMLChar* xmlChars = 0;
        return xmlChars;
    }
    /**
     **********************************************************************
     * Function: OnBeginXMLAttributeValueString
     *
     *   Author: $author$
     *     Date: 11/10/2008
     **********************************************************************
     */
    virtual eError OnBeginXMLAttributeValueString() 
    {
        eError error = OnBeginXMLAttributeValue();
        return error;
    }
    /**
     **********************************************************************
     * Function: OnEndXMLAttributeValueString
     *
     *   Author: $author$
     *     Date: 11/10/2008
     **********************************************************************
     */
    virtual const cXMLChar* OnEndXMLAttributeValueString
    (TLENGTH& length) 
    {
        const cXMLChar* xmlChars = OnEndXMLAttributeValue(length);
        return xmlChars;
    }
    /**
     **********************************************************************
     * Function: OnBeginXMLAttributeValueStringPrefix
     *
     *   Author: $author$
     *     Date: 11/10/2008
     **********************************************************************
     */
    virtual eError OnBeginXMLAttributeValueStringPrefix() 
    {
        eError error = e_ERROR_NONE;
        return error;
    }
    /**
     **********************************************************************
     * Function: OnEndXMLAttributeValueStringPrefix
     *
     *   Author: $author$
     *     Date: 11/10/2008
     **********************************************************************
     */
    virtual const cXMLChar* OnEndXMLAttributeValueStringPrefix
    (TLENGTH& length) 
    {
        const cXMLChar* xmlChars = 0;
        return xmlChars;
    }

    /**
     **********************************************************************
     * Function: OnBeginXMLText
     *
     *   Author: $author$
     *     Date: 11/6/2008
     **********************************************************************
     */
    virtual eError OnBeginXMLText() 
    {
        eError error = e_ERROR_NONE;
        return error;
    }
    /**
     **********************************************************************
     * Function: OnEndXMLText
     *
     *   Author: $author$
     *     Date: 11/6/2008
     **********************************************************************
     */
    virtual const cXMLChar* OnEndXMLText
    (TLENGTH& length) 
    {
        const cXMLChar* xmlChars = 0;
        return xmlChars;
    }
    /**
     **********************************************************************
     * Function: OnBeginXMLTextString
     *
     *   Author: $author$
     *     Date: 11/11/2008
     **********************************************************************
     */
    virtual eError OnBeginXMLTextString() 
    {
        eError error = e_ERROR_NONE;
        return error;
    }
    /**
     **********************************************************************
     * Function: OnEndXMLTextString
     *
     *   Author: $author$
     *     Date: 11/11/2008
     **********************************************************************
     */
    virtual const cXMLChar* OnEndXMLTextString
    (TLENGTH& length) 
    {
        const cXMLChar* xmlChars = 0;
        return xmlChars;
    }
    /**
     **********************************************************************
     * Function: OnBeginXMLTextEntity
     *
     *   Author: $author$
     *     Date: 12/15/2008
     **********************************************************************
     */
    virtual eError OnBeginXMLTextEntity() 
    {
        eError error = e_ERROR_NONE;
        return error;
    }
    /**
     **********************************************************************
     * Function: OnEndXMLTextEntity
     *
     *   Author: $author$
     *     Date: 12/15/2008
     **********************************************************************
     */
    virtual const cXMLChar* OnEndXMLTextEntity
    (TLENGTH& length) 
    {
        const cXMLChar* xmlChars = 0;
        return xmlChars;
    }

    /**
     **********************************************************************
     * Function: OnProcessorXMLChar
     *
     *   Author: $author$
     *     Date: 11/6/2008
     **********************************************************************
     */
    virtual TLENGTH OnProcessorXMLChar
    (cXMLChar& xmlChar) 
    {
        TLENGTH count = OnTextXMLChar(xmlChar);
        return count;
    }
    /**
     **********************************************************************
     * Function: OnProcessorStringXMLChar
     *
     *   Author: $author$
     *     Date: 11/11/2008
     **********************************************************************
     */
    virtual TLENGTH OnProcessorStringXMLChar
    (cXMLChar& xmlChar) 
    {
        TLENGTH count = OnProcessorXMLChar(xmlChar);
        return count;
    }

    /**
     **********************************************************************
     * Function: OnCommentXMLChar
     *
     *   Author: $author$
     *     Date: 11/6/2008
     **********************************************************************
     */
    virtual TLENGTH OnCommentXMLChar
    (cXMLChar& xmlChar) 
    {
        TLENGTH count = OnTextXMLChar(xmlChar);
        return count;
    }
    /**
     **********************************************************************
     * Function: OnCommentStringXMLChar
     *
     *   Author: $author$
     *     Date: 11/11/2008
     **********************************************************************
     */
    virtual TLENGTH OnCommentStringXMLChar
    (cXMLChar& xmlChar) 
    {
        TLENGTH count = OnCommentXMLChar(xmlChar);
        return count;
    }

    /**
     **********************************************************************
     * Function: OnDeclarationXMLChar
     *
     *   Author: $author$
     *     Date: 11/6/2008
     **********************************************************************
     */
    virtual TLENGTH OnDeclarationXMLChar
    (cXMLChar& xmlChar) 
    {
        TLENGTH count = OnTextXMLChar(xmlChar);
        return count;
    }
    /**
     **********************************************************************
     * Function: OnDeclarationStringXMLChar
     *
     *   Author: $author$
     *     Date: 11/11/2008
     **********************************************************************
     */
    virtual TLENGTH OnDeclarationStringXMLChar
    (cXMLChar& xmlChar) 
    {
        TLENGTH count = OnDeclarationXMLChar(xmlChar);
        return count;
    }

    /**
     **********************************************************************
     * Function: OnSectionXMLChar
     *
     *   Author: $author$
     *     Date: 11/6/2008
     **********************************************************************
     */
    virtual TLENGTH OnSectionXMLChar
    (cXMLChar& xmlChar) 
    {
        TLENGTH count = OnTextXMLChar(xmlChar);
        return count;
    }
    /**
     **********************************************************************
     * Function: OnSectionStringXMLChar
     *
     *   Author: $author$
     *     Date: 11/11/2008
     **********************************************************************
     */
    virtual TLENGTH OnSectionStringXMLChar
    (cXMLChar& xmlChar) 
    {
        TLENGTH count = OnSectionXMLChar(xmlChar);
        return count;
    }

    /**
     **********************************************************************
     * Function: OnTagXMLChar
     *
     *   Author: $author$
     *     Date: 11/6/2008
     **********************************************************************
     */
    virtual TLENGTH OnTagXMLChar
    (cXMLChar& xmlChar) 
    {
        TLENGTH count = OnTextXMLChar(xmlChar);
        return count;
    }
    /**
     **********************************************************************
     * Function: OnTagNameXMLChar
     *
     *   Author: $author$
     *     Date: 11/10/2008
     **********************************************************************
     */
    virtual TLENGTH OnTagNameXMLChar
    (cXMLChar& xmlChar) 
    {
        TLENGTH count = OnTagXMLChar(xmlChar);
        return count;
    }
    /**
     **********************************************************************
     * Function: OnTagStringXMLChar
     *
     *   Author: $author$
     *     Date: 11/11/2008
     **********************************************************************
     */
    virtual TLENGTH OnTagStringXMLChar
    (cXMLChar& xmlChar) 
    {
        TLENGTH count = OnTagXMLChar(xmlChar);
        return count;
    }

    /**
     **********************************************************************
     * Function: OnAttributeNameXMLChar
     *
     *   Author: $author$
     *     Date: 11/10/2008
     **********************************************************************
     */
    virtual TLENGTH OnAttributeNameXMLChar
    (cXMLChar& xmlChar) 
    {
        TLENGTH count = OnTagXMLChar(xmlChar);
        return count;
    }
    /**
     **********************************************************************
     * Function: OnAttributeValueXMLChar
     *
     *   Author: $author$
     *     Date: 11/10/2008
     **********************************************************************
     */
    virtual TLENGTH OnAttributeValueXMLChar
    (cXMLChar& xmlChar) 
    {
        TLENGTH count = OnTagXMLChar(xmlChar);
        return count;
    }
    /**
     **********************************************************************
     * Function: OnAttributeValueStringXMLChar
     *
     *   Author: $author$
     *     Date: 11/10/2008
     **********************************************************************
     */
    virtual TLENGTH OnAttributeValueStringXMLChar
    (cXMLChar& xmlChar) 
    {
        TLENGTH count = OnAttributeValueXMLChar(xmlChar);
        return count;
    }

    /**
     **********************************************************************
     * Function: OnTextXMLChar
     *
     *   Author: $author$
     *     Date: 11/6/2008
     **********************************************************************
     */
    virtual TLENGTH OnTextXMLChar
    (cXMLChar& xmlChar) 
    {
        TLENGTH count = 1;
        return count;
    }
    /**
     **********************************************************************
     * Function: OnTextStringXMLChar
     *
     *   Author: $author$
     *     Date: 11/10/2008
     **********************************************************************
     */
    virtual TLENGTH OnTextStringXMLChar
    (cXMLChar& xmlChar) 
    {
        TLENGTH count = OnTextXMLChar(xmlChar);
        return count;
    }
    /**
     **********************************************************************
     * Function: OnTextEntityXMLChar
     *
     *   Author: $author$
     *     Date: 12/15/2008
     **********************************************************************
     */
    virtual TLENGTH OnTextEntityXMLChar
    (cXMLChar& xmlChar) 
    {
        TLENGTH count = OnTextXMLChar(xmlChar);
        return count;
    }
};

#endif /* _CXMLPARSEREVENTS_HXX */
