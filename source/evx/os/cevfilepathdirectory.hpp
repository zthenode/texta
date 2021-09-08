///////////////////////////////////////////////////////////////////////
//   File: cevfilepathdirectory.hpp
//
// Author: $author$
//   Date: 7/5/2007
//
//    $Id$
///////////////////////////////////////////////////////////////////////

#ifndef _CEVFILEPATHDIRECTORY_HPP
#define _CEVFILEPATHDIRECTORY_HPP

#include "evfilepathdirectory.hpp"
#include "cevstringinstance.hpp"
#include "cevinstance.hpp"

///////////////////////////////////////////////////////////////////////
//  Class: CEvFilePathDirectory
//
// Author: $author$
//   Date: 5/31/2007
///////////////////////////////////////////////////////////////////////
class CEvFilePathDirectory
: virtual public EvFilePathDirectory,
  public CEvStringInstance
{
public:
    typedef EvFilePathDirectory CImplements;
    typedef CEvStringInstance CExtends;
    typedef CEvFilePathDirectory CDerives;

    Type m_type;

    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvFilePathDirectory
    //
    //       Author: $author$
    //         Date: 5/31/2007
    ///////////////////////////////////////////////////////////////////////
    CEvFilePathDirectory
    (Type type=EV_TYPE_NONE, 
     const char* chars=0, LONG length=-1) 
    : CExtends(chars, length),
      m_type(type)
    {
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: DeleteInstance
    //
    //   Author: $author$
    //     Date: 5/31/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError DeleteInstance() 
    {
        return DeleteThis();
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: DeleteThis
    //
    //   Author: $author$
    //     Date: 5/31/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError DeleteThis() 
    {
        delete this;
        return EV_ERROR_NONE;
    }
};

#endif // _CEVFILEPATHDIRECTORY_HPP
