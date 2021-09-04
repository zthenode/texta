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
 *   File: cwinmenuiteminfo.h
 *
 * Author: $author$
 *   Date: 10/31/2008
 **********************************************************************
 */
#ifndef _CWINMENUITEMINFO_H
#define _CWINMENUITEMINFO_H

#include "cplatform.h"

/*
typedef struct tagMENUITEMINFO {
    UINT    cbSize; 
    UINT    fMask; 
    UINT    fType; 
    UINT    fState; 
    UINT    wID; 
    HMENU   hSubMenu; 
    HBITMAP hbmpChecked; 
    HBITMAP hbmpUnchecked; 
    DWORD   dwItemData; 
    LPTSTR  dwTypeData; 
    UINT    cch; 
} MENUITEMINFO, FAR *LPMENUITEMINFO; 
 
cbSize 
Size of structure, in bytes. 

fMask 
Members to retrieve or set. This member can be one or more of these values: Value Meaning 
MIIM_CHECKMARKS Retrieves or sets the hbmpChecked and hbmpUnchecked members. 
MIIM_DATA Retrieves or sets the dwItemData member. 
MIIM_ID Retrieves or sets the wID member. 
MIIM_STATE Retrieves or sets the fState member. 
MIIM_SUBMENU Retrieves or sets the hSubMenu member. 
MIIM_TYPE Retrieves or sets the fType and dwTypeData members. 

fType 
Menu item type. This member can be one or more of these values: Value Meaning 
MFT_BITMAP Displays the menu item using a bitmap. The low-order word of the dwTypeData member is the bitmap handle, and the cch member is ignored. 
MFT_MENUBARBREAK Places the menu item on a new line (for a menu bar) or in a new column (for a drop-down menu, submenu, or shortcut menu). For a drop-down menu, submenu, or shortcut menu, a vertical line separates the new column from the old. 
MFT_MENUBREAK Places the menu item on a new line (for a menu bar) or in a new column (for a drop-down menu, submenu, or shortcut menu). For a drop-down menu, submenu, or shortcut menu, the columns are not separated by a vertical line. 
MFT_OWNERDRAW Assigns responsibility for drawing the menu item to the window that owns the menu. The window receives a WM_MEASUREITEM message before the menu is displayed for the first time, and a WM_DRAWITEM message whenever the appearance of the menu item must be updated. If this value is specified, the dwTypeData member contains an application-defined 32-bit value. 
MFT_RADIOCHECK Displays checked menu items using a radio-button mark instead of a check mark if the hbmpChecked member is NULL. 
MFT_RIGHTJUSTIFY Right-justifies the menu item and any subsequent items. This value is valid only if the menu item is in a menu bar. 
MFT_RIGHTORDER Windows 95, Windows NT 5.0, and later: Specifies that menus cascade right-to-left (the default is left-to-right). This is used to support right-to-left languages, such as Arabic and Hebrew. ` 
MFT_SEPARATOR Specifies that the menu item is a separator. A menu item separator appears as a horizontal dividing line. The dwTypeData and cch members are ignored. This value is valid only in a drop-down menu, submenu, or shortcut menu. 
MFT_STRING Displays the menu item using a text string. The dwTypeData member is the pointer to a null-terminated string, and the cch member is the length of the string. 

The MFT_BITMAP, MFT_SEPARATOR, and MFT_STRING values cannot be combined with one another. 

fState 
Menu item state. This member can be one or more of these values: Value Meaning 
MFS_CHECKED Checks the menu item. For more information about checked menu items, see the hbmpChecked member. 
MFS_DEFAULT Specifies that the menu item is the default. A menu can contain only one default menu item, which is displayed in bold. 
MFS_DISABLED Disables the menu item so that it cannot be selected, but does not gray it. 
MFS_ENABLED Enables the menu item so that it can be selected. This is the default state. 
MFS_GRAYED Disables the menu item and grays it so that it cannot be selected. 
MFS_HILITE Highlights the menu item. 
MFS_UNCHECKED Unchecks the menu item. For more information about unchecked menu items, see the hbmpUnchecked member. 
MFS_UNHILITE Removes the highlight from the menu item. This is the default state. 

wID 
Application-defined 16-bit value that identifies the menu item. 

hSubMenu 
Handle to the drop-down menu or submenu associated with the menu item. If the menu item is not an item that opens a drop-down menu or submenu, this member is NULL. 

hbmpChecked 
Handle to the bitmap to display next to the item if it is checked. If this member is NULL, a default bitmap is used. If the MFT_RADIOCHECK type value is specified, the default bitmap is a bullet. Otherwise, it is a check mark. 

hbmpUnchecked 
Handle to the bitmap to display next to the item if it is not checked. If this member is NULL, no bitmap is used. 

dwItemData 
Application-defined value associated with the menu item. 

dwTypeData 
Content of the menu item. This member is used only if the MIIM_TYPE flag is set in the fMask member. 
Before calling GetMenuItemInfo, the application must set this member to point to a buffer whose length is specified by the cch member. If the retrieved menu item is of the type MFT_STRING, then GetMenuItemInfo copies the menu item text to the buffer. If the retrieved menu item is of some other type, then GetMenuItemInfo sets the dwTypeData member to a value whose type is specified by the fType member. 

When using with the SetMenuItemInfo function, this member should contains a value whose type is specified by the fType member. 

cch 
Length of the menu item text when information is received about a menu item of the MFT_STRING type. This member is used only if the MIIM_TYPE flag is set in the fMask member and is zero otherwise. This member is ignored when the content of a menu item is set by calling SetMenuItemInfo. 
Before calling GetMenuItemInfo, the application must set this member to the length of the buffer pointed to by the dwTypeData member. If the retrieved menu item is of type MFT_STRING (as indicated by the fType member), then GetMenuItemInfo sets cch to the length of the retrieved string. If the retrieved menu item is of some other type, GetMenuItemInfo sets the cch field to zero. 

Remarks
The MENUITEMINFO structure is used with the GetMenuItemInfo, InsertMenuItem, and SetMenuItemInfo functions.

QuickInfo
  Windows NT: Requires version 4.0 or later.
  Windows: Requires Windows 95 or later.
  Windows CE: Requires version 1.0 or later.
  Header: Declared in winuser.h.
  Unicode: Defined as Unicode and ANSI structures.

See Also
Menus Overview, Menu Structures, 
GetMenuItemInfo, InsertMenuItem, SetMenuItemInfo, 
WM_DRAWITEM, WM_MEASUREITEM 
*/
#endif /* _CWINMENUITEMINFO_H */
