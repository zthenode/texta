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
 *   File: cinstanceinterface.hxx
 *
 * Author: $author$
 *   Date: 3/13/2008
 **********************************************************************
 */
#ifndef _CINSTANCEINTERFACE_HXX
#define _CINSTANCEINTERFACE_HXX

#include "cinterfacebase.hxx"

#undef CDB_CLASS
#define CDB_CLASS "cInstanceInterfaceT"
/**
 **********************************************************************
 *  Class: cInstanceInterfaceT
 *
 * Author: $author$
 *   Date: 3/13/2008
 **********************************************************************
 */
template <class TImplements = cInterfaceBase>
class c_INTERFACE_CLASS cInstanceInterfaceT
: virtual public TImplements
{
public:
    typedef TImplements cImplements;
    typedef cInstanceInterfaceT cDerives;
    /**
     **********************************************************************
     * Function: DeleteInstance
     *
     *   Author: $author$
     *     Date: 3/13/2008
     **********************************************************************
     */
    virtual eError DeleteInstance
    (bool onlyNotIsStaticInstance=false) = 0;
    /**
     **********************************************************************
     * Function: DeleteThis
     *
     *   Author: $author$
     *     Date: 3/13/2008
     **********************************************************************
     */
    virtual eError DeleteThis() = 0;
    /**
     **********************************************************************
     * Function: SetIsStaticInstance
     *
     *   Author: $author$
     *     Date: 3/13/2008
     **********************************************************************
     */
    virtual int SetIsStaticInstance(bool is=true) = 0;
    /**
     **********************************************************************
     * Function: GetIsStaticInstance
     *
     *   Author: $author$
     *     Date: 3/13/2008
     **********************************************************************
     */
    virtual bool GetIsStaticInstance() const = 0;
};
#undef CDB_CLASS

typedef cInstanceInterfaceT
<cInterfaceBase> cInstanceInterfaceImplements;
/**
 **********************************************************************
 *  Class: cInstanceInterface
 *
 * Author: $author$
 *   Date: 3/13/2008
 **********************************************************************
 */
class c_INTERFACE_CLASS cInstanceInterface
: virtual public cInstanceInterfaceImplements
{
public:
    typedef cInstanceInterfaceImplements cImplements;
};

#undef CDB_CLASS
#define CDB_CLASS "cInstanceImplementT"
/**
 **********************************************************************
 *  Class: cInstanceImplementT
 *
 * Author: $author$
 *   Date: 12/10/2017
 **********************************************************************
 */
template <class TImplements = cInstanceInterface>
class cInstanceImplementT
: virtual public TImplements
{
public:
    typedef TImplements cImplements;
    /**
     **********************************************************************
     * Function: DeleteInstance
     *
     *   Author: $author$
     *     Date: 3/13/2008
     **********************************************************************
     */
    virtual eError DeleteInstance
    (bool onlyNotIsStaticInstance = false)
    {
        return e_ERROR_FAILED;
    }
    /**
     **********************************************************************
     * Function: DeleteThis
     *
     *   Author: $author$
     *     Date: 3/13/2008
     **********************************************************************
     */
    virtual eError DeleteThis()
    {
        return e_ERROR_FAILED;
    }
    /**
     **********************************************************************
     * Function: SetIsStaticInstance
     *
     *   Author: $author$
     *     Date: 3/13/2008
     **********************************************************************
     */
    virtual int SetIsStaticInstance(bool is = true)
    {
        return -e_ERROR_FAILED;
    }
    /**
     **********************************************************************
     * Function: GetIsStaticInstance
     *
     *   Author: $author$
     *     Date: 3/13/2008
     **********************************************************************
     */
    virtual bool GetIsStaticInstance() const
    {
        return false;
    }
};
#undef CDB_CLASS

typedef cInstanceImplementT
<cInstanceInterface> cInstanceImplementImplements;
/**
 **********************************************************************
 *  Class: cInstanceImplement
 *
 * Author: $author$
 *   Date: 12/10/2017
 **********************************************************************
 */
class cInstanceImplement
: virtual public cInstanceImplementImplements
{
public:
    typedef cInstanceImplementImplements cImplements;
};

#endif /* _CINSTANCEINTERFACE_HXX */
