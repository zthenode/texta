///////////////////////////////////////////////////////////////////////
//   File: cevsemaphore.hpp
//
// Author: $author$
//   Date: 4/5/2007
//
//    $Id$
///////////////////////////////////////////////////////////////////////

#ifndef _CEVSEMAPHORE_HPP
#define _CEVSEMAPHORE_HPP

#include "evplatform_semaphore.h"
#include "evsemaphore.hpp"
#include "evwait.hpp"
#include "evtake.hpp"
#include "evgive.hpp"
#include "cevbase.hpp"

#if defined(WIN32) 
//
// Windows
//
#else // defined(WIN32) 
//
// Unix
//
#endif // defined(WIN32)

///////////////////////////////////////////////////////////////////////
//  Class: CEvSemaphore
//
// Author: $author$
//   Date: 4/5/2007
///////////////////////////////////////////////////////////////////////
class EV_EXPORT_CLASS CEvSemaphore
: virtual public EvSemaphore,
  public CEvBase
{
public:
    typedef EvSemaphore CImplements;
    typedef CEvBase CExtends;
    typedef CEvSemaphore CDerives;

#if defined(WIN32) 
// Windows
	HANDLE m_sem;
#else // defined(WIN32) 
// Unix
	sem_t m_sem;
#endif // defined(WIN32)

	bool m_isCreated;

    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvSemaphore
    //
    //       Author: $author$
    //         Date: 4/5/2007
    ///////////////////////////////////////////////////////////////////////
    CEvSemaphore
    (bool isCreated=false, 
     UINT count=0) 
	: m_isCreated(false) 
    {
		EvError error;

		if (isCreated)
		if ((error = Create(count)))
			throw(error);
    }
    ///////////////////////////////////////////////////////////////////////
    // Destructor: ~CEvSemaphore
    //
    //      Author: $author$
    //        Date: 4/5/2007
    ///////////////////////////////////////////////////////////////////////
    virtual ~CEvSemaphore()
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
    virtual EvError Create(UINT count=0) 
    {
        EvError error = EV_ERROR_FAILED;

		if (m_isCreated)
			return EV_ERROR_ALREADY_CREATED;

#if defined(WIN32) 
// Windows
		LONG maxcount = (((ULONG)-1)>>1);
		if ((m_isCreated = (NULL != (m_sem = CreateSemaphore
			(NULL, count, maxcount, NULL)))))
#else // defined(WIN32) 
// Unix
		int err;
		if ((m_isCreated = (!(err = sem_init(&m_sem, 0, count)))))
#endif // defined(WIN32)
            error = EV_ERROR_NONE;

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
		if (CloseHandle(m_sem))
#else // defined(WIN32) 
// Unix
		int err;
		if (!(err = sem_destroy(&m_sem)))
#endif // defined(WIN32)
        {
            m_isCreated = false;
			error = EV_ERROR_NONE;
        }

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
        EvError error = Take(1, milliSeconds);
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
        EvError error = Take(1, waitMilliSeconds);
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
        EvError error = Give();
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
			(m_sem, milliSeconds)))
		if (WAIT_TIMEOUT != result)
            return error;
        else return EV_ERROR_WAIT_TIMEOUT;
#else // defined(WIN32) 
// Unix
		int err;
		if (!(err = sem_wait(&m_sem)))
#endif // defined(WIN32)
        error = EV_ERROR_NONE;

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

		if (!m_isCreated)
			return EV_ERROR_NOT_CREATED;

#if defined(WIN32) 
// Windows
		LONG oldcount;
		if (ReleaseSemaphore(m_sem, amount, &oldcount))
#else // defined(WIN32) 
// Unix
		for (UINT i=0; i<amount; i++)
		{
			int err;
			if ((err = sem_post(&m_sem)))
				return error;
		}		
#endif // defined(WIN32)
        error = EV_ERROR_NONE;

        return error;
    }
};
#endif // _CEVSEMAPHORE_HPP
