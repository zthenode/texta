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
//   File: cDLibrary.hpp
//
// Author: $author$
//   Date: 10/14/2011
///////////////////////////////////////////////////////////////////////
#if !defined(_CDLIBRARY_HPP) || defined(CDLIBRARY_MEMBERS_ONLY)
#if !defined(_CDLIBRARY_HPP) && !defined(CDLIBRARY_MEMBERS_ONLY)
#define _CDLIBRARY_HPP
#endif // !defined(_CDLIBRARY_HPP) && !defined(CDLIBRARY_MEMBERS_ONLY) 

#if !defined(CDLIBRARY_MEMBERS_ONLY)
#include "cDLibraryInterface.hpp"

#if defined(WINDOWS) 
// Windows 
#include "cWinDLibrary.hpp"
#else // defined(WINDOWS) 
// Unix 
#include "cUnixDLibrary.hpp"
#endif // defined(WINDOWS) 

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

///////////////////////////////////////////////////////////////////////
// Typedef: cDLibraryExtend
//
//  Author: $author$
//    Date: 10/14/2011
///////////////////////////////////////////////////////////////////////
#if defined(WINDOWS) 
// Windows 
typedef cWinDLibrary
cDLibraryExtend;
#else // defined(WINDOWS) 
// Unix 
typedef cUnixDLibrary
cDLibraryExtend;
#endif // defined(WINDOWS)

///////////////////////////////////////////////////////////////////////
//  Class: cDLibrary
//
// Author: $author$
//   Date: 10/14/2011
///////////////////////////////////////////////////////////////////////
class c_INSTANCE_CLASS cDLibrary
: public cDLibraryExtend
{
public:
    typedef cDLibraryExtend cExtends;
    ///////////////////////////////////////////////////////////////////////
    //  Constructor: cDLibrary
    //
    //       Author: $author$
    //         Date: 10/14/2011
    ///////////////////////////////////////////////////////////////////////
    cDLibrary
    (const char* fileName=0)
    {
        eError error;
        if ((fileName))
        if ((error = Load(fileName)))
        {
            c_DB_ERROR("() failed on Load(" << fileName << ")");
            throw error;
        }
    }
    ///////////////////////////////////////////////////////////////////////
    //  Constructor: cDLibrary
    //
    //       Author: $author$
    //         Date: 10/14/2011
    ///////////////////////////////////////////////////////////////////////
    cDLibrary
    (const wchar_t* fileName)
    {
        eError error;
        if ((fileName))
        if ((error = Load(fileName)))
        {
            c_DB_ERROR("() failed on Load(" << fileName << ")");
            throw error;
        }
    }
    ///////////////////////////////////////////////////////////////////////
    //  Destructor: ~cDLibrary
    //
    //      Author: $author$
    //        Date: 10/14/2011
    ///////////////////////////////////////////////////////////////////////
    virtual ~cDLibrary()
    {
        eError error;
        if ((error = Unloaded()))
        {
            c_DB_ERROR("() failed on  Unloaded()");
            throw error;
        }
    }
#else // !defined(CDLIBRARY_MEMBERS_ONLY) 
#endif // !defined(CDLIBRARY_MEMBERS_ONLY) 

#if !defined(CDLIBRARY_MEMBERS_ONLY)
};


#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#else // !defined(CDLIBRARY_MEMBERS_ONLY) 
#endif // !defined(CDLIBRARY_MEMBERS_ONLY) 

#endif // !defined(_CDLIBRARY_HPP) || defined(CDLIBRARY_MEMBERS_ONLY) 
        

