///////////////////////////////////////////////////////////////////////
//   File: cevcocontextevcpservlet.hpp
//
// Author: $author$
//   Date: 9/19/2007
//
//    $Id$
///////////////////////////////////////////////////////////////////////

#ifndef _CEVCOCONTEXTEVCPSERVLET_HPP
#define _CEVCOCONTEXTEVCPSERVLET_HPP

#include "cevcscontextevcpservlet.hpp"
#include "cevgetevcpresponse.hpp"
#include "cevfilesystementry.hpp"
#include "cevfiletimes2evcpheader.hpp"
#include "cev2filesystementrytimesdeligate.hpp"
#include "cevreadwritebuffer.hpp"

#define DEFAULT_CEVCOCONTEXTEVCPSERVLET_NAME "CO_CONTEXT"

///////////////////////////////////////////////////////////////////////
//  Class: CEvCoContextEvcpServlet
//
// Author: $author$
//   Date: 9/19/2007
///////////////////////////////////////////////////////////////////////
class CEvCoContextEvcpServlet
: public CEvcsContextEvcpServlet
{
public:
    typedef CEvcsContextEvcpServlet CExtends;
    typedef CEvCoContextEvcpServlet CDerives;

    typedef EvError (CDerives::*MService)
    (EvcpServletRequest& request,
     EvcpServletResponse& response);

    MService m_service;

    ULONG m_blockSize;
    ULONG m_blockLength;
    bool m_isBinary;
    bool m_isRecursive;

    CEvFilePath m_filePath;
    CEvFileSystemEntry m_fileEntry;
    CEv2FileSystemEntryTimesDeligate m_fileEntryTimes;
	CEvFileTimes2EvcpHeader m_fileTimes2Header;

    CEvCharReadWriteBuffer m_buffer;
    char* m_bufferChars;

    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvCoContextEvcpServlet
    //
    //       Author: $author$
    //         Date: 9/19/2007
    ///////////////////////////////////////////////////////////////////////
    CEvCoContextEvcpServlet
    (const char* name=DEFAULT_CEVCOCONTEXTEVCPSERVLET_NAME,
     LONG length=-1) 
    : CExtends(name, length),
      m_service(0),
      m_blockSize(0),
      m_blockLength(0),
      m_isBinary(false),
      m_isRecursive(false),
      m_fileEntryTimes(m_fileEntry)
    {
    }
    ///////////////////////////////////////////////////////////////////////
    // Destructor: ~CEvCoContextEvcpServlet
    //
    //      Author: $author$
    //        Date: 9/19/2007
    ///////////////////////////////////////////////////////////////////////
    virtual ~CEvCoContextEvcpServlet()
    {
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: ConnectionInitialize
    //
    //   Author: $author$
    //     Date: 9/19/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError ConnectionInitialize
    (EvcpServletConnection& connection) 
    {
        EvError error;
        DBF("() in...\n");
        if (!(error = CExtends::ConnectionInitialize(connection)))
            m_service = &CDerives::ServiceStartCheckOut;
        DBF("() ...out\n");
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: ConnectionFinalize
    //
    //   Author: $author$
    //     Date: 9/19/2007
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
    //     Date: 9/19/2007
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
    // Function: ServiceStartCheckOut
    //
    //   Author: $author$
    //     Date: 9/19/2007
    ///////////////////////////////////////////////////////////////////////
    EvError ServiceStartCheckOut
    (EvcpServletRequest& request,
     EvcpServletResponse& response) 
    {
        EvError error = EV_ERROR_NONE;
        EvcpStatus status = EVCP_STATUS_INTERNAL_SERVER_ERROR;
        EvcpHeader& reqHeader = request.GetHeader();
        EvcpHeaderHeading& reqHeading = reqHeader.GetHeading();
        EvCharWriter& writer = response.GetWriter();
        EvcpHeader& respHeader = response.GetHeader();
        CEvGetEvcpResponse getResponse(respHeader);
        const EvcpHeaderField* field;
        const char* chars;
        LONG length;
        EvError error2;

        DBF("() in...\n");

        SetKeepAlive(request, response);

		if ((field = GetRequiredHeaderField
		    (request, chars = EVCP_HEADER_FIELD_NAME_BLOCK_SIZE)))
        if (0 >= (m_blockSize = field->GetUnsignedFieldValue(length)))
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

		    if ((field = GetBoolHeaderField
		        (m_isRecursive, request, 
                 chars = EVCP_HEADER_FIELD_NAME_IS_RECURSIVE,
                 EVCP_HEADER_FIELD_VALUE_YES)))
                DBT
                ("() %s:%s\n", chars, m_isRecursive
                 ?EVCP_HEADER_FIELD_VALUE_YES
                 :EVCP_HEADER_FIELD_VALUE_NO);

                if ((m_bufferChars = AllocateBuffer(m_blockSize)))

                if (!(chars = reqHeading.
                    GetRequestPath(length)) || (0 >= length))
                    DBE("() missing or invalid request path\n");

                else if ((error2 = m_evcs->StartCheckOutOp
				        (m_filePath, m_fileEntry, chars, m_isBinary, m_isRecursive)))
				        DBE("() failed to start check out op\n");

                else if (0 <= (m_blockLength = ReadBlock(respHeader)))
                {
                    if ((chars = m_filePath.HasChars(length)))

                    if ((error2 = getResponse.AddFirstFields
                       (m_fileEntryTimes, chars, EVCP_REQUEST_ACTION_NAME_CO, 
                        EVCP_STATUS_DESC_OK, EVCP_STATUS_CODE_OK, 
                        m_isBinary, m_blockSize, m_blockLength)))
                        DBE("() failed to add first fields in header\n");

                    else status = EVCP_STATUS_OK;
                }
        }

        if (!(error2 = RespondStatus(response, status)))
        if (EVCP_STATUS_OK == status)
        {
            if ((error2 = getResponse.
                RemoveFirstFields(m_fileEntryTimes)))
                DBE("() failed to remove first fields in header\n");

            if (0 < m_blockLength)
                length = WriteBlock(writer);

            if (m_blockLength < m_blockSize)
                m_service = &CDerives::ServiceContinueCheckOut;
            else m_service = &CDerives::ServiceReadCheckOut;
        }

        DBF("() ...out\n");
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: ServiceContinueCheckOut
    //
    //   Author: $author$
    //     Date: 9/19/2007
    ///////////////////////////////////////////////////////////////////////
    EvError ServiceContinueCheckOut
    (EvcpServletRequest& request,
     EvcpServletResponse& response) 
    {
        EvError error = EV_ERROR_NONE;
        EvcpStatus status = EVCP_STATUS_INTERNAL_SERVER_ERROR;
        EvcpHeader& reqHeader = request.GetHeader();
        EvcpHeaderHeading& reqHeading = reqHeader.GetHeading();
        EvCharWriter& writer = response.GetWriter();
        EvcpHeader& respHeader = response.GetHeader();
        CEvGetEvcpResponse getResponse(respHeader);
        const char* chars;
        LONG length;
        EvError error2;

        DBF("() in...\n");

        SetKeepAlive(request, response);

        m_service = &CDerives::ServiceStartCheckOut;

        if ((error2 = m_evcs->ContinueCheckOutOp
            (m_filePath, m_fileEntry)))
		    DBE("() failed to continue check out op\n");
        
        else if (0 <= (m_blockLength = ReadBlock(respHeader)))
        {
            if ((chars = m_filePath.HasChars(length)))

            if ((error2 = getResponse.AddFirstFields
               (m_fileEntryTimes, chars, 
                EVCP_REQUEST_ACTION_NAME_CO, 
                EVCP_STATUS_DESC_OK, EVCP_STATUS_CODE_OK, 
                m_isBinary, m_blockSize, m_blockLength)))
                DBE("() failed to add first fields in header\n");

            else status = EVCP_STATUS_OK;
        }

        if (!(error2 = RespondStatus(response, status)))
        if (EVCP_STATUS_OK == status)
        {
            if ((error2 = getResponse.
                RemoveFirstFields(m_fileEntryTimes)))
                DBE("() failed to remove first fields in header\n");

            if (0 < m_blockLength)
                length = WriteBlock(writer);

            if (m_blockLength < m_blockSize)
                m_service = &CDerives::ServiceContinueCheckOut;
            else m_service = &CDerives::ServiceReadCheckOut;
        }
        DBF("() ...out\n");
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: ServiceReadCheckOut
    //
    //   Author: $author$
    //     Date: 9/19/2007
    ///////////////////////////////////////////////////////////////////////
    EvError ServiceReadCheckOut
    (EvcpServletRequest& request,
     EvcpServletResponse& response) 
    {
        EvError error = EV_ERROR_NONE;
        EvcpStatus status = EVCP_STATUS_INTERNAL_SERVER_ERROR;
        EvcpHeader& reqHeader = request.GetHeader();
        EvcpHeaderHeading& reqHeading = reqHeader.GetHeading();
        EvCharWriter& writer = response.GetWriter();
        EvcpHeader& respHeader = response.GetHeader();
        CEvGetEvcpResponse getResponse(respHeader);
        LONG length;
        EvError error2;

        DBF("() in...\n");

        SetKeepAlive(request, response);

        m_service = &CDerives::ServiceStartCheckOut;

        if (0 <= (m_blockLength = ReadBlock(respHeader)))
        {
            if ((error2 = getResponse.SetFields(m_blockLength)))
                DBE("() failed to set fields in header\n");

            else status = EVCP_STATUS_OK;
        }

        if (!(error2 = RespondStatus(response, status)))
        if (EVCP_STATUS_OK == status)
        {
            if (0 < m_blockLength)
                length = WriteBlock(writer);

            if (m_blockLength < m_blockSize)
                m_service = &CDerives::ServiceContinueCheckOut;
            else m_service = &CDerives::ServiceReadCheckOut;
        }
        DBF("() ...out\n");
        return error;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: ReadBlock
    //
    //   Author: $author$
    //     Date: 8/21/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG ReadBlock
    (EvcpHeader& respHeader) 
    {
        LONG blockLength;
        const EvcpHeaderField* field;
        EvError error;

        if (0 > (blockLength = m_evcs->
            ReadOpData(m_bufferChars, m_blockSize)))
            DBE("() failed to read block[%d]\n", m_blockSize);
		else
        {
			DBT("() read block[%d]\n", blockLength);

			if ((field = respHeader.SetFieldUnsigned
				(EVCP_HEADER_FIELD_NAME_BLOCK_LENGTH, blockLength)))
				return blockLength;

			DBE
			("() failed to set header field \"%s\" to %d\n", 
			 EVCP_HEADER_FIELD_NAME_BLOCK_LENGTH, blockLength);
        }

        if ((error = m_evcs->CancelOp()))
            DBE("() failed to cancel evcs op\n");

        return -EV_ERROR_FAILED;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: WriteBlock
    //
    //   Author: $author$
    //     Date: 8/29/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG WriteBlock
    (EvCharWriter& writer) 
    {
        LONG wrote;
        if (0 > (wrote = writer.Write(m_bufferChars, m_blockLength)))
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

#endif // _CEVCOCONTEXTEVCPSERVLET_HPP
