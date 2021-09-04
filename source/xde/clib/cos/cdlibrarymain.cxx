/**
 **********************************************************************
 * Copyright (c) 1988-2008 $organization$
 *
 * This software is provided by the author and contributors ``as is'' 
 * and any express or implied warranties, including, but not limited to, 
 * the implied warranties of merchantability and fitness for a particular 
 * purpose are disclaimed. In no event shall the author or contributors 
 * be liable for any direct, indirect, incidental, special, exemplary, 
 * or consequential damages (including, but not limited to, procurement 
 * of substitute goods or services; loss of use, data, or profits; or 
 * business interruption) however caused and on any theory of liability, 
 * whether in contract, strict liability, or tort (including negligence 
 * or otherwise) arising in any way out of the use of this software, 
 * even if advised of the possibility of such damage.
 *
 *   File: cdlibrarymain.cxx
 *
 * Author: $author$
 *   Date: 5/24/2008
 **********************************************************************
 */

#include "cdlibrarymain.hxx"
#include "cdebug.hxx"

#if defined(WIN32) 
/* Windows
 */
/**
 **********************************************************************
 * Function: DllMain
 *
 *   Author: $author$
 *     Date: 5/24/2008
 **********************************************************************
 */
BOOL WINAPI DllMain
(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpvReserved)
{
	DF(DllMain)
    eError error;
    cDLibraryMainInterface* dlibraryMain;

    if ((dlibraryMain = cDLibraryMainInterface::GetTheInstance(error)))
    switch(fdwReason)
    {
    case DLL_PROCESS_ATTACH:
        /*
        ** The DLL is being loaded into the virtual address 
        ** space of the current process as a result of the 
        ** process starting up or as a result of a call to 
        ** LoadLibrary. DLLs can use this opportunity to 
        ** initialize any instance data or to use the TlsAlloc 
        ** function to allocate a thread local storage (TLS) 
        ** index.
        */
        if ((error = dlibraryMain->Initialize()))
            DBE("() failed on dlibraryMain->Initialize()\n");
        break;

    case DLL_THREAD_ATTACH:
        /*
        ** The current process is creating a new thread. 
        ** When this occurs, the system calls the entry-point 
        ** function of all DLLs currently attached to the process. 
        ** The call is made in the context of the new thread. 
        ** DLLs can use this opportunity to initialize a TLS slot 
        ** for the thread. 
        */
        break;

    case DLL_THREAD_DETACH:
        /*
        ** A thread is exiting cleanly. If the DLL has stored 
        ** a pointer to allocated memory in a TLS slot, it 
        ** should use this opportunity to free the memory. 
        ** The system calls the entry-point function of all 
        ** currently loaded DLLs with this value. The call 
        ** is made in the context of the exiting thread.
        */
        break;

    case DLL_PROCESS_DETACH:
        /*
        ** The DLL is being unloaded from the virtual address 
        ** space of the calling process as a result of 
        ** unsuccessfully loading the DLL, termination of the 
        ** process, or a call to FreeLibrary. The DLL can use 
        ** this opportunity to call the TlsFree function to 
        ** free any TLS indices allocated by using TlsAlloc 
        ** and to free any thread local data. 
        */
        if ((error = dlibraryMain->Finalize()))
            DBE("() failed on dlibraryMain->Finalize()\n");
        break;
    }
    return TRUE;
}
#else /* defined(WIN32) */
/* Unix
 */
/**
 **********************************************************************
 * Function: _init
 *
 *   Author: $author$
 *     Date: 5/24/2008
 **********************************************************************
 */
void _init() 
{
	DF(_init)
    eError error;
    cDLibraryMainInterface* dlibraryMain;

    if ((dlibraryMain = cDLibraryMainInterface::GetTheInstance(error)))
    if ((error = dlibraryMain->Initialize()))
        DBE("() failed on dlibraryMain->Initialize()\n");
}
/**
 **********************************************************************
 * Function: _fini
 *
 *   Author: $author$
 *     Date: 5/24/2008
 **********************************************************************
 */
void _fini() 
{
	DF(_fini)
    eError error;
    cDLibraryMainInterface* dlibraryMain;

    if ((dlibraryMain = cDLibraryMainInterface::GetTheInstance(error)))
    if ((error = dlibraryMain->Finalize()))
        DBE("() failed on dlibraryMain->Finalize()\n");
}
#endif /* defined(WIN32) */
