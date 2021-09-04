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
 *   File: cwinsecurityattributes.hxx
 *
 * Author: $author$
 *   Date: 2/4/2008
 **********************************************************************
 */
#ifndef _CWINSECURITYATTRIBUTES_HXX
#define _CWINSECURITYATTRIBUTES_HXX

#include "cplatform.h"

#if defined(WIN32_API) 
/* use Windows API
 */
/**
 **********************************************************************
 *  Class: cWinSecurityAttributes
 *
 * Author: $author$
 *   Date: 2/4/2008
 **********************************************************************
 */
class cWinSecurityAttributes
: public SECURITY_ATTRIBUTES
{
public:
    typedef SECURITY_ATTRIBUTES cExtends;
    typedef cWinSecurityAttributes cDerives;
    /**
     **********************************************************************
     * Constructor: cWinSecurityAttributes
     *
     *      Author: $author$
     *        Date: 2/4/2008
     **********************************************************************
     */
    cWinSecurityAttributes() 
    {
        Clear();
    }
    /**
     **********************************************************************
     * Function: Init
     *
     *   Author: $author$
     *     Date: 10/29/2004
     **********************************************************************
     */
    void Clear()
    {
        memset((cExtends*)this, 0, sizeof(cExtends));
        nLength = sizeof(cExtends);
    }
    /**
     **********************************************************************
     * Function: SetInheritHandle
     *
     *   Author: $author$
     *     Date: 10/29/2004
     **********************************************************************
     */
    BOOL SetInheritHandle(BOOL on=TRUE) 
    {
        bInheritHandle = on;
        return bInheritHandle;
    }
    /**
     **********************************************************************
     * Function: GetInheritHandle
     *
     *   Author: $author$
     *     Date: 10/29/2004
     **********************************************************************
     */
    BOOL GetInheritHandle() const
    {
        return bInheritHandle;
    }
};
#else /* defined(WIN32_API) */
/* use Unix API
 */
#endif /* defined(WIN32_API) */
#endif /* _CWINSECURITYATTRIBUTES_HXX */
