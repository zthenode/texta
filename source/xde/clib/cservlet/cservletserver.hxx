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
 *   File: cservletserver.hxx
 *
 * Author: $author$
 *   Date: 2/24/2008
 **********************************************************************
 */
#ifndef _CSERVLETSERVER_HXX
#define _CSERVLETSERVER_HXX

#include "cservletserverinterface.hxx"
#include "cservletbase.hxx"

#undef CDB_CLASS
#define CDB_CLASS "cServletServerT"
/**
 **********************************************************************
 *  Class: cServletServerT
 *
 * Author: $author$
 *   Date: 2/24/2008
 **********************************************************************
 */
template
<class TServletServiceInterface=cServletServiceInterface,
 class TImplements=cServletServerInterface,
 class TExtends=cServletBase>
 
class cServletServerT
: virtual public TImplements,
  public TExtends
{
public:
    typedef TImplements cImplements;
    typedef TExtends cExtends;
    typedef cServletServerT cDerives;
    /**
     **********************************************************************
     * Constructor: cServletServerT
     *
     *      Author: $author$
     *        Date: 2/24/2008
     **********************************************************************
     */
    cServletServerT() 
    {
    }
    /**
     **********************************************************************
     * Destructor: cServletServerT
     *
     *     Author: $author$
     *       Date: 2/24/2008
     **********************************************************************
     */
    virtual ~cServletServerT()
    {
    }
    /**
     **********************************************************************
     * Function: AddService
     *
     *   Author: $author$
     *     Date: 2/24/2008
     **********************************************************************
     */
    virtual eError AddService
    (TServletServiceInterface& service) 
    {
        eError error = e_ERROR_NONE;
        return error;
    }
    /**
     **********************************************************************
     * Function: RemoveService
     *
     *   Author: $author$
     *     Date: 2/24/2008
     **********************************************************************
     */
    virtual eError RemoveService
    (TServletServiceInterface& service) 
    {
        eError error = e_ERROR_NONE;
        return error;
    }
};
#undef CDB_CLASS

/**
 **********************************************************************
 *  Class: cServletServer
 *
 * Author: $author$
 *   Date: 2/27/2008
 **********************************************************************
 */
class cServletServer
: public cServletServerT
  <cServletServiceInterface,
   cServletServerInterface,cServletBase>
{
public:
    typedef cServletServerT
    <cServletServiceInterface,
     cServletServerInterface,cServletBase> cExtends;
    /**
     **********************************************************************
     * Constructor: cServletServer
     *
     *      Author: $author$
     *        Date: 2/27/2008
     **********************************************************************
     */
    cServletServer() 
    {
    }
};
#endif /* _CSERVLETSERVER_HXX */
