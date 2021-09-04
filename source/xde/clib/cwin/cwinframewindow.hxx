/**
 **********************************************************************
 * Copyright (c) 1988-2009 $organization$
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
 *   File: cwinframewindow.hxx
 *
 * Author: $author$
 *   Date: 2/15/2009
 **********************************************************************
 */
#ifndef _CWINFRAMEWINDOW_HXX
#define _CWINFRAMEWINDOW_HXX

#include "cwinwindow.hxx"

/**
 **********************************************************************
 *  Class: cWinFrameWindow
 *
 * Author: $author$
 *   Date: 2/15/2009
 **********************************************************************
 */
class cWinFrameWindow
: public cWinWindow
{
public:
    typedef cWinWindow cExtends;
    typedef cWinFrameWindow cDerives;
    /**
     **********************************************************************
     * Constructor: cWinFrameWindow
     *
     *      Author: $author$
     *        Date: 2/15/2009
     **********************************************************************
     */
    cWinFrameWindow
    (HINSTANCE hinstance=NULL_HANDLE,
     HWND attached=NULL_HANDLE,
     bool isCreated=false) 
    : cExtends(hinstance, attached, isCreated)
    {
    }
    /**
     **********************************************************************
     * Destructor: ~cWinFrameWindow
     *
     *     Author: $author$
     *       Date: 2/15/2009
     **********************************************************************
     */
    virtual ~cWinFrameWindow()
    {
        Destruct();
    }
};

#endif /* _CWINFRAMEWINDOW_HXX */
