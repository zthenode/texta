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
//   File: cFileSystemEntryBase.hpp
//
// Author: $author$
//   Date: 7/30/2011
///////////////////////////////////////////////////////////////////////
#if !defined(_CFILESYSTEMENTRYBASE_HPP) || defined(CFILESYSTEMENTRYBASE_MEMBERS_ONLY)
#if !defined(_CFILESYSTEMENTRYBASE_HPP) && !defined(CFILESYSTEMENTRYBASE_MEMBERS_ONLY)
#define _CFILESYSTEMENTRYBASE_HPP
#endif // !defined(_CFILESYSTEMENTRYBASE_HPP) && !defined(CFILESYSTEMENTRYBASE_MEMBERS_ONLY) 

#if !defined(CFILESYSTEMENTRYBASE_MEMBERS_ONLY)
#include "cFileSystemEntryInterface.hpp"
#include "cInstanceBase.hpp"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

///////////////////////////////////////////////////////////////////////
// Typedef: cFileSystemEntryBaseExtend
//
//  Author: $author$
//    Date: 7/30/2011
///////////////////////////////////////////////////////////////////////
typedef cInstanceBase
cFileSystemEntryBaseExtend;
///////////////////////////////////////////////////////////////////////
//  Class: cFileSystemEntryBase
//
// Author: $author$
//   Date: 7/30/2011
///////////////////////////////////////////////////////////////////////
class c_INSTANCE_CLASS cFileSystemEntryBase
: virtual public cFileSystemEntryImplement,
  public cFileSystemEntryBaseExtend
{
public:
    typedef cFileSystemEntryImplement cImplements;
    typedef cFileSystemEntryBaseExtend cExtends;

    eFileSystemEntryType m_type;

    ///////////////////////////////////////////////////////////////////////
    //  Constructor: cFileSystemEntryBase
    //
    //       Author: $author$
    //         Date: 7/30/2011
    ///////////////////////////////////////////////////////////////////////
    cFileSystemEntryBase
    (eFileSystemEntryType type = e_FILE_SYSTEM_ENTRY_TYPE_NONE)
    : m_type(type)
    {
    }
    ///////////////////////////////////////////////////////////////////////
    //  Destructor: ~cFileSystemEntryBase
    //
    //      Author: $author$
    //        Date: 7/30/2011
    ///////////////////////////////////////////////////////////////////////
    virtual ~cFileSystemEntryBase()
    {
    }
#else // !defined(CFILESYSTEMENTRYBASE_MEMBERS_ONLY) 
#endif // !defined(CFILESYSTEMENTRYBASE_MEMBERS_ONLY) 

    ///////////////////////////////////////////////////////////////////////
    //  Function: Exists
    //
    //    Author: $author$
    //      Date: 7/30/2011
    ///////////////////////////////////////////////////////////////////////
    virtual eFileSystemEntryType Exists
    (const cString& fileName)
#if defined(CFILESYSTEMENTRYBASE_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CFILESYSTEMENTRYBASE_MEMBER_FUNCS_INTERFACE) 
    {
        eFileSystemEntryType type = e_FILE_SYSTEM_ENTRY_TYPE_NONE;
#if !defined(CFILESYSTEMENTRYBASE_MEMBER_FUNCS_IMPLEMENT)
#else // !defined(CFILESYSTEMENTRYBASE_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CFILESYSTEMENTRYBASE_MEMBER_FUNCS_IMPLEMENT) 
        return type;
    }
#endif // defined(CFILESYSTEMENTRYBASE_MEMBER_FUNCS_INTERFACE) 

    ///////////////////////////////////////////////////////////////////////
    //  Function: SetType
    //
    //    Author: $author$
    //      Date: 7/30/2011
    ///////////////////////////////////////////////////////////////////////
    virtual eFileSystemEntryType SetType
    (eFileSystemEntryType toType)
#if defined(CFILESYSTEMENTRYBASE_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CFILESYSTEMENTRYBASE_MEMBER_FUNCS_INTERFACE) 
    {
        eFileSystemEntryType type = e_FILE_SYSTEM_ENTRY_TYPE_NONE;
#if !defined(CFILESYSTEMENTRYBASE_MEMBER_FUNCS_IMPLEMENT)
        type = (m_type = toType);
#else // !defined(CFILESYSTEMENTRYBASE_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CFILESYSTEMENTRYBASE_MEMBER_FUNCS_IMPLEMENT) 
        return type;
    }
#endif // defined(CFILESYSTEMENTRYBASE_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    //  Function: GetType
    //
    //    Author: $author$
    //      Date: 7/30/2011
    ///////////////////////////////////////////////////////////////////////
    virtual eFileSystemEntryType GetType() const
#if defined(CFILESYSTEMENTRYBASE_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CFILESYSTEMENTRYBASE_MEMBER_FUNCS_INTERFACE) 
    {
        eFileSystemEntryType type = e_FILE_SYSTEM_ENTRY_TYPE_NONE;
#if !defined(CFILESYSTEMENTRYBASE_MEMBER_FUNCS_IMPLEMENT)
        type = (m_type);
#else // !defined(CFILESYSTEMENTRYBASE_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CFILESYSTEMENTRYBASE_MEMBER_FUNCS_IMPLEMENT) 
        return type;
    }
#endif // defined(CFILESYSTEMENTRYBASE_MEMBER_FUNCS_INTERFACE) 

#if !defined(CFILESYSTEMENTRYBASE_MEMBERS_ONLY)
};


#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#else // !defined(CFILESYSTEMENTRYBASE_MEMBERS_ONLY) 
#endif // !defined(CFILESYSTEMENTRYBASE_MEMBERS_ONLY) 

#endif // !defined(_CFILESYSTEMENTRYBASE_HPP) || defined(CFILESYSTEMENTRYBASE_MEMBERS_ONLY) 
        

