/**
 **********************************************************************
 * Copyright (c) 1988-2008 $organization$
 *
 * This software is provided by the author and contributors ``as is'' 
 * and any express or implied warranties, including, but not limited to, 
 * the implied warranties of merchantability and fitness for a particular 
 * purpose are disclaimed. In no event shall the author or contributors 
 * be liable for any direct, indirect, incidental, special, exemplary, 
 * or consequential damages (including, but not limited to, procurement 
 * of substitute goods or services; loss of use, data, or profits; or 
 * business interruption) however caused and on any theory of liability, 
 * whether in contract, strict liability, or tort (including negligence 
 * or otherwise) arising in any way out of the use of this software, 
 * even if advised of the possibility of such damage.
 *
 *   File: cstringctring.hxx
 *
 * Author: $author$
 *   Date: 11/9/2008
 **********************************************************************
 */
#ifndef _CSTRING_HXX
#define _CSTRING_HXX

#include <string>
#include "cstringinterface.hxx"
#include "cdebug.hxx"

/**
 **********************************************************************
 * Typedef: cStringExtends
 *
 *  Author: $author$
 *    Date: 1/7/2008
 **********************************************************************
 */
typedef std::basic_string<CHAR>
cStringExtends;

/**
 **********************************************************************
 *  Class: cStringT
 *
 * Author: $author$
 *   Date: 1/7/2008
 **********************************************************************
 */
template
<class TChar=CHAR, 
 class TSize=TSIZE,
 class TLength=TLENGTH,
 TLength VUndefinedLength=UNDEFINED_LENGTH,
 class TNullChar=TChar,
 TNullChar VNullChar=NULL_CHAR,
 class TStreamInterface=cStreamInterface,
 class TImplements=cStringImplement,
 class TExtends=cStringExtends>
 
class cStringT
: virtual public TImplements,
  public TExtends
{
public:
    typedef TImplements cImplements;
    typedef TExtends cExtends;
    typedef cStringT cDerives;

    TSize m_tell;

    /**
     **********************************************************************
     * Constructor: cStringT
     *
     *      Author: $author$
     *        Date: 1/7/2008
     **********************************************************************
     */
    cStringT
    (const TChar* chars=0,
     TLength length=VUndefinedLength) 
    : m_tell(0)
    {
        eError error;
        if (chars)
        if (0 > (length = Append(chars, length)))
            throw(error = -length);
    }
    /**
     **********************************************************************
     * Destructor: cStringT
     *
     *     Author: $author$
     *       Date: 1/7/2008
     **********************************************************************
     */
    virtual ~cStringT()
    {
    }

    /**
     **********************************************************************
     * Function: Read
     *
     *   Author: $author$
     *     Date: 1/7/2008
     **********************************************************************
     */
    virtual TLength Read
    (TChar* chars, TSize size) 
    {
        TLength count = -e_ERROR_NOT_IMPLEMENTED;
        TSize length;
        TSize told;
        const TChar* thisChars;

        if (!(thisChars = this->HasChars(count)))
            return count;

        if (m_tell >= (length = (TSize)(count)))
            return 0;

        if (length < (told = m_tell+size))
            count = (TLength)((told = length) - m_tell);
        else count = (TLength)(size);

        if (0 <= (count = this->CopyTo
            (chars, thisChars+m_tell, count)))
            m_tell = told;
        return count;
    }

    /**
     **********************************************************************
     * Function: AssignSigned
     *
     *   Author: $author$
     *     Date: 8/1/2008
     **********************************************************************
     */
    virtual TLength AssignSigned(TLength value) 
    {
        TLength length = 0;
        if (0 > (length = Clear()))
            return length;
        length = AppendSigned(value);
        return length;
    }
    /**
     **********************************************************************
     * Function: AssignUnsigned
     *
     *   Author: $author$
     *     Date: 8/1/2008
     **********************************************************************
     */
    virtual TLength AssignUnsigned(TLength value) 
    {
        TLength length = 0;
        if (0 > (length = Clear()))
            return length;
        length = AppendUnsigned(value);
        return length;
    }
    /**
     **********************************************************************
     * Function: AssignUpper
     *
     *   Author: $author$
     *     Date: 8/1/2008
     **********************************************************************
     */
    virtual TLength AssignUpper
    (const TChar* chars,
     TLength length=VUndefinedLength) 
    {
        TLength llength = 0;
        if (0 > (llength = Clear()))
            return llength;
        length = AppendUpper(chars, length);
        return length;
    }
    /**
     **********************************************************************
     * Function: AssignLower
     *
     *   Author: $author$
     *     Date: 8/1/2008
     **********************************************************************
     */
    virtual TLength AssignLower
    (const TChar* chars,
     TLength length=VUndefinedLength) 
    {
        TLength llength = 0;
        if (0 > (llength = Clear()))
            return llength;
        length = AppendLower(chars, length);
        return length;
    }

    /**
     **********************************************************************
     * Function: AppendSigned
     *
     *   Author: $author$
     *     Date: 1/7/2008
     **********************************************************************
     */
    virtual TLength AppendSigned(TLength value) 
    {
        TChar c = ((TChar)('0'));
        TChar s = ((TChar)('-'));
        TLength length = 0;
        TSize digits;
        TSize msdValue;

        if (0 == value)
            length = Append(&c, 1);
        else
        {
            if (0 > value)
            {
                length = Append(&s, 1);
                value = -value;
            }
            for (digits = 0, msdValue = 0; 
                 value; value /= 10, digits++)
                msdValue = (msdValue*10) + (value%10);
            for (; msdValue; msdValue /= 10, --digits)
            {
                TChar d = c + (TChar)(msdValue%10);
                length += Append(&d, 1);
            }
            for (; digits; --digits)
                length += Append(&c, 1);
        }
        return length;
    }
    /**
     **********************************************************************
     * Function: AppendUnsigned
     *
     *   Author: $author$
     *     Date: 1/7/2008
     **********************************************************************
     */
    virtual TLength AppendUnsigned(TSize value) 
    {
        TChar c = ((TChar)('0'));
        TLength length = 0;
        TSize digits;
        TSize msdValue;

        if (0 == value)
            length = Append(&c, 1);
        else
        {
            for (digits = 0, msdValue = 0; 
                 value; value /= 10, digits++)
                msdValue = (msdValue*10) + (value%10);
            for (; msdValue; msdValue /= 10, --digits)
            {
                TChar d = c + (TChar)(msdValue%10);
                length += Append(&d, 1);
            }
            for (; digits; --digits)
                length += Append(&c, 1);
        }
        return length;
    }
    /**
     **********************************************************************
     * Function: AppendUpper
     *
     *   Author: $author$
     *     Date: 1/7/2008
     **********************************************************************
     */
    virtual TLength AppendUpper
    (const TChar* chars,
     TLength length=VUndefinedLength) 
    {
		DF(AppendUpper)
        const TChar a = ((TChar)'a');
        const TChar z = ((TChar)'z');
        const TChar A = ((TChar)'A');
        TLength oldLength = Length();
        TLength i;
        TChar c;

        if (chars)
        for (i = 0; length; i++)
        {
            c = chars[i];

            if (0 < length)
                --length;
            else if ((0 > length) && !c)
                    break;

            if ((c >= a) && (c <= z))
                c = A + (c - a);

            this->append(&c, 1);
        }
        length = Length()-oldLength;
        return length;
    }
    /**
     **********************************************************************
     * Function: AppendLower
     *
     *   Author: $author$
     *     Date: 1/7/2008
     **********************************************************************
     */
    virtual TLength AppendLower
    (const TChar* chars,
     TLength length=VUndefinedLength) 
    {
		DF(AppendLower)
        const TChar A = ((TChar)'A');
        const TChar Z = ((TChar)'Z');
        const TChar a = ((TChar)'a');
        TLength oldLength = Length();
        TLength i;
        TChar c;

        if (chars)
        for (i = 0; length; i++)
        {
            c = chars[i];

            if (0 < length)
                --length;
            else if ((0 > length) && !c)
                    break;

            if ((c >= A) && (c <= Z))
                c = a + (c - A);

            this->append(&c, 1);
        }
        length = Length()-oldLength;
        return length;
    }

    /**
     **********************************************************************
     * Function: Assign
     *
     *   Author: $author$
     *     Date: 9/5/2008
     **********************************************************************
     */
    virtual TLength Assign
    (const TChar* chars,
     TLength length=VUndefinedLength) 
    {
        TLength count = AssignChars(chars, length);
        return count;
    }
    /**
     **********************************************************************
     * Function: Append
     *
     *   Author: $author$
     *     Date: 1/7/2008
     **********************************************************************
     */
    virtual TLength Append
    (const TChar* chars,
     TLength length=VUndefinedLength) 
    {
        TLength count = AppendChars(chars, length);
        return count;
    }
    /**
     **********************************************************************
     * Function: Clear
     *
     *   Author: $author$
     *     Date: 1/7/2008
     **********************************************************************
     */
    virtual TLength Clear() 
    {
        TLength count = ClearChars();
        return count;
    }

    /**
     **********************************************************************
     * Function: AssignChars
     *
     *   Author: $author$
     *     Date: 9/5/2008
     **********************************************************************
     */
    virtual TLength AssignChars
    (const TChar* chars,
     TLength length=VUndefinedLength) 
    {
        TLength count = 0;
        if (!chars)
        {
            if (0 > (count = Clear()))
                return count;
            return 0;
        }
        if (0 > length)
        if (0 > (length = this->LengthOf(chars)))
            return length;
        this->assign(chars, length);
        count = length;
        m_tell = 0;
        return count;
    }
    /**
     **********************************************************************
     * Function: AppendChars
     *
     *   Author: $author$
     *     Date: 9/5/2008
     **********************************************************************
     */
    virtual TLength AppendChars
    (const TChar* chars,
     TLength length=VUndefinedLength) 
    {
        TLength count = 0;
        if (!chars)
            return 0;
        if (0 > length)
        if (0 > (length = this->LengthOf(chars)))
            return length;
        this->append(chars, length);
        count = length;
        return count;
    }
    /**
     **********************************************************************
     * Function: ClearChars
     *
     *   Author: $author$
     *     Date: 9/5/2008
     **********************************************************************
     */
    virtual TLength ClearChars() 
    {
        TLength count = Length();
        CTHIS clear();
        m_tell = 0;
        return count;
    }

    /**
     **********************************************************************
     * Function: Length
     *
     *   Author: $author$
     *     Date: 1/7/2008
     **********************************************************************
     */
    virtual TLength Length() const 
    {
        TLength count = (TLength)(CTHIS length());
        return count;
    }
    /**
     **********************************************************************
     * Function: Signed
     *
     *   Author: $author$
     *     Date: 1/7/2008
     **********************************************************************
     */
    virtual TLength Signed(TLength& digits) const 
    {
        const TChar c0 = (TChar)('0');
        const TChar c9 = (TChar)('9');
        const TChar minus = (TChar)('-');
        bool negative = false;
        TLength value = 0;
        TLength count, length;
        const TChar* chars;
        TChar c, d;

        if (((chars = Chars(length))) && (0 < length))
        for (digits = 0, count = 0; count < length; count++)
        {
            if (((c = chars[count]) >= c0) && (c <= c9))
            {
                value = (value*10) + (TLength)(d = (TChar)(c - c0));

                if ((d != 0) || digits)
                    digits++;
            }
            else if (minus == c)
                    negative = true;
        }
        if (negative)
            return -value;
        return value;
    }
    /**
     **********************************************************************
     * Function: Unsigned
     *
     *   Author: $author$
     *     Date: 1/7/2008
     **********************************************************************
     */
    virtual TSize Unsigned(TLength& digits) const 
    {
        const TChar c0 = (TChar)('0');
        const TChar c9 = (TChar)('9');
        TSize value = 0;
        TLength count, length;
        const TChar* chars;
        TChar c, d;

        if (((chars = Chars(length))) && (0 < length))
        for (digits = 0, count = 0; count < length; count++)
        {
            if (((c = chars[count]) >= c0) && (c <= c9))
            {
                value = (value*10) + (TLength)(d = (TChar)(c - c0));

                if ((d != 0) || digits)
                    digits++;
            }
        }
        return value;
    }
    /**
     **********************************************************************
     * Function: Chars
     *
     *   Author: $author$
     *     Date: 1/7/2008
     **********************************************************************
     */
    virtual const TChar* Chars
    (TLength& length) const 
    {
        const TChar* chars = CTHIS c_str();
        length = Length();
        return chars;
    }
    /**
     **********************************************************************
     * Function: Compare
     *
     *   Author: $author$
     *     Date: 1/7/2008
     **********************************************************************
     */
    virtual int Compare
    (const TChar* chars,
     TLength length=VUndefinedLength) const
    {
        int unequal = -e_ERROR_FAILED-1;
        if (chars)
        if (0 > length)
            unequal = this->compare(chars);
        else
        {
            cExtends to;
            to.assign(chars, length);
            unequal = this->compare(to);
        }
        return unequal;
    }
#if defined(NO_STD_STRING_CLEAR) 
    /**
     **********************************************************************
     * Function: clear
     *
     *   Author: $author$
     *     Date: 1/7/2008
     **********************************************************************
     */
    void clear() 
    {
        assign("");
    }
#endif /* defined(NO_STD_STRING_CLEAR) */
};

/**
 **********************************************************************
 * Typedef: cString
 *
 *  Author: $author$
 *    Date: 1/7/2008
 **********************************************************************
 */
typedef cStringT
<CHAR, TSIZE, TLENGTH, UNDEFINED_LENGTH, 
 CHAR, NULL_CHAR, 
 cStreamInterface, cStringImplement, cStringExtends>
cCHARString,
cString;

/**
 **********************************************************************
 * Typedef: cCharStringExtends
 *
 *  Author: $author$
 *    Date: 1/7/2008
 **********************************************************************
 */
typedef std::basic_string<char>
cCharStringExtends;

/**
 **********************************************************************
 * Typedef: cCharString
 *
 *  Author: $author$
 *    Date: 1/7/2008
 **********************************************************************
 */
typedef cStringT
<char, TSIZE, TLENGTH, UNDEFINED_LENGTH, 
 char, 0, 
 cCharStreamInterface, cCharStringImplement, cCharStringExtends>
cCharString;

/**
 **********************************************************************
 * Typedef: cTStringExtends
 *
 *  Author: $author$
 *    Date: 1/7/2008
 **********************************************************************
 */
typedef std::basic_string<TCHAR>
cTStringExtends;

/**
 **********************************************************************
 * Typedef: cTString
 *
 *  Author: $author$
 *    Date: 1/7/2008
 **********************************************************************
 */
typedef cStringT
<TCHAR, TSIZE, TLENGTH, UNDEFINED_LENGTH, 
 TCHAR, NULL_TCHAR, 
 cTCHARStreamInterface, cTStringImplement, cTStringExtends>
cTCHARString,
cTString;

/**
 **********************************************************************
 * Typedef: cWStringExtends
 *
 *  Author: $author$
 *    Date: 1/7/2008
 **********************************************************************
 */
typedef std::basic_string<WCHAR>
cWStringExtends;

/**
 **********************************************************************
 * Typedef: cWString
 *
 *  Author: $author$
 *    Date: 1/7/2008
 **********************************************************************
 */
typedef cStringT
<WCHAR, TSIZE, TLENGTH, UNDEFINED_LENGTH, 
 WCHAR, NULL_WCHAR, 
 cWCHARStreamInterface, cWStringImplement, cWStringExtends>
cWCHARString,
cWString;

/**
 **********************************************************************
 * Typedef: cBYTEStringExtends
 *
 *  Author: $author$
 *    Date: 1/7/2008
 **********************************************************************
 */
typedef std::basic_string<BYTE>
cBYTEStringExtends;

/**
 **********************************************************************
 * Typedef: cBYTEString
 *
 *  Author: $author$
 *    Date: 1/7/2008
 **********************************************************************
 */
typedef cStringT
<BYTE, TSIZE, TLENGTH, UNDEFINED_LENGTH, 
 BYTE, 0, 
 cBYTEStreamInterface, cBYTEStringImplement, cBYTEStringExtends>
cBYTEString;

#endif /* _CSTRING_HXX */
