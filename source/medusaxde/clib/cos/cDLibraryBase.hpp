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
//   File: cDLibraryBase.hpp
//
// Author: $author$
//   Date: 10/13/2011
///////////////////////////////////////////////////////////////////////
#if !defined(_CDLIBRARYBASE_HPP) || defined(CDLIBRARYBASE_MEMBERS_ONLY)
#if !defined(_CDLIBRARYBASE_HPP) && !defined(CDLIBRARYBASE_MEMBERS_ONLY)
#define _CDLIBRARYBASE_HPP
#endif // !defined(_CDLIBRARYBASE_HPP) && !defined(CDLIBRARYBASE_MEMBERS_ONLY) 

#if !defined(CDLIBRARYBASE_MEMBERS_ONLY)
#include "cDLibraryInterface.hpp"
#include "cInstanceBase.hpp"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

///////////////////////////////////////////////////////////////////////
// Typedef: cDLibraryBaseExtend
//
//  Author: $author$
//    Date: 10/13/2011
///////////////////////////////////////////////////////////////////////
typedef cInstanceBase
cDLibraryBaseExtend;
///////////////////////////////////////////////////////////////////////
//  Class: cDLibraryBase
//
// Author: $author$
//   Date: 10/13/2011
///////////////////////////////////////////////////////////////////////
class c_INSTANCE_CLASS cDLibraryBase
: virtual public cDLibraryImplement,
  public cDLibraryBaseExtend
{
public:
    typedef cDLibraryImplement cImplements;
    typedef cDLibraryBaseExtend cExtends;
    ///////////////////////////////////////////////////////////////////////
    //  Constructor: cDLibraryBase
    //
    //       Author: $author$
    //         Date: 10/13/2011
    ///////////////////////////////////////////////////////////////////////
    cDLibraryBase()
    {
    }
    ///////////////////////////////////////////////////////////////////////
    //  Destructor: ~cDLibraryBase
    //
    //      Author: $author$
    //        Date: 10/13/2011
    ///////////////////////////////////////////////////////////////////////
    virtual ~cDLibraryBase()
    {
    }
#else // !defined(CDLIBRARYBASE_MEMBERS_ONLY) 
#endif // !defined(CDLIBRARYBASE_MEMBERS_ONLY) 

    ///////////////////////////////////////////////////////////////////////
    //  Function: Load
    //
    //    Author: $author$
    //      Date: 10/13/2011
    ///////////////////////////////////////////////////////////////////////
    virtual eError Load
    (const wchar_t* fileName,
     bool onlyUnloaded=false)
#if defined(CDLIBRARYBASE_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CDLIBRARYBASE_MEMBER_FUNCS_INTERFACE) 
    {
        eError error = e_ERROR_NOT_IMPLEMENTED;
#if !defined(CDLIBRARYBASE_MEMBER_FUNCS_IMPLEMENT)
#else // !defined(CDLIBRARYBASE_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CDLIBRARYBASE_MEMBER_FUNCS_IMPLEMENT) 
        return error;
    }
#endif // defined(CDLIBRARYBASE_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    //  Function: Load
    //
    //    Author: $author$
    //      Date: 10/13/2011
    ///////////////////////////////////////////////////////////////////////
    virtual eError Load
    (const char* fileName,
     bool onlyUnloaded=false)
#if defined(CDLIBRARYBASE_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CDLIBRARYBASE_MEMBER_FUNCS_INTERFACE) 
    {
        eError error = e_ERROR_NOT_IMPLEMENTED;
#if !defined(CDLIBRARYBASE_MEMBER_FUNCS_IMPLEMENT)
#else // !defined(CDLIBRARYBASE_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CDLIBRARYBASE_MEMBER_FUNCS_IMPLEMENT) 
        return error;
    }
#endif // defined(CDLIBRARYBASE_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    //  Function: Unload
    //
    //    Author: $author$
    //      Date: 10/13/2011
    ///////////////////////////////////////////////////////////////////////
    virtual eError Unload
    (bool onlyLoaded=false)
#if defined(CDLIBRARYBASE_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CDLIBRARYBASE_MEMBER_FUNCS_INTERFACE) 
    {
        eError error = e_ERROR_NOT_IMPLEMENTED;
#if !defined(CDLIBRARYBASE_MEMBER_FUNCS_IMPLEMENT)
#else // !defined(CDLIBRARYBASE_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CDLIBRARYBASE_MEMBER_FUNCS_IMPLEMENT) 
        return error;
    }
#endif // defined(CDLIBRARYBASE_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    //  Function: OnLoad
    //
    //    Author: $author$
    //      Date: 10/27/2011
    ///////////////////////////////////////////////////////////////////////
    virtual eError OnLoad()
#if defined(CDLIBRARYBASE_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CDLIBRARYBASE_MEMBER_FUNCS_INTERFACE) 
    {
        eError error = e_ERROR_NONE;
#if !defined(CDLIBRARYBASE_MEMBER_FUNCS_IMPLEMENT)
#else // !defined(CDLIBRARYBASE_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CDLIBRARYBASE_MEMBER_FUNCS_IMPLEMENT) 
        return error;
    }
#endif // defined(CDLIBRARYBASE_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    //  Function: OnUnload
    //
    //    Author: $author$
    //      Date: 10/27/2011
    ///////////////////////////////////////////////////////////////////////
    virtual eError OnUnload()
#if defined(CDLIBRARYBASE_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CDLIBRARYBASE_MEMBER_FUNCS_INTERFACE) 
    {
        eError error = e_ERROR_NONE;
#if !defined(CDLIBRARYBASE_MEMBER_FUNCS_IMPLEMENT)
#else // !defined(CDLIBRARYBASE_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CDLIBRARYBASE_MEMBER_FUNCS_IMPLEMENT) 
        return error;
    }
#endif // defined(CDLIBRARYBASE_MEMBER_FUNCS_INTERFACE) 

    ///////////////////////////////////////////////////////////////////////
    //  Function: Open
    //
    //    Author: $author$
    //      Date: 10/13/2011
    ///////////////////////////////////////////////////////////////////////
    virtual eError Open
    (const wchar_t* fileName,
     bool onlyClosed=false)
#if defined(CDLIBRARYBASE_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CDLIBRARYBASE_MEMBER_FUNCS_INTERFACE) 
    {
        eError error = e_ERROR_NOT_IMPLEMENTED;
#if !defined(CDLIBRARYBASE_MEMBER_FUNCS_IMPLEMENT)
#else // !defined(CDLIBRARYBASE_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CDLIBRARYBASE_MEMBER_FUNCS_IMPLEMENT) 
        return error;
    }
#endif // defined(CDLIBRARYBASE_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    //  Function: Open
    //
    //    Author: $author$
    //      Date: 10/13/2011
    ///////////////////////////////////////////////////////////////////////
    virtual eError Open
    (const char* fileName,
     bool onlyClosed=false)
#if defined(CDLIBRARYBASE_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CDLIBRARYBASE_MEMBER_FUNCS_INTERFACE) 
    {
        eError error = e_ERROR_NOT_IMPLEMENTED;
#if !defined(CDLIBRARYBASE_MEMBER_FUNCS_IMPLEMENT)
#else // !defined(CDLIBRARYBASE_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CDLIBRARYBASE_MEMBER_FUNCS_IMPLEMENT) 
        return error;
    }
#endif // defined(CDLIBRARYBASE_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    //  Function: Close
    //
    //    Author: $author$
    //      Date: 10/13/2011
    ///////////////////////////////////////////////////////////////////////
    virtual eError Close
    (bool onlyOpen=false)
#if defined(CDLIBRARYBASE_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CDLIBRARYBASE_MEMBER_FUNCS_INTERFACE) 
    {
        eError error = e_ERROR_NOT_IMPLEMENTED;
#if !defined(CDLIBRARYBASE_MEMBER_FUNCS_IMPLEMENT)
#else // !defined(CDLIBRARYBASE_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CDLIBRARYBASE_MEMBER_FUNCS_IMPLEMENT) 
        return error;
    }
#endif // defined(CDLIBRARYBASE_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    //  Function: OnOpen
    //
    //    Author: $author$
    //      Date: 10/27/2011
    ///////////////////////////////////////////////////////////////////////
    virtual eError OnOpen()
#if defined(CDLIBRARYBASE_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CDLIBRARYBASE_MEMBER_FUNCS_INTERFACE) 
    {
        eError error = e_ERROR_NONE;
#if !defined(CDLIBRARYBASE_MEMBER_FUNCS_IMPLEMENT)
#else // !defined(CDLIBRARYBASE_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CDLIBRARYBASE_MEMBER_FUNCS_IMPLEMENT) 
        return error;
    }
#endif // defined(CDLIBRARYBASE_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    //  Function: OnClose
    //
    //    Author: $author$
    //      Date: 10/27/2011
    ///////////////////////////////////////////////////////////////////////
    virtual eError OnClose()
#if defined(CDLIBRARYBASE_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CDLIBRARYBASE_MEMBER_FUNCS_INTERFACE) 
    {
        eError error = e_ERROR_NONE;
#if !defined(CDLIBRARYBASE_MEMBER_FUNCS_IMPLEMENT)
#else // !defined(CDLIBRARYBASE_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CDLIBRARYBASE_MEMBER_FUNCS_IMPLEMENT) 
        return error;
    }
#endif // defined(CDLIBRARYBASE_MEMBER_FUNCS_INTERFACE) 

    ///////////////////////////////////////////////////////////////////////
    //  Function: GetAddress
    //
    //    Author: $author$
    //      Date: 10/13/2011
    ///////////////////////////////////////////////////////////////////////
    virtual void* GetAddress
     (const wchar_t* symbol) const
#if defined(CDLIBRARYBASE_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CDLIBRARYBASE_MEMBER_FUNCS_INTERFACE) 
    {
        void* address = 0;
#if !defined(CDLIBRARYBASE_MEMBER_FUNCS_IMPLEMENT)
#else // !defined(CDLIBRARYBASE_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CDLIBRARYBASE_MEMBER_FUNCS_IMPLEMENT) 
        return address;
    }
#endif // defined(CDLIBRARYBASE_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    //  Function: GetAddress
    //
    //    Author: $author$
    //      Date: 10/13/2011
    ///////////////////////////////////////////////////////////////////////
    virtual void* GetAddress
    (const char* symbol) const
#if defined(CDLIBRARYBASE_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CDLIBRARYBASE_MEMBER_FUNCS_INTERFACE) 
    {
        void* address = 0;
#if !defined(CDLIBRARYBASE_MEMBER_FUNCS_IMPLEMENT)
#else // !defined(CDLIBRARYBASE_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CDLIBRARYBASE_MEMBER_FUNCS_IMPLEMENT) 
        return address;
    }
#endif // defined(CDLIBRARYBASE_MEMBER_FUNCS_INTERFACE) 

    ///////////////////////////////////////////////////////////////////////
    //  Function: SetIsLoaded
    //
    //    Author: $author$
    //      Date: 10/13/2011
    ///////////////////////////////////////////////////////////////////////
    virtual bool SetIsLoaded
    (bool isTrue=true)
#if defined(CDLIBRARYBASE_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CDLIBRARYBASE_MEMBER_FUNCS_INTERFACE) 
    {
        bool is = false;
#if !defined(CDLIBRARYBASE_MEMBER_FUNCS_IMPLEMENT)
#else // !defined(CDLIBRARYBASE_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CDLIBRARYBASE_MEMBER_FUNCS_IMPLEMENT) 
        return is;
    }
#endif // defined(CDLIBRARYBASE_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    //  Function: GetIsLoaded
    //
    //    Author: $author$
    //      Date: 10/13/2011
    ///////////////////////////////////////////////////////////////////////
    virtual bool GetIsLoaded() const
#if defined(CDLIBRARYBASE_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CDLIBRARYBASE_MEMBER_FUNCS_INTERFACE) 
    {
        bool is = false;
#if !defined(CDLIBRARYBASE_MEMBER_FUNCS_IMPLEMENT)
#else // !defined(CDLIBRARYBASE_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CDLIBRARYBASE_MEMBER_FUNCS_IMPLEMENT) 
        return is;
    }
#endif // defined(CDLIBRARYBASE_MEMBER_FUNCS_INTERFACE) 

    ///////////////////////////////////////////////////////////////////////
    //  Function: SetIsOpen
    //
    //    Author: $author$
    //      Date: 10/13/2011
    ///////////////////////////////////////////////////////////////////////
    virtual bool SetIsOpen
    (bool isTrue=true)
#if defined(CDLIBRARYBASE_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CDLIBRARYBASE_MEMBER_FUNCS_INTERFACE) 
    {
        bool is = false;
#if !defined(CDLIBRARYBASE_MEMBER_FUNCS_IMPLEMENT)
#else // !defined(CDLIBRARYBASE_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CDLIBRARYBASE_MEMBER_FUNCS_IMPLEMENT) 
        return is;
    }
#endif // defined(CDLIBRARYBASE_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    //  Function: GetIsOpen
    //
    //    Author: $author$
    //      Date: 10/13/2011
    ///////////////////////////////////////////////////////////////////////
    virtual bool GetIsOpen() const
#if defined(CDLIBRARYBASE_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CDLIBRARYBASE_MEMBER_FUNCS_INTERFACE) 
    {
        bool is = false;
#if !defined(CDLIBRARYBASE_MEMBER_FUNCS_IMPLEMENT)
#else // !defined(CDLIBRARYBASE_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CDLIBRARYBASE_MEMBER_FUNCS_IMPLEMENT) 
        return is;
    }
#endif // defined(CDLIBRARYBASE_MEMBER_FUNCS_INTERFACE) 

#if !defined(CDLIBRARYBASE_MEMBERS_ONLY)
};


#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#else // !defined(CDLIBRARYBASE_MEMBERS_ONLY) 
#endif // !defined(CDLIBRARYBASE_MEMBERS_ONLY) 

#endif // !defined(_CDLIBRARYBASE_HPP) || defined(CDLIBRARYBASE_MEMBERS_ONLY) 
        

