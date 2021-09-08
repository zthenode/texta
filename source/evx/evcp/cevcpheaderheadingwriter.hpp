///////////////////////////////////////////////////////////////////////
//   File: cevcpheaderheadingwriter.hpp
//
// Author: $author$
//   Date: 4/21/2007
//
//    $Id$
///////////////////////////////////////////////////////////////////////

#ifndef _CEVCPHEADERHEADINGWRITER_HPP
#define _CEVCPHEADERHEADINGWRITER_HPP

#include "cevcpheaderheadingevents.hpp"
#include "cevcharreaderwriter.hpp"
#include "cevstring.hpp"

///////////////////////////////////////////////////////////////////////
//  Class: CEvcpHeaderHeadingWriter
//
// Author: $author$
//   Date: 4/19/2007
///////////////////////////////////////////////////////////////////////
class CEvcpHeaderHeadingWriter
: virtual public CEvcpHeaderHeadingEvents,
  public CEvCharReaderWriter
{
public:
    typedef CEvcpHeaderHeadingEvents CImplements;
    typedef CEvCharReaderWriter CExtends;
    typedef CEvcpHeaderHeadingWriter CDerives;
    typedef EvError (CDerives::*MFinal)();
    typedef LONG (CDerives::*MPutc)(char c);

    CEvString m_token;
    MFinal m_final;
    MFinal m_oldFinal;
    MPutc m_putc;
    MPutc m_oldPutc;

    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvcpHeaderHeadingWriter
    //
    //       Author: $author$
    //         Date: 4/19/2007
    ///////////////////////////////////////////////////////////////////////
    CEvcpHeaderHeadingWriter(EvcpHeaderHeadingEvents& events) 
    : CImplements(events),
      m_final(&CDerives::Final),
      m_oldFinal(&CDerives::Final),
      m_putc(&CDerives::Arg1Putc),
      m_oldPutc(&CDerives::Arg1Putc)
    {
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: Initialize
    //
    //   Author: $author$
    //     Date: 4/19/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError Initialize() 
    {
        EvError error = EV_ERROR_NONE;
        m_final = &CDerives::Final;
        m_oldFinal = &CDerives::Final;
        m_putc = &CDerives::Arg1Putc;
        m_oldPutc = &CDerives::Arg1Putc;
        m_token.clear();
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: Finalize
    //
    //   Author: $author$
    //     Date: 4/19/2007
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
    // Function: Final
    //
    //   Author: $author$
    //     Date: 4/19/2007
    ///////////////////////////////////////////////////////////////////////
    EvError Final() 
    {
        EvError error = EV_ERROR_NONE;
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: ProtocolFinal
    //
    //   Author: $author$
    //     Date: 4/19/2007
    ///////////////////////////////////////////////////////////////////////
    EvError ProtocolFinal() 
    {
        EvError error = OnProtocolVersionMinor(m_token.c_str());
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: DescriptionFinal
    //
    //   Author: $author$
    //     Date: 4/19/2007
    ///////////////////////////////////////////////////////////////////////
    EvError DescriptionFinal() 
    {
        EvError error = OnResponseDescription(m_token.c_str());
        return error;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: Putc
    //
    //   Author: $author$
    //     Date: 4/19/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG Putc(char c) 
    {
        LONG count = -EV_ERROR_FAILED;
        if (m_putc) count = (this->*m_putc)(c);
        return count;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: Arg1Putc
    //
    //   Author: $author$
    //     Date: 4/19/2007
    ///////////////////////////////////////////////////////////////////////
    LONG Arg1Putc(char c) 
    {
        LONG count = 1;
        switch(c)
        {
        case '/':
            OnResponseProtocol(m_token.c_str());
            m_token.clear();
            m_oldPutc = &CDerives::RespArg2Putc;
            m_putc = &CDerives::MajorPutc;
            break;
        case ' ':
        case '\t':
            OnRequestAction(m_token.c_str());
            m_token.clear();
            m_oldPutc = &CDerives::Arg2Putc;
            m_putc = &CDerives::SpacePutc;
            break;
        default:
            m_token.Append(&c, 1);
        }
        return count;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: Arg2Putc
    //
    //   Author: $author$
    //     Date: 4/19/2007
    ///////////////////////////////////////////////////////////////////////
    LONG Arg2Putc(char c) 
    {
        LONG count = 1;
        switch(c)
        {
        case ' ':
        case '\t':
            OnRequestPath(m_token.c_str());
            m_token.clear();
            m_oldPutc = &CDerives::Arg3Putc;
            m_putc = &CDerives::SpacePutc;
            break;
        default:
            m_token.Append(&c, 1);
        }
        return count;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: RespArg2Putc
    //
    //   Author: $author$
    //     Date: 4/20/2007
    ///////////////////////////////////////////////////////////////////////
    LONG RespArg2Putc(char c) 
    {
        LONG count = 1;
        switch(c)
        {
        case ' ':
        case '\t':
            OnResponseStatus(m_token.c_str());
            m_token.clear();
            m_final = &CDerives::DescriptionFinal;
            m_oldPutc = &CDerives::RespArg3Putc;
            m_putc = &CDerives::SpacePutc;
            break;
        default:
            m_token.Append(&c, 1);
        }
        return count;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: Arg3Putc
    //
    //   Author: $author$
    //     Date: 4/19/2007
    ///////////////////////////////////////////////////////////////////////
    LONG Arg3Putc(char c) 
    {
        LONG count = 1;
        switch(c)
        {
        case '/':
            OnRequestProtocol(m_token.c_str());
            m_token.clear();
            m_oldFinal = &CDerives::ProtocolFinal;
            m_oldPutc = &CDerives::Arg4Putc;
            m_putc = &CDerives::MajorPutc;
            break;
        case ' ':
        case '\t':
            m_token.clear();
            m_oldPutc = &CDerives::Arg4Putc;
            m_putc = &CDerives::SpacePutc;
            break;
        default:
            m_token.Append(&c, 1);
        }
        return count;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: RespArg3Putc
    //
    //   Author: $author$
    //     Date: 4/20/2007
    ///////////////////////////////////////////////////////////////////////
    LONG RespArg3Putc(char c) 
    {
        LONG count = 1;
        switch(c)
        {
        case ' ':
        case '\t':
            OnResponseDescription(m_token.c_str());
            m_token.clear();
            m_oldPutc = &CDerives::Arg4Putc;
            m_putc = &CDerives::SpacePutc;
            break;
        default:
            m_token.Append(&c, 1);
        }
        return count;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: Arg4Putc
    //
    //   Author: $author$
    //     Date: 4/19/2007
    ///////////////////////////////////////////////////////////////////////
    LONG Arg4Putc(char c) 
    {
        LONG count = 1;
        switch(c)
        {
        case ' ':
        case '\t':
            m_token.clear();
            m_oldPutc = &CDerives::Arg4Putc;
            m_putc = &CDerives::SpacePutc;
            break;
        default:
            m_token.Append(&c, 1);
        }
        return count;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: MajorPutc
    //
    //   Author: $author$
    //     Date: 4/19/2007
    ///////////////////////////////////////////////////////////////////////
    LONG MajorPutc(char c) 
    {
        LONG count = 1;
        switch(c)
        {
        case '.':
            OnProtocolVersionMajor(m_token.c_str());
            m_token.clear();
            m_final = m_oldFinal;
            m_putc = &CDerives::MinorPutc;
            break;
        default:
            m_token.Append(&c, 1);
        }
        return count;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: MinorPutc
    //
    //   Author: $author$
    //     Date: 4/19/2007
    ///////////////////////////////////////////////////////////////////////
    LONG MinorPutc(char c) 
    {
        LONG count = 1;
        switch(c)
        {
        case ' ':
        case '\t':
            OnProtocolVersionMinor(m_token.c_str());
            m_token.clear();
            m_putc = &CDerives::SpacePutc;
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
    //     Date: 4/19/2007
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
        }
        return count;
    }
};

#endif // _CEVCPHEADERHEADINGWRITER_HPP
