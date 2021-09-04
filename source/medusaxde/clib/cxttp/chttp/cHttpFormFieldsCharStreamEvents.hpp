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
//   File: cHttpFormFieldsCharStreamEvents.hpp
//
// Author: $author$
//   Date: 11/24/2012
///////////////////////////////////////////////////////////////////////
#ifndef _CHTTPFORMFIELDSCHARSTREAMEVENTS_HPP
#define _CHTTPFORMFIELDSCHARSTREAMEVENTS_HPP

#include "cString.hpp"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

///////////////////////////////////////////////////////////////////////
//  Class: cHttpFormFieldsCharStreamEvents
//
// Author: $author$
//   Date: 11/24/2012
///////////////////////////////////////////////////////////////////////
class c_EXPORT_CLASS cHttpFormFieldsCharStreamEvents
{
public:
    ///////////////////////////////////////////////////////////////////////
    //  Function: OnReadFormFieldsInit
    //
    //    Author: $author$
    //      Date: 11/24/2012
    ///////////////////////////////////////////////////////////////////////
    virtual eError OnReadFormFieldsInit(bool isFromQueryString=false)
    {
        eError error = e_ERROR_NONE;
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    //  Function: OnReadFormFieldsFinal
    //
    //    Author: $author$
    //      Date: 11/24/2012
    ///////////////////////////////////////////////////////////////////////
    virtual eError OnReadFormFieldsFinal(bool isFromQueryString=false)
    {
        eError error = e_ERROR_NONE;
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    //  Function: OnReadFormField
    //
    //    Author: $author$
    //      Date: 11/24/2012
    ///////////////////////////////////////////////////////////////////////
    virtual eError OnReadFormField
    (const cString& name, const cString& value, bool isFromQueryString=false)
    {
        eError error = e_ERROR_NONE;
        return error;
    }
};

#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#endif // _CHTTPFORMFIELDSCHARSTREAMEVENTS_HPP 
        

