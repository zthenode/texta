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
 *   File: cxmlchartoxmlparsereventswriter.hxx
 *
 * Author: $author$
 *   Date: 11/6/2008
 **********************************************************************
 */
#ifndef _CXMLCHARTOXMLPARSEREVENTSWRITER_HXX
#define _CXMLCHARTOXMLPARSEREVENTSWRITER_HXX

#include "cxmlparserevents.hxx"
#include "cxmlcharwriter.hxx"
#include "cxmlnode.hxx"

/**
 **********************************************************************
 *  Class: cXMLCharToXMLParserEventsWriter
 *
 * Author: $author$
 *   Date: 11/6/2008
 **********************************************************************
 */
class cXMLCharToXMLParserEventsWriter
: virtual public cXMLCharWriterImplement,
  public cBase
{
public:
    typedef cXMLCharWriterImplement cImplements;
    typedef cBase cExtends;
    typedef cXMLCharToXMLParserEventsWriter cDerives;

    typedef TLENGTH (cDerives::*mXMLPut)(cXMLChar& xmlChar);

    cXMLParserEventsInterface& m_xmlParserEvents;

    mXMLPut m_xmlPut;
    mXMLPut m_oldXMLPut;
    mXMLPut m_onStringXMLChar;
    mXMLPut m_onEndStringXMLChar;
    TLENGTH m_ltDepth;
    TLENGTH m_lbDepth;

    cXMLChar m_lt;
    cXMLChar m_gt;
    cXMLChar m_lb;
    cXMLChar m_rb;
    cXMLChar m_qm;
    cXMLChar m_xm;
    cXMLChar m_minus;
    cXMLChar m_slash;
    cXMLChar m_null;

    /**
     **********************************************************************
     * Constructor: cXMLCharToXMLParserEventsWriter
     *
     *      Author: $author$
     *        Date: 11/6/2008
     **********************************************************************
     */
    cXMLCharToXMLParserEventsWriter
    (cXMLParserEventsInterface& xmlParserEvents)
    : m_xmlParserEvents(xmlParserEvents),
      m_xmlPut(&cDerives::XMLPut),
      m_oldXMLPut(0),
      m_onStringXMLChar(0),
      m_onEndStringXMLChar(0),
      m_ltDepth(0),
      m_lbDepth(0),
      m_lt('<'),
      m_gt('>'),
      m_lb('['),
      m_rb(']'),
      m_qm('?'),
      m_xm('!'),
      m_minus('-'),
      m_slash('/'),
      m_null('\0')
    {
    }

    /**
     **********************************************************************
     * Function: Initialize
     *
     *   Author: $author$
     *     Date: 11/9/2008
     **********************************************************************
     */
    virtual eError Initialize() 
    {
        eError error = e_ERROR_NONE;
        m_xmlPut = &cDerives::XMLPut;
        m_oldXMLPut = 0;
        m_onStringXMLChar = 0;
        m_onEndStringXMLChar = 0;
        return error;
    }
    /**
     **********************************************************************
     * Function: Finalize
     *
     *   Author: $author$
     *     Date: 11/9/2008
     **********************************************************************
     */
    virtual eError Finalize() 
    {
        eError error = e_ERROR_NONE;
        return error;
    }

    /**
     **********************************************************************
     * Function: Put
     *
     *   Author: $author$
     *     Date: 11/6/2008
     **********************************************************************
     */
    virtual TLENGTH Put
    (cXMLChar& xmlChar) 
    {
        TLENGTH length = 1;
        if (m_xmlPut)
            length = (this->*m_xmlPut)(xmlChar);
        return length;
    }
    /**
     **********************************************************************
     * Function: XMLPut
     *
     *   Author: $author$
     *     Date: 11/6/2008
     *
     * ?
     **********************************************************************
     */
    TLENGTH XMLPut
    (cXMLChar& xmlChar) 
    {
        TLENGTH length = 1;
        CHAR c=xmlChar.GetCHAR();
        eError error;
        switch(c)
        {
        case '<':
            m_xmlPut = &cDerives::LTXMLPut;
            break;

        case '&':
            if ((error = OnBeginXMLText()))
                return length = -error;
            if ((error = OnBeginXMLTextEntity()))
                return length = -error;
            if (0 > (length = OnTextXMLChar(xmlChar)))
                return length;
            m_oldXMLPut = &cDerives::TextXMLPut;
            m_xmlPut = &cDerives::AmpXMLPut;
            m_onStringXMLChar = &cDerives::OnTextEntityXMLChar;
            m_onEndStringXMLChar = &cDerives::OnTextEndEntityXMLChar;
            break;

        default:
            if ((error = OnBeginXMLText()))
                return length = -error;
            if (0 > (length = OnTextXMLChar(xmlChar)))
                return length;
            m_xmlPut = &cDerives::TextXMLPut;
        }
        return length;
    }
    /**
     **********************************************************************
     * Function: TextXMLPut
     *
     *   Author: $author$
     *     Date: 11/8/2008
     *
     * A+ ?
     **********************************************************************
     */
    TLENGTH TextXMLPut
    (cXMLChar& xmlChar) 
    {
        TLENGTH count = 1;
        CHAR c=xmlChar.GetCHAR();
        const cXMLChar* xmlChars;
        TLENGTH length;
        eError error;
        switch(c)
        {
        case '<':
            // A+ '<'
            if (!(xmlChars = OnEndXMLText(length)))
                return length;
            m_xmlPut = &cDerives::LTXMLPut;
            break;

        case '&':
            // A+ '&' 
            if ((error = OnBeginXMLTextEntity()))
                return length = -error;
            if (0 > (length = OnTextXMLChar(xmlChar)))
                return length;
            m_oldXMLPut = m_xmlPut;
            m_xmlPut = &cDerives::AmpXMLPut;
            m_onStringXMLChar = &cDerives::OnTextEntityXMLChar;
            m_onEndStringXMLChar = &cDerives::OnTextEndEntityXMLChar;
            break;

        default:
            // A+ A
            if (0 > (length = OnTextXMLChar(xmlChar)))
                return length;
        }
        return count;
    }
    /**
     **********************************************************************
     * Function: LTXMLPut
     *
     *   Author: $author$
     *     Date: 11/6/2008
     *
     * '<' ?
     **********************************************************************
     */
    TLENGTH LTXMLPut
    (cXMLChar& xmlChar) 
    {
        TLENGTH count = 1;
        CHAR c=xmlChar.GetCHAR();
        const cXMLChar* xmlChars;
        TLENGTH length;
        eError error;
        switch(c)
        {
        case '>':
            if ((error = OnBeginXMLTag()))
                return length = -error;
            if (!(xmlChars = OnEndXMLBeginTag(length)))
                return length;
            m_xmlPut = &cDerives::XMLPut;
            break;

        case '?':
            if ((error = OnBeginXMLProcessor()))
                return length = -error;
            m_xmlPut = &cDerives::ProcessorXMLPut;
            break;

        case '!':
            m_xmlPut = &cDerives::LTXMXMLPut;
            break;

        case '"':
            if ((error = OnBeginXMLTag()))
                return length = -error;
            if ((error = OnBeginXMLTagString()))
                return length = -error;
            if (0 > (length = OnTagXMLChar(xmlChar)))
                return length;
            m_oldXMLPut = m_xmlPut;
            m_xmlPut = &cDerives::QuotXMLPut;
            m_onStringXMLChar = &cDerives::OnTagXMLChar;
            m_onEndStringXMLChar = &cDerives::OnTagEndStringXMLChar;
            break;

        case '\'':
            if ((error = OnBeginXMLTag()))
                return length = -error;
            if ((error = OnBeginXMLTagString()))
                return length = -error;
            if (0 > (length = OnTagXMLChar(xmlChar)))
                return length;
            m_oldXMLPut = m_xmlPut;
            m_xmlPut = &cDerives::AposXMLPut;
            m_onStringXMLChar = &cDerives::OnTagXMLChar;
            m_onEndStringXMLChar = &cDerives::OnTagEndStringXMLChar;
            break;

        case '/':
            if ((error = OnBeginXMLEndTag()))
                return length = -error;
            m_xmlPut = &cDerives::LTSlashXMLPut;
            break;

        default:
            if (!IsTagNameXMLChar(xmlChar))
            {
                if ((error = OnBeginXMLTag()))
                    return length = -error;
                if (0 > (length = OnTagXMLChar(xmlChar)))
                    return length;
                m_xmlPut = &cDerives::TagNameXMLPut;
                break;
            }
            if ((error = OnBeginXMLTag()))
                return length = -error;
            if ((error = OnBeginXMLTagName()))
                return length = -error;
            if (0 > (length = OnTagNameXMLChar(xmlChar)))
                return length;
            m_xmlPut = &cDerives::TagXMLPut;
        }
        return count;
    }
    /**
     **********************************************************************
     * Function: LTSlashXMLPut
     *
     *   Author: $author$
     *     Date: 11/19/2008
     *
     * '<''/' ?
     **********************************************************************
     */
    TLENGTH LTSlashXMLPut
    (cXMLChar& xmlChar) 
    {
        TLENGTH count = 1;
        CHAR c=xmlChar.GetCHAR();
        const cXMLChar* xmlChars;
        TLENGTH length;
        eError error;
        switch(c)
        {
        case '>':
            if (!(xmlChars = OnEndXMLEndTag(length)))
                return length;
            m_xmlPut = &cDerives::XMLPut;
            break;

        case '"':
            if ((error = OnBeginXMLTagString()))
                return length = -error;
            if (0 > (length = OnTagXMLChar(xmlChar)))
                return length;
            m_oldXMLPut = &cDerives::EndTagNameXMLPut;
            m_xmlPut = &cDerives::QuotXMLPut;
            m_onStringXMLChar = &cDerives::OnTagXMLChar;
            m_onEndStringXMLChar = &cDerives::OnTagEndStringXMLChar;
            break;

        case '\'':
            if ((error = OnBeginXMLTagString()))
                return length = -error;
            if (0 > (length = OnTagXMLChar(xmlChar)))
                return length;
            m_oldXMLPut = &cDerives::EndTagNameXMLPut;
            m_xmlPut = &cDerives::AposXMLPut;
            m_onStringXMLChar = &cDerives::OnTagXMLChar;
            m_onEndStringXMLChar = &cDerives::OnTagEndStringXMLChar;
            break;

        default:
            if (!IsTagNameXMLChar(xmlChar))
            {
                if (0 > (length = OnTagXMLChar(xmlChar)))
                    return length;
                m_xmlPut = &cDerives::EndTagNameXMLPut;
                break;
            }
            if ((error = OnBeginXMLTagName()))
                return length = -error;
            if (0 > (length = OnTagNameXMLChar(xmlChar)))
                return length;
            m_xmlPut = &cDerives::EndTagXMLPut;
        }
        return count;
    }
    /**
     **********************************************************************
     * Function: TagXMLPut
     *
     *   Author: $author$
     *     Date: 11/6/2008
     *
     * '<'A+ ?
     **********************************************************************
     */
    TLENGTH TagXMLPut
    (cXMLChar& xmlChar) 
    {
        TLENGTH count = 1;
        CHAR c=xmlChar.GetCHAR();
        const cXMLChar* xmlChars;
        TLENGTH length;
        eError error;
        switch(c)
        {
        case '>':
            if (!(xmlChars = OnEndXMLTagName(length)))
                return length;
            if (!(xmlChars = OnEndXMLBeginTag(length)))
                return length;
            m_xmlPut = &cDerives::XMLPut;
            break;

        case '"':
            if (!(xmlChars = OnEndXMLTagName(length)))
                return length;
            if ((error = OnBeginXMLTagString()))
                return length = -error;
            if (0 > (length = OnTagXMLChar(xmlChar)))
                return length;
            m_oldXMLPut = &cDerives::TagNameXMLPut;;
            m_xmlPut = &cDerives::QuotXMLPut;
            m_onStringXMLChar = &cDerives::OnTagXMLChar;
            m_onEndStringXMLChar = &cDerives::OnTagEndStringXMLChar;
            break;

        case '\'':
            if (!(xmlChars = OnEndXMLTagName(length)))
                return length;
            if ((error = OnBeginXMLTagString()))
                return length = -error;
            if (0 > (length = OnTagXMLChar(xmlChar)))
                return length;
            m_oldXMLPut = &cDerives::TagNameXMLPut;;
            m_xmlPut = &cDerives::AposXMLPut;
            m_onStringXMLChar = &cDerives::OnTagXMLChar;
            m_onEndStringXMLChar = &cDerives::OnTagEndStringXMLChar;
            break;

        case '/':
            if (!(xmlChars = OnEndXMLTagName(length)))
                return length;
            m_xmlPut = &cDerives::TagSlashXMLPut;
            break;

        default:
            if (!IsTagNameXMLChar(xmlChar))
            {
                if (!(xmlChars = OnEndXMLTagName(length)))
                    return length;
                if (0 > (length = OnTagXMLChar(xmlChar)))
                    return length;
                m_xmlPut = &cDerives::TagNameXMLPut;
                break;
            }
            if (0 > (length = OnTagNameXMLChar(xmlChar)))
                return length;
        }
        return count;
    }
    /**
     **********************************************************************
     * Function: EndTagXMLPut
     *
     *   Author: $author$
     *     Date: 11/19/2008
     *
     * '<''/'A+ ?
     **********************************************************************
     */
    TLENGTH EndTagXMLPut
    (cXMLChar& xmlChar) 
    {
        TLENGTH count = 1;
        CHAR c=xmlChar.GetCHAR();
        const cXMLChar* xmlChars;
        TLENGTH length;
        eError error;
        switch(c)
        {
        case '>':
            if (!(xmlChars = OnEndXMLTagName(length)))
                return length;
            if (!(xmlChars = OnEndXMLEndTag(length)))
                return length;
            m_xmlPut = &cDerives::XMLPut;
            break;

        case '"':
            if (!(xmlChars = OnEndXMLTagName(length)))
                return length;
            if ((error = OnBeginXMLTagString()))
                return length = -error;
            if (0 > (length = OnTagXMLChar(xmlChar)))
                return length;
            m_oldXMLPut = &cDerives::EndTagNameXMLPut;;
            m_xmlPut = &cDerives::QuotXMLPut;
            m_onStringXMLChar = &cDerives::OnTagXMLChar;
            m_onEndStringXMLChar = &cDerives::OnTagEndStringXMLChar;
            break;

        case '\'':
            if (!(xmlChars = OnEndXMLTagName(length)))
                return length;
            if ((error = OnBeginXMLTagString()))
                return length = -error;
            if (0 > (length = OnTagXMLChar(xmlChar)))
                return length;
            m_oldXMLPut = &cDerives::EndTagNameXMLPut;;
            m_xmlPut = &cDerives::AposXMLPut;
            m_onStringXMLChar = &cDerives::OnTagXMLChar;
            m_onEndStringXMLChar = &cDerives::OnTagEndStringXMLChar;
            break;

        default:
            if (!IsTagNameXMLChar(xmlChar))
            {
                if (!(xmlChars = OnEndXMLTagName(length)))
                    return length;
                if (0 > (length = OnTagXMLChar(xmlChar)))
                    return length;
                m_xmlPut = &cDerives::EndTagNameXMLPut;
                break;
            }
            if (0 > (length = OnTagNameXMLChar(xmlChar)))
                return length;
        }
        return count;
    }
    /**
     **********************************************************************
     * Function: TagNameXMLPut
     *
     *   Author: $author$
     *     Date: 11/6/2008
     *
     * '<'A+WS+ ?
     **********************************************************************
     */
    TLENGTH TagNameXMLPut
    (cXMLChar& xmlChar) 
    {
        TLENGTH count = 1;
        CHAR c=xmlChar.GetCHAR();
        const cXMLChar* xmlChars;
        TLENGTH length;
        eError error;
        switch(c)
        {
        case '>':
            if (!(xmlChars = OnEndXMLBeginTag(length)))
                return length;
            m_xmlPut = &cDerives::XMLPut;
            break;

        case '"':
            if ((error = OnBeginXMLTagString()))
                return length = -error;
            if (0 > (length = OnTagXMLChar(xmlChar)))
                return length;
            m_oldXMLPut = m_xmlPut;
            m_xmlPut = &cDerives::QuotXMLPut;
            m_onStringXMLChar = &cDerives::OnTagXMLChar;
            m_onEndStringXMLChar = &cDerives::OnTagEndStringXMLChar;
            break;

        case '\'':
            if ((error = OnBeginXMLTagString()))
                return length = -error;
            if (0 > (length = OnTagXMLChar(xmlChar)))
                return length;
            m_oldXMLPut = m_xmlPut;
            m_xmlPut = &cDerives::AposXMLPut;
            m_onStringXMLChar = &cDerives::OnTagXMLChar;
            m_onEndStringXMLChar = &cDerives::OnTagEndStringXMLChar;
            break;

        case '/':
            m_xmlPut = &cDerives::TagSlashXMLPut;
            break;

        default:
            if (!IsTagNameXMLChar(xmlChar))
            {
                if (0 > (length = OnTagXMLChar(xmlChar)))
                    return length;
                break;
            }
            if ((error = OnBeginXMLAttributeName()))
                return length = -error;
            if (0 > (length = OnAttributeNameXMLChar(xmlChar)))
                return length;
            m_xmlPut = &cDerives::AttributeXMLPut;
        }
        return count;
    }
    /**
     **********************************************************************
     * Function: EndTagNameXMLPut
     *
     *   Author: $author$
     *     Date: 11/19/2008
     *
     * '<''/'A+WS+ ?
     **********************************************************************
     */
    TLENGTH EndTagNameXMLPut
    (cXMLChar& xmlChar) 
    {
        TLENGTH count = 1;
        CHAR c=xmlChar.GetCHAR();
        const cXMLChar* xmlChars;
        TLENGTH length;
        eError error;
        switch(c)
        {
        case '>':
            if (!(xmlChars = OnEndXMLEndTag(length)))
                return length;
            m_xmlPut = &cDerives::XMLPut;
            break;

        case '"':
            if ((error = OnBeginXMLTagString()))
                return length = -error;
            if (0 > (length = OnTagXMLChar(xmlChar)))
                return length;
            m_oldXMLPut = m_xmlPut;
            m_xmlPut = &cDerives::QuotXMLPut;
            m_onStringXMLChar = &cDerives::OnTagXMLChar;
            m_onEndStringXMLChar = &cDerives::OnTagEndStringXMLChar;
            break;

        case '\'':
            if ((error = OnBeginXMLTagString()))
                return length = -error;
            if (0 > (length = OnTagXMLChar(xmlChar)))
                return length;
            m_oldXMLPut = m_xmlPut;
            m_xmlPut = &cDerives::AposXMLPut;
            m_onStringXMLChar = &cDerives::OnTagXMLChar;
            m_onEndStringXMLChar = &cDerives::OnTagEndStringXMLChar;
            break;

        default:
            if (0 > (length = OnTagXMLChar(xmlChar)))
                return length;
        }
        return count;
    }
    /**
     **********************************************************************
     * Function: AttributeXMLPut
     *
     *   Author: $author$
     *     Date: 11/10/2008
     *
     * '<'A+WS+A+ ?
     **********************************************************************
     */
    TLENGTH AttributeXMLPut
    (cXMLChar& xmlChar) 
    {
        TLENGTH count = 1;
        CHAR c=xmlChar.GetCHAR();
        const cXMLChar* xmlChars;
        TLENGTH length;
        eError error;
        switch(c)
        {
        case '>':
            if (!(xmlChars = OnEndXMLAttributeName(length)))
                return length;
            if ((error = OnBeginXMLAttributeValueName()))
                return length = -error;
            if (!(xmlChars = OnEndXMLAttributeValueName(length)))
                return length;
            if (!(xmlChars = OnEndXMLBeginTag(length)))
                return length;
            m_xmlPut = &cDerives::XMLPut;
            break;

        case '"':
            if (!(xmlChars = OnEndXMLAttributeName(length)))
                return length;
            if ((error = OnBeginXMLAttributeValueName()))
                return length = -error;
            if (!(xmlChars = OnEndXMLAttributeValueName(length)))
                return length;
            if ((error = OnBeginXMLTagString()))
                return length = -error;
            if (0 > (length = OnTagXMLChar(xmlChar)))
                return length;
            m_oldXMLPut = &cDerives::TagNameXMLPut;
            m_xmlPut = &cDerives::QuotXMLPut;
            m_onStringXMLChar = &cDerives::OnTagXMLChar;
            m_onEndStringXMLChar = &cDerives::OnTagEndStringXMLChar;
            break;

        case '\'':
            if (!(xmlChars = OnEndXMLAttributeName(length)))
                return length;
            if ((error = OnBeginXMLAttributeValueName()))
                return length = -error;
            if (!(xmlChars = OnEndXMLAttributeValueName(length)))
                return length;
            if ((error = OnBeginXMLTagString()))
                return length = -error;
            if (0 > (length = OnTagXMLChar(xmlChar)))
                return length;
            m_oldXMLPut = &cDerives::TagNameXMLPut;
            m_xmlPut = &cDerives::AposXMLPut;
            m_onStringXMLChar = &cDerives::OnTagXMLChar;
            m_onEndStringXMLChar = &cDerives::OnTagEndStringXMLChar;
            break;

        case '/':
            if (!(xmlChars = OnEndXMLAttributeName(length)))
                return length;
            if ((error = OnBeginXMLAttributeValueName()))
                return length = -error;
            if (!(xmlChars = OnEndXMLAttributeValueName(length)))
                return length;
            m_xmlPut = &cDerives::TagSlashXMLPut;
            break;

        case '=':
            if (!(xmlChars = OnEndXMLAttributeName(length)))
                return length;
            if (0 > (length = OnTagXMLChar(xmlChar)))
                return length;
            m_xmlPut = &cDerives::AttributeNameEQXMLPut;
            break;

        default:
            if (!IsTagNameXMLChar(xmlChar))
            {
                if (!(xmlChars = OnEndXMLAttributeName(length)))
                    return length;
                if (0 > (length = OnTagXMLChar(xmlChar)))
                    return length;
                m_xmlPut = &cDerives::AttributeNameXMLPut;
                break;
            }
            if (0 > (length = OnAttributeNameXMLChar(xmlChar)))
                return length;
        }
        return count;
    }
    /**
     **********************************************************************
     * Function: AttributeNameXMLPut
     *
     *   Author: $author$
     *     Date: 11/10/2008
     *
     * '<'A+WS+A+WS+ ?
     **********************************************************************
     */
    TLENGTH AttributeNameXMLPut
    (cXMLChar& xmlChar) 
    {
        TLENGTH count = 1;
        CHAR c=xmlChar.GetCHAR();
        const cXMLChar* xmlChars;
        TLENGTH length;
        eError error;
        switch(c)
        {
        case '>':
            if (!(xmlChars = OnEndXMLBeginTag(length)))
                return length;
            m_xmlPut = &cDerives::XMLPut;
            break;

        case '"':
            if ((error = OnBeginXMLTagString()))
                return length = -error;
            if (0 > (length = OnTagXMLChar(xmlChar)))
                return length;
            m_oldXMLPut = &cDerives::TagNameXMLPut;
            m_xmlPut = &cDerives::QuotXMLPut;
            m_onStringXMLChar = &cDerives::OnTagXMLChar;
            m_onEndStringXMLChar = &cDerives::OnTagEndStringXMLChar;
            break;

        case '\'':
            if ((error = OnBeginXMLTagString()))
                return length = -error;
            if (0 > (length = OnTagXMLChar(xmlChar)))
                return length;
            m_oldXMLPut = &cDerives::TagNameXMLPut;
            m_xmlPut = &cDerives::AposXMLPut;
            m_onStringXMLChar = &cDerives::OnTagXMLChar;
            m_onEndStringXMLChar = &cDerives::OnTagEndStringXMLChar;
            break;

        case '/':
            m_xmlPut = &cDerives::TagSlashXMLPut;
            break;

        case ' ':
        case '\r':
        case '\t':
        case '\v':
            if (0 > (length = OnTagXMLChar(xmlChar)))
                return length;
            break;

        default:
            if (!IsTagNameXMLChar(xmlChar))
            {
                if (0 > (length = OnTagXMLChar(xmlChar)))
                    return length;
                m_xmlPut = &cDerives::TagNameXMLPut;
                break;
            }
            if ((error = OnBeginXMLAttributeName()))
                return length = -error;
            if (0 > (length = OnAttributeNameXMLChar(xmlChar)))
                return length;
            m_xmlPut = &cDerives::AttributeXMLPut;
        }
        return count;
    }
    /**
     **********************************************************************
     * Function: AttributeNameEQXMLPut
     *
     *   Author: $author$
     *     Date: 11/20/2008
     *
     * '<'A+WS+A+WS*'=' ?
     **********************************************************************
     */
    TLENGTH AttributeNameEQXMLPut
    (cXMLChar& xmlChar) 
    {
        TLENGTH count = 1;
        CHAR c=xmlChar.GetCHAR();
        const cXMLChar* xmlChars;
        TLENGTH length;
        eError error;
        switch(c)
        {
        case '>':
            if (!(xmlChars = OnEndXMLBeginTag(length)))
                return length;
            m_xmlPut = &cDerives::XMLPut;
            break;

        case '"':
            if ((error = OnBeginXMLAttributeValueString()))
                return length = -error;
            //if ((error = OnBeginXMLTagString()))
            //    return length = -error;
            if (0 > (length = OnTagXMLChar(xmlChar)))
                return length;
            m_oldXMLPut = &cDerives::TagNameXMLPut;
            m_xmlPut = &cDerives::QuotXMLPut;
            m_onStringXMLChar = &cDerives::OnAttributeValueStringXMLChar;
            m_onEndStringXMLChar = &cDerives::OnAttributeValueEndStringXMLChar;
            break;

        case '\'':
            if ((error = OnBeginXMLAttributeValueString()))
                return length = -error;
            //if ((error = OnBeginXMLTagString()))
            //    return length = -error;
            if (0 > (length = OnTagXMLChar(xmlChar)))
                return length;
            m_oldXMLPut = &cDerives::TagNameXMLPut;
            m_xmlPut = &cDerives::AposXMLPut;
            m_onStringXMLChar = &cDerives::OnAttributeValueStringXMLChar;
            m_onEndStringXMLChar = &cDerives::OnAttributeValueEndStringXMLChar;
            break;

        case '/':
            m_xmlPut = &cDerives::TagSlashXMLPut;
            break;

        case ' ':
        case '\r':
        case '\t':
        case '\v':
            if (0 > (length = OnTagXMLChar(xmlChar)))
                return length;
            break;

        default:
            if (!IsTagNameXMLChar(xmlChar))
            {
                if (0 > (length = OnTagXMLChar(xmlChar)))
                    return length;
                m_xmlPut = &cDerives::TagNameXMLPut;
                break;
            }
            if ((error = OnBeginXMLAttributeValueName()))
                return length = -error;
            if (0 > (length = OnAttributeValueXMLChar(xmlChar)))
                return length;
            m_xmlPut = &cDerives::AttributeValueNameXMLPut;
        }
        return count;
    }
    /**
     **********************************************************************
     * Function: AttributeValueNameXMLPut
     *
     *   Author: $author$
     *     Date: 11/20/2008
     *
     * '<'A+WS+A+WS*'='WS*A+ ?
     **********************************************************************
     */
    TLENGTH AttributeValueNameXMLPut
    (cXMLChar& xmlChar) 
    {
        TLENGTH count = 1;
        CHAR c=xmlChar.GetCHAR();
        const cXMLChar* xmlChars;
        TLENGTH length;
        eError error;
        switch(c)
        {
        case '>':
            if (!(xmlChars = OnEndXMLAttributeValueName(length)))
                return length;
            if (!(xmlChars = OnEndXMLBeginTag(length)))
                return length;
            m_xmlPut = &cDerives::XMLPut;
            break;

        case '"':
            if ((error = OnBeginXMLTagString()))
                return length = -error;
            if (0 > (length = OnTagXMLChar(xmlChar)))
                return length;
            m_oldXMLPut = &cDerives::TagNameXMLPut;
            m_xmlPut = &cDerives::QuotXMLPut;
            m_onStringXMLChar = &cDerives::OnTagXMLChar;
            m_onEndStringXMLChar = &cDerives::OnTagEndStringXMLChar;
            break;

        case '\'':
            if ((error = OnBeginXMLTagString()))
                return length = -error;
            if (0 > (length = OnTagXMLChar(xmlChar)))
                return length;
            m_oldXMLPut = &cDerives::TagNameXMLPut;
            m_xmlPut = &cDerives::AposXMLPut;
            m_onStringXMLChar = &cDerives::OnTagXMLChar;
            m_onEndStringXMLChar = &cDerives::OnTagEndStringXMLChar;
            break;

        case '/':
            m_xmlPut = &cDerives::TagSlashXMLPut;
            break;

        default:
            if (!IsTagNameXMLChar(xmlChar))
            {
                if (!(xmlChars = OnEndXMLAttributeValueName(length)))
                    return length;
                if (0 > (length = OnTagXMLChar(xmlChar)))
                    return length;
                m_xmlPut = &cDerives::TagNameXMLPut;
                break;
            }
            if (0 > (length = OnAttributeValueXMLChar(xmlChar)))
                return length;
        }
        return count;
    }
    /**
     **********************************************************************
     * Function: TagSlashXMLPut
     *
     *   Author: $author$
     *     Date: 11/6/2008
     *
     * '<'A'/' ?
     **********************************************************************
     */
    TLENGTH TagSlashXMLPut
    (cXMLChar& xmlChar) 
    {
        TLENGTH count = 1;
        CHAR c=xmlChar.GetCHAR();
        const cXMLChar* xmlChars;
        TLENGTH length;
        eError error;
        switch(c)
        {
        case '>':
            if (!(xmlChars = OnEndXMLTag(length)))
                return length;
            m_xmlPut = &cDerives::XMLPut;
            break;

        case '"':
            if (0 > (length = OnTagXMLChar(m_slash)))
                return length;
            if ((error = OnBeginXMLTagString()))
                return length = -error;
            if (0 > (length = OnTagXMLChar(xmlChar)))
                return length;
            m_oldXMLPut = &cDerives::TagXMLPut;
            m_xmlPut = &cDerives::QuotXMLPut;
            m_onStringXMLChar = &cDerives::OnTagXMLChar;
            m_onEndStringXMLChar = &cDerives::OnTagEndStringXMLChar;
            break;

        case '\'':
            if (0 > (length = OnTagXMLChar(m_slash)))
                return length;
            if ((error = OnBeginXMLTagString()))
                return length = -error;
            if (0 > (length = OnTagXMLChar(xmlChar)))
                return length;
            m_oldXMLPut = &cDerives::TagXMLPut;
            m_xmlPut = &cDerives::AposXMLPut;
            m_onStringXMLChar = &cDerives::OnTagXMLChar;
            m_onEndStringXMLChar = &cDerives::OnTagEndStringXMLChar;
            break;

        case '/':
            if (0 > (length = OnTagXMLChar(m_slash)))
                return length;
            break;

        default:
            if (0 > (length = OnTagXMLChar(m_slash)))
                return length;
            if (0 > (length = OnTagXMLChar(xmlChar)))
                return length;
            m_xmlPut = &cDerives::TagXMLPut;
        }
        return count;
    }
    /**
     **********************************************************************
     * Function: ProcessorXMLPut
     *
     *   Author: $author$
     *     Date: 11/6/2008
     *
     * '<''?' ?
     **********************************************************************
     */
    TLENGTH ProcessorXMLPut
    (cXMLChar& xmlChar) 
    {
        TLENGTH count = 1;
        CHAR c=xmlChar.GetCHAR();
        const cXMLChar* xmlChars;
        TLENGTH length;
        switch(c)
        {
        case '>':
            if (!(xmlChars = OnEndXMLProcessor(length)))
                return length;
            m_xmlPut = &cDerives::XMLPut;
            break;

        case '?':
            m_xmlPut = &cDerives::ProcessorQMXMLPut;
            break;

        case '"':
            if (0 > (length = OnProcessorXMLChar(xmlChar)))
                return length;
            m_oldXMLPut = m_xmlPut;
            m_xmlPut = &cDerives::QuotXMLPut;
            m_onStringXMLChar = &cDerives::OnProcessorXMLChar;
            m_onEndStringXMLChar = &cDerives::OnProcessorEndStringXMLChar;
            break;

        case '\'':
            if (0 > (length = OnProcessorXMLChar(xmlChar)))
                return length;
            m_oldXMLPut = m_xmlPut;
            m_xmlPut = &cDerives::AposXMLPut;
            m_onStringXMLChar = &cDerives::OnProcessorXMLChar;
            m_onEndStringXMLChar = &cDerives::OnProcessorEndStringXMLChar;
            break;

        default:
            if (0 > (length = OnProcessorXMLChar(xmlChar)))
                return length;
        }
        return count;
    }
    /**
     **********************************************************************
     * Function: ProcessorQMXMLPut
     *
     *   Author: $author$
     *     Date: 11/6/2008
     *
     * '<''?' .* '?' ?
     **********************************************************************
     */
    TLENGTH ProcessorQMXMLPut
    (cXMLChar& xmlChar) 
    {
        TLENGTH count = 1;
        CHAR c=xmlChar.GetCHAR();
        const cXMLChar* xmlChars;
        TLENGTH length;
        switch(c)
        {
        case '>':
            if (!(xmlChars = OnEndXMLProcessor(length)))
                return length;
            m_xmlPut = &cDerives::XMLPut;
            break;

        case '?':
            if (0 > (length = OnProcessorXMLChar(m_qm)))
                return length;
            break;

        case '"':
            if (0 > (length = OnProcessorXMLChar(xmlChar)))
                return length;
            m_oldXMLPut = &cDerives::ProcessorXMLPut;
            m_xmlPut = &cDerives::QuotXMLPut;
            m_onStringXMLChar = &cDerives::OnProcessorXMLChar;
            m_onEndStringXMLChar = &cDerives::OnProcessorEndStringXMLChar;
            break;

        case '\'':
            if (0 > (length = OnProcessorXMLChar(xmlChar)))
                return length;
            m_oldXMLPut = &cDerives::ProcessorXMLPut;
            m_xmlPut = &cDerives::AposXMLPut;
            m_onStringXMLChar = &cDerives::OnProcessorXMLChar;
            m_onEndStringXMLChar = &cDerives::OnProcessorEndStringXMLChar;
            break;

        default:
            if (0 > (length = OnProcessorXMLChar(m_qm)))
                return length;
            if (0 > (length = OnProcessorXMLChar(xmlChar)))
                return length;
            m_xmlPut = &cDerives::ProcessorXMLPut;
        }
        return count;
    }
    /**
     **********************************************************************
     * Function: LTXMXMLPut
     *
     *   Author: $author$
     *     Date: 11/6/2008
     *
     * '<''!' ?
     **********************************************************************
     */
    TLENGTH LTXMXMLPut
    (cXMLChar& xmlChar) 
    {
        TLENGTH count = 1;
        CHAR c=xmlChar.GetCHAR();
        const cXMLChar* xmlChars;
        TLENGTH length;
        eError error;
        switch(c)
        {
        case '>':
            if ((error = OnBeginXMLDeclaration()))
                return length = -error;
            if (!(xmlChars = OnEndXMLDeclaration(length)))
                return length;
            m_xmlPut = &cDerives::XMLPut;
            break;

        case '-':
            m_xmlPut = &cDerives::LTXMMinusXMLPut;
            break;

        case '"':
            if (0 > (length = OnTagXMLChar(m_xm)))
                return length;
            if ((error = OnBeginXMLTagString()))
                return length = -error;
            if (0 > (length = OnTagXMLChar(xmlChar)))
                return length;
            m_oldXMLPut = &cDerives::TagXMLPut;
            m_xmlPut = &cDerives::QuotXMLPut;
            m_onStringXMLChar = &cDerives::OnTagXMLChar;
            m_onEndStringXMLChar = &cDerives::OnTagEndStringXMLChar;
            break;

        case '\'':
            if (0 > (length = OnTagXMLChar(m_xm)))
                return length;
            if ((error = OnBeginXMLTagString()))
                return length = -error;
            if (0 > (length = OnTagXMLChar(xmlChar)))
                return length;
            m_oldXMLPut = &cDerives::TagXMLPut;
            m_xmlPut = &cDerives::AposXMLPut;
            m_onStringXMLChar = &cDerives::OnTagXMLChar;
            m_onEndStringXMLChar = &cDerives::OnTagEndStringXMLChar;
            break;

        case '[':
            if ((error = OnBeginXMLSection()))
                return length = -error;
            if (0 > (length = OnSectionXMLChar(xmlChar)))
                return length;
            m_xmlPut = &cDerives::SectionXMLPut;
            m_ltDepth = 0;
            m_lbDepth = 0;
            break;

        default:
            if ((error = OnBeginXMLDeclaration()))
                return length = -error;
            if (0 > (length = OnDeclarationXMLChar(xmlChar)))
                return length;
            m_xmlPut = &cDerives::DeclarationXMLPut;
            m_ltDepth = 0;
            m_lbDepth = 0;
        }
        return count;
    }
    /**
     **********************************************************************
     * Function: LTXMMinusXMLPut
     *
     *   Author: $author$
     *     Date: 11/6/2008
     *
     * '<''!''-' ?
     **********************************************************************
     */
    TLENGTH LTXMMinusXMLPut
    (cXMLChar& xmlChar) 
    {
        TLENGTH count = 1;
        CHAR c=xmlChar.GetCHAR();
        const cXMLChar* xmlChars;
        TLENGTH length;
        eError error;
        switch(c)
        {
        case '>':
            if (!(xmlChars = OnEndXMLBeginTag(length)))
                return length;
            m_xmlPut = &cDerives::XMLPut;
            break;

        case '-':
            if ((error = OnBeginXMLComment()))
                return length = -error;
            m_xmlPut = &cDerives::CommentXMLPut;
            break;

        case '"':
            if ((error = OnBeginXMLTag()))
                return length = -error;
            if (0 > (length = OnTagXMLChar(m_xm)))
                return length;
            if (0 > (length = OnTagXMLChar(m_minus)))
                return length;
            if ((error = OnBeginXMLTagString()))
                return length = -error;
            if (0 > (length = OnTagXMLChar(xmlChar)))
                return length;
            m_oldXMLPut = &cDerives::TagXMLPut;
            m_xmlPut = &cDerives::QuotXMLPut;
            m_onStringXMLChar = &cDerives::OnTagXMLChar;
            m_onEndStringXMLChar = &cDerives::OnTagEndStringXMLChar;
            break;

        case '\'':
            if ((error = OnBeginXMLTag()))
                return length = -error;
            if (0 > (length = OnTagXMLChar(m_xm)))
                return length;
            if (0 > (length = OnTagXMLChar(m_minus)))
                return length;
            if ((error = OnBeginXMLTagString()))
                return length = -error;
            if (0 > (length = OnTagXMLChar(xmlChar)))
                return length;
            m_oldXMLPut = &cDerives::TagXMLPut;
            m_xmlPut = &cDerives::AposXMLPut;
            m_onStringXMLChar = &cDerives::OnTagXMLChar;
            m_onEndStringXMLChar = &cDerives::OnTagEndStringXMLChar;
            break;

        default:
            if ((error = OnBeginXMLTag()))
                return length = -error;
            if (0 > (length = OnTagXMLChar(m_xm)))
                return length;
            if (0 > (length = OnTagXMLChar(m_minus)))
                return length;
            if (0 > (length = OnTagXMLChar(xmlChar)))
                return length;
            m_xmlPut = &cDerives::TagXMLPut;
        }
        return count;
    }
    /**
     **********************************************************************
     * Function: CommentXMLPut
     *
     *   Author: $author$
     *     Date: 11/6/2008
     *
     * '<''!''-''-' ?
     **********************************************************************
     */
    TLENGTH CommentXMLPut
    (cXMLChar& xmlChar) 
    {
        TLENGTH count = 1;
        CHAR c=xmlChar.GetCHAR();
        TLENGTH length;
        switch(c)
        {
        case '-':
            m_xmlPut = &cDerives::CommentMinusXMLPut;
            break;

        default:
            if (0 > (length = OnCommentXMLChar(xmlChar)))
                return length;
        }
        return count;
    }
    /**
     **********************************************************************
     * Function: CommentMinusXMLPut
     *
     *   Author: $author$
     *     Date: 11/6/2008
     *
     * '<''!''-''-' .+ '-' ?
     **********************************************************************
     */
    TLENGTH CommentMinusXMLPut
    (cXMLChar& xmlChar) 
    {
        TLENGTH count = 1;
        CHAR c=xmlChar.GetCHAR();
        TLENGTH length;
        switch(c)
        {
        case '-':
            m_xmlPut = &cDerives::CommentMinusMinusXMLPut;
            break;

        default:
            if (0 > (length = OnCommentXMLChar(m_minus)))
                return length;
            if (0 > (length = OnCommentXMLChar(xmlChar)))
                return length;
            m_xmlPut = &cDerives::CommentXMLPut;
        }
        return count;
    }
    /**
     **********************************************************************
     * Function: CommentMinusMinusXMLPut
     *
     *   Author: $author$
     *     Date: 11/6/2008
     *
     * '<''!''-''-' .+ '-''-' ?
     **********************************************************************
     */
    TLENGTH CommentMinusMinusXMLPut
    (cXMLChar& xmlChar) 
    {
        TLENGTH count = 1;
        CHAR c=xmlChar.GetCHAR();
        const cXMLChar* xmlChars;
        TLENGTH length;
        switch(c)
        {
        case '>':
            if (!(xmlChars = OnEndXMLComment(length)))
                return length;
            m_xmlPut = &cDerives::XMLPut;
            break;

        case '-':
            if (0 > (length = OnCommentXMLChar(m_minus)))
                return length;
            break;

        default:
            if (0 > (length = OnCommentXMLChar(m_minus)))
                return length;
            if (0 > (length = OnCommentXMLChar(m_minus)))
                return length;
            if (0 > (length = OnCommentXMLChar(xmlChar)))
                return length;
            m_xmlPut = &cDerives::CommentXMLPut;
        }
        return count;
    }
    /**
     **********************************************************************
     * Function: DeclarationXMLPut
     *
     *   Author: $author$
     *     Date: 11/11/2008
     *
     * '<''!'A+ ?
     **********************************************************************
     */
    TLENGTH DeclarationXMLPut
    (cXMLChar& xmlChar) 
    {
        TLENGTH count = 1;
        CHAR c=xmlChar.GetCHAR();
        const cXMLChar* xmlChars;
        TLENGTH length;
        eError error;
        switch(c)
        {
        case '<':
            if (0 > (length = OnDeclarationXMLChar(xmlChar)))
                return length;
            m_ltDepth++;
            break;

        case '>':
            if (0 < m_ltDepth)
            {
                if (0 > (length = OnDeclarationXMLChar(xmlChar)))
                    return length;
                --m_ltDepth;
                break;
            }
            if (!(xmlChars = OnEndXMLDeclaration(length)))
                return length;
            m_xmlPut = &cDerives::XMLPut;
            break;

        case '"':
            if ((error = OnBeginXMLDeclarationString()))
                return length = -error;
            if (0 > (length = OnDeclarationXMLChar(xmlChar)))
                return length;
            m_oldXMLPut = &cDerives::DeclarationXMLPut;
            m_xmlPut = &cDerives::QuotXMLPut;
            m_onStringXMLChar = &cDerives::OnDeclarationXMLChar;
            m_onEndStringXMLChar = &cDerives::OnDeclarationEndStringXMLChar;
            break;

        case '\'':
            if ((error = OnBeginXMLDeclarationString()))
                return length = -error;
            if (0 > (length = OnDeclarationXMLChar(xmlChar)))
                return length;
            m_oldXMLPut = &cDerives::DeclarationXMLPut;
            m_xmlPut = &cDerives::AposXMLPut;
            m_onStringXMLChar = &cDerives::OnDeclarationXMLChar;
            m_onEndStringXMLChar = &cDerives::OnDeclarationEndStringXMLChar;
            break;

        default:
            if (0 > (length = OnDeclarationXMLChar(xmlChar)))
                return length;
        }
        return count;
    }
    /**
     **********************************************************************
     * Function: SectionXMLPut
     *
     *   Author: $author$
     *     Date: 11/11/2008
     *
     * '<''!''[' ?
     **********************************************************************
     */
    TLENGTH SectionXMLPut
    (cXMLChar& xmlChar) 
    {
        TLENGTH count = 1;
        CHAR c=xmlChar.GetCHAR();
        //const cXMLChar* xmlChars;
        TLENGTH length;
        eError error;
        switch(c)
        {
        case '[':
            if (0 > (length = OnSectionXMLChar(xmlChar)))
                return length;
            m_lbDepth++;
            break;

        case ']':
            if (0 < m_lbDepth)
            {
                if (0 > (length = OnSectionXMLChar(xmlChar)))
                    return length;
                --m_lbDepth;
                break;
            }
            m_xmlPut = &cDerives::SectionRBXMLPut;
            break;

        case '"':
            if ((error = OnBeginXMLSectionString()))
                return length = -error;
            if (0 > (length = OnSectionXMLChar(xmlChar)))
                return length;
            m_oldXMLPut = &cDerives::SectionXMLPut;
            m_xmlPut = &cDerives::QuotXMLPut;
            m_onStringXMLChar = &cDerives::OnSectionXMLChar;
            m_onEndStringXMLChar = &cDerives::OnSectionEndStringXMLChar;
            break;

        case '\'':
            if ((error = OnBeginXMLSectionString()))
                return length = -error;
            if (0 > (length = OnSectionXMLChar(xmlChar)))
                return length;
            m_oldXMLPut = &cDerives::SectionXMLPut;
            m_xmlPut = &cDerives::AposXMLPut;
            m_onStringXMLChar = &cDerives::OnSectionXMLChar;
            m_onEndStringXMLChar = &cDerives::OnSectionEndStringXMLChar;
            break;

        default:
            if (0 > (length = OnSectionXMLChar(xmlChar)))
                return length;
        }
        return count;
    }
    /**
     **********************************************************************
     * Function: SectionRBXMLPut
     *
     *   Author: $author$
     *     Date: 11/11/2008
     *
     * '<''!''[' .* ']'+ ?
     **********************************************************************
     */
    TLENGTH SectionRBXMLPut
    (cXMLChar& xmlChar) 
    {
        TLENGTH count = 1;
        CHAR c=xmlChar.GetCHAR();
        const cXMLChar* xmlChars;
        TLENGTH length;
        //eError error;
        switch(c)
        {
        case '>':
            if (!(xmlChars = OnEndXMLSection(length)))
                return length;
            m_xmlPut = &cDerives::XMLPut;
            break;

        case '[':
            if (0 > (length = OnSectionXMLChar(m_rb)))
                return length;
            m_lbDepth++;
            m_xmlPut = &cDerives::SectionXMLPut;
            break;

        case ']':
            if (0 > (length = OnSectionXMLChar(m_rb)))
                return length;
            break;

        default:
            if (0 > (length = OnSectionXMLChar(m_rb)))
                return length;
            if (0 > (length = OnSectionXMLChar(xmlChar)))
                return length;
            m_xmlPut = &cDerives::SectionXMLPut;
        }
        return count;
    }

    /**
     **********************************************************************
     * Function: QuotXMLPut
     *
     *   Author: $author$
     *     Date: 11/7/2008
     **********************************************************************
     */
    TLENGTH QuotXMLPut
    (cXMLChar& xmlChar) 
    {
        TLENGTH count = 1;
        CHAR c=xmlChar.GetCHAR();
        switch(c)
        {
        case '"':
            m_xmlPut = m_oldXMLPut;
            if (0 > (count = OnEndStringXMLChar(xmlChar)))
                return count;
            break;

        default:
            if (0 > (count = count = OnStringXMLChar(xmlChar)))
                return count;
        }
        return count;
    }
    /**
     **********************************************************************
     * Function: AposXMLPut
     *
     *   Author: $author$
     *     Date: 11/7/2008
     **********************************************************************
     */
    TLENGTH AposXMLPut
    (cXMLChar& xmlChar) 
    {
        TLENGTH count = 1;
        CHAR c=xmlChar.GetCHAR();
        switch(c)
        {
        case '\'':
            m_xmlPut = m_oldXMLPut;
            if (0 > (count = OnEndStringXMLChar(xmlChar)))
                return count;
            break;

        default:
            if (0 > (count = OnStringXMLChar(xmlChar)))
                return count;
        }
        return count;
    }
    /**
     **********************************************************************
     * Function: AmpXMLPut
     *
     *   Author: $author$
     *     Date: 12/15/2008
     **********************************************************************
     */
    TLENGTH AmpXMLPut
    (cXMLChar& xmlChar) 
    {
        TLENGTH count = 1;
        CHAR c=xmlChar.GetCHAR();
        switch(c)
        {
        case ';':
            m_xmlPut = m_oldXMLPut;
            if (0 > (count = OnEndStringXMLChar(xmlChar)))
                return count;
            break;

        default:
            if (0 > (count = OnStringXMLChar(xmlChar)))
                return count;
        }
        return count;
    }

    /**
     **********************************************************************
     * Function: OnStringXMLChar
     *
     *   Author: $author$
     *     Date: 11/7/2008
     **********************************************************************
     */
    TLENGTH OnStringXMLChar
    (cXMLChar& xmlChar) 
    {
        TLENGTH length = 1;
        if (m_onStringXMLChar)
            length = (this->*m_onStringXMLChar)(xmlChar);
        return length;
    }
    /**
     **********************************************************************
     * Function: OnEndStringXMLChar
     *
     *   Author: $author$
     *     Date: 11/9/2008
     **********************************************************************
     */
    TLENGTH OnEndStringXMLChar
    (cXMLChar& xmlChar) 
    {
        TLENGTH count = 1;
        if (m_onEndStringXMLChar)
            count = (this->*m_onEndStringXMLChar)(xmlChar);
        return count;
    }

    /**
     **********************************************************************
     * Function: OnTextEndEntityXMLChar
     *
     *   Author: $author$
     *     Date: 12/15/2008
     **********************************************************************
     */
    TLENGTH OnTextEndEntityXMLChar
    (cXMLChar& xmlChar) 
    {
        TLENGTH count = 1;
        TLENGTH length;
        if (0 <= (count = OnTextXMLChar(xmlChar)))
            OnEndXMLTextEntity(length);
        return count;
    }
    /**
     **********************************************************************
     * Function: OnTextEndStringXMLChar
     *
     *   Author: $author$
     *     Date: 11/11/2008
     **********************************************************************
     */
    TLENGTH OnTextEndStringXMLChar
    (cXMLChar& xmlChar) 
    {
        TLENGTH count = 1;
        TLENGTH length;
        if (0 <= (count = OnTextXMLChar(xmlChar)))
            OnEndXMLTextString(length);
        return count;
    }
    /**
     **********************************************************************
     * Function: OnProcessorEndStringXMLChar
     *
     *   Author: $author$
     *     Date: 11/9/2008
     **********************************************************************
     */
    TLENGTH OnProcessorEndStringXMLChar
    (cXMLChar& xmlChar) 
    {
        TLENGTH count = 1;
        TLENGTH length;
        if (0 <= (count = OnProcessorXMLChar(xmlChar)))
            OnEndXMLProcessorString(length);
        return count;
    }
    /**
     **********************************************************************
     * Function: OnCommentEndStringXMLChar
     *
     *   Author: $author$
     *     Date: 11/9/2008
     **********************************************************************
     */
    TLENGTH OnCommentEndStringXMLChar
    (cXMLChar& xmlChar) 
    {
        TLENGTH count = 1;
        TLENGTH length;
        if (0 <= (count = OnCommentXMLChar(xmlChar)))
            OnEndXMLCommentString(length);
        return count;
    }
    /**
     **********************************************************************
     * Function: OnDeclarationEndStringXMLChar
     *
     *   Author: $author$
     *     Date: 11/9/2008
     **********************************************************************
     */
    TLENGTH OnDeclarationEndStringXMLChar
    (cXMLChar& xmlChar) 
    {
        TLENGTH count = 1;
        TLENGTH length;
        if (0 <= (count = OnDeclarationXMLChar(xmlChar)))
            OnEndXMLDeclarationString(length);
        return count;
    }
    /**
     **********************************************************************
     * Function: OnSectionEndStringXMLChar
     *
     *   Author: $author$
     *     Date: 11/9/2008
     **********************************************************************
     */
    TLENGTH OnSectionEndStringXMLChar
    (cXMLChar& xmlChar) 
    {
        TLENGTH count = 1;
        TLENGTH length;
        if (0 <= (count = OnSectionXMLChar(xmlChar)))
            OnEndXMLSectionString(length);
        return count;
    }
    /**
     **********************************************************************
     * Function: OnTagEndStringXMLChar
     *
     *   Author: $author$
     *     Date: 11/9/2008
     **********************************************************************
     */
    TLENGTH OnTagEndStringXMLChar
    (cXMLChar& xmlChar) 
    {
        TLENGTH count = 1;
        TLENGTH length;
        if (0 <= (count = OnTagXMLChar(xmlChar)))
            OnEndXMLTagString(length);
        return count;
    }
    /**
     **********************************************************************
     * Function: OnAttributeValueEndStringXMLChar
     *
     *   Author: $author$
     *     Date: 11/20/2008
     **********************************************************************
     */
    TLENGTH OnAttributeValueEndStringXMLChar
    (cXMLChar& xmlChar) 
    {
        TLENGTH count = 1;
        TLENGTH length;
        const cXMLChar* xmlChars;
        if ((xmlChars = OnEndXMLAttributeValueString(length)))
        if (0 <= (count = OnTagXMLChar(xmlChar)))
            OnEndXMLTagString(length);
        return count;
    }

    /**
     **********************************************************************
     * Function: OnProcessorXMLChar
     *
     *   Author: $author$
     *     Date: 11/7/2008
     **********************************************************************
     */
    TLENGTH OnProcessorXMLChar
    (cXMLChar& xmlChar) 
    {
        TLENGTH count = m_xmlParserEvents.OnProcessorXMLChar(xmlChar);
        return count;
    }
    /**
     **********************************************************************
     * Function: OnProcessorStringXMLChar
     *
     *   Author: $author$
     *     Date: 11/7/2008
     **********************************************************************
     */
    TLENGTH OnProcessorStringXMLChar
    (cXMLChar& xmlChar) 
    {
        TLENGTH count = m_xmlParserEvents.OnProcessorStringXMLChar(xmlChar);
        return count;
    }
    /**
     **********************************************************************
     * Function: OnCommentXMLChar
     *
     *   Author: $author$
     *     Date: 11/7/2008
     **********************************************************************
     */
    TLENGTH OnCommentXMLChar
    (cXMLChar& xmlChar) 
    {
        TLENGTH count = m_xmlParserEvents.OnCommentXMLChar(xmlChar);
        return count;
    }
    /**
     **********************************************************************
     * Function: OnDeclarationXMLChar
     *
     *   Author: $author$
     *     Date: 11/7/2008
     **********************************************************************
     */
    TLENGTH OnDeclarationXMLChar
    (cXMLChar& xmlChar) 
    {
        TLENGTH count = m_xmlParserEvents.OnDeclarationXMLChar(xmlChar);
        return count;
    }
    /**
     **********************************************************************
     * Function: OnDeclarationStringXMLChar
     *
     *   Author: $author$
     *     Date: 11/7/2008
     **********************************************************************
     */
    TLENGTH OnDeclarationStringXMLChar
    (cXMLChar& xmlChar) 
    {
        TLENGTH count = m_xmlParserEvents.OnDeclarationStringXMLChar(xmlChar);
        return count;
    }
    /**
     **********************************************************************
     * Function: OnSectionXMLChar
     *
     *   Author: $author$
     *     Date: 11/7/2008
     **********************************************************************
     */
    TLENGTH OnSectionXMLChar
    (cXMLChar& xmlChar) 
    {
        TLENGTH count = m_xmlParserEvents.OnSectionXMLChar(xmlChar);
        return count;
    }
    /**
     **********************************************************************
     * Function: OnSectionStringXMLChar
     *
     *   Author: $author$
     *     Date: 11/7/2008
     **********************************************************************
     */
    TLENGTH OnSectionStringXMLChar
    (cXMLChar& xmlChar) 
    {
        TLENGTH count = m_xmlParserEvents.OnSectionStringXMLChar(xmlChar);
        return count;
    }
    /**
     **********************************************************************
     * Function: OnTagXMLChar
     *
     *   Author: $author$
     *     Date: 11/7/2008
     **********************************************************************
     */
    TLENGTH OnTagXMLChar
    (cXMLChar& xmlChar) 
    {
        TLENGTH count = m_xmlParserEvents.OnTagXMLChar(xmlChar);
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
    TLENGTH OnTagNameXMLChar
    (cXMLChar& xmlChar) 
    {
        TLENGTH count = m_xmlParserEvents.OnTagNameXMLChar(xmlChar);
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
    TLENGTH OnAttributeNameXMLChar
    (cXMLChar& xmlChar) 
    {
        TLENGTH count = m_xmlParserEvents.OnAttributeNameXMLChar(xmlChar);
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
    TLENGTH OnAttributeValueXMLChar
    (cXMLChar& xmlChar) 
    {
        TLENGTH count = m_xmlParserEvents.OnAttributeValueXMLChar(xmlChar);
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
    TLENGTH OnAttributeValueStringXMLChar
    (cXMLChar& xmlChar) 
    {
        TLENGTH count = m_xmlParserEvents.OnAttributeValueStringXMLChar(xmlChar);
        return count;
    }
    /**
     **********************************************************************
     * Function: OnTextXMLChar
     *
     *   Author: $author$
     *     Date: 11/7/2008
     **********************************************************************
     */
    TLENGTH OnTextXMLChar
    (cXMLChar& xmlChar) 
    {
        TLENGTH count = m_xmlParserEvents.OnTextXMLChar(xmlChar);
        return count;
    }
    /**
     **********************************************************************
     * Function: OnTextStringXMLChar
     *
     *   Author: $author$
     *     Date: 11/7/2008
     **********************************************************************
     */
    TLENGTH OnTextStringXMLChar
    (cXMLChar& xmlChar) 
    {
        TLENGTH count = m_xmlParserEvents.OnTextStringXMLChar(xmlChar);
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
    TLENGTH OnTextEntityXMLChar
    (cXMLChar& xmlChar)
    {
        TLENGTH count = m_xmlParserEvents.OnTextEntityXMLChar(xmlChar);
        return count;
    }

    /**
     **********************************************************************
     * Function: OnBeginXMLProcessor
     *
     *   Author: $author$
     *     Date: 11/8/2008
     **********************************************************************
     */
    eError OnBeginXMLProcessor() 
    {
        eError error = m_xmlParserEvents.OnBeginXMLProcessor();
        return error;
    }
    /**
     **********************************************************************
     * Function: OnEndXMLProcessor
     *
     *   Author: $author$
     *     Date: 11/8/2008
     **********************************************************************
     */
    const cXMLChar* OnEndXMLProcessor
    (TLENGTH& length) 
    {
        const cXMLChar* xmlChars = m_xmlParserEvents.OnEndXMLProcessor(length);
        if (!xmlChars) 
            xmlChars = &m_null;
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
    eError OnBeginXMLProcessorString() 
    {
        eError error = m_xmlParserEvents.OnBeginXMLProcessorString();
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
    const cXMLChar* OnEndXMLProcessorString
    (TLENGTH& length) 
    {
        const cXMLChar* xmlChars = m_xmlParserEvents.OnEndXMLProcessorString(length);
        if (!xmlChars) 
            xmlChars = &m_null;
        return xmlChars;
    }

    /**
     **********************************************************************
     * Function: OnBeginXMLComment
     *
     *   Author: $author$
     *     Date: 11/8/2008
     **********************************************************************
     */
    eError OnBeginXMLComment() 
    {
        eError error = m_xmlParserEvents.OnBeginXMLComment();
        return error;
    }
    /**
     **********************************************************************
     * Function: OnEndXMLComment
     *
     *   Author: $author$
     *     Date: 11/8/2008
     **********************************************************************
     */
    const cXMLChar* OnEndXMLComment
    (TLENGTH& length) 
    {
        const cXMLChar* xmlChars = m_xmlParserEvents.OnEndXMLComment(length);
        if (!xmlChars) 
            xmlChars = &m_null;
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
    eError OnBeginXMLCommentString() 
    {
        eError error = m_xmlParserEvents.OnBeginXMLCommentString();
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
    const cXMLChar* OnEndXMLCommentString
    (TLENGTH& length) 
    {
        const cXMLChar* xmlChars = m_xmlParserEvents.OnEndXMLCommentString(length);
        if (!xmlChars) 
            xmlChars = &m_null;
        return xmlChars;
    }

    /**
     **********************************************************************
     * Function: OnBeginXMLDeclaration
     *
     *   Author: $author$
     *     Date: 11/8/2008
     **********************************************************************
     */
    eError OnBeginXMLDeclaration() 
    {
        eError error = m_xmlParserEvents.OnBeginXMLDeclaration();
        return error;
    }
    /**
     **********************************************************************
     * Function: OnEndXMLDeclaration
     *
     *   Author: $author$
     *     Date: 11/8/2008
     **********************************************************************
     */
    const cXMLChar* OnEndXMLDeclaration
    (TLENGTH& length) 
    {
        const cXMLChar* xmlChars = m_xmlParserEvents.OnEndXMLDeclaration(length);
        if (!xmlChars) 
            xmlChars = &m_null;
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
    eError OnBeginXMLDeclarationString() 
    {
        eError error = m_xmlParserEvents.OnBeginXMLDeclarationString();
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
    const cXMLChar* OnEndXMLDeclarationString
    (TLENGTH& length) 
    {
        const cXMLChar* xmlChars = m_xmlParserEvents.OnEndXMLDeclarationString(length);
        if (!xmlChars) 
            xmlChars = &m_null;
        return xmlChars;
    }

    /**
     **********************************************************************
     * Function: OnBeginXMLSection
     *
     *   Author: $author$
     *     Date: 11/8/2008
     **********************************************************************
     */
    eError OnBeginXMLSection() 
    {
        eError error = m_xmlParserEvents.OnBeginXMLSection();
        return error;
    }
    /**
     **********************************************************************
     * Function: OnEndXMLSection
     *
     *   Author: $author$
     *     Date: 11/8/2008
     **********************************************************************
     */
    const cXMLChar* OnEndXMLSection
    (TLENGTH& length) 
    {
        const cXMLChar* xmlChars = m_xmlParserEvents.OnEndXMLSection(length);
        if (!xmlChars) 
            xmlChars = &m_null;
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
    eError OnBeginXMLSectionString() 
    {
        eError error = m_xmlParserEvents.OnBeginXMLSectionString();
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
    const cXMLChar* OnEndXMLSectionString
    (TLENGTH& length) 
    {
        const cXMLChar* xmlChars = m_xmlParserEvents.OnEndXMLSectionString(length);
        if (!xmlChars) 
            xmlChars = &m_null;
        return xmlChars;
    }

    /**
     **********************************************************************
     * Function: OnBeginXMLTag
     *
     *   Author: $author$
     *     Date: 11/8/2008
     **********************************************************************
     */
    eError OnBeginXMLTag() 
    {
        eError error = m_xmlParserEvents.OnBeginXMLTag();
        return error;
    }
    /**
     **********************************************************************
     * Function: OnEndXMLTag
     *
     *   Author: $author$
     *     Date: 11/8/2008
     **********************************************************************
     */
    const cXMLChar* OnEndXMLTag
    (TLENGTH& length) 
    {
        const cXMLChar* xmlChars = m_xmlParserEvents.OnEndXMLTag(length);
        if (!xmlChars) 
            xmlChars = &m_null;
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
    const cXMLChar* OnEndXMLBeginTag
    (TLENGTH& length) 
    {
        const cXMLChar* xmlChars = m_xmlParserEvents.OnEndXMLBeginTag(length);
        if (!xmlChars) 
            xmlChars = &m_null;
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
    eError OnBeginXMLEndTag() 
    {
        eError error = m_xmlParserEvents.OnBeginXMLEndTag();
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
    const cXMLChar* OnEndXMLEndTag
    (TLENGTH& length) 
    {
        const cXMLChar* xmlChars = m_xmlParserEvents.OnEndXMLEndTag(length);
        if (!xmlChars) 
            xmlChars = &m_null;
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
    eError OnBeginXMLTagName() 
    {
        eError error = m_xmlParserEvents.OnBeginXMLTagName();
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
    const cXMLChar* OnEndXMLTagName
    (TLENGTH& length) 
    {
        const cXMLChar* xmlChars = m_xmlParserEvents.OnEndXMLTagName(length);
        if (!xmlChars) 
            xmlChars = &m_null;
        return xmlChars;
    }
    /**
     **********************************************************************
     * Function: OnEndXMLTagPrefix
     *
     *   Author: $author$
     *     Date: 11/10/2008
     **********************************************************************
     */
    const cXMLChar* OnEndXMLTagPrefix
    (TLENGTH& length) 
    {
        const cXMLChar* xmlChars = m_xmlParserEvents.OnEndXMLTagPrefix(length);
        if (!xmlChars) 
            xmlChars = &m_null;
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
    eError OnBeginXMLTagString() 
    {
        eError error = m_xmlParserEvents.OnBeginXMLTagString();
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
    const cXMLChar* OnEndXMLTagString
    (TLENGTH& length) 
    {
        const cXMLChar* xmlChars = m_xmlParserEvents.OnEndXMLTagString(length);
        if (!xmlChars) 
            xmlChars = &m_null;
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
    eError OnBeginXMLAttributeName() 
    {
        eError error = m_xmlParserEvents.OnBeginXMLAttributeName();
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
    const cXMLChar* OnEndXMLAttributeName
    (TLENGTH& length) 
    {
        const cXMLChar* xmlChars = m_xmlParserEvents.OnEndXMLAttributeName(length);
        if (!xmlChars) 
            xmlChars = &m_null;
        return xmlChars;
    }
    /**
     **********************************************************************
     * Function: OnEndXMLAttributePrefix
     *
     *   Author: $author$
     *     Date: 11/10/2008
     **********************************************************************
     */
    const cXMLChar* OnEndXMLAttributePrefix
    (TLENGTH& length) 
    {
        const cXMLChar* xmlChars = m_xmlParserEvents.OnEndXMLAttributePrefix(length);
        if (!xmlChars) 
            xmlChars = &m_null;
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
    eError OnBeginXMLAttributeValueName() 
    {
        eError error = m_xmlParserEvents.OnBeginXMLAttributeValueName();
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
    const cXMLChar* OnEndXMLAttributeValueName
    (TLENGTH& length) 
    {
        const cXMLChar* xmlChars = m_xmlParserEvents.OnEndXMLAttributeValueName(length);
        if (!xmlChars) 
            xmlChars = &m_null;
        return xmlChars;
    }
    /**
     **********************************************************************
     * Function: OnEndXMLAttributeValuePrefix
     *
     *   Author: $author$
     *     Date: 11/10/2008
     **********************************************************************
     */
    const cXMLChar* OnEndXMLAttributeValuePrefix
    (TLENGTH& length) 
    {
        const cXMLChar* xmlChars = m_xmlParserEvents.OnEndXMLAttributeValuePrefix(length);
        if (!xmlChars) 
            xmlChars = &m_null;
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
    eError OnBeginXMLAttributeValueString() 
    {
        eError error = m_xmlParserEvents.OnBeginXMLAttributeValueString();
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
    const cXMLChar* OnEndXMLAttributeValueString
    (TLENGTH& length) 
    {
        const cXMLChar* xmlChars = m_xmlParserEvents.OnEndXMLAttributeValueString(length);
        if (!xmlChars) 
            xmlChars = &m_null;
        return xmlChars;
    }
    /**
     **********************************************************************
     * Function: OnEndXMLAttributeValueStringPrefix
     *
     *   Author: $author$
     *     Date: 11/10/2008
     **********************************************************************
     */
    const cXMLChar* OnEndXMLAttributeValueStringPrefix
    (TLENGTH& length) 
    {
        const cXMLChar* xmlChars = m_xmlParserEvents.OnEndXMLAttributeValueStringPrefix(length);
        if (!xmlChars) 
            xmlChars = &m_null;
        return xmlChars;
    }

    /**
     **********************************************************************
     * Function: OnBeginXMLText
     *
     *   Author: $author$
     *     Date: 11/8/2008
     **********************************************************************
     */
    eError OnBeginXMLText() 
    {
        eError error = m_xmlParserEvents.OnBeginXMLText();
        return error;
    }
    /**
     **********************************************************************
     * Function: OnEndXMLText
     *
     *   Author: $author$
     *     Date: 11/8/2008
     **********************************************************************
     */
    const cXMLChar* OnEndXMLText
    (TLENGTH& length) 
    {
        const cXMLChar* xmlChars = m_xmlParserEvents.OnEndXMLText(length);
        if (!xmlChars) 
            xmlChars = &m_null;
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
    eError OnBeginXMLTextString() 
    {
        eError error = m_xmlParserEvents.OnBeginXMLTextString();
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
    const cXMLChar* OnEndXMLTextString
    (TLENGTH& length) 
    {
        const cXMLChar* xmlChars = m_xmlParserEvents.OnEndXMLTextString(length);
        if (!xmlChars) 
            xmlChars = &m_null;
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
    eError OnBeginXMLTextEntity() 
    {
        eError error = m_xmlParserEvents.OnBeginXMLTextEntity();
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
    const cXMLChar* OnEndXMLTextEntity
    (TLENGTH& length) 
    {
        const cXMLChar* xmlChars = m_xmlParserEvents.OnEndXMLTextEntity(length);
        if (!xmlChars) 
            xmlChars = &m_null;
        return xmlChars;
    }

    /**
     **********************************************************************
     * Function: IsTagNameXMLChar
     *
     *   Author: $author$
     *     Date: 11/19/2008
     **********************************************************************
     */
    virtual bool IsTagNameXMLChar
    (cXMLChar& xmlChar) 
    {
        CHAR c=xmlChar.GetCHAR();
        switch(c)
        {
        case '<':
        case '>':
        case '/':
        case '!':
        case '?':
        case '\'':
        case '\"':
        case ' ':
        case '\n':
        case '\r':
        case '\t':
        case '\v':
           return false;
        }
        return true;
    }
};
#endif /* _CXMLCHARTOXMLPARSEREVENTSWRITER_HXX */
