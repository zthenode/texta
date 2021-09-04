/**
 **********************************************************************
 * Copyright (c) 1988-2007 $organization$
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
 *   File: cbuffer.hxx
 *
 * Author: $author$
 *   Date: 2/15/2007
 *
 *    $Id$
 **********************************************************************
 */

#ifndef _CBUFFER_HXX
#define _CBUFFER_HXX

#include <string.h>
#include "cplatform_stdio.h"
#include "cbufferinterface.hxx"
#include "cbase.hxx"

#define CBUFFER_DEFAULT_SIZE 128

/**
 **********************************************************************
 *  Class: cBufferT
 *
 * Author: $author$
 *   Date: 2/15/2007
 **********************************************************************
 */
template
<class TWhat=CHAR,
 class TSize=TSIZE,
 class TLength=TLENGTH,
 class TEnd=TWhat,
 TEnd VEnd=NULL_CHAR,
 TLength VUndefined=UNDEFINED_LENGTH,
 TSize VDefaultSize=CBUFFER_DEFAULT_SIZE,
 class TExtends=cBase,
 class TImplements=cBufferInterface,
 class TStreamImplements=cStreamImplement>

class cBufferT
: virtual public TStreamImplements,
  virtual public TImplements,
  public TExtends
{
public:
    typedef TImplements cImplements;
    typedef TExtends cExtends;
    typedef cBufferT cDerives;

    bool m_freeBuffer;
    bool m_fixedSize;

    TSize m_size;
    TLength m_length;
    TLength m_tell;

    const TWhat* m_readBuffer;
    TWhat* m_writeBuffer;
    TWhat m_defaultBuffer[VDefaultSize];

    /**
     **********************************************************************
     * Constructor: cBufferT
     *
     *      Author: $author$
     *        Date: 2/15/2007
     **********************************************************************
     */
    cBufferT
    (const TWhat* what=0, TLength length=VUndefined) 
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

        if (what)
        if (0 > (length = Write(what, length)))
            throw (error = -length);
    }
    /**
     **********************************************************************
     *  Destructor: ~cBufferT
     *
     *      Author: $author$
     *        Date: 2/15/2007
     **********************************************************************
     */
    virtual ~cBufferT()
    {
    }

    /**
     **********************************************************************
     * Function: Read
     *
     *   Author: $author$
     *     Date: 2/15/2007
     **********************************************************************
     */
    virtual TLength Read
    (TWhat* what, TSize size) 
    {
        TLength length = VUndefined;

        if (size < 1)
            return 0;

        if (!what)
            return -e_ERROR_NULL_PARAMETER;

        if (!m_readBuffer)
            return -e_ERROR_NOT_ATTACHED;

        if (m_tell >= m_length)
            return -e_ERROR_ENDOF;

        if (m_tell + (length = (TLength)(size)) >= m_length)
            size = (TSize)(length = (m_length - m_tell));

        CopyBuffer(what, m_readBuffer+m_tell, size);

        m_tell += length;
        return length;
    }
    /**
     **********************************************************************
     * Function: Copy
     *
     *   Author: $author$
     *     Date: 2/20/2007
     **********************************************************************
     */
    virtual TLength Copy
    (const TWhat* what, TLength length = VUndefined) 
    {
        TLength count;

        if (0 > (count = Clear()))
            return count;

        length = Write(what, length);
        return length;
    }
    /**
     **********************************************************************
     * Function: Write
     *
     *   Author: $author$
     *     Date: 2/15/2007
     **********************************************************************
     */
    virtual TLength Write
    (const TWhat* what, TLength length = VUndefined) 
    {
        eError error;
        TSize newSize;

        if (length < 0)
            length = GetLengthOf(what);

        if (length < 1)
            return 0;

        if (!what)
            return -e_ERROR_NULL_PARAMETER;

        if (!m_writeBuffer)
            return -e_ERROR_NOT_ATTACHED;

        if (m_size <= (newSize = (m_tell+length)))
        if (m_fixedSize)
            return -e_ERROR_FULL;

        else if ((error = AdjustToSize(NewSize(newSize))))
                return -error;

        CopyBuffer(m_writeBuffer+m_tell, what, length);

        if ((m_tell += length) > m_length)
        if ((TSize)(m_length = m_tell) < m_size)
            m_writeBuffer[m_tell] = (TWhat)(VEnd);

        return length;
    }
    /**
     **********************************************************************
     * Function: Clear
     *
     *   Author: $author$
     *     Date: 2/15/2007
     **********************************************************************
     */
    virtual TLength Clear()
    {
        TLength length;

        if (!m_writeBuffer)
            return -e_ERROR_NOT_ATTACHED;

        length = m_length;

        if (m_size > (TSize)(m_length = (m_tell = 0)))
            m_writeBuffer[m_tell] = (TWhat)(VEnd);

        return length;
    }

    /**
     **********************************************************************
     * Function: Seek
     *
     *   Author: $author$
     *     Date: 7/6/2003
     **********************************************************************
     */
    virtual TLength Seek
    (TLength offset, int origin=e_SEEK_SET)
    {
        TLength tell;

        switch(origin)
        {
        case e_SEEK_SET:
            if (offset < 0)
                tell = -e_ERROR_BEGINOF;

            else if (offset > m_length)
                    tell = -e_ERROR_ENDOF;

            else tell = (m_tell = offset);
            break;

        case e_SEEK_CUR:
            if ((tell = m_tell+offset) < 0)
                tell = -e_ERROR_BEGINOF;

            else if (tell > m_length)
                    tell = -e_ERROR_ENDOF;

            else m_tell = tell;
            break;

        case e_SEEK_END:
            if (offset > 0)
                tell = -e_ERROR_ENDOF;

            else if ((tell = m_length-offset) < 0)
                    tell = -e_ERROR_BEGINOF;

            else m_tell = tell;
            break;

        default:
            tell = -e_ERROR_INVALID_PARAMETER;
        }

        return tell;
    }
    /**
     **********************************************************************
     * Function: Tell
     *
     * Author: $author$
     * Date:   7/17/2003
     **********************************************************************
     */
    virtual TLength Tell() const
    {
        return m_tell;
    }

    /**
     **********************************************************************
     * Function: Compare
     *
     *   Author: $author$
     *     Date: 12/28/2008
     **********************************************************************
     */
    int Compare
    (const TImplements& to, TLength length=VUndefined) 
    {
        int unequal = 1;
        const TWhat* toBuffer;
        TLength toLength;
        if ((toBuffer = to.GetBuffer(toLength)))
        {
            if ((0 <= length) && (toLength < length))
                length = toLength;
            unequal = Compare(toBuffer, length);
        }
        return unequal;
    }
    /**
     **********************************************************************
     * Function: Compare
     *
     *   Author: $author$
     *     Date: 2/20/2003
     **********************************************************************
     */
    virtual int Compare
    (const TWhat* toBuffer, TLength length=VUndefined) const
    {
        const TWhat* whatBuffer;
        TWhat to,what;
        TLength lendiff;

        if (!(whatBuffer = m_readBuffer))
            return toBuffer?-1:1;

        if (length < 0)
            length = GetLengthOf(toBuffer);

        if (0 < (lendiff = (length - m_length)))
        {
            lendiff = -1;
            length = m_length;
        }
        else if (lendiff)
                lendiff = 1;
 
        if (length > 0)
        do
        {
            if ((what = *(whatBuffer++)) > (to = *(toBuffer++)))
                return 1;

            if (what < to)
                return -1;
        }
        while (--length > 0);

        return lendiff;
    }

    /**
     **********************************************************************
     * Function: GetBuffer
     *
     *   Author: $author$
     *     Date: 2/15/2007
     **********************************************************************
     */
    virtual const TWhat* GetBuffer() const
    {
        TSize size;
        TLength length;
        return GetBuffer(size, length);
    }
    /**
     **********************************************************************
     * Function: GetBuffer
     *
     *   Author: $author$
     *     Date: 2/15/2007
     **********************************************************************
     */
    virtual const TWhat* GetBuffer(TLength &length) const
    {
        TSize size;
        return GetBuffer(size, length);
    }
    /**
     **********************************************************************
     * Function: GetBuffer
     *
     *   Author: $author$
     *     Date: 2/15/2007
     **********************************************************************
     */
    virtual const TWhat* GetBuffer(TSize& size, TLength &length) const
    {
        size = m_size;
        length = m_length;
        return m_readBuffer;
    }

    /**
     **********************************************************************
     * Function: GetWriteBuffer
     *
     *   Author: $author$
     *     Date: 2/15/2007
     **********************************************************************
     */
    virtual TWhat* GetWriteBuffer() const
    {
        TSize size;
        TLength length;
        return GetWriteBuffer(size, length);
    }
    /**
     **********************************************************************
     * Function: GetWriteBuffer
     *
     *   Author: $author$
     *     Date: 2/15/2007
     **********************************************************************
     */
    virtual TWhat* GetWriteBuffer(TLength &length) const
    {
        TSize size;
        return GetWriteBuffer(size, length);
    }
    /**
     **********************************************************************
     * Function: GetWriteBuffer
     *
     *   Author: $author$
     *     Date: 2/15/2007
     **********************************************************************
     */
    virtual TWhat* GetWriteBuffer(TSize& size, TLength &length) const
    {
        size = m_size;
        length = m_length;
        return m_writeBuffer;
    }

    /**
     **********************************************************************
     * Function: SetSize
     *
     *   Author: $author$
     *     Date: 2/15/2007
     **********************************************************************
     */
    virtual TLength SetSize(TSize size)
    {
        eError error;

        if (size >= m_size)
        if (m_fixedSize)
            return -e_ERROR_FULL;

        else if ((error = AdjustToSize(NewSize(size))))
                return -error;

        return (TLength)(m_size);
    }
    /**
     **********************************************************************
     * Function: GetSize
     *
     *   Author: $author$
     *     Date: 2/15/2007
     **********************************************************************
     */
    virtual TLength GetSize() const
    {
        return (TLength)(m_size);
    }

    /**
     **********************************************************************
     * Function: SetLength
     *
     *   Author: $author$
     *     Date: 2/15/2007
     **********************************************************************
     */
    virtual TLength SetLength(TLength length)
    {
        TLength size;

        if (!m_writeBuffer)
            return -e_ERROR_NOT_ATTACHED;

        if (0 > length)
        if (0 > (length = GetLengthOf(m_writeBuffer)))
            return -e_ERROR_FAILED;

        if ((TSize)(length) > m_size)
        if (length > (size = SetSize(length)))
        if (size < 0)
            return size;
        else return -e_ERROR_FULL;

        m_tell = length;

        if (m_size > (TSize)(m_length = m_tell))
            m_writeBuffer[m_tell] = (TWhat)(VEnd);

        return m_length;
    }
    /**
     **********************************************************************
     * Function: GetLength
     *
     *   Author: $author$
     *     Date: 2/15/2007
     **********************************************************************
     */
    virtual TLength GetLength() const
    {
        return m_length;
    }

    /**
     **********************************************************************
     * Function: CopyBuffer
     *
     *   Author: $author$
     *     Date: 2/15/2007
     **********************************************************************
     */
    virtual TLength CopyBuffer
    (TWhat* to, const TWhat* from, TSize size)
    {
		TLength length = size;
        memcpy(to, from, sizeof(TWhat)*size);
		return length;
    }
    /**
     **********************************************************************
     * Function: AdjustToSize
     *
     *   Author: $author$
     *     Date: 2/15/2007
     **********************************************************************
     */
    virtual eError AdjustToSize(TSize size)
    {
        bool allocBuffer;
        TWhat* buffer;

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

        if (!(buffer = new TWhat[size]))
        {
            if (allocBuffer)
                m_freeBuffer = false;

            return e_ERROR_NEW;
        }

        if (m_writeBuffer)
        {
            if (m_length > 0)
                CopyBuffer(buffer, m_writeBuffer, m_length);

            if (m_writeBuffer != m_defaultBuffer)
                delete m_writeBuffer;
        }

        m_writeBuffer = buffer;
        m_readBuffer = buffer;
        m_size = size;
        return e_ERROR_NONE;
    }
    /**
     **********************************************************************
     * Function: NewSize
     *
     *   Author: $author$
     *     Date: 2/15/2007
     **********************************************************************
     */
    virtual TSize NewSize(TSize size)
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
     * Function: GetLengthOf
     *
     *   Author: $author$
     *     Date: 2/15/2007
     **********************************************************************
     */
    virtual TLength GetLengthOf(const TWhat* buffer) const
    {
        TLength length;
        TWhat what;

        for (length = 0; (what = *buffer) != (TWhat)(VEnd); buffer++)
            length++;

        return length;
    }
};

/**
 **********************************************************************
 *  Class: cChar2BufferT
 *
 * Author: $author$
 *   Date: 2/15/2007
 **********************************************************************
 */
template
<class TWhat=CHAR,
 class TSize=TSIZE,
 class TLength=TLENGTH,
 class TEnd=TWhat,
 TEnd VEnd=NULL_CHAR,
 TLength VUndefined=UNDEFINED_LENGTH,
 TSize VDefaultSize=CBUFFER_DEFAULT_SIZE,
 class TExtends=cBase,
 class TImplements=cBufferInterface,
 class TStreamImplements=cStreamImplement>

class cChar2BufferT
: public cBufferT
  <TWhat, TSize, TLength, TEnd, 
   VEnd, VUndefined, VDefaultSize, 
   TExtends, TImplements, TStreamImplements>
{
public:
	typedef cBufferT
    <TWhat, TSize, TLength, TEnd, 
     VEnd, VUndefined, VDefaultSize, 
     TExtends, TImplements, TStreamImplements> cExtends;

    /**
     **********************************************************************
     * Constructor: cChar2BufferT
     *
     *      Author: $author$
     *        Date: 2/15/2007
     **********************************************************************
     */
    cChar2BufferT
    (const char* what=0, TLength length=VUndefined) 
    {
        eError error;
        if (what)
        if (0 > (length = Writec(what, length)))
            throw(error = -length);
    }
    /**
     **********************************************************************
     * Constructor: cChar2BufferT
     *
     *      Author: $author$
     *        Date: 2/15/2007
     **********************************************************************
     */
    cChar2BufferT
    (const TWhat* what, TLength length=VUndefined) 
    : cExtends(what, length)
    {
    }

    /**
     **********************************************************************
     * Function: Copyc
     *
     *   Author: $author$
     *     Date: 1/5/2008
     **********************************************************************
     */
    virtual TLength Copyc
    (const char* what, TLength length = VUndefined) 
    {
        TLength count;

        if (0 > (count = (*this).Clear()))
            return count;

        length = Writec(what, length);
        return length;
    }
    /**
     **********************************************************************
     * Function: Writec
     *
     *   Author: $author$
     *     Date: 1/5/2008
     **********************************************************************
     */
    virtual TLength Writec
    (const char* what, TLength length = VUndefined) 
    {
        eError error;
        TSize newSize;

        if (length < 0)
            length = GetcLengthOf(what);

        if (length < 1)
            return 0;

        if (!what)
            return -e_ERROR_NULL_PARAMETER;

        if (!(*this).m_writeBuffer)
            return -e_ERROR_NOT_ATTACHED;

        if ((*this).m_size <= (newSize = ((*this).m_tell+length)))
        if ((*this).m_fixedSize)
            return -e_ERROR_FULL;

        else if ((error = (*this).AdjustToSize(NewSize(newSize))))
                return -error;

        CopycBuffer((*this).m_writeBuffer+(*this).m_tell, what, length);

        if (((*this).m_tell += length) > (*this).m_length)
        if ((TSize)((*this).m_length = (*this).m_tell) < (*this).m_size)
            (*this).m_writeBuffer[(*this).m_tell] = (TWhat)(VEnd);

        return length;
    }
    /**
     **********************************************************************
     * Function: Comparec
     *
     *   Author: $author$
     *     Date: 1/5/2008
     **********************************************************************
     */
    virtual int Comparec
    (const char* toBuffer, TLength length=VUndefined) const
    {
        const TWhat* whatBuffer;
        TWhat what,to;
        TLength lendiff;

        if (!(whatBuffer = (*this).m_readBuffer))
            return toBuffer?-1:1;

        if (length < 0)
            length = GetcLengthOf(toBuffer);

        if (0 < (lendiff = (length - (*this).m_length)))
        {
            lendiff = -1;
            length = (*this).m_length;
        }
        else if (lendiff)
                lendiff = 1;
 
        if (length > 0)
        do
        {
            if ((what = *(whatBuffer++)) 
                > (to = (TWhat)(*(toBuffer++))))
                return 1;

            if (what < to)
                return -1;
        }
        while (--length > 0);

        return lendiff;
    }
    /**
     **********************************************************************
     * Function: CopycBuffer
     *
     *   Author: $author$
     *     Date: 1/5/2008
     **********************************************************************
     */
    virtual TLength CopycBuffer
    (TWhat* to, const char* from, TSize size)
    {
		TLength length = (TLength)(size);
        TLength i;
        for (i=0; i<length; i++)
        {
            TWhat what = (TWhat)(from[i]);
            to[i] = what;
        }
		return length;
    }
    /**
     **********************************************************************
     * Function: GetcLengthOf
     *
     *   Author: $author$
     *     Date: 1/5/2008
     **********************************************************************
     */
    virtual TLength GetcLengthOf(const char* buffer) const
    {
        TLength length;
        char what;

        for (length = 0; (what = *buffer); buffer++)
            length++;

        return length;
    }
};

/**
 **********************************************************************
 * Typedef: cBufferExtends
 *
 *  Author: $author$
 *    Date: 2/15/2007
 **********************************************************************
 */
typedef cBufferT
<CHAR, TSIZE, TLENGTH, CHAR, NULL_CHAR, 
 UNDEFINED_LENGTH, CBUFFER_DEFAULT_SIZE, 
 cBase, cBufferInterface, cStreamImplement>
cBufferExtends;
/**
 **********************************************************************
 *  Class: cBuffer
 *
 * Author: $author$
 *   Date: 2/15/2007
 **********************************************************************
 */
class cBuffer
: public cBufferExtends
{
public:
    typedef cBufferExtends cExtends;
    typedef cBuffer cDerives;
    /**
     **********************************************************************
     * Constructor: cBuffer
     *
     *      Author: $author$
     *        Date: 2/15/2007
     **********************************************************************
     */
    cBuffer
    (const CHAR* what=0, TLENGTH length=UNDEFINED_LENGTH) 
    : cExtends(what, length)
    {
    }
};

/*
 * char
 */
/**
 **********************************************************************
 * Typedef: cCharBufferExtends
 *
 *  Author: $author$
 *    Date: 2/15/2007
 **********************************************************************
 */
typedef cBufferT
<char, TSIZE, TLENGTH, char, NULL_CHAR, 
 UNDEFINED_LENGTH, CBUFFER_DEFAULT_SIZE, 
 cBase, cCharBufferInterface, cCharStreamImplement>
cCharBufferExtends;
/**
 **********************************************************************
 *  Class: cCharBuffer
 *
 * Author: $author$
 *   Date: 2/15/2007
 **********************************************************************
 */
class cCharBuffer
: public cCharBufferExtends
{
public:
    typedef cCharBufferExtends cExtends;
    typedef cCharBuffer cDerives;
    /**
     **********************************************************************
     * Constructor: cCharBuffer
     *
     *      Author: $author$
     *        Date: 2/15/2007
     **********************************************************************
     */
    cCharBuffer
    (const char* what=0, TLENGTH length=UNDEFINED_LENGTH) 
    : cExtends(what, length)
    {
    }
};

/*
 * BYTE
 */
/**
 **********************************************************************
 * Typedef: cBYTEBufferExtends
 *
 *  Author: $author$
 *    Date: 2/15/2007
 **********************************************************************
 */
typedef cBufferT
<BYTE, TSIZE, TLENGTH, BYTE, NULL_CHAR, 
 UNDEFINED_LENGTH, CBUFFER_DEFAULT_SIZE, 
 cBase, cBYTEBufferInterface, cBYTEStreamImplement>
cBYTEBufferExtends;
/**
 **********************************************************************
 *  Class: cBYTEBuffer
 *
 * Author: $author$
 *   Date: 2/15/2007
 **********************************************************************
 */
class cBYTEBuffer
: public cBYTEBufferExtends
{
public:
    typedef cBYTEBufferExtends cExtends;
    typedef cBYTEBuffer cDerives;
    /**
     **********************************************************************
     * Constructor: cBYTEBuffer
     *
     *      Author: $author$
     *        Date: 2/15/2007
     **********************************************************************
     */
    cBYTEBuffer
    (const BYTE* what=0, TLENGTH length=UNDEFINED_LENGTH) 
    : cExtends(what, length)
    {
    }
};

/*
 * TCHAR
 */
#if defined(TCHAR_NOT_CHAR) 
/* TCHAR is WCHAR
 */
/**
 **********************************************************************
 * Typedef: cTCHARBufferExtends
 *
 *  Author: $author$
 *    Date: 2/15/2007
 **********************************************************************
 */
typedef cChar2BufferT
<TCHAR, TSIZE, TLENGTH, TCHAR, NULL_CHAR, 
 UNDEFINED_LENGTH, CBUFFER_DEFAULT_SIZE, 
 cBase, cTCHARBufferInterface, cTCHARStreamImplement>
cTCHARBufferExtends;
/**
 **********************************************************************
 *  Class: cTCHARBuffer
 *
 * Author: $author$
 *   Date: 2/15/2007
 **********************************************************************
 */
class cTCHARBuffer
: public cTCHARBufferExtends
{
public:
    typedef cTCHARBufferExtends cExtends;
    typedef cTCHARBuffer cDerives;
    /**
     **********************************************************************
     * Constructor: cTCHARBuffer
     *
     *      Author: $author$
     *        Date: 2/15/2007
     **********************************************************************
     */
    cTCHARBuffer
    (const char* what=0, TLENGTH length=UNDEFINED_LENGTH) 
    : cExtends(what, length)
    {
    }
};
#else /* defined(TCHAR_NOT_CHAR) */
/* TCHAR is CHAR
 */
/**
 **********************************************************************
 * Typedef: cTCHARBuffer
 *
 *  Author: $author$
 *    Date: 1/6/2008
 **********************************************************************
 */
typedef cCharBuffer cTCHARBuffer;
#endif /* defined(TCHAR_NOT_CHAR) */

#endif /* _CBUFFER_HXX */
