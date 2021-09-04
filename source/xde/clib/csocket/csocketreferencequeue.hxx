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
 *   File: csocketreferencequeue.hxx
 *
 * Author: $author$
 *   Date: 2/21/2008
 **********************************************************************
 */
#ifndef _CSOCKETREFERENCEQUEUE_HXX
#define _CSOCKETREFERENCEQUEUE_HXX

#include "cqueue.hxx"
#include "csocket.hxx"

/**
 **********************************************************************
 *  Class: cSocketReferenceQueueInterface
 *
 * Author: $author$
 *   Date: 2/19/2008
 **********************************************************************
 */
class cSocketReferenceQueueInterface
: public cQueueInterfaceT<cSocketReference>
{
public:
    typedef cQueueInterfaceT<cSocketReference> cExtends;
    typedef cSocketReferenceQueueInterface cDerives;
};
/**
 **********************************************************************
 *  Typedef: cSocketReferenceQueueExtends
 *
 *  Author: $author$
 *    Date: 2/19/2008
 **********************************************************************
 */
typedef std::deque
<cSocketReference>
cSocketReferenceQueueExtends;
/**
 **********************************************************************
 *  Class: cSocketReferenceQueue
 *
 * Author: $author$
 *   Date: 2/19/2008
 **********************************************************************
 */
class cSocketReferenceQueue
: public cQueueT
  <cSocketReference,TSIZE,TLENGTH,
   cSocketReferenceQueueInterface,
   cSocketReferenceQueueExtends>
{
public:
    typedef cQueueT
    <cSocketReference,TSIZE,TLENGTH,
     cSocketReferenceQueueInterface,
     cSocketReferenceQueueExtends> cExtends;
    typedef cSocketReferenceQueue cDerives;
};

#endif /* _CSOCKETREFERENCEQUEUE_HXX */
