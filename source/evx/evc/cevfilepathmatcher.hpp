///////////////////////////////////////////////////////////////////////
//   File: cevfilepathmatcher.hpp
//
// Author: $author$
//   Date: 5/21/2007
//
//    $Id$
///////////////////////////////////////////////////////////////////////

#ifndef _CEVFILEPATHMATCHER_HPP
#define _CEVFILEPATHMATCHER_HPP

#include "evfilepathmatcher.hpp"
#include "cevstring.hpp"
#include "cevbase.hpp"

///////////////////////////////////////////////////////////////////////
//  Class: CEvFilePathMatcher
//
// Author: $author$
//   Date: 5/21/2007
///////////////////////////////////////////////////////////////////////
class CEvFilePathMatcher
: virtual public EvFilePathMatcher,
  public CEvBase
{
public:
    typedef EvFilePathMatcher CImplements;
    typedef CEvBase CExtends;
    typedef CEvFilePathMatcher CDerives;

    CEvString m_pattern;

    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvFilePathMatcher
    //
    //       Author: $author$
    //         Date: 5/21/2007
    ///////////////////////////////////////////////////////////////////////
    CEvFilePathMatcher
    (const char* chars=0, LONG length=-1) 
    {
        EvError error;
        if (chars)
        if (0 > (length = m_pattern.Assign(chars, length)))
            throw(error = -length);
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
        return does;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: MatchesChars
    //
    //   Author: $author$
    //     Date: 7/25/2007
    ///////////////////////////////////////////////////////////////////////
    virtual bool MatchesChars
    (const char* chars, 
     LONG length=-1, 
     bool ignoreCase=false) 
    {
        bool does = false;
        int unequal;
        if (0 < m_pattern.Length())
        {
            if (ignoreCase)
                unequal = m_pattern.CaselessCompare(chars, length);
            else unequal = m_pattern.Compare(chars, length);
            does = !unequal;
        }
        return does;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: SetMatch
    //
    //   Author: $author$
    //     Date: 5/21/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG SetMatch
    (const char* chars,
     LONG length=-1) 
    {
        length = m_pattern.Assign(chars,length);
        return length;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: GetMatch
    //
    //   Author: $author$
    //     Date: 5/21/2007
    ///////////////////////////////////////////////////////////////////////
    virtual const char* GetMatch
    (LONG& length) const 
    {
        const char* chars = m_pattern.Chars(length);
        return chars;
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
#endif // _CEVFILEPATHMATCHER_HPP
