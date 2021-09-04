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
 *   File: cwinmenu.hxx
 *
 * Author: $author$
 *   Date: 10/30/2008
 **********************************************************************
 */
#ifndef _CWINMENU_HXX
#define _CWINMENU_HXX

#include "cwinmenuiteminfo.hxx"
#include "cwinattached.hxx"
#include "cdebug.hxx"

/**
 **********************************************************************
 *  Class: cWinMenu
 *
 * Author: $author$
 *   Date: 10/30/2008
 **********************************************************************
 */
class cWinMenu
: public cHMENUCreatedAttached
{
public:
    typedef cHMENUCreatedAttached cExtends;
    typedef cWinMenu cDerives;

    cWinMenuItemInfo m_menuItemInfo;

    /**
     **********************************************************************
     * Constructor: cWinMenu
     *
     *      Author: $author$
     *        Date: 10/30/2008
     **********************************************************************
     */
    cWinMenu
    (HMENU attached=NULL_HANDLE,
     bool isCreated=false) 
    : cExtends(attached, isCreated)
    {
    }
    /**
     **********************************************************************
     * Destructor: ~cWinMenu
     *
     *     Author: $author$
     *       Date: 10/30/2008
     **********************************************************************
     */
    virtual ~cWinMenu()
    {
    }

    /**
     **********************************************************************
     * Function: Create
     *
     *   Author: $author$
     *     Date: 10/30/2008
     **********************************************************************
     */
    virtual eError Create
    (bool onlyDestroyed=false) 
    {
        eError error = e_ERROR_FAILED;
        HMENU attached;
        int isCreated;

        if ((error = Destroyed(onlyDestroyed)))
            return error;

        if (!(isCreated = NULL_HANDLE != 
            (attached = CreateAttached(error))))
            return error;

        if (0 > (isCreated = SetIsCreated(0!=isCreated)))
            error = -isCreated;
        else
        if (!(error = Attach(attached)))
            return error;

        DestroyAttached(attached);
        return error;
    }
    /**
     **********************************************************************
     * Function: Destroy
     *
     *   Author: $author$
     *     Date: 10/30/2008
     **********************************************************************
     */
    virtual eError Destroy
    (bool onlyCreated=false) 
    {
        eError error = e_ERROR_FAILED;
        HMENU attached = NULL_HANDLE;
        int isCreated;

        if ((isCreated = GetIsCreated()))
        {
            if (0 > (isCreated  = SetIsCreated(false)))
                return error = -isCreated;
        }
        else
        if (onlyCreated)
            return e_ERROR_NOT_CREATED;

        if ((error = Detach(attached, onlyCreated)))
            return error;

        if (NULL_HANDLE == attached)
            return e_ERROR_NOT_ATTACHED;

        error = DestroyAttached(attached);
        return error;
    }

    /**
     **********************************************************************
     * Function: SetMenuItemChecked
     *
     *   Author: $author$
     *     Date: 11/3/2008
     **********************************************************************
     */
    virtual eError SetMenuItemChecked
    (UINT id, bool isChecked=true) 
    {
        eError error = e_ERROR_NOT_ATTACHED;
        HMENU attached;
        if (NULL_HANDLE != (attached = GetAttached()))
        if (!(error = m_menuItemInfo.SetChecked(isChecked)))
        if (SetMenuItemInfo(attached, id, FALSE, &((MENUITEMINFO&)(m_menuItemInfo))))
            error = e_ERROR_NONE;
        else
        error = e_ERROR_FAILED;
        return error;
    }

    /**
     **********************************************************************
     * Function: AddSeparatorMenuItem
     *
     *   Author: $author$
     *     Date: 11/2/2008
     **********************************************************************
     */
    virtual eError AddSeparatorMenuItem() 
    {
        eError error = e_ERROR_NOT_ATTACHED;
        HMENU attached;
        if (NULL_HANDLE != (attached = GetAttached()))
        if ((error = m_menuItemInfo.SetSeparator()))
            return error;
        else
        if (InsertMenuItem(attached, 0, 0, &((MENUITEMINFO&)(m_menuItemInfo))))
            error = e_ERROR_NONE;
        return error;
    }
    /**
     **********************************************************************
     * Function: AddBitmapMenuItem
     *
     *   Author: $author$
     *     Date: 11/2/2008
     **********************************************************************
     */
    virtual eError AddBitmapMenuItem
    (UINT id, HBITMAP hBitmap,
     bool isRadioCheck=false) 
    {
        eError error = e_ERROR_NOT_ATTACHED;
        HMENU attached;
        if (NULL_HANDLE != (attached = GetAttached()))
        if (!(error = m_menuItemInfo.SetID(id)))
        if (!(error = m_menuItemInfo.SetBitmap(hBitmap, isRadioCheck)))
        if (InsertMenuItem(attached, 0, 0, &((MENUITEMINFO&)(m_menuItemInfo))))
            error = e_ERROR_NONE;
        else
        error = e_ERROR_FAILED;
        return error;
    }
    /**
     **********************************************************************
     * Function: AddStringMenuItem
     *
     *   Author: $author$
     *     Date: 10/31/2008
     **********************************************************************
     */
    virtual eError AddStringMenuItem
    (UINT id,
     const TCHAR* chars,
     TLENGTH length=-1) 
    {
        eError error = e_ERROR_NOT_ATTACHED;
        HMENU attached;
        if (NULL_HANDLE != (attached = GetAttached()))
        if (!(error = m_menuItemInfo.SetID(id)))
        if (0 > (length = m_menuItemInfo.SetString(chars, length)))
            return -length;
        else
        if (InsertMenuItem(attached, 0, 0, &((MENUITEMINFO&)(m_menuItemInfo))))
            error = e_ERROR_NONE;
        return error;
    }
    /**
     **********************************************************************
     * Function: AddStringSubMenuMenuItem
     *
     *   Author: $author$
     *     Date: 11/2/2008
     **********************************************************************
     */
    virtual eError AddStringSubMenuMenuItem
    (UINT id,
     HMENU hSubMenu,
     const TCHAR* chars,
     TLENGTH length=-1) 
    {
        eError error = e_ERROR_NOT_ATTACHED;
        HMENU attached;
        if (NULL_HANDLE != (attached = GetAttached()))
        if (!(error = m_menuItemInfo.SetID(id)))
        if (0 > (length = m_menuItemInfo.
            SetStringSubMenu(hSubMenu, chars, length)))
            return -length;
        else
        if (InsertMenuItem(attached, 0, 0, &((MENUITEMINFO&)(m_menuItemInfo))))
            error = e_ERROR_NONE;
        return error;
    }

    /**
     **********************************************************************
     * Function: CreateAttached
     *
     *   Author: $author$
     *     Date: 10/30/2008
     **********************************************************************
     */
    virtual HMENU CreateAttached
    (eError& error) const 
    {
        HMENU attached = NULL_HANDLE;
        error = e_ERROR_FAILED;
        if (NULL_HANDLE != (attached = CreateMenu()))
            error = e_ERROR_NONE;
        else
        DBE("() failed on CreateMenu()\n");
        return attached;
    }
    /**
     **********************************************************************
     * Function: DestroyAttached
     *
     *   Author: $author$
     *     Date: 10/30/2008
     **********************************************************************
     */
    virtual eError DestroyAttached
    (HMENU attached) const 
    {
        eError error = e_ERROR_FAILED;
        if (NULL_HANDLE != attached)
        if (DestroyMenu(attached))
            error = e_ERROR_NONE;
        else
        DBE("() failed on DestroyMenu()\n");
        return error;
    }
};
#endif /* _CWINMENU_HXX */
