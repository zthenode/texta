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
 *   File: cxmlnodetype.hxx
 *
 * Author: $author$
 *   Date: 11/4/2008
 **********************************************************************
 */
#ifndef _CXMLNODETYPE_HXX
#define _CXMLNODETYPE_HXX

#include "cxmlnodetype.h"
#include "cxmlstring.hxx"

/**
 **********************************************************************
 *  Class: cXMLNodeType
 *
 * Author: $author$
 *   Date: 12/2/2008
 **********************************************************************
 */
class cXMLNodeType
{
public:
    typedef cXMLNodeType cDerives;

    static cXMLString m_nodeTypeName[e_XML_NODE_TYPE_COUNT];

    /**
     **********************************************************************
     * Function: NodeTypeName
     *
     *   Author: $author$
     *     Date: 12/2/2008
     **********************************************************************
     */
    static const cXMLString* NodeTypeName
    (eXMLNodeType nodeType) 
    {
        eXMLNodeType nodeTypeIndex = xml_node_type_index(nodeType);
        cXMLString* xmlString = 0;
        const cXMLChar* xmlChars;
        const char* chars;
        TLENGTH length;

        if ((chars = xml_node_type_index_name(nodeTypeIndex)))
        if ((xmlString = m_nodeTypeName+nodeTypeIndex))
        {
            if (!(xmlChars = xmlString->HasChars(length)))
            if (0 >= (length = xmlString->Assignc(chars)))
                xmlString = 0;
        }
        return xmlString;
    }
};

#endif /* _CXMLNODETYPE_HXX */
