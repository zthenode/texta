///////////////////////////////////////////////////////////////////////
//   File: cevtcpservletexporter.cpp
//
// Author: $author$
//   Date: 4/13/2007
//
//    $Id$
///////////////////////////////////////////////////////////////////////

#include "cevtcpservletexporter.hpp"

///////////////////////////////////////////////////////////////////////
//  Class: CEvTcpServletExporter
//
// Author: $author$
//   Date: 4/13/2007
///////////////////////////////////////////////////////////////////////
CEvTcpServletExporter* CEvTcpServletExporter::m_exporter = 0;

///////////////////////////////////////////////////////////////////////
//
// Exported functions
//
///////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////
// Function: EV_TCP_SERVLET_ACQUIRE
//
//   Author: $author$
//     Date: 4/12/2007
///////////////////////////////////////////////////////////////////////
EV_PLATFORM_EXPORT EvTcpServlet* 
EV_TCP_SERVLET_ACQUIRE(EvError& error)
{
    EvTcpServlet* servlet = 0;
    CEvTcpServletExporter* exporter;

    if ((exporter = CEvTcpServletExporter::GetExporter()))
        servlet = exporter->AcquireServlet(error);
    return servlet;
}

///////////////////////////////////////////////////////////////////////
// Function: EV_TCP_SERVLET_RELEASE
//
//   Author: $author$
//     Date: 4/12/2007
///////////////////////////////////////////////////////////////////////
EV_PLATFORM_EXPORT EvError 
EV_TCP_SERVLET_RELEASE(EvTcpServlet* servlet)
{
    EvError error = EV_ERROR_FAILED;
    CEvTcpServletExporter* exporter;

    if ((exporter = CEvTcpServletExporter::GetExporter()))
    if (servlet)
        error = exporter->ReleaseServlet(*servlet);
    else error = exporter->ReleaseAllServlets();
    return error;
}
