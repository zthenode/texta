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
 *   File: cpseudorandombytestream.hxx
 *
 * Author: $author$
 *   Date: $date$
 **********************************************************************
 */
#ifndef _CPSEUDORANDOMBYTESTREAM_HXX
#define _CPSEUDORANDOMBYTESTREAM_HXX

#include <time.h>
#include <stdlib.h>
#include "cbytestream.hxx"

/**
 **********************************************************************
 *  Class: CPseudoRandomBYTEStream
 *
 * Author: $author$
 *   Date: $date$
 **********************************************************************
 */
class CPseudoRandomBYTEStream
: public CBYTEStream
{
public:
    typedef CBYTEStream CExtends;
    typedef CPseudoRandomBYTEStream CDerives;

    unsigned m_rand;
    int m_avail;

    /**
     **********************************************************************
     * Constructor: CPseudoRandomBYTEStream
     *
     *      Author: $author$
     *        Date: $date$
     **********************************************************************
     */
    CPseudoRandomBYTEStream() 
    : m_rand(0),
      m_avail(0)
    {
    }
    /**
     **********************************************************************
     * Destructor: CPseudoRandomBYTEStream
     *
     *     Author: $author$
     *       Date: $date$
     **********************************************************************
     */
    virtual ~CPseudoRandomBYTEStream()
    {
    }

    /**
     **********************************************************************
     * Function: Seed
     *
     *   Author: $author$
     *     Date: $date$
     **********************************************************************
     */
    virtual void Seed(time_t t) 
    {
        srand((int)t);
    }

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
        int i, j, count, length;

        if (1 > size)
            return size;

        length = 0;

        while (length < (int)(size))
        {
            if (1 > m_avail)
            {
                m_rand = (unsigned)(rand());
                m_avail = sizeof(m_rand);
            }

            if ((count = size-length) > m_avail)
                count = m_avail;

            for (j=0,i=0; i<count; i++)
            {
                if ((bytes[length+j] = (m_rand & 255)))
                    j++;
                m_rand >>= 8;
            }

            length += j;
            m_avail -= count;
        }
        return length;
    }
};
#endif /* _CPSEUDORANDOMBYTESTREAM_HXX */
