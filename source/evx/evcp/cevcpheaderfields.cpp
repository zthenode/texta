///////////////////////////////////////////////////////////////////////
//   File: cevcpheaderfields.cpp
//
// Author: $author$
//   Date: 5/16/2007
//
//    $Id$
///////////////////////////////////////////////////////////////////////

#include "cevcpheaderfields.hpp"

///////////////////////////////////////////////////////////////////////
//  Class: CEvcpHeaderFields
//
// Author: $author$
//   Date: 5/16/2007
///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
// Function: CEvcpHeaderFields::RemoveField
//
//   Author: $author$
//     Date: 5/17/2007
///////////////////////////////////////////////////////////////////////
EvError CEvcpHeaderFields::RemoveField
(EvcpHeaderField& field) 
{
    CEvcpHeaderFieldsIterator iterator;

    for (iterator=begin(); iterator != end(); iterator++)
    {
        if (&field == *iterator)
        {
            erase(iterator);
            return EV_ERROR_NONE;
        }
    }
    return EV_ERROR_FAILED;
}
///////////////////////////////////////////////////////////////////////
// Function: CEvcpHeaderFields::FindField
//
//   Author: $author$
//     Date: 5/16/2007
///////////////////////////////////////////////////////////////////////
EvcpHeaderField* CEvcpHeaderFields::FindField
(const_CEvcpHeaderFieldsIterator& iterator,
 const char* name, int length) const
{
    EvcpHeaderField* field;
    int unequal;

    for (iterator = begin(); iterator != end(); iterator++)
    {
        if ((field = *iterator))
        if (!(unequal = field->CompareFieldName(name, length)))
            return field;
    }
    return 0;
}
