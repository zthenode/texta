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
//   File: cXsltParam.cpp
//
// Author: $author$
//   Date: 7/25/2011
///////////////////////////////////////////////////////////////////////
#include "cXsltParam.hpp"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

///////////////////////////////////////////////////////////////////////
//  Class: cXsltParamInterface
//
// Author: $author$
//   Date: 7/25/2011
///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
//  Function: cXsltParamInterface::NewInstance
//
//    Author: $author$
//      Date: 7/25/2011
///////////////////////////////////////////////////////////////////////
cXsltParamInterface* cXsltParamInterface::NewInstance
(eError& error,
 const cString& name,
 const cString& expression,
 bool isLiteral)
{
    cXsltParam* instance = 0;
    error = e_ERROR_FAILED;
    if ((instance = new cXsltParam(name, expression, isLiteral)))
        error = e_ERROR_NONE;
    return instance;
}
///////////////////////////////////////////////////////////////////////
//  Function: cXsltParamInterface::DeleteInstance
//
//    Author: $author$
//      Date: 7/25/2011
///////////////////////////////////////////////////////////////////////
eError cXsltParamInterface::DeleteInstance
(cXsltParamInterface* instance)
{
    eError error = e_ERROR_FAILED;
    if ((instance))
    {
        delete (&instance->XsltParam());
        error = e_ERROR_NONE;
    }
    return error;
}

///////////////////////////////////////////////////////////////////////
//  Class: cXsltParam
//
// Author: $author$
//   Date: 7/25/2011
///////////////////////////////////////////////////////////////////////


#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

        

