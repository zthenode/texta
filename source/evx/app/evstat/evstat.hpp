///////////////////////////////////////////////////////////////////////
//   File: evstat.hpp
//
// Author: $author$
//   Date: 9/1/2007
//
//    $Id$
///////////////////////////////////////////////////////////////////////

#ifndef _EVSTAT_HPP
#define _EVSTAT_HPP

#include "cevmain.hpp"
#include "cevfilepath.hpp"
#include "cevfilesystementry.hpp"

#include "cevgetevcpresponse.hpp"
#include "cevputevcprequest.hpp"

#include "cevcpresponse.hpp"
#include "cevcprequest.hpp"

#include "cevfiletimes2charwriter.hpp"
#include "cev2filesystementrytimesdeligate.hpp"

#include "cevfiletimes2evcpheader.hpp"
#include "cevcpheader.hpp"
#include "cevcpfile.hpp"
#include "evcp.h"

#include "cevreadwritebuffer.hpp"

#define DEFAULT_BLOCK_SIZE 2048

///////////////////////////////////////////////////////////////////////
//  Class: CEvStatMain
//
// Author: $author$
//   Date: 9/1/2007
///////////////////////////////////////////////////////////////////////
class CEvStatMain
: public CEvMain
{
public:
    typedef CEvMain CExtends;
    typedef CEvStatMain CDerives;

    CEvFilePath m_filePath;
    CEvFileSystemEntry m_fileEntry;
    CEv2FileSystemEntryTimesDeligate m_fileEntryTimes;
    CEvFileTimes2CharWriter m_fileTimesWriter;

    CEvcpHeader m_reqHeader;
    CEvcpHeader m_respHeader;
    EvcpHeaderHeading& m_reqHeading;
    EvcpHeaderHeading& m_respHeading;

    CEvcpRequest m_request;
    CEvcpResponse m_response;

    CEvPutEvcpRequest m_putRequest;
    CEvGetEvcpResponse m_getResponse;

    ULONG m_blockSize;
    ULONG m_blockLength;
    bool m_isBinary;

    CEvCharFile m_file;
    CEvCharReadWriteBuffer m_buffer;

    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvStatMain
    //
    //       Author: $author$
    //         Date: 9/2/2007
    ///////////////////////////////////////////////////////////////////////
    CEvStatMain() 
    : m_fileEntryTimes(m_fileEntry),
      m_reqHeading(m_reqHeader.GetHeading()),
      m_respHeading(m_respHeader.GetHeading()),
      m_request(m_reqHeader),
      m_response(m_respHeader),
      m_putRequest(m_reqHeader),
      m_getResponse(m_respHeader),
      m_blockSize(DEFAULT_BLOCK_SIZE),
      m_blockLength(0),
      m_isBinary(false)
    {
    }
    ///////////////////////////////////////////////////////////////////////
    // Destructor: ~CEvStatMain
    //
    //      Author: $author$
    //        Date: 9/2/2007
    ///////////////////////////////////////////////////////////////////////
    virtual ~CEvStatMain()
    {
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: Run
    //
    //    Author: $author$
    //      Date: 9/1/2007
    ///////////////////////////////////////////////////////////////////////
    virtual int Run
    (int argc, const char** argv, const char** env) 
    {
        int err = 0;
        const char* chars;
        LONG length;
        int type;

        if (!(chars = m_filePath.Chars(length)) || (0 >= length))
        {
            if (!GetDidMain())
                Help(argc, argv, env);
        }
        else if (0 < (type = m_fileEntry.Exists(chars)))
        {
            m_fileTimesWriter.WriteFileTimes
            (m_stdOut, m_fileEntryTimes);
        }
        return err;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: In
    //
    //   Author: $author$
    //     Date: 9/4/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError In
    (const char* chars) 
    {
        EvError error = EV_ERROR_NONE;
        EvError error2;
        LONG length;
        int type;
        char* buffer;

        SetDidMain();

        if (0 < (type = m_fileEntry.Exists(chars)))
        if (0 < (length = m_reqHeading.SetProtocol(EVC_PROTOCOL_NAME)))
        if (0 < (length = m_reqHeading.SetProtocolVersionMajor(EVC_PROTOCOL_VERSION_MAJOR)))
        if (0 < (length = m_reqHeading.SetProtocolVersionMinor(EVC_PROTOCOL_VERSION_MINOR)))
        if (!(error2 = m_buffer.AllocateBuffer(m_blockSize)))
        if ((buffer = m_buffer.GetWriteBuffer
            (length)) && (m_blockSize == (ULONG)length))
        if (!(error2 = m_file.Open
            (chars, m_isBinary
             ?EVCP_FILE_MODE_READ_BINARY
             :EVCP_FILE_MODE_READ_TEXT)))
        {
            if (0 <= (m_blockLength = m_file.Read
                (buffer, m_blockSize)))
            if (!(error2 = m_putRequest.AddFirstFields
                (m_fileEntryTimes, chars, 
                 EVCP_REQUEST_ACTION_NAME_CI, m_isBinary, 
                 m_blockSize, m_blockLength,
                 EVCP_HEADER_FIELD_VALUE_CONNECTION_KEEPALIVE)))
            if (0 < (length = m_request.Write
                (m_stdOut, buffer, m_blockLength)))
            if (!(error2 = m_putRequest.RemoveFirstFields
                (m_fileEntryTimes)))
            if (m_blockLength >= m_blockSize)
            while (0 <= (m_blockLength = m_file.Read
                   (buffer, m_blockSize)))
            {
                if (!(error2 = m_putRequest.SetFields
                    (m_blockLength, EVCP_HEADER_FIELD_VALUE_CONNECTION_KEEPALIVE)))
                if (0 < (length = m_request.Write
                    (m_stdOut, buffer, m_blockLength)))
                if (m_blockLength >= m_blockSize)
                    continue;
                break;
            }
            m_file.Close();
        }
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: Out
    //
    //   Author: $author$
    //     Date: 9/4/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError Out
    (const char* chars) 
    {
        EvError error = EV_ERROR_NONE;
        EvError error2;
        LONG length;
        int type;
        char* buffer;

        SetDidMain();

        if (0 < (type = m_fileEntry.Exists(chars)))
        if (0 < (length = m_respHeading.SetProtocol(EVC_PROTOCOL_NAME)))
        if (0 < (length = m_respHeading.SetProtocolVersionMajor(EVC_PROTOCOL_VERSION_MAJOR)))
        if (0 < (length = m_respHeading.SetProtocolVersionMinor(EVC_PROTOCOL_VERSION_MINOR)))
        if (!(error2 = m_buffer.AllocateBuffer(m_blockSize)))
        if ((buffer = m_buffer.GetWriteBuffer
            (length)) && (m_blockSize == (ULONG)length))
        if (!(error2 = m_file.Open
            (chars, m_isBinary
             ?EVCP_FILE_MODE_READ_BINARY
             :EVCP_FILE_MODE_READ_TEXT)))
        {
            if (0 <= (m_blockLength = m_file.Read
                (buffer, m_blockSize)))
            if (!(error2 = m_getResponse.AddFirstFields
                (m_fileEntryTimes, chars, EVCP_REQUEST_ACTION_NAME_CI, 
                 EVCP_STATUS_DESC_OK, EVCP_STATUS_CODE_OK, 
                 m_isBinary, m_blockSize, m_blockLength)))
            if (0 < (length = m_response.Write
                (m_stdOut, buffer, m_blockLength)))
            if (!(error2 = m_getResponse.RemoveFirstFields
                (m_fileEntryTimes)))
            if (m_blockLength >= m_blockSize)
            while (0 <= (m_blockLength = m_file.Read
                   (buffer, m_blockSize)))
            {
                if (!(error2 = m_getResponse.SetFields(m_blockLength)))
                if (0 < (length = m_response.Write
                    (m_stdOut, buffer, m_blockLength)))
                if (m_blockLength >= m_blockSize)
                    continue;
                break;
            }
            m_file.Close();
        }
        return error;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: MainArgn
    //
    //   Author: $author$
    //     Date: 9/2/2007
    ///////////////////////////////////////////////////////////////////////
    virtual int MainArgn
    (int args, int argn, const char *arg, 
     int argc, const char** argv, const char** env) 
    {
        m_filePath.Assign(arg);
        return argn;
    }
};

#endif // _EVSTAT_HPP
