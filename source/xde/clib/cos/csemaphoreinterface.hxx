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
 *   File: csemaphoreinterface.hxx
 *
 * Author: $author$
 *   Date: 2/5/2008
 **********************************************************************
 */
#ifndef _CSEMAPHOREINTERFACE_HXX
#define _CSEMAPHOREINTERFACE_HXX

#include "ccloseinterface.hxx"

#if defined(WIN32) 
/* Windows
 */
#if !defined(CSEMAPHORE_WIN32_API) 
#if !defined(CSEMAPHORE_UNIX_API) 
/* use Windows API
 */
#define CSEMAPHORE_WIN32_API
#endif /* !defined(CSEMAPHORE_UNIX_API) */
#endif /* !defined(CSEMAPHORE_WIN32_API) */
#else /* defined(WIN32) */
/* Unix
 */
#if !defined(CSEMAPHORE_UNIX_API) 
#if !defined(CSEMAPHORE_WIN32_API) 
/* use Unix API
 */
#define CSEMAPHORE_UNIX_API
#endif /* !defined(CSEMAPHORE_WIN32_API) */
#endif /* !defined(CSEMAPHORE_UNIX_API) */
#endif /* defined(WIN32) */

#undef CDB_CLASS
#define CDB_CLASS "cSemaphoreInterfaceT"
/**
 **********************************************************************
 *  Class: cSemaphoreInterfaceT
 *
 * Author: $author$
 *   Date: 2/5/2008
 **********************************************************************
 */
template
<class TImplements=cCloseInterface>
 
class c_INTERFACE_CLASS cSemaphoreInterfaceT
: virtual public TImplements
{
public:
    typedef TImplements cImplements;
    typedef cSemaphoreInterfaceT cDerives;
};
#undef CDB_CLASS

/**
 **********************************************************************
 *  Class: cSemaphoreInterface
 *
 * Author: $author$
 *   Date: 2/5/2008
 **********************************************************************
 */
class c_INTERFACE_CLASS cSemaphoreInterface
: virtual public cSemaphoreInterfaceT<cCloseInterface>
{
public:
    typedef cSemaphoreInterfaceT<cCloseInterface> cImplements;
    typedef cSemaphoreInterface cDerives;
    /**
     **********************************************************************
     * Function: CreateInstance
     *
     *   Author: $author$
     *     Date: 2/5/2008
     **********************************************************************
     */
    static cSemaphoreInterface* 
    CreateInstance(eError& error);
    /**
     **********************************************************************
     * Function: DestroyInstance
     *
     *   Author: $author$
     *     Date: 2/5/2008
     **********************************************************************
     */
    static eError DestroyInstance
    (cSemaphoreInterface& instance);
    /**
     **********************************************************************
     * Function: DeleteInstance
     *
     *   Author: $author$
     *     Date: 2/5/2008
     **********************************************************************
     */
    virtual eError DeleteInstance() = 0;
};
#endif /* _CSEMAPHOREINTERFACE_HXX */
