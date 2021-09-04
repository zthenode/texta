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
//   File: cSemaphore.hpp
//
// Author: $author$
//   Date: 6/18/2011
///////////////////////////////////////////////////////////////////////
#if !defined(_CSEMAPHORE_HPP) || defined(CSEMAPHORE_MEMBERS_ONLY)
#if !defined(_CSEMAPHORE_HPP) && !defined(CSEMAPHORE_MEMBERS_ONLY)
#define _CSEMAPHORE_HPP
#endif // !defined(_CSEMAPHORE_HPP) && !defined(CSEMAPHORE_MEMBERS_ONLY) 

#if !defined(CSEMAPHORE_MEMBERS_ONLY)
#include "cSemaphoreBase.hpp"

#if defined(WINDOWS) 
// Windows 
#if !defined(CSEMAPHORE_WINDOWS_API) 
#if !defined(CSEMAPHORE_PTHREAD_API) 
// Use Windows API 
#define CSEMAPHORE_WINDOWS_API
#endif // !defined(CSEMAPHORE_PTHREAD_API) 
#else // !defined(CSEMAPHORE_WINDOWS_API) 
#if defined(CSEMAPHORE_PTHREAD_API) 
// Use Windows API 
#undef CSEMAPHORE_PTHREAD_API
#endif // defined(CSEMAPHORE_PTHREAD_API) 
#endif // !defined(CSEMAPHORE_WINDOWS_API) 
#else // defined(WINDOWS) 
// Unix 
#if !defined(CSEMAPHORE_PTHREAD_API) 
#if !defined(CSEMAPHORE_WINDOWS_API) 
// Use pthread API 
#define CSEMAPHORE_PTHREAD_API
#endif // !defined(CSEMAPHORE_WINDOWS_API) 
#else // !defined(CSEMAPHORE_PTHREAD_API) 
#if defined(CSEMAPHORE_WINDOWS_API) 
// Use pthread API 
#undef CSEMAPHORE_WINDOWS_API
#endif // defined(CSEMAPHORE_WINDOWS_API) 
#endif // !defined(CSEMAPHORE_PTHREAD_API) 
#endif // defined(WINDOWS) 

#if defined(CSEMAPHORE_WINDOWS_API) 
// Use Windows API 
#include "cWinSemaphore.hpp"
#else // defined(CSEMAPHORE_WINDOWS_API) 
// Use pthread API 
#include "cPThreadSemaphore.hpp"
#endif // defined(CSEMAPHORE_WINDOWS_API) 

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

///////////////////////////////////////////////////////////////////////
// Typedef: cSemaphoreExtends
//
//  Author: $author$
//    Date: 6/18/2011
///////////////////////////////////////////////////////////////////////
#if defined(CSEMAPHORE_WINDOWS_API) 
// Use Windows API 
typedef cWinSemaphore
cSemaphoreExtends;
#else // defined(CSEMAPHORE_WINDOWS_API) 
// Use pthread API 
typedef cPThreadSemaphore
cSemaphoreExtends;
#endif // defined(CSEMAPHORE_WINDOWS_API) 
///////////////////////////////////////////////////////////////////////
//  Class: cSemaphore
//
// Author: $author$
//   Date: 6/18/2011
///////////////////////////////////////////////////////////////////////
class c_INSTANCE_CLASS cSemaphore
: public cSemaphoreExtends
{
public:
    typedef cSemaphoreExtends cExtends;
    ///////////////////////////////////////////////////////////////////////
    //  Constructor: cSemaphore
    //
    //       Author: $author$
    //         Date: 6/18/2011
    ///////////////////////////////////////////////////////////////////////
    cSemaphore
    (bool create=false,
     unsigned int initialCount=0, int maximumCount=-1)
    : cExtends(create, initialCount, maximumCount)
    {
    }
#else // !defined(CSEMAPHORE_MEMBERS_ONLY) 
#endif // !defined(CSEMAPHORE_MEMBERS_ONLY) 

#if !defined(CSEMAPHORE_MEMBERS_ONLY)
};


#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#else // !defined(CSEMAPHORE_MEMBERS_ONLY) 
#endif // !defined(CSEMAPHORE_MEMBERS_ONLY) 

#endif // !defined(_CSEMAPHORE_HPP) || defined(CSEMAPHORE_MEMBERS_ONLY) 
        

