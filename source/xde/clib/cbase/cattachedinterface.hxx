/**
 **********************************************************************
 * Copyright (c) 1988-2007 $organization$
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
 *   File: cattachedinterface.hxx
 *
 * Author: $author$
 *   Date: 3/26/2007
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CATTACHEDINTERFACE_HXX
#define _CATTACHEDINTERFACE_HXX

#include "cattachinterface.hxx"

/**
 **********************************************************************
 *  Class: cAttachedInterfaceT
 *
 * Author: $author$
 *   Date: 3/26/2007
 **********************************************************************
 */
template
<class TAttached=HANDLE,
 class TAttachImplements=cAttachInterface,
 class TDetachImplements=cDetachInterface>

class c_INTERFACE_CLASS cAttachedInterfaceT
: virtual public TAttachImplements,
  virtual public TDetachImplements
{
public:
};

/**
 **********************************************************************
 * Typedef: cAttachedInterface
 *
 *  Author: $author$
 *    Date: 1/3/2008
 **********************************************************************
 */
typedef cAttachedInterfaceT
<HANDLE, cAttachInterface, cDetachInterface>
cAttachedInterface;

#endif /* _CATTACHEDINTERFACE_HXX */
