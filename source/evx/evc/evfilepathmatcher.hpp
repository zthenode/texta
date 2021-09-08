///////////////////////////////////////////////////////////////////////
//   File: evfilepathmatcher.hpp
//
// Author: $author$
//   Date: 5/21/2007
///////////////////////////////////////////////////////////////////////

#ifndef _EVFILEPATHMATCHER_HPP
#define _EVFILEPATHMATCHER_HPP

#include "evfilepath.hpp"

#define EVFILEPATH_MATCH_PATTERN_WILDCARD_CHAR '*'
#define EVFILEPATH_MATCH_PATTERN_WILDCARD "*"

#define EVFILEPATH_MATCH_PATTERN_EXTENSION_SEPARATOR_CHAR '.'
#define EVFILEPATH_MATCH_PATTERN_EXTENSION_SEPARATOR "."

///////////////////////////////////////////////////////////////////////
//  Class: EvFilePathMatcher
//
// Author: $author$
//   Date: 5/21/2007
///////////////////////////////////////////////////////////////////////
class EV_EXPORT_CLASS EvFilePathMatcher
: virtual public EvBase
{
public:
    typedef EvBase CImplements;
    typedef EvFilePathMatcher CDerives;
    ///////////////////////////////////////////////////////////////////////
    // Function: Matches
    //
    //   Author: $author$
    //     Date: 5/21/2007
    ///////////////////////////////////////////////////////////////////////
    virtual bool Matches
    (const EvFilePath& path, bool ignoreCase=false) = 0;
    ///////////////////////////////////////////////////////////////////////
    // Function: DeleteInstance
    //
    //   Author: $author$
    //     Date: 5/21/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError DeleteInstance() = 0;
};
#endif // _EVFILEPATHMATCHER_HPP
