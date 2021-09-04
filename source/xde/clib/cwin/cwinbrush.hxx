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
 *   File: cwinbrush.hxx
 *
 * Author: $author$
 *   Date: 4/30/2008
 **********************************************************************
 */
#ifndef _CWINBRUSH_HXX
#define _CWINBRUSH_HXX

#include "cwingdiobject.hxx"

/**
 **********************************************************************
 *  Class: cWinBrushInterface
 *
 * Author: $author$
 *   Date: 4/27/2008
 **********************************************************************
 */
class c_INTERFACE_CLASS cWinBrushInterface
: virtual public cWinGDIObjectInterface
{
public:
    typedef cWinGDIObjectInterface cImplements;
    typedef cWinBrushInterface cDerives;
};

/**
 **********************************************************************
 *  Class: cWinBrush
 *
 * Author: $author$
 *   Date: 4/27/2008
 **********************************************************************
 */
class cWinBrush
: virtual public cWinBrushInterface,
  public cWinGDIObject
{
public:
    typedef cWinBrushInterface cImplements;
    typedef cWinGDIObject cExtends;
    typedef cWinBrush cDerives;

    HBRUSH m_hbrush;

    /**
     **********************************************************************
     * Constructor: cWinBrush
     *
     *      Author: $author$
     *        Date: 4/27/2008
     **********************************************************************
     */
    cWinBrush
    (HBRUSH hbrush=NULL,
     bool isCreated=false) 
    : cExtends((HGDIOBJ)(hbrush), isCreated),
      m_hbrush(hbrush)
    {
    }
    /**
     **********************************************************************
     * Destructor: ~cWinBrush
     *
     *     Author: $author$
     *       Date: 4/27/2008
     **********************************************************************
     */
    virtual ~cWinBrush()
    {
        Destruct();
    }

    /**
     **********************************************************************
     * Function: CreateSolid
     *
     *   Author: $author$
     *     Date: 4/27/2008
     **********************************************************************
     */
    virtual eError CreateSolid
    (BYTE red, BYTE green, BYTE blue,
     bool onlyDestroyed=false) 
    {
        COLORREF color = RGB(red, green, blue);
        eError error = CreateSolid(color, onlyDestroyed);
        return error;
    }
    /**
     **********************************************************************
     * Function: CreateSolid
     *
     *   Author: $author$
     *     Date: 4/27/2008
     **********************************************************************
     */
    virtual eError CreateSolid
    (COLORREF color,
     bool onlyDestroyed=false) 
    {
        eError error = e_ERROR_FAILED;
        HGDIOBJ attached;
        HBRUSH hbrush;
        bool is;

        if ((error = Destroyed(onlyDestroyed)))
            return error;

        if (!(is = NULL_HANDLE != (attached = (hbrush = CreateSolidBrush(color)))))
            DBE("() failed on CreateSolidBrush()\n");
        else
        if ((error = Attach(attached, is)))
            DestroyAttached(attached);
        else
        m_hbrush = hbrush;

        return error;
    }
    /**
     **********************************************************************
     * Function: Detach
     *
     *   Author: $author$
     *     Date: 4/27/2008
     **********************************************************************
     */
    virtual eError Detach
    (HGDIOBJ& attached, bool onlyAttached=false) 
    {
        eError error = cExtends::Detach(attached, onlyAttached);
        m_hbrush = NULL_HANDLE;
        return error;
    }
};

#endif /* _CWINBRUSH_HXX */
