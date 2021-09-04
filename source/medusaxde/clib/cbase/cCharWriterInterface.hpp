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
//   File: cCharWriterInterface.hpp
//
// Author: $author$
//   Date: 5/18/2011
///////////////////////////////////////////////////////////////////////
#if !defined(_CCHARWRITERINTERFACE_HPP) || defined(CCHARWRITERINTERFACET_MEMBERS_ONLY)
#if !defined(_CCHARWRITERINTERFACE_HPP) && !defined(CCHARWRITERINTERFACET_MEMBERS_ONLY)
#define _CCHARWRITERINTERFACE_HPP
#endif // !defined(_CCHARWRITERINTERFACE_HPP) && !defined(CCHARWRITERINTERFACET_MEMBERS_ONLY) 

#if !defined(CCHARWRITERINTERFACET_MEMBERS_ONLY)
#include "cWriterInterface.hpp"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

class c_INTERFACE_CLASS cCharWriterInterface;

#undef CDB_CLASS
#define CDB_CLASS "cCharWriterInterfaceT"
///////////////////////////////////////////////////////////////////////
//  Class: cCharWriterInterfaceT
//
// Author: $author$
//   Date: 5/18/2011
///////////////////////////////////////////////////////////////////////
template
<class TImplement=cWriterInterface,
 class TWhat=char>

class c_INTERFACE_CLASS cCharWriterInterfaceT
: virtual public TImplement
{
public:
    typedef TImplement cImplements;
#else // !defined(CCHARWRITERINTERFACET_MEMBERS_ONLY) 
#endif // !defined(CCHARWRITERINTERFACET_MEMBERS_ONLY) 

    typedef TWhat tWhat;
    typedef tWhat char_t;

#if !defined(CCHARWRITERINTERFACET_MEMBERS_ONLY)
// include cCharWriterT member functions interface
 
#define CCHARWRITERT_MEMBERS_ONLY
#define CCHARWRITERT_MEMBER_FUNCS_INTERFACE
#include "cCharWriter.hpp"
#undef CCHARWRITERT_MEMBER_FUNCS_INTERFACE
#undef CCHARWRITERT_MEMBERS_ONLY
};
#undef CDB_CLASS

class c_IMPLEMENT_CLASS cCharWriterImplement;

#undef CDB_CLASS
#define CDB_CLASS "cCharWriterImplementT"
///////////////////////////////////////////////////////////////////////
//  Class: cCharWriterImplementT
//
// Author: $author$
//   Date: 5/19/2011
///////////////////////////////////////////////////////////////////////
template
<class TInterface=cCharWriterInterface,
 class TImplement=cWriterImplement,
 class TWhat=char>

class c_IMPLEMENT_CLASS cCharWriterImplementT
: virtual public TInterface,
  virtual public TImplement
{
public:
    typedef TInterface cImplements;

// include cCharWriterT interface member definitions
 
#define CCHARWRITERINTERFACET_MEMBERS_ONLY
#include "cCharWriterInterface.hpp"
#undef CCHARWRITERINTERFACET_MEMBERS_ONLY

// include cCharWriterT member functions implement
 
#define CCHARWRITERT_MEMBERS_ONLY
#define CCHARWRITERT_MEMBER_FUNCS_IMPLEMENT
#include "cCharWriter.hpp"
#undef CCHARWRITERT_MEMBER_FUNCS_IMPLEMENT
#undef CCHARWRITERT_MEMBERS_ONLY
};
#undef CDB_CLASS

///////////////////////////////////////////////////////////////////////
// Typedef: cCharWriterInterfaceImplement
//
//  Author: $author$
//    Date: 5/22/2011
///////////////////////////////////////////////////////////////////////
typedef cCharWriterInterfaceT<cWriterInterface,char>
cCharWriterInterfaceImplement;
///////////////////////////////////////////////////////////////////////
//  Class: cCharWriterInterface
//
// Author: $author$
//   Date: 5/22/2011
///////////////////////////////////////////////////////////////////////
class c_INTERFACE_CLASS cCharWriterInterface
: virtual public cCharWriterInterfaceImplement
{
public:
    typedef cCharWriterInterfaceImplement cImplements;
};
///////////////////////////////////////////////////////////////////////
// Typedef: cCharWriterImplementImplement
//
//  Author: $author$
//    Date: 5/22/2011
///////////////////////////////////////////////////////////////////////
typedef cCharWriterImplementT
<cCharWriterInterface,cWriterImplement,char>
cCharWriterImplementImplement;
///////////////////////////////////////////////////////////////////////
//  Class: cCharWriterImplement
//
// Author: $author$
//   Date: 5/22/2011
///////////////////////////////////////////////////////////////////////
class c_IMPLEMENT_CLASS cCharWriterImplement
: virtual public cCharWriterImplementImplement
{
public:
    typedef cCharWriterImplementImplement cImplements;
};

#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#else // !defined(CCHARWRITERINTERFACET_MEMBERS_ONLY) 
#endif // !defined(CCHARWRITERINTERFACET_MEMBERS_ONLY) 

#endif // !defined(_CCHARWRITERINTERFACE_HPP) || defined(CCHARWRITERINTERFACET_MEMBERS_ONLY) 
        

