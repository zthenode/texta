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
 *   File: cxmlreaderinterface.hxx
 *
 * Author: $author$
 *   Date: 3/15/2008
 **********************************************************************
 */
#ifndef _CXMLREADERINTERFACE_HXX
#define _CXMLREADERINTERFACE_HXX

#include "cxmlnodereader.hxx"
#include "cwriterinterface.hxx"
#include "cinstanceinterface.hxx"

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
#endif /* _CXMLREADERINTERFACE_HXX */
