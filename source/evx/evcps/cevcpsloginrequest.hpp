///////////////////////////////////////////////////////////////////////
//   File: cevcpsloginrequest.hpp
//
// Author: $author$
//   Date: 11/22/2007
///////////////////////////////////////////////////////////////////////

#ifndef _CEVCPSLOGINREQUEST_HPP
#define _CEVCPSLOGINREQUEST_HPP

#include "cevcpslogin.hpp"

///////////////////////////////////////////////////////////////////////
//  Class: CEvcpsLoginRequest
//
// Author: $author$
//   Date: 11/22/2007
///////////////////////////////////////////////////////////////////////
class CEvcpsLoginRequest
: public CEvcpsLogin
{
public:
    typedef CEvcpsLogin CExtends;
    typedef CEvcpsLoginRequest CDerives;

    CEvcpsCipherSuites m_cipherSuites;
    CEvcpsCompressionMethods m_compressionMethods;

    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvcpsLoginRequest
    //
    //       Author: $author$
    //         Date: 11/22/2007
    ///////////////////////////////////////////////////////////////////////
    CEvcpsLoginRequest() 
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

        if (0 > (count1 = CExtends::Read(reader)))
            return length;

        if (0 > (count2 = m_cipherSuites.Read(reader)))
            return length;

        count1 += count2;

        if (0 > (count2 = m_compressionMethods.Read(reader)))
            return length;

        length = count1 + count2;
        return length;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: Write
    //
    //   Author: $author$
    //     Date: 11/22/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG Write
    (EvCharWriter& writer) 
    {
        LONG length = -EV_ERROR_FAILED;
        LONG count1, count2;

        if (0 > (count1 = CExtends::Write(writer)))
            return length;

        if (0 > (count2 = m_cipherSuites.Write(writer)))
            return length;

        count1 += count2;

        if (0 > (count2 = m_compressionMethods.Write(writer)))
            return length;

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
        USHORT size = CExtends::Sizeof()
        + m_cipherSuites.Sizeof()
        + m_compressionMethods.Sizeof();
        return size;
    }
};
#endif // _CEVCPSLOGINREQUEST_HPP
