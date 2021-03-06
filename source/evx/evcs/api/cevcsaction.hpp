///////////////////////////////////////////////////////////////////////
//   File: cevcsaction.hpp
//
// Author: $author$
//   Date: 9/28/2007
//
//    $Id$
///////////////////////////////////////////////////////////////////////

#ifndef _CEVCSACTION_HPP
#define _CEVCSACTION_HPP

#include "evcsaction.hpp"
#include "evcsarchive.hpp"
#include "cevinstance.hpp"

///////////////////////////////////////////////////////////////////////
//  Class: CEvcsAction
//
// Author: $author$
//   Date: 9/28/2007
///////////////////////////////////////////////////////////////////////
class CEvcsAction
: virtual public EvcsAction,
  public CEvInstance
{
public:
    typedef EvcsAction CImplements;
    typedef CEvInstance CExtends;
    typedef CEvcsAction CDerives;

    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvcsAction
    //
    //       Author: $author$
    //         Date: 9/28/2007
    ///////////////////////////////////////////////////////////////////////
    CEvcsAction()
    {
    }
    ///////////////////////////////////////////////////////////////////////
    // Destructor: ~CEvcsAction
    //
    //      Author: $author$
    //        Date: 9/28/2007
    ///////////////////////////////////////////////////////////////////////
    virtual ~CEvcsAction()
    {
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: Finish
    //
    //   Author: $author$
    //     Date: 9/28/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError Finish() 
    {
        EvError error = EV_ERROR_NONE;
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: Cancel
    //
    //   Author: $author$
    //     Date: 9/28/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError Cancel() 
    {
        EvError error = EV_ERROR_NONE;
        return error;
    }
};
#endif // _CEVCSACTION_HPP
