///////////////////////////////////////////////////////////////////////
//   File: cevcpheaderline.hpp
//
// Author: $author$
//   Date: 5/16/2007
//
//    $Id$
///////////////////////////////////////////////////////////////////////

#ifndef _CEVCPHEADERLINE_HPP
#define _CEVCPHEADERLINE_HPP

#include "evcpheaderline.hpp"
#include "cevstring.hpp"

///////////////////////////////////////////////////////////////////////
//  Class: CEvcpHeaderLine
//
// Author: $author$
//   Date: 5/16/2007
///////////////////////////////////////////////////////////////////////
class CEvcpHeaderLine
: virtual public EvcpHeaderLine,
  public CEvString
{
public:
    typedef EvcpHeaderLine CImplements;
    typedef CEvString CExtends;
    typedef CEvcpHeaderLine CDerives;

    bool m_hasCR;
    bool m_hasLF;

    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvcpHeaderLine
    //
    //       Author: $author$
    //         Date: 5/16/2007
    ///////////////////////////////////////////////////////////////////////
    CEvcpHeaderLine
    (bool hasCR=false, bool hasLF=true) 
    : m_hasCR(hasCR),
      m_hasLF(hasLF)
    {
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: ClearLine
    //
    //   Author: $author$
    //     Date: 5/17/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG ClearLine
    (bool hasCR=false,
     bool hasLF=true) 
    {
        LONG length = ClearChars();
        m_hasCR = hasCR;
        m_hasLF = hasLF;
        return length;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: ClearChars
    //
    //   Author: $author$
    //     Date: 5/19/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG ClearChars() 
    {
        LONG length = Clear();
        return length;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: SetHasCR
    //
    //   Author: $author$
    //     Date: 5/16/2007
    ///////////////////////////////////////////////////////////////////////
    virtual int SetHasCR
    (bool has=true) 
    {
        m_hasCR = has;
        return m_hasCR;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: GetHasCR
    //
    //   Author: $author$
    //     Date: 5/16/2007
    ///////////////////////////////////////////////////////////////////////
    virtual bool GetHasCR() const 
    {
        return m_hasCR;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: SetHasLF
    //
    //   Author: $author$
    //     Date: 5/16/2007
    ///////////////////////////////////////////////////////////////////////
    virtual int SetHasLF
    (bool has=true) 
    {
        m_hasLF = has;
        return m_hasLF;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: GetHasLF
    //
    //   Author: $author$
    //     Date: 5/16/2007
    ///////////////////////////////////////////////////////////////////////
    virtual bool GetHasLF() const 
    {
        return m_hasLF;
    }
};
#endif // _CEVCPHEADERLINE_HPP
