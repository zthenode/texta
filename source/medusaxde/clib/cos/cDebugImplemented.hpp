///////////////////////////////////////////////////////////////////////
// Copyright (c) 1988-2011 $organization$
//
// This software is provided by the author and contributors ``as is'' 
// and any express or implied warranties, including, but not limited to, 
// the implied warranties of merchantability and fitness for a particular 
// purpose are disclaimed. In no event shall the author or contributors 
// be liable for any direct, indirect, incidental, special, exemplary, 
// or consequential damages (including, but not limited to, procurement 
// of substitute goods or services; loss of use, data, or profits; or 
// business interruption) however caused and on any theory of liability, 
// whether in contract, strict liability, or tort (including negligence 
// or otherwise) arising in any way out of the use of this software, 
// even if advised of the possibility of such damage.
//
//   File: cDebugImplemented.hpp
//
// Author: $author$
//   Date: 5/25/2011
///////////////////////////////////////////////////////////////////////
#if !defined(_CDEBUGIMPLEMENTED_HPP) || defined(CDEBUGIMPLEMENTED_MEMBERS_ONLY)
#if !defined(_CDEBUGIMPLEMENTED_HPP) && !defined(CDEBUGIMPLEMENTED_MEMBERS_ONLY)
#define _CDEBUGIMPLEMENTED_HPP
#endif // !defined(_CDEBUGIMPLEMENTED_HPP) && !defined(CDEBUGIMPLEMENTED_MEMBERS_ONLY) 

#if !defined(CDEBUGIMPLEMENTED_MEMBERS_ONLY)
#include "cDebug.hpp"
#include "cMutex.hpp"
#include "cCharFile.hpp"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

///////////////////////////////////////////////////////////////////////
// Typedef: cDebugImplementedExtend
//
//  Author: $author$
//    Date: 5/25/2011
///////////////////////////////////////////////////////////////////////
typedef cDebug
cDebugImplementedExtend;
///////////////////////////////////////////////////////////////////////
//  Class: cDebugImplemented
//
// Author: $author$
//   Date: 5/25/2011
///////////////////////////////////////////////////////////////////////
class c_INSTANCE_CLASS cDebugImplemented
: //virtual public cDebugImplementedImplement,
  public cDebugImplementedExtend
{
public:
    //typedef cDebugImplementedImplement cImplements;
    typedef cDebugImplementedExtend cExtends;

    cMutex m_mutex;
    cCharFile m_stdOut;

    ///////////////////////////////////////////////////////////////////////
    //  Constructor: cDebugImplemented
    //
    //       Author: $author$
    //         Date: 5/25/2011
    ///////////////////////////////////////////////////////////////////////
    cDebugImplemented()
    {
    }
    ///////////////////////////////////////////////////////////////////////
    //  Destructor: ~cDebugImplemented
    //
    //      Author: $author$
    //        Date: 5/25/2011
    ///////////////////////////////////////////////////////////////////////
    virtual ~cDebugImplemented()
    {
    }
#else // !defined(CDEBUGIMPLEMENTED_MEMBERS_ONLY) 
#endif // !defined(CDEBUGIMPLEMENTED_MEMBERS_ONLY) 

    ///////////////////////////////////////////////////////////////////////
    //  Function: Initialize
    //
    //    Author: $author$
    //      Date: 5/25/2011
    ///////////////////////////////////////////////////////////////////////
    virtual eError Initialize
    (eDebugLevels levels=CDEBUG_DEFAULT_LEVELS, 
     cStreamInterface* out=0)
#if defined(CDEBUGIMPLEMENTED_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CDEBUGIMPLEMENTED_MEMBER_FUNCS_INTERFACE) 
    {
        eError error = e_ERROR_NONE;
#if !defined(CDEBUGIMPLEMENTED_MEMBER_FUNCS_IMPLEMENT)
        m_stdOut.Attach(stdout);

        if (!(out))
            out = &m_stdOut;

        if (!(error = m_mutex.Create()))
            error = cExtends::Initialize(levels, out);
#else // !defined(CDEBUGIMPLEMENTED_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CDEBUGIMPLEMENTED_MEMBER_FUNCS_IMPLEMENT) 
        return error;
    }
#endif // defined(CDEBUGIMPLEMENTED_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    //  Function: Finalize
    //
    //    Author: $author$
    //      Date: 5/25/2011
    ///////////////////////////////////////////////////////////////////////
    virtual eError Finalize()
#if defined(CDEBUGIMPLEMENTED_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CDEBUGIMPLEMENTED_MEMBER_FUNCS_INTERFACE) 
    {
        eError error = e_ERROR_NONE;
#if !defined(CDEBUGIMPLEMENTED_MEMBER_FUNCS_IMPLEMENT)
        eError error2 = e_ERROR_NONE;

        error = cExtends::Finalize();

        if ((error2 = m_mutex.Destroy()))
        if (!(error))
            error = error2;

        m_stdOut.Detach();
#else // !defined(CDEBUGIMPLEMENTED_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CDEBUGIMPLEMENTED_MEMBER_FUNCS_IMPLEMENT) 
        return error;
    }
#endif // defined(CDEBUGIMPLEMENTED_MEMBER_FUNCS_INTERFACE) 

    ///////////////////////////////////////////////////////////////////////
    //  Function: OutputMessage
    //
    //    Author: $author$
    //      Date: 5/25/2011
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t OutputMessage
    (eDebugLevels atLevels,
     const char* message)
#if defined(CDEBUGIMPLEMENTED_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CDEBUGIMPLEMENTED_MEMBER_FUNCS_INTERFACE) 
    {
        ssize_t count = 0;
#if !defined(CDEBUGIMPLEMENTED_MEMBER_FUNCS_IMPLEMENT)
        cStreamInterface* out;
        if ((message))
        {
            m_mutex.Lock();
            if ((Levels()) & (atLevels))
            if ((out = GetOut()))
                count = out->WriteL(message, m_endl, 0);
            m_mutex.Unlock();
        }
#else // !defined(CDEBUGIMPLEMENTED_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CDEBUGIMPLEMENTED_MEMBER_FUNCS_IMPLEMENT) 
        return count;
    }
#endif // defined(CDEBUGIMPLEMENTED_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    //  Function: OutputMessage
    //
    //    Author: $author$
    //      Date: 5/25/2011
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t OutputMessage
    (const char* message)
#if defined(CDEBUGIMPLEMENTED_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CDEBUGIMPLEMENTED_MEMBER_FUNCS_INTERFACE) 
    {
        ssize_t count = 0;
#if !defined(CDEBUGIMPLEMENTED_MEMBER_FUNCS_IMPLEMENT)
        if ((message))
        {
            cStreamInterface* out;
            m_mutex.Lock();
            if ((out = GetOut()))
                count = out->WriteL(message, m_endl, 0);
            m_mutex.Unlock();
        }
#else // !defined(CDEBUGIMPLEMENTED_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CDEBUGIMPLEMENTED_MEMBER_FUNCS_IMPLEMENT) 
        return count;
    }
#endif // defined(CDEBUGIMPLEMENTED_MEMBER_FUNCS_INTERFACE) 

#if !defined(CDEBUGIMPLEMENTED_MEMBERS_ONLY)
};

#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#else // !defined(CDEBUGIMPLEMENTED_MEMBERS_ONLY) 
#endif // !defined(CDEBUGIMPLEMENTED_MEMBERS_ONLY) 

#endif // !defined(_CDEBUGIMPLEMENTED_HPP) || defined(CDEBUGIMPLEMENTED_MEMBERS_ONLY) 

