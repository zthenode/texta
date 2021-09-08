///////////////////////////////////////////////////////////////////////
//   File: cevdir2filesystementrytimesdeligate.hpp
//
// Author: $author$
//   Date: 9/7/2007
//
//    $Id$
///////////////////////////////////////////////////////////////////////

#ifndef _CEVDIR2FILESYSTEMENTRYTIMESDELIGATE_HPP
#define _CEVDIR2FILESYSTEMENTRYTIMESDELIGATE_HPP

#include "cevfilesystementrytimesdeligate.hpp"
#include "evfiledirectoryentry.hpp"

///////////////////////////////////////////////////////////////////////
//  Typedef: CEvDirectory2FileSystemEntryTimesDeligate
//
//   Author: $author$
//     Date: 9/7/2007
///////////////////////////////////////////////////////////////////////
typedef CEvFileSystemEntryTimesDeligateT
<EvFileDirectoryEntry, CEvBase, EvFileSystemEntryTimes>
CEvDirectory2FileSystemEntryTimesDeligate;

#endif // _CEVDIR2FILESYSTEMENTRYTIMESDELIGATE_HPP
