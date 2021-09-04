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
//   File: cFilePathInterface.hpp
//
// Author: $author$
//   Date: 8/4/2011
///////////////////////////////////////////////////////////////////////
#if !defined(_CFILEPATHINTERFACE_HPP) || defined(CFILEPATHINTERFACET_MEMBERS_ONLY)
#if !defined(_CFILEPATHINTERFACE_HPP) && !defined(CFILEPATHINTERFACET_MEMBERS_ONLY)
#define _CFILEPATHINTERFACE_HPP
#endif // !defined(_CFILEPATHINTERFACE_HPP) && !defined(CFILEPATHINTERFACET_MEMBERS_ONLY) 

#if !defined(CFILEPATHINTERFACET_MEMBERS_ONLY)
#include "cplatform_path.h"
#include "cString.hpp"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

class c_INTERFACE_CLASS cFilePathInterface;

#undef CDB_CLASS
#define CDB_CLASS "cFilePathInterfaceT"
///////////////////////////////////////////////////////////////////////
//  Class: cFilePathInterfaceT
//
// Author: $author$
//   Date: 8/4/2011
///////////////////////////////////////////////////////////////////////
template
<class TStringInterface=cStringInterface,
 class TString=cString,
 class TChar=char,
 class TImplement=TStringInterface>

class c_INTERFACE_CLASS cFilePathInterfaceT
: virtual public TImplement
{
public:
    typedef TImplement cImplements;
#else // !defined(CFILEPATHINTERFACET_MEMBERS_ONLY) 
#endif // !defined(CFILEPATHINTERFACET_MEMBERS_ONLY) 

    typedef TStringInterface tStringInterface;
    typedef TString tString;
    typedef TChar char_t;

#if !defined(CFILEPATHINTERFACET_MEMBERS_ONLY)
// include cFilePathT member functions interface
//
#define CFILEPATHT_MEMBERS_ONLY
#define CFILEPATHT_MEMBER_FUNCS_INTERFACE
#include "cFilePath.hpp"
#undef CFILEPATHT_MEMBER_FUNCS_INTERFACE
#undef CFILEPATHT_MEMBERS_ONLY
};
#undef CDB_CLASS

#if !defined(CFILEPATHIMPLEMENTT_MEMBERS_ONLY)
class c_IMPLEMENT_CLASS cFilePathImplement;
#undef CDB_CLASS
#define CDB_CLASS "cFilePathImplementT"
///////////////////////////////////////////////////////////////////////
//  Class: cFilePathImplementT
//
// Author: $author$
//   Date: 8/4/2011
///////////////////////////////////////////////////////////////////////
template
<class TInterfaceImplement=cFilePathInterface,
 class TImplementImplement=cStringImplement,
 class TStringInterface=cStringInterface,
 class TString=cString,
 class TChar=char>

class c_IMPLEMENT_CLASS cFilePathImplementT
: virtual public TInterfaceImplement,
  virtual public TImplementImplement
{
public:
    //typedef TInterfaceImplement cImplements;
    typedef TImplementImplement cImplements;
#else // !defined(CFILEPATHIMPLEMENTT_MEMBERS_ONLY) 
#endif // !defined(CFILEPATHIMPLEMENTT_MEMBERS_ONLY) 

#if !defined(CFILEPATHIMPLEMENTT_MEMBERS_ONLY)
// include cFilePathT interface member definitions
//
#define CFILEPATHINTERFACET_MEMBERS_ONLY
#include "cFilePathInterface.hpp"
#undef CFILEPATHINTERFACET_MEMBERS_ONLY

// include cFilePathT member functions implement
//
#define CFILEPATHT_MEMBERS_ONLY
#define CFILEPATHT_MEMBER_FUNCS_IMPLEMENT
#include "cFilePath.hpp"
#undef CFILEPATHT_MEMBER_FUNCS_IMPLEMENT
#undef CFILEPATHT_MEMBERS_ONLY
};
#undef CDB_CLASS
#else // !defined(CFILEPATHIMPLEMENTT_MEMBERS_ONLY) 
#endif // !defined(CFILEPATHIMPLEMENTT_MEMBERS_ONLY) 

///////////////////////////////////////////////////////////////////////
// Typedef: cFilePathInterfaceImplements
//
//  Author: $author$
//    Date: 8/6/2011
///////////////////////////////////////////////////////////////////////
typedef cFilePathInterfaceT<>
cFilePathInterfaceImplements;
///////////////////////////////////////////////////////////////////////
//  Class: cFilePathInterface
//
// Author: $author$
//   Date: 8/6/2011
///////////////////////////////////////////////////////////////////////
class c_INTERFACE_CLASS cFilePathInterface
: virtual public cFilePathInterfaceImplements
{
public:
    typedef cFilePathInterfaceImplements cImplements;
};
///////////////////////////////////////////////////////////////////////
// Typedef: cFilePathImplementImplements
//
//  Author: $author$
//    Date: 8/6/2011
///////////////////////////////////////////////////////////////////////
typedef cFilePathImplementT<>
cFilePathImplementImplements;
///////////////////////////////////////////////////////////////////////
//  Class: cFilePathImplement
//
// Author: $author$
//   Date: 8/6/2011
///////////////////////////////////////////////////////////////////////
class c_IMPLEMENT_CLASS cFilePathImplement
: virtual public cFilePathImplementImplements
{
public:
    typedef cFilePathImplementImplements cImplements;
};

#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#else // !defined(CFILEPATHINTERFACET_MEMBERS_ONLY) 
#endif // !defined(CFILEPATHINTERFACET_MEMBERS_ONLY) 

#endif // !defined(_CFILEPATHINTERFACE_HPP) || defined(CFILEPATHINTERFACET_MEMBERS_ONLY) 
        

