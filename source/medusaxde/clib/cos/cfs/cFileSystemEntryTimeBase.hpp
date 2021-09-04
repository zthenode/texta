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
//   File: cFileSystemEntryTimeBase.hpp
//
// Author: $author$
//   Date: 7/31/2011
///////////////////////////////////////////////////////////////////////
#if !defined(_CFILESYSTEMENTRYTIMEBASE_HPP) || defined(CFILESYSTEMENTRYTIMEBASE_MEMBERS_ONLY)
#if !defined(_CFILESYSTEMENTRYTIMEBASE_HPP) && !defined(CFILESYSTEMENTRYTIMEBASE_MEMBERS_ONLY)
#define _CFILESYSTEMENTRYTIMEBASE_HPP
#endif // !defined(_CFILESYSTEMENTRYTIMEBASE_HPP) && !defined(CFILESYSTEMENTRYTIMEBASE_MEMBERS_ONLY) 

#if !defined(CFILESYSTEMENTRYTIMEBASE_MEMBERS_ONLY)
#include "cFileSystemEntryTimeInterface.hpp"
#include "cFileSystemTimeBase.hpp"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

///////////////////////////////////////////////////////////////////////
// Typedef: cFileSystemEntryTimeBaseExtend
//
//  Author: $author$
//    Date: 7/31/2011
///////////////////////////////////////////////////////////////////////
typedef cFileSystemTimeBase
cFileSystemEntryTimeBaseExtend;
///////////////////////////////////////////////////////////////////////
//  Class: cFileSystemEntryTimeBase
//
// Author: $author$
//   Date: 7/31/2011
///////////////////////////////////////////////////////////////////////
class c_INSTANCE_CLASS cFileSystemEntryTimeBase
: virtual public cFileSystemEntryTimeImplement,
  public cFileSystemEntryTimeBaseExtend
{
public:
    typedef cFileSystemEntryTimeImplement cImplements;
    typedef cFileSystemEntryTimeBaseExtend cExtends;

    eFileSystemEntryTimeWhen m_when;

    ///////////////////////////////////////////////////////////////////////
    //  Constructor: cFileSystemEntryTimeBase
    //
    //       Author: $author$
    //         Date: 7/31/2011
    ///////////////////////////////////////////////////////////////////////
    cFileSystemEntryTimeBase
    (eFileSystemEntryTimeWhen when=e_FILE_SYSTEM_ENTRY_TIME_WHEN_NONE)
    : m_when(when)
    {
    }
    ///////////////////////////////////////////////////////////////////////
    //  Destructor: ~cFileSystemEntryTimeBase
    //
    //      Author: $author$
    //        Date: 7/31/2011
    ///////////////////////////////////////////////////////////////////////
    virtual ~cFileSystemEntryTimeBase()
    {
    }
#else // !defined(CFILESYSTEMENTRYTIMEBASE_MEMBERS_ONLY) 
#endif // !defined(CFILESYSTEMENTRYTIMEBASE_MEMBERS_ONLY) 

    ///////////////////////////////////////////////////////////////////////
    //  Function: SetWhen
    //
    //    Author: $author$
    //      Date: 7/31/2011
    ///////////////////////////////////////////////////////////////////////
    virtual eFileSystemEntryTimeWhen SetWhen
    (eFileSystemEntryTimeWhen toWhen)
#if defined(CFILESYSTEMENTRYTIMEBASE_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CFILESYSTEMENTRYTIMEBASE_MEMBER_FUNCS_INTERFACE) 
    {
        eFileSystemEntryTimeWhen when = e_FILE_SYSTEM_ENTRY_TIME_WHEN_NONE;
#if !defined(CFILESYSTEMENTRYTIMEBASE_MEMBER_FUNCS_IMPLEMENT)
        when = (m_when = toWhen);
#else // !defined(CFILESYSTEMENTRYTIMEBASE_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CFILESYSTEMENTRYTIMEBASE_MEMBER_FUNCS_IMPLEMENT) 
        return when;
    }
#endif // defined(CFILESYSTEMENTRYTIMEBASE_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    //  Function: GetWhen
    //
    //    Author: $author$
    //      Date: 7/31/2011
    ///////////////////////////////////////////////////////////////////////
    virtual eFileSystemEntryTimeWhen GetWhen() const
#if defined(CFILESYSTEMENTRYTIMEBASE_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CFILESYSTEMENTRYTIMEBASE_MEMBER_FUNCS_INTERFACE) 
    {
        eFileSystemEntryTimeWhen when = e_FILE_SYSTEM_ENTRY_TIME_WHEN_NONE;
#if !defined(CFILESYSTEMENTRYTIMEBASE_MEMBER_FUNCS_IMPLEMENT)
        when = (m_when);
#else // !defined(CFILESYSTEMENTRYTIMEBASE_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CFILESYSTEMENTRYTIMEBASE_MEMBER_FUNCS_IMPLEMENT) 
        return when;
    }
#endif // defined(CFILESYSTEMENTRYTIMEBASE_MEMBER_FUNCS_INTERFACE) 

#if !defined(CFILESYSTEMENTRYTIMEBASE_MEMBERS_ONLY)
};

#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#else // !defined(CFILESYSTEMENTRYTIMEBASE_MEMBERS_ONLY) 
#endif // !defined(CFILESYSTEMENTRYTIMEBASE_MEMBERS_ONLY) 

#endif // !defined(_CFILESYSTEMENTRYTIMEBASE_HPP) || defined(CFILESYSTEMENTRYTIMEBASE_MEMBERS_ONLY) 
        

