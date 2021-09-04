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
 *   File: cxmlnodetype.h
 *
 * Author: $author$
 *   Date: 11/4/2008
 **********************************************************************
 */
#ifndef _CXMLNODETYPE_H
#define _CXMLNODETYPE_H

#include "cplatform.h"

/**
 **********************************************************************
 *   Enum:  eXMLNodeType
 *
 * Author: $author$
 *   Date: 11/4/2008
 **********************************************************************
 */
typedef int 
eXMLNodeType;
enum
{
    e_XML_NODE_TYPE_ALL =  -1,
    e_XML_NODE_TYPE_FIRST = 0,

    e_XML_NODE_TYPE_NONE = e_XML_NODE_TYPE_FIRST,

    e_XML_NODE_TYPE_TEXT,
    e_XML_NODE_TYPE_COMMENT,
    e_XML_NODE_TYPE_ATTRIBUTE,
    e_XML_NODE_TYPE_ELEMENT,
    e_XML_NODE_TYPE_BEGIN_ELEMENT,
    e_XML_NODE_TYPE_END_ELEMENT,
    e_XML_NODE_TYPE_DATA,
    e_XML_NODE_TYPE_DOCUMENT,
    e_XML_NODE_TYPE_DOCUMENT_FRAGMENT,
    e_XML_NODE_TYPE_DOCUMENT_TYPE,
    e_XML_NODE_TYPE_CDATA,
    e_XML_NODE_TYPE_NOTATION,
    e_XML_NODE_TYPE_ENTITY,
    e_XML_NODE_TYPE_ENTITY_REFERENCE,
    e_XML_NODE_TYPE_PROCESSING_INSTRUCTION,

    e_XML_NODE_TYPE_NEXT,
    e_XML_NODE_TYPE_LAST = e_XML_NODE_TYPE_NEXT-1,
    e_XML_NODE_TYPE_COUNT = e_XML_NODE_TYPE_LAST-e_XML_NODE_TYPE_FIRST+1
};

/**
 **********************************************************************
 *   Enum:  eXMLNodeTypeValue
 *
 * Author: $author$
 *   Date: 11/4/2008
 **********************************************************************
 */
typedef eXMLNodeType 
eXMLNodeTypeValue;
enum
{
    e_XML_NODE_TYPE_VALUE_ALL = -1,
    e_XML_NODE_TYPE_VALUE_NONE = 0,

    e_XML_NODE_TYPE_VALUE_TEXT                   = (1 << (e_XML_NODE_TYPE_TEXT-1)),
    e_XML_NODE_TYPE_VALUE_COMMENT                = (1 << (e_XML_NODE_TYPE_COMMENT-1)),
    e_XML_NODE_TYPE_VALUE_ATTRIBUTE              = (1 << (e_XML_NODE_TYPE_ATTRIBUTE-1)),
    e_XML_NODE_TYPE_VALUE_ELEMENT                = (1 << (e_XML_NODE_TYPE_ELEMENT-1)),
    e_XML_NODE_TYPE_VALUE_BEGIN_ELEMENT          = (1 << (e_XML_NODE_TYPE_BEGIN_ELEMENT-1)),
    e_XML_NODE_TYPE_VALUE_END_ELEMENT            = (1 << (e_XML_NODE_TYPE_END_ELEMENT-1)),
    e_XML_NODE_TYPE_VALUE_DATA                   = (1 << (e_XML_NODE_TYPE_DATA-1)),
    e_XML_NODE_TYPE_VALUE_DOCUMENT               = (1 << (e_XML_NODE_TYPE_DOCUMENT-1)),
    e_XML_NODE_TYPE_VALUE_DOCUMENT_FRAGMENT      = (1 << (e_XML_NODE_TYPE_DOCUMENT_FRAGMENT-1)),
    e_XML_NODE_TYPE_VALUE_DOCUMENT_TYPE          = (1 << (e_XML_NODE_TYPE_DOCUMENT_TYPE-1)),
    e_XML_NODE_TYPE_VALUE_CDATA                  = (1 << (e_XML_NODE_TYPE_CDATA-1)),
    e_XML_NODE_TYPE_VALUE_NOTATION               = (1 << (e_XML_NODE_TYPE_NOTATION-1)),
    e_XML_NODE_TYPE_VALUE_ENTITY                 = (1 << (e_XML_NODE_TYPE_ENTITY-1)),
    e_XML_NODE_TYPE_VALUE_ENTITY_REFERENCE       = (1 << (e_XML_NODE_TYPE_ENTITY_REFERENCE-1)),
    e_XML_NODE_TYPE_VALUE_PROCESSING_INSTRUCTION = (1 << (e_XML_NODE_TYPE_PROCESSING_INSTRUCTION-1)),
};

#define e_XML_NODE_TYPE_NAME_NONE "NONE"
#define e_XML_NODE_TYPE_NAME_TEXT "TEXT"
#define e_XML_NODE_TYPE_NAME_COMMENT "COMMENT"
#define e_XML_NODE_TYPE_NAME_ATTRIBUTE "ATTRIBUTE"
#define e_XML_NODE_TYPE_NAME_ELEMENT "ELEMENT"
#define e_XML_NODE_TYPE_NAME_BEGIN_ELEMENT "BEGIN_ELEMENT"
#define e_XML_NODE_TYPE_NAME_END_ELEMENT "END_ELEMENT"
#define e_XML_NODE_TYPE_NAME_DATA "DATA"
#define e_XML_NODE_TYPE_NAME_DOCUMENT "DOCUMENT"
#define e_XML_NODE_TYPE_NAME_DOCUMENT_FRAGMENT "DOCUMENT_FRAGMENT"
#define e_XML_NODE_TYPE_NAME_DOCUMENT_TYPE "DOCUMENT_TYPE"
#define e_XML_NODE_TYPE_NAME_CDATA "CDATA"
#define e_XML_NODE_TYPE_NAME_NOTATION "NOTATION"
#define e_XML_NODE_TYPE_NAME_ENTITY "ENTITY"
#define e_XML_NODE_TYPE_NAME_ENTITY_REFERENCE "ENTITY_REFERENCE"
#define e_XML_NODE_TYPE_NAME_PROCESSING_INSTRUCTION "PROCESSING_INSTRUCTION"

#if defined(__cplusplus)
extern "C" {
#endif /* defined(__cplusplus) */

extern eXMLNodeType g_e_xml_node_type_value[e_XML_NODE_TYPE_COUNT];
extern const char* g_e_xml_node_type_name[e_XML_NODE_TYPE_COUNT];

/**
 **********************************************************************
 * Function: xml_node_type_index
 *
 *   Author: $author$
 *     Date: 12/2/2008
 **********************************************************************
 */
extern eXMLNodeType xml_node_type_index(eXMLNodeType nodeType);
/**
 **********************************************************************
 * Function: xml_node_type_name
 *
 *   Author: $author$
 *     Date: 12/2/2008
 **********************************************************************
 */
extern const char* xml_node_type_name(eXMLNodeType nodeType);
/**
 **********************************************************************
 * Function: xml_node_type_index_name
 *
 *   Author: $author$
 *     Date: 12/2/2008
 **********************************************************************
 */
extern const char* xml_node_type_index_name(eXMLNodeType nodeTypeIndex);

#if defined(__cplusplus)
}
#endif /* defined(__cplusplus) */

#endif /* _CXMLNODETYPE_H */
