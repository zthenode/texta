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
 *   File: cwsa.hxx
 *
 * Author: $author$
 *   Date: 1/15/2008
 **********************************************************************
 */
#ifndef _CWSA_HXX
#define _CWSA_HXX

#include "cplatform.hxx"
#include "csingleinstance.hxx"
#include "cwsainterface.hxx"

/**
 **********************************************************************
 *  Class: cWSA
 *
 * Author: $author$
 *   Date: 1/15/2008
 **********************************************************************
 */
class cWSA
: virtual public cWSAInterface,
  public cSingleInstanceT<cWSA>
{
public:
    typedef cWSAInterface cImplements;
    typedef cSingleInstanceT<cWSA> cExtends;

    int m_version;
    int m_startup;
    WSADATA m_data;

    /**
     **********************************************************************
     * Constructor: cWSA
     *
     *      Author: $author$
     *        Date: 1/15/2008
     **********************************************************************
     */
    cWSA(int version = 0x0002)
    : cExtends(this),
      m_version(version),
      m_startup(0) 
    {
    }
    /**
     **********************************************************************
     * Destructor: cWSA
     *
     *     Author: $author$
     *       Date: 1/15/2008
     **********************************************************************
     */
    virtual ~cWSA()
    {
        eError error;

        if (m_startup > 0)
        if ((error = Cleanup()))
            throw(error);
    }

    /**
     **********************************************************************
     * Function: Startup
     *
     *   Author: $author$
     *     Date: 1/15/2008
     **********************************************************************
     */
    virtual eError Startup() 
    {
        int err;

        if (m_startup >= 0)
        if (++m_startup <= 1)
        if ((err = WSAStartup(m_version, &m_data)))
        {
            --m_startup;
            return e_ERROR_FAILED;
        }
        return e_ERROR_NONE;
    }
    /**
     **********************************************************************
     * Function: Cleanup
     *
     *   Author: $author$
     *     Date: 1/15/2008
     **********************************************************************
     */
    virtual eError Cleanup() 
    {
        int err;

        if (m_startup > 0)
        if (--m_startup < 1)
        if ((err = WSACleanup()))
            return e_ERROR_FAILED;

        return e_ERROR_NONE;
    }
};
#endif /* _CWSA_HXX */
