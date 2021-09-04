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
 *   File: cservletinterface.hxx
 *
 * Author: $author$
 *   Date: 2/24/2008
 **********************************************************************
 */
#ifndef _CSERVLETINTERFACE_HXX
#define _CSERVLETINTERFACE_HXX

#include "cservletrequestinterface.hxx"
#include "cservletresponseinterface.hxx"
#include "cservletconfiginterface.hxx"
#include "cservletinterfacebase.hxx"

#undef CDB_CLASS
#define CDB_CLASS "cServletInterfaceT"
/**
 **********************************************************************
 *  Class: cServletInterfaceT
 *
 * Author: $author$
 *   Date: 2/24/2008
 **********************************************************************
 */
template
<class TServletRequestInterface=cServletRequestInterface,
 class TServletResponseInterface=cServletResponseInterface,
 class TServletConfigInterface=cServletConfigInterface,
 class TImplements=cServletInterfaceBase>
 
class c_INTERFACE_CLASS cServletInterfaceT
: virtual public TImplements
{
public:
    typedef TImplements cImplements;
    typedef cServletInterfaceT cDerives;
    /**
     **********************************************************************
     * Function: Initialize
     *
     *   Author: $author$
     *     Date: 2/24/2008
     **********************************************************************
     */
    virtual eError Initialize
    (TServletConfigInterface& config) = 0;
    /**
     **********************************************************************
     * Function: Finalize
     *
     *   Author: $author$
     *     Date: 2/24/2008
     **********************************************************************
     */
    virtual eError Finalize
    (TServletConfigInterface& config) = 0;
    /**
     **********************************************************************
     * Function: Service
     *
     *   Author: $author$
     *     Date: 2/24/2008
     **********************************************************************
     */
    virtual eError Service
    (TServletRequestInterface& request,
     TServletResponseInterface& response) = 0;
};
#undef CDB_CLASS

/**
 **********************************************************************
 *  Class: cServletInterface
 *
 * Author: $author$
 *   Date: 2/28/2008
 **********************************************************************
 */
class c_INTERFACE_CLASS cServletInterface
: virtual public cServletInterfaceT
  <cServletRequestInterface,
   cServletResponseInterface,
   cServletConfigInterface,
   cServletInterfaceBase>
{
public:
    typedef cServletInterfaceT
    <cServletRequestInterface,
     cServletResponseInterface,
     cServletConfigInterface,
     cServletInterfaceBase> cImplements;
}; 
#endif /* _CSERVLETINTERFACE_HXX */
