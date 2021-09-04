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
 *   File: copenedinterface.hxx
 *
 * Author: $author$
 *   Date: 1/4/2008
 **********************************************************************
 */
#ifndef _COPENEDINTERFACE_HXX
#define _COPENEDINTERFACE_HXX

#include "copeninterface.hxx"
#include "ccloseinterface.hxx"

/**
 **********************************************************************
 *  Class: cOpenedInterfaceT
 *
 * Author: $author$
 *   Date: 1/4/2008
 **********************************************************************
 */
template
<class TOpenImplements=cOpenInterface,
 class TCloseImplements=cCloseInterface>
 
class c_INTERFACE_CLASS cOpenedInterfaceT
: virtual public TOpenImplements,
  virtual public TCloseImplements
{
public:
};

/**
 **********************************************************************
 * Typedef: cOpenedInterface
 *
 *  Author: $author$
 *    Date: 1/4/2008
 **********************************************************************
 */
typedef cOpenedInterfaceT
<cOpenInterface,cCloseInterface>
cOpenedInterface;

/**
 **********************************************************************
 *  Class: cOpenedImplementT
 *
 * Author: $author$
 *   Date: 1/4/2008
 **********************************************************************
 */
template
<class TImplements=cOpenedInterface,
 class TOpenImplements=cOpenImplement,
 class TCloseImplements=cCloseImplement>
 
class cOpenedImplementT
: virtual public TOpenImplements,
  virtual public TCloseImplements,
  virtual public TImplements
{
public:
    typedef TImplements cImplements;
    typedef cOpenedImplementT cDerives;
};

/**
 **********************************************************************
 * Typedef: cOpenedImplement
 *
 *  Author: $author$
 *    Date: 1/4/2008
 **********************************************************************
 */
typedef cOpenedImplementT
<cOpenedInterface, 
 cOpenImplement, cCloseImplement>
cOpenedImplement;

#endif /* _COPENEDINTERFACE_HXX */
