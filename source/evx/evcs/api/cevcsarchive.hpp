///////////////////////////////////////////////////////////////////////
//   File: cevcsarchive.hpp
//
// Author: $author$
//   Date: 9/28/2007
//
//    $Id$
///////////////////////////////////////////////////////////////////////

#ifndef _CEVCSARCHIVE_HPP
#define _CEVCSARCHIVE_HPP

#include "evcsarchive.hpp"
#include "evcsdos.hpp"
#include "cevcsdo.hpp"
#include "cevcspendingactions.hpp"
#include "cevinstance.hpp"
#include "evcsactions.hpp"
#include "evdebug.h"

///////////////////////////////////////////////////////////////////////
//  Class: CEvcsArchive
//
// Author: $author$
//   Date: 9/28/2007
///////////////////////////////////////////////////////////////////////
class CEvcsArchive
: virtual public EvcsArchive,
  public CEvcsPendingActions
  <CEvInstance, EvcsArchive>
{
public:
    typedef EvcsArchive CImplements;
    typedef CEvcsPendingActions
    <CEvInstance, EvcsArchive> CExtends;
    typedef CEvcsArchive CDerives;

    EvcsDos m_doStack;
    EvcsDo* m_do;

    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvcsArchive
    //
    //       Author: $author$
    //         Date: 9/28/2007
    ///////////////////////////////////////////////////////////////////////
    CEvcsArchive()
    : m_do(0)
    {
        DBF("() in...\n");
        DBF("() ...out\n");
    }
    ///////////////////////////////////////////////////////////////////////
    // Destructor: ~CEvcsArchive
    //
    //      Author: $author$
    //        Date: 9/28/2007
    ///////////////////////////////////////////////////////////////////////
    virtual ~CEvcsArchive()
    {
        EvError error;
        if ((error = Close()))
            throw(error);
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: Close
    //
    //   Author: $author$
    //     Date: 9/28/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError Close() 
    {
        EvError error = CancelActions(true, true);
        return error;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: Do
    //
    //   Author: $author$
    //     Date: 10/8/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError Do() 
    {
        EvError error = EV_ERROR_NEW;
        EvcsDo* evcsDo = 0;

        if ((evcsDo = new CEvcsDo(*this)))
        {
            if (m_do)
                m_doStack.push_back(m_do);

            m_do = evcsDo;
            error = EV_ERROR_NONE;
        }
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: FinishDo
    //
    //   Author: $author$
    //     Date: 10/8/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError FinishDo() 
    {
        EvError error = EV_ERROR_FAILED;
        EvError error2;
        EvcsDo* topDo;

        if ((topDo = PopDo()))
        if (!(error2 = topDo->Finish()))
            error = EV_ERROR_NONE;
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: CancelDo
    //
    //   Author: $author$
    //     Date: 10/8/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError CancelDo() 
    {
        EvError error = EV_ERROR_FAILED;
        EvError error2;
        EvcsDo* topDo;

        if ((topDo = PopDo()))
        if (!(error2 = topDo->Cancel()))
            error = EV_ERROR_NONE;
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: PopDo
    //
    //   Author: $author$
    //     Date: 10/8/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvcsDo* PopDo()
    {
        EvcsDosIterator i;
        EvcsDo* topDo = m_do;

        if ((i = m_doStack.end()) != m_doStack.begin())
        {
            m_do = *(--i);
            m_doStack.pop_back();
        }
        else m_do = 0;
        return topDo;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: GetDo
    //
    //   Author: $author$
    //     Date: 10/8/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvcsDo* GetDo
    (EvError& error) const
    {
        EvcsDo* evcsDo = m_do;
        error = EV_ERROR_NONE;
        return evcsDo;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: GetEntry
    //
    //   Author: $author$
    //     Date: 9/28/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvcsGet* GetEntry
    (EvError& error,
     EvcsEntry& entry,
     const char* entryPathName,
     bool isRecursive=false) 
    {
        EvcsGet* get = 0;
        error = EV_ERROR_NOT_IMPLEMENTED;
        return 0;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: PutEntry
    //
    //   Author: $author$
    //     Date: 9/28/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvcsPut* PutEntry
    (EvError& error,
     const EvcsEntry& entry,
     const char* entryPathName) 
    {
        EvcsPut* put = 0;
        error = EV_ERROR_NOT_IMPLEMENTED;
        return put;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: LockEntry
    //
    //   Author: $author$
    //     Date: 10/10/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError LockEntry
    (const EvcsEntry& entry,
     const char* entryPathName,
     bool isExclusive=false,
     bool isDefered=false) 
    {
        EvError error = EV_ERROR_NOT_IMPLEMENTED;
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: UnlockEntry
    //
    //   Author: $author$
    //     Date: 10/10/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError UnlockEntry
    (const EvcsEntry& entry,
     const char* entryPathName) 
    {
        EvError error = EV_ERROR_NOT_IMPLEMENTED;
        return error;
    }
};
#endif // _CEVCSARCHIVE_HPP
