///////////////////////////////////////////////////////////////////////
//   File: cevcs.hpp
//
// Author: $author$
//   Date: 5/24/2007
//
//    $Id$
///////////////////////////////////////////////////////////////////////

#ifndef _CEVCS_HPP
#define _CEVCS_HPP

#include "evcsarchive.hpp"
#include "cevcsdo.hpp"
#include "cevcscheckin.hpp"
#include "cevcscheckout.hpp"
#include "evcsopstack.hpp"
#include "evcsops.hpp"
#include "evcsop.hpp"
#include "evcs.hpp"
#include "cevstring.hpp"
#include "cevinstance.hpp"

///////////////////////////////////////////////////////////////////////
//  Class: CEvcs
//
// Author: $author$
//   Date: 5/24/2007
///////////////////////////////////////////////////////////////////////
class CEvcs
: virtual public Evcs,
  virtual public EvcsOpStack,
  public CEvInstance
{
public:
    typedef Evcs CImplements;
    typedef CEvInstance CExtends;
    typedef CEvcs CDerives;

    EvcsAllocator* m_allocator;
    EvcsArchive* m_archive;
    CEvString m_name;
    CEvString m_vcDir;
    CEvString m_ciDir;
    CEvString m_coDir;
    EvcsOpStack* m_opStack; 
    EvcsOp* m_stackOp;
    EvcsOp* m_op;
    EvcsOps m_ops;

    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvcs
    //
    //       Author: $author$
    //         Date: 5/24/2007
    ///////////////////////////////////////////////////////////////////////
    CEvcs
    (EvcsAllocator* allocator=0, 
     const char* name=0,
     const char* vcDir=DEFAULT_EVCS_VC_DIR,
     const char* ciDir=DEFAULT_EVCS_CI_DIR,
     const char* coDir=DEFAULT_EVCS_CO_DIR) 
    : m_allocator(allocator),
      m_archive(0),
      m_opStack(this),
      m_stackOp(0),
      m_op(0)
    {
        EvError error;
        LONG length;

        if (name)
        if (0 > (length = m_name.Assign(name)))
            throw(error = -length);

        if (vcDir)
        if (0 > (length = m_vcDir.Assign(vcDir)))
            throw(error = -length);

        if (ciDir)
        if (0 > (length = m_ciDir.Assign(ciDir)))
            throw(error = -length);

        if (coDir)
        if (0 > (length = m_coDir.Assign(coDir)))
            throw(error = -length);
    }
    ///////////////////////////////////////////////////////////////////////
    // Destructor: ~CEvcs
    //
    //      Author: $author$
    //        Date: 5/24/2007
    ///////////////////////////////////////////////////////////////////////
    virtual ~CEvcs()
    {
        EvError error;

        if (m_archive)
        if ((error = m_archive->Close()))
            throw(error);

        if ((error = CancelOps()))
            throw(error);
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: OpenArchive
    //
    //   Author: $author$
    //     Date: 9/28/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvcsArchive* OpenArchive
    (EvError& error,
     const char* name=0,
     LONG length=-1) 
    {
        EvcsArchive* archive = 0;
        error = EV_ERROR_FAILED;

        if ((archive = m_archive))
            error = EV_ERROR_NONE;
        else
        if ((archive = EvcsArchive::Open(error, name, length)))
            m_archive = archive;
        return archive;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: CloseArchive
    //
    //   Author: $author$
    //     Date: 9/28/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError CloseArchive
    (EvcsArchive& archive) 
    {
        EvError error = EV_ERROR_FAILED;
        if (&archive == m_archive)
            error = EV_ERROR_NONE;
        return error;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: CancelOps
    //
    //   Author: $author$
    //     Date: 5/25/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError CancelOps() 
    {
        EvError error = EV_ERROR_NONE;
        EvError error2;
        EvcsOpsIterator i;
        EvcsOp* op;

        for (i = m_ops.end(); i != m_ops.begin(); --i)
        {
            if ((op = *i))
            {
                if ((error2 = op->Cancel()) && !error)
                    error = error2;
                if ((error2 = op->DeleteInstance()) && !error)
                    error = error2;
            }
        }
        m_ops.clear();
        m_op = 0;
        return error;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: StartDoOp
    //
    //   Author: $author$
    //     Date: 5/24/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError StartDoOp() 
    {
        EvError error = EV_ERROR_NEW;
/*        CEvcsDo* op;

        if ((op = new CEvcsDo
            (m_opStack, m_stackOp)))
        if ((error = op->Begin()))
            op->DeleteInstance();
        else if ((error = m_opStack->PushOp(*op)))
                op->DeleteInstance();
        else
        {
            m_op = op;
            m_stackOp = op;
            m_opStack = op;
            error = EV_ERROR_NONE;
        }
*/
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: StartCheckInOp
    //
    //   Author: $author$
    //     Date: 5/25/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError StartCheckInOp
    (const char* evcName, 
     const EvFileSystemEntryTimes& fileTimes,
     bool isBinary=false) 
    {
        EvError error = EV_ERROR_NEW;
        CEvcsCheckIn* op;
        const char* chars;
        LONG length;

        if ((op = new CEvcsCheckIn()))
        {
            if ((chars = m_vcDir.Chars(length)) && (0 < length))
                op->SetVcDirectory(chars, length);

            if ((chars = m_ciDir.Chars(length)) && (0 < length))
                op->SetTempDirectory(chars, length);

            if (!(error = op->Open(evcName, fileTimes, isBinary)))
            if (!(error = m_opStack->PushOp(*op)))
            {
                m_op = op;
                return error;
            }
            op->DeleteInstance();
        }
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: StartCheckOutOp
    //
    //   Author: $author$
    //     Date: 8/17/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError StartCheckOutOp
    (CEvFilePath& filePath,
     EvFileSystemEntry& fileEntry,
     const char* evcName, 
     bool isBinary=false, 
     bool isRecursive=false) 
    {
        EvError error = EV_ERROR_NEW;
        CEvcsCheckOut* op;
        const char* chars;
        LONG length;

        if ((op = new CEvcsCheckOut()))
        {
            if ((chars = m_vcDir.Chars(length)) && (0 < length))
                op->SetVcDirectory(chars, length);

            if ((chars = m_coDir.Chars(length)) && (0 < length))
                op->SetTempDirectory(chars, length);

            if (!(error = op->OpenFirst
                (filePath, fileEntry, 
                 evcName, isBinary, isRecursive)))
            if (!(error = m_opStack->PushOp(*op)))
            {
                m_op = op;
                return error;
            }
            op->DeleteInstance();
        }
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: ContinueCheckOutOp
    //
    //   Author: $author$
    //     Date: 8/21/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError ContinueCheckOutOp
    (CEvFilePath& filePath,
     EvFileSystemEntry& fileEntry) 
    {
        EvError error = EV_ERROR_FAILED;
        if (m_op)
            error = m_op->OpenNext
            (filePath, fileEntry);
        return error;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: WriteOpData
    //
    //   Author: $author$
    //     Date: 5/25/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG WriteOpData
    (const char* chars, LONG length=-1) 
    {
        if (m_op)
            length = m_op->Write(chars, length);
        else length = -EV_ERROR_FAILED;
        return length;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: ReadOpData
    //
    //   Author: $author$
    //     Date: 8/17/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG ReadOpData
    (char* chars, ULONG size)
    {
        ULONG length = -EV_ERROR_FAILED;
        if (m_op)
            length = m_op->Read(chars, size);
        return length;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: FinishOp
    //
    //   Author: $author$
    //     Date: 5/25/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError FinishOp() 
    {
        EvError error = EV_ERROR_FAILED;
        EvError error2;
        EvcsOp* op;

        if ((op = m_op))
        {
            if (op != m_stackOp)
            {
                m_op = 0;

                if (m_stackOp)
                    error = op->Continue();
                else if ((op = m_opStack->PopOp(error2)))
                {
                    error = op->Commit();

                    if ((error2 = op->DeleteInstance()) && !error)
                        error = error2;
                }
            }
            else if ((m_op = (m_stackOp = op->GetParent(error2))))
            {
                if ((m_opStack = op->GetStack(error2)))
                    error = EV_ERROR_NONE;
                else m_opStack = this;
            }
            else
            {
                error = op->Commit();
                
                if (!(m_opStack = op->GetStack(error2)))
                {
                    if (!error)
                        error = EV_ERROR_FAILED;
                    m_opStack = this;
                }

                if ((error2 = op->DeleteInstance()) && !error)
                    error = error2;
            }
        }
        else if ((op = m_stackOp))
        {
            if ((m_op = (m_stackOp = op->GetParent(error2))))
            {
                if ((m_opStack = op->GetStack(error2)))
                    error = EV_ERROR_NONE;
                else m_opStack = this;
            }
            else
            {
                error = op->Commit();
                
                if (!(m_opStack = op->GetStack(error2)))
                {
                    if (!error)
                        error = EV_ERROR_FAILED;
                    m_opStack = this;
                }

                if ((error2 = op->DeleteInstance()) && !error)
                    error = error2;
            }
        }
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: CancelOp
    //
    //   Author: $author$
    //     Date: 5/25/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError CancelOp() 
    {
        EvError error = EV_ERROR_FAILED;
        EvError error2;
        EvcsOp* op;

        if ((op = m_op))
        {
            if (op != m_stackOp)
            {
                m_op = 0;

                if (m_stackOp)
                    error = op->Cancel();
                else if ((op = m_opStack->PopOp(error2)))
                {
                    error = op->Cancel();
                    if ((error2 = op->DeleteInstance()) && !error)
                        error = error2;
                }
            }
            else if ((m_op = (m_stackOp = op->GetParent(error2))))
            {
                if ((m_opStack = op->GetStack(error2)))
                    error = EV_ERROR_NONE;
                else m_opStack = this;
            }
            else
            {
                error = op->Cancel();

                if (!(m_opStack = op->GetStack(error2)))
                {
                    if (!error)
                        error = EV_ERROR_FAILED;
                    m_opStack = this;
                }

                if ((error2 = op->DeleteInstance()) && !error)
                    error = error2;
            }
        }
        else if ((op = m_stackOp))
        {
            if ((m_op = (m_stackOp = op->GetParent(error2))))
            {
                if ((m_opStack = op->GetStack(error2)))
                    error = EV_ERROR_NONE;
                else m_opStack = this;
            }
            else
            {
                error = op->Cancel();
                
                if (!(m_opStack = op->GetStack(error2)))
                {
                    if (!error)
                        error = EV_ERROR_FAILED;
                    m_opStack = this;
                }

                if ((error2 = op->DeleteInstance()) && !error)
                    error = error2;
            }
        }
        return error;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: PushOp
    //
    //   Author: $author$
    //     Date: 5/30/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError PushOp(EvcsOp& op) 
    {
        EvError error = EV_ERROR_NONE;
        m_ops.push_back(&op);
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: PopOp
    //
    //   Author: $author$
    //     Date: 5/30/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvcsOp* PopOp(EvError& error) 
    {
        EvcsOp* op = 0;
        unsigned size;

        if (0 < (size = (unsigned)m_ops.size()))
        {
            op = m_ops[size-1];
            m_ops.pop_back();
        }
        error = EV_ERROR_NONE;
        return op;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: TopOp
    //
    //   Author: $author$
    //     Date: 9/17/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvcsOp* TopOp(EvError& error) const
    {
        EvcsOp* op = 0;
        unsigned size;

        if (0 < (size = (unsigned)m_ops.size()))
            op = m_ops[size-1];

        error = EV_ERROR_NONE;
        return op;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: SetAllocator
    //
    //   Author: $author$
    //     Date: 5/24/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvcsAllocator* SetAllocator
    (EvcsAllocator* allocator) 
    {
        m_allocator = allocator;
        return m_allocator;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: GetAllocator
    //
    //   Author: $author$
    //     Date: 5/24/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvcsAllocator* GetAllocator() const 
    {
        return m_allocator;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: SetName
    //
    //   Author: $author$
    //     Date: 5/26/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG SetName
    (const char* chars, LONG length=-1) 
    {
        length = m_name.Assign(chars, length);
        return length;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: GetName
    //
    //   Author: $author$
    //     Date: 5/26/2007
    ///////////////////////////////////////////////////////////////////////
    virtual const char* GetName
    (LONG& length) const 
    {
        const char* chars = m_name.Chars(length);
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

    ///////////////////////////////////////////////////////////////////////
    // Function: DeleteThis
    //
    //   Author: $author$
    //     Date: 9/28/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError DeleteThis() 
    {
        delete this;
        return EV_ERROR_NONE;
    }
};
#endif // _CEVCS_HPP
