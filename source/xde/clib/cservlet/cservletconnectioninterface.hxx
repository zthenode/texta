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
 *   File: cservletconnectioninterface.hxx
 *
 * Author: $author$
 *   Date: 2/24/2008
 **********************************************************************
 */
#ifndef _CSERVLETCONNECTIONINTERFACE_HXX
#define _CSERVLETCONNECTIONINTERFACE_HXX

#include "cservletinterfacebase.hxx"
#include "cwriterinterface.hxx"
#include "creaderinterface.hxx"

class c_INTERFACE_CLASS cServletConnectorInterface;

#undef CDB_CLASS
#define CDB_CLASS "cServletConnectionInterfaceT"
/**
 **********************************************************************
 *  Class: cServletConnectionInterfaceT
 *
 * Author: $author$
 *   Date: 2/24/2008
 **********************************************************************
 */
template
<class TReaderInterface=cReaderInterface,
 class TWriterInterface=cWriterInterface,
 class TImplements=cServletInterfaceBase>
 
class c_INTERFACE_CLASS cServletConnectionInterfaceT
: virtual public TImplements
{
public:
    typedef TImplements cImplements;
    typedef cServletConnectionInterfaceT cDerives;
    /**
     **********************************************************************
     * Function: SetKeepAlive
     *
     *   Author: $author$
     *     Date: 2/24/2008
     **********************************************************************
     */
    virtual int SetKeepAlive
    (bool on=true) = 0;
    /**
     **********************************************************************
     * Function: GetKeepAlive
     *
     *   Author: $author$
     *     Date: 2/24/2008
     **********************************************************************
     */
    virtual bool GetKeepAlive() const = 0;
};
#undef CDB_CLASS

/**
 **********************************************************************
 *  Class: cServletConnectionInterface
 *
 * Author: $author$
 *   Date: 2/25/2008
 **********************************************************************
 */
class c_INTERFACE_CLASS cServletConnectionInterface
: virtual public cServletConnectionInterfaceT
  <cReaderInterface,cWriterInterface,cServletInterfaceBase>
{
    typedef cServletConnectionInterfaceT
    <cReaderInterface,cWriterInterface,cServletInterfaceBase> cImplements;
};
#endif /* _CSERVLETCONNECTIONINTERFACE_HXX */
