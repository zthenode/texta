///////////////////////////////////////////////////////////////////////
//   File: cevopeneddll.hpp
//
// Author: $author$
//   Date: 5/28/2008
///////////////////////////////////////////////////////////////////////
#ifndef _CEVOPENEDDLL_HPP
#define _CEVOPENEDDLL_HPP

#include "cevdll.hpp"
#include "cevstring.hpp"

///////////////////////////////////////////////////////////////////////
//  Class: CEvOpenedDll
//
// Author: $author$
//   Date: 5/28/2008
///////////////////////////////////////////////////////////////////////
class CEvOpenedDll
: public CEvBase
{
public:
    typedef CEvBase CEvExtends;
    typedef CEvOpenedDll CEvDerives;

    const char* m_dllFilenameChars;
    CEvString m_dllFilename;
    bool m_opened;
    CEvDll m_dll;

    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvOpenedDll
    //
    //      Author: $author$
    //        Date: 5/28/2008
    ///////////////////////////////////////////////////////////////////////
    CEvOpenedDll
    (const char* dllFilenameChars=0,
     DLL attached=INVALID_DLL,
     bool opened=false) 
    : m_dllFilenameChars(dllFilenameChars),
      m_opened(opened),
      m_dll(attached)
    {
    }
    ///////////////////////////////////////////////////////////////////////
    // Destructor: ~CEvOpenedDll
    //
    //     Author: $author$
    //       Date: 5/28/2008
    ///////////////////////////////////////////////////////////////////////
    virtual ~CEvOpenedDll()
    {
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: Open
    //
    //   Author: $author$
    //     Date: 5/28/2008
    ///////////////////////////////////////////////////////////////////////
    virtual EvError Open
    (const char* dllFilenameChars=0, 
     bool onlyClosed=false) 
    {
		DF(Open)
        EvError error = EV_ERROR_FAILED;

        if (m_opened)
        if (onlyClosed)
            return EV_ERROR_ALREADY_OPEN;
        else return EV_ERROR_NONE;

        if (!dllFilenameChars)
            dllFilenameChars = m_dllFilenameChars;

        if (dllFilenameChars)
        if ((error = m_dll.Open(dllFilenameChars)))
            DBE("() failed to open dll \"%s\"\n", dllFilenameChars);
        else
        {
            if ((error = AcquireSymbols()))
                DBE("() acquire symbols failed\n");
            {
                m_opened = true;
                return error;
            }
            m_dll.Close();
        }
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: Close
    //
    //   Author: $author$
    //     Date: 5/28/2008
    ///////////////////////////////////////////////////////////////////////
    virtual EvError Close(bool onlyOpened=false) 
    {
		DF(Close)
        EvError error = EV_ERROR_FAILED;

        if (!m_opened)
        if (onlyOpened)
            return EV_ERROR_NOT_OPEN;
        else return EV_ERROR_NONE;

        if ((error = ReleaseSymbols()))
            DBE("() release symbols failed\n");

        if ((error = m_dll.Close()))
            DBE("() dll close failed\n");

        m_opened = false;
        return error;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: AcquireSymbols
    //
    //   Author: $author$
    //     Date: 5/28/2008
    ///////////////////////////////////////////////////////////////////////
    virtual EvError AcquireSymbols() 
    {
        EvError error = EV_ERROR_NONE;
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: ReleaseSymbols
    //
    //   Author: $author$
    //     Date: 5/28/2008
    ///////////////////////////////////////////////////////////////////////
    virtual EvError ReleaseSymbols() 
    {
        EvError error = EV_ERROR_NONE;
        return error;
    }
};
#endif // _CEVOPENEDDLL_HPP 
