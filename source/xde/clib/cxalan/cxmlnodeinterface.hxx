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
 *   File: cxmlnodeinterface.hxx
 *
 * Author: $author$
 *   Date: 3/15/2008
 **********************************************************************
 */
#ifndef _CXMLNODEINTERFACE_HXX
#define _CXMLNODEINTERFACE_HXX

#include "cinterfacebase.hxx"
#include "cxmlnodetype.hxx"
#include "creference.hxx"

class cXMLNodeReference;

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
    virtual int SetNodeType
    (eXMLNodeType nodeType) = 0;
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
 *  Class: cXMLNodeReference
 *
 * Author: $author$
 *   Date: 3/15/2008
 **********************************************************************
 */
class cXMLNodeReference
: public cReferenceT<cXMLNodeInterface,cReferenced>
{
public:
    typedef cReferenceT<cXMLNodeInterface,cReferenced> cExtends;
};
#endif /* _CXMLNODEINTERFACE_HXX */
