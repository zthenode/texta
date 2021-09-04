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
 *   File: cservletserverinterface.hxx
 *
 * Author: $author$
 *   Date: 2/24/2008
 **********************************************************************
 */
#ifndef _CSERVLETSERVERINTERFACE_HXX
#define _CSERVLETSERVERINTERFACE_HXX

#include "cservletserviceinterface.hxx"
#include "cservletinterfacebase.hxx"

#undef CDB_CLASS
#define CDB_CLASS "cServletServerInterfaceT"
/**
 **********************************************************************
 *  Class: cServletServerInterfaceT
 *
 * Author: $author$
 *   Date: 2/24/2008
 **********************************************************************
 */
template
<class TServletServiceInterface=cServletServiceInterface,
 class TImplements=cServletInterfaceBase>
 
class c_INTERFACE_CLASS cServletServerInterfaceT
: virtual public TImplements
{
public:
    typedef TImplements cImplements;
    typedef cServletServerInterfaceT cDerives;
    /**
     **********************************************************************
     * Function: AddService
     *
     *   Author: $author$
     *     Date: 2/24/2008
     **********************************************************************
     */
    virtual eError AddService
    (TServletServiceInterface& service) = 0;
    /**
     **********************************************************************
     * Function: RemoveService
     *
     *   Author: $author$
     *     Date: 2/24/2008
     **********************************************************************
     */
    virtual eError RemoveService
    (TServletServiceInterface& service) = 0;
};
#undef CDB_CLASS

/**
 **********************************************************************
 *  Class: cServletServerInterface
 *
 * Author: $author$
 *   Date: 2/27/2008
 **********************************************************************
 */
class c_INTERFACE_CLASS cServletServerInterface
: virtual public cServletServerInterfaceT
  <cServletServiceInterface,cServletInterfaceBase>
{
public:
    typedef cServletServerInterfaceT
    <cServletServiceInterface,cServletInterfaceBase> cImplements;
};
#endif /* _CSERVLETSERVERINTERFACE_HXX */
