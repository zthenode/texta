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
 *   File: cservletservice.hxx
 *
 * Author: $author$
 *   Date: 2/24/2008
 **********************************************************************
 */
#ifndef _CSERVLETSERVICE_HXX
#define _CSERVLETSERVICE_HXX

#include "cservletserviceinterface.hxx"
#include "cservletbase.hxx"

#undef CDB_CLASS
#define CDB_CLASS "cServletServiceT"
/**
 **********************************************************************
 *  Class: cServletServiceT
 *
 * Author: $author$
 *   Date: 2/24/2008
 **********************************************************************
 */
template
<class TServletConnectorInterface=cServletConnectorInterface,
 class TImplements=cServletServiceInterface,
 class TExtends=cServletBase>
 
class cServletServiceT
: virtual public TImplements,
  public TExtends
{
public:
    typedef TImplements cImplements;
    typedef TExtends cExtends;
    typedef cServletServiceT cDerives;
    /**
     **********************************************************************
     * Constructor: cServletServiceT
     *
     *      Author: $author$
     *        Date: 2/24/2008
     **********************************************************************
     */
    cServletServiceT() 
    {
    }
    /**
     **********************************************************************
     * Destructor: cServletServiceT
     *
     *     Author: $author$
     *       Date: 2/24/2008
     **********************************************************************
     */
    virtual ~cServletServiceT()
    {
    }
    /**
     **********************************************************************
     * Function: AddConnector
     *
     *   Author: $author$
     *     Date: 2/24/2008
     **********************************************************************
     */
    virtual eError AddConnector
    (TServletConnectorInterface& connector) 
    {
        eError error = e_ERROR_NONE;
        return error;
    }
    /**
     **********************************************************************
     * Function: RemoveConnector
     *
     *   Author: $author$
     *     Date: 2/24/2008
     **********************************************************************
     */
    virtual eError RemoveConnector
    (TServletConnectorInterface& connector) 
    {
        eError error = e_ERROR_NONE;
        return error;
    }
};
#undef CDB_CLASS

/**
 **********************************************************************
 *  Class: cServletService
 *
 * Author: $author$
 *   Date: 2/27/2008
 **********************************************************************
 */
class cServletService
: public cServletServiceT
  <cServletConnectorInterface,
   cServletServiceInterface,cServletBase>
{
public:
    typedef cServletServiceT
    <cServletConnectorInterface,
     cServletServiceInterface,cServletBase> cExtends;
    /**
     **********************************************************************
     * Constructor: cServletService
     *
     *      Author: $author$
     *        Date: 2/27/2008
     **********************************************************************
     */
    cServletService() 
    {
    }
};
#endif /* _CSERVLETSERVICE_HXX */
