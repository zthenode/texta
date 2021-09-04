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
//   File: cUnixDLibrary.hpp
//
// Author: $author$
//   Date: 10/13/2011
///////////////////////////////////////////////////////////////////////
#if !defined(_CUNIXDLIBRARY_HPP) || defined(CUNIXDLIBRARY_MEMBERS_ONLY)
#if !defined(_CUNIXDLIBRARY_HPP) && !defined(CUNIXDLIBRARY_MEMBERS_ONLY)
#define _CUNIXDLIBRARY_HPP
#endif // !defined(_CUNIXDLIBRARY_HPP) && !defined(CUNIXDLIBRARY_MEMBERS_ONLY) 

#if !defined(CUNIXDLIBRARY_MEMBERS_ONLY)
#include "cUnixDLibraryInterface.hpp"
#include "cDLibraryBase.hpp"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

///////////////////////////////////////////////////////////////////////
// Typedef: cUnixDLibraryExtend
//
//  Author: $author$
//    Date: 10/13/2011
///////////////////////////////////////////////////////////////////////
typedef cDLibraryBase
cUnixDLibraryExtend;
///////////////////////////////////////////////////////////////////////
//  Class: cUnixDLibrary
//
// Author: $author$
//   Date: 10/13/2011
///////////////////////////////////////////////////////////////////////
class c_INSTANCE_CLASS cUnixDLibrary
: virtual public cUnixDLibraryImplement,
  public cUnixDLibraryExtend
{
public:
    typedef cUnixDLibraryImplement cImplements;
    typedef cUnixDLibraryExtend cExtends;

    bool m_isOpen;

    ///////////////////////////////////////////////////////////////////////
    //  Constructor: cUnixDLibrary
    //
    //       Author: $author$
    //         Date: 10/13/2011
    ///////////////////////////////////////////////////////////////////////
    cUnixDLibrary
    (bool isOpen=false)
    : m_isOpen(isOpen)
    {
    }
    ///////////////////////////////////////////////////////////////////////
    //  Destructor: ~cUnixDLibrary
    //
    //      Author: $author$
    //        Date: 10/13/2011
    ///////////////////////////////////////////////////////////////////////
    virtual ~cUnixDLibrary()
    {
    }
#else // !defined(CUNIXDLIBRARY_MEMBERS_ONLY) 
#endif // !defined(CUNIXDLIBRARY_MEMBERS_ONLY) 

    ///////////////////////////////////////////////////////////////////////
    //  Function: Open
    //
    //    Author: $author$
    //      Date: 10/13/2011
    ///////////////////////////////////////////////////////////////////////
    virtual eError Open
    (const char* fileName,
     bool onlyClosed=false)
#if defined(CUNIXDLIBRARY_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CUNIXDLIBRARY_MEMBER_FUNCS_INTERFACE) 
    {
        eError error = e_ERROR_NOT_IMPLEMENTED;
#if !defined(CUNIXDLIBRARY_MEMBER_FUNCS_IMPLEMENT)
#else // !defined(CUNIXDLIBRARY_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CUNIXDLIBRARY_MEMBER_FUNCS_IMPLEMENT) 
        return error;
    }
#endif // defined(CUNIXDLIBRARY_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    //  Function: Close
    //
    //    Author: $author$
    //      Date: 10/13/2011
    ///////////////////////////////////////////////////////////////////////
    virtual eError Close
    (bool onlyOpen=false)
#if defined(CUNIXDLIBRARY_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CUNIXDLIBRARY_MEMBER_FUNCS_INTERFACE) 
    {
        eError error = e_ERROR_NOT_IMPLEMENTED;
#if !defined(CUNIXDLIBRARY_MEMBER_FUNCS_IMPLEMENT)
#else // !defined(CUNIXDLIBRARY_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CUNIXDLIBRARY_MEMBER_FUNCS_IMPLEMENT) 
        return error;
    }
#endif // defined(CUNIXDLIBRARY_MEMBER_FUNCS_INTERFACE) 

    ///////////////////////////////////////////////////////////////////////
    //  Function: OnOpen
    //
    //    Author: $author$
    //      Date: 10/27/2011
    ///////////////////////////////////////////////////////////////////////
    virtual eError OnOpen()
#if defined(CUNIXDLIBRARY_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CUNIXDLIBRARY_MEMBER_FUNCS_INTERFACE) 
    {
        eError error = e_ERROR_NONE;
#if !defined(CUNIXDLIBRARY_MEMBER_FUNCS_IMPLEMENT)
        error = OnLoad();
#else // !defined(CUNIXDLIBRARY_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CUNIXDLIBRARY_MEMBER_FUNCS_IMPLEMENT) 
        return error;
    }
#endif // defined(CUNIXDLIBRARY_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    //  Function: OnClose
    //
    //    Author: $author$
    //      Date: 10/27/2011
    ///////////////////////////////////////////////////////////////////////
    virtual eError OnClose()
#if defined(CUNIXDLIBRARY_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CUNIXDLIBRARY_MEMBER_FUNCS_INTERFACE) 
    {
        eError error = e_ERROR_NONE;
#if !defined(CUNIXDLIBRARY_MEMBER_FUNCS_IMPLEMENT)
        OnUnload();
#else // !defined(CUNIXDLIBRARY_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CUNIXDLIBRARY_MEMBER_FUNCS_IMPLEMENT) 
        return error;
    }
#endif // defined(CUNIXDLIBRARY_MEMBER_FUNCS_INTERFACE) 

    ///////////////////////////////////////////////////////////////////////
    //  Function: SetIsOpen
    //
    //    Author: $author$
    //      Date: 10/13/2011
    ///////////////////////////////////////////////////////////////////////
    virtual bool SetIsOpen
    (bool isTrue=true)
#if defined(CUNIXDLIBRARY_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CUNIXDLIBRARY_MEMBER_FUNCS_INTERFACE) 
    {
        bool is = false;
#if !defined(CUNIXDLIBRARY_MEMBER_FUNCS_IMPLEMENT)
        is =  (m_isOpen = isTrue);
#else // !defined(CUNIXDLIBRARY_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CUNIXDLIBRARY_MEMBER_FUNCS_IMPLEMENT) 
        return is;
    }
#endif // defined(CUNIXDLIBRARY_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    //  Function: GetIsOpen
    //
    //    Author: $author$
    //      Date: 10/13/2011
    ///////////////////////////////////////////////////////////////////////
    virtual bool GetIsOpen() const
#if defined(CUNIXDLIBRARY_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CUNIXDLIBRARY_MEMBER_FUNCS_INTERFACE) 
    {
        bool is = false;
#if !defined(CUNIXDLIBRARY_MEMBER_FUNCS_IMPLEMENT)
        is =  (m_isOpen);
#else // !defined(CUNIXDLIBRARY_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CUNIXDLIBRARY_MEMBER_FUNCS_IMPLEMENT) 
        return is;
    }
#endif // defined(CUNIXDLIBRARY_MEMBER_FUNCS_INTERFACE) 

#if !defined(CUNIXDLIBRARY_MEMBERS_ONLY)
    ///////////////////////////////////////////////////////////////////////
    //  Function: SetIsLoaded
    //
    //    Author: $author$
    //      Date: 10/13/2011
    ///////////////////////////////////////////////////////////////////////
    virtual bool SetIsLoaded
    (bool isTrue=true)
    {
        bool is = SetIsOpen(isTrue);
        return is;
    }
    ///////////////////////////////////////////////////////////////////////
    //  Function: GetIsLoaded
    //
    //    Author: $author$
    //      Date: 10/13/2011
    ///////////////////////////////////////////////////////////////////////
    virtual bool GetIsLoaded() const
    {
        bool is = GetIsLoaded();
        return is;
    }
};


#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#else // !defined(CUNIXDLIBRARY_MEMBERS_ONLY) 
#endif // !defined(CUNIXDLIBRARY_MEMBERS_ONLY) 

#endif // !defined(_CUNIXDLIBRARY_HPP) || defined(CUNIXDLIBRARY_MEMBERS_ONLY) 
        

