///////////////////////////////////////////////////////////////////////
//   File: cevcryptodll.hpp
//
// Author: $author$
//   Date: 10/29/2007
//
//    $Id$
///////////////////////////////////////////////////////////////////////

#ifndef _CEVCRYPTODLL_HPP
#define _CEVCRYPTODLL_HPP

#include "evcryptoexporter.hpp"
#include "cevcrypto.hpp"
#include "cevdll.hpp"
#include "cevstring.hpp"
#include "evdebug.h"

#define DEFAULT_CEVCRYPTODLL_DLL_FILENAME "libev2crypto." DLL_FILE_EXTENSION_CHARS

///////////////////////////////////////////////////////////////////////
//  Class: CEvCryptoDll
//
// Author: $author$
//   Date: 10/29/2007
///////////////////////////////////////////////////////////////////////
class CEvCryptoDll
: virtual public EvCryptoExporter,
  public CEvCrypto
{
public:
    typedef EvCryptoExporter CImplements;
    typedef CEvCrypto CExtends;
    typedef CEvCryptoDll CDerives;

    CEvString m_dllFilename;

    CEvString m_cryptoAcquireSymbol;
    CEvString m_cryptoReleaseSymbol;

    FEvCryptoAcquire* m_cryptoAcquire;
    FEvCryptoRelease* m_cryptoRelease;

    EvCrypto* m_crypto;
    bool m_opened;
    CEvDll m_dll;

    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvCryptoDll
    //
    //       Author: $author$
    //         Date: 10/29/2007
    ///////////////////////////////////////////////////////////////////////
    CEvCryptoDll(const char* dllFilename=DEFAULT_CEVCRYPTODLL_DLL_FILENAME) 
    : m_cryptoAcquireSymbol(EV_CRYPTO_ACQUIRE_SYMBOL),
      m_cryptoReleaseSymbol(EV_CRYPTO_RELEASE_SYMBOL),
      m_cryptoAcquire(0),
      m_cryptoRelease(0),
      m_crypto(0),
      m_opened(false) 
    {
        EvError error;
        LONG length;

        if (dllFilename)
        if (0 > (length = m_dllFilename.Assign(dllFilename)))
            throw(error = -length);
    }
    ///////////////////////////////////////////////////////////////////////
    // Destructor: ~CEvCryptoDll
    //
    //      Author: $author$
    //        Date: 10/29/2007
    ///////////////////////////////////////////////////////////////////////
    virtual ~CEvCryptoDll()
    {
        EvError error;
        //DBT("() ...in\n");
        if (m_opened)
        if ((error = Close(m_opened)))
            throw(error);
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: AcquireRSAPublicKey
    //
    //   Author: $author$
    //     Date: 10/27/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvRSAPublicKey* 
    AcquireRSAPublicKey
    (EvError& error) 
    {
        EvRSAPublicKey* acquired = 0;
        EvCrypto* acquirer = 0;
        EvError error2;
        
        error = EV_ERROR_FAILED;
        
        if ((error2 = Open()))
            return acquired;

        if ((acquirer = AcquireCrypto(error2)))
            acquired = acquirer->AcquireRSAPublicKey(error);
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
        EvError error = EV_ERROR_FAILED;
        EvCrypto* acquirer = 0;
        EvError error2;
        
        if ((error2 = Open()))
            return error;

        if ((acquirer = AcquireCrypto(error2)))
            error = acquirer->ReleaseRSAPublicKey(acquired);
        return error;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: AcquireRSAPrivateKey
    //
    //   Author: $author$
    //     Date: 10/29/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvRSAPrivateKey* 
    AcquireRSAPrivateKey
    (EvError& error) 
    {
        EvRSAPrivateKey* acquired = 0;
        EvCrypto* acquirer = 0;
        EvError error2;
        
        error = EV_ERROR_FAILED;
        
        if ((error2 = Open()))
            return acquired;

        if ((acquirer = AcquireCrypto(error2)))
            acquired = acquirer->AcquireRSAPrivateKey(error);
        return acquired;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: ReleaseRSAPrivateKey
    //
    //   Author: $author$
    //     Date: 10/29/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError ReleaseRSAPrivateKey
    (EvRSAPrivateKey& acquired) 
    {
        EvError error = EV_ERROR_NOT_IMPLEMENTED;
        EvCrypto* acquirer = 0;
        EvError error2;
        
        error = EV_ERROR_FAILED;
        
        if ((error2 = Open()))
            return error;

        if ((acquirer = AcquireCrypto(error2)))
        if (!(error2 = acquirer->ReleaseRSAPrivateKey(acquired)))
            error = EV_ERROR_NONE;
        return error;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: AcquireAES
    //
    //   Author: $author$
    //     Date: 11/19/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvAES* 
    AcquireAES(EvError& error) 
    {
        EvAES* acquired = 0;
        EvCrypto* acquirer = 0;
        EvError error2;
        
        error = EV_ERROR_FAILED;
        
        if ((error2 = Open()))
            return acquired;

        if ((acquirer = AcquireCrypto(error2)))
            acquired = acquirer->AcquireAES(error);
        return acquired;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: ReleaseAES
    //
    //   Author: $author$
    //     Date: 11/19/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError ReleaseAES
    (EvAES& acquired) 
    {
        EvError error = EV_ERROR_FAILED;
        EvCrypto* acquirer = 0;
        EvError error2;
        
        if ((error2 = Open()))
            return error;

        if ((acquirer = AcquireCrypto(error2)))
            error = acquirer->ReleaseAES(acquired);
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: ReleaseAllAESs
    //
    //   Author: $author$
    //     Date: 11/19/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError ReleaseAllAESs() 
    {
        EvError error = EV_ERROR_FAILED;
        EvCrypto* acquirer = 0;
        EvError error2;
        
        if ((error2 = Open()))
            return error;

        if ((acquirer = AcquireCrypto(error2)))
            error = acquirer->ReleaseAllAESs();
        return error;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: AcquireDES3
    //
    //   Author: $author$
    //     Date: 11/19/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvDES3* 
    AcquireDES3(EvError& error) 
    {
        EvDES3* acquired = 0;
        EvCrypto* acquirer = 0;
        EvError error2;
        
        error = EV_ERROR_FAILED;
        
        if ((error2 = Open()))
            return acquired;

        if ((acquirer = AcquireCrypto(error2)))
            acquired = acquirer->AcquireDES3(error);
        return acquired;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: ReleaseDES3
    //
    //   Author: $author$
    //     Date: 11/19/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError ReleaseDES3
    (EvDES3& acquired) 
    {
        EvError error = EV_ERROR_FAILED;
        EvCrypto* acquirer = 0;
        EvError error2;
        
        if ((error2 = Open()))
            return error;

        if ((acquirer = AcquireCrypto(error2)))
            error = acquirer->ReleaseDES3(acquired);
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: ReleaseAllDES3s
    //
    //   Author: $author$
    //     Date: 11/19/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError ReleaseAllDES3s() 
    {
        EvError error = EV_ERROR_FAILED;
        EvCrypto* acquirer = 0;
        EvError error2;
        
        if ((error2 = Open()))
            return error;

        if ((acquirer = AcquireCrypto(error2)))
            error = acquirer->ReleaseAllDES3s();
        return error;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: AcquireMD5
    //
    //   Author: $author$
    //     Date: 11/5/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvMD5* 
    AcquireMD5(EvError& error) 
    {
        EvMD5* acquired = 0;
        EvCrypto* acquirer = 0;
        EvError error2;
        
        error = EV_ERROR_FAILED;
        
        if ((error2 = Open()))
            return acquired;

        if ((acquirer = AcquireCrypto(error2)))
            acquired = acquirer->AcquireMD5(error);
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
        EvError error = EV_ERROR_FAILED;
        EvCrypto* acquirer = 0;
        EvError error2;
        
        if ((error2 = Open()))
            return error;

        if ((acquirer = AcquireCrypto(error2)))
            error = acquirer->ReleaseMD5(acquired);
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
        EvError error = EV_ERROR_FAILED;
        EvCrypto* acquirer = 0;
        EvError error2;
        
        if ((error2 = Open()))
            return error;

        if ((acquirer = AcquireCrypto(error2)))
            error = acquirer->ReleaseAllMD5s();
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
        EvSHA1* acquired = 0;
        EvCrypto* acquirer = 0;
        EvError error2;
        
        error = EV_ERROR_FAILED;
        
        if ((error2 = Open()))
            return acquired;

        if ((acquirer = AcquireCrypto(error2)))
            acquired = acquirer->AcquireSHA1(error);
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
        EvError error = EV_ERROR_FAILED;
        EvCrypto* acquirer = 0;
        EvError error2;
        
        if ((error2 = Open()))
            return error;

        if ((acquirer = AcquireCrypto(error2)))
            error = acquirer->ReleaseSHA1(acquired);
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
        EvError error = EV_ERROR_FAILED;
        EvCrypto* acquirer = 0;
        EvError error2;
        
        if ((error2 = Open()))
            return error;

        if ((acquirer = AcquireCrypto(error2)))
            error = acquirer->ReleaseAllSHA1s();
        return error;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: Open
    //
    //   Author: $author$
    //     Date: 4/13/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError Open
    (const char* dllFilename=0, bool onlyClosed=false) 
    {
        EvError error = EV_ERROR_FAILED;
        LONG length = 1;
        int unequal;
        const char* cryptoAcquire;
        const char* cryptoRelease;

        if (m_opened)
        if (onlyClosed)
            return EV_ERROR_ALREADY_OPEN;

        if (!dllFilename)
            dllFilename = m_dllFilename.Chars(length);

        if (!dllFilename || (0 >= length))
            return EV_ERROR_NULL_PARAMETER;

        if (m_opened)
        if (!(unequal = m_dllFilename.Compare(dllFilename)))
            return EV_ERROR_NONE;
        else
        if ((error = Close(m_opened)))
            return error;

        if ((cryptoAcquire = m_cryptoAcquireSymbol.HasChars(length)))
        if ((cryptoRelease = m_cryptoReleaseSymbol.HasChars(length)))
        if (!(error = m_dll.Open(dllFilename)))
        {
            if (!(m_cryptoAcquire = (FEvCryptoAcquire*)
                (m_dll.GetAddress(cryptoAcquire))))
                DBE("() failed to get address of \"%s\"\n", cryptoAcquire);
            else if (!(m_cryptoRelease = (FEvCryptoRelease*)
                    (m_dll.GetAddress(cryptoRelease))))
                    DBE("() failed to get address of \"%s\"\n", cryptoRelease);
            else
            {
                m_opened = true;
                return EV_ERROR_NONE;
            }
            m_cryptoAcquire = 0;
            m_dll.Close();
        }
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: Close
    //
    //   Author: $author$
    //     Date: 4/13/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError Close
    (bool onlyOpened=false) 
    {
        EvError error = EV_ERROR_FAILED;

        if (!m_opened)
        if (onlyOpened)
            return EV_ERROR_NOT_OPEN;
        else return EV_ERROR_NONE;

        if ((error = ReleaseAllCryptos()))
            DBE("() release all cryptos failed\n");

        if ((error = m_dll.Close()))
            DBE("() dll close failed\n");

        m_opened = false;
        m_cryptoRelease = 0;
        m_cryptoAcquire = 0;
        return error;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: AcquireCrypto
    //
    //   Author: $author$
    //     Date: 4/16/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvCrypto* 
    AcquireCrypto(EvError &error) 
    {
        EvCrypto* crypto = 0;

        if ((crypto = m_crypto))
        {
            error = EV_ERROR_NONE;
            return crypto;
        }

        if (!m_opened)
        {
            error = EV_ERROR_NOT_OPEN;
            return crypto;
        }

        crypto = (m_crypto = m_cryptoAcquire(error));
        return crypto;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: ReleaseCrypto
    //
    //   Author: $author$
    //     Date: 4/16/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError ReleaseCrypto
    (EvCrypto& crypto) 
    {
        EvError error = EV_ERROR_FAILED;

        if (!m_opened)
            return EV_ERROR_NOT_OPEN;

        error = m_cryptoRelease(&crypto);
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: ReleaseAllCryptos
    //
    //   Author: $author$
    //     Date: 4/16/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError ReleaseAllCryptos() 
    {
        EvError error = EV_ERROR_NONE;

        if (!m_opened)
            return EV_ERROR_NOT_OPEN;

        if ((error = m_cryptoRelease(0)))
            DBE("() (*m_cryptoRelease)(0) failed\n");
        return error;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: SetDllFilename
    //
    //   Author: $author$
    //     Date: 11/19/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG SetDllFilename
    (const char* chars,
     LONG length=-1) 
    {
        LONG count = m_dllFilename.Assign(chars,length);
        return count;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: GetDllFilename
    //
    //   Author: $author$
    //     Date: 11/19/2007
    ///////////////////////////////////////////////////////////////////////
    virtual const char* GetDllFilename
    (LONG& length) const 
    {
        const char* chars = m_dllFilename.Chars(length);
        return chars;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: DeleteThis
    //
    //   Author: $author$
    //     Date: 10/4/2008
    ///////////////////////////////////////////////////////////////////////
    virtual EvError DeleteThis() 
    {
        EvError error = EV_ERROR_NONE;
        delete this;
        return error;
    }
};

#endif // _CEVCRYPTODLL_HPP
