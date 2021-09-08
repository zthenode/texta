///////////////////////////////////////////////////////////////////////
//   File: cevcicontextevcpservlet.hpp
//
// Author: $author$
//   Date: 9/21/2007
//
//    $Id$
///////////////////////////////////////////////////////////////////////

#ifndef _CEVCICONTEXTEVCPSERVLET_HPP
#define _CEVCICONTEXTEVCPSERVLET_HPP

#include "cevcscontextevcpservlet.hpp"
#include "cevputevcpresponse.hpp"
#include "cevfilesystementrytimes.hpp"
#include "cevcpheader2filetimes.hpp"
#include "cevreadwritebuffer.hpp"

#define DEFAULT_CEVCICONTEXTEVCPSERVLET_NAME "CI_CONTEXT"

///////////////////////////////////////////////////////////////////////
//  Class: CEvCiContextEvcpServlet
//
// Author: $author$
//   Date: 9/21/2007
///////////////////////////////////////////////////////////////////////
class CEvCiContextEvcpServlet
: public CEvcsContextEvcpServlet
{
public:
    typedef CEvcsContextEvcpServlet CExtends;
    typedef CEvCiContextEvcpServlet CDerives;

    typedef EvError (CDerives::*MService)
    (EvcpServletRequest& request,
     EvcpServletResponse& response);

    MService m_service;

    ULONG m_blockSize;
    ULONG m_blockLength;
    bool m_isBinary;

    CEvCharReadWriteBuffer m_buffer;
    char* m_bufferChars;

    CEvFileSystemEntryTimes m_fileEntryTimes;
    CEvcpHeader2FileTimes m_header2FileTimes;

    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvCiContextEvcpServlet
    //
    //       Author: $author$
    //         Date: 9/21/2007
    ///////////////////////////////////////////////////////////////////////
    CEvCiContextEvcpServlet
    (const char* name=DEFAULT_CEVCICONTEXTEVCPSERVLET_NAME,
     LONG length=-1) 
    : CExtends(name, length),
      m_service(0),
      m_blockSize(0),
      m_blockLength(0),
      m_isBinary(false)
    {
    }
    ///////////////////////////////////////////////////////////////////////
    // Destructor: ~CEvCiContextEvcpServlet
    //
    //      Author: $author$
    //        Date: 9/21/2007
    ///////////////////////////////////////////////////////////////////////
    virtual ~CEvCiContextEvcpServlet()
    {
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: ConnectionInitialize
    //
    //   Author: $author$
    //     Date: 9/21/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError ConnectionInitialize
    (EvcpServletConnection& connection) 
    {
        EvError error;
        DBF("() in...\n");
        if (!(error = CExtends::ConnectionInitialize(connection)))
            m_service = &CDerives::ServiceStartCheckIn;
        DBF("() ...out\n");
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: ConnectionFinalize
    //
    //   Author: $author$
    //     Date: 9/21/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError ConnectionFinalize
    (EvcpServletConnection& connection) 
    {
        EvError error;
        DBF("() in...\n");
        m_service = 0;
        error = CExtends::ConnectionFinalize(connection);
        DBF("() ...out\n");
        return error;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: Service
    //
    //   Author: $author$
    //     Date: 9/21/2007
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
        else
        {
		    SetKeepAlive(request, response);
            RespondStatus(response, status);
        }
        DBF("() ...out\n");
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: ServiceStartCheckIn
    //
    //   Author: $author$
    //     Date: 9/21/2007
    ///////////////////////////////////////////////////////////////////////
    EvError ServiceStartCheckIn
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
        const char* chars;
        LONG length;
        EvError error2;
        bool readBlock;

        DBF("() in...\n");

        SetKeepAlive(request, response);

		if ((field = GetRequiredUnsignedHeaderField
		    (m_blockLength, request, 
             chars = EVCP_HEADER_FIELD_NAME_BLOCK_LENGTH)))
        {
            DBT("() %s:%d\n", chars, m_blockLength);

		    if ((field = GetRequiredHeaderField
		        (request, chars = EVCP_HEADER_FIELD_NAME_BLOCK_SIZE)))
            if ((0 >= (m_blockSize = field->GetUnsignedFieldValue(length)))
                || (m_blockLength > m_blockSize))
                DBE("() invalid block size %d\n", m_blockSize);
            else
            {
                DBT("() %s:%d\n", chars, m_blockSize);

		        if ((field = GetBoolHeaderField
		            (m_isBinary, request, 
                     chars = EVCP_HEADER_FIELD_NAME_IS_BINARY,
                     EVCP_HEADER_FIELD_VALUE_YES)))
                    DBT
                    ("() %s:%s\n", chars, m_isBinary
                     ?EVCP_HEADER_FIELD_VALUE_YES
                     :EVCP_HEADER_FIELD_VALUE_NO);

                if ((readBlock = (0 != (m_bufferChars = AllocateBuffer(m_blockSize)))))
                if (!(readBlock = (0 >= m_blockLength)))
                    readBlock = (m_blockLength == (ULONG)(length = ReadBlock(reader)));

                if (readBlock)
                if (!(chars = reqHeading.
                    GetRequestPath(length)) || (0 >= length))
                    DBE("() missing or invalid request path\n");

                else if ((error2 = m_header2FileTimes.
                         GetFileTimeFields(m_fileEntryTimes, reqHeader)))
			             DBE("() failed to get file times\n");

                else if ((error2 = m_evcs->StartCheckInOp
			            (chars, m_fileEntryTimes, m_isBinary)))
			            DBE("() failed to start check in op\n");

                else 
                {
                    if (!(readBlock = (0 >= m_blockLength)))
                        readBlock = (m_blockLength == (ULONG)(length = WriteBlock()));

                    if (readBlock)
                    if (!(readBlock = (m_blockLength >= m_blockSize)))
                    if (!(readBlock = !(error2 = m_evcs->FinishOp())))
                        DBE("() failed to finish op\n");

                    if (readBlock)
                    if ((error2 = putResponse.SetFields
                       (EVCP_REQUEST_ACTION_NAME_CI, 
                        EVCP_STATUS_DESC_OK, EVCP_STATUS_CODE_OK)))
                        DBE("() failed to set fields in header\n");

                    else status = EVCP_STATUS_OK;
                }
            }
        }

        if (!(error2 = RespondStatus(response, status)))
        if (EVCP_STATUS_OK == status)
        if (m_blockLength >= m_blockSize)
            m_service = &CDerives::ServiceWriteCheckIn;

        DBF("() ...out\n");
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: ServiceWriteCheckIn
    //
    //   Author: $author$
    //     Date: 9/21/2007
    ///////////////////////////////////////////////////////////////////////
    EvError ServiceWriteCheckIn
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
        const char* chars;
        LONG length;
        EvError error2;
        bool readBlock;

        DBF("() in...\n");

        m_service = &CDerives::ServiceStartCheckIn;

        SetKeepAlive(request, response);

		if ((field = GetRequiredUnsignedHeaderField
		    (m_blockLength, request, 
             chars = EVCP_HEADER_FIELD_NAME_BLOCK_LENGTH)))
        {
            DBT("() %s:%d\n", chars, m_blockLength);

            if (!(readBlock = (0 >= m_blockLength)))
            if ((m_bufferChars = AllocateBuffer(m_blockLength)))
            if (m_blockLength == (ULONG)(length = ReadBlock(reader)))
                readBlock = (m_blockLength == (ULONG)(length = WriteBlock()));

            if (readBlock)
            if (!(readBlock = (m_blockLength >= m_blockSize)))
            if (!(readBlock = !(error2 = m_evcs->FinishOp())))
                DBE("() failed to finish op\n");

            if (readBlock)
            if ((error2 = putResponse.SetFields
               (EVCP_REQUEST_ACTION_NAME_CI, 
                EVCP_STATUS_DESC_OK, EVCP_STATUS_CODE_OK)))
                DBE("() failed to set fields in header\n");

            else status = EVCP_STATUS_OK;
        }

        if (!(error2 = RespondStatus(response, status)))
        if (EVCP_STATUS_OK == status)
        if (m_blockLength >= m_blockSize)
            m_service = &CDerives::ServiceWriteCheckIn;

        DBF("() ...out\n");
        return error;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: ReadBlock
    //
    //   Author: $author$
    //     Date: 9/21/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG ReadBlock
    (EvCharReader& reader) 
    {
        LONG read;
        if (m_blockLength != (ULONG)(read = reader.Read(m_bufferChars, m_blockLength)))
            DBE("() failed to read block[%d]\n", m_blockLength);
        else DBT("() read block[%d]\n", m_blockLength);
        return read;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: WriteBlock
    //
    //   Author: $author$
    //     Date: 9/21/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG WriteBlock() 
    {
        LONG wrote;
        if (m_blockLength != (ULONG)(wrote = m_evcs->
            WriteOpData(m_bufferChars, m_blockLength)))
            DBE("() failed to write block[%d]\n", m_blockLength);
        else DBT("() wrote block[%d]\n", m_blockLength);
        return wrote;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: AllocateBuffer
    //
    //   Author: $author$
    //     Date: 8/24/2007
    ///////////////////////////////////////////////////////////////////////
    virtual char* AllocateBuffer
    (ULONG bufferSize) 
    {
        char* chars = 0;
        EvError error2;
        LONG length;

        if (!(error2 = m_buffer.AllocateBuffer(bufferSize)))
            chars = m_buffer.GetWriteBuffer(length);
        return chars;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: FreeBuffer
    //
    //   Author: $author$
    //     Date: 8/24/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError FreeBuffer() 
    {
        EvError error = m_buffer.FreeBuffer();
        return error;
    }
};

#endif // _CEVCICONTEXTEVCPSERVLET_HPP
