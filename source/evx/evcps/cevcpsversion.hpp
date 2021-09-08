///////////////////////////////////////////////////////////////////////
//   File: cevcpsversion.hpp
//
// Author: $author$
//   Date: 11/21/2007
///////////////////////////////////////////////////////////////////////

#ifndef _CEVCPSVERSION_HPP
#define _CEVCPSVERSION_HPP

#include "cevcpsbase.hpp"

#define EVCPS_VERSION_MAJOR TLS_VERSION_MAJOR
#define EVCPS_VERSION_MINOR TLS_VERSION_MINOR

///////////////////////////////////////////////////////////////////////
//  Class: CEvcpsVersion
//
// Author: $author$
//   Date: 11/21/2007
///////////////////////////////////////////////////////////////////////
class CEvcpsVersion
: public CEvcpsBase
{
public:
    typedef CEvcpsBase CExtends;
    typedef CEvcpsVersion CDerives;

    BYTE m_major;
    BYTE m_minor;

    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvcpsVersion
    //
    //       Author: $author$
    //         Date: 11/21/2007
    ///////////////////////////////////////////////////////////////////////
    CEvcpsVersion
    (BYTE major=EVCPS_VERSION_MAJOR, 
     BYTE minor=EVCPS_VERSION_MINOR)
    : m_major(major),
      m_minor(minor)
    {
    }
    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvcpsVersion
    //
    //       Author: $author$
    //         Date: 11/21/2007
    ///////////////////////////////////////////////////////////////////////
    CEvcpsVersion
    (const CEvcpsVersion& version)
    : m_major(version.m_major),
      m_minor(version.m_minor)
    {
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: Read
    //
    //   Author: $author$
    //     Date: 12/7/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG Read
    (EvCharReader& reader) 
    {
        LONG length = -EV_ERROR_FAILED;
        LONG count1, count2;
        if (0 < (count1 = reader.Read((char*)&m_major, sizeof(m_major))))
        if (0 < (count2 = reader.Read((char*)&m_minor, sizeof(m_minor))))
            length = count1 + count2;
        return length;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: Write
    //
    //   Author: $author$
    //     Date: 11/8/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG Write(EvCharWriter& writer)
    {
        LONG length = -EV_ERROR_FAILED;
        LONG count1, count2;
        if (0 < (count1 = writer.Write((char*)&m_major, sizeof(m_major))))
        if (0 < (count2 = writer.Write((char*)&m_minor, sizeof(m_minor))))
            length = count1 + count2;
        return length;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: Sizeof
    //
    //   Author: $author$
    //     Date: 11/23/2007
    ///////////////////////////////////////////////////////////////////////
    virtual USHORT Sizeof() const 
    {
        USHORT size = sizeof(m_major)+sizeof(m_minor);
        return size;
    }
};
#endif // _CEVCPSVERSION_HPP
