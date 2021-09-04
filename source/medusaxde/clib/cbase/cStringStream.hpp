///////////////////////////////////////////////////////////////////////
// Copyright (c) 1988-2012 $organization$
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
//   File: cStringStream.hpp
//
// Author: $author$
//   Date: 11/25/2012
///////////////////////////////////////////////////////////////////////
#if !defined(_CSTRINGSTREAM_HPP) || defined(CSTRINGSTREAMT_MEMBERS_ONLY)
#if !defined(_CSTRINGSTREAM_HPP) && !defined(CSTRINGSTREAMT_MEMBERS_ONLY)
#define _CSTRINGSTREAM_HPP
#endif // !defined(_CSTRINGSTREAM_HPP) && !defined(CSTRINGSTREAMT_MEMBERS_ONLY) 

#if !defined(CSTRINGSTREAMT_MEMBERS_ONLY)
#include "cStringStreamInterface.hpp"
#include "cCharStream.hpp"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

class c_INSTANCE_CLASS cStringStream;

#undef CDB_CLASS
#define CDB_CLASS "cStringStreamT"
///////////////////////////////////////////////////////////////////////
//  Class: cStringStreamT
//
// Author: $author$
//   Date: 7/19/2011
///////////////////////////////////////////////////////////////////////
template
<class TImplement=cStringStreamImplement,
 class TStringInterface=cStringInterface,
 class TExtend=cCharStream,
 class TChar=char,
 int VStringEnd=0>

class c_INSTANCE_CLASS cStringStreamT
: virtual public TImplement,
  public TExtend
{
public:
    typedef TImplement cImplements;
    typedef TExtend cExtends;
    enum { vStringEnd=VStringEnd };

// include cStringStream interface member definitions
//
#define CSTRINGSTREAMINTERFACET_MEMBERS_ONLY
#include "cStringStreamInterface.hpp"
#undef CSTRINGSTREAMINTERFACET_MEMBERS_ONLY

    const tStringInterface& m_string;
    const ssize_t m_stringEnd;
    const char_t* m_stringChars;
    size_t m_stringLength;
    size_t m_stringTell;

    ///////////////////////////////////////////////////////////////////////
    //  Constructor: cStringStreamT
    //
    //       Author: $author$
    //         Date: 7/19/2011
    ///////////////////////////////////////////////////////////////////////
    cStringStreamT
    (const tStringInterface& string, 
     const ssize_t stringEnd = vStringEnd)
    : m_string(string), 
      m_stringEnd(stringEnd),
      m_stringChars(0), 
      m_stringLength(0), 
      m_stringTell(0)
    {
        if ((m_stringChars = m_string.HasChars()))
            m_stringLength = (size_t)(m_string.Length());
    }
    ///////////////////////////////////////////////////////////////////////
    //  Destructor: ~cStringStreamT
    //
    //      Author: $author$
    //        Date: 7/19/2011
    ///////////////////////////////////////////////////////////////////////
    virtual ~cStringStreamT()
    {
    }
#else // !defined(CSTRINGSTREAMT_MEMBERS_ONLY) 
#endif // !defined(CSTRINGSTREAMT_MEMBERS_ONLY) 

    ///////////////////////////////////////////////////////////////////////
    //  Function: Read
    //
    //    Author: $author$
    //      Date: 7/19/2011
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t Read
    (char_t* chars,
     size_t size)
#if defined(CSTRINGSTREAMT_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CSTRINGSTREAMT_MEMBER_FUNCS_INTERFACE) 
    {
#if !defined(CSTRINGSTREAMT_MEMBER_FUNCS_IMPLEMENT)
        ssize_t count = m_stringEnd;
        size_t length;
        if ((chars) && (size))
        if ((m_stringChars) && (m_stringTell < m_stringLength))
        {
            if (size > (length = (m_stringLength - m_stringTell)))
                size = length;
            memcpy(chars, m_stringChars+m_stringTell, size*sizeof(char_t));
            m_stringTell += size;
            count = (ssize_t)(size);
        }
#else // !defined(CSTRINGSTREAMT_MEMBER_FUNCS_IMPLEMENT) 
        ssize_t count = 0;
#endif // !defined(CSTRINGSTREAMT_MEMBER_FUNCS_IMPLEMENT) 
        return count;
    }
#endif // defined(CSTRINGSTREAMT_MEMBER_FUNCS_INTERFACE) 

    ///////////////////////////////////////////////////////////////////////
    //  Function: Reset
    //
    //    Author: $author$
    //      Date: 7/28/2011
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t Reset()
#if defined(CSTRINGSTREAMT_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CSTRINGSTREAMT_MEMBER_FUNCS_INTERFACE) 
    {
        ssize_t count = 0;
#if !defined(CSTRINGSTREAMT_MEMBER_FUNCS_IMPLEMENT)
        m_stringTell = (m_stringLength = 0);
        if ((m_stringChars = m_string.HasChars()))
            m_stringLength = (size_t)(m_string.Length());
#else // !defined(CSTRINGSTREAMT_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CSTRINGSTREAMT_MEMBER_FUNCS_IMPLEMENT) 
        return count;
    }
#endif // defined(CSTRINGSTREAMT_MEMBER_FUNCS_INTERFACE) 

#if !defined(CSTRINGSTREAMT_MEMBERS_ONLY)
};
#undef CDB_CLASS

///////////////////////////////////////////////////////////////////////
// Typedef: cStringStreamExtend
//
//  Author: $author$
//    Date: 7/20/2011
///////////////////////////////////////////////////////////////////////
typedef cStringStreamT<>
cStringStreamExtend;
///////////////////////////////////////////////////////////////////////
//  Class: cStringStream
//
// Author: $author$
//   Date: 7/20/2011
///////////////////////////////////////////////////////////////////////
class c_INSTANCE_CLASS cStringStream
: public cStringStreamExtend
{
public:
    typedef cStringStreamExtend cExtends;
    ///////////////////////////////////////////////////////////////////////
    //  Constructor: cStringStream
    //
    //       Author: $author$
    //         Date: 7/20/2011
    ///////////////////////////////////////////////////////////////////////
    cStringStream
    (const tStringInterface& string,
     const ssize_t stringEnd = vStringEnd)
    : cExtends(string, stringEnd)
    {
    }
};

#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#else // !defined(CSTRINGSTREAMT_MEMBERS_ONLY) 
#endif // !defined(CSTRINGSTREAMT_MEMBERS_ONLY) 

#endif // !defined(_CSTRINGSTREAM_HPP) || defined(CSTRINGSTREAMT_MEMBERS_ONLY) 
