///////////////////////////////////////////////////////////////////////
//   File: cevcpheaderfieldwriter.hpp
//
// Author: $author$
//   Date: 4/23/2007
//
//    $Id$
///////////////////////////////////////////////////////////////////////

#ifndef _CEVCPHEADERFIELDWRITER_HPP
#define _CEVCPHEADERFIELDWRITER_HPP

#include "cevcpheaderfieldevents.hpp"
#include "cevcharreaderwriter.hpp"
#include "cevstring.hpp"

///////////////////////////////////////////////////////////////////////
//  Class: CEvcpHeaderFieldWriter
//
// Author: $author$
//   Date: 4/23/2007
///////////////////////////////////////////////////////////////////////
class CEvcpHeaderFieldWriter
: virtual public CEvcpHeaderFieldEvents,
  public CEvCharReaderWriter
{
public:
    typedef CEvcpHeaderFieldEvents CImplements;
    typedef CEvCharReaderWriter CExtends;
    typedef CEvcpHeaderFieldWriter CDerives;

    typedef EvError (CDerives::*MFinal)();
    typedef LONG (CDerives::*MPutc)(char c);

    CEvString m_token;
    CEvString m_space;
    MFinal m_final;
    MFinal m_oldFinal;
    MPutc m_putc;
    MPutc m_oldPutc;

    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvcpHeaderFieldWriter
    //
    //       Author: $author$
    //         Date: 4/23/2007
    ///////////////////////////////////////////////////////////////////////
    CEvcpHeaderFieldWriter(EvcpHeaderFieldEvents& events) 
    : CImplements(events),
      m_final(&CDerives::Final),
      m_oldFinal(&CDerives::Final),
      m_putc(&CDerives::Name1Putc),
      m_oldPutc(&CDerives::Name1Putc) 
    {
    }
    ///////////////////////////////////////////////////////////////////////
    // Destructor: ~CEvcpHeaderFieldWriter
    //
    //      Author: $author$
    //        Date: 4/23/2007
    ///////////////////////////////////////////////////////////////////////
    virtual ~CEvcpHeaderFieldWriter()
    {
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: Initialize
    //
    //   Author: $author$
    //     Date: 4/23/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError Initialize() 
    {
        EvError error = EV_ERROR_NONE;
        m_final = &CDerives::Final;
        m_oldFinal = &CDerives::Final;
        m_putc = &CDerives::Name1Putc;
        m_oldPutc = &CDerives::Name1Putc;
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: Finalize
    //
    //   Author: $author$
    //     Date: 4/23/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError Finalize() 
    {
        EvError error = EV_ERROR_FAILED;
        if (m_final) error = (this->*m_final)();
        return error;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: Write
    //
    //   Author: $author$
    //     Date: 4/19/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG Write
    (const char* chars, LONG length=-1) 
    {
        LONG count = -EV_ERROR_FAILED;
        LONG put;
        char c;

        if (0 < length)
        {
            for (count = 0; count < length; count++)
                if (0 >= (put = Putc(chars[count])))
                    return -EV_ERROR_FAILED;
        }
        else
        {
            for (count = 0; (c = chars[count]); count++)
                if (0 >= (put = Putc(c)))
                    return -EV_ERROR_FAILED;
        }
        return count;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: Putc
    //
    //   Author: $author$
    //     Date: 4/23/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG Putc(char c) 
    {
        LONG count = -EV_ERROR_FAILED;
        if (m_putc) count = (this->*m_putc)(c);
        return count;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: NameFinal
    //
    //   Author: $author$
    //     Date: 4/23/2007
    ///////////////////////////////////////////////////////////////////////
    EvError NameFinal() 
    {
        EvError error = OnFieldName(m_token.c_str());
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: ValueFinal
    //
    //   Author: $author$
    //     Date: 4/23/2007
    ///////////////////////////////////////////////////////////////////////
    EvError ValueFinal() 
    {
        EvError error = OnFieldValue(m_token.c_str());
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: Final
    //
    //   Author: $author$
    //     Date: 4/23/2007
    ///////////////////////////////////////////////////////////////////////
    EvError Final() 
    {
        EvError error = EV_ERROR_NONE;
        return error;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: Name1Putc
    //
    //   Author: $author$
    //     Date: 4/23/2007
    ///////////////////////////////////////////////////////////////////////
    LONG Name1Putc(char c) 
    {
        LONG count = 1;
        switch(c)
        {
        case ':':
            m_putc = &CDerives::Value1Putc;
            break;
        case ' ':
        case '\t':
            m_oldPutc = &CDerives::NamePutc;
            m_putc = &CDerives::SpacePutc;
            break;
        default:
            m_token.Append(&c, 1);
            m_final = &CDerives::NameFinal;
            m_putc = &CDerives::NamePutc;
        }
        return count;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: NamePutc
    //
    //   Author: $author$
    //     Date: 4/23/2007
    ///////////////////////////////////////////////////////////////////////
    LONG NamePutc(char c) 
    {
        LONG count = 1;
        switch(c)
        {
        case ':':
            OnFieldName(m_token.c_str());
            m_token.clear();
            m_final = &CDerives::Final;
            m_putc = &CDerives::Value1Putc;
            break;
        case ' ':
        case '\t':
            m_space.Assign(&c, 1);
            m_oldFinal = &CDerives::NameFinal;
            m_oldPutc = &CDerives::NamePutc;
            m_putc = &CDerives::Space2Putc;
            break;
        default:
            m_token.Append(&c, 1);
        }
        return count;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: Value1Putc
    //
    //   Author: $author$
    //     Date: 4/23/2007
    ///////////////////////////////////////////////////////////////////////
    LONG Value1Putc(char c) 
    {
        LONG count = 1;
        switch(c)
        {
        case ' ':
        case '\t':
            m_oldFinal = &CDerives::ValueFinal;
            m_oldPutc = &CDerives::ValuePutc;
            m_putc = &CDerives::SpacePutc;
            break;
        default:
            m_token.Append(&c, 1);
            m_final = &CDerives::ValueFinal;
            m_putc = &CDerives::ValuePutc;
        }
        return count;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: ValuePutc
    //
    //   Author: $author$
    //     Date: 4/23/2007
    ///////////////////////////////////////////////////////////////////////
    LONG ValuePutc(char c) 
    {
        LONG count = 1;
        switch(c)
        {
        case ' ':
        case '\t':
            m_space.Assign(&c, 1);
            m_oldFinal = &CDerives::ValueFinal;
            m_oldPutc = &CDerives::ValuePutc;
            m_putc = &CDerives::Space2Putc;
            break;
        default:
            m_token.Append(&c, 1);
        }
        return count;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: SpacePutc
    //
    //   Author: $author$
    //     Date: 4/23/2007
    ///////////////////////////////////////////////////////////////////////
    LONG SpacePutc(char c) 
    {
        LONG count = 1;
        switch(c)
        {
        case ' ':
        case '\t':
            break;
        default:
            m_token.Append(&c, 1);
            m_putc = m_oldPutc;
            m_final = m_oldFinal;
        }
        return count;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: Space2Putc
    //
    //   Author: $author$
    //     Date: 4/23/2007
    ///////////////////////////////////////////////////////////////////////
    LONG Space2Putc(char c) 
    {
        LONG count = 1;
        switch(c)
        {
        case ' ':
        case '\t':
            m_space.Append(&c, 1);
            break;
        default:
            m_token.Append(m_space.c_str());
            m_token.Append(&c, 1);
            m_putc = m_oldPutc;
            m_final = m_oldFinal;
        }
        return count;
    }
};
#endif // _CEVCPHEADERFIELDWRITER_HPP
