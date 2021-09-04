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
 *   File: cqueuedrequestserverbase.hxx
 *
 * Author: $author$
 *   Date: 2/21/2008
 **********************************************************************
 */
#ifndef _CQUEUEDREQUESTSERVERBASE_HXX
#define _CQUEUEDREQUESTSERVERBASE_HXX

#include "cbase.hxx"
#include "cerror.h"
#include "cdebug.h"

#undef CDB_CLASS
#define CDB_CLASS "cQueuedRequestServerBaseT"
/**
 **********************************************************************
 *  Class: cQueuedRequestServerBaseT
 *
 * Author: $author$
 *   Date: 2/21/2008
 **********************************************************************
 */
template
<class TDerives,
 class TRequest=CHAR,
 class TExtends=cBase>
 
class cQueuedRequestServerBaseT
: public TExtends
{
public:
    typedef TExtends cExtends;
    typedef TDerives cDerives;
    /**
     **********************************************************************
     * Function: Run
     *
     *   Author: $author$
     *     Date: 2/17/2008
     **********************************************************************
     */
    virtual eError Run
    (cDerives& requestServer) 
    {
        eError error = e_ERROR_NONE;
        return error;
    }
    /**
     **********************************************************************
     * Function: Service
     *
     *   Author: $author$
     *     Date: 2/17/2008
     **********************************************************************
     */
    virtual eError Service
    (TRequest& request,
     cDerives& queueServer) 
    {
        eError error = e_ERROR_NONE;
        return error;
    }
};
#undef CDB_CLASS

/**
 **********************************************************************
 *  Class: cQueuedRequestServerBase
 *
 * Author: $author$
 *   Date: 2/21/2008
 **********************************************************************
 */
class cQueuedRequestServerBase
: public cQueuedRequestServerBaseT
  <cQueuedRequestServerBase, CHAR, cBase>
{
public:
    typedef cQueuedRequestServerBaseT
    <cQueuedRequestServerBase, CHAR, cBase> cExtends;
    typedef cQueuedRequestServerBase cDerives;
};
#endif /* _CQUEUEDREQUESTSERVERBASE_HXX */
