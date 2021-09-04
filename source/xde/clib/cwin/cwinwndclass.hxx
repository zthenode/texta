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
 *   File: cwinwndclass.hxx
 *
 * Author: $author$
 *   Date: 4/30/2008
 **********************************************************************
 */
#ifndef _CWINWNDCLASS_HXX
#define _CWINWNDCLASS_HXX

#include "cwinatom.hxx"

/**
 **********************************************************************
 *  Typedef: tWNDCLASS
 *
 *  Author: $author$
 *    Date: 4/30/2008
 **********************************************************************
 */
typedef 
#if defined(WIN32_WCE) 
WNDCLASS
#else /* defined(WIN32_WCE) */
WNDCLASSEX
#endif /* defined(WIN32_WCE) */
cWinWNDCLASSExtends;

/**
 **********************************************************************
 *  Class: cWinWNDCLASS
 *
 * Author: $author$
 *   Date: 4/30/2008
 **********************************************************************
 */
class cWinWNDCLASS
: public cWinWNDCLASSExtends
{
public:
    typedef cWinWNDCLASSExtends cExtends;
    typedef cWinWNDCLASS cDerives;
    /**
     **********************************************************************
     * Constructor: cWinWNDCLASS
     *
     *      Author: $author$
     *        Date: 4/30/2008
     **********************************************************************
     */
    cWinWNDCLASS() 
    {
    }
    /**
     **********************************************************************
     * Function: Set
     *
     *   Author: $author$
     *     Date: 4/30/2008
     **********************************************************************
     */
    void Set
    (LPCTSTR classname, HINSTANCE instance, WNDPROC wndproc=NULL,
     LPCTSTR menuname=NULL, HICON icon=NULL, HICON iconsm=NULL,
     HCURSOR cursor=NULL, HBRUSH background=NULL, UINT style=0,
     int wndextra=0, int clsextra=0, bool isInitial=false) 
    {
#if defined(_WIN32_WCE) 
#else /* defined(_WIN32_WCE) */
        (*this).cbSize=sizeof(*this);
#endif /* defined(_WIN32_WCE) */

        (*this).lpszClassName=classname;
        (*this).cbClsExtra=clsextra;
        (*this).cbWndExtra=wndextra;

        if ((NULL != menuname) || isInitial)
            (*this).lpszMenuName=menuname;

        if ((NULL != icon) || isInitial)
            (*this).hIcon = icon;

#if defined(_WIN32_WCE) 
#else /* defined(_WIN32_WCE) */
        if ((NULL != iconsm) || isInitial)
            (*this).hIconSm = iconsm;
#endif /* defined(_WIN32_WCE) */

        if ((NULL != cursor) || isInitial)
            (*this).hCursor = cursor;

        else if (NULL == (*this).hCursor)
                (*this).hCursor = GetDefaultCursor();

        if ((NULL != background) || isInitial)
            (*this).hbrBackground = background;

        else if (NULL == (*this).hbrBackground)
                (*this).hbrBackground = GetDefaultBackground();

        if ((NULL != wndproc) || isInitial)
            (*this).lpfnWndProc = wndproc;

        else if (NULL == (*this).lpfnWndProc)
                (*this).lpfnWndProc = GetDefaultWindowProc();

        (*this).style=style;
        (*this).hInstance=instance;
        (*this).lpszClassName = classname;
    }
    /**
     **********************************************************************
     * Function: GetDefaultCursor
     *
     *   Author: $author$
     *     Date: 4/30/2008
     **********************************************************************
     */
    HCURSOR GetDefaultCursor() const 
    {
        HCURSOR handle = LoadCursor(NULL, IDC_ARROW);
        return handle;
    }
    /**
     **********************************************************************
     * Function: GetDefaultBackground
     *
     *   Author: $author$
     *     Date: 4/30/2008
     **********************************************************************
     */
    HBRUSH GetDefaultBackground() const 
    {
        HBRUSH handle = (HBRUSH)GetStockObject(WHITE_BRUSH);
        return handle;
    }
    /**
     **********************************************************************
     * Function: GetDefaultWindowProc
     *
     *   Author: $author$
     *     Date: 4/30/2008
     **********************************************************************
     */
    WNDPROC GetDefaultWindowProc() const 
    {
        WNDPROC wndproc = DefWindowProc;
        return wndproc;
    }
};

#endif /* _CWINWNDCLASS_HXX */
