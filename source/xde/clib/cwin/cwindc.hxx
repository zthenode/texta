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
 *   File: cwindc.hxx
 *
 * Author: $author$
 *   Date: 4/23/2008
 **********************************************************************
 */
#ifndef _CWINDC_HXX
#define _CWINDC_HXX

#include "cwinattached.hxx"
#include "cdebug.hxx"

/**
 **********************************************************************
 *  Class: cWinDC
 *
 * Author: $author$
 *   Date: 4/23/2008
 **********************************************************************
 */
class cWinDC
: public cHDCCreatedAttached
{
public:
    typedef cHDCCreatedAttached cExtends;
    typedef cWinDC cDerives;

    HWND m_hwnd;

    /**
     **********************************************************************
     * Constructor: cWinDC
     *
     *      Author: $author$
     *        Date: 4/23/2008
     **********************************************************************
     */
    cWinDC
    (HDC attached=NULL, bool isCreated=false)
    : cExtends(attached,isCreated),
      m_hwnd(NULL)
    {
    }
    /**
     **********************************************************************
     * Constructor: cWinDC
     *
     *      Author: $author$
     *        Date: 4/23/2008
     **********************************************************************
     */
    cWinDC
    (HDC attached, HWND hwnd, bool isCreated=false)
    : cExtends(attached,isCreated),
      m_hwnd(hwnd)
    {
    }
    /**
     **********************************************************************
     * Destructor: cWinDC
     *
     *     Author: $author$
     *       Date: 4/23/2008
     **********************************************************************
     */
    virtual ~cWinDC()
    {
        eError error;
        HDC attached;
        HWND gotten;
        bool is;

        if ((is = (NULL != (gotten = GetHWND()))))
        if ((error = Release(gotten,is)))
            throw(error);

        if ((is = GetIsCreated()))
        if ((error = Destroy(is)))
            throw(error);

        if ((is = (NULL != (attached = Attached()))))
        if ((error = Detach(attached,is)))
            throw(error);
    }

    /**
     **********************************************************************
     * Function: FillRect
     *
     *   Author: $author$
     *     Date: 4/24/2008
     **********************************************************************
     */
    virtual eError FillRect
    (int left, int top, int right, int bottom, HBRUSH hbrush) 
    {
        cWinRect rect(left, top, right, bottom);
        eError error = e_ERROR_FAILED;

        if (!(NULL != (m_attached)))
            return e_ERROR_NOT_ATTACHED;

        if (::FillRect(m_attached, &rect, hbrush))
            error = e_ERROR_NONE;
        else
        DBE("() failed on FillRect()\n");
        return error;
    }
    /**
     **********************************************************************
     * Function: BitBlt
     *
     *   Author: $author$
     *     Date: 4/24/2008
     **********************************************************************
     */
    virtual eError BitBlt
    (int x, int y, int width, int height, 
     HDC hdc, int dc_x, int dc_y, DWORD rop=SRCCOPY) 
    {
        eError error = e_ERROR_FAILED;
        if (!(NULL != (m_attached)))
            return e_ERROR_NOT_ATTACHED;

        if (::BitBlt
            (m_attached, x, y, width, height, 
             hdc, dc_x, dc_y, rop))
            error = e_ERROR_NONE;
        else
        DBE("() failed on BitBlt()\n");
        return error;
    }

    /**
     **********************************************************************
     * Function: Create
     *
     *   Author: $author$
     *     Date: 4/23/2008
     **********************************************************************
     */
    virtual eError Create
    (HWND hwnd, bool onlyDestroyed=false) 
    {
        eError error = e_ERROR_NOT_IMPLEMENTED;
        HDC hdc;
        HDC attached;
        HWND gotten;
        bool is;

        if ((is = (NULL != (gotten = GetHWND()))))
        if (onlyDestroyed)
            return e_ERROR_ALREADY_CREATED;
        else
        if ((error = Release(gotten,is)))
            return(error);

        if ((is = GetIsCreated()))
        if (onlyDestroyed)
            return e_ERROR_ALREADY_CREATED;
        else
        if ((error = Destroy(is)))
            return(error);

        if ((is = (NULL != (attached = Attached()))))
        if (onlyDestroyed)
            return e_ERROR_ALREADY_ATTACHED;
        else
        if ((error = Detach(attached,is)))
            return(error);

        if (!(is = (NULL != (hdc = GetDC(hwnd)))))
            DBE("() failed on GetDC()\n");
        else
        {
            if (!(is = (NULL != (attached = CreateCompatibleDC(hdc)))))
                DBE("() failed on CreateCompatibleDC()\n");
            else
            if ((error = Attach(attached, is)))
                DeleteDC(attached);

            ReleaseDC(hwnd, hdc);
        }
        return error;
    }
    /**
     **********************************************************************
     * Function: Create
     *
     *   Author: $author$
     *     Date: 4/23/2008
     **********************************************************************
     */
    virtual eError Create
    (HDC hdc, bool onlyDestroyed=false) 
    {
        eError error = e_ERROR_NOT_IMPLEMENTED;
        HDC attached;
        HWND gotten;
        bool is;

        if ((is = (NULL != (gotten = GetHWND()))))
        if (onlyDestroyed)
            return e_ERROR_ALREADY_CREATED;
        else
        if ((error = Release(gotten,is)))
            return(error);

        if ((is = GetIsCreated()))
        if (onlyDestroyed)
            return e_ERROR_ALREADY_CREATED;
        else
        if ((error = Destroy(is)))
            return(error);

        if ((is = (NULL != (attached = Attached()))))
        if (onlyDestroyed)
            return e_ERROR_ALREADY_ATTACHED;
        else
        if ((error = Detach(attached,is)))
            return(error);

        if (!(is = (NULL != (attached = CreateCompatibleDC(hdc)))))
            DBE("() failed on CreateCompatibleDC()\n");
        else
        if ((error = Attach(attached, is)))
            DeleteDC(attached);
        return error;
    }
    /**
     **********************************************************************
     * Function: Destroy
     *
     *   Author: $author$
     *     Date: 4/23/2008
     **********************************************************************
     */
    virtual eError Destroy
    (bool onlyCreated=false) 
    {
        eError error = e_ERROR_NOT_IMPLEMENTED;
        eError error2;
        HDC attached;
        HWND gotten;
        BOOL ok;
        bool is;

        if ((is = (NULL != (gotten = GetHWND()))))
            return e_ERROR_NOT_CREATED;

        if (!(is = (NULL != (attached = Attached()))))
        if (onlyCreated)
            return e_ERROR_NOT_ATTACHED;

        if ((ok = DeleteDC(attached))) 
            error = e_ERROR_NONE;
        else
        DBE("() failed on DeleteDC()\n");

        if ((error2 = Detach(attached, is)) && !error)
            error = error2;
        return error;
    }

    /**
     **********************************************************************
     * Function: Get
     *
     *   Author: $author$
     *     Date: 4/24/2008
     **********************************************************************
     */
    virtual eError Get
    (HWND hwnd, bool onlyReleased=false) 
    {
        eError error = e_ERROR_FAILED;
        HDC attached;
        HWND gotten;
        bool is;

        if ((is = (NULL != (gotten = GetHWND()))))
        if (onlyReleased)
            return e_ERROR_ALREADY_CREATED;
        else
        if ((error = Release(gotten,is)))
            return(error);

        if ((is = GetIsCreated()))
        if (onlyReleased)
            return e_ERROR_ALREADY_CREATED;
        else
        if ((error = Destroy(is)))
            return(error);

        if ((is = (NULL != (attached = Attached()))))
        if (onlyReleased)
            return e_ERROR_ALREADY_ATTACHED;
        else
        if ((error = Detach(attached,is)))
            return(error);

        if (!(is = (NULL != (attached = GetDC(hwnd)))))
            DBE("() failed on GetDC()\n");
        else
        if ((error = Attach(attached, is)))
            ReleaseDC(hwnd, attached);
        else
        SetHWND(hwnd);
        return error;
    }
    /**
     **********************************************************************
     * Function: Release
     *
     *   Author: $author$
     *     Date: 4/24/2008
     **********************************************************************
     */
    virtual eError Release
    (HWND& hwnd, bool onlyGotten=false) 
    {
        eError error = e_ERROR_FAILED;
        eError error2;
        HDC attached;
        HWND gotten;
        BOOL ok;
        bool is;

        if (!(is = (NULL != (hwnd = (gotten = GetHWND())))))
        if (onlyGotten)
            return e_ERROR_NOT_CREATED;

        if (!(is = (NULL != (attached = Attached()))))
        if (onlyGotten)
            return e_ERROR_NOT_ATTACHED;

        if ((ok = ReleaseDC(gotten, attached))) 
            error = e_ERROR_NONE;
        else
        DBE("() failed on ReleaseDC()\n");

        if ((error2 = Detach(attached, is)) && !error)
            error = error2;
        return error;
    }

    /**
     **********************************************************************
     * Function: Begin
     *
     *   Author: $author$
     *     Date: 6/3/2008
     **********************************************************************
     */
    virtual eError Begin
    (PAINTSTRUCT& ps, HWND hwnd, 
     bool onlyReleased=false) 
    {
        eError error = e_ERROR_FAILED;
        HDC attached;
        HWND gotten;
        bool is;

        if ((is = (NULL != (gotten = GetHWND()))))
        if (onlyReleased)
            return e_ERROR_ALREADY_CREATED;
        else
        if ((error = Release(gotten,is)))
            return(error);

        if ((is = GetIsCreated()))
        if (onlyReleased)
            return e_ERROR_ALREADY_CREATED;
        else
        if ((error = Destroy(is)))
            return(error);

        if ((is = (NULL != (attached = Attached()))))
        if (onlyReleased)
            return e_ERROR_ALREADY_ATTACHED;
        else
        if ((error = Detach(attached,is)))
            return(error);

        if (!(is = (NULL != (attached = BeginPaint(hwnd, &ps)))))
            DBE("() failed on BeginPaint()\n");
        else
        if ((error = Attach(attached, is)))
            ReleaseDC(hwnd, attached);
        else
        SetHWND(hwnd);
        return error;
    }
    /**
     **********************************************************************
     * Function: End
     *
     *   Author: $author$
     *     Date: 6/3/2008
     **********************************************************************
     */
    virtual eError End
    (PAINTSTRUCT& ps, HWND& hwnd, 
     bool onlyGotten=false) 
    {
        eError error = e_ERROR_FAILED;
        eError error2;
        HDC attached;
        HWND gotten;
        BOOL ok;
        bool is;

        if (!(is = (NULL != (hwnd = (gotten = GetHWND())))))
        if (onlyGotten)
            return e_ERROR_NOT_CREATED;

        if (!(is = (NULL != (attached = Attached()))))
        if (onlyGotten)
            return e_ERROR_NOT_ATTACHED;

        if ((ok = EndPaint(hwnd, &ps))) 
            error = e_ERROR_NONE;
        else
        DBE("() failed on EndPaint()\n");

        if ((error2 = Detach(attached, is)) && !error)
            error = error2;
        return error;
    }

    /**
     **********************************************************************
     * Function: SetHWND
     *
     *   Author: $author$
     *     Date: 4/24/2008
     **********************************************************************
     */
    virtual HWND SetHWND(HWND hwnd) 
    {
        HWND oldHwnd = m_hwnd;
        m_hwnd = hwnd;
        return oldHwnd;
    }
    /**
     **********************************************************************
     * Function: GetHWND
     *
     *   Author: $author$
     *     Date: 4/24/2008
     **********************************************************************
     */
    virtual HWND GetHWND() const 
    {
        return m_hwnd;
    }
};

#endif /* _CWINDC_HXX */
