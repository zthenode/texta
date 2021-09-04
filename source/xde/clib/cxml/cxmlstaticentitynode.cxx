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
 *   File: cxmlstaticentitynode.cxx
 *
 * Author: $author$
 *   Date: 12/16/2008
 **********************************************************************
 */
#include "cxmlstaticentitynode.hxx"
/**
 **********************************************************************
 *  Class: cXMLStaticEntityNode
 *
 * Author: $author$
 *   Date: 12/16/2008
 **********************************************************************
 */
template<> cXMLNodeItem* cXMLStaticEntityNodeListExtends::m_firstItem = 0;
template<> cXMLNodeItem* cXMLStaticEntityNodeListExtends::m_lastItem = 0;
cXMLStaticEntityNodeList cXMLStaticEntityNode::m_staticNodeList;

cXMLStaticEntityNode g_ltEntityNode("lt", "<");
cXMLStaticEntityNode g_gtEntityNode("gt", ">");
cXMLStaticEntityNode g_ampEntityNode("amp", "&");
cXMLStaticEntityNode g_quotEntityNode("quot", "\"");
cXMLStaticEntityNode g_aposEntityNode("apos", "'");
