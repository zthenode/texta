///////////////////////////////////////////////////////////////////////
//   File: cevdll.hpp
//
// Author: $author$
//   Date: 4/11/2007
///////////////////////////////////////////////////////////////////////

#ifndef _CEVDLL_HPP
#define _CEVDLL_HPP

#include "evdll.hpp"
#include "cevtstring.hpp"
#include "cevattached.hpp"
#include "cevreferenced.hpp"
#include "evdebug.h"

///////////////////////////////////////////////////////////////////////
//  Class: CEvDllAttached
//
// Author: $author$
//   Date: 4/12/2007
///////////////////////////////////////////////////////////////////////
typedef CEvAttached
<DLL, INVALID_DLL_T, INVALID_DLL, EvDllAttached, CEvBase>
CEvDllAttached;

///////////////////////////////////////////////////////////////////////
//  Class: CEvDll
//
// Author: $author$
//   Date: 4/11/2007
///////////////////////////////////////////////////////////////////////
class CEvDll
: virtual public EvDll,
  public CEvDllAttached
{
public:
    typedef EvDll CImplements;
    typedef CEvDllAttached CExtends;
    typedef CEvDll CDerives;

    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvDll
    //
    //       Author: $author$
    //         Date: 4/11/2007
    ///////////////////////////////////////////////////////////////////////
    CEvDll(DLL attached=INVALID_DLL)
    : CExtends(attached) 
    {
    }
    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvDll
    //
    //       Author: $author$
    //         Date: 4/11/2007
    ///////////////////////////////////////////////////////////////////////
    CEvDll
    (const char* filename,
     bool resolve=true,
     bool global=false) 
    {
        EvError error;

        if (filename)
        if (filename[0])
        if ((error = Open(filename, resolve, global)))
            throw(error);
    }
    ///////////////////////////////////////////////////////////////////////
    // Destructor: ~CEvDll
    //
    //      Author: $author$
    //        Date: 4/11/2007
    ///////////////////////////////////////////////////////////////////////
    virtual ~CEvDll()
    {
        EvError error;

        if (INVALID_DLL != m_attached)
        if ((error = Close()))
            throw(error);
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: Open
    //
    //   Author: $author$
    //     Date: 4/11/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError Open
    (const char* filename,
     bool resolve=true,
     bool global=false) 
    {
		DF(Open)
        EvError error = EV_ERROR_FAILED;

		if (!filename || !filename[0])
			return EV_ERROR_NULL_PARAMETER;

#if defined(WIN32) 
// Windows
        char c;
        LONG length;
        TCHAR tChar;
        const char* chars;
        const TCHAR* tChars;
        CEvTString tFilename;

        for (chars = filename; (c = *chars); chars++)
        {
            if ('/' == c)
                tChar = (TCHAR)('\\');
            else tChar = (TCHAR)(c);

            tFilename.Append(&tChar, 1);
        }

        if ((tChars = tFilename.Chars(length)))
        if (0 < length)
        if (INVALID_DLL != (m_attached = LoadLibrary(tChars)))
            error = EV_ERROR_NONE;
        else DBE("() LoadLibrary(\"%s\") error %lu", filename, GetLastError());
#else // defined(WIN32) 
// Unix
		int flag = (resolve?RTLD_NOW:RTLD_LAZY)
                   |(global?RTLD_GLOBAL:0);

		if (INVALID_DLL != (m_attached = dlopen(filename, flag)))
			error = EV_ERROR_NONE;
		else DBE("() dlopen(\"%s\") error \"%s\"\n", filename, dlerror());
#endif // defined(WIN32)

        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: Close
    //
    //   Author: $author$
    //     Date: 4/11/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError Close() 
    {
		DF(Close)
        EvError error = EV_ERROR_FAILED;

		if (INVALID_DLL == m_attached)
			return EV_ERROR_NOT_ATTACHED;

#if defined(WIN32) 
// Windows
		if (!FreeLibrary(m_attached))
            DBE("() FreeLibrary() failed\n");
#else // defined(WIN32) 
// Unix
		int err;
		if ((err = dlclose(m_attached)))
            DBE("() dlclose() failed\n");
#endif // defined(WIN32)
        else
        {
            error = EV_ERROR_NONE;
		    m_attached = INVALID_DLL;
        }

        return error;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: GetAddress
    //
    //   Author: $author$
    //     Date: 4/12/2007
    ///////////////////////////////////////////////////////////////////////
    virtual void* GetAddress
    (const char* symbol) const
    {
        void* address = 0;

		if (symbol && (INVALID_DLL != m_attached))
#if defined(WIN32) 
// Windows
		address = GetProcAddress(m_attached, symbol);
#else // defined(WIN32) 
// Unix
		address = dlsym(m_attached, symbol);
#endif // defined(WIN32)

        return address;
    }
};

#endif // _CEVDLL_HPP
