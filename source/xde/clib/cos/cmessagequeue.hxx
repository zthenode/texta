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
 *   File: cmessagequeue.hxx
 *
 * Author: $author$
 *   Date: 2/7/2008
 **********************************************************************
 */
#ifndef _CMESSAGEQUEUE_HXX
#define _CMESSAGEQUEUE_HXX

#include "cplatform_msg.h"
#include "cmessagequeueinterface.hxx"
#include "copened.hxx"
#include "cdebug.h"

/**
 **********************************************************************
 * Struct: QueueMessage
 *
 * Author: $author$
 *   Date: 2/9/2008
 **********************************************************************
 */
struct QueueMessage
{
    typedef QueueMessage cDerives;

    MSGTYPE_T m_type;

    /**
     **********************************************************************
     * Constructor: QueueMessage
     *
     *      Author: $author$
     *        Date: 2/9/2008
     **********************************************************************
     */
    QueueMessage
    (MSGTYPE_T type=DEFAULT_QUEUEMESSAGE_TYPE) 
    : m_type(type)
    {
    }
};

#undef CDB_CLASS
#define CDB_CLASS "cMessageQueueT"
/**
 **********************************************************************
 *  Class: cMessageQueueT
 *
 * Author: $author$
 *   Date: 2/7/2008
 **********************************************************************
 */
template
<class TExtends=cOpened,
 class TImplements=cMessageQueueInterface>
 
class cMessageQueueT
: virtual public TImplements,
  public TExtends
{
public:
    typedef TImplements cImplements;
    typedef TExtends cExtends;
    typedef cMessageQueueT cDerives;

#if defined(CMESSAGEQUEUE_WIN32_API) 
/* use Windows API
 */
#else /* defined(CMESSAGEQUEUE_WIN32_API) */
/* use Unix API
 */
    int m_msgqid;
#endif /* defined(CMESSAGEQUEUE_WIN32_API) */

    /**
     **********************************************************************
     * Constructor: cMessageQueueT
     *
     *      Author: $author$
     *        Date: 2/7/2008
     **********************************************************************
     */
    cMessageQueueT() 
#if defined(CMESSAGEQUEUE_WIN32_API) 
/* use Windows API
 */
#else /* defined(CMESSAGEQUEUE_WIN32_API) */
/* use Unix API
 */
    : m_msgqid(INVALID_MSQID)
#endif /* defined(CMESSAGEQUEUE_WIN32_API) */

    {
    }
    /**
     **********************************************************************
     * Destructor: cMessageQueueT
     *
     *     Author: $author$
     *       Date: 2/7/2008
     **********************************************************************
     */
    virtual ~cMessageQueueT()
    {
        bool isOpen;
        eError error;
        if ((isOpen = (0 < CTHIS GetIsOpen())))
        if ((error = Close(isOpen)))
            throw(error);
    }
    /**
     **********************************************************************
     * Function: Create
     *
     *   Author: $author$
     *     Date: 2/7/2008
     **********************************************************************
     */
    virtual eError Create
    (KEY_T key=IPC_PRIVATE, 
     bool onlyPublic=false,
     bool onlyClosed=false) 
    {
        eError error = e_ERROR_NOT_IMPLEMENTED;
        eError error2;

        if ((error2 = CTHIS Closed(onlyClosed)))
            return error;

#if defined(CMESSAGEQUEUE_WIN32_API) 
/* use Windows API
 */
#else /* defined(CMESSAGEQUEUE_WIN32_API) */
/* use Unix API
 */
        int msgflg = IPC_CREAT | S_IRUSR | S_IWUSR;
        if (0 <= (m_msgqid = msgget(key, msgflg)))
        {
            CDBT("() msgqid = 0x%x\n", m_msgqid);
            CTHIS SetIsOpen(true);
            return error = e_ERROR_NONE;
        }
        CDBE("() failed on msgget()\n");
#endif /* defined(CMESSAGEQUEUE_WIN32_API) */
        return error;
    }
    /**
     **********************************************************************
     * Function: Open
     *
     *   Author: $author$
     *     Date: 2/7/2008
     **********************************************************************
     */
    virtual eError Open
    (KEY_T key, bool onlyClosed=false) 
    {
        eError error = e_ERROR_NOT_IMPLEMENTED;
        eError error2;

        if ((error2 = CTHIS Closed(onlyClosed)))
            return error;

#if defined(CMESSAGEQUEUE_WIN32_API) 
/* use Windows API
 */
#else /* defined(CMESSAGEQUEUE_WIN32_API) */
/* use Unix API
 */
        int msgflg = 0;
        if (0 <= (m_msgqid = msgget(key, msgflg)))
        {
            CDBT("() msgqid = 0x%x\n", m_msgqid);
            CTHIS SetIsOpen(true);
            return error = e_ERROR_NONE;
        }
        CDBE("() failed on msgget()\n");
#endif /* defined(CMESSAGEQUEUE_WIN32_API) */
        return error;
    }
    /**
     **********************************************************************
     * Function: Close
     *
     *   Author: $author$
     *     Date: 2/7/2008
     **********************************************************************
     */
    virtual eError Close
    (bool onlyOpened=false) 
    {
        eError error = e_ERROR_NOT_IMPLEMENTED;
        int isOpen;

        if (0 > (isOpen = CTHIS Opened(onlyOpened)))
            return -isOpen;

        if (!isOpen)
            return e_ERROR_NONE;

#if defined(CMESSAGEQUEUE_WIN32_API) 
/* use Windows API
 */
#else /* defined(CMESSAGEQUEUE_WIN32_API) */
/* use Unix API
 */
        int err;
        if ((err = msgclose(m_msgqid)))
        {
            CDBE("() failed on close()\n");
            error = e_ERROR_FAILED;
        }
        else error = e_ERROR_NONE;

        CTHIS SetIsOpen(false);
#endif /* defined(CMESSAGEQUEUE_WIN32_API) */
        return error;
    }
    /**
     **********************************************************************
     * Function: Send
     *
     *   Author: $author$
     *     Date: 2/9/2008
     **********************************************************************
     */
    virtual eError Send
    (const QueueMessage& msg, TSIZE size,
     LONG waitMilliseconds=INFINITE) 
    {
        eError error = e_ERROR_NOT_IMPLEMENTED;
        int isOpen;

        if (0 > (isOpen = CTHIS Opened(true)))
            return -isOpen;

#if defined(CMESSAGEQUEUE_WIN32_API) 
/* use Windows API
 */
#else /* defined(CMESSAGEQUEUE_WIN32_API) */
/* use Unix API
 */
        int msgflg = ((!waitMilliseconds)?IPC_NOWAIT:0);
        int err;
        CDBT("() in...\n");
        if ((err = msgsnd(m_msgqid, &msg, (size_t)(size), msgflg)))
        {
            CDBE("() failed on msgsnd()\n");
            error = e_ERROR_FAILED;
        }
        else error = e_ERROR_NONE;
#endif /* defined(CMESSAGEQUEUE_WIN32_API) */
        return error;
    }
    /**
     **********************************************************************
     * Function: Recv
     *
     *   Author: $author$
     *     Date: 2/9/2008
     **********************************************************************
     */
    virtual eError Recv
    (QueueMessage& msg, TSIZE size,
     MSGTYPE_T type=ANY_QUEUEMESSAGE_TYPE,
     LONG waitMilliseconds=INFINITE)
    {
        eError error = e_ERROR_NOT_IMPLEMENTED;
        int isOpen;

        if (0 > (isOpen = CTHIS Opened(true)))
            return -isOpen;

#if defined(CMESSAGEQUEUE_WIN32_API) 
/* use Windows API
 */
#else /* defined(CMESSAGEQUEUE_WIN32_API) */
/* use Unix API
 */
        int msgflg = ((!waitMilliseconds)?IPC_NOWAIT:0);
        ssize_t count;
        CDBT("() in...\n");
        if (0 > (count = msgrcv
            (m_msgqid, &msg, (size_t)(size), type, msgflg)))
        {
            CDBE("() failed on msgrcv()\n");
            error = e_ERROR_FAILED;
        }
        else error = e_ERROR_NONE;
#endif /* defined(CMESSAGEQUEUE_WIN32_API) */
        return error;
    }
};
#undef CDB_CLASS

/**
 **********************************************************************
 *  Typedef: cMessageQueue
 *
 *  Author: $author$
 *    Date: 2/7/2008
 **********************************************************************
 */
typedef cMessageQueueT
<cOpened, cMessageQueueInterface>
cMessageQueue;

#endif /* _CMESSAGEQUEUE_HXX */
