///////////////////////////////////////////////////////////////////////
// Copyright (c) 1988-2011 $organization$
//
// This software is provided by the author and contributors ``as is'' 
// and any express or implied warranties, including, but not limited to, 
// the implied warranties of merchantability and fitness for a particular 
// purpose are disclaimed. In no event shall the author or contributors 
// be liable for any direct, indirect, incidental, special, exemplary, 
// or consequential damages (including, but not limited to, procurement 
// of substitute goods or services; loss of use, data, or profits; or 
// business interruption) however caused and on any theory of liability, 
// whether in contract, strict liability, or tort (including negligence 
// or otherwise) arising in any way out of the use of this software, 
// even if advised of the possibility of such damage.
//
//   File: cFileSystemEntry.hpp
//
// Author: $author$
//   Date: 8/1/2011
///////////////////////////////////////////////////////////////////////
#if !defined(_CFILESYSTEMENTRY_HPP) || defined(CFILESYSTEMENTRY_MEMBERS_ONLY)
#if !defined(_CFILESYSTEMENTRY_HPP) && !defined(CFILESYSTEMENTRY_MEMBERS_ONLY)
#define _CFILESYSTEMENTRY_HPP
#endif // !defined(_CFILESYSTEMENTRY_HPP) && !defined(CFILESYSTEMENTRY_MEMBERS_ONLY) 

#if !defined(CFILESYSTEMENTRY_MEMBERS_ONLY)
#include "cFileSystemEntryInterface.hpp"

#if defined(WINDOWS) 
// Windows 
#include "cWinFileSystemEntry.hpp"
#else // defined(WINDOWS) 
// Unix 
#include "cUnixFileSystemEntry.hpp"
#endif // defined(WINDOWS) 

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

///////////////////////////////////////////////////////////////////////
// Typedef: cFileSystemEntryExtend
//
//  Author: $author$
//    Date: 8/1/2011
///////////////////////////////////////////////////////////////////////
#if defined(WINDOWS) 
// Windows 
typedef cWinFileSystemEntry
#else // defined(WINDOWS) 
// Unix 
typedef cUnixFileSystemEntry
#endif // defined(WINDOWS) 
cFileSystemEntryExtend;
///////////////////////////////////////////////////////////////////////
//  Class: cFileSystemEntry
//
// Author: $author$
//   Date: 8/1/2011
///////////////////////////////////////////////////////////////////////
class c_INSTANCE_CLASS cFileSystemEntry
: public cFileSystemEntryExtend
{
public:
    typedef cFileSystemEntryExtend cExtends;
    ///////////////////////////////////////////////////////////////////////
    //  Constructor: cFileSystemEntry
    //
    //       Author: $author$
    //         Date: 8/1/2011
    ///////////////////////////////////////////////////////////////////////
    cFileSystemEntry()
    {
    }
    ///////////////////////////////////////////////////////////////////////
    //  Destructor: ~cFileSystemEntry
    //
    //      Author: $author$
    //        Date: 8/1/2011
    ///////////////////////////////////////////////////////////////////////
    virtual ~cFileSystemEntry()
    {
    }
#else // !defined(CFILESYSTEMENTRY_MEMBERS_ONLY) 
#endif // !defined(CFILESYSTEMENTRY_MEMBERS_ONLY) 

#if !defined(CFILESYSTEMENTRY_MEMBERS_ONLY)
};


#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#else // !defined(CFILESYSTEMENTRY_MEMBERS_ONLY) 
#endif // !defined(CFILESYSTEMENTRY_MEMBERS_ONLY) 

#endif // !defined(_CFILESYSTEMENTRY_HPP) || defined(CFILESYSTEMENTRY_MEMBERS_ONLY) 
        

