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
//   File: cXsltProcessorInterface.hpp
//
// Author: $author$
//   Date: 7/1/2011
///////////////////////////////////////////////////////////////////////
#if !defined(_CXSLTPROCESSORINTERFACE_HPP) || defined(CXSLTPROCESSORINTERFACE_MEMBERS_ONLY)
#if !defined(_CXSLTPROCESSORINTERFACE_HPP) && !defined(CXSLTPROCESSORINTERFACE_MEMBERS_ONLY)
#define _CXSLTPROCESSORINTERFACE_HPP
#endif // !defined(_CXSLTPROCESSORINTERFACE_HPP) && !defined(CXSLTPROCESSORINTERFACE_MEMBERS_ONLY) 

#if !defined(CXSLTPROCESSORINTERFACE_MEMBERS_ONLY)
#include "cXsltParamsInterface.hpp"
#include "cInterfaceBase.hpp"
#include "cImplementBase.hpp"
#include "cCharStreamInterface.hpp"
#include "cString.hpp"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

class c_INTERFACE_CLASS cXsltDocumentInterface;
class c_INTERFACE_CLASS cXsltStyleSheetInterface;

class c_INTERFACE_CLASS cXsltExtensionFunctionInterface;
class c_INTERFACE_CLASS cXsltExtensionModuleInterface;

class c_INSTANCE_CLASS cXsltProcessorImplemented;

typedef cInterfaceBase cXsltProcessorInterfaceImplements;
///////////////////////////////////////////////////////////////////////
//  Class: cXsltProcessorInterface
//
// Author: $author$
//   Date: 7/1/2011
///////////////////////////////////////////////////////////////////////
class c_INTERFACE_CLASS cXsltProcessorInterface
: virtual public cXsltProcessorInterfaceImplements
{
public:
    typedef cXsltProcessorInterfaceImplements cImplements;
#else // !defined(CXSLTPROCESSORINTERFACE_MEMBERS_ONLY) 
#endif // !defined(CXSLTPROCESSORINTERFACE_MEMBERS_ONLY) 

#if !defined(CXSLTPROCESSORINTERFACE_MEMBERS_ONLY)
// include cXsltProcessor member functions interface
//
#define CXSLTPROCESSOR_MEMBERS_ONLY
#define CXSLTPROCESSOR_MEMBER_FUNCS_INTERFACE
#include "cXsltProcessor.hpp"
#undef CXSLTPROCESSOR_MEMBER_FUNCS_INTERFACE
#undef CXSLTPROCESSOR_MEMBERS_ONLY
};

#if !defined(CXSLTPROCESSORIMPLEMENT_MEMBERS_ONLY)
typedef cXsltProcessorInterface cXsltProcessorImplementImplements;
///////////////////////////////////////////////////////////////////////
//  Class: cXsltProcessorImplement
//
// Author: $author$
//   Date: 7/1/2011
///////////////////////////////////////////////////////////////////////
class c_IMPLEMENT_CLASS cXsltProcessorImplement
: virtual public cXsltProcessorImplementImplements
{
public:
    typedef cXsltProcessorImplementImplements cImplements;
#else // !defined(CXSLTPROCESSORIMPLEMENT_MEMBERS_ONLY) 
#endif // !defined(CXSLTPROCESSORIMPLEMENT_MEMBERS_ONLY) 

#if !defined(CXSLTPROCESSORIMPLEMENT_MEMBERS_ONLY)
// include cXsltProcessor interface member definitions
//
#define CXSLTPROCESSORINTERFACE_MEMBERS_ONLY
#include "cXsltProcessorInterface.hpp"
#undef CXSLTPROCESSORINTERFACE_MEMBERS_ONLY

// include cXsltProcessor member functions implement
//
#define CXSLTPROCESSOR_MEMBERS_ONLY
#define CXSLTPROCESSOR_MEMBER_FUNCS_IMPLEMENT
#include "cXsltProcessor.hpp"
#undef CXSLTPROCESSOR_MEMBER_FUNCS_IMPLEMENT
#undef CXSLTPROCESSOR_MEMBERS_ONLY
};
#else // !defined(CXSLTPROCESSORIMPLEMENT_MEMBERS_ONLY) 
#endif // !defined(CXSLTPROCESSORIMPLEMENT_MEMBERS_ONLY) 

#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#else // !defined(CXSLTPROCESSORINTERFACE_MEMBERS_ONLY) 
#endif // !defined(CXSLTPROCESSORINTERFACE_MEMBERS_ONLY) 

#endif // !defined(_CXSLTPROCESSORINTERFACE_HPP) || defined(CXSLTPROCESSORINTERFACE_MEMBERS_ONLY) 
