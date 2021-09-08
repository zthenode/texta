///////////////////////////////////////////////////////////////////////
//   File: cevservletdllmain.hpp
//
// Author: $author$
//   Date: 4/13/2007
//
//    $Id$
///////////////////////////////////////////////////////////////////////

#ifndef _CEVSERVLETDLLMAIN_HPP
#define _CEVSERVLETDLLMAIN_HPP

#include "cevdllmain.hpp"
#include "cevservletexporter.hpp"

///////////////////////////////////////////////////////////////////////
//  Class: CEvServletDllMain
//
// Author: $author$
//   Date: 4/13/2007
///////////////////////////////////////////////////////////////////////
class CEvServletDllMain
: public CEvDllMain
{
public:
    typedef CEvDllMain CExtends;
    typedef CEvServletDllMain CDerives;

    static CEvServletDllMain* m_dllMain;
    CEvServletDllMain* m_oldDllMain;

    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvServletDllMain
    //
    //       Author: $author$
    //         Date: 4/13/2007
    ///////////////////////////////////////////////////////////////////////
    CEvServletDllMain() 
    : m_oldDllMain(m_dllMain)
    {
        m_dllMain = this;
    }
    ///////////////////////////////////////////////////////////////////////
    // Destructor: ~CEvServletDllMain
    //
    //      Author: $author$
    //        Date: 4/13/2007
    ///////////////////////////////////////////////////////////////////////
    virtual ~CEvServletDllMain()
    {
        if (this == m_dllMain)
            m_dllMain = m_oldDllMain;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: Initialize
    //
    //   Author: $author$
    //     Date: 4/13/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError Initialize() 
    {
        EvError error = EV_ERROR_NONE;
        CEvServletExporter* exporter;

        if ((exporter = CEvServletExporter::GetExporter()))
            error = exporter->Initialize();
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: Finalize
    //
    //   Author: $author$
    //     Date: 4/13/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError Finalize() 
    {
        EvError error = EV_ERROR_NONE;
        CEvServletExporter* exporter;

        if ((exporter = CEvServletExporter::GetExporter()))
            error = exporter->Finalize();
        return error;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: GetDllMain
    //
    //   Author: $author$
    //     Date: 4/12/2007
    ///////////////////////////////////////////////////////////////////////
    static CEvServletDllMain* GetDllMain() 
    {
        return m_dllMain;
    }
};
#endif // _CEVSERVLETDLLMAIN_HPP
