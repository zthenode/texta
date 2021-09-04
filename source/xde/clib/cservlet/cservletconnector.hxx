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
 *   File: cservletconnector.hxx
 *
 * Author: $author$
 *   Date: 2/24/2008
 **********************************************************************
 */
#ifndef _CSERVLETCONNECTOR_HXX
#define _CSERVLETCONNECTOR_HXX

#include "cservletconnectorinterface.hxx"
#include "cservletbase.hxx"

#undef CDB_CLASS
#define CDB_CLASS "cServletConnectorT"
/**
 **********************************************************************
 *  Class: cServletConnectorT
 *
 * Author: $author$
 *   Date: 2/24/2008
 **********************************************************************
 */
template
<class TServletConnectionInterface=cServletConnectionInterface,
 class TImplements=cServletConnectorInterface,
 class TExtends=cServletBase>
 
class cServletConnectorT
: virtual public TImplements,
  public TExtends
{
public:
    typedef TImplements cImplements;
    typedef TExtends cExtends;
    typedef cServletConnectorT cDerives;

    TServletConnectionInterface* m_connection;

    /**
     **********************************************************************
     * Constructor: cServletConnectorT
     *
     *      Author: $author$
     *        Date: 2/24/2008
     **********************************************************************
     */
    cServletConnectorT
    (TServletConnectionInterface* connection=0) 
    : m_connection(connection)
    {
    }
    /**
     **********************************************************************
     * Destructor: cServletConnectorT
     *
     *     Author: $author$
     *       Date: 2/24/2008
     **********************************************************************
     */
    virtual ~cServletConnectorT()
    {
    }
    /**
     **********************************************************************
     * Function: SetConnection
     *
     *   Author: $author$
     *     Date: 2/27/2008
     **********************************************************************
     */
    virtual eError SetConnection
    (TServletConnectionInterface* connection) 
    {
        eError error = e_ERROR_NONE;
        m_connection = connection;
        return error;
    }
    /**
     **********************************************************************
     * Function: GetConnection
     *
     *   Author: $author$
     *     Date: 2/27/2008
     **********************************************************************
     */
    virtual TServletConnectionInterface* 
    GetConnection(eError& error) const 
    {
        error = e_ERROR_NONE;
        return m_connection;
    }
};
#undef CDB_CLASS

/**
 **********************************************************************
 *  Class: cServletConnector
 *
 * Author: $author$
 *   Date: 2/27/2008
 **********************************************************************
 */
class cServletConnector
: public cServletConnectorT
  <cServletConnectionInterface,
   cServletConnectorInterface,cServletBase>
{
public:
    typedef cServletConnectorT
    <cServletConnectionInterface,
     cServletConnectorInterface,cServletBase> cExtends;
    /**
     **********************************************************************
     * Constructor: cServletConnector
     *
     *      Author: $author$
     *        Date: 2/27/2008
     **********************************************************************
     */
    cServletConnector
    (cServletConnectionInterface* connection=0) 
    : cExtends(connection) 
    {
    }
};
#endif /* _CSERVLETCONNECTOR_HXX */
