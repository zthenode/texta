///////////////////////////////////////////////////////////////////////
//   File: cevmacaddress.hpp
//
// Author: $author$
//   Date: 1/24/2008
///////////////////////////////////////////////////////////////////////
#ifndef _CEVMACADDRESS_HPP
#define _CEVMACADDRESS_HPP

#include "evplatform.h"

#if defined(WIN32) 
// Windows 
#include <objbase.h>
#include <netcon.h>
#else // defined(WIN32) 
// Unix 
#endif // defined(WIN32) 

#include "cevbase.hpp"
#include "cevtstring.hpp"
#include "cevstring.hpp"
#include "evdebug.h"

#if defined(WIN32) 
// Windows 
#define ADAPTER_LIST_KEY "SYSTEM\\CurrentControlSet\\Control\\Network\\{4D36E972-E325-11CE-BFC1-08002BE10318}"
#define ADAPTER_LIST_KEY2 "SYSTEM\\CurrentControlSet\\Control\\Class\\{4D36E972-E325-11CE-BFC1-08002bE10318}"
#define ADAPTER_CONFIG_KEY "NetCfgInstanceId"
#define NETWORK_ADDRESS_KEY "NetworkAddress"
#define CONNECTION_KEY "Connection"
#define NAME_KEY "Name"
#else // defined(WIN32) 
// Unix 
#endif // defined(WIN32) 

///////////////////////////////////////////////////////////////////////
//  Class: CEvMACAddress
//
// Author: $author$
//   Date: 1/24/2008
///////////////////////////////////////////////////////////////////////
class CEvMACAddress
: public CEvBase
{
public:
    typedef CEvBase CExtends;
    typedef CEvMACAddress CDerives;
    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvMACAddress
    //
    //      Author: $author$
    //        Date: 1/24/2008
    ///////////////////////////////////////////////////////////////////////
    CEvMACAddress() 
    {
    }
    ///////////////////////////////////////////////////////////////////////
    // Destructor: CEvMACAddress
    //
    //     Author: $author$
    //       Date: 1/24/2008
    ///////////////////////////////////////////////////////////////////////
    virtual ~CEvMACAddress()
    {
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: GetCurrent
    //
    //   Author: $author$
    //     Date: 1/24/2008
    ///////////////////////////////////////////////////////////////////////
    virtual EvError GetCurrent
    (const char* adapterName=0) 
    {
        EvError error = EV_ERROR_NOT_IMPLEMENTED;
#if defined(WIN32) 
// Windows 
        bool found = false;
        HKEY hListKey = NULL;
        HKEY hKey = NULL;
        LONG err;
        DWORD reserved;
        FILETIME writtenTime;
        TCHAR keyNameBuf[512];
        TCHAR keyValueBuf[512];
        DWORD keyValueBufSiz;
        DWORD keyNameBufSiz;
        CEvTString adapterIdT;
        CEvTString keyNameT;
        CEvString keyName;
        const char* keyNameChars;
        const TCHAR* keyNameTChars;
        LONG length;

        if (ERROR_SUCCESS != (err = RegOpenKeyEx
            (HKEY_LOCAL_MACHINE, _T(ADAPTER_LIST_KEY), 0, KEY_READ, &hListKey)))
            DBE("() failed to open registry key \"%s\"\n", ADAPTER_LIST_KEY);
        else
        {
            for (int i=0; !found; i++)
            {
                keyNameBufSiz = sizeof(keyNameBuf);

                if (ERROR_SUCCESS != (err = RegEnumKeyEx
                    (hListKey, i, keyNameBuf, &keyNameBufSiz, 
                     0, NULL, NULL, &writtenTime)))
                     break;

                if (0 < (length = keyName.Assignt(keyNameBuf)))
                if ((keyNameChars = keyName.HasChars(length)))
                {
                    DBT("() found registry key \"%s\"\n", keyNameChars);

                    if (0 < (length = keyNameT.Assign(keyNameBuf)))
                    if (0 < (length = keyNameT.Append(_T("\\"))))
                    if (0 < (length = keyNameT.Append(_T(CONNECTION_KEY))))
                    if ((keyNameTChars = keyNameT.HasChars(length)))

                    if (0 < (length = keyName.Append("\\")))
                    if (0 < (length = keyName.Append(CONNECTION_KEY)))
                    if ((keyNameChars = keyName.HasChars(length)))

                    if (ERROR_SUCCESS == (err = RegOpenKeyEx
                        (hListKey, keyNameTChars, 0, KEY_READ, &hKey)))
                    {
                        DBT("() opened registry key \"%s\"\n", keyNameChars);

                        keyValueBufSiz = sizeof(keyValueBuf);

                        if (ERROR_SUCCESS != (err = RegQueryValueEx
                            (hKey, _T(NAME_KEY), 0, &reserved, 
                             (LPBYTE)keyValueBuf, &keyValueBufSiz)))
                            DBE("() failed to get value of registry key \"%s\"\n", keyNameChars);
                        else
                        {
                            if (0 < (length = keyName.Assignt(keyValueBuf)))
                            if ((keyNameChars = keyName.HasChars(length)))
                            {
                                DBT("() Adapter name is \"%s\"\n", keyNameChars);
                                if (adapterName)
                                    found = !keyName.Compare(adapterName);
                                else found = true;
                            }
                        }
                        RegCloseKey(hKey);
                    }
                }
            }
            RegCloseKey(hListKey);
        }

        if (found)
        if (0 < (length = adapterIdT.Assign(keyNameBuf)))
        if ((keyNameTChars = adapterIdT.HasChars(length)))
        if (0 < (length = keyName.Assignt(keyNameTChars)))
        if ((keyNameChars = keyName.HasChars(length)))
        {
        DBT("() Found adapter id \"%s\"\n", keyNameChars);
        if (ERROR_SUCCESS != (err = RegOpenKeyEx
            (HKEY_LOCAL_MACHINE, _T(ADAPTER_LIST_KEY2), 0, KEY_READ, &hListKey)))
            DBE("() failed to open registry key \"%s\"\n", ADAPTER_LIST_KEY2);
        else
        {
            found = false;

            for (int i=0; !found; i++)
            {
                keyNameBufSiz = sizeof(keyNameBuf);

                if (ERROR_SUCCESS != (err = RegEnumKeyEx
                    (hListKey, i, keyNameBuf, &keyNameBufSiz, 
                     0, NULL, NULL, &writtenTime)))
                     break;

                if (0 < (length = keyName.Assignt(keyNameBuf)))
                if ((keyNameChars = keyName.HasChars(length)))
                {
                    DBT("() found registry key \"%s\"\n", keyNameChars);

                    if (ERROR_SUCCESS == (err = RegOpenKeyEx
                        (hListKey, keyNameBuf, 0, KEY_READ, &hKey)))
                    {
                        DBT("() opened registry key \"%s\"\n", keyNameChars);

                        keyValueBufSiz = sizeof(keyValueBuf);

                        if (ERROR_SUCCESS == (err = RegQueryValueEx
                            (hKey, _T(ADAPTER_CONFIG_KEY), 0, &reserved, 
                             (LPBYTE)keyValueBuf, &keyValueBufSiz)))
                        {
                            DBT("() got registry key value \"%s\"\n", ADAPTER_CONFIG_KEY);

                            if (!adapterIdT.Compare(keyValueBuf))
                            {
                                keyValueBufSiz = sizeof(keyValueBuf);

                                if (ERROR_SUCCESS == (err = RegQueryValueEx
                                    (hKey, _T(NETWORK_ADDRESS_KEY), 0, &reserved, 
                                     (LPBYTE)keyValueBuf, &keyValueBufSiz)))
                                    DBT("() got registry key value \"%s\"\n", NETWORK_ADDRESS_KEY);
                            }
                        }
                        RegCloseKey(hKey);
                    }
                }
            }
            RegCloseKey(hListKey);
        }
        }
#else // defined(WIN32) 
// Unix 
#endif // defined(WIN32) 
        return error;
    }
};

#endif // _CEVMACADDRESS_HPP 
