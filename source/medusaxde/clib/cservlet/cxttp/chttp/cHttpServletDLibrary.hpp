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
//   File: cHttpServletDLibrary.hpp
//
// Author: $author$
//   Date: 10/27/2011
///////////////////////////////////////////////////////////////////////
#if !defined(_CHTTPSERVLETDLIBRARY_HPP) || defined(CHTTPSERVLETDLIBRARY_MEMBERS_ONLY)
#if !defined(_CHTTPSERVLETDLIBRARY_HPP) && !defined(CHTTPSERVLETDLIBRARY_MEMBERS_ONLY)
#define _CHTTPSERVLETDLIBRARY_HPP
#endif // !defined(_CHTTPSERVLETDLIBRARY_HPP) && !defined(CHTTPSERVLETDLIBRARY_MEMBERS_ONLY) 

#if !defined(CHTTPSERVLETDLIBRARY_MEMBERS_ONLY)
#include "cHttpServletDLibraryInterface.hpp"
#include "cDLibrary.hpp"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

///////////////////////////////////////////////////////////////////////
// Typedef: cHttpServletDLibraryExtend
//
//  Author: $author$
//    Date: 10/27/2011
///////////////////////////////////////////////////////////////////////
typedef cDLibrary
cHttpServletDLibraryExtend;
///////////////////////////////////////////////////////////////////////
//  Class: cHttpServletDLibrary
//
// Author: $author$
//   Date: 10/27/2011
///////////////////////////////////////////////////////////////////////
class c_INSTANCE_CLASS cHttpServletDLibrary
: virtual public cHttpServletDLibraryImplement,
  public cHttpServletDLibraryExtend
{
public:
    typedef cHttpServletDLibraryImplement cImplements;
    typedef cHttpServletDLibraryExtend cExtends;

    cString m_getHttpServletAcquirerSymbol;
    fGetHttpServletAcquirer* m_getHttpServletAcquirer;
    cHttpServletAcquirerInterface* m_httpServletAcquirer;

    ///////////////////////////////////////////////////////////////////////
    //  Constructor: cHttpServletDLibrary
    //
    //       Author: $author$
    //         Date: 10/27/2011
    ///////////////////////////////////////////////////////////////////////
    cHttpServletDLibrary()
    : m_getHttpServletAcquirerSymbol(GET_HTTP_SERVLET_ACQUIRER_SYMBOL),
      m_getHttpServletAcquirer(0),
      m_httpServletAcquirer(0)
    {
    }
    ///////////////////////////////////////////////////////////////////////
    //  Destructor: ~cHttpServletDLibrary
    //
    //      Author: $author$
    //        Date: 10/27/2011
    ///////////////////////////////////////////////////////////////////////
    virtual ~cHttpServletDLibrary()
    {
    }
#else // !defined(CHTTPSERVLETDLIBRARY_MEMBERS_ONLY) 
#endif // !defined(CHTTPSERVLETDLIBRARY_MEMBERS_ONLY) 

    ///////////////////////////////////////////////////////////////////////
    //  Function: AcquireHttpServlet
    //
    //    Author: $author$
    //      Date: 10/29/2011
    ///////////////////////////////////////////////////////////////////////
    virtual cHttpServletInterface* AcquireHttpServlet
    (eError& error)
#if defined(CHTTPSERVLETDLIBRARY_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CHTTPSERVLETDLIBRARY_MEMBER_FUNCS_INTERFACE) 
    {
        cHttpServletInterface* servlet = 0;
#if !defined(CHTTPSERVLETDLIBRARY_MEMBER_FUNCS_IMPLEMENT)
        if ((m_httpServletAcquirer))
            servlet = m_httpServletAcquirer->AcquireHttpServlet(error);
        else
        error = e_ERROR_FAILED;
#else // !defined(CHTTPSERVLETDLIBRARY_MEMBER_FUNCS_IMPLEMENT) 
        error = e_ERROR_NOT_IMPLEMENTED;
#endif // !defined(CHTTPSERVLETDLIBRARY_MEMBER_FUNCS_IMPLEMENT) 
        return servlet;
    }
#endif // defined(CHTTPSERVLETDLIBRARY_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    //  Function: ReleaseHttpServlet
    //
    //    Author: $author$
    //      Date: 10/29/2011
    ///////////////////////////////////////////////////////////////////////
    virtual eError ReleaseHttpServlet
    (cHttpServletInterface* servlet)
#if defined(CHTTPSERVLETDLIBRARY_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CHTTPSERVLETDLIBRARY_MEMBER_FUNCS_INTERFACE) 
    {
#if !defined(CHTTPSERVLETDLIBRARY_MEMBER_FUNCS_IMPLEMENT)
        eError error = e_ERROR_FAILED;
        if ((m_httpServletAcquirer))
            error = m_httpServletAcquirer->ReleaseHttpServlet(servlet);
#else // !defined(CHTTPSERVLETDLIBRARY_MEMBER_FUNCS_IMPLEMENT) 
        eError error = e_ERROR_NOT_IMPLEMENTED;
#endif // !defined(CHTTPSERVLETDLIBRARY_MEMBER_FUNCS_IMPLEMENT) 
        return error;
    }
#endif // defined(CHTTPSERVLETDLIBRARY_MEMBER_FUNCS_INTERFACE) 

#if !defined(CHTTPSERVLETDLIBRARY_MEMBERS_ONLY)
    ///////////////////////////////////////////////////////////////////////
    //  Function: OnLoad
    //
    //    Author: $author$
    //      Date: 10/27/2011
    ///////////////////////////////////////////////////////////////////////
    virtual eError OnLoad()
    {
        eError error = e_ERROR_NONE;
        const char* symbol;
        if ((symbol = m_getHttpServletAcquirerSymbol.HasChars()))
        if (!(m_getHttpServletAcquirer = (fGetHttpServletAcquirer*)(GetAddress(symbol))))
            c_DB_ERROR("() failed on GetAddress(\"" << symbol << "\")");
        else
        if (!(m_httpServletAcquirer = (*m_getHttpServletAcquirer)()))
            c_DB_ERROR("() failed on (*m_getHttpServletAcquirer)()");
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    //  Function: OnUnload
    //
    //    Author: $author$
    //      Date: 10/27/2011
    ///////////////////////////////////////////////////////////////////////
    virtual eError OnUnload()
    {
        eError error = e_ERROR_NONE;
        m_httpServletAcquirer = 0;
        m_getHttpServletAcquirer = 0;
        return error;
    }
};


#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#else // !defined(CHTTPSERVLETDLIBRARY_MEMBERS_ONLY) 
#endif // !defined(CHTTPSERVLETDLIBRARY_MEMBERS_ONLY) 

#endif // !defined(_CHTTPSERVLETDLIBRARY_HPP) || defined(CHTTPSERVLETDLIBRARY_MEMBERS_ONLY) 
        

