///////////////////////////////////////////////////////////////////////
//   File: cevdmain.hpp
//
// Author: $author$
//   Date: 4/3/2007
//
//    $Id$
///////////////////////////////////////////////////////////////////////

#ifndef _CEVDMAIN_HPP
#define _CEVDMAIN_HPP

#include "cevtcpserver.hpp"
#include "cevthreadedqueuedrequestserver.hpp"
#include "cevmain.hpp"
#include "evdebug.h"
#include "cevmutex.hpp"
#include "cevsemaphore.hpp"
#include "evdebug.h"
#include "evd.h"

///////////////////////////////////////////////////////////////////////
//  Class: CEvDTcpRequestThread
//
// Author: $author$
//   Date: 4/6/2007
///////////////////////////////////////////////////////////////////////
class CEvDTcpRequestThread
: public CEvQueuedSocketRequestServletThread
{
public:
    typedef CEvQueuedSocketRequestServletThread CExtends;
    typedef CEvDTcpRequestThread CDerives;
};

///////////////////////////////////////////////////////////////////////
//  Typedef: CEvDTcpRequestThreadVector
//
//   Author: $author$
//     Date: 8/5/2007
///////////////////////////////////////////////////////////////////////
typedef ::std::vector<CEvDTcpRequestThread>
CEvDTcpRequestThreadVector;

///////////////////////////////////////////////////////////////////////
//  Typedef: CEvDTcpRequestThreadVectorIterator
//
//   Author: $author$
//     Date: 8/5/2007
///////////////////////////////////////////////////////////////////////
typedef CEvDTcpRequestThreadVector::iterator
CEvDTcpRequestThreadVectorIterator;

///////////////////////////////////////////////////////////////////////
//  Class: CEvDTcpServer
//
// Author: $author$
//   Date: 4/6/2007
///////////////////////////////////////////////////////////////////////
class CEvDTcpServer
: public CEvThreadedDllTcpServletServer
  <CEvDTcpRequestThread,
   CEvDTcpRequestThreadVector,
   CEvDTcpRequestThreadVectorIterator>
{
public:
    typedef CEvThreadedDllTcpServletServer
    <CEvDTcpRequestThread,
     CEvDTcpRequestThreadVector,
     CEvDTcpRequestThreadVectorIterator> CExtends;
    typedef CEvDTcpServer CDerives;

    CEvString m_dir;
    CEvString m_vcsDir;
    CEvString m_vcDir;
    CEvString m_ciDir;
    CEvString m_coDir;

    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvDTcpServer
    //
    //       Author: $author$
    //         Date: 4/6/2007
    ///////////////////////////////////////////////////////////////////////
    CEvDTcpServer() 
    : m_dir(DEFAULT_EVD_DIR),
      m_vcsDir(DEFAULT_EVD_EVCS_DIR),
      m_vcDir(DEFAULT_EVD_EVCS_VC_DIR),
      m_ciDir(DEFAULT_EVD_EVCS_CI_DIR),
      m_coDir(DEFAULT_EVD_EVCS_CO_DIR)
    {
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: GetPropertyCharsById
    //
    //   Author: $author$
    //     Date: 7/17/2007
    ///////////////////////////////////////////////////////////////////////
    virtual const char* GetPropertyCharsById
    (LONG& length,
     EvProperty::EvId id) const 
    {
        const char* chars = 0;
        length = -EV_ERROR_NOT_IMPLEMENTED;
        switch(id)
        {
        case EVD_PROPERTY_ID_EVD_DIR:
            chars = GetDir(length);
            break;
        case EVD_PROPERTY_ID_EVCS_DIR:
            chars = GetVcsDir(length);
            break;
        case EVD_PROPERTY_ID_EVCS_VC_DIR:
            chars = GetVcDir(length);
            break;
        case EVD_PROPERTY_ID_EVCS_CI_DIR:
            chars = GetCiDir(length);
            break;
        case EVD_PROPERTY_ID_EVCS_CO_DIR:
            chars = GetCoDir(length);
            break;
        }
        return chars;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: GetPropertyUnsignedById
    //
    //   Author: $author$
    //     Date: 7/17/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError GetPropertyUnsignedById
    (ULONG& value, EvProperty::EvId id) const 
    {
        EvError error = EV_ERROR_NOT_IMPLEMENTED;
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: GetPropertySignedById
    //
    //   Author: $author$
    //     Date: 7/17/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError GetPropertySignedById
    (LONG& value, EvProperty::EvId id) const 
    {
        EvError error = EV_ERROR_NOT_IMPLEMENTED;
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: GetPropertyBoolById
    //
    //   Author: $author$
    //     Date: 7/17/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError GetPropertyBoolById
    (bool& value, EvProperty::EvId id) const 
    {
        EvError error = EV_ERROR_NOT_IMPLEMENTED;
        return error;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: SetDir
    //
    //   Author: $author$
    //     Date: 7/27/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG SetDir
    (const char* chars,
     LONG length=-1) 
    {
        LONG count = m_dir.Assign(chars,length);
        return count;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: GetDir
    //
    //   Author: $author$
    //     Date: 7/27/2007
    ///////////////////////////////////////////////////////////////////////
    virtual const char* GetDir
    (LONG& length) const 
    {
        const char* chars = m_dir.Chars(length);
        return chars;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: SetVcsDir
    //
    //   Author: $author$
    //     Date: 7/27/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG SetVcsDir
    (const char* chars,
     LONG length=-1) 
    {
        LONG count = m_vcsDir.Assign(chars,length);
        return count;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: GetVcsDir
    //
    //   Author: $author$
    //     Date: 7/27/2007
    ///////////////////////////////////////////////////////////////////////
    virtual const char* GetVcsDir
    (LONG& length) const 
    {
        const char* chars = m_vcsDir.Chars(length);
        return chars;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: SetVcDir
    //
    //   Author: $author$
    //     Date: 8/17/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG SetVcDir
    (const char* chars,
     LONG length=-1) 
    {
        LONG count = m_vcDir.Assign(chars,length);
        return count;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: GetVcDir
    //
    //   Author: $author$
    //     Date: 8/17/2007
    ///////////////////////////////////////////////////////////////////////
    virtual const char* GetVcDir
    (LONG& length) const 
    {
        const char* chars = m_vcDir.Chars(length);
        return chars;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: SetCiDir
    //
    //   Author: $author$
    //     Date: 7/27/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG SetCiDir
    (const char* chars,
     LONG length=-1) 
    {
        LONG count = m_ciDir.Assign(chars,length);
        return count;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: GetCiDir
    //
    //   Author: $author$
    //     Date: 7/27/2007
    ///////////////////////////////////////////////////////////////////////
    virtual const char* GetCiDir
    (LONG& length) const 
    {
        const char* chars = m_ciDir.Chars(length);
        return chars;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: SetCoDir
    //
    //   Author: $author$
    //     Date: 7/27/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG SetCoDir
    (const char* chars,
     LONG length=-1) 
    {
        LONG count = m_coDir.Assign(chars,length);
        return count;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: GetCoDir
    //
    //   Author: $author$
    //     Date: 7/27/2007
    ///////////////////////////////////////////////////////////////////////
    virtual const char* GetCoDir
    (LONG& length) const 
    {
        const char* chars = m_coDir.Chars(length);
        return chars;
    }
};

///////////////////////////////////////////////////////////////////////
//  Class: CEvDMain
//
// Author: $author$
//   Date: 4/3/2007
///////////////////////////////////////////////////////////////////////
class CEvDMain
: public CEvMain
{
public:
    typedef CEvMain CExtends;
    typedef CEvDMain CDerives;

    USHORT m_tcpPort;
    UINT m_tcpThreads;
    const char* m_servletDllFilename;
    CEvString m_servletDllFilenameString;

    CEvDTcpServer m_tcpServer;

    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvDMain
    //
    //       Author: $author$
    //         Date: 4/6/2007
    ///////////////////////////////////////////////////////////////////////
    CEvDMain() 
    : m_tcpPort(DEFAULT_EVD_TCP_PORT),
      m_tcpThreads(DEFAULT_EVD_TCP_THREADS),
      m_servletDllFilename(DEFAULT_EVD_SERVLET_DLL_FILENAME)
    {
        EvError error;
        LONG length;

        if (0 > (length = SetHelpProduct(EVD_PRODUCT_LABEL)))
            throw(error = -length);

        if (0 > (length = SetHelpVersion(EVD_VERSION_LABEL)))
            throw(error = -length);

        if (0 > (length = SetServletDllFilename(DEFAULT_EVD_SERVLET_DLL_FILENAME)))
            throw(error = -length);
    }
    ///////////////////////////////////////////////////////////////////////
    // Destructor: ~CEvDMain
    //
    //      Author: $author$
    //        Date: 4/6/2007
    ///////////////////////////////////////////////////////////////////////
    virtual ~CEvDMain()
    {
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: Run
    //
    //    Author: $author$
    //      Date: 4/3/2007
    ///////////////////////////////////////////////////////////////////////
    virtual int Run
    (int argc,
     const char** argv,
     const char** env) 
    {
        int err = 0;

        if (!GetDidMain())
            return Help(argc, argv, env);
        return err;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: Runit
    //
    //    Author: $author$
    //      Date: 4/3/2007
    ///////////////////////////////////////////////////////////////////////
    virtual int Runit() 
    {
        int err = 0;
        EvError error;
        bool restart;

        SetDidMain();

		DBF("() in...\n");

        do
        {
            restart = false;

            if ((error = m_tcpServer.Start
                (m_tcpPort, m_tcpThreads, m_servletDllFilename)))
                DBE("() failed to start TCP server with %d threads\n", m_tcpThreads);

            else if ((error = m_tcpServer.Finish(restart)))
                    DBE("() failed to finish TCP server with %d threads\n", m_tcpThreads);
        }
        while(restart);

		DBF("() ...out\n");
        return err;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: SetServletDllFilename
    //
    //   Author: $author$
    //     Date: 7/14/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG SetServletDllFilename
    (const char* chars,
     LONG length=-1) 
    {
        if (0 < (length = m_servletDllFilenameString.Assign(chars,length)))
            m_servletDllFilename = m_servletDllFilenameString.Chars(length);
        return length;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: GetServletDllFilename
    //
    //   Author: $author$
    //     Date: 7/14/2007
    ///////////////////////////////////////////////////////////////////////
    virtual const char* GetServletDllFilename
    (LONG& length) const 
    {
        const char* chars = m_servletDllFilenameString.Chars(length);
        return chars;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: SetDir
    //
    //   Author: $author$
    //     Date: 7/27/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG SetDir
    (const char* chars,
     LONG length=-1) 
    {
        LONG count = m_tcpServer.SetDir(chars,length);
        return count;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: GetDir
    //
    //   Author: $author$
    //     Date: 7/27/2007
    ///////////////////////////////////////////////////////////////////////
    virtual const char* GetDir
    (LONG& length) const 
    {
        const char* chars = m_tcpServer.GetDir(length);
        return chars;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: SetVcsDir
    //
    //   Author: $author$
    //     Date: 7/27/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG SetVcsDir
    (const char* chars,
     LONG length=-1) 
    {
        LONG count = m_tcpServer.SetVcsDir(chars,length);
        return count;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: GetVcsDir
    //
    //   Author: $author$
    //     Date: 7/27/2007
    ///////////////////////////////////////////////////////////////////////
    virtual const char* GetVcsDir
    (LONG& length) const 
    {
        const char* chars = m_tcpServer.GetVcsDir(length);
        return chars;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: SetCiDir
    //
    //   Author: $author$
    //     Date: 7/27/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG SetCiDir
    (const char* chars,
     LONG length=-1) 
    {
        LONG count = m_tcpServer.SetCiDir(chars,length);
        return count;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: GetCiDir
    //
    //   Author: $author$
    //     Date: 7/27/2007
    ///////////////////////////////////////////////////////////////////////
    virtual const char* GetCiDir
    (LONG& length) const 
    {
        const char* chars = m_tcpServer.GetCiDir(length);
        return chars;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: SetCoDir
    //
    //   Author: $author$
    //     Date: 7/27/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG SetCoDir
    (const char* chars,
     LONG length=-1) 
    {
        LONG count = m_tcpServer.SetCoDir(chars,length);
        return count;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: GetCoDir
    //
    //   Author: $author$
    //     Date: 7/27/2007
    ///////////////////////////////////////////////////////////////////////
    virtual const char* GetCoDir
    (LONG& length) const 
    {
        const char* chars = m_tcpServer.GetCoDir(length);
        return chars;
    }
};
#endif // _CEVDMAIN_HPP
