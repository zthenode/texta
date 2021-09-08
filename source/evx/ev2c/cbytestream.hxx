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
 *   File: cbytestream.hxx
 *
 * Author: $author$
 *   Date: $date$
 **********************************************************************
 */
#ifndef __CBYTESTREAM_HXX
#define __CBYTESTREAM_HXX

#include "bytestream.hxx"
#include "cbase.hxx"

/**
 **********************************************************************
 *  Class: CBYTEStream
 *
 * Author: $author$
 *   Date: $date$
 **********************************************************************
 */
class CBYTEStream
: virtual public BYTEStream,
  public CBase
{
public:
    typedef BYTEStream CImplements;
    typedef CBase CExtends;
    typedef CBYTEStream CDerives;

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
     unsigned size) 
    {
        int count = -_ERROR_NOT_IMPLEMENTED;
        return count;
    }
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
     int length=-1) 
    {
        int count = -_ERROR_NOT_IMPLEMENTED;
        return count;
    }
};
#endif /* __CBYTESTREAM_HXX */
