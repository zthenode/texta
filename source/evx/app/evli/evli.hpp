///////////////////////////////////////////////////////////////////////
//   File: evli.hpp
//
// Author: $author$
//   Date: 12/19/2007
///////////////////////////////////////////////////////////////////////

#ifndef _EVLI_HPP
#define _EVLI_HPP

#include "cevcpclientmain.hpp"
#include "cevcpevcpsclientconnection.hpp"
#include "cevcpevcpsclient.hpp"
#include "cevcploginrequest.hpp"

#include "cevchardeligatereader.hpp"
#include "cevchardeligatewriter.hpp"

#include "cevrsa_test_keys.cpp"

#define DEFAULT_USER_NAME "User"
#define DEFAULT_USER_PASSWORD "Password"

///////////////////////////////////////////////////////////////////////
//  Class: CEvLoginMain
//
// Author: $author$
//   Date: 12/19/2007
///////////////////////////////////////////////////////////////////////
class CEvLoginMain
: public CEvcpClientMain
{
public:
    typedef CEvcpClientMain CExtends;
    typedef CEvLoginMain CDerives;

    const char m_lf;
    CEvcpCharHexEncoder m_hexOut;

    CEvCharDeligateReader m_deligateReader;
    CEvCharDeligateWriter m_deligateWriter;

    CEvcpEvcpsClient m_evcpsClient;
    CEvcpEvcpsClientConnection m_evcpsClientConnection;

    CEvcpLoginRequest m_loginRequest;

    CEvString m_userName;
    CEvString m_userPassword;

    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvLoginMain
    //
    //       Author: $author$
    //         Date: 12/19/2007
    ///////////////////////////////////////////////////////////////////////
    CEvLoginMain
    (const char* userName=DEFAULT_USER_NAME,
     const char* userPassword=DEFAULT_USER_PASSWORD) 
    : m_lf('\n'),

      m_hexOut(m_stdOut),
      m_deligateReader(m_reader),
      m_deligateWriter(m_writer),

      m_evcpsClient
      (m_deligateReader, m_deligateWriter, 
       m_stdOut, m_request, m_response),

      m_evcpsClientConnection(m_evcpsClient),

      m_loginRequest(m_reqHeader)
    {
        EvError error;
        LONG length;

        if (0 > (length = m_userName.Assign(userName)))
            throw(error = -length);

        if (0 > (length = m_userPassword.Assign(userPassword)))
            throw(error = -length);
    }
    ///////////////////////////////////////////////////////////////////////
    // Destructor: ~CEvLoginMain
    //
    //      Author: $author$
    //        Date: 12/19/2007
    ///////////////////////////////////////////////////////////////////////
    virtual ~CEvLoginMain()
    {
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: Run
    //
    //    Author: $author$
    //      Date: 12/19/2007
    ///////////////////////////////////////////////////////////////////////
    virtual int Run
    (int argc, const char** argv, const char** env) 
    {
        int err = 0;
        EvError error;

        if (!(error = m_evcpsClient.Initialize
            (rsaPublicM, sizeof(rsaPublicM), 
             rsaPublicE, sizeof(rsaPublicE),
             
             rsaPrivateP, rsaPrivateQ, 
             rsaPrivateDmp1,rsaPrivateDmq1, 
             rsaPrivateIqmp, sizeof(rsaPrivateP),
             
             rsaPrivateP, rsaPrivateQ, 
             rsaPrivateDmp1,rsaPrivateDmq1, 
             rsaPrivateIqmp, sizeof(rsaPrivateP),
             
             rsaPublicM, sizeof(rsaPublicM), 
             rsaPublicE, sizeof(rsaPublicE))))
        {
            if (!(error = Connect(m_tcpHost, m_tcpPort)))
            {
                if (!(error = m_evcpsClient.Connect()))
                {
                    Login();
                    m_evcpsClient.Disconnect();
                }
                Disconnect();
            }
            m_evcpsClient.Finalize();
        }
        return err;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: Login
    //
    //    Author: $author$
    //      Date: 12/21/2007
    ///////////////////////////////////////////////////////////////////////
    virtual void Login() 
    {
        EvError error;
        LONG length;
        const char* userName;
        const char* userPassword;

        if ((userName = m_userName.HasChars(length)))
        if ((userPassword = m_userPassword.HasChars(length)))

        if (!(error = m_loginRequest.SetFields
            (*m_evcpsClient.m_evcpsContext.m_sha1,
             userName, userPassword)))

        if (0 < (length = m_loginRequest.
            Write(m_stdOut)))
        if (0 < (length = m_loginRequest.
            Write(m_evcpsClientConnection)))

        if (0 <= (length = m_evcpsClient.Flush()))
        if (0 < (length = m_evcpsClient.Fill()))
            ReadOKResponse(m_evcpsClientConnection);
    }
};

#endif // _EVLI_HPP
