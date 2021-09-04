/**
 **********************************************************************
 * Copyright (c) $year$ $author$
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
 *   File: cplatform.hxx
 *
 * Author: $author$
 *   Date: $date$
 **********************************************************************
 */
#ifndef _CPLATFORM_HXX
#define _CPLATFORM_HXX
#define _PLATFORM_HXX

#include "cplatform.h"

#if defined(WIN32) 
/* Windows
 */
#define c_INTERFACE_CLASS PLATFORM_EXPORT
#define c_EXPORT_CLASS PLATFORM_EXPORT
#define c_EXPORT PLATFORM_EXPORT
#else /* defined(WIN32) */
/* Unix
 */
#define c_INTERFACE_CLASS
#define c_EXPORT_CLASS
#define c_EXPORT
#endif /* defined(WIN32) */

#define c_INSTANCE_CLASS
#define c_IMPLEMENT_CLASS

#endif /* _CPLATFORM_HXX */
