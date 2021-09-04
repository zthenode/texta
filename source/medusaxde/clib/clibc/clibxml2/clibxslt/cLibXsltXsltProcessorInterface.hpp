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
//   File: cLibXsltXsltProcessorInterface.hpp
//
// Author: $author$
//   Date: 7/1/2011
///////////////////////////////////////////////////////////////////////
#if !defined(_CLIBXSLTXSLTPROCESSORINTERFACE_HPP) || defined(CLIBXSLTXSLTPROCESSORINTERFACE_MEMBERS_ONLY)
#if !defined(_CLIBXSLTXSLTPROCESSORINTERFACE_HPP) && !defined(CLIBXSLTXSLTPROCESSORINTERFACE_MEMBERS_ONLY)
#define _CLIBXSLTXSLTPROCESSORINTERFACE_HPP
#endif // !defined(_CLIBXSLTXSLTPROCESSORINTERFACE_HPP) && !defined(CLIBXSLTXSLTPROCESSORINTERFACE_MEMBERS_ONLY) 

#if !defined(CLIBXSLTXSLTPROCESSORINTERFACE_MEMBERS_ONLY)
#include "cXsltProcessorInterface.hpp"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

///////////////////////////////////////////////////////////////////////
// Typedef: cLibXsltXsltProcessorInterfaceImplements
//
//  Author: $author$
//    Date: 7/1/2011
///////////////////////////////////////////////////////////////////////
typedef cXsltProcessorInterface
cLibXsltXsltProcessorInterfaceImplements;
///////////////////////////////////////////////////////////////////////
//  Class: cLibXsltXsltProcessorInterface
//
// Author: $author$
//   Date: 7/1/2011
///////////////////////////////////////////////////////////////////////
class c_INTERFACE_CLASS cLibXsltXsltProcessorInterface
: virtual public cLibXsltXsltProcessorInterfaceImplements
{
public:
    typedef cLibXsltXsltProcessorInterfaceImplements cImplements;
#else // !defined(CLIBXSLTXSLTPROCESSORINTERFACE_MEMBERS_ONLY) 
#endif // !defined(CLIBXSLTXSLTPROCESSORINTERFACE_MEMBERS_ONLY) 

#if !defined(CLIBXSLTXSLTPROCESSORINTERFACE_MEMBERS_ONLY)
// include cLibXsltXsltProcessor member functions interface
//
#define CLIBXSLTXSLTPROCESSOR_MEMBERS_ONLY
#define CLIBXSLTXSLTPROCESSOR_MEMBER_FUNCS_INTERFACE
#include "cLibXsltXsltProcessor.hpp"
#undef CLIBXSLTXSLTPROCESSOR_MEMBER_FUNCS_INTERFACE
#undef CLIBXSLTXSLTPROCESSOR_MEMBERS_ONLY
};

#if !defined(CLIBXSLTXSLTPROCESSORIMPLEMENT_MEMBERS_ONLY)
///////////////////////////////////////////////////////////////////////
// Typedef: cLibXsltXsltProcessorImplementImplements
//
//  Author: $author$
//    Date: 7/1/2011
///////////////////////////////////////////////////////////////////////
typedef cXsltProcessorImplement
cLibXsltXsltProcessorImplementImplements;
///////////////////////////////////////////////////////////////////////
//  Class: cLibXsltXsltProcessorImplement
//
// Author: $author$
//   Date: 7/1/2011
///////////////////////////////////////////////////////////////////////
class c_IMPLEMENT_CLASS cLibXsltXsltProcessorImplement
: virtual public cLibXsltXsltProcessorInterface,
  virtual public cLibXsltXsltProcessorImplementImplements
{
public:
    //typedef cLibXsltXsltProcessorInterface cImplements;
    typedef cLibXsltXsltProcessorImplementImplements cImplements;
#else // !defined(CLIBXSLTXSLTPROCESSORIMPLEMENT_MEMBERS_ONLY) 
#endif // !defined(CLIBXSLTXSLTPROCESSORIMPLEMENT_MEMBERS_ONLY) 

#if !defined(CLIBXSLTXSLTPROCESSORIMPLEMENT_MEMBERS_ONLY)
// include cLibXsltXsltProcessor interface member definitions
//
#define CLIBXSLTXSLTPROCESSORINTERFACE_MEMBERS_ONLY
#include "cLibXsltXsltProcessorInterface.hpp"
#undef CLIBXSLTXSLTPROCESSORINTERFACE_MEMBERS_ONLY

// include cLibXsltXsltProcessor member functions implement
//
#define CLIBXSLTXSLTPROCESSOR_MEMBERS_ONLY
#define CLIBXSLTXSLTPROCESSOR_MEMBER_FUNCS_IMPLEMENT
#include "cLibXsltXsltProcessor.hpp"
#undef CLIBXSLTXSLTPROCESSOR_MEMBER_FUNCS_IMPLEMENT
#undef CLIBXSLTXSLTPROCESSOR_MEMBERS_ONLY
};
#else // !defined(CLIBXSLTXSLTPROCESSORIMPLEMENT_MEMBERS_ONLY) 
#endif // !defined(CLIBXSLTXSLTPROCESSORIMPLEMENT_MEMBERS_ONLY) 


#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#else // !defined(CLIBXSLTXSLTPROCESSORINTERFACE_MEMBERS_ONLY) 
#endif // !defined(CLIBXSLTXSLTPROCESSORINTERFACE_MEMBERS_ONLY) 

#endif // !defined(_CLIBXSLTXSLTPROCESSORINTERFACE_HPP) || defined(CLIBXSLTXSLTPROCESSORINTERFACE_MEMBERS_ONLY) 
        

