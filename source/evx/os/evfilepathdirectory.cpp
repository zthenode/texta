///////////////////////////////////////////////////////////////////////
//   File: evfilepathdirectory.cpp
//
// Author: $author$
//   Date: 5/16/2008
///////////////////////////////////////////////////////////////////////

#include "evfilepathdirectory.hpp"

///////////////////////////////////////////////////////////////////////
//  Class: EvFilePathDirectory
//
// Author: $author$
//   Date: 5/16/2008
///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
// Function: EvFilePathDirectory::CreateInstance
//
//   Author: $author$
//     Date: 5/16/2008
///////////////////////////////////////////////////////////////////////
EvFilePathDirectory* EvFilePathDirectory::CreateInstance
(EvError& error) 
{
    EvFilePathDirectory* instance = 0;
    error = EV_ERROR_NOT_IMPLEMENTED;
    return instance;
}
///////////////////////////////////////////////////////////////////////
// Function: EvFilePathDirectory::DestroyInstance
//
//   Author: $author$
//     Date: 5/16/2008
///////////////////////////////////////////////////////////////////////
EvError EvFilePathDirectory::DestroyInstance
(EvFilePathDirectory& instance) 
{
    EvError error = EV_ERROR_NOT_IMPLEMENTED;
    return error;
}
