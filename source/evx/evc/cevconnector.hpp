///////////////////////////////////////////////////////////////////////
//   File: cevconnector.hpp
//
// Author: $author$
//   Date: 8/2/2007
//
//    $Id$
///////////////////////////////////////////////////////////////////////

#ifndef _CEVCONNECTOR_HPP
#define _CEVCONNECTOR_HPP

#include "evconnector.hpp"
#include "cevbase.hpp"

///////////////////////////////////////////////////////////////////////
//  Class: CEvConnector
//
// Author: $author$
//   Date: 8/2/2007
///////////////////////////////////////////////////////////////////////
class CEvConnector
: virtual public EvConnector,
  public CEvBase
{
public:
    typedef EvConnector CImplements;
    typedef CEvBase CExtends;
    typedef CEvConnector CDerives;

    bool m_isConnected;

    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvConnector
    //
    //       Author: $author$
    //         Date: 8/2/2007
    ///////////////////////////////////////////////////////////////////////
    CEvConnector()
    : m_isConnected(false)
    {
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: Connect
    //
    //   Author: $author$
    //     Date: 8/2/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError Connect
    (bool& disconnect) 
    {
        EvError error = EV_ERROR_FAILED;
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: Disconnect
    //
    //   Author: $author$
    //     Date: 8/2/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError Disconnect
    (bool onlyIfConnected=false) 
    {
        EvError error = EV_ERROR_FAILED;
        return error;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: SetIsConnected
    //
    //   Author: $author$
    //     Date: 8/2/2007
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
    //     Date: 8/2/2007
    ///////////////////////////////////////////////////////////////////////
    virtual bool GetIsConnected() const 
    {
        return m_isConnected;
    }
};
#endif // _CEVCONNECTOR_HPP
