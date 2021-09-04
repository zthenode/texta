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
//   File: cWriterInterface.hpp
//
// Author: $author$
//   Date: 3/21/2011
///////////////////////////////////////////////////////////////////////
#if !defined(_CWRITERINTERFACE_HPP) || defined(CWRITERINTERFACET_MEMBERS_ONLY)
#if !defined(_CWRITERINTERFACE_HPP) && !defined(CWRITERINTERFACET_MEMBERS_ONLY)
#define _CWRITERINTERFACE_HPP
#endif // !defined(_CWRITERINTERFACE_HPP) && !defined(CWRITERINTERFACET_MEMBERS_ONLY) 

#if !defined(CWRITERINTERFACET_MEMBERS_ONLY)
#include "cInterfaceBase.hpp"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

class c_INTERFACE_CLASS cWriterInterface;

#undef CDB_CLASS
#define CDB_CLASS "cWriterInterfaceT"
///////////////////////////////////////////////////////////////////////
//  Class: cWriterInterfaceT
//
// Author: $author$
//   Date: 3/21/2011
///////////////////////////////////////////////////////////////////////
template
<class TWriterInterface=cWriterInterface,
 class TWhat=char,
 class TImplement=cInterfaceBase>

class c_INTERFACE_CLASS cWriterInterfaceT
: virtual public TImplement
{
public:
    typedef TImplement cImplements;
#else // !defined(CWRITERINTERFACET_MEMBERS_ONLY) 
#endif // !defined(CWRITERINTERFACET_MEMBERS_ONLY) 

    typedef TWriterInterface tWriterInterface;
    typedef TWhat tWhat;

#if !defined(CWRITERINTERFACET_MEMBERS_ONLY)
// include cWriterT member functions interface
 
#define CWRITERT_MEMBERS_ONLY
#define CWRITERT_MEMBER_FUNCS_INTERFACE
#include "cWriter.hpp"
#undef CWRITERT_MEMBER_FUNCS_INTERFACE
#undef CWRITERT_MEMBERS_ONLY
};
#undef CDB_CLASS

class c_IMPLEMENT_CLASS cWriterImplement;

#undef CDB_CLASS
#define CDB_CLASS "cWriterImplementT"
///////////////////////////////////////////////////////////////////////
//  Class: cWriterImplementT
//
// Author: $author$
//   Date: 5/15/2011
///////////////////////////////////////////////////////////////////////
template
<class TWriterInterface=cWriterInterface,
 class TWhat=char,
 class TImplement=TWriterInterface>

class c_IMPLEMENT_CLASS cWriterImplementT
: virtual public TImplement
{
public:
    typedef TImplement cImplements;

// include cWriterT interface member definitions
 
#define CWRITERINTERFACET_MEMBERS_ONLY
#include "cWriterInterface.hpp"
#undef CWRITERINTERFACET_MEMBERS_ONLY

// include cWriterT member functions implement
 
#define CWRITERT_MEMBERS_ONLY
#define CWRITERT_MEMBER_FUNCS_IMPLEMENT
#include "cWriter.hpp"
#undef CWRITERT_MEMBER_FUNCS_IMPLEMENT
#undef CWRITERT_MEMBERS_ONLY
};
#undef CDB_CLASS

///////////////////////////////////////////////////////////////////////
// Typedef: cWriterInterfaceImplement
//
//  Author: $author$
//    Date: 5/15/2011
///////////////////////////////////////////////////////////////////////
typedef cWriterInterfaceT
<cWriterInterface, char>
cWriterInterfaceImplement;
///////////////////////////////////////////////////////////////////////
//  Class: cWriterInterface
//
// Author: $author$
//   Date: 5/15/2011
///////////////////////////////////////////////////////////////////////
class c_INTERFACE_CLASS cWriterInterface
: virtual public cWriterInterfaceImplement
{
public:
    typedef cWriterInterfaceImplement cImplements;
};
///////////////////////////////////////////////////////////////////////
// Typedef: cWriterImplementImplement
//
//  Author: $author$
//    Date: 5/15/2011
///////////////////////////////////////////////////////////////////////
typedef cWriterImplementT
<cWriterInterface, char>
cWriterImplementImplement;
///////////////////////////////////////////////////////////////////////
//  Class: cWriterImplement
//
// Author: $author$
//   Date: 5/15/2011
///////////////////////////////////////////////////////////////////////
class c_IMPLEMENT_CLASS cWriterImplement
: virtual public cWriterImplementImplement
{
public:
    typedef cWriterImplementImplement cImplements;
};

//
// BYTE
//
class c_INTERFACE_CLASS cBYTEWriterInterface;
typedef cWriterInterfaceT
<cBYTEWriterInterface, BYTE> cBYTEWriterInterfaceImplement;
///////////////////////////////////////////////////////////////////////
//  Class: cBYTEWriterInterface
//
// Author: $author$
//   Date: 5/15/2011
///////////////////////////////////////////////////////////////////////
class c_INTERFACE_CLASS cBYTEWriterInterface
: virtual public cBYTEWriterInterfaceImplement {
public:
    typedef cBYTEWriterInterfaceImplement cImplements;
};
typedef cWriterImplementT
<cBYTEWriterInterface, BYTE> cBYTEWriterImplementImplement;
///////////////////////////////////////////////////////////////////////
//  Class: cBYTEWriterImplement
//
// Author: $author$
//   Date: 5/15/2011
///////////////////////////////////////////////////////////////////////
class c_IMPLEMENT_CLASS cBYTEWriterImplement
: virtual public cBYTEWriterImplementImplement
{
public:
    typedef cBYTEWriterImplementImplement cImplements;
};

#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#else // !defined(CWRITERINTERFACET_MEMBERS_ONLY) 
#endif // !defined(CWRITERINTERFACET_MEMBERS_ONLY) 

#endif // !defined(_CWRITERINTERFACE_HPP) || defined(CWRITERINTERFACET_MEMBERS_ONLY)

