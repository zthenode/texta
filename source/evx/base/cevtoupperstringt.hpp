///////////////////////////////////////////////////////////////////////
//   File: cevtoupperstringt.hpp
//
// Author: $author$
//   Date: 6/28/2007
//
//    $Id$
///////////////////////////////////////////////////////////////////////

#ifndef _CEVTOUPPERSTRINGT_HPP
#define _CEVTOUPPERSTRINGT_HPP

#include "cevstring.hpp"

#define CEV_IS_LOWER(tchar, c) \
    ((c >= ((tchar)'c')) && (c <= ((tchar)'z')))

#define CEV_TO_UPPER(tchar, c) \
    ((c - ((tchar)'a')) + ((tchar)'A'))

///////////////////////////////////////////////////////////////////////
//  Class: CEvToUpperStringT
//
// Author: $author$
//   Date: 6/28/2007
///////////////////////////////////////////////////////////////////////
template
<class TExtends=CEvString,
 class TImplements=EvString,
 class TChar=CHAR,
 class TSize=ULONG,
 class TLength=LONG>

class CEvToUpperStringT
: virtual public TImplements,
  public TExtends
{
public:
    typedef TImplements CImplements;
    typedef TExtends CExtends;
    typedef CEvToUpperStringT CDerives;
    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvToUpperStringT
    //
    //       Author: $author$
    //         Date: 6/28/2007
    ///////////////////////////////////////////////////////////////////////
    CEvToUpperStringT
    (const CHAR* chars,
     LONG length=-1) 
    {
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: Append
    //
    //   Author: $author$
    //     Date: 6/28/2007
    ///////////////////////////////////////////////////////////////////////
    virtual TLength Append
    (const TChar* chars,
     LONG length=-1) 
    {
        typedef TChar tchar;
#include "cevtoupperstringt_append.hpp"
        return length;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: Appendc
    //
    //   Author: $author$
    //     Date: 6/28/2007
    ///////////////////////////////////////////////////////////////////////
    virtual TLength Appendc
    (const CHAR* chars,
     LONG length=-1) 
    {
        typedef CHAR tchar;
#include "cevtoupperstringt_append.hpp"
        return length;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: Appendt
    //
    //   Author: $author$
    //     Date: 6/28/2007
    ///////////////////////////////////////////////////////////////////////
    virtual TLength Appendt
    (const CHAR* chars,
     LONG length=-1) 
    {
        typedef TCHAR tchar;
#include "cevtoupperstringt_append.hpp"
        return length;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: Appendw
    //
    //   Author: $author$
    //     Date: 6/28/2007
    ///////////////////////////////////////////////////////////////////////
    virtual TLength Appendw
    (const CHAR* chars,
     LONG length=-1) 
    {
        typedef WCHAR tchar;
#include "cevtoupperstringt_append.hpp"
        return length;
    }
};
#endif // _CEVTOUPPERSTRINGT_HPP
