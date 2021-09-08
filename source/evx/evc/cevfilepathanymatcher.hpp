///////////////////////////////////////////////////////////////////////
//   File: cevfilepathanymatcher.hpp
//
// Author: $author$
//   Date: 8/4/2008
///////////////////////////////////////////////////////////////////////
#ifndef _CEVFILEPATHANYMATCHER_HPP
#define _CEVFILEPATHANYMATCHER_HPP

#include "cevfilepathmatcher.hpp"

///////////////////////////////////////////////////////////////////////
//  Class: CEvFilePathAnyMatcher
//
// Author: $author$
//   Date: 8/4/2008
///////////////////////////////////////////////////////////////////////
class CEvFilePathAnyMatcher
: public CEvFilePathMatcher
{
public:
    typedef CEvFilePathMatcher CExtends;
    typedef CEvFilePathAnyMatcher CDerives;
    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvFilePathAnyMatcher
    //
    //       Author: $author$
    //         Date: 8/4/2008
    ///////////////////////////////////////////////////////////////////////
    CEvFilePathAnyMatcher
    (const char* chars=0, LONG length=-1)
    : CExtends(chars, length) 
    {
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: Matches
    //
    //   Author: $author$
    //     Date: 8/4/2008
    ///////////////////////////////////////////////////////////////////////
    virtual bool Matches
    (const EvFilePath& path, bool ignoreCase=false) 
    {
        bool does = true;
        return does;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: DeleteInstance
    //
    //   Author: $author$
    //     Date: 8/4/2008
    ///////////////////////////////////////////////////////////////////////
    virtual EvError DeleteInstance() 
    {
        EvError error = EV_ERROR_NONE;
        delete this;
        return error;
    }
};
#endif // _CEVFILEPATHANYMATCHER_HPP
