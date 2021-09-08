///////////////////////////////////////////////////////////////////////
//   File: cevservletresponse.hpp
//
// Author: $author$
//   Date: 4/16/2007
//
//    $Id$
///////////////////////////////////////////////////////////////////////

#ifndef _CEVSERVLETRESPONSE_HPP
#define _CEVSERVLETRESPONSE_HPP

#include "evservletresponse.hpp"
#include "cevservletinteraction.hpp"

///////////////////////////////////////////////////////////////////////
//  Class: CEvServletResponse
//
// Author: $author$
//   Date: 4/16/2007
///////////////////////////////////////////////////////////////////////
class CEvServletResponse
: virtual public EvServletResponse,
  public CEvServletInteraction
{
public:
    typedef EvServletResponse CImplements;
    typedef CEvServletInteraction CExtends;
    typedef CEvServletResponse CDerives;

    EvCharWriter& m_writer;

    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvServletResponse
    //
    //       Author: $author$
    //         Date: 4/16/2007
    ///////////////////////////////////////////////////////////////////////
    CEvServletResponse
    (EvServletConnection& connection,
     EvCharWriter& writer)
    : CExtends(connection),
      m_writer(writer)
    {
    }
    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvServletResponse
    //
    //       Author: $author$
    //         Date: 4/16/2007
    ///////////////////////////////////////////////////////////////////////
    CEvServletResponse(const CEvServletResponse& response)
    : CExtends(response.GetConnection()),
      m_writer(response.GetWriter())
    {
    }
    ///////////////////////////////////////////////////////////////////////
    // Destructor: ~CEvServletResponse
    //
    //      Author: $author$
    //        Date: 4/16/2007
    ///////////////////////////////////////////////////////////////////////
    virtual ~CEvServletResponse()
    {
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: GetWriter
    //
    //   Author: $author$
    //     Date: 4/16/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvCharWriter& GetWriter() const 
    {
        return m_writer;
    }
};
#endif // _CEVSERVLETRESPONSE_HPP
