///////////////////////////////////////////////////////////////////////
//   File: evstream.hpp
//
// Author: $author$
//   Date: 11/6/2007
//
//    $Id$
///////////////////////////////////////////////////////////////////////

#ifndef _EVSTREAM_HPP
#define _EVSTREAM_HPP

#include "evreader.hpp"
#include "evwriter.hpp"
#include "evbase.hpp"

///////////////////////////////////////////////////////////////////////
//  Class: EvStream
//
// Author: $author$
//   Date: 11/6/2007
///////////////////////////////////////////////////////////////////////
template
<class TChar=CHAR,
 class TSize=ULONG,
 class TLength=LONG,
 class TReaderImplements=EvReader<TChar,TSize,TLength,EvBase>,
 class TWriterImplements=EvWriter<TChar,TSize,TLength,EvBase>,
 class TImplements=EvBase>

class EV_EXPORT_CLASS EvStream
: virtual public TReaderImplements,
  virtual public TWriterImplements
{
public:
    typedef TReaderImplements CReaderImplements;
    typedef TWriterImplements CWriterImplements;
    typedef TImplements CImplements;
    typedef EvStream CDerives;
};
#endif // _EVSTREAM_HPP
