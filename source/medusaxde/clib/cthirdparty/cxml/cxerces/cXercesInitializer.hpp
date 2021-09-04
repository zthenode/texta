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
//   File: cXercesInitializer.hpp
//
// Author: $author$
//   Date: 7/17/2011
///////////////////////////////////////////////////////////////////////
#if !defined(_CXERCESINITIALIZER_HPP) || defined(CXERCESINITIALIZER_MEMBERS_ONLY)
#if !defined(_CXERCESINITIALIZER_HPP) && !defined(CXERCESINITIALIZER_MEMBERS_ONLY)
#define _CXERCESINITIALIZER_HPP
#endif // !defined(_CXERCESINITIALIZER_HPP) && !defined(CXERCESINITIALIZER_MEMBERS_ONLY) 

#if !defined(CXERCESINITIALIZER_MEMBERS_ONLY)
#include "cXercesInitializerInterface.hpp"
#include "cInstanceBase.hpp"

#include <util/PlatformUtils.hpp>
#include "nsXerces.hpp"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

///////////////////////////////////////////////////////////////////////
// Typedef: cXercesInitializerExtend
//
//  Author: $author$
//    Date: 7/17/2011
///////////////////////////////////////////////////////////////////////
typedef cInstanceBase
cXercesInitializerExtend;
///////////////////////////////////////////////////////////////////////
//  Class: cXercesInitializer
//
// Author: $author$
//   Date: 7/17/2011
///////////////////////////////////////////////////////////////////////
class c_INSTANCE_CLASS cXercesInitializer
: virtual public cXercesInitializerImplement,
  public cXercesInitializerExtend
{
public:
    typedef cXercesInitializerImplement cImplements;
    typedef cXercesInitializerExtend cExtends;

#if defined(NO_STATIC_MEMBER_EXPORT)
    unsigned int& m_instanceCount;
    cXercesInitializer*& m_instance;
#else // defined(NO_STATIC_MEMBER_EXPORT)
    static unsigned int m_instanceCount;
    static cXercesInitializer* m_instance;
#endif // defined(NO_STATIC_MEMBER_EXPORT)
    cXercesInitializer* m_oldInstance;

    ///////////////////////////////////////////////////////////////////////
    //  Constructor: cXercesInitializer
    //
    //       Author: $author$
    //         Date: 7/17/2011
    ///////////////////////////////////////////////////////////////////////
    cXercesInitializer():
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
            nsXerces::XMLPlatformUtils::Initialize();
        }
        catch (const nsXerces::XMLException&)
        {
            --(m_instanceCount);
            throw (error);
        }

        if (!(m_instance))
            m_instance = this;
    }
    ///////////////////////////////////////////////////////////////////////
    //  Destructor: ~cXercesInitializer
    //
    //      Author: $author$
    //        Date: 7/17/2011
    ///////////////////////////////////////////////////////////////////////
    virtual ~cXercesInitializer()
    {
        eError error = e_ERROR_FAILED;

        if (this == (m_instance))
            (m_instance) = m_oldInstance;

        if ((m_instanceCount)<1)
            throw (error);

        if ((--(m_instanceCount))<1)
        try
        {
            nsXerces::XMLPlatformUtils::Terminate();
        }
        catch(const nsXerces::XMLException&)
        {
            throw (error);
        }
    }
#else // !defined(CXERCESINITIALIZER_MEMBERS_ONLY) 
#endif // !defined(CXERCESINITIALIZER_MEMBERS_ONLY) 

    ///////////////////////////////////////////////////////////////////////
    //  Function: XercesInitializer
    //
    //    Author: $author$
    //      Date: 7/17/2011
    ///////////////////////////////////////////////////////////////////////
    virtual cXercesInitializer* XercesInitializer() const
#if defined(CXERCESINITIALIZER_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CXERCESINITIALIZER_MEMBER_FUNCS_INTERFACE) 
    {
        cXercesInitializer* instance = 0;
#if !defined(CXERCESINITIALIZER_MEMBER_FUNCS_IMPLEMENT)
        instance = (cXercesInitializer*)(this);
#else // !defined(CXERCESINITIALIZER_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CXERCESINITIALIZER_MEMBER_FUNCS_IMPLEMENT) 
        return instance;
    }
#endif // defined(CXERCESINITIALIZER_MEMBER_FUNCS_INTERFACE) 

#if defined(CXERCESINITIALIZER_MEMBER_FUNCS_INTERFACE)
    ///////////////////////////////////////////////////////////////////////
    //  Function: GetInstance
    //
    //    Author: $author$
    //      Date: 7/17/2011
    ///////////////////////////////////////////////////////////////////////
    static cXercesInitializerInterface* GetInstance
    (eError& error);
#else // defined(CXERCESINITIALIZER_MEMBER_FUNCS_INTERFACE) 
#endif // defined(CXERCESINITIALIZER_MEMBER_FUNCS_INTERFACE) 

#if defined(CXERCESINITIALIZER_MEMBER_FUNCS_INTERFACE)
    ///////////////////////////////////////////////////////////////////////
    //  Function: FreeInstance
    //
    //    Author: $author$
    //      Date: 7/17/2011
    ///////////////////////////////////////////////////////////////////////
    static eError FreeInstance
    (cXercesInitializerInterface* instance);
#else // defined(CXERCESINITIALIZER_MEMBER_FUNCS_INTERFACE) 
#endif // defined(CXERCESINITIALIZER_MEMBER_FUNCS_INTERFACE) 

#if !defined(CXERCESINITIALIZER_MEMBERS_ONLY)
#if defined(NO_STATIC_MEMBER_EXPORT)
    ///////////////////////////////////////////////////////////////////////
    //  Function: Instance
    //
    //    Author: $author$
    //      Date: 7/18/2011
    ///////////////////////////////////////////////////////////////////////
    static cXercesInitializer*& Instance()
    {
        static cXercesInitializer* instance = 0;
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

#else // !defined(CXERCESINITIALIZER_MEMBERS_ONLY) 
#endif // !defined(CXERCESINITIALIZER_MEMBERS_ONLY) 

#endif // !defined(_CXERCESINITIALIZER_HPP) || defined(CXERCESINITIALIZER_MEMBERS_ONLY) 
