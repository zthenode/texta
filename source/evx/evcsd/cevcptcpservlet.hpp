///////////////////////////////////////////////////////////////////////
//   File: cevcptcpservlet.hpp
//
// Author: $author$
//   Date: 7/31/2007
//
//    $Id$
///////////////////////////////////////////////////////////////////////

#ifndef _CEVCPTCPSERVLET_HPP
#define _CEVCPTCPSERVLET_HPP

#include "cevtcpservlet.hpp"
#include "cevcpservlets.hpp"
#include "cevcpservletconnection.hpp"
#include "cevcpservletresponse.hpp"
#include "cevcpservletrequest.hpp"
#include "cevcpservletallocator.hpp"
#include "cevcpheader.hpp"
#include "cevcp.hpp"
#include "cevstring.hpp"

///////////////////////////////////////////////////////////////////////
//  Class: CEvcpTcpServlet
//
// Author: $author$
//   Date: 7/31/2007
///////////////////////////////////////////////////////////////////////
class CEvcpTcpServlet
: public CEvTcpServlet
{
public:
    typedef CEvTcpServlet CExtends;
    typedef CEvcpTcpServlet CDerives;

    CEvcpServlets m_protocolServlets;

    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvcpTcpServlet
    //
    //       Author: $author$
    //         Date: 7/31/2007
    ///////////////////////////////////////////////////////////////////////
    CEvcpTcpServlet() 
    {
    }
    ///////////////////////////////////////////////////////////////////////
    // Destructor: ~CEvcpTcpServlet
    //
    //      Author: $author$
    //        Date: 7/31/2007
    ///////////////////////////////////////////////////////////////////////
    virtual ~CEvcpTcpServlet()
    {
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: DeleteInstance
    //
    //   Author: $author$
    //     Date: 7/31/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError DeleteInstance() 
    {
        EvError error = EV_ERROR_NONE;
        delete this;
        return error;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: Initialize
    //
    //   Author: $author$
    //     Date: 7/31/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError Initialize(EvServletServer& server) 
    {
        EvError error = EV_ERROR_NONE;
        EvError error2;
        CEvcpServletAllocatorItem* item;

        DBF("() in...\n");

        if ((error2 = m_protocolServlets.Clear()))
            return EV_ERROR_FAILED;

        for (item = CEvcpServletAllocatorList::GetFirstItem(); 
             item; item = item->GetNextItem())
        {
            EvcpServletAllocator& allocator = item->GetAllocator();
            EvcpServlet* servlet;

            if ((servlet = allocator.AcquireServlet(error2)))
            {
                if ((error2 = servlet->Initialize(server)))
                {
                    DBE("() failed to initialize servlet\n");
                    error = EV_ERROR_INITIALIZE;
                }
                else if ((error = m_protocolServlets.AddServlet(*servlet)))
                {
                    DBE("() failed to add servlet\n");

                    if ((error2 = servlet->Finalize(server)))
                        DBE("() failed to finalize servlet\n");
                }
                else continue;

                if ((error2 = allocator.ReleaseServlet(*servlet)))
                    DBE("() failed to release servlet\n");
            }
            else 
            {
                DBE("() failed to acquire servlet\n");
                error = EV_ERROR_FAILED;
            }
            Finalize(server);
            break;
        }
        DBF("() ...out\n");
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: Finalize
    //
    //   Author: $author$
    //     Date: 7/31/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError Finalize(EvServletServer& server) 
    {
        EvError error = EV_ERROR_NONE;
        EvError error2;
        const_CEvcpServletsIterator i;
        EvcpServlet* servlet;

        DBF("() in...\n");
        for (i = m_protocolServlets.end(); i != m_protocolServlets.begin();)
        {
            if ((servlet = *(--i)))
            if ((error2 = servlet->Finalize(server)) && !error)
                error = EV_ERROR_FINALIZE;
        }
        if ((error2 = m_protocolServlets.Clear()) && !error)
            error = EV_ERROR_FAILED;
        DBF("() ...out\n");
        return error;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: Service
    //
    //   Author: $author$
    //     Date: 7/32/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError Service
    (EvServletRequest& request,
     EvServletResponse& response) 
    {
        EvError error = EV_ERROR_NONE;
        EvServletConnection& connection = request.GetConnection();
        EvCharReader& reader = request.GetReader();
        CEvcpServletConnection evcpConnection(connection);
        CEvcpServletRequest evcpRequest(request, evcpConnection);
        EvcpHeader& header = evcpRequest.GetHeader();
        EvcpHeaderHeading& heading = header.GetHeading();
        const_CEvcpHeaderFieldsIterator& iterator = header.GetFieldsIterator();
        EvcpHeaderField* field;
        LONG count,length;
        const char* chars;
        const char* chars2;
        EvcpServlet* protocolServlet;

        DBF("() in...\n");

        do
        {
            connection.SetKeepAlive(false);

            if (0 < (count = header.Read(reader)))
            {
                CEvcpServletResponse evcpResponse(evcpRequest, response);

                DBF("() <-- \"%s\"\n", heading.GetChars(length));

                for (field = header.GetFirstField(iterator);
                     field; field = header.GetNextField(iterator))
                {
                    if ((chars = field->GetFieldName(length)))
                    if ((chars2 = field->GetFieldValue(length)))
                        DBF("() <-- \"%s\" : \"%s\"\n", chars, chars2);
                }

                if ((chars = heading.GetProtocol(length)))
                if ((protocolServlet = m_protocolServlets.FindServlet(chars)))
                    protocolServlet->Service(evcpRequest, evcpResponse);
                else DBE("() unknown protocol \"%s\"\n", chars);
            }
            else break;
        }
        while (connection.GetKeepAlive());

        DBF("() ...out\n");
        return error;
    }
};
#endif // _CEVCPTCPSERVLET_HPP
