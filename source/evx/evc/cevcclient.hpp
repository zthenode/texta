///////////////////////////////////////////////////////////////////////
//   File: cevcclient.hpp
//
// Author: $author$
//   Date: 5/11/2007
//
//    $Id$
///////////////////////////////////////////////////////////////////////

#ifndef _CEVCCLIENT_HPP
#define _CEVCCLIENT_HPP

#include "cevfilesystementrytimesdeligate.hpp"
#include "cevfilesystementryreaderevents.hpp"
#include "cevfilesystementryreader.hpp"
#include "evcpfield.h"
#include "evcprequest.h"
#include "evcpstatus.h"
#include "evcpversion.h"
#include "evcclient.hpp"
#include "cevsocket.hpp"
#include "cevstring.hpp"
#include "cevcpheader.hpp"
#include "cevdatetimewriter.hpp"
#include "cevfilewriter.hpp"
#include "cevfilereader.hpp"
#include "cevcharfile.hpp"
#include "cevfile.hpp"
#include "cevfilematch.hpp"
#include "cevfilepath.hpp"
#include "cevfiledirectory.hpp"
#include "cevfiledirectoryentry.hpp"
#include "cevmsticks.hpp"

#define CEVCCLIENT_FILE_MODE_READ_BINARY EVFILE_MODE_READ_BINARY
#define CEVCCLIENT_FILE_MODE_READ_TEXT EVFILE_MODE_READ_BINARY

#define DEFAULT_CEVCCLIENT_TCP_NO_DELAY_ON true
#define DEFAULT_CEVCCLIENT_SOCKET_DONT_LINGER_ON true
#define DEFAULT_CEVCCLIENT_SOCKET_LINGER 0

#define DEFAULT_CEVCCLIENT_BLOCKSIZE 4096

#define DEFAULT_CEVCCLIENT_MATCH_PATTERNS \
    "*.t;*.txt;*.xml;*.xsl;*.htm;*.html;*.css;*.js;" \
    "*.h;*.c;*.hpp;*.cpp;*.hxx;*.cxx;*.rc;*.rc2;" \
    "*.dsw;*.dsp;*.sln;*.vcproj;*.vsprops;" \
    "*.mak;Makedefines;Makerules;Makefile;" \
    ""

#define DEFAULT_CEVCCLIENT_BINARY_MATCH_PATTERNS \
    "*.ico;*.bmp;*.gif;*.tif;*.jpg;*.png;" \
    ""

///////////////////////////////////////////////////////////////////////
//  Typedef: CEvFileDirectoryEntryTimesDeligate
//
//   Author: $author$
//     Date: 7/10/2007
///////////////////////////////////////////////////////////////////////
typedef CEvFileSystemEntryTimesDeligateT
<EvFileDirectoryEntry>
CEvFileDirectoryEntryTimesDeligate;

///////////////////////////////////////////////////////////////////////
//  Typedef: CEvFileSystemEntryTimesDeligate
//
//   Author: $author$
//     Date: 7/10/2007
///////////////////////////////////////////////////////////////////////
typedef CEvFileSystemEntryTimesDeligateT
<EvFileSystemEntry>
CEvFileSystemEntryTimesDeligate;

///////////////////////////////////////////////////////////////////////
//  Class: CEvcClient
//
// Author: $author$
//   Date: 5/11/2007
///////////////////////////////////////////////////////////////////////
class CEvcClient
: virtual public EvcClient,
  public CEvFileSystemEntryReaderEvents
{
public:
    typedef EvcClient CImplements;
    typedef CEvFileSystemEntryReaderEvents CExtends;
    typedef CEvcClient CDerives;

    static const char* m_connectionKeepAlive;
    static const char* m_connectionClose;
    const char* m_connection;

    EvFileSystemEntryReaderEvents* m_oldEvents;

    CEvString m_host;
    SOCKET_PORT m_port;
    bool m_tcpNoDelayOn;
    bool m_isConnected;
    bool m_isTestMode;
    bool m_matchCase;

    ULONG m_blockSize;
    CEvString m_matchPatterns;
    CEvString m_binaryMatchPatterns;

    CEvFileMatch m_fileMatch;
    CEvFileMatch m_fileBinaryMatch;

    CEvSocket m_socket;
    CEvSocketReader m_socketReader;
    CEvSocketWriter m_socketWriter;

    CEvFILEReader m_inReader;
    CEvFILEWriter m_outWriter;
    CEvFILEWriter m_errWriter;

    CEvCharReader* m_headerReader;
    CEvCharWriter* m_headerWriter;

    CEvCharReader* m_contentReader;
    CEvCharWriter* m_contentWriter;

    CEvString m_fieldName;
    CEvString m_fieldValue;
    CEvStringWriter m_fieldValueWriter;
    CEvDateTimeCharWriter m_dateTimeWriter;

    CEvcpHeader m_requestHeader;
    CEvcpHeader m_responseHeader;

    CEvFileSystemEntryReader m_entryReader;
    CEvFileSystemEntry m_fileEntry;

    CEvFilePath m_entryPath;
    CEvFilePath m_evcPath;

    CEvCharFile m_file;
    CEvString m_blockData;

    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvcClient
    //
    //       Author: $author$
    //         Date: 5/11/2007
    ///////////////////////////////////////////////////////////////////////
    CEvcClient
    (const char* host=0,
     SOCKET_PORT port=INVALID_SOCKET_PORT,
     ULONG blockSize=DEFAULT_CEVCCLIENT_BLOCKSIZE,
     const char* matchPatterns=DEFAULT_CEVCCLIENT_MATCH_PATTERNS,
     const char* binaryMatchPatterns=DEFAULT_CEVCCLIENT_BINARY_MATCH_PATTERNS,
     const char* protocol=EVC_PROTOCOL_NAME,
     const char* protocolVersionMajor=EVC_PROTOCOL_VERSION_MAJOR,
     const char* protocolVersionMinor=EVC_PROTOCOL_VERSION_MINOR) 
    : m_connection(m_connectionClose),
      m_port(port),
      m_tcpNoDelayOn(DEFAULT_CEVCCLIENT_TCP_NO_DELAY_ON),
      m_isConnected(false),
      m_isTestMode(false),
      m_matchCase(false),
      m_blockSize(blockSize),
      m_socketReader(m_socket),
      m_socketWriter(m_socket),
      m_inReader(stdin),
      m_outWriter(stdout),
      m_errWriter(stderr),
      m_headerReader(&m_inReader),
      m_headerWriter(&m_outWriter),
      m_contentReader(&m_inReader),
      m_contentWriter(&m_outWriter),
      m_fieldValueWriter(m_fieldValue),
      m_requestHeader
      (protocol, protocolVersionMajor, protocolVersionMinor)
    {
        EvError error;
        LONG length;

        if (matchPatterns)
        if (0 > (length = m_matchPatterns.Assign(matchPatterns)))
            throw(error = -length);

        if (binaryMatchPatterns)
        if (0 > (length = m_binaryMatchPatterns.Assign(binaryMatchPatterns)))
            throw(error = -length);

        if (host)
        if (0 > (length = m_host.Assign(host)))
            throw(error = -length);

        m_oldEvents = m_entryReader.SetEvents(this);
    }
    ///////////////////////////////////////////////////////////////////////
    // Destructor: ~CEvcClient
    //
    //      Author: $author$
    //        Date: 5/11/2007
    ///////////////////////////////////////////////////////////////////////
    virtual ~CEvcClient()
    {
        EvError error;

        m_entryReader.SetEvents(m_oldEvents);

        if (GetIsConnected())
        if ((error = Disconnect()))
            throw(error);
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
        CEvFileDirectoryEntryTimesDeligate entryTimes(entry);
        EvError error = EV_ERROR_NONE;
        const char* chars;
        const char* evcChars;
        const char* entryChars;
        LONG entryLength;
        LONG evcLength;
        LONG length;
        bool matches;
        bool isBinary;

        if ((entryChars = entry.GetName(entryLength)) && (0 < entryLength))
        if ((chars = path.Chars(length)) && (0 <= length))
        if (0 <= (length = m_entryPath.AssignChars(chars, length)))
        if (0 < (length = m_entryPath.AppendFileName(entryChars, entryLength)))
        if ((chars = m_entryPath.Chars(length)) && (0 < length))
        {
            if (!(isBinary = (matches = m_fileBinaryMatch.Matches(m_entryPath, !m_matchCase))))
                matches = m_fileMatch.Matches(m_entryPath, !m_matchCase);

            if (matches)
            if ((evcChars = reflectedPath.Chars(evcLength)) && (0 <= evcLength))
            if (0 <= (evcLength = m_evcPath.AssignChars(evcChars, evcLength)))
            if (0 < (evcLength = m_evcPath.AppendFileName(entryChars, entryLength)))
            if ((evcChars = m_evcPath.Chars(evcLength)) && (0 < evcLength))
                error = PutFileEntry
                (entryTimes, chars, evcChars, 
                 isBinary, m_connection);
        }
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: OnFileSystemFileEntry
    //
    //   Author: $author$
    //     Date: 7/10/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError OnFileSystemFileEntry
    (const EvFileSystemEntry& entry, 
     const EvFilePath& path,
     const EvFilePath& reflectedPath,
     EvFileSystemEntryReaderEvents* deligate=0) 
    {
        CEvFileSystemEntryTimesDeligate entryTimes(entry);
        EvError error = EV_ERROR_NONE;
        const char* chars;
        const char* evcChars;
        const char* entryChars;
        LONG entryLength;
        LONG evcLength;
        LONG length;
        bool matches;
        bool isBinary;

        if ((entryChars = entry.GetName(entryLength)) && (0 < entryLength))
        if ((chars = path.Chars(length)) && (0 <= length))
        if (0 < (length = m_entryPath.Assign(chars, length)))
        if ((chars = m_entryPath.Chars(length)) && (0 < length))
        {
            isBinary = (matches = m_fileBinaryMatch.Matches(m_entryPath, !m_matchCase));

            if ((evcChars = reflectedPath.Chars(evcLength)) && (0 <= evcLength))
            if (0 <= (evcLength = m_evcPath.AssignChars(evcChars, evcLength)))
            if (0 < (evcLength = m_evcPath.AppendFileName(entryChars, entryLength)))
            if ((evcChars = m_evcPath.Chars(evcLength)) && (0 < evcLength))
                error = PutFileEntry
                (entryTimes, chars, evcChars, 
                 isBinary, m_connection);
        }
        return error;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: PutFileEntry
    //
    //   Author: $author$
    //     Date: 7/9/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError PutFileEntry
    (const EvFileSystemEntryTimes& entryTimes,
     const char* entryPath, 
     const char* evcPath, 
     bool isBinary=false,
     const char* connectionClose=0) 
    {
        EvError error = EV_ERROR_NONE;
        EvError error2;
        LONG length;
        ULONG blockNo;
        LONG blockLength;
        EvcpHeaderField *field;
        EvcpHeaderField *blockField;
        EvcpHeaderField *blockLengthField;
        EvcpHeaderField *connectionField;
        const char* connection;

        DBT("() \"%s\" --> \"%s\"...\n", entryPath, evcPath);

        if ((error2 = m_file.Open
            (entryPath, isBinary
             ?CEVCCLIENT_FILE_MODE_READ_BINARY
             :CEVCCLIENT_FILE_MODE_READ_TEXT)))
        {
            DBE("() failed to open file \"%s\"\n", entryPath);
            return error2;
        }

        blockNo = 0;
        blockLength = (LONG)(m_blockSize);

        if (!(connection = connectionClose))
            connectionClose = m_connectionClose;

        do
        {
            LONG oldBlockLength = blockLength;
            const char* oldConnection = connection;

            if (0 > (length = m_blockData.Read(m_file, blockLength)))
            {
                DBE("() failed to read file block %d\n", blockNo);
                break;
            }
            else DBT("() read block %d [%d]\n", blockNo, length);

            if (blockLength > length)
            {
                blockLength = length;
                connection = connectionClose;
            }
            else connection = m_connectionKeepAlive;

            if (1 > blockNo)
            {
                if ((error = SetFirstPutRequestFields
                    (entryTimes, entryPath, evcPath, isBinary)))
                    break;

                error = EV_ERROR_FAILED;

                if ((blockLengthField = m_requestHeader.SetFieldUnsigned
                    (EVCP_HEADER_FIELD_NAME_BLOCK_LENGTH, blockLength)))
                if ((blockField = m_requestHeader.SetFieldUnsigned
                    (EVCP_HEADER_FIELD_NAME_BLOCK, blockNo++)))
                if ((connectionField = m_requestHeader.SetField
                    (EVCP_HEADER_FIELD_NAME_CONNECTION, connection)))
                    error = EV_ERROR_NONE;

                if (error)
                    break;
            }
            else 
            {
                if (1 == blockNo)
                {
                    if ((error = RemoveFirstPutRequestFields(entryTimes)))
                        break;
                }

                error = EV_ERROR_FAILED;

                if (0 >= (length = blockField->
                    SetUnsignedFieldValue(blockNo++)))
                    break;

                if (oldBlockLength != blockLength)
                if (0 >= (length = blockLengthField->
                    SetUnsignedFieldValue(blockLength)))
                    break;

                if (oldConnection != connection)
                if (0 >= (length = connectionField->
                    SetFieldValue(connection)))
                    break;
            }

            error = EV_ERROR_FAILED;

            if (0 < (length = m_requestHeader.
                WriteRequest(*m_headerWriter)))
            if (0 <= (length = m_blockData.
                Write(*m_contentWriter)))
            if (!(error = ReceiveOk()))
            if (blockLength < (LONG)(m_blockSize))
                break;

            if (error)
                break;
        }
        while (0 < blockLength);

        if ((error2 = m_file.Close()))
            DBE("() failed to close file \"%s\"\n", entryPath);

        return error;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: SetFirstPutRequestFields
    //
    //   Author: $author$
    //     Date: 7/9/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError SetFirstPutRequestFields
    (const EvFileSystemEntryTimes& entryTimes,
     const char* entryPath, 
     const char* evcPath, 
     bool isBinary) 
    {
        const char* action = EVCP_REQUEST_ACTION_NAME_CI;
        EvError error = EV_ERROR_FAILED;
        EvError error2;
        EvcpHeaderField *field;
        LONG length;

        if (0 < (length = m_requestHeader.m_heading.
            SetRequestAction(action)))
        if (0 < (length = m_requestHeader.m_heading.
            SetRequestPath(evcPath)))
        if ((field = m_requestHeader.SetField
            (EVCP_HEADER_FIELD_NAME_LOCAL_PATH, entryPath)))
        if (!(error2 = SetFileTimeRequestFields(entryTimes)))
        if ((field = m_requestHeader.SetField
            (EVCP_HEADER_FIELD_NAME_IS_BINARY, isBinary
             ?EVCP_HEADER_FIELD_VALUE_IS_BINARY_YES
             :EVCP_HEADER_FIELD_VALUE_IS_BINARY_NO)))
        if ((field = m_requestHeader.SetFieldUnsigned
            (EVCP_HEADER_FIELD_NAME_BLOCK_SIZE, m_blockSize)))
            error = EV_ERROR_NONE;
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: RemoveFirstPutRequestFields
    //
    //   Author: $author$
    //     Date: 7/9/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError RemoveFirstPutRequestFields
    (const EvFileSystemEntryTimes& entryTimes) 
    {
        EvError error = EV_ERROR_NONE;

        if (!(error = RemoveFileTimeRequestFields(entryTimes)))
        if (!(error = m_requestHeader.RemoveField
            (EVCP_HEADER_FIELD_NAME_LOCAL_PATH)))
        if (!(error = m_requestHeader.RemoveField
            (EVCP_HEADER_FIELD_NAME_IS_BINARY)))
            error = m_requestHeader.RemoveField
            (EVCP_HEADER_FIELD_NAME_BLOCK_SIZE);
        return error;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: SetFileTimeRequestFields
    //
    //   Author: $author$
    //     Date: 7/9/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError SetFileTimeRequestFields
    (const EvFileSystemEntryTimes& entryTimes) 
    {
        EvError error = EV_ERROR_NONE;
        const char* fileTimeName;
        const char* fileTimeValue;
        const EvFileTime* fileTime;
        EvFileTime::EvType fileTimeType;
        const_CEvFileTimesIterator i;
        EvcpHeaderField *field;
        LONG length;

        for (fileTime = entryTimes.GetFirstFileTime(i); 
             fileTime; fileTime = entryTimes.GetNextFileTime(i))
        {
            if (0 <= (fileTimeType = fileTime->GetType()))
            if ((fileTimeName = EvFileTime::GetTypeName(fileTimeType)))
            if (0 < (length = m_fieldName.Assign
                (EVCP_HEADER_FIELD_NAME_TIME_)))
            if (0 < (length = m_fieldName.Append(fileTimeName)))
            if ((fileTimeName = m_fieldName.Chars(length)) && (0 < length))
            if (0 <= (length = m_fieldValue.Clear()))
            if (0 <= (length = m_dateTimeWriter.Write
                (m_fieldValueWriter, *fileTime)))
            if ((fileTimeValue = m_fieldValue.Chars(length)) && (0 <= length))
			{
				DBT("() file %s time is %s\n", fileTimeName, fileTimeValue);
				if ((field = m_requestHeader.SetField
					(fileTimeName, fileTimeValue)))
					continue;
			}
            break;
        }
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: RemoveFileTimeRequestFields
    //
    //   Author: $author$
    //     Date: 7/9/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError RemoveFileTimeRequestFields
    (const EvFileSystemEntryTimes& entryTimes) 
    {
        EvError error = EV_ERROR_NONE;
        const char* fileTimeName;
        const EvFileTime* fileTime;
        EvFileTime::EvType fileTimeType;
        const_CEvFileTimesIterator i;
        EvcpHeaderField *field;
        LONG length;

        for (fileTime = entryTimes.GetFirstFileTime(i); 
             fileTime; fileTime = entryTimes.GetNextFileTime(i))
        {
            if (0 <= (fileTimeType = fileTime->GetType()))
            if ((fileTimeName = EvFileTime::GetTypeName(fileTimeType)))
            if (0 < (length = m_fieldName.Assign
                (EVCP_HEADER_FIELD_NAME_TIME_)))
            if (0 < (length = m_fieldName.Append(fileTimeName)))
            if ((fileTimeName = m_fieldName.Chars(length)) && (0 < length))
            if (!(error = m_requestHeader.RemoveField(fileTimeName)))
                continue;
            break;
        }
        return error;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: CheckIn
    //
    //   Author: $author$
    //     Date: 5/17/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError CheckIn
    (const char* localPath, 
     const char* evcPath, 
     bool isBinary=false,
     bool isRecursive=false) 
    {
        EvError error = EV_ERROR_FAILED;
        EvFileSystemEntry::EvType entryType;
        const char* chars;
        LONG length;
        
        if (EvFileSystemEntry::EV_TYPE_NONE >=
            (entryType = m_fileEntry.Exists(localPath)))
        {
            DBE("() unable to find \"%s\"\n", localPath);
            return error;
        }

        if ((error = MatchPatterns()))
            return error;

        switch(entryType)
        {
        case EvFileSystemEntry::EV_TYPE_DIRECTORY:
            error = CheckInDirectoryEntry
            (localPath, evcPath, isBinary, isRecursive);
            break;

        case EvFileSystemEntry::EV_TYPE_FILE:
            error = CheckInEntry
            (localPath, evcPath, isBinary, isRecursive);
            break;

        default:
            DBE("() unable to process entry type %d\n", entryType);
        }
        return error;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: CheckOut
    //
    //   Author: $author$
    //     Date: 8/15/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError CheckOut
    (const char* evcPath, 
     const char* localPath, 
     bool isBinary=false,
     bool isRecursive=false) 
    {
        EvError error = EV_ERROR_FAILED;
        EvFileSystemEntry::EvType entryType;
        bool entryExists;
        const char* chars;
        LONG length;
        
        DBF("() in...\n");

        if (!(entryExists = EvFileSystemEntry::EV_TYPE_NONE <
            (entryType = m_fileEntry.Exists(localPath))))
            DBW("() unable to find \"%s\"\n", localPath);

        if ((error = MatchPatterns()))
            return error;

        error = CheckOutEntry
        (evcPath, localPath, isBinary, isRecursive);

        DBF("() ...out\n");
        return error;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: MatchPatterns
    //
    //   Author: $author$
    //     Date: 8/15/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError MatchPatterns() 
    {
        EvError error = EV_ERROR_FAILED;
        EvError error2;
        const char* chars;
        LONG length;
        
        if ((chars = m_matchPatterns.Chars(length)) && (0 < length))
        if ((error2 = m_fileMatch.Match(chars, length)))
            return error;

        if ((chars = m_binaryMatchPatterns.Chars(length)) && (0 < length))
        if ((error2 = m_fileBinaryMatch.Match(chars, length)))
            return error;

        error = EV_ERROR_NONE;
        return error;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: CheckInDirectoryEntry
    //
    //   Author: $author$
    //     Date: 7/10/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError CheckInDirectoryEntry
    (const char* localPath, 
     const char* evcPath, 
     bool isBinary=false,
     bool isRecursive=false) 
    {
        EvError error = EV_ERROR_FAILED;
        const char* oldConnection = m_connection;

        m_connection = m_connectionKeepAlive;

        if (!(error = DoBegin()))
        if (!(error = CheckInEntry
            (localPath, evcPath, isBinary, isRecursive)))
            error = DoEnd(m_connectionClose);

        m_connection = oldConnection;
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: CheckInEntry
    //
    //   Author: $author$
    //     Date: 7/10/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError CheckInEntry
    (const char* localPath, 
     const char* evcPath, 
     bool isBinary=false,
     bool isRecursive=false) 
    {
        EvError error;
        EvError error2;
        LONG length;
        bool disconnect;

        DBF("() in...\n");

        if (!(error = Connect(disconnect)))
        {
            error = EV_ERROR_FAILED;

            if (0 <= (length = m_entryReader.Read
                (localPath, evcPath, isRecursive, true)))
                error = EV_ERROR_NONE;

            if (disconnect && (m_connectionKeepAlive != m_connection))
            if ((error2 = Disconnect()) && !error)
                error = error2;
        }
        DBF("() ...out\n");
        return error;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: CheckOutEntry
    //
    //   Author: $author$
    //     Date: 8/15/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError CheckOutEntry
    (const char* evcPath, 
     const char* localPath, 
     bool isBinary=false,
     bool isRecursive=false) 
    {
        EvError error;
        EvError error2;
        LONG length;
        bool disconnect;

        DBF("() in...\n");

        if (!(error = Connect(disconnect)))
        {
            error = GetEntry
            (evcPath, localPath, 
             isBinary, isRecursive, m_connection);

            if (disconnect && (m_connectionKeepAlive != m_connection))
            if ((error2 = Disconnect()) && !error)
                error = error2;
        }
        DBF("() ...out\n");
        return error;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: DoBegin
    //
    //   Author: $author$
    //     Date: 5/22/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError DoBegin() 
    {
        EvError error = Do
        (EVCP_REQUEST_ACTION_ARGUMENT_NAME_BEGIN, 
         m_connectionKeepAlive);
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: DoEnd
    //
    //   Author: $author$
    //     Date: 5/22/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError DoEnd
    (const char* connection=0) 
    {
        EvError error = Do
        (EVCP_REQUEST_ACTION_ARGUMENT_NAME_END, connection);
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: Do
    //
    //   Author: $author$
    //     Date: 5/22/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError Do
    (const char* actionArgument,
     const char* connection=0) 
    {
        EvError error = EV_ERROR_NONE;
        EvError error2;
        LONG length;
        bool disconnect;
        EvcpHeaderField *connectionField;

        if (!connection)
            connection = m_connectionClose;

        if (!(error = Connect(disconnect)))
        {
            error = EV_ERROR_FAILED;

            if (0 < (length = m_requestHeader.m_heading.SetRequestAction(EVCP_REQUEST_ACTION_NAME_DO)))
            if (0 < (length = m_requestHeader.m_heading.SetRequestPath(actionArgument)))
            if ((connectionField = m_requestHeader.SetField
                (EVCP_HEADER_FIELD_NAME_CONNECTION, connection)))
            if (0 < (length = m_requestHeader.WriteRequest(*m_headerWriter)))
                error = ReceiveOk();

            if (disconnect && (m_connectionKeepAlive != connection))
            if ((error2 = Disconnect()) && !error)
                error = error2;
        }
        return error;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: StopServer
    //
    //   Author: $author$
    //     Date: 5/11/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError StopServer() 
    {
        EvError error, error2;
        bool disconnect;
        LONG length;

        if (!(error = Connect(disconnect)))
        {
            error = EV_ERROR_FAILED;

            if (0 < (length = m_requestHeader.m_heading.SetRequestAction(EVCP_REQUEST_ACTION_NAME_STOP)))
            if (0 < (length = m_requestHeader.m_heading.SetRequestPath(EVCP_REQUEST_ACTION_ARGUMENT_NAME_NOW)))
            if (0 < (length = m_requestHeader.WriteRequest(m_socketWriter)))
            if (!(error = ReceiveOk()))
                error = EV_ERROR_NONE;

            if (disconnect)
            if ((error2 = Disconnect()) && !error)
                error = error2;
        }
        return error;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: Hello
    //
    //   Author: $author$
    //     Date: 8/14/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError Hello() 
    {
        EvError error, error2;
        bool disconnect;
        LONG length;

        if (!(error = Connect(disconnect)))
        {
            error = EV_ERROR_FAILED;

            if (0 < (length = m_requestHeader.m_heading.
                SetRequestAction(EVCP_REQUEST_ACTION_NAME_HELLO)))
            if (0 < (length = m_requestHeader.m_heading.
                SetRequestPath(EVCP_REQUEST_ACTION_ARGUMENT_NAME_NOW)))
            if (0 < (length = m_requestHeader.WriteRequest(m_socketWriter)))
            if (!(error = ReceiveOk()))
                error = EV_ERROR_NONE;

            if (disconnect)
            if ((error2 = Disconnect()) && !error)
                error = error2;
        }
        return error;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: GetEntry
    //
    //   Author: $author$
    //     Date: 8/15/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError GetEntry
    (const char* evcPath, 
     const char* entryPath, 
     bool isBinary=false,
     bool isRecursive=false,
     const char* connectionClose=0) 
    {
        EvError error = EV_ERROR_FAILED;
        EvError error2;
        LONG length;
        ULONG blockNo;
        LONG blockLength;
        EvcpHeaderField *field;
        EvcpHeaderField *blockField;
        EvcpHeaderField *blockLengthField;
        EvcpHeaderField *connectionField;
        const char* connection;

        DBT("() \"%s\" <-- \"%s\"...\n", entryPath, evcPath);

        blockNo = 0;
        blockLength = 0;

        if (!(connection = connectionClose))
            connectionClose = m_connectionClose;

		connection = m_connectionKeepAlive;

        do
        {
            const char* oldConnection = connection;

            if (1 > blockNo)
            {
                if ((error = SetFirstGetRequestFields
                    (entryPath, evcPath, isBinary, isRecursive)))
                    break;

                error = EV_ERROR_FAILED;

                if ((blockField = m_requestHeader.SetFieldUnsigned
                    (EVCP_HEADER_FIELD_NAME_BLOCK, blockNo++)))
                if ((connectionField = m_requestHeader.SetField
                    (EVCP_HEADER_FIELD_NAME_CONNECTION, connection)))
                    error = EV_ERROR_NONE;

                if (error)
                    break;
            }
            else 
            {
                if (1 == blockNo)
                {
                    if ((error = RemoveFirstGetRequestFields()))
                        break;
                }

                error = EV_ERROR_FAILED;

                if (0 >= (length = blockField->
                    SetUnsignedFieldValue(blockNo++)))
                    break;

                if (oldConnection != connection)
                if (0 >= (length = connectionField->
                    SetFieldValue(connection)))
                    break;
            }

            error = EV_ERROR_FAILED;

            if (0 < (length = m_requestHeader.
                WriteRequest(*m_headerWriter)))
            if (!(error = ReceiveOk()))
            {
                if ((field = m_responseHeader.FindField
                    (EVCP_HEADER_FIELD_NAME_BLOCK_LENGTH)))
                if ((0 < (blockLength = field->GetUnsignedFieldValue
                    (length))) && (0 < length))
                if (0 < (ReadBlockData(m_blockData, *m_contentReader, blockLength)))
                if (blockLength >= (LONG)(m_blockSize))
                    continue;

                break;
            }

            if (error)
                break;
        }
        while (0 < blockLength);

        if ((error2 = m_file.Close()))
            DBE("() failed to close file \"%s\"\n", entryPath);

        DBT("() ...\"%s\" <-- \"%s\"\n", entryPath, evcPath);
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: SetFirstGetRequestFields
    //
    //   Author: $author$
    //     Date: 8/15/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError SetFirstGetRequestFields
    (const char* entryPath, 
     const char* evcPath, 
     bool isBinary,
	 bool isRecursive) 
    {
        const char* action = EVCP_REQUEST_ACTION_NAME_CO;
        EvError error = EV_ERROR_FAILED;
        EvError error2;
        EvcpHeaderField *field;
        LONG length;

        if (0 < (length = m_requestHeader.m_heading.
            SetRequestAction(action)))
        if (0 < (length = m_requestHeader.m_heading.
            SetRequestPath(evcPath)))
        if ((field = m_requestHeader.SetField
            (EVCP_HEADER_FIELD_NAME_IS_BINARY, isBinary
             ?EVCP_HEADER_FIELD_VALUE_YES
             :EVCP_HEADER_FIELD_VALUE_NO)))
        if ((field = m_requestHeader.SetField
            (EVCP_HEADER_FIELD_NAME_IS_RECURSIVE, isRecursive
             ?EVCP_HEADER_FIELD_VALUE_YES
             :EVCP_HEADER_FIELD_VALUE_NO)))
        if ((field = m_requestHeader.SetFieldUnsigned
            (EVCP_HEADER_FIELD_NAME_BLOCK_SIZE, m_blockSize)))
            error = EV_ERROR_NONE;
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: RemoveFirstGetRequestFields
    //
    //   Author: $author$
    //     Date: 8/15/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError RemoveFirstGetRequestFields() 
    {
        EvError error = EV_ERROR_NONE;

        if (!(error = m_requestHeader.RemoveField
            (EVCP_HEADER_FIELD_NAME_IS_RECURSIVE)))
        if (!(error = m_requestHeader.RemoveField
            (EVCP_HEADER_FIELD_NAME_IS_BINARY)))
            error = m_requestHeader.RemoveField
            (EVCP_HEADER_FIELD_NAME_BLOCK_SIZE);
        return error;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: ReceiveOk
    //
    //   Author: $author$
    //     Date: 5/14/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError ReceiveOk() 
    {
        EvError error = EV_ERROR_FAILED;
        LONG length;
        int unequal;

        if (&m_inReader == m_headerReader)
            return EV_ERROR_NONE;

        do
        {
            if (0 >= (length = m_responseHeader.Read(m_socketReader)))
                DBE("() failed to read header\n");
            else
            {
                const EvcpHeaderHeading& heading = m_responseHeader.GetHeading();
                if (heading.GetIsResponse())
                {
                    if ((unequal = heading.
                        CompareUnsignedResponseStatus(EVCP_STATUS_CODE_OK)))
                    {
                        LONG length;
                        DBE("() received status %s\n", heading.GetResponseStatus(length));
                        break;
                    }
                    return EV_ERROR_NONE;
                }
            }
        }
        while (0 < length);
        return error;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: WriteRequestHeader
    //
    //   Author: $author$
    //     Date: 6/13/2007
    ///////////////////////////////////////////////////////////////////////
    LONG WriteRequestHeader
    (CEvcpHeader& requestHeader, EvCharWriter& writer) 
    {
        const char* chars;
        LONG length;
        DWORD elapsed;
        CEvMillisecondTicks ticks;

        elapsed = ticks.GetCurrentTicks();
        length = requestHeader.WriteRequest(writer);
        elapsed = ticks.GetElapsedTicks(elapsed);
        printf("wrote header[%d] in %d ms\n", length, elapsed);
        return length;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: WriteBlockData
    //
    //   Author: $author$
    //     Date: 6/13/2007
    ///////////////////////////////////////////////////////////////////////
    LONG WriteBlockData
    (CEvString& blockData, EvCharWriter& writer) 
    {
        //const char* chars;
        LONG length;
        DWORD elapsed;
        CEvMillisecondTicks ticks;

        //if ((chars = blockData.Chars(length)) && (0 < length))
        {
        elapsed = ticks.GetCurrentTicks();
        //length = writer.Write(chars, length);
        length = blockData.Write(writer);
        elapsed = ticks.GetElapsedTicks(elapsed);
        //printf("wrote data[%d] in %d ms\n", length, elapsed);
        }
        return length;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: ReadBlockData
    //
    //   Author: $author$
    //     Date: 8/29/2007
    ///////////////////////////////////////////////////////////////////////
    LONG ReadBlockData
    (CEvString& blockData, 
     EvCharReader& reader,
     LONG length=-1) 
    {
        //const char* chars;
        LONG read;
        DWORD elapsed;
        CEvMillisecondTicks ticks;

        //if ((chars = blockData.Chars(length)) && (0 < length))
        {
        elapsed = ticks.GetCurrentTicks();
        //length = writer.Write(chars, length);
        read = blockData.Read(reader, length);
        elapsed = ticks.GetElapsedTicks(elapsed);
        //printf("wrote data[%d] in %d ms\n", length, elapsed);
        }
        return read;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: GetElapsedTicks
    //
    //   Author: $author$
    //     Date: 6/13/2007
    ///////////////////////////////////////////////////////////////////////
    DWORD GetElapsedTicks
    (CEvMillisecondTicks& cticks, const char* what) 
    {
        DWORD ticks = cticks.GetElapsedTicks();
        printf("%s in %d ms\n", what, ticks);
        return ticks;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: Connect
    //
    //   Author: $author$
    //     Date: 5/11/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError Connect
    (bool& disconnect, const char* host=0,
     SOCKET_PORT port=INVALID_SOCKET_PORT) 
    {
        EvError error = EV_ERROR_FAILED;

        if (GetIsConnected())
        {
            disconnect = false;
            return EV_ERROR_NONE;
        }

        if (INVALID_SOCKET_PORT == port)
            port = m_port;

        if (!(error = Connect(host, port)))
        {
            m_contentReader = (m_headerReader = &m_socketReader);
            m_contentWriter = (m_headerWriter = &m_socketWriter);
            disconnect = true;
        }
        else if (GetIsTestMode())
        {
            error = EV_ERROR_NONE;
            disconnect = true;
        }
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: Connect
    //
    //   Author: $author$
    //     Date: 5/11/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError Connect
    (const char* host=0,
     SOCKET_PORT port=INVALID_SOCKET_PORT) 
    {
        EvError error = EV_ERROR_FAILED;
        EvError error2;
        LONG length;

        if (!host)
        if (!(host = m_host.Chars(length)) || (1 > length))
        {
            DBE("() null host name\n");
            return error;
        }

        if (INVALID_SOCKET_PORT == port)
        if (INVALID_SOCKET_PORT == (port = m_port))
        {
            DBE("() invalid port number\n");
            return error;
        }

        if ((error = m_socket.Create()))
			DBE("() failed to create socket\n");
		else
        {
            if (GetTcpNoDelayOn())
		    if ((error = m_socket.SetNoDelayOpt()))
			    DBE("() failed to set nodelay socketopt\n");

            if (!error)
            if ((error = m_socket.Connect(port, host)))
				DBE("() failed to connect to %s:%d\n", host, port);
			else
            {
                SetIsConnected();
                return error;
            }
            if ((error2 = m_socket.Close()))
                DBE("() failed to close socket\n");
        }
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: Disconnect
    //
    //   Author: $author$
    //     Date: 5/11/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError Disconnect() 
    {
        EvError error = EV_ERROR_FAILED;

        if (GetIsConnected())
        {
            if (&m_socketReader != m_headerReader)
            {
                m_contentReader = (m_headerReader = &m_inReader);
                m_contentWriter = (m_headerWriter = &m_outWriter);

                if ((error = m_socket.Close()))
                    DBE("() failed to close socket\n");
            }
            else error = EV_ERROR_NONE;
            SetIsConnected(false);
        }
        return error;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: SetTcpNoDelayOn
    //
    //   Author: $author$
    //     Date: 5/16/2007
    ///////////////////////////////////////////////////////////////////////
    virtual int SetTcpNoDelayOn
    (bool on=true) 
    {
        m_tcpNoDelayOn = on;
        return m_tcpNoDelayOn;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: GetTcpNoDelayOn
    //
    //   Author: $author$
    //     Date: 5/16/2007
    ///////////////////////////////////////////////////////////////////////
    virtual bool GetTcpNoDelayOn() const 
    {
        return m_tcpNoDelayOn;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: SetIsTestMode
    //
    //   Author: $author$
    //     Date: 7/12/2007
    ///////////////////////////////////////////////////////////////////////
    virtual int SetIsTestMode
    (bool is=true) 
    {
        m_isTestMode = is;
        return m_isTestMode;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: GetIsTestMode
    //
    //   Author: $author$
    //     Date: 7/12/2007
    ///////////////////////////////////////////////////////////////////////
    virtual bool GetIsTestMode() const 
    {
        return m_isTestMode;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: SetIsConnected
    //
    //   Author: $author$
    //     Date: 5/11/2007
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
    //     Date: 5/11/2007
    ///////////////////////////////////////////////////////////////////////
    virtual bool GetIsConnected() const 
    {
        return m_isConnected;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: SetBlockSize
    //
    //   Author: $author$
    //     Date: 5/19/2007
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
    //     Date: 5/19/2007
    ///////////////////////////////////////////////////////////////////////
    virtual ULONG GetBlockSize() const 
    {
        return m_blockSize;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: SetBinaryMatch
    //
    //   Author: $author$
    //     Date: 5/21/2007
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
    //     Date: 5/21/2007
    ///////////////////////////////////////////////////////////////////////
    virtual const char* GetBinaryMatch
    (LONG& length) const 
    {
        const char* chars = m_binaryMatchPatterns.Chars(length);
        return chars;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: SetMatch
    //
    //   Author: $author$
    //     Date: 5/21/2007
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
    //     Date: 5/21/2007
    ///////////////////////////////////////////////////////////////////////
    virtual const char* GetMatch
    (LONG& length) const 
    {
        const char* chars = m_matchPatterns.Chars(length);
        return chars;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: SetMatchCase
    //
    //   Author: $author$
    //     Date: 7/30/2007
    ///////////////////////////////////////////////////////////////////////
    virtual int SetMatchCase(bool on=true) 
    {
        m_matchCase = on;
        return m_matchCase;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: GetMatchCase
    //
    //   Author: $author$
    //     Date: 7/30/2007
    ///////////////////////////////////////////////////////////////////////
    virtual bool GetMatchCase() const 
    {
        return m_matchCase;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: SetHost
    //
    //   Author: $author$
    //     Date: 7/31/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG SetHost
    (const char* chars,
     LONG length=-1) 
    {
        LONG count = m_host.Assign(chars,length);
        return count;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: GetHost
    //
    //   Author: $author$
    //     Date: 7/31/2007
    ///////////////////////////////////////////////////////////////////////
    virtual const char* GetHost
    (LONG& length) const 
    {
        const char* chars = m_host.Chars(length);
        return chars;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: SetPort
    //
    //   Author: $author$
    //     Date: 7/31/2007
    ///////////////////////////////////////////////////////////////////////
    virtual SOCKET_PORT SetPort
    (SOCKET_PORT port) 
    {
        m_port = port;
        return m_port;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: GetPort
    //
    //   Author: $author$
    //     Date: 7/31/2007
    ///////////////////////////////////////////////////////////////////////
    virtual SOCKET_PORT GetPort() const 
    {
        return m_port;
    }
};
#endif // _CEVCCLIENT_HPP
