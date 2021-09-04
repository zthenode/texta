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
 *   File: cthreadinterface.hxx
 *
 * Author: $author$
 *   Date: 2/14/2008
 **********************************************************************
 */
#ifndef _CTHREADINTERFACE_HXX
#define _CTHREADINTERFACE_HXX

#include "cinterfacebase.hxx"

#undef CDB_CLASS
#define CDB_CLASS "cThreadInterfaceT"
/**
 **********************************************************************
 *  Class: cThreadInterfaceT
 *
 * Author: $author$
 *   Date: 2/14/2008
 **********************************************************************
 */
template
<class TDerives,
 class TImplements=cInterfaceBase>
 
class c_INTERFACE_CLASS cThreadInterfaceT
: virtual public TImplements
{
public:
    typedef TImplements cImplements;
    typedef TDerives cDerives;
    /**
     **********************************************************************
     * Function: DeleteInstance
     *
     *   Author: $author$
     *     Date: 2/14/2008
     **********************************************************************
     */
    virtual eError DeleteInstance() = 0;
    /**
     **********************************************************************
     * Function: Run
     *
     *   Author: $author$
     *     Date: 2/14/2008
     **********************************************************************
     */
    virtual eError Run() = 0;
    /**
     **********************************************************************
     * Function: SetDeligate
     *
     *   Author: $author$
     *     Date: 2/14/2008
     **********************************************************************
     */
    virtual eError SetDeligate
    (TDerives* deligate) = 0;
    /**
     **********************************************************************
     * Function: GetDeligate
     *
     *   Author: $author$
     *     Date: 2/14/2008
     **********************************************************************
     */
    virtual TDerives* GetDeligate() const = 0;
};
#undef CDB_CLASS

/**
 **********************************************************************
 *  Class: cThreadInterface
 *
 * Author: $author$
 *   Date: 2/14/2008
 **********************************************************************
 */
class c_INTERFACE_CLASS cThreadInterface
: virtual public cThreadInterfaceT
  <cThreadInterface,cInterfaceBase>
{
public:
    typedef cThreadInterfaceT
    <cThreadInterface,cInterfaceBase> cImplements;
    /**
     **********************************************************************
     * Function: CreateInstance
     *
     *   Author: $author$
     *     Date: 2/14/2008
     **********************************************************************
     */
    static cThreadInterface* 
    CreateInstance(eError& error);
    /**
     **********************************************************************
     * Function: DestroyInstance
     *
     *   Author: $author$
     *     Date: 2/14/2008
     **********************************************************************
     */
    static eError DestroyInstance
    (cThreadInterface& instance);
    /**
     **********************************************************************
     * Function: DeleteInstance
     *
     *   Author: $author$
     *     Date: 2/14/2008
     **********************************************************************
     */
    virtual eError DeleteInstance() = 0;
};

#undef CDB_CLASS
#define CDB_CLASS "cThreadImplementT"
/**
 **********************************************************************
 *  Class: cThreadImplementT
 *
 * Author: $author$
 *   Date: 2/2/2009
 **********************************************************************
 */
template
<class TThreadInterface=cThreadInterface,
 class TImplements=TThreadInterface>
 
class cThreadImplementT
: virtual public TImplements
{
public:
    typedef TImplements cImplements;
    typedef cThreadImplementT cDerives;
    /**
     **********************************************************************
     * Function: DeleteInstance
     *
     *   Author: $author$
     *     Date: 2/2/2009
     **********************************************************************
     */
    virtual eError DeleteInstance() 
    {
        eError error = e_ERROR_NOT_IMPLEMENTED;
        return error;
    }
};
#undef CDB_CLASS

/**
 **********************************************************************
 *  Class: cThreadImplement
 *
 * Author: $author$
 *   Date: 2/2/2009
 **********************************************************************
 */
class cThreadImplement
: virtual public cThreadImplementT<cThreadInterface>
{
public:
    typedef cThreadImplementT<cThreadInterface> cImplements;
};

#endif /* _CTHREADINTERFACE_HXX */
