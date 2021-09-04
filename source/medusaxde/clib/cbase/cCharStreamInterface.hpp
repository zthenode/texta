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
//   File: cCharStreamInterface.hpp
//
// Author: $author$
//   Date: 5/21/2011
///////////////////////////////////////////////////////////////////////
#if !defined(_CCHARSTREAMINTERFACE_HPP) || defined(CCHARSTREAMINTERFACET_MEMBERS_ONLY)
#if !defined(_CCHARSTREAMINTERFACE_HPP) && !defined(CCHARSTREAMINTERFACET_MEMBERS_ONLY)
#define _CCHARSTREAMINTERFACE_HPP
#endif // !defined(_CCHARSTREAMINTERFACE_HPP) && !defined(CCHARSTREAMINTERFACET_MEMBERS_ONLY) 

#if !defined(CCHARSTREAMINTERFACET_MEMBERS_ONLY)
#include "cCharReaderInterface.hpp"
#include "cCharWriterInterface.hpp"
#include "cStreamInterface.hpp"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

class c_INTERFACE_CLASS cCharStreamInterface;

#undef CDB_CLASS
#define CDB_CLASS "cCharStreamInterfaceT"
///////////////////////////////////////////////////////////////////////
//  Class: cCharStreamInterfaceT
//
// Author: $author$
//   Date: 5/21/2011
///////////////////////////////////////////////////////////////////////
template
<class TImplement=cStreamInterface,
 class TReaderImplement=cCharReaderInterface,
 class TWriterImplement=cCharWriterInterface,
 class TWhat=char>

class c_INTERFACE_CLASS cCharStreamInterfaceT
: virtual public TImplement,
  virtual public TReaderImplement,
  virtual public TWriterImplement
{
public:
    typedef TReaderImplement cReaderImplements;
    typedef TWriterImplement cWriterImplements;
    typedef TImplement cImplements;
#else // !defined(CCHARSTREAMINTERFACET_MEMBERS_ONLY) 
#endif // !defined(CCHARSTREAMINTERFACET_MEMBERS_ONLY) 

    typedef TWhat tWhat;
    typedef tWhat char_t;

#if !defined(CCHARSTREAMINTERFACET_MEMBERS_ONLY)
// include cCharStream member functions interface
//
#define CCHARSTREAMT_MEMBERS_ONLY
#define CCHARSTREAMT_MEMBER_FUNCS_INTERFACE
#include "cCharStream.hpp"
#undef CCHARSTREAMT_MEMBER_FUNCS_INTERFACE
#undef CCHARSTREAMT_MEMBERS_ONLY
};
#undef CDB_CLASS

#if !defined(CCHARSTREAMINTERFACEIMPLEMENTT_MEMBERS_ONLY)
class c_IMPLEMENT_CLASS cCharStreamImplement;

#undef CDB_CLASS
#define CDB_CLASS "cCharStreamImplementT"
///////////////////////////////////////////////////////////////////////
//  Class: cCharStreamImplementT
//
// Author: $author$
//   Date: 5/21/2011
///////////////////////////////////////////////////////////////////////
template
<class TInterface=cCharStreamInterface,
 class TReaderImplement=cCharReaderImplement,
 class TWriterImplement=cCharWriterImplement,
 class TImplement=cStreamImplement,
 class TWhat=char>

class c_IMPLEMENT_CLASS cCharStreamImplementT
: virtual public TInterface,
  virtual public TImplement,
  virtual public TReaderImplement,
  virtual public TWriterImplement
{
public:
    typedef TInterface cImplements;
#else // !defined(CCHARSTREAMINTERFACEIMPLEMENTT_MEMBERS_ONLY) 
#endif // !defined(CCHARSTREAMINTERFACEIMPLEMENTT_MEMBERS_ONLY) 

#if !defined(CCHARSTREAMINTERFACEIMPLEMENTT_MEMBERS_ONLY)
// include cCharStream interface member definitions
//
#define CCHARSTREAMINTERFACET_MEMBERS_ONLY
#include "cCharStreamInterface.hpp"
#undef CCHARSTREAMINTERFACET_MEMBERS_ONLY

// include cCharStream member functions implement
//
#define CCHARSTREAMT_MEMBERS_ONLY
#define CCHARSTREAMT_MEMBER_FUNCS_IMPLEMENT
#include "cCharStream.hpp"
#undef CCHARSTREAMT_MEMBER_FUNCS_IMPLEMENT
#undef CCHARSTREAMT_MEMBERS_ONLY
};
#undef CDB_CLASS
#else // !defined(CCHARSTREAMINTERFACEIMPLEMENTT_MEMBERS_ONLY) 
#endif // !defined(CCHARSTREAMINTERFACEIMPLEMENTT_MEMBERS_ONLY) 

///////////////////////////////////////////////////////////////////////
// Typedef: cCharStreamInterfaceImplements
//
//  Author: $author$
//    Date: 5/30/2011
///////////////////////////////////////////////////////////////////////
typedef cCharStreamInterfaceT
<cStreamInterface,cCharReaderInterface,cCharWriterInterface,char>
cCharStreamInterfaceImplements;
///////////////////////////////////////////////////////////////////////
//  Class: cCharStreamInterface
//
// Author: $author$
//   Date: 5/30/2011
///////////////////////////////////////////////////////////////////////
class c_INTERFACE_CLASS cCharStreamInterface
: virtual public cCharStreamInterfaceImplements
{
public:
    typedef cCharStreamInterfaceImplements cImplements;
};
///////////////////////////////////////////////////////////////////////
// Typedef: cCharStreamImplementImplements
//
//  Author: $author$
//    Date: 5/30/2011
///////////////////////////////////////////////////////////////////////
typedef cCharStreamImplementT
<cCharStreamInterface,cCharReaderImplement,
 cCharWriterImplement,cStreamImplement,char>
cCharStreamImplementImplements;
///////////////////////////////////////////////////////////////////////
//  Class: cCharStreamImplement
//
// Author: $author$
//   Date: 5/30/2011
///////////////////////////////////////////////////////////////////////
class c_IMPLEMENT_CLASS cCharStreamImplement
: virtual public cCharStreamImplementImplements
{
public:
    typedef cCharStreamImplementImplements cImplements;
};

#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#else // !defined(CCHARSTREAMINTERFACET_MEMBERS_ONLY) 
#endif // !defined(CCHARSTREAMINTERFACET_MEMBERS_ONLY) 

#endif // !defined(_CCHARSTREAMINTERFACE_HPP) || defined(CCHARSTREAMINTERFACET_MEMBERS_ONLY) 

