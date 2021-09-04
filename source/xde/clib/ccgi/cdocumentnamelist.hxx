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
 *   File: cdocumentnamelist.hxx
 *
 * Author: $author$
 *   Date: 5/3/2008
 **********************************************************************
 */
#ifndef _CDOCUMENTNAMELIST_HXX
#define _CDOCUMENTNAMELIST_HXX

#include "cnamelist.hxx"

/**
 **********************************************************************
 *  Class: cDocumentFilePathItem
 *
 * Author: $author$
 *   Date: 12/29/2008
 **********************************************************************
 */
class cDocumentFilePathItem
: public cNameItemT<cDocumentFilePathItem,char,cBase>
{
public:
    typedef cNameItemT<cDocumentFilePathItem,char,cBase> cExtends;
    cDocumentFilePathItem(const tChar* name)
    : cExtends(name) 
    {Add2List();}
    void Add2List();
};
/**
 **********************************************************************
 *  Class: cDocumentFilePathList
 *
 * Author: $author$
 *   Date: 12/29/2008
 **********************************************************************
 */
class cDocumentFilePathList
: public cNameListT<char,cDocumentFilePathItem,cBase>
{
public:
    typedef cNameListT<char,cDocumentFilePathItem,cBase> cExtends;
    static cDocumentFilePathList m_instance;
};

/**
 **********************************************************************
 *  Class: cDocumentFileNameItem
 *
 * Author: $author$
 *   Date: 3/26/2008
 **********************************************************************
 */
class cDocumentFileNameItem
: public cNameItemT<cDocumentFileNameItem,char,cBase>
{
public:
    typedef cNameItemT<cDocumentFileNameItem,char,cBase> cExtends;
    cDocumentFileNameItem(const tChar* name)
    : cExtends(name) 
    {Add2List();}
    void Add2List();
};
/**
 **********************************************************************
 *  Class: cDocumentFileNameList
 *
 * Author: $author$
 *   Date: 3/26/2008
 **********************************************************************
 */
class cDocumentFileNameList
: public cNameListT<char,cDocumentFileNameItem,cBase>
{
public:
    typedef cNameListT<char,cDocumentFileNameItem,cBase> cExtends;
    static cDocumentFileNameList m_instance;
};

/**
 **********************************************************************
 *  Class: cDocumentURIItem
 *
 * Author: $author$
 *   Date: 3/27/2008
 **********************************************************************
 */
class cDocumentURIItem
: public cNameItemT<cDocumentURIItem,char,cBase>
{
public:
    typedef cNameItemT<cDocumentURIItem,char,cBase> cExtends;
    cDocumentURIItem(const tChar* name)
    : cExtends(name) 
    {Add2List();}
    void Add2List();
};
/**
 **********************************************************************
 *  Class: cDocumentURIList
 *
 * Author: $author$
 *   Date: 3/27/2008
 **********************************************************************
 */
class cDocumentURIList
: public cNameListT<char,cDocumentURIItem,cBase>
{
public:
    typedef cNameListT<char,cDocumentURIItem,cBase> cExtends;
    static cDocumentURIList m_instance;
};

#endif /* _CDOCUMENTNAMELIST_HXX */
