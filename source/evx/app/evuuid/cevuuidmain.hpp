///////////////////////////////////////////////////////////////////////
//   File: cevuuidmain.hpp
//
// Author: $author$
//   Date: 1/23/2008
///////////////////////////////////////////////////////////////////////
#ifndef _CEVUUIDMAIN_HPP
#define _CEVUUIDMAIN_HPP

#include "cevmain.hpp"
#include "cevuuid.hpp"

typedef CEvMain CEvUUIDMainExtends;
///////////////////////////////////////////////////////////////////////
//  Class: CEvUUIDMain
//
// Author: $author$
//   Date: 1/23/2008
///////////////////////////////////////////////////////////////////////
class CEvUUIDMain
: public CEvUUIDMainExtends
{
public:
    typedef CEvUUIDMainExtends CExtends;
    typedef CEvUUIDMain CDerives;

    CEvUUID m_uuid;

    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvUUIDMain
    //
    //       Author: $author$
    //         Date: 1/23/2008
    ///////////////////////////////////////////////////////////////////////
    CEvUUIDMain() 
    {
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: Run
    //
    //    Author: $author$
    //      Date: 1/23/2008
    ///////////////////////////////////////////////////////////////////////
    virtual int Run
    (int argc, const char** argv, const char** env) 
    {
        int err = 0;
        EvError error = 0;
        LONG length = 0;
        const char* name = 0;
        UINT8 value = 0;

        if (!(error = m_uuid.Generate()))
        {
            if ((name = m_uuid.GetVersionName(value)))
            DBT("() uuid version = 0x%u (%s)\n", value, name);

            if ((name = m_uuid.GetVariantName(value)))
            DBT("() uuid variant = 0x%u (%s)\n", value, name);

            if (0 < (length = m_uuid.WriteX(m_stdOut)))
                m_stdOut.Write("\n",1);
        }

        return err;
    }
};

#endif // _CEVUUIDMAIN_HPP
