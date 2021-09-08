///////////////////////////////////////////////////////////////////////
//   File: cevfilematch.hpp
//
// Author: $author$
//   Date: 5/21/2007
///////////////////////////////////////////////////////////////////////

#ifndef _CEVFILEMATCH_HPP
#define _CEVFILEMATCH_HPP

#include "cevfilepathextensonprefixmatcher.hpp"
#include "cevfilepathextensionmatcher.hpp"
#include "cevfilepathfilenamematcher.hpp"
#include "cevfilepathfilebasematcher.hpp"
#include "cevfilepathanymatcher.hpp"
#include "cevfilepathmatcher.hpp"
#include "cevfilematchwriter.hpp"
#include "cevfilematchevents.hpp"
#include "evdebug.h"

///////////////////////////////////////////////////////////////////////
//  Typedef: CEvFilePathMatchers
//
//   Author: $author$
//     Date: 5/21/2007
///////////////////////////////////////////////////////////////////////
typedef ::std::vector
<EvFilePathMatcher*>
CEvFilePathMatchers;

///////////////////////////////////////////////////////////////////////
//  Typedef: CEvFilePathMatchersIterator
//
//   Author: $author$
//     Date: 5/21/2007
///////////////////////////////////////////////////////////////////////
typedef CEvFilePathMatchers::iterator
CEvFilePathMatchersIterator;

///////////////////////////////////////////////////////////////////////
//  Typedef: CEvFileMatchExtends
//
//   Author: $author$
//     Date: 6/28/2007
///////////////////////////////////////////////////////////////////////
typedef CEvFileMatchEvents<CEvBase>
CEvFileMatchExtends;

///////////////////////////////////////////////////////////////////////
//  Class: CEvFileMatch
//
// Author: $author$
//   Date: 5/21/2007
///////////////////////////////////////////////////////////////////////
class CEvFileMatch
: virtual public EvFileMatchEvents,
  public CEvFileMatchExtends
{
public:
    typedef EvFileMatchEvents CImplements;
    typedef CEvFileMatchExtends CExtends;
    typedef CEvFileMatch CDerives;

    CEvFileMatchWriter m_writer;
    CEvFilePathMatchers m_matchers;

    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvFileMatch
    //
    //       Author: $author$
    //         Date: 5/21/2007
    ///////////////////////////////////////////////////////////////////////
    CEvFileMatch() 
    : m_writer(*this)
    {
    }
    ///////////////////////////////////////////////////////////////////////
    // Destructor: ~CEvFileMatch
    //
    //      Author: $author$
    //        Date: 5/21/2007
    ///////////////////////////////////////////////////////////////////////
    virtual ~CEvFileMatch()
    {
        ClearMatchers();
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: Match
    //
    //   Author: $author$
    //     Date: 5/20/2008
    ///////////////////////////////////////////////////////////////////////
    virtual EvError Match
    (EvCharReader& reader, LONG length=-1) 
    {
        EvError error = EV_ERROR_NONE;

        ClearMatchers();
        error = MatchMore(reader, length);
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: MatchMore
    //
    //   Author: $author$
    //     Date: 8/4/2008
    ///////////////////////////////////////////////////////////////////////
    virtual EvError MatchMore
    (EvCharReader& reader, LONG length=-1) 
    {
        EvError error = EV_ERROR_NONE;
        EvError error2;
        
        if (!(error = m_writer.Initialize()))
        {
            if (0 > (length = m_writer.Write(reader, length)))
                error = -length;

            if ((error2 = m_writer.Finalize()) && !error)
                error = error2;
        }
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: Match
    //
    //   Author: $author$
    //     Date: 5/21/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError Match
    (const char* chars, LONG length=-1) 
    {
        EvError error = EV_ERROR_NONE;
        
        ClearMatchers();
        error = MatchMore(chars, length);
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: MatchMore
    //
    //   Author: $author$
    //     Date: 8/4/2008
    ///////////////////////////////////////////////////////////////////////
    virtual EvError MatchMore
    (const char* chars, LONG length=-1) 
    {
        EvError error = EV_ERROR_NONE;
        EvError error2;
        
        if (!(error = m_writer.Initialize()))
        {
            if (0 > (length = m_writer.Write(chars, length)))
                error = -length;

            if ((error2 = m_writer.Finalize()) && !error)
                error = error2;
        }
        return error;
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
        CEvFilePathMatchersIterator i;
        EvFilePathMatcher* matcher;
        for (i = m_matchers.begin(); i != m_matchers.end(); i++)
            if ((matcher = *i))
            if ((does = matcher->Matches(path, ignoreCase)))
                return does;
        return does;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: OnMatchAny
    //
    //   Author: $author$
    //     Date: 8/4/2008
    ///////////////////////////////////////////////////////////////////////
    virtual EvError OnMatchAny
    (const char* chars,
     LONG length=-1)
    { 
        EvError error = EV_ERROR_NONE;
        DBT("(\"%s\")\n", chars);
        CEvFilePathMatcher* matcher;

        if ((matcher = new CEvFilePathAnyMatcher(chars, length)))
            m_matchers.push_back(matcher);
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: OnMatchFilename
    //
    //   Author: $author$
    //     Date: 5/21/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError OnMatchFilename
    (const char* chars, LONG length=-1) 
    {
        EvError error = EV_ERROR_NONE;
        DBT("(\"%s\")\n", chars);
        CEvFilePathMatcher* matcher;

        if ((matcher = new CEvFilePathFilenameMatcher(chars, length)))
            m_matchers.push_back(matcher);
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: OnMatchFilebase
    //
    //   Author: $author$
    //     Date: 4/11/2010
    ///////////////////////////////////////////////////////////////////////
    virtual EvError OnMatchFilebase
    (const char* chars, LONG length=-1)
    {
        EvError error = EV_ERROR_NONE;
        DBT("(\"%s\")\n", chars);
        CEvFilePathMatcher* matcher;

        if ((matcher = new CEvFilePathFilebaseMatcher(chars, length)))
            m_matchers.push_back(matcher);
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: OnMatchExtension
    //
    //   Author: $author$
    //     Date: 5/21/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError OnMatchExtension
    (const char* chars, LONG length=-1) 
    {
        EvError error = EV_ERROR_NONE;
        DBT("(\"%s\")\n", chars);
        CEvFilePathMatcher* matcher;

        if ((matcher = new CEvFilePathExtensionMatcher(chars, length)))
            m_matchers.push_back(matcher);
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: OnMatchExtensionPrefix
    //
    //   Author: $author$
    //     Date: 9/26/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError OnMatchExtensionPrefix
    (const char* chars, LONG length=-1) 
    {
        EvError error = EV_ERROR_NONE;
        DBT("(\"%s\")\n", chars);
        CEvFilePathMatcher* matcher;

        if ((matcher = new CEvFilePathExtensionPrefixMatcher(chars, length)))
            m_matchers.push_back(matcher);
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: ClearMatchers
    //
    //   Author: $author$
    //     Date: 5/21/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError ClearMatchers() 
    {
        EvError error = EV_ERROR_NONE;
        CEvFilePathMatchersIterator i;
        EvFilePathMatcher* matcher;
        for (i = m_matchers.begin(); i != m_matchers.end(); i++)
            if ((matcher = *i))
                matcher->DeleteInstance();
        return error;
    }
};
#endif // _CEVFILEMATCH_HPP
