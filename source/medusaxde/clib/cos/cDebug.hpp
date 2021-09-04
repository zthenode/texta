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
//   File: cDebug.hpp
//
// Author: $author$
//   Date: 3/20/2011
///////////////////////////////////////////////////////////////////////
#if !defined(_CDEBUG_HPP) || defined(CDEBUG_MEMBERS_ONLY)
#if !defined(_CDEBUG_HPP) && !defined(CDEBUG_MEMBERS_ONLY)
#define _CDEBUG_HPP
#endif // !defined(_CDEBUG_HPP) && !defined(CDEBUG_MEMBERS_ONLY) 

#if !defined(CDEBUG_MEMBERS_ONLY)
#include "cDebugInterface.hpp"
#include "cStreamInterface.hpp"
#include "cInstanceBase.hpp"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

///////////////////////////////////////////////////////////////////////
// Typedef: cDebugExtend
//
//  Author: $author$
//    Date: 3/20/2011
///////////////////////////////////////////////////////////////////////
typedef cInstanceBase
cDebugExtend;
///////////////////////////////////////////////////////////////////////
//  Class: cDebug
//
// Author: $author$
//   Date: 3/20/2011
///////////////////////////////////////////////////////////////////////
class c_INSTANCE_CLASS cDebug
: virtual public cDebugImplement,
  public cDebugExtend
{
public:
    typedef cDebugImplement cImplements;
    typedef cDebugExtend cExtends;

    cStreamInterface* m_out;
    cStreamInterface* m_oldOut;
    eDebugLevels m_levels;
    char m_endl[2];
    
    ///////////////////////////////////////////////////////////////////////
    //  Constructor: cDebug
    //
    //       Author: $author$
    //         Date: 3/20/2011
    ///////////////////////////////////////////////////////////////////////
    cDebug()
    : m_out(0),
      m_oldOut(0),
      m_levels(CDEBUG_DEFAULT_LEVELS)
    {
        m_endl[0] = '\n';
        m_endl[1] = '\00';
    }
    ///////////////////////////////////////////////////////////////////////
    //  Destructor: ~cDebug
    //
    //      Author: $author$
    //        Date: 3/20/2011
    ///////////////////////////////////////////////////////////////////////
    virtual ~cDebug()
    {
    }
#else // !defined(CDEBUG_MEMBERS_ONLY) 
#endif // !defined(CDEBUG_MEMBERS_ONLY) 

    ///////////////////////////////////////////////////////////////////////
    //  Function: Initialize
    //
    //    Author: $author$
    //      Date: 3/20/2011
    ///////////////////////////////////////////////////////////////////////
    virtual eError Initialize
    (eDebugLevels levels=CDEBUG_DEFAULT_LEVELS, 
     cStreamInterface* out=0)
#if defined(CDEBUG_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CDEBUG_MEMBER_FUNCS_INTERFACE) 
    {
        eError error = e_ERROR_NONE;
#if !defined(CDEBUG_MEMBER_FUNCS_IMPLEMENT)
        m_levels = levels;
        m_oldOut = (m_out);
        m_out = (out);
#else // !defined(CDEBUG_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CDEBUG_MEMBER_FUNCS_IMPLEMENT) 
        return error;
    }
#endif // defined(CDEBUG_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    //  Function: Finalize
    //
    //    Author: $author$
    //      Date: 3/20/2011
    ///////////////////////////////////////////////////////////////////////
    virtual eError Finalize()
#if defined(CDEBUG_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CDEBUG_MEMBER_FUNCS_INTERFACE) 
    {
        eError error = e_ERROR_NONE;
#if !defined(CDEBUG_MEMBER_FUNCS_IMPLEMENT)
        m_out = (m_oldOut);
#else // !defined(CDEBUG_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CDEBUG_MEMBER_FUNCS_IMPLEMENT) 
        return error;
    }
#endif // defined(CDEBUG_MEMBER_FUNCS_INTERFACE) 

    ///////////////////////////////////////////////////////////////////////
    //  Function: OutputMessageFormatted
    //
    //    Author: $author$
    //      Date: 3/20/2011
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t OutputMessageFormatted
    (eDebugLevels atLevels,
     const char* format,
     ...)
#if defined(CDEBUG_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CDEBUG_MEMBER_FUNCS_INTERFACE) 
    {
        ssize_t count = 0;
#if !defined(CDEBUG_MEMBER_FUNCS_IMPLEMENT)
#else // !defined(CDEBUG_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CDEBUG_MEMBER_FUNCS_IMPLEMENT) 
        return count;
    }
#endif // defined(CDEBUG_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    //  Function: OutputMessageFormatted
    //
    //    Author: $author$
    //      Date: 3/20/2011
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t OutputMessageFormatted
    (const char* format,
     ...)
#if defined(CDEBUG_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CDEBUG_MEMBER_FUNCS_INTERFACE) 
    {
        ssize_t count = 0;
#if !defined(CDEBUG_MEMBER_FUNCS_IMPLEMENT)
#else // !defined(CDEBUG_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CDEBUG_MEMBER_FUNCS_IMPLEMENT) 
        return count;
    }
#endif // defined(CDEBUG_MEMBER_FUNCS_INTERFACE) 

    ///////////////////////////////////////////////////////////////////////
    //  Function: OutputMessageFormattedV
    //
    //    Author: $author$
    //      Date: 3/20/2011
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t OutputMessageFormattedV
    (eDebugLevels atLevels,
     const char* format,
     va_list va)
#if defined(CDEBUG_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CDEBUG_MEMBER_FUNCS_INTERFACE) 
    {
        ssize_t count = 0;
#if !defined(CDEBUG_MEMBER_FUNCS_IMPLEMENT)
#else // !defined(CDEBUG_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CDEBUG_MEMBER_FUNCS_IMPLEMENT) 
        return count;
    }
#endif // defined(CDEBUG_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    //  Function: OutputMessageFormattedV
    //
    //    Author: $author$
    //      Date: 3/20/2011
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t OutputMessageFormattedV
    (const char* format,
     va_list va)
#if defined(CDEBUG_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CDEBUG_MEMBER_FUNCS_INTERFACE) 
    {
        ssize_t count = 0;
#if !defined(CDEBUG_MEMBER_FUNCS_IMPLEMENT)
#else // !defined(CDEBUG_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CDEBUG_MEMBER_FUNCS_IMPLEMENT) 
        return count;
    }
#endif // defined(CDEBUG_MEMBER_FUNCS_INTERFACE) 

    ///////////////////////////////////////////////////////////////////////
    //  Function: OutputMessageL
    //
    //    Author: $author$
    //      Date: 3/20/2011
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t OutputMessageL
    (eDebugLevels atLevels,
     const char* message,
     ...)
#if defined(CDEBUG_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CDEBUG_MEMBER_FUNCS_INTERFACE) 
    {
        ssize_t count = 0;
#if !defined(CDEBUG_MEMBER_FUNCS_IMPLEMENT)
#else // !defined(CDEBUG_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CDEBUG_MEMBER_FUNCS_IMPLEMENT) 
        return count;
    }
#endif // defined(CDEBUG_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    //  Function: OutputMessageL
    //
    //    Author: $author$
    //      Date: 3/20/2011
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t OutputMessageL
    (const char* message,
     ...)
#if defined(CDEBUG_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CDEBUG_MEMBER_FUNCS_INTERFACE) 
    {
        ssize_t count = 0;
#if !defined(CDEBUG_MEMBER_FUNCS_IMPLEMENT)
#else // !defined(CDEBUG_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CDEBUG_MEMBER_FUNCS_IMPLEMENT) 
        return count;
    }
#endif // defined(CDEBUG_MEMBER_FUNCS_INTERFACE) 

    ///////////////////////////////////////////////////////////////////////
    //  Function: OutputMessageV
    //
    //    Author: $author$
    //      Date: 3/20/2011
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t OutputMessageV
    (eDebugLevels atLevels,
     const char* message,
     va_list va)
#if defined(CDEBUG_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CDEBUG_MEMBER_FUNCS_INTERFACE) 
    {
        ssize_t count = 0;
#if !defined(CDEBUG_MEMBER_FUNCS_IMPLEMENT)
#else // !defined(CDEBUG_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CDEBUG_MEMBER_FUNCS_IMPLEMENT) 
        return count;
    }
#endif // defined(CDEBUG_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    //  Function: OutputMessageV
    //
    //    Author: $author$
    //      Date: 3/20/2011
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t OutputMessageV
    (const char* message,
     va_list va)
#if defined(CDEBUG_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CDEBUG_MEMBER_FUNCS_INTERFACE) 
    {
        ssize_t count = 0;
#if !defined(CDEBUG_MEMBER_FUNCS_IMPLEMENT)
#else // !defined(CDEBUG_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CDEBUG_MEMBER_FUNCS_IMPLEMENT) 
        return count;
    }
#endif // defined(CDEBUG_MEMBER_FUNCS_INTERFACE) 

    ///////////////////////////////////////////////////////////////////////
    //  Function: OutputMessage
    //
    //    Author: $author$
    //      Date: 6/1/2011
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t OutputMessage
    (eDebugLevels atLevels,
     const cStringInterface& message)
#if defined(CDEBUG_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CDEBUG_MEMBER_FUNCS_INTERFACE) 
    {
        ssize_t count = 0;
#if !defined(CDEBUG_MEMBER_FUNCS_IMPLEMENT)
        const char* chars;
        if ((chars = message.HasChars()))
            count = OutputMessage(atLevels, chars);
#else // !defined(CDEBUG_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CDEBUG_MEMBER_FUNCS_IMPLEMENT) 
        return count;
    }
#endif // defined(CDEBUG_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    //  Function: OutputMessage
    //
    //    Author: $author$
    //      Date: 6/1/2011
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t OutputMessage
    (const cStringInterface& message)
#if defined(CDEBUG_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CDEBUG_MEMBER_FUNCS_INTERFACE) 
    {
        ssize_t count = 0;
#if !defined(CDEBUG_MEMBER_FUNCS_IMPLEMENT)
        const char* chars;
        if ((chars = message.HasChars()))
            count = OutputMessage(chars);
#else // !defined(CDEBUG_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CDEBUG_MEMBER_FUNCS_IMPLEMENT) 
        return count;
    }
#endif // defined(CDEBUG_MEMBER_FUNCS_INTERFACE) 

    ///////////////////////////////////////////////////////////////////////
    //  Function: OutputMessage
    //
    //    Author: $author$
    //      Date: 3/20/2011
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t OutputMessage
    (eDebugLevels atLevels,
     const char* message)
#if defined(CDEBUG_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CDEBUG_MEMBER_FUNCS_INTERFACE) 
    {
        ssize_t count = 0;
#if !defined(CDEBUG_MEMBER_FUNCS_IMPLEMENT)
        cStreamInterface* out;
        if ((message))
        if ((Levels()) & (atLevels))
        if ((out = GetOut()))
            count = out->WriteL(message, m_endl, 0);
#else // !defined(CDEBUG_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CDEBUG_MEMBER_FUNCS_IMPLEMENT) 
        return count;
    }
#endif // defined(CDEBUG_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    //  Function: OutputMessage
    //
    //    Author: $author$
    //      Date: 3/20/2011
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t OutputMessage
    (const char* message)
#if defined(CDEBUG_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CDEBUG_MEMBER_FUNCS_INTERFACE) 
    {
        ssize_t count = 0;
#if !defined(CDEBUG_MEMBER_FUNCS_IMPLEMENT)
        cStreamInterface* out;
        if ((message))
        if ((out = GetOut()))
            count = out->WriteL(message, m_endl, 0);
#else // !defined(CDEBUG_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CDEBUG_MEMBER_FUNCS_IMPLEMENT) 
        return count;
    }
#endif // defined(CDEBUG_MEMBER_FUNCS_INTERFACE) 

    ///////////////////////////////////////////////////////////////////////
    //  Function: SetOut
    //
    //    Author: $author$
    //      Date: 5/15/2011
    ///////////////////////////////////////////////////////////////////////
    virtual cStreamInterface* SetOut
    (cStreamInterface* toOut)
#if defined(CDEBUG_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CDEBUG_MEMBER_FUNCS_INTERFACE) 
    {
        cStreamInterface* out = 0;
#if !defined(CDEBUG_MEMBER_FUNCS_IMPLEMENT)
        out = (m_out = toOut);
#else // !defined(CDEBUG_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CDEBUG_MEMBER_FUNCS_IMPLEMENT) 
        return out;
    }
#endif // defined(CDEBUG_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    //  Function: GetOut
    //
    //    Author: $author$
    //      Date: 5/15/2011
    ///////////////////////////////////////////////////////////////////////
    virtual cStreamInterface* GetOut() const
#if defined(CDEBUG_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CDEBUG_MEMBER_FUNCS_INTERFACE) 
    {
        cStreamInterface* out = 0;
#if !defined(CDEBUG_MEMBER_FUNCS_IMPLEMENT)
        out = m_out;
#else // !defined(CDEBUG_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CDEBUG_MEMBER_FUNCS_IMPLEMENT) 
        return out;
    }
#endif // defined(CDEBUG_MEMBER_FUNCS_INTERFACE) 

    ///////////////////////////////////////////////////////////////////////
    //  Function: SetLevels
    //
    //    Author: $author$
    //      Date: 3/21/2011
    ///////////////////////////////////////////////////////////////////////
    virtual eDebugLevels SetLevels(eDebugLevels toLevels)
#if defined(CDEBUG_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CDEBUG_MEMBER_FUNCS_INTERFACE) 
    {
        eDebugLevels levels = e_DEBUG_LEVELS_NONE;
#if !defined(CDEBUG_MEMBER_FUNCS_IMPLEMENT)
        levels = (m_levels = toLevels);
#else // !defined(CDEBUG_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CDEBUG_MEMBER_FUNCS_IMPLEMENT) 
        return levels;
    }
#endif // defined(CDEBUG_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    //  Function: Levels
    //
    //    Author: $author$
    //      Date: 3/21/2011
    ///////////////////////////////////////////////////////////////////////
    virtual eDebugLevels Levels() const
#if defined(CDEBUG_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CDEBUG_MEMBER_FUNCS_INTERFACE) 
    {
        eDebugLevels levels = e_DEBUG_LEVELS_NONE;
#if !defined(CDEBUG_MEMBER_FUNCS_IMPLEMENT)
        levels = (m_levels);
#else // !defined(CDEBUG_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CDEBUG_MEMBER_FUNCS_IMPLEMENT) 
        return levels;
    }
#endif // defined(CDEBUG_MEMBER_FUNCS_INTERFACE) 

#if !defined(CDEBUG_MEMBER_FUNCS_IMPLEMENT)
#if defined(CDEBUG_MEMBER_FUNCS_INTERFACE) || defined(CDEBUG_GetInstance_INLINE)
    ///////////////////////////////////////////////////////////////////////
    //  Function: GetInstance
    //
    //    Author: $author$
    //      Date: 3/20/2011
    ///////////////////////////////////////////////////////////////////////
    static cDebugInterface& GetInstance()
#endif // defined(CDEBUG_MEMBER_FUNCS_INTERFACE) || defined(CDEBUG_GetInstance_INLINE)
#if defined(CDEBUG_MEMBER_FUNCS_INTERFACE)
    ;
#else // defined(CDEBUG_MEMBER_FUNCS_INTERFACE) 
#if defined(CDEBUG_GetInstance_INLINE)
    {
        static cDebug instance;
        return instance;
    }
#endif //defined(CDEBUG_GetInstance_INLINE)
#endif // defined(CDEBUG_MEMBER_FUNCS_INTERFACE) 
#else // !defined(CDEBUG_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CDEBUG_MEMBER_FUNCS_IMPLEMENT) 

#if !defined(CDEBUG_MEMBERS_ONLY)
};

#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#else // !defined(CDEBUG_MEMBERS_ONLY) 
#endif // !defined(CDEBUG_MEMBERS_ONLY) 

#endif // !defined(_CDEBUG_HPP) || defined(CDEBUG_MEMBERS_ONLY)

