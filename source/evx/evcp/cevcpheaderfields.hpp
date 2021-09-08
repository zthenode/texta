///////////////////////////////////////////////////////////////////////
//   File: cevcpheaderfields.hpp
//
// Author: $author$
//   Date: 5/16/2007
//
//    $Id$
///////////////////////////////////////////////////////////////////////

#ifndef _CEVCPHEADERFIELDS_HPP
#define _CEVCPHEADERFIELDS_HPP

#include <vector>
#include "evcpheaderfields.hpp"
#include "cevcpheaderfield.hpp"

///////////////////////////////////////////////////////////////////////
//  Class: CEvcpHeaderFields
//
// Author: $author$
//   Date: 4/18/2007
///////////////////////////////////////////////////////////////////////
class CEvcpHeaderFields
: public ::std::vector<CEvcpHeaderField*>
{
public:
    typedef ::std::vector<CEvcpHeaderField*> CExtends;
    typedef CEvcpHeaderFields CDerives;

    ///////////////////////////////////////////////////////////////////////
    // Function: AddField
    //
    //   Author: $author$
    //     Date: 5/17/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError AddField
    (CEvcpHeaderField& field) 
    {
        EvError error = EV_ERROR_NONE;
        push_back(&field);
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: RemoveField
    //
    //   Author: $author$
    //     Date: 5/17/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError RemoveField
    (EvcpHeaderField& field);
    ///////////////////////////////////////////////////////////////////////
    // Function: FindField
    //
    //   Author: $author$
    //     Date: 4/30/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvcpHeaderField* FindField
    (const_CEvcpHeaderFieldsIterator& iterator,
     const char* name, int length=-1) const; 
};

///////////////////////////////////////////////////////////////////////
//  Class: CEvcpHeaderFieldsIterator
//
// Author: $author$
//   Date: 5/16/2007
///////////////////////////////////////////////////////////////////////
class CEvcpHeaderFieldsIterator
: public CEvcpHeaderFields::iterator
{
public:
    typedef CEvcpHeaderFields::iterator CExtends;
    typedef CEvcpHeaderFieldsIterator CDerives;
    ///////////////////////////////////////////////////////////////////////
    // Operator: =
    //
    //   Author: $author$
    //     Date: 5/16/2007
    ///////////////////////////////////////////////////////////////////////
    virtual CExtends& operator = (const CExtends& to)
    {
        return (CExtends&)(*this) = to;
    }
    ///////////////////////////////////////////////////////////////////////
    // Operator: ==
    //
    //   Author: $author$
    //     Date: 5/16/2007
    ///////////////////////////////////////////////////////////////////////
    virtual bool operator == (const CExtends& to) const
    {
        return (const CExtends&)(*this) == to;
    }
    ///////////////////////////////////////////////////////////////////////
    // Operator: !=
    //
    //   Author: $author$
    //     Date: 5/16/2007
    ///////////////////////////////////////////////////////////////////////
    virtual bool operator != (const CExtends& to) const
    {
        return (const CExtends&)(*this) != to;
    }
};

///////////////////////////////////////////////////////////////////////
//  Class: const_CEvcpHeaderFieldsIterator
//
// Author: $author$
//   Date: 5/16/2007
///////////////////////////////////////////////////////////////////////
class const_CEvcpHeaderFieldsIterator
: public CEvcpHeaderFields::const_iterator
{
public:
    typedef CEvcpHeaderFields::const_iterator CExtends;
    typedef const_CEvcpHeaderFieldsIterator CDerives;
    ///////////////////////////////////////////////////////////////////////
    // Operator: =
    //
    //   Author: $author$
    //     Date: 5/16/2007
    ///////////////////////////////////////////////////////////////////////
    virtual CExtends& operator = (const CExtends& to)
    {
        return (CExtends&)(*this) = to;
    }
    ///////////////////////////////////////////////////////////////////////
    // Operator: ==
    //
    //   Author: $author$
    //     Date: 5/16/2007
    ///////////////////////////////////////////////////////////////////////
    virtual bool operator == (const CExtends& to) const
    {
        return (const CExtends&)(*this) == to;
    }
    ///////////////////////////////////////////////////////////////////////
    // Operator: !=
    //
    //   Author: $author$
    //     Date: 5/16/2007
    ///////////////////////////////////////////////////////////////////////
    virtual bool operator != (const CExtends& to) const
    {
        return (const CExtends&)(*this) != to;
    }
};

#endif // _CEVCPHEADERFIELDS_HPP
