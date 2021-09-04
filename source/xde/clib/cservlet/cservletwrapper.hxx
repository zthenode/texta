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
 *   File: cservletwrapper.hxx
 *
 * Author: $author$
 *   Date: 2/24/2008
 **********************************************************************
 */
#ifndef _CSERVLETWRAPPER_HXX
#define _CSERVLETWRAPPER_HXX

#include "cservletwrapperinterface.hxx"
#include "cservletbase.hxx"

#undef CDB_CLASS
#define CDB_CLASS "cServletWrapperT"
/**
 **********************************************************************
 *  Class: cServletWrapperT
 *
 * Author: $author$
 *   Date: 2/24/2008
 **********************************************************************
 */
template
<class TServletInterface=cServletInterface,
 class TImplements=cServletWrapperInterface,
 class TExtends=cServletBase>
 
class cServletWrapperT
: virtual public TImplements,
  public TExtends
{
public:
    typedef TImplements cImplements;
    typedef TExtends cExtends;
    typedef cServletWrapperT cDerives;
    /**
     **********************************************************************
     * Constructor: cServletWrapperT
     *
     *      Author: $author$
     *        Date: 2/24/2008
     **********************************************************************
     */
    cServletWrapperT() 
    {
    }
    /**
     **********************************************************************
     * Destructor: cServletWrapperT
     *
     *     Author: $author$
     *       Date: 2/24/2008
     **********************************************************************
     */
    virtual ~cServletWrapperT()
    {
    }
    /**
     **********************************************************************
     * Function: Allocate
     *
     *   Author: $author$
     *     Date: 2/24/2008
     **********************************************************************
     */
    virtual TServletInterface* Allocate
    (eError& error) 
    {
        TServletInterface* servlet=0;
        error = e_ERROR_NOT_IMPLEMENTED;
        return servlet;
    }
    /**
     **********************************************************************
     * Function: Deallocate
     *
     *   Author: $author$
     *     Date: 2/24/2008
     **********************************************************************
     */
    virtual eError Deallocate
    (TServletInterface& servlet) 
    {
        eError error = e_ERROR_NOT_IMPLEMENTED;
        return error;
    }
};
#undef CDB_CLASS

/**
 **********************************************************************
 *  Class: cServletWrapper
 *
 * Author: $author$
 *   Date: 2/29/2008
 **********************************************************************
 */
class cServletWrapper
: public cServletWrapperT
  <cServletInterface,cServletWrapperInterface,cServletBase>
{
public:
    typedef cServletWrapperT
    <cServletInterface,cServletWrapperInterface,cServletBase> cExtends;
    /**
     **********************************************************************
     * Constructor: cServletWrapper
     *
     *      Author: $author$
     *        Date: 2/29/2008
     **********************************************************************
     */
    cServletWrapper() 
    {
    }
};
#endif /* _CSERVLETWRAPPER_HXX */
