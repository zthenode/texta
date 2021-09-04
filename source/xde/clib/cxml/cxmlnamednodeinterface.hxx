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
 *   File: cxmlnamednodeinterface.hxx
 *
 * Author: $author$
 *   Date: 11/21/2008
 **********************************************************************
 */
#ifndef _CXMLNAMEDNODEINTERFACE_HXX
#define _CXMLNAMEDNODEINTERFACE_HXX

#include "cxmlnodeinterface.hxx"

#undef CDB_CLASS
#define CDB_CLASS "cXMLNamedNodeInterfaceT"
/**
 **********************************************************************
 *  Class: cXMLNamedNodeInterfaceT
 *
 * Author: $author$
 *   Date: 11/21/2008
 **********************************************************************
 */
template
<class TXMLNamedNodeInterface=cXMLNamedNodeInterface,
 class TXMLNodeInterface=cXMLNodeInterface,
 class TImplements=TXMLNodeInterface>
 
class c_INTERFACE_CLASS cXMLNamedNodeInterfaceT
: virtual public TImplements
{
public:
    typedef TImplements cImplements;
    typedef cXMLNamedNodeInterfaceT cDerives;
};
#undef CDB_CLASS

/**
 **********************************************************************
 *  Class: cXMLNamedNodeInterface
 *
 * Author: $author$
 *   Date: 11/21/2008
 **********************************************************************
 */
class c_INTERFACE_CLASS cXMLNamedNodeInterface
: virtual public cXMLNamedNodeInterfaceT<>
{
public:
    typedef cXMLNamedNodeInterfaceT<> cImplements;
    typedef cXMLNamedNodeInterface cDerives;
};

#undef CDB_CLASS
#define CDB_CLASS "cXMLNamedNodeImplementT"
/**
 **********************************************************************
 *  Class: cXMLNamedNodeImplementT
 *
 * Author: $author$
 *   Date: 11/21/2008
 **********************************************************************
 */
template
<class TXMLNamedNodeInterface=cXMLNamedNodeInterface,
 class TXMLNodeInterface=cXMLNodeInterface,
 class TXMLNodeImplement=cXMLNodeImplement,
 class TImplements=TXMLNamedNodeInterface>
 
class cXMLNamedNodeImplementT
: virtual public TXMLNodeImplement,
  virtual public TImplements
{
public:
    typedef TImplements cImplements;
    typedef cXMLNamedNodeImplementT cDerives;
};
#undef CDB_CLASS

/**
 **********************************************************************
 *  Class: cXMLNamedNodeImplement
 *
 * Author: $author$
 *   Date: 11/21/2008
 **********************************************************************
 */
class cXMLNamedNodeImplement
: virtual public cXMLNamedNodeImplementT<>
{
public:
    typedef cXMLNamedNodeImplementT<> cImplements;
    typedef cXMLNamedNodeImplement cDerives;
};

#endif /* _CXMLNAMEDNODEINTERFACE_HXX */
