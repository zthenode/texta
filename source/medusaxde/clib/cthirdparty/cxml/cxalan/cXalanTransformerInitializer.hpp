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
//   File: cXalanTransformerInitializer.hpp
//
// Author: $author$
//   Date: 7/17/2011
///////////////////////////////////////////////////////////////////////
#if !defined(_CXALANTRANSFORMERINITIALIZER_HPP) || defined(CXALANTRANSFORMERINITIALIZER_MEMBERS_ONLY)
#if !defined(_CXALANTRANSFORMERINITIALIZER_HPP) && !defined(CXALANTRANSFORMERINITIALIZER_MEMBERS_ONLY)
#define _CXALANTRANSFORMERINITIALIZER_HPP
#endif // !defined(_CXALANTRANSFORMERINITIALIZER_HPP) && !defined(CXALANTRANSFORMERINITIALIZER_MEMBERS_ONLY) 

#if !defined(CXALANTRANSFORMERINITIALIZER_MEMBERS_ONLY)
#include "cXalanTransformerInitializerInterface.hpp"
#include "cInstanceBase.hpp"

#include <PlatformSupport/XSLException.hpp>
#include <XalanTransformer/XalanTransformer.hpp>

#include "cXercesInitializer.hpp"
#include "nsXalan.hpp"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

///////////////////////////////////////////////////////////////////////
// Typedef: cXalanTransformerInitializerExtend
//
//  Author: $author$
//    Date: 7/17/2011
///////////////////////////////////////////////////////////////////////
typedef cInstanceBase
cXalanTransformerInitializerExtend;
///////////////////////////////////////////////////////////////////////
//  Class: cXalanTransformerInitializer
//
// Author: $author$
//   Date: 7/17/2011
///////////////////////////////////////////////////////////////////////
class c_INSTANCE_CLASS cXalanTransformerInitializer
: virtual public cXalanTransformerInitializerImplement,
  public cXalanTransformerInitializerExtend
{
public:
    typedef cXalanTransformerInitializerImplement cImplements;
    typedef cXalanTransformerInitializerExtend cExtends;

#if defined(NO_STATIC_MEMBER_EXPORT)
    unsigned int& m_instanceCount;
    cXalanTransformerInitializer*& m_instance;
#else // defined(NO_STATIC_MEMBER_EXPORT)
    static unsigned int m_instanceCount;
    static cXalanTransformerInitializer* m_instance;
#endif // defined(NO_STATIC_MEMBER_EXPORT)
    cXalanTransformerInitializer* m_oldInstance;

    cXercesInitializer m_xercesInitializer;

    ///////////////////////////////////////////////////////////////////////
    //  Constructor: cXalanTransformerInitializer
    //
    //       Author: $author$
    //         Date: 7/17/2011
    ///////////////////////////////////////////////////////////////////////
    cXalanTransformerInitializer():
#if defined(NO_STATIC_MEMBER_EXPORT)
      m_instanceCount(InstanceCount()),
      m_instance(Instance()),
#else // defined(NO_STATIC_MEMBER_EXPORT)
#endif // defined(NO_STATIC_MEMBER_EXPORT)
      m_oldInstance(m_instance)
    {
        eError error = e_ERROR_FAILED;

        if ((++(m_instanceCount))<2)
        try
        {
            nsXalan::XalanTransformer::initialize();
        }
        catch (const nsXalan::XSLException&)
        {
            --(m_instanceCount);
            throw (error);
        }

        if (!(m_instance))
            (m_instance) = this;
    }
    ///////////////////////////////////////////////////////////////////////
    //  Destructor: ~cXalanTransformerInitializer
    //
    //      Author: $author$
    //        Date: 7/17/2011
    ///////////////////////////////////////////////////////////////////////
    virtual ~cXalanTransformerInitializer()
    {
        eError error = e_ERROR_FAILED;

        if (this == (m_instance))
            (m_instance) = m_oldInstance;

        if ((m_instanceCount)<1)
            throw (error);

        if ((--(m_instanceCount))<1)
        try
        {
            nsXalan::XalanTransformer::terminate();
        }
        catch (const nsXalan::XSLException&)
        {
            throw (error);
        }
    }
#else // !defined(CXALANTRANSFORMERINITIALIZER_MEMBERS_ONLY) 
#endif // !defined(CXALANTRANSFORMERINITIALIZER_MEMBERS_ONLY) 

    ///////////////////////////////////////////////////////////////////////
    //  Function: XalanTransformerInitializer
    //
    //    Author: $author$
    //      Date: 7/17/2011
    ///////////////////////////////////////////////////////////////////////
    virtual cXalanTransformerInitializer* XalanTransformerInitializer() const
#if defined(CXALANTRANSFORMERINITIALIZER_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CXALANTRANSFORMERINITIALIZER_MEMBER_FUNCS_INTERFACE) 
    {
        cXalanTransformerInitializer* instance = 0;
#if !defined(CXALANTRANSFORMERINITIALIZER_MEMBER_FUNCS_IMPLEMENT)
        instance = (cXalanTransformerInitializer*)(this);
#else // !defined(CXALANTRANSFORMERINITIALIZER_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CXALANTRANSFORMERINITIALIZER_MEMBER_FUNCS_IMPLEMENT) 
        return instance;
    }
#endif // defined(CXALANTRANSFORMERINITIALIZER_MEMBER_FUNCS_INTERFACE) 

#if defined(CXALANTRANSFORMERINITIALIZER_MEMBER_FUNCS_INTERFACE)
    ///////////////////////////////////////////////////////////////////////
    //  Function: GetInstance
    //
    //    Author: $author$
    //      Date: 7/17/2011
    ///////////////////////////////////////////////////////////////////////
    static cXalanTransformerInitializerInterface* GetInstance
    (eError& error);
#else // defined(CXALANTRANSFORMERINITIALIZER_MEMBER_FUNCS_INTERFACE) 
#endif // defined(CXALANTRANSFORMERINITIALIZER_MEMBER_FUNCS_INTERFACE) 
#if defined(CXALANTRANSFORMERINITIALIZER_MEMBER_FUNCS_INTERFACE)
    ///////////////////////////////////////////////////////////////////////
    //  Function: FreeInstance
    //
    //    Author: $author$
    //      Date: 7/17/2011
    ///////////////////////////////////////////////////////////////////////
    static eError FreeInstance
    (cXalanTransformerInitializerInterface* instance);
#else // defined(CXALANTRANSFORMERINITIALIZER_MEMBER_FUNCS_INTERFACE) 
#endif // defined(CXALANTRANSFORMERINITIALIZER_MEMBER_FUNCS_INTERFACE) 

#if !defined(CXALANTRANSFORMERINITIALIZER_MEMBERS_ONLY)
#if defined(NO_STATIC_MEMBER_EXPORT)
    ///////////////////////////////////////////////////////////////////////
    //  Function: Instance
    //
    //    Author: $author$
    //      Date: 7/18/2011
    ///////////////////////////////////////////////////////////////////////
    static cXalanTransformerInitializer*& Instance()
    {
        static cXalanTransformerInitializer* instance = 0;
        return instance;
    }
    ///////////////////////////////////////////////////////////////////////
    //  Function: InstanceCount
    //
    //    Author: $author$
    //      Date: 7/18/2011
    ///////////////////////////////////////////////////////////////////////
    static unsigned int& InstanceCount()
    {
        static unsigned int instanceCount = 0;
        return instanceCount;
    }
#else // defined(NO_STATIC_MEMBER_EXPORT)
#endif // defined(NO_STATIC_MEMBER_EXPORT)
};


#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#else // !defined(CXALANTRANSFORMERINITIALIZER_MEMBERS_ONLY) 
#endif // !defined(CXALANTRANSFORMERINITIALIZER_MEMBERS_ONLY) 

#endif // !defined(_CXALANTRANSFORMERINITIALIZER_HPP) || defined(CXALANTRANSFORMERINITIALIZER_MEMBERS_ONLY) 
