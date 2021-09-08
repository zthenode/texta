///////////////////////////////////////////////////////////////////////
//   File: cevtcpservletdll.hpp
//
// Author: $author$
//   Date: 4/13/2007
//
//    $Id$
///////////////////////////////////////////////////////////////////////

#ifndef _CEVTCPSERVLETDLL_HPP
#define _CEVTCPSERVLETDLL_HPP

#include "cevservletdll.hpp"

///////////////////////////////////////////////////////////////////////
//  Class: CEvTcpServletDll
//
// Author: $author$
//   Date: 4/13/2007
///////////////////////////////////////////////////////////////////////
class CEvTcpServletDll
: virtual public EvTcpServletExporter,
  public CEvServletDll
{
public:
    typedef EvTcpServletExporter CImplements;
    typedef CEvServletDll CExtends;
    typedef CEvTcpServletDll CDerives;

    CEvString m_tcpServletAcquireSymbol;
    CEvString m_tcpServletReleaseSymbol;

    FEvTcpServletAcquire* m_tcpServletAcquire;
    FEvTcpServletRelease* m_tcpServletRelease;

    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvTcpServletDll
    //
    //       Author: $author$
    //         Date: 4/13/2007
    ///////////////////////////////////////////////////////////////////////
    CEvTcpServletDll(const char* dllFilename=0) 
    : CExtends(dllFilename),
      m_tcpServletAcquireSymbol(EV_TCP_SERVLET_ACQUIRE_SYMBOL),
      m_tcpServletReleaseSymbol(EV_TCP_SERVLET_RELEASE_SYMBOL),
      m_tcpServletAcquire(0),
      m_tcpServletRelease(0)
    {
    }
    ///////////////////////////////////////////////////////////////////////
    // Destructor: ~CEvTcpServletDll
    //
    //      Author: $author$
    //        Date: 4/13/2007
    ///////////////////////////////////////////////////////////////////////
    virtual ~CEvTcpServletDll()
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

        if ((servletAcquire = m_tcpServletAcquireSymbol.HasChars(length)))
        if ((servletRelease = m_tcpServletReleaseSymbol.HasChars(length)))
        if (!(error = m_dll.Open(dllFilename)))
        {
            if (!(m_tcpServletAcquire = (FEvTcpServletAcquire*)
                (m_dll.GetAddress(servletAcquire))))
                DBE("() failed to get address of \"%s\"\n", servletAcquire);
            else if (!(m_tcpServletRelease = (FEvTcpServletRelease*)
                    (m_dll.GetAddress(servletRelease))))
                    DBE("() failed to get address of \"%s\"\n", servletRelease);
            else
            {
                if ((servletAcquire = m_servletAcquireSymbol.HasChars(length)))
                if ((servletRelease = m_servletReleaseSymbol.HasChars(length)))
                if (!(m_servletAcquire = (FEvServletAcquire*)
                    (m_dll.GetAddress(servletAcquire))))
                    DBE("() failed to get address of \"%s\"\n", servletAcquire);
                else 
                if (!(m_servletRelease = (FEvServletRelease*)
                    (m_dll.GetAddress(servletRelease))))
                {
                    DBE("() failed to get address of \"%s\"\n", servletRelease);
                    m_servletAcquire = 0;
                }

                m_opened = true;
                return EV_ERROR_NONE;
            }
            m_tcpServletAcquire = 0;
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
        m_tcpServletRelease = 0;
        m_tcpServletAcquire = 0;
        return error;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: AcquireServlet
    //
    //   Author: $author$
    //     Date: 4/16/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvTcpServlet* 
    AcquireServlet(EvError &error) 
    {
        EvTcpServlet* servlet = 0;

        if (!m_opened)
        {
            error = EV_ERROR_NOT_OPEN;
            return servlet;
        }

        servlet = m_tcpServletAcquire(error);
        return servlet;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: ReleaseServlet
    //
    //   Author: $author$
    //     Date: 4/16/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError ReleaseServlet
    (EvTcpServlet& servlet) 
    {
        EvError error = EV_ERROR_FAILED;

        if (!m_opened)
            return EV_ERROR_NOT_OPEN;

        error = m_tcpServletRelease(&servlet);
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

        error = m_tcpServletRelease(0);
        return error;
    }
};
#endif // _CEVTCPSERVLETDLL_HPP
