///////////////////////////////////////////////////////////////////////
//   File: cevreadwritebase.hpp
//
// Author: $author$
//   Date: 11/27/2007
///////////////////////////////////////////////////////////////////////

#ifndef _CEVREADWRITEBASE_HPP
#define _CEVREADWRITEBASE_HPP

#include "evcharreader.hpp"
#include "evcharwriter.hpp"
#include "cevbase.hpp"

///////////////////////////////////////////////////////////////////////
//  Class: CEvReadWriteBase
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
 <TChar, TSize, TLength, EvBase>,
 class TExtends=CEvBase>

class CEvReadWriteBase
: virtual public TReaderImplements,
  virtual public TWriterImplements,
  public TExtends
{
public:
    typedef TReaderImplements CReaderImplements;
    typedef TWriterImplements CWriterImplements;
    typedef TExtends CExtends;
    typedef CEvReadWriteBase CDerives;

#include "cevreader_member_functions.hpp"
#include "cevwriter_member_functions.hpp"
};

///////////////////////////////////////////////////////////////////////
//  Typedef: CEvCharReadWriteBase
//
//   Author: $author$
//     Date: 11/27/2007
///////////////////////////////////////////////////////////////////////
typedef CEvReadWriteBase
<char, ULONG, LONG, 
 EvCharReader, EvCharWriter>
CEvCharReadWriteBase;

#endif // _CEVREADWRITEBASE_HPP
