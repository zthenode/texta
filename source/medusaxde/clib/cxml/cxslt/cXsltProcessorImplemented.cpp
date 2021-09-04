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
//   File: cXsltProcessorImplemented.cpp
//
// Author: $author$
//   Date: 7/24/2011
///////////////////////////////////////////////////////////////////////
#include "cXsltProcessorImplemented.hpp"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

///////////////////////////////////////////////////////////////////////
//  Class: cXsltProcessorImplemented
//
// Author: $author$
//   Date: 7/24/2011
///////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////
//  Class: cXsltProcessorInterface
//
// Author: $author$
//   Date: 7/1/2011
///////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////
//  Function: cXsltProcessorInterface::GetInstance
//
//    Author: $author$
//      Date: 7/1/2011
///////////////////////////////////////////////////////////////////////
cXsltProcessorInterface* 
cXsltProcessorInterface::GetInstance(eError& error)
{
    cXsltProcessorImplemented* instance = 0;
    if ((instance = new cXsltProcessorImplemented())) {
        error = e_ERROR_NONE;
    } else {
        error = e_ERROR_NEW;
    }
    return instance;
}
///////////////////////////////////////////////////////////////////////
//  Function: cXsltProcessorInterface::FreeInstance
//
//    Author: $author$
//      Date: 7/1/2011
///////////////////////////////////////////////////////////////////////
eError cXsltProcessorInterface::FreeInstance
(cXsltProcessorInterface* instance)
{
    eError error = e_ERROR_FAILED;
    if ((instance))
    {
        cXsltProcessorImplemented* implemented = 0;
        if ((implemented = instance->Implemented())) {
            delete implemented;
            error = e_ERROR_NONE;
        }
    }
    return error;
}

#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 
