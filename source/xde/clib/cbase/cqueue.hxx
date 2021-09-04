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
 *   File: cqueue.hxx
 *
 * Author: $author$
 *   Date: 2/16/2008
 **********************************************************************
 */
#ifndef _CQUEUE_HXX
#define _CQUEUE_HXX

#include <deque>
#include "cqueueinterface.hxx"

/**
 **********************************************************************
 *  Typedef: cQueueExtends
 *
 *  Author: $author$
 *    Date: 2/16/2008
 **********************************************************************
 */
typedef std::deque<CHAR>
cQueueExtends;

#undef CDB_CLASS
#define CDB_CLASS "cQueueT"
/**
 **********************************************************************
 *  Class: cQueueT
 *
 * Author: $author$
 *   Date: 2/16/2008
 **********************************************************************
 */
template
<class TWhat=CHAR,
 class TSize=ULONG,
 class TLength=LONG,
 class TImplements=cQueueInterface,
 class TExtends=cQueueExtends>
 
class cQueueT
: virtual public TImplements,
  public TExtends
{
public:
    typedef TImplements cImplements;
    typedef TExtends cExtends;
    typedef cQueueT cDerives;
    /**
     **********************************************************************
     * Constructor: cQueueT
     *
     *      Author: $author$
     *        Date: 2/16/2008
     **********************************************************************
     */
    cQueueT() 
    {
    }
    /**
     **********************************************************************
     * Destructor: cQueueT
     *
     *     Author: $author$
     *       Date: 2/16/2008
     **********************************************************************
     */
    virtual ~cQueueT()
    {
    }
    /**
     **********************************************************************
     * Function: Add
     *
     *   Author: $author$
     *     Date: 2/17/2008
     **********************************************************************
     */
    virtual TLength Add
    (const TWhat& what) 
    {
        TLength count;
        CTHIS push_back(what);
        count = Length();
        return count;
    }
    /**
     **********************************************************************
     * Function: Pull
     *
     *   Author: $author$
     *     Date: 2/17/2008
     **********************************************************************
     */
    virtual TLength Pull
    (TWhat& what) 
    {
        TLength count;
        if (0 < (count = Length()))
        {
            what = CTHIS back();
            CTHIS pop_back();
        }
        return count;
    }
    /**
     **********************************************************************
     * Function: Push
     *
     *   Author: $author$
     *     Date: 2/17/2008
     **********************************************************************
     */
    virtual TLength Push
    (const TWhat& what) 
    {
        TLength count;
        CTHIS push_front(what);
        count = Length();
        return count;
    }
    /**
     **********************************************************************
     * Function: Pop
     *
     *   Author: $author$
     *     Date: 2/17/2008
     **********************************************************************
     */
    virtual TLength Pop
    (TWhat& what) 
    {
        TLength count;
        if (0 < (count = Length()))
        {
            what = CTHIS front();
            CTHIS pop_front();
        }
        return count;
    }
    /**
     **********************************************************************
     * Function: Length
     *
     *   Author: $author$
     *     Date: 2/17/2008
     **********************************************************************
     */
    virtual TLength Length() const 
    {
        TLength length = (TLength)(CTHIS size());
        return length;
    }
};
#undef CDB_CLASS

/**
 **********************************************************************
 *  Typedef: cQueue
 *
 *  Author: $author$
 *    Date: 2/16/2008
 **********************************************************************
 */
typedef cQueueT
<CHAR, ULONG, LONG, 
 cQueueInterface, cQueueExtends>
cQueue;

#endif /* _CQUEUE_HXX */
