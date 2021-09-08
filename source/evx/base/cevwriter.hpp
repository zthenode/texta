///////////////////////////////////////////////////////////////////////
//   File: cevwriter.hpp
//
// Author: $author$
//   Date: 4/16/2007
///////////////////////////////////////////////////////////////////////

#ifndef _CEVWRITER_HPP
#define _CEVWRITER_HPP

#include "evwriter.hpp"
#include "cevbase.hpp"

///////////////////////////////////////////////////////////////////////
//  Class: CEvWriter
//
// Author: $author$
//   Date: 4/16/2007
///////////////////////////////////////////////////////////////////////
template
<class TChar=CHAR,
 class TSize=ULONG,
 class TLength=LONG,
 class TImplements=EvCHARWriter,
 class TExtends=CEvBase>

class CEvWriter
: virtual public TImplements,
  public TExtends
{
public:
    typedef TImplements CImplements;
    typedef TExtends CExtends;
    typedef CEvWriter CDerives;

#include "cevwriter_member_functions.hpp"
};

///////////////////////////////////////////////////////////////////////
//  Typedef: CEvCHARWriter
//
//   Author: $author$
//     Date: 1/26/2008
///////////////////////////////////////////////////////////////////////
typedef CEvWriter
<CHAR, ULONG, LONG, EvCHARWriter, CEvBase>
CEvCHARWriter;

#endif // _CEVWRITER_HPP
