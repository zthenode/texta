///////////////////////////////////////////////////////////////////////
//   File: cevreader_member_functions.hpp
//
// Author: $author$
//   Date: 11/6/2007
//
//    $Id$
///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    // Function: Read
    //
    //   Author: $author$
    //     Date: 4/17/2007
    ///////////////////////////////////////////////////////////////////////
    virtual TLength Read
    (TChar* chars, TSize size) 
    {
        TLength length = -EV_ERROR_FAILED;
        return length;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: ReadSigned
    //
    //   Author: $author$
    //     Date: 4/17/2007
    ///////////////////////////////////////////////////////////////////////
    virtual TLength ReadSigned
    (TLength& value, TLength length=-1) 
    {
        const TChar d0 = ((TChar)('0'));
        const TChar d9 = ((TChar)('9'));
        const TChar minus = ((TChar)('-'));
        TLength count = -EV_ERROR_FAILED;
        TLength digits = 0;
        bool negative = false;
        TChar c;

        for (value = 0; length; digits += count)
        {
            if ((1 > (count = Read(&c, 1)))
                || ((0 > length) && !c))
                break;

            else if (0 < length)
                    --length;

            if ((d0 <= c) && (d9 >= c))
            {
                value = value*10 + (c - d0);
                digits++;
            }
            else if (digits)
                    break;
            else if (minus == c)
            {
                negative = true;
                digits++;
            }
        }

        if (negative && value)
            value = -value;

        return digits;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: ReadUnsigned
    //
    //   Author: $author$
    //     Date: 4/17/2007
    ///////////////////////////////////////////////////////////////////////
    virtual TLength ReadUnsigned
    (TSize& value, TLength length=-1) 
    {
        const TChar d0 = ((TChar)('0'));
        const TChar d9 = ((TChar)('9'));
        TLength count = -EV_ERROR_FAILED;
        TLength digits = 0;
        TChar c;

        for (value = 0; length; digits += count)
        {
            if ((1 > (count = Read(&c, 1)))
                || ((0 > length) && !c))
                break;

            else if (0 < length)
                    --length;

            if ((d0 <= c) && (d9 >= c))
            {
                value = value*10 + (c - d0);
                digits++;
            }
            else if (digits)
                    break;
        }
        return digits;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: ReadUnsignedMSB
    //
    //   Author: $author$
    //     Date: 12/7/2007
    ///////////////////////////////////////////////////////////////////////
    virtual TLength ReadUnsignedMSB
    (TSize& value, TLength length=-1) 
    {
        TLength count = -EV_ERROR_FAILED;
        TLength digits = 0;
        TChar c;

        for (value = 0; length; digits += count)
        {
            if ((1 > (count = Read(&c, 1)))
                || ((0 > length) && !c))
                break;

            else if (0 < length)
                    --length;

            value <<= 8;
            value |= (BYTE)(c);
        }
        return digits;
    }
