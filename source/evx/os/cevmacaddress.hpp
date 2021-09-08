///////////////////////////////////////////////////////////////////////
//   File: cevmacaddress.hpp
//
// Author: $author$
//   Date: 1/24/2008
///////////////////////////////////////////////////////////////////////
#ifndef _CEVMACADDRESS_HPP
#define _CEVMACADDRESS_HPP

#include "evplatform_socket.h"
#include "cevstring.hpp"
#include "cevbase.hpp"
#include "evmacaddress.hpp"
#include "evdebug.h"

#if defined(WIN32) 
// Windows 
#else // defined(WIN32) 
// Unix
#if defined(MACOSX)
//
// Mac OSX
//
#include <sys/sysctl.h>
#include <sys/ioctl.h>
#include <net/if.h>
#include<ifaddrs.h>
#include <net/if_dl.h>
#else // defined(MACOSX)
//
// Linux or other
//
#include <sys/ioctl.h>
#include <linux/if.h>
#endif // defined(MACOSX)
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

#if defined(WIN32) 
// Windows 
#else // defined(WIN32) 
// Unix
    char m_buf[1024];
#endif // defined(WIN32) 

    SEvMACAddress m_macAddress;
    CEvString m_adapterName;

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
#if defined(CEVMACADDRESS_UNIX_API) 
        static const BYTE macAddress[sizeof(m_macAddress.m_b)] = {0x12,0x34,0x56,0x78,0x9A,0xBC};
        memcpy(m_macAddress.m_b, macAddress, sizeof(m_macAddress.m_b));
        error = EV_ERROR_NONE;
#else // defined(CEVMACADDRESS_UNIX_API) 
#endif // defined(CEVMACADDRESS_UNIX_API) 
#else // defined(WIN32) 
//
// Unix 
//
#if defined(MACOSX)
//
// Mac OSX
//
        struct ifaddrs *ifa = 0;  
        struct sockaddr_dl* dl;
        LONG length;
        int err, unequal;
        SEvMACAddress macAddress;

        if (adapterName)
        if (0 > (length = m_adapterName.Assign(adapterName)))
            return error;

        memset(macAddress.m_b, 0, sizeof(m_macAddress.m_b));

        DBT("() getifaddrs(&ifa)...\n");
        if (!(err = getifaddrs(&ifa)))
        {
            DBT("() ...getifaddrs(&ifa)\n");
            for (; ifa; ifa = ifa->ifa_next) 
            {  
                if ((dl = (struct sockaddr_dl*)(ifa->ifa_addr)))
                if (0 < (dl->sdl_nlen))
                {  
                    if (!(memcmp(macAddress.m_b, (const void*)(LLADDR(dl)), sizeof(m_macAddress.m_b))))
                        continue;

                    if (adapterName) {
                        if ((unequal = m_adapterName.Compare(dl->sdl_data, dl->sdl_nlen)))
                            continue;
                    }
                    if (0 > (length = m_adapterName.Assign(dl->sdl_data, dl->sdl_nlen)))
                        break;

                    DBT("() ...found MAC of \"%s\"\n", m_adapterName.Chars());
                    memcpy(m_macAddress.m_b, (const void*)(LLADDR(dl)), sizeof(m_macAddress.m_b));
                    error = EV_ERROR_NONE;
                    break;
                } 
            }
        }
        else
        DBE("() ...failed on getifaddrs()\n");
#else // defined(MACOSX)
//
// Linux or other
//
        struct ifreq ifr;
        struct ifreq *IFR;
        struct ifconf ifc;
        int s, i, err, unequal;
        LONG length;

        if (adapterName)
        if (0 > (length = m_adapterName.Assign(adapterName)))
            return error;

        if (0 > (s = socket(AF_INET, SOCK_DGRAM, 0)))
            return error;

        ifc.ifc_len = sizeof(m_buf);
        ifc.ifc_buf = m_buf;

        if (0 > (err = ioctl(s, SIOCGIFCONF, &ifc)))
            return error;

        for (IFR = ifc.ifc_req, i = 0; 
             i < ifc.ifc_len; 
             i += sizeof(struct ifreq), IFR++)
        {
            if (adapterName)
            if ((unequal = m_adapterName.Compare(IFR->ifr_name)))
                continue;

            strcpy(ifr.ifr_name, IFR->ifr_name);

            if (!(err = ioctl(s, SIOCGIFFLAGS, &ifr)))
            if (!(ifr.ifr_flags & IFF_LOOPBACK))
            if (!(err = ioctl(s, SIOCGIFHWADDR, &ifr))) 
            {
                DBT("() found MAC of \"%s\"\n", IFR->ifr_name);

                if (!adapterName)
                if (0 > (length = m_adapterName.Assign(IFR->ifr_name)))
                    continue;

                memcpy(m_macAddress.m_b, ifr.ifr_hwaddr.sa_data, sizeof(m_macAddress.m_b));
                error = EV_ERROR_NONE;
                break;
            }
        }
#endif // defined(MACOSX)
#endif // defined(WIN32) 
        return error;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: WriteX
    //
    //   Author: $author$
    //     Date: 1/23/2008
    ///////////////////////////////////////////////////////////////////////
    virtual LONG WriteX
    (EvCharWriter& writer, char separator='-') 
    {
        LONG count,count2;
        size_t i;

        for (count=0, i=0; i<sizeof(m_macAddress.m_b); i++)
        {
            if (0 < (count2 = WriteUnsignedX
                (writer, m_macAddress.m_b[i], 
                 sizeof(m_macAddress.m_b[i]), 
                 (i<(sizeof(m_macAddress.m_b)-1))?separator:0)))
                count += count2;
        }
        return count;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: WriteUnsignedX
    //
    //   Author: $author$
    //     Date: 1/23/2008
    ///////////////////////////////////////////////////////////////////////
    virtual LONG WriteUnsignedX
    (EvCharWriter& writer, 
     ULONG value, ULONG size, char separator=0) 
    {
        LONG count,count2;

        if (0 < (count = writer.WriteUnsignedX(value, size)))
        if (separator)
        if (0 < (count2 = writer.Write
            (&separator, sizeof(separator))))
            count += count2;

        return count;
    }
};
#endif // _CEVMACADDRESS_HPP 
