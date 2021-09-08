///////////////////////////////////////////////////////////////////////
//   File: cevevcscievcpservlet.hpp
//
// Author: $author$
//   Date: 7/31/2007
//
//    $Id$
///////////////////////////////////////////////////////////////////////

#ifndef _CEVEVCSCIEVCPSERVLET_HPP
#define _CEVEVCSCIEVCPSERVLET_HPP


#include "cevcpservlet.hpp"
#include "cevcpservlets.hpp"
#include "cevstringwriter.hpp"
#include "cevfilepath.hpp"
#include "cevpid.hpp"
#include "evcsd.h"

#define DEFAULT_CEVEVCSCIEVCPSERVLET_NAME "CI"
#define DEFAULT_CEVEVCSCIEVCPSERVLET_CI_PATH "EVCS/CI"

///////////////////////////////////////////////////////////////////////
//  Class: CEvEvcsCiEvcpServlet
//
// Author: $author$
//   Date: 7/31/2007
///////////////////////////////////////////////////////////////////////
class CEvEvcsCiEvcpServlet
: public CEvcpServlet
{
public:
    typedef CEvcpServlet CExtends;
    typedef CEvEvcsCiEvcpServlet CDerives;

    CEvString m_ciDirectory;
    CEvFilePath m_filePath;
    CEvPid m_pid;

    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvEvcsCiEvcpServlet
    //
    //       Author: $author$
    //         Date: 7/31/2007
    ///////////////////////////////////////////////////////////////////////
    CEvEvcsCiEvcpServlet
    (const char* name=DEFAULT_CEVEVCSCIEVCPSERVLET_NAME,
     LONG length=-1) 
    : CExtends(name, length),
      m_ciDirectory(DEFAULT_CEVEVCSCIEVCPSERVLET_CI_PATH)
    {
    }
    ///////////////////////////////////////////////////////////////////////
    // Destructor: ~CEvEvcsCiEvcpServlet
    //
    //      Author: $author$
    //        Date: 7/31/2007
    ///////////////////////////////////////////////////////////////////////
    virtual ~CEvEvcsCiEvcpServlet()
    {
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: Initialize
    //
    //   Author: $author$
    //     Date: 7/31/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError Initialize(EvServletServer& server) 
    {
        EvError error = EV_ERROR_NONE;
        const char* chars;
        LONG length;
        DBF("() in...\n");
        if ((chars = server.GetPropertyCharsById
            (length, EVCSD_PROPERTY_ID_CI_DIRECTORY)) 
            && (0 < length))
            m_ciDirectory.Assign(chars, length);
        DBF("() ...out\n");
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: Finalize
    //
    //   Author: $author$
    //     Date: 7/31/2007
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
    //     Date: 7/31/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError Service
    (EvcpServletRequest& request,
     EvcpServletResponse& response) 
    {
        EvError error = EV_ERROR_NONE;
        EvcpStatus status = EVCP_STATUS_INTERNAL_SERVER_ERROR;
        bool keepAlive = false;
        EvCharReader& reader = request.GetReader();
        EvcpHeader& reqHeader = request.GetHeader();
        EvcpHeaderHeading& reqHeading = reqHeader.GetHeading();
        EvCharWriter& writer = response.GetWriter();
        EvServletConnection& connection = response.GetConnection();
        EvcpHeaderField* field;
        const char* directoryChars;
        const char* chars;
        LONG length;
        EvError error2;

        DBF("() in...\n");

        if ((field = reqHeader.FindField(CEVCP_CONNECTION_FIELDNAME)))
        if ((chars = field->GetFieldValue(length)) && (0 < length))
        {
            DBT("() %s \"%s\"\n", CEVCP_CONNECTION_FIELDNAME, chars);
            keepAlive = (!field->CompareFieldValue(CEVCP_KEEPALIVE_FIELDVALUE));
            connection.SetKeepAlive(keepAlive);
        }

        if ((chars = m_ciDirectory.Chars(length)) && (0 < length))
        if (0 < (length = m_filePath.AssignChars(chars, length)))
        if ((chars = reqHeading.
            GetRequestPath(length)) && (0 < length))
        if (0 < (length = m_filePath.
            AppendFileName(chars, length)))
        if ((directoryChars = m_filePath.
            GetFileDirectory(length)) && (0 < length))
        if ((chars = m_filePath.
            GetFileName(length)) && (0 < length))
        {
            DBT("() check in file \"%s\"\n", chars);
            if (!(error2 = CheckInFile(directoryChars, chars)))
                status = EVCP_STATUS_OK;
        }

        RespondStatus(response, status);
        DBF("() ...out\n");
        return error;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: CheckInFile
    //
    //   Author: $author$
    //     Date: 7/31/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError CheckInFile
    (const char* directory, const char* filename) 
    {
        const char* ci="evcsci";
        EvError error = EV_ERROR_FAILED;
        EvError error2;

        if ((error2 = m_pid.CDCreateLP(directory, ci, filename, 0)))
            DBE("() failed to exec \"%s %s\"\n", ci, filename);

        else if ((error2 = m_pid.Wait()))
                DBE("() failed to wait for pid\n");
        return error;
    }
};

#endif // _CEVEVCSCIEVCPSERVLET_HPP
