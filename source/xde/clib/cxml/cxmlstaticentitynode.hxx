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
 *   File: cxmlstaticentitynode.hxx
 *
 * Author: $author$
 *   Date: 12/16/2008
 **********************************************************************
 */
#ifndef _CXMLSTATICENTITYNODE_HXX
#define _CXMLSTATICENTITYNODE_HXX

#include "cxmlentitynode.hxx"
#include "cxmltextnode.hxx"

/**
 **********************************************************************
 * Typedef: cXMLStaticEntityNodeListExtends
 *
 *  Author: $author$
 *    Date: 12/16/2008
 **********************************************************************
 */
typedef cStaticListT
<cXMLNodeItem, cImplement>
cXMLStaticEntityNodeListExtends;

/**
 **********************************************************************
 *  Class: cXMLStaticEntityNodeList
 *
 * Author: $author$
 *   Date: 12/16/2008
 **********************************************************************
 */
class cXMLStaticEntityNodeList
: public cXMLNodeListT
  <cXMLNode, cXMLNodeItem, cXMLNodeInterface, 
   cXMLNodeListImplement, cXMLStaticEntityNodeListExtends>
{
public:
    typedef cXMLNodeListT<> cExtends;
    typedef cXMLStaticEntityNodeList cDerives;
};

/**
 **********************************************************************
 *  Class: cXMLStaticEntityNode
 *
 * Author: $author$
 *   Date: 12/16/2008
 **********************************************************************
 */
class cXMLStaticEntityNode
: public cXMLEntityNode
{
public:
    typedef cXMLEntityNode cExtends;
    typedef cXMLStaticEntityNode cDerives;

    static cXMLStaticEntityNodeList m_staticNodeList;
    cXMLTextNode m_textNode;

    /**
     **********************************************************************
     * Constructor: cXMLStaticEntityNode
     *
     *      Author: $author$
     *        Date: 12/16/2008
     **********************************************************************
     */
    cXMLStaticEntityNode
    (const char* nodeNameChars,
     const char* nodeTextChars) 
    : cExtends(nodeNameChars),
      m_textNode(nodeTextChars)
    {
        m_staticNodeList.AddItem(m_nodeItem);
        AppendChild(m_textNode);
    }
    /**
     **********************************************************************
     * Function: Find
     *
     *   Author: $author$
     *     Date: 12/16/2008
     **********************************************************************
     */
    static cXMLEntityNodeInterface* Find
    (const cXMLChar* referencedNameXmlChars,
     TLENGTH referencedNameLength=-1) 
    {
        cXMLEntityNodeInterface* entityNode = 0;
        const cXMLNodeInterface* node = 0;
        const cXMLString* nodeName;
        int unequal;

        for (node = m_staticNodeList.FirstItem();
             node; node = node->NextSibling())
        {
            if ((nodeName = node->NodeName()))
            if (!(unequal = nodeName->Compare
                (referencedNameXmlChars, referencedNameLength)))
            {
                entityNode = node->EntityNodeInterface();
                break;
            }
        }
        return entityNode;
    }
};

#endif /* _CXMLSTATICENTITYNODE_HXX */

