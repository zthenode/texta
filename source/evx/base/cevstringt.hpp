///////////////////////////////////////////////////////////////////////
//   File: cevstringt.hpp
//
// Author: $author$
//   Date: 4/11/2007
///////////////////////////////////////////////////////////////////////

#ifndef _CEVSTRINGT_HPP
#define _CEVSTRINGT_HPP

#include <string>
#include "evstringt.hpp"
#include "evreader.hpp"
#include "evwriter.hpp"
#include "evdebug.h"

#undef CDB_CLASS
#define CDB_CLASS "CEvStringT"
///////////////////////////////////////////////////////////////////////
//  Class: CEvStringT
//
// Author: $author$
//   Date: 4/11/2007
///////////////////////////////////////////////////////////////////////
template 
<class TChar=CHAR,
 class TSize=ULONG,
 class TLength=LONG,
 class TReader=EvReader<TChar, TSize, TLength>,
 class TWriter=EvWriter<TChar, TSize, TLength>,
 class TImplements=EvStringT<TChar, TSize, TLength>,
 class TExtends=::std::basic_string<TChar> >

class CEvStringT
: virtual public TImplements,
  public TExtends
{
public:
    typedef TImplements CImplements;
    typedef TExtends CExtends;
    typedef CEvStringT CDerives;

    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvStringT
    //
    //       Author: $author$
    //         Date: 4/13/2007
    ///////////////////////////////////////////////////////////////////////
    CEvStringT(const TChar* chars=0, TLength length=-1) 
    {
        if (chars)
            Assign(chars, length);
    }
    ///////////////////////////////////////////////////////////////////////
    // Destructor: ~CEvStringT
    //
    //      Author: $author$
    //        Date: 5/3/2007
    ///////////////////////////////////////////////////////////////////////
    virtual ~CEvStringT()
    {
    }

#if defined(EV_NO_STD_STRING_CLEAR) 
    ///////////////////////////////////////////////////////////////////////
    // Function: clear
    //
    //   Author: $author$
    //     Date: 6/7/2007
    ///////////////////////////////////////////////////////////////////////
    void clear()
    {
        assign("");
    }
#endif // defined(EV_NO_STD_STRING_CLEAR)

    ///////////////////////////////////////////////////////////////////////
    // Function: ReadLine
    //
    //   Author: $author$
    //     Date: 4/18/2007
    ///////////////////////////////////////////////////////////////////////
    virtual TLength ReadLine
    (TReader& reader, TLength length=-1) 
    {
        TLength count = -EV_ERROR_FAILED;
        TLength read;
        TChar c;

        //CDBT("() in...\n");

        (*this).clear();

        for (count = 0; (0 > length) || (count < length); count++)
        {
            if (0 < (read = reader.Read(&c, 1)))
            {
                if (c != '\n')
                {
                    if (c != '\r')
                        Append(&c, 1);
                    continue;
                }
            }
            else if (0 > read)
                    count = -EV_ERROR_READ;
            else count += read;
            break;
        }

        //CDBT("() ...out\n");
        return count;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: WriteLine
    //
    //   Author: $author$
    //     Date: 4/18/2007
    ///////////////////////////////////////////////////////////////////////
    virtual TLength WriteLine
    (TWriter& writer, TLength length=-1) 
    {
        TChar newLine = '\n';
        TLength count = -EV_ERROR_FAILED;
        TLength write;
        TLength charsLength;
        const TChar* chars;

        if ((chars = Chars(charsLength)))
        {
            if ((0 < length) && (charsLength > length))
                charsLength = length;

            if (0 < (count = writer.Write(chars, charsLength)))
            {
                if ((0 > length) || (count < length))
                if (0 > (write = writer.Write(&newLine, 1)))
                    count = -EV_ERROR_WRITE;
                else count += write;
            }
            else if (0 > count)
                    count = -EV_ERROR_WRITE;
        }
        return count;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: Read
    //
    //   Author: $author$
    //     Date: 4/30/2007
    ///////////////////////////////////////////////////////////////////////
    virtual TLength Read
    (TReader& reader, TLength length=-1) 
    {
        TLength count = -EV_ERROR_FAILED;
        TLength read;
        TChar c;

        //CDBT("() in...\n");

        (*this).clear();

        for (count = 0; (0 > length) || (count < length); count++)
        {
            if (0 < (read = reader.Read(&c, 1)))
            {
                Append(&c, 1);
                continue;
            }
            else if (0 > read)
                    count = -EV_ERROR_READ;
            else count += read;
            break;
        }
        return count;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: Write
    //
    //   Author: $author$
    //     Date: 4/20/2007
    ///////////////////////////////////////////////////////////////////////
    virtual TLength Write
    (TWriter& writer, TLength length=-1) 
    {
        TLength count = -EV_ERROR_FAILED;
        TLength charsLength;
        const TChar* chars;

        if ((chars = Chars(charsLength)))
        {
            if ((0 < length) && (charsLength > length))
                charsLength = length;

            if (0 > (count = writer.Write(chars, charsLength)))
                count = -EV_ERROR_WRITE;
        }
        return count;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: AssignSigned
    //
    //   Author: $author$
    //     Date: 5/1/2007
    ///////////////////////////////////////////////////////////////////////
    virtual TLength AssignSigned(TLength value) 
    {
        TLength length;
        (*this).clear();
        length = AppendSigned(value);
        return length;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: AppendSigned
    //
    //   Author: $author$
    //     Date: 5/1/2007
    ///////////////////////////////////////////////////////////////////////
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
    ///////////////////////////////////////////////////////////////////////
    // Function: AssignUnsigned
    //
    //   Author: $author$
    //     Date: 5/1/2007
    ///////////////////////////////////////////////////////////////////////
    virtual TLength AssignUnsigned(TSize value) 
    {
        TLength length;
        (*this).clear();
        length = AppendUnsigned(value);
        return length;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: AppendUnsigned
    //
    //   Author: $author$
    //     Date: 5/1/2007
    ///////////////////////////////////////////////////////////////////////
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

    ///////////////////////////////////////////////////////////////////////
    // Function: Assignc
    //
    //   Author: $author$
    //     Date: 5/4/2007
    ///////////////////////////////////////////////////////////////////////
    virtual TLength Assignc
    (const char* chars, TLength length=-1) 
    {
        (*this).clear();
        Appendc(chars, length);
        length = Length();
        return length;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: Appendc
    //
    //   Author: $author$
    //     Date: 5/4/2007
    ///////////////////////////////////////////////////////////////////////
    virtual TLength Appendc
    (const char* chars, TLength length=-1) 
    {
		DF(Appendc)
        TLength tell;

        if (!chars)
        {
            CDBW("() chars == 0\n");
            return 0;
        }

        if (0 <= length)
        {
            for (tell=0; tell<length; tell++)
            {
                TChar c = ((TChar)chars[tell]);
                Append(&c, 1);
            }
        }
        else
        {
            for (tell=0; chars[tell]; tell++)
            {
                TChar c = ((TChar)chars[tell]);
                Append(&c, 1);
            }
        }
        return tell;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: Assignt
    //
    //   Author: $author$
    //     Date: 5/4/2007
    ///////////////////////////////////////////////////////////////////////
    virtual TLength Assignt
    (const TCHAR* chars, TLength length=-1) 
    {
        (*this).clear();
        Appendt(chars, length);
        length = Length();
        return length;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: Appendt
    //
    //   Author: $author$
    //     Date: 5/4/2007
    ///////////////////////////////////////////////////////////////////////
    virtual TLength Appendt
    (const TCHAR* chars, TLength length=-1) 
    {
		DF(Appandt)
        TLength tell = 0;

        if (!chars)
        {
            CDBW("() chars == 0\n");
            return 0;
        }

        if (0 <= length)
        {
            for (tell=0; tell<length; tell++)
            {
                TChar c = ((TChar)chars[tell]);
                Append(&c, 1);
            }
        }
        else
        {
            for (tell=0; chars[tell]; tell++)
            {
                TChar c = ((TChar)chars[tell]);
                Append(&c, 1);
            }
        }
        return tell;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: Assignw
    //
    //   Author: $author$
    //     Date: 5/4/2007
    ///////////////////////////////////////////////////////////////////////
    virtual TLength Assignw
    (const WCHAR* chars, TLength length=-1) 
    {
        (*this).clear();
        Appendw(chars, length);
        length = Length();
        return length;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: Appendw
    //
    //   Author: $author$
    //     Date: 5/4/2007
    ///////////////////////////////////////////////////////////////////////
    virtual TLength Appendw
    (const WCHAR* chars, TLength length=-1) 
    {
		DF(Appandw)
        TLength tell;

        if (!chars)
        {
            CDBW("() chars == 0\n");
            return 0;
        }

        if (0 <= length)
        {
            for (tell=0; tell<length; tell++)
            {
                TChar c = ((TChar)chars[tell]);
                Append(&c, 1);
            }
        }
        else
        {
            for (tell=0; chars[tell]; tell++)
            {
                TChar c = ((TChar)chars[tell]);
                Append(&c, 1);
            }
        }
        return tell;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: Clear
    //
    //   Author: $author$
    //     Date: 5/7/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG Clear()
    {
        LONG length = Length();
        (*this).clear();
        return length;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: Assign
    //
    //   Author: $author$
    //     Date: 4/11/2007
    ///////////////////////////////////////////////////////////////////////
    virtual TLength Assign
    (const TChar* chars, TLength length=-1) 
    {
		DF(Assign)
        if (!chars)
        {
            CDBW("() chars == 0\n");
            return 0;
        }

        if (0 > length)
            this->assign(chars);
        else this->assign(chars, length);
        length = Length();
        return length;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: Append
    //
    //   Author: $author$
    //     Date: 4/11/2007
    ///////////////////////////////////////////////////////////////////////
    virtual TLength Append
    (const TChar* chars, TLength length=-1) 
    {
		DF(Append)
        TLength oldLength = Length();

        if (!chars)
        {
            CDBW("() chars == 0\n");
            return 0;
        }

        if (0 > length)
            this->append(chars);
        else this->append(chars, length);
        length = Length()-oldLength;
        return length;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: AssignLower
    //
    //   Author: $author$
    //     Date: 4/11/2007
    ///////////////////////////////////////////////////////////////////////
    virtual TLength AssignLower
    (const TChar* chars, TLength length=-1) 
    {
		DF(AssignLower)
        Clear();
        length = AppendLower(chars, length);
        return length;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: AppendLower
    //
    //   Author: $author$
    //     Date: 4/11/2007
    ///////////////////////////////////////////////////////////////////////
    virtual TLength AppendLower
    (const TChar* chars, TLength length=-1) 
    {
		DF(AppendLower)
        const TChar A = ((TChar)'A');
        const TChar Z = ((TChar)'Z');
        const TChar a = ((TChar)'a');
        TLength oldLength = Length();
        TLength i;
        TChar c;

        if (!chars)
        {
            CDBW("() chars == 0\n");
            return 0;
        }

        for (i = 0; length; i++)
        {
            c = chars[i];

            if (0 < length)
                --length;
            else if ((0 > length) && !c)
                    break;

            if ((c >= A) && (c <= Z))
                c = (c - A) + a;

            this->append(&c, 1);
        }
        length = Length()-oldLength;
        return length;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: AssignUpper
    //
    //   Author: $author$
    //     Date: 4/11/2007
    ///////////////////////////////////////////////////////////////////////
    virtual TLength AssignUpper
    (const TChar* chars, TLength length=-1) 
    {
		DF(AssignUpper)
        Clear();
        length = AppendUpper(chars, length);
        return length;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: AppendUpper
    //
    //   Author: $author$
    //     Date: 4/11/2007
    ///////////////////////////////////////////////////////////////////////
    virtual TLength AppendUpper
    (const TChar* chars, TLength length=-1) 
    {
		DF(AppendUpper)
        const TChar a = ((TChar)'a');
        const TChar z = ((TChar)'z');
        const TChar A = ((TChar)'A');
        TLength oldLength = Length();
        TLength i;
        TChar c;

        if (!chars)
        {
            CDBW("() chars == 0\n");
            return 0;
        }

        for (i = 0; length; i++)
        {
            c = chars[i];

            if (0 < length)
                --length;
            else if ((0 > length) && !c)
                    break;

            if ((c >= a) && (c <= z))
                c = (c - a) + A;

            this->append(&c, 1);
        }
        length = Length()-oldLength;
        return length;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: CaselessCompare
    //
    //   Author: $author$
    //     Date: 7/25/2007
    ///////////////////////////////////////////////////////////////////////
    virtual int CaselessCompare
    (const TChar* tochars, TLength tolength=-1) const
    {
		DF(CaselessCompare)
        int unequal = 0;
        TChar A = ((TChar)'A');
        TChar Z = ((TChar)'Z');
        TChar a = ((TChar)'a');
        TChar c1, c2;
        const TChar* chars;
        TLength i,length;

        if (!tochars)
        {
            CDBW("() chars == 0\n");
            return 0;
        }

        if ((chars = Chars(length)) && (0 < length))
        {
            if (0 > tolength)
            {
                for (i = 0; i < length; i++)
                {
                    if (!(c2 = tochars[i]))
                        return 1;

                    if ((c2 >= A) && (c2 <= Z))
                        c2 = (c2 - A) + a;

                    if (((c1 = chars[i]) >= A) && (c1 <= Z))
                        c1 = (c1 - A) + a;

                    if (c1 > c2) 
                        return 1;
                    else if (c1 < c2)
                            return -1;
                }
                if ((c2 = tochars[i]))
                    return -1;
            }
            else
            {
                if (length > tolength)
                {
                    unequal = 1;
                    length = tolength;
                }
                else if (length < tolength)
                        unequal = -1;

                for (i = 0; i < length; i++)
                {
                    if (((c2 = tochars[i]) >= A) && (c2 <= Z))
                        c2 = (c2 - A) + a;

                    if (((c1 = chars[i]) >= A) && (c1 <= Z))
                        c1 = (c1 - A) + a;

                    if (c1 > c2) 
                        return 1;
                    else if (c1 < c2)
                            return -1;
                }
            }
        }
        else if (chars)
                unequal = 1;
        return unequal;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: Compare
    //
    //   Author: $author$
    //     Date: 4/11/2007
    ///////////////////////////////////////////////////////////////////////
    virtual int Compare
    (const TChar* tochars, TLength tolength=-1) const
    {
		DF(Compare)
        int unequal;

        if (!tochars)
        {
            CDBW("() chars == 0\n");
            return 0;
        }

        if (0 > tolength)
            unequal = this->compare(tochars);
        else
        {
            CExtends to;
            to.assign(tochars, tolength);
            unequal = this->compare(to);
        }
        return unequal;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: HasChars
    //
    //   Author: $author$
    //     Date: 4/11/2007
    ///////////////////////////////////////////////////////////////////////
    virtual const TChar* HasChars(TLength &length) const
    {
        const TChar* chars = 0;
        if (0 < (length = (TLength)((*this).length())))
            chars = (*this).c_str();
        return chars;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: Chars
    //
    //   Author: $author$
    //     Date: 4/11/2007
    ///////////////////////////////////////////////////////////////////////
    virtual const TChar* Chars(TLength &length) const
    {
        const TChar* chars = (*this).c_str();
        length = (TLength)((*this).length());
        return chars;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: Chars
    //
    //   Author: $author$
    //     Date: 11/29/2019
    ///////////////////////////////////////////////////////////////////////
    virtual const TChar* Chars() const
    {
        const TChar* chars = (*this).c_str();
        return chars;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: Length
    //
    //   Author: $author$
    //     Date: 4/20/2007
    ///////////////////////////////////////////////////////////////////////
    virtual TLength Length() const 
    {
        return (TLength)((*this).length());
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: Signed
    //
    //   Author: $author$
    //     Date: 4/30/2007
    ///////////////////////////////////////////////////////////////////////
    virtual TLength Signed(TLength& digits) const 
    {
        bool negative = false;
        TLength value = 0;
        TLength count, length;
        const TChar* chars;
        TChar c, d;

        if (((chars = Chars(length))) && (0 < length))
        for (digits = 0, count = 0; count < length; count++)
        {
            if (((c = chars[count]) >= '0') && (c <= '9'))
            {
                value = (value*10) + (d = (c - '0'));

                if (d || digits)
                    digits++;
            }
            else if ('-' == c)
                    negative = true;
        }
        if (negative)
            return -value;
        return value;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: Unsigned
    //
    //   Author: $author$
    //     Date: 4/30/2007
    ///////////////////////////////////////////////////////////////////////
    virtual TSize Unsigned(TLength& digits) const 
    {
        TSize value = 0;
        TLength count, length;
        const TChar* chars;
        TChar c, d;

        if (((chars = Chars(length))) && (0 < length))
        for (digits = 0, count = 0; count < length; count++)
        {
            if (((c = chars[count]) >= '0') && (c <= '9'))
            {
                value = (value*10) + (d = (c - '0'));

                if (d || digits)
                    digits++;
            }
        }
        return value;
    }
};
#undef CDB_CLASS
#endif // _CEVSTRINGT_HPP
