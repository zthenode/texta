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
 *   File: cxmlprocessor.hxx
 *
 * Author: $author$
 *   Date: 12/12/2008
 **********************************************************************
 */
#ifndef _CXMLPROCESSOR_HXX
#define _CXMLPROCESSOR_HXX

#include "cxmlprocessorinterface.hxx"
#include "cxmlelementprocessorlist.hxx"
#include "cxmlelementnodeprocessor.hxx"
#include "cxmlprocessing.hxx"
#include "cxmlnodelist.hxx"

/**
 **********************************************************************
 *  Class: cXMLProcessor
 *
 * Author: $author$
 *   Date: 12/12/2008
 **********************************************************************
 */
class cXMLProcessor
: virtual public cXMLProcessorImplement,
  public cXMLProcessing
{
public:
    typedef cXMLProcessorImplement cImplements;
    typedef cXMLProcessing cExtends;
    typedef cXMLProcessor cDerives;

    cXMLString m_mode;
    cXMLNodeList m_result_xmlNodeList;

    /**
     **********************************************************************
     * Constructor: cXMLProcessor
     *
     *      Author: $author$
     *        Date: 12/12/2008
     **********************************************************************
     */
    cXMLProcessor() 
    {
    }
    /**
     **********************************************************************
     * Destructor: ~cXMLProcessor
     *
     *     Author: $author$
     *       Date: 12/12/2008
     **********************************************************************
     */
    virtual ~cXMLProcessor()
    {
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
    (const cXMLNodeListInterface& xmlNodeList) 
    {
        eError error = Process
        (m_result_xmlNodeList, xmlNodeList, m_mode);
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
        eError error = Process
        (m_result_xmlNodeList, xmlNodeList, mode);
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
        const cXMLString* xmlNodeName;
        const cXMLNodeInterface* xmlNode;
        cXMLElementNodeInterface* xmlElementNode;
        cXMLElementNodeProcessor* xmlElementNodeProccessor;

        for (xmlNode = xmlNodeList.FirstItem();
             xmlNode; xmlNode = xmlNode->NextSibling())
        {
            if ((xmlElementNode = xmlNode->ElementNodeInterface()))
            if ((xmlNodeName = xmlNode->LocalName()))
            if ((xmlElementNodeProccessor = 
                cXMLElementProcessorList::Find(*xmlNodeName, mode)))
            if ((error = xmlElementNodeProccessor->Process
                (*this, result_xmlNodeList, *xmlNode)))
            {
                cXMLStringToString nodeName(*xmlNodeName);
                DBE("() failed to process <%s> element\n",nodeName.c_str());
                break;
            }
        }
        return error;
    }
    /**
     **********************************************************************
     * Function: ProcessToStream
     *
     *   Author: $author$
     *     Date: 1/2/2009
     **********************************************************************
     */
    virtual eError ProcessToStream
    (cXMLCharStreamInterface& result_xmlStream,
     const cXMLNodeListInterface& xmlNodeList) 
    {
        eError error = ProcessToStream
        (result_xmlStream, xmlNodeList, m_mode);
        return error;
    }
    /**
     **********************************************************************
     * Function: ProcessToStream
     *
     *   Author: $author$
     *     Date: 1/2/2009
     **********************************************************************
     */
    virtual eError ProcessToStream
    (cXMLCharStreamInterface& result_xmlStream,
     const cXMLNodeListInterface& xmlNodeList,
     const cXMLString& mode) 
    {
        eError error = e_ERROR_NONE;
        const cXMLString* xmlNodeName;
        const cXMLNodeInterface* xmlNode;
        cXMLElementNodeInterface* xmlElementNode;
        cXMLElementNodeProcessor* xmlElementNodeProccessor;

        for (xmlNode = xmlNodeList.FirstItem();
             xmlNode; xmlNode = xmlNode->NextSibling())
        {
            if ((xmlElementNode = xmlNode->ElementNodeInterface()))
            {
                if ((xmlNodeName = xmlNode->LocalName()))
                if ((xmlElementNodeProccessor = 
                    cXMLElementProcessorList::Find(*xmlNodeName, mode)))
                if ((error = xmlElementNodeProccessor->ProcessToStream
                    (*this, result_xmlStream, *xmlNode)))
                {
                    cXMLStringToString nodeName(*xmlNodeName);
                    DBE("() failed to process <%s> element\n",nodeName.c_str());
                    break;
                }
            }
        }
        return error;
    }
    /**
     **********************************************************************
     * Function: MatchElementProcessor
     *
     *   Author: $author$
     *     Date: 12/14/2008
     **********************************************************************
     */
    virtual cXMLElementNodeProcessor* MatchElementProcessor
    (const cXMLString& match,
     const cXMLString& mode) const 
    {
        cXMLElementNodeProcessor* xmlElementNoderocessor 
        = cXMLElementProcessorList::Find(match, mode);
        return xmlElementNoderocessor;
    }
};
#endif /* _CXMLPROCESSOR_HXX */
