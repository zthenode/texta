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
//   File: cThreadBase.hpp
//
// Author: $author$
//   Date: 6/14/2011
///////////////////////////////////////////////////////////////////////
#if !defined(_CTHREADBASE_HPP) || defined(CTHREADBASE_MEMBERS_ONLY)
#if !defined(_CTHREADBASE_HPP) && !defined(CTHREADBASE_MEMBERS_ONLY)
#define _CTHREADBASE_HPP
#endif // !defined(_CTHREADBASE_HPP) && !defined(CTHREADBASE_MEMBERS_ONLY) 

#if !defined(CTHREADBASE_MEMBERS_ONLY)
#include "cThreadInterface.hpp"
#include "cWait.hpp"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

///////////////////////////////////////////////////////////////////////
// Typedef: cThreadBaseExtend
//
//  Author: $author$
//    Date: 6/14/2011
///////////////////////////////////////////////////////////////////////
typedef cWait
cThreadBaseExtend;
///////////////////////////////////////////////////////////////////////
//  Class: cThreadBase
//
// Author: $author$
//   Date: 6/14/2011
///////////////////////////////////////////////////////////////////////
class c_INSTANCE_CLASS cThreadBase
: virtual public cThreadImplement,
  public cThreadBaseExtend
{
public:
    typedef cThreadImplement cImplements;
    typedef cThreadBaseExtend cExtends;

    bool m_isStarted;

    ///////////////////////////////////////////////////////////////////////
    //  Constructor: cThreadBase
    //
    //       Author: $author$
    //         Date: 6/14/2011
    ///////////////////////////////////////////////////////////////////////
    cThreadBase
    (bool isStarted=false,
     bool isCreated=false)
    : cExtends(isCreated),
      m_isStarted(isStarted)
    {
    }
    ///////////////////////////////////////////////////////////////////////
    //  Destructor: ~cThreadBase
    //
    //      Author: $author$
    //        Date: 6/14/2011
    ///////////////////////////////////////////////////////////////////////
    virtual ~cThreadBase()
    {
    }
#else // !defined(CTHREADBASE_MEMBERS_ONLY) 
#endif // !defined(CTHREADBASE_MEMBERS_ONLY) 

    ///////////////////////////////////////////////////////////////////////
    //  Function: Create
    //
    //    Author: $author$
    //      Date: 6/15/2011
    ///////////////////////////////////////////////////////////////////////
    virtual eError Create
    (bool initiallyStopped=false,
     bool onlyDestroyed=false)
#if defined(CTHREADBASE_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CTHREADBASE_MEMBER_FUNCS_INTERFACE) 
    {
        eError error = e_ERROR_FAILED;
#if !defined(CTHREADBASE_MEMBER_FUNCS_IMPLEMENT)
#else // !defined(CTHREADBASE_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CTHREADBASE_MEMBER_FUNCS_IMPLEMENT) 
        return error;
    }
#endif // defined(CTHREADBASE_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    //  Function: Destroy
    //
    //    Author: $author$
    //      Date: 6/15/2011
    ///////////////////////////////////////////////////////////////////////
    virtual eError Destroy
    (bool onlyCreated=false)
#if defined(CTHREADBASE_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CTHREADBASE_MEMBER_FUNCS_INTERFACE) 
    {
        eError error = e_ERROR_FAILED;
#if !defined(CTHREADBASE_MEMBER_FUNCS_IMPLEMENT)
#else // !defined(CTHREADBASE_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CTHREADBASE_MEMBER_FUNCS_IMPLEMENT) 
        return error;
    }
#endif // defined(CTHREADBASE_MEMBER_FUNCS_INTERFACE) 

    ///////////////////////////////////////////////////////////////////////
    //  Function: Start
    //
    //    Author: $author$
    //      Date: 6/14/2011
    ///////////////////////////////////////////////////////////////////////
    virtual eError Start
    (bool onlyStopped=false)
#if defined(CTHREADBASE_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CTHREADBASE_MEMBER_FUNCS_INTERFACE) 
    {
        eError error = e_ERROR_FAILED;
#if !defined(CTHREADBASE_MEMBER_FUNCS_IMPLEMENT)
#else // !defined(CTHREADBASE_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CTHREADBASE_MEMBER_FUNCS_IMPLEMENT) 
        return error;
    }
#endif // defined(CTHREADBASE_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    //  Function: Finish
    //
    //    Author: $author$
    //      Date: 6/14/2011
    ///////////////////////////////////////////////////////////////////////
    virtual eError Finish
    (mseconds_t waitMilliseconds,
     bool onlyStarted=false)
#if defined(CTHREADBASE_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CTHREADBASE_MEMBER_FUNCS_INTERFACE) 
    {
        eError error = e_ERROR_FAILED;
#if !defined(CTHREADBASE_MEMBER_FUNCS_IMPLEMENT)
#else // !defined(CTHREADBASE_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CTHREADBASE_MEMBER_FUNCS_IMPLEMENT) 
        return error;
    }
#endif // defined(CTHREADBASE_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    //  Function: Finish
    //
    //    Author: $author$
    //      Date: 6/14/2011
    ///////////////////////////////////////////////////////////////////////
    virtual eError Finish
    (bool onlyStarted=false)
#if defined(CTHREADBASE_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CTHREADBASE_MEMBER_FUNCS_INTERFACE) 
    {
        eError error = e_ERROR_FAILED;
#if !defined(CTHREADBASE_MEMBER_FUNCS_IMPLEMENT)
#else // !defined(CTHREADBASE_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CTHREADBASE_MEMBER_FUNCS_IMPLEMENT) 
        return error;
    }
#endif // defined(CTHREADBASE_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    //  Function: TryFinish
    //
    //    Author: $author$
    //      Date: 6/14/2011
    ///////////////////////////////////////////////////////////////////////
    virtual eError TryFinish
    (bool onlyStarted=false)
#if defined(CTHREADBASE_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CTHREADBASE_MEMBER_FUNCS_INTERFACE) 
    {
        eError error = e_ERROR_FAILED;
#if !defined(CTHREADBASE_MEMBER_FUNCS_IMPLEMENT)
#else // !defined(CTHREADBASE_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CTHREADBASE_MEMBER_FUNCS_IMPLEMENT) 
        return error;
    }
#endif // defined(CTHREADBASE_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    //  Function: Finished
    //
    //    Author: $author$
    //      Date: 6/15/2011
    ///////////////////////////////////////////////////////////////////////
    virtual eError Finished
    (bool onlyFinished=false)
#if defined(CTHREADBASE_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CTHREADBASE_MEMBER_FUNCS_INTERFACE) 
    {
        eError error = e_ERROR_FAILED;
#if !defined(CTHREADBASE_MEMBER_FUNCS_IMPLEMENT)
	    if (GetIsStarted())
		if (onlyFinished)
	        return error;
		else
		if ((error = Finish()))
		    return error;
#else // !defined(CTHREADBASE_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CTHREADBASE_MEMBER_FUNCS_IMPLEMENT) 
        return error;
    }
#endif // defined(CTHREADBASE_MEMBER_FUNCS_INTERFACE) 

    ///////////////////////////////////////////////////////////////////////
    //  Function: Run
    //
    //    Author: $author$
    //      Date: 6/14/2011
    ///////////////////////////////////////////////////////////////////////
    virtual eError Run()
#if defined(CTHREADBASE_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CTHREADBASE_MEMBER_FUNCS_INTERFACE) 
    {
        eError error = e_ERROR_NONE;
#if !defined(CTHREADBASE_MEMBER_FUNCS_IMPLEMENT)
#else // !defined(CTHREADBASE_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CTHREADBASE_MEMBER_FUNCS_IMPLEMENT) 
        return error;
    }
#endif // defined(CTHREADBASE_MEMBER_FUNCS_INTERFACE) 

    ///////////////////////////////////////////////////////////////////////
    //  Function: SetIsStarted
    //
    //    Author: $author$
    //      Date: 6/15/2011
    ///////////////////////////////////////////////////////////////////////
    virtual bool SetIsStarted
    (bool isTrue=true)
#if defined(CTHREADBASE_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CTHREADBASE_MEMBER_FUNCS_INTERFACE) 
    {
#if !defined(CTHREADBASE_MEMBER_FUNCS_IMPLEMENT)
        m_isStarted = (isTrue);
#else // !defined(CTHREADBASE_MEMBER_FUNCS_IMPLEMENT) 
        isTrue = false;
#endif // !defined(CTHREADBASE_MEMBER_FUNCS_IMPLEMENT) 
        return isTrue;
    }
#endif // defined(CTHREADBASE_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    //  Function: GetIsStarted
    //
    //    Author: $author$
    //      Date: 6/15/2011
    ///////////////////////////////////////////////////////////////////////
    virtual bool GetIsStarted() const
#if defined(CTHREADBASE_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CTHREADBASE_MEMBER_FUNCS_INTERFACE) 
    {
        bool isTrue = false;
#if !defined(CTHREADBASE_MEMBER_FUNCS_IMPLEMENT)
        isTrue = (m_isStarted);
#else // !defined(CTHREADBASE_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CTHREADBASE_MEMBER_FUNCS_IMPLEMENT) 
        return isTrue;
    }
#endif // defined(CTHREADBASE_MEMBER_FUNCS_INTERFACE) 

#if !defined(CTHREADBASE_MEMBERS_ONLY)
};

#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#else // !defined(CTHREADBASE_MEMBERS_ONLY) 
#endif // !defined(CTHREADBASE_MEMBERS_ONLY) 

#endif // !defined(_CTHREADBASE_HPP) || defined(CTHREADBASE_MEMBERS_ONLY) 
        

