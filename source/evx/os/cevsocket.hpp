///////////////////////////////////////////////////////////////////////
//   File: cevsocket.hpp
//
// Author: $author$
//   Date: 4/6/2007
//
//    $Id$
///////////////////////////////////////////////////////////////////////

#ifndef _CEVSOCKET_HPP
#define _CEVSOCKET_HPP

#include "evplatform_socket.h"
#include "cevreference.hpp"
#include "cevreferenced.hpp"
#include "evwsa.hpp"
#include "cevcharreader.hpp"
#include "cevcharwriter.hpp"
#include "cevbase.hpp"
#include "evdebug.h"

#define DEFAULT_EV_SOCKET_BACKLOG 10

class CEvSocketReference;

///////////////////////////////////////////////////////////////////////
//  Class: CEvSocket
//
// Author: $author$
//   Date: 4/6/2007
///////////////////////////////////////////////////////////////////////
class CEvSocket
: public CEvReferenced
{
public:
    typedef CEvReferenced CExtends;
    typedef CEvSocket CDerives;

	SOCKET_ADDR_FAMILY m_family;
	SOCKET_TYPE m_type;
	SOCKET_PROTOCOL m_protocol;
	SOCKET_ADDR m_addr;
	SOCKET_PORT m_port;
    int m_backlog;
    SOCKET m_attached;

    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvSocket
    //
    //       Author: $author$
    //         Date: 4/6/2007
    ///////////////////////////////////////////////////////////////////////
    CEvSocket
    (SOCKET attached = INVALID_SOCKET, 
	 SOCKET_PORT port = INVALID_SOCKET_PORT,
	 SOCKET_ADDR addr = INADDR_ANY,
	 SOCKET_ADDR_FAMILY family = AF_INET,
	 SOCKET_TYPE type = SOCK_STREAM,
	 SOCKET_PROTOCOL protocol = 0,
     int backlog = DEFAULT_EV_SOCKET_BACKLOG) 
    : m_family(family),
	  m_type(type),
	  m_protocol(protocol),
	  m_addr(addr),
	  m_port(port),
      m_backlog(backlog),
	  m_attached(attached)
    {
    }
    ///////////////////////////////////////////////////////////////////////
    // Destructor: ~CEvSocket
    //
    //      Author: $author$
    //        Date: 4/6/2007
    ///////////////////////////////////////////////////////////////////////
    virtual ~CEvSocket()
    {
        EvError error;

		if (INVALID_SOCKET != m_attached)
	    if ((error = Close()))
			throw(error);
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: Create
    //
    //   Author: $author$
    //     Date: 4/6/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError Create() 
    {
        EvError error = EV_ERROR_FAILED;

		if (INVALID_SOCKET != m_attached)
			return EV_ERROR_ALREADY_ATTACHED;

#if defined(WIN32) 
// Windows
        if ((error = EvWsa::Startup()))
        {
            DBE("() failed on wsa startup\n");
            return error;
        }
#endif // defined(WIN32)

		if (INVALID_SOCKET != (m_attached = socket
			(m_family, m_type, m_protocol)))
		{
#if defined(WIN32) 
// Windows
			int optval = 1;
            int err;

			if ((err = setsockopt
			    (m_attached, IPPROTO_TCP, TCP_NODELAY, 
			    (char*)&optval, sizeof(optval))))
            {
                DBE("() failed on setsockopt\n");
                closesocket(m_attached);
                m_attached = INVALID_SOCKET;
                return error;
            }
#endif // defined(WIN32)
			return EV_ERROR_NONE;
		}

		DBE("() failed error = %d\n", GET_SOCKET_ERROR(0));
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: Close
    //
    //   Author: $author$
    //     Date: 4/6/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError Close
    (bool onlyIfOpen=false) 
    {
        EvError error = EV_ERROR_FAILED;
        int err;

		if (INVALID_SOCKET == m_attached)
        if (onlyIfOpen)
			return EV_ERROR_NOT_ATTACHED;
        else return EV_ERROR_NONE;

		if ((err = closesocket(m_attached)))
        {
			DBE("() failed to close socket error = %d\n", GET_SOCKET_ERROR(err));
            return error;
        }
        else error = EV_ERROR_NONE;

        m_attached = INVALID_SOCKET;
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: ShutDown
    //
    //   Author: $author$
    //     Date: 5/12/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError ShutDown
    (int how=SD_BOTH, bool onlyIfOpen=false) 
    {
        EvError error = EV_ERROR_FAILED;
        int err;

		if (INVALID_SOCKET == m_attached)
        if (onlyIfOpen)
			return EV_ERROR_NOT_ATTACHED;
        else return EV_ERROR_NONE;

		if ((err = shutdown(m_attached, how)))
        {
			DBE("() failed to shutdown socket error = %d\n", GET_SOCKET_ERROR(err));
            return error;
        }
        else error = EV_ERROR_NONE;
        return error;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: Bind
    //
    //   Author: $author$
    //     Date: 4/6/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError Bind
    (USHORT port, const char* host=0) 
    {
        EvError error = EV_ERROR_FAILED;
		SOCKADDR_IN sockAddrIn;
		int err;

        if (host)
            return EV_ERROR_NOT_IMPLEMENTED;

		if (INVALID_SOCKET == m_attached)
			return EV_ERROR_NOT_ATTACHED;

		if (INVALID_SOCKET_PORT == port)
			port = m_port;

		sockAddrIn.sin_family = m_family;
		sockAddrIn.sin_port = htons(port);
		sockAddrIn.sin_addr.s_addr = htonl(m_addr);

		if ((err = bind(m_attached, (SOCKADDR*)(&sockAddrIn), sizeof(sockAddrIn))))
			DBE("() failed to bind socket error = %d\n", GET_SOCKET_ERROR(err));
        else error = EV_ERROR_NONE;

        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: Listen
    //
    //   Author: $author$
    //     Date: 4/6/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError Listen(int backlog=UNDEFINED) 
    {
        EvError error = EV_ERROR_FAILED;
		int err;

		if (INVALID_SOCKET == m_attached)
			return EV_ERROR_NOT_ATTACHED;

        if (UNDEFINED == backlog)
            backlog = m_backlog;

		if ((err = listen(m_attached, backlog)))
			DBE("() failed to listen error = %d\n", GET_SOCKET_ERROR(err));
        else error = EV_ERROR_NONE;

        return error;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: Accept
    //
    //   Author: $author$
    //     Date: 4/8/2007
    ///////////////////////////////////////////////////////////////////////
    virtual CEvSocketReference Accept
#if defined(WIN32) 
// Windows
    (EvError& error, bool updateAcceptContext=false);
#else // defined(WIN32) 
// Unix
    (EvError& error);
#endif // defined(WIN32)
    ///////////////////////////////////////////////////////////////////////
    // Function: Reject
    //
    //   Author: $author$
    //     Date: 5/16/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError Reject
    (CEvSocketReference& acceptedSocket);
    ///////////////////////////////////////////////////////////////////////
    // Function: Accept
    //
    //   Author: $author$
    //     Date: 4/6/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError Accept
#if defined(WIN32) 
// Windows
    (CEvSocket& connection, bool updateAcceptContext=false)
#else // defined(WIN32) 
// Unix
    (CEvSocket& connection) 
#endif // defined(WIN32)
    {
        EvError error = EV_ERROR_FAILED;
		SOCKADDR_IN sockAddrIn;
		socklen_t sockAddrInLen = sizeof(sockAddrIn);

		if (INVALID_SOCKET == m_attached)
			return EV_ERROR_NOT_ATTACHED;

		if (INVALID_SOCKET != connection.m_attached)
			return EV_ERROR_ALREADY_ATTACHED;

		if (INVALID_SOCKET != (connection.m_attached = accept
			(m_attached, (SOCKADDR*)(&sockAddrIn), &sockAddrInLen)))
            error = EV_ERROR_NONE;
		else 
        {
            DBE("() failed to accept error = %d\n", GET_SOCKET_ERROR(-1));
            return error;
        }

#if defined(WIN32) 
// Windows
        if (updateAcceptContext)
        if ((error = connection.
            UpdateAcceptContext(m_attached)))
        {
            DBE("() failed to update accept context\n");
            connection.Close();
        }
#endif // defined(WIN32)
        return error;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: Connect
    //
    //   Author: $author$
    //     Date: 4/6/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError Connect
    (USHORT port, const char* host=0) 
    {
        EvError error = EV_ERROR_FAILED;
		SOCKADDR_IN sockAddrIn;
		HOSTENT *hostEnt;
		UINT32 addr;
		int err;

		if (INVALID_SOCKET == m_attached)
			return EV_ERROR_NOT_ATTACHED;

		if (INVALID_SOCKET_PORT == (SOCKET_PORT)(port))
			port = m_port;

		if (!(hostEnt = gethostbyname(host)))
		{
			DBE("() Failed to gethostbyname \"%s\"\n", host);
			return error;
		}

		addr = ntohl(*(UINT32*)(hostEnt->h_addr));

		sockAddrIn.sin_addr.s_addr = htonl(addr);
		sockAddrIn.sin_family = m_family;
		sockAddrIn.sin_port = htons(port);

		if ((err = connect(m_attached, (SOCKADDR*)(&sockAddrIn), sizeof(sockAddrIn))))
		{
			DBE("() failed to connect error = %d\n", GET_SOCKET_ERROR(err));
			return error;
		}
		
		m_addr = addr;
		m_port = port;
		error = EV_ERROR_NONE;
        return error;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: SetDelayOpt
    //
    //   Author: $author$
    //     Date: 5/15/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError SetDelayOpt
    (bool on=true) 
    {
        int optValue = IN_SOCKET_NODELAY_ON(!on);
        EvError error = SetOpt
        (IPPROTO_TCP, TCP_NODELAY,
         &optValue, ((SOCKET_OPT_LENGTH)sizeof(optValue)));
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: GetDelayOpt
    //
    //   Author: $author$
    //     Date: 5/15/2007
    ///////////////////////////////////////////////////////////////////////
    virtual int GetDelayOpt() const 
    {
        int on;
        SOCKET_OPT_LENGTH length;
        EvError error;

        length = ((SOCKET_OPT_LENGTH)sizeof(on));

        if ((error = GetOpt
            (IPPROTO_TCP, TCP_NODELAY, &on, length)))
            return -error;

        on = !OUT_SOCKET_NODELAY_ON(on);
        return on;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: SetNoDelayOpt
    //
    //   Author: $author$
    //     Date: 5/15/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError SetNoDelayOpt
    (bool on=true) 
    {
        int optValue = IN_SOCKET_NODELAY_ON(on);
        EvError error = SetOpt
        (IPPROTO_TCP, TCP_NODELAY,
         &optValue, ((SOCKET_OPT_LENGTH)sizeof(optValue)));
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: GetNoDelayOpt
    //
    //   Author: $author$
    //     Date: 5/15/2007
    ///////////////////////////////////////////////////////////////////////
    virtual int GetNoDelayOpt() const 
    {
        int on;
        SOCKET_OPT_LENGTH length;
        EvError error;

        length = ((SOCKET_OPT_LENGTH)sizeof(on));

        if ((error = GetOpt
            (IPPROTO_TCP, TCP_NODELAY, &on, length)))
            return -error;

        on = OUT_SOCKET_NODELAY_ON(on);
        return on;
    }

#if defined(WIN32) 
// Windows
    ///////////////////////////////////////////////////////////////////////
    // Function: UpdateAcceptContext
    //
    //   Author: $author$
    //     Date: 5/15/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError UpdateAcceptContext
    (SOCKET socket) 
    {
        SOCKET optValue = socket;
        EvError error = SetOpt
        (SOL_SOCKET, SO_UPDATE_ACCEPT_CONTEXT,
         &optValue, ((SOCKET_OPT_LENGTH)sizeof(optValue)));
        return error;
    }
#endif // defined(WIN32)

    ///////////////////////////////////////////////////////////////////////
    // Function: SetLingerOpt
    //
    //   Author: $author$
    //     Date: 5/15/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError SetLingerOpt
    (bool on=true, int lingerSeconds=-1) 
    {
        SOCKET_LINGER linger;
        EvError error;

        if (0 > lingerSeconds)
            lingerSeconds = DEFAULT_SOCKET_LINGER_SECONDS;

        SET_SOCKET_LINGER_ON(linger, on);
        SET_SOCKET_LINGER_SECONDS(linger, lingerSeconds);

        error = SetOpt
        (SOL_SOCKET, SO_LINGER, 
         &linger, ((SOCKET_OPT_LENGTH)sizeof(linger)));
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: GetLingerOpt
    //
    //   Author: $author$
    //     Date: 5/15/2007
    ///////////////////////////////////////////////////////////////////////
    virtual int GetLingerOpt
    (int& lingerSeconds) const 
    {
        SOCKET_LINGER linger;
        SOCKET_OPT_LENGTH length;
        EvError error;
        int on;

        length = ((SOCKET_OPT_LENGTH)sizeof(linger));

        if ((error = GetOpt
            (SOL_SOCKET, SO_LINGER, &linger, length)))
            return -error;

        on = GET_SOCKET_LINGER_ON(linger);
        lingerSeconds = GET_SOCKET_LINGER_SECONDS(linger);
        return on;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: SetDontLingerOpt
    //
    //   Author: $author$
    //     Date: 5/15/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError SetDontLingerOpt
    (bool on=true) 
    {
        SOCKET_LINGER linger;
        EvError error;

        SET_SOCKET_DONT_LINGER_ON(linger, on);
        SET_SOCKET_LINGER_SECONDS(linger, 0);

        error = SetOpt
        (SOL_SOCKET, SO_LINGER, &linger, sizeof(linger));
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: GetDontLingerOpt
    //
    //   Author: $author$
    //     Date: 5/15/2007
    ///////////////////////////////////////////////////////////////////////
    virtual int GetDontLingerOpt() const 
    {
        SOCKET_LINGER linger;
        SOCKET_OPT_LENGTH length;
        EvError error;
        int on;

        length = ((SOCKET_OPT_LENGTH)sizeof(linger));

        if ((error = GetOpt
            (SOL_SOCKET, SO_LINGER, &linger, length)))
            return -error;

        on = GET_SOCKET_DONT_LINGER_ON(linger);
        return on;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: SetOpt
    //
    //   Author: $author$
    //     Date: 5/14/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError SetOpt
    (SOCKET_OPT_LEVEL level,
     SOCKET_OPT_NAME name,
     const SOCKET_OPT_VALUE* value,
     SOCKET_OPT_LENGTH length) 
    {
        EvError error = EV_ERROR_FAILED;
        int err;

		if (INVALID_SOCKET == m_attached)
			return EV_ERROR_NOT_ATTACHED;

        if ((err = setsockopt
            (m_attached, level, name,
             (const char*)value, length)))
			DBE("() failed to setsockopt error = %d\n", GET_SOCKET_ERROR(err));
        else error = EV_ERROR_NONE;

        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: GetOpt
    //
    //   Author: $author$
    //     Date: 5/14/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError GetOpt
    (SOCKET_OPT_LEVEL level,
     SOCKET_OPT_NAME name,
     SOCKET_OPT_VALUE* value,
     SOCKET_OPT_LENGTH& length) const 
    {
        EvError error = EV_ERROR_FAILED;
        int err;

		if (INVALID_SOCKET == m_attached)
			return EV_ERROR_NOT_ATTACHED;

        if ((err = getsockopt
            (m_attached, level, name,
             (char*)value, &length)))
			DBE("() failed to getsockopt error = %d\n", GET_SOCKET_ERROR(err));
        else error = EV_ERROR_NONE;

        return error;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: WriteAll
    //
    //   Author: $author$
    //     Date: 4/16/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG WriteAll
    (const void* buffer, LONG length) 
    {
        const char* chars = (const char*)(buffer);
        LONG count = 0;
		LONG sent, remain;

		for (remain = length; remain; remain -= sent)
		{
			if (0 > (sent = Write(chars, remain)))
				break;
			count += sent;
			chars += sent;
		}
        return count;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: ReadAll
    //
    //   Author: $author$
    //     Date: 4/16/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG ReadAll
    (void* buffer, ULONG size) 
    {
        char* chars = (char*)(buffer);
        LONG count = 0;
		LONG recved;
        ULONG remain;

		for (remain = size; remain; remain -= recved)
		{
			if (0 >= (recved = Read(chars, remain)))
				break;
			count += recved;
			chars += recved;
		}
        return count;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: Write
    //
    //   Author: $author$
    //     Date: 4/16/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG Write
    (const void* buffer, LONG length) 
    {
        const char* chars = (const char*)(buffer);
		LONG sent;

		if (0 > (sent = send(m_attached, chars, length, 0)))
		{
			DBE("() failed error = %d\n", GET_SOCKET_ERROR(sent));
			return -EV_ERROR_WRITE;
		}
        return sent;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: Read
    //
    //   Author: $author$
    //     Date: 4/16/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG Read
    (void* buffer, ULONG size) 
    {
        char* chars = (char*)(buffer);
		LONG recved;

		if (0 > (recved = recv(m_attached, chars, size, 0)))
		{
			DBE("() failed error = %d\n", GET_SOCKET_ERROR(recved));
			return -EV_ERROR_READ;
		}
        return recved;
    }
};

///////////////////////////////////////////////////////////////////////
//  Class: CEvSocketReader
//
// Author: $author$
//   Date: 4/16/2007
///////////////////////////////////////////////////////////////////////
class CEvSocketReader
: public CEvCharReader
{
public:
    typedef CEvCharReader CExtends;
    typedef CEvSocketReader CDerives;

    CEvSocket& m_socket;

    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvSocketReader
    //
    //       Author: $author$
    //         Date: 4/16/2007
    ///////////////////////////////////////////////////////////////////////
    CEvSocketReader(CEvSocket& socket)
    : m_socket(socket)
    {
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: Read
    //
    //   Author: $author$
    //     Date: 4/16/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG Read
    (char* chars, ULONG size) 
    {
        LONG count = m_socket.Read(chars, size);
        return count;
    }
};

///////////////////////////////////////////////////////////////////////
//  Class: CEvSocketWriter
//
// Author: $author$
//   Date: 4/16/2007
///////////////////////////////////////////////////////////////////////
class CEvSocketWriter
: public CEvCharWriter
{
public:
    typedef CEvCharWriter CExtends;
    typedef CEvSocketWriter CDerives;

    CEvSocket& m_socket;

    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvSocketWriter
    //
    //       Author: $author$
    //         Date: 4/16/2007
    ///////////////////////////////////////////////////////////////////////
    CEvSocketWriter(CEvSocket& socket)
    : m_socket(socket)
    {
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: Write
    //
    //   Author: $author$
    //     Date: 4/16/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG Write
    (const char* chars, LONG length) 
    {
        LONG count = m_socket.Write(chars, length);
        return count;
    }
};

///////////////////////////////////////////////////////////////////////
//  Class: CEvSocketReference
//
// Author: $author$
//   Date: 4/8/2007
///////////////////////////////////////////////////////////////////////
class CEvSocketReference
: public CEvReference<CEvSocket>
{
public:
    typedef CEvReference<CEvSocket> CExtends;
    typedef CEvSocketReference CDerives;
    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvSocketReference
    //
    //       Author: $author$
    //         Date: 4/8/2007
    ///////////////////////////////////////////////////////////////////////
    CEvSocketReference(CEvSocket* referenced=0)
    : CExtends(referenced)
    {
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: Close
    //
    //   Author: $author$
    //     Date: 4/8/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError Close() 
    {
        EvError error = EV_ERROR_NOT_REFERENCED;
        if (m_referenced)
            error = m_referenced->Close();
        return error;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: Write
    //
    //   Author: $author$
    //     Date: 4/16/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG Write
    (const void* buffer, LONG length) 
    {
        LONG count = -EV_ERROR_FAILED;
        if (m_referenced)
            count = m_referenced->Write(buffer, length);
        return count;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: Read
    //
    //   Author: $author$
    //     Date: 4/16/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG Read
    (void* buffer, ULONG size) 
    {
        LONG count = -EV_ERROR_FAILED;
        if (m_referenced)
            count = m_referenced->Read(buffer, size);
        return count;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: SetNoDelayOpt
    //
    //   Author: $author$
    //     Date: 8/1/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError SetNoDelayOpt
    (bool on=true) 
    {
        EvError error = EV_ERROR_FAILED;
        if (m_referenced)
            error = m_referenced->SetNoDelayOpt(on);
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: SetDontLingerOpt
    //
    //   Author: $author$
    //     Date: 8/1/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError SetDontLingerOpt
    (bool on=true) 
    {
        EvError error = EV_ERROR_FAILED;
        if (m_referenced)
            error = m_referenced->SetDontLingerOpt(on);
        return error;
    }

    ///////////////////////////////////////////////////////////////////////
    // Operator: =
    //
    //   Author: $author$
    //     Date: 4/9/2007
    ///////////////////////////////////////////////////////////////////////
    virtual CEvSocketReference& operator =
    (const CEvSocketReference& reference) 
    {
        EvError error = EV_ERROR_NOT_REFERENCED;
        if (reference)
            error = Set(*reference.m_referenced);
        if (error && (EV_ERROR_NOT_REFERENCED != error))
            throw(error);
        return *this;
    }
    ///////////////////////////////////////////////////////////////////////
    // Operator: *
    //
    //   Author: $author$
    //     Date: 8/1/2007
    ///////////////////////////////////////////////////////////////////////
    virtual CEvSocket& operator*() const
    {
        return *m_referenced;
    }
    ///////////////////////////////////////////////////////////////////////
    // Operator: ->
    //
    //   Author: $author$
    //     Date: 8/1/2007
    ///////////////////////////////////////////////////////////////////////
    virtual CEvSocket* operator->() const
    {
        return m_referenced;
    }
};

#endif // _CEVSOCKET_HPP
