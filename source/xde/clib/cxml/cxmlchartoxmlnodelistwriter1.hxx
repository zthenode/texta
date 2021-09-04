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
#include "cxmlelementnodeinterface.hxx"
#include "cxmlprocessornodeinterface.hxx"
#include "cxmlcommentnodeinterface.hxx"
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
 class TXMLProcessorNodeInterface=cXMLProcessorNodeInterface,
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

    TXMLNodeListInterface& m_nodeList;
    TXMLDocumentNodeInterface& m_documentNode;

    TXMLCharToXMLParserEventsWriter m_xmlCharWriter;

    cXMLString m_textNodeText;
    cXMLString m_processorNodeText;
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
            if (0 < m_string.AssignXMLCh(xmlChars, length))
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
        if (0 > (length = m_processorNodeText.Clear()))
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
        cXMLProcessorNodeInterface* processorNodeInterface;
        if ((xmlChars = m_processorNodeText.Chars(length)))
        {
            if (0 < m_string.AssignXMLCh(xmlChars, length))
            if ((m_chars = m_string.Chars(m_length)))
            CDBT("() \"%s\"\n", m_chars);

            if ((processorNodeInterface = cXMLProcessorNodeInterface::
                CreateInstance(m_documentNode, xmlChars, length)))
            {
                if ((nodeInterface = m_nodeList.
                    AppendItem(*processorNodeInterface)))
                return xmlChars;

                processorNodeInterface->DeleteInstance();
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
        (length, e_XML_NODE_TYPE_ELEMENT);
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
        (length, e_XML_NODE_TYPE_BEGIN_ELEMENT);
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
        (length, e_XML_NODE_TYPE_END_ELEMENT);
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
    (TLENGTH& length, eXMLNodeType = e_XML_NODE_TYPE_ELEMENT) 
    {
        const cXMLChar* xmlChars;
        TXMLNodeInterface* firstAttribute;
        TXMLNodeInterface* lastAttribute;
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
        TLENGTH nameSuffixLength = 0;
        const cXMLChar* namePrefixXMLChars = m_attributeNodeNamePrefix.HasChars(namePrefixLength);
        const cXMLChar* nameSuffixXMLChars = m_attributeNodeNameSuffix.HasChars(nameSuffixLength);
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
     * Function: OnEndXMLTag
     *
     *   Author: $author$
     *     Date: 11/14/2008
     **********************************************************************
     */
    virtual const cXMLChar* OnEndXMLTag
    (TLENGTH& length) 
    {
        const cXMLChar* xmlChars = 0;
        TLENGTH prefixLength = 0;
        TLENGTH suffixLength = 0;
        const cXMLChar* prefixXMLChars = m_elementNodeNamePrefix.HasChars(length);
        const cXMLChar* suffixXMLChars = m_elementNodeNameSuffix.HasChars(length);
        cXMLNodeInterface* nodeInterface;
        cXMLElementNodeInterface* elementNodeInterface;

        if ((xmlChars = m_elementNodeName.Chars(length)))
        {
            if (0 < m_string.AssignXMLCh(xmlChars, length))
            if ((m_chars = m_string.Chars(m_length)))
            CDBT("() \"%s\"\n", m_chars);

            if ((elementNodeInterface = cXMLElementNodeInterface::
                CreateInstance
                (m_documentNode, xmlChars, length,
                 prefixXMLChars, prefixLength,
                 suffixXMLChars, suffixLength)))
            {
                if ((nodeInterface = m_nodeList.
                    AppendItem(*elementNodeInterface)))
                return xmlChars;

                elementNodeInterface->DeleteInstance();
            }
            xmlChars = 0;
            length = 0;
        }
        return xmlChars;
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
     * Function: OnProcessorXMLChar
     *
     *   Author: $author$
     *     Date: 11/18/2008
     **********************************************************************
     */
    virtual TLENGTH OnProcessorXMLChar
    (cXMLChar& xmlChar) 
    {
        TLENGTH count = m_processorNodeText.Append(&xmlChar,1);
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
