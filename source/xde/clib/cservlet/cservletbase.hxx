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
 *   File: cservletbase.hxx
 *
 * Author: $author$
 *   Date: 2/24/2008
 **********************************************************************
 */
#ifndef _CSERVLETBASE_HXX
#define _CSERVLETBASE_HXX

#include "cservletinterfacebase.hxx"
#include "cbase.hxx"
#include "cdebug.h"

#undef CDB_CLASS
#define CDB_CLASS "cServletBaseT"
/**
 **********************************************************************
 *  Class: cServletBaseT
 *
 * Author: $author$
 *   Date: 2/24/2008
 **********************************************************************
 */
template
<class TImplements=cServletInterfaceBase,
 class TExtends=cBase>
 
class cServletBaseT
: virtual public TImplements,
  public TExtends
{
public:
    typedef TImplements cImplements;
    typedef TExtends cExtends;
    typedef cServletBaseT cDerives;
    /**
     **********************************************************************
     * Constructor: cServletBaseT
     *
     *      Author: $author$
     *        Date: 2/24/2008
     **********************************************************************
     */
    cServletBaseT() 
    {
    }
    /**
     **********************************************************************
     * Destructor: cServletBaseT
     *
     *     Author: $author$
     *       Date: 2/24/2008
     **********************************************************************
     */
    virtual ~cServletBaseT()
    {
    }
};
#undef CDB_CLASS

/**
 **********************************************************************
 *  Class: cServletBase
 *
 * Author: $author$
 *   Date: 2/25/2008
 **********************************************************************
 */
class cServletBase
: public cServletBaseT<cServletInterfaceBase,cBase>
{
    typedef cServletBaseT<cServletInterfaceBase,cBase> cExtends;
};
#endif /* _CSERVLETBASE_HXX */
