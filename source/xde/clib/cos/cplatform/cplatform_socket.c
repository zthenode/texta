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
 *   File: cplatform_socket.c
 *
 * Author: $author$
 *   Date: 1/8/2008
 **********************************************************************
 */
#include "cplatform_socket.h"
/**
 **********************************************************************
 * Function: cplatform_socket
 *
 *   Author: $author$
 *     Date: 1/17/2008
 **********************************************************************
 */
SOCKET cplatform_socket
(SOCKET_FAMILY family, SOCKET_TYPE type, SOCKET_PROTOCOL protocol)
{
    SOCKET sock;
    sock = socket(family, type, protocol);
    return sock;
}
/**
 **********************************************************************
 * Function: cplatform_closesocket
 *
 *   Author: $author$
 *     Date: 1/17/2008
 **********************************************************************
 */
int cplatform_closesocket(SOCKET sock)
{
    int err;
    err = closesocket(sock);
    return err;
}

/**
 **********************************************************************
 * Function: cplatform_bind
 *
 *   Author: $author$
 *     Date: 1/17/2008
 **********************************************************************
 */
int cplatform_bind
(SOCKET sock, const SOCKADDR *addr, SOCKLEN addrlen)
{
    int err;
    err = bind(sock, addr, addrlen);
    return err;
}
/**
 **********************************************************************
 * Function: cplatform_listen
 *
 *   Author: $author$
 *     Date: 1/17/2008
 **********************************************************************
 */
int cplatform_listen(SOCKET sock, int backlog)
{
    int err;
    err = listen(sock, backlog);
    return err;
}

/**
 **********************************************************************
 * Function: cplatform_accept
 *
 *   Author: $author$
 *     Date: 1/17/2008
 **********************************************************************
 */
SOCKET cplatform_accept
(SOCKET sock, SOCKADDR *addr, SOCKLEN *addrlen)
{
    SOCKET newsock;
    newsock = accept(sock, addr, addrlen);
    return newsock;
}
/**
 **********************************************************************
 * Function: cplatform_connect
 *
 *   Author: $author$
 *     Date: 1/17/2008
 **********************************************************************
 */
int cplatform_connect
(SOCKET sock, const SOCKADDR *addr, SOCKLEN addrlen)
{
    int err;
    err = connect(sock, addr, addrlen);
    return err;
}

/**
 **********************************************************************
 * Function: cplatform_send
 *
 *   Author: $author$
 *     Date: 2/29/2008
 **********************************************************************
 */
SOCKET_SSIZE_T cplatform_send
(SOCKET sock, const void *buf, SOCKET_SIZE_T len, int flags)
{
    SOCKET_SSIZE_T count = 0;
    count = send(sock, buf, len, flags);
    return count;
}

/**
 **********************************************************************
 * Function: cplatform_recv
 *
 *   Author: $author$
 *     Date: 2/29/2008
 **********************************************************************
 */
SOCKET_SSIZE_T cplatform_recv
(SOCKET sock, void *buf, SOCKET_SIZE_T len, int flags)
{
    SOCKET_SSIZE_T count = 0;
    count = recv(sock, buf, len, flags);
    return count;
}
