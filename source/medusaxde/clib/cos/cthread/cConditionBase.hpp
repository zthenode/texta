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
//   File: cConditionBase.hpp
//
// Author: $author$
//   Date: 5/30/2011
///////////////////////////////////////////////////////////////////////
#if !defined(_CCONDITIONBASE_HPP) || defined(CCONDITIONBASE_MEMBERS_ONLY)
#if !defined(_CCONDITIONBASE_HPP) && !defined(CCONDITIONBASE_MEMBERS_ONLY)
#define _CCONDITIONBASE_HPP
#endif // !defined(_CCONDITIONBASE_HPP) && !defined(CCONDITIONBASE_MEMBERS_ONLY) 

#if !defined(CCONDITIONBASE_MEMBERS_ONLY)
#include "cConditionInterface.hpp"
#include "cWait.hpp"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

///////////////////////////////////////////////////////////////////////
// Typedef: cConditionBaseExtend
//
//  Author: $author$
//    Date: 5/30/2011
///////////////////////////////////////////////////////////////////////
typedef cWait
cConditionBaseExtend;
///////////////////////////////////////////////////////////////////////
//  Class: cConditionBase
//
// Author: $author$
//   Date: 5/30/2011
///////////////////////////////////////////////////////////////////////
class c_INSTANCE_CLASS cConditionBase
: virtual public cConditionImplement,
  public cConditionBaseExtend
{
public:
    typedef cConditionImplement cImplements;
    typedef cConditionBaseExtend cExtends;
    ///////////////////////////////////////////////////////////////////////
    //  Constructor: cConditionBase
    //
    //       Author: $author$
    //         Date: 5/30/2011
    ///////////////////////////////////////////////////////////////////////
    cConditionBase()
    {
    }
    ///////////////////////////////////////////////////////////////////////
    //  Destructor: ~cConditionBase
    //
    //      Author: $author$
    //        Date: 5/30/2011
    ///////////////////////////////////////////////////////////////////////
    virtual ~cConditionBase()
    {
    }
#else // !defined(CCONDITIONBASE_MEMBERS_ONLY) 
#endif // !defined(CCONDITIONBASE_MEMBERS_ONLY) 

#if !defined(CCONDITIONBASE_MEMBERS_ONLY)
};


#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#else // !defined(CCONDITIONBASE_MEMBERS_ONLY) 
#endif // !defined(CCONDITIONBASE_MEMBERS_ONLY) 

#endif // !defined(_CCONDITIONBASE_HPP) || defined(CCONDITIONBASE_MEMBERS_ONLY) 
        

