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
 *   File: cwinrect.hxx
 *
 * Author: $author$
 *   Date: 6/2/2008
 **********************************************************************
 */
#ifndef _CWINRECT_HXX
#define _CWINRECT_HXX

#include "cwin.hxx"

/**
 **********************************************************************
 *  Class: cWinClientRect
 *
 * Author: $author$
 *   Date: 5/12/2004
 **********************************************************************
 */
class cWinClientRect
: public cWinRect
{
public:
    typedef cWinRect cIs;

    /**
     **********************************************************************
     * Constructor: cWinClientRect
     *
     *      Author: $author$
     *        Date: 5/12/2004
     **********************************************************************
     */
    cWinClientRect(HWND window=NULL) 
    {
        eError error;

        if (window)
        if ((error = GetClient(window)))
            throw(error);
    }
};

/**
 **********************************************************************
 *  Class: cWinWindowRect
 *
 * Author: $author$
 *   Date: 2/1/2006
 **********************************************************************
 */
class cWinWindowRect
: public cWinRect
{
public:
    typedef cWinRect cIs;

    /**
     **********************************************************************
     * Constructor: cWinWindowRect
     *
     *      Author: $author$
     *        Date: 2/1/2006
     **********************************************************************
     */
    cWinWindowRect(HWND window=NULL) 
    {
        eError error;

        if (window)
        if ((error = GetWindow(window)))
            throw(error);
    }
};

/**
 **********************************************************************
 *  Class: cWinWindowToClientRect
 *
 * Author: $author$
 *   Date: 2/1/2006
 **********************************************************************
 */
class cWinWindowToClientRect
: public cWinRect
{
public:
    typedef cWinRect cIs;

    /**
     **********************************************************************
     * Constructor: cWinWindowToClientRect
     *
     *      Author: $author$
     *        Date: 2/1/2006
     **********************************************************************
     */
    cWinWindowToClientRect
    (HWND window=NULL, HWND client=NULL) 
    {
        eError error;

        if (window && client)
        if ((error = GetWindow(window)))
            throw(error);
        else if ((error = ToClient(client)))
                throw(error);
    }
};

#endif /* _CWINRECT_HXX */
