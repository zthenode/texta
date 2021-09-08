///////////////////////////////////////////////////////////////////////
//   File: cevcpsloginresponse.hpp
//
// Author: $author$
//   Date: 11/22/2007
///////////////////////////////////////////////////////////////////////

#ifndef _CEVCPSLOGINRESPONSE_HPP
#define _CEVCPSLOGINRESPONSE_HPP

#include "cevcpslogin.hpp"

///////////////////////////////////////////////////////////////////////
//  Class: CEvcpsLoginResponse
//
// Author: $author$
//   Date: 11/22/2007
///////////////////////////////////////////////////////////////////////
class CEvcpsLoginResponse
: public CEvcpsLogin
{
public:
    typedef CEvcpsLogin CExtends;
    typedef CEvcpsLoginResponse CDerives;

    CEvcpsCipherSuite m_cipherSuite;
    CEvcpsCompressionMethod m_compressionMethod;

    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvcpsLoginResponse
    //
    //       Author: $author$
    //         Date: 11/22/2007
    ///////////////////////////////////////////////////////////////////////
    CEvcpsLoginResponse() 
    {
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: Read
    //
    //   Author: $author$
    //     Date: 11/22/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG Read
    (EvCharReader& reader) 
    {
        LONG length = -EV_ERROR_FAILED;
        LONG count1, count2;

        if (0 > (count1 = CExtends::Read(reader)))
            return length;

        if (0 > (count2 = m_cipherSuite.Read(reader)))
            return length;

        count1 += count2;

        if (0 > (count2 = m_compressionMethod.Read(reader)))
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

        if (0 > (count2 = m_cipherSuite.Write(writer)))
            return length;

        count1 += count2;

        if (0 > (count2 = m_compressionMethod.Write(writer)))
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
        + m_cipherSuite.Sizeof()
        + m_compressionMethod.Sizeof();
        return size;
    }
};
#endif // _CEVCPSLOGINRESPONSE_HPP
