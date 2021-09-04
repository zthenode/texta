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
 *   File: ctemplatenamelist.cxx
 *
 * Author: $author$
 *   Date: 5/2/2008
 **********************************************************************
 */

#include "ctemplatenamelist.hxx"

/**
 **********************************************************************
 *  Class: cTemplateFilePathList
 *
 * Author: $author$
 *   Date: 12/29/2008
 **********************************************************************
 */
cTemplateFilePathList cTemplateFilePathList::m_instance;
template<>
cTemplateFilePathItem* cTemplateFilePathList::cExtends::cExtends::m_firstItem = 0;
template<>
cTemplateFilePathItem* cTemplateFilePathList::cExtends::cExtends::m_lastItem = 0;
void cTemplateFilePathItem::Add2List()
{cTemplateFilePathList::m_instance.AddItem(*this);}

/**
 **********************************************************************
 *  Class: cTemplateFileNameList
 *
 * Author: $author$
 *   Date: 3/26/2008
 **********************************************************************
 */
cTemplateFileNameList cTemplateFileNameList::m_instance;
template<>
cTemplateFileNameItem* cTemplateFileNameList::cExtends::cExtends::m_firstItem = 0;
template<>
cTemplateFileNameItem* cTemplateFileNameList::cExtends::cExtends::m_lastItem = 0;
void cTemplateFileNameItem::Add2List()
{cTemplateFileNameList::m_instance.AddItem(*this);}

/**
 **********************************************************************
 *  Class: cTemplateURIList
 *
 * Author: $author$
 *   Date: 3/27/2008
 **********************************************************************
 */
cTemplateURIList cTemplateURIList::m_instance;
template<>
cTemplateURIItem* cTemplateURIList::cExtends::cExtends::m_firstItem = 0;
template<>
cTemplateURIItem* cTemplateURIList::cExtends::cExtends::m_lastItem = 0;
void cTemplateURIItem::Add2List()
{cTemplateURIList::m_instance.AddItem(*this);}
