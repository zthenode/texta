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

#include "evcpfield.h"
#include "evcprequest.h"
#include "evcpstatus.h"
#include "evcclient.hpp"
#include "cevsocket.hpp"
#include "cevstring.hpp"
#include "cevcpheader.hpp"
#include "cevcharfile.hpp"
#include "cevfile.hpp"
#include "cevfilematch.hpp"
#include "cevfilepath.hpp"
#include "cevfiledirectory.hpp"
#include "cevfiledirectoryentry.hpp"
#include "cevmsticks.hpp"

#define DEFAULT_CEVCCLIENT_TCP_NO_DELAY_ON true
#define DEFAULT_CEVCCLIENT_SOCKET_DONT_LINGER_ON true
#define DEFAULT_CEVCCLIENT_SOCKET_LINGER 0

#define DEFAULT_CEVCCLIENT_BLOCKSIZE 4096

#define DEFAULT_CEVCCLIENT_MATCH_PATTERNS \
    "*.t;*.txt;*.xml;*.xsl;*.html;*.css;*.js;" \
    "*.h;*.c;*.hpp;*.cpp;*.hxx;*.cxx;*.rc;" \
    "*.dsw;*.dsp;*.sln;*.vcproj;*.vsprops;" \
    "Makedefines;Makerules;Makefile;"

#define DEFAULT_CEVCCLIENT_BINARY_MATCH_PATTERNS \
    "*.zip;*.tgz;*.tar;*.gz;" \
    "*.ico;*.bmp;*.gif;*.jpg;*.tif;" \
    "*.SLDPRT;*.SLDASM;"

///////////////////////////////////////////////////////////////////////
//  Class: CEvcClient
//
// Author: $author$
//   Date: 5/11/2007
///////////////////////////////////////////////////////////////////////
class CEvcClient
: virtual public EvcClient,
  public CEvBase
{
public:
    typedef EvcClient CImplements;
    typedef CEvBase CExtends;
    typedef CEvcClient CDerives;

    static const char* m_connectionKeepAlive;
    static const char* m_connectionClose;

    CEvString m_host;
    SOCKET_PORT m_port;
    bool m_tcpNoDelayOn;
    bool m_isConnected;

    ULONG m_blockSize;
    CEvString m_matchPatterns;
    CEvString m_binaryMatchPatterns;

    CEvFilePath m_entryPath;
    CEvFilePath m_localPath;
    CEvFilePath m_filePath;
    CEvFileMatch m_fileMatch;
    CEvFileMatch m_fileBinaryMatch;
    CEvFileDirectory m_fileDirectory;

    CEvSocket m_socket;
    CEvSocketReader m_socketReader;
    CEvSocketWriter m_socketWriter;

    CEvcpHeader m_requestHeader;
    CEvcpHeader m_responseHeader;

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
     const char* protocol="EVCP",
     const char* protocolVersionMajor="3",
     const char* protocolVersionMinor="0") 
    : m_port(port),
      m_tcpNoDelayOn(DEFAULT_CEVCCLIENT_TCP_NO_DELAY_ON),
      m_isConnected(false),
      m_blockSize(blockSize),
      m_socketReader(m_socket),
      m_socketWriter(m_socket),
      m_requestHeader(protocol, protocolVersionMajor, protocolVersionMinor)
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
        if (GetIsConnected())
        if ((error = Disconnect()))
            throw(error);
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
        const char* chars;
        LONG length;
        int type;
        
        if (0 >= (type = m_localPath.Exists(localPath)))
        {
            DBE("() unable to find local path \"%s\"\n", localPath);
            return error;
        }

        if ((chars = m_matchPatterns.Chars(length)) && (0 < length))
        if ((error = m_fileMatch.Match(chars, length)))
            return error;

        if ((chars = m_binaryMatchPatterns.Chars(length)) && (0 < length))
        if ((error = m_fileBinaryMatch.Match(chars, length)))
            return error;

        if ((localPath = m_localPath.Chars(length)) && (0 < length))
        if (EvFileDirectoryEntry::EV_TYPE_DIRECTORY != type)
            error = CheckInFile
            (localPath, evcPath, isBinary);
        else error = CheckInDirectory
             (localPath, evcPath, isBinary, isRecursive);
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: CheckInDirectory
    //
    //   Author: $author$
    //     Date: 5/17/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError CheckInDirectory
    (const char* localPath, 
     const char* evcPath, 
     bool isBinary=false,
     bool isRecursive=false) 
    {
        EvError error = EV_ERROR_FAILED;
        LONG length;

        DBF("() \"%s\" --> \"%s\" in...\n", localPath, evcPath);

        error = CheckInFileDirectory
        (m_fileDirectory, 
         localPath, evcPath, 
         isBinary, isRecursive);

        DBF("() \"%s\" --> \"%s\" ...out\n", localPath, evcPath);
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: CheckInFileDirectory
    //
    //   Author: $author$
    //     Date: 5/17/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError CheckInFileDirectory
    (CEvFileDirectory& fileDirectory,
     const char* localPath, 
     const char* evcPath, 
     bool isBinary=false,
     bool isRecursive=false,
     const char* connectionClose=0) 
    {
        EvError error = EV_ERROR_FAILED;
        EvError error2;
        const char* chars;
        LONG length;
        EvFileDirectoryEntry* entry;

        DBF("() \"%s\" --> \"%s\" in...\n", localPath, evcPath);

        if (!connectionClose)
            connectionClose = m_connectionClose;

        if ((error = fileDirectory.OpenPath(localPath)))
            return error;

        if ((entry = fileDirectory.GetFirstEntry(error2)))
        if ((error = DoBegin()))
            DBE("() failed to do begin\n");
        else
        {
            do
            {
                if ((error = CheckInFileDirectoryEntry
                    (*entry, localPath, evcPath, 
                     isBinary, isRecursive, m_connectionKeepAlive)))
                {
                    DBE("() failed to check in entry\n");
                    break;
                }
            }
            while (!(error2 = entry->GetNextEntry()));

            if ((error2 = DoEnd(connectionClose)))
            {
                DBE("() failed to do end\n");
                if (!error) error = error2;
            }
        }

        if ((error2 = fileDirectory.Close()) && !error)
            error = error2;

        DBF("() \"%s\" --> \"%s\" ...out\n", localPath, evcPath);
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: CheckInFileDirectoryEntry
    //
    //   Author: $author$
    //     Date: 5/17/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError CheckInFileDirectoryEntry
    (EvFileDirectoryEntry& entry,
     const char* localPath, 
     const char* evcPath, 
     bool isBinary=false,
     bool isRecursive=false,
     const char* connectionClose=0) 
    {
        EvError error = EV_ERROR_FAILED;
        const char* chars;
        LONG length;

        DBF("() \"%s\" --> \"%s\" in...\n", localPath, evcPath);

        if (!connectionClose)
            connectionClose = m_connectionClose;

        if ((chars = entry.GetName(length)) && (0 < length))
        {
            DBT("() entry \"%s\" \"%c\" \"%s\"\n", 
                localPath, CEvFilePath::m_normalSeparator, chars);

            if (entry.GetIsDirectory())
            {
                if (isRecursive && !entry.GetIsCircular())
                    error = CheckInFileDirectoryEntryDirectory
                    (entry, localPath, evcPath, isBinary);
                else error = EV_ERROR_NONE;
            }
            else error = CheckInFileDirectoryEntryFile
            (entry, localPath, evcPath, isBinary, connectionClose);
        }
        DBF("() \"%s\" --> \"%s\" ...out\n", localPath, evcPath);
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: CheckInFileDirectoryEntryDirectory
    //
    //   Author: $author$
    //     Date: 5/17/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError CheckInFileDirectoryEntryDirectory
    (EvFileDirectoryEntry& entry,
     const char* localPath, 
     const char* evcPath, 
     bool isBinary=false) 
    {
        EvError error = EV_ERROR_FAILED;
        CEvFilePath localSubdirPath;
        CEvFilePath evcSubdirPath;
        const char* localSubdirChars;
        const char* evcSubdirChars;
        const char* chars;
        LONG localSubdirLength;
        LONG evcSubdirLength;
        LONG length;

        DBF("() \"%s\" --> \"%s\" in...\n", localPath, evcPath);

        if ((chars = entry.GetName(length)) && (0 < length))
        if (0 < (localSubdirLength = localSubdirPath.AssignChars(localPath)))
        if (0 < (localSubdirLength = localSubdirPath.AppendDirectory(chars)))
        if ((localSubdirChars = localSubdirPath.Chars(localSubdirLength))
            && (0 < localSubdirLength))
        if (0 < (evcSubdirLength = evcSubdirPath.AssignChars(evcPath)))
        if (0 < (evcSubdirLength = evcSubdirPath.AppendDirectory(chars)))
        if ((evcSubdirChars = evcSubdirPath.Chars(evcSubdirLength))
            && (0 < evcSubdirLength))
        {
            CEvFileDirectory subdir;

            if (!(error = CheckInFileDirectory
                (subdir, localSubdirChars, evcSubdirChars,
                 isBinary, true, m_connectionKeepAlive)))
            {
            }
        }
        DBF("() \"%s\" --> \"%s\" ...out\n", localPath, evcPath);
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: CheckInFileDirectoryEntryFile
    //
    //   Author: $author$
    //     Date: 5/17/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError CheckInFileDirectoryEntryFile
    (EvFileDirectoryEntry& entry,
     const char* localPath, 
     const char* evcPath, 
     bool isBinary=false,
     const char* connectionClose=0) 
    {
        EvError error = EV_ERROR_FAILED;
        const char* filePath;
        const char* fileName;
        LONG length;
        bool doesMatch;

        if (!connectionClose)
            connectionClose = m_connectionClose;

        if (0 < (length = m_filePath.AssignChars(localPath)))
        if ((fileName = entry.GetName(length)) && (0 < length))
        if (0 < (length = m_filePath.AppendFileName(fileName, length)))
        if ((filePath = m_filePath.Chars(length)) && (0 < length))
        {
            error = EV_ERROR_NONE;

            if ((doesMatch = m_fileBinaryMatch.Matches(m_filePath)))
                isBinary = true;
            else doesMatch = m_fileMatch.Matches(m_filePath);

            if (doesMatch)
            {
                DBT("() Check In %s File \"%s\" -- > \"%s\"\n", 
                    isBinary?"binary":"text", localPath, evcPath);

                error = CheckInFile
                (filePath, evcPath, fileName,
                 isBinary, connectionClose);
            }
        }
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: CheckInFile
    //
    //   Author: $author$
    //     Date: 5/31/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError CheckInFile
    (const char* localPath, 
     const char* evcPath, 
     bool isBinary=false,
     const char* connectionClose=0) 
    {
        EvError error = EV_ERROR_FAILED;
        const char* entryName;
        LONG length;
        bool doesMatch;

        if (0 < (length = m_filePath.Assign(localPath)))
        if ((entryName = m_filePath.GetFileName(length)) && (0 < length))
        {
            if (!isBinary)
            if ((doesMatch = m_fileBinaryMatch.Matches(m_filePath)))
                isBinary = true;

            error = CheckInFile
            (localPath, evcPath, entryName, 
             isBinary, connectionClose);
        }
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: CheckInFile
    //
    //   Author: $author$
    //     Date: 5/17/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError CheckInFile
    (const char* localPath, 
     const char* evcPath, 
     const char* entryName, 
     bool isBinary=false,
     const char* connectionClose=0) 
    {
        EvError error, error2;
        bool disconnect;
        LONG length;
        ULONG blockNo;
        LONG blockLength;
        const char* entryPath;
        const char* connection;
        CEvString fieldValue;
        CEvString blockData;
        CEvCharFile file;
        EvcpHeaderField *field;
        EvcpHeaderField *blockField;
        EvcpHeaderField *blockLengthField;
        EvcpHeaderField *connectionField;

        DWORD elapsed;
        CEvMillisecondTicks ticks;

        DBF("() \"%s\" --> \"%s\" in...\n", localPath, evcPath);

        elapsed = ticks.GetCurrentTicks();

        if ((error = file.Open
            (localPath, isBinary
             ?EVFILE_MODE_READ_BINARY
             :EVFILE_MODE_READ_TEXT)))
        {
            DBE("() failed to open file \"%s\"\n", localPath);
            return error;
        }
        //else printf("opened file \"%s\"...\n", localPath);

        blockLength = (LONG)(m_blockSize);
        blockNo = 0;

        if (0 > (length = blockData.Read(file, blockLength)))
        {
            DBE("() failed to read file block %d\n", blockNo);
            return length;
        }
        else DBF("() read block %d [%d]\n", blockNo, length);

        if (!connectionClose)
            connectionClose = m_connectionClose;

        if (blockLength > length)
        {
            blockLength = length;
            connection = connectionClose;
        }
        else connection = m_connectionKeepAlive;

        if (!(error = Connect(disconnect)))
        {
            error = EV_ERROR_FAILED;

            if (0 < (length = m_entryPath.AssignChars(evcPath)))
            if (0 < (length = m_entryPath.AppendFileName(entryName)))
            if ((entryPath = m_entryPath.Chars(length)) && (0 < length))
            if (0 < (length = m_requestHeader.m_heading.SetRequestAction(EVCP_REQUEST_ACTION_NAME_CI)))
            if (0 < (length = m_requestHeader.m_heading.SetRequestPath(entryPath)))
            if ((field = m_requestHeader.SetField
                (EVCP_HEADER_FIELD_NAME_IS_BINARY, isBinary
                 ?EVCP_HEADER_FIELD_VALUE_IS_BINARY_YES
                 :EVCP_HEADER_FIELD_VALUE_IS_BINARY_NO)))
            if ((field = m_requestHeader.SetFieldUnsigned
                (EVCP_HEADER_FIELD_NAME_BLOCK_SIZE, m_blockSize)))
            if ((blockLengthField = m_requestHeader.SetFieldUnsigned
                (EVCP_HEADER_FIELD_NAME_BLOCK_LENGTH, blockLength)))
            if ((blockField = m_requestHeader.SetFieldUnsigned
                (EVCP_HEADER_FIELD_NAME_BLOCK, blockNo++)))
            if ((connectionField = m_requestHeader.SetField
                (EVCP_HEADER_FIELD_NAME_CONNECTION, connection)))
            do
            {
                //elapsed = ticks.GetCurrentTicks();

                if (0 < (length = m_requestHeader.WriteRequest(m_socketWriter)))
                //if (0 < (length = WriteRequestHeader(m_requestHeader, m_socketWriter)))
                if (0 <= (length = blockData.Write(m_socketWriter)))
                //if (0 <= (length = WriteBlockData(blockData, m_socketWriter)))
                if (!(error = ReceiveOk()))
                //if (elapsed == (elapsed = GetElapsedTicks(ticks, "ReceiveOk")))
                if (blockLength < (LONG)(m_blockSize))
                    error = EV_ERROR_NONE;
                else if (0 > (length = blockData.Read
                        (file, blockLength)))
                        DBE("() failed to read file block %d\n", blockNo);
                else
                {
                    LONG oldBlockLength = blockLength;
                    const char* oldConnection = connection;

                    DBF("() read block %d [%d]\n", blockNo, length);

                    if (blockLength > length)
                    {
                        blockLength = length;
                        connection = connectionClose;
                    }
                    else connection = m_connectionKeepAlive;

                    if (oldBlockLength != blockLength)
                    if (0 >= (length = blockLengthField->
                        SetUnsignedFieldValue(blockLength)))
                        break;

                    if (0 >= (length = blockField->
                        SetUnsignedFieldValue(blockNo++)))
                        break;

                    if (oldConnection != connection)
                    if (0 >= (length = connectionField->
                        SetFieldValue(connection)))
                        break;

                    continue;
                }
                break;
            }
            while (0 <= blockLength);

            if (disconnect && (m_connectionKeepAlive != connectionClose))
            if ((error2 = Disconnect()) && !error)
                error = error2;
        }

        if ((error2 = file.Close()))
        {
            DBE("() failed to close file \"%s\"\n", localPath);
            return error;
        }
        //else printf("...closed file \"%s\"\n", localPath);

        //if (elapsed == (elapsed = GetElapsedTicks(ticks, localPath)))
        //    ;

        DBF("() \"%s\" --> \"%s\" ...out\n", localPath, evcPath);
        return error;
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
        const char* chars;
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

        DBF("() in...\n");

        if (!connection)
            connection = m_connectionClose;

        if (!(error = Connect(disconnect)))
        {
            error = EV_ERROR_FAILED;

            if (0 < (length = m_requestHeader.m_heading.SetRequestAction(EVCP_REQUEST_ACTION_NAME_DO)))
            if (0 < (length = m_requestHeader.m_heading.SetRequestPath(actionArgument)))
            if ((connectionField = m_requestHeader.SetField
                (EVCP_HEADER_FIELD_NAME_CONNECTION, connection)))
            if (0 < (length = m_requestHeader.WriteRequest(m_socketWriter)))
                error = ReceiveOk();

            if (disconnect && (m_connectionKeepAlive != connection))
            if ((error2 = Disconnect()) && !error)
                error = error2;
        }

        DBF("() ...out\n");
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
        if (!(error = Connect(host, port)))
            disconnect = true;
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

        if (!(error = m_socket.Create()))
        {
            if (GetTcpNoDelayOn())
		    if ((error = m_socket.SetNoDelayOpt()))
			    DBE("() failed to set nodelay socketopt\n");

            if (!error)
            if (!(error = m_socket.Connect(port, host)))
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
            if ((error = m_socket.Close()))
                DBE("() failed to close socket\n");
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
};
#endif // _CEVCCLIENT_HPP
