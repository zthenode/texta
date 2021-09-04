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
 *   File: cfileattachedinterface.hxx
 *
 * Author: $author$
 *   Date: 3/5/2008
 **********************************************************************
 */
#ifndef _CFILEATTACHEDINTERFACE_HXX
#define _CFILEATTACHEDINTERFACE_HXX

#include "cattachedinterface.hxx"
#include "cplatform_file.h"

/**
 **********************************************************************
 *  Class: cFILEAttachInterface
 *
 * Author: $author$
 *   Date: 3/6/2008
 **********************************************************************
 */
class c_INTERFACE_CLASS cFILEAttachInterface
: virtual public cAttachInterfaceT<FILE*,cInterfaceBase>
{
public:
    typedef cAttachInterfaceT<FILE*,cInterfaceBase> cImplements;
};
/**
 **********************************************************************
 *  Class: cFILEDetachInterface
 *
 * Author: $author$
 *   Date: 3/6/2008
 **********************************************************************
 */
class c_INTERFACE_CLASS cFILEDetachInterface
: virtual public cDetachInterfaceT<FILE*,cInterfaceBase>
{
public:
    typedef cDetachInterfaceT<FILE*,cInterfaceBase> cImplements;
};
/**
 **********************************************************************
 *  Class: cFILEAttachedInterface
 *
 * Author: $author$
 *   Date: 3/5/2008
 **********************************************************************
 */
class c_INTERFACE_CLASS cFILEAttachedInterface
: virtual public cAttachedInterfaceT
   <FILE*,cFILEAttachInterface,cFILEDetachInterface>
{
public:
    typedef cAttachedInterfaceT
    <FILE*,cFILEAttachInterface,cFILEDetachInterface> cImplements;
};
#endif /* _CFILEATTACHEDINTERFACE_HXX */
