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
 *   File: cwinwindow.hxx
 *
 * Author: $author$
 *   Date: 4/28/2008
 **********************************************************************
 */
#ifndef _CWINWINDOW_HXX
#define _CWINWINDOW_HXX

#include "cwinmessagetargetinterface.hxx"
#include "cwinattached.hxx"
#include "cdebug.hxx"

/**
 **********************************************************************
 *  Class: cWinWindow
 *
 * Author: $author$
 *   Date: 4/28/2008
 **********************************************************************
 */
class cWinWindow
: virtual public cWinMessageTargetImplement,
  public cHWNDCreatedAttached
{
public:
    typedef cWinMessageTargetImplement cImplements;
    typedef cHWNDCreatedAttached cExtends;
    typedef cWinWindow cDerives;

    HINSTANCE m_hinstance;

    /**
     **********************************************************************
     * Constructor: cWinWindow
     *
     *      Author: $author$
     *        Date: 4/28/2008
     **********************************************************************
     */
    cWinWindow
    (HINSTANCE hinstance=NULL_HANDLE,
     HWND attached=NULL_HANDLE, 
     bool isCreated=false) 
    : cExtends(attached, isCreated),
      m_hinstance(hinstance)
    {
    }
    /**
     **********************************************************************
     * Destructor: cWinWindow
     *
     *     Author: $author$
     *       Date: 4/28/2008
     **********************************************************************
     */
    virtual ~cWinWindow()
    {
        Destruct();
    }
    /**
     **********************************************************************
     * Function: Create
     *
     *   Author: $author$
     *     Date: 4/29/2008
     **********************************************************************
     */
    virtual eError Create
    (HINSTANCE instance, LPCTSTR classname, 
     LPCTSTR windowname=NULL, HWND parent=NULL_HANDLE, 
     HMENU menu=NULL_HANDLE, DWORD style=CWIN_DEFAULT_WINDOW_STYLE,
     DWORD exstyle=CWIN_DEFAULT_WINDOW_EXSTYLE, 
     int x=CW_USEDEFAULT, int y=CW_USEDEFAULT, 
     int width=CW_USEDEFAULT, int height=CW_USEDEFAULT,
     bool onlyDestroyed=false) 
    {
        eError error = Create
        (classname, windowname, style, exstyle, 
         x, y, width, height, parent, menu, instance, 
         (LPVOID)((cWinMessageTargetInterface*)(this)), onlyDestroyed);
        return error;
    }
    /**
     **********************************************************************
     * Function: Create
     *
     *   Author: $author$
     *     Date: 4/29/2008
     **********************************************************************
     */
    virtual eError Create
    (LPCTSTR classname, LPCTSTR windowname, 
     DWORD style, DWORD exstyle, 
     int x, int y, int width, int height, 
     HWND parent, HMENU menu, 
     HINSTANCE instance, LPVOID param,
     bool onlyDestroyed=false) 
    {
        eError error = e_ERROR_FAILED;
        bool isCreated;
        HWND attached;

        if ((error = Destroyed(onlyDestroyed)))
            return error;

        if (!(isCreated = (NULL_HANDLE != (attached = CreateAttached
            (error, exstyle, classname, windowname, style, 
             x, y, width, height, parent, menu, instance, param)))))
             return error;

        m_isCreated = isCreated;
        m_attached = attached;
        m_hinstance = instance;
        return error;
    }
    /**
     **********************************************************************
     * Function: Destroy
     *
     *   Author: $author$
     *     Date: 10/29/2008
     **********************************************************************
     */
    virtual eError Destroy
    (bool onlyCreated=false) 
    {
        eError error = e_ERROR_NONE;
        HWND attached;
        bool isCreated;

        if ((isCreated = GetIsCreated()))
            SetIsCreated(false);
        else
        if (onlyCreated)
            return e_ERROR_NOT_CREATED;

        if ((error = Detach(attached, onlyCreated)) 
            || !(isCreated = (NULL_HANDLE != attached)))
            return error;

        error = DestroyAttached(attached);
        return error;
    }
    /**
     **********************************************************************
     * Function: Detach
     *
     *   Author: $author$
     *     Date: 4/29/2008
     **********************************************************************
     */
    virtual eError Detach
    (HWND& attached, bool onlyAttached=false) 
    {
        eError error = cExtends::Detach(attached, onlyAttached);
        m_hinstance = NULL_HANDLE;
        return error;
    }

    /**
     **********************************************************************
     * Function: CreateAttached
     *
     *   Author: $author$
     *     Date: 10/29/2008
     **********************************************************************
     */
    virtual HWND CreateAttached
    (eError& error,
     DWORD exstyle, LPCTSTR classname, 
     LPCTSTR windowname, DWORD style, 
     int x, int y, int width, int height, 
     HWND parent, HMENU menu, 
     HINSTANCE instance, LPVOID param) const
    {
        HWND attached = NULL_HANDLE;

        error = e_ERROR_FAILED;

        if (NULL_HANDLE == (attached = CreateWindowEx
            (exstyle, classname, windowname, style, 
             x, y, width, height, parent, menu, instance, param)))
            DBE("() failed on CreateWindowEx()\n");
        else
        error = e_ERROR_NONE;
        return attached;
    }
    /**
     **********************************************************************
     * Function: DestroyAttached
     *
     *   Author: $author$
     *     Date: 4/29/2008
     **********************************************************************
     */
    virtual eError DestroyAttached(HWND attached) const
    {
        eError error = e_ERROR_FAILED;
        if (DestroyWindow(attached))
            error = e_ERROR_NONE;
        else
        DBE("() failed on DestroyWindow()\n");
        return error;
    }

    /**
     **********************************************************************
     * Function: SetMenu
     *
     *   Author: $author$
     *     Date: 10/31/2008
     **********************************************************************
     */
    virtual eError SetMenu(HMENU hMenu) 
    {
        eError error = e_ERROR_NOT_ATTACHED;
        HWND attached;
        if (NULL_HANDLE != (attached = GetAttached()))
        if (::SetMenu(attached, hMenu))
            error = e_ERROR_NONE;
        else
        error = e_ERROR_FAILED;
        return error;
    }
    /**
     **********************************************************************
     * Function: GetMenu
     *
     *   Author: $author$
     *     Date: 10/31/2008
     **********************************************************************
     */
    virtual HMENU GetMenu(eError& error) const 
    {
        HMENU hMenu = NULL_HANDLE;
        HWND attached;
        error = e_ERROR_NOT_ATTACHED;
        if (NULL_HANDLE != (attached = GetAttached()))
        if (NULL_HANDLE != (hMenu = ::GetMenu(attached)))
            error = e_ERROR_NONE;
        else
        error = e_ERROR_FAILED;
        return hMenu;
    }

    /**
     **********************************************************************
     * Function: On_WM_NCCREATE_Message
     *
     *   Author: $author$
     *     Date: 10/29/2008
     **********************************************************************
     */
    virtual LRESULT On_WM_NCCREATE_Message
    (HWND hWnd,
     UINT msg,
     WPARAM wParam,
     LPARAM lParam) 
    {
        LRESULT lResult;
        if (hWnd != m_attached)
            m_attached = hWnd;
        lResult = OnWindowMessageDefault
        (hWnd,msg,wParam,lParam);
        return lResult;
    }
    /**
     **********************************************************************
     * Function: On_WM_NCDESTROY_Message
     *
     *   Author: $author$
     *     Date: 10/29/2008
     **********************************************************************
     */
    virtual LRESULT On_WM_NCDESTROY_Message
    (HWND hWnd,
     UINT msg,
     WPARAM wParam,
     LPARAM lParam) 
    {
        LRESULT lResult;
        lResult = OnWindowMessageDefault
        (hWnd,msg,wParam,lParam);
        if (hWnd == m_attached)
            m_attached = NULL_HANDLE;
        return lResult;
    }

    /**
     **********************************************************************
     * Function: On_WM_CREATE_Message
     *
     *   Author: $author$
     *     Date: 10/29/2008
     **********************************************************************
     */
    virtual LRESULT On_WM_CREATE_Message
    (HWND hWnd,
     UINT msg,
     WPARAM wParam,
     LPARAM lParam) 
    {
        LRESULT lResult;
#if defined(_WIN32_WCE)
        if (hWnd != m_attached)
            m_attached = hWnd;
#else /* defined(_WIN32_WCE) */
#endif /* defined(_WIN32_WCE) */
        lResult = OnWindowMessageDefault
        (hWnd,msg,wParam,lParam);
        return lResult;
    }
    /**
     **********************************************************************
     * Function: On_WM_DESTROY_Message
     *
     *   Author: $author$
     *     Date: 10/29/2008
     **********************************************************************
     */
    virtual LRESULT On_WM_DESTROY_Message
    (HWND hWnd,
     UINT msg,
     WPARAM wParam,
     LPARAM lParam) 
    {
        LRESULT lResult;
        lResult = OnWindowMessageDefault
        (hWnd,msg,wParam,lParam);
#if defined(_WIN32_WCE)
        if (m_hWnd == m_attached)
            m_attached = NULL_HANDLE;
#else /* defined(_WIN32_WCE) */
#endif /* defined(_WIN32_WCE) */
        return lResult;
    }

    /**
     **********************************************************************
     * Function: WindowProc
     *
     *   Author: $author$
     *     Date: 10/28/2008
     **********************************************************************
     */
    static LRESULT CALLBACK WindowProc
    (HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) 
    {
        LRESULT lResult;
        LPVOID userData;
        CREATESTRUCT *cs;
        cWinMessageTargetInterface* target;

#if defined(WIN32_MSC_VER_8)
#pragma warning(push)
#pragma warning(disable:4312)
#endif /* defined(WIN32_MSC_VER_8) */

        if ((target = (cWinMessageTargetInterface*)
            (GetWindowLongPtr(hWnd, GWLP_USERDATA))))
        {
            lResult = target->OnWindowMessage(hWnd, msg, wParam, lParam);
            return lResult;
        }

        switch(msg)
        {
#if defined(_WIN32_WCE)
        case WM_CREATE:
#else /* defined(_WIN32_WCE) */
        case WM_NCCREATE:
#endif /* defined(_WIN32_WCE) */
            if ((cs = (CREATESTRUCT*)(lParam)))
            if ((target = (cWinMessageTargetInterface*)
                (userData = cs->lpCreateParams)))
            {
                SetWindowLongPtr(hWnd, GWLP_USERDATA, (LONG)(LONG_PTR)(userData));
                lResult = target->OnWindowMessage(hWnd, msg, wParam, lParam);
                return lResult;
            }
            break;
        }

#if defined(WIN32_MSC_VER_8)
#pragma warning(pop)
#endif /* defined(WIN32_MSC_VER_8) */

        return DefWindowProc(hWnd, msg, wParam, lParam);
    }
};
#endif /* _CWINWINDOW_HXX */
