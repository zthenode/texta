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
//   File: cFilePathParserEventsInterface.hpp
//
// Author: $author$
//   Date: 8/6/2011
///////////////////////////////////////////////////////////////////////
#if !defined(_CFILEPATHPARSEREVENTSINTERFACE_HPP) || defined(CFILEPATHPARSEREVENTSINTERFACET_MEMBERS_ONLY)
#if !defined(_CFILEPATHPARSEREVENTSINTERFACE_HPP) && !defined(CFILEPATHPARSEREVENTSINTERFACET_MEMBERS_ONLY)
#define _CFILEPATHPARSEREVENTSINTERFACE_HPP
#endif // !defined(_CFILEPATHPARSEREVENTSINTERFACE_HPP) && !defined(CFILEPATHPARSEREVENTSINTERFACET_MEMBERS_ONLY) 

#if !defined(CFILEPATHPARSEREVENTSINTERFACET_MEMBERS_ONLY)
#include "cInterfaceBase.hpp"
#include "cImplementBase.hpp"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

class c_INTERFACE_CLASS cFilePathParserEventsInterface;

#undef CDB_CLASS
#define CDB_CLASS "cFilePathParserEventsInterfaceT"
///////////////////////////////////////////////////////////////////////
//  Class: cFilePathParserEventsInterfaceT
//
// Author: $author$
//   Date: 8/6/2011
///////////////////////////////////////////////////////////////////////
template
<class TInterface=cFilePathParserEventsInterface,
 class TChar=char,
 class TImplement=cInterfaceBase>

class c_INTERFACE_CLASS cFilePathParserEventsInterfaceT
: virtual public TImplement
{
public:
    typedef TImplement cImplements;
#else // !defined(CFILEPATHPARSEREVENTSINTERFACET_MEMBERS_ONLY) 
#endif // !defined(CFILEPATHPARSEREVENTSINTERFACET_MEMBERS_ONLY) 

    typedef TInterface tInterface;
    typedef TChar char_t;

#if !defined(CFILEPATHPARSEREVENTSINTERFACET_MEMBERS_ONLY)
// include cFilePathParserEventsT member functions interface
//
#define CFILEPATHPARSEREVENTST_MEMBERS_ONLY
#define CFILEPATHPARSEREVENTST_MEMBER_FUNCS_INTERFACE
#include "cFilePathParserEvents.hpp"
#undef CFILEPATHPARSEREVENTST_MEMBER_FUNCS_INTERFACE
#undef CFILEPATHPARSEREVENTST_MEMBERS_ONLY
};
#undef CDB_CLASS

#if !defined(CFILEPATHPARSEREVENTSIMPLEMENTT_MEMBERS_ONLY)
class c_IMPLEMENT_CLASS cFilePathParserEventsImplement;

#undef CDB_CLASS
#define CDB_CLASS "cFilePathParserEventsImplementT"
///////////////////////////////////////////////////////////////////////
//  Class: cFilePathParserEventsImplementT
//
// Author: $author$
//   Date: 8/6/2011
///////////////////////////////////////////////////////////////////////
template
<class TInterface=cFilePathParserEventsInterface,
 class TChar=char,
 class TImplement=cImplementBase>

class c_IMPLEMENT_CLASS cFilePathParserEventsImplementT
: virtual public TInterface,
  virtual public TImplement
{
public:
    //typedef TInterface cImplements;
    typedef TImplement cImplements;
#else // !defined(CFILEPATHPARSEREVENTSIMPLEMENTT_MEMBERS_ONLY) 
#endif // !defined(CFILEPATHPARSEREVENTSIMPLEMENTT_MEMBERS_ONLY) 

#if !defined(CFILEPATHPARSEREVENTSIMPLEMENTT_MEMBERS_ONLY)
// include cFilePathParserEventsT interface member definitions
//
#define CFILEPATHPARSEREVENTSINTERFACET_MEMBERS_ONLY
#include "cFilePathParserEventsInterface.hpp"
#undef CFILEPATHPARSEREVENTSINTERFACET_MEMBERS_ONLY

// include cFilePathParserEventsT member functions implement
//
#define CFILEPATHPARSEREVENTST_MEMBERS_ONLY
#define CFILEPATHPARSEREVENTST_MEMBER_FUNCS_IMPLEMENT
#include "cFilePathParserEvents.hpp"
#undef CFILEPATHPARSEREVENTST_MEMBER_FUNCS_IMPLEMENT
#undef CFILEPATHPARSEREVENTST_MEMBERS_ONLY
};
#undef CDB_CLASS
#else // !defined(CFILEPATHPARSEREVENTSIMPLEMENTT_MEMBERS_ONLY) 
#endif // !defined(CFILEPATHPARSEREVENTSIMPLEMENTT_MEMBERS_ONLY) 

///////////////////////////////////////////////////////////////////////
// Typedef: cFilePathParserEventsInterfaceImplements
//
//  Author: $author$
//    Date: 8/6/2011
///////////////////////////////////////////////////////////////////////
typedef cFilePathParserEventsInterfaceT<>
cFilePathParserEventsInterfaceImplements;
///////////////////////////////////////////////////////////////////////
//  Class: cFilePathParserEventsInterface
//
// Author: $author$
//   Date: 8/6/2011
///////////////////////////////////////////////////////////////////////
class c_INTERFACE_CLASS cFilePathParserEventsInterface
: virtual public cFilePathParserEventsInterfaceImplements
{
public:
    typedef cFilePathParserEventsInterfaceImplements cImplements;
};
///////////////////////////////////////////////////////////////////////
// Typedef: cFilePathParserEventsImplementImplements
//
//  Author: $author$
//    Date: 8/6/2011
///////////////////////////////////////////////////////////////////////
typedef cFilePathParserEventsImplementT<>
cFilePathParserEventsImplementImplements;
///////////////////////////////////////////////////////////////////////
//  Class: cFilePathParserEventsImplement
//
// Author: $author$
//   Date: 8/6/2011
///////////////////////////////////////////////////////////////////////
class c_IMPLEMENT_CLASS cFilePathParserEventsImplement
: virtual public cFilePathParserEventsImplementImplements
{
public:
    typedef cFilePathParserEventsImplementImplements cImplements;
};


#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#else // !defined(CFILEPATHPARSEREVENTSINTERFACET_MEMBERS_ONLY) 
#endif // !defined(CFILEPATHPARSEREVENTSINTERFACET_MEMBERS_ONLY) 

#endif // !defined(_CFILEPATHPARSEREVENTSINTERFACE_HPP) || defined(CFILEPATHPARSEREVENTSINTERFACET_MEMBERS_ONLY) 
        

