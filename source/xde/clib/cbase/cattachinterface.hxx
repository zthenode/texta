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
 *   File: cattachinterface.hxx
 *
 * Author: $author$
 *   Date: 3/13/2007
 *
 *    $Id$
 **********************************************************************
 */

#ifndef _CATTACHINTERFACE_HXX
#define _CATTACHINTERFACE_HXX

#include "cinterface.hxx"

/**
 **********************************************************************
 *  Class: cAttachInterfaceT
 *
 * Author: $author$
 *   Date: 3/13/2007
 **********************************************************************
 */
template
<class TAttached=HANDLE,
 class TImplements=cInterfaceBase>

class c_INTERFACE_CLASS cAttachInterfaceT
: virtual public TImplements
{
public:
    /**
     **********************************************************************
     * Function: Attach
     *
     *   Author: $author$
     *     Date: 3/13/2007
     **********************************************************************
     */
    virtual eError Attach
    (TAttached attached, bool onlyUnattached=false) = 0;
};

/**
 **********************************************************************
 *  Class: cDetachInterfaceT
 *
 * Author: $author$
 *   Date: 3/13/2007
 **********************************************************************
 */
template
<class TAttached=HANDLE,
 class TImplements=cInterfaceBase>

class c_INTERFACE_CLASS cDetachInterfaceT
: virtual public TImplements
{
public:
    /**
     **********************************************************************
     * Function: Detach
     *
     *   Author: $author$
     *     Date: 3/13/2007
     **********************************************************************
     */
    virtual eError Detach
    (TAttached& attached, bool onlyAttached=false) = 0;
};

/**
 **********************************************************************
 * Typedef: cAttachInterface
 *
 *  Author: $author$
 *    Date: 1/3/2008
 **********************************************************************
 */
typedef cAttachInterfaceT
<HANDLE,cInterfaceBase>
cAttachInterface;

/**
 **********************************************************************
 * Typedef: cDetachInterface
 *
 *  Author: $author$
 *    Date: 1/3/2008
 **********************************************************************
 */
typedef cDetachInterfaceT
<HANDLE,cInterfaceBase>
cDetachInterface;

/**
 **********************************************************************
 *  Class: cAttachImplementT
 *
 * Author: $author$
 *   Date: 3/13/2007
 **********************************************************************
 */
template
<class TAttached=HANDLE,
 class TImplements=cAttachInterface>

class cAttachImplementT
: virtual public TImplements
{
public:
    /**
     **********************************************************************
     * Function: Attach
     *
     *   Author: $author$
     *     Date: 3/13/2007
     **********************************************************************
     */
    virtual eError Attach
    (TAttached attached, bool onlyUnattached=false) 
    {
        eError error = e_ERROR_NOT_IMPLEMENTED;
        return error;
    }
};

/**
 **********************************************************************
 *  Class: cDetachImplementT
 *
 * Author: $author$
 *   Date: 3/13/2007
 **********************************************************************
 */
template
<class TAttached=HANDLE,
 class TImplements=cDetachInterface>

class cDetachImplementT
: virtual public TImplements
{
public:
    /**
     **********************************************************************
     * Function: Detach
     *
     *   Author: $author$
     *     Date: 3/13/2007
     **********************************************************************
     */
    virtual eError Detach
    (TAttached& attached, bool onlyAttached=false) 
    {
        eError error = e_ERROR_NOT_IMPLEMENTED;
        return error;
    }
};

#endif /* _CATTACHINTERFACE_HXX */
