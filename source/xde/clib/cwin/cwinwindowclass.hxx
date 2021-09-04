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
 *   File: cwinwindowclass.hxx
 *
 * Author: $author$
 *   Date: 4/30/2008
 **********************************************************************
 */
#ifndef _CWINWINDOWCLASS_HXX
#define _CWINWINDOWCLASS_HXX

#include "cwinatom.hxx"
#include "cstring.hxx"

#if defined(_WIN32_WCE) 
typedef WNDCLASS TWNDCLASS;
#else /* defined(_WIN32_WCE) */
typedef WNDCLASSEX TWNDCLASS;
#endif /* defined(_WIN32_WCE) */

/**
 **********************************************************************
 *  Class: cWinWindowClassInterface
 *
 * Author: $author$
 *   Date: 4/30/2008
 **********************************************************************
 */
class c_INTERFACE_CLASS cWinWindowClassInterface
: virtual public cWinAtomInterface
{
public:
    typedef cWinAtomInterface cImplements;
    typedef cWinWindowClassInterface cDerives;
};

/**
 **********************************************************************
 *  Class: cWinWindowClass
 *
 * Author: $author$
 *   Date: 4/30/2008
 **********************************************************************
 */
class cWinWindowClass
: virtual public cWinWindowClassInterface,
  public cWinAtom
{
public:
    typedef cWinWindowClassInterface cImplements;
    typedef cWinAtom cExtends;
    typedef cWinWindowClass cDerives;

    bool m_isRegistered;
    TWNDCLASS m_wndClass;
    LPCTSTR m_wndClassNameChars;
    cTCHARString m_wndClassName;

    /**
     **********************************************************************
     * Constructor: cWinWindowClass
     *
     *      Author: $author$
     *        Date: 4/30/2008
     **********************************************************************
     */
    cWinWindowClass
    (ATOM attached=NULL_ATOM,
     bool isRegistered=false,
     bool isCreated=false) 
    : cExtends(attached, isCreated),
      m_isRegistered(m_isRegistered),
      m_wndClassNameChars(0)
    {
        memset(&m_wndClass, 0, sizeof(m_wndClass));
    }
    /**
     **********************************************************************
     * Destructor: cWinWindowClass
     *
     *     Author: $author$
     *       Date: 4/30/2008
     **********************************************************************
     */
    virtual ~cWinWindowClass()
    {
        Destruct();
    }

    /**
     **********************************************************************
     * Function: Register
     *
     *   Author: $author$
     *     Date: 4/30/2008
     **********************************************************************
     */
    virtual eError Register
    (LPCTSTR classname, HINSTANCE instance, WNDPROC wndproc=NULL,
     LPCTSTR menuname=NULL, HICON icon=NULL, HICON iconsm=NULL,
     HCURSOR cursor=NULL, HBRUSH background=NULL, UINT style=0,
     int wndextra=0, int clsextra=0,
     bool onlyUnregistered=false) 
    {
        eError error = e_ERROR_FAILED;
        ATOM attached;
        bool isRegistered;

        if ((isRegistered = GetIsRegistered()))
        if (onlyUnregistered)
            return e_ERROR_ALREADY_CREATED;
        else
        if ((error = Unregister(isRegistered)))
            return error;

        if ((isRegistered = (NULL_ATOM != (attached = Attached()))))
        if (onlyUnregistered)
            return e_ERROR_ALREADY_ATTACHED;
        else 
        if ((error = Detach(attached, isRegistered)))
            return error;

#if defined(_WIN32_WCE) 
#else /* defined(_WIN32_WCE) */
        m_wndClass.cbSize = sizeof(m_wndClass);
#endif /* defined(_WIN32_WCE) */
        m_wndClass.lpszClassName = classname;
        m_wndClass.cbClsExtra = clsextra;
        m_wndClass.cbWndExtra = wndextra;

        if (NULL != menuname)
            m_wndClass.lpszMenuName = menuname;

        if (NULL != icon)
            m_wndClass.hIcon = icon;

#if defined(_WIN32_WCE) 
#else /* defined(_WIN32_WCE) */
        if (NULL != iconsm)
            m_wndClass.hIconSm = iconsm;
#endif /* defined(_WIN32_WCE) */

        if (NULL != cursor)
            m_wndClass.hCursor = cursor;

        else if (NULL == m_wndClass.hCursor)
                m_wndClass.hCursor = GetDefaultCursor();

        if (NULL != background)
            m_wndClass.hbrBackground = background;

        else if (NULL == m_wndClass.hbrBackground)
                m_wndClass.hbrBackground = GetDefaultBackground();

        if (NULL != wndproc)
            m_wndClass.lpfnWndProc = wndproc;

        else if (NULL == m_wndClass.lpfnWndProc)
                m_wndClass.lpfnWndProc = GetDefaultWindowProc();

        m_wndClass.style = style;
        m_wndClass.hInstance = instance;

        if ((isRegistered = NULL_ATOM 
            != (attached = Register(m_wndClass))))
        {
            m_isRegistered = isRegistered;
            m_attached = attached;
            error = e_ERROR_NONE;
        }
        return error;
    }
    /**
     **********************************************************************
     * Function: Unregister
     *
     *   Author: $author$
     *     Date: 4/30/2008
     **********************************************************************
     */
    virtual eError Unregister
    (bool onlyRegistered=false) 
    {
        eError error = e_ERROR_FAILED;
        ATOM attached;
        bool isRegistered;

        if ((isRegistered = GetIsRegistered()))
            SetIsRegistered(false);
        else
        if (onlyRegistered)
            return e_ERROR_NOT_CREATED;

        if ((error = Detach(attached, onlyRegistered)) 
            || !(isRegistered = (NULL_ATOM != attached)))
            return error;

        error = Unregister
        (m_wndClass.lpszClassName, m_wndClass.hInstance);
        return error;
    }

    /**
     **********************************************************************
     * Function: SetIsRegistered
     *
     *   Author: $author$
     *     Date: 10/28/2008
     **********************************************************************
     */
    virtual bool SetIsRegistered
    (bool isRegistered=true) 
    {
        m_isRegistered = isRegistered;
        return m_isRegistered;
    }
    /**
     **********************************************************************
     * Function: GetIsRegistered
     *
     *   Author: $author$
     *     Date: 10/28/2008
     **********************************************************************
     */
    virtual bool GetIsRegistered() const 
    {
        bool isRegistered = m_isRegistered;
        return isRegistered;
    }

    /**
     **********************************************************************
     * Function: Register
     *
     *   Author: $author$
     *     Date: 10/28/2008
     **********************************************************************
     */
    virtual ATOM Register
    (TWNDCLASS& wndClass) const
    {
        ATOM attached;
#if defined(_WIN32_WCE) 
        if (!(NULL_ATOM != (attached = RegisterClass(&wndClass))))
#else /* defined(_WIN32_WCE) */
        if (!(NULL_ATOM != (attached = RegisterClassEx(&wndClass))))
#endif /* defined(_WIN32_WCE) */
            DBE("() failed on RegisterClass()\n");
        return attached;
    }
    /**
     **********************************************************************
     * Function: Unregister
     *
     *   Author: $author$
     *     Date: 4/30/2008
     **********************************************************************
     */
    virtual eError Unregister
    (LPCTSTR wndClassNameChars, 
     HINSTANCE wndClassHInstance) const
    {
        eError error = e_ERROR_FAILED;
        if (UnregisterClass(wndClassNameChars, wndClassHInstance))
            return e_ERROR_NONE;
        else
        DBE("() failed on UnregisterClass()\n");
        return error;
    }


    /**
     **********************************************************************
     * Function: GetDefaultCursor
     *
     *   Author: $author$
     *     Date: 6/6/2007
     **********************************************************************
     */
    virtual HCURSOR GetDefaultCursor() const 
    {
        HCURSOR handle = LoadCursor(NULL, IDC_ARROW);
        return handle;
    }
    /**
     **********************************************************************
     * Function: GetDefaultBackground
     *
     *   Author: $author$
     *     Date: 6/6/2007
     **********************************************************************
     */
    virtual HBRUSH GetDefaultBackground() const 
    {
        HBRUSH handle = (HBRUSH)GetStockObject(WHITE_BRUSH);
        return handle;
    }
    /**
     **********************************************************************
     * Function: GetDefaultWindowProc
     *
     *   Author: $author$
     *     Date: 6/6/2007
     **********************************************************************
     */
    virtual WNDPROC GetDefaultWindowProc() const 
    {
        WNDPROC wndproc = DefWindowProc;
        return wndproc;
    }
};
#endif /* _CWINWINDOWCLASS_HXX */
