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
//   File: cReaderInterface.hpp
//
// Author: $author$
//   Date: 3/21/2011
///////////////////////////////////////////////////////////////////////
#if !defined(_CREADERINTERFACE_HPP) || defined(CREADERINTERFACET_MEMBERS_ONLY)
#if !defined(_CREADERINTERFACE_HPP) && !defined(CREADERINTERFACET_MEMBERS_ONLY)
#define _CREADERINTERFACE_HPP
#endif // !defined(_CREADERINTERFACE_HPP) && !defined(CREADERINTERFACET_MEMBERS_ONLY) 

#if !defined(CREADERINTERFACET_MEMBERS_ONLY)
#include "cInterfaceBase.hpp"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

class c_INTERFACE_CLASS cReaderInterface;

#undef CDB_CLASS
#define CDB_CLASS "cReaderInterfaceT"
///////////////////////////////////////////////////////////////////////
//  Class: cReaderInterfaceT
//
// Author: $author$
//   Date: 3/21/2011
///////////////////////////////////////////////////////////////////////
template
<class TWhat=char,
 class TImplement=cInterfaceBase>
 
class c_INTERFACE_CLASS cReaderInterfaceT
: virtual public TImplement
{
public:
    typedef TImplement cImplements;
#else // !defined(CREADERINTERFACET_MEMBERS_ONLY) 
#endif // !defined(CREADERINTERFACET_MEMBERS_ONLY) 

    typedef TWhat tWhat;

#if !defined(CREADERINTERFACET_MEMBERS_ONLY)
// include cReaderT member functions interface
 
#define CREADERT_MEMBERS_ONLY
#define CREADERT_MEMBER_FUNCS_INTERFACE
#include "cReader.hpp"
#undef CREADERT_MEMBER_FUNCS_INTERFACE
#undef CREADERT_MEMBERS_ONLY
};
#undef CDB_CLASS

class c_IMPLEMENT_CLASS cReaderImplement;

#undef CDB_CLASS
#define CDB_CLASS "cReaderImplementT"
///////////////////////////////////////////////////////////////////////
//  Class: cReaderImplementT
//
// Author: $author$
//   Date: 5/15/2011
///////////////////////////////////////////////////////////////////////
template
<class TImplement=cReaderInterface,
 class TWhat=char>

class c_IMPLEMENT_CLASS cReaderImplementT
: virtual public TImplement
{
public:
    typedef TImplement cImplements;

// include cReaderT interface member definitions
 
#define CREADERINTERFACET_MEMBERS_ONLY
#include "cReaderInterface.hpp"
#undef CREADERINTERFACET_MEMBERS_ONLY

// include cReaderT member functions implement

#define CREADERT_MEMBERS_ONLY
#define CREADERT_MEMBER_FUNCS_IMPLEMENT
#include "cReader.hpp"
#undef CREADERT_MEMBER_FUNCS_IMPLEMENT
#undef CREADERT_MEMBERS_ONLY
};
#undef CDB_CLASS

///////////////////////////////////////////////////////////////////////
// Typedef: cReaderInterfaceImplement
//
//  Author: $author$
//    Date: 5/15/2011
///////////////////////////////////////////////////////////////////////
typedef cReaderInterfaceT<char>
cReaderInterfaceImplement;
///////////////////////////////////////////////////////////////////////
//  Class: cReaderInterface
//
// Author: $author$
//   Date: 5/15/2011
///////////////////////////////////////////////////////////////////////
class c_INTERFACE_CLASS cReaderInterface
: virtual public cReaderInterfaceImplement
{
public:
    typedef cReaderInterfaceImplement cImplements;
};
///////////////////////////////////////////////////////////////////////
// Typedef: cReaderImplementImplement
//
//  Author: $author$
//    Date: 5/15/2011
///////////////////////////////////////////////////////////////////////
typedef cReaderImplementT
<cReaderInterface,char>
cReaderImplementImplement;
///////////////////////////////////////////////////////////////////////
//  Class: cReaderImplement
//
// Author: $author$
//   Date: 5/15/2011
///////////////////////////////////////////////////////////////////////
class c_IMPLEMENT_CLASS cReaderImplement
: virtual public cReaderImplementImplement
{
public:
    typedef cReaderImplementImplement cImplements;
};

#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#else // !defined(CREADERINTERFACET_MEMBERS_ONLY) 
#endif // !defined(CREADERINTERFACET_MEMBERS_ONLY) 

#endif // !defined(_CREADERINTERFACE_HPP) || defined(CREADERINTERFACET_MEMBERS_ONLY)

