///////////////////////////////////////////////////////////////////////
//   File: cevdllmain.cpp
//
// Author: $author$
//   Date: 4/12/2007
//
//    $Id$
///////////////////////////////////////////////////////////////////////

#include "cevdllmain.hpp"
#include "evdebug.h"

#if defined(WIN32) 
// Windows
///////////////////////////////////////////////////////////////////////
// Function: DllMain
//
//   Author: $author$
//     Date: 4/12/2007
///////////////////////////////////////////////////////////////////////
BOOL WINAPI DllMain
(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpvReserved)
{
    EvError error;
    CEvDllMain* dllMain;

    if ((dllMain = CEvDllMain::GetDllMain()))
    switch(fdwReason)
    {
    case DLL_PROCESS_ATTACH:
        // The DLL is being loaded into the virtual address 
        // space of the current process as a result of the 
        // process starting up or as a result of a call to 
        // LoadLibrary. DLLs can use this opportunity to 
        // initialize any instance data or to use the TlsAlloc 
        // function to allocate a thread local storage (TLS) 
        // index.
        if ((error = dllMain->Initialize()))
            DBE("() failed on dllMain->Initialize()\n");
        break;

    case DLL_THREAD_ATTACH:
        // The current process is creating a new thread. 
        // When this occurs, the system calls the entry-point 
        // function of all DLLs currently attached to the process. 
        // The call is made in the context of the new thread. 
        // DLLs can use this opportunity to initialize a TLS slot 
        // for the thread. 
        break;

    case DLL_THREAD_DETACH:
        // A thread is exiting cleanly. If the DLL has stored 
        // a pointer to allocated memory in a TLS slot, it 
        // should use this opportunity to free the memory. 
        // The system calls the entry-point function of all 
        // currently loaded DLLs with this value. The call 
        // is made in the context of the exiting thread.
        break;

    case DLL_PROCESS_DETACH:
        // The DLL is being unloaded from the virtual address 
        // space of the calling process as a result of 
        // unsuccessfully loading the DLL, termination of the 
        // process, or a call to FreeLibrary. The DLL can use 
        // this opportunity to call the TlsFree function to 
        // free any TLS indices allocated by using TlsAlloc 
        // and to free any thread local data. 
        if ((error = dllMain->Finalize()))
            DBE("() failed on dllMain->Finalize()\n");
        break;
    }
    return TRUE;
}
#else // defined(WIN32) 
// Unix
///////////////////////////////////////////////////////////////////////
// Function: _init
//
//   Author: $author$
//     Date: 4/12/2007
///////////////////////////////////////////////////////////////////////
void _init() 
{
    EvError error;
    CEvDllMain* dllMain;

    if ((dllMain = CEvDllMain::GetDllMain()))
    if ((error = dllMain->Initialize()))
        DBE("() failed on dllMain->Initialize()\n");
}
///////////////////////////////////////////////////////////////////////
// Function: _fini
//
//   Author: $author$
//     Date: 4/12/2007
///////////////////////////////////////////////////////////////////////
void _fini() 
{
    EvError error;
    CEvDllMain* dllMain;

    if ((dllMain = CEvDllMain::GetDllMain()))
    if ((error = dllMain->Finalize()))
        DBE("() failed on dllMain->Finalize()\n");
}
#endif // defined(WIN32)

///////////////////////////////////////////////////////////////////////
//  Class: CEvDllMain
//
// Author: $author$
//   Date: 4/12/2007
///////////////////////////////////////////////////////////////////////
CEvDllMain* CEvDllMain::m_dllMain = 0;


