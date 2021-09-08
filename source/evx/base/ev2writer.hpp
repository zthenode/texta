///////////////////////////////////////////////////////////////////////
//   File: ev2writer.hpp
//
// Author: $author$
//   Date: 10/16/2007
//
//    $Id$
///////////////////////////////////////////////////////////////////////

#ifndef _EV2WRITER_HPP
#define _EV2WRITER_HPP

#include "evwriter.hpp"

///////////////////////////////////////////////////////////////////////
//  Class: Ev2Writer
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
 class TImplements=EvBase>

class Ev2Writer
: virtual public TImplements
{
public:
    typedef TImplements CImplements;
    typedef Ev2Writer CDerives;
    ///////////////////////////////////////////////////////////////////////
    // Function: Write
    //
    //   Author: $author$
    //     Date: 10/16/2007
    ///////////////////////////////////////////////////////////////////////
    virtual TLength Write
    (TWriter& writer,
     TLength length=VUndefinedLength) = 0;
};

///////////////////////////////////////////////////////////////////////
//  Typedef: Ev2CHARWriter
//
//   Author: $author$
//     Date: 10/16/2007
///////////////////////////////////////////////////////////////////////
typedef Ev2Writer
<char, ULONG, LONG, -1, 
 EvCHARWriter, EvBase>
Ev2CHARWriter;

#endif // _EV2WRITER_HPP
