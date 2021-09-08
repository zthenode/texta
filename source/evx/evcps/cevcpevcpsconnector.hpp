///////////////////////////////////////////////////////////////////////
//   File: cevcpevcpsconnector.hpp
//
// Author: $author$
//   Date: 12/21/2007
///////////////////////////////////////////////////////////////////////

#ifndef _CEVCPEVCPSCONNECTOR_HPP
#define _CEVCPEVCPSCONNECTOR_HPP

#include "cevbase.hpp"
#include "cevstringwriter.hpp"
#include "cevstringreader.hpp"
#include "cevstring.hpp"

#define DEFAULT_EVCP_EVCPS_IS_HEX_ENCODED true

///////////////////////////////////////////////////////////////////////
//  Class: CEvcpEvcpsConnector
//
// Author: $author$
//   Date: 12/21/2007
///////////////////////////////////////////////////////////////////////
class CEvcpEvcpsConnector
: public CEvBase
{
public:
    typedef CEvBase CExtends;
    typedef CEvcpEvcpsConnector CDerives;

    CEvString m_applicationDataString;
    CEvStringWriter m_applicationDataWriter;
    CEvStringReader m_applicationDataReader;

    bool m_isHexEncoded;

    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvcpEvcpsConnector
    //
    //       Author: $author$
    //         Date: 12/21/2007
    ///////////////////////////////////////////////////////////////////////
    CEvcpEvcpsConnector() 
    : m_applicationDataWriter(m_applicationDataString),
      m_applicationDataReader(m_applicationDataString),
      m_isHexEncoded(DEFAULT_EVCP_EVCPS_IS_HEX_ENCODED)
    {
    }
    ///////////////////////////////////////////////////////////////////////
    // Destructor: ~CEvcpEvcpsConnector
    //
    //      Author: $author$
    //        Date: 12/21/2007
    ///////////////////////////////////////////////////////////////////////
    virtual ~CEvcpEvcpsConnector()
    {
    }
};
#endif // _CEVCPEVCPSCONNECTOR_HPP
