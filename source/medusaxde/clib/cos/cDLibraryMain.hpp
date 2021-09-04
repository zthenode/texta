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
//   File: cDLibraryMain.hpp
//
// Author: $author$
//   Date: 10/20/2011
///////////////////////////////////////////////////////////////////////
#if !defined(_CDLIBRARYMAIN_HPP) || defined(CDLIBRARYMAIN_MEMBERS_ONLY)
#if !defined(_CDLIBRARYMAIN_HPP) && !defined(CDLIBRARYMAIN_MEMBERS_ONLY)
#define _CDLIBRARYMAIN_HPP
#endif // !defined(_CDLIBRARYMAIN_HPP) && !defined(CDLIBRARYMAIN_MEMBERS_ONLY) 

#if !defined(CDLIBRARYMAIN_MEMBERS_ONLY)
#include "cDLibraryMainInterface.hpp"

#if defined(USE_WINDOWS_DLIBRARY_API) 
// Use Windows API 
#include "cWinDLibraryMain.hpp"
#else // defined(USE_WINDOWS_DLIBRARY_API) 
// Use Unix API 
#include "cUnixDLibraryMain.hpp"
#endif // defined(USE_WINDOWS_DLIBRARY_API) 

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

///////////////////////////////////////////////////////////////////////
// Typedef: cDLibraryMainImplement
//
//  Author: $author$
//    Date: 10/20/2011
///////////////////////////////////////////////////////////////////////
#if defined(USE_WINDOWS_DLIBRARY_API) 
// Use Windows API 
typedef cWinDLibraryMainImplement
#else // defined(USE_WINDOWS_DLIBRARY_API) 
// Use Unix API 
typedef cUnixDLibraryMainImplement
#endif // defined(USE_WINDOWS_DLIBRARY_API) 
cDerivedDLibraryMainImplement;
///////////////////////////////////////////////////////////////////////
// Typedef: cDLibraryMainExtend
//
//  Author: $author$
//    Date: 10/20/2011
///////////////////////////////////////////////////////////////////////
#if defined(USE_WINDOWS_DLIBRARY_API) 
// Use Windows API 
typedef cWinDLibraryMain
#else // defined(USE_WINDOWS_DLIBRARY_API) 
// Use Unix API 
typedef cUnixDLibraryMain
#endif // defined(USE_WINDOWS_DLIBRARY_API) 
cDLibraryMainExtend;
///////////////////////////////////////////////////////////////////////
//  Class: cDLibraryMain
//
// Author: $author$
//   Date: 10/20/2011
///////////////////////////////////////////////////////////////////////
class c_INSTANCE_CLASS cDLibraryMain
: virtual public cDerivedDLibraryMainImplement,
  public cDLibraryMainExtend
{
public:
    typedef cDerivedDLibraryMainImplement cImplements;
    typedef cDLibraryMainExtend cExtends;
    ///////////////////////////////////////////////////////////////////////
    //  Constructor: cDLibraryMain
    //
    //       Author: $author$
    //         Date: 10/20/2011
    ///////////////////////////////////////////////////////////////////////
    cDLibraryMain()
    {
    }
    ///////////////////////////////////////////////////////////////////////
    //  Destructor: ~cDLibraryMain
    //
    //      Author: $author$
    //        Date: 10/20/2011
    ///////////////////////////////////////////////////////////////////////
    virtual ~cDLibraryMain()
    {
    }
#else // !defined(CDLIBRARYMAIN_MEMBERS_ONLY) 
#endif // !defined(CDLIBRARYMAIN_MEMBERS_ONLY) 

#if !defined(CDLIBRARYMAIN_MEMBERS_ONLY)
};


#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#else // !defined(CDLIBRARYMAIN_MEMBERS_ONLY) 
#endif // !defined(CDLIBRARYMAIN_MEMBERS_ONLY) 

#endif // !defined(_CDLIBRARYMAIN_HPP) || defined(CDLIBRARYMAIN_MEMBERS_ONLY) 
        

