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
 *   File: cxmlelementprocessorlist.hxx
 *
 * Author: $author$
 *   Date: 12/11/2008
 **********************************************************************
 */
#ifndef _CXMLELEMENTPROCESSORLIST_HXX
#define _CXMLELEMENTPROCESSORLIST_HXX

#include "cxmlnodeinterface.hxx"
#include "clist.hxx"

class cXMLElementNodeProcessor;
class cXMLElementProcessorItem;

/**
 **********************************************************************
 *  Class: cXMLElementProcessorList
 *
 * Author: $author$
 *   Date: 12/11/2008
 **********************************************************************
 */
class cXMLElementProcessorList
: public cStaticListT<cXMLElementProcessorItem>
{
public:
    typedef cStaticListT<cXMLElementProcessorItem> cExtends;
    typedef cXMLElementProcessorList cDerives;

    static cXMLElementProcessorList m_list;

    /**
     **********************************************************************
     * Function: Find
     *
     *   Author: $author$
     *     Date: 12/11/2008
     **********************************************************************
     */
    static cXMLElementNodeProcessor* Find
    (const cXMLString& match, const cXMLString& mode);
};

/**
 **********************************************************************
 *  Class: cXMLElementProcessorItem
 *
 * Author: $author$
 *   Date: 12/11/2008
 **********************************************************************
 */
class cXMLElementProcessorItem
: public cListItemT<cXMLElementProcessorItem>
{
public:
    typedef cListItemT<cXMLElementProcessorItem> cExtends;
    typedef cXMLElementProcessorItem cDerives;

    cXMLElementNodeProcessor& m_xmlElementProcessor;

    /**
     **********************************************************************
     * Constructor: cXMLElementProcessorItem
     *
     *      Author: $author$
     *        Date: 12/11/2008
     **********************************************************************
     */
    cXMLElementProcessorItem
    (cXMLElementNodeProcessor& xmlElementProcessor)
    : m_xmlElementProcessor(xmlElementProcessor)
    {
        cXMLElementProcessorList::m_list.AddItem(*this);
    }
    /**
     **********************************************************************
     * Destructor: ~cXMLElementProcessorItem
     *
     *     Author: $author$
     *       Date: 12/11/2008
     **********************************************************************
     */
    virtual ~cXMLElementProcessorItem()
    {
        cXMLElementProcessorList::m_list.DeleteItem(*this);
    }
};
#endif /* _CXMLELEMENTPROCESSORLIST_HXX */
