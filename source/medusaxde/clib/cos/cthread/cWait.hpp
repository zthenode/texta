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
//   File: cWait.hpp
//
// Author: $author$
//   Date: 3/19/2011
///////////////////////////////////////////////////////////////////////
#if !defined(_CWAIT_HPP) || defined(CWAIT_MEMBERS_ONLY)
#if !defined(_CWAIT_HPP) && !defined(CWAIT_MEMBERS_ONLY)
#define _CWAIT_HPP
#endif // !defined(_CWAIT_HPP) && !defined(CWAIT_MEMBERS_ONLY) 

#if !defined(CWAIT_MEMBERS_ONLY)
#include "cWaitInterface.hpp"
#include "cExportBase.hpp"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

///////////////////////////////////////////////////////////////////////
// Typedef: cWaitExtend
//
//  Author: $author$
//    Date: 3/19/2011
///////////////////////////////////////////////////////////////////////
typedef cExportBase
cWaitExtend;
///////////////////////////////////////////////////////////////////////
//  Class: cWait
//
// Author: $author$
//   Date: 3/19/2011
///////////////////////////////////////////////////////////////////////
class c_INSTANCE_CLASS cWait
: virtual public cWaitImplement,
  public cWaitExtend
{
public:
    typedef cWaitImplement cImplements;
    typedef cWaitExtend cExtends;
    
    bool m_isCreated;
    
    ///////////////////////////////////////////////////////////////////////
    //  Constructor: cWait
    //
    //       Author: $author$
    //         Date: 3/19/2011
    ///////////////////////////////////////////////////////////////////////
    cWait(bool withIsCreated=false)
    : m_isCreated(withIsCreated)
    {
    }
    ///////////////////////////////////////////////////////////////////////
    //  Destructor: ~cWait
    //
    //      Author: $author$
    //        Date: 3/19/2011
    ///////////////////////////////////////////////////////////////////////
    virtual ~cWait()
    {
    }
#else // !defined(CWAIT_MEMBERS_ONLY) 
#endif // !defined(CWAIT_MEMBERS_ONLY) 

    ///////////////////////////////////////////////////////////////////////
    //  Function: Wait
    //
    //    Author: $author$
    //      Date: 3/19/2011
    ///////////////////////////////////////////////////////////////////////
    virtual eError Wait
    (mseconds_t milliseconds)
#if defined(CWAIT_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CWAIT_MEMBER_FUNCS_INTERFACE) 
    {
        eError error = e_ERROR_FAILED;
#if !defined(CWAIT_MEMBER_FUNCS_IMPLEMENT)
#else // !defined(CWAIT_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CWAIT_MEMBER_FUNCS_IMPLEMENT) 
        return error;
    }
#endif // defined(CWAIT_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    //  Function: Wait
    //
    //    Author: $author$
    //      Date: 3/19/2011
    ///////////////////////////////////////////////////////////////////////
    virtual eError Wait()
#if defined(CWAIT_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CWAIT_MEMBER_FUNCS_INTERFACE) 
    {
        eError error = e_ERROR_FAILED;
#if !defined(CWAIT_MEMBER_FUNCS_IMPLEMENT)
#else // !defined(CWAIT_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CWAIT_MEMBER_FUNCS_IMPLEMENT) 
        return error;
    }
#endif // defined(CWAIT_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    //  Function: Continue
    //
    //    Author: $author$
    //      Date: 5/28/2011
    ///////////////////////////////////////////////////////////////////////
    virtual eError Continue()
#if defined(CWAIT_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CWAIT_MEMBER_FUNCS_INTERFACE) 
    {
        eError error = e_ERROR_FAILED;
#if !defined(CWAIT_MEMBER_FUNCS_IMPLEMENT)
#else // !defined(CWAIT_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CWAIT_MEMBER_FUNCS_IMPLEMENT) 
        return error;
    }
#endif // defined(CWAIT_MEMBER_FUNCS_INTERFACE) 

#if !defined(CWAIT_MEMBERS_ONLY)
    ///////////////////////////////////////////////////////////////////////
    //  Function: Destroyed
    //
    //    Author: $author$
    //      Date: 3/20/2011
    ///////////////////////////////////////////////////////////////////////
    virtual eError Destroyed
    (bool onlyDestroyed=false)
    {
        eError error = e_ERROR_NONE;

	    if (IsCreated())
		if (onlyDestroyed)
	        return error;
		else
		if ((error = Destroy()))
		    return error;

        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    //  Function: Destroy
    //
    //    Author: $author$
    //      Date: 3/20/2011
    ///////////////////////////////////////////////////////////////////////
    virtual eError Destroy
    (bool onlyCreated=false)
    {
        eError error = e_ERROR_NONE;
        SetIsCreated(false);
        return error;
    }

    ///////////////////////////////////////////////////////////////////////
    //  Function: SetIsCreated
    //
    //    Author: $author$
    //      Date: 3/20/2011
    ///////////////////////////////////////////////////////////////////////
    virtual int SetIsCreated(bool isTrue=true)
    {
        m_isCreated = isTrue;
        return isTrue;
    }
    ///////////////////////////////////////////////////////////////////////
    //  Function: GetIsCreated
    //
    //    Author: $author$
    //      Date: 5/29/2011
    ///////////////////////////////////////////////////////////////////////
    virtual bool GetIsCreated() const
    {
        bool isTrue = m_isCreated;
        return isTrue;
    }
    ///////////////////////////////////////////////////////////////////////
    //  Function: IsCreated
    //
    //    Author: $author$
    //      Date: 3/20/2011
    ///////////////////////////////////////////////////////////////////////
    virtual bool IsCreated() const
    {
        bool isTrue = m_isCreated;
        return isTrue;
    }
};

#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#else // !defined(CWAIT_MEMBERS_ONLY) 
#endif // !defined(CWAIT_MEMBERS_ONLY) 

#endif // !defined(_CWAIT_HPP) || defined(CWAIT_MEMBERS_ONLY) 
