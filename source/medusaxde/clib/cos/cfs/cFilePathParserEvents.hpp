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
//   File: cFilePathParserEvents.hpp
//
// Author: $author$
//   Date: 8/6/2011
///////////////////////////////////////////////////////////////////////
#if !defined(_CFILEPATHPARSEREVENTS_HPP) || defined(CFILEPATHPARSEREVENTST_MEMBERS_ONLY)
#if !defined(_CFILEPATHPARSEREVENTS_HPP) && !defined(CFILEPATHPARSEREVENTST_MEMBERS_ONLY)
#define _CFILEPATHPARSEREVENTS_HPP
#endif // !defined(_CFILEPATHPARSEREVENTS_HPP) && !defined(CFILEPATHPARSEREVENTST_MEMBERS_ONLY) 

#if !defined(CFILEPATHPARSEREVENTST_MEMBERS_ONLY)
#include "cFilePathParserEventsInterface.hpp"
#include "cInstanceBase.hpp"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

#undef CDB_CLASS
#define CDB_CLASS "cFilePathParserEventsT"
///////////////////////////////////////////////////////////////////////
//  Class: cFilePathParserEventsT
//
// Author: $author$
//   Date: 8/6/2011
///////////////////////////////////////////////////////////////////////
template
<class TImplement=cFilePathParserEventsImplement,
 class TInterface=cFilePathParserEventsInterface,
 class TChar=char,
 class TExtend=cInstanceBase>

class c_INSTANCE_CLASS cFilePathParserEventsT
: virtual public TImplement,
  public TExtend
{
public:
    typedef TImplement cImplements;
    typedef TExtend cExtends;

// include cFilePathParserEventsT interface member definitions
//
#define CFILEPATHPARSEREVENTSINTERFACET_MEMBERS_ONLY
#include "cFilePathParserEventsInterface.hpp"
#undef CFILEPATHPARSEREVENTSINTERFACET_MEMBERS_ONLY

    ///////////////////////////////////////////////////////////////////////
    //  Constructor: cFilePathParserEventsT
    //
    //       Author: $author$
    //         Date: 8/6/2011
    ///////////////////////////////////////////////////////////////////////
    cFilePathParserEventsT()
    {
    }
    ///////////////////////////////////////////////////////////////////////
    //  Destructor: ~cFilePathParserEventsT
    //
    //      Author: $author$
    //        Date: 8/6/2011
    ///////////////////////////////////////////////////////////////////////
    virtual ~cFilePathParserEventsT()
    {
    }
#else // !defined(CFILEPATHPARSEREVENTST_MEMBERS_ONLY) 
#endif // !defined(CFILEPATHPARSEREVENTST_MEMBERS_ONLY) 

    ///////////////////////////////////////////////////////////////////////
    //  Function: OnPathHost
    //
    //    Author: $author$
    //      Date: 8/6/2011
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t OnPathHost
    (const char_t* chars,
     ssize_t length=-1)
#if defined(CFILEPATHPARSEREVENTST_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CFILEPATHPARSEREVENTST_MEMBER_FUNCS_INTERFACE) 
    {
        ssize_t count = 0;
#if !defined(CFILEPATHPARSEREVENTST_MEMBER_FUNCS_IMPLEMENT)
#else // !defined(CFILEPATHPARSEREVENTST_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CFILEPATHPARSEREVENTST_MEMBER_FUNCS_IMPLEMENT) 
        return count;
    }
#endif // defined(CFILEPATHPARSEREVENTST_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    //  Function: OnPathVolume
    //
    //    Author: $author$
    //      Date: 8/6/2011
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t OnPathVolume
    (const char_t* chars,
     ssize_t length=-1)
#if defined(CFILEPATHPARSEREVENTST_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CFILEPATHPARSEREVENTST_MEMBER_FUNCS_INTERFACE) 
    {
        ssize_t count = 0;
#if !defined(CFILEPATHPARSEREVENTST_MEMBER_FUNCS_IMPLEMENT)
#else // !defined(CFILEPATHPARSEREVENTST_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CFILEPATHPARSEREVENTST_MEMBER_FUNCS_IMPLEMENT) 
        return count;
    }
#endif // defined(CFILEPATHPARSEREVENTST_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    //  Function: OnPathDirectory
    //
    //    Author: $author$
    //      Date: 8/6/2011
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t OnPathDirectory
    (const char_t* chars,
     ssize_t length=-1)
#if defined(CFILEPATHPARSEREVENTST_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CFILEPATHPARSEREVENTST_MEMBER_FUNCS_INTERFACE) 
    {
        ssize_t count = 0;
#if !defined(CFILEPATHPARSEREVENTST_MEMBER_FUNCS_IMPLEMENT)
#else // !defined(CFILEPATHPARSEREVENTST_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CFILEPATHPARSEREVENTST_MEMBER_FUNCS_IMPLEMENT) 
        return count;
    }
#endif // defined(CFILEPATHPARSEREVENTST_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    //  Function: OnPathCurrentDirectory
    //
    //    Author: $author$
    //      Date: 8/6/2011
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t OnPathCurrentDirectory
    (const char_t* chars,
     ssize_t length=-1)
#if defined(CFILEPATHPARSEREVENTST_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CFILEPATHPARSEREVENTST_MEMBER_FUNCS_INTERFACE) 
    {
        ssize_t count = 0;
#if !defined(CFILEPATHPARSEREVENTST_MEMBER_FUNCS_IMPLEMENT)
#else // !defined(CFILEPATHPARSEREVENTST_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CFILEPATHPARSEREVENTST_MEMBER_FUNCS_IMPLEMENT) 
        return count;
    }
#endif // defined(CFILEPATHPARSEREVENTST_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    //  Function: OnPathParentDirectory
    //
    //    Author: $author$
    //      Date: 8/6/2011
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t OnPathParentDirectory
    (const char_t* chars,
     ssize_t length=-1)
#if defined(CFILEPATHPARSEREVENTST_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CFILEPATHPARSEREVENTST_MEMBER_FUNCS_INTERFACE) 
    {
        ssize_t count = 0;
#if !defined(CFILEPATHPARSEREVENTST_MEMBER_FUNCS_IMPLEMENT)
#else // !defined(CFILEPATHPARSEREVENTST_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CFILEPATHPARSEREVENTST_MEMBER_FUNCS_IMPLEMENT) 
        return count;
    }
#endif // defined(CFILEPATHPARSEREVENTST_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    //  Function: OnPathRootDirectory
    //
    //    Author: $author$
    //      Date: 8/6/2011
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t OnPathRootDirectory
    (const char_t* chars,
     ssize_t length=-1)
#if defined(CFILEPATHPARSEREVENTST_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CFILEPATHPARSEREVENTST_MEMBER_FUNCS_INTERFACE) 
    {
        ssize_t count = 0;
#if !defined(CFILEPATHPARSEREVENTST_MEMBER_FUNCS_IMPLEMENT)
#else // !defined(CFILEPATHPARSEREVENTST_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CFILEPATHPARSEREVENTST_MEMBER_FUNCS_IMPLEMENT) 
        return count;
    }
#endif // defined(CFILEPATHPARSEREVENTST_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    //  Function: OnPathRootCurrentDirectory
    //
    //    Author: $author$
    //      Date: 8/6/2011
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t OnPathRootCurrentDirectory
    (const char_t* chars,
     ssize_t length=-1)
#if defined(CFILEPATHPARSEREVENTST_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CFILEPATHPARSEREVENTST_MEMBER_FUNCS_INTERFACE) 
    {
        ssize_t count = 0;
#if !defined(CFILEPATHPARSEREVENTST_MEMBER_FUNCS_IMPLEMENT)
#else // !defined(CFILEPATHPARSEREVENTST_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CFILEPATHPARSEREVENTST_MEMBER_FUNCS_IMPLEMENT) 
        return count;
    }
#endif // defined(CFILEPATHPARSEREVENTST_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    //  Function: OnPathRootParentDirectory
    //
    //    Author: $author$
    //      Date: 8/6/2011
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t OnPathRootParentDirectory
    (const char_t* chars,
     ssize_t length=-1)
#if defined(CFILEPATHPARSEREVENTST_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CFILEPATHPARSEREVENTST_MEMBER_FUNCS_INTERFACE) 
    {
        ssize_t count = 0;
#if !defined(CFILEPATHPARSEREVENTST_MEMBER_FUNCS_IMPLEMENT)
#else // !defined(CFILEPATHPARSEREVENTST_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CFILEPATHPARSEREVENTST_MEMBER_FUNCS_IMPLEMENT) 
        return count;
    }
#endif // defined(CFILEPATHPARSEREVENTST_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    //  Function: OnPathFileBase
    //
    //    Author: $author$
    //      Date: 8/6/2011
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t OnPathFileBase
    (const char_t* chars,
     ssize_t length=-1)
#if defined(CFILEPATHPARSEREVENTST_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CFILEPATHPARSEREVENTST_MEMBER_FUNCS_INTERFACE) 
    {
        ssize_t count = 0;
#if !defined(CFILEPATHPARSEREVENTST_MEMBER_FUNCS_IMPLEMENT)
#else // !defined(CFILEPATHPARSEREVENTST_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CFILEPATHPARSEREVENTST_MEMBER_FUNCS_IMPLEMENT) 
        return count;
    }
#endif // defined(CFILEPATHPARSEREVENTST_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    //  Function: OnPathRootFileBase
    //
    //    Author: $author$
    //      Date: 8/6/2011
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t OnPathRootFileBase
    (const char_t* chars,
     ssize_t length=-1)
#if defined(CFILEPATHPARSEREVENTST_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CFILEPATHPARSEREVENTST_MEMBER_FUNCS_INTERFACE) 
    {
        ssize_t count = 0;
#if !defined(CFILEPATHPARSEREVENTST_MEMBER_FUNCS_IMPLEMENT)
#else // !defined(CFILEPATHPARSEREVENTST_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CFILEPATHPARSEREVENTST_MEMBER_FUNCS_IMPLEMENT) 
        return count;
    }
#endif // defined(CFILEPATHPARSEREVENTST_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    //  Function: OnPathFileExtension
    //
    //    Author: $author$
    //      Date: 8/6/2011
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t OnPathFileExtension
    (const char_t* chars,
     ssize_t length=-1)
#if defined(CFILEPATHPARSEREVENTST_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CFILEPATHPARSEREVENTST_MEMBER_FUNCS_INTERFACE) 
    {
        ssize_t count = 0;
#if !defined(CFILEPATHPARSEREVENTST_MEMBER_FUNCS_IMPLEMENT)
#else // !defined(CFILEPATHPARSEREVENTST_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CFILEPATHPARSEREVENTST_MEMBER_FUNCS_IMPLEMENT) 
        return count;
    }
#endif // defined(CFILEPATHPARSEREVENTST_MEMBER_FUNCS_INTERFACE) 

#if !defined(CFILEPATHPARSEREVENTST_MEMBERS_ONLY)
};
#undef CDB_CLASS

///////////////////////////////////////////////////////////////////////
// Typedef: cFilePathParserEventsExtend
//
//  Author: $author$
//    Date: 8/6/2011
///////////////////////////////////////////////////////////////////////
typedef cFilePathParserEventsT<>
cFilePathParserEventsExtend;
///////////////////////////////////////////////////////////////////////
//  Class: cFilePathParserEvents
//
// Author: $author$
//   Date: 8/6/2011
///////////////////////////////////////////////////////////////////////
class c_INSTANCE_CLASS cFilePathParserEvents
: public cFilePathParserEventsExtend
{
public:
    typedef cFilePathParserEventsExtend cExtends;
    ///////////////////////////////////////////////////////////////////////
    //  Constructor: cFilePathParserEvents
    //
    //       Author: $author$
    //         Date: 8/6/2011
    ///////////////////////////////////////////////////////////////////////
    cFilePathParserEvents()
    {
    }
    ///////////////////////////////////////////////////////////////////////
    //  Destructor: ~cFilePathParserEvents
    //
    //      Author: $author$
    //        Date: 8/6/2011
    ///////////////////////////////////////////////////////////////////////
    virtual ~cFilePathParserEvents()
    {
    }
};

#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#else // !defined(CFILEPATHPARSEREVENTST_MEMBERS_ONLY) 
#endif // !defined(CFILEPATHPARSEREVENTST_MEMBERS_ONLY) 

#endif // !defined(_CFILEPATHPARSEREVENTS_HPP) || defined(CFILEPATHPARSEREVENTST_MEMBERS_ONLY) 
        

