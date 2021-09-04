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
 *   File: cattached.hxx
 *
 * Author: $author$
 *   Date: 3/24/2007
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CATTACHED_HXX
#define _CATTACHED_HXX

#include "cattachedinterface.hxx"
#include "cbase.hxx"

/**
 **********************************************************************
 *  Class: cAttachedT
 *
 * Author: $author$
 *   Date: 3/24/2007
 **********************************************************************
 */
template
<class TAttached=HANDLE,
 class TUnAttached=INVALID_HANDLE_T,
 TUnAttached VUnattached=V_INVALID_HANDLE,
 class TImplements=cAttachedInterface,
 class TExtends=cBase>

class cAttachedT
: virtual public TImplements,
  public TExtends
{
public:
    typedef TImplements cImplements;
    typedef TExtends cExtends;
    typedef TAttached tAttached;

    TAttached m_attached;

    /**
     **********************************************************************
     * Constructor: cAttachedT
     *
     *      Author: $author$
     *        Date: 3/24/2007
     **********************************************************************
     */
    cAttachedT(TAttached attached=(TAttached)(VUnattached)) 
    : m_attached((TAttached)(VUnattached))
    {
        eError error;

        if ((TAttached)(VUnattached) != attached)
        if ((error = Attach(attached, true)))
            throw(error);
    }
    /**
     **********************************************************************
     *  Destructor: ~cAttachedT
     *
     *      Author: $author$
     *        Date: 3/24/2007
     **********************************************************************
     */
    virtual ~cAttachedT()
    {
        eError error;
        TAttached attached;

        if ((TAttached)(VUnattached) != m_attached)
        if ((error = Detach(attached, true)))
            throw(error);
    }
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
        eError error = e_ERROR_NONE;

        if (onlyUnattached)
        if ((TAttached)(VUnattached) != m_attached)
            return e_ERROR_ALREADY_ATTACHED;

        m_attached = attached;
        return error;
    }
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
        eError error = e_ERROR_NONE;

        if (onlyAttached)
        if ((TAttached)(VUnattached) == m_attached)
            return e_ERROR_NOT_ATTACHED;

        attached = m_attached;
        m_attached = (TAttached)(VUnattached);
        return error;
    }
    /**
     **********************************************************************
     * Function: GetAttached
     *
     *   Author: $author$
     *     Date: 3/24/2007
     **********************************************************************
     */
    virtual TAttached GetAttached() const 
    {
        return m_attached;
    }
    /**
     **********************************************************************
     * Function: Attached
     *
     *   Author: $author$
     *     Date: 3/24/2007
     **********************************************************************
     */
    virtual TAttached Attached() const 
    {
        return m_attached;
    }
};

/**
 **********************************************************************
 * Typedef: cAttached
 *
 *  Author: $author$
 *    Date: 1/3/2008
 **********************************************************************
 */
typedef cAttachedT
<HANDLE, INVALID_HANDLE_T, V_INVALID_HANDLE,
 cAttachedInterface, cBase>
cAttached;

#endif /* _CATTACHED_HXX */
