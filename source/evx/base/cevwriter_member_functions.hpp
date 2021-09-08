///////////////////////////////////////////////////////////////////////
//   File: cevwriter_member_functions.hpp
//
// Author: $author$
//   Date: 11/6/2007
//
//    $Id$
///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    // Function: Write
    //
    //   Author: $author$
    //     Date: 4/16/2007
    ///////////////////////////////////////////////////////////////////////
    virtual TLength Write
    (const TChar* chars, TLength length) 
    {
        TLength count = -EV_ERROR_FAILED;
        return count;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: WriteSigned
    //
    //   Author: $author$
    //     Date: 7/11/2007
    ///////////////////////////////////////////////////////////////////////
    virtual TLength WriteSigned(TLength value) 
    {
        TChar c = ((TChar)('0'));
        TChar s = ((TChar)('-'));
        TLength length = 0;
        TLength count;
        TSize digits;
        TSize msdValue;

        if (0 == value)
            length = Write(&c, 1);
        else
        {
            if (0 > value)
            {
                if (0 > (length = Write(&s, 1)))
                    return length;
                value = -value;
            }
            for (digits = 0, msdValue = 0; 
                 value; value /= 10, digits++)
                msdValue = (msdValue*10) + (value%10);
            for (; msdValue; msdValue /= 10, --digits)
            {
                TChar d = c + (TChar)(msdValue%10);
                if (0 > (count = Write(&d, 1)))
                    return count;
                length += count;
            }
            for (; digits; --digits)
            {
                if (0 > (count = Write(&c, 1)))
                    return count;
                length += count;
            }
        }
        return length;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: WriteUnsigned
    //
    //   Author: $author$
    //     Date: 7/11/2007
    ///////////////////////////////////////////////////////////////////////
    virtual TLength WriteUnsigned(TSize value) 
    {
        TChar c = ((TChar)('0'));
        TLength length = 0;
        TLength count;
        TSize digits;
        TSize msdValue;

        if (0 == value)
            length = Write(&c, 1);
        else
        {
            for (digits = 0, msdValue = 0; 
                 value; value /= 10, digits++)
                msdValue = (msdValue*10) + (value%10);
            for (; msdValue; msdValue /= 10, --digits)
            {
                TChar d = c + (TChar)(msdValue%10);
                if (0 > (count = Write(&d, 1)))
                    return count;
                length += count;
            }
            for (; digits; --digits)
            {
                if (0 > (count = Write(&c, 1)))
                    return count;
                length += count;
            }
        }
        return length;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: WriteX
    //
    //   Author: $author$
    //     Date: 11/8/2007
    ///////////////////////////////////////////////////////////////////////
    virtual TLength WriteX
    (const TChar* chars, TLength length) 
    {
        TLength count, put, i;
        TChar c;

        if (0 <= length)
        {
            for (count=0, i=0; i<length; i++, count+=put)
                if (0 > (put = PutX(chars[i])))
                    return put;
        }
        else 
        for (count=0, i=0; (c=chars[i]); i++, count+=put)
            if (0 > (put = PutX(c)))
                return put;

        return count;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: PutX
    //
    //   Author: $author$
    //     Date: 10/30/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG PutX(TChar c) 
    {
        LONG count = -EV_ERROR_FAILED;
        BYTE b[sizeof(TChar)];
        unsigned i;

        for (i = sizeof(TChar); i > 0; c >>= 8)
            b[--i] = (BYTE)(c & 255);

        count = WriteBYTE2X(b, sizeof(TChar));
        return count;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: WriteUnsignedX
    //
    //   Author: $author$
    //     Date: 7/11/2007
    ///////////////////////////////////////////////////////////////////////
    virtual TLength WriteUnsignedX
    (TSize value, TSize size) 
    {
        BYTE b = 0;
        TLength length = 0;
        TLength count;
        TSize digits;
        TSize msdValue;

        for (digits = 0, msdValue = 0; 
             digits<size; value >>= 8, digits++)
            msdValue = (msdValue<<8) | (value&255);

        for (; digits>0; msdValue >>= 8, --digits)
        {
            b = (BYTE)(msdValue&255);
            if (0 > (count = WriteBYTE2X(&b, 1)))
                return count;
            length += count;
        }
        return length;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: WriteBYTE2X
    //
    //   Author: $author$
    //     Date: 11/8/2007
    ///////////////////////////////////////////////////////////////////////
    virtual TLength WriteBYTE2X
    (const BYTE* chars, TLength length) 
    {
        TLength count, put, i;
        BYTE c;

        if (0 <= length)
        {
            for (count=0, i=0; i<length; i++, count+=put)
                if (0 > (put = PutBYTE2X(chars[i])))
                    return put;
        }
        else 
        for (count=0, i=0; (c=chars[i]); i++, count+=put)
            if (0 > (put = PutBYTE2X(c)))
                return put;

        return count;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: PutBYTE2X
    //
    //   Author: $author$
    //     Date: 10/30/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG PutBYTE2X(BYTE b) 
    {
        LONG count = -EV_ERROR_FAILED;
        TChar x[2];

        x[0] = BYTE2X((b >> 4));
        x[1] = BYTE2X((b & 15));
        count = Write(x, 2);
        return count;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: BYTE2X
    //
    //   Author: $author$
    //     Date: 11/8/2007
    ///////////////////////////////////////////////////////////////////////
    virtual TChar BYTE2X(BYTE c) 
    {
        const TChar A = ((TChar)'A');
        const TChar zero = ((TChar)'0');
        TChar x;
        if ((c = (c & 15)) < 10) x = zero + c;
        else x = A + (c - 10);
        return x;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: WriteUnsignedMSB
    //
    //   Author: $author$
    //     Date: 11/27/2007
    ///////////////////////////////////////////////////////////////////////
    virtual TLength WriteUnsignedMSB
    (TSize value, TSize size) 
    {
        TChar b = 0;
        TLength length = 0;
        TLength count;
        TSize digits;
        TSize msdValue;

        for (digits = 0, msdValue = 0; 
             digits<size; value >>= 8, digits++)
            msdValue = (msdValue<<8) | (value&255);

        for (; digits>0; msdValue >>= 8, --digits)
        {
            b = (TChar)(msdValue&255);
            if (0 > (count = Write(&b, 1)))
                return count;
            length += count;
        }
        return length;
    }
