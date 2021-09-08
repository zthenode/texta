///////////////////////////////////////////////////////////////////////
//   File: evcontrolledentrytype.hpp
//
// Author: $author$
//   Date: 3/11/2008
///////////////////////////////////////////////////////////////////////
#ifndef _EVCONTROLLEDENTRYTYPE_HPP
#define _EVCONTROLLEDENTRYTYPE_HPP

#include "evplatform.h"

///////////////////////////////////////////////////////////////////////
//   Enum: EvControlledEntryType
//
// Author: $author$
//   Date: 3/11/2008
///////////////////////////////////////////////////////////////////////
typedef int EvControlledEntryType;
enum
{
    EV_CONTROLLED_ENTRY_TYPE_FIRST,

    EV_CONTROLLED_ENTRY_TYPE_FILE,
    EV_CONTROLLED_ENTRY_TYPE_FOLDER,
    EV_CONTROLLED_ENTRY_TYPE_LINK,

    EV_CONTROLLED_ENTRY_TYPE_NEXT,
    EV_CONTROLLED_ENTRY_TYPE_LAST = EV_CONTROLLED_ENTRY_TYPE_NEXT-1,
    EV_CONTROLLED_ENTRY_TYPE_COUNT = EV_CONTROLLED_ENTRY_TYPE_LAST-EV_CONTROLLED_ENTRY_TYPE_FIRST+1
};

#define EV_CONTROLLED_ENTRY_TYPE_NAME_FILE "FILE"
#define EV_CONTROLLED_ENTRY_TYPE_NAME_FOLDER "FOLDER"
#define EV_CONTROLLED_ENTRY_TYPE_NAME_LINK "LINK"

extern const char* evControlledEntryTypeName[EV_CONTROLLED_ENTRY_TYPE_COUNT];

#endif // _EVCONTROLLEDENTRYTYPE_HPP 
