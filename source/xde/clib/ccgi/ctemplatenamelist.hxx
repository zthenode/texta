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
 *   File: ctemplatenamelist.hxx
 *
 * Author: $author$
 *   Date: 5/2/2008
 **********************************************************************
 */
#ifndef _CTEMPLATENAMELIST_HXX
#define _CTEMPLATENAMELIST_HXX

#include "cnamelist.hxx"

/**
 **********************************************************************
 *  Class: cTemplateFilePathItem
 *
 * Author: $author$
 *   Date: 12/29/2008
 **********************************************************************
 */
class cTemplateFilePathItem
: public cNameItemT<cTemplateFilePathItem,char,cBase>
{
public:
    typedef cNameItemT<cTemplateFilePathItem,char,cBase> cExtends;
    cTemplateFilePathItem(const tChar* name)
    : cExtends(name) 
    {Add2List();}
    void Add2List();
};
/**
 **********************************************************************
 *  Class: cTemplateFilePathList
 *
 * Author: $author$
 *   Date: 12/29/2008
 **********************************************************************
 */
class cTemplateFilePathList
: public cNameListT<char,cTemplateFilePathItem,cBase>
{
public:
    typedef cNameListT<char,cTemplateFilePathItem,cBase> cExtends;
    static cTemplateFilePathList m_instance;
};

/**
 **********************************************************************
 *  Class: cTemplateFileNameItem
 *
 * Author: $author$
 *   Date: 3/26/2008
 **********************************************************************
 */
class cTemplateFileNameItem
: public cNameItemT<cTemplateFileNameItem,char,cBase>
{
public:
    typedef cNameItemT<cTemplateFileNameItem,char,cBase> cExtends;
    cTemplateFileNameItem(const tChar* name)
    : cExtends(name) 
    {Add2List();}
    void Add2List();
};
/**
 **********************************************************************
 *  Class: cTemplateFileNameList
 *
 * Author: $author$
 *   Date: 3/26/2008
 **********************************************************************
 */
class cTemplateFileNameList
: public cNameListT<char,cTemplateFileNameItem,cBase>
{
public:
    typedef cNameListT<char,cTemplateFileNameItem,cBase> cExtends;
    static cTemplateFileNameList m_instance;
};

/**
 **********************************************************************
 *  Class: cTemplateURIItem
 *
 * Author: $author$
 *   Date: 3/27/2008
 **********************************************************************
 */
class cTemplateURIItem
: public cNameItemT<cTemplateURIItem,char,cBase>
{
public:
    typedef cNameItemT<cTemplateURIItem,char,cBase> cExtends;
    cTemplateURIItem(const tChar* name)
    : cExtends(name) 
    {Add2List();}
    void Add2List();
};
/**
 **********************************************************************
 *  Class: cTemplateURIList
 *
 * Author: $author$
 *   Date: 3/27/2008
 **********************************************************************
 */
class cTemplateURIList
: public cNameListT<char,cTemplateURIItem,cBase>
{
public:
    typedef cNameListT<char,cTemplateURIItem,cBase> cExtends;
    static cTemplateURIList m_instance;
};

#endif /* _CTEMPLATENAMELIST_HXX */
