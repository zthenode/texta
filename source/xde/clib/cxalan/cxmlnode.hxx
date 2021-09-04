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
 *   File: cxmlnode.hxx
 *
 * Author: $author$
 *   Date: 3/15/2008
 **********************************************************************
 */
#ifndef _CXMLNODE_HXX
#define _CXMLNODE_HXX

#include "cxmlnodeinterface.hxx"
#include "cinstance.hxx"

/**
 **********************************************************************
 *  Class: cXMLNode
 *
 * Author: $author$
 *   Date: 3/15/2008
 **********************************************************************
 */
class cXMLNode
: virtual public cXMLNodeInterface,
  public cInstance
{
public:
    typedef cXMLNodeInterface cImplements;
    typedef cInstance cExtends;
    typedef cXMLNode cDerives;

    eXMLNodeType m_nodeType;

    /**
     **********************************************************************
     * Constructor: cXMLNode
     *
     *      Author: $author$
     *        Date: 3/15/2008
     **********************************************************************
     */
    cXMLNode
    (eXMLNodeType nodeType=e_XML_NODE_TYPE_NONE,
     bool isStaticInstance=true) 
    : cExtends(isStaticInstance),
      m_nodeType(nodeType)
    {
    }
    /**
     **********************************************************************
     * Destructor: cXMLNode
     *
     *     Author: $author$
     *       Date: 3/15/2008
     **********************************************************************
     */
    virtual ~cXMLNode()
    {
    }
    /**
     **********************************************************************
     * Function: SetNodeType
     *
     *   Author: $author$
     *     Date: 3/15/2008
     **********************************************************************
     */
    virtual int SetNodeType
    (eXMLNodeType nodeType) 
    {
        int type = (m_nodeType = nodeType);
        return type;
    }
    /**
     **********************************************************************
     * Function: GetNodeType
     *
     *   Author: $author$
     *     Date: 3/15/2008
     **********************************************************************
     */
    virtual eXMLNodeType GetNodeType() const 
    {
        return m_nodeType;
    }
};
#endif /* _CXMLNODE_HXX */
