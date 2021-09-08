///////////////////////////////////////////////////////////////////////
//   File: cevreaderwriter.hpp
//
// Author: $author$
//   Date: 4/19/2007
//
//    $Id$
///////////////////////////////////////////////////////////////////////

#ifndef _CEVREADERWRITER_HPP
#define _CEVREADERWRITER_HPP

#include "evreader.hpp"
#include "cevwriter.hpp"

///////////////////////////////////////////////////////////////////////
//  Class: CEvReaderWriter
//
// Author: $author$
//   Date: 4/19/2007
///////////////////////////////////////////////////////////////////////
template
<class TChar=CHAR,
 class TSize=ULONG,
 class TLength=LONG,
 class TReader=EvReader<TChar, TSize, TLength>,
 class TWriter=EvWriter<TChar, TSize, TLength>,
 class TExtends=CEvWriter<TChar, TSize, TLength, TWriter>,
 class TImplements=EvBase>

class CEvReaderWriter
: virtual public TImplements,
  public TExtends
{
public:
    typedef TImplements CImplements;
    typedef TExtends CExtends;
    typedef CEvReaderWriter CDerives;

    ///////////////////////////////////////////////////////////////////////
    // Function: WriteReader
    //
    //   Author: $author$
    //     Date: 4/19/2007
    ///////////////////////////////////////////////////////////////////////
    virtual TLength WriteReader
    (TReader& reader, TLength length=-1) 
    {
        TLength count = -EV_ERROR_FAILED;
        TLength read;
        TLength written;
        TChar c;

        for (count = 0; (0 > length) || (count < length); count++)
        {
            if (0 < (read = reader.Read(&c, 1)))
            {
                if (0 < (written = this->Write(&c, 1)))
                    continue;
                else count = -EV_ERROR_WRITE;
            }
            else if (0 > read)
                    count = -EV_ERROR_READ;
            break;
        }
        return count;
    }
};
#endif // _CEVREADERWRITER_HPP
