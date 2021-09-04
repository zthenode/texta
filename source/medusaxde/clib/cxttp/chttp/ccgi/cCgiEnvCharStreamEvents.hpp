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
//   File: cCgiEnvCharStreamEvents.hpp
//
// Author: $author$
//   Date: 11/24/2012
///////////////////////////////////////////////////////////////////////
#ifndef _CCGIENVCHARSTREAMEVENTS_HPP
#define _CCGIENVCHARSTREAMEVENTS_HPP

#include "cString.hpp"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

///////////////////////////////////////////////////////////////////////
//  Class: cCgiEnvCharStreamEvents
//
// Author: $author$
//   Date: 11/24/2012
///////////////////////////////////////////////////////////////////////
class c_EXPORT_CLASS cCgiEnvCharStreamEvents
{
public:
    ///////////////////////////////////////////////////////////////////////
    //  Function: OnReadCgiEnvInit
    //
    //    Author: $author$
    //      Date: 11/24/2012
    ///////////////////////////////////////////////////////////////////////
    virtual eError OnReadCgiEnvInit()
    {
        eError error = e_ERROR_NONE;
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    //  Function: OnReadCgiEnvFinal
    //
    //    Author: $author$
    //      Date: 11/24/2012
    ///////////////////////////////////////////////////////////////////////
    virtual eError OnReadCgiEnvFinal()
    {
        eError error = e_ERROR_NONE;
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    //  Function: OnReadCgiEnv
    //
    //    Author: $author$
    //      Date: 11/24/2012
    ///////////////////////////////////////////////////////////////////////
    virtual eError OnReadCgiEnv
    (const cString& name, const cString& value)
    {
        eError error = e_ERROR_NONE;
        return error;
    }
};

#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#endif // _CCGIENVCHARSTREAMEVENTS_HPP 
