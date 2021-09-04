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
 *   File: cservletresponse.hxx
 *
 * Author: $author$
 *   Date: 2/26/2008
 **********************************************************************
 */
#ifndef _CSERVLETRESPONSE_HXX
#define _CSERVLETRESPONSE_HXX

#include "cservletresponseinterface.hxx"
#include "cservletinteraction.hxx"

#undef CDB_CLASS
#define CDB_CLASS "cServletResponseT"
/**
 **********************************************************************
 *  Class: cServletResponseT
 *
 * Author: $author$
 *   Date: 2/26/2008
 **********************************************************************
 */
template
<class TServletConnectionInterface=cServletConnectionInterface,
 class TImplements=cServletResponseInterface,
 class TExtends=cServletInteraction>
 
class cServletResponseT
: virtual public TImplements,
  public TExtends
{
public:
    typedef TImplements cImplements;
    typedef TExtends cExtends;
    typedef cServletResponseT cDerives;
    /**
     **********************************************************************
     * Constructor: cServletResponseT
     *
     *      Author: $author$
     *        Date: 2/26/2008
     **********************************************************************
     */
    cServletResponseT
    (TServletConnectionInterface* connection=0) 
    : cExtends(connection) 
    {
    }
    /**
     **********************************************************************
     * Destructor: cServletResponseT
     *
     *     Author: $author$
     *       Date: 2/26/2008
     **********************************************************************
     */
    virtual ~cServletResponseT()
    {
    }
};

/**
 **********************************************************************
 *  Class: cServletResponse
 *
 * Author: $author$
 *   Date: 2/26/2008
 **********************************************************************
 */
class cServletResponse
: public cServletResponseT
  <cServletConnectionInterface,
   cServletResponseInterface,cServletInteraction>
{
public:
    typedef cServletResponseT
    <cServletConnectionInterface,
     cServletResponseInterface,cServletInteraction> cExtends;
    /**
     **********************************************************************
     * Constructor: cServletResponse
     *
     *      Author: $author$
     *        Date: 2/26/2008
     **********************************************************************
     */
    cServletResponse
    (cServletConnectionInterface* connection=0) 
    : cExtends(connection) 
    {
    }
};
#undef CDB_CLASS

#endif /* _CSERVLETRESPONSE_HXX */
