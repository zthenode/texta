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
//   File: cStringWriter.hpp
//
// Author: $author$
//   Date: 7/26/2011
///////////////////////////////////////////////////////////////////////
#if !defined(_CSTRINGWRITER_HPP) || defined(CSTRINGWRITERT_MEMBERS_ONLY)
#if !defined(_CSTRINGWRITER_HPP) && !defined(CSTRINGWRITERT_MEMBERS_ONLY)
#define _CSTRINGWRITER_HPP
#endif // !defined(_CSTRINGWRITER_HPP) && !defined(CSTRINGWRITERT_MEMBERS_ONLY) 

#if !defined(CSTRINGWRITERT_MEMBERS_ONLY)
#include "cStringWriterInterface.hpp"
#include "cCharWriter.hpp"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

#undef CDB_CLASS
#define CDB_CLASS "cStringWriterT"
///////////////////////////////////////////////////////////////////////
//  Class: cStringWriterT
//
// Author: $author$
//   Date: 7/26/2011
///////////////////////////////////////////////////////////////////////
template
<class TExtend=cCharWriter,
 class TImplement=cStringWriterImplement,
 class TStringInterface=cStringInterface,
 class TChar=char>

class c_INSTANCE_CLASS cStringWriterT
: virtual public TImplement,
  public TExtend
{
public:
    typedef TImplement cImplements;
    typedef TExtend cExtends;

// include cStringWriterT interface member definitions
//
#define CSTRINGWRITERINTERFACET_MEMBERS_ONLY
#include "cStringWriterInterface.hpp"
#undef CSTRINGWRITERINTERFACET_MEMBERS_ONLY

    tStringInterface& m_string;

    ///////////////////////////////////////////////////////////////////////
    //  Constructor: cStringWriterT
    //
    //       Author: $author$
    //         Date: 7/26/2011
    ///////////////////////////////////////////////////////////////////////
    cStringWriterT
    (tStringInterface& string)
    : m_string(string)
    {
    }
    ///////////////////////////////////////////////////////////////////////
    //  Destructor: ~cStringWriterT
    //
    //      Author: $author$
    //        Date: 7/26/2011
    ///////////////////////////////////////////////////////////////////////
    virtual ~cStringWriterT()
    {
    }
#else // !defined(CSTRINGWRITERT_MEMBERS_ONLY) 
#endif // !defined(CSTRINGWRITERT_MEMBERS_ONLY) 

    ///////////////////////////////////////////////////////////////////////
    //  Function: Write
    //
    //    Author: $author$
    //      Date: 7/26/2011
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t Write
    (const char_t* chars,
     ssize_t length=-1)
#if defined(CSTRINGWRITERT_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CSTRINGWRITERT_MEMBER_FUNCS_INTERFACE) 
    {
        ssize_t count = 0;
#if !defined(CSTRINGWRITERT_MEMBER_FUNCS_IMPLEMENT)
        count = m_string.Append(chars, length);
#else // !defined(CSTRINGWRITERT_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CSTRINGWRITERT_MEMBER_FUNCS_IMPLEMENT) 
        return count;
    }
#endif // defined(CSTRINGWRITERT_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    //  Function: Put
    //
    //    Author: $author$
    //      Date: 7/26/2011
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t Put
    (const char_t& aChar)
#if defined(CSTRINGWRITERT_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CSTRINGWRITERT_MEMBER_FUNCS_INTERFACE) 
    {
        ssize_t count = 0;
#if !defined(CSTRINGWRITERT_MEMBER_FUNCS_IMPLEMENT)
        count = m_string.Append(&aChar, 1);
#else // !defined(CSTRINGWRITERT_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CSTRINGWRITERT_MEMBER_FUNCS_IMPLEMENT) 
        return count;
    }
#endif // defined(CSTRINGWRITERT_MEMBER_FUNCS_INTERFACE) 

#if !defined(CSTRINGWRITERT_MEMBERS_ONLY)
};
#undef CDB_CLASS

///////////////////////////////////////////////////////////////////////
// Typedef: cStringWriterExtend
//
//  Author: $author$
//    Date: 7/26/2011
///////////////////////////////////////////////////////////////////////
typedef cStringWriterT
<cCharWriter, cStringWriterImplement, 
 cStringInterface, char>
cStringWriterExtend;
///////////////////////////////////////////////////////////////////////
//  Class: cStringWriter
//
// Author: $author$
//   Date: 7/26/2011
///////////////////////////////////////////////////////////////////////
class c_INSTANCE_CLASS cStringWriter
: public cStringWriterExtend
{
public:
    typedef cStringWriterExtend cExtends;
    ///////////////////////////////////////////////////////////////////////
    //  Constructor: cStringWriter
    //
    //       Author: $author$
    //         Date: 7/26/2011
    ///////////////////////////////////////////////////////////////////////
    cStringWriter
    (tStringInterface& string)
    : cExtends(string)
    {
    }
};

#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#else // !defined(CSTRINGWRITERT_MEMBERS_ONLY) 
#endif // !defined(CSTRINGWRITERT_MEMBERS_ONLY) 

#endif // !defined(_CSTRINGWRITER_HPP) || defined(CSTRINGWRITERT_MEMBERS_ONLY) 
