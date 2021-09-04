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
 *   File: ccreatedattached.hxx
 *
 * Author: $author$
 *   Date: 4/23/2008
 **********************************************************************
 */
#ifndef _CCREATEDATTACHED_HXX
#define _CCREATEDATTACHED_HXX

#include "ccreatedinterface.hxx"
#include "cattached.hxx"

#undef CDB_CLASS
#define CDB_CLASS "cCreatedAttachedT"
/**
 **********************************************************************
 *  Class: cCreatedAttachedT
 *
 * Author: $author$
 *   Date: 4/23/2008
 **********************************************************************
 */
template
<class TAttached=HANDLE,
 class TUnAttached=INVALID_HANDLE_T,
 TUnAttached VUnattached=V_INVALID_HANDLE,
 class TExtends=cAttached,
 class TImplements=cCreatedImplement>
 
class cCreatedAttachedT
: virtual public TImplements,
  public TExtends
{
public:
    typedef TImplements cImplements;
    typedef TExtends cExtends;
    typedef cCreatedAttachedT cDerives;

    bool m_isCreated;

    /**
     **********************************************************************
     * Constructor: cCreatedAttachedT
     *
     *      Author: $author$
     *        Date: 4/23/2008
     **********************************************************************
     */
    cCreatedAttachedT
    (TAttached attached=(TAttached)(VUnattached),
     bool isCreated=false) 
    : cExtends(attached),
      m_isCreated(isCreated)
    {
    }
    /**
     **********************************************************************
     * Destructor: cCreatedAttachedT
     *
     *     Author: $author$
     *       Date: 4/23/2008
     **********************************************************************
     */
    virtual ~cCreatedAttachedT()
    {
        Destruct();
    }

    /**
     **********************************************************************
     * Function: Destruct
     *
     *   Author: $author$
     *     Date: 4/29/2008
     **********************************************************************
     */
    virtual void Destruct() 
    {
        eError error;
        TAttached attached;
        bool isCreated;

        if ((isCreated = CTHIS GetIsCreated()))
        if ((error = Destroy(isCreated)))
            throw(error);

        if ((isCreated = (VUnattached != (attached = CTHIS Attached()))))
        if ((error = CTHIS Detach(attached, isCreated)))
            throw(error);
    }
    /**
     **********************************************************************
     * Function: Destroyed
     *
     *   Author: $author$
     *     Date: 4/29/2008
     **********************************************************************
     */
    virtual eError Destroyed
    (bool onlyDestroyed=false) 
    {
        eError error = e_ERROR_NONE;
        TAttached attached;
        bool isCreated;

        if ((isCreated = CTHIS GetIsCreated()))
        if (onlyDestroyed)
            return e_ERROR_ALREADY_CREATED;
        else
        if ((error = CTHIS Destroy(isCreated)))
            return error;

        if ((isCreated = (VUnattached != (attached = CTHIS Attached()))))
        if (onlyDestroyed)
            return e_ERROR_ALREADY_ATTACHED;
        else
        if ((error = CTHIS Detach(attached, isCreated)))
            return error;
        return error;
    }
    /**
     **********************************************************************
     * Function: Destroy
     *
     *   Author: $author$
     *     Date: 4/29/2008
     **********************************************************************
     */
    virtual eError Destroy
    (bool onlyCreated=false) 
    {
        eError error = e_ERROR_NONE;
        TAttached attached;
        bool isCreated;
        int created;

        if ((isCreated = CTHIS GetIsCreated()))
        {
            if (0 > (created = CTHIS SetIsCreated(false)))
                return error = -created;
        }
        else
        if (onlyCreated)
            return e_ERROR_NOT_CREATED;

        if (((error = CTHIS Detach(attached, onlyCreated)))
            || !(isCreated = (VUnattached != attached)))
            return error;

        error = CTHIS DestroyAttached(attached);
        return error;
    }

    /**
     **********************************************************************
     * Function: CreateAttached
     *
     *   Author: $author$
     *     Date: 11/3/2008
     **********************************************************************
     */
    virtual TAttached CreateAttached
    (eError& error) const 
    {
        TAttached attached = (TAttached)(VUnattached);
        error = e_ERROR_NOT_IMPLEMENTED;
        return attached;
    }
    /**
     **********************************************************************
     * Function: DestroyAttached
     *
     *   Author: $author$
     *     Date: 4/23/2008
     **********************************************************************
     */
    virtual eError DestroyAttached
    (TAttached attached) const
    {
        eError error = e_ERROR_NONE;
        return error;
    }

    /**
     **********************************************************************
     * Function: SetIsCreated
     *
     *   Author: $author$
     *     Date: 10/19/2008
     **********************************************************************
     */
    virtual int SetIsCreated
    (bool is=true) 
    {
        int isCreated = (m_isCreated = is);
        return isCreated;
    }
    /**
     **********************************************************************
     * Function: GetIsCreated
     *
     *   Author: $author$
     *     Date: 10/19/2008
     **********************************************************************
     */
    virtual bool GetIsCreated() const 
    {
        return m_isCreated;
    }
};
#undef CDB_CLASS

#endif /* _CCREATEDATTACHED_HXX */
