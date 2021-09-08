///////////////////////////////////////////////////////////////////////
//   File: cevcspendingactions.hpp
//
// Author: $author$
//   Date: 10/8/2007
//
//    $Id$
///////////////////////////////////////////////////////////////////////

#ifndef _CEVCSPENDINGACTIONS_HPP
#define _CEVCSPENDINGACTIONS_HPP

#include "cevinstance.hpp"
#include "evcsactions.hpp"
#include "evdebug.h"

#undef CDB_CLASS
#define CDB_CLASS "CEvcsPendingActions"
///////////////////////////////////////////////////////////////////////
//  Class: CEvcsPendingActions
//
// Author: $author$
//   Date: 10/8/2007
///////////////////////////////////////////////////////////////////////
template
<class TExtends=CEvInstance,
 class TImplements=EvInstance>

class CEvcsPendingActions
: virtual public TImplements,
  public TExtends
{
public:
    typedef TImplements CImplements;
    typedef TExtends CExtends;
    typedef CEvcsPendingActions CDerives;

    EvcsActions m_pendingActions;

    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvcsPendingActions
    //
    //       Author: $author$
    //         Date: 10/8/2007
    ///////////////////////////////////////////////////////////////////////
    CEvcsPendingActions() 
    {
    }
    ///////////////////////////////////////////////////////////////////////
    // Destructor: ~CEvcsPendingActions
    //
    //      Author: $author$
    //        Date: 10/8/2007
    ///////////////////////////////////////////////////////////////////////
    virtual ~CEvcsPendingActions()
    {
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: FinishActions
    //
    //   Author: $author$
    //     Date: 10/8/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError FinishActions
    (bool clearActions=false, bool deleteActions=false) 
    {
        EvError error = EV_ERROR_NONE;
        EvError error2;
        EvcsActionsIterator i;

        for (i = m_pendingActions.begin(); 
             i != m_pendingActions.end(); i++)
        {
            EvcsAction* action;
            if ((action = *i))
            {
                if ((error2 = action->Finish()))
                {
                    CDBE("() failed to finish action\n");
                    error = EV_ERROR_FAILED;
                }
                if (deleteActions)
                if ((error2 = action->DeleteInstance()))
                {
                    CDBE("() failed to delete action instance\n");
                    error = EV_ERROR_FAILED;
                }
            }
        }
        if (clearActions || deleteActions)
            m_pendingActions.clear();
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: CancelActions
    //
    //   Author: $author$
    //     Date: 10/8/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError CancelActions
    (bool clearActions=false, bool deleteActions=false) 
    {
        EvError error = EV_ERROR_NONE;
        EvError error2;
        EvcsActionsIterator i;

        for (i = m_pendingActions.end(); 
             i != m_pendingActions.begin();)
        {
            EvcsAction* action;
            if ((action = *(--i)))
            {
                if ((error2 = action->Cancel()))
                {
                    CDBE("() failed to cancel action\n");
                    error = EV_ERROR_FAILED;
                }
                if (deleteActions)
                if ((error2 = action->DeleteInstance()))
                {
                    CDBE("() failed to delete action instance\n");
                    error = EV_ERROR_FAILED;
                }
            }
        }
        if (clearActions || deleteActions)
            m_pendingActions.clear();
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: DeleteActions
    //
    //   Author: $author$
    //     Date: 10/8/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError DeleteActions() 
    {
        EvError error = EV_ERROR_NONE;
        EvError error2;
        EvcsActionsIterator i;

        for (i = m_pendingActions.end(); 
             i != m_pendingActions.begin(); i++)
        {
            EvcsAction* action;
            if ((action = *i))
            {
                if ((error2 = action->DeleteInstance()))
                {
                    CDBE("() failed to delete action instance\n");
                    error = EV_ERROR_FAILED;
                }
            }
        }
        m_pendingActions.clear();
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: ClearActions
    //
    //   Author: $author$
    //     Date: 10/8/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError ClearActions() 
    {
        EvError error = EV_ERROR_NONE;
        m_pendingActions.clear();
        return error;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: AddAction
    //
    //   Author: $author$
    //     Date: 10/8/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError AddAction(EvcsAction& action) 
    {
        EvError error = EV_ERROR_NONE;
        m_pendingActions.push_back(&action);
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: RemoveAction
    //
    //   Author: $author$
    //     Date: 10/8/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError RemoveAction(EvcsAction& action) 
    {
        EvError error = EV_ERROR_FAILED;
        EvcsActionsIterator i;

        for (i = m_pendingActions.begin(); 
             i != m_pendingActions.end(); i++)
        {
            EvcsAction* pendingAction;
            if (&action == (pendingAction = *i))
            {
                m_pendingActions.erase(i);
                error = EV_ERROR_NONE;
                break;
            }
        }
        return error;
    }
};
#undef CDB_CLASS
#endif // _CEVCSPENDINGACTIONS_HPP
