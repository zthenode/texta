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
//   File: cFileStatBase.hpp
//
// Author: $author$
//   Date: 8/24/2011
///////////////////////////////////////////////////////////////////////
#if !defined(_CFILESTATBASE_HPP) || defined(CFILESTATBASE_MEMBERS_ONLY)
#if !defined(_CFILESTATBASE_HPP) && !defined(CFILESTATBASE_MEMBERS_ONLY)
#define _CFILESTATBASE_HPP
#endif // !defined(_CFILESTATBASE_HPP) && !defined(CFILESTATBASE_MEMBERS_ONLY) 

#if !defined(CFILESTATBASE_MEMBERS_ONLY)
#include "cFileStatInterface.hpp"
#include "cInstanceBase.hpp"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

///////////////////////////////////////////////////////////////////////
// Typedef: cFileStatBaseExtend
//
//  Author: $author$
//    Date: 8/24/2011
///////////////////////////////////////////////////////////////////////
typedef cInstanceBase
cFileStatBaseExtend;
///////////////////////////////////////////////////////////////////////
//  Class: cFileStatBase
//
// Author: $author$
//   Date: 8/24/2011
///////////////////////////////////////////////////////////////////////
class c_INSTANCE_CLASS cFileStatBase
: virtual public cFileStatImplement,
  public cFileStatBaseExtend
{
public:
    typedef cFileStatImplement cImplements;
    typedef cFileStatBaseExtend cExtends;

    struct stat m_st;

    ///////////////////////////////////////////////////////////////////////
    //  Constructor: cFileStatBase
    //
    //       Author: $author$
    //         Date: 8/24/2011
    ///////////////////////////////////////////////////////////////////////
    cFileStatBase()
    {
    }
    ///////////////////////////////////////////////////////////////////////
    //  Destructor: ~cFileStatBase
    //
    //      Author: $author$
    //        Date: 8/24/2011
    ///////////////////////////////////////////////////////////////////////
    virtual ~cFileStatBase()
    {
    }
#else // !defined(CFILESTATBASE_MEMBERS_ONLY) 
#endif // !defined(CFILESTATBASE_MEMBERS_ONLY) 

#if !defined(CFILESTATBASE_MEMBERS_ONLY)
    inline operator struct stat&() const
    { return (struct stat&)(m_st); }
};


#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#else // !defined(CFILESTATBASE_MEMBERS_ONLY) 
#endif // !defined(CFILESTATBASE_MEMBERS_ONLY) 

#endif // !defined(_CFILESTATBASE_HPP) || defined(CFILESTATBASE_MEMBERS_ONLY) 
        

