///////////////////////////////////////////////////////////////////////
//   File: cev2charwriter.hpp
//
// Author: $author$
//   Date: 10/16/2007
//
//    $Id$
///////////////////////////////////////////////////////////////////////

#ifndef _CEV2CHARWRITER_HPP
#define _CEV2CHARWRITER_HPP

#include "ev2charwriter.hpp"
#include "cev2writer.hpp"

///////////////////////////////////////////////////////////////////////
//  Typedef: CEv2CharWriter
//
//   Author: $author$
//     Date: 10/16/2007
///////////////////////////////////////////////////////////////////////
typedef CEv2Writer
<char, ULONG, LONG, -1, 
 EvCharWriter, Ev2CharWriter, CEvBase>
CEv2CharWriter;

#endif // _CEV2CHARWRITER_HPP
