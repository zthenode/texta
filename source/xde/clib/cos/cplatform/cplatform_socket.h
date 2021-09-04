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
 *   File: cplatform_socket.h
 *
 * Author: $author$
 *   Date: 1/8/2008
 **********************************************************************
 */
#ifndef _CPLATFORM_SOCKET_H
#define _CPLATFORM_SOCKET_H

#if defined(WIN32) 
/***
 * Windows
 */
#include "cplatform_winsock.h"

#if defined(_WINSOCK2API_) 
/* Windows Sockets 2 API
 * <winsock2.h>
 */
#define WINDOWS_SOCKETS_2_API
/* WinSock 1 Other NT-specific options.
 */
#define SO_UPDATE_ACCEPT_CONTEXT 0x700B
#else /* defined(_WINSOCK2API_) */
/* Windows Sockets 1 API (_WINSOCKAPI_)
 * <winsock.h>
 */
#define WINDOWS_SOCKETS_1_API
/* WinSock 2 extension -- manifest constants for shutdown()
 */
#define SD_RECEIVE 0x00
#define SD_SEND    0x01
#define SD_BOTH    0x02
#endif /* defined(_WINSOCK2API_) */

typedef int SOCKET_SIZE_T;
typedef int SOCKET_SSIZE_T;

typedef int socklen_t;
#define GET_SOCKET_ERROR(err) WSAGetLastError()
#define IN_SOCKET_NODELAY_ON(on) !on
#define OUT_SOCKET_NODELAY_ON(on) !on

#if !defined(SO_UPDATE_ACCEPT_CONTEXT) 
#define SO_UPDATE_ACCEPT_CONTEXT 0x700B
#endif // !defined(SO_UPDATE_ACCEPT_CONTEXT)

#define IN_ADDR_GET_ADDRESS(in_addr) \
    (&in_addr.S_un.S_addr)

#define IN_ADDR_SET_INADDR_ANY(in_addr) \
    ((in_addr).S_un.S_addr = INADDR_ANY)

#define IN_ADDR_SET_ADDRESS(in_addr, addr) \
    ((in_addr).S_un.S_addr = (addr))
/*
 * Windows
 ***/
#else /* defined(WIN32) */
/***
 * Unix
 */
#include "cplatform.h"
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/tcp.h>
#include <arpa/inet.h>
#include <netdb.h>

#define SD_RECEIVE SHUT_RD
#define SD_SEND SHUT_WR
#define SD_BOTH SHUT_RDWR
#define INVALID_SOCKET -1

typedef int SOCKET;
typedef struct sockaddr SOCKADDR;
typedef struct sockaddr_in SOCKADDR_IN;
typedef struct hostent HOSTENT;

typedef size_t SOCKET_SIZE_T;
typedef ssize_t SOCKET_SSIZE_T;

#define GET_SOCKET_ERROR(err) err
#define IN_SOCKET_NODELAY_ON(on) on
#define OUT_SOCKET_NODELAY_ON(on) on
#define closesocket(fd) close(fd)

#define IN_ADDR_GET_ADDRESS(in_addr) \
    (&in_addr.s_addr)

#define IN_ADDR_SET_INADDR_ANY(in_addr) \
    ((in_addr).s_addr = INADDR_ANY)

#define IN_ADDR_SET_ADDRESS(in_addr, addr) \
    ((in_addr).s_addr = (addr))
/*
 * Unix
 ***/
#endif /* defined(WIN32) */

#define DEFAULT_SOCKET_BACKLOG 10
#define INVALID_SOCKET_PORT ((SOCKET_PORT)-1)
typedef USHORT SOCKET_PORT;
typedef ULONG SOCKET_ADDR;
typedef int SOCKET_FAMILY;
typedef int SOCKET_TYPE;
typedef int SOCKET_PROTOCOL;
typedef socklen_t SOCKLEN;

typedef int SOCKET_OPT_LEVEL;
typedef int SOCKET_OPT_NAME;
typedef void SOCKET_OPT_VALUE;
typedef socklen_t SOCKET_OPT_LENGTH;

typedef struct linger SOCKET_LINGER;
#define DEFAULT_SOCKET_LINGER_SECONDS 10

#define SET_SOCKET_LINGER_ON(linger, on) linger.l_onoff = on
#define SET_SOCKET_DONT_LINGER_ON(linger, on) linger.l_onoff = !on
#define SET_SOCKET_LINGER_SECONDS(linger, lingerSeconds) linger.l_linger = lingerSeconds

#define GET_SOCKET_LINGER_ON(linger) linger.l_onoff
#define GET_SOCKET_DONT_LINGER_ON(linger) !linger.l_onoff
#define GET_SOCKET_LINGER_SECONDS(linger) linger.l_linger

#define SOCKET_WAITFOREVER -1

#define HOSTENT_GET_ADDRESS(hostent) \
    ((hostent)->h_addr)

#define HOSTENT_GET_IN_ADDR(hostent) \
    *((IN_ADDR*)(HOSTENT_GET_ADDRESS(hostent)))

#define HOSTENT_GET_ADDRESS_INDEX(hostent, index) \
    ((hostent)->h_addr_list[index])

#define HOSTENT_GET_IN_ADDR_INDEX(hostent, index) \
    *((IN_ADDR*)(HOSTENT_GET_ADDRESS_INDEX(hostent, index)))

#if defined(__cplusplus)
extern "C" {
#endif /* defined(__cplusplus) */

/**
 **********************************************************************
 * Function: cplatform_socket
 *
 *   Author: $author$
 *     Date: 1/17/2008
 **********************************************************************
 */
SOCKET cplatform_socket
(SOCKET_FAMILY family, SOCKET_TYPE type, SOCKET_PROTOCOL protocol);
/**
 **********************************************************************
 * Function: cplatform_closesocket
 *
 *   Author: $author$
 *     Date: 1/17/2008
 **********************************************************************
 */
int cplatform_closesocket(SOCKET sock);

/**
 **********************************************************************
 * Function: cplatform_bind
 *
 *   Author: $author$
 *     Date: 1/17/2008
 **********************************************************************
 */
int cplatform_bind
(SOCKET sock, const SOCKADDR *addr, SOCKLEN addrlen);
/**
 **********************************************************************
 * Function: cplatform_listen
 *
 *   Author: $author$
 *     Date: 1/17/2008
 **********************************************************************
 */
int cplatform_listen(SOCKET sock, int backlog);

/**
 **********************************************************************
 * Function: cplatform_accept
 *
 *   Author: $author$
 *     Date: 1/17/2008
 **********************************************************************
 */
SOCKET cplatform_accept
(SOCKET sock, SOCKADDR *addr, SOCKLEN *addrlen);
/**
 **********************************************************************
 * Function: cplatform_connect
 *
 *   Author: $author$
 *     Date: 1/17/2008
 **********************************************************************
 */
int cplatform_connect
(SOCKET sock, const SOCKADDR *addr, SOCKLEN addrlen);

/**
 **********************************************************************
 * Function: cplatform_send
 *
 *   Author: $author$
 *     Date: 1/17/2008
 **********************************************************************
 */
SOCKET_SSIZE_T cplatform_send
(SOCKET sock, const void *buf, SOCKET_SIZE_T len, int flags);
/**
 **********************************************************************
 * Function: cplatform_recv
 *
 *   Author: $author$
 *     Date: 1/17/2008
 **********************************************************************
 */
SOCKET_SSIZE_T cplatform_recv
(SOCKET sock, void *buf, SOCKET_SIZE_T len, int flags);

/**
 **********************************************************************
 * Function: cplatform_setsockopt
 *
 *   Author: $author$
 *     Date: 1/17/2008
 **********************************************************************
 */
int cplatform_setsockopt
(SOCKET sock, SOCKET_OPT_LEVEL level, SOCKET_OPT_NAME optname, 
 const SOCKET_OPT_VALUE *optval, SOCKET_OPT_LENGTH optlen);
/**
 **********************************************************************
 * Function: cplatform_getsockopt
 *
 *   Author: $author$
 *     Date: 1/17/2008
 **********************************************************************
 */
int cplatform_getsockopt
(SOCKET sock, SOCKET_OPT_LEVEL level, SOCKET_OPT_NAME optname, 
 SOCKET_OPT_VALUE *optval, SOCKET_OPT_LENGTH *optlen);

#if defined(__cplusplus)
}
#endif /* defined(__cplusplus) */

#endif /* _CPLATFORM_SOCKET_H */
