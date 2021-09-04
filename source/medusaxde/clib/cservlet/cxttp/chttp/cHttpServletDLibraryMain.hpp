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
//   File: cHttpServletDLibraryMain.hpp
//
// Author: $author$
//   Date: 10/20/2011
///////////////////////////////////////////////////////////////////////
#if !defined(_CHTTPSERVLETDLIBRARYMAIN_HPP) || defined(CHTTPSERVLETDLIBRARYMAIN_MEMBERS_ONLY)
#if !defined(_CHTTPSERVLETDLIBRARYMAIN_HPP) && !defined(CHTTPSERVLETDLIBRARYMAIN_MEMBERS_ONLY)
#define _CHTTPSERVLETDLIBRARYMAIN_HPP
#endif // !defined(_CHTTPSERVLETDLIBRARYMAIN_HPP) && !defined(CHTTPSERVLETDLIBRARYMAIN_MEMBERS_ONLY) 

#if !defined(CHTTPSERVLETDLIBRARYMAIN_MEMBERS_ONLY)
#include "cHttpServletDLibraryMainInterface.hpp"
#include "cHttpServletAcquirerInterface.hpp"
#include "cDLibraryMain.hpp"
#include "cDebug.hpp"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

///////////////////////////////////////////////////////////////////////
// Typedef: cHttpServletDLibraryMainExtend
//
//  Author: $author$
//    Date: 10/20/2011
///////////////////////////////////////////////////////////////////////
typedef cDLibraryMain
cHttpServletDLibraryMainExtend;
///////////////////////////////////////////////////////////////////////
//  Class: cHttpServletDLibraryMain
//
// Author: $author$
//   Date: 10/20/2011
///////////////////////////////////////////////////////////////////////
class c_INSTANCE_CLASS cHttpServletDLibraryMain
: virtual public cHttpServletDLibraryMainImplement,
  public cHttpServletDLibraryMainExtend
{
public:
    typedef cHttpServletDLibraryMainImplement cImplements;
    typedef cHttpServletDLibraryMainExtend cExtends;

    static cHttpServletDLibraryMainInterface* m_theMain;
    cHttpServletDLibraryMainInterface* m_theOldMain;

    ///////////////////////////////////////////////////////////////////////
    //  Constructor: cHttpServletDLibraryMain
    //
    //       Author: $author$
    //         Date: 10/20/2011
    ///////////////////////////////////////////////////////////////////////
    cHttpServletDLibraryMain()
    : m_theOldMain(m_theMain)
    {
        m_theMain = this;
    }
    ///////////////////////////////////////////////////////////////////////
    //  Destructor: ~cHttpServletDLibraryMain
    //
    //      Author: $author$
    //        Date: 10/20/2011
    ///////////////////////////////////////////////////////////////////////
    virtual ~cHttpServletDLibraryMain()
    {
        if (this == m_theMain)
            m_theMain = m_theOldMain;
    }
#else // !defined(CHTTPSERVLETDLIBRARYMAIN_MEMBERS_ONLY) 
#endif // !defined(CHTTPSERVLETDLIBRARYMAIN_MEMBERS_ONLY) 

    ///////////////////////////////////////////////////////////////////////
    //  Function: GetTheAcquirer
    //
    //    Author: $author$
    //      Date: 10/20/2011
    ///////////////////////////////////////////////////////////////////////
    virtual cHttpServletAcquirerInterface* GetTheAcquirer() const
#if defined(CHTTPSERVLETDLIBRARYMAIN_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CHTTPSERVLETDLIBRARYMAIN_MEMBER_FUNCS_INTERFACE) 
    {
        cHttpServletAcquirerInterface* theAcquirer = 0;
#if !defined(CHTTPSERVLETDLIBRARYMAIN_MEMBER_FUNCS_IMPLEMENT)
        if (!(theAcquirer = cHttpServletAcquirerInterface::GetTheAcquirer()))
            c_DB_ERROR("() failed on cHttpServletAcquirerInterface::GetTheAcquirer() == 0");
#else // !defined(CHTTPSERVLETDLIBRARYMAIN_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CHTTPSERVLETDLIBRARYMAIN_MEMBER_FUNCS_IMPLEMENT) 
        return theAcquirer;
    }
#endif // defined(CHTTPSERVLETDLIBRARYMAIN_MEMBER_FUNCS_INTERFACE) 


#if !defined(CHTTPSERVLETDLIBRARYMAIN_MEMBER_FUNCS_IMPLEMENT)
    ///////////////////////////////////////////////////////////////////////
    //  Function: GetTheMain
    //
    //    Author: $author$
    //      Date: 10/27/2011
    ///////////////////////////////////////////////////////////////////////
    static cHttpServletDLibraryMainInterface* GetTheMain()
#if defined(CHTTPSERVLETDLIBRARYMAIN_MEMBER_FUNCS_INTERFACE)
    ;
#else // defined(CHTTPSERVLETDLIBRARYMAIN_MEMBER_FUNCS_INTERFACE) 
    {
        return m_theMain;
    }
#endif // defined(CHTTPSERVLETDLIBRARYMAIN_MEMBER_FUNCS_INTERFACE) 
#else // !defined(CHTTPSERVLETDLIBRARYMAIN_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CHTTPSERVLETDLIBRARYMAIN_MEMBER_FUNCS_IMPLEMENT) 

#if !defined(CHTTPSERVLETDLIBRARYMAIN_MEMBERS_ONLY)
    ///////////////////////////////////////////////////////////////////////
    //  Function: Init
    //
    //    Author: $author$
    //      Date: 10/20/2011
    ///////////////////////////////////////////////////////////////////////
    virtual eError Init()
    {
        eError error = e_ERROR_FAILED;
        cHttpServletAcquirerInterface* theAcquirer = 0;
        if ((theAcquirer = GetTheAcquirer()))
            error = theAcquirer->Init();
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    //  Function: Finish
    //
    //    Author: $author$
    //      Date: 10/20/2011
    ///////////////////////////////////////////////////////////////////////
    virtual eError Finish()
    {
        eError error = e_ERROR_FAILED;
        cHttpServletAcquirerInterface* theAcquirer = 0;
        if ((theAcquirer = GetTheAcquirer()))
            error = theAcquirer->Finish();
        return error;
    }
};

#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#else // !defined(CHTTPSERVLETDLIBRARYMAIN_MEMBERS_ONLY) 
#endif // !defined(CHTTPSERVLETDLIBRARYMAIN_MEMBERS_ONLY) 

#endif // !defined(_CHTTPSERVLETDLIBRARYMAIN_HPP) || defined(CHTTPSERVLETDLIBRARYMAIN_MEMBERS_ONLY) 
