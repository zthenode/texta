///////////////////////////////////////////////////////////////////////
//   File: cevtolowerstringt_append.hpp
//
// Author: $author$
//   Date: 6/28/2007
//
//    $Id$
///////////////////////////////////////////////////////////////////////
        tchar tc;
        TChar c;
        if (0 > length)
        {
            for (length=0; tc=(chars[length]); length++)
            {
                if (CEV_IS_UPPER(tchar, tc))
                    c = (TChar)(CEV_TO_LOWER(tchar, tc));
                else c = (TChar)(tc);
                append(&c, 1);
            }
        }
        else if (0 < length)
        {
            for (c=*chars; length>0; --length)
            {
                if (CEV_IS_UPPER(tchar, tc))
                    c = (TChar)(CEV_TO_LOWER(tchar, tc));
                else c = (TChar)(tc);
                append(&c, 1);
            }
        }
