///////////////////////////////////////////////////////////////////////
//   File: cevcpsserverrsaparams.hpp
//
// Author: $author$
//   Date: 11/26/2007
///////////////////////////////////////////////////////////////////////

#ifndef _CEVCPSSERVERRSAPARAMS_HPP
#define _CEVCPSSERVERRSAPARAMS_HPP

#include "cevcpsshortopaque.hpp"
#include "cevcpsbase.hpp"

///////////////////////////////////////////////////////////////////////
//  Class: CEvcpsServerRSAParams
//
// Author: $author$
//   Date: 11/26/2007
///////////////////////////////////////////////////////////////////////
class CEvcpsServerRSAParams
: public CEvcpsBase
{
public:
    typedef CEvcpsBase CExtends;
    typedef CEvcpsServerRSAParams CDerives;

    CEvcpsSHORTOpaque m_rsaModulus;
    CEvcpsSHORTOpaque m_rsaExponent;

    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvcpsServerRSAParams
    //
    //       Author: $author$
    //         Date: 11/26/2007
    ///////////////////////////////////////////////////////////////////////
    CEvcpsServerRSAParams
    (const BYTE* rsaModulus=0, SHORT rsaModulusBytes=0,
     const BYTE* rsaExponent=0, SHORT rsaExponentBytes=0) 
    {
        EvError error;
        LONG length;

        if (rsaModulus && rsaModulusBytes)
        if (0 > (length = AssignModulus
            (rsaModulus, rsaModulusBytes)))
            throw(error = -length);

        if (rsaExponent && rsaExponentBytes)
        if (0 > (length = AssignExponent
            (rsaExponent, rsaExponentBytes)))
            throw(error = -length);
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: Assign
    //
    //   Author: $author$
    //     Date: 12/10/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG Assign
    (const BYTE* rsaModulus, SHORT rsaModulusBytes,
     const BYTE* rsaExponent, SHORT rsaExponentBytes) 
    {
        LONG length = -EV_ERROR_FAILED;
        LONG count1, count2;

        if (0 < (count1 = AssignModulus
            (rsaModulus, rsaModulusBytes)))
        if (0 < (count2 = AssignExponent
            (rsaExponent, rsaExponentBytes)))
            length = count1 + count2;

        return length;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: AssignModulus
    //
    //   Author: $author$
    //     Date: 12/10/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG AssignModulus
    (const BYTE* rsaModulus, SHORT rsaModulusBytes) 
    {
        LONG length = -EV_ERROR_FAILED;
        if (rsaModulus && rsaModulusBytes)
            length = m_rsaModulus.Assign
            (rsaModulus, rsaModulusBytes);
        return length;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: AssignExponent
    //
    //   Author: $author$
    //     Date: 12/10/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG AssignExponent
    (const BYTE* rsaExponent, SHORT rsaExponentBytes) 
    {
        LONG length = -EV_ERROR_FAILED;
        if (rsaExponent && rsaExponentBytes)
            length = m_rsaExponent.Assign
            (rsaExponent, rsaExponentBytes);
        return length;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: ModulusHasChars
    //
    //   Author: $author$
    //     Date: 12/14/2007
    ///////////////////////////////////////////////////////////////////////
    virtual const BYTE* ModulusHasChars
    (LONG& length) const
    {
        const BYTE* chars = m_rsaModulus.HasChars(length);
        return chars;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: ExponentHasChars
    //
    //   Author: $author$
    //     Date: 12/14/2007
    ///////////////////////////////////////////////////////////////////////
    virtual const BYTE* ExponentHasChars
    (LONG& length) const
    {
        const BYTE* chars = m_rsaExponent.HasChars(length);
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
        LONG length = -EV_ERROR_FAILED;
        LONG count1, count2;

        if (0 > (count1 = m_rsaModulus.Read(reader)))
            return length;

        if (0 > (count2 = m_rsaExponent.Read(reader)))
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

        if (0 > (count1 = m_rsaModulus.Write(writer)))
            return length;

        if (0 > (count2 = m_rsaExponent.Write(writer)))
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
        USHORT size = m_rsaModulus.Sizeof()
            + m_rsaExponent.Sizeof();
        return size;
    }
};

#endif // _CEVCPSSERVERRSAPARAMS_HPP
