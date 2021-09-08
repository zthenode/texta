///////////////////////////////////////////////////////////////////////
//   File: cevcpservlet.hpp
//
// Author: $author$
//   Date: 4/23/2007
//
//    $Id$
///////////////////////////////////////////////////////////////////////

#ifndef _CEVCPSERVLET_HPP
#define _CEVCPSERVLET_HPP

#include "evcpservletcontext.hpp"
#include "evcpservlet.hpp"
#include "cevservlet.hpp"
#include "cevstringwriter.hpp"
#include "evdebug.h"

#define CEVCP_CONNECTION_FIELDNAME EVCP_HEADER_FIELD_NAME_CONNECTION
#define CEVCP_KEEPALIVE_FIELDVALUE EVCP_HEADER_FIELD_VALUE_CONNECTION_KEEPALIVE

#define CEVCP_IS_BINARY_FIELDNAME EVCP_HEADER_FIELD_NAME_IS_BINARY
#define CEVCP_IS_BINARY_FIELDVALUE EVCP_HEADER_FIELD_VALUE_IS_BINARY_YES

#define CEVCP_BLOCK_FIELDNAME EVCP_HEADER_FIELD_NAME_BLOCK
#define CEVCP_BLOCKSIZE_FIELDNAME EVCP_HEADER_FIELD_NAME_BLOCK_SIZE
#define CEVCP_BLOCKLENGTH_FIELDNAME EVCP_HEADER_FIELD_NAME_BLOCK_LENGTH

///////////////////////////////////////////////////////////////////////
//  Class: CEvcpServlet
//
// Author: $author$
//   Date: 4/23/2007
///////////////////////////////////////////////////////////////////////
class CEvcpServlet
: virtual public EvcpServlet,
  public CEvServlet
{
public:
    typedef EvcpServlet CImplements;
    typedef CEvServlet CExtends;
    typedef CEvcpServlet CDerives;

    CEvString m_chars;
    CEvStringWriter m_charsWriter;

    EvcpServlet* m_parentEvcpServlet;

    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvcpServlet
    //
    //       Author: $author$
    //         Date: 4/26/2007
    ///////////////////////////////////////////////////////////////////////
    CEvcpServlet
    (const char* name=0, LONG length=-1) 
    : CExtends(name, length),
      m_charsWriter(m_chars),
      m_parentEvcpServlet(0)
    {
    }
    ///////////////////////////////////////////////////////////////////////
    // Destructor: ~CEvcpServlet
    //
    //      Author: $author$
    //        Date: 4/26/2007
    ///////////////////////////////////////////////////////////////////////
    virtual ~CEvcpServlet()
    {
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: Service
    //
    //   Author: $author$
    //     Date: 4/23/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError Service
    (EvcpServletRequest& request,
     EvcpServletResponse& response) 
    {
        EvError error = EV_ERROR_NONE;
        DBF("() in...\n");
        DBF("() ...out\n");
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: SetKeepAlive
    //
    //   Author: $author$
    //     Date: 5/23/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError SetKeepAlive
    (EvcpServletRequest& request,
     EvcpServletResponse& response) 
    {
        EvError error = EV_ERROR_NONE;
        EvcpHeader& reqHeader = request.GetHeader();
        EvServletConnection& connection = response.GetConnection();
        EvcpHeaderField* field;
        const char* chars;
        LONG length;
		bool keepAlive;

        if ((field = reqHeader.FindField(CEVCP_CONNECTION_FIELDNAME)))
        {
			if ((chars = field->GetFieldValue(length)))
				DBT("() %s \"%s\"\n", CEVCP_CONNECTION_FIELDNAME, chars);
            keepAlive = (!field->CompareFieldValue(CEVCP_KEEPALIVE_FIELDVALUE));
            connection.SetKeepAlive(keepAlive);
        }

        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: RespondStatusOk
    //
    //   Author: $author$
    //     Date: 5/23/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError RespondStatusOk
    (EvcpServletResponse& response) 
    {
        EvError error = RespondStatusCode
        (response, EVCP_STATUS_CODE_OK, 
         EVCP_STATUS_DESC_OK);
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: RespondStatus
    //
    //   Author: $author$
    //     Date: 5/29/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError RespondStatus
    (EvcpServletResponse& response, int status) 
    {
        EvError error = EV_ERROR_FAILED;

        if ((status >= FIRST_EVCP_STATUS) 
            && (status <= LAST_EVCP_STATUS))
            error = RespondStatusCode
            (response, 
             g_evcpStatusCode[status-FIRST_EVCP_STATUS], 
             g_evcpStatusDesc[status-FIRST_EVCP_STATUS]);

        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: RespondStatusCode
    //
    //   Author: $author$
    //     Date: 5/1/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError RespondStatusCode
    (EvcpServletResponse& response,
     ULONG statusCode, const char* statusDesc) 
    {
        EvCharWriter& writer = response.GetWriter();
        EvError error;
        LONG length;
        const char* chars;
        
        m_chars.Clear();

        if (!(error = RespondStatusCode
            (m_charsWriter, response, statusCode, statusDesc)))
        if ((chars = m_chars.Chars(length)) && (0 < length))
        {
            DBT("() --> \"%s\"\n", chars);
            if (0 > (length = m_chars.Write(writer)))
                error = -length;
        }
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: RespondStatusCode
    //
    //   Author: $author$
    //     Date: 5/1/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError RespondStatusCode
    (EvCharWriter& writer,
     EvcpServletResponse& response,
     ULONG statusCode, const char* statusDesc) 
    {
        EvError error = EV_ERROR_NONE;
        EvcpHeader& respHeader = response.GetHeader();
        EvcpHeaderHeading& respHeading = respHeader.GetHeading();

        respHeading.SetResponseStatusUnsigned(statusCode);
        respHeading.SetResponseDescription(statusDesc);
        respHeader.WriteResponse(writer);
        return error;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: SetEvcpServletContext
    //
    //   Author: $author$
    //     Date: 5/24/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError SetEvcpServletContext
    (EvcpServletContext* context) 
    {
        EvError error = EV_ERROR_NOT_ALLOWED;
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: GetEvcpServletContext
    //
    //   Author: $author$
    //     Date: 5/24/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvcpServletContext* GetEvcpServletContext
    (EvError& error) const 
    {
        EvcpServletContext* evcpServletContext = 0;
        error = EV_ERROR_NOT_ALLOWED;
        return evcpServletContext;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: SetParentServlet
    //
    //   Author: $author$
    //     Date: 5/24/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError SetParentEvcpServlet
    (EvcpServlet* servlet) 
    {
        EvError error = EV_ERROR_NONE;
        m_parentEvcpServlet = servlet;
        m_parentServlet = servlet;
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: GetParentEvcpServlet
    //
    //   Author: $author$
    //     Date: 5/24/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvcpServlet* 
    GetParentEvcpServlet(EvError& error) const 
    {
        error = EV_ERROR_NONE;
        return m_parentEvcpServlet;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: FindEvcpServlet
    //
    //   Author: $author$
    //     Date: 5/24/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvcpServlet* FindEvcpServlet
    (const char* name, LONG length=-1) const
    {
        EvcpServlet* servlet = 0;
        return servlet;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: GetRequiredHeaderField
    //
    //   Author: $author$
    //     Date: 8/15/2007
    ///////////////////////////////////////////////////////////////////////
    virtual const EvcpHeaderField* GetRequiredHeaderField
    (const EvcpServletRequest& request,
     const char* chars) const 
    {
        const EvcpHeader& reqHeader = request.GetHeader();
        const EvcpHeaderField* field = 0;
		if (!(field = reqHeader.FindField(chars)))
			DBE("() missing header field \"%s\"\n", chars);
        return field;
    }
};
#endif // _CEVCPSERVLET_HPP
