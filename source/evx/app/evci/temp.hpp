///////////////////////////////////////////////////////////////////////
//   File: evci.hpp
//
// Author: $author$
//   Date: 9/5/2007
//
//    $Id$
///////////////////////////////////////////////////////////////////////

#ifndef _EVCI_HPP
#define _EVCI_HPP

#include "cevmain.hpp"
#include "cevputevcprequest.hpp"
#include "cevgetevcpresponse.hpp"
#include "cevcpresponse.hpp"
#include "cevcprequest.hpp"
#include "cevcpfile.hpp"
#include "cevdir2filesystementrytimesdeligate.hpp"
#include "cev2filesystementrytimesdeligate.hpp"
#include "cevfilesystementryreader.hpp"
#include "cevfilesystementry.hpp"
#include "cevfilematch.hpp"
#include "cevfilepath.hpp"
#include "cevreadwritebuffer.hpp"
#include "cevsocket.hpp"
#include "evdebug.h"

#define DEFAULT_BLOCK_SIZE 2048

#define DEFAULT_MATCH_PATTERNS \
    "*.t;*.txt;*.xml;*.xsl;*.htm;*.html;*.css;*.js;" \
    "*.h;*.c;*.hpp;*.cpp;*.hxx;*.cxx;*.rc;*.rc2;" \
    "*.dsw;*.dsp;*.sln;*.vcproj;*.vsprops;" \
    "*.mak;Makedefines;Makerules;Makefile;" \
    ""

#define DEFAULT_BINARY_MATCH_PATTERNS \
    "*.ico;*.bmp;*.gif;*.tif;*.jpg;*.png;" \
    ""

#define DEFAULT_SKIP_MATCH_PATTERNS \
    ""

///////////////////////////////////////////////////////////////////////
//  Class: CEvCiMain
//
// Author: $author$
//   Date: 9/5/2007
///////////////////////////////////////////////////////////////////////
class CEvCiMain
: virtual public EvFileSystemEntryReaderEvents,
  public CEvMain
{
public:
    typedef CEvMain CExtends;
    typedef CEvCiMain CDerives;

    typedef EvError 
    (CDerives::*MOnFileEntry)
    (const EvFileSystemEntryBase& entry, 
     const EvFileSystemEntryTimes& entryTimes, 
     const EvFilePath& path,
     const EvFilePath& reflectedPath,
     const char* connectionClose,
     bool isBinary);

    EvFileSystemEntryReaderEvents* m_oldEvents;

    CEvFilePath m_filePath;
    CEvFilePath m_controlPath;
    CEvFilePath m_entryPath;
    CEvFilePath m_directoryEntryPath;
    CEvFileSystemEntry m_fileEntry;
    CEvFileSystemEntryReader m_fileEntryReader;

    CEvCharReadWriteBuffer m_buffer;

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
    bool m_isZeroBlockLength;
    bool m_isBinary;

    bool m_isRecursive;
    bool m_isReflective;

    bool m_matchCase;
    CEvString m_matchPatterns;
    CEvString m_binaryMatchPatterns;
    CEvString m_skipMatchPatterns;

    CEvFileMatch m_fileMatch;
    CEvFileMatch m_binaryFileMatch;
    CEvFileMatch m_skipFileMatch;

    CEvCharFile m_file;

    CEvSocket m_socket;
    CEvSocketReader m_socketReader;
    CEvSocketWriter m_socketWriter;

    EvCharReader* m_reader;
    EvCharWriter* m_writer;

    bool m_isConnected;

    MOnFileEntry m_onFileEntry;

    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvCiMain
    //
    //       Author: $author$
    //         Date: 9/5/2007
    ///////////////////////////////////////////////////////////////////////
    CEvCiMain() 
    : m_reqHeading(m_reqHeader.GetHeading()),
      m_respHeading(m_respHeader.GetHeading()),
      m_request(m_reqHeader),
      m_response(m_respHeader),
      m_putRequest(m_reqHeader),
      m_getResponse(m_respHeader),
      m_blockSize(DEFAULT_BLOCK_SIZE),
      m_blockLength(0),
      m_isZeroBlockLength(false),
      m_isBinary(false),
      m_isRecursive(false), 
      m_isReflective(true),
      m_matchCase(false),
      m_socketReader(m_socket),
      m_socketWriter(m_socket),
      m_reader(&m_stdIn),
      m_writer(&m_stdOut),
      m_isConnected(false),
      m_onFileEntry(&CDerives::OnRequestFileEntry)
    {
        EvError error;
        if ((error = Construct()))
            throw(error);
    }
    ///////////////////////////////////////////////////////////////////////
    // Destructor: ~CEvCiMain
    //
    //      Author: $author$
    //        Date: 9/5/2007
    ///////////////////////////////////////////////////////////////////////
    virtual ~CEvCiMain()
    {
        EvError error;
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

        if (0 <= (length = m_matchPatterns.Assign(DEFAULT_MATCH_PATTERNS)))
        if (0 <= (length = m_binaryMatchPatterns.Assign(DEFAULT_BINARY_MATCH_PATTERNS)))
        if (0 <= (length = m_skipMatchPatterns.Assign(DEFAULT_SKIP_MATCH_PATTERNS)))
        if (0 < (length = m_reqHeading.SetProtocol(EVC_PROTOCOL_NAME)))
        if (0 < (length = m_reqHeading.SetProtocolVersionMajor(EVC_PROTOCOL_VERSION_MAJOR)))
        if (0 < (length = m_reqHeading.SetProtocolVersionMinor(EVC_PROTOCOL_VERSION_MINOR)))
        if (0 < (length = m_respHeading.SetProtocol(EVC_PROTOCOL_NAME)))
        if (0 < (length = m_respHeading.SetProtocolVersionMajor(EVC_PROTOCOL_VERSION_MAJOR)))
        if (0 < (length = m_respHeading.SetProtocolVersionMinor(EVC_PROTOCOL_VERSION_MINOR)))
        {
            m_oldEvents = m_fileEntryReader.SetEvents(this);
            error = EV_ERROR_NONE;
        }
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
        EvError error = EV_ERROR_NONE;
        m_fileEntryReader.SetEvents(m_oldEvents);
        return error;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: Run
    //
    //    Author: $author$
    //      Date: 9/5/2007
    ///////////////////////////////////////////////////////////////////////
    virtual int Run
    (int argc, const char** argv, const char** env) 
    {
        int err = 0;
        const char* chars;
        const char* chars2;
        LONG length2;
        LONG length;

        if (!(chars = m_filePath.Chars(length)) || (0 >= length))
        {
            if (!GetDidMain())
                Help(argc, argv, env);
        }
        else if (!(chars2 = m_controlPath.
                 Chars(length2)) || (0 >= length2))
                Do(chars);

        else Do(chars, chars2);
        return err;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: MainArgn
    //
    //   Author: $author$
    //     Date: 9/5/2007
    ///////////////////////////////////////////////////////////////////////
    virtual int MainArgn
    (int args, int argn, const char *arg, 
     int argc, const char** argv, const char** env) 
    {
        int mainArgs;
        if (1 > (mainArgs = m_mainArgs++))
            m_filePath.Assign(arg);
        else if (2 > mainArgs)
                m_controlPath.Assign(arg);
        return argn;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: In
    //
    //   Author: $author$
    //     Date: 9/6/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError In
    (const char* chars, const char* chars2=0) 
    {
        EvError error = EV_ERROR_NONE;
        MOnFileEntry onFileEntry = m_onFileEntry;
        m_onFileEntry = &CDerives::OnRequestFileEntry;
        error = Do(chars, chars2);
        m_onFileEntry = onFileEntry;
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: Out
    //
    //   Author: $author$
    //     Date: 9/6/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError Out
    (const char* chars, const char* chars2=0) 
    {
        EvError error = EV_ERROR_NONE;
        MOnFileEntry onFileEntry = m_onFileEntry;
        m_onFileEntry = &CDerives::OnRespondFileEntry;
        error = Do(chars, chars2);
        m_onFileEntry = onFileEntry;
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: Do
    //
    //   Author: $author$
    //     Date: 9/6/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError Do
    (const char* chars, const char* chars2=0) 
    {
        EvError error = EV_ERROR_NONE;
        int type;
        SetDidMain();
        if (!(error = MatchPatterns()))
        if (0 < (type = m_fileEntry.Exists(chars)))
            m_fileEntryReader.Read
            (chars, -1, chars2, -1, 
             m_isRecursive, m_isReflective);
        else DBE("() unable to find \"%s\"\n", chars);
        return error;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: OnFileDirectoryEntry
    //
    //   Author: $author$
    //     Date: 6/24/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError OnFileDirectoryEntry
    (const EvFileDirectoryEntry& entry, 
     const EvFilePath& path,
     const EvFilePath& reflectedPath,
     EvFileSystemEntryReaderEvents* deligate=0) 
    {
        EvError error = EV_ERROR_NONE;
        DBF("() in...\n");
        if (deligate)
            error = deligate->OnFileDirectoryEntry
            (entry, path, reflectedPath);
        DBF("() ...out\n");
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: OnFileDirectoryFileEntry
    //
    //   Author: $author$
    //     Date: 6/24/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError OnFileDirectoryFileEntry
    (const EvFileDirectoryEntry& entry, 
     const EvFilePath& path,
     const EvFilePath& reflectedPath,
     EvFileSystemEntryReaderEvents* deligate=0) 
    {
        CEvDirectory2FileSystemEntryTimesDeligate entryTimes(entry);
        const char* connectionClose = EVCP_HEADER_FIELD_VALUE_CONNECTION_KEEPALIVE;
        EvError error = EV_ERROR_FAILED;
        const char* entryChars;
        const char* pathChars;
        LONG pathLength;
        LONG entryLength;
        
        DBF("() in...\n");

        if ((entryChars = entry.GetName
            (entryLength)) && (0 < entryLength))
        if ((pathChars = path.Chars
            (pathLength)) && (0 <= pathLength))
        if (0 <= (pathLength = m_directoryEntryPath.
            AssignChars(pathChars, pathLength)))
        if (0 < (pathLength = m_directoryEntryPath.
            AppendFileName(entryChars, entryLength)))
        if (!(error = OnFileEntry
            (entry, entryTimes, m_directoryEntryPath, 
             reflectedPath, connectionClose)))
        if (deligate)
            error = deligate->OnFileDirectoryFileEntry
            (entry, path, reflectedPath);

        DBF("() ...out\n");
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: OnFileDirectoryDirectoryEntry
    //
    //   Author: $author$
    //     Date: 6/24/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError OnFileDirectoryDirectoryEntry
    (const EvFileDirectoryEntry& entry, 
     const EvFilePath& path,
     const EvFilePath& reflectedPath,
     EvFileSystemEntryReaderEvents* deligate=0) 
    {
        EvError error = EV_ERROR_NONE;
        DBF("() in...\n");
        if (deligate)
            error = deligate->OnFileDirectoryDirectoryEntry
            (entry, path, reflectedPath);
        DBF("() ...out\n");
        return error;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: OnFileSystemEntry
    //
    //   Author: $author$
    //     Date: 6/24/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError OnFileSystemEntry
    (const EvFileSystemEntry& entry, 
     const EvFilePath& path,
     const EvFilePath& reflectedPath,
     EvFileSystemEntryReaderEvents* deligate=0) 
    {
        EvError error = EV_ERROR_NONE;
        DBF("() in...\n");
        if (deligate)
            error = deligate->OnFileSystemEntry
            (entry, path, reflectedPath);
        DBF("() ...out\n");
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: OnFileSystemFileEntry
    //
    //   Author: $author$
    //     Date: 6/24/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError OnFileSystemFileEntry
    (const EvFileSystemEntry& entry, 
     const EvFilePath& path,
     const EvFilePath& reflectedPath,
     EvFileSystemEntryReaderEvents* deligate=0) 
    {
        CEv2FileSystemEntryTimesDeligate entryTimes(entry);
        const char* connectionClose = EVCP_HEADER_FIELD_VALUE_CONNECTION_CLOSE;
        EvError error;
        
        if (!(error = OnFileEntry
            (entry, entryTimes, path, 
             reflectedPath, connectionClose)))
        if (deligate)
            error = deligate->OnFileSystemFileEntry
            (entry, path, reflectedPath);
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: OnFileSystemDirectoryEntry
    //
    //   Author: $author$
    //     Date: 6/24/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError OnFileSystemDirectoryEntry
    (const EvFileSystemEntry& entry, 
     const EvFilePath& path,
     const EvFilePath& reflectedPath,
     EvFileSystemEntryReaderEvents* deligate=0) 
    {
        EvError error = EV_ERROR_NONE;
        DBF("() in...\n");
        if (deligate)
            error = deligate->OnFileSystemDirectoryEntry
            (entry, path, reflectedPath);
        DBF("() ...out\n");
        return error;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: OnFileEntry
    //
    //   Author: $author$
    //     Date: 9/6/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError OnFileEntry
    (const EvFileSystemEntryBase& entry, 
     const EvFileSystemEntryTimes& entryTimes, 
     const EvFilePath& path,
     const EvFilePath& reflectedPath,
     const char* connectionClose) 
    {
        EvError error = EV_ERROR_NONE;
        bool matches = false;
        bool isBinary = false;

        if (!m_skipFileMatch.Matches(path, !m_matchCase))
        if (!(isBinary = (matches = m_binaryFileMatch.
            Matches(path, !m_matchCase))))
            matches = m_fileMatch.Matches(path, !m_matchCase);

        if (matches)
        if (m_onFileEntry)
            error = (this->*m_onFileEntry)
            (entry, entryTimes, path, reflectedPath, 
             connectionClose, isBinary);
        return error;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: OnRequestFileEntry
    //
    //   Author: $author$
    //     Date: 9/6/2007
    ///////////////////////////////////////////////////////////////////////
    EvError OnRequestFileEntry
    (const EvFileSystemEntryBase& entry, 
     const EvFileSystemEntryTimes& entryTimes, 
     const EvFilePath& path,
     const EvFilePath& reflectedPath,
     const char* connectionClose,
     bool isBinary) 
    {
        EvError error = EV_ERROR_NONE;
        EvError error2;
        const char* chars;
        const char* pathChars;
        const char* entryChars;
        LONG entryLength;
        LONG pathLength;
        LONG length;
        ULONG blockLength;
        char* buffer;

        DBF("() in...\n");

        if ((entryChars = entry.GetName(entryLength)) && (0 < entryLength))
        if ((pathChars = path.Chars(pathLength)) && (0 <= pathLength))
        if ((chars = reflectedPath.Chars(length)) && (0 <= length))
        if (0 <= (length = m_entryPath.AssignChars(chars, length)))
        if (0 < (length = m_entryPath.AppendFileName(entryChars, entryLength)))
        if ((chars = m_entryPath.Chars(length)) && (0 < length))
        if (!(error2 = m_buffer.AllocateBuffer(m_blockSize)))
        if ((buffer = m_buffer.GetWriteBuffer
            (length)) && (m_blockSize <= (ULONG)length))
        if (!(error2 = m_file.Open
            (pathChars, m_isBinary
             ?EVCP_FILE_MODE_READ_BINARY
             :EVCP_FILE_MODE_READ_TEXT)))
        {
            if (0 <= (m_blockLength = m_file.Read
                (buffer, m_blockSize)))
            if (0 <= (blockLength = GetBlockLength()))
            if (!(error2 = m_putRequest.AddFirstFields
                (entryTimes, chars, EVCP_REQUEST_ACTION_NAME_CI, 
                 isBinary, m_blockSize, blockLength, 
                 (blockLength < m_blockSize)?connectionClose:
                  EVCP_HEADER_FIELD_VALUE_CONNECTION_KEEPALIVE)))
            if (0 < (length = m_request.Write
                (*m_writer, buffer, blockLength)))
            if (!(error2 = m_putRequest.RemoveFirstFields
                (entryTimes)))
            if (!(error2 = ReadOKResponse()))
            if (blockLength >= m_blockSize)
            while (0 <= (m_blockLength = m_file.Read
                   (buffer, m_blockSize)))
            {
                if (0 <= (blockLength = GetBlockLength()))
                if (!(error2 = m_putRequest.SetFields
                    (blockLength, 
                     (blockLength < m_blockSize)?connectionClose:
                     EVCP_HEADER_FIELD_VALUE_CONNECTION_KEEPALIVE)))
                if (0 < (length = m_request.Write
                    (*m_writer, buffer, blockLength)))
                if (!(error2 = ReadOKResponse()))
                if (blockLength >= m_blockSize)
                    continue;
                break;
            }
            m_file.Close();
        }
        DBF("() ...out\n");
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: OnRespondFileEntry
    //
    //   Author: $author$
    //     Date: 9/6/2007
    ///////////////////////////////////////////////////////////////////////
    EvError OnRespondFileEntry
    (const EvFileSystemEntryBase& entry, 
     const EvFileSystemEntryTimes& entryTimes, 
     const EvFilePath& path,
     const EvFilePath& reflectedPath,
     const char* connectionClose,
     bool isBinary) 
    {
        EvError error = EV_ERROR_NONE;
        EvError error2;
        const char* chars;
        const char* pathChars;
        const char* entryChars;
        LONG entryLength;
        LONG pathLength;
        LONG length;
        ULONG blockLength;
        char* buffer;

        DBF("() in...\n");

        if ((entryChars = entry.GetName(entryLength)) && (0 < entryLength))
        if ((pathChars = path.Chars(pathLength)) && (0 <= pathLength))
        if ((chars = reflectedPath.Chars(length)) && (0 <= length))
        if (0 <= (length = m_entryPath.AssignChars(chars, length)))
        if (0 < (length = m_entryPath.AppendFileName(entryChars, entryLength)))
        if ((chars = m_entryPath.Chars(length)) && (0 < length))
        if (!(error2 = m_buffer.AllocateBuffer(m_blockSize)))
        if ((buffer = m_buffer.GetWriteBuffer
            (length)) && (m_blockSize <= (ULONG)length))
        if (!(error2 = m_file.Open
            (pathChars, m_isBinary
             ?EVCP_FILE_MODE_READ_BINARY
             :EVCP_FILE_MODE_READ_TEXT)))
        {
            if (0 <= (m_blockLength = m_file.Read
                (buffer, m_blockSize)))
            if (0 <= (blockLength = GetBlockLength()))
            if (!(error2 = m_getResponse.AddFirstFields
                (entryTimes, chars, EVCP_REQUEST_ACTION_NAME_CO, 
                 EVCP_STATUS_DESC_OK, EVCP_STATUS_CODE_OK, 
                 isBinary, m_blockSize, blockLength)))
            if (0 < (length = m_response.Write
                (*m_writer, buffer, blockLength)))
            if (!(error2 = m_getResponse.RemoveFirstFields
                (entryTimes)))
            if (blockLength >= m_blockSize)
            while (0 <= (m_blockLength = m_file.Read
                   (buffer, m_blockSize)))
            {
                if (0 <= (blockLength = GetBlockLength()))
                if (!(error2 = m_getResponse.SetFields(blockLength)))
                if (!(error2 = ReadCIRequest()))
                if (0 < (length = m_response.Write
                    (*m_writer, buffer, blockLength)))
                if (blockLength >= m_blockSize)
                    continue;
                break;
            }
            m_file.Close();
        }
        DBF("() ...out\n");
        return error;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: ReadOKResponse
    //
    //   Author: $author$
    //     Date: 9/6/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError ReadOKResponse() 
    {
        EvError error = EV_ERROR_FAILED;
        bool isConnected;
        const char* chars;
        LONG length;
        int unequal;

        if (!(isConnected = GetIsConnected()))
            return EV_ERROR_NONE;

        if (0 >= (length = m_respHeader.Read(m_socketReader)))
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
        else error = EV_ERROR_NONE;
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: ReadCIRequest
    //
    //   Author: $author$
    //     Date: 9/6/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError ReadCIRequest() 
    {
        EvError error = EV_ERROR_NONE;
        return error;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: MatchPatterns
    //
    //   Author: $author$
    //     Date: 9/7/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError MatchPatterns() 
    {
        EvError error = EV_ERROR_FAILED;
        EvError error2;
        const char* chars;
        LONG length;
        
        if ((chars = m_matchPatterns.
            Chars(length)) && (0 < length))
        if ((error2 = m_fileMatch.Match(chars, length)))
            return error;

        if ((chars = m_binaryMatchPatterns.
            Chars(length)) && (0 < length))
        if ((error2 = m_binaryFileMatch.Match(chars, length)))
            return error;

        if ((chars = m_skipMatchPatterns.
            Chars(length)) && (0 < length))
        if ((error2 = m_skipFileMatch.Match(chars, length)))
            return error;

        error = EV_ERROR_NONE;
        return error;
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

        if (!(isConnected = GetIsConnected()))
            return EV_ERROR_NONE;

        m_reader = &m_stdIn;
        m_writer = &m_stdOut;
        SetIsConnected(false);

        if (!(error2 = m_socket.Close()))
            error = EV_ERROR_NONE;
        return error;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: SetIsReflective
    //
    //   Author: $author$
    //     Date: 6/27/2007
    ///////////////////////////////////////////////////////////////////////
    virtual int SetIsReflective
    (bool is=true) 
    {
        m_isReflective = is;
        return m_isReflective;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: GetIsReflective
    //
    //   Author: $author$
    //     Date: 6/27/2007
    ///////////////////////////////////////////////////////////////////////
    virtual bool GetIsReflective() const 
    {
        return m_isReflective;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: SetIsRecursive
    //
    //   Author: $author$
    //     Date: 6/27/2007
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
    //     Date: 6/27/2007
    ///////////////////////////////////////////////////////////////////////
    virtual bool GetIsRecursive() const 
    {
        return m_isRecursive;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: SetMatch
    //
    //   Author: $author$
    //     Date: 9/7/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG SetMatch
    (const char* chars,
     LONG length=-1) 
    {
        length = m_matchPatterns.Assign(chars,length);
        return length;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: GetMatch
    //
    //   Author: $author$
    //     Date: 9/7/2007
    ///////////////////////////////////////////////////////////////////////
    virtual const char* GetMatch
    (LONG& length) const 
    {
        const char* chars = m_matchPatterns.Chars(length);
        return chars;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: SetBinaryMatch
    //
    //   Author: $author$
    //     Date: 9/7/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG SetBinaryMatch
    (const char* chars,
     LONG length=-1) 
    {
        length = m_binaryMatchPatterns.Assign(chars,length);
        return length;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: GetBinaryMatch
    //
    //   Author: $author$
    //     Date: 9/7/2007
    ///////////////////////////////////////////////////////////////////////
    virtual const char* GetBinaryMatch
    (LONG& length) const 
    {
        const char* chars = m_binaryMatchPatterns.Chars(length);
        return chars;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: SetSkipMatch
    //
    //   Author: $author$
    //     Date: 9/7/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG SetSkipMatch
    (const char* chars,
     LONG length=-1) 
    {
        length = m_skipMatchPatterns.Assign(chars,length);
        return length;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: GetSkipMatch
    //
    //   Author: $author$
    //     Date: 9/7/2007
    ///////////////////////////////////////////////////////////////////////
    virtual const char* GetSkipMatch
    (LONG& length) const 
    {
        const char* chars = m_skipMatchPatterns.Chars(length);
        return chars;
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
    // Function: GetBlockLength
    //
    //   Author: $author$
    //     Date: 9/6/2007
    ///////////////////////////////////////////////////////////////////////
    virtual ULONG GetBlockLength() const 
    {
        if (m_isZeroBlockLength)
            return 0;
        return m_blockLength;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: SetIsZeroBlockLength
    //
    //   Author: $author$
    //     Date: 9/8/2007
    ///////////////////////////////////////////////////////////////////////
    virtual int SetIsZeroBlockLength
    (bool is=true) 
    {
        m_isZeroBlockLength = is;
        return m_isZeroBlockLength;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: GetIsZeroBlockLength
    //
    //   Author: $author$
    //     Date: 9/8/2007
    ///////////////////////////////////////////////////////////////////////
    virtual bool GetIsZeroBlockLength() const 
    {
        return m_isZeroBlockLength;
    }
};

#endif // _EVCI_HPP
