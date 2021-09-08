///////////////////////////////////////////////////////////////////////
//   File: cevbytereadwritebase.hpp
//
// Author: $author$
//   Date: 12/4/2007
///////////////////////////////////////////////////////////////////////

#ifndef _CEVBYTEREADWRITEBASE_HPP
#define _CEVBYTEREADWRITEBASE_HPP

#include "cevreadwritebase.hpp"
#include "evbytereader.hpp"
#include "evbytewriter.hpp"

///////////////////////////////////////////////////////////////////////
//  Typedef: CEvBYTEReadWriteBase
//
//   Author: $author$
//     Date: 12/4/2007
///////////////////////////////////////////////////////////////////////
typedef CEvReadWriteBase
<BYTE, ULONG, LONG, 
 EvBYTEReader, EvBYTEWriter>
CEvBYTEReadWriteBase;

#endif // _CEVBYTEREADWRITEBASE_HPP
