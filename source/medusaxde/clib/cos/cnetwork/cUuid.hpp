///////////////////////////////////////////////////////////////////////
// Copyright (c) 1988-2013 $organization$
//
// This software is provided by the author and contributors ``as is'' 
// and any express or implied warranties, including, but not limited to, 
// the implied warranties of merchantability and fitness for a particular 
// purpose are disclaimed. In no event shall the author or contributors 
// be liable for any direct, indirect, incidental, special, exemplary, 
// or consequential damages (including, but not limited to, procurement 
// of substitute goods or services; loss of use, data, or profits; or 
// business interruption) however caused and on any theory of liability, 
// whether in contract, strict liability, or tort (including negligence 
// or otherwise) arising in any way out of the use of this software, 
// even if advised of the possibility of such damage.
//
//   File: cUuid.hpp
//
// Author: $author$
//   8/20/2013
///////////////////////////////////////////////////////////////////////
#ifndef _CUUID_HPP
#define _CUUID_HPP

#include "cMacAddress.hpp"
#include "cBufferWriter.hpp"
#include "cBases.hpp"
#include "cDebug.hpp"

#define CUUID_TIME_LOW_BM 0x00000000FFFFFFFFLL
#define CUUID_TIME_LOW_BS 0

#define CUUID_TIME_MID_BM 0x0000FFFF00000000LL
#define CUUID_TIME_MID_BS 32

#define CUUID_TIME_HI_BM 0x0FFF000000000000LL
#define CUUID_TIME_HI_BS 48

#define CUUID_TIME_HI_VERSION_BM 0xF000
#define CUUID_TIME_HI_VERSION_BS 12

#define CUUID_VERSION_BM 0xF0
#define CUUID_VERSION_BS 4

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

///////////////////////////////////////////////////////////////////////
//   Enum: 
//
// Author: $author$
//   8/20/2013
///////////////////////////////////////////////////////////////////////
enum
{
    CUUID_VERSION_NONE            = 0x0,

    CUUID_VERSION_TIME_BASED      = 0x1,
    CUUID_VERSION_DCE_SECURITY    = 0x2,
    CUUID_VERSION_NAME_BASED_MD5  = 0x3,
    CUUID_VERSION_RANDOM          = 0x4,
    CUUID_VERSION_NAME_BASED_SHA1 = 0x5,

    CUUID_VERSION_NEXT,
    CUUID_VERSION_FIRST = CUUID_VERSION_NONE+1,
    CUUID_VERSION_LAST = CUUID_VERSION_NEXT-1,
    CUUID_VERSION_COUNT = CUUID_VERSION_LAST-CUUID_VERSION_FIRST+1
};

#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////

#define CUUID_VERSION_NAME_NONE            "NONE"
#define CUUID_VERSION_NAME_TIME_BASED      "TIME_BASED"
#define CUUID_VERSION_NAME_DCE_SECURITY    "DCE_SECURITY"
#define CUUID_VERSION_NAME_NAME_BASED_MD5  "NAME_BASED_MD5"
#define CUUID_VERSION_NAME_RANDOM          "RANDOM"
#define CUUID_VERSION_NAME_NAME_BASED_SHA1 "NAME_BASED_SHA1"

#define CUUID_CLOCK_SEQ_LOW_BM 0x00FF
#define CUUID_CLOCK_SEQ_LOW_BS 0

#define CUUID_CLOCK_SEQ_HI_BM 0x1F00
#define CUUID_CLOCK_SEQ_HI_BS 8

#define CUUID_CLOCK_SEQ_HI_RESERVED_BM 0xE0
#define CUUID_CLOCK_SEQ_HI_RESERVED_BS 5

#define CUUID_RESERVED_VARIANT_NCS_COMPATIBILITY_BM 0x4
#define CUUID_RESERVED_VARIANT_NCS_COMPATIBILITY_BV 0x0

#define CUUID_RESERVED_VARIANT_RFC4122_BM 0x6
#define CUUID_RESERVED_VARIANT_RFC4122_BV 0x4

#define CUUID_RESERVED_VARIANT_MICROSOFT_COMPATIBILITY_BM 0x7
#define CUUID_RESERVED_VARIANT_MICROSOFT_COMPATIBILITY_BV 0x6

#define CUUID_RESERVED_VARIANT_FUTURE_DEFINITION_BM 0x7
#define CUUID_RESERVED_VARIANT_FUTURE_DEFINITION_BV 0x7

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

///////////////////////////////////////////////////////////////////////
//   Enum: 
//
// Author: $author$
//   8/20/2013
///////////////////////////////////////////////////////////////////////
enum
{
    CUUID_RESERVED_VARIANT_FIRST,

    CUUID_RESERVED_VARIANT_FUTURE_DEFINITION = CUUID_RESERVED_VARIANT_FIRST,
    CUUID_RESERVED_VARIANT_MICROSOFT_COMPATIBILITY,
    CUUID_RESERVED_VARIANT_RFC4122,
    CUUID_RESERVED_VARIANT_NCS_COMPATIBILITY,

    CUUID_RESERVED_VARIANT_NEXT,
    CUUID_RESERVED_VARIANT_LAST = CUUID_RESERVED_VARIANT_NEXT-1,
    CUUID_RESERVED_VARIANT_COUNT = CUUID_RESERVED_VARIANT_LAST-CUUID_RESERVED_VARIANT_FIRST+1
};

#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////

#define CUUID_RESERVED_VARIANT_NAME_NONE                    "NONE"
#define CUUID_RESERVED_VARIANT_NAME_FUTURE_DEFINITION       "FUTURE_DEFINITION"
#define CUUID_RESERVED_VARIANT_NAME_MICROSOFT_COMPATIBILITY "MICROSOFT_COMPATIBILITY"
#define CUUID_RESERVED_VARIANT_NAME_RFC4122                 "RFC4122"
#define CUUID_RESERVED_VARIANT_NAME_NCS_COMPATIBILITY       "NCS_COMPATIBILITY"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

///////////////////////////////////////////////////////////////////////
// Struct: sUuid
//
// Author: $author$
//   8/20/2013
//
// This stuct is defined in network (MSB) order.
///////////////////////////////////////////////////////////////////////
#if defined(__MSC__)
#pragma pack(push,1)
#define PACKED
#else // defined(__MSC__) 
#define PACKED __attribute__ ((packed))
#endif // defined(__MSC__) 
struct PACKED sUuid
{
    union {
        BYTE m_b[16];
        UINT16 m_w[8];
        UINT32 m_l[4];
        struct PACKED {
            union {
                BYTE m_b[4];
                UINT16 m_w[2];
                UINT32 m_l;
            } m_timeLow;

            union {
                BYTE m_b[2];
                UINT16 m_w;
            } m_timeMid;

            union {
                BYTE m_b[2];
                UINT16 m_w;
                struct PACKED {
                    UINT8 m_version;
                    UINT8 m_hi;
                };
            } m_timeHiAndVersion;

            union {
                BYTE m_b[2];
                UINT16 m_w;
                struct PACKED {
                    UINT8 m_hiAndRes;
                    UINT8 m_low;
                };
            } m_clockSeq;

            union {
                BYTE m_b[6];
                UINT16 m_w[3];
                struct PACKED {
                    union {
                        BYTE m_b[2];
                        UINT16 m_w;
                    } m_nodeHi;

                    union {
                        BYTE m_b[4];
                        UINT16 m_w[2];
                        UINT32 m_l;
                    } m_nodeLow;
                };
                sMacAddress m_macAddress;
            } m_node;
        };
    };
}
#if defined(__MSC__)
#pragma pack(pop)
#else // defined(__MSC__) 
#undef PACKED
#endif // defined(__MSC__) 
;

extern const char* cuuid_versionName[CUUID_VERSION_COUNT];
extern int cuuid_versionValue[CUUID_VERSION_COUNT];

extern const char* cuuid_reservedVariantName[CUUID_RESERVED_VARIANT_COUNT];
extern int cuuid_reservedVariantMask[CUUID_RESERVED_VARIANT_COUNT];
extern int cuuid_reservedVariantValue[CUUID_RESERVED_VARIANT_COUNT];

#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////

#if defined(WINDOWS) 
// Windows 
#if !defined(CUUID_UNIX_API) 
#define CUUID_WINDOWS_API
#endif // !defined(CUUID_UNIX_API) 
#else // defined(WINDOWS) 
// Unix 
#include <sys/time.h>
#if !defined(CUUID_WINDOWS_API) 
#define CUUID_UNIX_API
#endif // !defined(CUUID_WINDOWS_API) 
#define CUUID_UNIX_API
#endif // defined(WINDOWS) 

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

typedef cInterfaceBase cUuidImplement;
typedef cExportBase cUuidExtend;
///////////////////////////////////////////////////////////////////////
//  Class: cUuid
//
// Author: $author$
//   Date: 8/20/2013
///////////////////////////////////////////////////////////////////////
class c_EXPORT_CLASS cUuid
: virtual public cUuidImplement, public cUuidExtend {
public:
    typedef cUuidImplement cImplements;
    typedef cUuidExtend cExtends;
    ///////////////////////////////////////////////////////////////////////
    //  Constructor: cUuid
    //
    //       Author: $author$
    //         Date: 8/20/2013
    ///////////////////////////////////////////////////////////////////////
    cUuid() {
    }
    virtual ~cUuid() {
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool Generate() {
#if defined(CUUID_WINDOWS_API)
// Windows
        RPC_STATUS status;

        if (RPC_S_OK == (status = UuidCreate((UUID*)(m_uuid.m_b)))) {
            bool success = false;
            RPC_WSTR uuidTString;
            cString uuidString;
            const char* chars;
            LONG length;

            if (RPC_S_OK == (status = UuidToString
                ((UUID*)(m_uuid.m_b), &uuidTString))) {
                if (0 < (length = uuidString.Assign_tchar((TCHAR*)(uuidTString))))
                if ((chars = uuidString.HasChars(length)))
                    c_DB_TRACE("() UUID = \"" << chars << "\"");
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
            success = TimeToMSB();
            return success;
        }
        else if (RPC_S_UUID_LOCAL_ONLY == status)
                c_DB_ERROR("() The UUID is guaranteed to be unique to this computer only");

        else if (RPC_S_UUID_NO_ADDRESS == status)
                c_DB_ERROR("() Cannot get Ethernet or token-ring hardware address for this computer");
#else // defined(CUUID_WINDOWS_API)
// Unix
#endif // defined(CUUID_WINDOWS_API)
        return false;
    }
    virtual bool TimeToMSB() {
        ssize_t length;

        if (0 < (length = SetMSB
            (*m_uuid.m_timeLow.m_b, 
             m_uuid.m_timeLow.m_l, 
             sizeof(m_uuid.m_timeLow.m_l))))

        if (0 < (length = SetMSB
            (*m_uuid.m_timeMid.m_b, 
             m_uuid.m_timeMid.m_w, 
             sizeof(m_uuid.m_timeMid.m_w))))

        if (0 < (length = SetMSB
            (*m_uuid.m_timeHiAndVersion.m_b, 
             m_uuid.m_timeHiAndVersion.m_w, 
             sizeof(m_uuid.m_timeHiAndVersion.m_w))))
            return true;

        return false;
    }
    virtual ssize_t SetMSB
    (BYTE& bytes, size_t value, size_t size) {
        cBYTEBufferWriter writer(bytes, size);
        return writer.WriteMSB(value, size);
    }
    virtual ssize_t WriteX
    (cWriter& writer, char A='A', char F='F', char separator='-') {
        ssize_t count,count2;

        if (0 < (count = WriteX
            (writer, m_uuid.m_timeLow.m_b, 
             sizeof(m_uuid.m_timeLow.m_b), A, F, separator)))

        if (0 < (count2 = WriteX
            (writer, m_uuid.m_timeMid.m_b, 
             sizeof(m_uuid.m_timeMid.m_b), A, F, separator)))

        if (0 < (count2 = WriteX
            (writer, m_uuid.m_timeHiAndVersion.m_b, 
             sizeof(m_uuid.m_timeHiAndVersion.m_b), A, F, separator)))

        if (0 < (count2 = WriteX
            (writer, m_uuid.m_clockSeq.m_b, 
             sizeof(m_uuid.m_clockSeq.m_b), A, F, separator)))

        if (0 < (count2 = WriteX
            (writer, m_uuid.m_node.m_b, 
             sizeof(m_uuid.m_node.m_b), A, F)))
            count += count2;

        return count;
    }
    virtual ssize_t WriteX
    (cWriter& writer, const BYTE* value, size_t size, 
     char A='A', char F='F', char separator=0) {
        ssize_t count, count2;

        if (0 < (count = writer.WriteX(value, size, A, F)))
        if (separator)
        if (0 < (count2 = writer.Write(&separator, sizeof(separator))))
            count += count2;

        return count;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual sUuid& uuid() const {
        return (sUuid&)(m_uuid);
    }
    virtual operator sUuid&() const {
        return (sUuid&)(m_uuid);
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    sUuid m_uuid;
};

#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#endif // _CUUID_HPP 
