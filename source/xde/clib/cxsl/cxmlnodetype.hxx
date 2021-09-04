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
 *   File: cxmlnodetype.hxx
 *
 * Author: $author$
 *   Date: 12/10/2017
 **********************************************************************
 */
#ifndef _CXMLNODETYPE_HXX
#define _CXMLNODETYPE_HXX

#include "cinterfacebase.hxx"

/**
 **********************************************************************
 *   Enum:  eXMLNodeType
 *
 * Author: $author$
 *   Date: 3/15/2008
 **********************************************************************
 */
typedef int 
eXMLNodeType;
enum
{
    e_FIRST_XML_NODE_TYPE = 0,

    e_XML_NODE_TYPE_NONE = e_FIRST_XML_NODE_TYPE,
    e_XML_NODE_TYPE_ELEMENT,
    e_XML_NODE_TYPE_ATTRIBUTE,
    e_XML_NODE_TYPE_TEXT,
    e_XML_NODE_TYPE_CDATA_SECTION,
    e_XML_NODE_TYPE_ENTITY_REFERENCE,
    e_XML_NODE_TYPE_ENTITY,
    e_XML_NODE_TYPE_PROCESSING_INSTRUCTION,
    e_XML_NODE_TYPE_COMMENT,
    e_XML_NODE_TYPE_DOCUMENT,
    e_XML_NODE_TYPE_DOCUMENT_TYPE,
    e_XML_NODE_TYPE_DOCUMENT_FRAGMENT,
    e_XML_NODE_TYPE_NOTATION,

    e_NEXT_XML_NODE_TYPE,
    e_LAST_XML_NODE_TYPE = e_NEXT_XML_NODE_TYPE-1,
    e_COUNT_XML_NODE_TYPE = e_LAST_XML_NODE_TYPE-e_FIRST_XML_NODE_TYPE+1
};

#define e_XML_NODE_TYPE_NAME_NONE "NONE"
#define e_XML_NODE_TYPE_NAME_ELEMENT "ELEMENT"
#define e_XML_NODE_TYPE_NAME_ATTRIBUTE "ATTRIBUTE"
#define e_XML_NODE_TYPE_NAME_TEXT "TEXT"
#define e_XML_NODE_TYPE_NAME_CDATA_SECTION "CDATA_SECTION"
#define e_XML_NODE_TYPE_NAME_ENTITY_REFERENCE "ENTITY_REFERENCE"
#define e_XML_NODE_TYPE_NAME_ENTITY "ENTITY"
#define e_XML_NODE_TYPE_NAME_PROCESSING_INSTRUCTION "PROCESSING_INSTRUCTION"
#define e_XML_NODE_TYPE_NAME_COMMENT "COMMENT"
#define e_XML_NODE_TYPE_NAME_DOCUMENT "DOCUMENT"
#define e_XML_NODE_TYPE_NAME_DOCUMENT_TYPE "DOCUMENT_TYPE"
#define e_XML_NODE_TYPE_NAME_DOCUMENT_FRAGMENT "DOCUMENT_FRAGMENT"
#define e_XML_NODE_TYPE_NAME_NOTATION "NOTATION"

extern const char* eXMLNodeTypeName[e_COUNT_XML_NODE_TYPE];

typedef cImplementBase cXMLNodeTypeImplements;
typedef cInstanceBase cXMLNodeTypeExtends;
/**
 **********************************************************************
 *  Class: cXMLNodeType
 *
 * Author: $author$
 *   Date: 12/10/2017
 **********************************************************************
 */
class cXMLNodeType
: virtual public cXMLNodeTypeImplements,
  public cXMLNodeTypeExtends
{
public:
    typedef cXMLNodeTypeImplements cImplements;
    typedef cXMLNodeTypeExtends cExtends;
    /**
     **********************************************************************
     * Constructor: cXMLNodeType
     *
     *      Author: $author$
     *        Date: 12/10/2017
     **********************************************************************
     */
    cXMLNodeType()
    {
    }
    /**
     **********************************************************************
     * Destructor: ~cXMLNodeType
     *
     *     Author: $author$
     *       Date: 12/10/2017
     **********************************************************************
     */
    virtual ~cXMLNodeType()
    {
    }
};

#endif /* _CXMLNODETYPE_HXX */
