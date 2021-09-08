///////////////////////////////////////////////////////////////////////
//   File: cevdtcpservletserver.hpp
//
// Author: $author$
//   Date: 12/11/2007
///////////////////////////////////////////////////////////////////////

#ifndef _CEVDTCPSERVLETSERVER_HPP
#define _CEVDTCPSERVLETSERVER_HPP

#include "cevtcpservletserver.hpp"
#include "cevstring.hpp"
#include "evd.h"

///////////////////////////////////////////////////////////////////////
//  Class: CEvdTcpServletServer
//
// Author: $author$
//   Date: 12/11/2007
///////////////////////////////////////////////////////////////////////
class CEvdTcpServletServer
: public CEvTcpServletServer
{
public:
    typedef CEvTcpServletServer CExtends;
    typedef CEvdTcpServletServer CDerives;

    CEvString m_dir;
    CEvString m_vcsDir;
    CEvString m_vcDir;
    CEvString m_ciDir;
    CEvString m_coDir;

    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvdTcpServletServer
    //
    //       Author: $author$
    //         Date: 12/11/2007
    ///////////////////////////////////////////////////////////////////////
    CEvdTcpServletServer() 
    : m_dir(DEFAULT_EVD_DIR),
      m_vcsDir(DEFAULT_EVD_EVCS_DIR),
      m_vcDir(DEFAULT_EVD_EVCS_VC_DIR),
      m_ciDir(DEFAULT_EVD_EVCS_CI_DIR),
      m_coDir(DEFAULT_EVD_EVCS_CO_DIR)
    {
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: End
    //
    //   Author: $author$
    //     Date: 9/10/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError End() 
    {
        EvError error = EV_ERROR_NONE;
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: Restart
    //
    //   Author: $author$
    //     Date: 9/10/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError Restart() 
    {
        EvError error = EV_ERROR_NONE;
        return error;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: GetPropertyCharsById
    //
    //   Author: $author$
    //     Date: 9/16/2007
    ///////////////////////////////////////////////////////////////////////
    virtual const char* GetPropertyCharsById
    (LONG& length,
     EvProperty::EvId id) const 
    {
        const char* chars = 0;
        length = -EV_ERROR_NOT_IMPLEMENTED;
        switch(id)
        {
        case EVD_PROPERTY_ID_EVD_DIR:
            chars = m_dir.Chars(length);
            break;
        case EVD_PROPERTY_ID_EVCS_DIR:
            chars = m_vcsDir.Chars(length);
            break;
        case EVD_PROPERTY_ID_EVCS_VC_DIR:
            chars = m_vcDir.Chars(length);
            break;
        case EVD_PROPERTY_ID_EVCS_CI_DIR:
            chars = m_ciDir.Chars(length);
            break;
        case EVD_PROPERTY_ID_EVCS_CO_DIR:
            chars = m_coDir.Chars(length);
            break;
        }
        return chars;
    }
};
#endif // _CEVDTCPSERVLETSERVER_HPP
