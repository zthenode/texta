///////////////////////////////////////////////////////////////////////
//   File: cevcryptomain.hpp
//
// Author: $author$
//   Date: 11/5/2007
//
//    $Id$
///////////////////////////////////////////////////////////////////////

#ifndef _CEVCRYPTOMAIN_HPP
#define _CEVCRYPTOMAIN_HPP

#include "cevmain.hpp"
#include "cevcryptodll.hpp"
#include "cevmsticks.hpp"

#define DEFAULT_CRYPTO_DLL_NAME "libev2crypto." DLL_FILE_EXTENSION_CHARS

///////////////////////////////////////////////////////////////////////
//  Class: CEvCryptoMain
//
// Author: $author$
//   Date: 11/5/2007
///////////////////////////////////////////////////////////////////////
class CEvCryptoMain
: public CEvMain
{
public:
    typedef CEvMain CExtends;
    typedef CEvCryptoMain CDerives;

    static CEvCryptoMain* m_theMain;
    CEvCryptoMain* m_oldMain;

    const char* m_dllFilename;
    CEvCryptoDll m_crypto;
    CEvMillisecondTicks m_msTicks;

    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvCryptoMain
    //
    //       Author: $author$
    //         Date: 11/5/2007
    ///////////////////////////////////////////////////////////////////////
    CEvCryptoMain(const char* dllFilename=DEFAULT_CRYPTO_DLL_NAME)
    : m_oldMain(m_theMain),
      m_dllFilename(dllFilename),
      m_crypto(dllFilename) 
    {
        m_theMain = this;
    }
    ///////////////////////////////////////////////////////////////////////
    // Destructor: ~CEvCryptoMain
    //
    //      Author: $author$
    //        Date: 11/5/2007
    ///////////////////////////////////////////////////////////////////////
    virtual ~CEvCryptoMain()
    {
        if (this == m_theMain)
            m_theMain = m_oldMain;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: Run
    //
    //    Author: $author$
    //      Date: 11/5/2007
    ///////////////////////////////////////////////////////////////////////
    virtual int Run
    (int argc, const char** argv, const char** env) 
    {
        int err = 0;

        if (GetDidMain())
            return err;

        err = Test(argc, argv, env);
        return err;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: Test
    //
    //    Author: $author$
    //      Date: 11/5/2007
    ///////////////////////////////////////////////////////////////////////
    virtual int Test
    (int argc, const char** argv, const char** env) 
    {
        int err = 0;
        return err;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: HashFile
    //
    //   Author: $author$
    //     Date: 11/5/2007
    ///////////////////////////////////////////////////////////////////////
    virtual int HashFile
    (const char* filename) 
    {
        int err = 0;
        return err;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: MegaByteFile
    //
    //   Author: $author$
    //     Date: 11/5/2007
    ///////////////////////////////////////////////////////////////////////
    virtual int MegaByteFile
    (const char* filename) 
    {
        int err = 0;
        int i;
        EvError error;
        CEvCharFile f;
        char b[1024];
        SetDidMain();
        if ((error = f.Open(filename, EVFILE_MODE_READ_BINARY)))
        {
            if (!(error = f.Open(filename, EVFILE_MODE_WRITE_BINARY)))
            {
                for (i=0; i<sizeof(b); i++)
                    b[i] = i;
                for (i=0; i<sizeof(b); i++)
                    f.Write(b, sizeof(b));
                f.Close();
            }
        }
        else
        {
            DBE("() file \"%s\" already exists\n", filename);
            f.Close();
        }
        return err;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: AcquireHash
    //
    //   Author: $author$
    //     Date: 11/6/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvHash* 
    AcquireHash(EvError& error) 
    {
        EvHash* acquired = 0;
        error = EV_ERROR_NOT_IMPLEMENTED;
        return acquired;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: ReleaseHash
    //
    //   Author: $author$
    //     Date: 11/6/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError ReleaseHash
    (EvHash& acquired) 
    {
        EvError error = EV_ERROR_NOT_IMPLEMENTED;
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: GetHashSize
    //
    //   Author: $author$
    //     Date: 11/6/2007
    ///////////////////////////////////////////////////////////////////////
    virtual ULONG GetHashSize() const 
    {
        ULONG value = 0;
        return value;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: AcquireCipher
    //
    //   Author: $author$
    //     Date: 11/18/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvCipher* 
    AcquireCipher(EvError& error) 
    {
        EvCipher* acquired = 0;
        error = EV_ERROR_NOT_IMPLEMENTED;
        return acquired;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: ReleaseCipher
    //
    //   Author: $author$
    //     Date: 11/18/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError ReleaseCipher
    (EvCipher& acquired) 
    {
        EvError error = EV_ERROR_NOT_IMPLEMENTED;
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: GetCipherKey
    //
    //   Author: $author$
    //     Date: 11/18/2007
    ///////////////////////////////////////////////////////////////////////
    virtual BYTE* GetCipherKey(ULONG& size) const 
    {
        BYTE* value = 0;

        size = 0;
        return value;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: GetCipherIV
    //
    //   Author: $author$
    //     Date: 11/18/2007
    ///////////////////////////////////////////////////////////////////////
    virtual BYTE* GetCipherIV(ULONG& size) const 
    {
        BYTE* value = 0;

        size = 0;
        return value;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: ReleaseAll
    //
    //   Author: $author$
    //     Date: 4/23/2014
    ///////////////////////////////////////////////////////////////////////
    virtual EvError ReleaseAll()
    {
        EvError error = m_crypto.Close();
        return error;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: OutputDllFilename
    //
    //   Author: $author$
    //     Date: 10/4/2008
    ///////////////////////////////////////////////////////////////////////
    virtual LONG OutputDllFilename() 
    {
        LONG count = 0;
        LONG length;
        const char* chars;
        if ((chars = GetDllFilename(length)))
        if (0 <= (count = m_stdOut.Write(chars, length)))
            m_stdOut.Write("\n");
        return count;
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
        LONG count;
        
        if (0 <= (count = m_crypto.SetDllFilename(chars, length)))
            m_dllFilename = m_crypto.GetDllFilename(length);
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
        const char* chars = m_crypto.GetDllFilename(length);
        return chars;
    }
};

#endif // _CEVCRYPTOMAIN_HPP
