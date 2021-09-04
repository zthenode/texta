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
//   File: cMutex.hpp
//
// Author: $author$
//   Date: 6/19/2011
///////////////////////////////////////////////////////////////////////
#if !defined(_CMUTEX_HPP) || defined(CMUTEX_MEMBERS_ONLY)
#if !defined(_CMUTEX_HPP) && !defined(CMUTEX_MEMBERS_ONLY)
#define _CMUTEX_HPP
#endif // !defined(_CMUTEX_HPP) && !defined(CMUTEX_MEMBERS_ONLY) 

#if !defined(CMUTEX_MEMBERS_ONLY)
#include "cMutexBase.hpp"

#if defined(WINDOWS) 
// Windows 
#if !defined(CMUTEX_WINDOWS_API) 
#if !defined(CMUTEX_PTHREAD_API) 
// Use Windows API 
#define CMUTEX_WINDOWS_API
#endif // !defined(CMUTEX_PTHREAD_API) 
#else // !defined(CMUTEX_WINDOWS_API) 
#if defined(CMUTEX_PTHREAD_API) 
// Use Windows API 
#undef CMUTEX_PTHREAD_API
#endif // defined(CMUTEX_PTHREAD_API) 
#endif // !defined(CMUTEX_WINDOWS_API) 
#else // defined(WINDOWS) 
// Unix 
#if !defined(CMUTEX_PTHREAD_API) 
#if !defined(CMUTEX_WINDOWS_API) 
// Use pthread API 
#define CMUTEX_PTHREAD_API
#endif // !defined(CMUTEX_WINDOWS_API) 
#else // !defined(CMUTEX_PTHREAD_API) 
#if defined(CMUTEX_WINDOWS_API) 
// Use pthread API 
#undef CMUTEX_WINDOWS_API
#endif // defined(CMUTEX_WINDOWS_API) 
#endif // !defined(CMUTEX_PTHREAD_API) 
#endif // defined(WINDOWS) 

#if defined(CMUTEX_WINDOWS_API) 
// Use Windows API 
#include "cWinMutex.hpp"
#else // defined(CMUTEX_WINDOWS_API) 
// Use pthread API 
#include "cPThreadMutex.hpp"
#endif // defined(CMUTEX_WINDOWS_API) 

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

///////////////////////////////////////////////////////////////////////
// Typedef: cMutexExtends
//
//  Author: $author$
//    Date: 6/19/2011
///////////////////////////////////////////////////////////////////////
#if defined(CMUTEX_WINDOWS_API) 
// Use Windows API 
typedef cWinMutex
cMutexExtends;
#else // defined(CMUTEX_WINDOWS_API) 
// Use pthread API 
typedef cPThreadMutex
cMutexExtends;
#endif // defined(CMUTEX_WINDOWS_API) 
///////////////////////////////////////////////////////////////////////
//  Class: cMutex
//
// Author: $author$
//   Date: 6/19/2011
///////////////////////////////////////////////////////////////////////
class c_INSTANCE_CLASS cMutex
: public cMutexExtends
{
public:
    typedef cMutexExtends cExtends;
    ///////////////////////////////////////////////////////////////////////
    //  Constructor: cMutex
    //
    //       Author: $author$
    //         Date: 6/19/2011
    ///////////////////////////////////////////////////////////////////////
    cMutex
    (bool create=false,
     bool initiallyLocked=false)
    : cExtends(create, initiallyLocked)
    {
    }
#else // !defined(CMUTEX_MEMBERS_ONLY) 
#endif // !defined(CMUTEX_MEMBERS_ONLY) 

#if !defined(CMUTEX_MEMBERS_ONLY)
};

#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#else // !defined(CMUTEX_MEMBERS_ONLY) 
#endif // !defined(CMUTEX_MEMBERS_ONLY) 

#endif // !defined(_CMUTEX_HPP) || defined(CMUTEX_MEMBERS_ONLY) 
