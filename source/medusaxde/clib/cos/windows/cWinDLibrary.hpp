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
//   File: cWinDLibrary.hpp
//
// Author: $author$
//   Date: 10/13/2011
///////////////////////////////////////////////////////////////////////
#if !defined(_CWINDLIBRARY_HPP) || defined(CWINDLIBRARY_MEMBERS_ONLY)
#if !defined(_CWINDLIBRARY_HPP) && !defined(CWINDLIBRARY_MEMBERS_ONLY)
#define _CWINDLIBRARY_HPP
#endif // !defined(_CWINDLIBRARY_HPP) && !defined(CWINDLIBRARY_MEMBERS_ONLY) 

#if !defined(CWINDLIBRARY_MEMBERS_ONLY)
#include "cWinDLibraryInterface.hpp"
#include "cDLibraryBase.hpp"
#include "cDebug.hpp"
#include "cString.hpp"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

///////////////////////////////////////////////////////////////////////
// Typedef: cWinDLibraryExtend
//
//  Author: $author$
//    Date: 10/13/2011
///////////////////////////////////////////////////////////////////////
typedef cDLibraryBase
cWinDLibraryExtend;
///////////////////////////////////////////////////////////////////////
//  Class: cWinDLibrary
//
// Author: $author$
//   Date: 10/13/2011
///////////////////////////////////////////////////////////////////////
class c_INSTANCE_CLASS cWinDLibrary
: virtual public cWinDLibraryImplement,
  public cWinDLibraryExtend
{
public:
    typedef cWinDLibraryImplement cImplements;
    typedef cWinDLibraryExtend cExtends;

    HMODULE m_hModule;
    bool m_isLoaded;

    ///////////////////////////////////////////////////////////////////////
    //  Constructor: cWinDLibrary
    //
    //       Author: $author$
    //         Date: 10/13/2011
    ///////////////////////////////////////////////////////////////////////
    cWinDLibrary
    (HMODULE hModule=0,
     bool isLoaded=false)
    : m_hModule(hModule),
      m_isLoaded(isLoaded)
    {
    }
    ///////////////////////////////////////////////////////////////////////
    //  Destructor: ~cWinDLibrary
    //
    //      Author: $author$
    //        Date: 10/13/2011
    ///////////////////////////////////////////////////////////////////////
    virtual ~cWinDLibrary()
    {
    }
#else // !defined(CWINDLIBRARY_MEMBERS_ONLY) 
#endif // !defined(CWINDLIBRARY_MEMBERS_ONLY) 

    ///////////////////////////////////////////////////////////////////////
    //  Function: Load
    //
    //    Author: $author$
    //      Date: 10/13/2011
    ///////////////////////////////////////////////////////////////////////
    virtual eError Load
    (const wchar_t* fileName,
     bool onlyUnloaded=false)
#if defined(CWINDLIBRARY_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CWINDLIBRARY_MEMBER_FUNCS_INTERFACE) 
    {
        eError error = e_ERROR_NOT_IMPLEMENTED;
#if !defined(CWINDLIBRARY_MEMBER_FUNCS_IMPLEMENT)
        cTString tFileName;
        const tchar_t* lpFileName;
        HMODULE hModule;

        if (0 <= (tFileName.Assign_wchar(fileName)))
        if ((lpFileName = tFileName.HasChars()))
            hModule = LoadAttached(error, lpFileName, onlyUnloaded);

#else // !defined(CWINDLIBRARY_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CWINDLIBRARY_MEMBER_FUNCS_IMPLEMENT) 
        return error;
    }
#endif // defined(CWINDLIBRARY_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    //  Function: Load
    //
    //    Author: $author$
    //      Date: 10/13/2011
    ///////////////////////////////////////////////////////////////////////
    virtual eError Load
    (const char* fileName,
     bool onlyUnloaded=false)
#if defined(CWINDLIBRARY_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CWINDLIBRARY_MEMBER_FUNCS_INTERFACE) 
    {
        eError error = e_ERROR_NOT_IMPLEMENTED;
#if !defined(CWINDLIBRARY_MEMBER_FUNCS_IMPLEMENT)
        cTString tFileName;
        const tchar_t* lpFileName;
        HMODULE hModule;

        if (0 <= (tFileName.Assign_char(fileName)))
        if ((lpFileName = tFileName.HasChars()))
            hModule = LoadAttached(error, lpFileName, onlyUnloaded);

#else // !defined(CWINDLIBRARY_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CWINDLIBRARY_MEMBER_FUNCS_IMPLEMENT) 
        return error;
    }
#endif // defined(CWINDLIBRARY_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    //  Function: Unload
    //
    //    Author: $author$
    //      Date: 10/13/2011
    ///////////////////////////////////////////////////////////////////////
    virtual eError Unload
    (bool onlyLoaded=false)
#if defined(CWINDLIBRARY_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CWINDLIBRARY_MEMBER_FUNCS_INTERFACE) 
    {
        eError error = e_ERROR_NOT_IMPLEMENTED;
#if !defined(CWINDLIBRARY_MEMBER_FUNCS_IMPLEMENT)
        HMODULE hModule;

        if ((hModule = Attached()))
            OnUnload();

        if ((hModule = Detach()))
            error = UnloadDetached(hModule);
        else
        if ((onlyLoaded))
            error = e_ERROR_NOT_ATTACHED;
        else
        error = e_ERROR_NONE;

#else // !defined(CWINDLIBRARY_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CWINDLIBRARY_MEMBER_FUNCS_IMPLEMENT) 
        return error;
    }
#endif // defined(CWINDLIBRARY_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    //  Function: Unloaded
    //
    //    Author: $author$
    //      Date: 10/13/2011
    ///////////////////////////////////////////////////////////////////////
    virtual eError Unloaded
    (bool onlyUnloaded=false)
#if defined(CWINDLIBRARY_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CWINDLIBRARY_MEMBER_FUNCS_INTERFACE) 
    {
        eError error = e_ERROR_NOT_IMPLEMENTED;
#if !defined(CWINDLIBRARY_MEMBER_FUNCS_IMPLEMENT)
        bool isLoaded;

        if ((isLoaded = GetIsLoaded()))
        if ((onlyUnloaded))
            return error = e_ERROR_FAILED;
        else
        if ((error = Unload(isLoaded)))
            return error;

        if ((Attached()))
        if ((onlyUnloaded))
            return error = e_ERROR_FAILED;
        else
        Detach();

        error = e_ERROR_NONE;
#else // !defined(CWINDLIBRARY_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CWINDLIBRARY_MEMBER_FUNCS_IMPLEMENT) 
        return error;
    }
#endif // defined(CWINDLIBRARY_MEMBER_FUNCS_INTERFACE) 

    ///////////////////////////////////////////////////////////////////////
    //  Function: LoadAttached
    //
    //    Author: $author$
    //      Date: 10/13/2011
    ///////////////////////////////////////////////////////////////////////
    virtual HMODULE LoadAttached
    (eError& error,
     const tchar_t* lpFileName,
     bool onlyUnloaded=false)
#if defined(CWINDLIBRARY_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CWINDLIBRARY_MEMBER_FUNCS_INTERFACE) 
    {
        HMODULE hModule = 0;
#if !defined(CWINDLIBRARY_MEMBER_FUNCS_IMPLEMENT)
        if ((error = Unloaded(onlyUnloaded)))
            return 0;
        error = e_ERROR_FAILED;
        if ((hModule = LoadDetached(lpFileName)))
        if (hModule != (Attach(hModule, true)))
        {
            UnloadDetached(hModule);
            hModule = 0;
        }
        else
        if ((error = OnLoad()))
        {
            Detach();
            UnloadDetached(hModule);
            hModule = 0;
        }
        else
        error = e_ERROR_NONE;
#else // !defined(CWINDLIBRARY_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CWINDLIBRARY_MEMBER_FUNCS_IMPLEMENT) 
        return hModule;
    }
#endif // defined(CWINDLIBRARY_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    //  Function: LoadDetached
    //
    //    Author: $author$
    //      Date: 10/13/2011
    ///////////////////////////////////////////////////////////////////////
    virtual HMODULE LoadDetached
    (const tchar_t* lpFileName) const
#if defined(CWINDLIBRARY_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CWINDLIBRARY_MEMBER_FUNCS_INTERFACE) 
    {
        HMODULE hModule = 0;
#if !defined(CWINDLIBRARY_MEMBER_FUNCS_IMPLEMENT)
        if (!(hModule = LoadLibrary(lpFileName)))
            c_DB_ERROR("() failed on LoadLibrary(" << lpFileName << ")");
#else // !defined(CWINDLIBRARY_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CWINDLIBRARY_MEMBER_FUNCS_IMPLEMENT) 
        return hModule;
    }
#endif // defined(CWINDLIBRARY_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    //  Function: UnloadDetached
    //
    //    Author: $author$
    //      Date: 10/13/2011
    ///////////////////////////////////////////////////////////////////////
    virtual eError UnloadDetached
    (HMODULE hModule) const
#if defined(CWINDLIBRARY_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CWINDLIBRARY_MEMBER_FUNCS_INTERFACE) 
    {
        eError error = e_ERROR_NOT_IMPLEMENTED;
#if !defined(CWINDLIBRARY_MEMBER_FUNCS_IMPLEMENT)
        if (!(FreeLibrary(hModule)))
            c_DB_ERROR("() failed on FreeLibrary()");
#else // !defined(CWINDLIBRARY_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CWINDLIBRARY_MEMBER_FUNCS_IMPLEMENT) 
        return error;
    }
#endif // defined(CWINDLIBRARY_MEMBER_FUNCS_INTERFACE) 

    ///////////////////////////////////////////////////////////////////////
    //  Function: OnLoad
    //
    //    Author: $author$
    //      Date: 10/27/2011
    ///////////////////////////////////////////////////////////////////////
    virtual eError OnLoad()
#if defined(CWINDLIBRARY_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CWINDLIBRARY_MEMBER_FUNCS_INTERFACE) 
    {
        eError error = e_ERROR_NONE;
#if !defined(CWINDLIBRARY_MEMBER_FUNCS_IMPLEMENT)
        error = OnOpen();
#else // !defined(CWINDLIBRARY_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CWINDLIBRARY_MEMBER_FUNCS_IMPLEMENT) 
        return error;
    }
#endif // defined(CWINDLIBRARY_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    //  Function: OnUnload
    //
    //    Author: $author$
    //      Date: 10/27/2011
    ///////////////////////////////////////////////////////////////////////
    virtual eError OnUnload()
#if defined(CWINDLIBRARY_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CWINDLIBRARY_MEMBER_FUNCS_INTERFACE) 
    {
        eError error = e_ERROR_NONE;
#if !defined(CWINDLIBRARY_MEMBER_FUNCS_IMPLEMENT)
        error = OnClose();
#else // !defined(CWINDLIBRARY_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CWINDLIBRARY_MEMBER_FUNCS_IMPLEMENT) 
        return error;
    }
#endif // defined(CWINDLIBRARY_MEMBER_FUNCS_INTERFACE) 

    ///////////////////////////////////////////////////////////////////////
    //  Function: GetAddress
    //
    //    Author: $author$
    //      Date: 10/13/2011
    ///////////////////////////////////////////////////////////////////////
    virtual void* GetAddress
    (const wchar_t* symbol) const
#if defined(CWINDLIBRARY_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CWINDLIBRARY_MEMBER_FUNCS_INTERFACE) 
    {
        void* address = 0;
#if !defined(CWINDLIBRARY_MEMBER_FUNCS_IMPLEMENT)
        cString procName;
        const char* lpProcName;
        HMODULE hModule;

        if ((hModule = Attached()))
        if (0 <= (procName.Assign_wchar(symbol)))
        if ((lpProcName = procName.HasChars()))
            address = GetAddress(hModule, lpProcName);
#else // !defined(CWINDLIBRARY_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CWINDLIBRARY_MEMBER_FUNCS_IMPLEMENT) 
        return address;
    }
#endif // defined(CWINDLIBRARY_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    //  Function: GetAddress
    //
    //    Author: $author$
    //      Date: 10/13/2011
    ///////////////////////////////////////////////////////////////////////
    virtual void* GetAddress
    (const char* symbol) const
#if defined(CWINDLIBRARY_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CWINDLIBRARY_MEMBER_FUNCS_INTERFACE) 
    {
        void* address = 0;
#if !defined(CWINDLIBRARY_MEMBER_FUNCS_IMPLEMENT)
        const char* lpProcName;
        HMODULE hModule;

        if ((hModule = Attached()))
        if ((lpProcName = symbol))
            address = GetAddress(hModule, lpProcName);
#else // !defined(CWINDLIBRARY_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CWINDLIBRARY_MEMBER_FUNCS_IMPLEMENT) 
        return address;
    }
#endif // defined(CWINDLIBRARY_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    //  Function: GetProcAddress
    //
    //    Author: $author$
    //      Date: 10/13/2011
    ///////////////////////////////////////////////////////////////////////
    virtual FARPROC GetAddress
    (HMODULE hModule, LPCSTR lpProcName) const
#if defined(CWINDLIBRARY_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CWINDLIBRARY_MEMBER_FUNCS_INTERFACE) 
    {
        FARPROC address = 0;
#if !defined(CWINDLIBRARY_MEMBER_FUNCS_IMPLEMENT)
        if (!(address = GetProcAddress(hModule, lpProcName)))
            c_DB_ERROR("() failed on GetProcAddress(hModule, " << lpProcName << ")");
#else // !defined(CWINDLIBRARY_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CWINDLIBRARY_MEMBER_FUNCS_IMPLEMENT) 
        return address;
    }
#endif // defined(CWINDLIBRARY_MEMBER_FUNCS_INTERFACE) 

    ///////////////////////////////////////////////////////////////////////
    //  Function: Attach
    //
    //    Author: $author$
    //      Date: 10/13/2011
    ///////////////////////////////////////////////////////////////////////
    virtual HMODULE Attach
    (HMODULE hModuleTo,
     bool isLoaded=false)
#if defined(CWINDLIBRARY_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CWINDLIBRARY_MEMBER_FUNCS_INTERFACE) 
    {
        HMODULE hModule = 0;
#if !defined(CWINDLIBRARY_MEMBER_FUNCS_IMPLEMENT)
        hModule = (m_hModule = hModuleTo);
        SetIsLoaded(isLoaded);
#else // !defined(CWINDLIBRARY_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CWINDLIBRARY_MEMBER_FUNCS_IMPLEMENT) 
        return hModule;
    }
#endif // defined(CWINDLIBRARY_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    //  Function: Detach
    //
    //    Author: $author$
    //      Date: 10/13/2011
    ///////////////////////////////////////////////////////////////////////
    virtual HMODULE Detach()
#if defined(CWINDLIBRARY_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CWINDLIBRARY_MEMBER_FUNCS_INTERFACE) 
    {
        HMODULE hModule = 0;
#if !defined(CWINDLIBRARY_MEMBER_FUNCS_IMPLEMENT)
        hModule = (m_hModule);
        m_hModule = 0;
        SetIsLoaded(false);
#else // !defined(CWINDLIBRARY_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CWINDLIBRARY_MEMBER_FUNCS_IMPLEMENT) 
        return hModule;
    }
#endif // defined(CWINDLIBRARY_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    //  Function: Attached
    //
    //    Author: $author$
    //      Date: 10/13/2011
    ///////////////////////////////////////////////////////////////////////
    virtual HMODULE Attached() const
#if defined(CWINDLIBRARY_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CWINDLIBRARY_MEMBER_FUNCS_INTERFACE) 
    {
        HMODULE hModule = 0;
#if !defined(CWINDLIBRARY_MEMBER_FUNCS_IMPLEMENT)
        hModule = (m_hModule);
#else // !defined(CWINDLIBRARY_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CWINDLIBRARY_MEMBER_FUNCS_IMPLEMENT) 
        return hModule;
    }
#endif // defined(CWINDLIBRARY_MEMBER_FUNCS_INTERFACE) 

    ///////////////////////////////////////////////////////////////////////
    //  Function: SetIsLoaded
    //
    //    Author: $author$
    //      Date: 10/13/2011
    ///////////////////////////////////////////////////////////////////////
    virtual bool SetIsLoaded
    (bool isTrue=true)
#if defined(CWINDLIBRARY_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CWINDLIBRARY_MEMBER_FUNCS_INTERFACE) 
    {
        bool is = false;
#if !defined(CWINDLIBRARY_MEMBER_FUNCS_IMPLEMENT)
#else // !defined(CWINDLIBRARY_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CWINDLIBRARY_MEMBER_FUNCS_IMPLEMENT) 
        return is;
    }
#endif // defined(CWINDLIBRARY_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    //  Function: GetIsLoaded
    //
    //    Author: $author$
    //      Date: 10/13/2011
    ///////////////////////////////////////////////////////////////////////
    virtual bool GetIsLoaded() const
#if defined(CWINDLIBRARY_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CWINDLIBRARY_MEMBER_FUNCS_INTERFACE) 
    {
        bool is = false;
#if !defined(CWINDLIBRARY_MEMBER_FUNCS_IMPLEMENT)
#else // !defined(CWINDLIBRARY_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CWINDLIBRARY_MEMBER_FUNCS_IMPLEMENT) 
        return is;
    }
#endif // defined(CWINDLIBRARY_MEMBER_FUNCS_INTERFACE) 

#if !defined(CWINDLIBRARY_MEMBERS_ONLY)
    ///////////////////////////////////////////////////////////////////////
    //  Function: SetIsOpen
    //
    //    Author: $author$
    //      Date: 10/13/2011
    ///////////////////////////////////////////////////////////////////////
    virtual bool SetIsOpen
    (bool isTrue=true)
    {
        bool is = SetIsLoaded(isTrue);
        return is;
    }
    ///////////////////////////////////////////////////////////////////////
    //  Function: GetIsOpen
    //
    //    Author: $author$
    //      Date: 10/13/2011
    ///////////////////////////////////////////////////////////////////////
    virtual bool GetIsOpen() const
    {
        bool is = GetIsLoaded();
        return is;
    }
};


#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#else // !defined(CWINDLIBRARY_MEMBERS_ONLY) 
#endif // !defined(CWINDLIBRARY_MEMBERS_ONLY) 

#endif // !defined(_CWINDLIBRARY_HPP) || defined(CWINDLIBRARY_MEMBERS_ONLY) 
        

