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
//   File: cStringReader.hpp
//
// Author: $author$
//   Date: 7/19/2011
///////////////////////////////////////////////////////////////////////
#if !defined(_CSTRINGREADER_HPP) || defined(CSTRINGREADERT_MEMBERS_ONLY)
#if !defined(_CSTRINGREADER_HPP) && !defined(CSTRINGREADERT_MEMBERS_ONLY)
#define _CSTRINGREADER_HPP
#endif // !defined(_CSTRINGREADER_HPP) && !defined(CSTRINGREADERT_MEMBERS_ONLY) 

#if !defined(CSTRINGREADERT_MEMBERS_ONLY)
#include "cStringReaderInterface.hpp"
#include "cCharReader.hpp"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

class c_INSTANCE_CLASS cStringReader;

#undef CDB_CLASS
#define CDB_CLASS "cStringReaderT"
///////////////////////////////////////////////////////////////////////
//  Class: cStringReaderT
//
// Author: $author$
//   Date: 7/19/2011
///////////////////////////////////////////////////////////////////////
template
<class TImplement=cStringReaderImplement,
 class TStringInterface=cStringInterface,
 class TExtend=cCharReader,
 class TChar=char>

class c_INSTANCE_CLASS cStringReaderT
: virtual public TImplement,
  public TExtend
{
public:
    typedef TImplement cImplements;
    typedef TExtend cExtends;

// include cStringReader interface member definitions
//
#define CSTRINGREADERINTERFACET_MEMBERS_ONLY
#include "cStringReaderInterface.hpp"
#undef CSTRINGREADERINTERFACET_MEMBERS_ONLY

    const tStringInterface& m_string;
    const char_t* m_stringChars;
    size_t m_stringLength;
    size_t m_stringTell;

    ///////////////////////////////////////////////////////////////////////
    //  Constructor: cStringReaderT
    //
    //       Author: $author$
    //         Date: 7/19/2011
    ///////////////////////////////////////////////////////////////////////
    cStringReaderT
    (const tStringInterface& string)
    : m_string(string), 
      m_stringChars(0), 
      m_stringLength(0), 
      m_stringTell(0)
    {
        if ((m_stringChars = m_string.HasChars()))
            m_stringLength = (size_t)(m_string.Length());
    }
    ///////////////////////////////////////////////////////////////////////
    //  Destructor: ~cStringReaderT
    //
    //      Author: $author$
    //        Date: 7/19/2011
    ///////////////////////////////////////////////////////////////////////
    virtual ~cStringReaderT()
    {
    }
#else // !defined(CSTRINGREADERT_MEMBERS_ONLY) 
#endif // !defined(CSTRINGREADERT_MEMBERS_ONLY) 

    ///////////////////////////////////////////////////////////////////////
    //  Function: Read
    //
    //    Author: $author$
    //      Date: 7/19/2011
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t Read
    (char_t* chars,
     size_t size)
#if defined(CSTRINGREADERT_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CSTRINGREADERT_MEMBER_FUNCS_INTERFACE) 
    {
        ssize_t count = 0;
#if !defined(CSTRINGREADERT_MEMBER_FUNCS_IMPLEMENT)
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
#else // !defined(CSTRINGREADERT_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CSTRINGREADERT_MEMBER_FUNCS_IMPLEMENT) 
        return count;
    }
#endif // defined(CSTRINGREADERT_MEMBER_FUNCS_INTERFACE) 

    ///////////////////////////////////////////////////////////////////////
    //  Function: Reset
    //
    //    Author: $author$
    //      Date: 7/28/2011
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t Reset()
#if defined(CSTRINGREADERT_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CSTRINGREADERT_MEMBER_FUNCS_INTERFACE) 
    {
        ssize_t count = 0;
#if !defined(CSTRINGREADERT_MEMBER_FUNCS_IMPLEMENT)
        m_stringTell = (m_stringLength = 0);
        if ((m_stringChars = m_string.HasChars()))
            m_stringLength = (size_t)(m_string.Length());
#else // !defined(CSTRINGREADERT_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CSTRINGREADERT_MEMBER_FUNCS_IMPLEMENT) 
        return count;
    }
#endif // defined(CSTRINGREADERT_MEMBER_FUNCS_INTERFACE) 

#if !defined(CSTRINGREADERT_MEMBERS_ONLY)
};
#undef CDB_CLASS

///////////////////////////////////////////////////////////////////////
// Typedef: cStringReaderExtend
//
//  Author: $author$
//    Date: 7/20/2011
///////////////////////////////////////////////////////////////////////
typedef cStringReaderT<>
cStringReaderExtend;
///////////////////////////////////////////////////////////////////////
//  Class: cStringReader
//
// Author: $author$
//   Date: 7/20/2011
///////////////////////////////////////////////////////////////////////
class c_INSTANCE_CLASS cStringReader
: public cStringReaderExtend
{
public:
    typedef cStringReaderExtend cExtends;
    ///////////////////////////////////////////////////////////////////////
    //  Constructor: cStringReader
    //
    //       Author: $author$
    //         Date: 7/20/2011
    ///////////////////////////////////////////////////////////////////////
    cStringReader
    (const tStringInterface& string)
    : cExtends(string)
    {
    }
};

#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#else // !defined(CSTRINGREADERT_MEMBERS_ONLY) 
#endif // !defined(CSTRINGREADERT_MEMBERS_ONLY) 

#endif // !defined(_CSTRINGREADER_HPP) || defined(CSTRINGREADERT_MEMBERS_ONLY) 
        

