///////////////////////////////////////////////////////////////////////
//   File: cevcpsrsacertificateinfo.hpp
//
// Author: $author$
//   Date: 11/29/2007
///////////////////////////////////////////////////////////////////////

#ifndef _CEVCPSRSACERTIFICATEINFO_HPP
#define _CEVCPSRSACERTIFICATEINFO_HPP

#include "cevcpsserverrsaparams.hpp"
#include "cevcpsbase.hpp"

///////////////////////////////////////////////////////////////////////
//  Class: CEvcpsRSACertificateInfo
//
// Author: $author$
//   Date: 11/29/2007
///////////////////////////////////////////////////////////////////////
class CEvcpsRSACertificateInfo
: public CEvcpsBase
{
public:
    typedef CEvcpsBase CExtends;
    typedef CEvcpsRSACertificateInfo CDerives;

    CEvcpsServerRSAParams m_signer;

    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvcpsRSACertificateInfo
    //
    //       Author: $author$
    //         Date: 11/29/2007
    ///////////////////////////////////////////////////////////////////////
    CEvcpsRSACertificateInfo
    (const BYTE* rsaModulus=0, SHORT rsaModulusBytes=0,
     const BYTE* rsaExponent=0, SHORT rsaExponentBytes=0) 
    : m_signer
      (rsaModulus, rsaModulusBytes, 
       rsaExponent, rsaExponentBytes)
    {
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: Assign
    //
    //   Author: $author$
    //     Date: 12/19/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG Assign
    (const BYTE* rsaModulus, SHORT rsaModulusBytes,
     const BYTE* rsaExponent, SHORT rsaExponentBytes) 
    {
        LONG length = m_signer.Assign
        (rsaModulus, rsaModulusBytes,
         rsaExponent, rsaExponentBytes);
        return length;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: Read
    //
    //   Author: $author$
    //     Date: 11/29/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG Read
    (EvCharReader& reader) 
    {
        LONG length = -EV_ERROR_FAILED;
        LONG count1;
        if (0 < (count1 = m_signer.Read(reader)))
            length = count1;
        return length;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: Write
    //
    //   Author: $author$
    //     Date: 11/29/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG Write
    (EvCharWriter& writer) 
    {
        LONG length = -EV_ERROR_FAILED;
        LONG count1;
        if (0 < (count1 = m_signer.Write(writer)))
            length = count1;
        return length;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: Sizeof
    //
    //   Author: $author$
    //     Date: 11/29/2007
    ///////////////////////////////////////////////////////////////////////
    virtual USHORT Sizeof() const 
    {
        USHORT size = m_signer.Sizeof();
        return size;
    }
};

#endif // _CEVCPSRSACERTIFICATEINFO_HPP
