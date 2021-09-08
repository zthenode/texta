///////////////////////////////////////////////////////////////////////
//   File: cevservletexporter.hpp
//
// Author: $author$
//   Date: 4/13/2007
//
//    $Id$
///////////////////////////////////////////////////////////////////////

#ifndef _CEVSERVLETEXPORTER_HPP
#define _CEVSERVLETEXPORTER_HPP

#include "evservletexporter.hpp"
#include "cevservletallocator.hpp"

///////////////////////////////////////////////////////////////////////
//  Class: CEvServletExporter
//
// Author: $author$
//   Date: 4/13/2007
///////////////////////////////////////////////////////////////////////
class CEvServletExporter
: public CEvServletAllocator
{
public:
    typedef CEvServletAllocator CExtends;
    typedef CEvServletExporter CDerives;

    static CEvServletExporter* m_exporter;
    CEvServletExporter* m_oldExporter;

    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvServletExporter
    //
    //       Author: $author$
    //         Date: 4/13/2007
    ///////////////////////////////////////////////////////////////////////
    CEvServletExporter() 
    : m_oldExporter(m_exporter)
    {
        m_exporter = this;
    }
    ///////////////////////////////////////////////////////////////////////
    // Destructor: ~CEvServletExporter
    //
    //      Author: $author$
    //        Date: 4/13/2007
    ///////////////////////////////////////////////////////////////////////
    virtual ~CEvServletExporter()
    {
        if (this == m_exporter)
            m_exporter = m_oldExporter;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: AcquireEvServlet
    //
    //   Author: $author$
    //     Date: 9/10/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvServlet* AcquireEvServlet(EvError &error) 
    {
        EvServlet* servlet = 0;
        error = EV_ERROR_FAILED;
        return servlet;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: GetExporter
    //
    //   Author: $author$
    //     Date: 4/13/2007
    ///////////////////////////////////////////////////////////////////////
    static CEvServletExporter* GetExporter() 
    {
        return m_exporter;
    }
};
#endif // _CEVSERVLETEXPORTER_HPP
