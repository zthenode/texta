///////////////////////////////////////////////////////////////////////
//   File: evhandleattached.cpp
//
// Author: $author$
//   Date: 5/15/2008
///////////////////////////////////////////////////////////////////////

#include "evhandleattached.hpp"

///////////////////////////////////////////////////////////////////////
//  Class: EvHANDLEAttached
//
// Author: $author$
//   Date: 5/15/2008
///////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////
// Function: EvHANDLEAttached::CreateInstance
//
//   Author: $author$
//     Date: 5/15/2008
///////////////////////////////////////////////////////////////////////
EvHANDLEAttached* EvHANDLEAttached::CreateInstance
(EvError& error) 
{
    EvHANDLEAttached* instance = 0;
    error = EV_ERROR_NOT_IMPLEMENTED;
    return instance;
}
///////////////////////////////////////////////////////////////////////
// Function: EvHANDLEAttached::DestroyInstance
//
//   Author: $author$
//     Date: 5/15/2008
///////////////////////////////////////////////////////////////////////
EvError EvHANDLEAttached::DestroyInstance
(EvHANDLEAttached& instance) 
{
    EvError error = EV_ERROR_NOT_IMPLEMENTED;
    return error;
}