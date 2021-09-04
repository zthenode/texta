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
//   File: cDLibraryMainBase.hpp
//
// Author: $author$
//   Date: 10/16/2011
///////////////////////////////////////////////////////////////////////
#if !defined(_CDLIBRARYMAINBASE_HPP) || defined(CDLIBRARYMAINBASE_MEMBERS_ONLY)
#if !defined(_CDLIBRARYMAINBASE_HPP) && !defined(CDLIBRARYMAINBASE_MEMBERS_ONLY)
#define _CDLIBRARYMAINBASE_HPP
#endif // !defined(_CDLIBRARYMAINBASE_HPP) && !defined(CDLIBRARYMAINBASE_MEMBERS_ONLY) 

#if !defined(CDLIBRARYMAINBASE_MEMBERS_ONLY)
#include "cDLibraryMainInterface.hpp"
#include "cInstanceBase.hpp"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

///////////////////////////////////////////////////////////////////////
// Typedef: cDLibraryMainBaseExtend
//
//  Author: $author$
//    Date: 10/16/2011
///////////////////////////////////////////////////////////////////////
typedef cInstanceBase
cDLibraryMainBaseExtend;
///////////////////////////////////////////////////////////////////////
//  Class: cDLibraryMainBase
//
// Author: $author$
//   Date: 10/16/2011
///////////////////////////////////////////////////////////////////////
class c_INSTANCE_CLASS cDLibraryMainBase
: virtual public cDLibraryMainImplement,
  public cDLibraryMainBaseExtend
{
public:
    typedef cDLibraryMainImplement cImplements;
    typedef cDLibraryMainBaseExtend cExtends;
    ///////////////////////////////////////////////////////////////////////
    //  Constructor: cDLibraryMainBase
    //
    //       Author: $author$
    //         Date: 10/16/2011
    ///////////////////////////////////////////////////////////////////////
    cDLibraryMainBase()
    {
    }
    ///////////////////////////////////////////////////////////////////////
    //  Destructor: ~cDLibraryMainBase
    //
    //      Author: $author$
    //        Date: 10/16/2011
    ///////////////////////////////////////////////////////////////////////
    virtual ~cDLibraryMainBase()
    {
    }
#else // !defined(CDLIBRARYMAINBASE_MEMBERS_ONLY) 
#endif // !defined(CDLIBRARYMAINBASE_MEMBERS_ONLY) 

    ///////////////////////////////////////////////////////////////////////
    //  Function: Init
    //
    //    Author: $author$
    //      Date: 10/16/2011
    ///////////////////////////////////////////////////////////////////////
    virtual eError Init()
#if defined(CDLIBRARYMAINBASE_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CDLIBRARYMAINBASE_MEMBER_FUNCS_INTERFACE) 
    {
        eError error = e_ERROR_NONE;
#if !defined(CDLIBRARYMAINBASE_MEMBER_FUNCS_IMPLEMENT)
#else // !defined(CDLIBRARYMAINBASE_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CDLIBRARYMAINBASE_MEMBER_FUNCS_IMPLEMENT) 
        return error;
    }
#endif // defined(CDLIBRARYMAINBASE_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    //  Function: Finish
    //
    //    Author: $author$
    //      Date: 10/16/2011
    ///////////////////////////////////////////////////////////////////////
    virtual eError Finish()
#if defined(CDLIBRARYMAINBASE_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CDLIBRARYMAINBASE_MEMBER_FUNCS_INTERFACE) 
    {
        eError error = e_ERROR_NONE;
#if !defined(CDLIBRARYMAINBASE_MEMBER_FUNCS_IMPLEMENT)
#else // !defined(CDLIBRARYMAINBASE_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CDLIBRARYMAINBASE_MEMBER_FUNCS_IMPLEMENT) 
        return error;
    }
#endif // defined(CDLIBRARYMAINBASE_MEMBER_FUNCS_INTERFACE) 

#if !defined(CDLIBRARYMAINBASE_MEMBERS_ONLY)
};


#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#else // !defined(CDLIBRARYMAINBASE_MEMBERS_ONLY) 
#endif // !defined(CDLIBRARYMAINBASE_MEMBERS_ONLY) 

#endif // !defined(_CDLIBRARYMAINBASE_HPP) || defined(CDLIBRARYMAINBASE_MEMBERS_ONLY) 
        

