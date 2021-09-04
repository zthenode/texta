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
 *   File: cservlet.hxx
 *
 * Author: $author$
 *   Date: 2/24/2008
 **********************************************************************
 */
#ifndef _CSERVLET_HXX
#define _CSERVLET_HXX

#include "cservletinterface.hxx"
#include "cservletbase.hxx"

#undef CDB_CLASS
#define CDB_CLASS "cServletT"
/**
 **********************************************************************
 *  Class: cServletT
 *
 * Author: $author$
 *   Date: 2/24/2008
 **********************************************************************
 */
template
<class TImplements=cServletInterface,
 class TServletRequestInterface=cServletRequestInterface,
 class TServletResponseInterface=cServletResponseInterface,
 class TServletConfigInterface=cServletConfigInterface,
 class TExtends=cServletBase>
 
class cServletT
: virtual public TImplements,
  public TExtends
{
public:
    typedef TImplements cImplements;
    typedef TExtends cExtends;
    typedef cServletT cDerives;
    /**
     **********************************************************************
     * Constructor: cServletT
     *
     *      Author: $author$
     *        Date: 2/24/2008
     **********************************************************************
     */
    cServletT() 
    {
    }
    /**
     **********************************************************************
     * Destructor: cServletT
     *
     *     Author: $author$
     *       Date: 2/24/2008
     **********************************************************************
     */
    virtual ~cServletT()
    {
    }
    /**
     **********************************************************************
     * Function: Initialize
     *
     *   Author: $author$
     *     Date: 2/24/2008
     **********************************************************************
     */
    virtual eError Initialize
    (TServletConfigInterface& config) 
    {
        eError error = e_ERROR_NOT_IMPLEMENTED;
        return error;
    }
    /**
     **********************************************************************
     * Function: Finalize
     *
     *   Author: $author$
     *     Date: 2/24/2008
     **********************************************************************
     */
    virtual eError Finalize
    (TServletConfigInterface& config) 
    {
        eError error = e_ERROR_NOT_IMPLEMENTED;
        return error;
    }
    /**
     **********************************************************************
     * Function: Service
     *
     *   Author: $author$
     *     Date: 2/24/2008
     **********************************************************************
     */
    virtual eError Service
    (TServletRequestInterface& request,
     TServletResponseInterface& response) 
    {
        eError error = e_ERROR_NOT_IMPLEMENTED;
        return error;
    }
};
#undef CDB_CLASS

/**
 **********************************************************************
 *  Class: cServlet
 *
 * Author: $author$
 *   Date: 2/28/2008
 **********************************************************************
 */
class cServlet
: public cServletT
  <cServletInterface,
   cServletRequestInterface,
   cServletResponseInterface,
   cServletConfigInterface,
   cServletBase>
{
public:
    typedef cServletT
    <cServletInterface,
     cServletRequestInterface,
     cServletResponseInterface,
     cServletConfigInterface,
     cServletBase> cExtends;
    /**
     **********************************************************************
     * Constructor: cServlet
     *
     *      Author: $author$
     *        Date: 2/28/2008
     **********************************************************************
     */
    cServlet() 
    {
    }
};
#endif /* _CSERVLET_HXX */
