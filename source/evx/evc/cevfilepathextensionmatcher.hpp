///////////////////////////////////////////////////////////////////////
//   File: cevfilepathextensonmatcher.hpp
//
// Author: $author$
//   Date: 5/21/2007
///////////////////////////////////////////////////////////////////////

#ifndef _CEVFILEPATHEXTENSIONMATCHER_HPP
#define _CEVFILEPATHEXTENSIONMATCHER_HPP

#include "cevfilepathmatcher.hpp"

///////////////////////////////////////////////////////////////////////
//  Class: CEvFilePathExtensionMatcher
//
// Author: $author$
//   Date: 5/21/2007
///////////////////////////////////////////////////////////////////////
class CEvFilePathExtensionMatcher
: public CEvFilePathMatcher
{
public:
    typedef CEvFilePathMatcher CExtends;
    typedef CEvFilePathExtensionMatcher CDerives;
    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvFilePathExtensionMatcher
    //
    //       Author: $author$
    //         Date: 5/21/2007
    ///////////////////////////////////////////////////////////////////////
    CEvFilePathExtensionMatcher
    (const char* chars=0, LONG length=-1)
    : CExtends(chars, length) 
    {
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: Matches
    //
    //   Author: $author$
    //     Date: 5/21/2007
    ///////////////////////////////////////////////////////////////////////
    virtual bool Matches
    (const EvFilePath& path, bool ignoreCase=false) 
    {
        bool does = false;
        const char* chars;
        LONG length;
        if ((chars = path.GetFileExtension(length)) && (0 < length))
            does = MatchesChars(chars, length, ignoreCase);
        return does;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: DeleteInstance
    //
    //   Author: $author$
    //     Date: 5/21/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError DeleteInstance() 
    {
        EvError error = EV_ERROR_NONE;
        delete this;
        return error;
    }
};
#endif // _CEVFILEPATHEXTENSIONMATCHER_HPP
