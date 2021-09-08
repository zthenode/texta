///////////////////////////////////////////////////////////////////////
//   File: cevcryptodllmain.hpp
//
// Author: $author$
//   Date: 10/27/2007
//
//    $Id$
///////////////////////////////////////////////////////////////////////

#ifndef _CEVCRYPTODLLMAIN_HPP
#define _CEVCRYPTODLLMAIN_HPP

#include "cevdllmain.hpp"
#include "cevcryptoexporter.hpp"

///////////////////////////////////////////////////////////////////////
//  Class: CEvCryptoDllMain
//
// Author: $author$
//   Date: 10/27/2007
///////////////////////////////////////////////////////////////////////
class CEvCryptoDllMain
: public CEvDllMain
{
public:
    typedef CEvDllMain CExtends;
    typedef CEvCryptoDllMain CDerives;

    static CEvCryptoDllMain* m_dllMain;
    CEvCryptoDllMain* m_oldDllMain;

    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvCryptoDllMain
    //
    //       Author: $author$
    //         Date: 10/27/2007
    ///////////////////////////////////////////////////////////////////////
    CEvCryptoDllMain() 
    : m_oldDllMain(m_dllMain)
    {
        m_dllMain = this;
    }
    ///////////////////////////////////////////////////////////////////////
    // Destructor: ~CEvCryptoDllMain
    //
    //      Author: $author$
    //        Date: 10/27/2007
    ///////////////////////////////////////////////////////////////////////
    virtual ~CEvCryptoDllMain()
    {
        if (this == m_dllMain)
            m_dllMain = m_oldDllMain;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: Initialize
    //
    //   Author: $author$
    //     Date: 10/27/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError Initialize() 
    {
        EvError error = EV_ERROR_NONE;
        CEvCryptoExporter* exporter;

        if ((exporter = CEvCryptoExporter::GetExporter()))
            error = exporter->Initialize();
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: Finalize
    //
    //   Author: $author$
    //     Date: 10/27/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError Finalize() 
    {
        EvError error = EV_ERROR_NONE;
        CEvCryptoExporter* exporter;

        if ((exporter = CEvCryptoExporter::GetExporter()))
            error = exporter->Finalize();
        return error;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: GetDllMain
    //
    //   Author: $author$
    //     Date: 4/12/2007
    ///////////////////////////////////////////////////////////////////////
    static CEvCryptoDllMain* GetDllMain() 
    {
        return m_dllMain;
    }
};

#endif // _CEVCRYPTODLLMAIN_HPP
