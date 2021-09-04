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
 *   File: cservletinteractioninterface.hxx
 *
 * Author: $author$
 *   Date: 2/24/2008
 **********************************************************************
 */
#ifndef _CSERVLETINTERACTIONINTERFACE_HXX
#define _CSERVLETINTERACTIONINTERFACE_HXX

#include "cservletinterfacebase.hxx"
#include "cservletconnectioninterface.hxx"

#undef CDB_CLASS
#define CDB_CLASS "cServletInteractionInterfaceT"
/**
 **********************************************************************
 *  Class: cServletInteractionInterfaceT
 *
 * Author: $author$
 *   Date: 2/24/2008
 **********************************************************************
 */
template
<class TServletConnectionInterface=cServletConnectionInterface,
 class TImplements=cServletInterfaceBase>
 
class c_INTERFACE_CLASS cServletInteractionInterfaceT
: virtual public TImplements
{
public:
    typedef TImplements cImplements;
    typedef cServletInteractionInterfaceT cDerives;
    /**
     **********************************************************************
     * Function: SetConnection
     *
     *   Author: $author$
     *     Date: 2/26/2008
     **********************************************************************
     */
    virtual eError SetConnection
    (TServletConnectionInterface* connection) = 0;
    /**
     **********************************************************************
     * Function: GetConnection
     *
     *   Author: $author$
     *     Date: 2/26/2008
     **********************************************************************
     */
    virtual TServletConnectionInterface* 
    GetConnection(eError& error) const = 0;
    /**
     **********************************************************************
     * Function: Connection
     *
     *   Author: $author$
     *     Date: 2/26/2008
     **********************************************************************
     */
    virtual TServletConnectionInterface& 
    Connection() const = 0;
};
#undef CDB_CLASS

/**
 **********************************************************************
 *  Class: cServletInteractionInterface
 *
 * Author: $author$
 *   Date: 2/25/2008
 **********************************************************************
 */
class c_INTERFACE_CLASS cServletInteractionInterface
: virtual public cServletInteractionInterfaceT
  <cServletConnectionInterface,cServletInterfaceBase>
{
public:
    typedef cServletInteractionInterfaceT
    <cServletConnectionInterface,cServletInterfaceBase> cImplements;
};
#endif /* _CSERVLETINTERACTIONINTERFACE_HXX */
