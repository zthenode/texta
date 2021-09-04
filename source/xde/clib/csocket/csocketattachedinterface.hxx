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
 *   File: csocketattachedinterface.hxx
 *
 * Author: $author$
 *   Date: 1/16/2008
 **********************************************************************
 */
#ifndef _CSOCKETATTACHEDINTERFACE_HXX
#define _CSOCKETATTACHEDINTERFACE_HXX

#include "cplatform_socket.h"
#include "cattachedinterface.hxx"

/**
 **********************************************************************
 *  Typedef: cSocketAttachInterface
 *
 *  Author: $author$
 *    Date: 1/16/2008
 **********************************************************************
 */
typedef cAttachInterfaceT
<SOCKET, cInterfaceBase>
cSocketAttachInterface;

/**
 **********************************************************************
 *  Typedef: cSocketDetachInterface
 *
 *  Author: $author$
 *    Date: 1/16/2008
 **********************************************************************
 */
typedef cDetachInterfaceT
<SOCKET, cInterfaceBase>
cSocketDetachInterface;

/**
 **********************************************************************
 *  Typedef: cSocketAttachedInterface
 *
 *  Author: $author$
 *    Date: 1/16/2008
 **********************************************************************
 */
typedef cAttachedInterfaceT
<SOCKET, cSocketAttachInterface, cSocketDetachInterface>
cSocketAttachedInterface;

#endif /* _CSOCKETATTACHEDINTERFACE_HXX */
