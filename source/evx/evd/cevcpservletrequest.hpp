///////////////////////////////////////////////////////////////////////
//   File: cevcpservletrequest.hpp
//
// Author: $author$
//   Date: 4/23/2007
//
//    $Id$
///////////////////////////////////////////////////////////////////////

#ifndef _CEVCPSERVLETREQUEST_HPP
#define _CEVCPSERVLETREQUEST_HPP

#include "evcpservletrequest.hpp"
#include "cevservletrequest.hpp"
#include "cevcpheader.hpp"

///////////////////////////////////////////////////////////////////////
//  Class: CEvcpServletRequest
//
// Author: $author$
//   Date: 4/23/2007
///////////////////////////////////////////////////////////////////////
class CEvcpServletRequest
: virtual public EvcpServletRequest,
  public CEvServletRequest
{
public:
    typedef EvcpServletRequest CImplements;
    typedef CEvServletRequest CExtends;
    typedef CEvcpServletRequest CDerives;

    EvcpServletConnection& m_evcpConnection;
    CEvcpHeader m_header;

    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvcpServletRequest
    //
    //       Author: $author$
    //         Date: 4/23/2007
    ///////////////////////////////////////////////////////////////////////
    CEvcpServletRequest
    (EvcpServletConnection& evcpConnection,
     EvCharReader& reader) 
    : CExtends((EvServletConnection&)(evcpConnection), reader),
      m_evcpConnection(evcpConnection)
    {
    }
    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvcpServletRequest
    //
    //       Author: $author$
    //         Date: 4/23/2007
    ///////////////////////////////////////////////////////////////////////
    CEvcpServletRequest
    (const CEvcpServletRequest& request) 
    : CExtends(request.GetConnection(), request.GetReader()),
      m_evcpConnection(request.GetEvcpConnection())
    {
    }
    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvcpServletRequest
    //
    //       Author: $author$
    //         Date: 4/23/2007
    ///////////////////////////////////////////////////////////////////////
    CEvcpServletRequest
    (const EvcpServletRequest& request) 
    : CExtends(request.GetConnection(), request.GetReader()),
      m_evcpConnection(request.GetEvcpConnection())
    {
    }
    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvcpServletRequest
    //
    //       Author: $author$
    //         Date: 4/23/2007
    ///////////////////////////////////////////////////////////////////////
    CEvcpServletRequest
    (const EvServletRequest& request,
     EvcpServletConnection& evcpConnection) 
    : CExtends(request.GetConnection(), request.GetReader()),
      m_evcpConnection(evcpConnection)
    {
    }
    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvcpServletRequest
    //
    //       Author: $author$
    //         Date: 10/14/2007
    ///////////////////////////////////////////////////////////////////////
    CEvcpServletRequest
    (const EvServletRequest& request,
     EvcpServletConnection& evcpConnection,
     EvCharReader& reader) 
    : CExtends(request.GetConnection(), reader),
      m_evcpConnection(evcpConnection)
    {
    }
    ///////////////////////////////////////////////////////////////////////
    // Destructor: ~CEvcpServletRequest
    //
    //      Author: $author$
    //        Date: 4/23/2007
    ///////////////////////////////////////////////////////////////////////
    virtual ~CEvcpServletRequest()
    {
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
};
#endif // _CEVCPSERVLETREQUEST_HPP
