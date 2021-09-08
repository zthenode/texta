///////////////////////////////////////////////////////////////////////
//   File: cevfilematchevents.hpp
//
// Author: $author$
//   Date: 6/28/2007
///////////////////////////////////////////////////////////////////////

#ifndef _CEVFILEMATCHEVENTS_HPP
#define _CEVFILEMATCHEVENTS_HPP

#include "evfilematchevents.hpp"

///////////////////////////////////////////////////////////////////////
//  Class: CEvFileMatchEvents
//
// Author: $author$
//   Date: 6/28/2007
///////////////////////////////////////////////////////////////////////
template
<class TExtends=CEvBase,
 class TImplements=EvFileMatchEvents>

class CEvFileMatchEvents
: virtual public TImplements,
  public TExtends
{
public:
    typedef TImplements CImplements;
    typedef TExtends CExtends;
    typedef CEvFileMatchEvents CDerives;
    ///////////////////////////////////////////////////////////////////////
    // Function: OnMatchFilename
    //
    //   Author: $author$
    //     Date: 6/28/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError OnMatchFilename
    (const char* chars,
     LONG length=-1) 
    {
        EvError error = EV_ERROR_NONE;
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: OnMatchFilebase
    //
    //   Author: $author$
    //     Date: 7/2/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError OnMatchFilebase
    (const char* chars,
     LONG length=-1) 
    {
        EvError error = EV_ERROR_NONE;
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: OnMatchExtension
    //
    //   Author: $author$
    //     Date: 6/28/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError OnMatchExtension
    (const char* chars,
     LONG length=-1) 
    {
        EvError error = EV_ERROR_NONE;
        return error;
    }
};
#endif // _CEVFILEMATCHEVENTS_HPP
