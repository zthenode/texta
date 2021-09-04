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
//   File: cHttpFormFieldInterface.cpp
//
// Author: $author$
//   Date: 6/5/2011
///////////////////////////////////////////////////////////////////////
#include "cHttpFormFieldInterface.hpp"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

///////////////////////////////////////////////////////////////////////
//  Class: cHttpFormFieldInterfaceT
//
// Author: $author$
//   Date: 6/5/2011
///////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////
//  Function: NewInstance
//
//    Author: $author$
//      Date: 7/22/2011
///////////////////////////////////////////////////////////////////////
template
<class TInterface,
 class TItem,
 class THttpFormField,
 class TString,
 class TChar,
 class TImplement>
TInterface* cHttpFormFieldInterfaceT
<TInterface,
 TItem,
 THttpFormField,
 TString,
 TChar,
 TImplement>
::NewInstance
(eError& error,
 const cString& name,
 const cString& value,
 bool isFromQueryString)
{
    tHttpFormField*  formField = 0;
    error = e_ERROR_FAILED;
    if ((formField = new tHttpFormField
        (name, value, isFromQueryString)))
        error = e_ERROR_NONE;
    return (TInterface*)(formField);
}
///////////////////////////////////////////////////////////////////////
//  Function: DeleteInstance
//
//    Author: $author$
//      Date: 7/22/2011
///////////////////////////////////////////////////////////////////////
template
<class TInterface,
 class TItem,
 class THttpFormField,
 class TString,
 class TChar,
 class TImplement>
eError cHttpFormFieldInterfaceT
<TInterface,
 TItem,
 THttpFormField,
 TString,
 TChar,
 TImplement>
::DeleteInstance
(tHttpFormFieldInterface* formField)
{
    eError error = e_ERROR_FAILED;
    if ((formField))
    {
        tHttpFormField* implemented = &formField->Implememted();
        delete implemented;
        error = e_ERROR_NONE;
    }
    return error;
}

#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

        

