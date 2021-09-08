///////////////////////////////////////////////////////////////////////
//   File: evcscheckout.hpp
//
// Author: $author$
//   Date: 8/16/2007
//
//    $Id$
///////////////////////////////////////////////////////////////////////

#ifndef _EVCSCHECKOUT_HPP
#define _EVCSCHECKOUT_HPP

#include "evcscheck.hpp"
#include "evfilesystementry.hpp"

///////////////////////////////////////////////////////////////////////
//  Class: EvcsCheckOut
//
// Author: $author$
//   Date: 8/16/2007
///////////////////////////////////////////////////////////////////////
class EV_EXPORT_CLASS EvcsCheckOut
: virtual public EvcsCheck
{
public:
    typedef EvcsCheck CImplements;
    typedef EvcsCheckOut CDerives;
    ///////////////////////////////////////////////////////////////////////
    // Function: OpenFirst
    //
    //   Author: $author$
    //     Date: 5/29/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError OpenFirst
    (EvFileSystemEntry& fileEntry,
     const char* evcName, 
     bool isBinary=false, 
     bool isRecursive=false) = 0;
    ///////////////////////////////////////////////////////////////////////
    // Function: OpenFirst
    //
    //   Author: $author$
    //     Date: 5/29/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError OpenFirst
    (CEvFilePath& filePath,
     EvFileSystemEntry& fileEntry,
     const char* evcName, 
     bool isBinary=false, 
     bool isRecursive=false) = 0;
};

#endif // _EVCSCHECKOUT_HPP
