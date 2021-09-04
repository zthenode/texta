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
 *   File: csocket.hxx
 *
 * Author: $author$
 *   Date: 1/16/2008
 **********************************************************************
 */
#ifndef _CSOCKET_HXX
#define _CSOCKET_HXX

#include "csocketstream.hxx"
#include "csocketinterface.hxx"
#include "creference.hxx"
#include "cdebug.hxx"

class cSocketReference;

#undef CDB_CLASS
#define CDB_CLASS "cSocketT"
/**
 **********************************************************************
 *  Class: cSocketT
 *
 * Author: $author$
 *   Date: 1/16/2008
 **********************************************************************
 */
template
<class TDerives,
 class TWhat=CHAR,
 class TSize=TSIZE,
 class TLength=TLENGTH,
 TLength VUndefinedLength=UNDEFINED_LENGTH,
 class TReference=cSocketReference,
 class TImplements=cSocketInterface,
 class TExtends=cSocketStream>
 
class cSocketT
: virtual public TImplements,
  public TExtends
{
public:
    typedef TImplements cImplements;
    typedef TExtends cExtends;
    typedef TDerives cDerives;

	SOCKET_FAMILY m_family;
	SOCKET_TYPE m_type;
	SOCKET_PROTOCOL m_protocol;
	SOCKET_ADDR m_addr;
	SOCKET_PORT m_port;
    int m_backlog;

    /**
     **********************************************************************
     * Constructor: cSocketT
     *
     *      Author: $author$
     *        Date: 1/16/2008
     **********************************************************************
     */
    cSocketT
    (SOCKET attached=INVALID_SOCKET, 
	 SOCKET_PORT port = INVALID_SOCKET_PORT,
	 SOCKET_ADDR addr = INADDR_ANY,
	 SOCKET_FAMILY family = AF_INET,
	 SOCKET_TYPE type = SOCK_STREAM,
	 SOCKET_PROTOCOL protocol = IPPROTO_TCP,
     int backlog = DEFAULT_SOCKET_BACKLOG) 
    : cExtends(attached),
      m_family(family),
	  m_type(type),
	  m_protocol(protocol),
	  m_addr(addr),
	  m_port(port),
      m_backlog(backlog)
    {
    }
    /**
     **********************************************************************
     * Destructor: cSocketT
     *
     *     Author: $author$
     *       Date: 1/16/2008
     **********************************************************************
     */
    virtual ~cSocketT()
    {
        eError error;
        if (INVALID_SOCKET != CTHIS m_attached)
        if ((error = Close()))
            throw(error);
    }

    /**
     **********************************************************************
     * Function: Open
     *
     *   Author: $author$
     *     Date: 1/16/2008
     **********************************************************************
     */
    virtual eError Open
    (bool onlyClosed=false) 
    {
        eError error = Open
        (m_family,  m_type, m_protocol, onlyClosed);
        return error;
    }
    /**
     **********************************************************************
     * Function: Open
     *
     *   Author: $author$
     *     Date: 1/16/2008
     **********************************************************************
     */
    virtual eError Open
    (SOCKET_FAMILY family, 
     SOCKET_TYPE type, 
     SOCKET_PROTOCOL protocol,
     bool onlyClosed=false) 
    {
        eError error = e_ERROR_FAILED;

        if ((INVALID_SOCKET != CTHIS m_attached) && onlyClosed)
            return e_ERROR_ALREADY_ATTACHED;

        if (INVALID_SOCKET != (CTHIS m_attached = cplatform_socket
            (family, type, protocol)))
            error = e_ERROR_NONE;

        return error;
    }
    /**
     **********************************************************************
     * Function: Close
     *
     *   Author: $author$
     *     Date: 1/16/2008
     **********************************************************************
     */
    virtual eError Close
    (bool onlyOpened=false) 
    {
        eError error = e_ERROR_FAILED;
        int err;

        if (INVALID_SOCKET == CTHIS m_attached)
        if (onlyOpened)
            return e_ERROR_NOT_ATTACHED;
        else return e_ERROR_NONE;

		if ((err = cplatform_closesocket(m_attached)))
			CDBE("() failed to close socket error = %d\n", GET_SOCKET_ERROR(err));
        else error = e_ERROR_NONE;

        m_attached = INVALID_SOCKET;
        return error;
    }

    /**
     **********************************************************************
     * Function: Bind
     *
     *   Author: $author$
     *     Date: 2/18/2008
     **********************************************************************
     */
    virtual eError Bind
    (SOCKET_PORT port, const char* host=0) 
    {
        eError error = e_ERROR_FAILED;
		SOCKADDR_IN sockAddrIn;

        if (INVALID_SOCKET == CTHIS m_attached)
            return e_ERROR_NOT_ATTACHED;

        if (host)
            return e_ERROR_NOT_IMPLEMENTED;

		if (INVALID_SOCKET_PORT == port)
            port = m_port;

		sockAddrIn.sin_family = m_family;
		sockAddrIn.sin_port = htons(port);
		sockAddrIn.sin_addr.s_addr = htonl(m_addr);

        error = bind
        (m_attached, (SOCKADDR*)(&sockAddrIn), sizeof(sockAddrIn));
        return error;
    }
    /**
     **********************************************************************
     * Function: Bind
     *
     *   Author: $author$
     *     Date: 2/18/2008
     **********************************************************************
     */
    virtual eError Bind
    (const SOCKADDR *addr, SOCKLEN addrlen) 
    {
        eError error = e_ERROR_FAILED;
        int err;

        if (INVALID_SOCKET == CTHIS m_attached)
            return e_ERROR_NOT_ATTACHED;

		if ((err = cplatform_bind(CTHIS m_attached, addr, addrlen)))
			CDBE("() failed to bind socket error = %d\n", GET_SOCKET_ERROR(err));
        else error = e_ERROR_NONE;
        return error;
    }
    /**
     **********************************************************************
     * Function: Listen
     *
     *   Author: $author$
     *     Date: 2/18/2008
     **********************************************************************
     */
    virtual eError Listen() 
    {
        eError error = Listen(m_backlog);
        return error;
    }
    /**
     **********************************************************************
     * Function: Listen
     *
     *   Author: $author$
     *     Date: 2/18/2008
     **********************************************************************
     */
    virtual eError Listen(int backlog) 
    {
        eError error = e_ERROR_FAILED;
        int err;

        if (INVALID_SOCKET == CTHIS m_attached)
            return e_ERROR_NOT_ATTACHED;

		if ((err = cplatform_listen(CTHIS m_attached, backlog)))
			CDBE("() failed to listen socket error = %d\n", GET_SOCKET_ERROR(err));
        else error = e_ERROR_NONE;
        return error;
    }

    /**
     **********************************************************************
     * Function: Accept
     *
     *   Author: $author$
     *     Date: 2/19/2008
     **********************************************************************
     */
    virtual TReference Accept
    (eError& error, bool updateAcceptContext=false);
    /**
     **********************************************************************
     * Function: Reject
     *
     *   Author: $author$
     *     Date: 2/19/2008
     **********************************************************************
     */
    virtual eError Reject(TReference& rsock);
    /**
     **********************************************************************
     * Function: Accept
     *
     *   Author: $author$
     *     Date: 2/19/2008
     **********************************************************************
     */
    virtual eError Accept
    (cDerives& sock, bool onlyClosed=false,
     bool updateAcceptContext=false)
    {
        eError error = e_ERROR_FAILED;
        eError error2;
        SOCKET attached;
		SOCKADDR_IN sockAddrIn;
		SOCKLEN sockAddrInLen = sizeof(sockAddrIn);
        int err;

        if (INVALID_SOCKET == CTHIS m_attached)
            return e_ERROR_NOT_ATTACHED;

        if (INVALID_SOCKET != sock.Attached())
        if (onlyClosed)
            return e_ERROR_ALREADY_ATTACHED;
        else
        if ((error2 = sock.Close(true)))
        {
            CDBE("() failed to close socket to accept\n");
            return error;
        }

		if (INVALID_SOCKET == (attached = cplatform_accept
			(m_attached, (SOCKADDR*)(&sockAddrIn), &sockAddrInLen)))
            CDBE("() failed on accept() error = %d\n", GET_SOCKET_ERROR(-1));
        else
        if ((error2 = sock.Attach(attached)))
        {
            CDBE("() failed to attach accepted socket\n");
            if ((err = cplatform_closesocket(attached)))
                CDBE("() failed on closesocket() error = %d\n", GET_SOCKET_ERROR(err));
        }
        else
        error = e_ERROR_NONE;
        return error;
    }
    /**
     **********************************************************************
     * Function: NewInstance
     *
     *   Author: $author$
     *     Date: 2/20/2008
     **********************************************************************
     */
    virtual cDerives* NewInstance(eError& error) 
    {
        cDerives* instance = 0;
        error = e_ERROR_NOT_IMPLEMENTED;
        return instance;
    }
    /**
     **********************************************************************
     * Function: DeleteInstance
     *
     *   Author: $author$
     *     Date: 2/20/2008
     **********************************************************************
     */
    virtual eError DeleteInstance() 
    {
        eError error = e_ERROR_NOT_IMPLEMENTED;
        return error;
    }
    /**
     **********************************************************************
     * Function: Send
     *
     *   Author: $author$
     *     Date: 2/29/2008
     **********************************************************************
     */
    virtual TLength Send
    (const TWhat* what, TLength length=VUndefinedLength) 
    {
        TLength count = -e_ERROR_FAILED;
        SOCKET_SSIZE_T size;

        if (INVALID_SOCKET == CTHIS m_attached)
            return e_ERROR_NOT_ATTACHED;

        if (0 > length)
            return e_ERROR_NOT_IMPLEMENTED;

        if (0 <= (size = cplatform_send
            (m_attached, what, sizeof(TWhat)*length, 0)))
            count = (TLength)(size);
        return count;
    }
    /**
     **********************************************************************
     * Function: Recv
     *
     *   Author: $author$
     *     Date: 2/29/2008
     **********************************************************************
     */
    virtual TLength Recv
    (TWhat* what, TSize size) 
    {
        TLength count = -e_ERROR_FAILED;
        SOCKET_SSIZE_T length;

        if (INVALID_SOCKET == CTHIS m_attached)
            return e_ERROR_NOT_ATTACHED;

        if (0 <= (length = cplatform_recv
            (m_attached, what, sizeof(TWhat)*size, 0)))
            count = (TLength)(length);
        return count;
    }
    /**
     **********************************************************************
     * Function: Write
     *
     *   Author: $author$
     *     Date: 2/29/2008
     **********************************************************************
     */
    virtual TLength Write
    (const TWhat* what, TLength length=VUndefinedLength) 
    {
        TLength count,count2;

        if (0 > length)
            return e_ERROR_NOT_IMPLEMENTED;

        for (count=0; count<length; count+=count2)
        {
            if (0 >= (count2 = Send(what+count, length-count)))
            {
                if (0 > count2)
                    count = count2;
                else count = -e_ERROR_FAILED;
                break;
            }
        }
        return count;
    }
    /**
     **********************************************************************
     * Function: Read
     *
     *   Author: $author$
     *     Date: 2/29/2008
     **********************************************************************
     */
    virtual TLength Read
    (TWhat* what, TSize size) 
    {
        TLength length = (TLength)(size);
        TLength count,count2;
        for (count=0; count<length; count+=count2)
        {
            if (0 >= (count2 = Recv(what+count, length-count)))
            {
                if (0 > count2)
                    count = count2;
                break;
            }
        }
        return count;
    }
};
#undef CDB_CLASS

class cCharSocketReference;
class cBYTESocketReference;
class cTCHARSocketReference;
class cWCHARSocketReference;

/**
 **********************************************************************
 *  Class: cSocket
 *
 * Author: $author$
 *   Date: 2/19/2008
 **********************************************************************
 */
class cSocket
: public cSocketT
  <cSocket, CHAR, TSIZE, TLENGTH, UNDEFINED_LENGTH, 
   cSocketReference, cSocketInterface, cSocketStream>
{
public:
    typedef cSocketT
    <cSocket, CHAR, TSIZE, TLENGTH, UNDEFINED_LENGTH, 
     cSocketReference, cSocketInterface, cSocketStream> cExtends;
    /**
     **********************************************************************
     * Function: NewInstance
     *
     *   Author: $author$
     *     Date: 2/20/2008
     **********************************************************************
     */
    virtual cSocket* NewInstance(eError& error) 
    {
        cSocket* instance = new cSocket();
        error = e_ERROR_NONE;
        return instance;
    }
    /**
     **********************************************************************
     * Function: DeleteInstance
     *
     *   Author: $author$
     *     Date: 2/19/2008
     **********************************************************************
     */
    virtual eError DeleteInstance()
    {
        delete this;
        return e_ERROR_NONE;
    }
};
/**
 **********************************************************************
 *  Class: cCharSocket
 *
 * Author: $author$
 *   Date: 2/20/2008
 **********************************************************************
 */
class cCharSocket
: public cSocketT
<cCharSocket, char, TSIZE, TLENGTH, UNDEFINED_LENGTH, 
cCharSocketReference, cCharSocketInterface, cCharSocketStream>
{
public:
    typedef cSocketT
<cCharSocket, char, TSIZE, TLENGTH, UNDEFINED_LENGTH, 
cCharSocketReference, cCharSocketInterface, cCharSocketStream> cExtends;
    typedef cSocket cDerives;
    /**
     **********************************************************************
     * Function: DeleteInstance
     *
     *   Author: $author$
     *     Date: 2/20/2008
     **********************************************************************
     */
    virtual eError DeleteInstance() 
    {
        eError error = e_ERROR_NONE;
        return error;
    }
};
/**
 **********************************************************************
 *  Class: cBYTESocket
 *
 * Author: $author$
 *   Date: 2/20/2008
 **********************************************************************
 */
class cBYTESocket
: public cSocketT
<cBYTESocket, BYTE, TSIZE, TLENGTH, UNDEFINED_LENGTH, 
cBYTESocketReference, cBYTESocketInterface, cBYTESocketStream>
{
public:
    typedef cSocketT
<cBYTESocket, BYTE, TSIZE, TLENGTH, UNDEFINED_LENGTH, 
cBYTESocketReference, cBYTESocketInterface, cBYTESocketStream> cExtends;
    typedef cSocket cDerives;
    /**
     **********************************************************************
     * Function: DeleteInstance
     *
     *   Author: $author$
     *     Date: 2/20/2008
     **********************************************************************
     */
    virtual eError DeleteInstance() 
    {
        eError error = e_ERROR_NONE;
        return error;
    }
};
/**
 **********************************************************************
 *  Class: cTCHARSocket
 *
 * Author: $author$
 *   Date: 2/20/2008
 **********************************************************************
 */
class cTCHARSocket
: public cSocketT
<cTCHARSocket, TCHAR, TSIZE, TLENGTH, UNDEFINED_LENGTH, 
cTCHARSocketReference, cTCHARSocketInterface, cTCHARSocketStream>
{
public:
    typedef cSocketT
<cTCHARSocket, TCHAR, TSIZE, TLENGTH, UNDEFINED_LENGTH, 
cTCHARSocketReference, cTCHARSocketInterface, cTCHARSocketStream> cExtends;
    typedef cSocket cDerives;
    /**
     **********************************************************************
     * Function: DeleteInstance
     *
     *   Author: $author$
     *     Date: 2/20/2008
     **********************************************************************
     */
    virtual eError DeleteInstance() 
    {
        eError error = e_ERROR_NONE;
        return error;
    }
};
/**
 **********************************************************************
 *  Class: cWCHARSocket
 *
 * Author: $author$
 *   Date: 2/20/2008
 **********************************************************************
 */
class cWCHARSocket
: public cSocketT
<cWCHARSocket, WCHAR, TSIZE, TLENGTH, UNDEFINED_LENGTH, 
cWCHARSocketReference, cWCHARSocketInterface, cWCHARSocketStream>
{
public:
    typedef cSocketT
<cWCHARSocket, WCHAR, TSIZE, TLENGTH, UNDEFINED_LENGTH, 
cWCHARSocketReference, cWCHARSocketInterface, cWCHARSocketStream> cExtends;
    typedef cSocket cDerives;
    /**
     **********************************************************************
     * Function: DeleteInstance
     *
     *   Author: $author$
     *     Date: 2/20/2008
     **********************************************************************
     */
    virtual eError DeleteInstance() 
    {
        eError error = e_ERROR_NONE;
        return error;
    }
};

/**
 **********************************************************************
 *  Class: cSocketReference
 *
 * Author: $author$
 *   Date: 2/19/2008
 **********************************************************************
 */
class cSocketReference
: public cReferenceT<cSocket, cReferenced>
{
public:
    typedef cReferenceT<cSocket, cReferenced> cExtends;
    typedef cSocketReference cDerives;
};
/**
 **********************************************************************
 *  Class: cCharSocketReference
 *
 * Author: $author$
 *   Date: 2/19/2008
 **********************************************************************
 */
class cCharSocketReference
: public cReferenceT<cCharSocket, cReferenced>
{
    typedef cReferenceT<cCharSocket, cReferenced> cExtends;
    typedef cSocketReference cDerives;
};
/**
 **********************************************************************
 *  Class: cBYTESocketReference
 *
 * Author: $author$
 *   Date: 2/19/2008
 **********************************************************************
 */
class cBYTESocketReference
: public cReferenceT<cBYTESocket, cReferenced>
{
    typedef cReferenceT<cBYTESocket, cReferenced> cExtends;
    typedef cSocketReference cDerives;
};
/**
 **********************************************************************
 *  Class: cTCHARSocketReference
 *
 * Author: $author$
 *   Date: 2/19/2008
 **********************************************************************
 */
class cTCHARSocketReference
: public cReferenceT<cTCHARSocket, cReferenced>
{
    typedef cReferenceT<cTCHARSocket, cReferenced> cExtends;
    typedef cSocketReference cDerives;
};
/**
 **********************************************************************
 *  Class: cWCHARSocketReference
 *
 * Author: $author$
 *   Date: 2/19/2008
 **********************************************************************
 */
class cWCHARSocketReference
: public cReferenceT<cWCHARSocket, cReferenced>
{
    typedef cReferenceT<cWCHARSocket, cReferenced> cExtends;
    typedef cSocketReference cDerives;
};

#undef CDB_CLASS
#define CDB_CLASS "cSocketT"
/**
 **********************************************************************
 * Function: cSocketT::Accept
 *
 *   Author: $author$
 *     Date: 2/19/2008
 **********************************************************************
 */
template
<class TDerives, class TWhat, class TSize, 
 class TLength, TLength VUndefinedLength, 
 class TReference, class TImplements, class TExtends>
 
TReference cSocketT
<TDerives, TWhat, TSize, TLength, VUndefinedLength,
 TReference, TImplements, TExtends>
::Accept(eError& error, bool updateAcceptContext) 
{
    eError error2;
    TReference sockReference;
    cDerives* sock;
    error = e_ERROR_NONE;

    if (!(sock = NewInstance(error)))
        CDBE("() failed on NewInstance()\n");
    else
    if ((error = Accept(*sock, true, updateAcceptContext)))
    {
        if ((error2 = sock->DeleteInstance()))
            CDBE("() failed on sock->DeleteInstance()\n");
    }
    else
    sockReference.Set(sock);
    return sockReference;
}
/**
 **********************************************************************
 * Function: cSocketT::Reject
 *
 *   Author: $author$
 *     Date: 2/19/2008
 **********************************************************************
 */
template
<class TDerives, class TWhat, class TSize, 
 class TLength, TLength VUndefinedLength, 
 class TReference, class TImplements, class TExtends>
 
eError cSocketT
<TDerives, TWhat, TSize, TLength, VUndefinedLength,
 TReference, TImplements, TExtends>
::Reject(TReference& rsock) 
{
    eError error = e_ERROR_NOT_IMPLEMENTED;
    return error;
}
#undef CDB_CLASS
#endif /* _CSOCKET_HXX */
