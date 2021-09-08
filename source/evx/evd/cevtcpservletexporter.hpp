///////////////////////////////////////////////////////////////////////
//   File: cevtcpservletexporter.hpp
//
// Author: $author$
//   Date: 4/12/2007
//
//    $Id$
///////////////////////////////////////////////////////////////////////

#ifndef _CEVTCPSERVLETEXPORTER_HPP
#define _CEVTCPSERVLETEXPORTER_HPP

#include "cevservletexporter.hpp"
#include "cevtcpservlet.hpp"

///////////////////////////////////////////////////////////////////////
//  Class: CEvTcpServletExporter
//
// Author: $author$
//   Date: 4/12/2007
///////////////////////////////////////////////////////////////////////
class CEvTcpServletExporter
: public CEvServletExporter
{
public:
    typedef CEvServletExporter CExtends;
    typedef CEvTcpServletExporter CDerives;

    static CEvTcpServletExporter* m_exporter;
    CEvTcpServletExporter* m_oldExporter;

    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvTcpServletExporter
    //
    //       Author: $author$
    //         Date: 4/12/2007
    ///////////////////////////////////////////////////////////////////////
    CEvTcpServletExporter() 
    : m_oldExporter(m_exporter)
    {
        m_exporter = this;
    }
    ///////////////////////////////////////////////////////////////////////
    // Destructor: ~CEvTcpServletExporter
    //
    //      Author: $author$
    //        Date: 4/12/2007
    ///////////////////////////////////////////////////////////////////////
    virtual ~CEvTcpServletExporter()
    {
        if (this == m_exporter)
            m_exporter = m_oldExporter;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: AcquireServlet
    //
    //   Author: $author$
    //     Date: 4/12/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvTcpServlet* AcquireServlet(EvError &error) 
    {
        EvTcpServlet* servlet = 0;
        error = EV_ERROR_FAILED;
        return servlet;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: GetExporter
    //
    //   Author: $author$
    //     Date: 4/13/2007
    ///////////////////////////////////////////////////////////////////////
    static CEvTcpServletExporter* GetExporter() 
    {
        return m_exporter;
    }
};
#endif // _CEVTCPSERVLETEXPORTER_HPP
