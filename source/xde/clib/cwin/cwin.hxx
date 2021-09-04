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
 *   File: cwin.hxx
 *
 * Author: $author$
 *   Date: 4/23/2008
 **********************************************************************
 */
#ifndef _CWIN_HXX
#define _CWIN_HXX

#include "cplatform_windows.h"
#include "cerror.h"

#define CWIN_DEFAULT_WINDOW_STYLE \
    WS_VISIBLE | WS_OVERLAPPED | WS_THICKFRAME | \
    WS_SYSMENU | WS_MINIMIZEBOX | WS_MAXIMIZEBOX

#define CWIN_DEFAULT_WINDOW_EXSTYLE 0

/**
 **********************************************************************
 *  Class: cWinPoint
 *
 * Author: $author$
 *   Date: 4/24/2008
 **********************************************************************
 */
class cWinPoint
: public POINT
{
public:
    typedef POINT cExtends;
    typedef cWinPoint cDerives;
    /**
     **********************************************************************
     * Constructor: cWinPoint
     *
     *      Author: $author$
     *        Date: 4/24/2008
     **********************************************************************
     */
    cWinPoint
    (LONG p_x=0, LONG p_y=0) 
    {
        x = p_x;
        y = p_y;
    }
    /**
     **********************************************************************
     * Constructor: cWinPoint
     *
     *      Author: $author$
     *        Date: 4/24/2008
     **********************************************************************
     */
    cWinPoint
    (const cWinPoint& p) 
    {
        x = p.x;
        y = p.y;
    }
    /**
     **********************************************************************
     * Function: ToClient
     *
     *   Author: $author$
     *     Date: 4/5/2004
     **********************************************************************
     */
    eError ToClient(HWND hwnd)
    {
        if (ScreenToClient(hwnd, this))
            return e_ERROR_NONE;
        return e_ERROR_FAILED;
    }
    /**
     **********************************************************************
     * Function: ToScreen
     *
     *   Author: $author$
     *     Date: 4/5/2004
     **********************************************************************
     */
    eError ToScreen(HWND hwnd)
    {
        if (ClientToScreen(hwnd, this))
            return e_ERROR_NONE;
        return e_ERROR_FAILED;
    }

    /**
     **********************************************************************
     * Operator: =
     *
     *   Author: $author$
     *     Date: 4/5/2004
     **********************************************************************
     */
    cWinPoint &operator = (cWinPoint &point)
    {
        x = point.x;
        y = point.y;
        return *this;
    }
};

/**
 **********************************************************************
 *  Class: cWinRect
 *
 * Author: $author$
 *   Date: 4/24/2008
 **********************************************************************
 */
class cWinRect
: public RECT
{
public:
    typedef RECT cExtends;
    typedef cWinRect cDerives;
    /**
     **********************************************************************
     * Constructor: cWinRect
     *
     *      Author: $author$
     *        Date: 4/24/2008
     **********************************************************************
     */
    cWinRect
    (int p_left=0, int p_top=0, 
     int p_right=0, int p_bottom=0) 
    {
        left = p_left;
        top = p_top;
        right = p_right;
        bottom = p_bottom;
    }
    /**
     **********************************************************************
     * Constructor: cWinRect
     *
     *      Author: $author$
     *        Date: 4/24/2008
     **********************************************************************
     */
    cWinRect
    (const cWinRect &r1) 
    {
        left = r1.left;
        top = r1.top;
        right = r1.right;
        bottom = r1.bottom;
    }
    /**
     **********************************************************************
     * Constructor: cWinRect
     *
     *      Author: $author$
     *        Date: 4/24/2008
     **********************************************************************
     */
    cWinRect
    (const cWinRect &r1, const cWinRect &r2) 
    {
        left = r1.left;
        top = r1.top;
        right = r1.right;
        bottom = r1.bottom;

        if (left > r2.left)
            left = r2.left;

        if (top > r2.top)
            top = r2.top;

        if (right < r2.right)
            right = r2.right;

        if (bottom < r2.bottom)
            bottom = r2.bottom;
    }
    /**
     **********************************************************************
     * Constructor: cWinRect
     *
     *      Author: $author$
     *        Date: 4/24/2008
     **********************************************************************
     */
    cWinRect(HWND window) 
    {
        eError error;
        if (window)
        if ((error = GetWindow(window)))
            throw(error);
    }

    /**
     **********************************************************************
     * Function: ToClient
     *
     *   Author: $author$
     *     Date: 4/12/2004
     **********************************************************************
     */
    eError ToClient(HWND hwnd)
    {
        cWinPoint p1(left, top),p2(right,bottom);

        if (ScreenToClient(hwnd, &p1))
        if (ScreenToClient(hwnd, &p2))
        {
            left = p1.x;
            top =p1.y;
            right = p2.x;
            bottom = p2.y;
            return e_ERROR_NONE;
        }
        return e_ERROR_FAILED;
    }

    /**
     **********************************************************************
     * Function: GetClient
     *
     *   Author: $author$
     *     Date: 4/8/2004
     **********************************************************************
     */
    eError GetClient(HWND hwnd)
    {
        if (GetClientRect(hwnd, this))
            return e_ERROR_NONE;
        return e_ERROR_FAILED;
    }
    /**
     **********************************************************************
     * Function: GetWindow
     *
     *   Author: $author$
     *     Date: 4/5/2004
     **********************************************************************
     */
    eError GetWindow(HWND hwnd)
    {
        if (GetWindowRect(hwnd, this))
            return e_ERROR_NONE;
        return e_ERROR_FAILED;
    }
    /**
     **********************************************************************
     * Function: GetUpdate
     *
     *   Author: $author$
     *     Date: 2/28/2004
     **********************************************************************
     */
    eError GetUpdate(HWND hwnd, BOOL erase=FALSE)
    {
        if (GetUpdateRect(hwnd, this, erase))
            return e_ERROR_NONE;
        return e_ERROR_FAILED;
    }
};

#endif /* _CWIN_HXX */
