/**
 **********************************************************************
 * Copyright (c) 1988-2017 $organization$
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
 *   File: cxmlreaderinterface.hxx
 *
 * Author: $author$
 *   Date: 12/10/2017
 **********************************************************************
 */
#ifndef _CXMLREADERINTERFACE_HXX
#define _CXMLREADERINTERFACE_HXX

#include "cxmlnodeinterface.hxx"
#include "creaderinterface.hxx"
#include "cinstanceinterface.hxx"

typedef cReaderInterfaceT
<cXMLNodeReference,  
 TSIZE, TLENGTH, UNDEFINED_LENGTH, 
 cInterfaceBase> cXMLNodeReaderInterfaceImplements;
/**
 **********************************************************************
 *  Class: cXMLNodeReaderInterface
 *
 * Author: $author$
 *   Date: 3/15/2008
 **********************************************************************
 */
class c_INTERFACE_CLASS cXMLNodeReaderInterface
: virtual public cXMLNodeReaderInterfaceImplements
{
public:
    typedef cXMLNodeReaderInterfaceImplements cImplements;
};

typedef cReaderImplementT
<cXMLNodeReference, 
 TSIZE, TLENGTH, UNDEFINED_LENGTH, 
 cXMLNodeReaderInterface> cXMLNodeReaderImplementImplements;
/**
 **********************************************************************
 *  Class: cXMLNodeReaderImplement
 *
 * Author: $author$
 *   Date: 3/15/2008
 **********************************************************************
 */
class cXMLNodeReaderImplement
: virtual public cXMLNodeReaderImplementImplements
{
public:
    typedef cXMLNodeReaderImplementImplements cImplements;
};

/**
 **********************************************************************
 *  Class: cXMLReaderInterface
 *
 * Author: $author$
 *   Date: 3/15/2008
 **********************************************************************
 */
class c_INTERFACE_CLASS cXMLReaderInterface
: virtual public cXMLNodeReaderInterface,
  virtual public cInstanceInterface
{
public:
    typedef cXMLNodeReaderInterface cImplements;
    typedef cXMLReaderInterface cDerives;
    /**
     **********************************************************************
     * Function: Initialize
     *
     *   Author: $author$
     *     Date: 3/15/2008
     **********************************************************************
     */
    virtual eError Initialize() = 0;
    /**
     **********************************************************************
     * Function: Finalize
     *
     *   Author: $author$
     *     Date: 3/15/2008
     **********************************************************************
     */
    virtual eError Finalize() = 0;
    /**
     **********************************************************************
     * Function: OpenFile
     *
     *   Author: $author$
     *     Date: 3/15/2008
     **********************************************************************
     */
    virtual eError OpenFile
    (cCharWriterInterface& errors,
     const char* filename) = 0;
    /**
     **********************************************************************
     * Function: Close
     *
     *   Author: $author$
     *     Date: 3/15/2008
     **********************************************************************
     */
    virtual eError Close() = 0;
    /**
     **********************************************************************
     * Function: CreateInstance
     *
     *   Author: $author$
     *     Date: 3/15/2008
     **********************************************************************
     */
    static cXMLReaderInterface* 
    CreateInstance(eError& error);
    /**
     **********************************************************************
     * Function: DestroyInstance
     *
     *   Author: $author$
     *     Date: 3/15/2008
     **********************************************************************
     */
    static eError DestroyInstance
    (cXMLReaderInterface& instance);
};

/**
 **********************************************************************
 *  Class: cXMLReaderImplement
 *
 * Author: $author$
 *   Date: 12/10/2017
 **********************************************************************
 */
class cXMLReaderImplement
: virtual public cXMLReaderInterface
{
public:
    typedef cXMLReaderInterface cImplements;
    /**
     **********************************************************************
     * Function: Initialize
     *
     *   Author: $author$
     *     Date: 3/15/2008
     **********************************************************************
     */
    virtual eError Initialize()
    {
        return e_ERROR_NONE;
    }
    /**
     **********************************************************************
     * Function: Finalize
     *
     *   Author: $author$
     *     Date: 3/15/2008
     **********************************************************************
     */
    virtual eError Finalize()
    {
        return e_ERROR_NONE;
    }
    /**
     **********************************************************************
     * Function: OpenFile
     *
     *   Author: $author$
     *     Date: 3/15/2008
     **********************************************************************
     */
    virtual eError OpenFile
    (cCharWriterInterface& errors, const char* filename)
    {
        return e_ERROR_NONE;
    }
    /**
     **********************************************************************
     * Function: Close
     *
     *   Author: $author$
     *     Date: 3/15/2008
     **********************************************************************
     */
    virtual eError Close()
    {
        return e_ERROR_NONE;
    }
};

/**
 **********************************************************************
 *  Class: cXMLReaderBase
 *
 * Author: $author$
 *   Date: 12/10/2017
 **********************************************************************
 */
class cXMLReaderBase
: virtual public cXMLReaderImplement,
  public cInstanceBase
{
public:
    typedef cXMLReaderImplement cImplements;
    typedef cInstanceBase cExtends;
    /**
     **********************************************************************
     * Constructor: cXMLReaderBase
     *
     *      Author: $author$
     *        Date: 12/10/2017
     **********************************************************************
     */
    cXMLReaderBase()
    {
    }
    /**
     **********************************************************************
     * Destructor: ~cXMLReaderBase
     *
     *     Author: $author$
     *       Date: 12/10/2017
     **********************************************************************
     */
    virtual ~cXMLReaderBase()
    {
    }
};

#endif /* _CXMLREADERINTERFACE_HXX */

        

