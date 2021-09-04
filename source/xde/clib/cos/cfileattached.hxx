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
 *   File: cfileattached.hxx
 *
 * Author: $author$
 *   Date: 3/5/2008
 **********************************************************************
 */
#ifndef _CFILEATTACHED_HXX
#define _CFILEATTACHED_HXX

#include "cfileattachedinterface.hxx"
#include "cattached.hxx"

/**
 **********************************************************************
 *  Class: cFILEAttached
 *
 * Author: $author$
 *   Date: 3/5/2008
 **********************************************************************
 */
class cFILEAttached
: public cAttachedT
  <FILE*, int, NULL, cFILEAttachedInterface, cBase>
{
public:
    typedef cAttachedT
    <FILE*, int, NULL, cFILEAttachedInterface, cBase> cExtends;
    typedef cFILEAttached cDerives;
    /**
     **********************************************************************
     * Constructor: cFILEAttached
     *
     *      Author: $author$
     *        Date: 3/5/2008
     **********************************************************************
     */
    cFILEAttached() 
    {
    }
    /**
     **********************************************************************
     * Destructor: cFILEAttached
     *
     *     Author: $author$
     *       Date: 3/5/2008
     **********************************************************************
     */
    virtual ~cFILEAttached()
    {
    }
};
#endif /* _CFILEATTACHED_HXX */
