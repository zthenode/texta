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
//   File: cUnixFileStatInterface.hpp
//
// Author: $author$
//   Date: 8/24/2011
///////////////////////////////////////////////////////////////////////
#if !defined(_CUNIXFILESTATINTERFACE_HPP) || defined(CUNIXFILESTATINTERFACE_MEMBERS_ONLY)
#if !defined(_CUNIXFILESTATINTERFACE_HPP) && !defined(CUNIXFILESTATINTERFACE_MEMBERS_ONLY)
#define _CUNIXFILESTATINTERFACE_HPP
#endif // !defined(_CUNIXFILESTATINTERFACE_HPP) && !defined(CUNIXFILESTATINTERFACE_MEMBERS_ONLY) 

#if !defined(CUNIXFILESTATINTERFACE_MEMBERS_ONLY)
#include "cFileStatInterface.hpp"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

///////////////////////////////////////////////////////////////////////
// Typedef: cUnixFileStatInterfaceImplements
//
//  Author: $author$
//    Date: 8/24/2011
///////////////////////////////////////////////////////////////////////
typedef cFileStatInterface
cUnixFileStatInterfaceImplements;
///////////////////////////////////////////////////////////////////////
//  Class: cUnixFileStatInterface
//
// Author: $author$
//   Date: 8/24/2011
///////////////////////////////////////////////////////////////////////
class c_INTERFACE_CLASS cUnixFileStatInterface
: virtual public cUnixFileStatInterfaceImplements
{
public:
    typedef cUnixFileStatInterfaceImplements cImplements;
#else // !defined(CUNIXFILESTATINTERFACE_MEMBERS_ONLY) 
#endif // !defined(CUNIXFILESTATINTERFACE_MEMBERS_ONLY) 

#if !defined(CUNIXFILESTATINTERFACE_MEMBERS_ONLY)
// include cUnixFileStat member functions interface
//
#define CUNIXFILESTAT_MEMBERS_ONLY
#define CUNIXFILESTAT_MEMBER_FUNCS_INTERFACE
#include "cUnixFileStat.hpp"
#undef CUNIXFILESTAT_MEMBER_FUNCS_INTERFACE
#undef CUNIXFILESTAT_MEMBERS_ONLY
};

#if !defined(CUNIXFILESTATIMPLEMENT_MEMBERS_ONLY)
///////////////////////////////////////////////////////////////////////
// Typedef: cUnixFileStatImplementImplements
//
//  Author: $author$
//    Date: 8/24/2011
///////////////////////////////////////////////////////////////////////
typedef cFileStatImplement
cUnixFileStatImplementImplements;
///////////////////////////////////////////////////////////////////////
//  Class: cUnixFileStatImplement
//
// Author: $author$
//   Date: 8/24/2011
///////////////////////////////////////////////////////////////////////
class c_IMPLEMENT_CLASS cUnixFileStatImplement
: virtual public cUnixFileStatInterface,
  virtual public cUnixFileStatImplementImplements
{
public:
    //typedef cUnixFileStatInterface cImplements;
    typedef cUnixFileStatImplementImplements cImplements;
#else // !defined(CUNIXFILESTATIMPLEMENT_MEMBERS_ONLY) 
#endif // !defined(CUNIXFILESTATIMPLEMENT_MEMBERS_ONLY) 

#if !defined(CUNIXFILESTATIMPLEMENT_MEMBERS_ONLY)
// include cUnixFileStat member functions implement
//
#define CUNIXFILESTAT_MEMBERS_ONLY
#define CUNIXFILESTAT_MEMBER_FUNCS_IMPLEMENT
#include "cUnixFileStat.hpp"
#undef CUNIXFILESTAT_MEMBER_FUNCS_IMPLEMENT
#undef CUNIXFILESTAT_MEMBERS_ONLY
};
#else // !defined(CUNIXFILESTATIMPLEMENT_MEMBERS_ONLY) 
#endif // !defined(CUNIXFILESTATIMPLEMENT_MEMBERS_ONLY) 

#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#else // !defined(CUNIXFILESTATINTERFACE_MEMBERS_ONLY) 
#endif // !defined(CUNIXFILESTATINTERFACE_MEMBERS_ONLY) 

#endif // !defined(_CUNIXFILESTATINTERFACE_HPP) || defined(CUNIXFILESTATINTERFACE_MEMBERS_ONLY) 
        

