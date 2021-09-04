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
//   File: cHttpFormFields.cpp
//
// Author: $author$
//   Date: 7/22/2011
///////////////////////////////////////////////////////////////////////
#include "cHttpFormFields.hpp"
#include "cHttpFormField.hpp"
#include "cHttpFormFieldInterface.cpp"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

///////////////////////////////////////////////////////////////////////
//  Class: cHttpFormFields
//
// Author: $author$
//   Date: 7/22/2011
///////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////
//  Function: cHttpFormFields::Add
//
//    Author: $author$
//      Date: 7/22/2011
///////////////////////////////////////////////////////////////////////
eError cHttpFormFields::Add
(const cString& name,
 const cString& value,
 bool isFromQueryString)
{
    eError error = e_ERROR_FAILED;
    cHttpFormFieldInterface* formField;
    if ((formField = cHttpFormFieldInterface::NewInstance
        (error, name, value, isFromQueryString)))
    {
        m_formFields.AddItem(&formField->Item());
        error = e_ERROR_NONE;
    }
    return error;
}

#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

        

