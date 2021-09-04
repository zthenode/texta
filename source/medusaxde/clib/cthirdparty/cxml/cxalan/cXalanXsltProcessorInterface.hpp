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
//   File: cXalanXsltProcessorInterface.hpp
//
// Author: $author$
//   Date: 7/23/2011
///////////////////////////////////////////////////////////////////////
#if !defined(_CXALANXSLTPROCESSORINTERFACE_HPP) || defined(CXALANXSLTPROCESSORINTERFACE_MEMBERS_ONLY)
#if !defined(_CXALANXSLTPROCESSORINTERFACE_HPP) && !defined(CXALANXSLTPROCESSORINTERFACE_MEMBERS_ONLY)
#define _CXALANXSLTPROCESSORINTERFACE_HPP
#endif // !defined(_CXALANXSLTPROCESSORINTERFACE_HPP) && !defined(CXALANXSLTPROCESSORINTERFACE_MEMBERS_ONLY) 

#if !defined(CXALANXSLTPROCESSORINTERFACE_MEMBERS_ONLY)
#include "cXsltProcessorInterface.hpp"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

///////////////////////////////////////////////////////////////////////
// Typedef: cXalanXsltProcessorInterfaceImplements
//
//  Author: $author$
//    Date: 7/23/2011
///////////////////////////////////////////////////////////////////////
typedef cXsltProcessorInterface
cXalanXsltProcessorInterfaceImplements;
///////////////////////////////////////////////////////////////////////
//  Class: cXalanXsltProcessorInterface
//
// Author: $author$
//   Date: 7/23/2011
///////////////////////////////////////////////////////////////////////
class c_INTERFACE_CLASS cXalanXsltProcessorInterface
: virtual public cXalanXsltProcessorInterfaceImplements
{
public:
    typedef cXalanXsltProcessorInterfaceImplements cImplements;
#else // !defined(CXALANXSLTPROCESSORINTERFACE_MEMBERS_ONLY) 
#endif // !defined(CXALANXSLTPROCESSORINTERFACE_MEMBERS_ONLY) 

#if !defined(CXALANXSLTPROCESSORINTERFACE_MEMBERS_ONLY)
// include cXalanXsltProcessor member functions interface
//
#define CXALANXSLTPROCESSOR_MEMBERS_ONLY
#define CXALANXSLTPROCESSOR_MEMBER_FUNCS_INTERFACE
//#include "cXalanXsltProcessor.hpp"
#undef CXALANXSLTPROCESSOR_MEMBER_FUNCS_INTERFACE
#undef CXALANXSLTPROCESSOR_MEMBERS_ONLY
};

#if !defined(CXALANXSLTPROCESSORIMPLEMENT_MEMBERS_ONLY)
///////////////////////////////////////////////////////////////////////
// Typedef: cXalanXsltProcessorImplementImplements
//
//  Author: $author$
//    Date: 7/23/2011
///////////////////////////////////////////////////////////////////////
typedef cXsltProcessorImplement
cXalanXsltProcessorImplementImplements;
///////////////////////////////////////////////////////////////////////
//  Class: cXalanXsltProcessorImplement
//
// Author: $author$
//   Date: 7/23/2011
///////////////////////////////////////////////////////////////////////
class c_IMPLEMENT_CLASS cXalanXsltProcessorImplement
: virtual public cXalanXsltProcessorInterface,
  virtual public cXalanXsltProcessorImplementImplements
{
public:
    //typedef cXalanXsltProcessorInterface cImplements;
    typedef cXalanXsltProcessorImplementImplements cImplements;
#else // !defined(CXALANXSLTPROCESSORIMPLEMENT_MEMBERS_ONLY) 
#endif // !defined(CXALANXSLTPROCESSORIMPLEMENT_MEMBERS_ONLY) 

#if !defined(CXALANXSLTPROCESSORIMPLEMENT_MEMBERS_ONLY)
// include cXalanXsltProcessor member functions implement
//
#define CXALANXSLTPROCESSOR_MEMBERS_ONLY
#define CXALANXSLTPROCESSOR_MEMBER_FUNCS_IMPLEMENT
//#include "cXalanXsltProcessor.hpp"
#undef CXALANXSLTPROCESSOR_MEMBER_FUNCS_IMPLEMENT
#undef CXALANXSLTPROCESSOR_MEMBERS_ONLY
};
#else // !defined(CXALANXSLTPROCESSORIMPLEMENT_MEMBERS_ONLY) 
#endif // !defined(CXALANXSLTPROCESSORIMPLEMENT_MEMBERS_ONLY) 

#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#else // !defined(CXALANXSLTPROCESSORINTERFACE_MEMBERS_ONLY) 
#endif // !defined(CXALANXSLTPROCESSORINTERFACE_MEMBERS_ONLY) 

#endif // !defined(_CXALANXSLTPROCESSORINTERFACE_HPP) || defined(CXALANXSLTPROCESSORINTERFACE_MEMBERS_ONLY) 
