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
//   File: cStringWriterInterface.hpp
//
// Author: $author$
//   Date: 7/26/2011
///////////////////////////////////////////////////////////////////////
#if !defined(_CSTRINGWRITERINTERFACE_HPP) || defined(CSTRINGWRITERINTERFACET_MEMBERS_ONLY)
#if !defined(_CSTRINGWRITERINTERFACE_HPP) && !defined(CSTRINGWRITERINTERFACET_MEMBERS_ONLY)
#define _CSTRINGWRITERINTERFACE_HPP
#endif // !defined(_CSTRINGWRITERINTERFACE_HPP) && !defined(CSTRINGWRITERINTERFACET_MEMBERS_ONLY) 

#if !defined(CSTRINGWRITERINTERFACET_MEMBERS_ONLY)
#include "cStringInterface.hpp"
#include "cCharWriterInterface.hpp"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

class c_INTERFACE_CLASS cStringWriterInterface;

#undef CDB_CLASS
#define CDB_CLASS "cStringWriterInterfaceT"
///////////////////////////////////////////////////////////////////////
//  Class: cStringWriterInterfaceT
//
// Author: $author$
//   Date: 7/26/2011
///////////////////////////////////////////////////////////////////////
template
<class TImplement=cCharWriterInterface,
 class TStringInterface=cStringInterface,
 class TChar=char>

class c_INTERFACE_CLASS cStringWriterInterfaceT
: virtual public TImplement
{
public:
    typedef TImplement cImplements;
#else // !defined(CSTRINGWRITERINTERFACET_MEMBERS_ONLY) 
#endif // !defined(CSTRINGWRITERINTERFACET_MEMBERS_ONLY) 

    typedef TStringInterface tStringInterface;
    typedef TChar char_t;
    typedef TChar tWhat;

#if !defined(CSTRINGWRITERINTERFACET_MEMBERS_ONLY)
// include cStringWriterT member functions interface
//
#define CSTRINGWRITERT_MEMBERS_ONLY
#define CSTRINGWRITERT_MEMBER_FUNCS_INTERFACE
#include "cStringWriter.hpp"
#undef CSTRINGWRITERT_MEMBER_FUNCS_INTERFACE
#undef CSTRINGWRITERT_MEMBERS_ONLY
};
#undef CDB_CLASS

#if !defined(CSTRINGWRITERIMPLEMENTT_MEMBERS_ONLY)
class c_IMPLEMENT_CLASS cStringWriterImplement;

#undef CDB_CLASS
#define CDB_CLASS "cStringWriterImplementT"
///////////////////////////////////////////////////////////////////////
//  Class: cStringWriterImplementT
//
// Author: $author$
//   Date: 7/26/2011
///////////////////////////////////////////////////////////////////////
template
<class TImplement=cStringWriterInterface,
 class TStringInterface=cStringInterface,
 class TChar=char>

class c_IMPLEMENT_CLASS cStringWriterImplementT
: virtual public TImplement
{
public:
    typedef TImplement cImplements;
#else // !defined(CSTRINGWRITERIMPLEMENTT_MEMBERS_ONLY) 
#endif // !defined(CSTRINGWRITERIMPLEMENTT_MEMBERS_ONLY) 

#if !defined(CSTRINGWRITERIMPLEMENTT_MEMBERS_ONLY)
// include cStringWriterT interface member definitions
//
#define CSTRINGWRITERINTERFACET_MEMBERS_ONLY
#include "cStringWriterInterface.hpp"
#undef CSTRINGWRITERINTERFACET_MEMBERS_ONLY

// include cStringWriterT member functions implement
//
#define CSTRINGWRITERT_MEMBERS_ONLY
#define CSTRINGWRITERT_MEMBER_FUNCS_IMPLEMENT
#include "cStringWriter.hpp"
#undef CSTRINGWRITERT_MEMBER_FUNCS_IMPLEMENT
#undef CSTRINGWRITERT_MEMBERS_ONLY
};
#undef CDB_CLASS
#else // !defined(CSTRINGWRITERIMPLEMENTT_MEMBERS_ONLY) 
#endif // !defined(CSTRINGWRITERIMPLEMENTT_MEMBERS_ONLY) 

///////////////////////////////////////////////////////////////////////
// Typedef: cStringWriterInterfaceImplements
//
//  Author: $author$
//    Date: 7/26/2011
///////////////////////////////////////////////////////////////////////
typedef cStringWriterInterfaceT
<cCharWriterInterface, cStringInterface, char>
cStringWriterInterfaceImplements;
///////////////////////////////////////////////////////////////////////
//  Class: cStringWriterInterface
//
// Author: $author$
//   Date: 7/26/2011
///////////////////////////////////////////////////////////////////////
class c_INTERFACE_CLASS cStringWriterInterface
: virtual public cStringWriterInterfaceImplements
{
public:
    typedef cStringWriterInterfaceImplements cImplements;
};
///////////////////////////////////////////////////////////////////////
// Typedef: cStringWriterImplementImplements
//
//  Author: $author$
//    Date: 7/26/2011
///////////////////////////////////////////////////////////////////////
typedef cStringWriterImplementT
<cStringWriterInterface, cStringInterface, char>
cStringWriterImplementImplements;
///////////////////////////////////////////////////////////////////////
//  Class: cStringWriterImplement
//
// Author: $author$
//   Date: 7/26/2011
///////////////////////////////////////////////////////////////////////
class c_IMPLEMENT_CLASS cStringWriterImplement
: virtual public cStringWriterImplementImplements
{
public:
    typedef cStringWriterImplementImplements cImplements;
};

#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#else // !defined(CSTRINGWRITERINTERFACET_MEMBERS_ONLY) 
#endif // !defined(CSTRINGWRITERINTERFACET_MEMBERS_ONLY) 

#endif // !defined(_CSTRINGWRITERINTERFACE_HPP) || defined(CSTRINGWRITERINTERFACET_MEMBERS_ONLY) 
