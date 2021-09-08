///////////////////////////////////////////////////////////////////////
//   File: cevfilepathwriter.hpp
//
// Author: $author$
//   Date: 5/7/2007
///////////////////////////////////////////////////////////////////////

#ifndef _CEVFILEPATHWRITER_HPP
#define _CEVFILEPATHWRITER_HPP

#include "evfilepathevents.hpp"
#include "cevcharreaderwriter.hpp"
#include "cevstring.hpp"

///////////////////////////////////////////////////////////////////////
//  Class: CEvFilePathWriter
//
// Author: $author$
//   Date: 5/7/2007
///////////////////////////////////////////////////////////////////////
class CEvFilePathWriter
: public CEvCharReaderWriter
{
public:
    typedef CEvCharReaderWriter CExtends;
    typedef CEvFilePathWriter CDerives;

    typedef EvError (CDerives::*MFinal)();
    typedef LONG (CDerives::*MPut)(char c);

    static const char m_dot;
    static const char m_slash;

    EvFilePathEvents& m_events;
    CEvString m_token;
    CEvString m_token2;
    MFinal m_final;
    MFinal m_oldFinal;
    MPut m_put;
    MPut m_oldPut;

    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvFilePathWriter
    //
    //       Author: $author$
    //         Date: 5/7/2007
    ///////////////////////////////////////////////////////////////////////
    CEvFilePathWriter(EvFilePathEvents& events) 
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
    //     Date: 5/7/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError Initialize() 
    {
        EvError error = EV_ERROR_NONE;
        m_final = &CDerives::Final;
        m_oldFinal = &CDerives::Final;
        m_put = &CDerives::Put;
        m_oldPut = &CDerives::Put;
        m_token.clear();
        m_token2.clear();
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: Finalize
    //
    //   Author: $author$
    //     Date: 5/7/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError Finalize() 
    {
        EvError error = EV_ERROR_FAILED;
        if (m_final) error = (this->*m_final)();
        return error;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: Putc
    //
    //   Author: $author$
    //     Date: 5/7/2007
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
    //     Date: 4/19/2007
    ///////////////////////////////////////////////////////////////////////
    EvError Final() 
    {
        EvError error = EV_ERROR_NONE;
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: HostFinal
    //
    //   Author: $author$
    //     Date: 4/19/2007
    ///////////////////////////////////////////////////////////////////////
    EvError HostFinal() 
    {
        EvError error = EV_ERROR_NONE;
        LONG length;
        const char* chars;
        if ((chars = m_token.Chars(length)))
            m_events.OnHost(chars, length);
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: RootCurrentFinal
    //
    //   Author: $author$
    //     Date: 4/19/2007
    //
    // '/''.'E
    ///////////////////////////////////////////////////////////////////////
    EvError RootCurrentFinal() 
    {
        EvError error = EV_ERROR_NONE;
        LONG length;
        const char* chars;
        m_token.Append(&m_dot, 1);
        if ((chars = m_token.Chars(length)))
            m_events.OnRootCurrentDirectory(chars, length);
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: RootParentFinal
    //
    //   Author: $author$
    //     Date: 4/19/2007
    //
    // '/''.''.'E
    ///////////////////////////////////////////////////////////////////////
    EvError RootParentFinal() 
    {
        EvError error = EV_ERROR_NONE;
        LONG length;
        const char* chars;
        m_token.Append(&m_dot, 1);
        m_token.Append(&m_dot, 1);
        if ((chars = m_token.Chars(length)))
            m_events.OnRootParentDirectory(chars, length);
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: CurrentFinal
    //
    //   Author: $author$
    //     Date: 4/19/2007
    //
    // '.'E
    ///////////////////////////////////////////////////////////////////////
    EvError CurrentFinal() 
    {
        EvError error = EV_ERROR_NONE;
        LONG length;
        const char* chars;
        m_token.Append(&m_dot, 1);
        if ((chars = m_token.Chars(length)))
            m_events.OnCurrentDirectory(chars, length);
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: ParentFinal
    //
    //   Author: $author$
    //     Date: 4/19/2007
    //
    // '.''.'E
    ///////////////////////////////////////////////////////////////////////
    EvError ParentFinal() 
    {
        EvError error = EV_ERROR_NONE;
        LONG length;
        const char* chars;
        m_token.Append(&m_dot, 1);
        m_token.Append(&m_dot, 1);
        if ((chars = m_token.Chars(length)))
            m_events.OnParentDirectory(chars, length);
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: RootNameExtensionFinal
    //
    //   Author: $author$
    //     Date: 4/19/2007
    //
    // A+'.'A+E
    ///////////////////////////////////////////////////////////////////////
    EvError RootNameExtensionFinal() 
    {
        EvError error = EV_ERROR_NONE;
        LONG length;
        const char* chars;
        if ((chars = m_token.Chars(length)))
            m_events.OnRootFileName(chars, length);
        if ((chars = m_token2.Chars(length)))
            m_events.OnFileExtension(chars, length);
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: RootNameFinal
    //
    //   Author: $author$
    //     Date: 4/19/2007
    //
    // '/'A+E
    ///////////////////////////////////////////////////////////////////////
    EvError RootNameFinal() 
    {
        EvError error = EV_ERROR_NONE;
        LONG length;
        const char* chars;
        if ((chars = m_token.Chars(length)))
            m_events.OnRootFileName(chars, length);
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: RootNameDotFinal
    //
    //   Author: $author$
    //     Date: 4/19/2007
    //
    // '/'A+'.'E
    ///////////////////////////////////////////////////////////////////////
    EvError RootNameDotFinal() 
    {
        EvError error = EV_ERROR_NONE;
        LONG length;
        const char* chars;
        m_token.Append(&m_dot, 1);
        if ((chars = m_token.Chars(length)))
            m_events.OnRootFileName(chars, length);
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: NameExtensionFinal
    //
    //   Author: $author$
    //     Date: 4/19/2007
    //
    // A+'.'A+E
    ///////////////////////////////////////////////////////////////////////
    EvError NameExtensionFinal() 
    {
        EvError error = EV_ERROR_NONE;
        LONG length;
        const char* chars;
        if ((chars = m_token.Chars(length)))
            m_events.OnFileName(chars, length);
        if ((chars = m_token2.Chars(length)))
            m_events.OnFileExtension(chars, length);
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: NameFinal
    //
    //   Author: $author$
    //     Date: 4/19/2007
    //
    // A+E
    ///////////////////////////////////////////////////////////////////////
    EvError NameFinal() 
    {
        EvError error = EV_ERROR_NONE;
        LONG length;
        const char* chars;
        if ((chars = m_token.Chars(length)))
            m_events.OnFileName(chars, length);
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: NameDotFinal
    //
    //   Author: $author$
    //     Date: 4/19/2007
    //
    // A+'.'E
    ///////////////////////////////////////////////////////////////////////
    EvError NameDotFinal() 
    {
        EvError error = EV_ERROR_NONE;
        LONG length;
        const char* chars;
        m_token.Append(&m_dot, 1);
        if ((chars = m_token.Chars(length)))
            m_events.OnFileName(chars, length);
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: ExtensionFinal
    //
    //   Author: $author$
    //     Date: 4/19/2007
    //
    // A+'.'A+E
    ///////////////////////////////////////////////////////////////////////
    EvError ExtensionFinal() 
    {
        EvError error = EV_ERROR_NONE;
        LONG length;
        const char* chars;
        if ((chars = m_token.Chars(length)))
            m_events.OnFileExtension(chars, length);
        return error;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: Put
    //
    //   Author: $author$
    //     Date: 5/7/2007
    //
    // A*?
    ///////////////////////////////////////////////////////////////////////
    LONG Put(char c) 
    {
        LONG length;
        const char* chars;
        switch(c)
        {
        case '/':
        case '\\':
            if ((chars = m_token.Chars
                (length)) && (0 < length))
            {
                // A+'/'
                m_events.OnDirectory(chars, length);
                m_token.Clear();
                m_put = &CDerives::NamePut;
            }
            else 
            {
                // '/'
                m_put = &CDerives::HostPut;
                m_final = &CDerives::RootNameFinal;
            }
            break;
        case ':':
            if ((chars = m_token.Chars
                (length)) && (0 < length))
            {
                // A+':'
                m_events.OnVolume(chars, length);
                m_token.Clear();
            }
            m_put = &CDerives::RootPut;
            break;
        case '.':
            if ((chars = m_token.Chars
                (length)) && (0 < length))
            {
                // A+'.'
                m_oldPut = &CDerives::NamePut;
                m_put = &CDerives::ExtensionPut;
                m_final = &CDerives::NameDotFinal;
            }
            else
            {
                // '.' 
                m_put = &CDerives::CurrentPut;
                m_final = &CDerives::CurrentFinal;
            }
            break;
        default:
            // A
            m_token.Append(&c, 1);
            m_final = &CDerives::NameFinal;
        }
        return 1;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: DirectoryPut
    //
    //   Author: $author$
    //     Date: 5/7/2007
    //
    // A+'/'+?
    ///////////////////////////////////////////////////////////////////////
    LONG DirectoryPut(char c) 
    {
        //LONG length;
        //const char* chars;
        switch(c)
        {
        case '/':
        case '\\':
            // A+'/'+'/'
            break;
        case '.':
            // A+'/'+'.'
            m_put = &CDerives::CurrentPut;
            m_final = &CDerives::CurrentFinal;
            break;
        default:
            // A+'/'+A
            m_token.Append(&c, 1);
            m_put = &CDerives::NamePut;
            m_final = &CDerives::NameFinal;
        }
        return 1;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: HostPut
    //
    //   Author: $author$
    //     Date: 5/7/2007
    //
    // '/'?
    ///////////////////////////////////////////////////////////////////////
    LONG HostPut(char c) 
    {
        //LONG length;
        //const char* chars;
        switch(c)
        {
        case '/':
        case '\\':
            // '/''/'
            m_put = &CDerives::HostNamePut;
            break;
        case '.':
            // '/''.'
            m_put = &CDerives::RootCurrentPut;
            m_final = &CDerives::RootCurrentFinal;
            break;
        default:
            // '/'A
            m_token.Append(&c, 1);
            m_put = &CDerives::RootNamePut;
            m_final = &CDerives::RootNameFinal;
        }
        return 1;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: HostNamePut
    //
    //   Author: $author$
    //     Date: 5/7/2007
    //
    // '/''/'A*?
    ///////////////////////////////////////////////////////////////////////
    LONG HostNamePut(char c) 
    {
        LONG length;
        const char* chars;
        switch(c)
        {
        case '/':
        case '\\':
            // '/''/'A*'/'
            if ((chars = m_token.Chars
                (length)) && (0 < length))
            {
                m_events.OnHost(chars, length);
                m_token.Clear();
            }
            m_put = &CDerives::RootNamePut;
            break;
        default:
            // '/''/'A+
            m_token.Append(&c, 1);
            m_final = &CDerives::HostFinal;
        }
        return 1;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: CurrentPut
    //
    //   Author: $author$
    //     Date: 5/7/2007
    //
    // '.'?
    ///////////////////////////////////////////////////////////////////////
    LONG CurrentPut(char c) 
    {
        LONG length;
        const char* chars;
        switch(c)
        {
        case '/':
        case '\\':
            // '.''/'
            m_token.Append(&m_dot, 1);
            if ((chars = m_token.Chars
                (length)) && (0 < length))
            {
                m_events.OnCurrentDirectory(chars, length);
                m_token.Clear();
            }
            m_put = &CDerives::DirectoryPut;
            break;
        case '.':
            // '.''.'
            m_put = &CDerives::ParentPut;
            m_final = &CDerives::ParentFinal;
            break;
        default:
            // '.'A
            m_token.Append(&m_dot, 1);
            m_token.Append(&c, 1);
            m_put = &CDerives::NamePut;
            m_final = &CDerives::NameFinal;
        }
        return 1;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: RootCurrentPut
    //
    //   Author: $author$
    //     Date: 5/7/2007
    //
    // '/''.'?
    ///////////////////////////////////////////////////////////////////////
    LONG RootCurrentPut(char c) 
    {
        LONG length;
        const char* chars;
        switch(c)
        {
        case '/':
        case '\\':
            // '/''.''/'
            m_token.Append(&m_dot, 1);
            if ((chars = m_token.Chars
                (length)) && (0 < length))
            {
                m_events.OnRootCurrentDirectory(chars, length);
                m_token.Clear();
            }
            m_put = &CDerives::DirectoryPut;
            break;
        case '.':
            // '/''.''.'
            m_put = &CDerives::RootParentPut;
            m_final = &CDerives::RootParentFinal;
            break;
        default:
            // '/''.'A
            m_token.Append(&m_dot, 1);
            m_token.Append(&c, 1);
            m_put = &CDerives::RootNamePut;
            m_final = &CDerives::RootNameFinal;
        }
        return 1;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: ParentPut
    //
    //   Author: $author$
    //     Date: 5/7/2007
    //
    // '.''.'?
    ///////////////////////////////////////////////////////////////////////
    LONG ParentPut(char c) 
    {
        LONG length;
        const char* chars;
        switch(c)
        {
        case '/':
        case '\\':
            // '.''.''/'
            m_token.Append(&m_dot, 1);
            m_token.Append(&m_dot, 1);
            if ((chars = m_token.Chars
                (length)) && (0 < length))
            {
                m_events.OnParentDirectory(chars, length);
                m_token.Clear();
            }
            m_put = &CDerives::DirectoryPut;
            break;
        case '.':
            // '.''.''.'
        default:
            // '.''.'A
            m_token.Append(&m_dot, 1);
            m_token.Append(&m_dot, 1);
            m_token.Append(&c, 1);
            m_put = &CDerives::NamePut;
            m_final = &CDerives::NameFinal;
        }
        return 1;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: RootParentPut
    //
    //   Author: $author$
    //     Date: 5/7/2007
    //
    // '/''.''.'?
    ///////////////////////////////////////////////////////////////////////
    LONG RootParentPut(char c) 
    {
        LONG length;
        const char* chars;
        switch(c)
        {
        case '/':
        case '\\':
            // '/''.''.''/'
            m_token.Append(&m_dot, 1);
            m_token.Append(&m_dot, 1);
            if ((chars = m_token.Chars
                (length)) && (0 < length))
            {
                m_events.OnRootParentDirectory(chars, length);
                m_token.Clear();
            }
            m_put = &CDerives::NamePut;
            break;
        case '.':
            // '/''.''.''.'
        default:
            // '/''.''.'A
            m_token.Append(&m_dot, 1);
            m_token.Append(&c, 1);
            m_put = &CDerives::RootNamePut;
            m_final = &CDerives::RootNameFinal;
        }
        return 1;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: RootPut
    //
    //   Author: $author$
    //     Date: 5/7/2007
    //
    // A+':'?
    ///////////////////////////////////////////////////////////////////////
    LONG RootPut(char c) 
    {
        //LONG length;
        //const char* chars;
        switch(c)
        {
        case '/':
        case '\\':
            // A+':''/'
            m_put = &CDerives::RootNamePut;
            break;
        case '.':
            // A+':''.'
            m_put = &CDerives::ParentPut;
            m_final = &CDerives::CurrentFinal;
            break;
        default:
            // A+':'A
            m_token.Append(&c, 1);
            m_put = &CDerives::NamePut;
            m_final = &CDerives::NameFinal;
        }
        return 1;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: RootNamePut
    //
    //   Author: $author$
    //     Date: 5/7/2007
    //
    // '/'A+?
    ///////////////////////////////////////////////////////////////////////
    LONG RootNamePut(char c) 
    {
        LONG length;
        const char* chars;
        switch(c)
        {
        case '/':
        case '\\':
            // '/'A+'/'
            if ((chars = m_token.Chars
                (length)) && (0 < length))
            {
                m_events.OnRootDirectory(chars, length);
                m_token.Clear();
            }
            m_put = &CDerives::NamePut;
            break;
        case '.':
            // '/'A+'.'
            m_oldPut = &CDerives::RootNamePut;
            m_put = &CDerives::RootExtensionPut;
            m_final = &CDerives::RootNameDotFinal;
            break;
        default:
            // '/'A+
            m_token.Append(&c, 1);
            m_final = &CDerives::RootNameFinal;
        }
        return 1;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: NamePut
    //
    //   Author: $author$
    //     Date: 5/7/2007
    //
    // A+?
    ///////////////////////////////////////////////////////////////////////
    LONG NamePut(char c) 
    {
        LONG length;
        const char* chars;
        switch(c)
        {
        case '/':
        case '\\':
            // A+'/'
            if ((chars = m_token.Chars
                (length)) && (0 < length))
            {
                m_events.OnDirectory(chars, length);
                m_token.Clear();
            }
            break;
        case '.':
            // A+'.'
            m_oldPut = &CDerives::NamePut;
            m_put = &CDerives::ExtensionPut;
            m_final = &CDerives::NameDotFinal;
            break;
        default:
            // A+
            m_token.Append(&c, 1);
            m_final = &CDerives::NameFinal;
        }
        return 1;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: ExtensionPut
    //
    //   Author: $author$
    //     Date: 5/7/2007
    //
    // A+'.'?
    ///////////////////////////////////////////////////////////////////////
    LONG ExtensionPut(char c) 
    {
        LONG length;
        const char* chars;
        switch(c)
        {
        case '/':
        case '\\':
            // A+'.''/'
            m_token.Append(&m_dot, 1);
            if ((chars = m_token.Chars
                (length)) && (0 < length))
            {
                m_events.OnDirectory(chars, length);
                m_token.Clear();
            }
            m_put = m_oldPut;
            break;
        case '.':
            // A+'.''.'
            m_token.Append(&m_dot, 1);
            m_token.Append(&m_dot, 1);
            m_put = m_oldPut;
            m_final = &CDerives::NameFinal;
            break;
        default:
            // A+'.'A
            m_token2.Append(&c, 1);
            m_put = &CDerives::ExtensionNamePut;
            m_final = &CDerives::NameExtensionFinal;
        }
        return 1;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: ExtensionNamePut
    //
    //   Author: $author$
    //     Date: 5/7/2007
    //
    // A+'.'A+?
    ///////////////////////////////////////////////////////////////////////
    LONG ExtensionNamePut(char c) 
    {
        LONG length;
        const char* chars;
        switch(c)
        {
        case '/':
        case '\\':
            // A+'.'A+'/'
            m_token.Append(&m_dot, 1);
            if ((chars = m_token2.Chars
                (length)) && (0 < length))
            {
                m_token.Append(chars, length);
                m_token2.Clear();
            }
            if ((chars = m_token.Chars
                (length)) && (0 < length))
            {
                m_events.OnDirectory(chars, length);
                m_token.Clear();
            }
            m_put = m_oldPut;
            break;
        case '.':
            // A+'.'A+'.'
            m_token.Append(&m_dot, 1);
            if ((chars = m_token2.Chars
                (length)) && (0 < length))
            {
                m_token.Append(chars, length);
                m_token2.Clear();
            }
            m_final = &CDerives::NameDotFinal;
            break;
        default:
            // A+'.'A+
            m_token2.Append(&c, 1);
            m_final = &CDerives::NameExtensionFinal;
        }
        return 1;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: RootExtensionPut
    //
    //   Author: $author$
    //     Date: 5/7/2007
    //
    // '/'A+'.'?
    ///////////////////////////////////////////////////////////////////////
    LONG RootExtensionPut(char c) 
    {
        LONG length;
        const char* chars;
        switch(c)
        {
        case '/':
        case '\\':
            // '/'A+'.''/'
            m_token.Append(&m_dot, 1);
            if ((chars = m_token.Chars
                (length)) && (0 < length))
            {
                m_events.OnRootDirectory(chars, length);
                m_token.Clear();
            }
            m_put = m_oldPut;
            break;
        case '.':
            // '/'A+'.''.'
            m_token.Append(&m_dot, 1);
            m_token.Append(&m_dot, 1);
            m_put = m_oldPut;
            m_final = &CDerives::RootNameFinal;
            break;
        default:
            // '/'A+'.'A
            m_token2.Append(&c, 1);
            m_put = &CDerives::RootExtensionNamePut;
            m_final = &CDerives::RootNameExtensionFinal;
        }
        return 1;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: RootExtensionNamePut
    //
    //   Author: $author$
    //     Date: 5/7/2007
    //
    // '/'A+'.'A+?
    ///////////////////////////////////////////////////////////////////////
    LONG RootExtensionNamePut(char c) 
    {
        LONG length;
        const char* chars;
        switch(c)
        {
        case '/':
        case '\\':
            // '/'A+'.'A+'/'
            m_token.Append(&m_dot, 1);
            if ((chars = m_token2.Chars
                (length)) && (0 < length))
            {
                m_token.Append(chars, length);
                m_token2.Clear();
            }
            if ((chars = m_token.Chars
                (length)) && (0 < length))
            {
                m_events.OnRootDirectory(chars, length);
                m_token.Clear();
            }
            m_put = m_oldPut;
            break;
        case '.':
            // '/'A+'.'A+'.'
            m_token.Append(&m_dot, 1);
            if ((chars = m_token2.Chars
                (length)) && (0 < length))
            {
                m_token.Append(chars, length);
                m_token2.Clear();
            }
            m_final = &CDerives::RootNameDotFinal;
            break;
        default:
            // '/'A+'.'A+
            m_token2.Append(&c, 1);
            m_final = &CDerives::RootNameExtensionFinal;
        }
        return 1;
    }
};
#endif // _CEVFILEPATHWRITER_HPP
