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
 *   File: cxmlattributenodeinterface.cxx
 *
 * Author: $author$
 *   Date: 11/21/2008
 **********************************************************************
 */

#include "cxmlattributenodeinterface.hxx"
#include "cxmlattributenode.hxx"

/**
 **********************************************************************
 *  Class: cXMLAttributeNodeInterface
 *
 * Author: $author$
 *   Date: 11/21/2008
 **********************************************************************
 */
//cXMLAttributeNodeInterface* g_cXMLAttributeNodeInterface;
/**
 **********************************************************************
 * Function: cXMLAttributeNodeInterface::CreateInstance
 *
 *   Author: $author$
 *     Date: 11/29/2008
 **********************************************************************
 */
cXMLAttributeNodeInterface* 
cXMLAttributeNodeInterface::CreateInstance
(cXMLDocumentNodeInterface& documentNode,
 const cXMLChar* nodeNameXMLChars, TLENGTH nodeNameLength,
 const cXMLChar* nodeNamespacePrefixXMLChars, TLENGTH nodeNamespacePrefixLength,
 const cXMLChar* nodeValueXMLChars, TLENGTH nodeValueLength) 
{
    cXMLAttributeNodeInterface* nodeInterface = 0;
    cXMLAttributeNode* node = 0;
    if ((node = new cXMLAttributeNode
        (nodeNameXMLChars, nodeNameLength,
         nodeNamespacePrefixXMLChars, nodeNamespacePrefixLength,
         nodeValueXMLChars, nodeValueLength)))
    {
        node->m_holdInstance = 0;
        nodeInterface = (cXMLAttributeNodeInterface*)(node);
    }
    return node;
}
