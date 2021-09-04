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
//   File: cFileSystemTimeBase.hpp
//
// Author: $author$
//   Date: 7/31/2011
///////////////////////////////////////////////////////////////////////
#if !defined(_CFILESYSTEMTIMEBASE_HPP) || defined(CFILESYSTEMTIMEBASE_MEMBERS_ONLY)
#if !defined(_CFILESYSTEMTIMEBASE_HPP) && !defined(CFILESYSTEMTIMEBASE_MEMBERS_ONLY)
#define _CFILESYSTEMTIMEBASE_HPP
#endif // !defined(_CFILESYSTEMTIMEBASE_HPP) && !defined(CFILESYSTEMTIMEBASE_MEMBERS_ONLY) 

#if !defined(CFILESYSTEMTIMEBASE_MEMBERS_ONLY)
#include "cFileSystemTimeInterface.hpp"
#include "cInstanceBase.hpp"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

///////////////////////////////////////////////////////////////////////
// Typedef: cFileSystemTimeBaseExtend
//
//  Author: $author$
//    Date: 7/31/2011
///////////////////////////////////////////////////////////////////////
typedef cInstanceBase
cFileSystemTimeBaseExtend;
///////////////////////////////////////////////////////////////////////
//  Class: cFileSystemTimeBase
//
// Author: $author$
//   Date: 7/31/2011
///////////////////////////////////////////////////////////////////////
class c_INSTANCE_CLASS cFileSystemTimeBase
: virtual public cFileSystemTimeImplement,
  public cFileSystemTimeBaseExtend
{
public:
    typedef cFileSystemTimeImplement cImplements;
    typedef cFileSystemTimeBaseExtend cExtends;
    ///////////////////////////////////////////////////////////////////////
    //  Constructor: cFileSystemTimeBase
    //
    //       Author: $author$
    //         Date: 7/31/2011
    ///////////////////////////////////////////////////////////////////////
    cFileSystemTimeBase()
    {
    }
    ///////////////////////////////////////////////////////////////////////
    //  Destructor: ~cFileSystemTimeBase
    //
    //      Author: $author$
    //        Date: 7/31/2011
    ///////////////////////////////////////////////////////////////////////
    virtual ~cFileSystemTimeBase()
    {
    }
#else // !defined(CFILESYSTEMTIMEBASE_MEMBERS_ONLY) 
#endif // !defined(CFILESYSTEMTIMEBASE_MEMBERS_ONLY) 

#if !defined(CFILESYSTEMTIMEBASE_MEMBERS_ONLY)
};


#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#else // !defined(CFILESYSTEMTIMEBASE_MEMBERS_ONLY) 
#endif // !defined(CFILESYSTEMTIMEBASE_MEMBERS_ONLY) 

#endif // !defined(_CFILESYSTEMTIMEBASE_HPP) || defined(CFILESYSTEMTIMEBASE_MEMBERS_ONLY) 
        

