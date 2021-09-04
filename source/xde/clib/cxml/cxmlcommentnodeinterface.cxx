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
 *   File: cxmlcommentnodeinterface.cxx
 *
 * Author: $author$
 *   Date: 11/14/2008
 **********************************************************************
 */

#include "cxmlcommentnodeinterface.hxx"
#include "cxmlcommentnode.hxx"

/**
 **********************************************************************
 *  Class: cXMLCommentNodeInterface
 *
 * Author: $author$
 *   Date: 11/14/2008
 **********************************************************************
 */
/**
 **********************************************************************
 * Function: cXMLCommentNodeInterface::CreateInstance
 *
 *   Author: $author$
 *     Date: 11/14/2008
 **********************************************************************
 */
cXMLCommentNodeInterface* 
cXMLCommentNodeInterface::CreateInstance
(cXMLDocumentNodeInterface& documentNode,
 const cXMLChar* textChars, TLENGTH textLength) 
{
    cXMLCommentNodeInterface* xmlCommentNodeInterface = 0;
    cXMLCommentNode* xmlCommentNode;
    if ((xmlCommentNodeInterface = (cXMLCommentNodeInterface*)
        (xmlCommentNode = new cXMLCommentNode(textChars, textLength))))
        xmlCommentNode->m_holdInstance = 0;
    return xmlCommentNodeInterface;
}
