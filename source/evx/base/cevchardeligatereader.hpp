///////////////////////////////////////////////////////////////////////
//   File: cevchardeligatereader.hpp
//
// Author: $author$
//   Date: 12/19/2007
///////////////////////////////////////////////////////////////////////

#ifndef _CEVCHARDELIGATEREADER_HPP
#define _CEVCHARDELIGATEREADER_HPP

#include "cevdeligatereader.hpp"
#include "cevcharreader.hpp"

///////////////////////////////////////////////////////////////////////
//  Typedef: CEvCharDeligateReader
//
//   Author: $author$
//     Date: 12/19/2007
///////////////////////////////////////////////////////////////////////
typedef CEvDeligateReader
<char, ULONG, LONG, 
 EvCharReader, CEvCharReader>
CEvCharDeligateReader;

#endif // _CEVCHARDELIGATEREADER_HPP
