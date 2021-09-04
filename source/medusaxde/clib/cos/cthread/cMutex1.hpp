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
//   Date: 3/21/2011
///////////////////////////////////////////////////////////////////////
#if !defined(_CMUTEX_HPP) || defined(CMUTEX_MEMBERS_ONLY)
#if !defined(_CMUTEX_HPP) && !defined(CMUTEX_MEMBERS_ONLY)
#define _CMUTEX_HPP
#endif // !defined(_CMUTEX_HPP) && !defined(CMUTEX_MEMBERS_ONLY) 

#if !defined(CMUTEX_MEMBERS_ONLY)
#include "cMutexInterface.hpp"

#if defined(WINDOWS) 
// Windows 
#if !defined(CMUTEX_WINDOWS_API) 
#if !defined(CMUTEX_PTHREAD_API)
#define CMUTEX_WINDOWS_API
#endif // !defined(CMUTEX_PTHREAD_API) 
#else // !defined(CMUTEX_WINDOWS_API) 
#if defined(CMUTEX_PTHREAD_API)
#undef CMUTEX_PTHREAD_API
#endif // defined(CMUTEX_PTHREAD_API) 
#endif // !defined(CMUTEX_WINDOWS_API) 
#else // defined(WINDOWS) 
// Unix 
#if !defined(CMUTEX_PTHREAD_API) 
#if !defined(CMUTEX_WINDOWS_API)
#define CMUTEX_PTHREAD_API
#endif // !defined(CMUTEX_WINDOWS_API) 
#else // !defined(CMUTEX_PTHREAD_API) 
#if defined(CMUTEX_WINDOWS_API)
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

#else // !defined(CMUTEX_MEMBERS_ONLY) 
#endif // !defined(CMUTEX_MEMBERS_ONLY) 

#endif // !defined(_CMUTEX_HPP) || defined(CMUTEX_MEMBERS_ONLY) 
