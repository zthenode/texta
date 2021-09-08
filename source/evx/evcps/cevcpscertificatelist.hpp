///////////////////////////////////////////////////////////////////////
//   File: cevcpscertificatelist.hpp
//
// Author: $author$
//   Date: 11/29/2007
///////////////////////////////////////////////////////////////////////

#ifndef _CEVCPSCERTIFICATELIST_HPP
#define _CEVCPSCERTIFICATELIST_HPP

#include "cevcpsrsacertificate.hpp"
#include "cevcpslist.hpp"
#include "cevcpsbase.hpp"
#include "cevbytereadwritebuffer.hpp"
#include "cevbyte2charreader.hpp"

#define EVCPS_CERTIFICATE_LIST_CERTIFICATES 2

///////////////////////////////////////////////////////////////////////
//  Class: CEvcpsCertificateList
//
// Author: $author$
//   Date: 11/29/2007
///////////////////////////////////////////////////////////////////////
class CEvcpsCertificateList
: public CEvcpsBase
{
public:
    typedef CEvcpsBase CExtends;
    typedef CEvcpsCertificateList CDerives;

    ULONG m_length;
    CEvcpsList m_list;

    CEvBYTEReadWriteBuffer m_value;
    CEvBYTE2CharReader m_valueReader;

    ULONG m_certificates;
    CEvcpsRSACertificate 
    m_certificate[EVCPS_CERTIFICATE_LIST_CERTIFICATES];


    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvcpsCertificateList
    //
    //       Author: $author$
    //         Date: 11/29/2007
    ///////////////////////////////////////////////////////////////////////
    CEvcpsCertificateList()
    : m_length(0),
      m_valueReader(m_value),
      m_certificates(0)
    {
    }
    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvcpsCertificateList
    //
    //       Author: $author$
    //         Date: 11/29/2007
    ///////////////////////////////////////////////////////////////////////
    CEvcpsCertificateList
    (CEvcpsRSACertificate* cert,...)
    : m_length(0),
      m_valueReader(m_value),
      m_certificates(0)
    {
        va_list va;
        va_start(va, cert);
        VAppend(cert, va);
        va_end(va);
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: VAssign
    //
    //   Author: $author$
    //     Date: 11/29/2007
    ///////////////////////////////////////////////////////////////////////
    virtual void VAssign
    (CEvcpsRSACertificate* value, va_list va) 
    {
        Clear();
        VAppend(value, va);
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: VAppend
    //
    //   Author: $author$
    //     Date: 11/29/2007
    ///////////////////////////////////////////////////////////////////////
    virtual void VAppend
    (CEvcpsRSACertificate* value, va_list va) 
    {
        do m_list.Append((CEvcpsBase*)value);
        while (0 != (value = va_arg(va, CEvcpsRSACertificate*)));
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: Append
    //
    //   Author: $author$
    //     Date: 11/29/2007
    ///////////////////////////////////////////////////////////////////////
    virtual void Append
    (CEvcpsRSACertificate* value) 
    {
        m_list.Append((CEvcpsBase*)value);
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: Clear
    //
    //   Author: $author$
    //     Date: 11/29/2007
    ///////////////////////////////////////////////////////////////////////
    virtual void Clear() 
    {
        m_list.Clear();
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
        LONG count1, count2, count3;
        BYTE* bytes;
        EvError error;

        Clear();

        if (0 < (count1 = reader.ReadUnsignedMSB
            (m_length, sizeof(m_length)-1)))

        if (!(error = m_value.AllocateBuffer(m_length)))

        if ((bytes = m_value.GetWriteBuffer(count2))
            && (count2 >= m_length))

        if (0 < (count2 = reader.Read
            ((char*)(bytes), m_length)))

        if ((0 < (count3 = ReadCertificates(m_valueReader)))
            && (count3 == m_length))
            length = count1 + count2;

        return length;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: ReadCertificates
    //
    //   Author: $author$
    //     Date: 11/29/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG ReadCertificates
    (EvCharReader& reader) 
    {
        LONG length = -EV_ERROR_FAILED;
        LONG count1, count2;

        for (count1 = 0,
             m_certificates = 0; 
             m_certificates < EVCPS_CERTIFICATE_LIST_CERTIFICATES; 
             m_certificates++)
        {
            if (0 > (count2 = m_certificate
                [m_certificates].Read(reader)))
                break;

            Append(m_certificate+m_certificates);
            count1 += count2;
        }
        if (m_certificates)
            return count1;
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
        LONG count1, count2;

        m_length = m_list.Sizeof();

        if (0 < (count1 = writer.WriteUnsignedMSB
            (m_length, sizeof(m_length)-1)))
        if (0 < (count2 = m_list.Write(writer)))
            length = count1 + count2;

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
        USHORT size = (sizeof(m_length)-1)
            + m_list.Sizeof();
        return size;
    }
};

#endif // _CEVCPSCERTIFICATELIST_HPP
