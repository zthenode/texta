///////////////////////////////////////////////////////////////////////
//   File: cevreadwritebuffer.hpp
//
// Author: $author$
//   Date: 9/5/2007
//
//    $Id$
///////////////////////////////////////////////////////////////////////

#ifndef _CEVREADWRITEBUFFER_HPP
#define _CEVREADWRITEBUFFER_HPP

#include "evreadwritebuffer.hpp"
#include "cevreadwritebase.hpp"
#include "evdebug.h"

#define DEFAULT_CEVREADWRITEBUFFER_SIZE 128

#undef CDB_CLASS
#define CDB_CLASS "CEvReadWriteBuffer"
///////////////////////////////////////////////////////////////////////
//  Class: CEvReadWriteBuffer
//
// Author: $author$
//   Date: 9/5/2007
///////////////////////////////////////////////////////////////////////
template
<class TChar=CHAR,
 class TSize=ULONG,
 TSize VSize=DEFAULT_CEVREADWRITEBUFFER_SIZE,
 class TLength=LONG,
 class TImplements=EvReadWriteBuffer
 <TChar, TSize, TLength>,
 class TExtends=CEvReadWriteBase
 <TChar, TSize, TLength> >

class CEvReadWriteBuffer
: virtual public TImplements,
  public TExtends
{
public:
    typedef TImplements CImplements;
    typedef TExtends CExtends;
    typedef CEvReadWriteBuffer CDerives;

    TChar m_defaultBuffer[VSize];
    const TChar* m_readBuffer;
    TChar* m_writeBuffer;
    TSize m_bufferSize;
    TSize m_bufferLength;
    TSize m_tell;

    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvReadWriteBuffer
    //
    //       Author: $author$
    //         Date: 9/5/2007
    ///////////////////////////////////////////////////////////////////////
    CEvReadWriteBuffer() 
    : m_readBuffer(m_defaultBuffer),
      m_writeBuffer(m_defaultBuffer),
      m_bufferSize(VSize),
      m_bufferLength(VSize),
      m_tell(0)
    {
    }
    ///////////////////////////////////////////////////////////////////////
    // Destructor: ~CEvReadWriteBuffer
    //
    //      Author: $author$
    //        Date: 9/5/2007
    ///////////////////////////////////////////////////////////////////////
    virtual ~CEvReadWriteBuffer()
    {
		EvError error;
		if ((error = FreeBuffer()))
			throw(error);
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: Reset
    //
    //   Author: $author$
    //     Date: 12/7/2007
    ///////////////////////////////////////////////////////////////////////
    virtual TLength Reset() 
    {
        return (TLength)(m_tell = 0);
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: Read
    //
    //   Author: $author$
    //     Date: 4/17/2007
    ///////////////////////////////////////////////////////////////////////
    virtual TLength Read
    (TChar* chars, TSize size) 
    {
        TLength length = 0;
        TSize avail;
        if (m_tell < m_bufferLength)
        {
            if (size > (avail = (m_bufferLength-m_tell)))
                size = avail;

            for (avail=0; avail<size; avail++, m_tell++)
                chars[avail] = m_readBuffer[m_tell];

            length = size;
        }
        return length;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: Write
    //
    //   Author: $author$
    //     Date: 12/8/2007
    ///////////////////////////////////////////////////////////////////////
    virtual TLength Write
    (const TChar* chars, TLength length) 
    {
        TLength count = -EV_ERROR_FAILED;
        TSize size, avail;

        if (!length)
            return length;

        if (0 < length)
        if (m_tell < m_bufferLength)
        {
            if ((size = (TSize)(length)) 
                 > (avail = (m_bufferLength-m_tell)))
                size = avail;

            for (avail=0; avail<size; avail++, m_tell++)
                m_writeBuffer[m_tell] = chars[avail];

            count = size;
        }
        else count = 0;
        return count;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: AllocateBuffer
    //
    //   Author: $author$
    //     Date: 9/5/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError AllocateBuffer
    (TSize bufferSize) 
    {
        EvError error = EV_ERROR_FAILED;
        EvError error2;
		TChar* buffer;

        if (m_bufferSize >= bufferSize)
        {
            m_bufferLength = bufferSize;
            m_tell = 0;
			error = EV_ERROR_NONE;
        }
        else if ((error2 = FreeBuffer()))
                CDBE("() failed on free buffer\n");

		else if (!(buffer = new TChar[bufferSize]))
			    CDBE("() failed on new TChar[%d]\n", bufferSize);
		else
		{
			m_readBuffer = m_writeBuffer = buffer;
			m_bufferLength = m_bufferSize = bufferSize;
            m_tell = 0;
			error = EV_ERROR_NONE;
		}
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: FreeBuffer
    //
    //   Author: $author$
    //     Date: 9/5/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError FreeBuffer() 
    {
        EvError error = EV_ERROR_NONE;

		if (m_writeBuffer != m_defaultBuffer)
		{
			delete m_writeBuffer;
			m_readBuffer = m_writeBuffer = m_defaultBuffer;
			m_bufferLength = m_bufferSize = VSize;
		}
        return error;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: GetWriteBuffer
    //
    //   Author: $author$
    //     Date: 9/5/2007
    ///////////////////////////////////////////////////////////////////////
    virtual TChar* GetWriteBuffer
    (TLength& size) const 
    {
        size = (TLength)(m_bufferSize);
        return m_writeBuffer;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: GetReadBuffer
    //
    //   Author: $author$
    //     Date: 9/5/2007
    ///////////////////////////////////////////////////////////////////////
    virtual const TChar* GetReadBuffer
    (TLength& size) const 
    {
        size = (TLength)(m_bufferSize);
        return m_readBuffer;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: GetSize
    //
    //   Author: $author$
    //     Date: 11/26/2007
    ///////////////////////////////////////////////////////////////////////
    virtual TLength GetSize() const
    {
        TLength size = (TLength)(m_bufferSize);
        return size;
    }
};
#undef CDB_CLASS

///////////////////////////////////////////////////////////////////////
//  Typedef: CEvCharReadWriteBuffer
//
//   Author: $author$
//     Date: 9/5/2007
///////////////////////////////////////////////////////////////////////
typedef CEvReadWriteBuffer
<char, ULONG, DEFAULT_CEVREADWRITEBUFFER_SIZE, LONG, 
 EvCharReadWriteBuffer, CEvCharReadWriteBase>
CEvCharReadWriteBuffer;

#endif // _CEVREADWRITEBUFFER_HPP
