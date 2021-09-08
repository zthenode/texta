///////////////////////////////////////////////////////////////////////
//   File: cevcryptoexporter.hpp
//
// Author: $author$
//   Date: 10/27/2007
//
//    $Id$
///////////////////////////////////////////////////////////////////////

#ifndef _CEVCRYPTOEXPORTER_HPP
#define _CEVCRYPTOEXPORTER_HPP

#include "cevcryptoallocator.hpp"
#include "evdebug.h"

///////////////////////////////////////////////////////////////////////
//  Class: CEvCryptoExporter
//
// Author: $author$
//   Date: 10/27/2007
///////////////////////////////////////////////////////////////////////
class CEvCryptoExporter
: public CEvCryptoAllocator
{
public:
    typedef CEvCryptoAllocator CExtends;
    typedef CEvCryptoExporter CDerives;

    static CEvCryptoExporter* m_exporter;
    CEvCryptoExporter* m_oldExporter;

    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvCryptoExporter
    //
    //       Author: $author$
    //         Date: 10/27/2007
    ///////////////////////////////////////////////////////////////////////
    CEvCryptoExporter() 
    : m_oldExporter(m_exporter)
    {
        m_exporter = this;
    }
    ///////////////////////////////////////////////////////////////////////
    // Destructor: ~CEvCryptoExporter
    //
    //      Author: $author$
    //        Date: 10/27/2007
    ///////////////////////////////////////////////////////////////////////
    virtual ~CEvCryptoExporter()
    {
        //DBF("() in...\n");
        if (this == m_exporter)
            m_exporter = m_oldExporter;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: AcquireEvCrypto
    //
    //   Author: $author$
    //     Date: 10/27/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvCrypto* AcquireEvCrypto(EvError &error) 
    {
        EvCrypto* crypto = 0;
        error = EV_ERROR_FAILED;
        return crypto;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: GetExporter
    //
    //   Author: $author$
    //     Date: 10/27/2007
    ///////////////////////////////////////////////////////////////////////
    static CEvCryptoExporter* GetExporter() 
    {
        return m_exporter;
    }
};

#endif // _CEVCRYPTOEXPORTER_HPP
