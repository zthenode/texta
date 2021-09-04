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
//   File: cFilePathParserInterface.hpp
//
// Author: $author$
//   Date: 8/6/2011
///////////////////////////////////////////////////////////////////////
#if !defined(_CFILEPATHPARSERINTERFACE_HPP) || defined(CFILEPATHPARSERINTERFACET_MEMBERS_ONLY)
#if !defined(_CFILEPATHPARSERINTERFACE_HPP) && !defined(CFILEPATHPARSERINTERFACET_MEMBERS_ONLY)
#define _CFILEPATHPARSERINTERFACE_HPP
#endif // !defined(_CFILEPATHPARSERINTERFACE_HPP) && !defined(CFILEPATHPARSERINTERFACET_MEMBERS_ONLY) 

#if !defined(CFILEPATHPARSERINTERFACET_MEMBERS_ONLY)
#include "cFilePathParserEventsInterface.hpp"
#include "cCharWriterInterface.hpp"
#include "cString.hpp"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

class c_INTERFACE_CLASS cFilePathParserInterface;

#undef CDB_CLASS
#define CDB_CLASS "cFilePathParserInterfaceT"
///////////////////////////////////////////////////////////////////////
//  Class: cFilePathParserInterfaceT
//
// Author: $author$
//   Date: 8/6/2011
///////////////////////////////////////////////////////////////////////
template
<class TWriterInterface=cCharWriterInterface,
 class TString=cString,
 class TChar=char,
 class TImplement=TWriterInterface>

class c_INTERFACE_CLASS cFilePathParserInterfaceT
: virtual public TImplement
{
public:
    typedef TImplement cImplements;
#else // !defined(CFILEPATHPARSERINTERFACET_MEMBERS_ONLY) 
#endif // !defined(CFILEPATHPARSERINTERFACET_MEMBERS_ONLY) 

    typedef TString tString;
    typedef TChar char_t;

#if !defined(CFILEPATHPARSERINTERFACET_MEMBERS_ONLY)
// include cFilePathParseT member functions interface
//
#define CFILEPATHPARSERT_MEMBERS_ONLY
#define CFILEPATHPARSERT_MEMBER_FUNCS_INTERFACE
#include "cFilePathParser.hpp"
#undef CFILEPATHPARSERT_MEMBER_FUNCS_INTERFACE
#undef CFILEPATHPARSERT_MEMBERS_ONLY
};
#undef CDB_CLASS

#if !defined(CFILEPATHPARSERIMPLEMENTT_MEMBERS_ONLY)
class c_IMPLEMENT_CLASS cFilePathParserImplement;

#undef CDB_CLASS
#define CDB_CLASS "cFilePathParserImplementT"
///////////////////////////////////////////////////////////////////////
//  Class: cFilePathParserImplementT
//
// Author: $author$
//   Date: 8/6/2011
///////////////////////////////////////////////////////////////////////
template
<class TInterface=cFilePathParserInterface,
 class TWriterImplement=cCharWriterImplement,
 class TWriterInterface=cCharWriterInterface,
 class TString=cString,
 class TChar=char,
 class TImplement=TWriterImplement>

class c_IMPLEMENT_CLASS cFilePathParserImplementT
: virtual public TInterface,
  virtual public TImplement
{
public:
    //typedef TInterface cImplements;
    typedef TImplement cImplements;
#else // !defined(CFILEPATHPARSERIMPLEMENTT_MEMBERS_ONLY) 
#endif // !defined(CFILEPATHPARSERIMPLEMENTT_MEMBERS_ONLY) 

#if !defined(CFILEPATHPARSERIMPLEMENTT_MEMBERS_ONLY)
// include cFilePathParserT interface member definitions
//
#define CFILEPATHPARSERINTERFACET_MEMBERS_ONLY
#include "cFilePathParserInterface.hpp"
#undef CFILEPATHPARSERINTERFACET_MEMBERS_ONLY

// include cFilePathParserT member functions implement
// 
#define CFILEPATHPARSERT_MEMBERS_ONLY
#define CFILEPATHPARSERT_MEMBER_FUNCS_IMPLEMENT
#include "cFilePathParser.hpp"
#undef CFILEPATHPARSERT_MEMBER_FUNCS_IMPLEMENT
#undef CFILEPATHPARSERT_MEMBERS_ONLY
};
#undef CDB_CLASS
#else // !defined(CFILEPATHPARSERIMPLEMENTT_MEMBERS_ONLY) 
#endif // !defined(CFILEPATHPARSERIMPLEMENTT_MEMBERS_ONLY) 

///////////////////////////////////////////////////////////////////////
// Typedef: cFilePathParserInterfaceImplements
//
//  Author: $author$
//    Date: 8/6/2011
///////////////////////////////////////////////////////////////////////
typedef cFilePathParserInterfaceT<>
cFilePathParserInterfaceImplements;
///////////////////////////////////////////////////////////////////////
//  Class: cFilePathParserInterface
//
// Author: $author$
//   Date: 8/6/2011
///////////////////////////////////////////////////////////////////////
class c_INTERFACE_CLASS cFilePathParserInterface
: virtual public cFilePathParserInterfaceImplements
{
public:
    typedef cFilePathParserInterfaceImplements cImplements;
};
///////////////////////////////////////////////////////////////////////
// Typedef: cFilePathParserImplementImplements
//
//  Author: $author$
//    Date: 8/6/2011
///////////////////////////////////////////////////////////////////////
typedef cFilePathParserImplementT<>
cFilePathParserImplementImplements;
///////////////////////////////////////////////////////////////////////
//  Class: cFilePathParserImplement
//
// Author: $author$
//   Date: 8/6/2011
///////////////////////////////////////////////////////////////////////
class c_IMPLEMENT_CLASS cFilePathParserImplement
: virtual public cFilePathParserImplementImplements
{
public:
    typedef cFilePathParserImplementImplements cImplements;
};

#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#else // !defined(CFILEPATHPARSERINTERFACET_MEMBERS_ONLY) 
#endif // !defined(CFILEPATHPARSERINTERFACET_MEMBERS_ONLY) 

#endif // !defined(_CFILEPATHPARSERINTERFACE_HPP) || defined(CFILEPATHPARSERINTERFACET_MEMBERS_ONLY) 
