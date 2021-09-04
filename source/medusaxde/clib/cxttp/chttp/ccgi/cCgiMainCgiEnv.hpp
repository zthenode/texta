///////////////////////////////////////////////////////////////////////
// Copyright (c) 1988-2012 $organization$
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
//   File: cCgiMainCgiEnv.hpp
//
// Author: $author$
//   Date: 11/23/2012
///////////////////////////////////////////////////////////////////////
#ifndef _CCGIMAINCGIENV_HPP
#define _CCGIMAINCGIENV_HPP

#include "cCgiMain.hpp"
#include "cCgiEnv.hpp"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

///////////////////////////////////////////////////////////////////////
// Typedef: cCgiMainCgiEnvImplement
//
//  Author: $author$
//    Date: 11/23/2012
///////////////////////////////////////////////////////////////////////
typedef cCgiEnvImplement
cCgiMainCgiEnvImplement;
///////////////////////////////////////////////////////////////////////
// Typedef: cCgiMainCgiEnvExtend
//
//  Author: $author$
//    Date: 11/23/2012
///////////////////////////////////////////////////////////////////////
typedef cCgiEnv
cCgiMainCgiEnvExtend;
///////////////////////////////////////////////////////////////////////
//  Class: cCgiMainCgiEnv
//
// Author: $author$
//   Date: 11/23/2012
///////////////////////////////////////////////////////////////////////
class c_EXPORT_CLASS cCgiMainCgiEnv
: virtual public cCgiMainCgiEnvImplement,
  public cCgiMainCgiEnvExtend
{
public:
    typedef cCgiMainCgiEnvImplement cImplements;
    typedef cCgiMainCgiEnvExtend cExtends;

    cCgiMain& m_cgiMain;

    ///////////////////////////////////////////////////////////////////////
    //  Constructor: cCgiMainCgiEnv
    //
    //       Author: $author$
    //         Date: 11/23/2012
    ///////////////////////////////////////////////////////////////////////
    cCgiMainCgiEnv
    (cCgiMain& cgiMain)
    : m_cgiMain(cgiMain)
    {
    }
    ///////////////////////////////////////////////////////////////////////
    //  Destructor: ~cCgiMainCgiEnv
    //
    //      Author: $author$
    //        Date: 11/23/2012
    ///////////////////////////////////////////////////////////////////////
    virtual ~cCgiMainCgiEnv()
    {
    }

    ///////////////////////////////////////////////////////////////////////
    //  Function: SetEnv
    //
    //    Author: $author$
    //      Date: 11/23/2012
    ///////////////////////////////////////////////////////////////////////
    virtual const char* SetEnv
    (eCgiEnv e, const char* toChars, 
     ssize_t length=-1, bool overwrite=true)
    {
        const char* chars = m_cgiMain.SetCgiEnvValue(e, toChars, length, overwrite);
        return chars;
    }
    ///////////////////////////////////////////////////////////////////////
    //  Function: GetEnv
    //
    //    Author: $author$
    //      Date: 11/23/2012
    ///////////////////////////////////////////////////////////////////////
    virtual const char* GetEnv(eCgiEnv e) const
    {
        const char* chars = m_cgiMain.GetCgiEnvValue(e);
        return chars;
    }
    ///////////////////////////////////////////////////////////////////////
    //  Function: GetEnvName
    //
    //    Author: $author$
    //      Date: 11/23/2012
    ///////////////////////////////////////////////////////////////////////
    virtual const char* GetEnvName(eCgiEnv e) const
    {
        const char* chars = m_cgiMain.GetCgiEnvName(e);
        return chars;
    }
};


#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#endif // _CCGIMAINCGIENV_HPP 
        

