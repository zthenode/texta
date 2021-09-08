///////////////////////////////////////////////////////////////////////
//   File: cevhashmain.hpp
//
// Author: $author$
//   Date: 11/5/2007
//
//    $Id$
///////////////////////////////////////////////////////////////////////

#ifndef _CEVHASHMAIN_HPP
#define _CEVHASHMAIN_HPP

#include "cevcryptomain.hpp"
#include "cevchar2xwriter.hpp"
#include "cevhashedfile.hpp"

///////////////////////////////////////////////////////////////////////
//  Class: CEvHashMain
//
// Author: $author$
//   Date: 11/5/2007
///////////////////////////////////////////////////////////////////////
class CEvHashMain
: public CEvCryptoMain
{
public:
    typedef CEvCryptoMain CExtends;
    typedef CEvHashMain CDerives;

    static CEvHashMain* m_theMain;
    CEvHashMain* m_oldMain;

    BYTE m_out[EvSHA1::EV_HASH_SIZE*1024];

    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvHashMain
    //
    //       Author: $author$
    //         Date: 11/5/2007
    ///////////////////////////////////////////////////////////////////////
    CEvHashMain() 
    {
        m_theMain = this;
    }
    ///////////////////////////////////////////////////////////////////////
    // Destructor: ~CEvHashMain
    //
    //      Author: $author$
    //        Date: 11/5/2007
    ///////////////////////////////////////////////////////////////////////
    virtual ~CEvHashMain()
    {
        if (this == m_theMain)
            m_theMain = m_oldMain;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: TestHash
    //
    //   Author: $author$
    //     Date: 11/5/2007
    ///////////////////////////////////////////////////////////////////////
    virtual int TestHash
    (const char* test[], const char* ret[]) 
    {
        CEvChar2XWriter writer(m_stdOut);
        int err = 0;
        EvError error;
        EvHash* hash;

        if ((hash = AcquireHash(error)))
        {
            for (int i=0; test[i]; i++)
            {
                if (0 <= (hash->Initialize()))
                if (0 <= (hash->Hash((const BYTE*)(test[i]))))
                if (0 <= (hash->Finalize(m_out, sizeof(m_out))))
                    writer.WriteLine((const char*)m_out, GetHashSize());
            }
            ReleaseHash(*hash);
        }
        ReleaseAll();
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
        CEvChar2XWriter writer(m_stdOut);
        int err = 0;
        LONG count;
        DWORD msElapsed;
        EvError error;
        EvHash* hash;

        SetDidMain();

        if ((hash = AcquireHash(error)))
        {
            CEvHashedFile file(*hash);

            msElapsed = m_msTicks.GetCurrentTicks();

            if (0 <= (count = file.Hash
                (m_out, sizeof(m_out), filename)))
            {
                msElapsed = m_msTicks.GetElapsedTicks(msElapsed);
                m_stdOut.WriteUnsigned(file.m_hashedBytes);
                m_stdOut.Write(" bytes in ");
                m_stdOut.WriteUnsigned(msElapsed);
                m_stdOut.Write(" ms: ");
                writer.WriteLine((const char*)m_out, GetHashSize());
            }

            ReleaseHash(*hash);
        }
        return err;
    }
};

#endif // _CEVHASHMAIN_HPP
