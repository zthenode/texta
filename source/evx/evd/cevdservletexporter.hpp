///////////////////////////////////////////////////////////////////////
//   File: cevdservletexporter.hpp
//
// Author: $author$
//   Date: 4/13/2007
//
//    $Id$
///////////////////////////////////////////////////////////////////////

#ifndef _CEVDSERVLETEXPORTER_HPP
#define _CEVDSERVLETEXPORTER_HPP

#include "cevtcpservletexporter.hpp"
#include "cevservletexporter.hpp"
#include "cevdservlet.hpp"

///////////////////////////////////////////////////////////////////////
//  Class: CEvDTcpServletExporter
//
// Author: $author$
//   Date: 4/13/2007
///////////////////////////////////////////////////////////////////////
class CEvDTcpServletExporter
: public CEvTcpServletExporter
{
public:
    typedef CEvTcpServletExporter CExtends;
    typedef CEvDTcpServletExporter CDerives;

    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvDTcpServletExporter
    //
    //       Author: $author$
    //         Date: 4/13/2007
    ///////////////////////////////////////////////////////////////////////
    CEvDTcpServletExporter() 
    {
    }
    ///////////////////////////////////////////////////////////////////////
    // Destructor: ~CEvDTcpServletExporter
    //
    //      Author: $author$
    //        Date: 4/13/2007
    ///////////////////////////////////////////////////////////////////////
    virtual ~CEvDTcpServletExporter()
    {
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: AcquireServlet
    //
    //   Author: $author$
    //     Date: 4/13/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvTcpServlet* AcquireServlet(EvError &error) 
    {
        EvTcpServlet* servlet = 0;

        if ((servlet = new CEvDServlet()))
        {
            if ((error = AddServlet(*servlet)))
            {
                delete servlet;
                servlet = 0;
            }
        }
        else error = EV_ERROR_FAILED;
        return servlet;
    }
};

///////////////////////////////////////////////////////////////////////
//  Class: CEvDServletExporter
//
// Author: $author$
//   Date: 9/10/2007
///////////////////////////////////////////////////////////////////////
class CEvDServletExporter
: public CEvServletExporter
{
public:
    typedef CEvServletExporter CExtends;
    typedef CEvDServletExporter CDerives;

    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvDServletExporter
    //
    //       Author: $author$
    //         Date: 9/10/2007
    ///////////////////////////////////////////////////////////////////////
    CEvDServletExporter() 
    {
    }
    ///////////////////////////////////////////////////////////////////////
    // Destructor: ~CEvDServletExporter
    //
    //      Author: $author$
    //        Date: 9/10/2007
    ///////////////////////////////////////////////////////////////////////
    virtual ~CEvDServletExporter()
    {
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

        if ((servlet = new CEvDServlet()))
        {
            if ((error = AddServlet(*servlet)))
            {
                delete servlet;
                servlet = 0;
            }
        }
        else error = EV_ERROR_FAILED;
        return servlet;
    }
};
#endif // _CEVDSERVLETEXPORTER_HPP
