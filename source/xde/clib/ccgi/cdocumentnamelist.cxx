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
 *   File: cdocumentnamelist.cxx
 *
 * Author: $author$
 *   Date: 5/3/2008
 **********************************************************************
 */

#include "cdocumentnamelist.hxx"

/**
 **********************************************************************
 *  Class: cDocumentFilePathList
 *
 * Author: $author$
 *   Date: 12/29/2008
 **********************************************************************
 */
cDocumentFilePathList cDocumentFilePathList::m_instance;
template<>
cDocumentFilePathItem* cDocumentFilePathList::cExtends::cExtends::m_firstItem = 0;
template<>
cDocumentFilePathItem* cDocumentFilePathList::cExtends::cExtends::m_lastItem = 0;
void cDocumentFilePathItem::Add2List()
{cDocumentFilePathList::m_instance.AddItem(*this);}

/**
 **********************************************************************
 *  Class: cDocumentFileNameList
 *
 * Author: $author$
 *   Date: 3/26/2008
 **********************************************************************
 */
cDocumentFileNameList cDocumentFileNameList::m_instance;
template<>
cDocumentFileNameItem* cDocumentFileNameList::cExtends::cExtends::m_firstItem = 0;
template<>
cDocumentFileNameItem* cDocumentFileNameList::cExtends::cExtends::m_lastItem = 0;
void cDocumentFileNameItem::Add2List()
{cDocumentFileNameList::m_instance.AddItem(*this);}

/**
 **********************************************************************
 *  Class: cDocumentURIList
 *
 * Author: $author$
 *   Date: 3/27/2008
 **********************************************************************
 */
cDocumentURIList cDocumentURIList::m_instance;
template<>
cDocumentURIItem* cDocumentURIList::cExtends::cExtends::m_firstItem = 0;
template<>
cDocumentURIItem* cDocumentURIList::cExtends::cExtends::m_lastItem = 0;
void cDocumentURIItem::Add2List()
{cDocumentURIList::m_instance.AddItem(*this);}
