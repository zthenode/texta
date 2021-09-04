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
//   File: cStringReaderInterface.hpp
//
// Author: $author$
//   Date: 7/19/2011
///////////////////////////////////////////////////////////////////////
#if !defined(_CSTRINGREADERINTERFACE_HPP) || defined(CSTRINGREADERINTERFACET_MEMBERS_ONLY)
#if !defined(_CSTRINGREADERINTERFACE_HPP) && !defined(CSTRINGREADERINTERFACET_MEMBERS_ONLY)
#define _CSTRINGREADERINTERFACE_HPP
#endif // !defined(_CSTRINGREADERINTERFACE_HPP) && !defined(CSTRINGREADERINTERFACET_MEMBERS_ONLY) 

#if !defined(CSTRINGREADERINTERFACET_MEMBERS_ONLY)
#include "cStringInterface.hpp"
#include "cCharReaderInterface.hpp"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

class c_INTERFACE_CLASS cStringReaderInterface;

#undef CDB_CLASS
#define CDB_CLASS "cStringReaderInterfaceT"
///////////////////////////////////////////////////////////////////////
//  Class: cStringReaderInterfaceT
//
// Author: $author$
//   Date: 7/19/2011
///////////////////////////////////////////////////////////////////////
template
<class TStringInterface=cStringInterface,
 class TImplement=cCharReaderInterface,
 class TChar=char>

class c_INTERFACE_CLASS cStringReaderInterfaceT
: virtual public TImplement
{
public:
    typedef TImplement cImplements;
#else // !defined(CSTRINGREADERINTERFACET_MEMBERS_ONLY) 
#endif // !defined(CSTRINGREADERINTERFACET_MEMBERS_ONLY) 

    typedef TStringInterface tStringInterface;
    typedef TChar char_t;

#if !defined(CSTRINGREADERINTERFACET_MEMBERS_ONLY)
// include cStringReaderT member functions interface
//
#define CSTRINGREADERT_MEMBERS_ONLY
#define CSTRINGREADERT_MEMBER_FUNCS_INTERFACE
#include "cStringReader.hpp"
#undef CSTRINGREADERT_MEMBER_FUNCS_INTERFACE
#undef CSTRINGREADERT_MEMBERS_ONLY
};
#undef CDB_CLASS

#if !defined(CSTRINGREADERIMPLEMENTT_MEMBERS_ONLY)
class c_IMPLEMENT_CLASS cStringReaderImplement;

#undef CDB_CLASS
#define CDB_CLASS "cStringReaderImplementT"
///////////////////////////////////////////////////////////////////////
//  Class: cStringReaderImplementT
//
// Author: $author$
//   Date: 7/19/2011
///////////////////////////////////////////////////////////////////////
template
<class TInterfaceImplement=cStringReaderInterface,
 class TStringInterface=cStringInterface,
 class TImplementImplement=cCharReaderImplement,
 class TChar=char>

class c_IMPLEMENT_CLASS cStringReaderImplementT
: virtual public TInterfaceImplement,
  virtual public TImplementImplement
{
public:
    //typedef TInterfaceImplement cImplements;
    typedef TImplementImplement cImplements;
#else // !defined(CSTRINGREADERIMPLEMENTT_MEMBERS_ONLY) 
#endif // !defined(CSTRINGREADERIMPLEMENTT_MEMBERS_ONLY) 

#if !defined(CSTRINGREADERIMPLEMENTT_MEMBERS_ONLY)
// include cStringReader interface member definitions
//
#define CSTRINGREADERINTERFACET_MEMBERS_ONLY
#include "cStringReaderInterface.hpp"
#undef CSTRINGREADERINTERFACET_MEMBERS_ONLY

// include cStringReader member functions implement
//
#define CSTRINGREADERT_MEMBERS_ONLY
#define CSTRINGREADERT_MEMBER_FUNCS_IMPLEMENT
#include "cStringReader.hpp"
#undef CSTRINGREADERT_MEMBER_FUNCS_IMPLEMENT
#undef CSTRINGREADERT_MEMBERS_ONLY
};
#undef CDB_CLASS
#else // !defined(CSTRINGREADERIMPLEMENTT_MEMBERS_ONLY) 
#endif // !defined(CSTRINGREADERIMPLEMENTT_MEMBERS_ONLY) 

///////////////////////////////////////////////////////////////////////
// Typedef: cStringReaderInterfaceImplements
//
//  Author: $author$
//    Date: 7/20/2011
///////////////////////////////////////////////////////////////////////
typedef cStringReaderInterfaceT<>
cStringReaderInterfaceImplements;
///////////////////////////////////////////////////////////////////////
//  Class: cStringReaderInterface
//
// Author: $author$
//   Date: 7/20/2011
///////////////////////////////////////////////////////////////////////
class c_INTERFACE_CLASS cStringReaderInterface
: virtual public cStringReaderInterfaceImplements
{
public:
    typedef cStringReaderInterfaceImplements cImplements;
};
///////////////////////////////////////////////////////////////////////
// Typedef: cStringReaderImplementImplements
//
//  Author: $author$
//    Date: 7/20/2011
///////////////////////////////////////////////////////////////////////
typedef cStringReaderImplementT<>
cStringReaderImplementImplements;
///////////////////////////////////////////////////////////////////////
//  Class: cStringReaderImplement
//
// Author: $author$
//   Date: 7/20/2011
///////////////////////////////////////////////////////////////////////
class c_IMPLEMENT_CLASS cStringReaderImplement
: virtual public cStringReaderImplementImplements
{
public:
    typedef cStringReaderImplementImplements cImplements;
};

#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#else // !defined(CSTRINGREADERINTERFACET_MEMBERS_ONLY) 
#endif // !defined(CSTRINGREADERINTERFACET_MEMBERS_ONLY) 

#endif // !defined(_CSTRINGREADERINTERFACE_HPP) || defined(CSTRINGREADERINTERFACET_MEMBERS_ONLY) 
