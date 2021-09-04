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
 *   File: cxmlnodeprocessor.hxx
 *
 * Author: $author$
 *   Date: 12/12/2008
 **********************************************************************
 */
#ifndef _CXMLNODEPROCESSOR_HXX
#define _CXMLNODEPROCESSOR_HXX

#include "cxmlprocessorinterface.hxx"
#include "cxmlprocessing.hxx"
#include "cxmlnodelist.hxx"
#include "cxmlentityreferencenodeinterface.hxx"
#include "cxmltextnodeinterface.hxx"
#include "cxmlstringtostring.hxx"
#include "cdebug.hxx"

/**
 **********************************************************************
 *  Class: cXMLNodeProcessor
 *
 * Author: $author$
 *   Date: 12/12/2008
 **********************************************************************
 */
class cXMLNodeProcessor
: public cXMLProcessing
{
public:
    typedef cXMLProcessing cExtends;
    typedef cXMLNodeProcessor cDerives;

    cXMLString m_mode;
    cXMLString m_childMode;

    /**
     **********************************************************************
     * Constructor: cXMLNodeProcessor
     *
     *      Author: $author$
     *        Date: 12/12/2008
     **********************************************************************
     */
    cXMLNodeProcessor
    (const char* mode=0,
     const char* childMode=0) 
    {
        eError error;
        TLENGTH length;

        if (mode)
        if (0 > (length = m_mode.Appendc(mode)))
            throw(error = -length);

        if (childMode)
        if (0 > (length = m_childMode.Appendc(childMode)))
            throw(error = -length);
    }
    /**
     **********************************************************************
     * Destructor: ~cXMLNodeProcessor
     *
     *     Author: $author$
     *       Date: 12/12/2008
     **********************************************************************
     */
    virtual ~cXMLNodeProcessor()
    {
    }
    /**
     **********************************************************************
     * Function: Process
     *
     *   Author: $author$
     *     Date: 1/2/2009
     **********************************************************************
     */
    virtual eError Process
    (cXMLProcessorInterface& xmlProcessor,
     cXMLNodeListInterface& result_xmlNodeList,
     const cXMLNodeInterface& xmlNode) const
    {
        eError error = e_ERROR_NONE;
        
        error = ProcessChildren
        (xmlProcessor, result_xmlNodeList, xmlNode);
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
    (cXMLProcessorInterface& xmlProcessor,
     cXMLCharStreamInterface& result_xmlStream,
     const cXMLNodeInterface& xmlNode) const
    {
        eError error = e_ERROR_NONE;
        const cXMLTextNodeInterface* xmlTextNode;
        const cXMLEntityReferenceNodeInterface* xmlEntityReferenceNode;
        const cXMLEntityNodeInterface* xmlEntityNode;
        const cXMLChar* xmlChars;
        TLENGTH length;
        
        if ((xmlTextNode = xmlNode.TextNodeInterface()))
        {
            if ((xmlChars = xmlTextNode->DataChars(length)))
            {
                TLENGTH count;
                const char* chars;
                cXMLStringToString xmlStringToString;

                if (0 < (count = xmlStringToString.AssignXMLCh(xmlChars, length)))
                if ((chars = xmlStringToString.Chars(count)))
                    DBT("() dataChars = \"%s\"\n", chars);

                result_xmlStream.Write(xmlChars, length);
            }
        }
        else
        if ((xmlEntityReferenceNode = xmlNode.EntityReferenceNodeInterface()))
        {
            if ((xmlEntityNode = xmlEntityReferenceNode->ReferencedEntityNode()))
                error = ProcessChildrenToStream
                (xmlProcessor, result_xmlStream, *xmlEntityNode);
        }
        else
        error = ProcessChildrenToStream
        (xmlProcessor, result_xmlStream, xmlNode);
        return error;
    }
    /**
     **********************************************************************
     * Function: ProcessChildren
     *
     *   Author: $author$
     *     Date: 1/2/2009
     **********************************************************************
     */
    virtual eError ProcessChildren
    (cXMLProcessorInterface& xmlProcessor,
     cXMLNodeListInterface& result_xmlNodeList,
     const cXMLNodeInterface& xmlNode) const
    {
        const cXMLString& childMode 
        = (0 < m_childMode.Length())?m_childMode:m_mode;
        eError error = e_ERROR_NONE;
        const cXMLNodeInterface* child_xmlNode;
        const cXMLElementNodeInterface* child_xmlElementNode;
        const cXMLString* child_xmlNodeName;
        cXMLNodeProcessor* xmlNodeProcessor;

        for (child_xmlNode = xmlNode.FirstChild();
             child_xmlNode; child_xmlNode = child_xmlNode->NextSibling())
        {
            if ((child_xmlElementNode = child_xmlNode->ElementNodeInterface()))
            {
                if ((child_xmlNodeName = child_xmlElementNode->LocalName()))
                if ((xmlNodeProcessor = xmlProcessor.MatchElementProcessor
                    (*child_xmlNodeName, childMode)))
                if ((error = xmlNodeProcessor->Process
                    (xmlProcessor, result_xmlNodeList, *child_xmlNode)))
                {
                    cXMLStringToString nodeName(*child_xmlNodeName);
                    DBE("() failed to process <%s> element\n",nodeName.c_str());
                    break;
                }
            }
            else
            if ((error = Process
                (xmlProcessor, result_xmlNodeList, *child_xmlNode)))
            {
                DBE("() failed to process child node\n");
                break;
            }
        }
        return error;
    }
    /**
     **********************************************************************
     * Function: ProcessChildrenToStream
     *
     *   Author: $author$
     *     Date: 1/2/2009
     **********************************************************************
     */
    virtual eError ProcessChildrenToStream
    (cXMLProcessorInterface& xmlProcessor,
     cXMLCharStreamInterface& result_xmlStream,
     const cXMLNodeInterface& xmlNode) const
    {
        const cXMLString& childMode 
        = (0 < m_childMode.Length())?m_childMode:m_mode;
        eError error = e_ERROR_NONE;
        const cXMLNodeInterface* child_xmlNode;
        const cXMLElementNodeInterface* child_xmlElementNode;
        const cXMLString* child_xmlNodeName;
        cXMLNodeProcessor* xmlNodeProcessor;

        for (child_xmlNode = xmlNode.FirstChild();
             child_xmlNode; child_xmlNode = child_xmlNode->NextSibling())
        {
            TLENGTH count;
            const char* chars;
            const cXMLString* xmlNodeTypeName;
            cXMLStringToString xmlStringToString;

            if ((xmlNodeTypeName = child_xmlNode->NodeTypeName()))
            if (0 < (count = xmlStringToString.AssignXML(*xmlNodeTypeName)))
            if ((chars = xmlStringToString.Chars(count)))
                DBT("() nodeType = \"%s\"\n", chars);

            if ((child_xmlElementNode = child_xmlNode->ElementNodeInterface()))
            {
                if ((child_xmlNodeName = child_xmlElementNode->LocalName()))
                if ((xmlNodeProcessor = xmlProcessor.MatchElementProcessor
                    (*child_xmlNodeName, childMode)))
                if ((error = xmlNodeProcessor->ProcessToStream
                    (xmlProcessor, result_xmlStream, *child_xmlNode)))
                {
                    cXMLStringToString nodeName(*child_xmlNodeName);
                    DBE("() failed to process <%s> element\n",nodeName.c_str());
                    break;
                }
            }
            else
            if ((error = ProcessToStream
                (xmlProcessor, result_xmlStream, *child_xmlNode)))
            {
                DBE("() failed to process child node\n");
                break;
            }
        }
        return error;
    }
};
#endif /* _CXMLNODEPROCESSOR_HXX */
