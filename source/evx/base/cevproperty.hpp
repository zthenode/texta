///////////////////////////////////////////////////////////////////////
//   File: cevproperty.hpp
//
// Author: $author$
//   Date: 7/16/2007
//
//    $Id$
///////////////////////////////////////////////////////////////////////

#ifndef _CEVPROPERTY_HPP
#define _CEVPROPERTY_HPP

#include "evproperty.hpp"
#include "cevstring.hpp"
#include "cevbase.hpp"

///////////////////////////////////////////////////////////////////////
//  Class: CEvProperty
//
// Author: $author$
//   Date: 7/16/2007
///////////////////////////////////////////////////////////////////////
class CEvProperty
: virtual public EvProperty,
  public CEvBase
{
public:
    typedef EvProperty CImplements;
    typedef CEvBase CExtends;
    typedef CEvProperty CDerives;

    EvType m_type;
    CEvString m_name;

    CEvString m_chars;
    ULONG m_unsigned;
    LONG m_signed;
    bool m_bool;

    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvProperty
    //
    //       Author: $author$
    //         Date: 7/16/2007
    ///////////////////////////////////////////////////////////////////////
    CEvProperty
    (EvType type=EV_TYPE_CHARS,
     const char* chars=0,
     LONG length=-1) 
    : m_type(type)
    {
        EvError error;
        if (chars)
        if (0 > (length = SetName(chars, length)))
            throw(error = -length);
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: SetType
    //
    //   Author: $author$
    //     Date: 7/17/2007
    ///////////////////////////////////////////////////////////////////////
    virtual int SetType(EvType type) 
    {
        m_type = type;
        return m_type;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: GetType
    //
    //   Author: $author$
    //     Date: 7/17/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvType GetType() const 
    {
        return m_type;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: SetName
    //
    //   Author: $author$
    //     Date: 7/16/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG SetName
    (const char* chars,
     LONG length=-1) 
    {
        length = m_name.Assign(chars,length);
        return length;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: GetName
    //
    //   Author: $author$
    //     Date: 7/16/2007
    ///////////////////////////////////////////////////////////////////////
    virtual const char* GetName
    (LONG& length) const 
    {
        const char* chars = m_name.Chars(length);
        return chars;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: SetChars
    //
    //   Author: $author$
    //     Date: 7/16/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG SetChars
    (const char* chars,
     LONG length=-1) 
    {
        length = m_chars.Assign(chars,length);
        return length;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: GetChars
    //
    //   Author: $author$
    //     Date: 7/16/2007
    ///////////////////////////////////////////////////////////////////////
    virtual const char* GetChars
    (LONG& length) const 
    {
        const char* chars = m_chars.Chars(length);
        return chars;
    }
};
#endif // _CEVPROPERTY_HPP
