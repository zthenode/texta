///////////////////////////////////////////////////////////////////////
//   File: cevuuid.hpp
//
// Author: $author$
//   Date: 1/22/2008
///////////////////////////////////////////////////////////////////////
#ifndef _CEVUUID_HPP
#define _CEVUUID_HPP

#include "evuuid.hpp"
#include "cevinstance.hpp"
#include "cevbytebufferwriter.hpp"
#include "cevstringwriter.hpp"
#include "cevcharwriter.hpp"
#include "evdebug.h"

#if defined(WIN32) 
// Windows 
#if !defined(CEVUUID_UNIX_API) 
#define CEVUUID_WIN32_API
#endif // !defined(CEVUUID_UNIX_API) 
#else // defined(WIN32) 
// Unix 
#include <sys/time.h>
#if !defined(CEVUUID_WIN32_API) 
#define CEVUUID_UNIX_API
#endif // !defined(CEVUUID_WIN32_API) 
#define CEVUUID_UNIX_API
#endif // defined(WIN32) 

#if defined(CEVUUID_UNIX_API) 
// Unix 
#include "evbytereader.hpp"
#define CEVMACADDRESS_UNIX_API
#include "cevmacaddress.hpp"
#undef CEVMACADDRESS_UNIX_API
#include "cevrandombytereader.hpp"
#include "cevmd5.hpp"
#endif // defined(CEVUUID_UNIX_API) 

///////////////////////////////////////////////////////////////////////
//  Class: CEvUUID
//
// Author: $author$
//   Date: 1/22/2008
///////////////////////////////////////////////////////////////////////
class CEvUUID
: virtual public EvUUID,
  public CEvInstance
{
public:
    typedef EvUUID CImplements;
    typedef CEvInstance CExtends;
    typedef CEvUUID CDerives;

    SEvUUID m_uuid;

#if defined(CEVUUID_UNIX_API) 
// Unix 
    CEvMACAddress m_macAddr;
    CEvRandomBYTEReader m_random;
#endif // defined(CEVUUID_UNIX_API) 

    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvUUID
    //
    //      Author: $author$
    //        Date: 1/22/2008
    ///////////////////////////////////////////////////////////////////////
    CEvUUID(bool isStaticInstance=true) 
    : CExtends(isStaticInstance) 
    {
    }
    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvUUID
    //
    //      Author: $author$
    //        Date: 1/22/2008
    ///////////////////////////////////////////////////////////////////////
    CEvUUID(const SEvUUID& uuid) 
    : CExtends(true) 
    {
        memcpy(m_uuid.m_b, uuid.m_b, sizeof(m_uuid.m_b));
    }
    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvUUID
    //
    //      Author: $author$
    //        Date: 1/22/2008
    ///////////////////////////////////////////////////////////////////////
    CEvUUID(const CEvUUID& uuid) 
    : CExtends(true) 
    {
        memcpy(m_uuid.m_b, uuid.m_uuid.m_b, sizeof(m_uuid.m_b));
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: DeleteThis
    //
    //   Author: $author$
    //     Date: 3/12/2008
    ///////////////////////////////////////////////////////////////////////
    virtual EvError DeleteThis() 
    {
        if (m_isStaticInstance)
            return EV_ERROR_NOT_INSTANTIATED;
        delete this;
        return EV_ERROR_NONE;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: Compare
    //
    //   Author: $author$
    //     Date: 3/12/2008
    ///////////////////////////////////////////////////////////////////////
    virtual int Compare(const EvUUID& to) const
    {
        const SEvUUID& toUUID = to.GetUUID();
        int unequal = memcmp(m_uuid.m_b, toUUID.m_b, sizeof(toUUID.m_b));
        return unequal;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: GetUUID
    //
    //   Author: $author$
    //     Date: 3/12/2008
    ///////////////////////////////////////////////////////////////////////
    virtual const SEvUUID& GetUUID() const
    {
        return m_uuid;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: Generate
    //
    //   Author: $author$
    //     Date: 1/22/2008
    ///////////////////////////////////////////////////////////////////////
    virtual EvError Generate() 
    {
        EvError error = EV_ERROR_NOT_IMPLEMENTED;
#if defined(CEVUUID_WIN32_API) 
// Windows 
        RPC_STATUS status;

        if (RPC_S_OK == (status = UuidCreate((UUID*)(m_uuid.m_b))))
        {
            RPC_WSTR uuidTString;
            CEvString uuidString;
            const char* chars;
            LONG length;

            if (RPC_S_OK == (status = UuidToString
                ((UUID*)(m_uuid.m_b), &uuidTString))) 
            {
                if (0 < (length = uuidString.Assignt((TCHAR*)(uuidTString))))
                if ((chars = uuidString.HasChars(length)))
                DBT("() UUID = \"%s\"\n", chars);
                RpcStringFree(&uuidTString);
            }
            // Windows defines UUID as:
            //
            // typedef struct {
            //     unsigned long  Data1;
            //     unsigned short Data2;
            //     unsigned short Data3;
            //     byte           Data4[ 8 ];
            // } GUID, UUID;
            //
            // Since each integer is encoded in host order,
            // they beed to be converted to network (MSB) order.
            //
            error = TimeToMSB();
            return error;
        }

        else if (RPC_S_UUID_LOCAL_ONLY == status)
                DBE("() The UUID is guaranteed to be unique to this computer only.\n");

        else if (RPC_S_UUID_NO_ADDRESS == status)
                DBE("() Cannot get Ethernet or token-ring hardware address for this computer.\n");

        error = EV_ERROR_FAILED;
#else // defined(CEVUUID_WIN32_API) 
// Unix 
        EvError error2 = 0;
        LONG length = 0;
        ULONG value = 0;
        UINT64 uuidTime = 0;
        UINT16 uuidClockSeq = 0;
        CEvMD5 md5;
        BYTE md5Hash[EvMD5::EV_HASH_SIZE];

        // get current UUID time (64 bits)
        //
        uuidTime = GetCurrentUUIDTime();
        DBT("() ...uuidTime = 0x%llX\n", uuidTime);

        // Encode the time into the UUID struct (host order).
        //
        m_uuid.m_timeLow.m_l = (UINT32)(uuidTime & EVUUID_TIME_LOW_BM);
        m_uuid.m_timeMid.m_w = (UINT16)((uuidTime & EVUUID_TIME_MID_BM) >> EVUUID_TIME_MID_BS);
        m_uuid.m_timeHiAndVersion.m_w = (UINT16)((uuidTime & EVUUID_TIME_HI_BM) >> EVUUID_TIME_HI_BS);
        m_uuid.m_timeHiAndVersion.m_w |= (UINT16)(EVUUID_VERSION_TIME_BASED << EVUUID_TIME_HI_VERSION_BS);

        // Convert time part to MSB (network order)
        //
        if ((error2 = TimeToMSB()))
            return error;

        // get clock seqence from a crypto-quality 
        // random number generator.
        //
        if (0 >= (length = m_random.ReadUnsignedMSB(value, sizeof(uuidClockSeq))))
            return error;
        uuidClockSeq = (UINT16)value;
        DBT("() ...uuidClockSeq = 0x%X\n", uuidClockSeq);

        // Encode the sequence into the UUID struct (network order).
        //
        m_uuid.m_clockSeq.m_low = (uuidClockSeq & EVUUID_CLOCK_SEQ_LOW_BM);
        m_uuid.m_clockSeq.m_hiAndRes = ((uuidClockSeq & EVUUID_CLOCK_SEQ_HI_BM) >> EVUUID_CLOCK_SEQ_HI_BS);
        m_uuid.m_clockSeq.m_hiAndRes |= (EVUUID_RESERVED_VARIANT_RFC4122_BV << EVUUID_CLOCK_SEQ_HI_RESERVED_BS);

        // get node ID from the MAC address.
        //
        if (!(error2 = m_macAddr.GetCurrent()))
        {
            CEvString macAddrString;
            CEvStringWriter macAddrStringWriter(macAddrString);
            const char* chars = 0;

            if (0 < (length = m_macAddr.WriteX(macAddrStringWriter))) {
                if ((chars = macAddrString.HasChars(length)))
                    DBT("() ...MAC address = %s\n", chars);
            }

            memcpy
            (m_uuid.m_node.m_b, 
             m_macAddr.m_macAddress.m_b, sizeof(m_uuid.m_node.m_b));

            // Generate an MD5 hash of the MAC address to
            // hide it's identity.
            //
            DBT("() md5.Initialize()...\n");
            if (0 <= (length = md5.Initialize())) {
                DBT("() ...md5.Initialize()\n");

                if (0 < (length = md5.Hash(m_uuid.m_b, sizeof(m_uuid.m_b)))) {
                    DBT("() md5.Hash(m_uuid.m_b, sizeof(m_uuid.m_b))...\n");

                    if (0 < (length = md5.Finalize(md5Hash, sizeof(md5Hash)))) {
                        DBT("() md5.Finalize(md5Hash, sizeof(md5Hash))...\n");

                        if (0 <= (length = macAddrString.Clear())) {
                            if (0 < (length = macAddrStringWriter.WriteX((char*)md5Hash, sizeof(md5Hash)))) {
                                if ((chars = macAddrString.HasChars(length)))
                                    DBT("() MD5 hash = 0x%s\n", chars);
                            }
                        }
                        memcpy(m_uuid.m_node.m_b, md5Hash, sizeof(m_uuid.m_node.m_b));
        
                        // Set MAC address multicast bit per RFC4122
                        //
                        m_uuid.m_node.m_macAddress.m_oui.m_b[0] &= ~EV_MAC_ADDRESS_OUI_BM_MULTICAST;
                        m_uuid.m_node.m_macAddress.m_oui.m_b[0] |= EV_MAC_ADDRESS_OUI_BV_MULTICAST;
                        error = EV_ERROR_NONE;
                    } else {
                        DBE("() ...failed on md5.Finalize(md5Hash, sizeof(md5Hash))\n");
                    }
                } else {
                    DBE("() ...failed on md5.Hash(m_uuid.m_b, sizeof(m_uuid.m_b))\n");
                }
            } else {
                DBE("() ...failed on md5.Initialize()\n");
            }
        }
#endif // defined(CEVUUID_WIN32_API) 
        return error;
    }
#if defined(CEVUUID_UNIX_API) 
// Unix 
    ///////////////////////////////////////////////////////////////////////
    // Function: GetCurrentUUIDTime
    //
    //   Author: $author$
    //     Date: 1/25/2008
    ///////////////////////////////////////////////////////////////////////
    virtual UINT64 GetCurrentUUIDTime() const 
    {
        UINT64 uuidTime = 0;
#if defined(WIN32) 
// Windows 
#if defined(CEVUUID_UNIX_API) 
        uuidTime = 0x1234567890ABCDEFLL;
#else // defined(CEVUUID_UNIX_API) 
#endif // defined(CEVUUID_UNIX_API) 
#else // defined(WIN32) 
// Unix 
        struct timeval tv;

        // get current time 
        //
        gettimeofday(&tv, (struct timezone*)0);

        // Offset between UUID formatted times and Unix formatted times.
        // UUID UTC base time is October 15, 1582.
        // Unix base time is January 1, 1970.
        //
        uuidTime = (tv.tv_sec * 10000000) 
            + (tv.tv_usec * 10) 
            + 0x01B21DD213814000LL;
#endif // defined(WIN32) 
        return uuidTime;
    }
#endif // defined(CEVUUID_UNIX_API) 

    ///////////////////////////////////////////////////////////////////////
    // Function: TimeToMSB
    //
    //   Author: $author$
    //     Date: 1/30/2008
    ///////////////////////////////////////////////////////////////////////
    virtual EvError TimeToMSB() 
    {
        EvError error = EV_ERROR_FAILED;
        LONG length;

        if (0 < (length = SetUnsignedMSB
        (*m_uuid.m_timeLow.m_b, 
         m_uuid.m_timeLow.m_l, 
         sizeof(m_uuid.m_timeLow.m_l))))

        if (0 < (length = SetUnsignedMSB
        (*m_uuid.m_timeMid.m_b, 
         m_uuid.m_timeMid.m_w, 
         sizeof(m_uuid.m_timeMid.m_w))))

        if (0 < (length = SetUnsignedMSB
        (*m_uuid.m_timeHiAndVersion.m_b, 
         m_uuid.m_timeHiAndVersion.m_w, 
         sizeof(m_uuid.m_timeHiAndVersion.m_w))))
         error = EV_ERROR_NONE;

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

        if (0 < (count = WriteX
            (writer, m_uuid.m_timeLow.m_b, 
             sizeof(m_uuid.m_timeLow.m_b), separator)))

        if (0 < (count2 = WriteX
            (writer, m_uuid.m_timeMid.m_b, 
             sizeof(m_uuid.m_timeMid.m_b), separator)))

        if (0 < (count2 = WriteX
            (writer, m_uuid.m_timeHiAndVersion.m_b, 
             sizeof(m_uuid.m_timeHiAndVersion.m_b), separator)))

        if (0 < (count2 = WriteX
            (writer, m_uuid.m_clockSeq.m_b, 
             sizeof(m_uuid.m_clockSeq.m_b), separator)))

        if (0 < (count2 = WriteX
            (writer, m_uuid.m_node.m_b, 
             sizeof(m_uuid.m_node.m_b))))
            count += count2;

        return count;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: WriteX
    //
    //   Author: $author$
    //     Date: 1/23/2008
    ///////////////////////////////////////////////////////////////////////
    virtual LONG WriteX
    (EvCharWriter& writer, 
     const BYTE* value, ULONG size, char separator=0) 
    {
        LONG count,count2;

        if (0 < (count = writer.WriteX
            ((const char*)(value), size)))
        if (separator)
        if (0 < (count2 = writer.Write
            (&separator, sizeof(separator))))
            count += count2;

        return count;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: GetVersionName
    //
    //   Author: $author$
    //     Date: 1/29/2008
    ///////////////////////////////////////////////////////////////////////
    virtual const char* GetVersionName(UINT8& uuidVersion) const 
    {
        const char* chars = EVUUID_VERSION_NAME_NONE;

        uuidVersion = ((m_uuid.m_timeHiAndVersion.m_version 
                        & EVUUID_VERSION_BM) >> EVUUID_VERSION_BS);

        if ((uuidVersion >= EVUUID_VERSION_FIRST) 
            && (uuidVersion <= EVUUID_VERSION_LAST))
            chars = evuuid_versionName[uuidVersion-EVUUID_VERSION_FIRST];

        return chars;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: GetVariantName
    //
    //   Author: $author$
    //     Date: 1/29/2008
    ///////////////////////////////////////////////////////////////////////
    virtual const char* GetVariantName(UINT8& uuidVariant) const 
    {
        const char* chars = EVUUID_RESERVED_VARIANT_NAME_NONE;
        UINT8 uuidVariant_b 
        = ((m_uuid.m_clockSeq.m_hiAndRes 
            & EVUUID_CLOCK_SEQ_HI_RESERVED_BM) 
           >> EVUUID_CLOCK_SEQ_HI_RESERVED_BS);

        uuidVariant = 0;

        for (int i = 0; i < EVUUID_RESERVED_VARIANT_COUNT; i++)
        {
            UINT8 uuidVariant_i = (uuidVariant_b & evuuid_reservedVariantMask[i]);
            if (uuidVariant_i == evuuid_reservedVariantValue[i])
            {
                chars = evuuid_reservedVariantName[i];
                uuidVariant = uuidVariant_i;
                break;
            }
        }
        return chars;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: SetUnsignedMSB
    //
    //   Author: $author$
    //     Date: 1/26/2008
    ///////////////////////////////////////////////////////////////////////
    virtual LONG SetUnsignedMSB
    (BYTE& bytes,
     ULONG value,
     ULONG size) 
    {
        CEvBYTEBufferWriter writer(bytes, size);
        LONG count = writer.WriteUnsignedMSB(value, size);
        return count;
    }

    ///////////////////////////////////////////////////////////////////////
    // Operator: SEvUUID&
    //
    //   Author: $author$
    //     Date: 1/22/2008
    ///////////////////////////////////////////////////////////////////////
    virtual operator SEvUUID&() const 
    {
        return (SEvUUID&)(m_uuid);
    }
};

#endif // _CEVUUID_HPP 
