///////////////////////////////////////////////////////////////////////
//   File: cevcmain.hpp
//
// Author: $author$
//   Date: 9/11/2007
//
//    $Id$
///////////////////////////////////////////////////////////////////////

#ifndef _CEVCMAIN_HPP
#define _CEVCMAIN_HPP

#include "cevmain.hpp"
#include "cevputevcprequest.hpp"
#include "cevgetevcprequest.hpp"
#include "cevputevcpresponse.hpp"
#include "cevgetevcpresponse.hpp"
#include "cevcpresponse.hpp"
#include "cevcprequest.hpp"
#include "cevfiletimes2evcpheader.hpp"
#include "cevcpheader2filetimes.hpp"
#include "cevfilesystem.hpp"
#include "cevsocket.hpp"
#include "cevreadwritebuffer.hpp"
#include "evdebug.h"

#define DEFAULT_BLOCK_SIZE 2048

///////////////////////////////////////////////////////////////////////
//  Class: CEvcMain
//
// Author: $author$
//   Date: 9/11/2007
///////////////////////////////////////////////////////////////////////
class CEvcMain
: public CEvMain
{
public:
    typedef CEvMain CExtends;
    typedef CEvcMain CDerives;

    ///////////////////////////////////////////////////////////////////////
    //   Enum:  
    //
    // Author: $author$
    //   Date: 9/12/2007
    ///////////////////////////////////////////////////////////////////////
    enum
    {
        EV_RESULT_CONTINUE = EV_ERROR_NONE-1,
        EV_RESULT_BREAK = EV_ERROR_NONE-2
    };

    static CEvcMain* m_main;
    CEvcMain* m_oldMain;

    CEvcpHeader m_reqHeader;
    CEvcpHeader m_respHeader;
    EvcpHeaderHeading& m_reqHeading;
    EvcpHeaderHeading& m_respHeading;

    CEvcpRequest m_request;
    CEvcpResponse m_response;

    CEvPutEvcpRequest m_putRequest;
    CEvGetEvcpRequest m_getRequest;
    CEvGetEvcpResponse m_putResponse;
    CEvGetEvcpResponse m_getResponse;

    CEvFileSystemEntryTimes m_fileTimes;
    CEvcpHeader2FileTimes m_header2FileTimes;
    CEvFileTimes2EvcpHeader m_fileTimes2Header;

    CEvCharFile m_responseFile;

    CEvSocket m_socket;
    CEvSocketReader m_socketReader;
    CEvSocketWriter m_socketWriter;

    EvCharReader* m_reader;
    EvCharWriter* m_writer;

    CEvCharReadWriteBuffer m_buffer;

    CEvFilePath m_filePath;
    CEvFilePath m_entryPath;
    CEvFilePath m_localPath;
    CEvFilePath m_controlPath;

    CEvString m_fileVersionDirectory;
    CEvString m_fileVersionExtension;

    ULONG m_blockSize;
    ULONG m_blockLength;

    bool m_isBinary;
    bool m_isRecursive;

    bool m_isConnected;
    bool m_isOpen;

    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvcMain
    //
    //       Author: $author$
    //         Date: 9/11/2007
    ///////////////////////////////////////////////////////////////////////
    CEvcMain() 
    : m_oldMain(m_main),
      m_reqHeading(m_reqHeader.GetHeading()),
      m_respHeading(m_respHeader.GetHeading()),
      m_request(m_reqHeader),
      m_response(m_respHeader),
      m_putRequest(m_reqHeader),
      m_getRequest(m_reqHeader),
      m_putResponse(m_respHeader),
      m_getResponse(m_respHeader),
      m_socketReader(m_socket),
      m_socketWriter(m_socket),
      m_reader(&m_stdIn),
      m_writer(&m_stdOut),
      m_blockSize(DEFAULT_BLOCK_SIZE),
      m_blockLength(0),
      m_isBinary(false),
      m_isRecursive(false),
      m_isConnected(false),
      m_isOpen(false)
    {
        EvError error;
        if ((error = Construct()))
            throw(error);
        m_main = this;
    }
    ///////////////////////////////////////////////////////////////////////
    // Destructor: ~CEvcMain
    //
    //      Author: $author$
    //        Date: 9/11/2007
    ///////////////////////////////////////////////////////////////////////
    virtual ~CEvcMain()
    {
        EvError error;
        if (this == m_main)
            m_main = m_oldMain;
        if ((error = Destruct()))
            throw(error);
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: Construct
    //
    //   Author: $author$
    //     Date: 9/6/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError Construct() 
    {
        EvError error = EV_ERROR_FAILED;
        LONG length;

        if (0 < (length = m_reqHeading.SetProtocol(EVC_PROTOCOL_NAME)))
        if (0 < (length = m_reqHeading.SetProtocolVersionMajor(EVC_PROTOCOL_VERSION_MAJOR)))
        if (0 < (length = m_reqHeading.SetProtocolVersionMinor(EVC_PROTOCOL_VERSION_MINOR)))
        if (0 < (length = m_respHeading.SetProtocol(EVC_PROTOCOL_NAME)))
        if (0 < (length = m_respHeading.SetProtocolVersionMajor(EVC_PROTOCOL_VERSION_MAJOR)))
        if (0 < (length = m_respHeading.SetProtocolVersionMinor(EVC_PROTOCOL_VERSION_MINOR)))
        if (0 < (length = m_fileVersionDirectory.Assign(DEFAULT_EVFILE_VERSION_DIRECTORY)))
        if (0 < (length = m_fileVersionExtension.Assign(DEFAULT_EVFILE_VERSION_EXTENSION)))
            error = EV_ERROR_NONE;
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: Destruct
    //
    //   Author: $author$
    //     Date: 9/6/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError Destruct() 
    {
        EvError error = EV_ERROR_FAILED;
        EvError error2;

        if (!(error2 = Disconnect()))
        if (!(error2 = CloseResponseFile()))
            error = EV_ERROR_NONE;
        return error;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: OnOKResponse
    //
    //   Author: $author$
    //     Date: 9/12/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError OnOKResponse() 
    {
        EvError error = EV_ERROR_NONE;
        return error;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: ReadOKResponse
    //
    //   Author: $author$
    //     Date: 9/12/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError ReadOKResponse() 
    {
        EvError error = EV_ERROR_FAILED;
        EvError result = EV_ERROR_NONE;
        bool isConnected;
        bool isOpen;
        const char* chars;
        LONG length;
        int unequal;

        if (!(isConnected = GetIsConnected())
            && !(isOpen = GetIsOpen()))
            return EV_ERROR_NONE;

        do
        {
            if (0 >= (length = m_respHeader.Read(*m_reader)))
                DBE("() failed to read header\n");

            else if (!m_respHeading.GetIsResponse())
                    DBE("() read unexpected header type\n");

            else if ((unequal = m_respHeading.
                     CompareUnsignedResponseStatus
                     (EVCP_STATUS_CODE_OK)))
            {
                if ((chars = m_respHeading.
                    GetResponseStatus(length)) && (0 <= length))
                    DBE("() received status \"%s\"\n", chars);
            }
            else if (EV_ERROR_NONE > (result = OnOKResponse()))
                    continue;
            else error = result;
            break;
        }
        while (EV_RESULT_CONTINUE == result);

        return error;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: ReadBlock
    //
    //   Author: $author$
    //     Date: 9/13/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG ReadBlock
    (char* buffer) 
    {
        LONG count = -EV_ERROR_FAILED;
        LONG length;

        if (m_blockLength != (ULONG)(length = m_reader->
            Read(buffer, m_blockLength)))
            DBE("() failed to read block[%d]\n", m_blockLength);
        else
        {
            DBT("() read block[%d]\n", m_blockLength);
            count = length;
        }
        return count;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: AllocateBuffer
    //
    //   Author: $author$
    //     Date: 9/12/2007
    ///////////////////////////////////////////////////////////////////////
    virtual char* AllocateBuffer(ULONG size) 
    {
        EvError error2;
        char* buffer;
        LONG length;

        if (!(error2 = m_buffer.AllocateBuffer(size)))
        if ((buffer = m_buffer.GetWriteBuffer
            (length)) && (size <= (ULONG)length))
            return buffer;

        return 0;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: SetFileTimeHeaderFields
    //
    //   Author: $author$
    //     Date: 9/13/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError SetFileTimeHeaderFields
    (EvcpHeader& header,
     const EvFileSystemEntryTimes& fileTimes) 
    {
        EvError error = m_fileTimes2Header.
        SetFileTimeFields(header, fileTimes);
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: GetFileTimeHeaderFields
    //
    //   Author: $author$
    //     Date: 9/13/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError GetFileTimeHeaderFields
    (EvFileSystemEntryTimes& fileTimes,
     const EvcpHeader& header) 
    {
        EvError error = m_header2FileTimes.
        GetFileTimeFields(fileTimes, header);
        return error;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: GetRequiredUnsignedHeaderField
    //
    //   Author: $author$
    //     Date: 9/12/2007
    ///////////////////////////////////////////////////////////////////////
    virtual const EvcpHeaderField* GetRequiredUnsignedHeaderField
    (ULONG& value, 
     const EvcpHeader& header,
     const char* chars) const 
    {
        const EvcpHeaderField* field = 0;
        LONG length;
		if ((field = GetRequiredHeaderField(header, chars)))
            value = field->GetUnsignedFieldValue(length);
        return field;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: GetRequiredHeaderField
    //
    //   Author: $author$
    //     Date: 9/12/2007
    ///////////////////////////////////////////////////////////////////////
    virtual const EvcpHeaderField* GetRequiredHeaderField
    (const char*& value, 
     const EvcpHeader& header,
     const char* chars) const 
    {
        const EvcpHeaderField* field = 0;
        LONG length;
		if ((field = GetRequiredHeaderField(header, chars)))
        if ((value = field->GetFieldValue(length)) && (0 < length))
            return field;
        return 0;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: GetRequiredHeaderField
    //
    //   Author: $author$
    //     Date: 9/12/2007
    ///////////////////////////////////////////////////////////////////////
    virtual const EvcpHeaderField* GetRequiredHeaderField
    (const EvcpHeader& header,
     const char* chars) const 
    {
        const EvcpHeaderField* field = 0;
		if (!(field = header.FindField(chars)))
			DBE("() missing header field \"%s\"\n", chars);
        return field;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: OpenResponseFile
    //
    //   Author: $author$
    //     Date: 9/12/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError OpenResponseFile
    (const char* filename) 
    {
        EvError error = EV_ERROR_FAILED;
        EvError error2;

        if ((error2 = m_responseFile.
            Open(filename, EVFILE_MODE_READ_BINARY)))
            DBE("() failed to open response file \"%s\"\n", filename);
        else
        {
            m_reader = &m_responseFile;
            SetIsOpen();
            error = EV_ERROR_NONE;
        }
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: CloseResponseFile
    //
    //   Author: $author$
    //     Date: 9/12/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError CloseResponseFile() 
    {
        EvError error = EV_ERROR_FAILED;
        EvError error2;
        bool isOpen;

        m_reader = &m_stdIn;
        SetIsOpen(false);

        if (!(isOpen = GetIsOpen()))
            return EV_ERROR_NONE;

        if (!(error2 = m_responseFile.Close()))
            error = EV_ERROR_NONE;
        return error;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: SetIsOpen
    //
    //   Author: $author$
    //     Date: 9/12/2007
    ///////////////////////////////////////////////////////////////////////
    virtual int SetIsOpen
    (bool is=true) 
    {
        m_isOpen = is;
        return m_isOpen;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: GetIsOpen
    //
    //   Author: $author$
    //     Date: 9/12/2007
    ///////////////////////////////////////////////////////////////////////
    virtual bool GetIsOpen() const 
    {
        return m_isOpen;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: Connect
    //
    //   Author: $author$
    //     Date: 9/6/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError Connect
    (const char* host,
     USHORT port) 
    {
        EvError error = EV_ERROR_FAILED;
        EvError error2;
        bool isConnected;

        if ((isConnected = GetIsConnected()))
            return EV_ERROR_NONE;

        if (!(error2 = m_socket.Create()))
        {
            m_socket.SetNoDelayOpt();

            if ((error2 = m_socket.Connect(port, host)))
                DBE("() unable to connect to \"%s\":%d\n", host, port);
            else
            {
                m_reader = &m_socketReader;
                m_writer = &m_socketWriter;
                SetIsConnected();
                return EV_ERROR_NONE;
            }
            m_socket.Close();
        }
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: Disconnect
    //
    //   Author: $author$
    //     Date: 9/6/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError Disconnect() 
    {
        EvError error = EV_ERROR_FAILED;
        EvError error2;
        bool isConnected;

        m_reader = &m_stdIn;
        m_writer = &m_stdOut;
        SetIsConnected(false);

        if (!(isConnected = GetIsConnected()))
            return EV_ERROR_NONE;

        if (!(error2 = m_socket.Close()))
            error = EV_ERROR_NONE;
        return error;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: SetIsConnected
    //
    //   Author: $author$
    //     Date: 9/6/2007
    ///////////////////////////////////////////////////////////////////////
    virtual int SetIsConnected
    (bool is=true) 
    {
        m_isConnected = is;
        return m_isConnected;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: GetIsConnected
    //
    //   Author: $author$
    //     Date: 9/6/2007
    ///////////////////////////////////////////////////////////////////////
    virtual bool GetIsConnected() const 
    {
        return m_isConnected;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: SetBlockSize
    //
    //   Author: $author$
    //     Date: 9/6/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG SetBlockSize
    (ULONG size) 
    {
        m_blockSize = size;
        return m_blockSize;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: GetBlockSize
    //
    //   Author: $author$
    //     Date: 9/6/2007
    ///////////////////////////////////////////////////////////////////////
    virtual ULONG GetBlockSize() const 
    {
        return m_blockSize;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: SetIsBinary
    //
    //   Author: $author$
    //     Date: 9/24/2007
    ///////////////////////////////////////////////////////////////////////
    virtual int SetIsBinary
    (bool is=true) 
    {
        m_isBinary = is;
        return m_isBinary;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: GetIsBinary
    //
    //   Author: $author$
    //     Date: 9/24/2007
    ///////////////////////////////////////////////////////////////////////
    virtual bool GetIsBinary() const 
    {
        return m_isBinary;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: SetIsRecursive
    //
    //   Author: $author$
    //     Date: 9/24/2007
    ///////////////////////////////////////////////////////////////////////
    virtual int SetIsRecursive
    (bool is=true) 
    {
        m_isRecursive = is;
        return m_isRecursive;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: GetIsRecursive
    //
    //   Author: $author$
    //     Date: 9/24/2007
    ///////////////////////////////////////////////////////////////////////
    virtual bool GetIsRecursive() const 
    {
        return m_isRecursive;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: GetMain
    //
    //   Author: $author$
    //     Date: 9/11/2007
    ///////////////////////////////////////////////////////////////////////
    static CEvcMain* GetMain()
    {
        return m_main;
    }
};

#endif // _CEVCMAIN_HPP
