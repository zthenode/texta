///////////////////////////////////////////////////////////////////////
//   File: cevbytestring.hpp
//
// Author: $author$
//   Date: 11/26/2007
///////////////////////////////////////////////////////////////////////

#ifndef _CEVBYTESTRING_HPP
#define _CEVBYTESTRING_HPP

#include "evbytestring.hpp"
#include "cevstringt.hpp"
#include "evbytereader.hpp"
#include "evbytewriter.hpp"

///////////////////////////////////////////////////////////////////////
//  Typedef: CEvBYTEString
//
//   Author: $author$
//     Date: 11/26/2007
///////////////////////////////////////////////////////////////////////
typedef CEvStringT
<BYTE, ULONG, LONG, 
 EvBYTEReader, EvBYTEWriter, EvBYTEString>
CEvBYTEString;

#endif // _CEVBYTESTRING_HPP
