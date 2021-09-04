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
 *   File: cservletserviceinterface.hxx
 *
 * Author: $author$
 *   Date: 2/24/2008
 **********************************************************************
 */
#ifndef _CSERVLETSERVICEINTERFACE_HXX
#define _CSERVLETSERVICEINTERFACE_HXX

#include "cservletconnectorinterface.hxx"
#include "cservletinterfacebase.hxx"

#undef CDB_CLASS
#define CDB_CLASS "cServletServiceInterfaceT"
/**
 **********************************************************************
 *  Class: cServletServiceInterfaceT
 *
 * Author: $author$
 *   Date: 2/24/2008
 **********************************************************************
 */
template
<class TServletConnectorInterface=cServletConnectorInterface,
 class TImplements=cServletInterfaceBase>
 
class c_INTERFACE_CLASS cServletServiceInterfaceT
: virtual public TImplements
{
public:
    typedef TImplements cImplements;
    typedef cServletServiceInterfaceT cDerives;
    /**
     **********************************************************************
     * Function: AddConnector
     *
     *   Author: $author$
     *     Date: 2/24/2008
     **********************************************************************
     */
    virtual eError AddConnector
    (TServletConnectorInterface& connector) = 0;
    /**
     **********************************************************************
     * Function: RemoveConnector
     *
     *   Author: $author$
     *     Date: 2/24/2008
     **********************************************************************
     */
    virtual eError RemoveConnector
    (TServletConnectorInterface& connector) = 0;
};
#undef CDB_CLASS

/**
 **********************************************************************
 *  Class: cServletServiceInterface
 *
 * Author: $author$
 *   Date: 2/27/2008
 **********************************************************************
 */
class c_INTERFACE_CLASS cServletServiceInterface
: virtual public cServletServiceInterfaceT
  <cServletConnectorInterface,cServletInterfaceBase>
{
public:
    typedef cServletServiceInterfaceT
    <cServletConnectorInterface,cServletInterfaceBase> cImplements;
};
#endif /* _CSERVLETSERVICEINTERFACE_HXX */
