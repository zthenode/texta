///////////////////////////////////////////////////////////////////////
//   File: evcsco.hpp
//
// Author: $author$
//   Date: 9/17/2007
//
//    $Id$
///////////////////////////////////////////////////////////////////////

#ifndef _EVCSCO_HPP
#define _EVCSCO_HPP

#include "cevcmain.hpp"
#include "cevmain.hpp"
#include "cevcs.hpp"
#include "evcsallocator.hpp"

///////////////////////////////////////////////////////////////////////
//  Class: CEvcsCoMain
//
// Author: $author$
//   Date: 9/17/2007
///////////////////////////////////////////////////////////////////////
class CEvcsCoMain
: public CEvcMain
{
public:
    typedef CEvcMain CExtends;
    typedef CEvcsCoMain CDerives;

    Evcs* m_evcs;
    CEvFilePath m_filePath;
    CEvFileSystemEntry m_fileEntry;

    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvcsCoMain
    //
    //       Author: $author$
    //         Date: 9/17/2007
    ///////////////////////////////////////////////////////////////////////
    CEvcsCoMain() 
    : m_evcs(0)
    {
    }
    ///////////////////////////////////////////////////////////////////////
    // Destructor: ~CEvcsCoMain
    //
    //      Author: $author$
    //        Date: 9/17/2007
    ///////////////////////////////////////////////////////////////////////
    ~CEvcsCoMain()
    {
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: Do
    //
    //   Author: $author$
    //     Date: 9/6/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError Do
    (const char* chars, const char* chars2=0) 
    {
        EvError error = EV_ERROR_NONE;
        EvError error2;
        char* buffer;
        Evcs* evcs;

        if ((buffer = AllocateBuffer(m_blockSize)))
        if (!(error2 = InitializeEvcs()))
        {
            if ((evcs = AcquireEvcs(error2)))
            {
                if (!(error2 = evcs->StartCheckOutOp
                    (m_filePath, m_fileEntry, 
                     chars, m_isBinary, m_isRecursive)))
                do
                {
                    do
                    {
                        m_blockLength = evcs->ReadOpData(buffer, m_blockSize);
                    }
                    while (m_blockLength == m_blockSize);
                }
                while (!(error2 = evcs->ContinueCheckOutOp
                       (m_filePath, m_fileEntry)));
                ReleaseEvcs(*evcs);
            }
            FinalizeEvcs();
        }
        return error;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: AcquireEvcs
    //
    //   Author: $author$
    //     Date: 5/24/2007
    ///////////////////////////////////////////////////////////////////////
    virtual Evcs* AcquireEvcs(EvError& error) 
    {
        Evcs* evcs = 0;
        EvcsAllocator* allocator;

        if ((evcs = m_evcs))
        {
            error = EV_ERROR_NONE;
            return evcs;
        }

        error = EV_ERROR_FAILED;

        if ((allocator = EvcsAllocator::GetAllocator(error)))
        if ((evcs = allocator->AcquireEvcs(error)))
            m_evcs = evcs;

        return evcs;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: ReleaseEvcs
    //
    //   Author: $author$
    //     Date: 5/24/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError ReleaseEvcs(Evcs& evcs) 
    {
        EvError error = EV_ERROR_FAILED;
        EvcsAllocator* allocator;

        if (&evcs == m_evcs)
            m_evcs = 0;

        if ((allocator = evcs.GetAllocator()))
            error = allocator->ReleaseEvcs(evcs);
        return error;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: InitializeEvcs
    //
    //   Author: $author$
    //     Date: 9/18/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError InitializeEvcs() 
    {
        EvError error = EV_ERROR_FAILED;
        EvcsAllocator* allocator;

        if ((allocator = EvcsAllocator::GetAllocator(error)))
            error = allocator->Initialize();
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: FinalizeEvcs
    //
    //   Author: $author$
    //     Date: 9/18/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError FinalizeEvcs() 
    {
        EvError error = EV_ERROR_FAILED;
        EvcsAllocator* allocator;

        if ((allocator = EvcsAllocator::GetAllocator(error)))
            error = allocator->Finalize();
        return error;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: Run
    //
    //    Author: $author$
    //      Date: 9/17/2007
    ///////////////////////////////////////////////////////////////////////
    virtual int Run
    (int argc, const char** argv, const char** env) 
    {
        int err = 0;
        const char* chars;
        const char* chars2;
        LONG length2;
        LONG length;

        if (!(chars = m_controlPath.Chars(length)) || (0 >= length))
        {
            if (!GetDidMain())
                Help(argc, argv, env);
        }
        else if ((chars2 = m_localPath.
                 Chars(length2)) || (0 >= length2))
                Do(chars, chars2);
        else Do(chars);
        return err;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: MainArgn
    //
    //   Author: $author$
    //     Date: 9/17/2007
    ///////////////////////////////////////////////////////////////////////
    virtual int MainArgn
    (int args, int argn, const char *arg, 
     int argc, const char** argv, const char** env) 
    {
        int mainArgs;
        if (1 > (mainArgs = m_mainArgs++))
            m_controlPath.Assign(arg);
        else if (2 > mainArgs)
                m_localPath.Assign(arg);
        return argn;
    }
};

#endif // _EVCSCO_HPP
