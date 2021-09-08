///////////////////////////////////////////////////////////////////////
//   File: cevcpsopaque.hpp
//
// Author: $author$
//   Date: 11/26/2007
///////////////////////////////////////////////////////////////////////

#ifndef _CEVCPSOPAQUE_HPP
#define _CEVCPSOPAQUE_HPP

#include "cevcpsbase.hpp"
#include "cevbytestring.hpp"
#include "cevbytereadwritebuffer.hpp"
#include "cevchar2bytereader.hpp"

///////////////////////////////////////////////////////////////////////
//  Class: CEvcpsOpaque
//
// Author: $author$
//   Date: 11/26/2007
///////////////////////////////////////////////////////////////////////
template
<class TLength=BYTE>

class CEvcpsOpaque
: public CEvcpsBase
{
public:
    typedef CEvcpsBase CExtends;
    typedef CEvcpsOpaque CDerives;

    TLength m_length;
    CEvBYTEString m_value;

    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvcpsOpaque
    //
    //       Author: $author$
    //         Date: 11/26/2007
    ///////////////////////////////////////////////////////////////////////
    CEvcpsOpaque
    (const BYTE* chars=0, LONG length=-1) 
    : m_length(0)
    {
        EvError error;
        if (chars)
        if (0 > (length = Assign(chars, length)))
            throw(error=-length);
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: Assign
    //
    //   Author: $author$
    //     Date: 11/26/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG Assign
    (const BYTE* chars, LONG length=-1) 
    {
        if (0 <= (length = m_value.Assign(chars, length)))
            m_length = (TLength)(length);
        return length;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: Append
    //
    //   Author: $author$
    //     Date: 11/26/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG Append
    (const BYTE* chars, LONG length=-1) 
    {
        LONG oldLength = m_value.Length();
        if (0 <= (length = m_value.Append(chars, length)))
            m_length = (TLength)(length + oldLength);
        return length;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: HasChars
    //
    //   Author: $author$
    //     Date: 11/26/2007
    ///////////////////////////////////////////////////////////////////////
    virtual const BYTE* HasChars
    (LONG& length) const
    {
        const BYTE* chars = m_value.HasChars(length);
        return chars;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: Read
    //
    //   Author: $author$
    //     Date: 11/26/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG Read
    (EvCharReader& reader) 
    {
        CEvChar2BYTEReader c2bReader(reader);
        LONG length = -EV_ERROR_FAILED;
        LONG count1, count2;
        ULONG ulength;

        if (0 > (count1 = reader.
            ReadUnsignedMSB(ulength, sizeof(m_length))))
            return length;

        m_length = (TLength)(ulength);

        if (0 > (count2 = m_value.Read(c2bReader, m_length)))
            return length;

        length = count1+count2;
        return length;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: Write
    //
    //   Author: $author$
    //     Date: 11/26/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG Write
    (EvCharWriter& writer) 
    {
        LONG length = -EV_ERROR_FAILED;
        LONG count1, count2;
        const BYTE* chars;

        if (0 > (count1 = writer.
            WriteUnsignedMSB(m_length, sizeof(m_length))))
            return length;

        if ((chars = m_value.HasChars(count2)))
        if (0 > (count2 = writer.
            Write((char*)chars, count2)))
            return length;

        length = count1+count2;
        return length;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: Sizeof
    //
    //   Author: $author$
    //     Date: 11/26/2007
    ///////////////////////////////////////////////////////////////////////
    virtual USHORT Sizeof() const 
    {
        USHORT size = sizeof(m_length)+m_length;
        return size;
    }
};
#endif // _CEVCPSOPAQUE_HPP
