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
//   File: cCharStream.hpp
//
// Author: $author$
//   Date: 5/21/2011
///////////////////////////////////////////////////////////////////////
#if !defined(_CCHARSTREAM_HPP) || defined(CCHARSTREAMT_MEMBERS_ONLY)
#if !defined(_CCHARSTREAM_HPP) && !defined(CCHARSTREAMT_MEMBERS_ONLY)
#define _CCHARSTREAM_HPP
#endif // !defined(_CCHARSTREAM_HPP) && !defined(CCHARSTREAMT_MEMBERS_ONLY) 

#if !defined(CCHARSTREAMT_MEMBERS_ONLY)
#include "cCharStreamInterface.hpp"
#include "cStream.hpp"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

class c_INSTANCE_CLASS cCharStream;

#undef CDB_CLASS
#define CDB_CLASS "cCharStreamT"
///////////////////////////////////////////////////////////////////////
//  Class: cCharStreamT
//
// Author: $author$
//   Date: 5/21/2011
///////////////////////////////////////////////////////////////////////
template
<class TExtend=cStream,
 class TImplement=cCharStreamImplement,
 class TInterface=cCharStreamInterface,
 class TWhat=char>

class c_INSTANCE_CLASS cCharStreamT
: virtual public TImplement,
  public TExtend
{
public:
    typedef TImplement cImplements;
    typedef TExtend cExtends;

// include cCharStream interface member definitions
//
#define CCHARSTREAMINTERFACET_MEMBERS_ONLY
#include "cCharStreamInterface.hpp"
#undef CCHARSTREAMINTERFACET_MEMBERS_ONLY

    typedef TInterface tStreamInterface;

    tStreamInterface* m_delegated;

    ///////////////////////////////////////////////////////////////////////
    //  Constructor: cCharStreamT
    //
    //       Author: $author$
    //         Date: 5/21/2011
    ///////////////////////////////////////////////////////////////////////
    cCharStreamT
    (tStreamInterface* delegatedTo=0)
    : cExtends(delegatedTo),
      m_delegated(delegatedTo)
    {
    }
    ///////////////////////////////////////////////////////////////////////
    //  Destructor: ~cCharStreamT
    //
    //      Author: $author$
    //        Date: 5/21/2011
    ///////////////////////////////////////////////////////////////////////
    virtual ~cCharStreamT()
    {
    }
#else // !defined(CCHARSTREAMT_MEMBERS_ONLY) 
#endif // !defined(CCHARSTREAMT_MEMBERS_ONLY) 

    ///////////////////////////////////////////////////////////////////////
    //  Function: ReadFormatted
    //
    //    Author: $author$
    //      Date: 5/21/2011
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t ReadFormatted
    (const char_t* format,
     ...)
#if defined(CCHARSTREAMT_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CCHARSTREAMT_MEMBER_FUNCS_INTERFACE) 
    {
        ssize_t count = -e_ERROR_NOT_IMPLEMENTED;
#if !defined(CCHARSTREAMT_MEMBER_FUNCS_IMPLEMENT)
        va_list va;
        va_start(va, format);
        count = ReadFormattedV(format, va);
        va_end(va);
#else // !defined(CCHARSTREAMT_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CCHARSTREAMT_MEMBER_FUNCS_IMPLEMENT) 
        return count;
    }
#endif // defined(CCHARSTREAMT_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    //  Function: WriteFormatted
    //
    //    Author: $author$
    //      Date: 5/21/2011
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t WriteFormatted
    (const char_t* format,
     ...)
#if defined(CCHARSTREAMT_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CCHARSTREAMT_MEMBER_FUNCS_INTERFACE) 
    {
        ssize_t count = -e_ERROR_NOT_IMPLEMENTED;
#if !defined(CCHARSTREAMT_MEMBER_FUNCS_IMPLEMENT)
        va_list va;
        va_start(va, format);
        count = WriteFormattedV(format, va);
        va_end(va);
#else // !defined(CCHARSTREAMT_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CCHARSTREAMT_MEMBER_FUNCS_IMPLEMENT) 
        return count;
    }
#endif // defined(CCHARSTREAMT_MEMBER_FUNCS_INTERFACE) 

    ///////////////////////////////////////////////////////////////////////
    //  Function: ReadFormattedV
    //
    //    Author: $author$
    //      Date: 5/30/2011
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t ReadFormattedV
    (const char_t* format,
     va_list va)
#if defined(CCHARSTREAMT_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CCHARSTREAMT_MEMBER_FUNCS_INTERFACE)
    {
        ssize_t count = -e_ERROR_NOT_IMPLEMENTED;
#if !defined(CCHARSTREAMT_MEMBER_FUNCS_IMPLEMENT)
        if ((m_delegated) && (m_delegated != ((tStreamInterface*)(this))))
            count = m_delegated->ReadFormattedV(format, va);
#else // !defined(CCHARSTREAMT_MEMBER_FUNCS_IMPLEMENT)
#endif // !defined(CCHARSTREAMT_MEMBER_FUNCS_IMPLEMENT)
        return count;
    }
#endif // defined(CCHARSTREAMT_MEMBER_FUNCS_INTERFACE)
    ///////////////////////////////////////////////////////////////////////
    //  Function: WriteFormattedV
    //
    //    Author: $author$
    //      Date: 5/30/2011
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t WriteFormattedV
    (const char_t* format,
     va_list va)
#if defined(CCHARSTREAMT_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CCHARSTREAMT_MEMBER_FUNCS_INTERFACE)
    {
        ssize_t count = -e_ERROR_NOT_IMPLEMENTED;
#if !defined(CCHARSTREAMT_MEMBER_FUNCS_IMPLEMENT)
        if ((m_delegated) && (m_delegated != ((tStreamInterface*)(this))))
            count = m_delegated->WriteFormattedV(format, va);
#else // !defined(CCHARSTREAMT_MEMBER_FUNCS_IMPLEMENT)
#endif // !defined(CCHARSTREAMT_MEMBER_FUNCS_IMPLEMENT)
        return count;
    }
#endif // defined(CCHARSTREAMT_MEMBER_FUNCS_INTERFACE)

#if !defined(CCHARSTREAMT_MEMBERS_ONLY)
};
#undef CDB_CLASS

///////////////////////////////////////////////////////////////////////
// Typedef: cCharStreamExtends
//
//  Author: $author$
//    Date: 6/3/2011
///////////////////////////////////////////////////////////////////////
typedef cCharStreamT
<cStream,cCharStreamImplement,cCharStreamInterface,char>
cCharStreamExtends;
///////////////////////////////////////////////////////////////////////
//  Class: cCharStream
//
// Author: $author$
//   Date: 6/3/2011
///////////////////////////////////////////////////////////////////////
class c_INSTANCE_CLASS cCharStream
: public cCharStreamExtends
{
public:
    typedef cCharStreamExtends cExtends;
    ///////////////////////////////////////////////////////////////////////
    //  Constructor: cCharStream
    //
    //       Author: $author$
    //         Date: 6/3/2011
    ///////////////////////////////////////////////////////////////////////
    cCharStream
    (tStreamInterface* delegatedTo=0)
    : cExtends(delegatedTo)
    {
    }
};

#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#else // !defined(CCHARSTREAMT_MEMBERS_ONLY) 
#endif // !defined(CCHARSTREAMT_MEMBERS_ONLY) 

#endif // !defined(_CCHARSTREAM_HPP) || defined(CCHARSTREAMT_MEMBERS_ONLY) 
        

