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
//   File: cDebugInterface.hpp
//
// Author: $author$
//   Date: 3/20/2011
///////////////////////////////////////////////////////////////////////
#if !defined(_CDEBUGINTERFACE_HPP) || defined(CDEBUGINTERFACE_MEMBERS_ONLY)
#if !defined(_CDEBUGINTERFACE_HPP) && !defined(CDEBUGINTERFACE_MEMBERS_ONLY)
#define _CDEBUGINTERFACE_HPP
#endif // !defined(_CDEBUGINTERFACE_HPP) && !defined(CDEBUGINTERFACE_MEMBERS_ONLY) 

#if !defined(CDEBUGINTERFACE_MEMBERS_ONLY)
#include "cInterfaceBase.hpp"
#include "cStreamInterface.hpp"
#include "cString.hpp"

#define CDEBUG_DEFAULT_LEVELS e_DEBUG_LEVELS_WARNING

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

#if !defined(C_NO_DEBUG) 
//
// enable debug macros 
//
#define c_DEBUG_STRINGX(x) "" #x ""
#define c_DEBUG_STRING(x) c_DEBUG_STRINGX(x)

#define c_DEBUG_INIT_LEVELS_OUT(levels, out)\
cDebugInterface::GetInstance().Initialize(levels, out)

#define c_DEBUG_INIT_LEVELS(levels)\
cDebugInterface::GetInstance().Initialize(levels)

#define c_DEBUG_INIT()\
cDebugInterface::GetInstance().Initialize()

#define c_DEBUG_FINISH()\
cDebugInterface::GetInstance().Finalize()

#define c_DEBUG_SET_OUT(out)\
cDebugInterface::GetInstance().SetOut(out)

#define c_DEBUG_GET_OUT()\
cDebugInterface::GetInstance().GetOut()

#define c_DEBUG_SET_LEVELS(levels)\
cDebugInterface::GetInstance().SetLevels(levels)

#define c_DEBUG(args)\
cDebugInterface::GetInstance().OutputMessage\
(cString(__FILE__) << cString(":") << cString(c_DEBUG_STRING(__LINE__))\
 << cString(" ") << cString(__FUNCTION__) << args)

#define c_DEBUG_AT_LEVEL(levels, level, args)\
cDebugInterface::GetInstance().OutputMessage\
(levels, cString(__FILE__) << cString(":") << cString(c_DEBUG_STRING(__LINE__))\
 << cString(level) << cString(" ") << cString(__FUNCTION__) << args)
#else // !defined(C_NO_DEBUG) 
//
// disable debug macros 
//
#define c_DEBUG_INIT_LEVELS_OUT(levels, out) e_ERROR_NONE
#define c_DEBUG_INIT_LEVELS(levels) e_ERROR_NONE
#define c_DEBUG_INIT()) e_ERROR_NONE
#define c_DEBUG_FINISH()) e_ERROR_NONE
#define c_DEBUG_SET_OUT(out) out
#define c_DEBUG_GET_OUT() 0
#define c_DEBUG_SET_LEVELS(levels) levels
#define c_DEBUG(args)
#define c_DEBUG_AT_LEVEL(levels, level, args)
#endif // !defined(C_NO_DEBUG) 

#define c_DB_ERROR(args) c_DEBUG_AT_LEVEL(e_DEBUG_LEVEL_ERROR, " error", args)
#define c_DB_WARNING(args) c_DEBUG_AT_LEVEL(e_DEBUG_LEVEL_WARNING, " warning", args)
#define c_DB_INFO(args) c_DEBUG_AT_LEVEL(e_DEBUG_LEVEL_INFO, "", args)
#define c_DB_FUNC(args) c_DEBUG_AT_LEVEL(e_DEBUG_LEVEL_FUNC, "", args)
#define c_DB_TRACE(args) c_DEBUG_AT_LEVEL(e_DEBUG_LEVEL_TRACE, "", args)
#define c_DB_MAX(args) c_DEBUG_AT_LEVEL(e_DEBUG_LEVEL_MAX, "", args)
#define c_DB_ALL(args) c_DEBUG_AT_LEVEL(e_DEBUG_LEVELS_ALL, "", args)
#define c_DB(args) c_DEBUG(args)

///////////////////////////////////////////////////////////////////////
//    Enum: eDebugLevels
//
//  Author: $author$
//    Date: 3/20/2011
///////////////////////////////////////////////////////////////////////
typedef int eDebugLevels;
enum
{
    e_DEBUG_LEVELS_NONE    = 0,
    e_DEBUG_LEVELS_ERROR   = 1,
    e_DEBUG_LEVELS_WARNING = ((1<<2)-1),
    e_DEBUG_LEVELS_INFO    = ((1<<3)-1),
    e_DEBUG_LEVELS_FUNC    = ((1<<4)-1),
    e_DEBUG_LEVELS_TRACE   = ((1<<5)-1),

    e_DEBUG_LEVELS_ALL     = ((1<<6)-1)
};
///////////////////////////////////////////////////////////////////////
//    Enum: eDebugLevel
//
//  Author: $author$
//    Date: 3/20/2011
///////////////////////////////////////////////////////////////////////
typedef int eDebugLevel;
enum
{
    e_DEBUG_LEVEL_NONE    = 0,

    e_DEBUG_LEVEL_ERROR   = 1,
    e_DEBUG_LEVEL_WARNING = (1<<1),
    e_DEBUG_LEVEL_INFO    = (1<<2),
    e_DEBUG_LEVEL_FUNC    = (1<<3),
    e_DEBUG_LEVEL_TRACE   = (1<<4),

    e_DEBUG_LEVEL_MIN     = (e_DEBUG_LEVEL_ERROR),
    e_DEBUG_LEVEL_MAX     = (e_DEBUG_LEVEL_TRACE)
};

///////////////////////////////////////////////////////////////////////
// Typedef: cDebugInterfaceImplement
//
//  Author: $author$
//    Date: 3/20/2011
///////////////////////////////////////////////////////////////////////
typedef cInterfaceBase
cDebugInterfaceImplement;
///////////////////////////////////////////////////////////////////////
//  Class: cDebugInterface
//
// Author: $author$
//   Date: 3/20/2011
///////////////////////////////////////////////////////////////////////
class c_INTERFACE_CLASS cDebugInterface
: virtual public cDebugInterfaceImplement
{
public:
    typedef cDebugInterfaceImplement cImplements;
#else // !defined(CDEBUGINTERFACE_MEMBERS_ONLY) 
#endif // !defined(CDEBUGINTERFACE_MEMBERS_ONLY) 

#if !defined(CDEBUGINTERFACE_MEMBERS_ONLY)
// include cDebug member functions interface
// 
#define CDEBUG_MEMBERS_ONLY
#define CDEBUG_MEMBER_FUNCS_INTERFACE
#include "cDebug.hpp"
#undef CDEBUG_MEMBER_FUNCS_INTERFACE
#undef CDEBUG_MEMBERS_ONLY
};

#if !defined(CDEBUGIMPLEMENT_MEMBERS_ONLY)
///////////////////////////////////////////////////////////////////////
//  Class: cDebugImplement
//
// Author: $author$
//   Date: 3/20/2011
///////////////////////////////////////////////////////////////////////
class c_IMPLEMENT_CLASS cDebugImplement
: virtual public cDebugInterface
{
public:
    typedef cDebugInterface cImplements;
#else // !defined(CDEBUGIMPLEMENT_MEMBERS_ONLY) 
#endif // !defined(CDEBUGIMPLEMENT_MEMBERS_ONLY) 

#if !defined(CDEBUGIMPLEMENT_MEMBERS_ONLY)
// include cDebug member functions implement
// 
#define CDEBUG_MEMBERS_ONLY
#define CDEBUG_MEMBER_FUNCS_IMPLEMENT
#include "cDebug.hpp"
#undef CDEBUG_MEMBER_FUNCS_IMPLEMENT
#undef CDEBUG_MEMBERS_ONLY
};
#else // !defined(CDEBUGIMPLEMENT_MEMBERS_ONLY) 
#endif // !defined(CDEBUGIMPLEMENT_MEMBERS_ONLY) 

#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#else // !defined(CDEBUGINTERFACE_MEMBERS_ONLY) 
#endif // !defined(CDEBUGINTERFACE_MEMBERS_ONLY) 

#endif // !defined(_CDEBUGINTERFACE_HPP) || defined(CDEBUGINTERFACE_MEMBERS_ONLY) 
