///////////////////////////////////////////////////////////////////////
//   File: ccevcryptoexporter.hpp
//
// Author: $author$
//   Date: 10/30/2007
//
//    $Id$
///////////////////////////////////////////////////////////////////////

#ifndef _CCEVCRYPTOEXPORTER_HPP
#define _CCEVCRYPTOEXPORTER_HPP

#include "cevcryptoexporter.hpp"
#include "ccevcrypto.hpp"

///////////////////////////////////////////////////////////////////////
//  Class: CCEvCryptoExporter
//
// Author: $author$
//   Date: 10/30/2007
///////////////////////////////////////////////////////////////////////
class CCEvCryptoExporter
: public CEvCryptoExporter
{
public:
    typedef CEvCryptoExporter CExtends;
    typedef CCEvCryptoExporter CDerives;

    ///////////////////////////////////////////////////////////////////////
    // Constructor: CCEvCryptoExporter
    //
    //       Author: $author$
    //         Date: 10/30/2007
    ///////////////////////////////////////////////////////////////////////
    CCEvCryptoExporter() 
    {
    }
    ///////////////////////////////////////////////////////////////////////
    // Destructor: ~CCEvCryptoExporter
    //
    //      Author: $author$
    //        Date: 10/30/2007
    ///////////////////////////////////////////////////////////////////////
    virtual ~CCEvCryptoExporter()
    {
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

        if ((crypto = new CCEvCrypto()))
        {
            if (!(error = AddCrypto(*crypto)))
                return crypto;

            delete crypto;
            crypto = 0;
        }
        return crypto;
    }
};
#endif // _CCEVCRYPTOEXPORTER_HPP
