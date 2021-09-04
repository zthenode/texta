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
//   File: cHttpServletResponse.hpp
//
// Author: $author$
//   Date: 10/26/2011
///////////////////////////////////////////////////////////////////////
#if !defined(_CHTTPSERVLETRESPONSE_HPP) || defined(CHTTPSERVLETRESPONSE_MEMBERS_ONLY)
#if !defined(_CHTTPSERVLETRESPONSE_HPP) && !defined(CHTTPSERVLETRESPONSE_MEMBERS_ONLY)
#define _CHTTPSERVLETRESPONSE_HPP
#endif // !defined(_CHTTPSERVLETRESPONSE_HPP) && !defined(CHTTPSERVLETRESPONSE_MEMBERS_ONLY) 

#if !defined(CHTTPSERVLETRESPONSE_MEMBERS_ONLY)
#include "cHttpServletResponseInterface.hpp"
#include "cHttpContent.hpp"
#include "cInstanceBase.hpp"
#include "cWriter.hpp"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

///////////////////////////////////////////////////////////////////////
// Typedef: cHttpServletResponseExtend
//
//  Author: $author$
//    Date: 10/26/2011
///////////////////////////////////////////////////////////////////////
typedef cInstanceBase
cHttpServletResponseExtend;
///////////////////////////////////////////////////////////////////////
//  Class: cHttpServletResponse
//
// Author: $author$
//   Date: 10/26/2011
///////////////////////////////////////////////////////////////////////
class c_INSTANCE_CLASS cHttpServletResponse
: virtual public cHttpServletResponseImplement,
  public cHttpServletResponseExtend
{
public:
    typedef cHttpServletResponseImplement cImplements;
    typedef cHttpServletResponseExtend cExtends;

    cWriter m_writer;
    cHttpContent m_content;

    ///////////////////////////////////////////////////////////////////////
    //  Constructor: cHttpServletResponse
    //
    //       Author: $author$
    //         Date: 10/26/2011
    ///////////////////////////////////////////////////////////////////////
    cHttpServletResponse()
    {
    }
    ///////////////////////////////////////////////////////////////////////
    //  Destructor: ~cHttpServletResponse
    //
    //      Author: $author$
    //        Date: 10/26/2011
    ///////////////////////////////////////////////////////////////////////
    virtual ~cHttpServletResponse()
    {
    }
#else // !defined(CHTTPSERVLETRESPONSE_MEMBERS_ONLY) 
#endif // !defined(CHTTPSERVLETRESPONSE_MEMBERS_ONLY) 

#if !defined(CHTTPSERVLETRESPONSE_MEMBER_FUNCS_IMPLEMENT)
    ///////////////////////////////////////////////////////////////////////
    //  Function: SetContentType
    //
    //    Author: $author$
    //      Date: 10/27/2011
    ///////////////////////////////////////////////////////////////////////
    virtual const cString& SetContentType
    (const cString& toContentType)
#if defined(CHTTPSERVLETRESPONSE_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CHTTPSERVLETRESPONSE_MEMBER_FUNCS_INTERFACE) 
    {
        const cString& contentType = m_content.SetContentType(toContentType);
        return contentType;
    }
#endif // defined(CHTTPSERVLETRESPONSE_MEMBER_FUNCS_INTERFACE) 
#else // !defined(CHTTPSERVLETRESPONSE_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CHTTPSERVLETRESPONSE_MEMBER_FUNCS_IMPLEMENT) 
#if !defined(CHTTPSERVLETRESPONSE_MEMBER_FUNCS_IMPLEMENT)
    ///////////////////////////////////////////////////////////////////////
    //  Function: GetContentType
    //
    //    Author: $author$
    //      Date: 10/27/2011
    ///////////////////////////////////////////////////////////////////////
    virtual const cString& GetContentType()
#if defined(CHTTPSERVLETRESPONSE_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CHTTPSERVLETRESPONSE_MEMBER_FUNCS_INTERFACE) 
    {
        const cString& contentType = m_content.GetContentType();
        return contentType;
    }
#endif // defined(CHTTPSERVLETRESPONSE_MEMBER_FUNCS_INTERFACE) 
#else // !defined(CHTTPSERVLETRESPONSE_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CHTTPSERVLETRESPONSE_MEMBER_FUNCS_IMPLEMENT) 
    ///////////////////////////////////////////////////////////////////////
    //  Function: DelegateContent
    //
    //    Author: $author$
    //      Date: 11/1/2011
    ///////////////////////////////////////////////////////////////////////
    virtual cHttpContentInterface* DelegateContent
    (cHttpContentInterface* toContent)
#if defined(CHTTPSERVLETRESPONSE_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CHTTPSERVLETRESPONSE_MEMBER_FUNCS_INTERFACE) 
    {
        cHttpContentInterface* oldContent = 0;
#if !defined(CHTTPSERVLETRESPONSE_MEMBER_FUNCS_IMPLEMENT)
        oldContent = m_content.Delegate(toContent);
#else // !defined(CHTTPSERVLETRESPONSE_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CHTTPSERVLETRESPONSE_MEMBER_FUNCS_IMPLEMENT) 
        return oldContent;
    }
#endif // defined(CHTTPSERVLETRESPONSE_MEMBER_FUNCS_INTERFACE) 

#if !defined(CHTTPSERVLETRESPONSE_MEMBER_FUNCS_IMPLEMENT)
    ///////////////////////////////////////////////////////////////////////
    //  Function: DelegateWrite
    //
    //    Author: $author$
    //      Date: 10/26/2011
    ///////////////////////////////////////////////////////////////////////
    virtual cWriterInterface* DelegateWrite
    (cWriterInterface* toWriter)
#if defined(CHTTPSERVLETRESPONSE_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CHTTPSERVLETRESPONSE_MEMBER_FUNCS_INTERFACE) 
    {
        cWriterInterface* oldWriter = m_writer.DelegateWrite(toWriter);
        return oldWriter;
    }
#endif // defined(CHTTPSERVLETRESPONSE_MEMBER_FUNCS_INTERFACE) 
#else // !defined(CHTTPSERVLETRESPONSE_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CHTTPSERVLETRESPONSE_MEMBER_FUNCS_IMPLEMENT) 
#if !defined(CHTTPSERVLETRESPONSE_MEMBER_FUNCS_IMPLEMENT)
    ///////////////////////////////////////////////////////////////////////
    //  Function: GetWriter
    //
    //    Author: $author$
    //      Date: 10/26/2011
    ///////////////////////////////////////////////////////////////////////
    virtual cWriterInterface& GetWriter() const
#if defined(CHTTPSERVLETRESPONSE_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CHTTPSERVLETRESPONSE_MEMBER_FUNCS_INTERFACE) 
    {
        return (cWriterInterface&)(m_writer);
    }
#endif // defined(CHTTPSERVLETRESPONSE_MEMBER_FUNCS_INTERFACE) 
#else // !defined(CHTTPSERVLETRESPONSE_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CHTTPSERVLETRESPONSE_MEMBER_FUNCS_IMPLEMENT) 

#if !defined(CHTTPSERVLETRESPONSE_MEMBERS_ONLY)
};


#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#else // !defined(CHTTPSERVLETRESPONSE_MEMBERS_ONLY) 
#endif // !defined(CHTTPSERVLETRESPONSE_MEMBERS_ONLY) 

#endif // !defined(_CHTTPSERVLETRESPONSE_HPP) || defined(CHTTPSERVLETRESPONSE_MEMBERS_ONLY) 
        

