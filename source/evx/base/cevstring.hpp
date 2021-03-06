///////////////////////////////////////////////////////////////////////
//   File: cevstring.hpp
//
// Author: $author$
//   Date: 4/4/2007
///////////////////////////////////////////////////////////////////////

#ifndef _CEVSTRING_HPP
#define _CEVSTRING_HPP

#include "evstring.hpp"
#include "cevstringt.hpp"
#include "evcharreader.hpp"
#include "evcharwriter.hpp"

///////////////////////////////////////////////////////////////////////
//  Typedef: CEvStringExtends
//
//  Author: $author$
//    Date: 5/17/2008
///////////////////////////////////////////////////////////////////////
typedef ::std::basic_string<char>
CEvStringExtends;

///////////////////////////////////////////////////////////////////////
//  Typedef: CEvCHARStringExtends
//
//  Author: $author$
//    Date: 5/17/2008
///////////////////////////////////////////////////////////////////////
typedef ::std::basic_string<CHAR>
CEvCHARStringExtends;

///////////////////////////////////////////////////////////////////////
//  Typedef: CEvTCHARStringExtends
//
//  Author: $author$
//    Date: 5/17/2008
///////////////////////////////////////////////////////////////////////
typedef ::std::basic_string<TCHAR>
CEvTCHARStringExtends;

///////////////////////////////////////////////////////////////////////
//  Typedef: CEvWCHARStringExtends
//
//  Author: $author$
//    Date: 5/17/2008
///////////////////////////////////////////////////////////////////////
typedef ::std::basic_string<WCHAR>
CEvWCHARStringExtends;

///////////////////////////////////////////////////////////////////////
//  Typedef: CEvString
//
//   Author: $author$
//     Date: 4/13/2007
///////////////////////////////////////////////////////////////////////
typedef CEvStringT
<char, ULONG, LONG, 
 EvCharReader, EvCharWriter, 
 EvString, CEvStringExtends> 
CEvString;

///////////////////////////////////////////////////////////////////////
//  Typedef: CEvCHARString
//
//   Author: $author$
//     Date: 4/13/2007
///////////////////////////////////////////////////////////////////////
typedef CEvStringT
<CHAR, ULONG, LONG, 
 EvCHARReader, EvCHARWriter, 
 EvCHARString, CEvCHARStringExtends> 
CEvCHARString;

///////////////////////////////////////////////////////////////////////
//  Typedef: CEvTCHARString
//
//   Author: $author$
//     Date: 5/16/2008
///////////////////////////////////////////////////////////////////////
typedef CEvStringT
<TCHAR, ULONG, LONG, 
 EvTCHARReader, EvTCHARWriter, 
 EvTCHARString, CEvTCHARStringExtends> 
CEvTCHARString;

///////////////////////////////////////////////////////////////////////
//  Typedef: CEvWCHARString
//
//   Author: $author$
//     Date: 5/16/2008
///////////////////////////////////////////////////////////////////////
typedef CEvStringT
<WCHAR, ULONG, LONG, 
 EvWCHARReader, EvWCHARWriter, 
 EvWCHARString, CEvWCHARStringExtends> 
CEvWCHARString;

#endif // _CEVSTRING_HPP
