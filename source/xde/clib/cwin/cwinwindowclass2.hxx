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
 *   Date: 10/28/2008
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
 *   Date: 10/28/2008
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
     *        Date: 10/28/2008
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
    }
    /**
     **********************************************************************
     * Destructor: ~cWinWindowClass
     *
     *     Author: $author$
     *       Date: 10/28/2008
     **********************************************************************
     */
    virtual ~cWinWindowClass()
    {
    }
};
#endif /* _CWINWINDOWCLASS_HXX */
