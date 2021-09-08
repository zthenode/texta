///////////////////////////////////////////////////////////////////////
//   File: cevfilepathfilebasematcher.hpp
//
// Author: $author$
//   Date: 7/2/2007
///////////////////////////////////////////////////////////////////////

#ifndef _CEVFILEPATHFILEBASEMATCHER_HPP
#define _CEVFILEPATHFILEBASEMATCHER_HPP

#include "cevfilepathmatcher.hpp"

///////////////////////////////////////////////////////////////////////
//  Class: CEvFilePathFilebaseMatcher
//
// Author: $author$
//   Date: 7/2/2007
///////////////////////////////////////////////////////////////////////
class CEvFilePathFilebaseMatcher
: public CEvFilePathMatcher
{
public:
    typedef CEvFilePathMatcher CExtends;
    typedef CEvFilePathFilebaseMatcher CDerives;

    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvFilePathFilebaseMatcher
    //
    //       Author: $author$
    //         Date: 7/2/2007
    ///////////////////////////////////////////////////////////////////////
    CEvFilePathFilebaseMatcher
    (const char* chars=0, LONG length=-1)
    : CExtends(chars, length) 
    {
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: Matches
    //
    //   Author: $author$
    //     Date: 7/2/2007
    ///////////////////////////////////////////////////////////////////////
    virtual bool Matches
    (const EvFilePath& path, bool ignoreCase=false) 
    {
        bool does = false;
        const char* chars;
        LONG length;
        if ((chars = path.GetFileBase(length)) && (0 < length))
            does = MatchesChars(chars, length, ignoreCase);
        return does;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: DeleteInstance
    //
    //   Author: $author$
    //     Date: 7/2/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError DeleteInstance() 
    {
        EvError error = EV_ERROR_NONE;
        delete this;
        return error;
    }
};

#endif // _CEVFILEPATHFILEBASEMATCHER_HPP
