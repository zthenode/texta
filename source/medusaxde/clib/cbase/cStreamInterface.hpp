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
//   File: cStreamInterface.hpp
//
// Author: $author$
//   Date: 5/21/2011
///////////////////////////////////////////////////////////////////////
#if !defined(_CSTREAMINTERFACE_HPP) || defined(CSTREAMINTERFACET_MEMBERS_ONLY)
#if !defined(_CSTREAMINTERFACE_HPP) && !defined(CSTREAMINTERFACET_MEMBERS_ONLY)
#define _CSTREAMINTERFACE_HPP
#endif // !defined(_CSTREAMINTERFACE_HPP) && !defined(CSTREAMINTERFACET_MEMBERS_ONLY) 

#if !defined(CSTREAMINTERFACET_MEMBERS_ONLY)
#include "cReaderInterface.hpp"
#include "cWriterInterface.hpp"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

class c_INTERFACE_CLASS cStreamInterface;

#undef CDB_CLASS
#define CDB_CLASS "cStreamInterfaceT"
///////////////////////////////////////////////////////////////////////
//  Class: cStreamInterfaceT
//
// Author: $author$
//   Date: 5/21/2011
///////////////////////////////////////////////////////////////////////
template
<class TReaderImplement=cReaderInterface,
 class TWriterImplement=cWriterInterface,
 class TWhat=char>

class c_INTERFACE_CLASS cStreamInterfaceT
: virtual public TReaderImplement,
  virtual public TWriterImplement
{
public:
    typedef TReaderImplement cReaderImplements;
    typedef TWriterImplement cWriterImplements;
#else // !defined(CSTREAMINTERFACET_MEMBERS_ONLY) 
#endif // !defined(CSTREAMINTERFACET_MEMBERS_ONLY) 

    typedef TWhat tWhat;

#if !defined(CSTREAMINTERFACET_MEMBERS_ONLY)
// include cStreamT member functions interface
//
#define CSTREAMT_MEMBERS_ONLY
#define CSTREAMT_MEMBER_FUNCS_INTERFACE
#include "cStream.hpp"
#undef CSTREAMT_MEMBER_FUNCS_INTERFACE
#undef CSTREAMT_MEMBERS_ONLY
};
#undef CDB_CLASS

#if !defined(CSTREAMIMPLEMENTT_MEMBERS_ONLY)
class c_IMPLEMENT_CLASS cStreamImplement;

#undef CDB_CLASS
#define CDB_CLASS "cStreamImplementT"
///////////////////////////////////////////////////////////////////////
//  Class: cStreamImplementT
//
// Author: $author$
//   Date: 5/21/2011
///////////////////////////////////////////////////////////////////////
template
<class TImplement=cStreamInterface,
 class TReaderImplement=cReaderImplement,
 class TWriterImplement=cWriterImplement,
 class TWhat=char>

class c_IMPLEMENT_CLASS cStreamImplementT
: virtual public TImplement,
  virtual public TReaderImplement,
  virtual public TWriterImplement
{
public:
    typedef TImplement cImplements;
#else // !defined(CSTREAMIMPLEMENTT_MEMBERS_ONLY) 
#endif // !defined(CSTREAMIMPLEMENTT_MEMBERS_ONLY) 

#if !defined(CSTREAMIMPLEMENTT_MEMBERS_ONLY)
// include cStreamT interface member definitions
//
#define CSTREAMINTERFACET_MEMBERS_ONLY
#include "cStreamInterface.hpp"
#undef CSTREAMINTERFACET_MEMBERS_ONLY

// include cStreamT member functions implement
//
#define CSTREAMT_MEMBERS_ONLY
#define CSTREAMT_MEMBER_FUNCS_IMPLEMENT
#include "cStream.hpp"
#undef CSTREAMT_MEMBER_FUNCS_IMPLEMENT
#undef CSTREAMT_MEMBERS_ONLY
};
#undef CDB_CLASS
#else // !defined(CSTREAMIMPLEMENTT_MEMBERS_ONLY) 
#endif // !defined(CSTREAMIMPLEMENTT_MEMBERS_ONLY) 

///////////////////////////////////////////////////////////////////////
// Typedef: cStreamInterfaceImplement
//
//  Author: $author$
//    Date: 5/22/2011
///////////////////////////////////////////////////////////////////////
typedef cStreamInterfaceT
<cReaderInterface,cWriterInterface,char>
cStreamInterfaceImplement;
///////////////////////////////////////////////////////////////////////
//  Class: cStreamInterface
//
// Author: $author$
//   Date: 5/22/2011
///////////////////////////////////////////////////////////////////////
class c_INTERFACE_CLASS cStreamInterface
: virtual public cStreamInterfaceImplement
{
public:
    typedef cStreamInterfaceImplement cImplements;
};
///////////////////////////////////////////////////////////////////////
// Typedef: cStreamImplementImplement
//
//  Author: $author$
//    Date: 5/22/2011
///////////////////////////////////////////////////////////////////////
typedef cStreamImplementT
<cStreamInterface,cReaderImplement,cWriterImplement,char>
cStreamImplementImplement;
///////////////////////////////////////////////////////////////////////
//  Class: cStreamImplement
//
// Author: $author$
//   Date: 5/22/2011
///////////////////////////////////////////////////////////////////////
class c_IMPLEMENT_CLASS cStreamImplement
: virtual public cStreamImplementImplement
{
public:
    typedef cStreamImplementImplement cImplements;
};

#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#else // !defined(CSTREAMINTERFACET_MEMBERS_ONLY) 
#endif // !defined(CSTREAMINTERFACET_MEMBERS_ONLY) 

#endif // !defined(_CSTREAMINTERFACE_HPP) || defined(CSTREAMINTERFACET_MEMBERS_ONLY) 
