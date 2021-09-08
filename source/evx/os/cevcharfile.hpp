///////////////////////////////////////////////////////////////////////
//   File: cevcharfile.hpp
//
// Author: $author$
//   Date: 5/17/2007
//
//    $Id$
///////////////////////////////////////////////////////////////////////

#ifndef _CEVCHARFILE_HPP
#define _CEVCHARFILE_HPP

#include "cevfile.hpp"
#include "cevcharstream.hpp"
#include "evcharreader.hpp"
#include "evcharwriter.hpp"

///////////////////////////////////////////////////////////////////////
// Typedef: CEvCharFileAttached
//
//  Author: $author$
//    Date: 7/11/2007
///////////////////////////////////////////////////////////////////////
typedef CEvAttached
<FILE*, INVALID_FILE_T, INVALID_FILE,
 EvFileAttached, CEvCharStream> 
CEvCharFileAttached;

///////////////////////////////////////////////////////////////////////
//  Class: CEvCharFile
//
// Author: $author$
//   Date: 5/17/2007
///////////////////////////////////////////////////////////////////////
class CEvCharFile
: public CEvFile
  <char, ULONG, LONG, 
   EvCharReader, EvCharWriter,
   EvFileAttached, CEvCharFileAttached>
{
public:
    typedef CEvFile
    <char, ULONG, LONG, 
     EvCharReader, EvCharWriter,
     EvFileAttached, CEvCharFileAttached> CExtends;
    typedef CEvCharFile CDerives;

    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvCharFile
    //
    //       Author: $author$
    //         Date: 10/2/2007
    ///////////////////////////////////////////////////////////////////////
    CEvCharFile
    (const char* filename=0,
     const char* mode=EVFILE_MODE_READ) 
    {
        EvError error;
        if (filename)
        if ((error = Open(filename, mode)))
            throw(error);
    }
    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvCharFile
    //
    //       Author: $author$
    //         Date: 10/2/2007
    ///////////////////////////////////////////////////////////////////////
    CEvCharFile
    (FILE* attached) 
    {
        EvError error;
        if (attached)
        if ((error = Attach(attached)))
            throw(error);
    }
};
#endif // _CEVCHARFILE_HPP
