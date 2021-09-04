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
//   File: cUnixFileSystemTime.hpp
//
// Author: $author$
//   Date: 8/25/2011
///////////////////////////////////////////////////////////////////////
#if !defined(_CUNIXFILESYSTEMTIME_HPP) || defined(CUNIXFILESYSTEMTIME_MEMBERS_ONLY)
#if !defined(_CUNIXFILESYSTEMTIME_HPP) && !defined(CUNIXFILESYSTEMTIME_MEMBERS_ONLY)
#define _CUNIXFILESYSTEMTIME_HPP
#endif // !defined(_CUNIXFILESYSTEMTIME_HPP) && !defined(CUNIXFILESYSTEMTIME_MEMBERS_ONLY) 

#if !defined(CUNIXFILESYSTEMTIME_MEMBERS_ONLY)
#include "cUnixFileSystemTimeInterface.hpp"
#include "cFileSystemTimeBase.hpp"
#include "cDebug.hpp"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

///////////////////////////////////////////////////////////////////////
// Typedef: cUnixFileSystemTimeExtend
//
//  Author: $author$
//    Date: 8/25/2011
///////////////////////////////////////////////////////////////////////
typedef cFileSystemTimeBase
cUnixFileSystemTimeExtend;
///////////////////////////////////////////////////////////////////////
//  Class: cUnixFileSystemTime
//
// Author: $author$
//   Date: 8/25/2011
///////////////////////////////////////////////////////////////////////
class c_INSTANCE_CLASS cUnixFileSystemTime
: virtual public cUnixFileSystemTimeImplement,
  public cUnixFileSystemTimeExtend
{
public:
    typedef cUnixFileSystemTimeImplement cImplements;
    typedef cUnixFileSystemTimeExtend cExtends;

    time_t m_time;
    struct tm m_gmTm;
    struct tm m_localTm;

    ///////////////////////////////////////////////////////////////////////
    //  Constructor: cUnixFileSystemTime
    //
    //       Author: $author$
    //         Date: 8/25/2011
    ///////////////////////////////////////////////////////////////////////
    cUnixFileSystemTime
    (time_t time=(time_t)(-1))
    : m_time(time)
    {
    }
    ///////////////////////////////////////////////////////////////////////
    //  Destructor: ~cUnixFileSystemTime
    //
    //      Author: $author$
    //        Date: 8/25/2011
    ///////////////////////////////////////////////////////////////////////
    virtual ~cUnixFileSystemTime()
    {
    }
#else // !defined(CUNIXFILESYSTEMTIME_MEMBERS_ONLY) 
#endif // !defined(CUNIXFILESYSTEMTIME_MEMBERS_ONLY) 

    ///////////////////////////////////////////////////////////////////////
    //  Function: Set
    //
    //    Author: $author$
    //      Date: 8/26/2011
    ///////////////////////////////////////////////////////////////////////
    virtual time_t Set(time_t time)
#if defined(CUNIXFILESYSTEMTIME_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CUNIXFILESYSTEMTIME_MEMBER_FUNCS_INTERFACE) 
    {
#if !defined(CUNIXFILESYSTEMTIME_MEMBER_FUNCS_IMPLEMENT)
        m_time = time;

        if (!(gmtime_r(&time, &m_gmTm)))
            c_DB_ERROR("() failed on gmtime_r()");

        if (!(localtime_r(&time, &m_localTm)))
            c_DB_ERROR("() failed on localtime_r()");
#else // !defined(CUNIXFILESYSTEMTIME_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CUNIXFILESYSTEMTIME_MEMBER_FUNCS_IMPLEMENT) 
        return time;
    }
#endif // defined(CUNIXFILESYSTEMTIME_MEMBER_FUNCS_INTERFACE) 

#if !defined(CUNIXFILESYSTEMTIME_MEMBERS_ONLY)
    inline operator time_t&() const
    { return (time_t&)(m_time); }
};


#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#else // !defined(CUNIXFILESYSTEMTIME_MEMBERS_ONLY) 
#endif // !defined(CUNIXFILESYSTEMTIME_MEMBERS_ONLY) 

#endif // !defined(_CUNIXFILESYSTEMTIME_HPP) || defined(CUNIXFILESYSTEMTIME_MEMBERS_ONLY) 
        

