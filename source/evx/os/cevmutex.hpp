///////////////////////////////////////////////////////////////////////
//   File: cevmutex.hpp
//
// Author: $author$
//   Date: 4/5/2007
//
//    $Id$
///////////////////////////////////////////////////////////////////////

#ifndef _CEVMUTEX_HPP
#define _CEVMUTEX_HPP

#include "evmutex.hpp"
#include "cevbase.hpp"
#include "evplatform_mutex.h"

#if defined(WIN32) 
// Windows
#else // defined(WIN32) 
// Unix
#endif // defined(WIN32)

///////////////////////////////////////////////////////////////////////
//  Class: CEvMutex
//
// Author: $author$
//   Date: 4/5/2007
///////////////////////////////////////////////////////////////////////
class EV_EXPORT_CLASS CEvMutex
: virtual public EvMutex,
  public CEvBase
{
public:
    typedef EvMutex CImplements;
    typedef CEvBase CExtends;
    typedef CEvMutex CDerives;

#if defined(WIN32) 
// Windows
	HANDLE m_mutex;
#else // defined(WIN32) 
// Unix
	pthread_mutex_t m_mutex;
	pthread_mutexattr_t m_mutexAttr;
#endif // defined(WIN32)

	bool m_isCreated;

    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvMutex
    //
    //       Author: $author$
    //         Date: 4/5/2007
    ///////////////////////////////////////////////////////////////////////
    CEvMutex
    (bool isCreated=false, 
     bool isAcquired=false) 
	: m_isCreated(false)
    {
		EvError error;

		if (isCreated)
		if ((error = Create(isAcquired)))
			throw(error);
    }
    ///////////////////////////////////////////////////////////////////////
    // Destructor: ~CEvMutex
    //
    //      Author: $author$
    //        Date: 4/5/2007
    ///////////////////////////////////////////////////////////////////////
    virtual ~CEvMutex()
    {
		EvError error;

		if (m_isCreated)
		if ((error = Destroy()))
			throw(error);
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: Create
    //
    //   Author: $author$
    //     Date: 4/6/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError Create(bool isAcquired=false) 
    {
        EvError error = EV_ERROR_FAILED;

		if (m_isCreated)
			return EV_ERROR_ALREADY_CREATED;

#if defined(WIN32)
// Windows
		if ((m_isCreated = (NULL != (m_mutex = CreateMutex
			(NULL, isAcquired, NULL)))))
			error = EV_ERROR_NONE;
#else /* defined(WIN32) */
// Unix
		int err;
		if (!(err = pthread_mutexattr_settype
			(&m_mutexAttr, PTHREAD_MUTEX_RECURSIVE)))
		if (!(err = pthread_mutex_init(&m_mutex, &m_mutexAttr)))
		{
			m_isCreated = true;
			error = EV_ERROR_NONE;
		}
		else pthread_mutexattr_destroy(&m_mutexAttr);
#endif /* defined(WIN32) */

        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: Destroy
    //
    //   Author: $author$
    //     Date: 4/6/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError Destroy() 
    {
        EvError error = EV_ERROR_FAILED;

		if (!m_isCreated)
			return EV_ERROR_NOT_CREATED;

#if defined(WIN32) 
// Windows
		if (CloseHandle(m_mutex))
#else // defined(WIN32) 
// Unix
		int err, err2;
		err = pthread_mutexattr_destroy(&m_mutexAttr);
		if (!(err2 = pthread_mutex_destroy(&m_mutex)))
		if (!err)
#endif // defined(WIN32)
        {
            m_isCreated = false;
			error = EV_ERROR_NONE;
        }

        return error;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: Acquire
    //
    //   Author: $author$
    //     Date: 4/6/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError Acquire
    (LONG waitMilliSeconds=INFINITE) 
    {
        EvError error = EV_ERROR_FAILED;

		if (!m_isCreated)
			return EV_ERROR_NOT_CREATED;

#if defined(WIN32) 
// Windows
        DWORD milliSeconds 
        = (0 > waitMilliSeconds)
          ?INFINITE
          :waitMilliSeconds;
		DWORD result;

		if (WAIT_OBJECT_0 != (result = WaitForSingleObject
			(m_mutex, milliSeconds)))
		if (WAIT_TIMEOUT != result)
            return error;
        else return EV_ERROR_WAIT_TIMEOUT;

        error = EV_ERROR_NONE;
#else // defined(WIN32) 
// Unix
		int err;
		if (0 < waitMilliSeconds)
			return EV_ERROR_NOT_IMPLEMENTED;
		else if (0 > waitMilliSeconds)
				err = pthread_mutex_lock(&m_mutex);
		else if ((err = pthread_mutex_trylock(&m_mutex)))
                return EV_ERROR_WAIT_TIMEOUT;
		if (!err)
            error = EV_ERROR_NONE;
#endif // defined(WIN32)

        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: Release
    //
    //   Author: $author$
    //     Date: 4/6/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError Release() 
    {
        EvError error = EV_ERROR_FAILED;

		if (!m_isCreated)
			return EV_ERROR_NOT_CREATED;

#if defined(WIN32) 
// Windows
		if (ReleaseMutex(m_mutex))
            error = EV_ERROR_NONE;
#else // defined(WIN32) 
// Unix
		int err;
		if (!(err = pthread_mutex_unlock(&m_mutex)))
            error = EV_ERROR_NONE;
#endif // defined(WIN32)

        return error;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: Wait
    //
    //   Author: $author$
    //     Date: 4/6/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError Wait
    (LONG milliSeconds=INFINITE) 
    {
        EvError error = Acquire(milliSeconds);
        return error;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: Take
    //
    //   Author: $author$
    //     Date: 4/5/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError Take
    (UINT amount=1,
     LONG waitMilliSeconds=INFINITE) 
    {
        EvError error = EV_ERROR_FAILED;

        if (1 > amount)
            return EV_ERROR_NONE;
        else if (1 < amount)
                return EV_ERROR_INVALID_PARAMETER;
        else error = Acquire(waitMilliSeconds);

        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: Give
    //
    //   Author: $author$
    //     Date: 4/5/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError Give
    (UINT amount=1) 
    {
        EvError error = EV_ERROR_FAILED;

        if (1 > amount)
            return EV_ERROR_NONE;
        else if (1 < amount)
                return EV_ERROR_INVALID_PARAMETER;
        else error = Release();

        return error;
    }
};
#endif // _CEVMUTEX_HPP
