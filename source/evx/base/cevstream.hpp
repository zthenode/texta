///////////////////////////////////////////////////////////////////////
//   File: cevstream.hpp
//
// Author: $author$
//   Date: 11/6/2007
//
//    $Id$
///////////////////////////////////////////////////////////////////////

#ifndef _CEVSTREAM_HPP
#define _CEVSTREAM_HPP

#include "evstream.hpp"

///////////////////////////////////////////////////////////////////////
//  Class: CEvStream
//
// Author: $author$
//   Date: 11/6/2007
///////////////////////////////////////////////////////////////////////
template
<class TChar=CHAR,
 class TSize=ULONG,
 class TLength=LONG,
 class TImplements=EvStream
 <TChar, TSize, TLength, 
  EvCHARReader, EvCHARWriter, EvBase>,
 class TExtends=CEvBase>

class CEvStream
: virtual public TImplements,
  public TExtends
{
public:
    typedef TImplements CImplements;
    typedef TExtends CExtends;
    typedef CEvStream CDerives;

#include "cevreader_member_functions.hpp"
#include "cevwriter_member_functions.hpp"
};
#endif // _CEVSTREAM_HPP
