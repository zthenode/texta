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
 *   File: cwinmessagetargetinterface.hxx
 *
 * Author: $author$
 *   Date: 5/30/2008
 **********************************************************************
 */
#ifndef _CWINMESSAGETARGETINTERFACE_HXX
#define _CWINMESSAGETARGETINTERFACE_HXX

#include "cinterfacebase.hxx"
#include "cwin.hxx"

/**
 **********************************************************************
 *  Class: cWinMessageTargetInterface
 *
 * Author: $author$
 *   Date: 5/30/2008
 **********************************************************************
 */
class c_INTERFACE_CLASS cWinMessageTargetInterface
: virtual public cInterfaceBase
{
public:
    typedef cInterfaceBase cImplements;
    typedef cWinMessageTargetInterface cDerives;
    /**
     **********************************************************************
     * Function: OnWindowMessage
     *
     *   Author: $author$
     *     Date: 5/30/2008
     **********************************************************************
     */
    virtual LRESULT OnWindowMessage
    (HWND hWnd,
     UINT msg,
     WPARAM wParam,
     LPARAM lParam) = 0;

    /**
     **********************************************************************
     * Function: On_WM_NCCREATE_Message
     *
     *   Author: $author$
     *     Date: 5/30/2008
     **********************************************************************
     */
    virtual LRESULT On_WM_NCCREATE_Message
    (HWND hWnd,
     UINT msg,
     WPARAM wParam,
     LPARAM lParam) = 0;
    /**
     **********************************************************************
     * Function: On_WM_NCDESTROY_Message
     *
     *   Author: $author$
     *     Date: 5/30/2008
     **********************************************************************
     */
    virtual LRESULT On_WM_NCDESTROY_Message
    (HWND hWnd,
     UINT msg,
     WPARAM wParam,
     LPARAM lParam) = 0;
    /**
     **********************************************************************
     * Function: On_WM_CREATE_Message
     *
     *   Author: $author$
     *     Date: 5/30/2008
     **********************************************************************
     */
    virtual LRESULT On_WM_CREATE_Message
    (HWND hWnd,
     UINT msg,
     WPARAM wParam,
     LPARAM lParam) = 0;
    /**
     **********************************************************************
     * Function: On_WM_DESTROY_Message
     *
     *   Author: $author$
     *     Date: 5/30/2008
     **********************************************************************
     */
    virtual LRESULT On_WM_DESTROY_Message
    (HWND hWnd,
     UINT msg,
     WPARAM wParam,
     LPARAM lParam) = 0;

    /**
     **********************************************************************
     * Function: On_WM_NCCALCSIZE_Message
     *
     *   Author: $author$
     *     Date: 5/4/2009
     **********************************************************************
     */
    virtual LRESULT On_WM_NCCALCSIZE_Message
    (HWND hWnd,
     UINT msg,
     WPARAM wParam,
     LPARAM lParam) = 0;
    /**
     **********************************************************************
     * Function: On_WM_NCPAINT_Message
     *
     *   Author: $author$
     *     Date: 5/30/2008
     **********************************************************************
     */
    virtual LRESULT On_WM_NCPAINT_Message
    (HWND hWnd,
     UINT msg,
     WPARAM wParam,
     LPARAM lParam) = 0;
    /**
     **********************************************************************
     * Function: On_WM_PAINT_Message
     *
     *   Author: $author$
     *     Date: 5/30/2008
     **********************************************************************
     */
    virtual LRESULT On_WM_PAINT_Message
    (HWND hWnd,
     UINT msg,
     WPARAM wParam,
     LPARAM lParam) = 0;

    /**
     **********************************************************************
     * Function: On_WM_COMMAND_Message
     *
     *   Author: $author$
     *     Date: 10/29/2008
     **********************************************************************
     */
    virtual LRESULT On_WM_COMMAND_Message
    (HWND hWnd,
     UINT msg,
     WPARAM wParam,
     LPARAM lParam) = 0;
    /**
     **********************************************************************
     * Function: On_WM_NOTIFY_Message
     *
     *   Author: $author$
     *     Date: 10/29/2008
     **********************************************************************
     */
    virtual LRESULT On_WM_NOTIFY_Message
    (HWND hWnd,
     UINT msg,
     WPARAM wParam,
     LPARAM lParam) = 0;
    /**
     **********************************************************************
     * Function: On_WM_SIZE_Message
     *
     *   Author: $author$
     *     Date: 10/29/2008
     **********************************************************************
     */
    virtual LRESULT On_WM_SIZE_Message
    (HWND hWnd,
     UINT msg,
     WPARAM wParam,
     LPARAM lParam) = 0;
    /**
     **********************************************************************
     * Function: On_WM_CLOSE_Message
     *
     *   Author: $author$
     *     Date: 10/29/2008
     **********************************************************************
     */
    virtual LRESULT On_WM_CLOSE_Message
    (HWND hWnd,
     UINT msg,
     WPARAM wParam,
     LPARAM lParam) = 0;

    /**
     **********************************************************************
     * Function: OnWindowMessageDefault
     *
     *   Author: $author$
     *     Date: 5/30/2008
     **********************************************************************
     */
    virtual LRESULT OnWindowMessageDefault
    (HWND hWnd,
     UINT msg,
     WPARAM wParam,
     LPARAM lParam) = 0;
};

/**
 **********************************************************************
 *  Class: cWinMessageTargetImplement
 *
 * Author: $author$
 *   Date: 5/30/2008
 **********************************************************************
 */
class cWinMessageTargetImplement
: virtual public cWinMessageTargetInterface
{
public:
    typedef cWinMessageTargetInterface cImplements;
    typedef cWinMessageTargetImplement cDerives;
    /**
     **********************************************************************
     * Function: OnWindowMessage
     *
     *   Author: $author$
     *     Date: 5/30/2008
     **********************************************************************
     */
    virtual LRESULT OnWindowMessage
    (HWND hWnd,
     UINT msg,
     WPARAM wParam,
     LPARAM lParam) 
    {
        LRESULT lResult;
        
        switch(msg)
        {
        case WM_NCCREATE:
            lResult = On_WM_NCCREATE_Message
            (hWnd, msg, wParam, lParam);
            break;
        case WM_NCDESTROY:
            lResult = On_WM_NCDESTROY_Message
            (hWnd, msg, wParam, lParam);
            break;

        case WM_CREATE:
            lResult = On_WM_CREATE_Message
            (hWnd, msg, wParam, lParam);
            break;
        case WM_DESTROY:
            lResult = On_WM_DESTROY_Message
            (hWnd, msg, wParam, lParam);
            break;

        case WM_NCCALCSIZE:
            lResult = On_WM_NCCALCSIZE_Message
            (hWnd, msg, wParam, lParam);
            break;
        case WM_NCPAINT:
            lResult = On_WM_NCPAINT_Message
            (hWnd, msg, wParam, lParam);
            break;
        case WM_PAINT:
            lResult = On_WM_PAINT_Message
            (hWnd, msg, wParam, lParam);
            break;

        case WM_COMMAND:
            lResult = On_WM_COMMAND_Message
            (hWnd, msg, wParam, lParam);
            break;
        case WM_NOTIFY:
            lResult = On_WM_NOTIFY_Message
            (hWnd, msg, wParam, lParam);
            break;
        case WM_SIZE:
            lResult = On_WM_SIZE_Message
            (hWnd, msg, wParam, lParam);
            break;
        case WM_CLOSE:
            lResult = On_WM_CLOSE_Message
            (hWnd, msg, wParam, lParam);
            break;

        default:
            lResult = OnWindowMessageDefault
            (hWnd, msg, wParam, lParam);
        }
        return lResult;
    }
    /**
     **********************************************************************
     * Function: On_WM_NCCREATE_Message
     *
     *   Author: $author$
     *     Date: 5/30/2008
     **********************************************************************
     */
    virtual LRESULT On_WM_NCCREATE_Message
    (HWND hWnd,
     UINT msg,
     WPARAM wParam,
     LPARAM lParam) 
    {
        LRESULT lResult = OnWindowMessageDefault
        (hWnd,msg,wParam,lParam);
        return lResult;
    }
    /**
     **********************************************************************
     * Function: On_WM_NCDESTROY_Message
     *
     *   Author: $author$
     *     Date: 5/30/2008
     **********************************************************************
     */
    virtual LRESULT On_WM_NCDESTROY_Message
    (HWND hWnd,
     UINT msg,
     WPARAM wParam,
     LPARAM lParam) 
    {
        LRESULT lResult = OnWindowMessageDefault
        (hWnd,msg,wParam,lParam);
        return lResult;
    }
    /**
     **********************************************************************
     * Function: On_WM_CREATE_Message
     *
     *   Author: $author$
     *     Date: 5/30/2008
     **********************************************************************
     */
    virtual LRESULT On_WM_CREATE_Message
    (HWND hWnd,
     UINT msg,
     WPARAM wParam,
     LPARAM lParam) 
    {
        LRESULT lResult = OnWindowMessageDefault
        (hWnd,msg,wParam,lParam);
        return lResult;
    }
    /**
     **********************************************************************
     * Function: On_WM_DESTROY_Message
     *
     *   Author: $author$
     *     Date: 5/30/2008
     **********************************************************************
     */
    virtual LRESULT On_WM_DESTROY_Message
    (HWND hWnd,
     UINT msg,
     WPARAM wParam,
     LPARAM lParam) 
    {
        LRESULT lResult = OnWindowMessageDefault
        (hWnd,msg,wParam,lParam);
        return lResult;
    }

    /**
     **********************************************************************
     * Function: On_WM_NCCALCSIZE_Message
     *
     *   Author: $author$
     *     Date: 5/4/2009
     **********************************************************************
     */
    virtual LRESULT On_WM_NCCALCSIZE_Message
    (HWND hWnd,
     UINT msg,
     WPARAM wParam,
     LPARAM lParam)
    {
        LRESULT lResult = OnWindowMessageDefault
        (hWnd,msg,wParam,lParam);
        return lResult;
    }
    /**
     **********************************************************************
     * Function: On_WM_NCPAINT_Message
     *
     *   Author: $author$
     *     Date: 5/30/2008
     **********************************************************************
     */
    virtual LRESULT On_WM_NCPAINT_Message
    (HWND hWnd,
     UINT msg,
     WPARAM wParam,
     LPARAM lParam) 
    {
        LRESULT lResult = OnWindowMessageDefault
        (hWnd,msg,wParam,lParam);
        return lResult;
    }
    /**
     **********************************************************************
     * Function: On_WM_PAINT_Message
     *
     *   Author: $author$
     *     Date: 5/30/2008
     **********************************************************************
     */
    virtual LRESULT On_WM_PAINT_Message
    (HWND hWnd,
     UINT msg,
     WPARAM wParam,
     LPARAM lParam) 
    {
        LRESULT lResult = OnWindowMessageDefault
        (hWnd,msg,wParam,lParam);
        return lResult;
    }

    /**
     **********************************************************************
     * Function: On_WM_COMMAND_Message
     *
     *   Author: $author$
     *     Date: 10/29/2008
     **********************************************************************
     */
    virtual LRESULT On_WM_COMMAND_Message
    (HWND hWnd,
     UINT msg,
     WPARAM wParam,
     LPARAM lParam) 
    {
        LRESULT lResult = OnWindowMessageDefault
        (hWnd,msg,wParam,lParam);
        return lResult;
    }
    /**
     **********************************************************************
     * Function: On_WM_NOTIFY_Message
     *
     *   Author: $author$
     *     Date: 10/29/2008
     **********************************************************************
     */
    virtual LRESULT On_WM_NOTIFY_Message
    (HWND hWnd,
     UINT msg,
     WPARAM wParam,
     LPARAM lParam) 
    {
        LRESULT lResult = OnWindowMessageDefault
        (hWnd,msg,wParam,lParam);
        return lResult;
    }
    /**
     **********************************************************************
     * Function: On_WM_SIZE_Message
     *
     *   Author: $author$
     *     Date: 10/29/2008
     **********************************************************************
     */
    virtual LRESULT On_WM_SIZE_Message
    (HWND hWnd,
     UINT msg,
     WPARAM wParam,
     LPARAM lParam) 
    {
        LRESULT lResult = OnWindowMessageDefault
        (hWnd,msg,wParam,lParam);
        return lResult;
    }
    /**
     **********************************************************************
     * Function: On_WM_CLOSE_Message
     *
     *   Author: $author$
     *     Date: 10/29/2008
     **********************************************************************
     */
    virtual LRESULT On_WM_CLOSE_Message
    (HWND hWnd,
     UINT msg,
     WPARAM wParam,
     LPARAM lParam) 
    {
        LRESULT lResult = OnWindowMessageDefault
        (hWnd,msg,wParam,lParam);
        return lResult;
    }

    /**
     **********************************************************************
     * Function: OnWindowMessageDefault
     *
     *   Author: $author$
     *     Date: 5/30/2008
     **********************************************************************
     */
    virtual LRESULT OnWindowMessageDefault
    (HWND hWnd,
     UINT msg,
     WPARAM wParam,
     LPARAM lParam) 
    {
        LRESULT lResult = DefWindowProc
        (hWnd, msg, wParam, lParam);
        return lResult;
    }
};

#endif /* _CWINMESSAGETARGETINTERFACE_HXX */
