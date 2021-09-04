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
 *   File: cxmldocumentparser.hxx
 *
 * Author: $author$
 *   Date: 12/5/2008
 **********************************************************************
 */
#ifndef _CXMLDOCUMENTPARSER_HXX
#define _CXMLDOCUMENTPARSER_HXX

#include "cxmldocumentparserinterface.hxx"
#include "cxmlchartoxmlnodelistwriter.hxx"
#include "cxmldocumentnode.hxx"
#include "cxmlnodelist.hxx"

#undef CDB_CLASS
#define CDB_CLASS "cXMLDocumentParserT"
/**
 **********************************************************************
 *  Class: cXMLDocumentParserT
 *
 * Author: $author$
 *   Date: 12/5/2008
 **********************************************************************
 */
template
<class TXMLDocumentNode=cXMLDocumentNode,
 class TXMLAttributeNodeInterface=cXMLAttributeNodeInterface,
 class TXMLElementNodeInterface=cXMLElementNodeInterface,
 class TXMLBeginElementNodeInterface=cXMLBeginElementNodeInterface,
 class TXMLEndElementNodeInterface=cXMLEndElementNodeInterface,
 class TXMLNodeInterface=cXMLNodeInterface,
 class TXMLNodeListInterface=cXMLNodeListInterface,
 class TXMLNodeList=cXMLNodeList,
 class TXMLCharToXMLNodeListWriter=cXMLCharToXMLNodeListWriter,
 class TInterfaceInstance=cInterfaceInstance,
 class TXMLDocumentParserImplement=cXMLDocumentParserImplement,
 class TImplements=TXMLDocumentParserImplement,
 class TExtends=TInterfaceInstance>
 
class cXMLDocumentParserT
: virtual public TImplements,
  public TExtends
{
public:
    typedef TImplements cImplements;
    typedef TExtends cExtends;
    typedef cXMLDocumentParserT cDerives;

    TXMLNodeList m_xmlNodeList;
    TXMLDocumentNode m_xmlDocumentNode;
    TXMLCharToXMLNodeListWriter m_xmlCharToXMLNodeListWriter;
    TXMLNodeInterface* m_xmlParentNode;

    cXMLCharToString m_xmlCharToString;

    /**
     **********************************************************************
     * Constructor: cXMLDocumentParserT
     *
     *      Author: $author$
     *        Date: 12/5/2008
     **********************************************************************
     */
    cXMLDocumentParserT() 
    : m_xmlCharToXMLNodeListWriter
      (m_xmlNodeList, m_xmlDocumentNode),
      m_xmlParentNode(&m_xmlDocumentNode)
    {
    }

    /**
     **********************************************************************
     * Function: ParseNodes
     *
     *   Author: $author$
     *     Date: 12/7/2008
     **********************************************************************
     */
    virtual const TXMLNodeListInterface* ParseNodes
    (eError& error,
     const TXMLNodeListInterface& xmlNodeList) 
    {
        const TXMLNodeListInterface* parsedXmlNodeList = 0;
        const TXMLNodeInterface* xmlParentNode;
        const TXMLNodeInterface* xmlAttributeNode;
        TXMLNodeInterface* first_xmlAttributeNode;
        TXMLNodeInterface* last_xmlAttributeNode;
        TXMLBeginElementNodeInterface* xmlBeginElementNode;
        TXMLEndElementNodeInterface* xmlEndElementNode;
        TXMLElementNodeInterface* xmlElementNode;
        TXMLNodeInterface* xmlNode;
        const cXMLString* xmlBeginElementNodeName;
        const cXMLChar* xmlBeginNodeNameChars;
        const cXMLChar* xmlNodeNameChars;
        TLENGTH xmlBeginNodeNameLength;
        TLENGTH xmlNodeNameLength;
        const char* chars;
        TLENGTH length;
        int unequal;

        error = e_ERROR_NOT_IMPLEMENTED;

        if (&xmlNodeList != (const TXMLNodeListInterface*)(&m_xmlNodeList))
            return parsedXmlNodeList;

        while((xmlNode = m_xmlNodeList.PopItem()))
        {
            if ((xmlBeginElementNode = xmlNode->BeginElementNodeInterface()))
            {
                if ((xmlNodeNameChars = xmlNode->NodeNameChars(xmlNodeNameLength)))
                if ((xmlElementNode = TXMLElementNodeInterface::CreateInstance
                    (m_xmlDocumentNode, xmlNodeNameChars, xmlNodeNameLength)))
                {
                    if (0 < (length = m_xmlCharToString.
                        AssignXMLCh(xmlNodeNameChars, xmlNodeNameLength)))
                    if ((chars = m_xmlCharToString.Chars(length)))
                    CDBT("() <%s>...\n", chars);

                    if ((xmlAttributeNode = xmlBeginElementNode->FirstAttribute()))
                    if ((first_xmlAttributeNode = xmlAttributeNode->NodeInterface()))
                    if ((xmlAttributeNode = xmlBeginElementNode->LastAttribute()))
                    if ((last_xmlAttributeNode = xmlAttributeNode->NodeInterface()))
                    {
                        xmlBeginElementNode->RemoveAttributes
                        (*first_xmlAttributeNode, *last_xmlAttributeNode);

                        xmlElementNode->AppendAttributes
                        (*first_xmlAttributeNode, *last_xmlAttributeNode);
                    }
                    AppendChild(*xmlElementNode);
                    m_xmlParentNode = xmlElementNode;
                }
                xmlBeginElementNode->FreeInstance();
            }
            else
            if ((xmlEndElementNode = xmlNode->EndElementNodeInterface()))
            {
                if ((xmlNodeNameChars = xmlNode->NodeNameChars(xmlNodeNameLength)))
                if ((xmlParentNode = m_xmlParentNode))
                {
                    if (0 < (length = m_xmlCharToString.
                        AssignXMLCh(xmlNodeNameChars, xmlNodeNameLength)))
                    if ((chars = m_xmlCharToString.Chars(length)))
                    CDBT("() ...</%s>\n", chars);

                    do
                    {
                        if ((xmlBeginElementNodeName = xmlParentNode->NodeName()))
                        if ((xmlParentNode = xmlParentNode->ParentNode()))
                        if ((xmlNode = xmlParentNode->NodeInterface()))
                        {
                            m_xmlParentNode = xmlNode;
                            if ((unequal = xmlBeginElementNodeName->Compare
                                (xmlNodeNameChars, xmlNodeNameLength)))
                            {
                                if ((xmlBeginNodeNameChars = xmlBeginElementNodeName->
                                    Chars(xmlBeginNodeNameLength)))
                                if (0 < (length = m_xmlCharToString.
                                    AssignXMLCh(xmlBeginNodeNameChars, xmlBeginNodeNameLength)))
                                if ((chars = m_xmlCharToString.Chars(length)))
                                CDBT("() ...unmatched <%s>...\n", chars);

                                continue;
                            }
                        }
                        break;
                    }
                    while(xmlParentNode);
                }
                xmlEndElementNode->FreeInstance();
            }
            else 
            AppendChild(*xmlNode);
        }

        parsedXmlNodeList = m_xmlDocumentNode.ChildNodes();
        return parsedXmlNodeList;
    }
    /**
     **********************************************************************
     * Function: AppendChild
     *
     *   Author: $author$
     *     Date: 12/10/2008
     **********************************************************************
     */
    virtual TXMLNodeInterface* AppendChild
    (TXMLNodeInterface& xmlNode) 
    {
        TXMLNodeInterface& parentXmlNode 
        = (m_xmlParentNode)?(*m_xmlParentNode)
        :((TXMLNodeInterface&)m_xmlDocumentNode);

        TXMLNodeInterface* childXmlNode = 0;

        if ((childXmlNode = parentXmlNode.AppendChild(xmlNode)))
            xmlNode.SetParentNode(&parentXmlNode);
        return childXmlNode;
    }
    /**
     **********************************************************************
     * Function: Scan
     *
     *   Author: $author$
     *     Date: 12/5/2008
     **********************************************************************
     */
    virtual const TXMLNodeListInterface* Scan
    (eError& error,
     cCharReaderInterface& reader,
     TLENGTH length=-1) 
    {
        const TXMLNodeListInterface* xmlNodeList = 0;
        TLENGTH count;
        cXMLChar xmlCh;
        char ch;

        if ((error = m_xmlCharToXMLNodeListWriter.Initialize()))
            return xmlNodeList;

        if (0 > length)
        do
        {
            if (0 < (count = reader.Get(ch)))
            if (0 < (count = xmlCh.SetCHAR(ch)))
            if (0 < (count = m_xmlCharToXMLNodeListWriter.Put(xmlCh)))
                continue;
            break;
        }
        while (count > 0);
        else
        while (0 < (length--))
        {
            if (0 < (count = reader.Get(ch)))
            if (0 < (count = xmlCh.SetCHAR(ch)))
            if (0 < (count = m_xmlCharToXMLNodeListWriter.Put(xmlCh)))
                continue;
            break;
        }

        if ((error = m_xmlCharToXMLNodeListWriter.Finalize()))
            return xmlNodeList;

        xmlNodeList =  (const TXMLNodeListInterface*)(&m_xmlNodeList);
        return xmlNodeList;
    }
};
#undef CDB_CLASS

/**
 **********************************************************************
 *  Class: cXMLDocumentParser
 *
 * Author: $author$
 *   Date: 12/5/2008
 **********************************************************************
 */
class cXMLDocumentParser
: public cXMLDocumentParserT<>
{
public:
    typedef cXMLDocumentParserT<> cExtends;
    typedef cXMLDocumentParser cDerives;
};

#endif /* _CXMLDOCUMENTPARSER_HXX */
