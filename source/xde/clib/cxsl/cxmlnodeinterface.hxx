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
 *   File: cxmlnodeinterface.hxx
 *
 * Author: $author$
 *   Date: 12/10/2017
 **********************************************************************
 */
#ifndef _CXMLNODEINTERFACE_HXX
#define _CXMLNODEINTERFACE_HXX

#include "cxmlnodetype.hxx"
#include "creference.hxx"

/**
 **********************************************************************
 *  Class: cXMLNodeInterface
 *
 * Author: $author$
 *   Date: 3/15/2008
 **********************************************************************
 */
class c_INTERFACE_CLASS cXMLNodeInterface
: virtual public cInterfaceBase
{
public:
    typedef cInterfaceBase cImplements;
    typedef cXMLNodeInterface cDerives;
    /**
     **********************************************************************
     * Function: SetNodeType
     *
     *   Author: $author$
     *     Date: 3/15/2008
     **********************************************************************
     */
    virtual int SetNodeType(eXMLNodeType nodeType) = 0;
    /**
     **********************************************************************
     * Function: GetNodeType
     *
     *   Author: $author$
     *     Date: 3/15/2008
     **********************************************************************
     */
    virtual eXMLNodeType GetNodeType() const = 0;
};

/**
 **********************************************************************
 *  Class: cXMLNodeImplement
 *
 * Author: $author$
 *   Date: 12/10/2017
 **********************************************************************
 */
class cXMLNodeImplement
: virtual public cXMLNodeInterface
{
public:
    typedef cXMLNodeInterface cImplements;
   /**
    **********************************************************************
    * Function: SetNodeType
    *
    *   Author: $author$
    *     Date: 12/10/2017
    **********************************************************************
    */
   virtual int SetNodeType(eXMLNodeType nodeType)
   {
      return e_XML_NODE_TYPE_NONE;
   }
   /**
    **********************************************************************
    * Function: GetNodeType
    *
    *   Author: $author$
    *     Date: 12/10/2017
    **********************************************************************
    */
   virtual eXMLNodeType GetNodeType() const 
   {
      return e_XML_NODE_TYPE_NONE;
   }
};

/**
 **********************************************************************
 *  Class: cXMLNodeBase
 *
 * Author: $author$
 *   Date: 12/10/2017
 **********************************************************************
 */
class cXMLNodeBase
: virtual public cXMLNodeImplement,
  public cInstanceBase
{
public:
    typedef cXMLNodeImplement cImplements;
    typedef cInstanceBase cExtends;
    /**
     **********************************************************************
     * Constructor: cXMLNodeBase
     *
     *      Author: $author$
     *        Date: 12/10/2017
     **********************************************************************
     */
    cXMLNodeBase
    (eXMLNodeType nodeType = e_XML_NODE_TYPE_NONE)
    : m_nodeType(nodeType)
    {
    }
    /**
     **********************************************************************
     * Destructor: ~cXMLNodeBase
     *
     *     Author: $author$
     *       Date: 12/10/2017
     **********************************************************************
     */
    virtual ~cXMLNodeBase()
    {
    }
    /**
     **********************************************************************
     * Function: SetNodeType
     *
     *   Author: $author$
     *     Date: 12/10/2017
     **********************************************************************
     */
    virtual int SetNodeType(eXMLNodeType nodeType)
    {
       m_nodeType = nodeType;
       return m_nodeType;
    }
    /**
     **********************************************************************
     * Function: GetNodeType
     *
     *   Author: $author$
     *     Date: 12/10/2017
     **********************************************************************
     */
    virtual eXMLNodeType GetNodeType() const 
    {
       return m_nodeType;
    }
protected:
    eXMLNodeType m_nodeType;
};

typedef cReferenceT
<cXMLNodeInterface, cReferenced> cXMLNodeReferenceExtends;
/**
 **********************************************************************
 *  Class: cXMLNodeReference
 *
 * Author: $author$
 *   Date: 3/15/2008
 **********************************************************************
 */
class cXMLNodeReference
: public cXMLNodeReferenceExtends
{
public:
    typedef cXMLNodeReferenceExtends cExtends;
};

#endif /* _CXMLNODEINTERFACE_HXX */
