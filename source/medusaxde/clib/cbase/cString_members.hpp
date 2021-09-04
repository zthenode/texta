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
//   File: cString_members.hpp
//
// Author: $author$
//   Date: 6/25/2011
///////////////////////////////////////////////////////////////////////
#if !defined(_CSTRING_MEMBERS_HPP) || defined(CSTRING_MEMBERS_ONLY)
#if !defined(_CSTRING_MEMBERS_HPP) && !defined(CSTRING_MEMBERS_ONLY)
#define _CSTRING_MEMBERS_HPP
#endif // !defined(_CSTRING_MEMBERS_HPP) && !defined(CSTRING_MEMBERS_ONLY) 

#if !defined(CSTRING_MEMBERS_ONLY)

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

class cString
{
public:
#else // !defined(CSTRING_MEMBERS_ONLY) 

#if defined(CSTRING_MEMBER_FUNCS_INTERFACE) || defined(CSTRING_MEMBER_FUNCS_IMPLEMENT)
#define xImplements cImplements
#else // defined(CSTRING_MEMBER_FUNCS_INTERFACE) || defined(CSTRING_MEMBER_FUNCS_IMPLEMENT)
#define xImplements cExtends
#endif // defined(CSTRING_MEMBER_FUNCS_INTERFACE) || defined(CSTRING_MEMBER_FUNCS_IMPLEMENT)

#define Assign_xcharx(xchar) Assign_##xchar
#define Assign_xchar(xchar) Assign_xcharx(xchar)
#define Append_xcharx(xchar) Append_##xchar
#define Append_xchar(xchar) Append_xcharx(xchar)

using xImplements::Assign;
using xImplements::Append;
using xImplements::operator =;
using xImplements::operator <<;

#endif // !defined(CSTRING_MEMBERS_ONLY) 

    ///////////////////////////////////////////////////////////////////////
    //  Function: Assign
    //
    //    Author: $author$
    //      Date: 6/25/2011
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t Assign
    (const xchar_t* chars, ssize_t length=-1)
#if defined(CSTRING_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CSTRING_MEMBER_FUNCS_INTERFACE) 
    {
        ssize_t count = 0;
#if !defined(CSTRING_MEMBER_FUNCS_IMPLEMENT)
        count = cExtends::Assign_xchar(xchar)(chars, length);
#else // !defined(CSTRING_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CSTRING_MEMBER_FUNCS_IMPLEMENT) 
        return count;
    }
#endif // defined(CSTRING_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    //  Function: Append
    //
    //    Author: $author$
    //      Date: 6/25/2011
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t Append
    (const xchar_t* chars, ssize_t length=-1)
#if defined(CSTRING_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CSTRING_MEMBER_FUNCS_INTERFACE) 
    {
        ssize_t count = 0;
#if !defined(CSTRING_MEMBER_FUNCS_IMPLEMENT)
        count = cExtends::Append_xchar(xchar)(chars, length);
#else // !defined(CSTRING_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CSTRING_MEMBER_FUNCS_IMPLEMENT) 
        return count;
    }
#endif // defined(CSTRING_MEMBER_FUNCS_INTERFACE) 

    ///////////////////////////////////////////////////////////////////////
    //  Function: operator =
    //
    //    Author: $author$
    //      Date: 6/25/2011
    ///////////////////////////////////////////////////////////////////////
    virtual cInterface& operator =
    (const xchar_t* chars)
#if defined(CSTRINGT_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CSTRINGT_MEMBER_FUNCS_INTERFACE) 
    {
        cInterface& self = *this;
#if !defined(CSTRINGT_MEMBER_FUNCS_IMPLEMENT)
        Assign(chars);
#else // !defined(CSTRINGT_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CSTRINGT_MEMBER_FUNCS_IMPLEMENT) 
        return self;
    }
#endif // defined(CSTRINGT_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    //  Function: operator <<
    //
    //    Author: $author$
    //      Date: 6/25/2011
    ///////////////////////////////////////////////////////////////////////
    virtual cInterface& operator <<
    (const xchar_t* chars)
#if defined(CSTRINGT_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CSTRINGT_MEMBER_FUNCS_INTERFACE) 
    {
        cInterface& self = *this;
#if !defined(CSTRINGT_MEMBER_FUNCS_IMPLEMENT)
        Append(chars);
#else // !defined(CSTRINGT_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CSTRINGT_MEMBER_FUNCS_IMPLEMENT) 
        return self;
    }
#endif // defined(CSTRINGT_MEMBER_FUNCS_INTERFACE) 

#if !defined(CSTRING_MEMBERS_ONLY)
};

#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#else // !defined(CSTRING_MEMBERS_ONLY) 

#undef xImplements
#undef Assign_xcharx
#undef Assign_xchar
#undef Append_xcharx
#undef Append_xchar

#endif // !defined(CSTRING_MEMBERS_ONLY) 

#endif // !defined(_CSTRING_MEMBERS_HPP) || defined(CSTRING_MEMBERS_ONLY) 
