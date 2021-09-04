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
//   File: cString.hpp
//
// Author: $author$
//   Date: 3/20/2011
///////////////////////////////////////////////////////////////////////
#if !defined(_CSTRING_HPP) || defined(CSTRINGT_MEMBERS_ONLY)
#if !defined(_CSTRING_HPP) && !defined(CSTRINGT_MEMBERS_ONLY)
#define _CSTRING_HPP
#endif // !defined(_CSTRING_HPP) && !defined(CSTRINGT_MEMBERS_ONLY) 

#if !defined(CSTRINGT_MEMBERS_ONLY)
#include "cStringInterface.hpp"
#include "cInstanceBase.hpp"
#include <sstream>
#include <string>

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

///////////////////////////////////////////////////////////////////////
// Typedef: cStringExtendExtend
//
//  Author: $author$
//    Date: 5/20/2011
///////////////////////////////////////////////////////////////////////
typedef std::string
cStringExtendExtend;

#undef CDB_CLASS
#define CDB_CLASS "cStringT"
///////////////////////////////////////////////////////////////////////
//  Class: cStringT
//
// Author: $author$
//   Date: 3/20/2011
///////////////////////////////////////////////////////////////////////
template
<class TImplement=cStringImplement,
 class TInterface=cStringInterface,
 class TChar=char,
 class TExtend=cStringExtendExtend>

class c_INSTANCE_CLASS cStringT
: virtual public TImplement,
  public TExtend
{
public:
    typedef TImplement cImplements;
    typedef TExtend cExtends;

// include cString interface member definitions
//
#define CSTRINGINTERFACET_MEMBERS_ONLY
#include "cStringInterface.hpp"
#undef CSTRINGINTERFACET_MEMBERS_ONLY

    typedef TInterface cInterface;

    ///////////////////////////////////////////////////////////////////////
    //  Constructor: cStringT
    //
    //       Author: $author$
    //         Date: 3/20/2011
    ///////////////////////////////////////////////////////////////////////
    cStringT(const char_t* chars, ssize_t length=-1)
    {
        Append(chars, length);
    }
    ///////////////////////////////////////////////////////////////////////
    //  Constructor: cStringT
    //
    //       Author: $author$
    //         Date: 3/20/2011
    ///////////////////////////////////////////////////////////////////////
    cStringT(const cExtends& string)
    {
        Append(string.c_str());
    }
    ///////////////////////////////////////////////////////////////////////
    //  Constructor: cStringT
    //
    //       Author: $author$
    //         Date: 3/20/2011
    ///////////////////////////////////////////////////////////////////////
    cStringT(const cInterface& string)
    {
        Append(string);
    }
    ///////////////////////////////////////////////////////////////////////
    //  Constructor: cStringT
    //
    //       Author: $author$
    //         Date: 3/20/2011
    ///////////////////////////////////////////////////////////////////////
    cStringT(signed int value)
    {
        Append(value);
    }
    ///////////////////////////////////////////////////////////////////////
    //  Constructor: cStringT
    //
    //       Author: $author$
    //         Date: 3/20/2011
    ///////////////////////////////////////////////////////////////////////
    cStringT(unsigned int value)
    {
        Append(value);
    }
    ///////////////////////////////////////////////////////////////////////
    //  Constructor: cStringT
    //
    //       Author: $author$
    //         Date: 3/20/2011
    ///////////////////////////////////////////////////////////////////////
    cStringT()
    {
    }
    ///////////////////////////////////////////////////////////////////////
    //  Destructor: ~cStringT
    //
    //      Author: $author$
    //        Date: 3/20/2011
    ///////////////////////////////////////////////////////////////////////
    virtual ~cStringT()
    {
    }
#else // !defined(CSTRINGT_MEMBERS_ONLY) 
#endif // !defined(CSTRINGT_MEMBERS_ONLY) 

    ///////////////////////////////////////////////////////////////////////
    //  Function: ToLower
    //
    //    Author: $author$
    //      Date: 8/20/2013
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t ToLower()
#if defined(CSTRINGT_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CSTRINGT_MEMBER_FUNCS_INTERFACE) 
    {
        ssize_t count = 0;
#if !defined(CSTRINGT_MEMBER_FUNCS_IMPLEMENT)
        const char_t* chars;
        ssize_t length;
        if ((chars = HasChars(length))) {
            static const char_t a = (char_t)('a');
            static const char_t A = (char_t)('A');
            static const char_t Z = (char_t)('Z');
            cStringT upper(chars, length);
            if ((chars = upper.HasChars(length))) {
                Clear();
                for (ssize_t i=0; i<length; ++i) {
                    char_t c = chars[i];
                    if ((c >= A) && (c <= Z)) {
                        c = a + (c - A);
                        ++count;
                    }
                    Append(&c, 1);
                }
            }
        }
#else // !defined(CSTRINGT_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CSTRINGT_MEMBER_FUNCS_IMPLEMENT) 
        return count;
    }
#endif // defined(CSTRINGT_MEMBER_FUNCS_INTERFACE) 

    ///////////////////////////////////////////////////////////////////////
    //  Function: ToUpper
    //
    //    Author: $author$
    //      Date: 8/20/2013
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t ToUpper()
#if defined(CSTRINGT_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CSTRINGT_MEMBER_FUNCS_INTERFACE) 
    {
        ssize_t count = 0;
#if !defined(CSTRINGT_MEMBER_FUNCS_IMPLEMENT)
        const char_t* chars;
        ssize_t length;
        if ((chars = HasChars(length))) {
            static const char_t a = (char_t)('a');
            static const char_t z = (char_t)('z');
            static const char_t A = (char_t)('A');
            cStringT lower(chars, length);
            if ((chars = lower.HasChars(length))) {
                Clear();
                for (ssize_t i=0; i<length; ++i) {
                    char_t c = chars[i];
                    if ((c >= a) && (c <= z)) {
                        c = A + (c - a);
                        ++count;
                    }
                    Append(&c, 1);
                }
            }
        }
#else // !defined(CSTRINGT_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CSTRINGT_MEMBER_FUNCS_IMPLEMENT) 
        return count;
    }
#endif // defined(CSTRINGT_MEMBER_FUNCS_INTERFACE) 

    ///////////////////////////////////////////////////////////////////////
    //  Function: Clear
    //
    //    Author: $author$
    //      Date: 3/20/2011
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t Clear()
#if defined(CSTRINGT_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CSTRINGT_MEMBER_FUNCS_INTERFACE) 
    {
        ssize_t count = 0;
#if !defined(CSTRINGT_MEMBER_FUNCS_IMPLEMENT)
        count = cExtends::length();
        cExtends::clear();
#else // !defined(CSTRINGT_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CSTRINGT_MEMBER_FUNCS_IMPLEMENT) 
        return count;
    }
#endif // defined(CSTRINGT_MEMBER_FUNCS_INTERFACE) 

    ///////////////////////////////////////////////////////////////////////
    //  Function: Assign
    //
    //    Author: $author$
    //      Date: 3/20/2011
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t Assign
    (signed int value)
#if defined(CSTRINGT_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CSTRINGT_MEMBER_FUNCS_INTERFACE) 
    {
        ssize_t count = 0;
#if !defined(CSTRINGT_MEMBER_FUNCS_IMPLEMENT)
        if (0 <= (count = Clear()))
            count = Append(value);
#else // !defined(CSTRINGT_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CSTRINGT_MEMBER_FUNCS_IMPLEMENT) 
        return count;
    }
#endif // defined(CSTRINGT_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    //  Function: Assign
    //
    //    Author: $author$
    //      Date: 3/20/2011
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t Assign
    (unsigned int value)
#if defined(CSTRINGT_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CSTRINGT_MEMBER_FUNCS_INTERFACE) 
    {
        ssize_t count = 0;
#if !defined(CSTRINGT_MEMBER_FUNCS_IMPLEMENT)
        if (0 <= (count = Clear()))
            count = Append(value);
#else // !defined(CSTRINGT_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CSTRINGT_MEMBER_FUNCS_IMPLEMENT) 
        return count;
    }
#endif // defined(CSTRINGT_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    //  Function: Assign
    //
    //    Author: $author$
    //      Date: 3/20/2011
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t Assign
    (const char_t* chars,
     ssize_t length=-1)
#if defined(CSTRINGT_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CSTRINGT_MEMBER_FUNCS_INTERFACE) 
    {
        ssize_t count = 0;
#if !defined(CSTRINGT_MEMBER_FUNCS_IMPLEMENT)
        if (0 <= (count = Clear()))
            count = Append(chars, length);
#else // !defined(CSTRINGT_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CSTRINGT_MEMBER_FUNCS_IMPLEMENT) 
        return count;
    }
#endif // defined(CSTRINGT_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    //  Function: Assign
    //
    //    Author: $author$
    //      Date: 3/20/2011
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t Assign
    (const cInterface& string)
#if defined(CSTRINGT_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CSTRINGT_MEMBER_FUNCS_INTERFACE) 
    {
        ssize_t count = 0;
#if !defined(CSTRINGT_MEMBER_FUNCS_IMPLEMENT)
        if (0 <= (count = Clear()))
            count = Append(string);
#else // !defined(CSTRINGT_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CSTRINGT_MEMBER_FUNCS_IMPLEMENT) 
        return count;
    }
#endif // defined(CSTRINGT_MEMBER_FUNCS_INTERFACE) 

    ///////////////////////////////////////////////////////////////////////
    //  Function: Append
    //
    //    Author: $author$
    //      Date: 3/20/2011
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t Append
    (signed value)
#if defined(CSTRINGT_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CSTRINGT_MEMBER_FUNCS_INTERFACE) 
    {
        ssize_t count = 0;
#if !defined(CSTRINGT_MEMBER_FUNCS_IMPLEMENT)

        if (0 > (value))
        {
            const char_t minus = (char_t)('-');
            ssize_t count2;
            if (0 < (count = Append(&minus, 1)))
            if (0 < (count2 = Append((unsigned)(-value))))
                count += count2;
            else 
            count = count2;
        }
        else
        count = Append((unsigned)(value));

#else // !defined(CSTRINGT_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CSTRINGT_MEMBER_FUNCS_IMPLEMENT) 
        return count;
    }
#endif // defined(CSTRINGT_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    //  Function: Append
    //
    //    Author: $author$
    //      Date: 3/20/2011
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t Append
    (unsigned value)
#if defined(CSTRINGT_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CSTRINGT_MEMBER_FUNCS_INTERFACE) 
    {
        ssize_t count = 0;
#if !defined(CSTRINGT_MEMBER_FUNCS_IMPLEMENT)
        const char_t zero = (char_t)('0');
        if (1 > value)
            count = Append(&zero, 1);
        else
        {
            unsigned msdValue;
            unsigned digits;
            ssize_t count2;

            for (digits = 0, msdValue = 0; 
                 value; value /= 10, digits++)
                msdValue = (msdValue*10) + (value%10);
                
            for (; msdValue; msdValue /= 10, --digits)
            {
                char_t d = (char_t)('0' + (char)(msdValue%10));
                if (0 > (count2 = Append(&d, 1)))
                    return count2;
                else
                count += count2;
            }
            
            for (; digits; --digits)
            {
                if (0 > (count2 = Append(&zero, 1)))
                    return count2;
                else
                count += count2;
            }
        }
#else // !defined(CSTRINGT_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CSTRINGT_MEMBER_FUNCS_IMPLEMENT) 
        return count;
    }
#endif // defined(CSTRINGT_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    //  Function: Append
    //
    //    Author: $author$
    //      Date: 3/20/2011
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t Append
    (const char_t* chars,
     ssize_t length=-1)
#if defined(CSTRINGT_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CSTRINGT_MEMBER_FUNCS_INTERFACE) 
    {
        ssize_t count = 0;
#if !defined(CSTRINGT_MEMBER_FUNCS_IMPLEMENT)
        if ((chars))
        {
            ssize_t oldCount = cExtends::length();
            if (0 > (length))
            {
                int i;
                for (length=0, i=0; ((chars[i])!=0); i++)
                    length++;
            }
            cExtends::append(chars, length);
            count = (cExtends::length()-oldCount);
        }
#else // !defined(CSTRINGT_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CSTRINGT_MEMBER_FUNCS_IMPLEMENT) 
        return count;
    }
#endif // defined(CSTRINGT_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    //  Function: Append
    //
    //    Author: $author$
    //      Date: 3/20/2011
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t Append
    (const cInterface& string)
#if defined(CSTRINGT_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CSTRINGT_MEMBER_FUNCS_INTERFACE) 
    {
        ssize_t count = 0;
#if !defined(CSTRINGT_MEMBER_FUNCS_IMPLEMENT)
        ssize_t oldCount = cExtends::length();
        const char_t* chars;
        ssize_t length;
        if ((chars = string.HasChars(length)))
            cExtends::append(chars, length);
        count = (cExtends::length()-oldCount);
#else // !defined(CSTRINGT_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CSTRINGT_MEMBER_FUNCS_IMPLEMENT) 
        return count;
    }
#endif // defined(CSTRINGT_MEMBER_FUNCS_INTERFACE) 

    ///////////////////////////////////////////////////////////////////////
    //  Function: AssignL
    //
    //    Author: $author$
    //      Date: 7/29/2011
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t AssignL
    (const char_t* chars,
     ...)
#if defined(CSTRINGT_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CSTRINGT_MEMBER_FUNCS_INTERFACE) 
    {
        ssize_t count = 0;
#if !defined(CSTRINGT_MEMBER_FUNCS_IMPLEMENT)
        va_list va;
        va_start(va, chars);
        count = AssignV(chars, va);
        va_end(va);
#else // !defined(CSTRINGT_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CSTRINGT_MEMBER_FUNCS_IMPLEMENT) 
        return count;
    }
#endif // defined(CSTRINGT_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    //  Function: AssignV
    //
    //    Author: $author$
    //      Date: 7/29/2011
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t AssignV
    (const char_t* chars,
     va_list va)
#if defined(CSTRINGT_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CSTRINGT_MEMBER_FUNCS_INTERFACE) 
    {
        ssize_t count = 0;
#if !defined(CSTRINGT_MEMBER_FUNCS_IMPLEMENT)
        if (0 > (count = Clear()))
            return count;
        count = AppendV(chars, va);
#else // !defined(CSTRINGT_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CSTRINGT_MEMBER_FUNCS_IMPLEMENT) 
        return count;
    }
#endif // defined(CSTRINGT_MEMBER_FUNCS_INTERFACE) 

    ///////////////////////////////////////////////////////////////////////
    //  Function: AppendL
    //
    //    Author: $author$
    //      Date: 7/29/2011
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t AppendL
    (const char_t* chars,
     ...)
#if defined(CSTRINGT_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CSTRINGT_MEMBER_FUNCS_INTERFACE) 
    {
        ssize_t count = 0;
#if !defined(CSTRINGT_MEMBER_FUNCS_IMPLEMENT)
        va_list va;
        va_start(va, chars);
        count = AppendV(chars, va);
        va_end(va);
#else // !defined(CSTRINGT_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CSTRINGT_MEMBER_FUNCS_IMPLEMENT) 
        return count;
    }
#endif // defined(CSTRINGT_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    //  Function: AppendV
    //
    //    Author: $author$
    //      Date: 7/29/2011
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t AppendV
    (const char_t* chars,
     va_list va)
#if defined(CSTRINGT_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CSTRINGT_MEMBER_FUNCS_INTERFACE) 
    {
        ssize_t count = 0;
#if !defined(CSTRINGT_MEMBER_FUNCS_IMPLEMENT)
        ssize_t length = 0;
        for (count = 0; chars; count += length)
        {
            if (0 > (length = Append(chars)))

                return length;
            chars = va_arg(va, const char_t*);
        }
#else // !defined(CSTRINGT_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CSTRINGT_MEMBER_FUNCS_IMPLEMENT) 
        return count;
    }
#endif // defined(CSTRINGT_MEMBER_FUNCS_INTERFACE) 

    ///////////////////////////////////////////////////////////////////////
    //  Function: Assign_char
    //
    //    Author: $author$
    //      Date: 6/24/2011
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t Assign_char
    (const char* chars,
     ssize_t length=-1)
#if defined(CSTRINGT_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CSTRINGT_MEMBER_FUNCS_INTERFACE) 
    {
        ssize_t count = 0;
#if !defined(CSTRINGT_MEMBER_FUNCS_IMPLEMENT)
        if (0 <= (count = Clear()))
            count = Append_char(chars, length);
#else // !defined(CSTRINGT_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CSTRINGT_MEMBER_FUNCS_IMPLEMENT) 
        return count;
    }
#endif // defined(CSTRINGT_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    //  Function: Assign_wchar
    //
    //    Author: $author$
    //      Date: 6/24/2011
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t Assign_wchar
    (const wchar_t* chars,
     ssize_t length=-1)
#if defined(CSTRINGT_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CSTRINGT_MEMBER_FUNCS_INTERFACE) 
    {
        ssize_t count = 0;
#if !defined(CSTRINGT_MEMBER_FUNCS_IMPLEMENT)
        if (0 <= (count = Clear()))
            count = Append_wchar(chars, length);
#else // !defined(CSTRINGT_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CSTRINGT_MEMBER_FUNCS_IMPLEMENT) 
        return count;
    }
#endif // defined(CSTRINGT_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    //  Function: Assign_tchar
    //
    //    Author: $author$
    //      Date: 6/24/2011
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t Assign_tchar
    (const tchar_t* chars,
     ssize_t length=-1)
#if defined(CSTRINGT_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CSTRINGT_MEMBER_FUNCS_INTERFACE) 
    {
        ssize_t count = 0;
#if !defined(CSTRINGT_MEMBER_FUNCS_IMPLEMENT)
        if (0 <= (count = Clear()))
            count = Append_tchar(chars, length);
#else // !defined(CSTRINGT_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CSTRINGT_MEMBER_FUNCS_IMPLEMENT) 
        return count;
    }
#endif // defined(CSTRINGT_MEMBER_FUNCS_INTERFACE) 

    ///////////////////////////////////////////////////////////////////////
    //  Function: Append_char
    //
    //    Author: $author$
    //      Date: 6/24/2011
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t Append_char
    (const char* chars,
     ssize_t length=-1)
#if defined(CSTRINGT_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CSTRINGT_MEMBER_FUNCS_INTERFACE) 
    {
        ssize_t count = 0;
#if !defined(CSTRINGT_MEMBER_FUNCS_IMPLEMENT)
        ssize_t count2;
        char wc;
        char_t c;
        if ((chars))
        if (0 > (length))
        {
            for (; ((wc = *chars) != 0); ++chars, count += count2)
            {
                c = ((char_t)(wc));
                if (0 > (count2 = cStringT::Append(&c, 1)))
                    return count2;
            }
        }
        else
        {
            for (; (0 < length); --length, ++chars, count += count2)
            {
                c = ((char_t)(wc = *chars));
                if (0 > (count2 = cStringT::Append(&c, 1)))
                    return count2;
            }
        }
#else // !defined(CSTRINGT_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CSTRINGT_MEMBER_FUNCS_IMPLEMENT) 
        return count;
    }
#endif // defined(CSTRINGT_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    //  Function: Append_wchar
    //
    //    Author: $author$
    //      Date: 6/24/2011
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t Append_wchar
    (const wchar_t* chars,
     ssize_t length=-1)
#if defined(CSTRINGT_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CSTRINGT_MEMBER_FUNCS_INTERFACE) 
    {
        ssize_t count = 0;
#if !defined(CSTRINGT_MEMBER_FUNCS_IMPLEMENT)
        ssize_t count2;
        wchar_t wc;
        char_t c;
        if ((chars))
        if (0 > (length))
        {
            for (; ((wc = *chars) != 0); ++chars, count += count2)
            {
                c = ((char_t)(wc));
                if (0 > (count2 = cStringT::Append(&c, 1)))
                    return count2;
            }
        }
        else
        {
            for (; (0 < length); --length, ++chars, count += count2)
            {
                c = ((char_t)(wc = *chars));
                if (0 > (count2 = cStringT::Append(&c, 1)))
                    return count2;
            }
        }
#else // !defined(CSTRINGT_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CSTRINGT_MEMBER_FUNCS_IMPLEMENT) 
        return count;
    }
#endif // defined(CSTRINGT_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    //  Function: Append_tchar
    //
    //    Author: $author$
    //      Date: 6/24/2011
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t Append_tchar
    (const tchar_t* chars,
     ssize_t length=-1)
#if defined(CSTRINGT_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CSTRINGT_MEMBER_FUNCS_INTERFACE) 
    {
        ssize_t count = 0;
#if !defined(CSTRINGT_MEMBER_FUNCS_IMPLEMENT)
        ssize_t count2;
        tchar_t wc;
        char_t c;
        if ((chars))
        if (0 > (length))
        {
            for (; ((wc = *chars) != 0); ++chars, count += count2)
            {
                c = ((char_t)(wc));
                if (0 > (count2 = cStringT::Append(&c, 1)))
                    return count2;
            }
        }
        else
        {
            for (; (0 < length); --length, ++chars, count += count2)
            {
                c = ((char_t)(wc = *chars));
                if (0 > (count2 = cStringT::Append(&c, 1)))
                    return count2;
            }
        }
#else // !defined(CSTRINGT_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CSTRINGT_MEMBER_FUNCS_IMPLEMENT) 
        return count;
    }
#endif // defined(CSTRINGT_MEMBER_FUNCS_INTERFACE) 

    ///////////////////////////////////////////////////////////////////////
    //  Function: HasChars
    //
    //    Author: $author$
    //      Date: 3/20/2011
    ///////////////////////////////////////////////////////////////////////
    virtual const char_t* HasChars(ssize_t& length) const
#if defined(CSTRINGT_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CSTRINGT_MEMBER_FUNCS_INTERFACE) 
    {
        const char_t* chars = 0;
#if !defined(CSTRINGT_MEMBER_FUNCS_IMPLEMENT)
        if (0 < (length = cExtends::length()))
            chars = cExtends::c_str();
#else // !defined(CSTRINGT_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CSTRINGT_MEMBER_FUNCS_IMPLEMENT) 
        return chars;
    }
#endif // defined(CSTRINGT_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    //  Function: HasChars
    //
    //    Author: $author$
    //      Date: 3/20/2011
    ///////////////////////////////////////////////////////////////////////
    virtual const char_t* HasChars() const
#if defined(CSTRINGT_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CSTRINGT_MEMBER_FUNCS_INTERFACE) 
    {
        const char_t* chars = 0;
#if !defined(CSTRINGT_MEMBER_FUNCS_IMPLEMENT)
        if (0 < (cExtends::length()))
            chars = cExtends::c_str();
#else // !defined(CSTRINGT_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CSTRINGT_MEMBER_FUNCS_IMPLEMENT) 
        return chars;
    }
#endif // defined(CSTRINGT_MEMBER_FUNCS_INTERFACE) 

    ///////////////////////////////////////////////////////////////////////
    //  Function: Chars
    //
    //    Author: $author$
    //      Date: 3/20/2011
    ///////////////////////////////////////////////////////////////////////
    virtual const char_t* Chars(ssize_t& length) const
#if defined(CSTRINGT_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CSTRINGT_MEMBER_FUNCS_INTERFACE) 
    {
        const char_t* chars = 0;
#if !defined(CSTRINGT_MEMBER_FUNCS_IMPLEMENT)
        chars = cExtends::c_str();
        length = cExtends::length();
#else // !defined(CSTRINGT_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CSTRINGT_MEMBER_FUNCS_IMPLEMENT) 
        return chars;
    }
#endif // defined(CSTRINGT_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    //  Function: Chars
    //
    //    Author: $author$
    //      Date: 3/20/2011
    ///////////////////////////////////////////////////////////////////////
    virtual const char_t* Chars() const
#if defined(CSTRINGT_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CSTRINGT_MEMBER_FUNCS_INTERFACE) 
    {
        const char_t* chars = 0;
#if !defined(CSTRINGT_MEMBER_FUNCS_IMPLEMENT)
        chars = cExtends::c_str();
#else // !defined(CSTRINGT_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CSTRINGT_MEMBER_FUNCS_IMPLEMENT) 
        return chars;
    }
#endif // defined(CSTRINGT_MEMBER_FUNCS_INTERFACE) 

    ///////////////////////////////////////////////////////////////////////
    //  Function: Length
    //
    //    Author: $author$
    //      Date: 7/20/2011
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t Length() const
#if defined(CSTRINGT_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CSTRINGT_MEMBER_FUNCS_INTERFACE) 
    {
        ssize_t length = 0;
#if !defined(CSTRINGT_MEMBER_FUNCS_IMPLEMENT)
        length = cExtends::length();
#else // !defined(CSTRINGT_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CSTRINGT_MEMBER_FUNCS_IMPLEMENT) 
        return length;
    }
#endif // defined(CSTRINGT_MEMBER_FUNCS_INTERFACE) 

    ///////////////////////////////////////////////////////////////////////
    //  Function: operator =
    //
    //    Author: $author$
    //      Date: 8/26/2011
    ///////////////////////////////////////////////////////////////////////
    virtual cInterface& operator =
    (const char_t* chars)
#if defined(CSTRINGT_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CSTRINGT_MEMBER_FUNCS_INTERFACE) 
    {
        cInterface& self = *this;
#if !defined(CSTRINGT_MEMBER_FUNCS_IMPLEMENT)
        Assign(chars);
#else // !defined(CSTRINGT_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CSTRINGT_MEMBER_FUNCS_IMPLEMENT) 
        return self;
    }
#endif // defined(CSTRINGT_MEMBER_FUNCS_INTERFACE) 

    ///////////////////////////////////////////////////////////////////////
    //  Function: operator <<
    //
    //    Author: $author$
    //      Date: 3/20/2011
    ///////////////////////////////////////////////////////////////////////
    virtual cInterface& operator <<
    (signed value)
#if defined(CSTRINGT_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CSTRINGT_MEMBER_FUNCS_INTERFACE) 
    {
        cInterface& self = *this;
#if !defined(CSTRINGT_MEMBER_FUNCS_IMPLEMENT)
        Append(value);
#else // !defined(CSTRINGT_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CSTRINGT_MEMBER_FUNCS_IMPLEMENT) 
        return self;
    }
#endif // defined(CSTRINGT_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    //  Function: operator <<
    //
    //    Author: $author$
    //      Date: 3/20/2011
    ///////////////////////////////////////////////////////////////////////
    virtual cInterface& operator <<
    (unsigned value)
#if defined(CSTRINGT_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CSTRINGT_MEMBER_FUNCS_INTERFACE) 
    {
        cInterface& self = *this;
#if !defined(CSTRINGT_MEMBER_FUNCS_IMPLEMENT)
        Append(value);
#else // !defined(CSTRINGT_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CSTRINGT_MEMBER_FUNCS_IMPLEMENT) 
        return self;
    }
#endif // defined(CSTRINGT_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    //  Function: operator <<
    //
    //    Author: $author$
    //      Date: 3/20/2011
    ///////////////////////////////////////////////////////////////////////
    virtual cInterface& operator <<
    (const char_t* chars)
#if defined(CSTRINGT_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CSTRINGT_MEMBER_FUNCS_INTERFACE) 
    {
        cInterface& self = *this;
#if !defined(CSTRINGT_MEMBER_FUNCS_IMPLEMENT)
        Append(chars);
#else // !defined(CSTRINGT_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CSTRINGT_MEMBER_FUNCS_IMPLEMENT) 
        return self;
    }
#endif // defined(CSTRINGT_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    //  Function: operator <<
    //
    //    Author: $author$
    //      Date: 3/20/2011
    ///////////////////////////////////////////////////////////////////////
    virtual cInterface& operator <<
    (const cInterface& string)
#if defined(CSTRINGT_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CSTRINGT_MEMBER_FUNCS_INTERFACE) 
    {
        cInterface& self = *this;
#if !defined(CSTRINGT_MEMBER_FUNCS_IMPLEMENT)
        Append(string);
#else // !defined(CSTRINGT_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CSTRINGT_MEMBER_FUNCS_IMPLEMENT) 
        return self;
    }
#endif // defined(CSTRINGT_MEMBER_FUNCS_INTERFACE) 

#if !defined(CSTRINGT_MEMBERS_ONLY)
};
#undef CDB_CLASS

#if !defined(CSTRING_MEMBERS_ONLY)
///////////////////////////////////////////////////////////////////////
// Typedef: cStringExtends
//
//  Author: $author$
//    Date: 3/20/2011
///////////////////////////////////////////////////////////////////////
typedef cStringT
<cStringImplement, cStringInterface, char>
cStringExtends;
///////////////////////////////////////////////////////////////////////
//  Class: cString
//
// Author: $author$
//   Date: 6/1/2011
///////////////////////////////////////////////////////////////////////
class c_INSTANCE_CLASS cString
: public cStringExtends
{
public:
    typedef cStringExtends cExtends;
    ///////////////////////////////////////////////////////////////////////
    //  Constructor: cString
    //
    //       Author: $author$
    //         Date: 6/1/2011
    ///////////////////////////////////////////////////////////////////////
    cString
    (const wchar_t* chars,
     ssize_t length=-1)
    {
        Append(chars, length);
    }
    ///////////////////////////////////////////////////////////////////////
    //  Constructor: cString
    //
    //       Author: $author$
    //         Date: 6/1/2011
    ///////////////////////////////////////////////////////////////////////
    cString
    (const char* chars=0,
     ssize_t length=-1)
    : cExtends(chars, length)
    {
    }
    ///////////////////////////////////////////////////////////////////////
    //  Constructor: cString
    //
    //       Author: $author$
    //         Date: 6/1/2011
    ///////////////////////////////////////////////////////////////////////
    cString(signed int value)
    : cExtends(value)
    {
    }
    ///////////////////////////////////////////////////////////////////////
    //  Constructor: cString
    //
    //       Author: $author$
    //         Date: 6/1/2011
    ///////////////////////////////////////////////////////////////////////
    cString(unsigned int value)
    : cExtends(value)
    {
    }
    ///////////////////////////////////////////////////////////////////////
    //  Constructor: cString
    //
    //       Author: $author$
    //         Date: 6/1/2011
    ///////////////////////////////////////////////////////////////////////
    cString(const cExtends::cExtends& value)
    : cExtends(value)
    {
    }
    ///////////////////////////////////////////////////////////////////////
    //  Constructor: cString
    //
    //       Author: $author$
    //         Date: 6/1/2011
    ///////////////////////////////////////////////////////////////////////
    cString(const cExtends& value)
    : cExtends(value)
    {
    }
    ///////////////////////////////////////////////////////////////////////
    //  Constructor: cString
    //
    //       Author: $author$
    //         Date: 6/1/2011
    ///////////////////////////////////////////////////////////////////////
    cString(const cString& value)
    : cExtends(value)
    {
    }
#else // !defined(CSTRING_MEMBERS_ONLY) 
#endif // !defined(CSTRING_MEMBERS_ONLY) 

#if !defined(CSTRING_MEMBERS_ONLY)
// include cString member functions
//
#define xchar wchar
#define xchar_t wchar_t
#define CSTRING_MEMBERS_ONLY
#include "cString_members.hpp"
#undef CSTRING_MEMBERS_ONLY
#undef xchar_t
#undef xchar
};
#else // !defined(CSTRING_MEMBERS_ONLY) 
#endif // !defined(CSTRING_MEMBERS_ONLY) 

///////////////////////////////////////////////////////////////////////
// Typedef: cTStringExtendExtend
//
//  Author: $author$
//    Date: 7/23/2011
///////////////////////////////////////////////////////////////////////
typedef std::basic_string<tchar_t>
cTStringExtendExtend;
///////////////////////////////////////////////////////////////////////
// Typedef: cTStringExtend
//
//  Author: $author$
//    Date: 7/23/2011
///////////////////////////////////////////////////////////////////////
typedef cStringT
<cTStringImplement, cTStringInterface, 
 tchar_t, cTStringExtendExtend>
cTStringExtend;
///////////////////////////////////////////////////////////////////////
//  Class: cTString
//
// Author: $author$
//   Date: 7/23/2011
///////////////////////////////////////////////////////////////////////
class c_INSTANCE_CLASS cTString
: public cTStringExtend
{
public:
    typedef cTStringExtend cExtends;
    ///////////////////////////////////////////////////////////////////////
    //  Constructor: cTString
    //
    //       Author: $author$
    //         Date: 7/23/2011
    ///////////////////////////////////////////////////////////////////////
    cTString
    (const tchar_t* chars=0,
     ssize_t length=-1)
    : cExtends(chars, length)
    {
    }
};

#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#else // !defined(CSTRINGT_MEMBERS_ONLY) 
#endif // !defined(CSTRINGT_MEMBERS_ONLY) 

#endif // !defined(_CSTRING_HPP) || defined(CSTRINGT_MEMBERS_ONLY) 
