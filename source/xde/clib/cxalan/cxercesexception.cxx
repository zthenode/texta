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
 *   File: cxercesexception.cxx
 *
 * Author: $author$
 *   Date: 3/10/2008
 **********************************************************************
 */
#include "cxercesexception.hxx"

const char* g_xercesExceptionTypeName[e_COUNT_XERCES_EXCEPTION_TYPE] = 
{
    e_XERCES_EXCEPTION_TYPE_NAME_WARNING,
    e_XERCES_EXCEPTION_TYPE_NAME_ERROR,
    e_XERCES_EXCEPTION_TYPE_NAME_FATAL_ERROR
};

/**
 **********************************************************************
 *  Class: cXercesException
 *
 * Author: $author$
 *   Date: 3/10/2008
 **********************************************************************
 */
