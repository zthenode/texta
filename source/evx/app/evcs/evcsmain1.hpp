///////////////////////////////////////////////////////////////////////
//   File: evcsmain.hpp
//
// Author: $author$
//   Date: 11/9/2007
//
//    $Id$
///////////////////////////////////////////////////////////////////////

#ifndef _EVCSMAIN_HPP
#define _EVCSMAIN_HPP

#include "evcpversion.h"
#include "cevmain.hpp"
#include "cevcploginresponse.hpp"
#include "cevcploginrequest.hpp"
#include "cevcpheader.hpp"
#include "cevcpsloginresponse.hpp"
#include "cevcpsloginrequest.hpp"
#include "cevpseudorandombytereader.hpp"
#include "cevcpspkcs1encryptionblock.hpp"
#include "cevcpsserverrsaparams.hpp"
#include "cevcpsrsasignature.hpp"
#include "cevrsaprivatekey.hpp"
#include "cevrsapublickey.hpp"
#include "cevmd5.hpp"
#include "cevsha1.hpp"
#include "cevcryptodll.hpp"

#include "cevrsa_test_keys.cpp"

#define EVCP_REQUEST_ACTION_NAME_LOGIN "LOGIN"

///////////////////////////////////////////////////////////////////////
//  Class: CEvcsMain
//
// Author: $author$
//   Date: 11/9/2007
///////////////////////////////////////////////////////////////////////
class CEvcsMain
: public CEvMain
{
public:
    typedef CEvMain CExtends;
    typedef CEvcsMain CDerives;

    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvcsMain
    //
    //       Author: $author$
    //         Date: 11/9/2007
    ///////////////////////////////////////////////////////////////////////
    CEvcsMain() 
    {
    }
    ///////////////////////////////////////////////////////////////////////
    // Destructor: ~CEvcsMain
    //
    //      Author: $author$
    //        Date: 11/9/2007
    ///////////////////////////////////////////////////////////////////////
    virtual ~CEvcsMain()
    {
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: Run
    //
    //    Author: $author$
    //      Date: 11/9/2007
    ///////////////////////////////////////////////////////////////////////
    virtual int Run
    (int argc, const char** argv, const char** env) 
    {
        int err = 0;
        EvError error;
        LONG length;

        CEvUTCTime utcTime;
        CEvPseudoRandomBYTEReader randomReader;

        CEvcpHeader evcpHeader
        (EVC_PROTOCOL_NAME,
         EVC_PROTOCOL_VERSION_MAJOR,
         EVC_PROTOCOL_VERSION_MINOR);

        CEvcpsServerRSAParams rsaParams
        (rsaPublicM, sizeof(rsaPublicM),
         rsaPublicE, sizeof(rsaPublicE));

        CEvcpsRSASignature rsaSignature;

        EvRSAPublicKey* rsaPublic;
        EvRSAPrivateKey* rsaPrivate;
        EvMD5* md5;
        EvSHA1* sha1;

        CEvcpsPKCS1EncryptionBlock pkcs1(PKCS1_TYPE_PUBLIC_KEY_OPERATION);

        CEvcpsLoginRequest request;
        CEvcpLoginRequest evcpRequest(evcpHeader, request);

        CEvcpsLoginResponse response;
        CEvcpLoginResponse evcpResponse(evcpHeader, response);

        CEvCryptoDll crypto;

        rsaParams.WriteX(m_stdOut);

        if ((rsaPrivate = crypto.AcquireRSAPrivateKey(error)))
        if ((md5 = crypto.AcquireMD5(error)))
        if ((sha1 = crypto.AcquireSHA1(error)))
        if (!(error = rsaPrivate->CreateMSB
            (rsaPrivateP, rsaPrivateQ, 
             rsaPrivateDmp1, rsaPrivateDmq1,
             rsaPrivateIqmp, sizeof(rsaPrivateP))))
        if (0 < (length = rsaSignature.Sign
            (rsaParams, *rsaPrivate, *md5, *sha1, randomReader)))
        {
            rsaSignature.WriteX(m_stdOut);

            if ((rsaPublic = crypto.AcquireRSAPublicKey(error)))
            if (!(error = rsaPublic->CreateMSB
                (rsaPublicM, sizeof(rsaPublicM), 
                 rsaPublicE, sizeof(rsaPublicE))))
            if (0 < (length = rsaSignature.Verify
                (rsaParams, *rsaPublic, *md5, *sha1)))
                rsaSignature.WriteX(m_stdOut);
        }

        if (0 < (length = request.m_random.
            Generate(utcTime, randomReader)))
        if (!(error = evcpRequest.SetFields
            (EVCP_REQUEST_ACTION_NAME_LOGIN,
             EVCP_REQUEST_ACTION_NAME_BEGIN,
             EVCP_HEADER_FIELD_VALUE_CONNECTION_KEEPALIVE,
             EVCP_HEADER_FIELD_NAME_ENCODING_HEX)))
        if (0 < (evcpRequest.Write(m_stdOut)))
            evcpRequest.RemoveFields();

        if (0 < (length = pkcs1.Encode
            (request.m_random, randomReader, 128)))
            pkcs1.WriteX(m_stdOut);

        if (0 < (length = response.m_random.
            Generate(utcTime, randomReader)))
        if (!(error = evcpResponse.AddFields
            (EVCP_REQUEST_ACTION_NAME_LOGIN,
             EVCP_REQUEST_ACTION_NAME_BEGIN,
             EVCP_HEADER_FIELD_NAME_ENCODING_HEX,
             EVCP_STATUS_DESC_OK, EVCP_STATUS_CODE_OK)))
            evcpResponse.Write(m_stdOut);

        return err;
    }
};

#endif // _EVCSMAIN_HPP
