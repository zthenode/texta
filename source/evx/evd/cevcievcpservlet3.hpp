///////////////////////////////////////////////////////////////////////
//   File: cevcievcpservlet.hpp
//
// Author: $author$
//   Date: 4/26/2007
//
//    $Id$
///////////////////////////////////////////////////////////////////////

#ifndef _CEVCIEVCPSERVLET_HPP
#define _CEVCIEVCPSERVLET_HPP

#include "cevciservletcontext.hpp"
#include "evcpresponse.h"
#include "evcprequest.h"
#include "evcpheaderfield.h"
#include "cevcsevcpservlet.hpp"
#include "cevcpservlet.hpp"
#include "cevcpservlets.hpp"
#include "cevstringwriter.hpp"
#include "cevdatetimecharreader.hpp"
#include "cevfilesystementrytimes.hpp"
#include "cevsystemdatetime.hpp"
#include "evd.h"

#define DEFAULT_CEVCIEVCPSERVLET_NAME EVCP_REQUEST_ACTION_NAME_CI

///////////////////////////////////////////////////////////////////////
//  Class: CEvCiEvcpServlet
//
// Author: $author$
//   Date: 4/26/2007
///////////////////////////////////////////////////////////////////////
class CEvCiEvcpServlet
: public CEvcsEvcpServlet
{
public:
    typedef CEvcsEvcpServlet CExtends;
    typedef CEvCiEvcpServlet CDerives;

    CEvFileSystemEntryTimes m_fileTimes;
    CEvSystemDateTime m_systemDateTime;
    CEvDateTimeCharReader m_dateTimeReader;
    CEvFilePath m_ciPath;
    CEvString m_fieldName;
    CEvString m_block;

    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvCiEvcpServlet
    //
    //       Author: $author$
    //         Date: 4/26/2007
    ///////////////////////////////////////////////////////////////////////
    CEvCiEvcpServlet
    (const char* name=DEFAULT_CEVCIEVCPSERVLET_NAME,
     LONG length=-1) 
    : CExtends(name, length)
    {
    }
    ///////////////////////////////////////////////////////////////////////
    // Destructor: ~CEvCiEvcpServlet
    //
    //      Author: $author$
    //        Date: 4/26/2007
    ///////////////////////////////////////////////////////////////////////
    virtual ~CEvCiEvcpServlet()
    {
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
        LONG length;

        DBF("() in...\n");
		if ((parentContext = GetParentContext(error2)))
		if ((evcs = parentContext->AcquireEvcs(error2)))
		{
            if ((chars = GetVersionControlDirectory(server)))
		    {
			    DBT("() version control directory is \"%s\"\n", chars);
			    if (0 > (length = evcs->SetVcDir(chars)))
			        DBE("() failed to set version control directory to \"%s\"\n", chars);
		    }
            if ((chars = GetCheckInDirectory(server)))
		    {
			    DBT("() check in directory is \"%s\"\n", chars);
			    if (0 > (length = evcs->SetCiDir(chars)))
			        DBE("() failed to set check in directory to \"%s\"\n", chars);
		    }
			parentContext->ReleaseEvcs(*evcs);
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
        bool keepAlive = false;
        bool isBinary = false;
        bool nextBlock = false;
        bool lastBlock = false;
        ULONG blockSize = 0;
        ULONG blockLength = 0;
        EvcpServletConnection& evcpConnection = request.GetEvcpConnection();
        EvCharReader& reader = request.GetReader();
        EvcpHeader& reqHeader = request.GetHeader();
        EvcpHeaderHeading& reqHeading = reqHeader.GetHeading();
        EvCharWriter& writer = response.GetWriter();
        EvServletConnection& connection = response.GetConnection();
        const EvcpHeaderField* field;
        EvCiServletContext* ciContext;
        EvcpServletContext* parentContext;
        Evcs* evcs;
        EvError error2;
        const char* chars;
        LONG length;

        DBF("() in...\n");

		SetKeepAlive(request, response);

        if ((field = GetRequiredHeaderField
            (request, CEVCP_BLOCKLENGTH_FIELDNAME)))
        {
            blockLength = field->GetUnsignedFieldValue(length);
            DBT("() %s %d\n", CEVCP_BLOCKLENGTH_FIELDNAME, blockLength);

            if (0 < (length = blockLength))
            if (0 < (length = m_block.Read(reader, blockLength)))
                DBT("() <-- %s [%d]\n", CEVCP_BLOCK_FIELDNAME, length);

            if (length == blockLength)
            if ((parentContext = GetParentContext(error2)))
            if ((evcs = parentContext->AcquireEvcs(error2)))
            {
                if ((ciContext = GetCiContext(*evcs, evcpConnection)))
                if (!(nextBlock = (0 < (blockSize = ciContext->
                    GetBlockSize(error2))) && !error2))
                {
                    DBT("() first block (context block size is %d)\n", blockSize);

                    if ((field = GetRequiredHeaderField
                        (request, CEVCP_BLOCKSIZE_FIELDNAME)))
                    {
                        blockSize = field->GetUnsignedFieldValue(length);
                        DBT("() %s %d\n", CEVCP_BLOCKSIZE_FIELDNAME, blockSize);

                        if ((field = reqHeader.FindField
                            (CEVCP_IS_BINARY_FIELDNAME)))
                        if ((chars = field->GetFieldValue(length)))
                        {
                            DBT("() %s \"%s\"\n", CEVCP_IS_BINARY_FIELDNAME, chars);
                            isBinary = (!field->CompareFieldValue
                            (CEVCP_IS_BINARY_FIELDVALUE));
                        }

                        if (!(chars = reqHeading.
                            GetRequestPath(length)) || (0 >= length))
                            DBE("() invalid request path\n");

                        else if ((error2 = GetFileTimes(reqHeader)))
						         DBE("() failed to get file times\n");

                        else if (0 >= (length = ciContext->SetBlockSize(blockSize)))
                                 DBE("() failed to set context block size\n");

                        else if ((error2 = evcs->StartCheckInOp
								(chars, m_fileTimes, isBinary)))
								DBE("() failed to start check in op\n");

                        else nextBlock = true;
                    }
                }

                if (nextBlock)
                if (!(nextBlock = (lastBlock = (0 >= blockLength))))
                {
                    if ((chars = m_block.Chars(length)) 
                        && (length == blockLength))
                    if (!(nextBlock = !(blockLength != (length = evcs->
                        WriteOpData(chars, blockLength)))))
                        DBE("() failed to write op data\n");
                    else lastBlock = (blockLength < blockSize);
                }

                if (nextBlock)
                if (lastBlock)
                {
                    if ((error2 = evcs->FinishOp()))
                        DBE("() failed to finish op\n");
                    else status = EVCP_STATUS_OK;
                }
                else status = EVCP_STATUS_OK;

                parentContext->ReleaseEvcs(*evcs);
            }
        }

        RespondStatus(response, status);

        DBF("() ...out\n");
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: GetFileTimes
    //
    //   Author: $author$
    //     Date: 7/13/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError GetFileTimes
    (EvcpHeader& header) 
    {
        EvError error = EV_ERROR_NONE;
        EvFileTime* fileTime;
        CEvFileTimesIterator i;
        EvFileTime::EvType type;
        const char* nameChars;
        const char* chars;
        LONG length;

        DBF("() in...\n");

        //
        // Get current date and time
        //
        if ((error = m_systemDateTime.GetCurrentDateTime()))
        {
            DBE("() failed to get current date and time\n");
            return error;
        }

        for (fileTime = m_fileTimes.SetFirstFileTime(i);
             fileTime; fileTime = m_fileTimes.SetNextFileTime(i))
        {
            type = fileTime->GetType();
            if ((nameChars = (chars = EvFileTime::GetTypeName(type))))
            {
                DBT("() getting \"%s\" time\n", chars);
                if (0 < (length = m_fieldName.Assign
                    (EVCP_HEADER_FIELD_NAME_TIME_)))
                if (0 < (length = m_fieldName.Append(chars)))
                if ((chars = m_fieldName.Chars(length)) && (0 < length))
                if ((chars = header.GetField(length, chars, length)) && (0 < length))
                if (0 < (length = m_dateTimeReader.Read(*fileTime, chars, length)))
                    continue;
                else DBE("() failed to read date and time from field\n");
            }

            //
            // Set file time to current date and time
            //
            if ((error = fileTime->SetDateTime(m_systemDateTime)))
            {
                DBE("() failed to set \"%s\" time\n", nameChars);
                break;
            }
        }

        DBF("() ...out\n");
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: GetCiContext
    //
    //   Author: $author$
    //     Date: 6/4/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvCiServletContext* GetCiContext
    (Evcs& evcs, EvcpServletConnection& evcpConnection) const
    {
        EvCiServletContext* ciContext = 0;
        EvcpServletContext* thisContext;
        EvError error;

        if ((thisContext = evcpConnection.FindEvcpServletContext(*this)))
            ciContext = thisContext->GetCiServletContext(error);

        else if ((ciContext = new 
                 CEvCiServletContext(evcs, *this)))
        {
            if ((error = evcpConnection.AddEvcpServletContext(*ciContext)))
            {
                DBE("() failed to add evcp servlet context\n");
                ciContext->DeleteInstance();
                ciContext = 0;
            }
        }
        else DBE("() failed on new ci servlet context\n");
        return ciContext;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: GetCheckInDirectory
    //
    //   Author: $author$
    //     Date: 7/29/2007
    ///////////////////////////////////////////////////////////////////////
    virtual const char* GetCheckInDirectory
    (EvServletServer& server) 
    {
        EvError error = EV_ERROR_FAILED;
        const char* ciChars = 0;
        const char* evcsChars;
        const char* chars;
        LONG length;

        DBF("() in...\n");
        if ((chars = server.GetPropertyCharsById
            (length, EVD_PROPERTY_ID_EVCS_CI_DIR)) 
			&& (0 < length))
        if (0 < (length = m_ciPath.Assign(chars, length)))
        if (m_ciPath.GetIsRoot())
            ciChars = chars;
        else if ((evcsChars = GetEvcsDirectory(server)))
        {
			DBT("() EVCS directory is \"%s\"\n", evcsChars);
            if (0 < (length = m_ciPath.AssignChars(evcsChars)))
            if (0 < (length = m_ciPath.AppendDirectory(chars)))
            if ((chars = m_ciPath.Chars(length)) && (0 < length))
                ciChars = chars;
        }
		else ciChars = chars;
        DBF("() ...out\n");
        return ciChars;
    }
};

#endif // _CEVCIEVCPSERVLET_HPP
