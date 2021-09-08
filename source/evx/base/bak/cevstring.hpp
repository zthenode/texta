///////////////////////////////////////////////////////////////////////
//   File: cevstring.hpp
//
// Author: $author$
//   Date: 4/4/2007
//
//    $Id$
///////////////////////////////////////////////////////////////////////

#ifndef _CEVSTRING_HPP
#define _CEVSTRING_HPP

#include <string>
#include "cevstringt.hpp"

///////////////////////////////////////////////////////////////////////
//  Class: CEvString
//
// Author: $author$
//   Date: 4/4/2007
///////////////////////////////////////////////////////////////////////
class CEvString
: public ::std::string
{
public:
	typedef ::std::string CExtends;
    typedef CEvString CDerives;

    ///////////////////////////////////////////////////////////////////////
    // Function: Assign
    //
    //    Author: $author$
    //      Date: 4/4/2007
    ///////////////////////////////////////////////////////////////////////
    virtual void Assign
    (const char* chars, int length=-1) 
    {
        if (0 > length)
            assign(chars);
        else assign(chars, length);
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: Append
    //
    //    Author: $author$
    //      Date: 4/4/2007
    ///////////////////////////////////////////////////////////////////////
    virtual void Append
    (const char* chars, int length=-1) 
    {
        if (0 > length)
            append(chars);
        else append(chars, length);
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: Compare
    //
    //    Author: $author$
    //      Date: 4/4/2007
    ///////////////////////////////////////////////////////////////////////
    virtual int Compare
    (const char* tochars, int tolength=-1) 
    {
        int unequal;

        if (0 > tolength)
            unequal = compare(tochars);
        else
        {
            CExtends to;
            to.assign(tochars, tolength);
            unequal = compare(to);
        }
        return unequal;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: Chars
    //
    //    Author: $author$
    //      Date: 4/4/2007
    ///////////////////////////////////////////////////////////////////////
    virtual const char* Chars(int &length) 
    {
        const char* chars = c_str();
        length = (int)((*this).length());
        return chars;
    }
};
#endif // _CEVSTRING_HPP
