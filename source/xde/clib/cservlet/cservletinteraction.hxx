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
 *   File: cservletinteraction.hxx
 *
 * Author: $author$
 *   Date: 2/25/2008
 **********************************************************************
 */
#ifndef _CSERVLETINTERACTION_HXX
#define _CSERVLETINTERACTION_HXX

#include "cservletinteractioninterface.hxx"
#include "cservletbase.hxx"

#undef CDB_CLASS
#define CDB_CLASS "cServletInteractionT"
/**
 **********************************************************************
 *  Class: cServletInteractionT
 *
 * Author: $author$
 *   Date: 2/25/2008
 **********************************************************************
 */
template
<class TServletConnectionInterface=cServletConnectionInterface,
 class TImplements=cServletInteractionInterface,
 class TExtends=cServletBase>
 
class cServletInteractionT
: virtual public TImplements,
  public TExtends
{
public:
    typedef TImplements cImplements;
    typedef TExtends cExtends;
    typedef cServletInteractionT cDerives;

    TServletConnectionInterface* m_connection;

    /**
     **********************************************************************
     * Constructor: cServletInteractionT
     *
     *      Author: $author$
     *        Date: 2/25/2008
     **********************************************************************
     */
    cServletInteractionT
    (TServletConnectionInterface* connection=0) 
    : m_connection(connection)
    {
    }
    /**
     **********************************************************************
     * Destructor: cServletInteractionT
     *
     *     Author: $author$
     *       Date: 2/25/2008
     **********************************************************************
     */
    virtual ~cServletInteractionT()
    {
    }
    /**
     **********************************************************************
     * Function: SetConnection
     *
     *   Author: $author$
     *     Date: 2/26/2008
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
     *     Date: 2/26/2008
     **********************************************************************
     */
    virtual TServletConnectionInterface* GetConnection
    (eError& error) const 
    {
        error = e_ERROR_NONE;
        return m_connection;
    }
    /**
     **********************************************************************
     * Function: Connection
     *
     *   Author: $author$
     *     Date: 2/26/2008
     **********************************************************************
     */
    virtual TServletConnectionInterface& Connection() const 
    {
        TServletConnectionInterface* connection;
        eError error;
        if (!(connection = GetConnection(error)))
            throw(error);
        return *connection;
    }
};
#undef CDB_CLASS

/**
 **********************************************************************
 *  Class: cServletInteraction
 *
 * Author: $author$
 *   Date: 2/25/2008
 **********************************************************************
 */
class cServletInteraction
: public cServletInteractionT
  <cServletConnectionInterface,
   cServletInteractionInterface,cServletBase>
{
public:
    typedef cServletInteractionT
    <cServletConnectionInterface,
     cServletInteractionInterface,cServletBase> cExtends;
    /**
     **********************************************************************
     * Constructor: cServletInteraction
     *
     *      Author: $author$
     *        Date: 2/25/2008
     **********************************************************************
     */
    cServletInteraction
    (cServletConnectionInterface* connection=0) 
    : cExtends(connection) 
    {
    }
};
#endif /* _CSERVLETINTERACTION_HXX */
