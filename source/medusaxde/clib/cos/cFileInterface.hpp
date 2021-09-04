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
//   File: cFileInterface.hpp
//
// Author: $author$
//   Date: 5/31/2011
///////////////////////////////////////////////////////////////////////
#if !defined(_CFILEINTERFACE_HPP) || defined(CFILEINTERFACET_MEMBERS_ONLY)
#if !defined(_CFILEINTERFACE_HPP) && !defined(CFILEINTERFACET_MEMBERS_ONLY)
#define _CFILEINTERFACE_HPP
#endif // !defined(_CFILEINTERFACE_HPP) && !defined(CFILEINTERFACET_MEMBERS_ONLY) 

#if !defined(CFILEINTERFACET_MEMBERS_ONLY)
#include "cStreamInterface.hpp"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

class c_INTERFACE_CLASS cFileInterface;

#undef CDB_CLASS
#define CDB_CLASS "cFileInterfaceT"
///////////////////////////////////////////////////////////////////////
//  Class: cFileInterfaceT
//
// Author: $author$
//   Date: 5/31/2011
///////////////////////////////////////////////////////////////////////
template
<class TImplement=cStreamInterface,
 class TWhat=char>

class c_INTERFACE_CLASS cFileInterfaceT
: virtual public TImplement
{
public:
    typedef TImplement cImplements;
#else // !defined(CFILEINTERFACET_MEMBERS_ONLY) 
#endif // !defined(CFILEINTERFACET_MEMBERS_ONLY) 
    
    typedef TWhat tWhat;

#if !defined(CFILEINTERFACET_MEMBERS_ONLY)
// include cFileT member functions interface
//
#define CFILET_MEMBERS_ONLY
#define CFILET_MEMBER_FUNCS_INTERFACE
#include "cFile.hpp"
#undef CFILET_MEMBER_FUNCS_INTERFACE
#undef CFILET_MEMBERS_ONLY
};
#undef CDB_CLASS

#if !defined(CFILEIMPLEMENTT_MEMBERS_ONLY)
class c_IMPLEMENT_CLASS cFileImplement;

#undef CDB_CLASS
#define CDB_CLASS "cFileImplementT"
///////////////////////////////////////////////////////////////////////
//  Class: cFileImplementT
//
// Author: $author$
//   Date: 5/31/2011
///////////////////////////////////////////////////////////////////////
template
<class TInterface=cFileInterface,
 class TImplement=cStreamImplement,
 class TWhat=char>

class c_IMPLEMENT_CLASS cFileImplementT
: virtual public TInterface,
  virtual public TImplement
{
public:
    typedef TInterface cImplements;
#else // !defined(CFILEIMPLEMENTT_MEMBERS_ONLY) 
#endif // !defined(CFILEIMPLEMENTT_MEMBERS_ONLY) 

#if !defined(CFILEIMPLEMENTT_MEMBERS_ONLY)
// include cFileT interface member definitions
//
#define CFILEINTERFACET_MEMBERS_ONLY
#include "cFileInterface.hpp"
#undef CFILEINTERFACET_MEMBERS_ONLY

// include cFileT member functions implement
//
#define CFILET_MEMBERS_ONLY
#define CFILET_MEMBER_FUNCS_IMPLEMENT
#include "cFile.hpp"
#undef CFILET_MEMBER_FUNCS_IMPLEMENT
#undef CFILET_MEMBERS_ONLY
};
#else // !defined(CFILEIMPLEMENTT_MEMBERS_ONLY) 
#endif // !defined(CFILEIMPLEMENTT_MEMBERS_ONLY) 
#undef CDB_CLASS

///////////////////////////////////////////////////////////////////////
// Typedef: cFileInterfaceImplements
//
//  Author: $author$
//    Date: 6/2/2011
///////////////////////////////////////////////////////////////////////
typedef cFileInterfaceT<cStreamInterface,char>
cFileInterfaceImplements;
///////////////////////////////////////////////////////////////////////
//  Class: cFileInterface
//
// Author: $author$
//   Date: 6/2/2011
///////////////////////////////////////////////////////////////////////
class c_INTERFACE_CLASS cFileInterface
: virtual public cFileInterfaceImplements
{
public:
    typedef cFileInterfaceImplements cImplements;
};
///////////////////////////////////////////////////////////////////////
// Typedef: cFileImplementImplements
//
//  Author: $author$
//    Date: 6/2/2011
///////////////////////////////////////////////////////////////////////
typedef cFileImplementT<cFileInterface,cStreamImplement,char>
cFileImplementImplements;
///////////////////////////////////////////////////////////////////////
//  Class: cFileImplement
//
// Author: $author$
//   Date: 6/2/2011
///////////////////////////////////////////////////////////////////////
class c_IMPLEMENT_CLASS cFileImplement
: virtual public cFileImplementImplements
{
public:
    typedef cFileImplementImplements cImplements;
};

#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#else // !defined(CFILEINTERFACET_MEMBERS_ONLY) 
#endif // !defined(CFILEINTERFACET_MEMBERS_ONLY) 

#endif // !defined(_CFILEINTERFACE_HPP) || defined(CFILEINTERFACET_MEMBERS_ONLY) 
