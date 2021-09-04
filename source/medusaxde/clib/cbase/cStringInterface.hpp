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
//   File: cStringInterface.hpp
//
// Author: $author$
//   Date: 3/20/2011
///////////////////////////////////////////////////////////////////////
#if !defined(_CSTRINGINTERFACE_HPP) || defined(CSTRINGINTERFACET_MEMBERS_ONLY)
#if !defined(_CSTRINGINTERFACE_HPP) && !defined(CSTRINGINTERFACET_MEMBERS_ONLY)
#define _CSTRINGINTERFACE_HPP
#endif // !defined(_CSTRINGINTERFACE_HPP) && !defined(CSTRINGINTERFACET_MEMBERS_ONLY) 

#if !defined(CSTRINGINTERFACET_MEMBERS_ONLY)
#include "cInterfaceBase.hpp"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

class c_INTERFACE_CLASS cStringInterface;

#undef CDB_CLASS
#define CDB_CLASS "cStringInterfaceT"
///////////////////////////////////////////////////////////////////////
//  Class: cStringInterfaceT
//
// Author: $author$
//   Date: 3/20/2011
///////////////////////////////////////////////////////////////////////
template
<class TDerive=cStringInterface,
 class TChar=char,
 class TImplement=cInterfaceBase>

class c_INTERFACE_CLASS cStringInterfaceT
: virtual public TImplement
{
public:
    typedef TImplement cImplements;
    typedef TDerive cInterface;
#else // !defined(CSTRINGINTERFACET_MEMBERS_ONLY)
#endif // !defined(CSTRINGINTERFACET_MEMBERS_ONLY) 

    typedef TChar char_t;

#if !defined(CSTRINGINTERFACET_MEMBERS_ONLY)
// include cString member functions interface
//
#define CSTRINGT_MEMBERS_ONLY
#define CSTRINGT_MEMBER_FUNCS_INTERFACE
#include "cString.hpp"
#undef CSTRINGT_MEMBER_FUNCS_INTERFACE
#undef CSTRINGT_MEMBERS_ONLY
};
#undef CDB_CLASS

#if !defined(CSTRINGIMPLEMENTT_MEMBERS_ONLY)
class c_IMPLEMENT_CLASS cStringImplement;

#undef CDB_CLASS
#define CDB_CLASS "cStringImplementT"
///////////////////////////////////////////////////////////////////////
//  Class: cStringImplementT
//
// Author: $author$
//   Date: 3/20/2011
///////////////////////////////////////////////////////////////////////
template
<class TImplement=cStringInterface,
 class TChar=char>
 
class c_IMPLEMENT_CLASS cStringImplementT
: virtual public TImplement
{
public:
    typedef TImplement cImplements;
    typedef TImplement cInterface;
#else // !defined(CSTRINGIMPLEMENTT_MEMBERS_ONLY) 
#endif // !defined(CSTRINGIMPLEMENTT_MEMBERS_ONLY) 

#if !defined(CSTRINGIMPLEMENTT_MEMBERS_ONLY)
// include cString interface member definitions
//
#define CSTRINGINTERFACET_MEMBERS_ONLY
#include "cStringInterface.hpp"
#undef CSTRINGINTERFACET_MEMBERS_ONLY

// include cString member functions implement
//
#define CSTRINGT_MEMBERS_ONLY
#define CSTRINGT_MEMBER_FUNCS_IMPLEMENT
#include "cString.hpp"
#undef CSTRINGT_MEMBER_FUNCS_IMPLEMENT
#undef CSTRINGT_MEMBERS_ONLY
};
#undef CDB_CLASS
#else // !defined(CSTRINGIMPLEMENTT_MEMBERS_ONLY) 
#endif // !defined(CSTRINGIMPLEMENTT_MEMBERS_ONLY) 

///////////////////////////////////////////////////////////////////////
// Typedef: cStringInterfaceImplement
//
//  Author: $author$
//    Date: 3/20/2011
///////////////////////////////////////////////////////////////////////
typedef cStringInterfaceT
<cStringInterface, char>
cStringInterfaceImplement;
///////////////////////////////////////////////////////////////////////
//  Class: cStringInterface
//
// Author: $author$
//   Date: 3/20/2011
///////////////////////////////////////////////////////////////////////
class c_INTERFACE_CLASS cStringInterface
: virtual public cStringInterfaceImplement
{
public:
    typedef cStringInterfaceImplement cImplements;
// include cString member functions interface
//
#define xchar wchar
#define xchar_t wchar_t
#define CSTRING_MEMBERS_ONLY
#define CSTRING_MEMBER_FUNCS_INTERFACE
#include "cString_members.hpp"
#undef CSTRING_MEMBER_FUNCS_INTERFACE
#undef CSTRING_MEMBERS_ONLY
#undef xchar_t
#undef xchar
};
///////////////////////////////////////////////////////////////////////
// Typedef: cStringImplementImplement
//
//  Author: $author$
//    Date: 3/20/2011
///////////////////////////////////////////////////////////////////////
typedef cStringImplementT
<cStringInterface, char>
cStringImplementImplement;
///////////////////////////////////////////////////////////////////////
//  Class: cStringImplement
//
// Author: $author$
//   Date: 3/20/2011
///////////////////////////////////////////////////////////////////////
class c_IMPLEMENT_CLASS cStringImplement
: virtual public cStringImplementImplement
{
public:
    typedef cStringImplementImplement cImplements;
// include cString member functions implement
//
#define xchar wchar
#define xchar_t wchar_t
#define CSTRING_MEMBERS_ONLY
#define CSTRING_MEMBER_FUNCS_IMPLEMENT
#include "cString_members.hpp"
#undef CSTRING_MEMBER_FUNCS_IMPLEMENT
#undef CSTRING_MEMBERS_ONLY
#undef xchar_t
#undef xchar
};

class c_INTERFACE_CLASS cTStringInterface;
///////////////////////////////////////////////////////////////////////
// Typedef: cTStringInterfaceImplements
//
//  Author: $author$
//    Date: 7/23/2011
///////////////////////////////////////////////////////////////////////
typedef cStringInterfaceT
<cTStringInterface, tchar_t>
cTStringInterfaceImplements;
///////////////////////////////////////////////////////////////////////
//  Class: cTStringInterface
//
// Author: $author$
//   Date: 7/23/2011
///////////////////////////////////////////////////////////////////////
class c_INTERFACE_CLASS cTStringInterface
: virtual public cTStringInterfaceImplements
{
public:
    typedef cTStringInterfaceImplements cImplements;
};
class c_IMPLEMENT_CLASS cTStringImplement;
///////////////////////////////////////////////////////////////////////
// Typedef: cTStringImplementImplements
//
//  Author: $author$
//    Date: 7/23/2011
///////////////////////////////////////////////////////////////////////
typedef cStringImplementT
<cTStringInterface, tchar_t>
cTStringImplementImplements;
///////////////////////////////////////////////////////////////////////
//  Class: cTStringImplement
//
// Author: $author$
//   Date: 7/23/2011
///////////////////////////////////////////////////////////////////////
class c_IMPLEMENT_CLASS cTStringImplement
: virtual public cTStringImplementImplements
{
public:
    typedef cTStringImplementImplements cImplements;
};

#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#else // !defined(CSTRINGINTERFACET_MEMBERS_ONLY) 
#endif // !defined(CSTRINGINTERFACET_MEMBERS_ONLY) 

#endif // !defined(_CSTRINGINTERFACE_HPP) || defined(CSTRINGINTERFACET_MEMBERS_ONLY) 
