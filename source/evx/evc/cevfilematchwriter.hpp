///////////////////////////////////////////////////////////////////////
//   File: cevfilematchwriter.hpp
//
// Author: $author$
//   Date: 5/21/2007
///////////////////////////////////////////////////////////////////////

#ifndef _CEVMATCHWRITER_HPP
#define _CEVMATCHWRITER_HPP

#include "evfilematchevents.hpp"
#include "cevcharputer.hpp"
#include "cevcharwriter.hpp"
#include "cevstring.hpp"

///////////////////////////////////////////////////////////////////////
//  Class: CEvFileMatchWriter
//
// Author: $author$
//   Date: 5/21/2007
///////////////////////////////////////////////////////////////////////
class CEvFileMatchWriter
: public CEvCharPuter
{
public:
    typedef CEvCharPuter CExtends;
    typedef CEvFileMatchWriter CDerives;

    typedef EvError (CDerives::*MFinal)();
    typedef LONG (CDerives::*MPut)(char c);

    EvFileMatchEvents& m_events;

    CEvString m_token;

    MFinal m_final;
    MFinal m_oldFinal;
    MPut m_put;
    MPut m_oldPut;

    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvFileMatchWriter
    //
    //       Author: $author$
    //         Date: 5/21/2007
    ///////////////////////////////////////////////////////////////////////
    CEvFileMatchWriter(EvFileMatchEvents& events) 
    : m_events(events),
      m_final(&CDerives::Final),
      m_oldFinal(&CDerives::Final),
      m_put(&CDerives::Put),
      m_oldPut(&CDerives::Put)
    {
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: Initialize
    //
    //   Author: $author$
    //     Date: 5/21/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError Initialize() 
    {
        EvError error = EV_ERROR_NONE;
        m_final = &CDerives::Final;
        m_oldFinal = &CDerives::Final;
        m_put = &CDerives::Put;
        m_oldPut = &CDerives::Put;
        m_token.clear();
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: Finalize
    //
    //   Author: $author$
    //     Date: 5/21/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError Finalize() 
    {
        EvError error = EV_ERROR_NONE;
        if (m_final) error = (this->*m_final)();
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: Putc
    //
    //   Author: $author$
    //     Date: 5/21/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG Putc(char c) 
    {
        LONG count = -EV_ERROR_FAILED;
        if (m_put) count = (this->*m_put)(c);
        return count;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: Final
    //
    //   Author: $author$
    //     Date: 5/21/2007
    ///////////////////////////////////////////////////////////////////////
    EvError Final() 
    {
        EvError error = EV_ERROR_NONE;
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: WildFinal
    //
    //   Author: $author$
    //     Date: 8/4/2008
    ///////////////////////////////////////////////////////////////////////
    EvError WildFinal() 
    {
        EvError error = EV_ERROR_NONE;
        m_events.OnMatchAny("");
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: NameFinal
    //
    //   Author: $author$
    //     Date: 7/2/2007
    ///////////////////////////////////////////////////////////////////////
    EvError NameFinal() 
    {
        EvError error = EV_ERROR_NONE;
        LONG length;
        const char* chars;
        if ((chars = m_token.Chars(length)) && (0 < length))
            m_events.OnMatchFilename(chars, length);
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: BaseFinal
    //
    //   Author: $author$
    //     Date: 4/11/2010
    ///////////////////////////////////////////////////////////////////////
    EvError BaseFinal() 
    {
        EvError error = EV_ERROR_NONE;
        LONG length;
        const char* chars;
        if ((chars = m_token.Chars(length)) && (0 < length))
            m_events.OnMatchFilebase(chars, length);
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: ExtFinal
    //
    //   Author: $author$
    //     Date: 5/21/2007
    ///////////////////////////////////////////////////////////////////////
    EvError ExtFinal() 
    {
        EvError error = EV_ERROR_NONE;
        LONG length;
        const char* chars;
        if ((chars = m_token.Chars(length)) && (0 < length))
            m_events.OnMatchExtension(chars, length);
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: ExtPrefixFinal
    //
    //   Author: $author$
    //     Date: 9/26/2007
    ///////////////////////////////////////////////////////////////////////
    EvError ExtPrefixFinal() 
    {
        EvError error = EV_ERROR_NONE;
        LONG length;
        const char* chars;
        if ((chars = m_token.Chars(length)) && (0 < length))
            m_events.OnMatchExtensionPrefix(chars, length);
        return error;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: Put
    //
    //   Author: $author$
    //     Date: 5/21/2007
    //
    // ?
    ///////////////////////////////////////////////////////////////////////
    LONG Put(char c) 
    {
        //LONG length;
        //const char* chars;
        switch(c)
        {
        case '#':
            // '#'
            m_oldPut = m_put;
            m_put = &CDerives::CommentEOLPut;
            break;

        case '*':
            // '*'
            m_put = &CDerives::WildPut;
            m_final = &CDerives::WildFinal;
            break;

		case ' ':
		case '\t':
		case '\r':
		case '\n':
		case ';':
			break;

        case '.':
            // '.'
        default:
            // A
            m_token.Append(&c, 1);
            m_put = &CDerives::NamePut;
            m_final = &CDerives::NameFinal;
        }
        return 1;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: CommentEOLPut
    //
    //   Author: $author$
    //     Date: 5/20/2008
    //
    // '#'?\n
    ///////////////////////////////////////////////////////////////////////
    LONG CommentEOLPut(char c) 
    {
        //LONG length;
        //const char* chars;
        switch(c)
        {
        case '\n':
            // '#'?';'
            m_token.Clear();
            m_put = m_oldPut;
            m_oldPut = &CDerives::Put;
            break;
        }
        return 1;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: NextPut
    //
    //   Author: $author$
    //     Date: 5/21/2007
    //
    // '*'?
    ///////////////////////////////////////////////////////////////////////
    LONG NextPut(char c) 
    {
        //LONG length;
        //const char* chars;
        switch(c)
        {
        case ';':
            // '*'';'
            m_token.Clear();
            m_put = &CDerives::Put;
            m_final = &CDerives::Final;
            break;
        }
        return 1;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: NamePut
    //
    //   Author: $author$
    //     Date: 5/21/2007
    //
    // A?
    ///////////////////////////////////////////////////////////////////////
    LONG NamePut(char c) 
    {
        LONG length;
        const char* chars;
        switch(c)
        {
		case '*':
			// A'*'
			DBW("() unsupported pattern \"A'*'\"\n");
            m_put = &CDerives::NextPut;
            m_final = &CDerives::Final;
			break;

        case '.':
            // A'.'
            m_put = &CDerives::BasePut;
            m_final = &CDerives::Final;
            break;

        case ';':
            // A';'
            if ((chars = m_token.Chars(length)) && (0 < length))
                m_events.OnMatchFilename(chars, length);
            m_token.Clear();
            m_put = &CDerives::Put;
            m_final = &CDerives::Final;
            break;

        default:
            // A?
            m_token.Append(&c, 1);
        }
        return 1;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: BasePut
    //
    //   Author: $author$
    //     Date: 4/11/2010
    //
    // A'.'?
    ///////////////////////////////////////////////////////////////////////
    LONG BasePut(char c) 
    {
        LONG length;
        const char* chars;
        switch(c)
        {
		case '*':
			// A'.''*'
            m_put = &CDerives::BaseWildPut;
            m_final = &CDerives::BaseFinal;
			break;

		case '.':
			// A'.''.'
			DBW("() unsupported pattern \"A'.''%c'\"\n", c);
            m_put = &CDerives::NextPut;
            m_final = &CDerives::Final;
			break;

        case ';':
            // A'.'';'
            if ((chars = m_token.Chars(length)) && (0 < length))
                m_events.OnMatchFilename(chars, length);
            m_token.Clear();
            m_put = &CDerives::Put;
            m_final = &CDerives::Final;
            break;

        default:
            // A'.'?
			DBW("() unsupported pattern \"A'.''%c'\"\n", c);
            m_put = &CDerives::NextPut;
            m_final = &CDerives::Final;
        }
        return 1;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: BaseWildPut
    //
    //   Author: $author$
    //     Date: 5/21/2007
    //
    // A'.''*'?
    ///////////////////////////////////////////////////////////////////////
    LONG BaseWildPut(char c) 
    {
        LONG length;
        const char* chars;
        switch(c)
        {
        case ';':
            // A'.''*'';'
            if ((chars = m_token.Chars(length)) && (0 < length))
                m_events.OnMatchFilebase(chars, length);
            m_token.Clear();
            m_put = &CDerives::Put;
            m_final = &CDerives::Final;
            break;

        default:
            // A'.''*'?
			DBW("() unsupported pattern \"A'.''*''%c'\"\n", c);
            m_put = &CDerives::NextPut;
            m_final = &CDerives::Final;
        }
        return 1;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: WildPut
    //
    //   Author: $author$
    //     Date: 5/21/2007
    //
    // '*'?
    ///////////////////////////////////////////////////////////////////////
    LONG WildPut(char c) 
    {
        //LONG length;
        //const char* chars;
        switch(c)
        {
        case '.':
            // '*''.'
            m_put = &CDerives::ExtPut;
            m_final = &CDerives::Final;
            break;

        case ';':
            // '*'';'
            m_events.OnMatchAny("");
            m_put = &CDerives::Put;
            m_final = &CDerives::Final;
            break;

        default:
            // '*'A
			DBW("() unsupported pattern \"'*''%c'\"\n", c);
            m_put = &CDerives::NextPut;
            m_final = &CDerives::Final;
        }
        return 1;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: ExtPut
    //
    //   Author: $author$
    //     Date: 5/21/2007
    //
    // '*''.'?
    ///////////////////////////////////////////////////////////////////////
    LONG ExtPut(char c) 
    {
        //LONG length;
        //const char* chars;
        switch(c)
        {
        case '.':
            // '*''.''.'
        case '*':
            // '*''.''*'
        case ';':
            // '*''.'';'
			DBW("() unsupported pattern \"'*''.''%c'\"\n", c);
            m_put = &CDerives::NextPut;
            m_final = &CDerives::Final;
			break;

        default:
            // '*''.'A
            m_token.Append(&c, 1);
            m_put = &CDerives::ExtPrefixPut;
            m_final = &CDerives::ExtFinal;
        }
        return 1;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: ExtPrefixPut
    //
    //   Author: $author$
    //     Date: 9/26/2007
    //
    // '*''.'A*?
    ///////////////////////////////////////////////////////////////////////
    LONG ExtPrefixPut(char c) 
    {
        LONG length;
        const char* chars;
        switch(c)
        {
        case '.':
            // '*''.'A*'.'
			DBW("() unsupported pattern \"'*''.'A*'.'\"\n");
            m_put = &CDerives::NextPut;
            m_final = &CDerives::Final;
			break;

        case '*':
            // '*''.'A*'*'
            m_put = &CDerives::ExtPrefixWildPut;
            m_final = &CDerives::ExtPrefixFinal;
			break;

        case ';':
            // '*''.'A*';'
            if ((chars = m_token.Chars(length)) && (0 < length))
                m_events.OnMatchExtension(chars, length);
            m_token.Clear();
            m_put = &CDerives::Put;
            m_final = &CDerives::Final;
            break;

        default:
            // '*''.'A*A
            m_token.Append(&c, 1);
        }
        return 1;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: ExtPrefixWildPut
    //
    //   Author: $author$
    //     Date: 9/26/2007
    //
    // '*''.'A*'*'?
    ///////////////////////////////////////////////////////////////////////
    LONG ExtPrefixWildPut(char c) 
    {
        LONG length;
        const char* chars;
        switch(c)
        {
        case ';':
            // '*''.'A*'*'';'
            if ((chars = m_token.Chars(length)) && (0 < length))
                m_events.OnMatchExtensionPrefix(chars, length);
            m_token.Clear();
            m_put = &CDerives::Put;
            m_final = &CDerives::Final;
            break;

        default:
            // '*''.'A*'*'A
			DBW("() unsupported pattern \"'*''.'A*'*''%c'\"\n", c);
            m_put = &CDerives::NextPut;
            m_final = &CDerives::Final;
        }
        return 1;
    }
};
#endif // _CEVMATCHWRITER_HPP
