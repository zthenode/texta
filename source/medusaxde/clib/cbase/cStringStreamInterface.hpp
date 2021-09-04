///////////////////////////////////////////////////////////////////////
// Copyright (c) 1988-2012 $organization$
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
//   File: cStringStreamInterface.hpp
//
// Author: $author$
//   Date: 11/25/2012
///////////////////////////////////////////////////////////////////////
#if !defined(_CSTRINGSTREAMINTERFACE_HPP) || defined(CSTRINGSTREAMINTERFACET_MEMBERS_ONLY)
#if !defined(_CSTRINGSTREAMINTERFACE_HPP) && !defined(CSTRINGSTREAMINTERFACET_MEMBERS_ONLY)
#define _CSTRINGSTREAMINTERFACE_HPP
#endif // !defined(_CSTRINGSTREAMINTERFACE_HPP) && !defined(CSTRINGSTREAMINTERFACET_MEMBERS_ONLY) 

#if !defined(CSTRINGSTREAMINTERFACET_MEMBERS_ONLY)
#include "cStringInterface.hpp"
#include "cCharStreamInterface.hpp"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

class c_INTERFACE_CLASS cStringStreamInterface;

#undef CDB_CLASS
#define CDB_CLASS "cStringStreamInterfaceT"
///////////////////////////////////////////////////////////////////////
//  Class: cStringStreamInterfaceT
//
// Author: $author$
//   Date: 7/19/2011
///////////////////////////////////////////////////////////////////////
template
<class TStringInterface=cStringInterface,
 class TImplement=cCharStreamInterface,
 class TChar=char>

class c_INTERFACE_CLASS cStringStreamInterfaceT
: virtual public TImplement
{
public:
    typedef TImplement cImplements;
#else // !defined(CSTRINGSTREAMINTERFACET_MEMBERS_ONLY) 
#endif // !defined(CSTRINGSTREAMINTERFACET_MEMBERS_ONLY) 

    typedef TStringInterface tStringInterface;
    typedef TChar char_t;

#if !defined(CSTRINGSTREAMINTERFACET_MEMBERS_ONLY)
// include cStringStreamT member functions interface
//
#define CSTRINGSTREAMT_MEMBERS_ONLY
#define CSTRINGSTREAMT_MEMBER_FUNCS_INTERFACE
#include "cStringStream.hpp"
#undef CSTRINGSTREAMT_MEMBER_FUNCS_INTERFACE
#undef CSTRINGSTREAMT_MEMBERS_ONLY
};
#undef CDB_CLASS

#if !defined(CSTRINGSTREAMIMPLEMENTT_MEMBERS_ONLY)
class c_IMPLEMENT_CLASS cStringStreamImplement;

#undef CDB_CLASS
#define CDB_CLASS "cStringStreamImplementT"
///////////////////////////////////////////////////////////////////////
//  Class: cStringStreamImplementT
//
// Author: $author$
//   Date: 7/19/2011
///////////////////////////////////////////////////////////////////////
template
<class TInterfaceImplement=cStringStreamInterface,
 class TStringInterface=cStringInterface,
 class TImplementImplement=cCharStreamImplement,
 class TChar=char>

class c_IMPLEMENT_CLASS cStringStreamImplementT
: virtual public TInterfaceImplement,
  virtual public TImplementImplement
{
public:
    //typedef TInterfaceImplement cImplements;
    typedef TImplementImplement cImplements;
#else // !defined(CSTRINGSTREAMIMPLEMENTT_MEMBERS_ONLY) 
#endif // !defined(CSTRINGSTREAMIMPLEMENTT_MEMBERS_ONLY) 

#if !defined(CSTRINGSTREAMIMPLEMENTT_MEMBERS_ONLY)
// include cStringStream interface member definitions
//
#define CSTRINGSTREAMINTERFACET_MEMBERS_ONLY
#include "cStringStreamInterface.hpp"
#undef CSTRINGSTREAMINTERFACET_MEMBERS_ONLY

// include cStringStream member functions implement
//
#define CSTRINGSTREAMT_MEMBERS_ONLY
#define CSTRINGSTREAMT_MEMBER_FUNCS_IMPLEMENT
#include "cStringStream.hpp"
#undef CSTRINGSTREAMT_MEMBER_FUNCS_IMPLEMENT
#undef CSTRINGSTREAMT_MEMBERS_ONLY
};
#undef CDB_CLASS
#else // !defined(CSTRINGSTREAMIMPLEMENTT_MEMBERS_ONLY) 
#endif // !defined(CSTRINGSTREAMIMPLEMENTT_MEMBERS_ONLY) 

///////////////////////////////////////////////////////////////////////
// Typedef: cStringStreamInterfaceImplements
//
//  Author: $author$
//    Date: 7/20/2011
///////////////////////////////////////////////////////////////////////
typedef cStringStreamInterfaceT<>
cStringStreamInterfaceImplements;
///////////////////////////////////////////////////////////////////////
//  Class: cStringStreamInterface
//
// Author: $author$
//   Date: 7/20/2011
///////////////////////////////////////////////////////////////////////
class c_INTERFACE_CLASS cStringStreamInterface
: virtual public cStringStreamInterfaceImplements
{
public:
    typedef cStringStreamInterfaceImplements cImplements;
};
///////////////////////////////////////////////////////////////////////
// Typedef: cStringStreamImplementImplements
//
//  Author: $author$
//    Date: 7/20/2011
///////////////////////////////////////////////////////////////////////
typedef cStringStreamImplementT<>
cStringStreamImplementImplements;
///////////////////////////////////////////////////////////////////////
//  Class: cStringStreamImplement
//
// Author: $author$
//   Date: 7/20/2011
///////////////////////////////////////////////////////////////////////
class c_IMPLEMENT_CLASS cStringStreamImplement
: virtual public cStringStreamImplementImplements
{
public:
    typedef cStringStreamImplementImplements cImplements;
};

#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#else // !defined(CSTRINGSTREAMINTERFACET_MEMBERS_ONLY) 
#endif // !defined(CSTRINGSTREAMINTERFACET_MEMBERS_ONLY) 

#endif // !defined(_CSTRINGSTREAMINTERFACE_HPP) || defined(CSTRINGSTREAMINTERFACET_MEMBERS_ONLY) 
