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
//   File: cListItem.hpp
//
// Author: $author$
//   Date: 6/5/2011
///////////////////////////////////////////////////////////////////////
#if !defined(_CLISTITEM_HPP) || defined(CLISTITEMT_MEMBERS_ONLY)
#if !defined(_CLISTITEM_HPP) && !defined(CLISTITEMT_MEMBERS_ONLY)
#define _CLISTITEM_HPP
#endif // !defined(_CLISTITEM_HPP) && !defined(CLISTITEMT_MEMBERS_ONLY) 

#if !defined(CLISTITEMT_MEMBERS_ONLY)
#include "cImplementBase.hpp"
#include "cInstanceBase.hpp"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

#undef CDB_CLASS
#define CDB_CLASS "cListItemT"
///////////////////////////////////////////////////////////////////////
//  Class: cListItemT
//
// Author: $author$
//   Date: 6/5/2011
///////////////////////////////////////////////////////////////////////
template
<class TDerive,
 class TImplement=cImplementBase,
 class TExtend=cInstanceBase>

class c_INSTANCE_CLASS cListItemT
: virtual public TImplement,
  public TExtend
{
public:
    typedef TImplement cImplements;
    typedef TExtend cExtends;
    typedef TDerive tDerive;

    tDerive* m_prevItem;
    tDerive* m_nextItem;

    ///////////////////////////////////////////////////////////////////////
    //  Constructor: cListItemT
    //
    //       Author: $author$
    //         Date: 6/5/2011
    ///////////////////////////////////////////////////////////////////////
    cListItemT
    (tDerive* prevItem=0,
     tDerive* nextItem=0)
    : m_prevItem(prevItem), 
      m_nextItem(nextItem)
    {
    }
    ///////////////////////////////////////////////////////////////////////
    //  Destructor: ~cListItemT
    //
    //      Author: $author$
    //        Date: 6/5/2011
    ///////////////////////////////////////////////////////////////////////
    virtual ~cListItemT()
    {
    }
#else // !defined(CLISTITEMT_MEMBERS_ONLY) 
#endif // !defined(CLISTITEMT_MEMBERS_ONLY) 

    ///////////////////////////////////////////////////////////////////////
    //  Function: SetPrevItem
    //
    //    Author: $author$
    //      Date: 6/5/2011
    ///////////////////////////////////////////////////////////////////////
    virtual tDerive* SetPrevItem
    (tDerive* toItem)
#if defined(CLISTITEMT_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CLISTITEMT_MEMBER_FUNCS_INTERFACE) 
    {
        tDerive* item = 0;
#if !defined(CLISTITEMT_MEMBER_FUNCS_IMPLEMENT)
        item = (m_prevItem = toItem);
#else // !defined(CLISTITEMT_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CLISTITEMT_MEMBER_FUNCS_IMPLEMENT) 
        return item;
    }
#endif // defined(CLISTITEMT_MEMBER_FUNCS_INTERFACE) 

    ///////////////////////////////////////////////////////////////////////
    //  Function: GetPrevItem
    //
    //    Author: $author$
    //      Date: 6/5/2011
    ///////////////////////////////////////////////////////////////////////
    virtual tDerive* GetPrevItem() const
#if defined(CLISTITEMT_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CLISTITEMT_MEMBER_FUNCS_INTERFACE) 
    {
        tDerive* item = 0;
#if !defined(CLISTITEMT_MEMBER_FUNCS_IMPLEMENT)
        item = (m_prevItem);
#else // !defined(CLISTITEMT_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CLISTITEMT_MEMBER_FUNCS_IMPLEMENT) 
        return item;
    }
#endif // defined(CLISTITEMT_MEMBER_FUNCS_INTERFACE) 

    ///////////////////////////////////////////////////////////////////////
    //  Function: SetNextItem
    //
    //    Author: $author$
    //      Date: 6/5/2011
    ///////////////////////////////////////////////////////////////////////
    virtual tDerive* SetNextItem
    (tDerive* toItem)
#if defined(CLISTITEMT_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CLISTITEMT_MEMBER_FUNCS_INTERFACE) 
    {
        tDerive* item = 0;
#if !defined(CLISTITEMT_MEMBER_FUNCS_IMPLEMENT)
        item = (m_nextItem = toItem);
#else // !defined(CLISTITEMT_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CLISTITEMT_MEMBER_FUNCS_IMPLEMENT) 
        return item;
    }
#endif // defined(CLISTITEMT_MEMBER_FUNCS_INTERFACE) 

    ///////////////////////////////////////////////////////////////////////
    //  Function: GetNextItem
    //
    //    Author: $author$
    //      Date: 6/5/2011
    ///////////////////////////////////////////////////////////////////////
    virtual tDerive* GetNextItem() const
#if defined(CLISTITEMT_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CLISTITEMT_MEMBER_FUNCS_INTERFACE) 
    {
        tDerive* item = 0;
#if !defined(CLISTITEMT_MEMBER_FUNCS_IMPLEMENT)
        item = (m_nextItem);
#else // !defined(CLISTITEMT_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CLISTITEMT_MEMBER_FUNCS_IMPLEMENT) 
        return item;
    }
#endif // defined(CLISTITEMT_MEMBER_FUNCS_INTERFACE) 

#if !defined(CLISTITEMT_MEMBERS_ONLY)
};
#undef CDB_CLASS


#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#else // !defined(CLISTITEMT_MEMBERS_ONLY) 
#endif // !defined(CLISTITEMT_MEMBERS_ONLY) 

#endif // !defined(_CLISTITEM_HPP) || defined(CLISTITEMT_MEMBERS_ONLY) 
        

