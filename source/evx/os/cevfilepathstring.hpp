///////////////////////////////////////////////////////////////////////
//   File: cevfilepathstring.hpp
//
// Author: $author$
//   Date: 5/9/2007
///////////////////////////////////////////////////////////////////////

#ifndef _CEVFILEPATHSTRING_HPP
#define _CEVFILEPATHSTRING_HPP

#include "evplatform_directory.h"
#include "cevstring.hpp"

///////////////////////////////////////////////////////////////////////
//  Class: CEvFilePathString
//
// Author: $author$
//   Date: 5/9/2007
///////////////////////////////////////////////////////////////////////
class CEvFilePathString
: public CEvString
{
public:
    typedef CEvString CExtends;
    typedef CEvFilePathString CDerives;

    static const char m_foriegnSeparator;
    static const char m_nativeSeparator;
    static const char m_normalSeparator;

    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvFilePathString
    //
    //       Author: $author$
    //         Date: 5/9/2007
    ///////////////////////////////////////////////////////////////////////
    CEvFilePathString
    (const char* chars=0, LONG length=-1) 
    {
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: Assign
    //
    //   Author: $author$
    //     Date: 5/9/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG Assign
    (const char* chars,
     LONG length=-1) 
    {
        length = NormalAssign(chars, length);
        return length;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: RawAssign
    //
    //   Author: $author$
    //     Date: 5/9/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG RawAssign
    (const char* chars,
     LONG length=-1) 
    {
        length = CExtends::Assign(chars, length);
        return length;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: NativeAssign
    //
    //   Author: $author$
    //     Date: 5/9/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG NativeAssign
    (const char* chars,
     LONG length=-1) 
    {
        CExtends::Clear();
        length = NativeAppend(chars, length);
        return length;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: NormalAssign
    //
    //   Author: $author$
    //     Date: 5/9/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG NormalAssign
    (const char* chars,
     LONG length=-1) 
    {
        CExtends::Clear();
        length = NormalAppend(chars, length);
        return length;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: Append
    //
    //   Author: $author$
    //     Date: 5/9/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG Append
    (const char* chars,
     LONG length=-1) 
    {
        length = NormalAppend(chars, length);
        return length;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: RawAppend
    //
    //   Author: $author$
    //     Date: 5/9/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG RawAppend
    (const char* chars,
     LONG length=-1) 
    {
        length = CExtends::Append(chars, length);
        return length;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: NativeAppend
    //
    //   Author: $author$
    //     Date: 5/9/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG NativeAppend
    (const char* chars,
     LONG length=-1) 
    {
        length = ConvertAppend
        (FOREIGN_DIRECTORY_SEPARATOR_CHAR, 
         NATIVE_DIRECTORY_SEPARATOR_CHAR,
         NATIVE_DIRECTORY_SEPARATOR_CHAR,
         chars, length);
        return length;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: NormalAppend
    //
    //   Author: $author$
    //     Date: 5/9/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG NormalAppend
    (const char* chars,
     LONG length=-1) 
    {
        length = ConvertAppend
        (FOREIGN_DIRECTORY_SEPARATOR_CHAR, 
         NATIVE_DIRECTORY_SEPARATOR_CHAR,
         NORMAL_DIRECTORY_SEPARATOR_CHAR,
         chars, length);
        return length;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: ConvertAppend
    //
    //   Author: $author$
    //     Date: 5/9/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG ConvertAppend
    (char foriegn, char native, char normal,
     const char* chars, LONG length=-1) 
    {
        LONG tell = -EV_ERROR_FAILED;
        char c;

        if (0 <= length)
        {
            for (tell=0; tell<length; tell++)
            {
                if ((foriegn == (c = chars[tell]))
                    || (native == c))
                    c = normal;
                RawAppend(&c, 1);
            }
        }
        else
        {
            for (tell=0; chars[tell]; tell++)
            {
                if ((foriegn == (c = chars[tell]))
                    || (native == c))
                    c = normal;
                RawAppend(&c, 1);
            }
        }
        return tell;
    }
};
#endif // _CEVFILEPATHSTRING_HPP
