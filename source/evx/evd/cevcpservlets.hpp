///////////////////////////////////////////////////////////////////////
//   File: cevcpservlets.hpp
//
// Author: $author$
//   Date: 4/25/2007
//
//    $Id$
///////////////////////////////////////////////////////////////////////

#ifndef _CEVCPSERVLETS_HPP
#define _CEVCPSERVLETS_HPP

#include <vector>
#include "evcpservlet.hpp"

///////////////////////////////////////////////////////////////////////
//  Class: CEvcpServlets
//
// Author: $author$
//   Date: 4/25/2007
///////////////////////////////////////////////////////////////////////
class CEvcpServlets
: public ::std::vector<EvcpServlet*>
{
public:
    typedef ::std::vector<EvcpServlet*> CExtends;
    typedef CEvcpServlets CDerives;

    ///////////////////////////////////////////////////////////////////////
    // Function: ConnectionInitialize
    //
    //   Author: $author$
    //     Date: 12/6/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError ConnectionInitialize
    (EvcpServletConnection& connection) 
    {
        EvError error = EV_ERROR_NONE;
        EvcpServlet* servlet;
        iterator i;

        for (i = begin(); i != end(); i++)
        {
            if ((servlet = *i))
            if ((error = servlet->ConnectionInitialize(connection)))
            {
                while (i != begin())
                {
                    if ((servlet = *(--i)))
                        servlet->ConnectionFinalize(connection);
                }
                break;
            }
        }
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: ConnectionFinalize
    //
    //   Author: $author$
    //     Date: 12/6/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError ConnectionFinalize
    (EvcpServletConnection& connection) 
    {
        EvError error = EV_ERROR_NONE;
        EvError error2;
        EvcpServlet* servlet;
        iterator i;

        for (i = end(); i != begin();)
        {
            if ((servlet = *(--i)))
            if ((error2 = servlet->ConnectionFinalize(connection)))
                error = EV_ERROR_FAILED;
        }
        return error;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: Clear
    //
    //   Author: $author$
    //     Date: 4/25/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError Clear() 
    {
        EvError error = EV_ERROR_NONE;
        clear();
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: AddServlet
    //
    //   Author: $author$
    //     Date: 4/25/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError AddServlet(EvcpServlet& servlet) 
    {
        EvError error = EV_ERROR_NONE;
        push_back(&servlet);
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: FindServlet
    //
    //   Author: $author$
    //     Date: 4/25/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvcpServlet* FindServlet
    (const char* name, LONG length=-1) const
    {
        EvcpServlet* servlet;
        const_iterator i;
        int unequal;

        for (i = begin(); i != end(); i++)
        {
            if ((servlet = *i))
            if (!(unequal = servlet->CompareName(name, length)))
                return servlet;
        }
        return 0;
    }
};

///////////////////////////////////////////////////////////////////////
//  Typedef: CEvcpServletsIterator
//
//   Author: $author$
//     Date: 7/17/2007
///////////////////////////////////////////////////////////////////////
typedef CEvcpServlets::iterator
CEvcpServletsIterator;

///////////////////////////////////////////////////////////////////////
//  Typedef: const_CEvcpServletsIterator
//
//   Author: $author$
//     Date: 7/17/2007
///////////////////////////////////////////////////////////////////////
typedef CEvcpServlets::const_iterator
const_CEvcpServletsIterator;

#endif // _CEVCPSERVLETS_HPP
