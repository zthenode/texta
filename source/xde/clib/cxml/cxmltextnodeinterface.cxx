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
 *   File: cxmltextnodeinterface.cxx
 *
 * Author: $author$
 *   Date: 11/14/2008
 **********************************************************************
 */

#include "cxmltextnodeinterface.hxx"
#include "cxmltextnode.hxx"

/**
 **********************************************************************
 *  Class: cXMLTextNodeInterface
 *
 * Author: $author$
 *   Date: 11/14/2008
 **********************************************************************
 */
/**
 **********************************************************************
 * Function: cXMLTextNodeInterface::CreateInstance
 *
 *   Author: $author$
 *     Date: 11/16/2008
 **********************************************************************
 */
cXMLTextNodeInterface* 
cXMLTextNodeInterface::CreateInstance
(cXMLDocumentNodeInterface& documentNode,
 const cXMLChar* textChars, TLENGTH textLength) 
{
    cXMLTextNodeInterface* xmlTextNodeInterface = 0;
    cXMLTextNode* xmlTextNode;
    if ((xmlTextNodeInterface = (cXMLTextNodeInterface*)
        (xmlTextNode = new cXMLTextNode(textChars, textLength))))
        xmlTextNode->m_holdInstance = 0;
    return xmlTextNodeInterface;
}
