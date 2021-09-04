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
//   File: cCgiccMainCgiEnv.hpp
//
// Author: $author$
//   Date: 7/23/2011
///////////////////////////////////////////////////////////////////////
#if !defined(_CCGICCMAINCGIENV_HPP) || defined(CCGICCMAINCGIENV_MEMBERS_ONLY)
#if !defined(_CCGICCMAINCGIENV_HPP) && !defined(CCGICCMAINCGIENV_MEMBERS_ONLY)
#define _CCGICCMAINCGIENV_HPP
#endif // !defined(_CCGICCMAINCGIENV_HPP) && !defined(CCGICCMAINCGIENV_MEMBERS_ONLY) 

#if !defined(CCGICCMAINCGIENV_MEMBERS_ONLY)
#include "cCgiEnv.hpp"
#include "cCgiccMainInterface.hpp"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

///////////////////////////////////////////////////////////////////////
// Typedef: cCgiccMainCgiEnvImplement
//
//  Author: $author$
//    Date: 11/6/2011
///////////////////////////////////////////////////////////////////////
typedef cCgiEnvImplement
cCgiccMainCgiEnvImplement;
///////////////////////////////////////////////////////////////////////
// Typedef: cCgiccMainCgiEnvExtend
//
//  Author: $author$
//    Date: 7/23/2011
///////////////////////////////////////////////////////////////////////
typedef cCgiEnv
cCgiccMainCgiEnvExtend;
///////////////////////////////////////////////////////////////////////
//  Class: cCgiccMainCgiEnv
//
// Author: $author$
//   Date: 7/23/2011
///////////////////////////////////////////////////////////////////////
class c_INSTANCE_CLASS cCgiccMainCgiEnv
: virtual public cCgiccMainCgiEnvImplement,
  public cCgiccMainCgiEnvExtend
{
public:
    typedef cCgiccMainCgiEnvImplement cImplements;
    typedef cCgiccMainCgiEnvExtend cExtends;

    cCgiccMainInterface& m_ccgiccMain;

    ///////////////////////////////////////////////////////////////////////
    //  Constructor: cCgiccMainCgiEnv
    //
    //       Author: $author$
    //         Date: 7/23/2011
    ///////////////////////////////////////////////////////////////////////
    cCgiccMainCgiEnv
    (cCgiccMainInterface& ccgiccMain)
    : m_ccgiccMain(ccgiccMain)
    {
    }
    ///////////////////////////////////////////////////////////////////////
    //  Destructor: ~cCgiccMainCgiEnv
    //
    //      Author: $author$
    //        Date: 7/23/2011
    ///////////////////////////////////////////////////////////////////////
    virtual ~cCgiccMainCgiEnv()
    {
    }
#else // !defined(CCGICCMAINCGIENV_MEMBERS_ONLY) 
#endif // !defined(CCGICCMAINCGIENV_MEMBERS_ONLY) 

#if !defined(CCGICCMAINCGIENV_MEMBERS_ONLY)
};


#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#else // !defined(CCGICCMAINCGIENV_MEMBERS_ONLY) 
#endif // !defined(CCGICCMAINCGIENV_MEMBERS_ONLY) 

#endif // !defined(_CCGICCMAINCGIENV_HPP) || defined(CCGICCMAINCGIENV_MEMBERS_ONLY) 
        

