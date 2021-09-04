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
//   File: cCharReaderInterface.hpp
//
// Author: $author$
//   Date: 5/15/2011
///////////////////////////////////////////////////////////////////////
#if !defined(_CCHARREADERINTERFACE_HPP) || defined(CCHARREADERINTERFACET_MEMBERS_ONLY)
#if !defined(_CCHARREADERINTERFACE_HPP) && !defined(CCHARREADERINTERFACET_MEMBERS_ONLY)
#define _CCHARREADERINTERFACE_HPP
#endif // !defined(_CCHARREADERINTERFACE_HPP) && !defined(CCHARREADERINTERFACET_MEMBERS_ONLY) 

#if !defined(CCHARREADERINTERFACET_MEMBERS_ONLY)
#include "cReaderInterface.hpp"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

class c_INTERFACE_CLASS cCharReaderInterface;

#undef CDB_CLASS
#define CDB_CLASS "cCharReaderInterfaceT"
///////////////////////////////////////////////////////////////////////
//  Class: cCharReaderInterfaceT
//
// Author: $author$
//   Date: 5/15/2011
///////////////////////////////////////////////////////////////////////
template
<class TImplement=cReaderInterface,
 class TWhat=char>

class c_INTERFACE_CLASS cCharReaderInterfaceT
: virtual public TImplement
{
public:
    typedef TImplement cImplements;
#else // !defined(CCHARREADERINTERFACET_MEMBERS_ONLY) 
#endif // !defined(CCHARREADERINTERFACET_MEMBERS_ONLY) 

    typedef TWhat tWhat;
    typedef tWhat char_t;

#if !defined(CCHARREADERINTERFACET_MEMBERS_ONLY)
// include cCharReaderT member functions interface
 
#define CCHARREADERT_MEMBERS_ONLY
#define CCHARREADERT_MEMBER_FUNCS_INTERFACE
#include "cCharReader.hpp"
#undef CCHARREADERT_MEMBER_FUNCS_INTERFACE
#undef CCHARREADERT_MEMBERS_ONLY
};
#undef CDB_CLASS

#undef CDB_CLASS
#define CDB_CLASS "cCharReaderImplementT"
///////////////////////////////////////////////////////////////////////
//  Class: cCharReaderImplementT
//
// Author: $author$
//   Date: 5/15/2011
///////////////////////////////////////////////////////////////////////
template
<class TInterface=cCharReaderInterface,
 class TImplement=cReaderImplement,
 class TWhat=char>

class c_IMPLEMENT_CLASS cCharReaderImplementT
: virtual public TInterface,
  virtual public TImplement
{
public:
    typedef TInterface cImplements;
    typedef TInterface tCharReaderInterface;

// include cCharReaderT interface member definitions
 
#define CCHARREADERINTERFACET_MEMBERS_ONLY
#include "cCharReaderInterface.hpp"
#undef CCHARREADERINTERFACET_MEMBERS_ONLY

// include cCharReaderT member functions implement
 
#define CCHARREADERT_MEMBERS_ONLY
#define CCHARREADERT_MEMBER_FUNCS_IMPLEMENT
#include "cCharReader.hpp"
#undef CCHARREADERT_MEMBER_FUNCS_IMPLEMENT
#undef CCHARREADERT_MEMBERS_ONLY
};
#undef CDB_CLASS

///////////////////////////////////////////////////////////////////////
// Typedef: cCharReaderInterfaceImplement
//
//  Author: $author$
//    Date: 5/22/2011
///////////////////////////////////////////////////////////////////////
typedef cCharReaderInterfaceT<cReaderInterface,char>
cCharReaderInterfaceImplement;
///////////////////////////////////////////////////////////////////////
//  Class: cCharReaderInterface
//
// Author: $author$
//   Date: 5/22/2011
///////////////////////////////////////////////////////////////////////
class c_INTERFACE_CLASS cCharReaderInterface
: virtual public cCharReaderInterfaceImplement
{
public:
    typedef cCharReaderInterfaceImplement cImplements;
};
///////////////////////////////////////////////////////////////////////
// Typedef: cCharReaderImplementImplement
//
//  Author: $author$
//    Date: 5/22/2011
///////////////////////////////////////////////////////////////////////
typedef cCharReaderImplementT
<cCharReaderInterface,cReaderImplement,char>
cCharReaderImplementImplement;
///////////////////////////////////////////////////////////////////////
//  Class: cCharReaderImplement
//
// Author: $author$
//   Date: 5/22/2011
///////////////////////////////////////////////////////////////////////
class c_IMPLEMENT_CLASS cCharReaderImplement
: virtual public cCharReaderImplementImplement
{
public:
    typedef cCharReaderImplementImplement cImplements;
};

#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#else // !defined(CCHARREADERINTERFACET_MEMBERS_ONLY) 
#endif // !defined(CCHARREADERINTERFACET_MEMBERS_ONLY) 

#endif // !defined(_CCHARREADERINTERFACE_HPP) || defined(CCHARREADERINTERFACET_MEMBERS_ONLY) 

