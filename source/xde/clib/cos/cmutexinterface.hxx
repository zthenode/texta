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
 *   File: cmutexinterface.hxx
 *
 * Author: $author$
 *   Date: 2/3/2008
 **********************************************************************
 */
#ifndef _CMUTEXINTERFACE_HXX
#define _CMUTEXINTERFACE_HXX

#include "ccloseinterface.hxx"

#if defined(WIN32) 
/* Windows
 */
#if !defined(CMUTEX_WIN32_API) 
#if !defined(CMUTEX_UNIX_API) 
/* use Windows API
 */
#define CMUTEX_WIN32_API
#endif /* !defined(CMUTEX_UNIX_API) */
#endif /* !defined(CMUTEX_WIN32_API) */
#else /* defined(WIN32) */
/* Unix
 */
#if !defined(CMUTEX_UNIX_API) 
#if !defined(CMUTEX_WIN32_API) 
/* use Unix API
 */
#define CMUTEX_UNIX_API
#endif /* !defined(CMUTEX_WIN32_API) */
#endif /* !defined(CMUTEX_UNIX_API) */
#endif /* defined(WIN32) */

#undef CDB_CLASS
#define CDB_CLASS "cMutexInterfaceT"
/**
 **********************************************************************
 *  Class: cMutexInterfaceT
 *
 * Author: $author$
 *   Date: 2/3/2008
 **********************************************************************
 */
template
<class TImplements=cCloseInterface>
 
class c_INTERFACE_CLASS cMutexInterfaceT
: virtual public TImplements
{
public:
    typedef TImplements cImplements;
    typedef cMutexInterfaceT cDerives;
    /**
     **********************************************************************
     * Function: Create
     *
     *   Author: $author$
     *     Date: 2/3/2008
     **********************************************************************
     */
    virtual eError Create
    (const char* named=0,
     bool isAcquired=false,
     bool onlyClosed=true) = 0;
    /**
     **********************************************************************
     * Function: Open
     *
     *   Author: $author$
     *     Date: 2/3/2008
     **********************************************************************
     */
    virtual eError Open
    (const char* named,
     bool onlyClosed=true) = 0;
    /**
     **********************************************************************
     * Function: Acquire
     *
     *   Author: $author$
     *     Date: 2/3/2008
     **********************************************************************
     */
    virtual eError Acquire
    (LONG waitMilliSeconds=INFINITE) = 0;
    /**
     **********************************************************************
     * Function: Release
     *
     *   Author: $author$
     *     Date: 2/3/2008
     **********************************************************************
     */
    virtual eError Release
    (bool onlyAcquired=false) = 0;
};
#undef CDB_CLASS

/**
 **********************************************************************
 *  Class: cMutexInterface
 *
 * Author: $author$
 *   Date: 2/3/2008
 **********************************************************************
 */
class c_INTERFACE_CLASS cMutexInterface
: public cMutexInterfaceT<cCloseInterface>
{
public:
    typedef cMutexInterfaceT<cCloseInterface> cExtends;
    typedef cMutexInterface cDerives;
    /**
     **********************************************************************
     * Function: CreateInstance
     *
     *   Author: $author$
     *     Date: 2/3/2008
     **********************************************************************
     */
    static cMutexInterface* 
    CreateInstance(eError& error);
    /**
     **********************************************************************
     * Function: DestroyInstance
     *
     *   Author: $author$
     *     Date: 2/3/2008
     **********************************************************************
     */
    static eError DestroyInstance
    (cMutexInterface& instance);
};
#endif /* _CMUTEXINTERFACE_HXX */
