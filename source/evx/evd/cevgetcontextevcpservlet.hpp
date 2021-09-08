///////////////////////////////////////////////////////////////////////
//   File: cevgetcontextevcpservlet.hpp
//
// Author: $author$
//   Date: 9/28/2007
//
//    $Id$
///////////////////////////////////////////////////////////////////////

#ifndef _CEVGETCONTEXTEVCPSERVLET_HPP
#define _CEVGETCONTEXTEVCPSERVLET_HPP

#include "cevcsarchivecontextevcpservlet.hpp"
#include "cevcscontextevcpservlet.hpp"
#include "evcsarchive.hpp"
#include "cevcsentry.hpp"
#include "cevreadwritebuffer.hpp"
#include "cevgetevcpresponse.hpp"

#define DEFAULT_CEVGETCONTEXTEVCPSERVLET_NAME "GET_CONTEXT"
#define DEFAULT_EVCS_GET_BLOCK_SIZE 4096

///////////////////////////////////////////////////////////////////////
//  Class: CEvGetContextEvcpServlet
//
// Author: $author$
//   Date: 9/28/2007
///////////////////////////////////////////////////////////////////////
class CEvGetContextEvcpServlet
//: public CEvcsContextEvcpServlet
: public CEvcsArchiveContextEvcpServlet
{
public:
    //typedef CEvcsContextEvcpServlet CExtends;
    typedef CEvcsArchiveContextEvcpServlet CExtends;
    typedef CEvGetContextEvcpServlet CDerives;

    typedef EvError (CDerives::*MService)
    (EvcpServletRequest& request,
     EvcpServletResponse& response);

    MService m_service;
    //EvcsArchive* m_archive;
    EvcsGet* m_get;

    bool m_isRecursive;
    //bool m_isBinary;
    //ULONG m_blockSize;
    //ULONG m_blockLength;

    //CEvcsEntry m_entry;

    //CEvCharReadWriteBuffer m_buffer;
    //char* m_bufferChars;

    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvGetContextEvcpServlet
    //
    //       Author: $author$
    //         Date: 9/28/2007
    ///////////////////////////////////////////////////////////////////////
    CEvGetContextEvcpServlet
    (const char* name=DEFAULT_CEVGETCONTEXTEVCPSERVLET_NAME,
     LONG length=-1) 
    : CExtends(name, length),
      m_service(0),
      //m_archive(0),
      m_get(0),
      m_isRecursive(false/*),
      m_isBinary(false),
      m_blockSize(DEFAULT_EVCS_GET_BLOCK_SIZE),
      m_blockLength(0*/)
    {
    }
    ///////////////////////////////////////////////////////////////////////
    // Destructor: ~CEvGetContextEvcpServlet
    //
    //      Author: $author$
    //        Date: 9/28/2007
    ///////////////////////////////////////////////////////////////////////
    virtual ~CEvGetContextEvcpServlet()
    {
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: ConnectionInitialize
    //
    //   Author: $author$
    //     Date: 9/28/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError ConnectionInitialize
    (EvcpServletConnection& connection) 
    {
        EvError error = EV_ERROR_NONE;
        //EvError error2;

        DBF("() in...\n");

        if (!(error = CExtends::ConnectionInitialize(connection)))
//        if ((m_archive = m_evcs->OpenArchive(error2)))
            m_service = &CDerives::ServiceStart;
/*        else
        {
            DBE("() failed to open evcs archive\n");
            CExtends::ConnectionFinalize(connection);
            error = EV_ERROR_FAILED;
        }*/
        DBF("() ...out\n");
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: ConnectionFinalize
    //
    //   Author: $author$
    //     Date: 9/28/2007
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
    //     Date: 9/28/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError Service
    (EvcpServletRequest& request,
     EvcpServletResponse& response) 
    {
        EvError error = EV_ERROR_NONE;
        EvcpStatus status = EVCP_STATUS_INTERNAL_SERVER_ERROR;

        DBF("() in...\n");

        SetKeepAlive(request, response);

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
    //     Date: 9/28/2007
    ///////////////////////////////////////////////////////////////////////
    EvError ServiceStart
    (EvcpServletRequest& request,
     EvcpServletResponse& response) 
    {
        EvError error = EV_ERROR_NONE;
        EvcpStatus status = EVCP_STATUS_INTERNAL_SERVER_ERROR;
        EvcpHeader& reqHeader = request.GetHeader();
        EvcpHeaderHeading& reqHeading = reqHeader.GetHeading();
        const EvcpHeaderField* field;
        const char* chars;
        LONG length;
        EvError error2;

        DBF("() in...\n");

        SetKeepAlive(request, response);

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
        if (!(error2 = GetEntry(chars)))
            return ServiceFirst(request, response);

        DBF("() ...out\n");
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: ServiceContinue
    //
    //   Author: $author$
    //     Date: 9/28/2007
    ///////////////////////////////////////////////////////////////////////
    EvError ServiceContinue
    (EvcpServletRequest& request,
     EvcpServletResponse& response) 
    {
        EvError error = EV_ERROR_NONE;
        EvcpStatus status = EVCP_STATUS_INTERNAL_SERVER_ERROR;
        EvError error2;
        const EvcpHeaderField* field;
        int unequal;

        DBF("() in...\n");

        m_service = &CDerives::ServiceStart;

        if ((field = GetHeaderField
            (request, EVCP_HEADER_FIELD_NAME_ACTION)))
        if (!(unequal = field->CompareFieldValue
            (EVCP_REQUEST_ACTION_NAME_START)))
            return ServiceStart(request, response);

        SetKeepAlive(request, response);

        if (m_get)
        if ((error2 = m_get->OpenNext(m_entry)))
		    DBE("() failed to continue get\n");
        else 
        return ServiceFirst(request, response);

        RespondStatus(response, status);
        DBF("() ...out\n");
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: ServiceRead
    //
    //   Author: $author$
    //     Date: 9/28/2007
    ///////////////////////////////////////////////////////////////////////
    EvError ServiceRead
    (EvcpServletRequest& request,
     EvcpServletResponse& response) 
    {
        EvError error = EV_ERROR_NONE;
        EvcpStatus status = EVCP_STATUS_INTERNAL_SERVER_ERROR;
        EvCharWriter& writer = response.GetWriter();
        EvcpHeader& respHeader = response.GetHeader();
        CEvGetEvcpResponse getResponse(respHeader);
        LONG length;
        EvError error2;
        const EvcpHeaderField* field;
        int unequal;

        DBF("() in...\n");

        m_service = &CDerives::ServiceStart;

        if ((field = GetHeaderField
            (request, EVCP_HEADER_FIELD_NAME_ACTION)))
        if (!(unequal = field->CompareFieldValue
            (EVCP_REQUEST_ACTION_NAME_START)))
            return ServiceStart(request, response);

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
                m_service = &CDerives::ServiceContinue;
            else m_service = &CDerives::ServiceRead;
        }
        DBF("() ...out\n");
        return error;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: ServiceFirst
    //
    //   Author: $author$
    //     Date: 9/28/2007
    ///////////////////////////////////////////////////////////////////////
    EvError ServiceFirst
    (EvcpServletRequest& request,
     EvcpServletResponse& response) 
    {
        EvError error = EV_ERROR_NONE;
        EvcpStatus status = EVCP_STATUS_INTERNAL_SERVER_ERROR;
        EvFilePath& relativeFilePath = m_entry.GetRelativeFilePath();
        EvFileSystemEntryTimes& fileTimes = m_entry.GetFileTimes();
        EvCharWriter& writer = response.GetWriter();
        EvcpHeader& respHeader = response.GetHeader();
        CEvGetEvcpResponse getResponse(respHeader);
        const char* chars;
        const char* action;
        LONG length;
        EvError error2;

        DBF("() in...\n");

        if (0 <= (m_blockLength = ReadBlock(respHeader)))
        {
            if ((chars = relativeFilePath.HasChars(length)))
            if ((action = GetName(length)))
            if ((error2 = getResponse.AddFirstFields
               (fileTimes, chars, action, 
                EVCP_STATUS_DESC_OK, EVCP_STATUS_CODE_OK, 
                m_isBinary, m_blockSize, m_blockLength)))
                DBE("() failed to add first fields in header\n");

            else status = EVCP_STATUS_OK;
        }

        if (!(error2 = RespondStatus(response, status)))
        if (EVCP_STATUS_OK == status)
        {
            if ((error2 = getResponse.
                RemoveFirstFields(fileTimes)))
                DBE("() failed to remove first fields in header\n");

            if (0 < m_blockLength)
                length = WriteBlock(writer);

            if (m_blockLength < m_blockSize)
                m_service = &CDerives::ServiceContinue;
            else m_service = &CDerives::ServiceRead;
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
        const char* chars;

        if (m_get)
        if (0 > (blockLength = m_get->
            ReadBlock(m_entry, m_bufferChars, m_blockSize)))
            DBE("() failed to read block[%d]\n", m_blockSize);
		else
        {
			DBT("() read block[%d]\n", blockLength);

			if ((field = respHeader.SetFieldUnsigned
				(chars = EVCP_HEADER_FIELD_NAME_BLOCK_LENGTH, blockLength)))
				return blockLength;

			DBE
			("() failed to set header field \"%s\" to %d\n", 
			 chars, blockLength);
        }

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
    // Function: GetEntry
    //
    //   Author: $author$
    //     Date: 10/3/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError GetEntry
    (const char* entryPathName) 
    {
        EvError error = EV_ERROR_FAILED;
        EvError error2;

        if (m_archive)
        if (m_get)
        {
            if ((error2 = m_get->Cancel()))
                DBE("() failed to cancel get entry\n");

            else if ((error2 = m_get->OpenFirst
                     (m_entry, entryPathName, m_isRecursive)))
                DBE("() failed on get open first\n");

            else error = EV_ERROR_NONE;
        }
        else
        if ((m_get = m_archive->GetEntry
            (error2, m_entry, entryPathName, m_isRecursive)))
            error = EV_ERROR_NONE;

        else DBE("() failed on archive get entry\n");

        return error;
    }
/*
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
    }*/
};

#endif // _CEVGETCONTEXTEVCPSERVLET_HPP
