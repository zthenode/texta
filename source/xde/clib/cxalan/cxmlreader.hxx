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
 *   File: cxmlreader.hxx
 *
 * Author: $author$
 *   Date: 3/15/2008
 **********************************************************************
 */
#ifndef _CXMLREADER_HXX
#define _CXMLREADER_HXX

#include "cxmlreaderinterface.hxx"
#include "cwriterinterface.hxx"
#include "cinstance.hxx"

/**
 **********************************************************************
 *  Class: cXMLReader
 *
 * Author: $author$
 *   Date: 3/15/2008
 **********************************************************************
 */
class cXMLReader
: virtual public cXMLReaderInterface,
  virtual public cXMLNodeReaderImplement,
  public cInstance
{
public:
    typedef cInstance cExtends;
    typedef cXMLReader cDerives;
    /**
     **********************************************************************
     * Constructor: cXMLReader
     *
     *      Author: $author$
     *        Date: 3/15/2008
     **********************************************************************
     */
    cXMLReader
    (bool isStaticInstance=true)
    : cExtends(isStaticInstance)
    {
    }
    /**
     **********************************************************************
     * Destructor: cXMLReader
     *
     *     Author: $author$
     *       Date: 3/15/2008
     **********************************************************************
     */
    virtual ~cXMLReader()
    {
    }
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
        eError error = e_ERROR_NONE;
        return error;
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
        eError error = e_ERROR_NONE;
        return error;
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
    (cCharWriterInterface& errors,
     const char* filename) 
    {
        eError error = e_ERROR_NOT_IMPLEMENTED;
        return error;
    }
    /**
     **********************************************************************
     * Function: Open
     *
     *   Author: $author$
     *     Date: 3/15/2008
     **********************************************************************
     */
    virtual eError Open
    (cCharWriterInterface& errors,
     cCharReaderInterface& input) 
    {
        eError error = e_ERROR_NOT_IMPLEMENTED;
        return error;
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
        eError error = e_ERROR_NOT_IMPLEMENTED;
        return error;
    }
};
#endif /* _CXMLREADER_HXX */
