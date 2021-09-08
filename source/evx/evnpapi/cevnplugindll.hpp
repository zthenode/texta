///////////////////////////////////////////////////////////////////////
//   File: cevnplugindll.hpp
//
// Author: $author$
//   Date: 5/28/2008
///////////////////////////////////////////////////////////////////////
#ifndef _CEVNPLUGINDLL_HPP
#define _CEVNPLUGINDLL_HPP

#include "cevopeneddll.hpp"

#define EV_NP_INITIALIZE NP_Initialize
#define EV_NP_INITIALIZE_SYMBOL_CHARS DLL_SYMBOL(EV_NP_INITIALIZE)

///////////////////////////////////////////////////////////////////////
//  Class: CEvNPluginDll
//
// Author: $author$
//   Date: 5/28/2008
///////////////////////////////////////////////////////////////////////
class CEvNPluginDll
: public CEvOpenedDll
{
public:
    typedef CEvOpenedDll CEvExtends;
    typedef CEvNPluginDll CEvDerives;

    const char* m_npInitializeSymbolChars;

    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvNPluginDll
    //
    //      Author: $author$
    //        Date: 5/28/2008
    ///////////////////////////////////////////////////////////////////////
    CEvNPluginDll
    (const char* dllFilenameChars=0,
     DLL attached=INVALID_DLL,
     bool opened=false) 
    : CEvExtends(dllFilenameChars,attached,opened),
      m_npInitializeSymbolChars(EV_NP_INITIALIZE_SYMBOL_CHARS)
    {
    }
    ///////////////////////////////////////////////////////////////////////
    // Destructor: ~CEvNPluginDll
    //
    //     Author: $author$
    //       Date: 5/28/2008
    ///////////////////////////////////////////////////////////////////////
    virtual ~CEvNPluginDll()
    {
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: AcquireSymbols
    //
    //   Author: $author$
    //     Date: 5/28/2008
    ///////////////////////////////////////////////////////////////////////
    virtual EvError AcquireSymbols() 
    {
        EvError error = EV_ERROR_NONE;
        void* addr;
        if (m_npInitializeSymbolChars)
        if ((addr = m_dll.GetAddress(m_npInitializeSymbolChars)))
        {
        }
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: ReleaseSymbols
    //
    //   Author: $author$
    //     Date: 5/28/2008
    ///////////////////////////////////////////////////////////////////////
    virtual EvError ReleaseSymbols() 
    {
        EvError error = EV_ERROR_NONE;
        return error;
    }
};
#endif // _CEVNPLUGINDLL_HPP 
