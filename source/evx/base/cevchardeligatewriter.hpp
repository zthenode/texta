///////////////////////////////////////////////////////////////////////
//   File: cevchardeligatewriter.hpp
//
// Author: $author$
//   Date: 12/19/2007
///////////////////////////////////////////////////////////////////////

#ifndef _CEVCHARDELIGATEWRITER_HPP
#define _CEVCHARDELIGATEWRITER_HPP

#include "cevdeligatewriter.hpp"
#include "cevcharwriter.hpp"

///////////////////////////////////////////////////////////////////////
//  Typedef: CEvCharDeligateWriter
//
//   Author: $author$
//     Date: 12/19/2007
///////////////////////////////////////////////////////////////////////
typedef CEvDeligateWriter
<char, ULONG, LONG, 
 EvCharWriter, CEvCharWriter>
CEvCharDeligateWriter;

#endif // _CEVCHARDELIGATEWRITER_HPP
