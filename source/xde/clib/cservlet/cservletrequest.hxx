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
 *   File: cservletrequest.hxx
 *
 * Author: $author$
 *   Date: 2/26/2008
 **********************************************************************
 */
#ifndef _CSERVLETREQUEST_HXX
#define _CSERVLETREQUEST_HXX

#include "cservletrequestinterface.hxx"
#include "cservletinteraction.hxx"

#undef CDB_CLASS
#define CDB_CLASS "cServletRequestT"
/**
 **********************************************************************
 *  Class: cServletRequestT
 *
 * Author: $author$
 *   Date: 2/26/2008
 **********************************************************************
 */
template
<class TReaderInterface=cReaderInterface,
 class TServletConnectionInterface=cServletConnectionInterface,
 class TImplements=cServletRequestInterface,
 class TExtends=cServletInteraction>
 
class cServletRequestT
: virtual public TImplements,
  public TExtends
{
public:
    typedef TImplements cImplements;
    typedef TExtends cExtends;
    typedef cServletRequestT cDerives;

    TReaderInterface* m_reader;

    /**
     **********************************************************************
     * Constructor: cServletRequestT
     *
     *      Author: $author$
     *        Date: 2/26/2008
     **********************************************************************
     */
    cServletRequestT
    (TReaderInterface* reader=0,
     TServletConnectionInterface* connection=0) 
    : cExtends(connection),
      m_reader(reader)
    {
    }
    /**
     **********************************************************************
     * Destructor: cServletRequestT
     *
     *     Author: $author$
     *       Date: 2/26/2008
     **********************************************************************
     */
    virtual ~cServletRequestT()
    {
    }
    /**
     **********************************************************************
     * Function: SetReader
     *
     *   Author: $author$
     *     Date: 2/29/2008
     **********************************************************************
     */
    virtual eError SetReader(TReaderInterface* reader) 
    {
        eError error = e_ERROR_NONE;
        m_reader = reader;
        return error;
    }
    /**
     **********************************************************************
     * Function: GetReader
     *
     *   Author: $author$
     *     Date: 2/29/2008
     **********************************************************************
     */
    virtual TReaderInterface* GetReader(eError& error) const 
    {
        error = e_ERROR_NONE;
        return m_reader;
    }
    /**
     **********************************************************************
     * Function: Reader
     *
     *   Author: $author$
     *     Date: 2/29/2008
     **********************************************************************
     */
    virtual TReaderInterface& Reader() const 
    {
        eError error = e_ERROR_FAILED;
        TReaderInterface* reader;
        if (!(reader = GetReader(error)))
            throw(error);
        return *reader;
    }
};
#undef CDB_CLASS

/**
 **********************************************************************
 *  Class: cServletRequest
 *
 * Author: $author$
 *   Date: 2/26/2008
 **********************************************************************
 */
class cServletRequest
: public cServletRequestT
  <cReaderInterface, cServletConnectionInterface,
   cServletRequestInterface,cServletInteraction>
{
public:
    typedef cServletRequestT
    <cReaderInterface, cServletConnectionInterface,
     cServletRequestInterface,cServletInteraction> cExtends;
    /**
     **********************************************************************
     * Constructor: cServletRequest
     *
     *      Author: $author$
     *        Date: 2/26/2008
     **********************************************************************
     */
    cServletRequest
    (cReaderInterface* reader=0,
     cServletConnectionInterface* connection=0) 
    : cExtends(reader,connection) 
    {
    }
};
#endif /* _CSERVLETREQUEST_HXX */
