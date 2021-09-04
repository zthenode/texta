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
 *   File: cwinmessagetargetwindow.hxx
 *
 * Author: $author$
 *   Date: 5/30/2008
 **********************************************************************
 */
#ifndef _CWINMESSAGETARGETWINDOW_HXX
#define _CWINMESSAGETARGETWINDOW_HXX

#include "cwinmessagetargetinterface.hxx"
#include "cwinattached.hxx"

/**
 **********************************************************************
 *  Class: cWinMessageTargetWindow
 *
 * Author: $author$
 *   Date: 5/30/2008
 **********************************************************************
 */
class cWinMessageTargetWindow
: virtual public cWinMessageTargetImplement,
  public cHWNDAttached
{
public:
    typedef cWinMessageTargetImplement cImplements;
    typedef cHWNDAttached cExtends;
    typedef cWinMessageTargetWindow cDerives;

    WNDPROC m_superWindowProc;
	LONG_PTR m_superWindowLong;

    /**
     **********************************************************************
     * Constructor: cWinMessageTargetWindow
     *
     *      Author: $author$
     *        Date: 5/30/2008
     **********************************************************************
     */
    cWinMessageTargetWindow
    (HWND attached=NULL_HANDLE) 
    : cExtends(attached),
      m_superWindowProc(0),
      m_superWindowLong(0)
    {
    }
    /**
     **********************************************************************
     * Destructor: ~cWinMessageTargetWindow
     *
     *     Author: $author$
     *       Date: 5/30/2008
     **********************************************************************
     */
    virtual ~cWinMessageTargetWindow()
    {
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
        LRESULT lResult = cImplements::On_WM_NCDESTROY_Message
        (hWnd,msg,wParam,lParam);

        if (NULL != m_superWindowProc)
            Superclass(hWnd);
        return lResult;
    }

    /**
     **********************************************************************
     * Function: Subclass
     *
     *   Author: $author$
     *     Date: 5/30/2008
     **********************************************************************
     */
    virtual eError Subclass
    (HWND hWnd, 
     WNDPROC subWindowProc=SubWindowProc,
     bool onlyUnattached=false) 
    {
        eError error = e_ERROR_NONE;
        HWND attached;

        if (NULL_HANDLE != m_attached)
        if (onlyUnattached)
            return e_ERROR_ALREADY_ATTACHED;
        else
        if (NULL != m_superWindowProc)
        {
            if ((error = Superclass(hWnd, true)))
                return error;
        }
        else
        if ((error = Detach(attached, true)))
            return error;

        if (NULL_HANDLE == (m_attached = hWnd))
            return e_ERROR_NOT_ATTACHED;

#if defined(WIN32_MSC_VER_8)
#pragma warning(push)
#pragma warning(disable:4244 4312)
#endif /* defined(WIN32_MSC_VER_8) */

        m_superWindowLong = SetWindowLongPtr
        (hWnd, GWLP_USERDATA, 
         (LONG_PTR)((cWinMessageTargetInterface*)(this)));

        if (NULL == (m_superWindowProc = 
            SubclassWindow(hWnd, subWindowProc)))
        {
            SetWindowLongPtr
            (hWnd, GWLP_USERDATA, m_superWindowLong);
            m_attached = NULL_HANDLE;
            return e_ERROR_FAILED;
        }

#if defined(WIN32_MSC_VER_8)
#pragma warning(pop)
#endif /* defined(WIN32_MSC_VER_8) */
        return error;
    }
    /**
     **********************************************************************
     * Function: Superclass
     *
     *   Author: $author$
     *     Date: 5/30/2008
     **********************************************************************
     */
    virtual eError Superclass
    (HWND hWnd, 
     bool onlyAttached=false) 
    {
        eError error = e_ERROR_NONE;

        if ((NULL_HANDLE == m_attached) || (m_attached != hWnd))
        if (onlyAttached)
            return e_ERROR_NOT_ATTACHED;
        else return e_ERROR_NONE;

        if (NULL == m_superWindowProc)
        if (onlyAttached)
            return e_ERROR_NOT_ATTACHED;
        else return e_ERROR_NONE;

#if defined(WIN32_MSC_VER_8)
#pragma warning(push)
#pragma warning(disable:4244 4312)
#endif /* defined(WIN32_MSC_VER_8) */

        SubclassWindow(m_attached, m_superWindowProc);
        SetWindowLongPtr(m_attached, GWLP_USERDATA, m_superWindowLong);
        m_attached = NULL_HANDLE;

#if defined(WIN32_MSC_VER_8)
#pragma warning(pop)
#endif /* defined(WIN32_MSC_VER_8) */
        return error;
    }
    /**
     **********************************************************************
     * Function: SubWindowProc
     *
     *   Author: $author$
     *     Date: 5/31/2008
     **********************************************************************
     */
    static LRESULT CALLBACK SubWindowProc
    (HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) 
    {
        LRESULT lResult;
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

#if defined(WIN32_MSC_VER_8)
#pragma warning(pop)
#endif /* defined(WIN32_MSC_VER_8) */

        return DefWindowProc(hWnd, msg, wParam, lParam);
    }
};
#endif /* _CWINMESSAGETARGETWINDOW_HXX */
