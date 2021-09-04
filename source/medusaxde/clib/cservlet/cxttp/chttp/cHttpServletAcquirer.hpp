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
//   File: cHttpServletAcquirer.hpp
//
// Author: $author$
//   Date: 10/15/2011
///////////////////////////////////////////////////////////////////////
#if !defined(_CHTTPSERVLETACQUIRER_HPP) || defined(CHTTPSERVLETACQUIRER_MEMBERS_ONLY)
#if !defined(_CHTTPSERVLETACQUIRER_HPP) && !defined(CHTTPSERVLETACQUIRER_MEMBERS_ONLY)
#define _CHTTPSERVLETACQUIRER_HPP
#endif // !defined(_CHTTPSERVLETACQUIRER_HPP) && !defined(CHTTPSERVLETACQUIRER_MEMBERS_ONLY) 

#if !defined(CHTTPSERVLETACQUIRER_MEMBERS_ONLY)
#include "cHttpServletAcquirerInterface.hpp"
#include "cInstanceBase.hpp"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

///////////////////////////////////////////////////////////////////////
// Typedef: cHttpServletExtend
//
//  Author: $author$
//    Date: 10/15/2011
///////////////////////////////////////////////////////////////////////
typedef cInstanceBase
cHttpServletAcquirerExtend;
///////////////////////////////////////////////////////////////////////
//  Class: cHttpServletAcquirer
//
// Author: $author$
//   Date: 10/15/2011
///////////////////////////////////////////////////////////////////////
class c_INSTANCE_CLASS cHttpServletAcquirer
: virtual public cHttpServletAcquirerImplement,
  public cHttpServletAcquirerExtend
{
public:
    typedef cHttpServletAcquirerImplement cImplements;
    typedef cHttpServletAcquirerExtend cExtends;

    static cHttpServletAcquirerInterface* m_theAcquirer;
    cHttpServletAcquirerInterface* m_theOldAcquirer;

    bool m_isHttpServletAcquired;

    ///////////////////////////////////////////////////////////////////////
    //  Constructor: cHttpServletAcquirer
    //
    //       Author: $author$
    //         Date: 10/15/2011
    ///////////////////////////////////////////////////////////////////////
    cHttpServletAcquirer()
    : m_theOldAcquirer(m_theAcquirer),
      m_isHttpServletAcquired(false)
    {
        m_theAcquirer = this;
    }
    ///////////////////////////////////////////////////////////////////////
    //  Destructor: ~cHttpServletAcquirer
    //
    //      Author: $author$
    //        Date: 10/15/2011
    ///////////////////////////////////////////////////////////////////////
    virtual ~cHttpServletAcquirer()
    {
        if (this == m_theAcquirer)
            m_theAcquirer = m_theOldAcquirer;
    }
#else // !defined(CHTTPSERVLETACQUIRER_MEMBERS_ONLY) 
#endif // !defined(CHTTPSERVLETACQUIRER_MEMBERS_ONLY) 

    ///////////////////////////////////////////////////////////////////////
    //  Function: Init
    //
    //    Author: $author$
    //      Date: 10/20/2011
    ///////////////////////////////////////////////////////////////////////
    virtual eError Init()
#if defined(CHTTPSERVLETACQUIRER_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CHTTPSERVLETACQUIRER_MEMBER_FUNCS_INTERFACE) 
    {
        eError error = e_ERROR_NONE;
#if !defined(CHTTPSERVLETACQUIRER_MEMBER_FUNCS_IMPLEMENT)
#else // !defined(CHTTPSERVLETACQUIRER_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CHTTPSERVLETACQUIRER_MEMBER_FUNCS_IMPLEMENT) 
        return error;
    }
#endif // defined(CHTTPSERVLETACQUIRER_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    //  Function: Finish
    //
    //    Author: $author$
    //      Date: 10/20/2011
    ///////////////////////////////////////////////////////////////////////
    virtual eError Finish()
#if defined(CHTTPSERVLETACQUIRER_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CHTTPSERVLETACQUIRER_MEMBER_FUNCS_INTERFACE) 
    {
        eError error = e_ERROR_NONE;
#if !defined(CHTTPSERVLETACQUIRER_MEMBER_FUNCS_IMPLEMENT)
#else // !defined(CHTTPSERVLETACQUIRER_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CHTTPSERVLETACQUIRER_MEMBER_FUNCS_IMPLEMENT) 
        return error;
    }
#endif // defined(CHTTPSERVLETACQUIRER_MEMBER_FUNCS_INTERFACE) 

    ///////////////////////////////////////////////////////////////////////
    //  Function: AcquireHttpServlet
    //
    //    Author: $author$
    //      Date: 10/16/2011
    ///////////////////////////////////////////////////////////////////////
    virtual cHttpServletInterface* AcquireHttpServlet
    (eError& error)
#if defined(CHTTPSERVLETACQUIRER_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CHTTPSERVLETACQUIRER_MEMBER_FUNCS_INTERFACE) 
    {
        cHttpServletInterface* servlet = 0;
#if !defined(CHTTPSERVLETACQUIRER_MEMBER_FUNCS_IMPLEMENT)
        if ((GetIsHttpServletAcquired()))
            error = e_ERROR_ALREADY_ACQUIRED;
        else
        if ((servlet = GetHttpServlet()))
        {
            error = e_ERROR_NONE;
            SetIsHttpServletAcquired();
        }
        else
        error = e_ERROR_FAILED;
#else // !defined(CHTTPSERVLETACQUIRER_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CHTTPSERVLETACQUIRER_MEMBER_FUNCS_IMPLEMENT) 
        return servlet;
    }
#endif // defined(CHTTPSERVLETACQUIRER_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    //  Function: ReleaseHttpServlet
    //
    //    Author: $author$
    //      Date: 10/16/2011
    ///////////////////////////////////////////////////////////////////////
    virtual eError ReleaseHttpServlet
    (cHttpServletInterface* servlet)
#if defined(CHTTPSERVLETACQUIRER_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CHTTPSERVLETACQUIRER_MEMBER_FUNCS_INTERFACE) 
    {
        eError error = e_ERROR_NOT_IMPLEMENTED;
#if !defined(CHTTPSERVLETACQUIRER_MEMBER_FUNCS_IMPLEMENT)
        cHttpServletInterface* acquiredServlet;
        error = e_ERROR_FAILED;
        if ((GetIsHttpServletAcquired()))
        {
            if ((acquiredServlet = GetHttpServlet()))
            if ((servlet != acquiredServlet))
                error = e_ERROR_NOT_ACQUIRED;
            else
            {
                SetIsHttpServletAcquired(false);
                error = e_ERROR_NONE;
            }
        }
        else
        error = e_ERROR_NOT_ACQUIRED;
#else // !defined(CHTTPSERVLETACQUIRER_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CHTTPSERVLETACQUIRER_MEMBER_FUNCS_IMPLEMENT) 
        return error;
    }
#endif // defined(CHTTPSERVLETACQUIRER_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    //  Function: ReleaseAllHttpServlets
    //
    //    Author: $author$
    //      Date: 10/16/2011
    ///////////////////////////////////////////////////////////////////////
    virtual eError ReleaseAllHttpServlets()
#if defined(CHTTPSERVLETACQUIRER_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CHTTPSERVLETACQUIRER_MEMBER_FUNCS_INTERFACE) 
    {
        eError error = e_ERROR_NOT_IMPLEMENTED;
#if !defined(CHTTPSERVLETACQUIRER_MEMBER_FUNCS_IMPLEMENT)
#else // !defined(CHTTPSERVLETACQUIRER_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CHTTPSERVLETACQUIRER_MEMBER_FUNCS_IMPLEMENT) 
        return error;
    }
#endif // defined(CHTTPSERVLETACQUIRER_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    //  Function: GetHttpServlet
    //
    //    Author: $author$
    //      Date: 10/27/2011
    ///////////////////////////////////////////////////////////////////////
    virtual cHttpServletInterface* GetHttpServlet() const
#if defined(CHTTPSERVLETACQUIRER_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CHTTPSERVLETACQUIRER_MEMBER_FUNCS_INTERFACE) 
    {
        cHttpServletInterface* servlet = 0;
#if !defined(CHTTPSERVLETACQUIRER_MEMBER_FUNCS_IMPLEMENT)
#else // !defined(CHTTPSERVLETACQUIRER_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CHTTPSERVLETACQUIRER_MEMBER_FUNCS_IMPLEMENT) 
        return servlet;
    }
#endif // defined(CHTTPSERVLETACQUIRER_MEMBER_FUNCS_INTERFACE) 

    ///////////////////////////////////////////////////////////////////////
    //  Function: SetIsHttpServletAcquired
    //
    //    Author: $author$
    //      Date: 10/27/2011
    ///////////////////////////////////////////////////////////////////////
    virtual bool SetIsHttpServletAcquired
    (bool isTrue=true)
#if defined(CHTTPSERVLETACQUIRER_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CHTTPSERVLETACQUIRER_MEMBER_FUNCS_INTERFACE) 
    {
        bool is = false;
#if !defined(CHTTPSERVLETACQUIRER_MEMBER_FUNCS_IMPLEMENT)
        is =  (m_isHttpServletAcquired = isTrue);
#else // !defined(CHTTPSERVLETACQUIRER_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CHTTPSERVLETACQUIRER_MEMBER_FUNCS_IMPLEMENT) 
        return is;
    }
#endif // defined(CHTTPSERVLETACQUIRER_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    //  Function: GetIsHttpServletAcquired
    //
    //    Author: $author$
    //      Date: 10/27/2011
    ///////////////////////////////////////////////////////////////////////
    virtual bool GetIsHttpServletAcquired() const
#if defined(CHTTPSERVLETACQUIRER_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CHTTPSERVLETACQUIRER_MEMBER_FUNCS_INTERFACE) 
    {
        bool is = false;
#if !defined(CHTTPSERVLETACQUIRER_MEMBER_FUNCS_IMPLEMENT)
        is =  (m_isHttpServletAcquired);
#else // !defined(CHTTPSERVLETACQUIRER_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CHTTPSERVLETACQUIRER_MEMBER_FUNCS_IMPLEMENT) 
        return is;
    }
#endif // defined(CHTTPSERVLETACQUIRER_MEMBER_FUNCS_INTERFACE) 

#if !defined(CHTTPSERVLETACQUIRER_MEMBER_FUNCS_IMPLEMENT)
    ///////////////////////////////////////////////////////////////////////
    //  Function: GetTheAcquirer
    //
    //    Author: $author$
    //      Date: 10/20/2011
    ///////////////////////////////////////////////////////////////////////
    static cHttpServletAcquirerInterface* GetTheAcquirer()
#if defined(CHTTPSERVLETACQUIRER_MEMBER_FUNCS_INTERFACE)
    ;
#else // defined(CHTTPSERVLETACQUIRER_MEMBER_FUNCS_INTERFACE) 
    { return m_theAcquirer; }
#endif // defined(CHTTPSERVLETACQUIRER_MEMBER_FUNCS_INTERFACE) 
#else // !defined(CHTTPSERVLETACQUIRER_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CHTTPSERVLETACQUIRER_MEMBER_FUNCS_IMPLEMENT) 

#if !defined(CHTTPSERVLETACQUIRER_MEMBERS_ONLY)
};


#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#else // !defined(CHTTPSERVLETACQUIRER_MEMBERS_ONLY) 
#endif // !defined(CHTTPSERVLETACQUIRER_MEMBERS_ONLY) 

#endif // !defined(_CHTTPSERVLETACQUIRER_HPP) || defined(CHTTPSERVLETACQUIRER_MEMBERS_ONLY) 
        

