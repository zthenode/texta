///////////////////////////////////////////////////////////////////////
//   File: cevservletserver.hpp
//
// Author: $author$
//   Date: 9/10/2007
//
//    $Id$
///////////////////////////////////////////////////////////////////////

#ifndef _CEVSERVLETSERVER_HPP
#define _CEVSERVLETSERVER_HPP

#include "evservletserver.hpp"
#include "cevproperties.hpp"
#include "cevstring.hpp"
#include "evd.h"

///////////////////////////////////////////////////////////////////////
//  Class: CEvServletServer
//
// Author: $author$
//   Date: 9/10/2007
///////////////////////////////////////////////////////////////////////
class CEvServletServer
: virtual public EvServletServer,
  public CEvProperties
{
public:
    typedef EvServletServer CImplements;
    typedef CEvProperties CExtends;
    typedef CEvServletServer CDerives;

    CEvString m_dir;
    CEvString m_vcsDir;
    CEvString m_vcDir;
    CEvString m_ciDir;
    CEvString m_coDir;

    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvServletServer
    //
    //       Author: $author$
    //         Date: 9/10/2007
    ///////////////////////////////////////////////////////////////////////
    CEvServletServer() 
    : m_dir(DEFAULT_EVD_DIR),
      m_vcsDir(DEFAULT_EVD_EVCS_DIR),
      m_vcDir(DEFAULT_EVD_EVCS_VC_DIR),
      m_ciDir(DEFAULT_EVD_EVCS_CI_DIR),
      m_coDir(DEFAULT_EVD_EVCS_CO_DIR)
    {
    }
    ///////////////////////////////////////////////////////////////////////
    // Destructor: ~CEvServletServer
    //
    //      Author: $author$
    //        Date: 9/10/2007
    ///////////////////////////////////////////////////////////////////////
    virtual ~CEvServletServer()
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
#endif // _CEVSERVLETSERVER_HPP
