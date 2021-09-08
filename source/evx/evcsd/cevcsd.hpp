///////////////////////////////////////////////////////////////////////
//   File: cevcsd.hpp
//
// Author: $author$
//   Date: 7/30/2007
//
//    $Id$
///////////////////////////////////////////////////////////////////////

#ifndef _CEVCSD_HPP
#define _CEVCSD_HPP

#include "cevtcpserver.hpp"
#include "cevthreadedqueuedrequestserver.hpp"
#include "cevcptcpservlet.hpp"
#include "evcsd.h"

///////////////////////////////////////////////////////////////////////
//  Class: CEvcpDTcpRequestThread
//
// Author: $author$
//   Date: 7/30/2007
///////////////////////////////////////////////////////////////////////
class CEvcpDTcpRequestThread
: public CEvQueuedSocketRequestServletThread
{
public:
    typedef CEvQueuedSocketRequestServletThread CExtends;
    typedef CEvcpDTcpRequestThread CDerives;
};

///////////////////////////////////////////////////////////////////////
//  Typedef: CEvcpDTcpRequestThreadVector
//
//   Author: $author$
//     Date: 8/1/2007
///////////////////////////////////////////////////////////////////////
typedef ::std::vector<CEvcpDTcpRequestThread>
CEvcpDTcpRequestThreadVector;

///////////////////////////////////////////////////////////////////////
//  Typedef: CEvcpDTcpRequestThreadVectorIterator
//
//   Author: $author$
//     Date: 8/1/2007
///////////////////////////////////////////////////////////////////////
typedef CEvcpDTcpRequestThreadVector::iterator 
CEvcpDTcpRequestThreadVectorIterator;

///////////////////////////////////////////////////////////////////////
//  Class: CEvcpDTcpServer
//
// Author: $author$
//   Date: 7/30/2007
///////////////////////////////////////////////////////////////////////
class CEvcpDTcpServer
: public CEvThreadedTcpServletServer
  <CEvcpDTcpRequestThread,
   CEvcpDTcpRequestThreadVector,
   CEvcpDTcpRequestThreadVectorIterator>
{
public:
    typedef CEvThreadedTcpServletServer
    <CEvcpDTcpRequestThread,
     CEvcpDTcpRequestThreadVector,
     CEvcpDTcpRequestThreadVectorIterator> CExtends;
    typedef CEvcpDTcpServer CDerives;

    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvcpDTcpServer
    //
    //       Author: $author$
    //         Date: 7/30/2007
    ///////////////////////////////////////////////////////////////////////
    CEvcpDTcpServer() 
    {
    }
    ///////////////////////////////////////////////////////////////////////
    // Destructor: ~CEvcpDTcpServer
    //
    //      Author: $author$
    //        Date: 7/30/2007
    ///////////////////////////////////////////////////////////////////////
    virtual ~CEvcpDTcpServer()
    {
    }
};

///////////////////////////////////////////////////////////////////////
//  Class: CEvcsDServlet
//
// Author: $author$
//   Date: 7/31/2007
///////////////////////////////////////////////////////////////////////
class CEvcsDServlet
: public CEvcpTcpServlet
{
public:
    typedef CEvcpTcpServlet CExtends;
    typedef CEvcsDServlet CDerives;

    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvcsDServlet
    //
    //       Author: $author$
    //         Date: 7/31/2007
    ///////////////////////////////////////////////////////////////////////
    CEvcsDServlet() 
    {
    }
    ///////////////////////////////////////////////////////////////////////
    // Destructor: ~CEvcsDServlet
    //
    //      Author: $author$
    //        Date: 7/31/2007
    ///////////////////////////////////////////////////////////////////////
    virtual ~CEvcsDServlet()
    {
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: DeleteInstance
    //
    //   Author: $author$
    //     Date: 7/31/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError DeleteInstance() 
    {
        EvError error = EV_ERROR_NONE;
        delete this;
        return error;
    }
};

#define DEFAULT_EVCSD_CI_DIRECTORY "EVCS/CI"
#define DEFAULT_EVCSD_CO_DIRECTORY "EVCS/CO"

///////////////////////////////////////////////////////////////////////
//  Class: CEvcsDServer
//
// Author: $author$
//   Date: 7/31/2007
///////////////////////////////////////////////////////////////////////
class CEvcsDServer
: public CEvcpDTcpServer
{
public:
    typedef CEvcpDTcpServer CExtends;
    typedef CEvcsDServer CDerives;

    CEvString m_ciDirectory;
    CEvString m_coDirectory;

    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvcsDServer
    //
    //       Author: $author$
    //         Date: 7/31/2007
    ///////////////////////////////////////////////////////////////////////
    CEvcsDServer
    (const char* ciDirectory=DEFAULT_EVCSD_CI_DIRECTORY,
     const char* coDirectory=DEFAULT_EVCSD_CO_DIRECTORY)
     : m_ciDirectory(ciDirectory),
       m_coDirectory(coDirectory)
    {
    }
    ///////////////////////////////////////////////////////////////////////
    // Destructor: ~CEvcsDServer
    //
    //      Author: $author$
    //        Date: 7/31/2007
    ///////////////////////////////////////////////////////////////////////
    virtual ~CEvcsDServer()
    {
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: AllocateServlet
    //
    //   Author: $author$
    //     Date: 7/31/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvTcpServlet* AllocateServlet(EvError& error) 
    {
        EvTcpServlet* servlet = 0;
        error = EV_ERROR_FAILED;
        if ((servlet = new CEvcsDServlet()))
            error = EV_ERROR_NONE;
        return servlet;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: FreeServlet
    //
    //   Author: $author$
    //     Date: 7/31/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError FreeServlet(EvTcpServlet& servlet) 
    {
        EvError error = servlet.DeleteInstance();
        return error;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: GetPropertyCharsById
    //
    //   Author: $author$
    //     Date: 7/31/2007
    ///////////////////////////////////////////////////////////////////////
    virtual const char* GetPropertyCharsById
    (LONG& length,
     EvProperty::EvId id) const 
    {
        const char* chars = 0;
        length = -EV_ERROR_NOT_IMPLEMENTED;
        switch(id)
        {
        case EVCSD_PROPERTY_ID_CI_DIRECTORY:
            chars = GetCiDirectory(length);
            break;
        case EVCSD_PROPERTY_ID_CO_DIRECTORY:
            chars = GetCoDirectory(length);
            break;
        }
        return chars;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: SetCiDirectory
    //
    //   Author: $author$
    //     Date: 7/31/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG SetCiDirectory
    (const char* chars,
     LONG length=-1) 
    {
        LONG count = m_ciDirectory.Assign(chars,length);
        return count;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: GetCiDirectory
    //
    //   Author: $author$
    //     Date: 7/31/2007
    ///////////////////////////////////////////////////////////////////////
    virtual const char* GetCiDirectory
    (LONG& length) const 
    {
        const char* chars = m_ciDirectory.Chars(length);
        return chars;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: SetCoDirectory
    //
    //   Author: $author$
    //     Date: 7/31/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG SetCoDirectory
    (const char* chars,
     LONG length=-1) 
    {
        LONG count = m_coDirectory.Assign(chars,length);
        return count;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: GetCoDirectory
    //
    //   Author: $author$
    //     Date: 7/31/2007
    ///////////////////////////////////////////////////////////////////////
    virtual const char* GetCoDirectory
    (LONG& length) const 
    {
        const char* chars = m_coDirectory.Chars(length);
        return chars;
    }
};

#endif // _CEVCSD_HPP
