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
 *   File: cinstance.hxx
 *
 * Author: $author$
 *   Date: 3/13/2008
 **********************************************************************
 */
#ifndef _CINSTANCE_HXX
#define _CINSTANCE_HXX

#include "cinstanceinterface.hxx"
#include "cbase.hxx"

#undef CDB_CLASS
#define CDB_CLASS "cInstanceT"
/**
 **********************************************************************
 *  Class: cInstanceT
 *
 * Author: $author$
 *   Date: 3/13/2008
 **********************************************************************
 */
template
<class TImplements=cInstanceInterface,
 class TExtends=cBase>
 
class cInstanceT
: virtual public TImplements,
  public TExtends
{
public:
    typedef TImplements cImplements;
    typedef TExtends cExtends;
    typedef cInstanceT cDerives;

    bool m_isStaticInstance;

    /**
     **********************************************************************
     * Constructor: cInstanceT
     *
     *      Author: $author$
     *        Date: 3/13/2008
     **********************************************************************
     */
    cInstanceT
    (bool isStaticInstance=true) 
    : m_isStaticInstance(isStaticInstance)
    {
    }
    /**
     **********************************************************************
     * Constructor: cInstanceT
     *
     *      Author: $author$
     *        Date: 3/13/2008
     **********************************************************************
     */
    cInstanceT
    (const cInstanceT& instance) 
    : m_isStaticInstance(true)
    {
    }
    /**
     **********************************************************************
     * Destructor: cInstanceT
     *
     *     Author: $author$
     *       Date: 3/13/2008
     **********************************************************************
     */
    virtual ~cInstanceT()
    {
    }
    /**
     **********************************************************************
     * Function: DeleteInstance
     *
     *   Author: $author$
     *     Date: 3/13/2008
     **********************************************************************
     */
    virtual eError DeleteInstance
    (bool onlyNotIsStaticInstance=false) 
    {
        eError error = e_ERROR_NONE;
        bool isStaticInstance;
        if ((isStaticInstance = GetIsStaticInstance()))
        if (onlyNotIsStaticInstance)
            return e_ERROR_STATIC_INSTANCE;
        else return e_ERROR_NONE;
        error = DeleteThis();
        return error;
    }
    /**
     **********************************************************************
     * Function: DeleteThis
     *
     *   Author: $author$
     *     Date: 3/13/2008
     **********************************************************************
     */
    virtual eError DeleteThis() = 0
#if defined(WIN32) 
/* Windows */
    {
        eError error = e_ERROR_NONE;
        bool isStaticInstance;
        if ((isStaticInstance = GetIsStaticInstance()))
            return e_ERROR_STATIC_INSTANCE;
        delete this;
        return error;
    }
#else /* defined(WIN32) */
/* Unix */
   ;
#endif /* defined(WIN32) */
    /**
     **********************************************************************
     * Function: SetIsStaticInstance
     *
     *   Author: $author$
     *     Date: 3/13/2008
     **********************************************************************
     */
    virtual int SetIsStaticInstance(bool is=true) 
    {
        int isStaticInstance = (false != (m_isStaticInstance = is));
        return isStaticInstance;
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
        return m_isStaticInstance;
    }
};
#undef CDB_CLASS

/**
 **********************************************************************
 *  Class: cInstance
 *
 * Author: $author$
 *   Date: 3/13/2008
 **********************************************************************
 */
class cInstance
: public cInstanceT<cInstanceInterface,cBase>
{
public:
    typedef cInstanceT<cInstanceInterface,cBase> cExtends;
    /**
     **********************************************************************
     * Constructor: cInstance
     *
     *      Author: $author$
     *        Date: 3/13/2008
     **********************************************************************
     */
    cInstance
    (bool isStaticInstance=true) 
    : cExtends(isStaticInstance) 
    {
    }
};
#endif /* _CINSTANCE_HXX */

