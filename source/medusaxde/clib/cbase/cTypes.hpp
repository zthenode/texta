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
//   File: cTypes.hpp
//
// Author: $author$
//   Date: 7/29/2011
///////////////////////////////////////////////////////////////////////
#if !defined(_CTYPES_HPP) || defined(CTYPEST_MEMBERS_ONLY)
#if !defined(_CTYPES_HPP) && !defined(CTYPEST_MEMBERS_ONLY)
#define _CTYPES_HPP
#endif // !defined(_CTYPES_HPP) && !defined(CTYPEST_MEMBERS_ONLY) 

#if !defined(CTYPEST_MEMBERS_ONLY)
#include "cInstanceBase.hpp"

#if !defined(CTYPEST_MEMBERS_virtual) 
#define CTYPEST_MEMBERS_virtual static
#else // !defined(CTYPEST_MEMBERS_virtual) 
#endif // !defined(CTYPEST_MEMBERS_virtual) 

#if !defined(CTYPEST_MEMBERS_linine) 
#define CTYPEST_MEMBERS_linine inline
#else // !defined(CTYPEST_MEMBERS_linine) 
#endif // !defined(CTYPEST_MEMBERS_linine) 

#if !defined(CTYPEST_MEMBERS_const) 
#define CTYPEST_MEMBERS_const
#else // !defined(CTYPEST_MEMBERS_const) 
#endif // !defined(CTYPEST_MEMBERS_const) 

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

#undef CDB_CLASS
#define CDB_CLASS "cTypesT"
///////////////////////////////////////////////////////////////////////
//  Class: cTypesT
//
// Author: $author$
//   Date: 7/29/2011
///////////////////////////////////////////////////////////////////////
template
<class TWhat=char,
 class TEndWhat=TWhat,
 TEndWhat VEndWhat=0>

class c_INSTANCE_CLASS cTypesT
{
public:
    typedef TWhat tWhat;
    typedef TEndWhat tEndWhat;
    enum { vEndWhat = VEndWhat };
#else // !defined(CTYPEST_MEMBERS_ONLY) 
#endif // !defined(CTYPEST_MEMBERS_ONLY) 

    ///////////////////////////////////////////////////////////////////////
    //  Function: ToInt
    //
    //    Author: $author$
    //      Date: 11/21/2012
    ///////////////////////////////////////////////////////////////////////
    CTYPEST_MEMBERS_virtual int ToInt
    (const tWhat* what,
     ssize_t length=-1, 
     tEndWhat endWhat=vEndWhat) CTYPEST_MEMBERS_const
#if defined(CTYPEST_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CTYPEST_MEMBER_FUNCS_INTERFACE) 
    {
        int value = 0;
#if !defined(CTYPEST_MEMBER_FUNCS_IMPLEMENT)
#else // !defined(CTYPEST_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CTYPEST_MEMBER_FUNCS_IMPLEMENT) 
        return value;
    }
#endif // defined(CTYPEST_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    //  Function: ToUInt
    //
    //    Author: $author$
    //      Date: 11/21/2012
    ///////////////////////////////////////////////////////////////////////
    CTYPEST_MEMBERS_virtual int ToUInt
    (const tWhat* what,
     ssize_t length=-1, 
     tEndWhat endWhat=vEndWhat) CTYPEST_MEMBERS_const
#if defined(CTYPEST_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CTYPEST_MEMBER_FUNCS_INTERFACE) 
    {
        unsigned int value = 0;
#if !defined(CTYPEST_MEMBER_FUNCS_IMPLEMENT)
        int d;
        tWhat c;

        if (what)
        if (0 > length)
        {
            while ((c = (*what++)) != endWhat)
            {
                if (0 > (d = DToInt(c)))
                    break;
                value *= 10;
                value += d;
            }
        }
        else
        {
            for (; 0 < length; --length)
            {
                if (0 > (d = DToInt(c = (*what++))))
                    break;
                value *= 10;
                value += d;
            }
        }
#else // !defined(CTYPEST_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CTYPEST_MEMBER_FUNCS_IMPLEMENT) 
        return value;
    }
#endif // defined(CTYPEST_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    //  Function: DToInt
    //
    //    Author: $author$
    //      Date: 11/21/2012
    ///////////////////////////////////////////////////////////////////////
    CTYPEST_MEMBERS_virtual int DToInt
    (tWhat d, 
     tWhat d0=(tWhat)('0'), 
     tWhat d9=(tWhat)('9')) CTYPEST_MEMBERS_const
#if defined(CTYPEST_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CTYPEST_MEMBER_FUNCS_INTERFACE) 
    {
        int value = 0;
#if !defined(CTYPEST_MEMBER_FUNCS_IMPLEMENT)
        if ((d >= d0) && (d <= d9))
            value = d - d0;
#else // !defined(CTYPEST_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CTYPEST_MEMBER_FUNCS_IMPLEMENT) 
        return value;
    }
#endif // defined(CTYPEST_MEMBER_FUNCS_INTERFACE) 

    ///////////////////////////////////////////////////////////////////////
    //  Function: FindFirst
    //
    //    Author: $author$
    //      Date: 7/29/2011
    ///////////////////////////////////////////////////////////////////////
    CTYPEST_MEMBERS_virtual const tWhat* FindFirst
    (const tWhat* what,
     const tWhat* whatFind,
     tEndWhat endWhat=vEndWhat,
     ssize_t findLength=-1,
     ssize_t length=-1) CTYPEST_MEMBERS_const
#if defined(CTYPEST_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CTYPEST_MEMBER_FUNCS_INTERFACE) 
    {
        const tWhat* found = 0;
#if !defined(CTYPEST_MEMBER_FUNCS_IMPLEMENT)
        tWhat findWhat, atWhat;
        int unequal;
        
        if ((what) && (whatFind))
        {
            if (0 > length)
            if (1 > (length = Count(what, endWhat)))
                return 0;
                
            if (0 > findLength)
            if (1 > (findLength = Count(whatFind, endWhat)))
                return 0;
                
            if (findLength < length)
            {
                for (findWhat = *whatFind, length -= (findLength-1); 
                     (0 < length); --length, what++)
                {
                    if (findWhat == (atWhat = (*what)))
                    if (!(unequal = Compare
                        (what, whatFind, findLength, endWhat)))
                    {
                        found = what;
                        break;
                    }
                    if ((0 > length) && (atWhat == (tWhat)(endWhat)))
                        break;
                }
            }
            else
            if (findLength == length)
            {
                if (!(unequal = Compare
                    (what, whatFind, findLength, endWhat)))
                    found = what;
            }
        }
#else // !defined(CTYPEST_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CTYPEST_MEMBER_FUNCS_IMPLEMENT) 
        return found;
    }
#endif // defined(CTYPEST_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    //  Function: FindLast
    //
    //    Author: $author$
    //      Date: 7/29/2011
    ///////////////////////////////////////////////////////////////////////
    CTYPEST_MEMBERS_virtual const tWhat* FindLast
    (const tWhat* what,
     const tWhat* whatFind,
     tEndWhat endWhat=vEndWhat,
     ssize_t findLength=-1,
     ssize_t length=-1) CTYPEST_MEMBERS_const
#if defined(CTYPEST_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CTYPEST_MEMBER_FUNCS_INTERFACE) 
    {
        const tWhat* found = 0;
#if !defined(CTYPEST_MEMBER_FUNCS_IMPLEMENT)
        tWhat findWhat, atWhat;
        int unequal;
        
        if ((what) && (whatFind))
        {
            if (0 > length)
                length = Count(what, endWhat);
                
            if (0 > findLength)
                findLength = Count(whatFind, endWhat);
                
            if (findLength <= length)
            {
                for (findWhat = *whatFind, 
                     what += (length -= findLength); 
                     (0 < length); --length, --what)
                {
                    if (findWhat == (atWhat = (*what)))
                    if (!(unequal = Compare
                        (what, whatFind, findLength, endWhat)))
                    {
                        found = what;
                        break;
                    }
                }
                if (!(unequal = Compare
                    (what, whatFind, findLength, endWhat)))
                    found = what;
            }
        }
#else // !defined(CTYPEST_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CTYPEST_MEMBER_FUNCS_IMPLEMENT) 
        return found;
    }
#endif // defined(CTYPEST_MEMBER_FUNCS_INTERFACE) 

    ///////////////////////////////////////////////////////////////////////
    //  Function: FindFirst
    //
    //    Author: $author$
    //      Date: 7/29/2011
    ///////////////////////////////////////////////////////////////////////
    CTYPEST_MEMBERS_virtual const tWhat* FindFirst
    (const tWhat* what,
     const tWhat& whatFind,
     tEndWhat endWhat=vEndWhat,
     ssize_t length=-1) CTYPEST_MEMBERS_const
#if defined(CTYPEST_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CTYPEST_MEMBER_FUNCS_INTERFACE) 
    {
        const tWhat* found = 0;
#if !defined(CTYPEST_MEMBER_FUNCS_IMPLEMENT)
        tWhat atWhat;
        ssize_t count;
        
        if (what)
        for (count = 0; (0 > length) || (count < length); count++, what++)
        {
            if (whatFind == (atWhat = (*what)))
            {
                found = what;
                break;
            }
            if ((0 > length) && (atWhat == (tWhat)(endWhat)))
                break;
        }
#else // !defined(CTYPEST_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CTYPEST_MEMBER_FUNCS_IMPLEMENT) 
        return found;
    }
#endif // defined(CTYPEST_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    //  Function: FindLast
    //
    //    Author: $author$
    //      Date: 7/29/2011
    ///////////////////////////////////////////////////////////////////////
    CTYPEST_MEMBERS_virtual const tWhat* FindLast
    (const tWhat* what,
     const tWhat& whatFind,
     tEndWhat endWhat=vEndWhat,
     ssize_t length=-1) CTYPEST_MEMBERS_const
#if defined(CTYPEST_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CTYPEST_MEMBER_FUNCS_INTERFACE) 
    {
        const tWhat* found = 0;
#if !defined(CTYPEST_MEMBER_FUNCS_IMPLEMENT)
        const tWhat* whatEnd;
        tWhat atWhat;
        
        if ((whatEnd = what))
        {
            if (0 <= length)
                whatEnd += length;
            else
            while (endWhat != *whatEnd)
                whatEnd++;
                
            while (whatEnd != what)
            {
                if (whatFind == (atWhat = (*--whatEnd)))
                {
                    found = whatEnd;
                    break;
                }
            }
        }
#else // !defined(CTYPEST_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CTYPEST_MEMBER_FUNCS_IMPLEMENT) 
        return found;
    }
#endif // defined(CTYPEST_MEMBER_FUNCS_INTERFACE) 

    ///////////////////////////////////////////////////////////////////////
    //  Function: Compare
    //
    //    Author: $author$
    //      Date: 7/29/2011
    ///////////////////////////////////////////////////////////////////////
    CTYPEST_MEMBERS_virtual int Compare
    (const tWhat* what,
     const tWhat* toWhat,
     ssize_t length=-1, 
     tEndWhat endWhat=vEndWhat) CTYPEST_MEMBERS_const
#if defined(CTYPEST_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CTYPEST_MEMBER_FUNCS_INTERFACE) 
    {
        int unequal = Compare
        (what, length, toWhat, length, endWhat);
#if !defined(CTYPEST_MEMBER_FUNCS_IMPLEMENT)
#else // !defined(CTYPEST_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CTYPEST_MEMBER_FUNCS_IMPLEMENT) 
        return unequal;
    }
#endif // defined(CTYPEST_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    //  Function: Compare
    //
    //    Author: $author$
    //      Date: 7/29/2011
    ///////////////////////////////////////////////////////////////////////
    CTYPEST_MEMBERS_virtual int Compare
    (const tWhat* what,
     ssize_t length,
     const tWhat* toWhat,
     ssize_t toLength=-1, 
     tEndWhat endWhat=vEndWhat) CTYPEST_MEMBERS_const
#if defined(CTYPEST_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CTYPEST_MEMBER_FUNCS_INTERFACE) 
    {
#if !defined(CTYPEST_MEMBER_FUNCS_IMPLEMENT)
        int unequal = 0;
        if (what != toWhat)
        if (what)
        {
            if (toWhat)
            {
                if (0 > length)
                    length = Count(what, endWhat);

                if (0 > toLength)
                    toLength = Count(toWhat, endWhat);

                if (length > toLength)
                {
                    unequal = 1;
                    length = toLength;
                }
                else
                if (toLength > length)
                    unequal = -1;
                else
                unequal = 0;

                for (; 0 < length; --length, what++, toWhat++)
                {
                    if (*what > *toWhat)
                        return 1;
                    else
                    if (*what < *toWhat)
                        return -1;
                }
            }
            else
            unequal = 1;
        }
        else
        unequal = -1;        
        return unequal;
#else // !defined(CTYPEST_MEMBER_FUNCS_IMPLEMENT) 
        return 1;
#endif // !defined(CTYPEST_MEMBER_FUNCS_IMPLEMENT) 
    }
#endif // defined(CTYPEST_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    //  Function: Count
    //
    //    Author: $author$
    //      Date: 7/29/2011
    ///////////////////////////////////////////////////////////////////////
    CTYPEST_MEMBERS_virtual ssize_t Count
    (const tWhat* what,
     tEndWhat endWhat=vEndWhat,
     ssize_t length=-1) CTYPEST_MEMBERS_const
#if defined(CTYPEST_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CTYPEST_MEMBER_FUNCS_INTERFACE) 
    {
        ssize_t count = 0;
#if !defined(CTYPEST_MEMBER_FUNCS_IMPLEMENT)
        if (what && ((0 > length) || (count < length)))
        while ((*what++) != (tWhat)(endWhat))
        {
            if ((0 <= length) && (count >= length))
                break;
            count++;
        }
#else // !defined(CTYPEST_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CTYPEST_MEMBER_FUNCS_IMPLEMENT) 
        return count;
    }
#endif // defined(CTYPEST_MEMBER_FUNCS_INTERFACE) 
#if !defined(CTYPEST_MEMBERS_ONLY)
};
#undef CDB_CLASS

///////////////////////////////////////////////////////////////////////
// Typedef: cChars
//
//  Author: $author$
//    Date: 7/29/2011
///////////////////////////////////////////////////////////////////////
typedef cTypesT
<char, char, 0> cChars;

///////////////////////////////////////////////////////////////////////
// Typedef: cChars
//
//  Author: $author$
//    Date: 7/29/2011
///////////////////////////////////////////////////////////////////////
typedef cTypesT
<tchar_t, tchar_t, 0> cTChars;

///////////////////////////////////////////////////////////////////////
// Typedef: cChars
//
//  Author: $author$
//    Date: 7/29/2011
///////////////////////////////////////////////////////////////////////
typedef cTypesT
<wchar_t, wchar_t, 0> cWChars;

#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#else // !defined(CTYPEST_MEMBERS_ONLY) 
#endif // !defined(CTYPEST_MEMBERS_ONLY) 

#endif // !defined(_CTYPES_HPP) || defined(CTYPEST_MEMBERS_ONLY) 
