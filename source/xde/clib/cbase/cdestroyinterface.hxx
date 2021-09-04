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
 *   File: cdestroyinterface.hxx
 *
 * Author: $author$
 *   Date: 4/23/2008
 **********************************************************************
 */
#ifndef _CDESTROYINTERFACE_HXX
#define _CDESTROYINTERFACE_HXX

#include "cinterfacebase.hxx"

#undef CDB_CLASS
#define CDB_CLASS "cDestroyInterfaceT"
/**
 **********************************************************************
 *  Class: cDestroyInterfaceT
 *
 * Author: $author$
 *   Date: 4/23/2008
 **********************************************************************
 */
template
<class TImplements=cInterfaceBase>
 
class c_INTERFACE_CLASS cDestroyInterfaceT
: virtual public TImplements
{
public:
    typedef TImplements cImplements;
    typedef cDestroyInterfaceT cDerives;
    /**
     **********************************************************************
     * Function: Destroy
     *
     *   Author: $author$
     *     Date: 4/23/2008
     **********************************************************************
     */
    virtual eError Destroy
    (bool onlyCreated=false) = 0;
};
#undef CDB_CLASS

/**
 **********************************************************************
 *  Typedef: cDestroyInterface
 *
 *  Author: $author$
 *    Date: 4/23/2008
 **********************************************************************
 */
typedef cDestroyInterfaceT
<cInterfaceBase>
cDestroyInterface;

#undef CDB_CLASS
#define CDB_CLASS "cDestroyImplementT"
/**
 **********************************************************************
 *  Class: cDestroyImplementT
 *
 * Author: $author$
 *   Date: 4/23/2008
 **********************************************************************
 */
template
<class TImplements=cDestroyInterface>
 
class cDestroyImplementT
: virtual public TImplements
{
public:
    typedef TImplements cImplements;
    typedef cDestroyImplementT cDerives;
    /**
     **********************************************************************
     * Function: Destroy
     *
     *   Author: $author$
     *     Date: 4/23/2008
     **********************************************************************
     */
    virtual eError Destroy
    (bool onlyCreated=false) 
    {
        eError error = e_ERROR_NONE;
        return error;
    }
};
#undef CDB_CLASS

/**
 **********************************************************************
 *  Typedef: cDestroyImplement
 *
 *  Author: $author$
 *    Date: 4/23/2008
 **********************************************************************
 */
typedef cDestroyImplementT
<cDestroyInterface>
cDestroyImplement;

#endif /* _CDESTROYINTERFACE_HXX */
