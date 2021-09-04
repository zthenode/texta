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
 *   File: cxmlelementprocessorlist.cxx
 *
 * Author: $author$
 *   Date: 12/11/2008
 **********************************************************************
 */
#include "cxmlelementprocessorlist.hxx"
#include "cxmlelementnodeprocessor.hxx"
/**
 **********************************************************************
 *  Class: cXMLElementProcessorList
 *
 * Author: $author$
 *   Date: 12/11/2008
 **********************************************************************
 */
template<>
cXMLElementProcessorItem* cXMLElementProcessorList::cExtends::m_firstItem = 0;
template<>
cXMLElementProcessorItem* cXMLElementProcessorList::cExtends::m_lastItem = 0;
cXMLElementProcessorList cXMLElementProcessorList::m_list;

/**
 **********************************************************************
 * Function: cXMLElementProcessorList::Find
 *
 *   Author: $author$
 *     Date: 12/11/2008
 **********************************************************************
 */
cXMLElementNodeProcessor* cXMLElementProcessorList::Find
(const cXMLString& match, const cXMLString& mode) 
{
    cXMLElementNodeProcessor* xmlElementProcessor = 0;
    cXMLElementProcessorItem* xmlElementProcessorItem;
    unsigned notMatched;

    for (notMatched=0; notMatched<2; notMatched++)
    {
        for (xmlElementProcessorItem = m_list.m_firstItem; 
             xmlElementProcessorItem; 
             xmlElementProcessorItem = xmlElementProcessorItem->m_nextItem)
        {
		    if (xmlElementProcessorItem->
                m_xmlElementProcessor.Match(match, mode, (notMatched > 0)))
			    return xmlElementProcessor = &xmlElementProcessorItem->m_xmlElementProcessor;
        }
    }
    return xmlElementProcessor;
}
