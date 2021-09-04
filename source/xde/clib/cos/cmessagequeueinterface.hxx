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
 *   File: cmessagequeueinterface.hxx
 *
 * Author: $author$
 *   Date: 2/7/2008
 **********************************************************************
 */
#ifndef _CMESSAGEQUEUEINTERFACE_HXX
#define _CMESSAGEQUEUEINTERFACE_HXX

#include "ccloseinterface.hxx"

#if defined(WIN32) 
/* Windows
 */
#if !defined(CMESSAGEQUEUE_WIN32_API) 
#if !defined(CMESSAGEQUEUE_UNIX_API) 
/* use Windows API
 */
#define CMESSAGEQUEUE_WIN32_API
#endif /* !defined(CMESSAGEQUEUE_UNIX_API) */
#endif /* !defined(CMESSAGEQUEUE_WIN32_API) */
#else /* defined(WIN32) */
/* Unix
 */
#if !defined(CMESSAGEQUEUE_UNIX_API) 
#if !defined(CMESSAGEQUEUE_WIN32_API) 
/* use Unix API
 */
#define CMESSAGEQUEUE_UNIX_API
#endif /* !defined(CMESSAGEQUEUE_WIN32_API) */
#endif /* !defined(CMESSAGEQUEUE_UNIX_API) */
#endif /* defined(WIN32) */

#define ANY_QUEUEMESSAGE_TYPE 0
#define DEFAULT_QUEUEMESSAGE_TYPE 1

struct QueueMessage;

#undef CDB_CLASS
#define CDB_CLASS "cMessageQueueInterfaceT"
/**
 **********************************************************************
 *  Class: cMessageQueueInterfaceT
 *
 * Author: $author$
 *   Date: 2/7/2008
 **********************************************************************
 */
template
<class TImplements=cCloseInterface>
 
class c_INTERFACE_CLASS cMessageQueueInterfaceT
: virtual public TImplements
{
public:
    typedef TImplements cImplements;
    typedef cMessageQueueInterfaceT cDerives;
};
#undef CDB_CLASS

/**
 **********************************************************************
 *  Class: cMessageQueueInterface
 *
 * Author: $author$
 *   Date: 2/7/2008
 **********************************************************************
 */
class c_INTERFACE_CLASS cMessageQueueInterface
: virtual public cMessageQueueInterfaceT<cCloseInterface>
{
public:
    typedef cMessageQueueInterfaceT<cCloseInterface> cImplements;
    typedef cMessageQueueInterface cDerives;
    /**
     **********************************************************************
     * Function: CreateInstance
     *
     *   Author: $author$
     *     Date: 2/7/2008
     **********************************************************************
     */
    static cMessageQueueInterface* 
    CreateInstance(eError& error);
    /**
     **********************************************************************
     * Function: DestroyInstance
     *
     *   Author: $author$
     *     Date: 2/7/2008
     **********************************************************************
     */
    static eError DestroyInstance
    (cMessageQueueInterface& instance);
};

#endif /* _CMESSAGEQUEUEINTERFACE_HXX */
