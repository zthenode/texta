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
//   File: cCharWriter.hpp
//
// Author: $author$
//   Date: 5/19/2011
///////////////////////////////////////////////////////////////////////
#if !defined(_CCHARWRITER_HPP) || defined(CCHARWRITERT_MEMBERS_ONLY)
#if !defined(_CCHARWRITER_HPP) && !defined(CCHARWRITERT_MEMBERS_ONLY)
#define _CCHARWRITER_HPP
#endif // !defined(_CCHARWRITER_HPP) && !defined(CCHARWRITERT_MEMBERS_ONLY) 

#if !defined(CCHARWRITERT_MEMBERS_ONLY)
#include "cCharWriterInterface.hpp"
#include "cWriter.hpp"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

class c_INSTANCE_CLASS cCharWriter;

#undef CDB_CLASS
#define CDB_CLASS "cCharWriterT"
///////////////////////////////////////////////////////////////////////
//  Class: cCharWriterT
//
// Author: $author$
//   Date: 5/19/2011
///////////////////////////////////////////////////////////////////////
template
<class TExtend=cWriter,
 class TImplement=cCharWriterImplement,
 class TInterface=cCharWriterInterface,
 class TWhat=char>

class c_INSTANCE_CLASS cCharWriterT
: virtual public TImplement,
  public TExtend
{
public:
    typedef TImplement cImplements;
    typedef TExtend cExtends;
    typedef TInterface tCharWriterInterface;

// include cCharWriter interface member definitions
//
#define CCHARWRITERINTERFACET_MEMBERS_ONLY
#include "cCharWriterInterface.hpp"
#undef CCHARWRITERINTERFACET_MEMBERS_ONLY

    tCharWriterInterface* m_delegated;

    ///////////////////////////////////////////////////////////////////////
    //  Constructor: cCharWriterT
    //
    //       Author: $author$
    //         Date: 5/19/2011
    ///////////////////////////////////////////////////////////////////////
    cCharWriterT
    (tCharWriterInterface* delegatedTo=0)
    : cExtends(delegatedTo), 
      m_delegated(delegatedTo)
    {
    }
    ///////////////////////////////////////////////////////////////////////
    //  Destructor: ~cCharWriterT
    //
    //      Author: $author$
    //        Date: 5/19/2011
    ///////////////////////////////////////////////////////////////////////
    virtual ~cCharWriterT()
    {
    }
#else // !defined(CCHARWRITERT_MEMBERS_ONLY) 
#endif // !defined(CCHARWRITERT_MEMBERS_ONLY) 

    ///////////////////////////////////////////////////////////////////////
    //  Function: WriteFormatted
    //
    //    Author: $author$
    //      Date: 5/19/2011
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t WriteFormatted
    (const char_t* format,
     ...)
#if defined(CCHARWRITERT_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CCHARWRITERT_MEMBER_FUNCS_INTERFACE) 
    {
        ssize_t count = -e_ERROR_NOT_IMPLEMENTED;
#if !defined(CCHARWRITERT_MEMBER_FUNCS_IMPLEMENT)
        va_list va;
        va_start(va, format);
        count = WriteFormattedV(format, va);
        va_end(va);
#else // !defined(CCHARWRITERT_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CCHARWRITERT_MEMBER_FUNCS_IMPLEMENT) 
        return count;
    }
#endif // defined(CCHARWRITERT_MEMBER_FUNCS_INTERFACE) 

    ///////////////////////////////////////////////////////////////////////
    //  Function: WriteFormattedV
    //
    //    Author: $author$
    //      Date: 5/19/2011
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t WriteFormattedV
    (const char_t* format,
     va_list va)
#if defined(CCHARWRITERT_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CCHARWRITERT_MEMBER_FUNCS_INTERFACE) 
    {
        ssize_t count = -e_ERROR_NOT_IMPLEMENTED;
#if !defined(CCHARWRITERT_MEMBER_FUNCS_IMPLEMENT)
#else // !defined(CCHARWRITERT_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CCHARWRITERT_MEMBER_FUNCS_IMPLEMENT) 
        return count;
    }
#endif // defined(CCHARWRITERT_MEMBER_FUNCS_INTERFACE) 

#if !defined(CCHARWRITERT_MEMBERS_ONLY)
};
#undef CDB_CLASS

///////////////////////////////////////////////////////////////////////
// Typedef: cCharWriterExtend
//
//  Author: $author$
//    Date: 5/23/2011
///////////////////////////////////////////////////////////////////////
typedef cCharWriterT
<cWriter,cCharWriterImplement,cCharWriterInterface,char>
cCharWriterExtend;
///////////////////////////////////////////////////////////////////////
//  Class: cCharWriter
//
// Author: $author$
//   Date: 5/23/2011
///////////////////////////////////////////////////////////////////////
class c_INSTANCE_CLASS cCharWriter
: public cCharWriterExtend
{
public:
    typedef cCharWriterExtend cExtends;
    ///////////////////////////////////////////////////////////////////////
    //  Constructor: cCharWriter
    //
    //       Author: $author$
    //         Date: 5/23/2011
    ///////////////////////////////////////////////////////////////////////
    cCharWriter
    (tCharWriterInterface* delegatedTo=0)
    : cExtends(delegatedTo)
    {
    }
};

#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#else // !defined(CCHARWRITERT_MEMBERS_ONLY) 
#endif // !defined(CCHARWRITERT_MEMBERS_ONLY) 

#endif // !defined(_CCHARWRITER_HPP) || defined(CCHARWRITERT_MEMBERS_ONLY) 
        

