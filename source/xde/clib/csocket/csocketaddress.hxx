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
 *   File: csocketaddress.hxx
 *
 * Author: $author$
 *   Date: 1/15/2008
 **********************************************************************
 */
#ifndef _CSOCKETADDRESS_HXX
#define _CSOCKETADDRESS_HXX

#include "csocketaddressinterface.hxx"
#include "cbase.hxx"

/**
 **********************************************************************
 *  Class: cSocketAddressT
 *
 * Author: $author$
 *   Date: 1/15/2008
 **********************************************************************
 */
template
<class TImplements=cSocketAddressImplement,
 class TExtends=cBase>
 
class cSocketAddressT
: virtual public TImplements,
  public TExtends
{
public:
    typedef TImplements cImplements;
    typedef TExtends cExtends;
    typedef cSocketAddressT cDerives;

    /**
     **********************************************************************
     * Constructor: cSocketAddressT
     *
     *      Author: $author$
     *        Date: 1/15/2008
     **********************************************************************
     */
    cSocketAddressT() 
    {
    }
    /**
     **********************************************************************
     * Destructor: cSocketAddressT
     *
     *     Author: $author$
     *       Date: 1/15/2008
     **********************************************************************
     */
    virtual ~cSocketAddressT()
    {
    }
};

/**
 **********************************************************************
 *  Typedef: cSocketAddress
 *
 *  Author: $author$
 *    Date: 1/15/2008
 **********************************************************************
 */
typedef cSocketAddressT
<cSocketAddressImplement, cBase>
cSocketAddress;

#endif /* _CSOCKETADDRESS_HXX */
