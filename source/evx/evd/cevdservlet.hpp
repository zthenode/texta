///////////////////////////////////////////////////////////////////////
//   File: cevdservlet.hpp
//
// Author: $author$
//   Date: 4/13/2007
//
//    $Id$
///////////////////////////////////////////////////////////////////////

#ifndef _CEVDSERVLET_HPP
#define _CEVDSERVLET_HPP

#include "cevtcpservlet.hpp"
#include "cevcpservlets.hpp"
#include "cevcpservletconnection.hpp"
#include "cevcpservletresponse.hpp"
#include "cevcpservletrequest.hpp"
#include "cevcpservletallocator.hpp"
#include "cevcpheader.hpp"
#include "cevcp.hpp"
#include "cevreadaheadcharreader.hpp"
#include "cevstring.hpp"

///////////////////////////////////////////////////////////////////////
//  Class: CEvDServlet
//
// Author: $author$
//   Date: 4/13/2007
///////////////////////////////////////////////////////////////////////
class CEvDServlet
: public CEvTcpServlet
{
public:
    typedef CEvTcpServlet CExtends;
    typedef CEvDServlet CDerives;

    CEvcpServlets m_protocolServlets;

    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvDServlet
    //
    //       Author: $author$
    //         Date: 10/14/2007
    ///////////////////////////////////////////////////////////////////////
    CEvDServlet() 
    {
    }
    ///////////////////////////////////////////////////////////////////////
    // Destructor: ~CEvDServlet
    //
    //      Author: $author$
    //        Date: 10/14/2007
    ///////////////////////////////////////////////////////////////////////
    virtual ~CEvDServlet()
    {
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: DeleteInstance
    //
    //   Author: $author$
    //     Date: 4/13/2007
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
    //     Date: 4/22/2007
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
                if ((error2 = servlet->SetRootServlet(this)))
                {
                    DBE("() failed to set root servlet\n");
                    error = EV_ERROR_FAILED;
                }
                else 
                if ((error2 = servlet->Initialize(server)))
                {
                    DBE("() failed to initialize servlet\n");
                    error = EV_ERROR_INITIALIZE;
                }
                else 
                if ((error = m_protocolServlets.AddServlet(*servlet)))
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
    //     Date: 4/22/2007
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
            {
                DBE("() failed to finalize servlet\n");
                error = EV_ERROR_FINALIZE;
            }
        }

        if ((error2 = m_protocolServlets.Clear()) && !error)
            error = EV_ERROR_FAILED;

        DBF("() ...out\n");
        return error;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: ConnectionInitialize
    //
    //   Author: $author$
    //     Date: 9/22/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError ConnectionInitialize
    (EvServletConnection& connection) 
    {
        EvError error = EV_ERROR_FAILED;
        EvError error2;
        CEvcpServletConnection* evcpConnection;

        if ((evcpConnection = new CEvcpServletConnection(connection, false)))
        {
            if (!(error2 = evcpConnection->SetServlet(this)))
            if (!(error2 = evcpConnection->Initialize()))
            if (!(error2 = m_protocolServlets.ConnectionInitialize(*evcpConnection)))
            if (!(error2 = connection.AddServletConnection(*evcpConnection)))
                return error = EV_ERROR_NONE;
            evcpConnection->DeleteInstance();
        }
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: ConnectionFinalize
    //
    //   Author: $author$
    //     Date: 9/22/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError ConnectionFinalize
    (EvServletConnection& connection) 
    {
        EvError error = EV_ERROR_FAILED;
        EvError error2;
        EvcpServletConnection* thisEvcpConnection;
        EvServletConnection* thisConnection;

        if ((thisConnection = connection.FindServletConnection(*this)))
        if ((thisEvcpConnection = thisConnection->GetEvcpServletConnection()))
        if (!(error2 = m_protocolServlets.ConnectionFinalize(*thisEvcpConnection))
            && !(error2 = thisEvcpConnection->Finalize()))
            error = EV_ERROR_NONE;

        return error;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: Service
    //
    //   Author: $author$
    //     Date: 4/12/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError Service
    (EvServletRequest& request,
     EvServletResponse& response) 
    {
        EvCharReader& reader = request.GetReader();
        CEvReadAheadCharReader readAheadReader(reader);
        EvError error = EV_ERROR_FAILED;
        bool isBinary = false;
        LONG length;
        char c;

        if (0 < (length = readAheadReader.ReadAhead(&c, 1)))
        {
            switch(c)
            {
            case '\n':
            case '\r':
            case '\t':
            case '\v':
                break;
            default:
                isBinary = ((c < 32) || (c > 127));
            }

            if (isBinary)
            {
                DBT("() binary protocol starting with '%u'\n", ((unsigned char)c));
                error = ServiceBinaryProtocol
                (readAheadReader, request, response);
            }
            else error = ServiceTextProtocol
                (readAheadReader, request, response);
        }
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: ServiceBinaryProtocol
    //
    //   Author: $author$
    //     Date: 4/12/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError ServiceBinaryProtocol
    (EvCharReader& reader,
     EvServletRequest& request,
     EvServletResponse& response) 
    {
        EvError error = EV_ERROR_FAILED;
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: ServiceTextProtocol
    //
    //   Author: $author$
    //     Date: 4/12/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError ServiceTextProtocol
    (EvCharReader& reader,
     EvServletRequest& request,
     EvServletResponse& response) 
    {
        EvError error = EV_ERROR_FAILED;
        EvServletConnection& connection = request.GetConnection();
        EvcpServletConnection* thisEvcpConnection;
        EvServletConnection* thisConnection;
        EvError error2;

        if ((thisConnection = connection.FindServletConnection(*this)))
        if ((thisEvcpConnection = thisConnection->GetEvcpServletConnection()))
            error = ServiceEvcpConnection
            (reader, request, response, 
             connection, *thisEvcpConnection);
        else
        {
            CEvcpServletConnection evcpConnection(connection);
            if (!(error2 = evcpConnection.Initialize()))
            {
                error = ServiceEvcpConnection
                (reader, request, response, 
                 connection, evcpConnection);
                error2 = evcpConnection.Finalize();
            }
        }
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: ServiceEvcpConnection
    //
    //   Author: $author$
    //     Date: 4/12/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError ServiceEvcpConnection
    (EvCharReader& reader,
     EvServletRequest& request,
     EvServletResponse& response,
     EvServletConnection& connection,
     EvcpServletConnection& evcpConnection) 
    {
        EvError error = EV_ERROR_NONE;
        CEvcpServletRequest evcpRequest
        (request, evcpConnection, reader);
        EvcpHeader& header = evcpRequest.GetHeader();
        EvcpHeaderHeading& heading = header.GetHeading();
        EvcpServlet* protocolServlet;
        LONG count,length;
        const char* chars;

        DBF("() in...\n");

        do
        {
            connection.SetKeepAlive(false);

            if (0 < (count = header.Read(reader)))
            {
                CEvcpServletResponse evcpResponse
                (evcpRequest, response, evcpConnection);

                DBT("() <-- \"%s\"\n", heading.GetChars(length));

                if (IS_DBT)
                {
                    const_CEvcpHeaderFieldsIterator& iterator = header.GetFieldsIterator();
                    EvcpHeaderField* field;
                    const char* chars2;

                    for (field = header.GetFirstField(iterator);
                         field; field = header.GetNextField(iterator))
                    {
                        if ((chars = field->GetFieldName(length)))
                        if ((chars2 = field->GetFieldValue(length)))
                            DBT("() <-- \"%s\" : \"%s\"\n", chars, chars2);
                    }
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
#endif // _CEVDSERVLET_HPP
