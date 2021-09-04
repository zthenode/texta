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
 *   File: cmainarg.cxx
 *
 * Author: $author$
 *   Date: 1/18/2008
 **********************************************************************
 */
#include "cmainarg.hxx"
#include "cmaininterface.hxx"
#include "cdebug.h"

template <>
cMainArgItem* cMainArgList::cExtends::cExtends::m_firstItem = 0;
template <>
cMainArgItem* cMainArgList::cExtends::cExtends::m_lastItem = 0;

#if defined(NO_TEMPLATE_STATIC_MEMBERS) 
cMainArgList cMainArg::m_list;
#else /* defined(NO_TEMPLATE_STATIC_MEMBERS) */
template <>
cMainArgList cMainArg::cExtends::m_list;
#endif /* defined(NO_TEMPLATE_STATIC_MEMBERS) */

/**
 **********************************************************************
 *  Class: cDebugLevelsMainArg
 *
 * Author: $author$
 *   Date: 1/21/2008
 **********************************************************************
 */
cDebugLevelsMainArg* cDebugLevelsMainArg::m_instance = 0;
cDebugLevelsMainArg g_debugLevelsArg;
