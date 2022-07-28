///////////////////////////////////////////////////////////////////////
/// Copyright (c) 1988-2014 $organization$
///
/// This software is provided by the author and contributors ``as is'' 
/// and any express or implied warranties, including, but not limited to, 
/// the implied warranties of merchantability and fitness for a particular 
/// purpose are disclaimed. In no event shall the author or contributors 
/// be liable for any direct, indirect, incidental, special, exemplary, 
/// or consequential damages (including, but not limited to, procurement 
/// of substitute goods or services; loss of use, data, or profits; or 
/// business interruption) however caused and on any theory of liability, 
/// whether in contract, strict liability, or tort (including negligence 
/// or otherwise) arising in any way out of the use of this software, 
/// even if advised of the possibility of such damage.
///
///   File: types.hpp
///
/// Author: $author$
///   Date: 11/3/2014
///////////////////////////////////////////////////////////////////////
#if !defined(_XOS_NADIR_XOS_TYPES_HPP) || defined(XOS_TYPES_MEMBERS_ONLY)
#if !defined(_XOS_NADIR_XOS_TYPES_HPP) && !defined(XOS_TYPES_MEMBERS_ONLY)
#define _XOS_NADIR_XOS_TYPES_HPP
#endif // !defined(_XOS_NADIR_XOS_TYPES_HPP) && !defined(XOS_TYPES_MEMBERS_ONLY)

#if !defined(XOS_TYPES_MEMBERS_ONLY)
#include "xos/base/base.hpp"

#undef XOS_TYPES_EXPORT_CLASS
#define XOS_TYPES_EXPORT_CLASS _EXPORT_CLASS

#undef XOS_TYPES_MEMBERS_STATIC
#define XOS_TYPES_MEMBERS_STATIC static

#undef XOS_TYPES_MEMBERS_INLINE
#define XOS_TYPES_MEMBERS_INLINE inline

#undef XOS_TYPES_MEMBERS_CONST
#define XOS_TYPES_MEMBERS_CONST

namespace xos {
namespace base {

///////////////////////////////////////////////////////////////////////
///  Class: typest
///////////////////////////////////////////////////////////////////////
template
<class TWhat = char,
 class TEndWhat = TWhat,
 TEndWhat VEndWhat = 0,
 class TInt = int,
 class TUInt = unsigned,
 class TSize = size_t,
 class TLength = ssize_t,
 TLength VUndefinedLength = -1>

class XOS_TYPES_EXPORT_CLASS typest {
#else // !defined(XOS_TYPES_MEMBERS_ONLY)
#endif // !defined(XOS_TYPES_MEMBERS_ONLY)
public:
    typedef TWhat tWhat;
    typedef TEndWhat tEndWhat;
    typedef TInt tSigned;
    typedef TUInt tUnsigned;
    typedef TInt tInt;
    typedef TUInt tUInt;
    typedef TSize tSize;
    typedef TLength tLength;
    enum { vEndWhat = VEndWhat };
    enum { vUndefinedLength = VUndefinedLength };

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    XOS_TYPES_MEMBERS_STATIC const tWhat* find
    (const tWhat* what,
     const tWhat* whatFind,
     tEndWhat endWhat=vEndWhat,
     tLength findLength=vUndefinedLength,
     tLength length=vUndefinedLength) XOS_TYPES_MEMBERS_CONST {
        const tWhat* found = 0;
        tWhat findWhat, atWhat;
        int unequal;

        if (what && whatFind) {
            if (0 > length) {
                if (1 > (length = count(what, endWhat)))
                    return 0;
            }
            if (0 > findLength) {
                if (1 > (findLength = count(whatFind, endWhat)))
                    return 0;
            }
            if (findLength < length) {
                for (findWhat = *whatFind, length -= (findLength-1);
                     (0 < length); --length, what++) {
                    if (findWhat == (atWhat = (*what))) {
                        if (!(unequal = compare
                            (what, whatFind, findLength, endWhat))) {
                            found = what;
                            break;
                        }
                    }
                    if ((0 > length) && (atWhat == (tWhat)(endWhat)))
                        break;
                }
            }
            else {
                if (findLength == length) {
                    if (!(unequal = compare
                        (what, whatFind, findLength, endWhat)))
                        found = what;
                }
            }
        }
        return found;
    }
    XOS_TYPES_MEMBERS_STATIC const tWhat* find_reverse
    (const tWhat* what,
     const tWhat* whatFind,
     tEndWhat endWhat=vEndWhat,
     tLength findLength=vUndefinedLength,
     tLength length=vUndefinedLength) XOS_TYPES_MEMBERS_CONST {
        const tWhat* found = 0;
        tWhat findWhat, atWhat;
        int unequal;

        if (what && whatFind) {
            if (0 > length) {
                length = count(what, endWhat);
            }
            if (0 > findLength) {
                findLength = count(whatFind, endWhat);
            }
            if (findLength <= length) {
                for (findWhat = *whatFind,
                     what += (length -= findLength);
                     (0 < length); --length, --what) {
                    if (findWhat == (atWhat = (*what))) {
                        if (!(unequal = compare
                            (what, whatFind, findLength, endWhat))) {
                            found = what;
                            break;
                        }
                    }
                }
                if (!(unequal = compare
                    (what, whatFind, findLength, endWhat)))
                    found = what;
            }
        }
        return found;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    XOS_TYPES_MEMBERS_STATIC const tWhat* find_case
    (const tWhat* what,
     const tWhat* whatFind,
     tEndWhat endWhat=vEndWhat,
     tLength findLength=vUndefinedLength,
     tLength length=vUndefinedLength) XOS_TYPES_MEMBERS_CONST {
        const tWhat* found = 0;
        tWhat findWhat, atWhat;
        int unequal;

        if (what && whatFind) {
            if (0 > length) {
                if (1 > (length = count(what, endWhat)))
                    return 0;
            }
            if (0 > findLength) {
                if (1 > (findLength = count(whatFind, endWhat)))
                    return 0;
            }
            if (findLength < length) {
                for (findWhat = to_lower(*whatFind), length -= (findLength-1);
                     (0 < length); --length, what++) {
                    if (findWhat == (atWhat = to_lower(*what))) {
                        if (!(unequal = compare_case
                            (what, whatFind, findLength, endWhat))) {
                            found = what;
                            break;
                        }
                    }
                    if ((0 > length) && (atWhat == (tWhat)(endWhat)))
                        break;
                }
            }
            else {
                if (findLength == length) {
                    if (!(unequal = compare_case
                        (what, whatFind, findLength, endWhat)))
                        found = what;
                }
            }
        }
        return found;
    }
    XOS_TYPES_MEMBERS_STATIC const tWhat* find_case_reverse
    (const tWhat* what,
     const tWhat* whatFind,
     tEndWhat endWhat=vEndWhat,
     tLength findLength=vUndefinedLength,
     tLength length=vUndefinedLength) XOS_TYPES_MEMBERS_CONST {
        const tWhat* found = 0;
        tWhat findWhat, atWhat;
        int unequal;

        if (what && whatFind) {
            if (0 > length) {
                length = count(what, endWhat);
            }
            if (0 > findLength) {
                findLength = count(whatFind, endWhat);
            }
            if (findLength <= length) {
                for (findWhat = to_lower(*whatFind),
                     what += (length -= findLength);
                     (0 < length); --length, --what) {
                    if (findWhat == (atWhat = to_lower(*what))) {
                        if (!(unequal = compare_case
                            (what, whatFind, findLength, endWhat))) {
                            found = what;
                            break;
                        }
                    }
                }
                if (!(unequal = compare_case
                    (what, whatFind, findLength, endWhat)))
                    found = what;
            }
        }
        return found;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    XOS_TYPES_MEMBERS_STATIC const tWhat* find
    (const tWhat* inWhat, tWhat what,
     tLength length=vUndefinedLength,
     tEndWhat endWhat=vEndWhat) XOS_TYPES_MEMBERS_CONST {
        if (inWhat) {
            tWhat c;
            if (0 > length) {
                while ((c = (*inWhat)) != endWhat) {
                    if (c == what)
                        return inWhat;
                    ++inWhat;
                }
            } else {
                while (0 < length) {
                    if ((c = (*inWhat)) == what)
                        return inWhat;
                    ++inWhat;
                    --length;
                }
            }
        }
        return 0;
    }
    XOS_TYPES_MEMBERS_STATIC const tWhat* find_reverse
    (const tWhat* inWhat, tWhat what,
     tLength length=vUndefinedLength,
     tEndWhat endWhat=vEndWhat) XOS_TYPES_MEMBERS_CONST {
        if (inWhat) {
            const tWhat* inWhatEnd = inWhat;
            tWhat c;
            if (0 > length) {
                while ((c = (*inWhatEnd)) != endWhat) {
                    ++inWhatEnd;
                }
            } else {
                inWhatEnd += length;
            }
            while (inWhatEnd != inWhat) {
                --inWhatEnd;
                if ((c = (*inWhatEnd)) == what)
                    return inWhatEnd;
            }
        }
        return 0;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    XOS_TYPES_MEMBERS_STATIC const tWhat* find_case
    (const tWhat* inWhat, tWhat what,
     tLength length=vUndefinedLength,
     tEndWhat endWhat=vEndWhat) XOS_TYPES_MEMBERS_CONST {
        if (inWhat) {
            tWhat c;
            what = to_lower(what);
            if (0 > length) {
                while ((c = to_lower(*inWhat)) != endWhat) {
                    if (c == what)
                        return inWhat;
                    ++inWhat;
                }
            } else {
                while (0 < length) {
                    if ((c = to_lower(*inWhat)) == what)
                        return inWhat;
                    ++inWhat;
                    --length;
                }
            }
        }
        return 0;
    }
    XOS_TYPES_MEMBERS_STATIC const tWhat* find_case_reverse
    (const tWhat* inWhat, tWhat what,
     tLength length=vUndefinedLength,
     tEndWhat endWhat=vEndWhat) XOS_TYPES_MEMBERS_CONST {
        if (inWhat) {
            const tWhat* inWhatEnd = inWhat;
            tWhat c;
            what = to_lower(what);
            if (0 > length) {
                while ((c = to_lower(*inWhatEnd)) != endWhat) {
                    ++inWhatEnd;
                }
            } else {
                inWhatEnd += length;
            }
            while (inWhatEnd != inWhat) {
                --inWhatEnd;
                if ((c = to_lower(*inWhatEnd)) == what)
                    return inWhatEnd;
            }
        }
        return 0;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    XOS_TYPES_MEMBERS_STATIC tLength set
    (void* toWhat, tWhat what,
     tLength length=vUndefinedLength,
     tEndWhat endWhat=vEndWhat) XOS_TYPES_MEMBERS_CONST {
        return set((tWhat*)toWhat, what, length, endWhat);
    }
    XOS_TYPES_MEMBERS_STATIC tLength set
    (tWhat* toWhat, tWhat what,
     tLength length=vUndefinedLength,
     tEndWhat endWhat=vEndWhat) XOS_TYPES_MEMBERS_CONST {
        tLength count = 0;
        tWhat c;

        if (toWhat)
        if (0 > length) {
            // strset
            //
            while ((c = (*toWhat)) != endWhat) {
                (*toWhat++) = what;
                count++;
            }
        } else {
            // memset
            //
            while (count < length) {
                (*toWhat++) = what;
                count++;
            }
        }
        return count;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    XOS_TYPES_MEMBERS_STATIC tLength copy
    (void* toWhat, const void* what,
     tLength length=vUndefinedLength,
     tEndWhat endWhat=vEndWhat) XOS_TYPES_MEMBERS_CONST {
        return copy((tWhat*)toWhat, (const tWhat*)what, length, endWhat);
    }
    XOS_TYPES_MEMBERS_STATIC tLength copy
    (tWhat* toWhat, const tWhat* what,
     tLength length=vUndefinedLength,
     tEndWhat endWhat=vEndWhat) XOS_TYPES_MEMBERS_CONST {
        tLength count = 0;
        tWhat c;

        if (toWhat && what)
        if (0 > length) {
            // strcpy
            //
            while ((c = (*what++)) != endWhat) {
                (*toWhat++) = c;
                count++;
            }
            (*toWhat) = c;
        } else {
            // memcpy
            //
            while (count < length) {
                (*toWhat++) = (c = (*what++));
                count++;
            }
        }
        return count;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    XOS_TYPES_MEMBERS_STATIC tLength count
    (const void* what,
     tEndWhat endWhat=vEndWhat,
     tLength length=vUndefinedLength) XOS_TYPES_MEMBERS_CONST {
        return count((const tWhat*)what, endWhat, length);
    }
    XOS_TYPES_MEMBERS_STATIC tLength count
    (const tWhat* what,
     tEndWhat endWhat=vEndWhat,
     tLength length=vUndefinedLength) XOS_TYPES_MEMBERS_CONST {
        tLength count = 0;

        if (what && ((0 > length) || (count < length)))
        while ((*what++) != (tWhat)(endWhat)) {
            if ((0 <= length) && (count >= length))
                break;
            count++;
        }
        return count;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    XOS_TYPES_MEMBERS_STATIC tSize size
    (const void* what,
     tEndWhat endWhat=vEndWhat,
     tLength length=vUndefinedLength) XOS_TYPES_MEMBERS_CONST {
        return size((const tWhat*)what, endWhat, length);
    }
    XOS_TYPES_MEMBERS_STATIC tSize size
    (const tWhat* what,
     tEndWhat endWhat=vEndWhat,
     tLength length=vUndefinedLength) XOS_TYPES_MEMBERS_CONST {
        tSize size = 0;

        if (what && ((0 > length) || (size < length)))
        while ((*what++) != (tWhat)(endWhat)) {
            if ((0 <= length) && (size >= length))
                break;
            size++;
        }
        return size;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    XOS_TYPES_MEMBERS_STATIC int compare
    (const tWhat* what,
     const tWhat* toWhat,
     tLength length=vUndefinedLength,
     tEndWhat endWhat=vEndWhat) XOS_TYPES_MEMBERS_CONST {
        int unequal = compare
        (what, length, toWhat, length, endWhat);
        return unequal;
    }
    XOS_TYPES_MEMBERS_STATIC int compare
    (const tWhat* what,
     tLength length,
     const tWhat* toWhat,
     tLength toLength=vUndefinedLength,
     tEndWhat endWhat=vEndWhat) XOS_TYPES_MEMBERS_CONST {
        int unequal = 0;

        if (what != toWhat)
        if (what) {
            if (toWhat) {
                if (0 > length)
                    length = count(what, endWhat);

                if (0 > toLength)
                    toLength = count(toWhat, endWhat);

                if (length > toLength) {
                    unequal = 1;
                    length = toLength;
                }
                else
                if (toLength > length)
                    unequal = -1;
                else
                unequal = 0;

                for (; 0 < length; --length, what++, toWhat++) {
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
    }
    
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    XOS_TYPES_MEMBERS_STATIC int compare_case
    (const tWhat* what,
     const tWhat* toWhat,
     tLength length=vUndefinedLength,
     tEndWhat endWhat=vEndWhat) XOS_TYPES_MEMBERS_CONST {
        int unequal = compare_case
        (what, length, toWhat, length, endWhat);
        return unequal;
    }
    XOS_TYPES_MEMBERS_STATIC int compare_case
    (const tWhat* what,
     tLength length,
     const tWhat* toWhat,
     tLength toLength=vUndefinedLength,
     tEndWhat endWhat=vEndWhat) XOS_TYPES_MEMBERS_CONST {
        int unequal = 0;

        if (what != toWhat)
        if (what) {
            if (toWhat) {
                if (0 > length)
                    length = count(what, endWhat);

                if (0 > toLength)
                    toLength = count(toWhat, endWhat);

                if (length > toLength) {
                    unequal = 1;
                    length = toLength;
                }
                else
                if (toLength > length)
                    unequal = -1;
                else
                unequal = 0;

                for (; 0 < length; --length, what++, toWhat++) {
                    tWhat u = to_lower(*what);
                    tWhat toU = to_lower(*toWhat);
                    if (u > toU)
                        return 1;
                    else
                    if (u < toU)
                        return -1;
                }
            }
            else
            unequal = 1;
        }
        else
        unequal = -1;

        return unequal;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    XOS_TYPES_MEMBERS_STATIC int compare_uncased
    (const tWhat* what,
     const tWhat* toWhat,
     tLength length=vUndefinedLength,
     tEndWhat endWhat=vEndWhat) XOS_TYPES_MEMBERS_CONST {
        int unequal = compare_case
        (what, length, toWhat, length, endWhat);
        return unequal;
    }
    XOS_TYPES_MEMBERS_STATIC int compare_uncased
    (const tWhat* what,
     tLength length,
     const tWhat* toWhat,
     tLength toLength=vUndefinedLength,
     tEndWhat endWhat=vEndWhat) XOS_TYPES_MEMBERS_CONST {
        int unequal = compare_case
        (what, length, toWhat, toLength, endWhat);
        return unequal;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    XOS_TYPES_MEMBERS_STATIC tSigned to_signed
    (const tWhat* what,
     tLength length=vUndefinedLength,
     tEndWhat endWhat=vEndWhat) XOS_TYPES_MEMBERS_CONST {
        const TWhat c0 = (TWhat)('0');
        const TWhat c9 = (TWhat)('9');
        const TWhat minus = (TWhat)('-');
        bool negative = false;
        tSigned value = 0;
        tSize digits, amount;
        TWhat c, d;

        if ((what) && (0 > (length))) {
            length = count(what, endWhat);
        }
        if ((0 < length) && (what)) {
            for (digits = 0, amount = 0; amount < length; amount++) {
                if (((c = what[amount]) >= c0) && (c <= c9)) {
                    value = (value*10) + (tSigned)(d = (TWhat)(c - c0));
                    if ((d != 0) || digits)
                        digits++;
                } else {
                    if ((minus == c) && !(digits))
                        negative = !negative;
                }
            }
        }
        if ((value) && (negative))
            value = -value;
        return value;
    }
    XOS_TYPES_MEMBERS_STATIC tUnsigned to_unsigned
    (const tWhat* what,
     tLength length=vUndefinedLength,
     tEndWhat endWhat=vEndWhat) XOS_TYPES_MEMBERS_CONST {
        const TWhat c0 = (TWhat)('0');
        const TWhat c9 = (TWhat)('9');
        tUnsigned value = 0;
        tSize digits, amount;
        TWhat c, d;

        if ((what) && (0 > (length))) {
            length = count(what, endWhat);
        }
        if ((0 < length) && (what)) {
            for (digits = 0, amount = 0; amount < length; amount++) {
                if (((c = what[amount]) >= c0) && (c <= c9)) {
                    value = (value*10) + (tUnsigned)(d = (TWhat)(c - c0));
                    if ((d != 0) || digits)
                        digits++;
                }
            }
        }
        return value;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    XOS_TYPES_MEMBERS_STATIC XOS_TYPES_MEMBERS_INLINE tWhat to_lower(tWhat what) XOS_TYPES_MEMBERS_CONST {
        static const tWhat A = ((tWhat)'A');
        static const tWhat Z = ((tWhat)'Z');
        static const tWhat a = ((tWhat)'a');
        if ((what >= A) && (what <= Z))
            what = a + (what - A);
        return what;
    }
    XOS_TYPES_MEMBERS_STATIC XOS_TYPES_MEMBERS_INLINE tWhat to_upper(tWhat what) XOS_TYPES_MEMBERS_CONST {
        static const tWhat A = ((tWhat)'A');
        static const tWhat a = ((tWhat)'a');
        static const tWhat z = ((tWhat)'z');
        if ((what >= a) && (what <= z))
            what = A + (what - a);
        return what;
    }
#if !defined(XOS_TYPES_MEMBERS_ONLY)
};

typedef typest<char> chars_t;
typedef typest<tchar_t> tchars_t;
typedef typest<wchar_t> wchars_t;
typedef typest<unsigned char> uchars_t;

typedef typest<uint8_t> bytes_t;
typedef typest<uint16_t> words_t;

} // namespace base
} // namespace xos

#else // !defined(XOS_TYPES_MEMBERS_ONLY)
#endif // !defined(XOS_TYPES_MEMBERS_ONLY)

#endif // !defined(_XOS_NADIR_XOS_TYPES_HPP) || defined(XOS_TYPES_MEMBERS_ONLY)
