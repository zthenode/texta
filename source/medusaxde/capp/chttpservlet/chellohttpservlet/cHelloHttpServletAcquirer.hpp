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
//   File: cHelloHttpServletAcquirer.hpp
//
// Author: $author$
//   Date: 10/20/2011
///////////////////////////////////////////////////////////////////////
#if !defined(_CHELLOHTTPSERVLETACQUIRER_HPP) || defined(CHELLOHTTPSERVLETACQUIRER_MEMBERS_ONLY)
#if !defined(_CHELLOHTTPSERVLETACQUIRER_HPP) && !defined(CHELLOHTTPSERVLETACQUIRER_MEMBERS_ONLY)
#define _CHELLOHTTPSERVLETACQUIRER_HPP
#endif // !defined(_CHELLOHTTPSERVLETACQUIRER_HPP) && !defined(CHELLOHTTPSERVLETACQUIRER_MEMBERS_ONLY) 

#if !defined(CHELLOHTTPSERVLETACQUIRER_MEMBERS_ONLY)
#include "cHttpServletAcquirer.hpp"
#include "cHelloHttpServlet.hpp"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

///////////////////////////////////////////////////////////////////////
//  Class: cHelloHttpServletAcquirer
//
// Author: $author$
//   Date: 10/20/2011
///////////////////////////////////////////////////////////////////////
class c_INSTANCE_CLASS cHelloHttpServletAcquirer
: public cHttpServletAcquirer
{
public:
    typedef cHttpServletAcquirer cExtends;

    cHelloHttpServlet m_helloHttpServlet;
#else // !defined(CHELLOHTTPSERVLETACQUIRER_MEMBERS_ONLY) 
#endif // !defined(CHELLOHTTPSERVLETACQUIRER_MEMBERS_ONLY) 

#if !defined(CHELLOHTTPSERVLETACQUIRER_MEMBERS_ONLY)
    ///////////////////////////////////////////////////////////////////////
    //  Function: GetHttpServlet
    //
    //    Author: $author$
    //      Date: 10/27/2011
    ///////////////////////////////////////////////////////////////////////
    virtual cHttpServletInterface* GetHttpServlet() const
    {
        cHttpServletInterface* servlet 
        = (cHttpServletInterface*)(&m_helloHttpServlet);
        return servlet;
    }
};


#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#else // !defined(CHELLOHTTPSERVLETACQUIRER_MEMBERS_ONLY) 
#endif // !defined(CHELLOHTTPSERVLETACQUIRER_MEMBERS_ONLY) 

#endif // !defined(_CHELLOHTTPSERVLETACQUIRER_HPP) || defined(CHELLOHTTPSERVLETACQUIRER_MEMBERS_ONLY) 
        

