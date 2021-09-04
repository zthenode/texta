/**
 **********************************************************************
 * Copyright (c) 1988-2008 $organization$
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
 *   File: cxercesbininputstream.hxx
 *
 * Author: $author$
 *   Date: 3/14/2008
 **********************************************************************
 */
#ifndef _CXERCESBININPUTSTREAM_HXX
#define _CXERCESBININPUTSTREAM_HXX

#include <util/BinInputStream.hpp>

#include "nsxerces.hxx"
#include "creaderinterface.hxx"

/**
 **********************************************************************
 *  Class: cXercesBinInputStream
 *
 * Author: $author$
 *   Date: 3/14/2008
 **********************************************************************
 */
class cXercesBinInputStream
: public nsXerces::BinInputStream
{
public:
    typedef nsXerces::BinInputStream cExtends;
    typedef cXercesBinInputStream cDerives;

    cCharReaderInterface& m_reader;
    unsigned int m_curPos;

    /**
     **********************************************************************
     * Constructor: cXercesBinInputStream
     *
     *      Author: $author$
     *        Date: 3/14/2008
     **********************************************************************
     */
    cXercesBinInputStream
    (cCharReaderInterface& reader) 
    : m_reader(reader),
      m_curPos(0)
    {
    }
    /**
     **********************************************************************
     * Destructor: cXercesBinInputStream
     *
     *     Author: $author$
     *       Date: 3/14/2008
     **********************************************************************
     */
    virtual ~cXercesBinInputStream()
    {
    }
    /**
     **********************************************************************
     * Function: readBytes
     *
     *   Author: $author$
     *     Date: 3/14/2008
     **********************************************************************
     */
    virtual unsigned int readBytes
    (XMLByte *const toFill, const unsigned int maxToRead) 
    {
		char* chars = (char*)(toFill);
		TSIZE size = (TSIZE)(maxToRead);
        unsigned int count = 0;
        TLENGTH length;
        if (0 <= (length = m_reader.Read(chars, size)))
            m_curPos += (count = (unsigned int)(length));
        return count;
    }
    /**
     **********************************************************************
     * Function: resetPos
     *
     *   Author: $author$
     *     Date: 3/14/2008
     **********************************************************************
     */
    virtual unsigned int resetPos(unsigned int curPos=0)
    {
        unsigned int oldPos = m_curPos;
        m_curPos = curPos;
        return oldPos;
    }
    /**
     **********************************************************************
     * Function: curPos
     *
     *   Author: $author$
     *     Date: 3/14/2008
     **********************************************************************
     */
    virtual unsigned int curPos() const 
    {
        return m_curPos;
    }
};
#endif /* _CXERCESBININPUTSTREAM_HXX */
