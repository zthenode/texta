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
 *   File: cservletrequestinterface.hxx
 *
 * Author: $author$
 *   Date: 2/23/2008
 **********************************************************************
 */
#ifndef _CSERVLETREQUESTINTERFACE_HXX
#define _CSERVLETREQUESTINTERFACE_HXX

#include "cservletinteractioninterface.hxx"
#include "creaderinterface.hxx"

#undef CDB_CLASS
#define CDB_CLASS "cServletRequestInterfaceT"
/**
 **********************************************************************
 *  Class: cServletRequestInterfaceT
 *
 * Author: $author$
 *   Date: 2/23/2008
 **********************************************************************
 */
template
<class TReaderInterface=cReaderInterface,
 class TImplements=cServletInteractionInterface>
 
class c_INTERFACE_CLASS cServletRequestInterfaceT
: virtual public TImplements
{
public:
    typedef TImplements cImplements;
    typedef cServletRequestInterfaceT cDerives;
    /**
     **********************************************************************
     * Function: SetReader
     *
     *   Author: $author$
     *     Date: 2/29/2008
     **********************************************************************
     */
    virtual eError SetReader(TReaderInterface* reader) = 0;
    /**
     **********************************************************************
     * Function: GetReader
     *
     *   Author: $author$
     *     Date: 2/29/2008
     **********************************************************************
     */
    virtual TReaderInterface* GetReader(eError& error) const = 0;
    /**
     **********************************************************************
     * Function: Reader
     *
     *   Author: $author$
     *     Date: 2/29/2008
     **********************************************************************
     */
    virtual TReaderInterface& Reader() const = 0;
};
#undef CDB_CLASS

/**
 **********************************************************************
 *  Class: cServletRequestInterface
 *
 * Author: $author$
 *   Date: 2/26/2008
 **********************************************************************
 */
class c_INTERFACE_CLASS cServletRequestInterface
: virtual public cServletRequestInterfaceT
  <cReaderInterface,cServletInteractionInterface>
{
public:
    typedef cServletRequestInterfaceT
    <cReaderInterface,cServletInteractionInterface> cImplements;
};
#endif /* _CSERVLETREQUESTINTERFACE_HXX */
