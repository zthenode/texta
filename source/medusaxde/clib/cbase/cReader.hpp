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
//   File: cReader.hpp
//
// Author: $author$
//   Date: 5/15/2011
///////////////////////////////////////////////////////////////////////
#if !defined(_CREADER_HPP) || defined(CREADERT_MEMBERS_ONLY)
#if !defined(_CREADER_HPP) && !defined(CREADERT_MEMBERS_ONLY)
#define _CREADER_HPP
#endif // !defined(_CREADER_HPP) && !defined(CREADERT_MEMBERS_ONLY) 

#if !defined(CREADERT_MEMBERS_ONLY)
#include "cReaderInterface.hpp"
#include "cInstanceBase.hpp"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

class c_INSTANCE_CLASS cReader;

#undef CDB_CLASS
#define CDB_CLASS "cReaderT"
///////////////////////////////////////////////////////////////////////
//  Class: cReaderT
//
// Author: $author$
//   Date: 5/15/2011
///////////////////////////////////////////////////////////////////////
template
<class TImplement=cReaderImplement,
 class TInterface=cReaderInterface,
 class TWhat=char,
 class TExtend=cInstanceBase>

class c_INSTANCE_CLASS cReaderT
: virtual public TImplement,
  public TExtend
{
public:
    typedef TImplement cImplements;
    typedef TExtend cExtends;

// include cReaderT interface member definitions
//
#define CREADERINTERFACET_MEMBERS_ONLY
#include "cReaderInterface.hpp"
#undef CREADERINTERFACET_MEMBERS_ONLY

    typedef TInterface tReaderInterface;

    tReaderInterface* m_delegated;

    ///////////////////////////////////////////////////////////////////////
    //  Constructor: cReaderT
    //
    //       Author: $author$
    //         Date: 5/15/2011
    ///////////////////////////////////////////////////////////////////////
    cReaderT(tReaderInterface* delegatedTo=0)
    : m_delegated(delegatedTo)
    {
    }
    ///////////////////////////////////////////////////////////////////////
    //  Destructor: ~cReaderT
    //
    //      Author: $author$
    //        Date: 5/15/2011
    ///////////////////////////////////////////////////////////////////////
    virtual ~cReaderT()
    {
    }
#else // !defined(CREADERT_MEMBERS_ONLY) 
#endif // !defined(CREADERT_MEMBERS_ONLY) 

    ///////////////////////////////////////////////////////////////////////
    //  Function: Read
    //
    //    Author: $author$
    //      Date: 5/15/2011
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t Read
    (tWhat* what, size_t size)
#if defined(CREADERT_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CREADERT_MEMBER_FUNCS_INTERFACE) 
    {
        ssize_t count = -e_ERROR_NOT_IMPLEMENTED;
#if !defined(CREADERT_MEMBER_FUNCS_IMPLEMENT)
        if (m_delegated && ((tReaderInterface*)(this) != m_delegated))
            count = m_delegated->Read(what, size);
#else // !defined(CREADERT_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CREADERT_MEMBER_FUNCS_IMPLEMENT) 
        return count;
    }
#endif // defined(CREADERT_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    //  Function: ReadL
    //
    //    Author: $author$
    //      Date: 5/30/2011
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t ReadL
    (tWhat* what,
     ...)
#if defined(CREADERT_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CREADERT_MEMBER_FUNCS_INTERFACE)
    {
        ssize_t count = -e_ERROR_NOT_IMPLEMENTED;
#if !defined(CREADERT_MEMBER_FUNCS_IMPLEMENT)
        va_list va;
        va_start(va, what);
        count = ReadV(what, va);
        va_end(va);
#else // !defined(CREADERT_MEMBER_FUNCS_IMPLEMENT)
#endif // !defined(CREADERT_MEMBER_FUNCS_IMPLEMENT)
        return count;
    }
#endif // defined(CREADERT_MEMBER_FUNCS_INTERFACE)
    ///////////////////////////////////////////////////////////////////////
    //  Function: ReadV
    //
    //    Author: $author$
    //      Date: 5/30/2011
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t ReadV
    (tWhat* what,
     va_list va)
#if defined(CREADERT_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CREADERT_MEMBER_FUNCS_INTERFACE)
    {
        ssize_t count = -e_ERROR_NOT_IMPLEMENTED;
#if !defined(CREADERT_MEMBER_FUNCS_IMPLEMENT)
        ssize_t length = 0;
        for (count = 0; what; count += length)
        {
            if (0 > (length = Read(what, 1)))
                return length;
            what = va_arg(va, tWhat*);
        }
#else // !defined(CREADERT_MEMBER_FUNCS_IMPLEMENT)
#endif // !defined(CREADERT_MEMBER_FUNCS_IMPLEMENT)
        return count;
    }
#endif // defined(CREADERT_MEMBER_FUNCS_INTERFACE)

    ///////////////////////////////////////////////////////////////////////
    //  Function: Fill
    //
    //    Author: $author$
    //      Date: 7/6/2011
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t Fill()
#if defined(CREADERT_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CREADERT_MEMBER_FUNCS_INTERFACE) 
    {
        ssize_t count = 0;
#if !defined(CREADERT_MEMBER_FUNCS_IMPLEMENT)
#else // !defined(CREADERT_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CREADERT_MEMBER_FUNCS_IMPLEMENT) 
        return count;
    }
#endif // defined(CREADERT_MEMBER_FUNCS_INTERFACE) 

#if !defined(CREADERT_MEMBERS_ONLY)
};
#undef CDB_CLASS

///////////////////////////////////////////////////////////////////////
// Typedef: cReaderExtend
//
//  Author: $author$
//    Date: 5/22/2011
///////////////////////////////////////////////////////////////////////
typedef cReaderT<cReaderImplement,cReaderInterface,char>
cReaderExtend;
///////////////////////////////////////////////////////////////////////
//  Class: cReader
//
// Author: $author$
//   Date: 5/22/2011
///////////////////////////////////////////////////////////////////////
class c_INSTANCE_CLASS cReader
: public cReaderExtend
{
public:
    typedef cReaderExtend cExtends;
    ///////////////////////////////////////////////////////////////////////
    //  Constructor: cReader
    //
    //       Author: $author$
    //         Date: 5/22/2011
    ///////////////////////////////////////////////////////////////////////
    cReader(tReaderInterface* delegatedTo=0)
    : cExtends(delegatedTo)
    {
    }
};

#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#else // !defined(CREADERT_MEMBERS_ONLY) 
#endif // !defined(CREADERT_MEMBERS_ONLY) 

#endif // !defined(_CREADER_HPP) || defined(CREADERT_MEMBERS_ONLY) 

