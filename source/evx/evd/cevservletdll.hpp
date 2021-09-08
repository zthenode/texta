///////////////////////////////////////////////////////////////////////
//   File: cevservletdll.hpp
//
// Author: $author$
//   Date: 9/10/2007
//
//    $Id$
///////////////////////////////////////////////////////////////////////

#ifndef _CEVSERVLETDLL_HPP
#define _CEVSERVLETDLL_HPP

#include "cevbase.hpp"

#include "evtcpservletexporter.hpp"
#include "cevdll.hpp"
#include "cevstring.hpp"
#include "evdebug.h"

///////////////////////////////////////////////////////////////////////
//  Class: CEvServletDll
//
// Author: $author$
//   Date: 9/10/2007
///////////////////////////////////////////////////////////////////////
class CEvServletDll
: virtual public EvServletExporter,
  public CEvBase
{
public:
    typedef EvServletExporter CImplements;
    typedef CEvBase CExtends;
    typedef CEvServletDll CDerives;

    CEvString m_dllFilename;

    CEvString m_servletAcquireSymbol;
    CEvString m_servletReleaseSymbol;

    FEvServletAcquire* m_servletAcquire;
    FEvServletRelease* m_servletRelease;

    bool m_opened;
    CEvDll m_dll;

    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvServletDll
    //
    //       Author: $author$
    //         Date: 9/10/2007
    ///////////////////////////////////////////////////////////////////////
    CEvServletDll(const char* dllFilename=0) 
    : m_servletAcquireSymbol(EV_SERVLET_ACQUIRE_SYMBOL),
      m_servletReleaseSymbol(EV_SERVLET_RELEASE_SYMBOL),
      m_servletAcquire(0),
      m_servletRelease(0),
      m_opened(false) 
    {
    }
    ///////////////////////////////////////////////////////////////////////
    // Destructor: ~CEvServletDll
    //
    //      Author: $author$
    //        Date: 9/10/2007
    ///////////////////////////////////////////////////////////////////////
    virtual ~CEvServletDll()
    {
        EvError error;

        if (m_opened)
        if ((error = Close()))
            throw(error);
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: Open
    //
    //   Author: $author$
    //     Date: 4/13/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError Open(const char* dllFilename=0) 
    {
        EvError error = EV_ERROR_FAILED;
        LONG length = 1;
        const char* servletAcquire;
        const char* servletRelease;

        if (m_opened)
            return EV_ERROR_NONE;

        if (!dllFilename)
            dllFilename = m_dllFilename.Chars(length);

        if (!dllFilename || (0 >= length))
            return EV_ERROR_NULL_PARAMETER;

        if ((servletAcquire = m_servletAcquireSymbol.HasChars(length)))
        if ((servletRelease = m_servletReleaseSymbol.HasChars(length)))
        if (!(error = m_dll.Open(dllFilename)))
        {
            if (!(m_servletAcquire = (FEvServletAcquire*)
                (m_dll.GetAddress(servletAcquire))))
                DBE("() failed to get address of \"%s\"\n", servletAcquire);
            else if (!(m_servletRelease = (FEvServletRelease*)
                    (m_dll.GetAddress(servletRelease))))
                    DBE("() failed to get address of \"%s\"\n", servletRelease);
            else
            {
                m_opened = true;
                return EV_ERROR_NONE;
            }
            m_servletAcquire = 0;
            m_dll.Close();
        }
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: Close
    //
    //   Author: $author$
    //     Date: 4/13/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError Close() 
    {
        EvError error = EV_ERROR_FAILED;

        if (!m_opened)
            return EV_ERROR_NOT_OPEN;

        if ((error = ReleaseAllServlets()))
            DBE("() release all servlets failed\n");

        if ((error = m_dll.Close()))
            DBE("() dll close failed\n");

        m_opened = false;
        m_servletRelease = 0;
        m_servletAcquire = 0;
        return error;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: AcquireEvServlet
    //
    //   Author: $author$
    //     Date: 4/16/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvServlet* 
    AcquireEvServlet(EvError &error) 
    {
        EvServlet* servlet = 0;

        if (!m_opened)
        {
            error = EV_ERROR_NOT_OPEN;
            return servlet;
        }

        servlet = m_servletAcquire(error);
        return servlet;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: ReleaseEvServlet
    //
    //   Author: $author$
    //     Date: 4/16/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError ReleaseEvServlet
    (EvServlet& servlet) 
    {
        EvError error = EV_ERROR_FAILED;

        if (!m_opened)
            return EV_ERROR_NOT_OPEN;

        error = m_servletRelease(&servlet);
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: ReleaseAllServlets
    //
    //   Author: $author$
    //     Date: 4/16/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError ReleaseAllServlets() 
    {
        EvError error = EV_ERROR_NONE;

        if (!m_opened)
            return EV_ERROR_NOT_OPEN;

        error = m_servletRelease(0);
        return error;
    }
};
#endif // _CEVSERVLETDLL_HPP
