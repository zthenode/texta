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
//   File: cXalanTransformerInitializer.cpp
//
// Author: $author$
//   Date: 7/17/2011
///////////////////////////////////////////////////////////////////////
#include "cXalanTransformerInitializer.hpp"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

///////////////////////////////////////////////////////////////////////
//  Class: cXalanTransformerInitializerInterface
//
// Author: $author$
//   Date: 7/17/2011
///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
//  Function: cXalanTransformerInitializerInterface::GetInstance
//
//    Author: $author$
//      Date: 7/17/2011
///////////////////////////////////////////////////////////////////////
cXalanTransformerInitializerInterface* 
cXalanTransformerInitializerInterface::GetInstance
(eError& error)
{
    cXalanTransformerInitializerInterface* instance = 0;
    error = e_ERROR_FAILED;
    try
    {
        if ((instance = new cXalanTransformerInitializer()))
            error = e_ERROR_NONE;
    }
    catch (eError e)
    {
        error = e;
    }
    return instance;
}
///////////////////////////////////////////////////////////////////////
//  Function: cXalanTransformerInitializerInterface::FreeInstance
//
//    Author: $author$
//      Date: 7/17/2011
///////////////////////////////////////////////////////////////////////
eError cXalanTransformerInitializerInterface::FreeInstance
(cXalanTransformerInitializerInterface* instance)
{
    eError error = e_ERROR_FAILED;
    cXalanTransformerInitializer* xalanTransformerInitializer;
    if ((xalanTransformerInitializer = instance->XalanTransformerInitializer()))
    try
    {
        delete xalanTransformerInitializer;
        error = e_ERROR_NONE;
    }
    catch (eError e)
    {
        error = e;
    }
    return error;
}

///////////////////////////////////////////////////////////////////////
//  Class: cXalanTransformerInitializer
//
// Author: $author$
//   Date: 7/17/2011
///////////////////////////////////////////////////////////////////////
#if defined(NO_STATIC_MEMBER_EXPORT)
#else // defined(NO_STATIC_MEMBER_EXPORT)
unsigned int cXalanTransformerInitializer::m_instanceCount = 0;
cXalanTransformerInitializer* cXalanTransformerInitializer::m_instance = 0;
#endif // defined(NO_STATIC_MEMBER_EXPORT)

#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

        

