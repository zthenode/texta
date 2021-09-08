///////////////////////////////////////////////////////////////////////
//   File: cevcpsciphersuite.hpp
//
// Author: $author$
//   Date: 11/21/2007
///////////////////////////////////////////////////////////////////////

#ifndef _CEVCPSCIPHERSUITE_HPP
#define _CEVCPSCIPHERSUITE_HPP

#include "cevcpsbase.hpp"
#include "cevcpskeyexchange.hpp"
#include "cevcpscipher.hpp"
#include "cevcpsmac.hpp"

#define EVCPS_CIPHER_SUITE_VALUE_NULL_WITH_NULL_NULL \
    TLS_NULL_WITH_NULL_NULL

#define EVCPS_CIPHER_SUITE_VALUE_RSA_WITH_3DES_EDE_CBC_SHA \
    TLS_RSA_WITH_3DES_EDE_CBC_SHA

#define EVCPS_CIPHER_SUITE_VALUE_RSA_WITH_AES_256_CBC_SHA \
    TLS_RSA_WITH_AES_256_CBC_SHA

#define DEFAULT_EVCPS_CIPHER_SUITE_VALUE \
    EVCPS_CIPHER_SUITE_VALUE_RSA_WITH_3DES_EDE_CBC_SHA

///////////////////////////////////////////////////////////////////////
//   Enum:  
//
// Author: $author$
//   Date: 12/3/2007
///////////////////////////////////////////////////////////////////////
enum 
{
    EVCPS_CIPHER_SUITE_NULL_WITH_NULL_NULL,

    EVCPS_CIPHER_SUITE_RSA_WITH_3DES_EDE_CBC_SHA,
    EVCPS_CIPHER_SUITE_RSA_WITH_AES_256_CBC_SHA,

    EVCPS_CIPHER_SUITES
};

///////////////////////////////////////////////////////////////////////
//  Class: CEvcpsCipherSuiteAttributes
//
// Author: $author$
//   Date: 12/3/2007
///////////////////////////////////////////////////////////////////////
class CEvcpsCipherSuiteAttributes
{
public:
    typedef CEvcpsCipherSuiteAttributes CDerives;

    BYTE m_keyExchangeAlgorithm;
    BYTE m_bulkCipherAlgorithm;
    BYTE m_macAlgorithm;
};

///////////////////////////////////////////////////////////////////////
//  Class: CEvcpsCipherSuite
//
// Author: $author$
//   Date: 11/21/2007
///////////////////////////////////////////////////////////////////////
class CEvcpsCipherSuite
: public CEvcpsBase
{
public:
    typedef CEvcpsBase CExtends;
    typedef CEvcpsCipherSuite CDerives;

    static CEvcpsCipherSuiteAttributes 
    m_suiteAttributes[EVCPS_CIPHER_SUITES];

    static USHORT 
    m_suiteValue[EVCPS_CIPHER_SUITES];

    BYTE m_value[2];

    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvcpsCipherSuite
    //
    //       Author: $author$
    //         Date: 11/21/2007
    ///////////////////////////////////////////////////////////////////////
    CEvcpsCipherSuite
    (USHORT suite=DEFAULT_EVCPS_CIPHER_SUITE_VALUE)
    {
        m_value[0] = (BYTE)((suite >> 8) & 255);
        m_value[1] = (BYTE)(suite & 255);
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: GetAttributes
    //
    //   Author: $author$
    //     Date: 12/4/2007
    ///////////////////////////////////////////////////////////////////////
    virtual CEvcpsCipherSuiteAttributes& 
    GetAttributes() const 
    {
        CEvcpsCipherSuiteAttributes& 
        attributes = m_suiteAttributes
        [EVCPS_CIPHER_SUITE_NULL_WITH_NULL_NULL];
        BYTE suite;

        if (EVCPS_CIPHER_SUITES > (suite = GetSuite()))
            return m_suiteAttributes[suite];

        return attributes;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: GetSuite
    //
    //   Author: $author$
    //     Date: 12/4/2007
    ///////////////////////////////////////////////////////////////////////
    virtual BYTE GetSuite() const 
    {
        BYTE suite = EVCPS_CIPHER_SUITE_NULL_WITH_NULL_NULL;
        SHORT value = (m_value[0] << 8) | m_value[1];

        for (BYTE i=0; i<EVCPS_CIPHER_SUITES; i++)
            if (value == m_suiteValue[i])
                return i;
        return suite;
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
        LONG count;
        if (0 < (count = reader.Read
            ((char*)m_value, sizeof(m_value))))
            length = count;
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
        LONG count;
        if (0 < (count = writer.Write
            ((char*)m_value, sizeof(m_value))))
            length = count;
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
        USHORT size = sizeof(m_value);
        return size;
    }
};
#endif // _CEVCPSCIPHERSUITE_HPP
