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
//   File: cUnixFileSystemEntryTime.hpp
//
// Author: $author$
//   Date: 8/25/2011
///////////////////////////////////////////////////////////////////////
#if !defined(_CUNIXFILESYSTEMENTRYTIME_HPP) || defined(CUNIXFILESYSTEMENTRYTIME_MEMBERS_ONLY)
#if !defined(_CUNIXFILESYSTEMENTRYTIME_HPP) && !defined(CUNIXFILESYSTEMENTRYTIME_MEMBERS_ONLY)
#define _CUNIXFILESYSTEMENTRYTIME_HPP
#endif // !defined(_CUNIXFILESYSTEMENTRYTIME_HPP) && !defined(CUNIXFILESYSTEMENTRYTIME_MEMBERS_ONLY) 

#if !defined(CUNIXFILESYSTEMENTRYTIME_MEMBERS_ONLY)
#include "cUnixFileSystemEntryTimeInterface.hpp"
#include "cUnixFileSystemTime.hpp"
#include "cFileSystemEntryTimeBase.hpp"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

///////////////////////////////////////////////////////////////////////
// Typedef: cUnixFileSystemEntryTimeExtend
//
//  Author: $author$
//    Date: 8/25/2011
///////////////////////////////////////////////////////////////////////
typedef cUnixFileSystemTime
cUnixFileSystemEntryTimeExtend;
///////////////////////////////////////////////////////////////////////
//  Class: cUnixFileSystemEntryTime
//
// Author: $author$
//   Date: 8/25/2011
///////////////////////////////////////////////////////////////////////
class c_INSTANCE_CLASS cUnixFileSystemEntryTime
: virtual public cUnixFileSystemEntryTimeImplement,
  public cUnixFileSystemEntryTimeExtend
{
public:
    typedef cUnixFileSystemEntryTimeImplement cImplements;
    typedef cUnixFileSystemEntryTimeExtend cExtends;

    eFileSystemEntryTimeWhen m_when;

    ///////////////////////////////////////////////////////////////////////
    //  Constructor: cUnixFileSystemEntryTime
    //
    //       Author: $author$
    //         Date: 8/25/2011
    ///////////////////////////////////////////////////////////////////////
    cUnixFileSystemEntryTime
    (eFileSystemEntryTimeWhen when=e_FILE_SYSTEM_ENTRY_TIME_WHEN_NONE,
     time_t time=(time_t)(-1))
    : cExtends(time),
      m_when(when)
    {
    }
    ///////////////////////////////////////////////////////////////////////
    //  Destructor: ~cUnixFileSystemEntryTime
    //
    //      Author: $author$
    //        Date: 8/25/2011
    ///////////////////////////////////////////////////////////////////////
    virtual ~cUnixFileSystemEntryTime()
    {
    }
#else // !defined(CUNIXFILESYSTEMENTRYTIME_MEMBERS_ONLY) 
#endif // !defined(CUNIXFILESYSTEMENTRYTIME_MEMBERS_ONLY) 

#if !defined(CUNIXFILESYSTEMENTRYTIME_MEMBERS_ONLY)
    ///////////////////////////////////////////////////////////////////////
    //  Function: SetWhen
    //
    //    Author: $author$
    //      Date: 8/25/2011
    ///////////////////////////////////////////////////////////////////////
    virtual eFileSystemEntryTimeWhen SetWhen
    (eFileSystemEntryTimeWhen when)
    {
        return m_when = when;
    }
    ///////////////////////////////////////////////////////////////////////
    //  Function: GetWhen
    //
    //    Author: $author$
    //      Date: 8/25/2011
    ///////////////////////////////////////////////////////////////////////
    virtual eFileSystemEntryTimeWhen GetWhen() const
    {
        return m_when;
    }
};


#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#else // !defined(CUNIXFILESYSTEMENTRYTIME_MEMBERS_ONLY) 
#endif // !defined(CUNIXFILESYSTEMENTRYTIME_MEMBERS_ONLY) 

#endif // !defined(_CUNIXFILESYSTEMENTRYTIME_HPP) || defined(CUNIXFILESYSTEMENTRYTIME_MEMBERS_ONLY) 
        

