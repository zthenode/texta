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
 *   File: ccloseinterface.hxx
 *
 * Author: $author$
 *   Date: 1/3/2008
 **********************************************************************
 */
#ifndef _CCLOSEINTERFACE_HXX
#define _CCLOSEINTERFACE_HXX

#include "cinterfacebase.hxx"

/**
 **********************************************************************
 *  Class: cCloseInterfaceT
 *
 * Author: $author$
 *   Date: 1/3/2008
 **********************************************************************
 */
template
<class TImplements=cInterfaceBase>
 
class c_INTERFACE_CLASS cCloseInterfaceT
: virtual public TImplements
{
public:
    /**
     **********************************************************************
     * Function: Close
     *
     *   Author: $author$
     *     Date: 1/3/2008
     **********************************************************************
     */
    virtual eError Close
    (bool onlyOpened=false) = 0;
};

/**
 **********************************************************************
 * Typedef: cCloseInterface
 *
 *  Author: $author$
 *    Date: 1/3/2008
 **********************************************************************
 */
typedef cCloseInterfaceT<cInterfaceBase>
cCloseInterface;

/**
 **********************************************************************
 *  Class: cCloseImplementT
 *
 * Author: $author$
 *   Date: 1/3/2008
 **********************************************************************
 */
template
<class TImplements=cCloseInterface>
 
class cCloseImplementT
: virtual public TImplements
{
public:
    /**
     **********************************************************************
     * Function: Close
     *
     *   Author: $author$
     *     Date: 1/3/2008
     **********************************************************************
     */
    virtual eError Close
    (bool onlyOpened=false) 
    {
        eError error = e_ERROR_NOT_IMPLEMENTED;
        return error;
    }
};

/**
 **********************************************************************
 * Typedef: cCloseImplement
 *
 *  Author: $author$
 *    Date: 1/3/2008
 **********************************************************************
 */
typedef cCloseImplementT
<cCloseInterface>
cCloseImplement;

#endif /* _CCLOSEINTERFACE_HXX */
