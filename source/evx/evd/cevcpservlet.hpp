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

#include "evcpservlet.hpp"
#include "cevservlet.hpp"
#include "cevstringwriter.hpp"
#include "evcs.hpp"
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
    // Function: ConnectionInitialize
    //
    //   Author: $author$
    //     Date: 9/20/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError ConnectionInitialize
    (EvcpServletConnection& connection) 
    {
        EvError error = EV_ERROR_NONE;
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: ConnectionFinalize
    //
    //   Author: $author$
    //     Date: 9/20/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError ConnectionFinalize
    (EvcpServletConnection& connection) 
    {
        EvError error = EV_ERROR_NONE;
        return error;
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
    // Function: AcquireEvcs
    //
    //   Author: $author$
    //     Date: 5/24/2007
    ///////////////////////////////////////////////////////////////////////
    virtual Evcs* AcquireEvcs
    (EvError& error, 
     const char* name=0, LONG length=-1) 
    {
        Evcs* evcs = 0;
        error = EV_ERROR_NOT_ALLOWED;
        return evcs;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: ReleaseEvcs
    //
    //   Author: $author$
    //     Date: 5/24/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError ReleaseEvcs(Evcs& evcs) 
    {
        EvError error = EV_ERROR_NOT_ALLOWED;
        return error;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: GetServletParentContext
    //
    //   Author: $author$
    //     Date: 9/20/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvcpServlet* 
    GetServletParentContext
    (EvcpServletConnection& connection) const
    {
        EvcpServlet* parentContext = 0;
        EvcpServlet* parent;
        EvError error;

        if ((parent = GetParentEvcpServlet(error)))
            parentContext = parent->GetEvcpServletContext(connection);
        return parentContext;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: GetEvcpServletContext
    //
    //   Author: $author$
    //     Date: 9/20/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvcpServlet* GetEvcpServletContext
    (EvcpServletConnection& connection) 
    {
        EvcpServlet* context;

        if (!(context = connection.
            FindEvcpServletContext(*this)))
            context = AddEvcpServletContext(connection);
        return context;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: AddEvcpServletContext
    //
    //   Author: $author$
    //     Date: 9/20/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvcpServlet* AddEvcpServletContext
    (EvcpServletConnection& connection) 
    {
        EvcpServlet* context;
        EvError error2;

        if ((context = NewEvcpServletContext(connection)))
        {
            if (!(error2 = context->SetParentEvcpServlet(this)))
            if (!(error2 = context->ConnectionInitialize(connection)))
            if (!(error2 = connection.AddEvcpServletContext(*context)))
                return context;
            else context->ConnectionFinalize(connection);

            context->DeleteInstance();
            context = 0;
        }
        return context;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: NewEvcpServletContext
    //
    //   Author: $author$
    //     Date: 9/20/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvcpServlet* NewEvcpServletContext
    (EvcpServletConnection& connection) 
    {
        EvcpServlet* context = 0;
        return context;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: SetParentEvcpServlet
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
    // Function: GetRequiredUnsignedHeaderField
    //
    //   Author: $author$
    //     Date: 9/12/2007
    ///////////////////////////////////////////////////////////////////////
    virtual const EvcpHeaderField* GetRequiredUnsignedHeaderField
    (ULONG& value, 
     const EvcpServletRequest& request,
     const char* chars) const 
    {
        const EvcpHeaderField* field = 0;
        LONG length;
		if ((field = GetRequiredHeaderField(request, chars)))
            value = field->GetUnsignedFieldValue(length);
        return field;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: GetUnsignedHeaderField
    //
    //   Author: $author$
    //     Date: 9/12/2007
    ///////////////////////////////////////////////////////////////////////
    virtual const EvcpHeaderField* GetUnsignedHeaderField
    (ULONG& value, 
     const EvcpServletRequest& request,
     const char* chars) const 
    {
        const EvcpHeaderField* field = 0;
        LONG length;
		if ((field = GetHeaderField(request, chars)))
            value = field->GetUnsignedFieldValue(length);
        return field;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: GetRequiredBoolHeaderField
    //
    //   Author: $author$
    //     Date: 9/12/2007
    ///////////////////////////////////////////////////////////////////////
    virtual const EvcpHeaderField* GetRequiredBoolHeaderField
    (bool& value, 
     const EvcpServletRequest& request,
     const char* chars,
     const char* isTrue) const 
    {
        const EvcpHeaderField* field = 0;
		if ((field = GetRequiredHeaderField(request, chars)))
            value = !field->CompareFieldValue(isTrue);
        return field;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: GetBoolHeaderField
    //
    //   Author: $author$
    //     Date: 9/12/2007
    ///////////////////////////////////////////////////////////////////////
    virtual const EvcpHeaderField* GetBoolHeaderField
    (bool& value, 
     const EvcpServletRequest& request,
     const char* chars,
     const char* isTrue) const 
    {
        const EvcpHeaderField* field = 0;
		if ((field = GetHeaderField(request, chars)))
            value = !field->CompareFieldValue(isTrue);
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
     const EvcpServletRequest& request,
     const char* chars) const 
    {
        const EvcpHeaderField* field = 0;
        LONG length;
		if ((field = GetRequiredHeaderField(request, chars)))
        if ((value = field->GetFieldValue(length)) && (0 < length))
            return field;
        return 0;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: GetHeaderField
    //
    //   Author: $author$
    //     Date: 9/12/2007
    ///////////////////////////////////////////////////////////////////////
    virtual const EvcpHeaderField* GetHeaderField
    (const char*& value, 
     const EvcpServletRequest& request,
     const char* chars) const 
    {
        const EvcpHeaderField* field = 0;
        LONG length;
		if ((field = GetHeaderField(request, chars)))
        if ((value = field->GetFieldValue(length)) && (0 < length))
            return field;
        return 0;
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
    ///////////////////////////////////////////////////////////////////////
    // Function: GetHeaderField
    //
    //   Author: $author$
    //     Date: 8/15/2007
    ///////////////////////////////////////////////////////////////////////
    virtual const EvcpHeaderField* GetHeaderField
    (const EvcpServletRequest& request,
     const char* chars) const 
    {
        const EvcpHeader& reqHeader = request.GetHeader();
        const EvcpHeaderField* field = reqHeader.FindField(chars);
        return field;
    }
};
#endif // _CEVCPSERVLET_HPP
