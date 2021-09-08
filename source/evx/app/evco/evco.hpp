///////////////////////////////////////////////////////////////////////
//   File: evco.hpp
//
// Author: $author$
//   Date: 9/11/2007
//
//    $Id$
///////////////////////////////////////////////////////////////////////

#ifndef _EVCO_HPP
#define _EVCO_HPP

#include "cevcmain.hpp"
#include "cevmain.hpp"
#include "cevfs.hpp"

///////////////////////////////////////////////////////////////////////
//  Class: CEvCoMain
//
// Author: $author$
//   Date: 9/11/2007
///////////////////////////////////////////////////////////////////////
class CEvCoMain
: public CEvcMain
{
public:
    typedef CEvcMain CExtends;
    typedef CEvCoMain CDerives;

    typedef EvError 
    (CDerives::*MOnOKResponse)();

    CEvfs m_evfs;

    bool m_isReadOnly;
    MOnOKResponse m_onOKResponse;

    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvCoMain
    //
    //       Author: $author$
    //         Date: 9/11/2007
    ///////////////////////////////////////////////////////////////////////
    CEvCoMain()
    : m_isReadOnly(false),
      m_onOKResponse(&CDerives::OnFirstOKResponse)
    {
    }
    ///////////////////////////////////////////////////////////////////////
    // Destructor: ~CEvCoMain
    //
    //      Author: $author$
    //        Date: 9/11/2007
    ///////////////////////////////////////////////////////////////////////
    virtual ~CEvCoMain()
    {
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
        EvError error2;
        LONG length;

        SetDidMain();

        if (!(error2 = m_buffer.AllocateBuffer(m_blockSize)))
        if (!(error2 = m_getRequest.
            AddFirstFields
            (chars, EVCP_REQUEST_ACTION_NAME_CO, 
             m_isBinary, m_isRecursive, m_blockSize, 
             EVCP_HEADER_FIELD_VALUE_CONNECTION_KEEPALIVE)))
        if (0 < (length = m_request.Write(*m_writer)))
        if (!(error2 = m_getRequest.RemoveFirstFields()))
        do
        {
            if (!(error2 = ReadOKResponse()))
            if (0 < (length = m_request.Write(*m_writer)))
                continue;
            break;
        }
        while (!error2);
        return error;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: OnFirstOKResponse
    //
    //   Author: $author$
    //     Date: 9/12/2007
    ///////////////////////////////////////////////////////////////////////
    EvError OnFirstOKResponse() 
    {
        EvError error = EV_ERROR_FAILED;
        EvError error2;
        const EvcpHeaderField* actionField;
        const EvcpHeaderField* field;
        const char* actionFieldName;
        const char* actionFieldValue;
        const char* pathFieldValue;
        const char* fieldName;
        const char* entryName;
        const char* chars;
        char* buffer;
        LONG length;
        int unequal;
        int is;

        if (!(actionField = GetRequiredHeaderField
            (actionFieldValue, m_respHeader, 
             actionFieldName = EVCP_HEADER_FIELD_NAME_ACTION)))
             return error;

        DBT("() %s:%s\n", actionFieldName, actionFieldValue);

        if (!(field = GetRequiredHeaderField
            (pathFieldValue, m_respHeader, 
             fieldName = EVCP_HEADER_FIELD_NAME_PATH)))
             return error;

        DBT("() %s:%s\n", fieldName, pathFieldValue);

        if (!(unequal = actionField->CompareFieldValue
            (EVCP_REQUEST_ACTION_ARGUMENT_NAME_END)))
        {
            if (!(unequal = field->CompareFieldValue
                (EVCP_REQUEST_ACTION_NAME_CO)))
                return EV_RESULT_BREAK;
            else
            {
                DBE
                ("() unexpected \"%s\" value \"%s\"\n", 
                 actionFieldName, actionFieldValue);
                return EV_ERROR_FAILED;
            }
        }
        else if ((unequal = actionField->CompareFieldValue
                 (EVCP_REQUEST_ACTION_NAME_CO)))
        {
            DBE
            ("() unexpected \"%s\" value \"%s\"\n", 
             actionFieldName, actionFieldValue);
            return EV_ERROR_FAILED;
        }

        if (!(field = GetRequiredUnsignedHeaderField
            (m_blockSize, m_respHeader, 
             fieldName = EVCP_HEADER_FIELD_NAME_BLOCK_SIZE)))
             return error;

        DBT("() %s:%d\n", fieldName, m_blockSize);

        if (!(field = GetRequiredUnsignedHeaderField
            (m_blockLength, m_respHeader, 
             fieldName = EVCP_HEADER_FIELD_NAME_BLOCK_LENGTH)))
             return error;

        DBT("() %s:%d\n", fieldName, m_blockLength);

        if (0 < (length = m_entryPath.Assign(pathFieldValue)))
        if ((entryName = m_entryPath.GetFileName(length)) && (0 < length))
        if ((chars = m_localPath.Chars(length)))
        if (0 <= (length = m_filePath.Assign(chars, length)))
        if (!(error2 = GetFileTimeHeaderFields
            (m_fileTimes, m_respHeader)))
        if ((buffer = AllocateBuffer(m_blockLength)))
        if (0 <= (length = ReadBlock(buffer)))
        {
            const_CEvFilePathDirectoriesIterator ei;
            const_CEvFilePathDirectoriesIterator li;
            EvFilePathDirectory* ed;
            bool ldIsFileName;
            const char* ld;
            const char* d;
            int unequal;

            if ((ed = m_entryPath.GetFirstDirectory(ei)))
            {
                if ((d = ed->HasChars(length)))
                if ((ld = m_controlPath.
                    GetFirstDirectoryOrFileName(li, ldIsFileName)))
                if (!(unequal = ed->Compare(ld)))
                do
                {
                    DBT("() removing control directory \"%s\"\n", d);

                    if ((ed = m_entryPath.GetNextDirectory(ei)))
                    {
                        if ((d = ed->HasChars(length)))
                        if (!ldIsFileName)
                        if ((ld = m_controlPath.
                            GetNextDirectoryOrFileName
                            (li, ldIsFileName)))
                        if (!(unequal = ed->Compare(ld)))
                            continue;
                    }
                    else d = 0;
                    break;
                }
                while (ld);

                if (d)
                do
                {
                    DBT("() appending control directory \"%s\"\n", d);

                    if (0 < (length = m_filePath.
                        AppendDirectory(d, length)))
                    if ((ed = m_entryPath.GetNextDirectory(ei)))
                    if ((d = ed->HasChars(length)))
                        continue;
                    break;
                }
                while (d);
            }

            if (0 < (length = m_filePath.
                AppendFileName(entryName)))
            if ((entryName = m_filePath.HasChars(length)))
            {
                const char* versionDirectory = m_fileVersionDirectory.HasChars(length);
                const char* versionExtension = m_fileVersionExtension.HasChars(length);

                DBT("() file path is \"%s\"\n", entryName);

                if (0 < (is = GetIsReadOnly()))
                {
                    printf("%s\n", entryName);

                    if (m_blockLength >= m_blockSize)
                        m_onOKResponse = &CDerives::OnNextOKResponse;
                    error = EV_ERROR_NONE;
                }
                else if (!(error2 = m_evfs.OpenFile2Write
                         (m_fileTimes, entryName, m_isBinary, 
                          versionDirectory, versionExtension)))
                {
                    bool blockWritten;

                    if (!(blockWritten = (0 >= m_blockLength)))
                    if (!(blockWritten = !(m_blockLength != (length = m_evfs.
                        WriteFile(buffer, m_blockLength)))))
                    {
                        DBE("() failed to write block[%d] to file\n", m_blockLength);
                        m_evfs.CloseFile();
                    }

                    if (blockWritten)
                    {
                        if (m_blockLength < m_blockSize)
                        {
                            if (!(error2 = m_evfs.CloseFile()))
                                error = EV_ERROR_NONE;
                        }
                        else 
                        {
                            m_onOKResponse = &CDerives::OnNextOKResponse;
                            error = EV_ERROR_NONE;
                        }
                    }
                }
            }
        }
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: OnNextOKResponse
    //
    //   Author: $author$
    //     Date: 9/12/2007
    ///////////////////////////////////////////////////////////////////////
    EvError OnNextOKResponse() 
    {
        EvError error = EV_ERROR_FAILED;
        EvError error2;
        const EvcpHeaderField* field;
        const char* fieldName;
        char* buffer;
        LONG length;
        int is;

        if (!(field = GetRequiredUnsignedHeaderField
            (m_blockLength, m_respHeader, 
             fieldName = EVCP_HEADER_FIELD_NAME_BLOCK_LENGTH)))
             return error;

        DBT("() %s %d\n", fieldName, m_blockLength);

        if ((buffer = AllocateBuffer(m_blockLength)))
        if (0 <= (length = ReadBlock(buffer)))
        if (0 < (is = GetIsReadOnly()))
        {
            if (m_blockLength < m_blockSize)
                m_onOKResponse = &CDerives::OnFirstOKResponse;
            error = EV_ERROR_NONE;
        }
        else
        {
            bool blockWritten;

            if (!(blockWritten = (0 >= m_blockLength)))
            if (!(blockWritten = !(m_blockLength != (length = m_evfs.
                WriteFile(buffer, m_blockLength)))))
            {
                DBE("() failed to write block[%d] to file\n", m_blockLength);
                m_evfs.CloseFile();
            }

            if (blockWritten)
            {
                if (m_blockLength < m_blockSize)
                {
                    m_onOKResponse = &CDerives::OnFirstOKResponse;
                    if (!(error2 = m_evfs.CloseFile()))
                        error = EV_ERROR_NONE;
                }
                else error = EV_ERROR_NONE;
            }
        }
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
        EvError error = EV_ERROR_FAILED;
        if (m_onOKResponse)
            error = (this->*m_onOKResponse)();
        return error;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: Run
    //
    //    Author: $author$
    //      Date: 9/11/2007
    ///////////////////////////////////////////////////////////////////////
    virtual int Run
    (int argc, const char** argv, const char** env) 
    {
        int err = 0;
        const char* chars;
        const char* chars2;
        LONG length2;
        LONG length;

        if (!(chars = m_controlPath.Chars(length)) || (0 >= length))
        {
            if (!GetDidMain())
                Help(argc, argv, env);
        }
        else if ((chars2 = m_localPath.
                 Chars(length2)) || (0 >= length2))
                Do(chars, chars2);
        else Do(chars);
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
            m_controlPath.Assign(arg);
        else if (2 > mainArgs)
                m_localPath.Assign(arg);
        return argn;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: SetIsReadOnly
    //
    //   Author: $author$
    //     Date: 9/16/2007
    ///////////////////////////////////////////////////////////////////////
    virtual int SetIsReadOnly
    (bool is=true) 
    {
        m_isReadOnly = is;
        return m_isReadOnly;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: GetIsReadOnly
    //
    //   Author: $author$
    //     Date: 9/16/2007
    ///////////////////////////////////////////////////////////////////////
    virtual bool GetIsReadOnly() const 
    {
        return m_isReadOnly;
    }
};

#endif // _EVCO_HPP
