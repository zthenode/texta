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
//   File: cCharFileInterface.hpp
//
// Author: $author$
//   Date: 6/2/2011
///////////////////////////////////////////////////////////////////////
#if !defined(_CCHARFILEINTERFACE_HPP) || defined(CCHARFILEINTERFACET_MEMBERS_ONLY)
#if !defined(_CCHARFILEINTERFACE_HPP) && !defined(CCHARFILEINTERFACET_MEMBERS_ONLY)
#define _CCHARFILEINTERFACE_HPP
#endif // !defined(_CCHARFILEINTERFACE_HPP) && !defined(CCHARFILEINTERFACET_MEMBERS_ONLY) 

#if !defined(CCHARFILEINTERFACET_MEMBERS_ONLY)
#include "cFileInterface.hpp"
#include "cCharStreamInterface.hpp"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

class c_INTERFACE_CLASS cCharFileInterface;

#undef CDB_CLASS
#define CDB_CLASS "cCharFileInterfaceT"
///////////////////////////////////////////////////////////////////////
//  Class: cCharFileInterfaceT
//
// Author: $author$
//   Date: 6/2/2011
///////////////////////////////////////////////////////////////////////
template
<class TImplement=cFileInterface,
 class TStreamImplement=cCharStreamInterface,
 class TWhat=char>

class c_INTERFACE_CLASS cCharFileInterfaceT
: virtual public TImplement,
  virtual public TStreamImplement
{
public:
    typedef TImplement cImplements;
#else // !defined(CCHARFILEINTERFACET_MEMBERS_ONLY) 
#endif // !defined(CCHARFILEINTERFACET_MEMBERS_ONLY) 

    typedef TWhat tWhat;
    typedef tWhat char_t;

#if !defined(CCHARFILEINTERFACET_MEMBERS_ONLY)
// include cCharFileT member functions interface
//
#define CCHARFILET_MEMBERS_ONLY
#define CCHARFILET_MEMBER_FUNCS_INTERFACE
#include "cCharFile.hpp"
#undef CCHARFILET_MEMBER_FUNCS_INTERFACE
#undef CCHARFILET_MEMBERS_ONLY
};
#undef CDB_CLASS

#if !defined(CCHARFILEIMPLEMENTT_MEMBERS_ONLY)
class c_IMPLEMENT_CLASS cCharFileImplement;

#undef CDB_CLASS
#define CDB_CLASS "cCharFileImplementT"
///////////////////////////////////////////////////////////////////////
//  Class: cCharFileImplementT
//
// Author: $author$
//   Date: 6/2/2011
///////////////////////////////////////////////////////////////////////
template
<class TInterface=cCharFileInterface,
 class TImplement=cFileImplement,
 class TWhat=char>

class c_IMPLEMENT_CLASS cCharFileImplementT
: virtual public TInterface,
  virtual public TImplement
{
public:
    typedef TInterface cImplements;
#else // !defined(CCHARFILEIMPLEMENTT_MEMBERS_ONLY) 
#endif // !defined(CCHARFILEIMPLEMENTT_MEMBERS_ONLY) 

#if !defined(CCHARFILEIMPLEMENTT_MEMBERS_ONLY)
// include cCharFileT interface member definitions
//
#define CCHARFILEINTERFACET_MEMBERS_ONLY
#include "cCharFileInterface.hpp"
#undef CCHARFILEINTERFACET_MEMBERS_ONLY

// include cCharFileT member functions implement
//
#define CCHARFILET_MEMBERS_ONLY
#define CCHARFILET_MEMBER_FUNCS_IMPLEMENT
#include "cCharFile.hpp"
#undef CCHARFILET_MEMBER_FUNCS_IMPLEMENT
#undef CCHARFILET_MEMBERS_ONLY
};
#undef CDB_CLASS
#else // !defined(CCHARFILEIMPLEMENTT_MEMBERS_ONLY) 
#endif // !defined(CCHARFILEIMPLEMENTT_MEMBERS_ONLY) 

///////////////////////////////////////////////////////////////////////
// Typedef: cCharFileInterfaceImplements
//
//  Author: $author$
//    Date: 6/2/2011
///////////////////////////////////////////////////////////////////////
typedef cCharFileInterfaceT
<cFileInterface,cCharStreamInterface,char>
cCharFileInterfaceImplements;
///////////////////////////////////////////////////////////////////////
//  Class: cCharFileInterface
//
// Author: $author$
//   Date: 6/2/2011
///////////////////////////////////////////////////////////////////////
class c_INTERFACE_CLASS cCharFileInterface
: virtual public cCharFileInterfaceImplements
{
public:
    typedef cCharFileInterfaceImplements cImplements;
};
///////////////////////////////////////////////////////////////////////
// Typedef: cCharFileImplementImplements
//
//  Author: $author$
//    Date: 6/2/2011
///////////////////////////////////////////////////////////////////////
typedef cCharFileImplementT
<cCharFileInterface,cFileImplement,char>
cCharFileImplementImplements;
///////////////////////////////////////////////////////////////////////
//  Class: cCharFileImplement
//
// Author: $author$
//   Date: 6/2/2011
///////////////////////////////////////////////////////////////////////
class c_IMPLEMENT_CLASS cCharFileImplement
: virtual public cCharFileImplementImplements
{
public:
    typedef cCharFileImplementImplements cImplements;
};

#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#else // !defined(CCHARFILEINTERFACET_MEMBERS_ONLY) 
#endif // !defined(CCHARFILEINTERFACET_MEMBERS_ONLY) 

#endif // !defined(_CCHARFILEINTERFACE_HPP) || defined(CCHARFILEINTERFACET_MEMBERS_ONLY) 
        

