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
//   File: cArrayInterface.hpp
//
// Author: $author$
//   Date: 8/14/2011
///////////////////////////////////////////////////////////////////////
#if !defined(_CARRAYINTERFACE_HPP) || defined(CARRAYINTERFACET_MEMBERS_ONLY)
#if !defined(_CARRAYINTERFACE_HPP) && !defined(CARRAYINTERFACET_MEMBERS_ONLY)
#define _CARRAYINTERFACE_HPP
#endif // !defined(_CARRAYINTERFACE_HPP) && !defined(CARRAYINTERFACET_MEMBERS_ONLY) 

#if !defined(CARRAYINTERFACET_MEMBERS_ONLY)
#include "cInterfaceBase.hpp"
#include "cImplementBase.hpp"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

#undef CDB_CLASS
#define CDB_CLASS "cArrayInterfaceT"
///////////////////////////////////////////////////////////////////////
//  Class: cArrayInterfaceT
//
// Author: $author$
//   Date: 8/14/2011
///////////////////////////////////////////////////////////////////////
template
<class TWhat=char,
 class TInterfaceImplements=cInterfaceBase>

class c_INTERFACE_CLASS cArrayInterfaceT
: virtual public TInterfaceImplements
{
public:
    typedef TInterfaceImplements cImplements;
#else // !defined(CARRAYINTERFACET_MEMBERS_ONLY) 
#endif // !defined(CARRAYINTERFACET_MEMBERS_ONLY) 

    typedef TWhat tWhat;
    typedef ssize_t tLength;
    typedef size_t tSize;

#if !defined(CARRAYINTERFACET_MEMBERS_ONLY)
// include cArrayT member functions interface
//
#define CARRAYT_MEMBERS_ONLY
#define CARRAYT_MEMBER_FUNCS_INTERFACE
#include "cArray.hpp"
#undef CARRAYT_MEMBER_FUNCS_INTERFACE
#undef CARRAYT_MEMBERS_ONLY
};
#undef CDB_CLASS

///////////////////////////////////////////////////////////////////////
// Typedef: cArrayInterface
//
//  Author: $author$
//    Date: 8/14/2011
///////////////////////////////////////////////////////////////////////
typedef cArrayInterfaceT<>
cArrayInterface;

#if !defined(CARRAYIMPLEMENTT_MEMBERS_ONLY)
#undef CDB_CLASS
#define CDB_CLASS "cArrayImplementT"
///////////////////////////////////////////////////////////////////////
//  Class: cArrayImplementT
//
// Author: $author$
//   Date: 8/14/2011
///////////////////////////////////////////////////////////////////////
template
<class TInterface=cArrayInterface,
 class TWhat=char,
 class TImplementImplements=cImplementBase>

class c_IMPLEMENT_CLASS cArrayImplementT
: virtual public TInterface,
  virtual public TImplementImplements
{
public:
    //typedef TInterface cImplements;
    typedef TImplementImplements cImplements;
#else // !defined(CARRAYIMPLEMENTT_MEMBERS_ONLY) 
#endif // !defined(CARRAYIMPLEMENTT_MEMBERS_ONLY) 

#if !defined(CARRAYIMPLEMENTT_MEMBERS_ONLY)
// include cArrayT interface member definitions
//
#define CARRAYINTERFACET_MEMBERS_ONLY
#include "cArrayInterface.hpp"
#undef CARRAYINTERFACET_MEMBERS_ONLY

// include cArrayT member functions implement
//
#define CARRAYT_MEMBERS_ONLY
#define CARRAYT_MEMBER_FUNCS_IMPLEMENT
#include "cArray.hpp"
#undef CARRAYT_MEMBER_FUNCS_IMPLEMENT
#undef CARRAYT_MEMBERS_ONLY
};
#undef CDB_CLASS
#else // !defined(CARRAYIMPLEMENTT_MEMBERS_ONLY) 
#endif // !defined(CARRAYIMPLEMENTT_MEMBERS_ONLY) 

///////////////////////////////////////////////////////////////////////
// Typedef: cArrayImplement
//
//  Author: $author$
//    Date: 8/14/2011
///////////////////////////////////////////////////////////////////////
typedef cArrayImplementT<>
cArrayImplement;

///////////////////////////////////////////////////////////////////////
// Typedef: cCharPtrArrayInterface
//
//  Author: $author$
//    Date: 8/14/2011
///////////////////////////////////////////////////////////////////////
typedef cArrayInterfaceT<char*>
cCharPtrArrayInterface;
///////////////////////////////////////////////////////////////////////
// Typedef: cCharPtrArrayImplement
//
//  Author: $author$
//    Date: 8/14/2011
///////////////////////////////////////////////////////////////////////
typedef cArrayImplementT
<cCharPtrArrayInterface,char*>
cCharPtrArrayImplement;

#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#else // !defined(CARRAYINTERFACET_MEMBERS_ONLY) 
#endif // !defined(CARRAYINTERFACET_MEMBERS_ONLY) 

#endif // !defined(_CARRAYINTERFACE_HPP) || defined(CARRAYINTERFACET_MEMBERS_ONLY) 
