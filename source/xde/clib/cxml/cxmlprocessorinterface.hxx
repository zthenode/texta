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
 *   File: cxmlprocessorinterface.hxx
 *
 * Author: $author$
 *   Date: 12/12/2008
 **********************************************************************
 */
#ifndef _CXMLPROCESSORINTERFACE_HXX
#define _CXMLPROCESSORINTERFACE_HXX

#include "cxmlelementnodeinterface.hxx"
#include "cxmlnodeinterface.hxx"

class cXMLNodeProcessor;

/**
 **********************************************************************
 *  Class: cXMLProcessorInterface
 *
 * Author: $author$
 *   Date: 12/12/2008
 **********************************************************************
 */
class c_INTERFACE_CLASS cXMLProcessorInterface
: virtual public cInterfaceBase
{
public:
    typedef cInterfaceBase cImplements;
    typedef cXMLProcessorInterface cDerives;
    /**
     **********************************************************************
     * Function: Process
     *
     *   Author: $author$
     *     Date: 12/13/2008
     **********************************************************************
     */
    virtual eError Process
    (const cXMLNodeListInterface& xmlNodeList) = 0;
    /**
     **********************************************************************
     * Function: Process
     *
     *   Author: $author$
     *     Date: 12/13/2008
     **********************************************************************
     */
    virtual eError Process
    (const cXMLNodeListInterface& xmlNodeList,
     const cXMLString& mode) = 0;
    /**
     **********************************************************************
     * Function: Process
     *
     *   Author: $author$
     *     Date: 12/13/2008
     **********************************************************************
     */
    virtual eError Process
    (cXMLNodeListInterface& result_xmlNodeList,
     const cXMLNodeListInterface& xmlNodeList,
     const cXMLString& mode) = 0;
    /**
     **********************************************************************
     * Function: MatchElementProcessor
     *
     *   Author: $author$
     *     Date: 12/12/2008
     **********************************************************************
     */
    virtual cXMLNodeProcessor* MatchElementProcessor
    (const cXMLString& match,
     const cXMLString& mode) const = 0;
};

/**
 **********************************************************************
 *  Class: cXMLProcessorImplement
 *
 * Author: $author$
 *   Date: 12/12/2008
 **********************************************************************
 */
class cXMLProcessorImplement
: virtual public cXMLProcessorInterface
{
public:
    typedef cXMLProcessorInterface cImplements;
    typedef cXMLProcessorImplement cDerives;
    /**
     **********************************************************************
     * Function: Process
     *
     *   Author: $author$
     *     Date: 12/13/2008
     **********************************************************************
     */
    virtual eError Process
    (const cXMLNodeListInterface& xmlNodeList) 
    {
        eError error = e_ERROR_NONE;
        return error;
    }
    /**
     **********************************************************************
     * Function: Process
     *
     *   Author: $author$
     *     Date: 12/13/2008
     **********************************************************************
     */
    virtual eError Process
    (const cXMLNodeListInterface& xmlNodeList,
     const cXMLString& mode) 
    {
        eError error = e_ERROR_NONE;
        return error;
    }
    /**
     **********************************************************************
     * Function: Process
     *
     *   Author: $author$
     *     Date: 12/13/2008
     **********************************************************************
     */
    virtual eError Process
    (cXMLNodeListInterface& result_xmlNodeList,
     const cXMLNodeListInterface& xmlNodeList,
     const cXMLString& mode) 
    {
        eError error = e_ERROR_NONE;
        return error;
    }
    /**
     **********************************************************************
     * Function: MatchElementProcessor
     *
     *   Author: $author$
     *     Date: 12/12/2008
     **********************************************************************
     */
    virtual cXMLNodeProcessor* MatchElementProcessor
    (const cXMLString& match,
     const cXMLString& mode) const 
    {
        cXMLNodeProcessor* xmlNoderocessor = 0;
        return xmlNoderocessor;
    }
}; 
#endif /* _CXMLPROCESSORINTERFACE_HXX */
