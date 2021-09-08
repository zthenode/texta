///////////////////////////////////////////////////////////////////////
//   File: cevputcontextevcpservlet.hpp
//
// Author: $author$
//   Date: 10/4/2007
//
//    $Id$
///////////////////////////////////////////////////////////////////////

#ifndef _CEVPUTCONTEXTEVCPSERVLET_HPP
#define _CEVPUTCONTEXTEVCPSERVLET_HPP

#include "cevcsarchivecontextevcpservlet.hpp"
#include "cevcscontextevcpservlet.hpp"
#include "evcsarchive.hpp"
#include "cevcsentry.hpp"
#include "cevreadwritebuffer.hpp"
#include "cevputevcpresponse.hpp"
#include "cevcpheader2filetimes.hpp"

#define DEFAULT_CEVPUTCONTEXTEVCPSERVLET_NAME "PUT_CONTEXT"
#define DEFAULT_EVCS_PUT_BLOCK_SIZE 4096

///////////////////////////////////////////////////////////////////////
//  Class: CEvPutContextEvcpServlet
//
// Author: $author$
//   Date: 10/4/2007
///////////////////////////////////////////////////////////////////////
class CEvPutContextEvcpServlet
: public CEvcsArchiveContextEvcpServlet
{
public:
    typedef CEvcsArchiveContextEvcpServlet CExtends;
    typedef CEvPutContextEvcpServlet CDerives;

    typedef EvError (CDerives::*MService)
    (EvcpServletRequest& request,
     EvcpServletResponse& response);

    MService m_service;
    EvcsPut* m_put;

    EvFileSystemEntryTimes& m_entryFileTimes;
    CEvcpHeader2FileTimes m_header2FileTimes;

    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvPutContextEvcpServlet
    //
    //       Author: $author$
    //         Date: 10/4/2007
    ///////////////////////////////////////////////////////////////////////
    CEvPutContextEvcpServlet
    (const char* name=DEFAULT_CEVPUTCONTEXTEVCPSERVLET_NAME,
     LONG length=-1) 
    : CExtends(name, length),
      m_service(0),
      m_put(0),
      m_entryFileTimes(m_entry.GetFileTimes())
    {
    }
    ///////////////////////////////////////////////////////////////////////
    // Destructor: ~CEvPutContextEvcpServlet
    //
    //      Author: $author$
    //        Date: 10/4/2007
    ///////////////////////////////////////////////////////////////////////
    virtual ~CEvPutContextEvcpServlet()
    {
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: ConnectionInitialize
    //
    //   Author: $author$
    //     Date: 10/4/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError ConnectionInitialize
    (EvcpServletConnection& connection) 
    {
        EvError error = EV_ERROR_NONE;
        DBF("() in...\n");

        if (!(error = CExtends::ConnectionInitialize(connection)))
            m_service = &CDerives::ServiceStart;

        DBF("() ...out\n");
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: ConnectionFinalize
    //
    //   Author: $author$
    //     Date: 10/4/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError ConnectionFinalize
    (EvcpServletConnection& connection) 
    {
        EvError error = EV_ERROR_NONE;
        DBF("() in...\n");
        error = CExtends::ConnectionFinalize(connection);
        DBF("() ...out\n");
        return error;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: Service
    //
    //   Author: $author$
    //     Date: 10/4/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError Service
    (EvcpServletRequest& request,
     EvcpServletResponse& response) 
    {
        EvError error = EV_ERROR_NONE;
        EvcpStatus status = EVCP_STATUS_INTERNAL_SERVER_ERROR;

        DBF("() in...\n");
        if (m_service)
            error = (this->*m_service)(request, response);
        else RespondStatus(response, status);
        DBF("() ...out\n");
        return error;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: ServiceStart
    //
    //   Author: $author$
    //     Date: 10/4/2007
    ///////////////////////////////////////////////////////////////////////
    EvError ServiceStart
    (EvcpServletRequest& request,
     EvcpServletResponse& response) 
    {
        EvError error = EV_ERROR_NONE;
        EvcpStatus status = EVCP_STATUS_INTERNAL_SERVER_ERROR;
        EvCharReader& reader = request.GetReader();
        EvcpHeader& reqHeader = request.GetHeader();
        EvcpHeaderHeading& reqHeading = reqHeader.GetHeading();
        EvCharWriter& writer = response.GetWriter();
        EvcpHeader& respHeader = response.GetHeader();
        EvcpHeaderHeading& respHeading = respHeader.GetHeading();
        EvcpServletConnection& connection = response.GetEvcpConnection();
        CEvPutEvcpResponse putResponse(respHeader);
        const EvcpHeaderField* field;
        MService service;
        const char* chars;
        LONG length;
        EvError error2;

        DBF("() in...\n");

        m_service = &CDerives::ServiceStart;

		if ((field = GetRequiredUnsignedHeaderField
		    (m_blockLength, request, 
             chars = EVCP_HEADER_FIELD_NAME_BLOCK_LENGTH)))

		if ((field = GetRequiredUnsignedHeaderField
		    (m_blockSize, request, 
             chars = EVCP_HEADER_FIELD_NAME_BLOCK_SIZE)))

        if (0 >= (m_blockSize))
            DBE("() invalid block size %d\n", m_blockSize);

        else
        if (!(chars = reqHeading.
            GetRequestPath(length)) || (0 >= length))
            DBE("() missing or invalid request path\n");

        else
        if (!(m_bufferChars = AllocateBuffer(m_blockSize)))
            DBE("() failed to allocate buffer\n");

        else
        if ((service = ReadBlock(reader)))
        {
            m_service = service;

            if ((error2 = m_header2FileTimes.
                GetFileTimeFields(m_entryFileTimes, reqHeader)))
			    DBE("() failed to get file times\n");

            else 
            if (!(error2 = PutEntry(chars)))
            {
                if (0 < (length = WriteBlock()))
                if ((chars = GetName(length)))
                if ((error2 = putResponse.SetFields
                   (chars, EVCP_STATUS_DESC_OK, EVCP_STATUS_CODE_OK)))
                    DBE("() failed to set fields in header\n");

                else status = EVCP_STATUS_OK;
            }
        }

        RespondStatus(response, status);
        DBF("() ...out\n");
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: ServiceContinue
    //
    //   Author: $author$
    //     Date: 10/4/2007
    ///////////////////////////////////////////////////////////////////////
    EvError ServiceContinue
    (EvcpServletRequest& request,
     EvcpServletResponse& response) 
    {
        EvError error = EV_ERROR_NONE;
        EvcpStatus status = EVCP_STATUS_INTERNAL_SERVER_ERROR;
        EvCharReader& reader = request.GetReader();
        EvcpHeader& reqHeader = request.GetHeader();
        EvcpHeaderHeading& reqHeading = reqHeader.GetHeading();
        EvCharWriter& writer = response.GetWriter();
        EvcpHeader& respHeader = response.GetHeader();
        EvcpHeaderHeading& respHeading = respHeader.GetHeading();
        EvcpServletConnection& connection = response.GetEvcpConnection();
        CEvPutEvcpResponse putResponse(respHeader);
        const EvcpHeaderField* field;
        MService service;
        const char* chars;
        LONG length;
        EvError error2;

        DBF("() in...\n");

        m_service = &CDerives::ServiceStart;

		if ((field = GetRequiredUnsignedHeaderField
		    (m_blockLength, request, 
             chars = EVCP_HEADER_FIELD_NAME_BLOCK_LENGTH)))

        if ((service = ReadBlock(reader)))
        {
            m_service = service;

            if (0 < (length = WriteBlock()))
            if ((chars = GetName(length)))
            if ((error2 = putResponse.SetFields
               (chars, EVCP_STATUS_DESC_OK, EVCP_STATUS_CODE_OK)))
                DBE("() failed to set fields in header\n");

            else status = EVCP_STATUS_OK;
        }

        RespondStatus(response, status);
        DBF("() ...out\n");
        return error;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: PutEntry
    //
    //   Author: $author$
    //     Date: 10/4/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError PutEntry
    (const char* entryPathName) 
    {
        EvError error = EV_ERROR_FAILED;
        EvError error2;

        if (m_archive)
        if (m_put)
        {
            if ((error2 = m_put->Cancel()))
                DBE("() failed to cancel pending put\n");

            else if ((error2 = m_put->Open
                     (m_entry, entryPathName)))
                DBE("() failed on put open\n");

            else error = EV_ERROR_NONE;
        }
        else
        if ((m_put = m_archive->PutEntry
            (error2, m_entry, entryPathName)))
            error = EV_ERROR_NONE;

        else DBE("() failed on archive put entry\n");

        return error;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: ReadBlock
    //
    //   Author: $author$
    //     Date: 10/5/2007
    ///////////////////////////////////////////////////////////////////////
    MService ReadBlock(EvCharReader& reader) 
    {
        MService service = 0;
        LONG read;
        if (m_blockLength != (ULONG)(read = reader.
            Read(m_bufferChars, m_blockLength)))
            DBE("() failed to read block[%d]\n", m_blockLength);
        else 
        {
            DBT("() read block[%d]\n", m_blockLength);

            if (m_blockLength < m_blockSize)
                service = &CDerives::ServiceStart;
            else service = &CDerives::ServiceContinue;
        }
        return service;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: WriteBlock
    //
    //   Author: $author$
    //     Date: 10/5/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG WriteBlock() 
    {
        LONG length = -EV_ERROR_FAILED;
        LONG wrote;
        EvError error2;

        if (m_put)
        if (m_blockLength != (ULONG)(wrote = m_put->
            WriteBlock(m_entry, m_bufferChars, m_blockLength)))
            DBE("() failed to write block[%d]\n", m_blockLength);
        else 
        {
            DBT("() wrote block[%d]\n", m_blockLength);

            if (m_blockLength < m_blockSize)
            {
                if ((error2 = m_put->Finish()))
                    DBE("() failed to finish put\n");
                else length = wrote;
            }
            else length = wrote;
        }
        return length;
    }
};

#endif // _CEVPUTCONTEXTEVCPSERVLET_HPP
