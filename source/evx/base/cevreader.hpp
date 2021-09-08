///////////////////////////////////////////////////////////////////////
//   File: cevreader.hpp
//
// Author: $author$
//   Date: 4/17/2007
//
//    $Id$
///////////////////////////////////////////////////////////////////////

#ifndef _CEVREADER_HPP
#define _CEVREADER_HPP

#include "evreader.hpp"
#include "cevbase.hpp"

///////////////////////////////////////////////////////////////////////
//  Class: CEvReader
//
// Author: $author$
//   Date: 4/17/2007
///////////////////////////////////////////////////////////////////////
template
<class TChar=CHAR,
 class TSize=ULONG,
 class TLength=LONG,
 class TImplements=EvReader<TChar,TSize,TLength,EvBase>,
 class TExtends=CEvBase>

class CEvReader
: virtual public TImplements,
  public TExtends
{
public:
    typedef TImplements CImplements;
    typedef TExtends CExtends;
    typedef CEvReader CDerives;

#include "cevreader_member_functions.hpp"
};
#endif // _CEVREADER_HPP
