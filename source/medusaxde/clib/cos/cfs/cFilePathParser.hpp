///////////////////////////////////////////////////////////////////////
// Copyright (c) 1988-2011 $organization$
//
// This software is provided by the author and contributors ``as is'' 
// and any express or implied warranties, including, but not limited to, 
// the implied warranties of merchantability and fitness for a particular 
// purpose are disclaimed. In no event shall the author or contributors 
// be liable for any direct, indirect, incidental, special, exemplary, 
// or consequential damages (including, but not limited to, procurement 
// of substitute goods or services; loss of use, data, or profits; or 
// business interruption) however caused and on any theory of liability, 
// whether in contract, strict liability, or tort (including negligence 
// or otherwise) arising in any way out of the use of this software, 
// even if advised of the possibility of such damage.
//
//   File: cFilePathParser.hpp
//
// Author: $author$
//   Date: 8/6/2011
///////////////////////////////////////////////////////////////////////
#if !defined(_CFILEPATHPARSER_HPP) || defined(CFILEPATHPARSERT_MEMBERS_ONLY)
#if !defined(_CFILEPATHPARSER_HPP) && !defined(CFILEPATHPARSERT_MEMBERS_ONLY)
#define _CFILEPATHPARSER_HPP
#endif // !defined(_CFILEPATHPARSER_HPP) && !defined(CFILEPATHPARSERT_MEMBERS_ONLY) 

#if !defined(CFILEPATHPARSERT_MEMBERS_ONLY)
#include "cFilePathParserInterface.hpp"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

#undef CDB_CLASS
#define CDB_CLASS "cFilePathParserT"
///////////////////////////////////////////////////////////////////////
//  Class: cFilePathParserT
//
// Author: $author$
//   Date: 8/6/2011
///////////////////////////////////////////////////////////////////////
template
<class TImplement=cFilePathParserImplement,
 class TEventsInterface=cFilePathParserEventsInterface,
 class TWriterImplement=cCharWriterImplement,
 class TWriterInterface=cCharWriterInterface,
 class TString=cString,
 class TChar=char,
 class TExtend=cInstanceBase>

class c_INSTANCE_CLASS cFilePathParserT
: virtual public TImplement,
  virtual public TWriterImplement,
  public TExtend
{
public:
    typedef TImplement cImplements;
    typedef TExtend cExtends;
    typedef cFilePathParserT cDerives;

// include cFilePathParserT interface member definitions
//
#define CFILEPATHPARSERINTERFACET_MEMBERS_ONLY
#include "cFilePathParserInterface.hpp"
#undef CFILEPATHPARSERINTERFACET_MEMBERS_ONLY

    typedef TEventsInterface tEventsInterface;
    typedef ssize_t (cDerives::*MPut)(const char_t& c);
    typedef eError (cDerives::*MFinal)();

    tEventsInterface& m_events;

    MFinal m_final;
    MPut m_put;
    MPut m_oldPut;

    char_t m_dot;
    tString m_token, m_token2;

    ///////////////////////////////////////////////////////////////////////
    //  Constructor: cFilePathParserT
    //
    //       Author: $author$
    //         Date: 8/6/2011
    ///////////////////////////////////////////////////////////////////////
    cFilePathParserT
    (tEventsInterface& events)
    : m_events(events),
      m_final(0),
      m_put(0),
      m_oldPut(0),
      m_dot((char_t)('.'))
    {
    }
    ///////////////////////////////////////////////////////////////////////
    //  Destructor: ~cFilePathParserT
    //
    //      Author: $author$
    //        Date: 8/6/2011
    ///////////////////////////////////////////////////////////////////////
    virtual ~cFilePathParserT()
    {
    }
#else // !defined(CFILEPATHPARSERT_MEMBERS_ONLY) 
#endif // !defined(CFILEPATHPARSERT_MEMBERS_ONLY) 

    ///////////////////////////////////////////////////////////////////////
    //  Function: Parse
    //
    //    Author: $author$
    //      Date: 8/8/2011
    ///////////////////////////////////////////////////////////////////////
    virtual eError Parse
    (const tString& path)
#if defined(CFILEPATHPARSERT_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CFILEPATHPARSERT_MEMBER_FUNCS_INTERFACE) 
    {
        eError error = Parse(path.Chars());
#if !defined(CFILEPATHPARSERT_MEMBER_FUNCS_IMPLEMENT)
#else // !defined(CFILEPATHPARSERT_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CFILEPATHPARSERT_MEMBER_FUNCS_IMPLEMENT) 
        return error;
    }
#endif // defined(CFILEPATHPARSERT_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    //  Function: Parse
    //
    //    Author: $author$
    //      Date: 8/8/2011
    ///////////////////////////////////////////////////////////////////////
    virtual eError Parse
    (const char_t* chars,
     ssize_t length=-1)
#if defined(CFILEPATHPARSERT_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CFILEPATHPARSERT_MEMBER_FUNCS_INTERFACE) 
    {
        eError error = e_ERROR_NONE;
#if !defined(CFILEPATHPARSERT_MEMBER_FUNCS_IMPLEMENT)
        if (!(error = Initialize()))
        {
            ssize_t count;
            eError error2;
            if (0 > (count = Write(chars, length)))
                error = (eError)(-count);
            if ((error2 = Finialize()))
            if (!(error))
                error = error2;
        }
#else // !defined(CFILEPATHPARSERT_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CFILEPATHPARSERT_MEMBER_FUNCS_IMPLEMENT) 
        return error;
    }
#endif // defined(CFILEPATHPARSERT_MEMBER_FUNCS_INTERFACE) 

    ///////////////////////////////////////////////////////////////////////
    //  Function: Initialize
    //
    //    Author: $author$
    //      Date: 8/8/2011
    ///////////////////////////////////////////////////////////////////////
    virtual eError Initialize()
#if defined(CFILEPATHPARSERT_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CFILEPATHPARSERT_MEMBER_FUNCS_INTERFACE) 
    {
        eError error = e_ERROR_NONE;
#if !defined(CFILEPATHPARSERT_MEMBER_FUNCS_IMPLEMENT)
        m_final = &cDerives::InitFinal;
        m_put = &cDerives::InitPut;
        m_token.Clear();
        m_token2.Clear();
#else // !defined(CFILEPATHPARSERT_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CFILEPATHPARSERT_MEMBER_FUNCS_IMPLEMENT) 
        return error;
    }
#endif // defined(CFILEPATHPARSERT_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    //  Function: Finialize
    //
    //    Author: $author$
    //      Date: 8/8/2011
    ///////////////////////////////////////////////////////////////////////
    virtual eError Finialize()
#if defined(CFILEPATHPARSERT_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CFILEPATHPARSERT_MEMBER_FUNCS_INTERFACE) 
    {
        eError error = e_ERROR_NONE;
#if !defined(CFILEPATHPARSERT_MEMBER_FUNCS_IMPLEMENT)
        if (m_final)
            error = (this->*m_final)();
#else // !defined(CFILEPATHPARSERT_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CFILEPATHPARSERT_MEMBER_FUNCS_IMPLEMENT) 
        return error;
    }
#endif // defined(CFILEPATHPARSERT_MEMBER_FUNCS_INTERFACE) 

    ///////////////////////////////////////////////////////////////////////
    //  Function: Write
    //
    //    Author: $author$
    //      Date: 8/8/2011
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t Write
    (const char_t* chars,
     ssize_t length=-1)
#if defined(CFILEPATHPARSERT_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CFILEPATHPARSERT_MEMBER_FUNCS_INTERFACE) 
    {
        ssize_t count = 0;
#if !defined(CFILEPATHPARSERT_MEMBER_FUNCS_IMPLEMENT)
        ssize_t count2;
        if ((chars))
        if (0 > (length))
        {
            for (; *chars ; ++chars, count += count2)
            {
                if (0 > (count2 = Put(*chars)))
                    return count2;
            }
        }
        else
        {
            for (; length; --length, ++chars, count += count2)
            {
                if (0 > (count2 = Put(*chars)))
                    return count2;
            }
        }
#else // !defined(CFILEPATHPARSERT_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CFILEPATHPARSERT_MEMBER_FUNCS_IMPLEMENT) 
        return count;
    }
#endif // defined(CFILEPATHPARSERT_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    //  Function: Put
    //
    //    Author: $author$
    //      Date: 8/8/2011
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t Put
    (const char_t& c)
#if defined(CFILEPATHPARSERT_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CFILEPATHPARSERT_MEMBER_FUNCS_INTERFACE) 
    {
        ssize_t count = 0;
#if !defined(CFILEPATHPARSERT_MEMBER_FUNCS_IMPLEMENT)
        if (m_put)
            count = (this->*m_put)(c);
#else // !defined(CFILEPATHPARSERT_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CFILEPATHPARSERT_MEMBER_FUNCS_IMPLEMENT) 
        return count;
    }
#endif // defined(CFILEPATHPARSERT_MEMBER_FUNCS_INTERFACE) 

    //
    // Put
    //

    ///////////////////////////////////////////////////////////////////////
    //  Function: InitPut
    //
    //    Author: $author$
    //      Date: 8/8/2011
    //
    // A*?
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t InitPut
    (const char_t& c)
#if defined(CFILEPATHPARSERT_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CFILEPATHPARSERT_MEMBER_FUNCS_INTERFACE) 
    {
        ssize_t count = 0;
#if !defined(CFILEPATHPARSERT_MEMBER_FUNCS_IMPLEMENT)
        ssize_t length;
        const char_t* chars;
        switch((char)(c))
        {
        case '/':
        case '\\':
            if ((chars = m_token.HasChars(length)))
            {
                // A+'/'
                m_events.OnPathDirectory(chars, length);
                m_token.Clear();
                m_put = &cDerives::NamePut;
            }
            else 
            {
                // '/'
                m_put = &cDerives::RootPut;
                m_final = &cDerives::RootFinal;
            }
            break;
        case '.':
            if ((chars = m_token.HasChars(length)))
            {
                // A+'.'
                m_oldPut = m_put;
                m_put = &cDerives::ExtensionPut;
                m_final = &cDerives::ExtensionFinal;
            }
            else
            {
                // '.' 
                m_put = &cDerives::CurrentPut;
                m_final = &cDerives::CurrentFinal;
            }
            break;
        case ':':
            if ((chars = m_token.HasChars(length)))
            {
                // A+':'
                m_events.OnPathVolume(chars, length);
                m_token.Clear();
            }
            m_put = &cDerives::VolumePut;
            break;
        default:
            // A
            m_token.Append(&c, 1);
            m_final = &cDerives::NameFinal;
        }
#else // !defined(CFILEPATHPARSERT_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CFILEPATHPARSERT_MEMBER_FUNCS_IMPLEMENT) 
        return count;
    }
#endif // defined(CFILEPATHPARSERT_MEMBER_FUNCS_INTERFACE) 

    ///////////////////////////////////////////////////////////////////////
    //  Function: HostPut
    //
    //    Author: $author$
    //      Date: 8/8/2011
    //
    // '/''/'?
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t HostPut
    (const char_t& c)
#if defined(CFILEPATHPARSERT_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CFILEPATHPARSERT_MEMBER_FUNCS_INTERFACE) 
    {
        ssize_t count = 0;
#if !defined(CFILEPATHPARSERT_MEMBER_FUNCS_IMPLEMENT)
        ssize_t length;
        const char_t* chars;
        switch((char)(c))
        {
        case '/':
        case '\\':
            // '/''/'A*'/'
            if ((chars = m_token.HasChars(length)))
            {
                // '/''/'A+'/'
                m_events.OnPathHost(chars, length);
                m_token.Clear();
            }
            m_put = &cDerives::NamePut;
            break;
        default:
            // '/''/'A
            m_token.Append(&c, 1);
            m_final = &cDerives::HostFinal;
        }
#else // !defined(CFILEPATHPARSERT_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CFILEPATHPARSERT_MEMBER_FUNCS_IMPLEMENT) 
        return count;
    }
#endif // defined(CFILEPATHPARSERT_MEMBER_FUNCS_INTERFACE) 

    ///////////////////////////////////////////////////////////////////////
    //  Function: VolumePut
    //
    //    Author: $author$
    //      Date: 8/8/2011
    //
    // A+':'?
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t VolumePut
    (const char_t& c)
#if defined(CFILEPATHPARSERT_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CFILEPATHPARSERT_MEMBER_FUNCS_INTERFACE) 
    {
        ssize_t count = 0;
#if !defined(CFILEPATHPARSERT_MEMBER_FUNCS_IMPLEMENT)
        ssize_t length;
        const char_t* chars;
        switch((char)(c))
        {
        case '/':
        case '\\':
            // A+':'A*'/'
            if ((chars = m_token.HasChars(length)))
            {
                // A+':'A+'/'
                m_events.OnPathDirectory(chars, length);
                m_token.Clear();
                m_put = &cDerives::NamePut;
            }
            else 
            {
                // A+':''/'
                m_put = &cDerives::RootPut;
                m_final = &cDerives::RootFinal;
            }
            break;
        case '.':
            // A+':'A*'.'
            if ((chars = m_token.HasChars(length)))
            {
                // A+':'A+'.'
                m_oldPut = &cDerives::NamePut;
                m_put = &cDerives::ExtensionPut;
                m_final = &cDerives::ExtensionFinal;
            }
            else
            {
                // A+':''.' 
                m_put = &cDerives::CurrentPut;
                m_final = &cDerives::CurrentFinal;
            }
            break;
        default:
            // A+':'A
            m_token.Append(&c, 1);
            m_final = &cDerives::NameFinal;
        }
#else // !defined(CFILEPATHPARSERT_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CFILEPATHPARSERT_MEMBER_FUNCS_IMPLEMENT) 
        return count;
    }
#endif // defined(CFILEPATHPARSERT_MEMBER_FUNCS_INTERFACE) 

    ///////////////////////////////////////////////////////////////////////
    //  Function: NamePut
    //
    //    Author: $author$
    //      Date: 8/8/2011
    //
    // .+?
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t NamePut
    (const char_t& c)
#if defined(CFILEPATHPARSERT_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CFILEPATHPARSERT_MEMBER_FUNCS_INTERFACE) 
    {
        ssize_t count = 0;
#if !defined(CFILEPATHPARSERT_MEMBER_FUNCS_IMPLEMENT)
        ssize_t length;
        const char_t* chars;
        switch((char)(c))
        {
        case '/':
        case '\\':
            if ((chars = m_token.HasChars(length)))
            {
                // .+A+'/'
                m_events.OnPathDirectory(chars, length);
                m_token.Clear();
            }
            break;
        case '.':
            if ((chars = m_token.HasChars(length)))
            {
                // .+A+'.'
                m_oldPut = m_put;
                m_put = &cDerives::ExtensionPut;
                m_final = &cDerives::ExtensionFinal;
            }
            else
            {
                // .+'.' 
                m_put = &cDerives::CurrentPut;
                m_final = &cDerives::CurrentFinal;
            }
            break;
        default:
            // .+A
            m_token.Append(&c, 1);
            m_final = &cDerives::NameFinal;
        }
#else // !defined(CFILEPATHPARSERT_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CFILEPATHPARSERT_MEMBER_FUNCS_IMPLEMENT) 
        return count;
    }
#endif // defined(CFILEPATHPARSERT_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    //  Function: RootNamePut
    //
    //    Author: $author$
    //      Date: 8/8/2011
    //
    // '/'.+?
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t RootNamePut
    (const char_t& c)
#if defined(CFILEPATHPARSERT_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CFILEPATHPARSERT_MEMBER_FUNCS_INTERFACE) 
    {
        ssize_t count = 0;
#if !defined(CFILEPATHPARSERT_MEMBER_FUNCS_IMPLEMENT)
        ssize_t length;
        const char_t* chars;
        switch((char)(c))
        {
        case '/':
        case '\\':
            if ((chars = m_token.HasChars(length)))
            {
                // '/'.+A+'/'
                m_events.OnPathRootDirectory(chars, length);
                m_token.Clear();
            }
            m_put = &cDerives::NamePut;
            break;
        case '.':
            if ((chars = m_token.HasChars(length)))
            {
                // '/'.+A+'.'
                m_oldPut = &cDerives::NamePut;
                m_put = &cDerives::RootExtensionPut;
                m_final = &cDerives::RootExtensionFinal;
            }
            else
            {
                // '/'.+'.' 
                m_put = &cDerives::RootCurrentPut;
                m_final = &cDerives::RootCurrentFinal;
            }
            break;
        default:
            // '/'.+A
            m_token.Append(&c, 1);
            m_final = &cDerives::RootNameFinal;
        }
#else // !defined(CFILEPATHPARSERT_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CFILEPATHPARSERT_MEMBER_FUNCS_IMPLEMENT) 
        return count;
    }
#endif // defined(CFILEPATHPARSERT_MEMBER_FUNCS_INTERFACE) 

    ///////////////////////////////////////////////////////////////////////
    //  Function: ExtensionPut
    //
    //    Author: $author$
    //      Date: 8/8/2011
    //
    // A+'.'?
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t ExtensionPut
    (const char_t& c)
#if defined(CFILEPATHPARSERT_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CFILEPATHPARSERT_MEMBER_FUNCS_INTERFACE) 
    {
        ssize_t count = 0;
#if !defined(CFILEPATHPARSERT_MEMBER_FUNCS_IMPLEMENT)
        ssize_t length;
        const char_t* chars;
        switch((char)(c))
        {
        case '/':
        case '\\':
            // A+'.'A*'/'
            m_token.Append(&m_dot, 1);
            if ((chars = m_token2.HasChars(length)))
            {
                // A+'.'A+'/'
                m_token.Append(chars, length);
                m_token2.Clear();
            }
            if ((chars = m_token.HasChars(length)))
            {
                m_events.OnPathDirectory(chars, length);
                m_token.Clear();
            }
            m_put = m_oldPut;
            break;
        case '.':
            // A+'.'A*'.'
            m_token.Append(&m_dot, 1);
            if ((chars = m_token2.HasChars(length)))
            {
                // A+'.'A+'.'
                m_token.Append(chars, length);
                m_token2.Clear();
            }
            break;
        default:
            // A+'.'A
            m_token2.Append(&c, 1);
            m_final = &cDerives::ExtensionFinal;
        }
#else // !defined(CFILEPATHPARSERT_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CFILEPATHPARSERT_MEMBER_FUNCS_IMPLEMENT) 
        return count;
    }
#endif // defined(CFILEPATHPARSERT_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    //  Function: RootExtensionPut
    //
    //    Author: $author$
    //      Date: 8/8/2011
    //
    // '/'A+'.'?
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t RootExtensionPut
    (const char_t& c)
#if defined(CFILEPATHPARSERT_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CFILEPATHPARSERT_MEMBER_FUNCS_INTERFACE) 
    {
        ssize_t count = 0;
#if !defined(CFILEPATHPARSERT_MEMBER_FUNCS_IMPLEMENT)
        ssize_t length;
        const char_t* chars;
        switch((char)(c))
        {
        case '/':
        case '\\':
            // '/'A+'.'A*'/'
            m_token.Append(&m_dot, 1);
            if ((chars = m_token2.HasChars(length)))
            {
                // '/'A+'.'A+'/'
                m_token.Append(chars, length);
                m_token2.Clear();
            }
            if ((chars = m_token.HasChars(length)))
            {
                m_events.OnPathRootDirectory(chars, length);
                m_token.Clear();
            }
            m_put = m_oldPut;
            break;
        case '.':
            // '/'A+'.'A*'.'
            m_token.Append(&m_dot, 1);
            if ((chars = m_token2.HasChars(length)))
            {
                // '/'A+'.'A+'.'
                m_token.Append(chars, length);
                m_token2.Clear();
            }
            break;
        default:
            // '/'A+'.'A
            m_token2.Append(&c, 1);
            m_final = &cDerives::RootExtensionFinal;
        }
#else // !defined(CFILEPATHPARSERT_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CFILEPATHPARSERT_MEMBER_FUNCS_IMPLEMENT) 
        return count;
    }
#endif // defined(CFILEPATHPARSERT_MEMBER_FUNCS_INTERFACE) 

    ///////////////////////////////////////////////////////////////////////
    //  Function: CurrentPut
    //
    //    Author: $author$
    //      Date: 8/8/2011
    //
    // '.'?
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t CurrentPut
    (const char_t& c)
#if defined(CFILEPATHPARSERT_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CFILEPATHPARSERT_MEMBER_FUNCS_INTERFACE) 
    {
        ssize_t count = 0;
#if !defined(CFILEPATHPARSERT_MEMBER_FUNCS_IMPLEMENT)
        ssize_t length;
        const char_t* chars;
        switch((char)(c))
        {
        case '/':
        case '\\':
            // '.'A*'/'
            m_token.Append(&m_dot, 1);
            if ((chars = m_token2.HasChars(length)))
            {
                // '.'A+'/'
                m_token.Append(chars, length);
                m_token2.Clear();
                if ((chars = m_token.HasChars(length)))
                {
                    m_events.OnPathDirectory(chars, length);
                    m_token.Clear();
                }
            }
            else
            if ((chars = m_token.HasChars(length)))
            {
                // '.''/'
                m_events.OnPathCurrentDirectory(chars, length);
                m_token.Clear();
            }
            m_put = &cDerives::NamePut;
            break;
        case '.':
            // '.'A*'.'
            m_token.Append(&m_dot, 1);
            if ((chars = m_token2.HasChars(length)))
            {
                // '.'A+'.'
                m_token.Append(chars, length);
                m_token2.Clear();
                m_oldPut = &cDerives::NamePut;
                m_put = &cDerives::ExtensionPut;
                m_final = &cDerives::ExtensionFinal;
            }
            else
            {
                // '.''.' 
                m_put = &cDerives::ParentPut;
                m_final = &cDerives::ParentFinal;
            }
            break;
        default:
            // '.'A
            m_token2.Append(&c, 1);
            m_final = &cDerives::CurrentFinal;
        }
#else // !defined(CFILEPATHPARSERT_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CFILEPATHPARSERT_MEMBER_FUNCS_IMPLEMENT) 
        return count;
    }
#endif // defined(CFILEPATHPARSERT_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    //  Function: RootCurrentPut
    //
    //    Author: $author$
    //      Date: 8/8/2011
    //
    // '/''.'?
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t RootCurrentPut
    (const char_t& c)
#if defined(CFILEPATHPARSERT_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CFILEPATHPARSERT_MEMBER_FUNCS_INTERFACE) 
    {
        ssize_t count = 0;
#if !defined(CFILEPATHPARSERT_MEMBER_FUNCS_IMPLEMENT)
        ssize_t length;
        const char_t* chars;
        switch((char)(c))
        {
        case '/':
        case '\\':
            // '/''.'A*'/'
            m_token.Append(&m_dot, 1);
            if ((chars = m_token2.HasChars(length)))
            {
                // '/''.'A+'/'
                m_token.Append(chars, length);
                m_token2.Clear();
                if ((chars = m_token.HasChars(length)))
                {
                    m_events.OnPathRootDirectory(chars, length);
                    m_token.Clear();
                }
            }
            else
            if ((chars = m_token.HasChars(length)))
            {
                // '/''.''/'
                m_events.OnPathRootCurrentDirectory(chars, length);
                m_token.Clear();
            }
            m_put = &cDerives::NamePut;
            break;
        case '.':
            // '/''.'A*'.'
            m_token.Append(&m_dot, 1);
            if ((chars = m_token2.HasChars(length)))
            {
                // '/''.'A+'.'
                m_token.Append(chars, length);
                m_token2.Clear();
                m_oldPut = &cDerives::NamePut;
                m_put = &cDerives::RootExtensionPut;
                m_final = &cDerives::RootExtensionFinal;
            }
            else
            {
                // '/''.''.' 
                m_put = &cDerives::RootParentPut;
                m_final = &cDerives::RootParentFinal;
            }
            break;
        default:
            // '/''.'A
            m_token2.Append(&c, 1);
            m_final = &cDerives::RootNameFinal;
        }
#else // !defined(CFILEPATHPARSERT_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CFILEPATHPARSERT_MEMBER_FUNCS_IMPLEMENT) 
        return count;
    }
#endif // defined(CFILEPATHPARSERT_MEMBER_FUNCS_INTERFACE) 

    ///////////////////////////////////////////////////////////////////////
    //  Function: ParentPut
    //
    //    Author: $author$
    //      Date: 8/8/2011
    //
    // '.''.'?
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t ParentPut
    (const char_t& c)
#if defined(CFILEPATHPARSERT_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CFILEPATHPARSERT_MEMBER_FUNCS_INTERFACE) 
    {
        ssize_t count = 0;
#if !defined(CFILEPATHPARSERT_MEMBER_FUNCS_IMPLEMENT)
        ssize_t length;
        const char_t* chars;
        switch((char)(c))
        {
        case '/':
        case '\\':
            // '.''.'A*'/'
            m_token.Append(&m_dot, 1);
            if ((chars = m_token2.HasChars(length)))
            {
                // '.''.'A+'/'
                m_token.Append(chars, length);
                m_token2.Clear();
                if ((chars = m_token.HasChars(length)))
                {
                    m_events.OnPathDirectory(chars, length);
                    m_token.Clear();
                }
            }
            else
            if ((chars = m_token.HasChars(length)))
            {
                // '.''.''/'
                m_events.OnPathParentDirectory(chars, length);
                m_token.Clear();
            }
            m_put = &cDerives::NamePut;
            break;
        case '.':
            // '.''.'A*'.'
            m_token.Append(&m_dot, 1);
            if ((chars = m_token2.HasChars(length)))
            {
                // '.''.'A+'.'
                m_token.Append(chars, length);
                m_token2.Clear();
                m_oldPut = &cDerives::NamePut;
                m_put = &cDerives::ExtensionPut;
                m_final = &cDerives::ExtensionFinal;
            }
            else
            {
                // '.''.''.' 
                m_token.Append(&m_dot, 1);
                m_put = &cDerives::NamePut;
                m_final = &cDerives::NameFinal;
            }
            break;
        default:
            // '.''.'A
            m_token2.Append(&c, 1);
            m_final = &cDerives::NameFinal;
        }
#else // !defined(CFILEPATHPARSERT_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CFILEPATHPARSERT_MEMBER_FUNCS_IMPLEMENT) 
        return count;
    }
#endif // defined(CFILEPATHPARSERT_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    //  Function: RootParentPut
    //
    //    Author: $author$
    //      Date: 8/8/2011
    //
    // '/''.''.'?
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t RootParentPut
    (const char_t& c)
#if defined(CFILEPATHPARSERT_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CFILEPATHPARSERT_MEMBER_FUNCS_INTERFACE) 
    {
        ssize_t count = 0;
#if !defined(CFILEPATHPARSERT_MEMBER_FUNCS_IMPLEMENT)
        ssize_t length;
        const char_t* chars;
        switch((char)(c))
        {
        case '/':
        case '\\':
            // '/''.''.'A*'/'
            m_token.Append(&m_dot, 1);
            if ((chars = m_token2.HasChars(length)))
            {
                // '/''.''.'A+'/'
                m_token.Append(chars, length);
                m_token2.Clear();
                if ((chars = m_token.HasChars(length)))
                {
                    m_events.OnPathRootDirectory(chars, length);
                    m_token.Clear();
                }
            }
            else
            if ((chars = m_token.HasChars(length)))
            {
                // '/''.''.''/'
                m_events.OnPathRootParentDirectory(chars, length);
                m_token.Clear();
            }
            m_put = &cDerives::NamePut;
            break;
        case '.':
            // '/''.''.'A*'.'
            m_token.Append(&m_dot, 1);
            if ((chars = m_token2.HasChars(length)))
            {
                // '/''.''.'A+'.'
                m_token.Append(chars, length);
                m_token2.Clear();
                m_oldPut = &cDerives::NamePut;
                m_put = &cDerives::RootExtensionPut;
                m_final = &cDerives::RootExtensionFinal;
            }
            else
            {
                // '/''.''.''.' 
                m_token.Append(&m_dot, 1);
                m_put = &cDerives::RootNamePut;
                m_final = &cDerives::RootNameFinal;
            }
            break;
        default:
            // '/''.''.'A
            m_token2.Append(&c, 1);
            m_final = &cDerives::RootNameFinal;
        }
#else // !defined(CFILEPATHPARSERT_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CFILEPATHPARSERT_MEMBER_FUNCS_IMPLEMENT) 
        return count;
    }
#endif // defined(CFILEPATHPARSERT_MEMBER_FUNCS_INTERFACE) 

    ///////////////////////////////////////////////////////////////////////
    //  Function: RootPut
    //
    //    Author: $author$
    //      Date: 8/8/2011
    //
    // '/'?
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t RootPut
    (const char_t& c)
#if defined(CFILEPATHPARSERT_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CFILEPATHPARSERT_MEMBER_FUNCS_INTERFACE) 
    {
        ssize_t count = 0;
#if !defined(CFILEPATHPARSERT_MEMBER_FUNCS_IMPLEMENT)
        ssize_t length;
        const char_t* chars;
        switch((char)(c))
        {
        case '/':
        case '\\':
            // '/'A*'/'
            if ((chars = m_token.HasChars(length)))
            {
                // '/'A+'/'
                m_events.OnPathRootDirectory(chars, length);
                m_token.Clear();
                m_put = &cDerives::NamePut;
            }
            else 
            {
                // '/''/'
                m_put = &cDerives::HostPut;
                m_final = &cDerives::HostFinal;
            }
            break;
        case '.':
            // '/'A*'.'
            if ((chars = m_token.HasChars(length)))
            {
                // '/'A+'.'
                m_oldPut = &cDerives::NamePut;
                m_put = &cDerives::RootExtensionPut;
                m_final = &cDerives::RootExtensionFinal;
            }
            else
            {
                // '/''.' 
                m_put = &cDerives::RootCurrentPut;
                m_final = &cDerives::RootCurrentFinal;
            }
            break;
        case ':':
            // '/'A*':'
            if ((chars = m_token.HasChars(length)))
            {
                // A+':'
                m_events.OnPathVolume(chars, length);
                m_token.Clear();
            }
            m_put = &cDerives::VolumePut;
            break;
        default:
            // '/'A
            m_token.Append(&c, 1);
            m_final = &cDerives::RootFinal;
        }
#else // !defined(CFILEPATHPARSERT_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CFILEPATHPARSERT_MEMBER_FUNCS_IMPLEMENT) 
        return count;
    }
#endif // defined(CFILEPATHPARSERT_MEMBER_FUNCS_INTERFACE) 

    //
    // Final
    //

    ///////////////////////////////////////////////////////////////////////
    //  Function: InitFinal
    //
    //    Author: $author$
    //      Date: 8/8/2011
    ///////////////////////////////////////////////////////////////////////
    virtual eError InitFinal()
#if defined(CFILEPATHPARSERT_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CFILEPATHPARSERT_MEMBER_FUNCS_INTERFACE) 
    {
        eError error = e_ERROR_NONE;
#if !defined(CFILEPATHPARSERT_MEMBER_FUNCS_IMPLEMENT)
#else // !defined(CFILEPATHPARSERT_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CFILEPATHPARSERT_MEMBER_FUNCS_IMPLEMENT) 
        return error;
    }
#endif // defined(CFILEPATHPARSERT_MEMBER_FUNCS_INTERFACE) 

    ///////////////////////////////////////////////////////////////////////
    //  Function: HostFinal
    //
    //    Author: $author$
    //      Date: 8/8/2011
    //
    // '/''/'A*
    ///////////////////////////////////////////////////////////////////////
    virtual eError HostFinal()
#if defined(CFILEPATHPARSERT_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CFILEPATHPARSERT_MEMBER_FUNCS_INTERFACE) 
    {
        eError error = e_ERROR_NONE;
#if !defined(CFILEPATHPARSERT_MEMBER_FUNCS_IMPLEMENT)
        ssize_t length;
        const char_t* chars;
        if ((chars = m_token.HasChars(length)))
        {
            // '/''/'A+
            m_events.OnPathHost(chars, length);
            m_token.Clear();
        }
#else // !defined(CFILEPATHPARSERT_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CFILEPATHPARSERT_MEMBER_FUNCS_IMPLEMENT) 
        return error;
    }
#endif // defined(CFILEPATHPARSERT_MEMBER_FUNCS_INTERFACE) 

    ///////////////////////////////////////////////////////////////////////
    //  Function: NameFinal
    //
    //    Author: $author$
    //      Date: 8/8/2011
    //
    // A*
    ///////////////////////////////////////////////////////////////////////
    virtual eError NameFinal()
#if defined(CFILEPATHPARSERT_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CFILEPATHPARSERT_MEMBER_FUNCS_INTERFACE) 
    {
        eError error = e_ERROR_NONE;
#if !defined(CFILEPATHPARSERT_MEMBER_FUNCS_IMPLEMENT)
        ssize_t length;
        const char_t* chars;
        if ((chars = m_token.HasChars(length)))
        {
            // A+
            m_events.OnPathFileBase(chars, length);
            m_token.Clear();
        }
#else // !defined(CFILEPATHPARSERT_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CFILEPATHPARSERT_MEMBER_FUNCS_IMPLEMENT) 
        return error;
    }
#endif // defined(CFILEPATHPARSERT_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    //  Function: RootNameFinal
    //
    //    Author: $author$
    //      Date: 8/8/2011
    //
    // '/'A*
    ///////////////////////////////////////////////////////////////////////
    virtual eError RootNameFinal()
#if defined(CFILEPATHPARSERT_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CFILEPATHPARSERT_MEMBER_FUNCS_INTERFACE) 
    {
        eError error = e_ERROR_NONE;
#if !defined(CFILEPATHPARSERT_MEMBER_FUNCS_IMPLEMENT)
        ssize_t length;
        const char_t* chars;
        if ((chars = m_token.HasChars(length)))
        {
            // '/'A+
            m_events.OnPathRootFileBase(chars, length);
            m_token.Clear();
        }
#else // !defined(CFILEPATHPARSERT_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CFILEPATHPARSERT_MEMBER_FUNCS_IMPLEMENT) 
        return error;
    }
#endif // defined(CFILEPATHPARSERT_MEMBER_FUNCS_INTERFACE) 

    ///////////////////////////////////////////////////////////////////////
    //  Function: ExtensionFinal
    //
    //    Author: $author$
    //      Date: 8/8/2011
    //
    // A+'.'A*
    ///////////////////////////////////////////////////////////////////////
    virtual eError ExtensionFinal()
#if defined(CFILEPATHPARSERT_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CFILEPATHPARSERT_MEMBER_FUNCS_INTERFACE) 
    {
        eError error = e_ERROR_NONE;
#if !defined(CFILEPATHPARSERT_MEMBER_FUNCS_IMPLEMENT)
        ssize_t length;
        const char_t* chars;
        if ((chars = m_token.HasChars(length)))
        {
            // A+'.'
            m_events.OnPathFileBase(chars, length);
            m_token.Clear();
        }
        if ((chars = m_token2.HasChars(length)))
        {
            // A'.'A+
            m_events.OnPathFileExtension(chars, length);
            m_token2.Clear();
        }
#else // !defined(CFILEPATHPARSERT_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CFILEPATHPARSERT_MEMBER_FUNCS_IMPLEMENT) 
        return error;
    }
#endif // defined(CFILEPATHPARSERT_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    //  Function: RootExtensionFinal
    //
    //    Author: $author$
    //      Date: 8/8/2011
    //
    // '/'A+'.'A*
    ///////////////////////////////////////////////////////////////////////
    virtual eError RootExtensionFinal()
#if defined(CFILEPATHPARSERT_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CFILEPATHPARSERT_MEMBER_FUNCS_INTERFACE) 
    {
        eError error = e_ERROR_NONE;
#if !defined(CFILEPATHPARSERT_MEMBER_FUNCS_IMPLEMENT)
        ssize_t length;
        const char_t* chars;
        if ((chars = m_token.HasChars(length)))
        {
            // '/'A+'.'
            m_events.OnPathRootFileBase(chars, length);
            m_token.Clear();
        }
        if ((chars = m_token2.HasChars(length)))
        {
            // '/'A'.'A+
            m_events.OnPathFileExtension(chars, length);
            m_token2.Clear();
        }
#else // !defined(CFILEPATHPARSERT_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CFILEPATHPARSERT_MEMBER_FUNCS_IMPLEMENT) 
        return error;
    }
#endif // defined(CFILEPATHPARSERT_MEMBER_FUNCS_INTERFACE) 

    ///////////////////////////////////////////////////////////////////////
    //  Function: CurrentFinal
    //
    //    Author: $author$
    //      Date: 8/8/2011
    //
    // '.'
    ///////////////////////////////////////////////////////////////////////
    virtual eError CurrentFinal()
#if defined(CFILEPATHPARSERT_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CFILEPATHPARSERT_MEMBER_FUNCS_INTERFACE) 
    {
        eError error = e_ERROR_NONE;
#if !defined(CFILEPATHPARSERT_MEMBER_FUNCS_IMPLEMENT)
        ssize_t length;
        const char_t* chars;
        if ((chars = m_token.HasChars(length)))
        {
            // '.'
            m_events.OnPathCurrentDirectory(chars, length);
            m_token.Clear();
        }
#else // !defined(CFILEPATHPARSERT_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CFILEPATHPARSERT_MEMBER_FUNCS_IMPLEMENT) 
        return error;
    }
#endif // defined(CFILEPATHPARSERT_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    //  Function: RootCurrentFinal
    //
    //    Author: $author$
    //      Date: 8/8/2011
    //
    // '/''.'
    ///////////////////////////////////////////////////////////////////////
    virtual eError RootCurrentFinal()
#if defined(CFILEPATHPARSERT_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CFILEPATHPARSERT_MEMBER_FUNCS_INTERFACE) 
    {
        eError error = e_ERROR_NONE;
#if !defined(CFILEPATHPARSERT_MEMBER_FUNCS_IMPLEMENT)
        ssize_t length;
        const char_t* chars;
        if ((chars = m_token.HasChars(length)))
        {
            // '/''.'
            m_events.OnPathRootCurrentDirectory(chars, length);
            m_token.Clear();
        }
#else // !defined(CFILEPATHPARSERT_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CFILEPATHPARSERT_MEMBER_FUNCS_IMPLEMENT) 
        return error;
    }
#endif // defined(CFILEPATHPARSERT_MEMBER_FUNCS_INTERFACE) 

    ///////////////////////////////////////////////////////////////////////
    //  Function: ParentFinal
    //
    //    Author: $author$
    //      Date: 8/8/2011
    //
    // '.''.'
    ///////////////////////////////////////////////////////////////////////
    virtual eError ParentFinal()
#if defined(CFILEPATHPARSERT_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CFILEPATHPARSERT_MEMBER_FUNCS_INTERFACE) 
    {
        eError error = e_ERROR_NONE;
#if !defined(CFILEPATHPARSERT_MEMBER_FUNCS_IMPLEMENT)
        ssize_t length;
        const char_t* chars;
        if ((chars = m_token.HasChars(length)))
        {
            // '.''.'
            m_events.OnPathParentDirectory(chars, length);
            m_token.Clear();
        }
#else // !defined(CFILEPATHPARSERT_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CFILEPATHPARSERT_MEMBER_FUNCS_IMPLEMENT) 
        return error;
    }
#endif // defined(CFILEPATHPARSERT_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    //  Function: RootParentFinal
    //
    //    Author: $author$
    //      Date: 8/8/2011
    //
    // '/''.''.'
    ///////////////////////////////////////////////////////////////////////
    virtual eError RootParentFinal()
#if defined(CFILEPATHPARSERT_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CFILEPATHPARSERT_MEMBER_FUNCS_INTERFACE) 
    {
        eError error = e_ERROR_NONE;
#if !defined(CFILEPATHPARSERT_MEMBER_FUNCS_IMPLEMENT)
        ssize_t length;
        const char_t* chars;
        if ((chars = m_token.HasChars(length)))
        {
            // '/''.''.'
            m_events.OnPathRootParentDirectory(chars, length);
            m_token.Clear();
        }
#else // !defined(CFILEPATHPARSERT_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CFILEPATHPARSERT_MEMBER_FUNCS_IMPLEMENT) 
        return error;
    }
#endif // defined(CFILEPATHPARSERT_MEMBER_FUNCS_INTERFACE) 

    ///////////////////////////////////////////////////////////////////////
    //  Function: RootFinal
    //
    //    Author: $author$
    //      Date: 8/8/2011
    //
    // '/'
    ///////////////////////////////////////////////////////////////////////
    virtual eError RootFinal()
#if defined(CFILEPATHPARSERT_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CFILEPATHPARSERT_MEMBER_FUNCS_INTERFACE) 
    {
        eError error = e_ERROR_NONE;
#if !defined(CFILEPATHPARSERT_MEMBER_FUNCS_IMPLEMENT)
        ssize_t length;
        const char_t* chars;
        chars = m_token.HasChars(length);
        m_events.OnPathRootDirectory(chars, length);
#else // !defined(CFILEPATHPARSERT_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CFILEPATHPARSERT_MEMBER_FUNCS_IMPLEMENT) 
        return error;
    }
#endif // defined(CFILEPATHPARSERT_MEMBER_FUNCS_INTERFACE) 

#if !defined(CFILEPATHPARSERT_MEMBERS_ONLY)
};
#undef CDB_CLASS

///////////////////////////////////////////////////////////////////////
// Typedef: cFilePathParserExtend
//
//  Author: $author$
//    Date: 8/6/2011
///////////////////////////////////////////////////////////////////////
typedef cFilePathParserT<>
cFilePathParserExtend;
///////////////////////////////////////////////////////////////////////
//  Class: cFilePathParser
//
// Author: $author$
//   Date: 8/6/2011
///////////////////////////////////////////////////////////////////////
class c_INSTANCE_CLASS cFilePathParser
: public cFilePathParserExtend
{
public:
    typedef cFilePathParserExtend cExtends;
    ///////////////////////////////////////////////////////////////////////
    //  Constructor: cFilePathParser
    //
    //       Author: $author$
    //         Date: 8/6/2011
    ///////////////////////////////////////////////////////////////////////
    cFilePathParser
    (tEventsInterface& events)
    : cExtends(events)
    {
    }
    ///////////////////////////////////////////////////////////////////////
    //  Destructor: ~cFilePathParser
    //
    //      Author: $author$
    //        Date: 8/6/2011
    ///////////////////////////////////////////////////////////////////////
    virtual ~cFilePathParser()
    {
    }
};

#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#else // !defined(CFILEPATHPARSERT_MEMBERS_ONLY) 
#endif // !defined(CFILEPATHPARSERT_MEMBERS_ONLY) 

#endif // !defined(_CFILEPATHPARSER_HPP) || defined(CFILEPATHPARSERT_MEMBERS_ONLY) 
        

