///////////////////////////////////////////////////////////////////////
//   File: evplatform_socket.h
//
// Author: $author$
//   Date: 4/6/2007
//
//    $Id$
///////////////////////////////////////////////////////////////////////

#ifndef _EVPLATFORM_SOCKET_H
#define _EVPLATFORM_SOCKET_H

#include "evplatform.h"

#if defined(WIN32) 
//
// Windows
//
#if defined(_WINSOCK2API_) 
// Windows Sockets 2 API
// <winsock2.h>
#define WINDOWS_SOCKETS_2_API
// WinSock 1 Other NT-specific options.
#define SO_UPDATE_ACCEPT_CONTEXT 0x700B
#elif defined(_WINSOCKAPI_) 
// Windows Sockets 1 API
// <winsock.h>
#define WINDOWS_SOCKETS_1_API
// WinSock 2 extension -- manifest constants for shutdown()
#define SD_RECEIVE 0x00
#define SD_SEND    0x01
#define SD_BOTH    0x02
#else // defined(_WINSOCK2API_) 
// Otherwise
#endif // defined(_WINSOCK2API_)

typedef int socklen_t;
#define GET_SOCKET_ERROR(err) WSAGetLastError()
#define IN_SOCKET_NODELAY_ON(on) !on
#define OUT_SOCKET_NODELAY_ON(on) !on

#if !defined(SO_UPDATE_ACCEPT_CONTEXT) 
#define SO_UPDATE_ACCEPT_CONTEXT 0x700B
#endif // !defined(SO_UPDATE_ACCEPT_CONTEXT)

#else // defined(WIN32) 
//
// Unix
//
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
#define GET_SOCKET_ERROR(err) err
#define IN_SOCKET_NODELAY_ON(on) on
#define OUT_SOCKET_NODELAY_ON(on) on
#define closesocket(fd) close(fd)
#endif // defined(WIN32)

#define INVALID_SOCKET_PORT ((SOCKET_PORT)-1)
typedef USHORT SOCKET_PORT;
typedef ULONG SOCKET_ADDR;
typedef int SOCKET_ADDR_FAMILY;
typedef int SOCKET_TYPE;
typedef int SOCKET_PROTOCOL;

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

#if defined(__cplusplus)
extern "C" {
#endif

#if defined(__cplusplus)
}
#endif

#endif // _EVPLATFORM_SOCKET_H
