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
 *   File: csocketaddressinterface.hxx
 *
 * Author: $author$
 *   Date: 1/15/2008
 **********************************************************************
 */
#ifndef _CSOCKETADDRESSINTERFACE_HXX
#define _CSOCKETADDRESSINTERFACE_HXX

#include "cinterfacebase.hxx"

/**
 **********************************************************************
 *  Class: cSocketAddressInterfaceT
 *
 * Author: $author$
 *   Date: 1/15/2008
 **********************************************************************
 */
template
<class TImplements=cInterfaceBase>
 
class c_INTERFACE_CLASS cSocketAddressInterfaceT
: virtual public TImplements
{
public:
    typedef TImplements cImplements;
    typedef cSocketAddressInterfaceT cDerives;
};

/**
 **********************************************************************
 *  Typedef: cSocketAddressInterface
 *
 *  Author: $author$
 *    Date: 1/15/2008
 **********************************************************************
 */
typedef cSocketAddressInterfaceT
<cInterfaceBase>
cSocketAddressInterface;

/**
 **********************************************************************
 *  Class: cSocketAddressImplementT
 *
 * Author: $author$
 *   Date: 1/15/2008
 **********************************************************************
 */
template
<class TImplements=cSocketInterface>
 
class cSocketAddressImplementT
: virtual public TImplements
{
public:
    typedef TImplements cImplements;
    typedef cSocketAddressImplementT cDerives;
};

/**
 **********************************************************************
 *  Typedef: cSocketAddressImplement
 *
 *  Author: $author$
 *    Date: 1/15/2008
 **********************************************************************
 */
typedef cSocketAddressImplementT
<cSocketAddressInterface>
cSocketAddressImplement;

#endif /* _CSOCKETADDRESSINTERFACE_HXX */
