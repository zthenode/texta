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
//   File: cMainInterface.hpp
//
// Author: $author$
//   Date: 6/1/2011
///////////////////////////////////////////////////////////////////////
#if !defined(_CMAININTERFACE_HPP) || defined(CMAININTERFACET_MEMBERS_ONLY)
#if !defined(_CMAININTERFACE_HPP) && !defined(CMAININTERFACET_MEMBERS_ONLY)
#define _CMAININTERFACE_HPP
#endif // !defined(_CMAININTERFACE_HPP) && !defined(CMAININTERFACET_MEMBERS_ONLY) 

#if !defined(CMAININTERFACET_MEMBERS_ONLY)
#include "cInterfaceBase.hpp"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

class c_INTERFACE_CLASS cMainInterface;

#undef CDB_CLASS
#define CDB_CLASS "cMainInterfaceT"
///////////////////////////////////////////////////////////////////////
//  Class: cMainInterfaceT
//
// Author: $author$
//   Date: 6/1/2011
///////////////////////////////////////////////////////////////////////
template
<class TDerive=cMainInterface,
 class TChar=char,
 class TImplement=cInterfaceBase>

class c_INTERFACE_CLASS cMainInterfaceT
: virtual public TImplement
{
public:
    typedef TImplement cImplements;
    typedef TDerive tMainInterface;
#else // !defined(CMAININTERFACET_MEMBERS_ONLY) 
#endif // !defined(CMAININTERFACET_MEMBERS_ONLY) 

    typedef TChar char_t;

#if !defined(CMAININTERFACET_MEMBERS_ONLY)
// include cMainT member functions interface
//
#define CMAINT_MEMBERS_ONLY
#define CMAINT_MEMBER_FUNCS_INTERFACE
#include "cMain.hpp"
#undef CMAINT_MEMBER_FUNCS_INTERFACE
#undef CMAINT_MEMBERS_ONLY
};
#undef CDB_CLASS

#if !defined(CMAINIMPLEMENTT_MEMBERS_ONLY)
class c_IMPLEMENT_CLASS cMainImplement;

#undef CDB_CLASS
#define CDB_CLASS "cMainImplementT"
///////////////////////////////////////////////////////////////////////
//  Class: cMainImplementT
//
// Author: $author$
//   Date: 6/1/2011
///////////////////////////////////////////////////////////////////////
template
<class TImplement=cMainInterface,
 class TChar=char>

class c_IMPLEMENT_CLASS cMainImplementT
: virtual public TImplement
{
public:
    typedef TImplement cImplements;
    typedef TImplement tMainInterface;
#else // !defined(CMAINIMPLEMENTT_MEMBERS_ONLY) 
#endif // !defined(CMAINIMPLEMENTT_MEMBERS_ONLY) 

#if !defined(CMAINIMPLEMENTT_MEMBERS_ONLY)
// include cMainT interface member definitions
//
#define CMAININTERFACET_MEMBERS_ONLY
#include "cMainInterface.hpp"
#undef CMAININTERFACET_MEMBERS_ONLY

// include cMainT member functions implement
//
#define CMAINT_MEMBERS_ONLY
#define CMAINT_MEMBER_FUNCS_IMPLEMENT
#include "cMain.hpp"
#undef CMAINT_MEMBER_FUNCS_IMPLEMENT
#undef CMAINT_MEMBERS_ONLY
};
#undef CDB_CLASS
#else // !defined(CMAINIMPLEMENTT_MEMBERS_ONLY) 
#endif // !defined(CMAINIMPLEMENTT_MEMBERS_ONLY) 

///////////////////////////////////////////////////////////////////////
// Typedef: cMainInterfaceImplements
//
//  Author: $author$
//    Date: 6/2/2011
///////////////////////////////////////////////////////////////////////
typedef cMainInterfaceT<cMainInterface,char>
cMainInterfaceImplements;
///////////////////////////////////////////////////////////////////////
//  Class: cMainInterface
//
// Author: $author$
//   Date: 6/2/2011
///////////////////////////////////////////////////////////////////////
class c_INTERFACE_CLASS cMainInterface
: virtual public cMainInterfaceImplements
{
public:
    typedef cMainInterfaceImplements cImplements;
};
///////////////////////////////////////////////////////////////////////
// Typedef: cMainImplementImplements
//
//  Author: $author$
//    Date: 6/2/2011
///////////////////////////////////////////////////////////////////////
typedef cMainImplementT<cMainInterface,char>
cMainImplementImplements;
///////////////////////////////////////////////////////////////////////
//  Class: cMainImplement
//
// Author: $author$
//   Date: 6/2/2011
///////////////////////////////////////////////////////////////////////
class c_IMPLEMENT_CLASS cMainImplement
: virtual public cMainImplementImplements
{
public:
    typedef cMainImplementImplements cImplements;
};

#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#else // !defined(CMAININTERFACET_MEMBERS_ONLY) 
#endif // !defined(CMAININTERFACET_MEMBERS_ONLY) 

#endif // !defined(_CMAININTERFACE_HPP) || defined(CMAININTERFACET_MEMBERS_ONLY) 

