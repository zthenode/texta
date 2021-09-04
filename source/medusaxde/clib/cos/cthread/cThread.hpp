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
//   File: cThread.hpp
//
// Author: $author$
//   Date: 6/18/2011
///////////////////////////////////////////////////////////////////////
#if !defined(_CTHREAD_HPP) || defined(CTHREAD_MEMBERS_ONLY)
#if !defined(_CTHREAD_HPP) && !defined(CTHREAD_MEMBERS_ONLY)
#define _CTHREAD_HPP
#endif // !defined(_CTHREAD_HPP) && !defined(CTHREAD_MEMBERS_ONLY) 

#if !defined(CTHREAD_MEMBERS_ONLY)
#include "cThreadBase.hpp"

#if defined(WINDOWS) 
// Windows 
#if !defined(CTHREAD_WINDOWS_API) 
#if !defined(CTHREAD_PTHREAD_API) 
// Use Windows API 
#define CTHREAD_WINDOWS_API
#endif // !defined(CTHREAD_PTHREAD_API) 
#else // !defined(CTHREAD_WINDOWS_API) 
#if defined(CTHREAD_PTHREAD_API) 
// Use Windows API 
#undef CTHREAD_PTHREAD_API
#endif // defined(CTHREAD_PTHREAD_API) 
#endif // !defined(CTHREAD_WINDOWS_API) 
#else // defined(WINDOWS) 
// Unix 
#if !defined(CTHREAD_PTHREAD_API) 
#if !defined(CTHREAD_WINDOWS_API) 
// Use pthread API 
#define CTHREAD_PTHREAD_API
#endif // !defined(CTHREAD_WINDOWS_API) 
#else // !defined(CTHREAD_PTHREAD_API) 
#if defined(CTHREAD_WINDOWS_API) 
// Use pthread API 
#undef CTHREAD_WINDOWS_API
#endif // defined(CTHREAD_WINDOWS_API) 
#endif // !defined(CTHREAD_PTHREAD_API) 
#endif // defined(WINDOWS) 

#if defined(CTHREAD_WINDOWS_API) 
// Use Windows API 
#if defined(CTHREAD_WINDOWS_API_USE_CREATETHREAD) 
// Use CreateThread 
#include "cWinThread.hpp"
#else // defined(CTHREAD_WINDOWS_API_USE_CREATETHREAD) 
// Use beginthread 
#include "cWinCrtThread.hpp"
#endif // defined(CTHREAD_WINDOWS_API_USE_CREATETHREAD) 
#else // defined(CTHREAD_WINDOWS_API) 
// Use pthread API 
#include "cPThread.hpp"
#endif // defined(CTHREAD_WINDOWS_API) 

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

///////////////////////////////////////////////////////////////////////
// Typedef: cThreadExtends
//
//  Author: $author$
//    Date: 6/18/2011
///////////////////////////////////////////////////////////////////////
#if defined(CTHREAD_WINDOWS_API) 
// Use Windows API 
#if defined(CTHREAD_WINDOWS_API_USE_CREATETHREAD) 
// Use CreateThread 
typedef cWinThread
cThreadExtends;
#else // defined(CTHREAD_WINDOWS_API_USE_CREATETHREAD) 
// Use beginthread 
typedef cWinCrtThread
cThreadExtends;
#endif // defined(CTHREAD_WINDOWS_API_USE_CREATETHREAD) 
#else // defined(CTHREAD_WINDOWS_API) 
// Use pthread API 
typedef cPThread
cThreadExtends;
#endif // defined(CTHREAD_WINDOWS_API) 

///////////////////////////////////////////////////////////////////////
//  Class: cThread
//
// Author: $author$
//   Date: 6/18/2011
///////////////////////////////////////////////////////////////////////
class c_INSTANCE_CLASS cThread
: public cThreadExtends
{
public:
    typedef cThreadExtends cExtends;

    ///////////////////////////////////////////////////////////////////////
    //  Constructor: cThread
    //
    //       Author: $author$
    //         Date: 6/18/2011
    ///////////////////////////////////////////////////////////////////////
    cThread
    (bool create=false,
     bool initiallyStopped=false)
    : cExtends(create, initiallyStopped)
    {
    }
#else // !defined(CTHREAD_MEMBERS_ONLY) 
#endif // !defined(CTHREAD_MEMBERS_ONLY) 

#if !defined(CTHREAD_MEMBERS_ONLY)
};

#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#else // !defined(CTHREAD_MEMBERS_ONLY) 
#endif // !defined(CTHREAD_MEMBERS_ONLY) 

#endif // !defined(_CTHREAD_HPP) || defined(CTHREAD_MEMBERS_ONLY) 
        

