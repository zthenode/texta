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
 *   File: cqueueinterface.hxx
 *
 * Author: $author$
 *   Date: 2/16/2008
 **********************************************************************
 */
#ifndef _CQUEUEINTERFACE_HXX
#define _CQUEUEINTERFACE_HXX

#include "cinterfacebase.hxx"

#undef CDB_CLASS
#define CDB_CLASS "cQueueInterfaceT"
/**
 **********************************************************************
 *  Class: cQueueInterfaceT
 *
 * Author: $author$
 *   Date: 2/16/2008
 **********************************************************************
 */
template
<class TWhat=CHAR,
 class TSize=ULONG,
 class TLength=LONG,
 class TImplements=cInterfaceBase>
 
class c_INTERFACE_CLASS cQueueInterfaceT
: virtual public TImplements
{
public:
    typedef TImplements cImplements;
    typedef cQueueInterfaceT cDerives;
    /**
     **********************************************************************
     * Function: Add
     *
     *   Author: $author$
     *     Date: 2/17/2008
     **********************************************************************
     */
    virtual TLength Add
    (const TWhat& what) = 0;
    /**
     **********************************************************************
     * Function: Pull
     *
     *   Author: $author$
     *     Date: 2/17/2008
     **********************************************************************
     */
    virtual TLength Pull
    (TWhat& what) = 0;
    /**
     **********************************************************************
     * Function: Push
     *
     *   Author: $author$
     *     Date: 2/17/2008
     **********************************************************************
     */
    virtual TLength Push
    (const TWhat& what) = 0;
    /**
     **********************************************************************
     * Function: Pop
     *
     *   Author: $author$
     *     Date: 2/17/2008
     **********************************************************************
     */
    virtual TLength Pop
    (TWhat& what) = 0;
};
#undef CDB_CLASS

/**
 **********************************************************************
 *  Typedef: cQueueInterface
 *
 *  Author: $author$
 *    Date: 2/16/2008
 **********************************************************************
 */
typedef cQueueInterfaceT
<CHAR, ULONG, LONG, cInterfaceBase>
cQueueInterface;

#endif /* _CQUEUEINTERFACE_HXX */
