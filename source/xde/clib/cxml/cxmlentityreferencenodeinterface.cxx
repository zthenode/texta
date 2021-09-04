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
 *   File: cxmlentityreferencenodeinterface.cxx
 *
 * Author: $author$
 *   Date: 12/16/2008
 **********************************************************************
 */

#include "cxmlentityreferencenodeinterface.hxx"
#include "cxmlentityreferencenode.hxx"
#include "cxmlstaticentitynode.hxx"

/**
 **********************************************************************
 *  Class: cXMLEntityReferenceNodeInterface
 *
 * Author: $author$
 *   Date: 12/16/2008
 **********************************************************************
 */
/**
 **********************************************************************
 * Function: cXMLEntityReferenceNodeInterface::CreateInstance
 *
 *   Author: $author$
 *     Date: 12/16/2008
 **********************************************************************
 */
cXMLEntityReferenceNodeInterface* cXMLEntityReferenceNodeInterface::CreateInstance
(cXMLDocumentNodeInterface& documentNode,
 const cXMLChar* referencedNameXmlChars,
 TLENGTH referencedNameLength) 
{
    const cXMLEntityNodeInterface* referencedEntityNode = 0;
    cXMLEntityReferenceNodeInterface* entityReferenceNodeInterface = 0;
    cXMLEntityReferenceNode* entityReferenceNode = 0;

    referencedEntityNode = cXMLStaticEntityNode::Find
    (referencedNameXmlChars, referencedNameLength);

    if ((entityReferenceNodeInterface = (cXMLEntityReferenceNodeInterface*)
        (entityReferenceNode = new cXMLEntityReferenceNode(referencedEntityNode))))
        entityReferenceNode->m_holdInstance = 0;
    return entityReferenceNode;
}
