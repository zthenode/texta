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
//   File: cStream.hpp
//
// Author: $author$
//   Date: 5/21/2011
///////////////////////////////////////////////////////////////////////
#if !defined(_CSTREAM_HPP) || defined(CSTREAMT_MEMBERS_ONLY)
#if !defined(_CSTREAM_HPP) && !defined(CSTREAMT_MEMBERS_ONLY)
#define _CSTREAM_HPP
#endif // !defined(_CSTREAM_HPP) && !defined(CSTREAMT_MEMBERS_ONLY) 

#if !defined(CSTREAMT_MEMBERS_ONLY)
#include "cStreamInterface.hpp"
#include "cInstanceBase.hpp"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

class c_INSTANCE_CLASS cStream;

#undef CDB_CLASS
#define CDB_CLASS "cStreamT"
///////////////////////////////////////////////////////////////////////
//  Class: cStreamT
//
// Author: $author$
//   Date: 5/21/2011
///////////////////////////////////////////////////////////////////////
template
<class TImplement=cStreamImplement,
 class TInterface=cStreamInterface,
 class TWhat=char,
 class TExtend=cInstanceBase>

class c_INSTANCE_CLASS cStreamT
: virtual public TImplement,
  public TExtend
{
public:
    typedef TImplement cImplements;
    typedef TExtend cExtends;

// include cStreamT interface member definitions
//
#define CSTREAMINTERFACET_MEMBERS_ONLY
#include "cStreamInterface.hpp"
#undef CSTREAMINTERFACET_MEMBERS_ONLY

    typedef TInterface tStreamInterface;

    tStreamInterface* m_delegated;

    ///////////////////////////////////////////////////////////////////////
    //  Constructor: cStreamT
    //
    //       Author: $author$
    //         Date: 5/21/2011
    ///////////////////////////////////////////////////////////////////////
    cStreamT
    (tStreamInterface* delegatedTo=0)
    : m_delegated(delegatedTo)
    {
    }
    ///////////////////////////////////////////////////////////////////////
    //  Destructor: ~cStreamT
    //
    //      Author: $author$
    //        Date: 5/21/2011
    ///////////////////////////////////////////////////////////////////////
    virtual ~cStreamT()
    {
    }
#else // !defined(CSTREAMT_MEMBERS_ONLY) 
#endif // !defined(CSTREAMT_MEMBERS_ONLY) 

    ///////////////////////////////////////////////////////////////////////
    //  Function: ReadL
    //
    //    Author: $author$
    //      Date: 6/3/2011
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t ReadL
    (tWhat* what,
     ...)
#if defined(CSTREAMT_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CSTREAMT_MEMBER_FUNCS_INTERFACE) 
    {
        ssize_t count = -e_ERROR_NOT_IMPLEMENTED;
#if !defined(CSTREAMT_MEMBER_FUNCS_IMPLEMENT)
        va_list va;
        va_start(va, what);
        count = ReadV(what, va);
        va_end(va);
#else // !defined(CSTREAMT_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CSTREAMT_MEMBER_FUNCS_IMPLEMENT) 
        return count;
    }
#endif // defined(CSTREAMT_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    //  Function: ReadV
    //
    //    Author: $author$
    //      Date: 6/3/2011
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t ReadV
    (tWhat* what,
     va_list va)
#if defined(CSTREAMT_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CSTREAMT_MEMBER_FUNCS_INTERFACE) 
    {
        ssize_t count = -e_ERROR_NOT_IMPLEMENTED;
#if !defined(CSTREAMT_MEMBER_FUNCS_IMPLEMENT)
        ssize_t length = 0;
        for (count = 0; what; count += length)
        {
            if (0 > (length = Read(what, 1)))
                return length;
            what = va_arg(va, tWhat*);
        }
#else // !defined(CSTREAMT_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CSTREAMT_MEMBER_FUNCS_IMPLEMENT) 
        return count;
    }
#endif // defined(CSTREAMT_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    //  Function: Read
    //
    //    Author: $author$
    //      Date: 5/21/2011
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t Read
    (tWhat* what,
     size_t size)
#if defined(CSTREAMT_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CSTREAMT_MEMBER_FUNCS_INTERFACE) 
    {
        ssize_t count = -e_ERROR_NOT_IMPLEMENTED;
#if !defined(CSTREAMT_MEMBER_FUNCS_IMPLEMENT)
        if ((m_delegated) && ((tStreamInterface*)(this) != m_delegated))
            count = m_delegated->Read(what, size);
#else // !defined(CSTREAMT_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CSTREAMT_MEMBER_FUNCS_IMPLEMENT) 
        return count;
    }
#endif // defined(CSTREAMT_MEMBER_FUNCS_INTERFACE) 

    ///////////////////////////////////////////////////////////////////////
    //  Function: WriteL
    //
    //    Author: $author$
    //      Date: 6/2/2011
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t WriteL
    (const tWhat* what,
     ...)
#if defined(CSTREAMT_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CSTREAMT_MEMBER_FUNCS_INTERFACE) 
    {
        ssize_t count = -e_ERROR_NOT_IMPLEMENTED;
#if !defined(CSTREAMT_MEMBER_FUNCS_IMPLEMENT)
        va_list va;
        va_start(va, what);
        count = WriteV(what, va);
        va_end(va);
#else // !defined(CSTREAMT_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CSTREAMT_MEMBER_FUNCS_IMPLEMENT) 
        return count;
    }
#endif // defined(CSTREAMT_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    //  Function: WriteV
    //
    //    Author: $author$
    //      Date: 6/2/2011
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t WriteV
    (const tWhat* what,
     va_list va)
#if defined(CSTREAMT_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CSTREAMT_MEMBER_FUNCS_INTERFACE) 
    {
        ssize_t count = -e_ERROR_NOT_IMPLEMENTED;
#if !defined(CSTREAMT_MEMBER_FUNCS_IMPLEMENT)
        ssize_t length = 0;
        for (count = 0; what; count += length)
        {
            if (0 > (length = Write(what)))
                return length;
            what = va_arg(va, const tWhat*);
        }
#else // !defined(CSTREAMT_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CSTREAMT_MEMBER_FUNCS_IMPLEMENT) 
        return count;
    }
#endif // defined(CSTREAMT_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    //  Function: Write
    //
    //    Author: $author$
    //      Date: 5/21/2011
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t Write
    (const tWhat* what,
     ssize_t length=-1)
#if defined(CSTREAMT_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CSTREAMT_MEMBER_FUNCS_INTERFACE) 
    {
        ssize_t count = -e_ERROR_NOT_IMPLEMENTED;
#if !defined(CSTREAMT_MEMBER_FUNCS_IMPLEMENT)
        if ((m_delegated) && ((tStreamInterface*)(this) != m_delegated))
            count = m_delegated->Write(what, length);
#else // !defined(CSTREAMT_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CSTREAMT_MEMBER_FUNCS_IMPLEMENT) 
        return count;
    }
#endif // defined(CSTREAMT_MEMBER_FUNCS_INTERFACE) 

#if !defined(CSTREAMT_MEMBERS_ONLY)
};
#undef CDB_CLASS

///////////////////////////////////////////////////////////////////////
// Typedef: cStreamExtend
//
//  Author: $author$
//    Date: 5/22/2011
///////////////////////////////////////////////////////////////////////
typedef cStreamT
<cStreamImplement,cStreamInterface,char>
cStreamExtend;
///////////////////////////////////////////////////////////////////////
//  Class: cStream
//
// Author: $author$
//   Date: 5/22/2011
///////////////////////////////////////////////////////////////////////
class c_INSTANCE_CLASS cStream
: public cStreamExtend
{
public:
    typedef cStreamExtend cExtends;
    ///////////////////////////////////////////////////////////////////////
    //  Constructor: cStream
    //
    //       Author: $author$
    //         Date: 5/22/2011
    ///////////////////////////////////////////////////////////////////////
    cStream
    (tStreamInterface* delegatedTo=0)
    : cExtends(delegatedTo)
    {
    }
};

#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#else // !defined(CSTREAMT_MEMBERS_ONLY) 
#endif // !defined(CSTREAMT_MEMBERS_ONLY) 

#endif // !defined(_CSTREAM_HPP) || defined(CSTREAMT_MEMBERS_ONLY) 
        

