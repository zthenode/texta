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
 *   File: cservletconnection.hxx
 *
 * Author: $author$
 *   Date: 2/24/2008
 **********************************************************************
 */
#ifndef _CSERVLETCONNECTION_HXX
#define _CSERVLETCONNECTION_HXX

#include "cservletconnectioninterface.hxx"
#include "cservletbase.hxx"
#include "cstream.hxx"

#undef CDB_CLASS
#define CDB_CLASS "cServletConnectionT"
/**
 **********************************************************************
 *  Class: cServletConnectionT
 *
 * Author: $author$
 *   Date: 2/24/2008
 **********************************************************************
 */
template
<class TServletConnectorInterface=cServletConnectorInterface,
 class TReaderInterface=cReaderInterface,
 class TWriterInterface=cWriterInterface,
 class TImplements=cServletConnectionInterface,
 class TExtends=cServletBase>
 
class cServletConnectionT
: virtual public TImplements,
  public TExtends
{
public:
    typedef TImplements cImplements;
    typedef TExtends cExtends;
    typedef cServletConnectionT cDerives;

    bool m_keepAlive;

    /**
     **********************************************************************
     * Constructor: cServletConnectionT
     *
     *      Author: $author$
     *        Date: 2/24/2008
     **********************************************************************
     */
    cServletConnectionT
    (bool keepAlive=false) 
    : m_keepAlive(keepAlive)
    {
    }
    /**
     **********************************************************************
     * Destructor: cServletConnectionT
     *
     *     Author: $author$
     *       Date: 2/24/2008
     **********************************************************************
     */
    virtual ~cServletConnectionT()
    {
    }
    /**
     **********************************************************************
     * Function: SetKeepAlive
     *
     *   Author: $author$
     *     Date: 2/24/2008
     **********************************************************************
     */
    virtual int SetKeepAlive
    (bool on=true) 
    {
        int ion = (false != (m_keepAlive = on));
        return ion;
    }
    /**
     **********************************************************************
     * Function: GetKeepAlive
     *
     *   Author: $author$
     *     Date: 2/24/2008
     **********************************************************************
     */
    virtual bool GetKeepAlive() const 
    {
        bool on = m_keepAlive;
        return on;
    }
};
#undef CDB_CLASS

/**
 **********************************************************************
 *  Class: cServletConnection
 *
 * Author: $author$
 *   Date: 2/25/2008
 **********************************************************************
 */
class cServletConnection
: public cServletConnectionT
  <cServletConnectorInterface,
   cReaderInterface,cWriterInterface,
   cServletConnectionInterface,cServletBase>
{
public:
    typedef cServletConnectionT
    <cServletConnectorInterface,
     cReaderInterface,cWriterInterface,
     cServletConnectionInterface,cServletBase> cExtends;
    /**
     **********************************************************************
     * Constructor: cServletConnection
     *
     *      Author: $author$
     *        Date: 2/25/2008
     **********************************************************************
     */
    cServletConnection
    (bool keepAlive=false) 
    : cExtends(keepAlive) 
    {
    }
};
#endif /* _CSERVLETCONNECTION_HXX */
