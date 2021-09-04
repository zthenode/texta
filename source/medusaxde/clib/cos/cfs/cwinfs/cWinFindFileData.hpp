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
//   File: cWinFindFileData.hpp
//
// Author: $author$
//   Date: 8/1/2011
///////////////////////////////////////////////////////////////////////
#if !defined(_CWINFINDFILEDATA_HPP) || defined(CWINFINDFILEDATA_MEMBERS_ONLY)
#if !defined(_CWINFINDFILEDATA_HPP) && !defined(CWINFINDFILEDATA_MEMBERS_ONLY)
#define _CWINFINDFILEDATA_HPP
#endif // !defined(_CWINFINDFILEDATA_HPP) && !defined(CWINFINDFILEDATA_MEMBERS_ONLY) 

#if !defined(CWINFINDFILEDATA_MEMBERS_ONLY)
#include "cInstanceBase.hpp"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

///////////////////////////////////////////////////////////////////////
// Typedef: cWinFindFileDataExtend
//
//  Author: $author$
//    Date: 8/1/2011
///////////////////////////////////////////////////////////////////////
typedef cInstanceBase
cWinFindFileDataExtend;
///////////////////////////////////////////////////////////////////////
//  Class: cWinFindFileData
//
// Author: $author$
//   Date: 8/1/2011
///////////////////////////////////////////////////////////////////////
class c_INSTANCE_CLASS cWinFindFileData
: //virtual public cWinFindFileDataImplement,
  public cWinFindFileDataExtend
{
public:
    //typedef cWinFindFileDataImplement cImplements;
    typedef cWinFindFileDataExtend cExtends;

    WIN32_FIND_DATA m_findFileData;

    ///////////////////////////////////////////////////////////////////////
    //  Constructor: cWinFindFileData
    //
    //       Author: $author$
    //         Date: 8/1/2011
    ///////////////////////////////////////////////////////////////////////
    cWinFindFileData()
    {
    }
    ///////////////////////////////////////////////////////////////////////
    //  Destructor: ~cWinFindFileData
    //
    //      Author: $author$
    //        Date: 8/1/2011
    ///////////////////////////////////////////////////////////////////////
    virtual ~cWinFindFileData()
    {
    }
#else // !defined(CWINFINDFILEDATA_MEMBERS_ONLY) 
#endif // !defined(CWINFINDFILEDATA_MEMBERS_ONLY) 

#if !defined(CWINFINDFILEDATA_MEMBERS_ONLY)
    inline operator WIN32_FIND_DATA& () const
    { return (WIN32_FIND_DATA&)(m_findFileData); }
};


#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#else // !defined(CWINFINDFILEDATA_MEMBERS_ONLY) 
#endif // !defined(CWINFINDFILEDATA_MEMBERS_ONLY) 

#endif // !defined(_CWINFINDFILEDATA_HPP) || defined(CWINFINDFILEDATA_MEMBERS_ONLY) 
        

