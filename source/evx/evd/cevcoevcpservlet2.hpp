///////////////////////////////////////////////////////////////////////
//   File: cevcoevcpservlet.hpp
//
// Author: $author$
//   Date: 4/26/2007
//
//    $Id$
///////////////////////////////////////////////////////////////////////

#ifndef _CEVCOEVCPSERVLET_HPP
#define _CEVCOEVCPSERVLET_HPP

#include "cevcsevcpservlet.hpp"
#include "cevcoservletcontext.hpp"
#include "cevcpservlet.hpp"
#include "cevcpservlets.hpp"
#include "cevfiletimes2evcpheader.hpp"
#include "cev2filesystementrytimesdeligate.hpp"
#include "cevstringwriter.hpp"

#define DEFAULT_CEVCOEVCPSERVLET_NAME EVCP_REQUEST_ACTION_NAME_CO
#define DEFAULT_CEVCOEVCPSERVLET_BUFFER_SIZE 4096

///////////////////////////////////////////////////////////////////////
//  Class: CEvCoEvcpServlet
//
// Author: $author$
//   Date: 4/26/2007
///////////////////////////////////////////////////////////////////////
class CEvCoEvcpServlet
: public CEvcsEvcpServlet
{
public:
    typedef CEvcsEvcpServlet CExtends;
    typedef CEvCoEvcpServlet CDerives;

    CEvFilePath m_coPath;
    CEvFileSystemEntry m_fileEntry;
    CEv2FileSystemEntryTimesDeligate m_fileEntryTimes;
	CEvFileTimes2EvcpHeader m_fileTimes2Header;
    char m_defaultBuffer[DEFAULT_CEVCOEVCPSERVLET_BUFFER_SIZE];
    char* m_buffer;
    LONG m_bufferSize;

    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvCoEvcpServlet
    //
    //       Author: $author$
    //         Date: 4/26/2007
    ///////////////////////////////////////////////////////////////////////
    CEvCoEvcpServlet
    (const char* name=DEFAULT_CEVCOEVCPSERVLET_NAME,
     LONG length=-1) 
    : CExtends(name, length),
      m_fileEntryTimes(m_fileEntry),
      m_buffer(m_defaultBuffer),
      m_bufferSize(DEFAULT_CEVCOEVCPSERVLET_BUFFER_SIZE)
    {
    }
    ///////////////////////////////////////////////////////////////////////
    // Destructor: ~CEvCoEvcpServlet
    //
    //      Author: $author$
    //        Date: 4/26/2007
    ///////////////////////////////////////////////////////////////////////
    virtual ~CEvCoEvcpServlet()
    {
		EvError error;
		if ((error = FreeBuffer()))
			throw(error);
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: Initialize
    //
    //   Author: $author$
    //     Date: 4/26/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError Initialize(EvServletServer& server) 
    {
        EvError error = EV_ERROR_NONE;
        EvError error2;
        EvcpServletContext* parentContext;
        Evcs* evcs;
        const char* chars;

        DBF("() in...\n");
        if ((chars = GetCheckOutDirectory(server)))
		{
			DBT("() check out directory is \"%s\"\n", chars);
			if ((parentContext = GetParentContext(error2)))
			if ((evcs = parentContext->AcquireEvcs(error2)))
			{
				evcs->SetCoDir(chars);
				parentContext->ReleaseEvcs(*evcs);
			}
		}
        DBF("() ...out\n");
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: Finalize
    //
    //   Author: $author$
    //     Date: 4/26/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError Finalize(EvServletServer& server) 
    {
        EvError error = EV_ERROR_NONE;
        DBF("() in...\n");
        DBF("() ...out\n");
        return error;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: Service
    //
    //   Author: $author$
    //     Date: 4/26/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError Service
    (EvcpServletRequest& request,
     EvcpServletResponse& response) 
    {
        EvError error = EV_ERROR_NONE;
        EvcpStatus status = EVCP_STATUS_INTERNAL_SERVER_ERROR;
        EvError error2;
        bool keepAlive = false;
        bool isBinary = false;
		bool isRecursive = false;
        bool isFirstRequest = false;
        bool isFirstBlock = false;
        ULONG block = -1;
        ULONG blockSize = -1;
        LONG blockLength = -1;
        EvCharReader& reader = request.GetReader();
        EvcpHeader& reqHeader = request.GetHeader();
        EvcpHeaderHeading& reqHeading = reqHeader.GetHeading();
        EvCharWriter& writer = response.GetWriter();
        EvcpHeader& respHeader = response.GetHeader();
        EvcpServletConnection& connection = response.GetEvcpConnection();
        const EvcpHeaderField* field;
        EvcpServletContext* parentContext;
        EvCoServletContext* coContext;
        Evcs* evcs;
		const char* valueChars;
		const char* chars;
		LONG length;

        DBF("() in...\n");

		SetKeepAlive(request, response);

        if ((parentContext = GetParentContext(error2)))
        if ((evcs = parentContext->AcquireEvcs(error2)))
        {
            if ((coContext = GetCoContext(*evcs, connection)))
            {
                blockSize = coContext->GetBlockSize(error2);

                if (error)
                    DBE("() failed to get block size from context\n");

                else if ((isFirstBlock = (isFirstRequest = (1 > blockSize))))
                {
                    DBT("() first request (blockSize=%d)\n", blockSize);

		            if ((field = GetRequiredHeaderField
			            (request, chars = EVCP_HEADER_FIELD_NAME_BLOCK_SIZE)))
                    if (0 >= (blockSize = field->GetUnsignedFieldValue(length)))
                        DBE("() invalid block size %d\n", blockSize);
                    else if (!(error2 = SetBufferSize(blockSize)))
		            {
                        DBT("() %s %d\n", chars, blockSize);

                        coContext->SetBlockSize(blockSize);

                        if ((field = reqHeader.FindField
                            (chars = EVCP_HEADER_FIELD_NAME_IS_BINARY)))
                        if ((valueChars = field->GetFieldValue(length)))
                        {
                            DBT("() %s \"%s\"\n", chars, valueChars);
                            isBinary = (!field->CompareFieldValue
                            (EVCP_HEADER_FIELD_VALUE_YES));
                        }

                        if ((field = reqHeader.FindField
                            (chars = EVCP_HEADER_FIELD_NAME_IS_RECURSIVE)))
                        if ((valueChars = field->GetFieldValue(length)))
                        {
                            DBT("() %s \"%s\"\n", chars, valueChars);
                            isRecursive = (!field->CompareFieldValue
                            (EVCP_HEADER_FIELD_VALUE_YES));
                        }

                        if (!(chars = reqHeading.
                            GetRequestPath(length)) || (0 >= length))
                            DBE("() missing or invalid request path\n");

                        else if ((error2 = evcs->StartCheckOutOp
					            (m_fileEntry, chars, isBinary, isRecursive)))
					            DBE("() failed to start check out op\n");

                        else if ((error2 = m_fileTimes2Header.
							     SetFileTimeFields(respHeader, m_fileEntryTimes)))
                                 DBE("() failed to set file times in header\n");

                        else if (0 < (blockLength = ReadBlock
						         (respHeader, *evcs, blockSize)))
                        {
						    coContext->SetBlock(((ULONG)blockLength<blockSize)?0:1);
						    status = EVCP_STATUS_OK;
                        }
		            }
                }
                else
                {
                    block = coContext->GetBlock(error2);

                    if (error)
                        DBE("() failed to get block from context\n");

                    else if (0 < block)
                    {
                        if (0 <= (blockLength = ReadBlock
						    (respHeader, *evcs, blockSize)))
                        {
						    coContext->SetBlock(((ULONG)blockLength<blockSize)?0:1);
						    status = EVCP_STATUS_OK;
                        }
                    }
                    else
                    {
                        if ((error2 = evcs->ContinueCheckOutOp(m_fileEntry)))
					        DBE("() failed to continue check out op\n");
                        else 
                        {
                            coContext->SetBlock(1);
                            if (0 < (blockLength = ReadBlock
							    (respHeader, *evcs, blockSize)))
                            {
                            }
                        }
                    }
                }
            }
            parentContext->ReleaseEvcs(*evcs);
        }

        if (!(error2 = RespondStatus(response, status)))
        if (EVCP_STATUS_OK == status)
        if (0 < blockLength)
            WriteBlock(writer, blockLength);

        DBF("() ...out\n");
        return error;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: WriteBlock
    //
    //   Author: $author$
    //     Date: 8/29/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG WriteBlock
    (EvCharWriter& writer, LONG blockLength) 
    {
        LONG wrote;
        if (0 > (wrote = writer.Write(m_buffer, blockLength)))
            DBE("() failed to write block[%d]\n", blockLength);
        else DBT("() wrote block[%d]\n", blockLength);
        return wrote;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: ReadBlock
    //
    //   Author: $author$
    //     Date: 8/21/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG ReadBlock
    (EvcpHeader& respHeader, Evcs& evcs, ULONG blockSize) 
    {
        LONG blockLength;
        const EvcpHeaderField* field;
        EvError error;

        if (0 > (blockLength = evcs.ReadOpData(m_buffer, blockSize)))
            DBE("() failed to read block[%d]\n", blockSize);
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

        if ((error = evcs.CancelOp()))
            DBE("() failed to cancel evcs op\n");

        return -EV_ERROR_FAILED;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: SetBufferSize
    //
    //   Author: $author$
    //     Date: 8/24/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError SetBufferSize(ULONG bufferSize)
    {
        EvError error = EV_ERROR_FAILED;

		if (bufferSize <= (ULONG)m_bufferSize)
			return EV_ERROR_NONE;

		if ((error = FreeBuffer()))
			return error;

		error = AllocateBuffer(bufferSize);
        return error;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: AllocateBuffer
    //
    //   Author: $author$
    //     Date: 8/24/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError AllocateBuffer
    (ULONG bufferSize) 
    {
        EvError error = EV_ERROR_FAILED;
		char* buffer;

		if (!(buffer = new char[bufferSize]))
			DBE("() failed on new char[%d]\n", bufferSize);
		else
		{
			m_buffer = buffer;
			m_bufferSize = (LONG)bufferSize;
			error = EV_ERROR_NONE;
		}
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: FreeBuffer
    //
    //   Author: $author$
    //     Date: 8/24/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError FreeBuffer() 
    {
        EvError error = EV_ERROR_NONE;

		if (m_buffer != m_defaultBuffer)
		{
			delete m_buffer;
			m_buffer = m_defaultBuffer;
			m_bufferSize = DEFAULT_CEVCOEVCPSERVLET_BUFFER_SIZE;
		}
        return error;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: GetCoContext
    //
    //   Author: $author$
    //     Date: 8/19/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvCoServletContext* GetCoContext
    (Evcs& evcs, EvcpServletConnection& evcpConnection) const
    {
        EvCoServletContext* coContext = 0;
        EvcpServletContext* thisContext;
        EvError error;

        if ((thisContext = evcpConnection.FindEvcpServletContext(*this)))
            coContext = thisContext->GetCoServletContext(error);

        else if ((coContext = new CEvCoServletContext(evcs, *this)))
        {
            DBT("() created new evcp servlet context\n");
            if ((error = evcpConnection.AddEvcpServletContext(*coContext)))
            {
                DBE("() failed to add evcp servlet context\n");
                coContext->DeleteInstance();
                coContext = 0;
            }
        }
        else DBE("() failed on new evcp servlet context\n");
        return coContext;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: GetCheckOutDirectory
    //
    //   Author: $author$
    //     Date: 8/15/2007
    ///////////////////////////////////////////////////////////////////////
    virtual const char* GetCheckOutDirectory
    (EvServletServer& server) 
    {
        EvError error = EV_ERROR_FAILED;
        const char* coChars = 0;
        const char* evcsChars;
        const char* chars;
        LONG length;

        DBF("() in...\n");
        if ((chars = server.GetPropertyCharsById
            (length, EVD_PROPERTY_ID_EVCS_CO_DIR)) 
			&& (0 < length))
        if (0 < (length = m_coPath.Assign(chars, length)))
        if (m_coPath.GetIsRoot())
            coChars = chars;
        else if ((evcsChars = GetEvcsDirectory(server)))
        {
			DBT("() EVCS directory is \"%s\"\n", evcsChars);
            if (0 < (length = m_coPath.AssignChars(evcsChars)))
            if (0 < (length = m_coPath.AppendDirectory(chars)))
            if ((chars = m_coPath.Chars(length)) && (0 < length))
                coChars = chars;
        }
		else coChars = chars;
        DBF("() ...out\n");
        return coChars;
    }
};

#endif // _CEVCOEVCPSERVLET_HPP
