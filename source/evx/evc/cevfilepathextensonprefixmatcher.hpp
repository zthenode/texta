///////////////////////////////////////////////////////////////////////
//   File: cevfilepathextensonprefixmatcher.hpp
//
// Author: $author$
//   Date: 9/26/2007
///////////////////////////////////////////////////////////////////////

#ifndef _CEVFILEPATHEXTENSONPREFIXMATCHER_HPP
#define _CEVFILEPATHEXTENSONPREFIXMATCHER_HPP

#include "cevfilepathmatcher.hpp"

///////////////////////////////////////////////////////////////////////
//  Class: CEvFilePathExtensionPrefixMatcher
//
// Author: $author$
//   Date: 9/26/2007
///////////////////////////////////////////////////////////////////////
class CEvFilePathExtensionPrefixMatcher
: public CEvFilePathMatcher
{
public:
    typedef CEvFilePathMatcher CExtends;
    typedef CEvFilePathExtensionPrefixMatcher CDerives;

    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvFilePathExtensionPrefixMatcher
    //
    //       Author: $author$
    //         Date: 9/26/2007
    ///////////////////////////////////////////////////////////////////////
    CEvFilePathExtensionPrefixMatcher
    (const char* chars=0, LONG length=-1)
    : CExtends(chars, length) 
    {
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: Matches
    //
    //   Author: $author$
    //     Date: 9/26/2007
    ///////////////////////////////////////////////////////////////////////
    virtual bool Matches
    (const EvFilePath& path, bool ignoreCase=false) 
    {
        bool does = false;
        const char* chars;
        const char* matchChars;
        LONG matchLength;
        LONG length;
		if ((matchChars = GetMatch(matchLength))&& (0 < matchLength))
        if ((chars = path.GetFileExtension(length)) && (matchLength <= length))
            does = MatchesChars(chars, matchLength, ignoreCase);
        return does;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: DeleteInstance
    //
    //   Author: $author$
    //     Date: 9/26/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError DeleteInstance() 
    {
        EvError error = EV_ERROR_NONE;
        delete this;
        return error;
    }
};
#endif // _CEVFILEPATHEXTENSONPREFIXMATCHER_HPP
