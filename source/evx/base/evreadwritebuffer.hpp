///////////////////////////////////////////////////////////////////////
//   File: evreadwritebuffer.hpp
//
// Author: $author$
//   Date: 11/27/2007
///////////////////////////////////////////////////////////////////////

#ifndef _EVREADWRITEBUFFER_HPP
#define _EVREADWRITEBUFFER_HPP

#include "evcharreader.hpp"
#include "evcharwriter.hpp"

///////////////////////////////////////////////////////////////////////
//  Class: EvReadWriteBuffer
//
// Author: $author$
//   Date: 11/27/2007
///////////////////////////////////////////////////////////////////////
template
<class TChar=CHAR,
 class TSize=ULONG,
 class TLength=LONG,
 class TReaderImplements=EvReader
 <TChar, TSize, TLength, EvBase>,
 class TWriterImplements=EvWriter
 <TChar, TSize, TLength, EvBase> >

class EV_EXPORT_CLASS EvReadWriteBuffer
: virtual public TReaderImplements,
  virtual public TWriterImplements
{
public:
    typedef TReaderImplements CReaderImplements;
    typedef TWriterImplements CWriterImplements;
    typedef EvReadWriteBuffer CDerives;
};

///////////////////////////////////////////////////////////////////////
//  Typedef: EvCharReadWriteBuffer
//
//   Author: $author$
//     Date: 11/27/2007
///////////////////////////////////////////////////////////////////////
typedef EvReadWriteBuffer
<char, ULONG, LONG, 
 EvCharReader, EvCharWriter>
EvCharReadWriteBuffer;

#endif // _EVREADWRITEBUFFER_HPP
