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
 *   File: cstringbase.hxx
 *
 * Author: $author$
 *   Date: 11/12/2008
 **********************************************************************
 */
#ifndef _CSTRINGBASE_HXX
#define _CSTRINGBASE_HXX

#include "cbase.hxx"

#define CSTRINGBASE_DEFAULT_SIZE 128

#undef CDB_CLASS
#define CDB_CLASS "cStringBaseT"
/**
 **********************************************************************
 *  Class: cStringBaseT
 *
 * Author: $author$
 *   Date: 11/12/2008
 **********************************************************************
 */
template
<class TChar=CHAR,
 class TSize=TSIZE,
 class TLength=TLENGTH,
 class TEnd=TChar,
 TEnd VEnd=NULL_CHAR,
 TLength VUndefinedLength=UNDEFINED_LENGTH,
 TSize VDefaultSize=CSTRINGBASE_DEFAULT_SIZE,
 class TExtends=cBase>
 
class cStringBaseT
: public TExtends
{
public:
    typedef TExtends cExtends;
    typedef cStringBaseT cDerives;

    bool m_freeBuffer;
    bool m_fixedSize;

    TSize m_size;
    TLength m_length;
    TLength m_tell;

    const TChar* m_readBuffer;
    TChar* m_writeBuffer;
    TChar m_defaultBuffer[VDefaultSize];

    /**
     **********************************************************************
     * Constructor: cStringBaseT
     *
     *      Author: $author$
     *        Date: 11/12/2008
     **********************************************************************
     */
    cStringBaseT
    (const TChar* chars=0,
     TLength length=VUndefinedLength) 
    : m_freeBuffer(false),
      m_fixedSize(false),
      m_size(VDefaultSize),
      m_length(0),
      m_tell(0),
      m_readBuffer(m_defaultBuffer),
      m_writeBuffer(m_defaultBuffer)
    {
        eError error;

        m_defaultBuffer[0] = VEnd;

        if (chars)
        if (0 > (length = append(chars, length)))
            throw (error = -length);
    }
    /**
     **********************************************************************
     * Destructor: ~cStringBaseT
     *
     *     Author: $author$
     *       Date: 11/12/2008
     **********************************************************************
     */
    virtual ~cStringBaseT()
    {
        if (m_writeBuffer)
        if (m_writeBuffer != m_defaultBuffer)
        if (m_freeBuffer)
            delete[] m_writeBuffer;
    }

    /**
     **********************************************************************
     * Function: assign
     *
     *   Author: $author$
     *     Date: 11/12/2008
     **********************************************************************
     */
    virtual TLength assign
    (const TChar* chars, TLength length = VUndefinedLength) 
    {
        TLength count;

        if (0 > (count = clear()))
            return count;

        length = append(chars, length);
        return length;
    }
    /**
     **********************************************************************
     * Function: append
     *
     *   Author: $author$
     *     Date: 11/12/2008
     **********************************************************************
     */
    virtual TLength append
    (const TChar* chars, TLength length = VUndefinedLength) 
    {
        eError error;
        TSize newSize;

        if (length < 0)
            length = _length_of(chars);

        if (length < 1)
            return 0;

        if (!chars)
            return -e_ERROR_NULL_PARAMETER;

        if (!m_writeBuffer)
            return -e_ERROR_NOT_ATTACHED;

        if (m_size <= (newSize = (m_tell+length)))
        if (m_fixedSize)
            return -e_ERROR_FULL;

        else if ((error = _adjust_to_size(_new_size_of(newSize))))
                return -error;

        _copy_to(m_writeBuffer+m_tell, chars, length);

        if ((m_tell += length) > m_length)
        if ((TSize)(m_length = m_tell) < m_size)
            m_writeBuffer[m_tell] = (TChar)(VEnd);

        return length;
    }
    /**
     **********************************************************************
     * Function: clear
     *
     *   Author: $author$
     *     Date: 11/12/2008
     **********************************************************************
     */
    virtual TLength clear()
    {
        TLength length;

        if (!m_writeBuffer)
            return -e_ERROR_NOT_ATTACHED;

        length = m_length;

        if (m_size > (TSize)(m_length = (m_tell = 0)))
            m_writeBuffer[m_tell] = (TChar)(VEnd);

        return length;
    }

    /**
     **********************************************************************
     * Function: compare
     *
     *   Author: $author$
     *     Date: 11/13/2008
     **********************************************************************
     */
    virtual int compare
    (const cDerives& to, 
     TLength toLength=VUndefinedLength) const
    {
        int unequal = 1;
        TLength charsLength;
        const TChar* toChars;

        if ((toChars = to.chars(charsLength)))
        {
            if (toLength > (charsLength))
                toLength = charsLength;

            unequal = compare(toChars, toLength);
        }
        return unequal;
    }
    /**
     **********************************************************************
     * Function: compare
     *
     *   Author: $author$
     *     Date: 11/13/2008
     **********************************************************************
     */
    virtual int compare
    (const TChar* toChars, 
     TLength length=VUndefinedLength) const
    {
        const TChar* thisChars;
        TChar toChar, thisChar;
        TLength lendiff, thisLength;

        if (!(thisChars = chars(thisLength)))
            return toChars?-1:1;

        if (length < 0)
            length = _length_of(toChars);

        if (0 < (lendiff = (length - thisLength)))
        {
            lendiff = -1;
            length = thisLength;
        }
        else if (lendiff)
                lendiff = 1;
 
        if (length > 0)
        do
        {
            if ((thisChar = *(thisChars++)) 
                > (toChar = *(toChars++)))
                return 1;

            if (thisChar < toChar)
                return -1;
        }
        while (--length > 0);

        return lendiff;
    }

    /**
     **********************************************************************
     * Function: chars
     *
     *   Author: $author$
     *     Date: 11/14/2008
     **********************************************************************
     */
    virtual const TChar* chars
    (TLength& charsLength) const
    {
        const TChar* chars = c_str();
        charsLength = length();
        return chars;
    }
    /**
     **********************************************************************
     * Function: c_str
     *
     *   Author: $author$
     *     Date: 11/13/2008
     **********************************************************************
     */
    virtual const TChar* c_str() const
    {
        const TChar* thisChars = m_readBuffer;
        return thisChars;
    }
    /**
     **********************************************************************
     * Function: length
     *
     *   Author: $author$
     *     Date: 11/13/2008
     **********************************************************************
     */
    virtual TLength length() const
    {
        TLength thisLength = m_length;
        return thisLength;
    }

private:

    /**
     **********************************************************************
     * Function: _adjust_to_size
     *
     *   Author: $author$
     *     Date: 11/12/2008
     **********************************************************************
     */
    virtual eError _adjust_to_size(TSize size)
    {
        bool allocBuffer;
        TChar* buffer;

        if (!m_writeBuffer)
            return e_ERROR_NOT_ATTACHED;

        if (size <= m_size)
            return e_ERROR_NONE;

        /* Set m_free_buffer here if it has not already been
         * done to make sure the buffer will be freed upon 
         * destruction.
         */
        if ((allocBuffer = !m_freeBuffer))
            m_freeBuffer = true;

        if (!(buffer = new TChar[size]))
        {
            if (allocBuffer)
                m_freeBuffer = false;

            return e_ERROR_NEW;
        }

        if (m_writeBuffer)
        {
            if (m_length > 0)
                _copy_to(buffer, m_writeBuffer, m_length);

            if (m_writeBuffer != m_defaultBuffer)
                delete[] m_writeBuffer;
        }

        m_writeBuffer = buffer;
        m_readBuffer = buffer;
        m_size = size;
        return e_ERROR_NONE;
    }
    /**
     **********************************************************************
     * Function: _new_size_of
     *
     *   Author: $author$
     *     Date: 11/12/2008
     **********************************************************************
     */
    virtual TSize _new_size_of(TSize size) const
    {
        /* Lets increase the buffer size by default buffer 
         * sized chunks. Note the desired new size is always
         * needed size + 1. The size in chunks is calculated
         * as (new size + (chunk size - 1)) / chunk size.
         * since new size = needed size + 1 then we have
         * chunks = (needed size + chunk size) / chunk size.
         * Finally we need bytes which is chunks * chunk size
         * which can be reduced to 
         * ((needed size / chunk size) + 1) * chunk size
         */
        return ((size/VDefaultSize)+1)*VDefaultSize;
    }
    /**
     **********************************************************************
     * Function: _copy_to
     *
     *   Author: $author$
     *     Date: 11/12/2008
     **********************************************************************
     */
    virtual TLength _copy_to
    (TChar* to, const TChar* from, TSize size)
    {
		TLength length;
        for (length = size; size; --size)
            (*to++) = (*from++);
		return length;
    }
    /**
     **********************************************************************
     * Function: _length_of
     *
     *   Author: $author$
     *     Date: 11/12/2008
     **********************************************************************
     */
    virtual TLength _length_of
    (const TChar* chars) const
    {
        TLength length;
        TChar c;

        for (length = 0; (c = *chars) != (TChar)(VEnd); chars++)
            length++;
        return length;
    }
};
#undef CDB_CLASS

/**
 **********************************************************************
 * Typedef: cStringBase
 *
 *  Author: $author$
 *    Date: 11/12/2008
 **********************************************************************
 */
typedef cStringBaseT<>
cStringBase;

#endif /* _CSTRINGBASE_HXX */
