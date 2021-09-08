///////////////////////////////////////////////////////////////////////
//   File: cevservletrequest.hpp
//
// Author: $author$
//   Date: 4/16/2007
//
//    $Id$
///////////////////////////////////////////////////////////////////////

#ifndef _CEVSERVLETREQUEST_HPP
#define _CEVSERVLETREQUEST_HPP

#include "evservletrequest.hpp"
#include "cevservletinteraction.hpp"

///////////////////////////////////////////////////////////////////////
//  Class: CEvServletRequest
//
// Author: $author$
//   Date: 4/16/2007
///////////////////////////////////////////////////////////////////////
class CEvServletRequest
: virtual public EvServletRequest,
  public CEvServletInteraction
{
public:
    typedef EvServletRequest CImplements;
    typedef CEvServletInteraction CExtends;
    typedef CEvServletRequest CDerives;

    EvCharReader& m_reader;

    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvServletRequest
    //
    //       Author: $author$
    //         Date: 4/16/2007
    ///////////////////////////////////////////////////////////////////////
    CEvServletRequest
    (EvServletConnection& connection,
     EvCharReader& reader)
    : CExtends(connection),
      m_reader(reader) 
    {
    }
    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvServletRequest
    //
    //       Author: $author$
    //         Date: 4/16/2007
    ///////////////////////////////////////////////////////////////////////
    CEvServletRequest(const CEvServletRequest& request)
    : CExtends(request.GetConnection()),
      m_reader(request.GetReader()) 
    {
    }
    ///////////////////////////////////////////////////////////////////////
    // Destructor: ~CEvServletRequest
    //
    //      Author: $author$
    //        Date: 4/16/2007
    ///////////////////////////////////////////////////////////////////////
    virtual ~CEvServletRequest()
    {
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: GetReader
    //
    //   Author: $author$
    //     Date: 4/16/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvCharReader& GetReader() const 
    {
        return m_reader;
    }
};
#endif // _CEVSERVLETREQUEST_HPP
