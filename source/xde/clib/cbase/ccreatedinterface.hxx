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
 *   File: ccreatedinterface.hxx
 *
 * Author: $author$
 *   Date: 4/23/2008
 **********************************************************************
 */
#ifndef _CCREATEDINTERFACE_HXX
#define _CCREATEDINTERFACE_HXX

#include "cdestroyinterface.hxx"

#undef CDB_CLASS
#define CDB_CLASS "cCreatedInterfaceT"
/**
 **********************************************************************
 *  Class: cCreatedInterfaceT
 *
 * Author: $author$
 *   Date: 4/23/2008
 **********************************************************************
 */
template
<class TImplements=cDestroyInterface>
 
class c_INTERFACE_CLASS cCreatedInterfaceT
: virtual public TImplements
{
public:
    typedef TImplements cImplements;
    typedef cCreatedInterfaceT cDerives;
    /**
     **********************************************************************
     * Function: SetIsCreated
     *
     *   Author: $author$
     *     Date: 4/23/2008
     **********************************************************************
     */
    virtual int SetIsCreated
    (bool is=true) = 0;
    /**
     **********************************************************************
     * Function: GetIsCreated
     *
     *   Author: $author$
     *     Date: 4/23/2008
     **********************************************************************
     */
    virtual bool GetIsCreated() const = 0;
};
#undef CDB_CLASS

/**
 **********************************************************************
 *  Typedef: cCreatedInterface
 *
 *  Author: $author$
 *    Date: 4/23/2008
 **********************************************************************
 */
typedef cCreatedInterfaceT
<cDestroyInterface>
cCreatedInterface;

#undef CDB_CLASS
#define CDB_CLASS "cCreatedImplementT"
/**
 **********************************************************************
 *  Class: cCreatedImplementT
 *
 * Author: $author$
 *   Date: 4/23/2008
 **********************************************************************
 */
template
<class TImplements=cCreatedInterface>
 
class cCreatedImplementT
: virtual public TImplements
{
public:
    typedef TImplements cImplements;
    typedef cCreatedImplementT cDerives;
    /**
     **********************************************************************
     * Function: SetIsCreated
     *
     *   Author: $author$
     *     Date: 4/23/2008
     **********************************************************************
     */
    virtual int SetIsCreated
    (bool is=true) 
    {
        int isCreated = -e_ERROR_NOT_IMPLEMENTED;
        return isCreated;
    }
    /**
     **********************************************************************
     * Function: GetIsCreated
     *
     *   Author: $author$
     *     Date: 4/23/2008
     **********************************************************************
     */
    virtual bool GetIsCreated() const 
    {
        bool isCreated = false;
        return isCreated;
    }
};
#undef CDB_CLASS

/**
 **********************************************************************
 *  Typedef: cCreatedImplement
 *
 *  Author: $author$
 *    Date: 4/23/2008
 **********************************************************************
 */
typedef cCreatedImplementT
<cCreatedInterface>
cCreatedImplement;

#endif /* _CCREATEDINTERFACE_HXX */
