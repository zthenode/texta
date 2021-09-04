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
//   File: cUnixDLibraryMain.hpp
//
// Author: $author$
//   Date: 10/16/2011
///////////////////////////////////////////////////////////////////////
#if !defined(_CUNIXDLIBRARYMAIN_HPP) || defined(CUNIXDLIBRARYMAIN_MEMBERS_ONLY)
#if !defined(_CUNIXDLIBRARYMAIN_HPP) && !defined(CUNIXDLIBRARYMAIN_MEMBERS_ONLY)
#define _CUNIXDLIBRARYMAIN_HPP
#endif // !defined(_CUNIXDLIBRARYMAIN_HPP) && !defined(CUNIXDLIBRARYMAIN_MEMBERS_ONLY) 

#if !defined(CUNIXDLIBRARYMAIN_MEMBERS_ONLY)
#include "cUnixDLibraryMainInterface.hpp"
#include "cDLibraryMainBase.hpp"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

///////////////////////////////////////////////////////////////////////
// Typedef: cUnixDLibraryMainExtend
//
//  Author: $author$
//    Date: 10/16/2011
///////////////////////////////////////////////////////////////////////
typedef cDLibraryMainBase
cUnixDLibraryMainExtend;
///////////////////////////////////////////////////////////////////////
//  Class: cUnixDLibraryMain
//
// Author: $author$
//   Date: 10/16/2011
///////////////////////////////////////////////////////////////////////
class c_INSTANCE_CLASS cUnixDLibraryMain
: virtual public cUnixDLibraryMainImplement,
  public cUnixDLibraryMainExtend
{
public:
    typedef cUnixDLibraryMainImplement cImplements;
    typedef cUnixDLibraryMainExtend cExtends;

    static cUnixDLibraryMainInterface* m_theMain;
    cUnixDLibraryMainInterface* m_theOldMain;

    ///////////////////////////////////////////////////////////////////////
    //  Constructor: cUnixDLibraryMain
    //
    //       Author: $author$
    //         Date: 10/16/2011
    ///////////////////////////////////////////////////////////////////////
    cUnixDLibraryMain()
    : m_theOldMain(m_theMain)
    {
        m_theMain = this;
    }
    ///////////////////////////////////////////////////////////////////////
    //  Destructor: ~cUnixDLibraryMain
    //
    //      Author: $author$
    //        Date: 10/16/2011
    ///////////////////////////////////////////////////////////////////////
    virtual ~cUnixDLibraryMain()
    {
        if (this == m_theMain)
            m_theMain = m_theOldMain;
    }
#else // !defined(CUNIXDLIBRARYMAIN_MEMBERS_ONLY) 
#endif // !defined(CUNIXDLIBRARYMAIN_MEMBERS_ONLY) 

#if !defined(CUNIXDLIBRARYMAIN_MEMBER_FUNCS_IMPLEMENT)
    ///////////////////////////////////////////////////////////////////////
    //  Function: GetTheMain
    //
    //    Author: $author$
    //      Date: 10/18/2011
    ///////////////////////////////////////////////////////////////////////
    static cUnixDLibraryMainInterface* GetTheMain()
#if defined(CUNIXDLIBRARYMAIN_MEMBER_FUNCS_INTERFACE)
    ;
#else // defined(CUNIXDLIBRARYMAIN_MEMBER_FUNCS_INTERFACE) 
    { return m_theMain; }
#endif // defined(CUNIXDLIBRARYMAIN_MEMBER_FUNCS_INTERFACE) 
#else // !defined(CUNIXDLIBRARYMAIN_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CUNIXDLIBRARYMAIN_MEMBER_FUNCS_IMPLEMENT) 

#if !defined(CUNIXDLIBRARYMAIN_MEMBERS_ONLY)
};

#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#else // !defined(CUNIXDLIBRARYMAIN_MEMBERS_ONLY) 
#endif // !defined(CUNIXDLIBRARYMAIN_MEMBERS_ONLY) 

#endif // !defined(_CUNIXDLIBRARYMAIN_HPP) || defined(CUNIXDLIBRARYMAIN_MEMBERS_ONLY) 
        

