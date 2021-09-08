///////////////////////////////////////////////////////////////////////
//   File: cevbytestringwriter.hpp
//
// Author: $author$
//   Date: 1/26/2008
///////////////////////////////////////////////////////////////////////

#ifndef _CEVBYTESTRINGWRITER_HPP
#define _CEVBYTESTRINGWRITER_HPP

#include "cevstringwritert.hpp"
#include "cevbytestring.hpp"
#include "cevbytewriter.hpp"

///////////////////////////////////////////////////////////////////////
//  Typedef: CEvBYTEStringWriter
//
//  Author: $author$
//    Date: 1/26/2008
///////////////////////////////////////////////////////////////////////
typedef CEvStringWriterT
<BYTE, ULONG, LONG, 
 CEvBYTEString, CEvBYTEWriter>
CEvBYTEStringWriter;

#endif // _CEVBYTESTRINGWRITER_HPP 
