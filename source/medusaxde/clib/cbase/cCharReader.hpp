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
//   File: cCharReader.hpp
//
// Author: $author$
//   Date: 5/18/2011
///////////////////////////////////////////////////////////////////////
#if !defined(_CCHARREADER_HPP) || defined(CCHARREADERT_MEMBERS_ONLY)
#if !defined(_CCHARREADER_HPP) && !defined(CCHARREADERT_MEMBERS_ONLY)
#define _CCHARREADER_HPP
#endif // !defined(_CCHARREADER_HPP) && !defined(CCHARREADERT_MEMBERS_ONLY) 

#if !defined(CCHARREADERT_MEMBERS_ONLY)
#include "cCharReaderInterface.hpp"
#include "cReader.hpp"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

class c_INSTANCE_CLASS cCharReader;

#undef CDB_CLASS
#define CDB_CLASS "cCharReaderT"
///////////////////////////////////////////////////////////////////////
//  Class: cCharReaderT
//
// Author: $author$
//   Date: 5/18/2011
///////////////////////////////////////////////////////////////////////
template
<class TExtend=cReader,
 class TImplement=cCharReaderImplement,
 class TInterface=cCharReaderInterface,
 class TWhat=char>

class c_INSTANCE_CLASS cCharReaderT
: virtual public TImplement,
  public TExtend
{
public:
    typedef TImplement cImplements;
    typedef TExtend cExtends;
    typedef TInterface tCharReaderInterface;

// include cCharReaderT interface member definitions
//
#define CCHARREADERINTERFACET_MEMBERS_ONLY
#include "cCharReaderInterface.hpp"
#undef CCHARREADERINTERFACET_MEMBERS_ONLY

    tCharReaderInterface* m_delegated;

    ///////////////////////////////////////////////////////////////////////
    //  Constructor: cCharReaderT
    //
    //       Author: $author$
    //         Date: 5/18/2011
    ///////////////////////////////////////////////////////////////////////
    cCharReaderT
    (tCharReaderInterface* delegatedTo=0)
    : cExtends(delegatedTo), 
      m_delegated(delegatedTo)
    {
    }
    ///////////////////////////////////////////////////////////////////////
    //  Destructor: ~cCharReaderT
    //
    //      Author: $author$
    //        Date: 5/18/2011
    ///////////////////////////////////////////////////////////////////////
    virtual ~cCharReaderT()
    {
    }
#else // !defined(CCHARREADERT_MEMBERS_ONLY) 
#endif // !defined(CCHARREADERT_MEMBERS_ONLY) 

    ///////////////////////////////////////////////////////////////////////
    //  Function: ReadFormatted
    //
    //    Author: $author$
    //      Date: 5/30/2011
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t ReadFormatted
    (const char_t* format,
     ...)
#if defined(CCHARREADERT_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CCHARREADERT_MEMBER_FUNCS_INTERFACE)
    {
        ssize_t count = -e_ERROR_NOT_IMPLEMENTED;
#if !defined(CCHARREADERT_MEMBER_FUNCS_IMPLEMENT)
        va_list va;
        va_start(va, format);
        count = ReadFormattedV(format, va);
        va_end(va);
#else // !defined(CCHARREADERT_MEMBER_FUNCS_IMPLEMENT)
#endif // !defined(CCHARREADERT_MEMBER_FUNCS_IMPLEMENT)
        return count;
    }
#endif // defined(CCHARREADERT_MEMBER_FUNCS_INTERFACE)
    ///////////////////////////////////////////////////////////////////////
    //  Function: ReadFormattedV
    //
    //    Author: $author$
    //      Date: 5/30/2011
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t ReadFormattedV
    (const char_t* format,
     va_list va)
#if defined(CCHARREADERT_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CCHARREADERT_MEMBER_FUNCS_INTERFACE)
    {
        ssize_t count = -e_ERROR_NOT_IMPLEMENTED;
#if !defined(CCHARREADERT_MEMBER_FUNCS_IMPLEMENT)
#else // !defined(CCHARREADERT_MEMBER_FUNCS_IMPLEMENT)
#endif // !defined(CCHARREADERT_MEMBER_FUNCS_IMPLEMENT)
        return count;
    }
#endif // defined(CCHARREADERT_MEMBER_FUNCS_INTERFACE)

#if !defined(CCHARREADERT_MEMBERS_ONLY)
};
#undef CDB_CLASS

///////////////////////////////////////////////////////////////////////
// Typedef: cCharReaderExtend
//
//  Author: $author$
//    Date: 5/23/2011
///////////////////////////////////////////////////////////////////////
typedef cCharReaderT
<cReader,cCharReaderImplement,cCharReaderInterface,char>
cCharReaderExtend;
///////////////////////////////////////////////////////////////////////
//  Class: cCharReader
//
// Author: $author$
//   Date: 5/23/2011
///////////////////////////////////////////////////////////////////////
class c_INSTANCE_CLASS cCharReader
: public cCharReaderExtend
{
public:
    typedef cCharReaderExtend cExtends;
    ///////////////////////////////////////////////////////////////////////
    //  Constructor: cCharReader
    //
    //       Author: $author$
    //         Date: 5/23/2011
    ///////////////////////////////////////////////////////////////////////
    cCharReader
    (tCharReaderInterface* delegatedTo=0)
    : cExtends(delegatedTo)
    {
    }
};

#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#else // !defined(CCHARREADERT_MEMBERS_ONLY) 
#endif // !defined(CCHARREADERT_MEMBERS_ONLY) 

#endif // !defined(_CCHARREADER_HPP) || defined(CCHARREADERT_MEMBERS_ONLY) 
        

