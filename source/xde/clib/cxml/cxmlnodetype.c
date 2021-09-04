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
 *   File: cxmlnodetype.c
 *
 * Author: $author$
 *   Date: 11/4/2008
 **********************************************************************
 */
#include "cxmlnodetype.h"

eXMLNodeType g_e_xml_node_type_value[e_XML_NODE_TYPE_COUNT] = 
{
    e_XML_NODE_TYPE_VALUE_NONE,
    e_XML_NODE_TYPE_VALUE_TEXT,
    e_XML_NODE_TYPE_VALUE_COMMENT,
    e_XML_NODE_TYPE_VALUE_ATTRIBUTE,
    e_XML_NODE_TYPE_VALUE_ELEMENT,
    e_XML_NODE_TYPE_VALUE_BEGIN_ELEMENT,
    e_XML_NODE_TYPE_VALUE_END_ELEMENT,
    e_XML_NODE_TYPE_VALUE_DATA,
    e_XML_NODE_TYPE_VALUE_DOCUMENT,
    e_XML_NODE_TYPE_VALUE_DOCUMENT_FRAGMENT,
    e_XML_NODE_TYPE_VALUE_DOCUMENT_TYPE,
    e_XML_NODE_TYPE_VALUE_CDATA,
    e_XML_NODE_TYPE_VALUE_NOTATION,
    e_XML_NODE_TYPE_VALUE_ENTITY,
    e_XML_NODE_TYPE_VALUE_ENTITY_REFERENCE,
    e_XML_NODE_TYPE_VALUE_PROCESSING_INSTRUCTION
};

const char* g_e_xml_node_type_name[e_XML_NODE_TYPE_COUNT] = 
{
    e_XML_NODE_TYPE_NAME_NONE,
    e_XML_NODE_TYPE_NAME_TEXT,
    e_XML_NODE_TYPE_NAME_COMMENT,
    e_XML_NODE_TYPE_NAME_ATTRIBUTE,
    e_XML_NODE_TYPE_NAME_ELEMENT,
    e_XML_NODE_TYPE_NAME_BEGIN_ELEMENT,
    e_XML_NODE_TYPE_NAME_END_ELEMENT,
    e_XML_NODE_TYPE_NAME_DATA,
    e_XML_NODE_TYPE_NAME_DOCUMENT,
    e_XML_NODE_TYPE_NAME_DOCUMENT_FRAGMENT,
    e_XML_NODE_TYPE_NAME_DOCUMENT_TYPE,
    e_XML_NODE_TYPE_NAME_CDATA,
    e_XML_NODE_TYPE_NAME_NOTATION,
    e_XML_NODE_TYPE_NAME_ENTITY,
    e_XML_NODE_TYPE_NAME_ENTITY_REFERENCE,
    e_XML_NODE_TYPE_NAME_PROCESSING_INSTRUCTION
};

/**
 **********************************************************************
 * Function: xml_node_type_index
 *
 *   Author: $author$
 *     Date: 12/2/2008
 **********************************************************************
 */
eXMLNodeType xml_node_type_index(eXMLNodeType nodeType) 
{
    eXMLNodeType nodeTypeIndex;
    for (nodeTypeIndex = e_XML_NODE_TYPE_NONE; 
         nodeTypeIndex < e_XML_NODE_TYPE_NEXT; nodeTypeIndex++)
    {
         if (nodeType != g_e_xml_node_type_value[nodeTypeIndex])
             continue;
         return nodeTypeIndex;
    }
    return e_XML_NODE_TYPE_ALL;
}

/**
 **********************************************************************
 * Function: xml_node_type_name
 *
 *   Author: $author$
 *     Date: 12/2/2008
 **********************************************************************
 */
const char* xml_node_type_name(eXMLNodeType nodeType) 
{
    eXMLNodeType nodeTypeIndex = xml_node_type_index(nodeType);
    const char* name = xml_node_type_index_name(nodeTypeIndex);
    return name;
}

/**
 **********************************************************************
 * Function: xml_node_type_index_name
 *
 *   Author: $author$
 *     Date: 12/2/2008
 **********************************************************************
 */
const char* xml_node_type_index_name(eXMLNodeType nodeTypeIndex) 
{
    const char* name = 0;
    if ((e_XML_NODE_TYPE_FIRST <= (nodeTypeIndex))
        && (e_XML_NODE_TYPE_LAST >= (nodeTypeIndex)))
         name = g_e_xml_node_type_name[nodeTypeIndex];
    return name;
}
