///////////////////////////////////////////////////////////////////////
//   File: cev2writer.hpp
//
// Author: $author$
//   Date: 10/16/2007
//
//    $Id$
///////////////////////////////////////////////////////////////////////

#ifndef _CEV2WRITER_HPP
#define _CEV2WRITER_HPP

#include "ev2writer.hpp"
#include "cevbase.hpp"

///////////////////////////////////////////////////////////////////////
//  Class: CEv2Writer
//
// Author: $author$
//   Date: 10/16/2007
///////////////////////////////////////////////////////////////////////
template
<class TChar=CHAR,
 class TSize=ULONG,
 class TLength=LONG,
 TLength VUndefinedLength=-1,
 class TWriter=EvCHARWriter,
 class TImplements=Ev2CHARWriter,
 class TExtends=CEvBase>

class CEv2Writer
: virtual public TImplements,
  public TExtends
{
public:
    typedef TImplements CImplements;
    typedef TExtends CExtends;
    typedef CEv2Writer CDerives;

    ///////////////////////////////////////////////////////////////////////
    // Function: Write
    //
    //   Author: $author$
    //     Date: 10/16/2007
    ///////////////////////////////////////////////////////////////////////
    virtual TLength Write
    (TWriter& writer,
     TLength length=VUndefinedLength) 
    {
        TLength count = -EV_ERROR_NOT_IMPLEMENTED;
        return count;
    }
};
#endif // _CEV2WRITER_HPP
