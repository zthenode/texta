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
//   File: cUnixFileStat.hpp
//
// Author: $author$
//   Date: 8/24/2011
///////////////////////////////////////////////////////////////////////
#if !defined(_CUNIXFILESTAT_HPP) || defined(CUNIXFILESTAT_MEMBERS_ONLY)
#if !defined(_CUNIXFILESTAT_HPP) && !defined(CUNIXFILESTAT_MEMBERS_ONLY)
#define _CUNIXFILESTAT_HPP
#endif // !defined(_CUNIXFILESTAT_HPP) && !defined(CUNIXFILESTAT_MEMBERS_ONLY) 

#if !defined(CUNIXFILESTAT_MEMBERS_ONLY)
#include "cUnixFileStatInterface.hpp"
#include "cFileStatBase.hpp"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

///////////////////////////////////////////////////////////////////////
// Typedef: cUnixFileStatExtend
//
//  Author: $author$
//    Date: 8/24/2011
///////////////////////////////////////////////////////////////////////
typedef cFileStatBase
cUnixFileStatExtend;
///////////////////////////////////////////////////////////////////////
//  Class: cUnixFileStat
//
// Author: $author$
//   Date: 8/24/2011
///////////////////////////////////////////////////////////////////////
class c_INSTANCE_CLASS cUnixFileStat
: virtual public cUnixFileStatImplement,
  public cUnixFileStatExtend
{
public:
    typedef cUnixFileStatImplement cImplements;
    typedef cUnixFileStatExtend cExtends;
    ///////////////////////////////////////////////////////////////////////
    //  Constructor: cUnixFileStat
    //
    //       Author: $author$
    //         Date: 8/24/2011
    ///////////////////////////////////////////////////////////////////////
    cUnixFileStat()
    {
    }
    ///////////////////////////////////////////////////////////////////////
    //  Destructor: ~cUnixFileStat
    //
    //      Author: $author$
    //        Date: 8/24/2011
    ///////////////////////////////////////////////////////////////////////
    virtual ~cUnixFileStat()
    {
    }
#else // !defined(CUNIXFILESTAT_MEMBERS_ONLY) 
#endif // !defined(CUNIXFILESTAT_MEMBERS_ONLY) 

#if !defined(CUNIXFILESTAT_MEMBERS_ONLY)
};

#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#else // !defined(CUNIXFILESTAT_MEMBERS_ONLY) 
#endif // !defined(CUNIXFILESTAT_MEMBERS_ONLY) 

#endif // !defined(_CUNIXFILESTAT_HPP) || defined(CUNIXFILESTAT_MEMBERS_ONLY) 
        

