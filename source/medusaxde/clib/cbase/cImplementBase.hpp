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
//   File: cImplementBase.hpp
//
// Author: $author$
//   Date: 3/19/2011
///////////////////////////////////////////////////////////////////////
#if !defined(_CIMPLEMENTBASE_HPP) || defined(CIMPLEMENTBASE_MEMBERS_ONLY)
#if !defined(_CIMPLEMENTBASE_HPP) && !defined(CIMPLEMENTBASE_MEMBERS_ONLY)
#define _CIMPLEMENTBASE_HPP
#endif // !defined(_CIMPLEMENTBASE_HPP) && !defined(CIMPLEMENTBASE_MEMBERS_ONLY) 

#if !defined(CIMPLEMENTBASE_MEMBERS_ONLY)
#include "cInterfaceBase.hpp"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

///////////////////////////////////////////////////////////////////////
//  Class: cImplementBase
//
// Author: $author$
//   Date: 3/19/2011
///////////////////////////////////////////////////////////////////////
class c_IMPLEMENT_CLASS cImplementBase
: virtual public cInterfaceBase
{
public:
    typedef cInterfaceBase cImplements;
#else // !defined(CIMPLEMENTBASE_MEMBERS_ONLY) 
#endif // !defined(CIMPLEMENTBASE_MEMBERS_ONLY) 

#if !defined(CIMPLEMENTBASE_MEMBERS_ONLY)
};


#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#else // !defined(CIMPLEMENTBASE_MEMBERS_ONLY) 
#endif // !defined(CIMPLEMENTBASE_MEMBERS_ONLY) 

#endif // !defined(_CIMPLEMENTBASE_HPP) || defined(CIMPLEMENTBASE_MEMBERS_ONLY)

