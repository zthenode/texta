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
 *   File: csockets.hxx
 *
 * Author: $author$
 *   Date: 1/15/2008
 **********************************************************************
 */
#ifndef _CSOCKETS_HXX
#define _CSOCKETS_HXX

#include "cerror.h"

#if defined(WIN32) 
/* Windows
 */
#include "cwsainterface.hxx"
#include "cdebug.h"
#else /* defined(WIN32) */
/* Unix
 */
#endif /* defined(WIN32) */
/**
 **********************************************************************
 *  Class: cSockets
 *
 * Author: $author$
 *   Date: 1/15/2008
 **********************************************************************
 */
class cSockets
{
public:
    typedef cSockets cDerives;

#if defined(WIN32) 
/* Windows
 */
    static cWSAInterface *m_wsa;
#else /* defined(WIN32) */
/* Unix
 */
#endif /* defined(WIN32) */

    /**
     **********************************************************************
     * Constructor: cSockets
     *
     *      Author: $author$
     *        Date: 1/15/2008
     **********************************************************************
     */
    cSockets() 
    {
    }
    /**
     **********************************************************************
     * Destructor: cSockets
     *
     *     Author: $author$
     *       Date: 1/15/2008
     **********************************************************************
     */
    virtual ~cSockets()
    {
    }
    /**
     **********************************************************************
     * Function: Initialize
     *
     *   Author: $author$
     *     Date: 1/15/2008
     **********************************************************************
     */
    virtual eError Initialize() 
    {
        eError error = e_ERROR_NONE;
#if defined(WIN32) 
/* Windows
 */
        if (m_wsa)
            return e_ERROR_ALREADY_INITIALIZED;

        if ((m_wsa = cWSAInterface::GetInstance()))
        if ((error = m_wsa->Startup()))
        {
            DBE("() failed on m_wsa->Startup()\n");
            m_wsa = 0;
        }
#else /* defined(WIN32) */
/* Unix
 */
#endif /* defined(WIN32) */
        return error;
    }
    /**
     **********************************************************************
     * Function: Finalize
     *
     *   Author: $author$
     *     Date: 1/15/2008
     **********************************************************************
     */
    virtual eError Finalize() 
    {
        eError error = e_ERROR_NONE;
#if defined(WIN32) 
/* Windows
 */
        if (!m_wsa)
            return e_ERROR_NOT_INITIALIZED;

        if ((error = m_wsa->Cleanup()))
            DBE("() failed on m_wsa->Cleanup()\n");
        m_wsa = 0;
#else /* defined(WIN32) */
/* Unix
 */
#endif /* defined(WIN32) */
        return error;
    }
};
#endif /* _CSOCKETS_HXX */
