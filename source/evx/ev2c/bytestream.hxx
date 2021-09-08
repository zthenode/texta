/**
 **********************************************************************
 * Copyright (c) $year$ $author$
 *
 * This software is provided by the author and contributors ``as is'' 
 * and any express or implied warranties, including, but not limited to, 
 * the implied warranties of merchantability and fitness for a particular 
 * purpose are disclaimed. In no event shall the author or contributors 
 * be liable for any direct, indirect, incidental, special, exemplary, 
 * or consequential damages (including, but not limited to, procurement 
 * of substitute goods or services; loss of use, data, or profits; or 
 * business interruption) however caused and on any theory of liability, 
 * whether in contract, strict liability, or tort (including negligence 
 * or otherwise) arising in any way out of the use of this software, 
 * even if advised of the possibility of such damage.
 *
 *   File: bytestream.hxx
 *
 * Author: $author$
 *   Date: $date$
 **********************************************************************
 */
#ifndef _BYTESTREAM_HXX
#define _BYTESTREAM_HXX

#include "base.hxx"

/**
 **********************************************************************
 *  Class: BYTEStream
 *
 * Author: $author$
 *   Date: $date$
 **********************************************************************
 */
class BYTEStream
: virtual public Base
{
public:
    typedef Base CImplements;
    typedef BYTEStream CDerives;

    /**
     **********************************************************************
     * Function: Read
     *
     *   Author: $author$
     *     Date: $date$
     **********************************************************************
     */
    virtual int Read
    (BYTE* bytes,
     unsigned size) = 0;
    /**
     **********************************************************************
     * Function: Write
     *
     *   Author: $author$
     *     Date: $date$
     **********************************************************************
     */
    virtual int Write
    (const BYTE* bytes,
     int length=-1) = 0;

    /**
     **********************************************************************
     * Function: Getb
     *
     *   Author: $author$
     *     Date: $date$
     **********************************************************************
     */
    virtual int Getb() 
    {
        int b;
        BYTE byte;
        if (0 < (b = Read(&byte, sizeof(byte))))
            b = byte;
        return b;
    }
    /**
     **********************************************************************
     * Function: Putb
     *
     *   Author: $author$
     *     Date: $date$
     **********************************************************************
     */
    virtual int Putb(int b) 
    {
        const BYTE byte = b;
        if (0 < (b = Write(&byte, sizeof(byte))))
            b = byte;
        return b;
    }
};
#endif /* _BYTESTREAM_HXX */
