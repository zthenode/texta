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
 *   File: cwinmenuiteminfo.hxx
 *
 * Author: $author$
 *   Date: 10/31/2008
 **********************************************************************
 */
#ifndef _CWINMENUITEMINFO_HXX
#define _CWINMENUITEMINFO_HXX

#include "cwinmenuiteminfo.h"
#include "cstring.hxx"
#include "cbuffer.hxx"

/**
 **********************************************************************
 *  Class: cWinMenuItemInfo
 *
 * Author: $author$
 *   Date: 10/31/2008
 **********************************************************************
 */
class cWinMenuItemInfo
{
public:
    typedef cWinMenuItemInfo cDerives;

    MENUITEMINFO m_menuItemInfo;
    UINT m_menuItemID;
    TCHAR* m_menuItemChars;
    TLENGTH m_menuItemCharsLength;
    cTCHARBuffer m_menuItem;

    /**
     **********************************************************************
     * Constructor: cWinMenuItemInfo
     *
     *      Author: $author$
     *        Date: 10/31/2008
     **********************************************************************
     */
    cWinMenuItemInfo
    (const TCHAR* menuItemChars=0, 
     TLENGTH menuItemCharsLength=-1) 
    : m_menuItemID(0),
      m_menuItemChars(0),
      m_menuItemCharsLength(0)
    {
        eError error;

        memset(&m_menuItemInfo, 0, sizeof(m_menuItemInfo));
        m_menuItemInfo.cbSize = sizeof(m_menuItemInfo);

        if (menuItemChars)
        if (0 > (menuItemCharsLength = SetString
            (menuItemChars, menuItemCharsLength)))
            throw(error = -menuItemCharsLength);
    }

    /**
     **********************************************************************
     * Function: SetID
     *
     *   Author: $author$
     *     Date: 11/2/2008
     **********************************************************************
     */
    virtual eError SetID(UINT id) 
    {
        eError error = e_ERROR_NONE;
         m_menuItemID = id;
        return error;
    }
    /**
     **********************************************************************
     * Function: SetChecked
     *
     *   Author: $author$
     *     Date: 11/3/2008
     **********************************************************************
     */
    virtual eError SetChecked(bool isChecked=true) 
    {
        eError error = e_ERROR_NONE;
        UINT fState = (isChecked)?(MFS_CHECKED):(MFS_UNCHECKED);
        m_menuItemInfo.fMask = MIIM_STATE;
        m_menuItemInfo.fState = fState;
        return error;
    }
    /**
     **********************************************************************
     * Function: SetSeparator
     *
     *   Author: $author$
     *     Date: 11/2/2008
     **********************************************************************
     */
    virtual eError SetSeparator() 
    {
        eError error = e_ERROR_NONE;
        m_menuItemInfo.fMask = MIIM_TYPE;
        m_menuItemInfo.fType = MFT_SEPARATOR;
        return error;
    }
    /**
     **********************************************************************
     * Function: SetBitmap
     *
     *   Author: $author$
     *     Date: 11/2/2008
     **********************************************************************
     */
    virtual eError SetBitmap
    (HBITMAP hBitmap, bool hasRadioCheck=false) 
    {
        eError error = e_ERROR_NONE;
        UINT fRadioCheck = hasRadioCheck?MFT_RADIOCHECK:0;

        m_menuItemInfo.fMask = MIIM_TYPE | MIIM_ID;
        m_menuItemInfo.fType = MFT_BITMAP | fRadioCheck;
        m_menuItemInfo.wID = m_menuItemID;
        m_menuItemInfo.dwTypeData = (LPTSTR)(hBitmap);
        return error;
    }
    /**
     **********************************************************************
     * Function: SetString
     *
     *   Author: $author$
     *     Date: 10/31/2008
     **********************************************************************
     */
    virtual TLENGTH SetString
    (const TCHAR* menuItemChars,
     TLENGTH menuItemCharsLength=-1,
     bool hasRadioCheck=false) 
    {
        TLENGTH count = 0;
        UINT fRadioCheck = hasRadioCheck?MFT_RADIOCHECK:0;

        if (menuItemChars)
        if (0 <= (count = m_menuItem.Copy
            (menuItemChars, menuItemCharsLength)))
        if ((m_menuItemChars = m_menuItem.
            GetWriteBuffer(m_menuItemCharsLength)))
        {
            m_menuItemInfo.fMask = MIIM_TYPE | MIIM_ID;
            m_menuItemInfo.fType = MFT_STRING | fRadioCheck;
            m_menuItemInfo.wID = m_menuItemID;
            m_menuItemInfo.dwTypeData = m_menuItemChars;
            m_menuItemInfo.cch = m_menuItemCharsLength;
        }
        return count;
    }

    /**
     **********************************************************************
     * Function: SetBitmapSubMenu
     *
     *   Author: $author$
     *     Date: 11/2/2008
     **********************************************************************
     */
    virtual eError SetBitmapSubMenu
    (HMENU hSubMenu,
     HBITMAP hBitmap) 
    {
        eError error = e_ERROR_NONE;
        m_menuItemInfo.fMask = MIIM_TYPE | MIIM_ID | MIIM_SUBMENU;
        m_menuItemInfo.fType = MFT_BITMAP;
        m_menuItemInfo.wID = m_menuItemID;
        m_menuItemInfo.dwTypeData = (LPTSTR)(hBitmap);
        m_menuItemInfo.hSubMenu = hSubMenu;
        return error;
    }
    /**
     **********************************************************************
     * Function: SetStringSubMenu
     *
     *   Author: $author$
     *     Date: 11/1/2008
     **********************************************************************
     */
    virtual TLENGTH SetStringSubMenu
    (HMENU hSubMenu,
     const TCHAR* menuItemChars,
     TLENGTH menuItemCharsLength=-1) 
    {
        TLENGTH count = 0;
        if (menuItemChars)
        if (0 <= (count = m_menuItem.Copy
            (menuItemChars, menuItemCharsLength)))
        if ((m_menuItemChars = m_menuItem.
            GetWriteBuffer(m_menuItemCharsLength)))
        {
            m_menuItemInfo.fMask = MIIM_TYPE | MIIM_ID | MIIM_SUBMENU;
            m_menuItemInfo.fType = MFT_STRING;
            m_menuItemInfo.wID = m_menuItemID;
            m_menuItemInfo.dwTypeData = m_menuItemChars;
            m_menuItemInfo.cch = m_menuItemCharsLength;
            m_menuItemInfo.hSubMenu = hSubMenu;
        }
        return count;
    }
    /**
     **********************************************************************
     * Function: MENUITEMINFO
     *
     *   Author: $author$
     *     Date: 10/31/2008
     **********************************************************************
     */
    virtual operator MENUITEMINFO&() const 
    {
        return (MENUITEMINFO&)(m_menuItemInfo);
    }
};
#endif /* _CWINMENUITEMINFO_HXX */
