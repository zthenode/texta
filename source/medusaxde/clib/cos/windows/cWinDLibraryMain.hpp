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
//   File: cWinDLibraryMain.hpp
//
// Author: $author$
//   Date: 10/16/2011
///////////////////////////////////////////////////////////////////////
#if !defined(_CWINDLIBRARYMAIN_HPP) || defined(CWINDLIBRARYMAIN_MEMBERS_ONLY)
#if !defined(_CWINDLIBRARYMAIN_HPP) && !defined(CWINDLIBRARYMAIN_MEMBERS_ONLY)
#define _CWINDLIBRARYMAIN_HPP
#endif // !defined(_CWINDLIBRARYMAIN_HPP) && !defined(CWINDLIBRARYMAIN_MEMBERS_ONLY) 

#if !defined(CWINDLIBRARYMAIN_MEMBERS_ONLY)
#include "cWinDLibraryMainInterface.hpp"
#include "cDLibraryMainBase.hpp"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

///////////////////////////////////////////////////////////////////////
// Typedef: cWinDLibraryMainExtend
//
//  Author: $author$
//    Date: 10/16/2011
///////////////////////////////////////////////////////////////////////
typedef cDLibraryMainBase
cWinDLibraryMainExtend;
///////////////////////////////////////////////////////////////////////
//  Class: cWinDLibraryMain
//
// Author: $author$
//   Date: 10/16/2011
///////////////////////////////////////////////////////////////////////
class c_INSTANCE_CLASS cWinDLibraryMain
: virtual public cWinDLibraryMainImplement,
  public cWinDLibraryMainExtend
{
public:
    typedef cWinDLibraryMainImplement cImplements;
    typedef cWinDLibraryMainExtend cExtends;
    ///////////////////////////////////////////////////////////////////////
    //  Constructor: cWinDLibraryMain
    //
    //       Author: $author$
    //         Date: 10/16/2011
    ///////////////////////////////////////////////////////////////////////
    cWinDLibraryMain()
    {
    }
    ///////////////////////////////////////////////////////////////////////
    //  Destructor: ~cWinDLibraryMain
    //
    //      Author: $author$
    //        Date: 10/16/2011
    ///////////////////////////////////////////////////////////////////////
    virtual ~cWinDLibraryMain()
    {
    }
#else // !defined(CWINDLIBRARYMAIN_MEMBERS_ONLY) 
#endif // !defined(CWINDLIBRARYMAIN_MEMBERS_ONLY) 

    ///////////////////////////////////////////////////////////////////////
    //  Function: DllMain
    //
    //    Author: $author$
    //      Date: 10/16/2011
    ///////////////////////////////////////////////////////////////////////
    virtual eError DllMain()
#if defined(CWINDLIBRARYMAIN_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CWINDLIBRARYMAIN_MEMBER_FUNCS_INTERFACE) 
    {
        eError error = e_ERROR_NONE;
#if !defined(CWINDLIBRARYMAIN_MEMBER_FUNCS_IMPLEMENT)
#else // !defined(CWINDLIBRARYMAIN_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CWINDLIBRARYMAIN_MEMBER_FUNCS_IMPLEMENT) 
        return error;
    }
#endif // defined(CWINDLIBRARYMAIN_MEMBER_FUNCS_INTERFACE) 

#if !defined(CWINDLIBRARYMAIN_MEMBERS_ONLY)
};


#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#else // !defined(CWINDLIBRARYMAIN_MEMBERS_ONLY) 
#endif // !defined(CWINDLIBRARYMAIN_MEMBERS_ONLY) 

#endif // !defined(_CWINDLIBRARYMAIN_HPP) || defined(CWINDLIBRARYMAIN_MEMBERS_ONLY) 
        

