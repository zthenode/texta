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
//   File: cCgiContentStream.hpp
//
// Author: $author$
//   Date: 6/25/2011
///////////////////////////////////////////////////////////////////////
#if !defined(_CCGICONTENTSTREAM_HPP) || defined(CCGICONTENTSTREAM_MEMBERS_ONLY)
#if !defined(_CCGICONTENTSTREAM_HPP) && !defined(CCGICONTENTSTREAM_MEMBERS_ONLY)
#define _CCGICONTENTSTREAM_HPP
#endif // !defined(_CCGICONTENTSTREAM_HPP) && !defined(CCGICONTENTSTREAM_MEMBERS_ONLY) 

#if !defined(CCGICONTENTSTREAM_MEMBERS_ONLY)
#include "cCgiContentStreamInterface.hpp"
#include "cCharStream.hpp"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

///////////////////////////////////////////////////////////////////////
// Typedef: cCgiContentStreamExtend
//
//  Author: $author$
//    Date: 6/25/2011
///////////////////////////////////////////////////////////////////////
typedef cCharStream
cCgiContentStreamExtend;
///////////////////////////////////////////////////////////////////////
//  Class: cCgiContentStream
//
// Author: $author$
//   Date: 6/25/2011
///////////////////////////////////////////////////////////////////////
class c_INSTANCE_CLASS cCgiContentStream
: virtual public cCgiContentStreamImplement,
  public cCgiContentStreamExtend
{
public:
    typedef cCgiContentStreamImplement cImplements;
    typedef cCgiContentStreamExtend cExtends;
    ///////////////////////////////////////////////////////////////////////
    //  Constructor: cCgiContentStream
    //
    //       Author: $author$
    //         Date: 6/25/2011
    ///////////////////////////////////////////////////////////////////////
    cCgiContentStream()
    {
    }
    ///////////////////////////////////////////////////////////////////////
    //  Destructor: ~cCgiContentStream
    //
    //      Author: $author$
    //        Date: 6/25/2011
    ///////////////////////////////////////////////////////////////////////
    virtual ~cCgiContentStream()
    {
    }
#else // !defined(CCGICONTENTSTREAM_MEMBERS_ONLY) 
#endif // !defined(CCGICONTENTSTREAM_MEMBERS_ONLY) 

#if !defined(CCGICONTENTSTREAM_MEMBERS_ONLY) 
    using cExtends::Write;
#else // !defined(CCGICONTENTSTREAM_MEMBERS_ONLY) 
    using cImplements::Write;
#endif // !defined(CCGICONTENTSTREAM_MEMBERS_ONLY) 

    ///////////////////////////////////////////////////////////////////////
    //  Function: SetContentType
    //
    //    Author: $author$
    //      Date: 6/25/2011
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t SetContentType
    (const cString& contentType)
#if defined(CCGICONTENTSTREAM_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CCGICONTENTSTREAM_MEMBER_FUNCS_INTERFACE) 
    {
        ssize_t count = 0;
#if !defined(CCGICONTENTSTREAM_MEMBER_FUNCS_IMPLEMENT)
#else // !defined(CCGICONTENTSTREAM_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CCGICONTENTSTREAM_MEMBER_FUNCS_IMPLEMENT) 
        return count;
    }
#endif // defined(CCGICONTENTSTREAM_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    //  Function: GetContentType
    //
    //    Author: $author$
    //      Date: 11/25/2012
    ///////////////////////////////////////////////////////////////////////
    virtual cString GetContentType() const
#if defined(CCGICONTENTSTREAM_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CCGICONTENTSTREAM_MEMBER_FUNCS_INTERFACE) 
    {
        cString type;
#if !defined(CCGICONTENTSTREAM_MEMBER_FUNCS_IMPLEMENT)
#else // !defined(CCGICONTENTSTREAM_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CCGICONTENTSTREAM_MEMBER_FUNCS_IMPLEMENT) 
        return type;
    }
#endif // defined(CCGICONTENTSTREAM_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    //  Function: GetContentTypeText
    //
    //    Author: $author$
    //      Date: 11/25/2012
    ///////////////////////////////////////////////////////////////////////
    virtual cString GetContentTypeText() const
#if defined(CCGICONTENTSTREAM_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CCGICONTENTSTREAM_MEMBER_FUNCS_INTERFACE) 
    {
        cString type;
#if !defined(CCGICONTENTSTREAM_MEMBER_FUNCS_IMPLEMENT)
#else // !defined(CCGICONTENTSTREAM_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CCGICONTENTSTREAM_MEMBER_FUNCS_IMPLEMENT) 
        return type;
    }
#endif // defined(CCGICONTENTSTREAM_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    //  Function: GetContentTypeHtml
    //
    //    Author: $author$
    //      Date: 11/25/2012
    ///////////////////////////////////////////////////////////////////////
    virtual cString GetContentTypeHtml() const
#if defined(CCGICONTENTSTREAM_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CCGICONTENTSTREAM_MEMBER_FUNCS_INTERFACE) 
    {
        cString type;
#if !defined(CCGICONTENTSTREAM_MEMBER_FUNCS_IMPLEMENT)
#else // !defined(CCGICONTENTSTREAM_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CCGICONTENTSTREAM_MEMBER_FUNCS_IMPLEMENT) 
        return type;
    }
#endif // defined(CCGICONTENTSTREAM_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    //  Function: GetContentTypeXml
    //
    //    Author: $author$
    //      Date: 11/25/2012
    ///////////////////////////////////////////////////////////////////////
    virtual cString GetContentTypeXml() const
#if defined(CCGICONTENTSTREAM_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CCGICONTENTSTREAM_MEMBER_FUNCS_INTERFACE) 
    {
        cString type;
#if !defined(CCGICONTENTSTREAM_MEMBER_FUNCS_IMPLEMENT)
#else // !defined(CCGICONTENTSTREAM_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CCGICONTENTSTREAM_MEMBER_FUNCS_IMPLEMENT) 
        return type;
    }
#endif // defined(CCGICONTENTSTREAM_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    //  Function: Write
    //
    //    Author: $author$
    //      Date: 6/25/2011
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t Write
    (const cString& content)
#if defined(CCGICONTENTSTREAM_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CCGICONTENTSTREAM_MEMBER_FUNCS_INTERFACE) 
    {
        ssize_t count = 0;
#if !defined(CCGICONTENTSTREAM_MEMBER_FUNCS_IMPLEMENT)
        const char* chars;
        ssize_t length;
        if ((chars = content.Chars(length)))
            count = Write(chars, length);
#else // !defined(CCGICONTENTSTREAM_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CCGICONTENTSTREAM_MEMBER_FUNCS_IMPLEMENT) 
        return count;
    }
#endif // defined(CCGICONTENTSTREAM_MEMBER_FUNCS_INTERFACE) 

#if !defined(CCGICONTENTSTREAM_MEMBERS_ONLY)
};

#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#else // !defined(CCGICONTENTSTREAM_MEMBERS_ONLY) 
#endif // !defined(CCGICONTENTSTREAM_MEMBERS_ONLY) 

#endif // !defined(_CCGICONTENTSTREAM_HPP) || defined(CCGICONTENTSTREAM_MEMBERS_ONLY) 
