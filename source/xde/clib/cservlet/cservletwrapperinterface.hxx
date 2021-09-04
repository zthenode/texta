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
 *   File: cservletwrapperinterface.hxx
 *
 * Author: $author$
 *   Date: 2/24/2008
 **********************************************************************
 */
#ifndef _CSERVLETWRAPPERINTERFACE_HXX
#define _CSERVLETWRAPPERINTERFACE_HXX

#include "cservletcontainerinterface.hxx"
#include "cservletinterface.hxx"

#undef CDB_CLASS
#define CDB_CLASS "cServletWrapperInterfaceT"
/**
 **********************************************************************
 *  Class: cServletWrapperInterfaceT
 *
 * Author: $author$
 *   Date: 2/24/2008
 **********************************************************************
 */
template
<class TServletInterface=cServletInterface,
 class TImplements=cServletContainerInterface>
 
class c_INTERFACE_CLASS cServletWrapperInterfaceT
: virtual public TImplements
{
public:
    typedef TImplements cImplements;
    typedef cServletWrapperInterfaceT cDerives;
    /**
     **********************************************************************
     * Function: Allocate
     *
     *   Author: $author$
     *     Date: 2/24/2008
     **********************************************************************
     */
    virtual TServletInterface* Allocate
    (eError& error) = 0;
    /**
     **********************************************************************
     * Function: Deallocate
     *
     *   Author: $author$
     *     Date: 2/24/2008
     **********************************************************************
     */
    virtual eError Deallocate
    (TServletInterface& servlet) = 0;
};
#undef CDB_CLASS

/**
 **********************************************************************
 *  Class: cServletWrapperInterface
 *
 * Author: $author$
 *   Date: 2/29/2008
 **********************************************************************
 */
class c_INTERFACE_CLASS cServletWrapperInterface
: virtual public cServletWrapperInterfaceT
  <cServletInterface,cServletContainerInterface>
{
public:
    typedef cServletWrapperInterfaceT
    <cServletInterface,cServletContainerInterface> cImplements;
};
#endif /* _CSERVLETWRAPPERINTERFACE_HXX */
