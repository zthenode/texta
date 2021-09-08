///////////////////////////////////////////////////////////////////////
//   File: evc.cpp
//
// Author: $author$
//   Date: 5/10/2007
//
//    $Id$
///////////////////////////////////////////////////////////////////////

#include "cevcclient.hpp"
#include "cevmain.hpp"
#include "evplatform.h"
#include "evdebug.h"
#include "evc.h"

///////////////////////////////////////////////////////////////////////
//  Class: CEvcMain
//
// Author: $author$
//   Date: 5/10/2007
///////////////////////////////////////////////////////////////////////
class CEvcMain
: public CEvMain
{
public:
    typedef CEvMain CExtends;
    typedef CEvcMain CDerives;

    bool m_isBinary;
    bool m_isRecursive;

    CEvcClient m_evcClient;

    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvcMain
    //
    //       Author: $author$
    //         Date: 5/10/2007
    ///////////////////////////////////////////////////////////////////////
    CEvcMain() 
    : m_isBinary(false),
      m_isRecursive(false),
      m_evcClient
      (DEFAULT_EVD_TCP_HOST, 
       DEFAULT_EVD_TCP_PORT)
    {
        EvError error;
        LONG length;

        if (0 > (length = SetHelpProduct(EVC_PRODUCT_LABEL)))
            throw(error = -length);

        if (0 > (length = SetHelpVersion(EVC_VERSION_LABEL)))
            throw(error = -length);
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: Run
    //
    //   Author: $author$
    //     Date: 5/10/2007
    ///////////////////////////////////////////////////////////////////////
    virtual int Run
    (int argc,
     const char** argv,
     const char** env) 
    {
        int err = 0;

        if (!GetDidMain())
            return Help(argc, argv, env);

        DBF("() in...\n");
        DBF("() ...out\n");
        return err;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: CheckIn
    //
    //   Author: $author$
    //     Date: 5/10/2007
    ///////////////////////////////////////////////////////////////////////
    virtual int CheckIn
    (const char* localPath,
     const char* evcPath) 
    {
        int err = 1;
        EvError error;

        DBF("()\n \"%s\"\n --> \"%s\" in...\n", localPath, evcPath);

        SetDidMain();

        if ((error = m_evcClient.CheckIn
            (localPath, evcPath, m_isBinary, m_isRecursive)))
            DBE("() failed to check in \"%s\"\n", localPath);
        else err = 0;

        DBF("() ...out\n");
        return err;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: CheckOut
    //
    //   Author: $author$
    //     Date: 5/10/2007
    ///////////////////////////////////////////////////////////////////////
    virtual int CheckOut
    (const char* evcPath,
     const char* localPath) 
    {
        int err = 1;
        EvError error;

        DBF("()\n\"%s\" <--\n\"%s\" in...\n", localPath, evcPath);

        SetDidMain();

        if ((error = m_evcClient.CheckOut
            (evcPath, localPath, m_isBinary, m_isRecursive)))
            DBE("() failed to check out \"%s\"\n", evcPath);
        else err = 0;

        DBF("() ...out\n");
        return err;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: StopServer
    //
    //   Author: $author$
    //     Date: 5/11/2007
    ///////////////////////////////////////////////////////////////////////
    virtual int StopServer() 
    {
        int err = 1;
        EvError error;

        DBF("()in...\n");

        SetDidMain();
        if ((error = m_evcClient.StopServer()))
            DBE("() failed to stop server\n");

        DBF("() ...out\n");
        return err;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: Hello
    //
    //   Author: $author$
    //     Date: 8/14/2007
    ///////////////////////////////////////////////////////////////////////
    virtual int Hello() 
    {
        int err = 1;
        EvError error;

        DBF("()in...\n");

        SetDidMain();
        if ((error = m_evcClient.Hello()))
            DBE("() failed on hello\n");

        DBF("() ...out\n");
        return err;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: SetMatch
    //
    //   Author: $author$
    //     Date: 5/21/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG SetMatch
    (const char* chars,
     LONG length=-1) 
    {
        length = m_evcClient.SetMatch(chars,length);
        return length;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: GetMatch
    //
    //   Author: $author$
    //     Date: 5/21/2007
    ///////////////////////////////////////////////////////////////////////
    virtual const char* GetMatch
    (LONG& length) const 
    {
        const char* chars = m_evcClient.GetMatch(length);
        return chars;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: SetBinaryMatch
    //
    //   Author: $author$
    //     Date: 5/21/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG SetBinaryMatch
    (const char* chars,
     LONG length=-1) 
    {
        length = m_evcClient.SetBinaryMatch(chars,length);
        return length;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: GetBinaryMatch
    //
    //   Author: $author$
    //     Date: 5/21/2007
    ///////////////////////////////////////////////////////////////////////
    virtual const char* GetBinaryMatch
    (LONG& length) const 
    {
        const char* chars = m_evcClient.GetBinaryMatch(length);
        return chars;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: SetBlockSize
    //
    //   Author: $author$
    //     Date: 5/19/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG SetBlockSize
    (ULONG size) 
    {
        LONG blockSize = m_evcClient.SetBlockSize(size);
        return blockSize;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: GetBlockSize
    //
    //   Author: $author$
    //     Date: 5/19/2007
    ///////////////////////////////////////////////////////////////////////
    virtual ULONG GetBlockSize() const 
    {
        return m_evcClient.GetBlockSize();
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: SetIsBinary
    //
    //   Author: $author$
    //     Date: 5/19/2007
    ///////////////////////////////////////////////////////////////////////
    virtual int SetIsBinary
    (bool is=true) 
    {
        m_isBinary = is;
        return m_isBinary;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: GetIsBinary
    //
    //   Author: $author$
    //     Date: 5/19/2007
    ///////////////////////////////////////////////////////////////////////
    virtual bool GetIsBinary() const 
    {
        return m_isBinary;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: SetIsText
    //
    //   Author: $author$
    //     Date: 5/19/2007
    ///////////////////////////////////////////////////////////////////////
    virtual int SetIsText
    (bool is=true) 
    {
        m_isBinary = !is;
        return !m_isBinary;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: GetIsText
    //
    //   Author: $author$
    //     Date: 5/19/2007
    ///////////////////////////////////////////////////////////////////////
    virtual bool GetIsText() const 
    {
        return !m_isBinary;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: SetIsRecursive
    //
    //   Author: $author$
    //     Date: 5/22/2007
    ///////////////////////////////////////////////////////////////////////
    virtual int SetIsRecursive
    (bool is=true) 
    {
        m_isRecursive = is;
        return m_isRecursive;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: GetIsRecursive
    //
    //   Author: $author$
    //     Date: 5/22/2007
    ///////////////////////////////////////////////////////////////////////
    virtual bool GetIsRecursive() const 
    {
        return m_isRecursive;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: SetIsTestMode
    //
    //   Author: $author$
    //     Date: 7/12/2007
    ///////////////////////////////////////////////////////////////////////
    virtual int SetIsTestMode
    (bool is=true) 
    {
        int isTestMode = m_evcClient.SetIsTestMode(is);
        return isTestMode;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: GetIsTestMode
    //
    //   Author: $author$
    //     Date: 7/12/2007
    ///////////////////////////////////////////////////////////////////////
    virtual bool GetIsTestMode() const 
    {
        bool isTestMode = m_evcClient.GetIsTestMode();
        return isTestMode;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: SetTcpNoDelayOn
    //
    //   Author: $author$
    //     Date: 5/16/2007
    ///////////////////////////////////////////////////////////////////////
    virtual int SetTcpNoDelayOn(bool on=true) 
    {
        return m_evcClient.SetTcpNoDelayOn(on);
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: GetTcpNoDelayOn
    //
    //   Author: $author$
    //     Date: 5/16/2007
    ///////////////////////////////////////////////////////////////////////
    virtual bool GetTcpNoDelayOn() const 
    {
        return m_evcClient.GetTcpNoDelayOn();
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: SetHost
    //
    //   Author: $author$
    //     Date: 7/31/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG SetHost
    (const char* chars,
     LONG length=-1) 
    {
        LONG count = m_evcClient.SetHost(chars,length);
        return count;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: GetHost
    //
    //   Author: $author$
    //     Date: 7/31/2007
    ///////////////////////////////////////////////////////////////////////
    virtual const char* GetHost
    (LONG& length) const 
    {
        const char* chars = m_evcClient.GetHost(length);
        return chars;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: SetPort
    //
    //   Author: $author$
    //     Date: 7/31/2007
    ///////////////////////////////////////////////////////////////////////
    virtual SOCKET_PORT SetPort
    (SOCKET_PORT port) 
    {
        port = m_evcClient.SetPort(port);
        return port;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: GetPort
    //
    //   Author: $author$
    //     Date: 7/31/2007
    ///////////////////////////////////////////////////////////////////////
    virtual SOCKET_PORT GetPort() const 
    {
        SOCKET_PORT port = m_evcClient.GetPort();
        return port;
    }
} g_evcMain;

///////////////////////////////////////////////////////////////////////
//  Class: CEvCiMainArg
//
// Author: $author$
//   Date: 5/10/2007
///////////////////////////////////////////////////////////////////////
class CEvCiMainArg
: public CEvMainArg
{
public:
    typedef CEvMainArg CExtends;
    typedef CEvCiMainArg CDerives;
    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvCiMainArg
    //
    //       Author: $author$
    //         Date: 5/10/2007
    ///////////////////////////////////////////////////////////////////////
    CEvCiMainArg
    (const char* shortName="i",
     const char* longName="ci",
     const char* description="Check In",
     const char* parameters="work:workfile path;archive:archive path")
    : CExtends(shortName, longName, description, parameters) 
    {
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: MainArg
    //
    //   Author: $author$
    //     Date: 5/10/2007
    ///////////////////////////////////////////////////////////////////////
    virtual int MainArg
    (int args, int argn, const char *arg, 
     int argc, const char** argv, const char** env) 
    {
        const char* localPath;
        const char* evcPath;
        if ((localPath = MainArgParam(argn, arg, argc, argv)))
        if ((evcPath = MainArgParam(argn, arg, argc, argv)))
            g_evcMain.CheckIn(localPath, evcPath);
        return argn;
    }
} g_ciArg;

///////////////////////////////////////////////////////////////////////
//  Class: CEvCoMainArg
//
// Author: $author$
//   Date: 5/10/2007
///////////////////////////////////////////////////////////////////////
class CEvCoMainArg
: public CEvMainArg
{
public:
    typedef CEvMainArg CExtends;
    typedef CEvCoMainArg CDerives;
    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvCoMainArg
    //
    //       Author: $author$
    //         Date: 5/10/2007
    ///////////////////////////////////////////////////////////////////////
    CEvCoMainArg
    (const char* shortName="o",
     const char* longName="co",
     const char* description="Check Out",
     const char* parameters="archive:archive path;work:workfile path")
    : CExtends(shortName, longName, description, parameters) 
    {
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: MainArg
    //
    //   Author: $author$
    //     Date: 5/10/2007
    ///////////////////////////////////////////////////////////////////////
    virtual int MainArg
    (int args, int argn, const char *arg, 
     int argc, const char** argv, const char** env) 
    {
        const char* localPath;
        const char* evcPath;
        if ((evcPath = MainArgParam(argn, arg, argc, argv)))
        if ((localPath = MainArgParam(argn, arg, argc, argv)))
            g_evcMain.CheckOut(evcPath, localPath);
        return argn;
    }
} g_coArg;

///////////////////////////////////////////////////////////////////////
//  Class: CEvStopMainArg
//
// Author: $author$
//   Date: 5/11/2007
///////////////////////////////////////////////////////////////////////
class CEvStopMainArg
: public CEvMainArg
{
public:
    typedef CEvMainArg CExtends;
    typedef CEvStopMainArg CDerives;
    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvStopMainArg
    //
    //       Author: $author$
    //         Date: 5/11/2007
    ///////////////////////////////////////////////////////////////////////
    CEvStopMainArg
    (const char* shortName="s",
     const char* longName="stop",
     const char* description="Stop Server",
     const char* parameters="")
    : CExtends(shortName, longName, description, parameters) 
    {
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: MainArg
    //
    //   Author: $author$
    //     Date: 5/11/2007
    ///////////////////////////////////////////////////////////////////////
    virtual int MainArg
    (int args, int argn, const char *arg, 
     int argc, const char** argv, const char** env) 
    {
        g_evcMain.StopServer();
        return argn;
    }
} g_stopArg;

///////////////////////////////////////////////////////////////////////
//  Class: CEvEvcHelloMainArg
//
// Author: $author$
//   Date: 8/14/2007
///////////////////////////////////////////////////////////////////////
class CEvEvcHelloMainArg
: public CEvMainArg
{
public:
    typedef CEvMainArg CExtends;
    typedef CEvEvcHelloMainArg CDerives;
    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvEvcHelloMainArg
    //
    //       Author: $author$
    //         Date: 8/14/2007
    ///////////////////////////////////////////////////////////////////////
    CEvEvcHelloMainArg
    (const char* shortName="",
     const char* longName="hello",
     const char* description="Hello",
     const char* parameters="")
    : CExtends(shortName, longName, description, parameters) 
    {
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: MainArg
    //
    //   Author: $author$
    //     Date: 8/14/2007
    ///////////////////////////////////////////////////////////////////////
    virtual int MainArg
    (int args, int argn, const char *arg, 
     int argc, const char** argv, const char** env) 
    {
        g_evcMain.Hello();
        return argn;
    }
} g_evcHelloArg;

///////////////////////////////////////////////////////////////////////
//  Class: CEvMatchMainArg
//
// Author: $author$
//   Date: 5/21/2007
///////////////////////////////////////////////////////////////////////
class CEvMatchMainArg
: public CEvMainArg
{
public:
    typedef CEvMainArg CExtends;
    typedef CEvMatchMainArg CDerives;
    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvMatchMainArg
    //
    //       Author: $author$
    //         Date: 5/21/2007
    ///////////////////////////////////////////////////////////////////////
    CEvMatchMainArg
    (const char* shortName="m",
     const char* longName="match",
     const char* description="File Match Patterns",
     const char* parameters="patterns:File Match Patterns")
    : CExtends(shortName, longName, description, parameters) 
    {
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: MainArg
    //
    //   Author: $author$
    //     Date: 5/21/2007
    ///////////////////////////////////////////////////////////////////////
    virtual int MainArg
    (int args, int argn, const char *arg, 
     int argc, const char** argv, const char** env) 
    {
        const char* patterns;

        if ((patterns = MainArgParam(argn, arg, argc, argv)))
            g_evcMain.SetMatch(patterns);
        return argn;
    }
} g_matchArg;

///////////////////////////////////////////////////////////////////////
//  Class: CEvEvcBinaryMatchMainArg
//
// Author: $author$
//   Date: 7/12/2007
///////////////////////////////////////////////////////////////////////
class CEvEvcBinaryMatchMainArg
: public CEvMainArg
{
public:
    typedef CEvMainArg CExtends;
    typedef CEvEvcBinaryMatchMainArg CDerives;
    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvEvcBinaryMatchMainArg
    //
    //       Author: $author$
    //         Date: 7/12/2007
    ///////////////////////////////////////////////////////////////////////
    CEvEvcBinaryMatchMainArg
    (const char* shortName="y",
     const char* longName="binary-match",
     const char* description="Binary File Match Patterns",
     const char* parameters="patterns:Binary File Match Patterns")
    : CExtends(shortName, longName, description, parameters) 
    {
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: MainArg
    //
    //   Author: $author$
    //     Date: 7/12/2007
    ///////////////////////////////////////////////////////////////////////
    virtual int MainArg
    (int args, int argn, const char *arg, 
     int argc, const char** argv, const char** env) 
    {
        const char* name;
        const char*  value;
        LONG length;
        if ((arg = MainArgParam(argn, arg, argc, argv)))
            g_evcMain.SetBinaryMatch(arg);
        else 
        {
            if ((name = GetLongName(length)))
            if ((value = g_evcMain.GetBinaryMatch(length)))
                printf("%s: %s \n", name, value);
        }
        return argn;
    }
} g_binaryMatchArg;

///////////////////////////////////////////////////////////////////////
//  Class: CEvBlockSizeMainArg
//
// Author: $author$
//   Date: 5/19/2007
///////////////////////////////////////////////////////////////////////
class CEvBlockSizeMainArg
: public CEvMainArg
{
public:
    typedef CEvMainArg CExtends;
    typedef CEvBlockSizeMainArg CDerives;
    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvBlockSizeMainArg
    //
    //       Author: $author$
    //         Date: 5/19/2007
    ///////////////////////////////////////////////////////////////////////
    CEvBlockSizeMainArg
    (const char* shortName="z",
     const char* longName="blocksize",
     const char* description="File Transfer Block Size",
     const char* parameters="size:File Transfer Block Size")
    : CExtends(shortName, longName, description, parameters) 
    {
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: MainArg
    //
    //   Author: $author$
    //     Date: 5/19/2007
    ///////////////////////////////////////////////////////////////////////
    virtual int MainArg
    (int args, int argn, const char *arg, 
     int argc, const char** argv, const char** env) 
    {
        int level;

        if ((arg = MainArgParam(argn, arg, argc, argv)))
        if ((0 > (level = atoi(arg))))
            DBE("() invalid block size %d\n", level);
        else g_evcMain.SetBlockSize(level);

        return argn;
    }
} g_blockSizeArg;

///////////////////////////////////////////////////////////////////////
//  Class: CEvBinaryMainArg
//
// Author: $author$
//   Date: 5/19/2007
///////////////////////////////////////////////////////////////////////
class CEvBinaryMainArg
: public CEvMainArg
{
public:
    typedef CEvMainArg CExtends;
    typedef CEvBinaryMainArg CDerives;
    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvBinaryMainArg
    //
    //       Author: $author$
    //         Date: 5/19/2007
    ///////////////////////////////////////////////////////////////////////
    CEvBinaryMainArg
    (const char* shortName="b",
     const char* longName="binary",
     const char* description="Binary file mode",
     const char* parameters="")
    : CExtends(shortName, longName, description, parameters) 
    {
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: MainArg
    //
    //   Author: $author$
    //     Date: 5/19/2007
    ///////////////////////////////////////////////////////////////////////
    virtual int MainArg
    (int args, int argn, const char *arg, 
     int argc, const char** argv, const char** env) 
    {
        g_evcMain.SetIsBinary();
        return argn;
    }
} g_binaryArg;

///////////////////////////////////////////////////////////////////////
//  Class: CEvTextMainArg
//
// Author: $author$
//   Date: 5/19/2007
///////////////////////////////////////////////////////////////////////
class CEvTextMainArg
: public CEvMainArg
{
public:
    typedef CEvMainArg CExtends;
    typedef CEvTextMainArg CDerives;
    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvTextMainArg
    //
    //       Author: $author$
    //         Date: 5/19/2007
    ///////////////////////////////////////////////////////////////////////
    CEvTextMainArg
    (const char* shortName="t",
     const char* longName="text",
     const char* description="Text file mode",
     const char* parameters="")
    : CExtends(shortName, longName, description, parameters) 
    {
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: MainArg
    //
    //   Author: $author$
    //     Date: 5/19/2007
    ///////////////////////////////////////////////////////////////////////
    virtual int MainArg
    (int args, int argn, const char *arg, 
     int argc, const char** argv, const char** env) 
    {
        g_evcMain.SetIsText();
        return argn;
    }
} g_textArg;

///////////////////////////////////////////////////////////////////////
//  Class: CEvRecursiveMainArg
//
// Author: $author$
//   Date: 5/22/2007
///////////////////////////////////////////////////////////////////////
class CEvRecursiveMainArg
: public CEvMainArg
{
public:
    typedef CEvMainArg CExtends;
    typedef CEvRecursiveMainArg CDerives;
    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvRecursiveMainArg
    //
    //       Author: $author$
    //         Date: 5/22/2007
    ///////////////////////////////////////////////////////////////////////
    CEvRecursiveMainArg
    (const char* shortName="r",
     const char* longName="recursive",
     const char* description="Recursive",
     const char* parameters="")
    : CExtends(shortName, longName, description, parameters) 
    {
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: MainArg
    //
    //   Author: $author$
    //     Date: 5/22/2007
    ///////////////////////////////////////////////////////////////////////
    virtual int MainArg
    (int args, int argn, const char *arg, 
     int argc, const char** argv, const char** env) 
    {
        g_evcMain.SetIsRecursive();
        return argn;
    }
} g_recursiveArg;

///////////////////////////////////////////////////////////////////////
//  Class: CEvEvcTestModeMainArg
//
// Author: $author$
//   Date: 7/12/2007
///////////////////////////////////////////////////////////////////////
class CEvEvcTestModeMainArg
: public CEvMainArg
{
public:
    typedef CEvMainArg CExtends;
    typedef CEvEvcTestModeMainArg CDerives;
    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvEvcTestModeMainArg
    //
    //       Author: $author$
    //         Date: 7/12/2007
    ///////////////////////////////////////////////////////////////////////
    CEvEvcTestModeMainArg
    (const char* shortName="x",
     const char* longName="test",
     const char* description="Test Mode",
     const char* parameters="")
    : CExtends(shortName, longName, description, parameters) 
    {
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: MainArg
    //
    //   Author: $author$
    //     Date: 7/12/2007
    ///////////////////////////////////////////////////////////////////////
    virtual int MainArg
    (int args, int argn, const char *arg, 
     int argc, const char** argv, const char** env) 
    {
        g_evcMain.SetIsTestMode();
        return argn;
    }
} g_testModeArg;

///////////////////////////////////////////////////////////////////////
//  Class: CEvEvcHostMainArg
//
// Author: $author$
//   Date: 7/31/2007
///////////////////////////////////////////////////////////////////////
class CEvEvcHostMainArg
: public CEvMainArg
{
public:
    typedef CEvMainArg CExtends;
    typedef CEvEvcHostMainArg CDerives;
    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvEvcHostMainArg
    //
    //       Author: $author$
    //         Date: 7/31/2007
    ///////////////////////////////////////////////////////////////////////
    CEvEvcHostMainArg
    (const char* shortName="h",
     const char* longName="host",
     const char* description="Host",
     const char* parameters="host:Host")
    : CExtends(shortName, longName, description, parameters) 
    {
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: MainArg
    //
    //   Author: $author$
    //     Date: 7/31/2007
    ///////////////////////////////////////////////////////////////////////
    virtual int MainArg
    (int args, int argn, const char *arg, 
     int argc, const char** argv, const char** env) 
    {
        const char* name;
        const char*  value;
        LONG length;
        if ((arg = MainArgParam(argn, arg, argc, argv)))
            g_evcMain.SetHost(arg);
        else 
        {
            g_evcMain.SetDidMain();
            if ((name = GetLongName(length)))
            if ((value = g_evcMain.GetHost(length)))
                printf("%s: %s \n", name, value);
        }
        return argn;
    }
} g_evcHostArg;

///////////////////////////////////////////////////////////////////////
//  Class: CEvPortMainArg
//
// Author: $author$
//   Date: 5/14/2007
///////////////////////////////////////////////////////////////////////
class CEvPortMainArg
: public CEvMainArg
{
public:
    typedef CEvMainArg CExtends;
    typedef CEvPortMainArg CDerives;
    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvPortMainArg
    //
    //       Author: $author$
    //         Date: 5/14/2007
    ///////////////////////////////////////////////////////////////////////
    CEvPortMainArg
    (const char* shortName="p",
     const char* longName="port",
     const char* description="Port",
     const char* parameters="port:Port")
    : CExtends(shortName, longName, description, parameters) 
    {
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: MainArg
    //
    //   Author: $author$
    //     Date: 5/14/2007
    ///////////////////////////////////////////////////////////////////////
    virtual int MainArg
    (int args, int argn, const char *arg, 
     int argc, const char** argv, const char** env) 
    {
        int level;

        if ((arg = MainArgParam(argn, arg, argc, argv)))
        if ((0 > (level = atoi(arg))))
            DBE("() invalid port number %d\n", level);
        else g_evcMain.SetPort(level);

        return argn;
    }
} g_portArg;

///////////////////////////////////////////////////////////////////////
//  Class: CEvNoDelayMainArg
//
// Author: $author$
//   Date: 6/13/2007
///////////////////////////////////////////////////////////////////////
class CEvNoDelayMainArg
: public CEvMainArg
{
public:
    typedef CEvMainArg CExtends;
    typedef CEvNoDelayMainArg CDerives;
    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvNoDelayMainArg
    //
    //       Author: $author$
    //         Date: 6/13/2007
    ///////////////////////////////////////////////////////////////////////
    CEvNoDelayMainArg
    (const char* shortName="n",
     const char* longName="nodelay",
     const char* description="Tcp NoDelay option",
     const char* parameters="on:1=on 0=off")
    : CExtends(shortName, longName, description, parameters) 
    {
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: MainArg
    //
    //   Author: $author$
    //     Date: 6/13/2007
    ///////////////////////////////////////////////////////////////////////
    virtual int MainArg
    (int args, int argn, const char *arg, 
     int argc, const char** argv, const char** env) 
    {
        int level;

        if ((arg = MainArgParam(argn, arg, argc, argv)))
        if ((0 > (level = atoi(arg))))
            DBE("() invalid nodelay on %d\n", level);
        else g_evcMain.SetTcpNoDelayOn(0 != level);

        return argn;
    }
} g_nodelayArg;
