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
 *   File: cxmlchartoxmlnodelistwriter.hxx
 *
 * Author: $author$
 *   Date: 11/11/2008
 **********************************************************************
 */
#ifndef _CXMLCHARTOXMLNODELISTWRITER_HXX
#define _CXMLCHARTOXMLNODELISTWRITER_HXX

#include "cxmlchartoxmlparsereventswriter.hxx"
#include "cxmlattributenodeinterface.hxx"
#include "cxmlendelementnodeinterface.hxx"
#include "cxmlbeginelementnodeinterface.hxx"
#include "cxmlelementnodeinterface.hxx"
#include "cxmlprocessinginstructionnodeinterface.hxx"
#include "cxmlcommentnodeinterface.hxx"
#include "cxmlentityreferencenodeinterface.hxx"
#include "cxmltextnodeinterface.hxx"
#include "cxmlparserevents.hxx"
#include "cxmlnodelist.hxx"
#include "cxmlchartostring.hxx"
#include "cdebug.hxx"

#undef CDB_CLASS
#define CDB_CLASS "cXMLCharToXMLNodeListWriterT"
/**
 **********************************************************************
 *  Class: cXMLCharToXMLNodeListWriterT
 *
 * Author: $author$
 *   Date: 11/11/2008
 **********************************************************************
 */
template
<class TXMLTextNodeInterface=cXMLTextNodeInterface,
 class TXMLProcessingInstructionNodeInterface=cXMLProcessingInstructionNodeInterface,
 class TXMLCommentNodeInterface=cXMLCommentNodeInterface,
 class TXMLElementNodeInterface=cXMLElementNodeInterface,
 class TXMLAttributeNodeInterface=cXMLAttributeNodeInterface,
 class TXMLBeginElementNodeInterface=cXMLBeginElementNodeInterface,
 class TXMLEndElementNodeInterface=cXMLEndElementNodeInterface,
 class TXMLDocumentNodeInterface=cXMLDocumentNodeInterface,
 class TXMLNodeInterface=cXMLNodeInterface,
 class TXMLNodeListInterface=cXMLNodeListInterface,
 class TXMLCharToXMLParserEventsWriter=cXMLCharToXMLParserEventsWriter,
 class TXMLParserEventsInterface=cXMLParserEventsInterface,
 class TXMLParserEventsImplements=cXMLParserEventsImplement,
 class TImplements=cXMLCharWriterImplement,
 class TExtends=cBase>
 
class cXMLCharToXMLNodeListWriterT
: virtual public TXMLParserEventsImplements,
  virtual public TImplements,
  public TExtends
{
public:
    typedef TImplements cImplements;
    typedef TExtends cExtends;
    typedef cXMLCharToXMLNodeListWriterT cDerives;

    typedef const cXMLChar* 
    (cDerives::*MOnEndXMLTag)
    (TLENGTH& length, 
     TXMLNodeInterface*& firstAttribute,
     TXMLNodeInterface*& lastAttribute,
     const cXMLChar* xmlChars,
     const cXMLChar* prefixXMLChars,
     TLENGTH prefixLength);

    TXMLNodeListInterface& m_nodeList;
    TXMLDocumentNodeInterface& m_documentNode;

    TXMLCharToXMLParserEventsWriter m_xmlCharWriter;

    cXMLString m_textNodeText;
    cXMLString m_entityReferenceNodeText;
    cXMLString m_processingInstructionNodeText;
    cXMLString m_commentNodeText;

    cXMLString m_elementNodeName;
    cXMLString m_elementNodeNamePrefix;
    cXMLString m_elementNodeNameSuffix;

    cXMLString m_attributeNodeName;
    cXMLString m_attributeNodeNamePrefix;
    cXMLString m_attributeNodeNameSuffix;

    cXMLString m_attributeNodeValue;
    cXMLString m_attributeNodeValuePrefix;
    cXMLString m_attributeNodeValueSuffix;

    cXMLCharToString m_string;
    const CHAR* m_chars;
    TLENGTH m_length;

    TXMLNodeInterface* m_firstAttribute;
    TXMLNodeInterface* m_lastAttribute;

    /**
     **********************************************************************
     * Constructor: cXMLCharToXMLNodeListWriterT
     *
     *      Author: $author$
     *        Date: 11/11/2008
     **********************************************************************
     */
    cXMLCharToXMLNodeListWriterT
    (TXMLNodeListInterface& nodeList,
     TXMLDocumentNodeInterface& documentNode)
    : m_nodeList(nodeList),
      m_documentNode(documentNode),
      m_xmlCharWriter((TXMLParserEventsInterface&)(*this)),
      m_chars(0),
      m_length(0),
      m_firstAttribute(0),
      m_lastAttribute(0)
    {
    }

    /**
     **********************************************************************
     * Function: Initialize
     *
     *   Author: $author$
     *     Date: 11/18/2008
     **********************************************************************
     */
    virtual eError Initialize() 
    {
        eError error = m_xmlCharWriter.Initialize();
        return error;
    }
    /**
     **********************************************************************
     * Function: Finalize
     *
     *   Author: $author$
     *     Date: 11/18/2008
     **********************************************************************
     */
    virtual eError Finalize() 
    {
        eError error = m_xmlCharWriter.Finalize();
        return error;
    }
    /**
     **********************************************************************
     * Function: Put
     *
     *   Author: $author$
     *     Date: 11/18/2008
     **********************************************************************
     */
    virtual TLENGTH Put
    (cXMLChar& xmlChar) 
    {
        TLENGTH length = m_xmlCharWriter.Put(xmlChar);
        return length;
    }

    /**
     **********************************************************************
     * Function: OnBeginXMLText
     *
     *   Author: $author$
     *     Date: 11/13/2008
     **********************************************************************
     */
    virtual eError OnBeginXMLText() 
    {
        eError error = e_ERROR_NONE;
        TLENGTH length;
        if (0 > (length = m_textNodeText.Clear()))
            error = -length;
        return error;
    }
    /**
     **********************************************************************
     * Function: OnEndXMLText
     *
     *   Author: $author$
     *     Date: 11/13/2008
     **********************************************************************
     */
    virtual const cXMLChar* OnEndXMLText
    (TLENGTH& length) 
    {
        const cXMLChar* xmlChars = 0;
        cXMLNodeInterface* nodeInterface;
        cXMLTextNodeInterface* textNodeInterface;
        if ((xmlChars = m_textNodeText.Chars(length)))
        {
            if (0 <= m_string.AssignXMLCh(xmlChars, length))
            if ((m_chars = m_string.Chars(m_length)))
            CDBT("() \"%s\"\n", m_chars);

            if ((textNodeInterface = cXMLTextNodeInterface::
                CreateInstance(m_documentNode, xmlChars, length)))
            {
                if ((nodeInterface = m_nodeList.
                    AppendItem(*textNodeInterface)))
                return xmlChars;

                textNodeInterface->DeleteInstance();
            }
            xmlChars = 0;
            length = 0;
        }
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
        TLENGTH length;
        OnEndXMLText(length);
        if (0 > (length = m_entityReferenceNodeText.Clear()))
            error = -length;
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
        cXMLNodeInterface* nodeInterface;
        cXMLEntityReferenceNodeInterface* entityReferenceNodeInterface;
        if (0 > (length = m_textNodeText.Clear()))
            return xmlChars;
        if ((xmlChars = m_entityReferenceNodeText.Chars(length)))
        {
            if (0 <= m_string.AssignXMLCh(xmlChars, length))
            if ((m_chars = m_string.Chars(m_length)))
            CDBT("() \"%s\"\n", m_chars);

            if ((entityReferenceNodeInterface = cXMLEntityReferenceNodeInterface::
                CreateInstance(m_documentNode, xmlChars, length)))
            {
                if ((nodeInterface = m_nodeList.
                    AppendItem(*entityReferenceNodeInterface)))
                return xmlChars;

                entityReferenceNodeInterface->DeleteInstance();
            }
            xmlChars = 0;
            length = 0;
        }
        OnBeginXMLText();
        return xmlChars;
    }

    /**
     **********************************************************************
     * Function: OnBeginXMLComment
     *
     *   Author: $author$
     *     Date: 11/14/2008
     **********************************************************************
     */
    virtual eError OnBeginXMLComment() 
    {
        eError error = e_ERROR_NONE;
        TLENGTH length;
        if (0 > (length = m_commentNodeText.Clear()))
            error = -length;
        return error;
    }
    /**
     **********************************************************************
     * Function: OnEndXMLComment
     *
     *   Author: $author$
     *     Date: 11/14/2008
     **********************************************************************
     */
    virtual const cXMLChar* OnEndXMLComment
    (TLENGTH& length) 
    {
        const cXMLChar* xmlChars = 0;
        cXMLNodeInterface* nodeInterface;
        cXMLCommentNodeInterface* commentNodeInterface;
        if ((xmlChars = m_commentNodeText.Chars(length)))
        {
            if (0 < m_string.AssignXMLCh(xmlChars, length))
            if ((m_chars = m_string.Chars(m_length)))
            CDBT("() \"%s\"\n", m_chars);

            if ((commentNodeInterface = cXMLCommentNodeInterface::
                CreateInstance(m_documentNode, xmlChars, length)))
            {
                if ((nodeInterface = m_nodeList.
                    AppendItem(*commentNodeInterface)))
                return xmlChars;

                commentNodeInterface->DeleteInstance();
            }
            xmlChars = 0;
            length = 0;
        }
        return xmlChars;
    }

    /**
     **********************************************************************
     * Function: OnBeginXMLProcessor
     *
     *   Author: $author$
     *     Date: 11/14/2008
     **********************************************************************
     */
    virtual eError OnBeginXMLProcessor() 
    {
        eError error = e_ERROR_NONE;
        TLENGTH length;
        if (0 > (length = m_processingInstructionNodeText.Clear()))
            error = -length;
        return error;
    }
    /**
     **********************************************************************
     * Function: OnEndXMLProcessor
     *
     *   Author: $author$
     *     Date: 11/14/2008
     **********************************************************************
     */
    virtual const cXMLChar* OnEndXMLProcessor
    (TLENGTH& length) 
    {
        const cXMLChar* xmlChars = 0;
        cXMLNodeInterface* nodeInterface;
        cXMLProcessingInstructionNodeInterface* processingInstructionNodeInterface;
        if ((xmlChars = m_processingInstructionNodeText.Chars(length)))
        {
            if (0 < m_string.AssignXMLCh(xmlChars, length))
            if ((m_chars = m_string.Chars(m_length)))
            CDBT("() \"%s\"\n", m_chars);

            if ((processingInstructionNodeInterface = cXMLProcessingInstructionNodeInterface::
                CreateInstance(m_documentNode, xmlChars, length)))
            {
                if ((nodeInterface = m_nodeList.
                    AppendItem(*processingInstructionNodeInterface)))
                return xmlChars;

                processingInstructionNodeInterface->DeleteInstance();
            }
            xmlChars = 0;
            length = 0;
        }
        return xmlChars;
    }

    /**
     **********************************************************************
     * Function: OnBeginXMLTag
     *
     *   Author: $author$
     *     Date: 11/30/2008
     **********************************************************************
     */
    virtual eError OnBeginXMLTag() 
    {
        eError error = OnBeginXMLAnyTag();
        return error;
    }
    /**
     **********************************************************************
     * Function: OnBeginXMLBeginTag
     *
     *   Author: $author$
     *     Date: 11/30/2008
     **********************************************************************
     */
    virtual eError OnBeginXMLBeginTag() 
    {
        eError error = OnBeginXMLAnyTag();
        return error;
    }
    /**
     **********************************************************************
     * Function: OnBeginXMLEndTag
     *
     *   Author: $author$
     *     Date: 11/30/2008
     **********************************************************************
     */
    virtual eError OnBeginXMLEndTag() 
    {
        eError error = OnBeginXMLAnyTag();
        return error;
    }
    /**
     **********************************************************************
     * Function: OnBeginXMLAnyTag
     *
     *   Author: $author$
     *     Date: 11/30/2008
     **********************************************************************
     */
    virtual eError OnBeginXMLAnyTag() 
    {
        eError error = e_ERROR_NONE;
        m_firstAttribute = 0;
        m_lastAttribute = 0;
        return error;
    }
    /**
     **********************************************************************
     * Function: OnEndXMLTag
     *
     *   Author: $author$
     *     Date: 11/30/2008
     **********************************************************************
     */
    virtual const cXMLChar* OnEndXMLTag(TLENGTH& length) 
    {
        const cXMLChar* xmlChars = OnEndXMLAnyTag
        (length, &cDerives::OnElementEndXMLTag);
        return xmlChars;
    }
    /**
     **********************************************************************
     * Function: OnEndXMLBeginTag
     *
     *   Author: $author$
     *     Date: 11/30/2008
     **********************************************************************
     */
    virtual const cXMLChar* OnEndXMLBeginTag(TLENGTH& length) 
    {
        const cXMLChar* xmlChars = OnEndXMLAnyTag
        (length, &cDerives::OnBeginElementEndXMLTag);
        return xmlChars;
    }
    /**
     **********************************************************************
     * Function: OnEndXMLEndTag
     *
     *   Author: $author$
     *     Date: 11/30/2008
     **********************************************************************
     */
    virtual const cXMLChar* OnEndXMLEndTag(TLENGTH& length) 
    {
        const cXMLChar* xmlChars = OnEndXMLAnyTag
        (length, &cDerives::OnEndElementEndXMLTag);
        return xmlChars;
    }
    /**
     **********************************************************************
     * Function: OnElementEndXMLTag
     *
     *   Author: $author$
     *     Date: 12/4/2008
     **********************************************************************
     */
    const cXMLChar* OnElementEndXMLTag
    (TLENGTH& length, 
     TXMLNodeInterface*& firstAttribute,
     TXMLNodeInterface*& lastAttribute,
     const cXMLChar* xmlChars,
     const cXMLChar* prefixXMLChars,
     TLENGTH prefixLength) 
    {
        TXMLNodeInterface* nodeInterface;
        TXMLElementNodeInterface* elementNodeInterface;

        if ((elementNodeInterface = cXMLElementNodeInterface::
            CreateInstance
            (m_documentNode, xmlChars, length,
             prefixXMLChars, prefixLength)))
        {
            if ((nodeInterface = m_nodeList.
                AppendItem(*elementNodeInterface)))
            {
                if ((firstAttribute) && (lastAttribute))
                    elementNodeInterface->AppendAttributes
                    (*firstAttribute, *lastAttribute);
                {
                    firstAttribute = 0;
                    lastAttribute = 0;
                    return xmlChars;
                }
            }

            elementNodeInterface->DeleteInstance();
        }
        xmlChars = 0;
        length = 0;
        return xmlChars;
    }
    /**
     **********************************************************************
     * Function: OnBeginElementEndXMLTag
     *
     *   Author: $author$
     *     Date: 12/4/2008
     **********************************************************************
     */
    const cXMLChar* OnBeginElementEndXMLTag
    (TLENGTH& length, 
     TXMLNodeInterface*& firstAttribute,
     TXMLNodeInterface*& lastAttribute,
     const cXMLChar* xmlChars,
     const cXMLChar* prefixXMLChars,
     TLENGTH prefixLength) 
    {
        TXMLNodeInterface* nodeInterface;
        TXMLBeginElementNodeInterface* elementNodeInterface;

        if ((elementNodeInterface = cXMLBeginElementNodeInterface::
            CreateInstance
            (m_documentNode, xmlChars, length,
             prefixXMLChars, prefixLength)))
        {
            if ((nodeInterface = m_nodeList.
                AppendItem(*elementNodeInterface)))
            {
                if ((firstAttribute) && (lastAttribute))
                    elementNodeInterface->AppendAttributes
                    (*firstAttribute, *lastAttribute);
                {
                    firstAttribute = 0;
                    lastAttribute = 0;
                    return xmlChars;
                }
            }

            elementNodeInterface->DeleteInstance();
        }
        xmlChars = 0;
        length = 0;
        return xmlChars;
    }
    /**
     **********************************************************************
     * Function: OnEndElementEndXMLTag
     *
     *   Author: $author$
     *     Date: 12/4/2008
     **********************************************************************
     */
    const cXMLChar* OnEndElementEndXMLTag
    (TLENGTH& length, 
     TXMLNodeInterface*& firstAttribute,
     TXMLNodeInterface*& lastAttribute,
     const cXMLChar* xmlChars,
     const cXMLChar* prefixXMLChars,
     TLENGTH prefixLength) 
    {
        TXMLNodeInterface* nodeInterface;
        TXMLEndElementNodeInterface* elementNodeInterface;

        if ((elementNodeInterface = cXMLEndElementNodeInterface::
            CreateInstance
            (m_documentNode, xmlChars, length,
             prefixXMLChars, prefixLength)))
        {
            if ((nodeInterface = m_nodeList.
                AppendItem(*elementNodeInterface)))
                return xmlChars;

            elementNodeInterface->DeleteInstance();
        }
        xmlChars = 0;
        length = 0;
        return xmlChars;
    }
    /**
     **********************************************************************
     * Function: OnEndXMLAnyTag
     *
     *   Author: $author$
     *     Date: 11/30/2008
     **********************************************************************
     */
    virtual const cXMLChar* OnEndXMLAnyTag
    (TLENGTH& length, MOnEndXMLTag mOnEndXMLTag) 
    {
        TLENGTH prefixLength = 0;
        const cXMLChar* prefixXMLChars = m_elementNodeNamePrefix.HasChars(length);
        const cXMLChar* xmlChars;
        const TXMLNodeInterface* sibling;
        TXMLNodeInterface* firstAttribute;
        TXMLNodeInterface* lastAttribute;
        TXMLNodeInterface* nodeInterface;

        if ((xmlChars = m_elementNodeName.Chars(length)))
        {
            if (0 < m_string.AssignXMLCh(xmlChars, length))
            if ((m_chars = m_string.Chars(m_length)))
            CDBT("() \"%s\"\n", m_chars);

            if ((firstAttribute = m_firstAttribute) 
                && (lastAttribute = m_lastAttribute))
            {
                m_firstAttribute = 0;
                m_lastAttribute = 0;

                m_nodeList.RemoveItems
                (*firstAttribute, *lastAttribute);
            }

            xmlChars = (this->*mOnEndXMLTag)
            (length, firstAttribute, lastAttribute,
             xmlChars, prefixXMLChars, prefixLength);

            for (sibling = firstAttribute; sibling;)
            {
                nodeInterface = sibling->NodeInterface();
                sibling = sibling->NextSibling();
                if (nodeInterface)
                    nodeInterface->DeleteInstance();
            }
        }
        return xmlChars;
    }

    /**
     **********************************************************************
     * Function: OnBeginXMLTagName
     *
     *   Author: $author$
     *     Date: 11/14/2008
     **********************************************************************
     */
    virtual eError OnBeginXMLTagName() 
    {
        eError error = e_ERROR_NONE;
        TLENGTH length;
        if (0 > (length = m_elementNodeName.Clear()))
            error = -length;
        if (0 > (length = m_elementNodeNamePrefix.Clear()))
            error = -length;
        if (0 > (length = m_elementNodeNameSuffix.Clear()))
            error = -length;
        return error;
    }
    /**
     **********************************************************************
     * Function: OnEndXMLTagName
     *
     *   Author: $author$
     *     Date: 11/14/2008
     **********************************************************************
     */
    virtual const cXMLChar* OnEndXMLTagName
    (TLENGTH& length) 
    {
        const cXMLChar* xmlChars;
        if ((xmlChars = m_elementNodeName.Chars(length)))
        {
            if (0 < m_string.AssignXMLCh(xmlChars, length))
            if ((m_chars = m_string.Chars(m_length)))
            CDBT("() \"%s\"\n", m_chars);

        }
        return xmlChars;
    }
    /**
     **********************************************************************
     * Function: OnEndXMLTagNamePrefix
     *
     *   Author: $author$
     *     Date: 11/14/2008
     **********************************************************************
     */
    virtual const cXMLChar* OnEndXMLTagNamePrefix
    (TLENGTH& length) 
    {
        const cXMLChar* xmlChars = m_elementNodeName.Chars(length);
        return xmlChars;
    }
    /**
     **********************************************************************
     * Function: OnEndXMLTagNameSuffix
     *
     *   Author: $author$
     *     Date: 11/14/2008
     **********************************************************************
     */
    virtual const cXMLChar* OnEndXMLTagNameSuffix
    (TLENGTH& length) 
    {
        const cXMLChar* xmlChars = m_elementNodeName.Chars(length);
        return xmlChars;
    }

    /**
     **********************************************************************
     * Function: OnBeginXMLAttributeName
     *
     *   Author: $author$
     *     Date: 11/20/2008
     **********************************************************************
     */
    virtual eError OnBeginXMLAttributeName() 
    {
        eError error = e_ERROR_NONE;
        TLENGTH length;
        if (0 > (length = m_attributeNodeName.Clear()))
            error = -length;
        if (0 > (length = m_attributeNodeNamePrefix.Clear()))
            error = -length;
        if (0 > (length = m_attributeNodeNameSuffix.Clear()))
            error = -length;
        return error;
    }
    /**
     **********************************************************************
     * Function: OnEndXMLAttributeName
     *
     *   Author: $author$
     *     Date: 11/20/2008
     **********************************************************************
     */
    virtual const cXMLChar* OnEndXMLAttributeName
    (TLENGTH& length) 
    {
        const cXMLChar* xmlChars;
        if ((xmlChars = m_attributeNodeName.Chars(length)))
        {
            if (0 < m_string.AssignXMLCh(xmlChars, length))
            if ((m_chars = m_string.Chars(m_length)))
            CDBT("() \"%s\"\n", m_chars);

        }
        return xmlChars;
    }

    /**
     **********************************************************************
     * Function: OnBeginXMLAttributeValueName
     *
     *   Author: $author$
     *     Date: 11/20/2008
     **********************************************************************
     */
    virtual eError OnBeginXMLAttributeValueName() 
    {
        eError error = e_ERROR_NONE;
        TLENGTH length;
        if (0 > (length = m_attributeNodeValue.Clear()))
            error = -length;
        if (0 > (length = m_attributeNodeValuePrefix.Clear()))
            error = -length;
        if (0 > (length = m_attributeNodeValueSuffix.Clear()))
            error = -length;
        return error;
    }
    /**
     **********************************************************************
     * Function: OnEndXMLAttributeValueName
     *
     *   Author: $author$
     *     Date: 11/20/2008
     **********************************************************************
     */
    virtual const cXMLChar* OnEndXMLAttributeValueName
    (TLENGTH& length) 
    {
        const cXMLChar* xmlChars;
        if ((xmlChars = m_attributeNodeValue.Chars(length)))
        {
            if (0 <= m_string.AssignXMLCh(xmlChars, length))
            if ((m_chars = m_string.Chars(m_length)))
            CDBT("() \"%s\"\n", m_chars);

            OnEndXMLAttributeValue(xmlChars, length);
        }
        return xmlChars;
    }

    /**
     **********************************************************************
     * Function: OnBeginXMLAttributeValueString
     *
     *   Author: $author$
     *     Date: 11/20/2008
     **********************************************************************
     */
    virtual eError OnBeginXMLAttributeValueString() 
    {
        eError error = e_ERROR_NONE;
        TLENGTH length;
        if (0 > (length = m_attributeNodeValue.Clear()))
            error = -length;
        if (0 > (length = m_attributeNodeValuePrefix.Clear()))
            error = -length;
        if (0 > (length = m_attributeNodeValueSuffix.Clear()))
            error = -length;
        return error;
    }
    /**
     **********************************************************************
     * Function: OnEndXMLAttributeValueString
     *
     *   Author: $author$
     *     Date: 11/20/2008
     **********************************************************************
     */
    virtual const cXMLChar* OnEndXMLAttributeValueString
    (TLENGTH& length) 
    {
        const cXMLChar* xmlChars;
        if ((xmlChars = m_attributeNodeValue.Chars(length)))
        {
            if (0 <= m_string.AssignXMLCh(xmlChars, length))
            if ((m_chars = m_string.Chars(m_length)))
            CDBT("() \"%s\"\n", m_chars);

            OnEndXMLAttributeValue(xmlChars, length);
        }
        return xmlChars;
    }
    /**
     **********************************************************************
     * Function: OnEndXMLAttributeValue
     *
     *   Author: $author$
     *     Date: 11/20/2008
     **********************************************************************
     */
    virtual eError OnEndXMLAttributeValue
    (const cXMLChar* valueXMLChars=0, TLENGTH valueLength=-1) 
    {
        static const CHAR eq[]="=";
        static const CHAR quot[]="\"";
        eError error = e_ERROR_FAILED;
        TLENGTH nameLength = 0;
        TLENGTH namePrefixLength = 0;
        const cXMLChar* namePrefixXMLChars = m_attributeNodeNamePrefix.HasChars(namePrefixLength);
        const cXMLChar* nameXMLChars;
        cXMLNodeInterface* nodeInterface;
        cXMLAttributeNodeInterface* attributeNodeInterface;

        if ((nameXMLChars = m_attributeNodeName.HasChars(nameLength)))
        if ((valueXMLChars = m_attributeNodeValue.Chars(valueLength)))
        {
            if (0 < m_string.AssignXMLCh(nameXMLChars, nameLength))
            if (0 < m_string.Append(eq))
            if (0 < m_string.Append(quot))
            if (0 <= m_string.AppendXMLCh(valueXMLChars, valueLength))
            if (0 < m_string.Append(quot))
            if ((m_chars = m_string.Chars(m_length)))
            CDBT("() %s\n", m_chars);

            if ((attributeNodeInterface = cXMLAttributeNodeInterface::
                CreateInstance
                (m_documentNode, nameXMLChars, nameLength,
                 namePrefixXMLChars, namePrefixLength)))
            {
                if ((nodeInterface = m_nodeList.
                    AppendItem(*attributeNodeInterface)))
                {
                    if (!m_firstAttribute)
                        m_firstAttribute = nodeInterface;
                    m_lastAttribute = nodeInterface;
                    return error = e_ERROR_NONE;
                }

                attributeNodeInterface->DeleteInstance();
            }
        }
        return error;
    }

    /**
     **********************************************************************
     * Function: OnTextXMLChar
     *
     *   Author: $author$
     *     Date: 11/18/2008
     **********************************************************************
     */
    virtual TLENGTH OnTextXMLChar
    (cXMLChar& xmlChar) 
    {
        TLENGTH count = m_textNodeText.Append(&xmlChar,1);
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
        TLENGTH count = m_entityReferenceNodeText.Append(&xmlChar,1);
        return count;
    }
    /**
     **********************************************************************
     * Function: OnProcessorXMLChar
     *
     *   Author: $author$
     *     Date: 11/18/2008
     **********************************************************************
     */
    virtual TLENGTH OnProcessorXMLChar
    (cXMLChar& xmlChar) 
    {
        TLENGTH count = m_processingInstructionNodeText.Append(&xmlChar,1);
        return count;
    }
    /**
     **********************************************************************
     * Function: OnCommentXMLChar
     *
     *   Author: $author$
     *     Date: 11/18/2008
     **********************************************************************
     */
    virtual TLENGTH OnCommentXMLChar
    (cXMLChar& xmlChar) 
    {
        TLENGTH count = m_commentNodeText.Append(&xmlChar,1);
        return count;
    }
    /**
     **********************************************************************
     * Function: OnTagNameXMLChar
     *
     *   Author: $author$
     *     Date: 11/18/2008
     **********************************************************************
     */
    virtual TLENGTH OnTagNameXMLChar
    (cXMLChar& xmlChar) 
    {
        TLENGTH count = m_elementNodeName.Append(&xmlChar,1);
        return count;
    }
    /**
     **********************************************************************
     * Function: OnAttributeNameXMLChar
     *
     *   Author: $author$
     *     Date: 11/20/2008
     **********************************************************************
     */
    virtual TLENGTH OnAttributeNameXMLChar
    (cXMLChar& xmlChar) 
    {
        TLENGTH count = m_attributeNodeName.Append(&xmlChar,1);
        return count;
    }
    /**
     **********************************************************************
     * Function: OnAttributeValueXMLChar
     *
     *   Author: $author$
     *     Date: 11/20/2008
     **********************************************************************
     */
    virtual TLENGTH OnAttributeValueXMLChar
    (cXMLChar& xmlChar) 
    {
        TLENGTH count = m_attributeNodeValue.Append(&xmlChar,1);
        return count;
    }
};
#undef CDB_CLASS

/**
 **********************************************************************
 *  Class: cXMLCharToXMLNodeListWriter
 *
 * Author: $author$
 *   Date: 11/11/2008
 **********************************************************************
 */
class cXMLCharToXMLNodeListWriter
: public cXMLCharToXMLNodeListWriterT<>
{
public:
    typedef cXMLCharToXMLNodeListWriterT<> cExtends;
    typedef cXMLCharToXMLNodeListWriter cDerives;
    /**
     **********************************************************************
     * Constructor: cXMLCharToXMLNodeListWriter
     *
     *      Author: $author$
     *        Date: 11/11/2008
     **********************************************************************
     */
    cXMLCharToXMLNodeListWriter
    (cXMLNodeListInterface& xmlNodeList,
     cXMLDocumentNodeInterface& xmlDocumentNode) 
    : cExtends(xmlNodeList,xmlDocumentNode)
    {
    }
};

#endif /* _CXMLCHARTOXMLNODELISTWRITER_HXX */
