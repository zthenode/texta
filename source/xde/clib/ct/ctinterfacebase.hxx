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
 *   File: ctinterfacebase.hxx
 *
 * Author: $author$
 *   Date: 4/1/2008
 **********************************************************************
 */
#ifndef _CTINTERFACEBASE_HXX
#define _CTINTERFACEBASE_HXX

#include "cinterfacebase.hxx"

/**
 **********************************************************************
 *   Enum: 
 *
 * Author: $author$
 *   Date: 8/2/2003
 **********************************************************************
 */
typedef int eTError;
enum
{
    e_FIRST_T_ERROR = e_NEXT_ERROR,

    e_ERROR_EXPAND = e_FIRST_T_ERROR,
    e_ERROR_BREAK,
    e_ERROR_EXIT,

    e_NEXT_T_ERROR,
    e_LAST_T_ERROR = e_NEXT_T_ERROR-1
};

/**
 **********************************************************************
 *  Typedef: tTNameChars
 *
 *  Author: $author$
 *    Date: 3/31/2008
 **********************************************************************
 */
typedef const char*
tTNameChars;

class c_INTERFACE_CLASS cTFunctionInterface;
class c_INTERFACE_CLASS cTInterface;

#endif /* _CTINTERFACEBASE_HXX */
