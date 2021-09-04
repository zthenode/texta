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
//   File: cXercesInitializer.cpp
//
// Author: $author$
//   Date: 7/17/2011
///////////////////////////////////////////////////////////////////////
#include "cXercesInitializer.hpp"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

///////////////////////////////////////////////////////////////////////
//  Class: cXercesInitializerInterface
//
// Author: $author$
//   Date: 7/17/2011
///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
//  Function: cXercesInitializerInterface::GetInstance
//
//    Author: $author$
//      Date: 7/17/2011
///////////////////////////////////////////////////////////////////////
cXercesInitializerInterface* cXercesInitializerInterface::GetInstance
(eError& error)
{
    cXercesInitializerInterface* instance = 0;
    error = e_ERROR_FAILED; 
    try
    {
        if ((instance = new cXercesInitializer()))
            error = e_ERROR_NONE;
    }
    catch (eError e)
    {
        error = e;
    }
    return instance;
}
///////////////////////////////////////////////////////////////////////
//  Function: cXercesInitializerInterface::FreeInstance
//
//    Author: $author$
//      Date: 7/17/2011
///////////////////////////////////////////////////////////////////////
eError cXercesInitializerInterface::FreeInstance
(cXercesInitializerInterface* instance)
{
    eError error = e_ERROR_FAILED;
    cXercesInitializer* xercesInitializer;
    if ((instance))
    if ((xercesInitializer = instance->XercesInitializer()))
    try
    {
        delete xercesInitializer;
        error = e_ERROR_NONE;
    }
    catch (eError e)
    {
        error = e;
    }
    return error;
}

///////////////////////////////////////////////////////////////////////
//  Class: cXercesInitializer
//
// Author: $author$
//   Date: 7/17/2011
///////////////////////////////////////////////////////////////////////
#if defined(NO_STATIC_MEMBER_EXPORT)
#else // defined(NO_STATIC_MEMBER_EXPORT)
unsigned int cXercesInitializer::m_instanceCount = 0;
cXercesInitializer* cXercesInitializer::m_instance = 0;
#endif // defined(NO_STATIC_MEMBER_EXPORT)

#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 
