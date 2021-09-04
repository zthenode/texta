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
//   File: cCgiXmlWriterInterface.hpp
//
// Author: $author$
//   Date: 7/27/2011
///////////////////////////////////////////////////////////////////////
#if !defined(_CCGIXMLWRITERINTERFACE_HPP) || defined(CCGIXMLWRITERINTERFACE_MEMBERS_ONLY)
#if !defined(_CCGIXMLWRITERINTERFACE_HPP) && !defined(CCGIXMLWRITERINTERFACE_MEMBERS_ONLY)
#define _CCGIXMLWRITERINTERFACE_HPP
#endif // !defined(_CCGIXMLWRITERINTERFACE_HPP) && !defined(CCGIXMLWRITERINTERFACE_MEMBERS_ONLY) 

#if !defined(CCGIXMLWRITERINTERFACE_MEMBERS_ONLY)
#include "cWriterInterface.hpp"
#include "cCgiInterface.hpp"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

///////////////////////////////////////////////////////////////////////
// Typedef: cCgiXmlWriterInterfaceImplements
//
//  Author: $author$
//    Date: 7/27/2011
///////////////////////////////////////////////////////////////////////
typedef cInterfaceBase
cCgiXmlWriterInterfaceImplements;
///////////////////////////////////////////////////////////////////////
//  Class: cCgiXmlWriterInterface
//
// Author: $author$
//   Date: 7/27/2011
///////////////////////////////////////////////////////////////////////
class c_INTERFACE_CLASS cCgiXmlWriterInterface
: virtual public cCgiXmlWriterInterfaceImplements
{
public:
    typedef cCgiXmlWriterInterfaceImplements cImplements;
#else // !defined(CCGIXMLWRITERINTERFACE_MEMBERS_ONLY) 
#endif // !defined(CCGIXMLWRITERINTERFACE_MEMBERS_ONLY) 

#if !defined(CCGIXMLWRITERINTERFACE_MEMBERS_ONLY)
// include cCgiXmlWriter member functions interface
//
#define CCGIXMLWRITER_MEMBERS_ONLY
#define CCGIXMLWRITER_MEMBER_FUNCS_INTERFACE
#include "cCgiXmlWriter.hpp"
#undef CCGIXMLWRITER_MEMBER_FUNCS_INTERFACE
#undef CCGIXMLWRITER_MEMBERS_ONLY
};

#if !defined(CCGIXMLWRITERIMPLEMENT_MEMBERS_ONLY)
///////////////////////////////////////////////////////////////////////
// Typedef: cCgiXmlWriterImplementImplements
//
//  Author: $author$
//    Date: 7/27/2011
///////////////////////////////////////////////////////////////////////
typedef cImplementBase
cCgiXmlWriterImplementImplements;
///////////////////////////////////////////////////////////////////////
//  Class: cCgiXmlWriterImplement
//
// Author: $author$
//   Date: 7/27/2011
///////////////////////////////////////////////////////////////////////
class c_IMPLEMENT_CLASS cCgiXmlWriterImplement
: virtual public cCgiXmlWriterInterface,
  virtual public cCgiXmlWriterImplementImplements
{
public:
    //typedef cCgiXmlWriterInterface cImplements;
    typedef cCgiXmlWriterImplementImplements cImplements;
#else // !defined(CCGIXMLWRITERIMPLEMENT_MEMBERS_ONLY) 
#endif // !defined(CCGIXMLWRITERIMPLEMENT_MEMBERS_ONLY) 

#if !defined(CCGIXMLWRITERIMPLEMENT_MEMBERS_ONLY)
// include cCgiXmlWriter member functions implement
//
#define CCGIXMLWRITER_MEMBERS_ONLY
#define CCGIXMLWRITER_MEMBER_FUNCS_IMPLEMENT
#include "cCgiXmlWriter.hpp"
#undef CCGIXMLWRITER_MEMBER_FUNCS_IMPLEMENT
#undef CCGIXMLWRITER_MEMBERS_ONLY
};
#else // !defined(CCGIXMLWRITERIMPLEMENT_MEMBERS_ONLY) 
#endif // !defined(CCGIXMLWRITERIMPLEMENT_MEMBERS_ONLY) 

#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#else // !defined(CCGIXMLWRITERINTERFACE_MEMBERS_ONLY) 
#endif // !defined(CCGIXMLWRITERINTERFACE_MEMBERS_ONLY) 

#endif // !defined(_CCGIXMLWRITERINTERFACE_HPP) || defined(CCGIXMLWRITERINTERFACE_MEMBERS_ONLY) 
        

