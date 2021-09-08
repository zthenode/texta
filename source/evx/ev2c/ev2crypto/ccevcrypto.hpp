///////////////////////////////////////////////////////////////////////
//   File: ccevcrypto.hpp
//
// Author: $author$
//   Date: 10/27/2007
//
//    $Id$
///////////////////////////////////////////////////////////////////////

#ifndef _CCEVCRYPTO_HPP
#define _CCEVCRYPTO_HPP

#include "cevcrypto.hpp"

#if !defined(CCEVCRYPTO_NO_RSA) 
#include "ccevrsaprivatekey.hpp"
#include "ccevcrsapublickey.hpp"
#endif // !defined(CCEVCRYPTO_NO_RSA) 

#if !defined(CCEVCRYPTO_NO_CIPHER) 
#include "ccevdes3.hpp"
#include "ccevaes.hpp"
#endif // !defined(CCEVCRYPTO_NO_CIPHER) 

#if !defined(CCEVCRYPTO_NO_HASH) 
#include "ccevsha1.hpp"
#include "ccevmd5.hpp"
#endif // !defined(CCEVCRYPTO_NO_HASH) 

///////////////////////////////////////////////////////////////////////
//  Class: CCEvCrypto
//
// Author: $author$
//   Date: 10/27/2007
///////////////////////////////////////////////////////////////////////
class CCEvCrypto
: public CEvCrypto
{
public:
    typedef CEvCrypto CExtends;
    typedef CCEvCrypto CDerives;

#if !defined(CCEVCRYPTO_NO_RSA) 
    CCEvRSAPublicKeys m_acquiredRSAPublicKeys;
    CCEvRSAPrivateKeys m_acquiredRSAPrivateKeys;
#endif // !defined(CCEVCRYPTO_NO_RSA) 

#if !defined(CCEVCRYPTO_NO_CIPHER) 
    CCEvDES3s m_acquiredDES3s;
    CCEvAESs m_acquiredAESs;
#endif // !defined(CCEVCRYPTO_NO_CIPHER) 

#if !defined(CCEVCRYPTO_NO_HASH) 
    CCEvMD5s m_acquiredMD5s;
    CCEvSHA1s m_acquiredSHA1s;
#endif // !defined(CCEVCRYPTO_NO_HASH) 

    ///////////////////////////////////////////////////////////////////////
    // Constructor: CCEvCrypto
    //
    //       Author: $author$
    //         Date: 10/27/2007
    ///////////////////////////////////////////////////////////////////////
    CCEvCrypto() 
    {
    }
    ///////////////////////////////////////////////////////////////////////
    // Destructor: ~CCEvCrypto
    //
    //      Author: $author$
    //        Date: 10/27/2007
    ///////////////////////////////////////////////////////////////////////
    virtual ~CCEvCrypto()
    {
        EvError error;
        if ((error = ReleaseAll()))
            throw(error);
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: ReleaseAll
    //
    //   Author: $author$
    //     Date: 10/27/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError ReleaseAll() 
    {
        EvError error = EV_ERROR_NONE;
        EvError error2;

#if !defined(CCEVCRYPTO_NO_RSA) 
        if ((error2 = ReleaseAllRSAPublicKeys()) && !error)
            error = error2;
        if ((error2 = ReleaseAllRSAPrivateKeys()) && !error)
            error = error2;
#endif // !defined(CCEVCRYPTO_NO_RSA) 

#if !defined(CCEVCRYPTO_NO_CIPHER) 
        if ((error2 = ReleaseAllDES3s()) && !error)
            error = error2;
        if ((error2 = ReleaseAllAESs()) && !error)
            error = error2;
#endif // !defined(CCEVCRYPTO_NO_CIPHER) 

#if !defined(CCEVCRYPTO_NO_HASH) 
        if ((error2 = ReleaseAllMD5s()) && !error)
            error = error2;
        if ((error2 = ReleaseAllSHA1s()) && !error)
            error = error2;
#endif // !defined(CCEVCRYPTO_NO_HASH) 
        return error;
    }

#if !defined(CCEVCRYPTO_NO_RSA) 
    ///////////////////////////////////////////////////////////////////////
    // Function: AcquireRSAPublicKey
    //
    //   Author: $author$
    //     Date: 10/27/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvRSAPublicKey* 
    AcquireRSAPublicKey(EvError& error) 
    {
        CCEvRSAPublicKey* acquired = 0;
        
        error = EV_ERROR_FAILED;
        
        if ((acquired = new CCEvRSAPublicKey()))
        {
            m_acquiredRSAPublicKeys.push_back(acquired);
            error = EV_ERROR_NONE;
        }
        return acquired;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: ReleaseRSAPublicKey
    //
    //   Author: $author$
    //     Date: 10/27/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError ReleaseRSAPublicKey
    (EvRSAPublicKey& acquired) 
    {
        EvError error = EV_ERROR_NOT_IMPLEMENTED;
        CCEvRSAPublicKeysIterator i;
        CCEvRSAPublicKey* pAcquired;
        
        error = EV_ERROR_FAILED;
        
        for (i=m_acquiredRSAPublicKeys.begin(); 
             i!=m_acquiredRSAPublicKeys.end(); i++)
        {
            if ((pAcquired = *i))
            if (&acquired == (EvRSAPublicKey*)(pAcquired))
            {
                m_acquiredRSAPublicKeys.erase(i);
                delete pAcquired;
                return error = EV_ERROR_NONE;
            }
        }
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: ReleaseAllRSAPublicKeys
    //
    //   Author: $author$
    //     Date: 10/27/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError ReleaseAllRSAPublicKeys() 
    {
        EvError error = EV_ERROR_NONE;
        CCEvRSAPublicKeysIterator i;
        CCEvRSAPublicKey* pAcquired;

		error = EV_ERROR_NONE;

        for (i=m_acquiredRSAPublicKeys.begin(); 
             i!=m_acquiredRSAPublicKeys.end(); i++)
        {
            if ((pAcquired = *i))
                delete pAcquired;
            else error = EV_ERROR_FAILED;
        }
        m_acquiredRSAPublicKeys.clear();
        return error;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: AcquireRSAPrivateKey
    //
    //   Author: $author$
    //     Date: 10/31/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvRSAPrivateKey* 
    AcquireRSAPrivateKey
    (EvError& error) 
    {
        CCEvRSAPrivateKey* acquired = 0;
        
        error = EV_ERROR_NOT_IMPLEMENTED;
        
        if ((acquired = new CCEvRSAPrivateKey()))
        {
            m_acquiredRSAPrivateKeys.push_back(acquired);
            error = EV_ERROR_NONE;
        }
        return acquired;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: ReleaseRSAPrivateKey
    //
    //   Author: $author$
    //     Date: 10/31/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError ReleaseRSAPrivateKey
    (EvRSAPrivateKey& acquired) 
    {
        EvError error = EV_ERROR_FAILED;
        CCEvRSAPrivateKeysIterator i;
        CCEvRSAPrivateKey* pAcquired;
        
        for (i=m_acquiredRSAPrivateKeys.begin(); 
             i!=m_acquiredRSAPrivateKeys.end(); i++)
        {
            if ((pAcquired = *i))
            if (&acquired == (EvRSAPrivateKey*)(pAcquired))
            {
                m_acquiredRSAPrivateKeys.erase(i);
                delete pAcquired;
                return error = EV_ERROR_NONE;
            }
        }
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: ReleaseAllRSAPrivateKeys
    //
    //   Author: $author$
    //     Date: 10/31/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError ReleaseAllRSAPrivateKeys() 
    {
        EvError error = EV_ERROR_NONE;
        CCEvRSAPrivateKeysIterator i;
        CCEvRSAPrivateKey* pAcquired;

        for (i=m_acquiredRSAPrivateKeys.begin(); 
             i!=m_acquiredRSAPrivateKeys.end(); i++)
        {
            if ((pAcquired = *i))
                delete pAcquired;
            else error = EV_ERROR_FAILED;
        }
        m_acquiredRSAPrivateKeys.clear();
        return error;
    }
#endif // !defined(CCEVCRYPTO_NO_RSA) 

#if !defined(CCEVCRYPTO_NO_CIPHER) 
    ///////////////////////////////////////////////////////////////////////
    // Function: AcquireDES3
    //
    //   Author: $author$
    //     Date: 11/5/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvDES3* 
    AcquireDES3(EvError& error) 
    {
        CCEvDES3* acquired = 0;
        
        error = EV_ERROR_NOT_IMPLEMENTED;
        
        if ((acquired = new CCEvDES3()))
        {
            m_acquiredDES3s.push_back(acquired);
            error = EV_ERROR_NONE;
        }
        else error = EV_ERROR_FAILED;
        return acquired;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: ReleaseDES3
    //
    //   Author: $author$
    //     Date: 11/5/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError ReleaseDES3
    (EvDES3& acquired) 
    {
        EvError error = EV_ERROR_NOT_IMPLEMENTED;
        CCEvDES3sIterator i;
        CCEvDES3* pAcquired;
        
        error = EV_ERROR_FAILED;
        
        for (i=m_acquiredDES3s.begin(); 
             i!=m_acquiredDES3s.end(); i++)
        {
            if ((pAcquired = *i))
            if (&acquired == (EvDES3*)(pAcquired))
            {
                m_acquiredDES3s.erase(i);
                delete pAcquired;
                return error = EV_ERROR_NONE;
            }
        }
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: ReleaseAllDES3s
    //
    //   Author: $author$
    //     Date: 11/5/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError ReleaseAllDES3s() 
    {
        EvError error = EV_ERROR_NOT_IMPLEMENTED;
        CCEvDES3sIterator i;
        CCEvDES3* pAcquired;

		error = EV_ERROR_NONE;

        for (i=m_acquiredDES3s.begin(); 
             i!=m_acquiredDES3s.end(); i++)
        {
            if ((pAcquired = *i))
                delete pAcquired;
            else error = EV_ERROR_FAILED;
        }
        m_acquiredDES3s.clear();
        return error;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: AcquireAES
    //
    //   Author: $author$
    //     Date: 11/5/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvAES* 
    AcquireAES(EvError& error) 
    {
        CCEvAES* acquired = 0;
        
        error = EV_ERROR_NOT_IMPLEMENTED;
        
        if ((acquired = new CCEvAES()))
        {
            m_acquiredAESs.push_back(acquired);
            error = EV_ERROR_NONE;
        }
        else error = EV_ERROR_FAILED;
        return acquired;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: ReleaseAES
    //
    //   Author: $author$
    //     Date: 11/5/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError ReleaseAES
    (EvAES& acquired) 
    {
        EvError error = EV_ERROR_NOT_IMPLEMENTED;
        CCEvAESsIterator i;
        CCEvAES* pAcquired;
        
        error = EV_ERROR_FAILED;
        
        for (i=m_acquiredAESs.begin(); 
             i!=m_acquiredAESs.end(); i++)
        {
            if ((pAcquired = *i))
            if (&acquired == (EvAES*)(pAcquired))
            {
                m_acquiredAESs.erase(i);
                delete pAcquired;
                return error = EV_ERROR_NONE;
            }
        }
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: ReleaseAllAESs
    //
    //   Author: $author$
    //     Date: 11/5/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError ReleaseAllAESs() 
    {
        EvError error = EV_ERROR_NOT_IMPLEMENTED;
        CCEvAESsIterator i;
        CCEvAES* pAcquired;

		error = EV_ERROR_NONE;

        for (i=m_acquiredAESs.begin(); 
             i!=m_acquiredAESs.end(); i++)
        {
            if ((pAcquired = *i))
                delete pAcquired;
            else error = EV_ERROR_FAILED;
        }
        m_acquiredAESs.clear();
        return error;
    }
#endif // !defined(CCEVCRYPTO_NO_CIPHER) 

#if !defined(CCEVCRYPTO_NO_HASH) 
    ///////////////////////////////////////////////////////////////////////
    // Function: AcquireMD5
    //
    //   Author: $author$
    //     Date: 11/5/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvMD5* 
    AcquireMD5(EvError& error) 
    {
        CCEvMD5* acquired = 0;
        
        error = EV_ERROR_NOT_IMPLEMENTED;
        
        if ((acquired = new CCEvMD5()))
        {
            m_acquiredMD5s.push_back(acquired);
            error = EV_ERROR_NONE;
        }
        else error = EV_ERROR_FAILED;
        return acquired;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: ReleaseMD5
    //
    //   Author: $author$
    //     Date: 11/5/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError ReleaseMD5
    (EvMD5& acquired) 
    {
        EvError error = EV_ERROR_NOT_IMPLEMENTED;
        CCEvMD5sIterator i;
        CCEvMD5* pAcquired;
        
        error = EV_ERROR_FAILED;
        
        for (i=m_acquiredMD5s.begin(); 
             i!=m_acquiredMD5s.end(); i++)
        {
            if ((pAcquired = *i))
            if (&acquired == (EvMD5*)(pAcquired))
            {
                m_acquiredMD5s.erase(i);
                delete pAcquired;
                return error = EV_ERROR_NONE;
            }
        }
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: ReleaseAllMD5s
    //
    //   Author: $author$
    //     Date: 11/5/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError ReleaseAllMD5s() 
    {
        EvError error = EV_ERROR_NOT_IMPLEMENTED;
        CCEvMD5sIterator i;
        CCEvMD5* pAcquired;

		error = EV_ERROR_NONE;

        for (i=m_acquiredMD5s.begin(); 
             i!=m_acquiredMD5s.end(); i++)
        {
            if ((pAcquired = *i))
                delete pAcquired;
            else error = EV_ERROR_FAILED;
        }
        m_acquiredMD5s.clear();
        return error;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: AcquireSHA1
    //
    //   Author: $author$
    //     Date: 11/5/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvSHA1* 
    AcquireSHA1(EvError& error) 
    {
        CCEvSHA1* acquired = 0;
        
        error = EV_ERROR_NOT_IMPLEMENTED;
        
        if ((acquired = new CCEvSHA1()))
        {
            m_acquiredSHA1s.push_back(acquired);
            error = EV_ERROR_NONE;
        }
        else error = EV_ERROR_FAILED;
        return acquired;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: ReleaseSHA1
    //
    //   Author: $author$
    //     Date: 11/5/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError ReleaseSHA1
    (EvSHA1& acquired) 
    {
        EvError error = EV_ERROR_NOT_IMPLEMENTED;
        CCEvSHA1sIterator i;
        CCEvSHA1* pAcquired;
        
        error = EV_ERROR_FAILED;
        
        for (i=m_acquiredSHA1s.begin(); 
             i!=m_acquiredSHA1s.end(); i++)
        {
            if ((pAcquired = *i))
            if (&acquired == (EvSHA1*)(pAcquired))
            {
                m_acquiredSHA1s.erase(i);
                delete pAcquired;
                return error = EV_ERROR_NONE;
            }
        }
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: ReleaseAllSHA1s
    //
    //   Author: $author$
    //     Date: 11/5/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError ReleaseAllSHA1s() 
    {
        EvError error = EV_ERROR_NOT_IMPLEMENTED;
        CCEvSHA1sIterator i;
        CCEvSHA1* pAcquired;

		error = EV_ERROR_NONE;

        for (i=m_acquiredSHA1s.begin(); 
             i!=m_acquiredSHA1s.end(); i++)
        {
            if ((pAcquired = *i))
                delete pAcquired;
            else error = EV_ERROR_FAILED;
        }
        m_acquiredSHA1s.clear();
        return error;
    }
#endif // !defined(CCEVCRYPTO_NO_HASH) 
};
#endif // _CCEVCRYPTO_HPP
