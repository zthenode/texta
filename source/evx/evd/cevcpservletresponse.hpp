///////////////////////////////////////////////////////////////////////
//   File: cevcpservletresponse.hpp
//
// Author: $author$
//   Date: 4/23/2007
//
//    $Id$
///////////////////////////////////////////////////////////////////////

#ifndef _CEVCPSERVLETRESPONSE_HPP
#define _CEVCPSERVLETRESPONSE_HPP

#include "evcpservletresponse.hpp"
#include "cevcpservletrequest.hpp"
#include "cevservletresponse.hpp"
#include "cevcpheader.hpp"

///////////////////////////////////////////////////////////////////////
//  Class: CEvcpServletResponse
//
// Author: $author$
//   Date: 4/23/2007
///////////////////////////////////////////////////////////////////////
class CEvcpServletResponse
: virtual public EvcpServletResponse,
  public CEvServletResponse
{
public:
    typedef EvcpServletResponse CImplements;
    typedef CEvServletResponse CExtends;
    typedef CEvcpServletResponse CDerives;

    CEvcpHeader m_header;

    EvcpServletConnection& m_evcpConnection;

    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvcpServletResponse
    //
    //       Author: $author$
    //         Date: 4/23/2007
    ///////////////////////////////////////////////////////////////////////
    CEvcpServletResponse
    (EvcpServletConnection& evcpConnection,
     EvCharWriter& writer)
    : CExtends((EvServletConnection&)(evcpConnection), writer),
      m_evcpConnection(evcpConnection)
    {
    }
    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvcpServletResponse
    //
    //       Author: $author$
    //         Date: 4/23/2007
    ///////////////////////////////////////////////////////////////////////
    CEvcpServletResponse
    (const CEvcpServletResponse& response) 
    : CExtends(response.GetConnection(), response.GetWriter()),
      m_evcpConnection(response.GetEvcpConnection())
    {
    }
    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvcpServletResponse
    //
    //       Author: $author$
    //         Date: 8/19/2007
    ///////////////////////////////////////////////////////////////////////
    CEvcpServletResponse
    (const EvcpServletResponse& response) 
    : CExtends(response.GetConnection(), response.GetWriter()),
      m_evcpConnection(response.GetEvcpConnection())
    {
    }
    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvcpServletResponse
    //
    //       Author: $author$
    //         Date: 4/23/2007
    ///////////////////////////////////////////////////////////////////////
    CEvcpServletResponse
    (const EvServletResponse& response,
     EvcpServletConnection& evcpConnection) 
    : CExtends(response.GetConnection(), response.GetWriter()),
      m_evcpConnection(evcpConnection)
    {
    }
    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvcpServletResponse
    //
    //       Author: $author$
    //         Date: 8/19/2007
    ///////////////////////////////////////////////////////////////////////
    CEvcpServletResponse
    (const EvcpServletRequest& request,
     const EvcpServletResponse& response) 
    : CExtends(response.GetConnection(), response.GetWriter()),
      m_header(request.GetHeader()),
      m_evcpConnection(response.GetEvcpConnection())
    {
    }
    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvcpServletResponse
    //
    //       Author: $author$
    //         Date: 4/23/2007
    ///////////////////////////////////////////////////////////////////////
    CEvcpServletResponse
    (const EvcpServletRequest& request,
     const EvServletResponse& response,
     EvcpServletConnection& evcpConnection) 
    : CExtends(response.GetConnection(), response.GetWriter()),
      m_header(request.GetHeader()),
      m_evcpConnection(evcpConnection)
    {
    }
    ///////////////////////////////////////////////////////////////////////
    // Destructor: ~CEvcpServletResponse
    //
    //      Author: $author$
    //        Date: 4/23/2007
    ///////////////////////////////////////////////////////////////////////
    virtual ~CEvcpServletResponse()
    {
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: Write
    //
    //   Author: $author$
    //     Date: 4/25/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG Write
    (EvCharWriter& writer, LONG length=-1) 
    {
        LONG count = m_header.Write(writer, length);
        return count;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: GetEvcpConnection
    //
    //   Author: $author$
    //     Date: 6/3/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvcpServletConnection& GetEvcpConnection() const
    {
        return (EvcpServletConnection&)(m_evcpConnection);
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: GetHeader
    //
    //   Author: $author$
    //     Date: 4/23/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvcpHeader& GetHeader() const 
    {
        return (EvcpHeader&)(m_header);
    }
};
#endif // _CEVCPSERVLETRESPONSE_HPP
