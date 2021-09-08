///////////////////////////////////////////////////////////////////////
//   File: cevcsevcpservlet.hpp
//
// Author: $author$
//   Date: 8/15/2007
//
//    $Id$
///////////////////////////////////////////////////////////////////////

#ifndef _CEVCSEVCPSERVLET_HPP
#define _CEVCSEVCPSERVLET_HPP

#include "cevcpservlet.hpp"
#include "cevcpservlets.hpp"
#include "cevstringwriter.hpp"
#include "cevfilepath.hpp"
#include "evd.h"

///////////////////////////////////////////////////////////////////////
//  Class: CEvcsEvcpServlet
//
// Author: $author$
//   Date: 8/15/2007
///////////////////////////////////////////////////////////////////////
class CEvcsEvcpServlet
: public CEvcpServlet
{
public:
    typedef CEvcpServlet CExtends;
    typedef CEvcsEvcpServlet CDerives;

    CEvFilePath m_evcsPath;
    CEvFilePath m_vcPath;

    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvcsEvcpServlet
    //
    //       Author: $author$
    //         Date: 8/15/2007
    ///////////////////////////////////////////////////////////////////////
    CEvcsEvcpServlet
    (const char* name,
     LONG length=-1) 
    : CExtends(name, length)
    {
    }
    ///////////////////////////////////////////////////////////////////////
    // Destructor: ~CEvcsEvcpServlet
    //
    //      Author: $author$
    //        Date: 8/15/2007
    ///////////////////////////////////////////////////////////////////////
    virtual ~CEvcsEvcpServlet()
    {
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: Initialize
    //
    //   Author: $author$
    //     Date: 8/15/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError Initialize(EvServletServer& server) 
    {
        EvError error = EV_ERROR_NONE;
        DBF("() in...\n");
        DBF("() ...out\n");
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: Finalize
    //
    //   Author: $author$
    //     Date: 8/15/2007
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
    //     Date: 8/15/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError Service
    (EvcpServletRequest& request,
     EvcpServletResponse& response) 
    {
        EvError error = EV_ERROR_NONE;
        EvCharReader& reader = request.GetReader();
        EvcpHeader& reqHeader = request.GetHeader();
        EvcpHeaderHeading& reqHeading = reqHeader.GetHeading();

        DBF("() in...\n");
        DBF("() ...out\n");
        return error;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: GetVersionControlDirectory
    //
    //   Author: $author$
    //     Date: 8/17/2007
    ///////////////////////////////////////////////////////////////////////
    virtual const char* GetVersionControlDirectory
    (EvServletServer& server) 
    {
        EvError error = EV_ERROR_FAILED;
        const char* vcChars = 0;
        const char* evcsChars;
        const char* chars;
        LONG length;

        DBF("() in...\n");
        if ((chars = server.GetPropertyCharsById
            (length, EVD_PROPERTY_ID_EVCS_VC_DIR)) 
			&& (0 < length))
        if (0 < (length = m_vcPath.Assign(chars, length)))
        if (m_vcPath.GetIsRoot())
            vcChars = chars;
        else if ((evcsChars = GetEvcsDirectory(server)))
        {
			DBT("() EVCS directory is \"%s\"\n", evcsChars);
            if (0 < (length = m_vcPath.AssignChars(evcsChars)))
            if (0 < (length = m_vcPath.AppendDirectory(chars)))
            if ((chars = m_vcPath.Chars(length)) && (0 < length))
                vcChars = chars;
        }
		else vcChars = chars;
        DBF("() ...out\n");
        return vcChars;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: GetEvcsDirectory
    //
    //   Author: $author$
    //     Date: 7/29/2007
    ///////////////////////////////////////////////////////////////////////
    virtual const char* GetEvcsDirectory
    (EvServletServer& server) 
    {
        EvError error = EV_ERROR_FAILED;
        const char* evcsChars = 0;
        const char* evdChars;
        const char* chars;
        LONG length;

        DBF("() in...\n");
        if ((chars = server.GetPropertyCharsById
            (length, EVD_PROPERTY_ID_EVCS_DIR)) && (0 < length))
        if (0 < (length = m_evcsPath.Assign(chars, length)))
        if (m_evcsPath.GetIsRoot())
            evcsChars = chars;
        else if ((evdChars = GetEvdDirectory(server)))
        {
			DBT("() EVD directory is \"%s\"\n", evdChars);
            if (0 < (length = m_evcsPath.AssignChars(evdChars)))
            if (0 < (length = m_evcsPath.AppendDirectory(chars)))
            if ((chars = m_evcsPath.Chars(length)) && (0 < length))
                evcsChars = chars;
        }
		else evcsChars = chars;
        DBF("() ...out\n");
        return evcsChars;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: GetEvdDirectory
    //
    //   Author: $author$
    //     Date: 7/29/2007
    ///////////////////////////////////////////////////////////////////////
    virtual const char* GetEvdDirectory
    (EvServletServer& server) 
    {
        EvError error = EV_ERROR_FAILED;
        const char* evdChars = 0;
        const char* chars;
        LONG length;

        DBF("() in...\n");
        if ((chars = server.GetPropertyCharsById
            (length, EVD_PROPERTY_ID_EVD_DIR)) && (0 < length))
            evdChars = chars;
        DBF("() ...out\n");
        return evdChars;
    }
};

#endif // _CEVCSEVCPSERVLET_HPP
