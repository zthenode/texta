///////////////////////////////////////////////////////////////////////
//   File: cevcpschangecipherspec.hpp
//
// Author: $author$
//   Date: 11/30/2007
///////////////////////////////////////////////////////////////////////

#ifndef _CEVCPSCHANGECIPHERSPEC_HPP
#define _CEVCPSCHANGECIPHERSPEC_HPP

#include "cevcpsbase.hpp"

///////////////////////////////////////////////////////////////////////
//   Enum:  
//
// Author: $author$
//   Date: 11/30/2007
///////////////////////////////////////////////////////////////////////
enum 
{
    EVCPS_CHANGE_CIPHER_SPEC_TYPE_CHANGE_CIPHER_SPEC 
    = TLS_CHANGE_CIPHER_SPEC_TYPE_CHANGE_CIPHER_SPEC
};

///////////////////////////////////////////////////////////////////////
//  Class: CEvcpsChangeCipherSpec
//
// Author: $author$
//   Date: 11/30/2007
///////////////////////////////////////////////////////////////////////
class CEvcpsChangeCipherSpec
: public CEvcpsBase
{
public:
    typedef CEvcpsBase CExtends;
    typedef CEvcpsChangeCipherSpec CDerives;

    BYTE m_type;

    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvcpsChangeCipherSpec
    //
    //       Author: $author$
    //         Date: 11/30/2007
    ///////////////////////////////////////////////////////////////////////
    CEvcpsChangeCipherSpec
    (BYTE type=EVCPS_CHANGE_CIPHER_SPEC_TYPE_CHANGE_CIPHER_SPEC) 
    : m_type(type)
    {
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: Read
    //
    //   Author: $author$
    //     Date: 11/30/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG Read
    (EvCharReader& reader) 
    {
        LONG length = -EV_ERROR_FAILED;
        return length;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: Write
    //
    //   Author: $author$
    //     Date: 11/30/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG Write
    (EvCharWriter& writer) 
    {
        LONG length = writer.Write
        ((char*)(&m_type), sizeof(m_type));
        return length;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: Sizeof
    //
    //   Author: $author$
    //     Date: 11/30/2007
    ///////////////////////////////////////////////////////////////////////
    virtual USHORT Sizeof() const 
    {
        USHORT size = sizeof(m_type);
        return size;
    }
};

#endif // _CEVCPSCHANGECIPHERSPEC_HPP
