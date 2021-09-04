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
 *   File: cwinbitmap.hxx
 *
 * Author: $author$
 *   Date: 11/3/2008
 **********************************************************************
 */
#ifndef _CWINBITMAP_HXX
#define _CWINBITMAP_HXX

#include "cwingdiobject.hxx"
#include "cwinattached.hxx"
#include "cdebug.hxx"

/**
 **********************************************************************
 *  Class: cWinBitmap
 *
 * Author: $author$
 *   Date: 11/3/2008
 **********************************************************************
 */
class cWinBitmap
: public cWinGDIObject
{
public:
    typedef cWinGDIObject cExtends;
    typedef cWinBitmap cDerives;
    /**
     **********************************************************************
     * Constructor: cWinBitmap
     *
     *      Author: $author$
     *        Date: 11/3/2008
     **********************************************************************
     */
    cWinBitmap
    (HBITMAP attached=NULL_HANDLE,
     bool isCreated=false) 
    : cExtends(attached, isCreated)
    {
    }
    /**
     **********************************************************************
     * Destructor: ~cWinBitmap
     *
     *     Author: $author$
     *       Date: 11/3/2008
     **********************************************************************
     */
    virtual ~cWinBitmap()
    {
        Destruct();
    }

    /**
     **********************************************************************
     * Function: Create
     *
     *   Author: $author$
     *     Date: 11/3/2008
     **********************************************************************
     */
    virtual eError Create
    (HINSTANCE hInstance, 
     const TCHAR* fileName, 
     bool onlyDestroyed=false) 
    {
        eError error = e_ERROR_FAILED;
        HBITMAP attached;
        int created;

        if ((error = Destroyed(onlyDestroyed)))
            return error;

        if (NULL_HANDLE != (attached = 
            CreateAttached(error, hInstance, fileName)))
        {
            if (!(error = Attach(attached, true)))
            if (0 <= (created = SetIsCreated()))
                return error;
            else error = -created;
            DestroyAttached(attached);
        }
        return error;
    }

    /**
     **********************************************************************
     * Function: CreateAttached
     *
     *   Author: $author$
     *     Date: 11/3/2008
     **********************************************************************
     */
    virtual HBITMAP CreateAttached
    (eError& error, HINSTANCE hInstance, const TCHAR* fileName) const 
    {
        HBITMAP attached = NULL_HANDLE;
        error = e_ERROR_NOT_IMPLEMENTED;

        if (NULL_HANDLE != (attached = (HBITMAP)LoadImage
            (hInstance, fileName, IMAGE_BITMAP, 0,0, LR_LOADFROMFILE)))
            error = e_ERROR_NONE;
        return attached;
    }
};
#endif /* _CWINBITMAP_HXX */
