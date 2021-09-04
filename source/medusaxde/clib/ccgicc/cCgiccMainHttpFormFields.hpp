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
//   File: cCgiccMainHttpFormFields.hpp
//
// Author: $author$
//   Date: 7/23/2011
///////////////////////////////////////////////////////////////////////
#if !defined(_CCGICCMAINHTTPFORMFIELDS_HPP) || defined(CCGICCMAINHTTPFORMFIELDS_MEMBERS_ONLY)
#if !defined(_CCGICCMAINHTTPFORMFIELDS_HPP) && !defined(CCGICCMAINHTTPFORMFIELDS_MEMBERS_ONLY)
#define _CCGICCMAINHTTPFORMFIELDS_HPP
#endif // !defined(_CCGICCMAINHTTPFORMFIELDS_HPP) && !defined(CCGICCMAINHTTPFORMFIELDS_MEMBERS_ONLY) 

#if !defined(CCGICCMAINHTTPFORMFIELDS_MEMBERS_ONLY)
#include "cHttpFormFields.hpp"
#include "cCgiccMainInterface.hpp"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

///////////////////////////////////////////////////////////////////////
// Typedef: cCgiccMainHttpFormFieldsExtend
//
//  Author: $author$
//    Date: 7/23/2011
///////////////////////////////////////////////////////////////////////
typedef cHttpFormFields
cCgiccMainHttpFormFieldsExtend;
///////////////////////////////////////////////////////////////////////
//  Class: cCgiccMainHttpFormFields
//
// Author: $author$
//   Date: 7/23/2011
///////////////////////////////////////////////////////////////////////
class c_INSTANCE_CLASS cCgiccMainHttpFormFields
: //virtual public cCgiccMainHttpFormFieldsImplement,
  public cCgiccMainHttpFormFieldsExtend
{
public:
    //typedef cCgiccMainHttpFormFieldsImplement cImplements;
    typedef cCgiccMainHttpFormFieldsExtend cExtends;

    cCgiccMainInterface& m_ccgiccMain;

    ///////////////////////////////////////////////////////////////////////
    //  Constructor: cCgiccMainHttpFormFields
    //
    //       Author: $author$
    //         Date: 7/23/2011
    ///////////////////////////////////////////////////////////////////////
    cCgiccMainHttpFormFields
    (cCgiccMainInterface& ccgiccMain)
    : m_ccgiccMain(ccgiccMain)
    {
    }
    ///////////////////////////////////////////////////////////////////////
    //  Destructor: ~cCgiccMainHttpFormFields
    //
    //      Author: $author$
    //        Date: 7/23/2011
    ///////////////////////////////////////////////////////////////////////
    virtual ~cCgiccMainHttpFormFields()
    {
    }
#else // !defined(CCGICCMAINHTTPFORMFIELDS_MEMBERS_ONLY) 
#endif // !defined(CCGICCMAINHTTPFORMFIELDS_MEMBERS_ONLY) 

#if !defined(CCGICCMAINHTTPFORMFIELDS_MEMBERS_ONLY)
};

#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#else // !defined(CCGICCMAINHTTPFORMFIELDS_MEMBERS_ONLY) 
#endif // !defined(CCGICCMAINHTTPFORMFIELDS_MEMBERS_ONLY) 

#endif // !defined(_CCGICCMAINHTTPFORMFIELDS_HPP) || defined(CCGICCMAINHTTPFORMFIELDS_MEMBERS_ONLY) 
