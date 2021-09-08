///////////////////////////////////////////////////////////////////////
//   File: cevcsdo.hpp
//
// Author: $author$
//   Date: 5/30/2007
//
//    $Id$
///////////////////////////////////////////////////////////////////////

#ifndef _CEVCSDO_HPP
#define _CEVCSDO_HPP

#include "evcsdo.hpp"
#include "evcsopstack.hpp"
#include "evcsops.hpp"
#include "cevcsop.hpp"
#include "evdebug.h"

///////////////////////////////////////////////////////////////////////
//  Class: CEvcsDo
//
// Author: $author$
//   Date: 5/30/2007
///////////////////////////////////////////////////////////////////////
class CEvcsDo
: virtual public EvcsDo,
  virtual public EvcsOpStack,
  public CEvcsOp
{
public:
    typedef EvcsDo CImplements;
    typedef CEvcsOp CExtends;
    typedef CEvcsDo CDerives;
    
    EvcsOpStack* m_opStack;
    EvcsOp* m_parentOp;
    EvcsOps m_ops;

    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvcsDo
    //
    //       Author: $author$
    //         Date: 5/30/2007
    ///////////////////////////////////////////////////////////////////////
    CEvcsDo
    (EvcsOpStack* opStack=0, EvcsOp* parentOp=0) 
    : m_opStack(opStack),
      m_parentOp(parentOp)
    {
    }
    ///////////////////////////////////////////////////////////////////////
    // Destructor: ~CEvcsDo
    //
    //      Author: $author$
    //        Date: 5/30/2007
    ///////////////////////////////////////////////////////////////////////
    virtual ~CEvcsDo()
    {
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: Commit
    //
    //   Author: $author$
    //     Date: 5/30/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError Commit() 
    {
        EvError error = EV_ERROR_NONE;
        EvcsOpsIterator i;
        EvcsOp* op;

        DBT("() in...\n");

        for (i = m_ops.begin(); i != m_ops.end(); i++)
        {
            if ((op = *i))
            if ((error = op->Commit()))
                break;
        }
        DBT("() ...out\n");
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: Cancel
    //
    //   Author: $author$
    //     Date: 5/30/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError Cancel() 
    {
        EvError error = EV_ERROR_FAILED;
        EvError error2;
        EvcsOpsIterator i;
        EvcsOp* op;

        DBT("() in...\n");

        for (i = m_ops.end(); i != m_ops.begin(); --i)
        {
            if ((op = *i))
            if ((error2 = op->Cancel()) && !error)
                error = error2;
        }
        DBT("() ...out\n");
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: DeleteThis
    //
    //   Author: $author$
    //     Date: 5/30/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError DeleteThis() 
    {
        delete this;
        return EV_ERROR_NONE;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: PushOp
    //
    //   Author: $author$
    //     Date: 5/30/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError PushOp(EvcsOp& op) 
    {
        EvError error = EV_ERROR_NONE;
        m_ops.push_back(&op);
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: PopOp
    //
    //   Author: $author$
    //     Date: 5/30/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvcsOp* PopOp(EvError& error) 
    {
        EvcsOp* op = 0;
        unsigned size;

        if (0 < (size = (unsigned)m_ops.size()))
        {
            op = m_ops[size-1];
            m_ops.pop_back();
        }
        error = EV_ERROR_NONE;
        return op;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: TopOp
    //
    //   Author: $author$
    //     Date: 9/17/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvcsOp* TopOp(EvError& error) const
    {
        EvcsOp* op = 0;
        unsigned size;

        if (0 < (size = (unsigned)m_ops.size()))
            op = m_ops[size-1];

        error = EV_ERROR_NONE;
        return op;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: SetStack
    //
    //   Author: $author$
    //     Date: 5/30/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError SetStack
    (EvcsOpStack* stack) 
    {
        EvError error = EV_ERROR_NONE;
        m_opStack = stack;
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: GetStack
    //
    //   Author: $author$
    //     Date: 5/30/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvcsOpStack* GetStack
    (EvError& error) const 
    {
        error = EV_ERROR_NONE;
        return m_opStack;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: SetParent
    //
    //   Author: $author$
    //     Date: 5/30/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError SetParent
    (EvcsOp* parent) 
    {
        EvError error = EV_ERROR_NONE;
        m_parentOp = parent;
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: GetParent
    //
    //   Author: $author$
    //     Date: 5/30/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvcsOp* GetParent
    (EvError& error) const 
    {
        error = EV_ERROR_NONE;
        return m_parentOp;
    }
};

#endif // _CEVCSDO_HPP
