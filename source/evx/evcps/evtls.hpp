///////////////////////////////////////////////////////////////////////
//   File: evtls.hpp
//
// Author: $author$
//   Date: 11/21/2007
///////////////////////////////////////////////////////////////////////

#ifndef _EVTLS_HPP
#define _EVTLS_HPP

#define TLS_VERSION_MAJOR 3
#define TLS_VERSION_MINOR 1

#define TLS_CLIENT_LABEL "client"
#define TLS_SERVER_LABEL "server"

#define TLS_PRE_MASTER_SECRET_RANDOM_SIZE 46

#define TLS_MASTER_SECRET_SIZE 48
#define TLS_MASTER_SECRET_LABEL "master secret"

#define TLS_FINISHED_SIZE 12
#define TLS_FINISHED_LABEL "finished"

#define TLS_CLIENT_FINISHED_LABEL \
    TLS_CLIENT_LABEL \
    " " TLS_FINISHED_LABEL

#define TLS_SERVER_FINISHED_LABEL \
    TLS_SERVER_LABEL \
    " " TLS_FINISHED_LABEL

#define TLS_KEY_BLOCK_LABEL "key expansion"

///////////////////////////////////////////////////////////////////////
//   Enum:  
//
// Author: $author$
//   Date: 12/1/2007
///////////////////////////////////////////////////////////////////////
enum 
{
    TLS_MAC_ALGORITHM_NULL,
    TLS_MAC_ALGORITHM_MD5,
    TLS_MAC_ALGORITHM_SHA1
};

///////////////////////////////////////////////////////////////////////
//   Enum:  
//
// Author: $author$
//   Date: 12/1/2007
///////////////////////////////////////////////////////////////////////
enum 
{
    TLS_BULK_CIPHER_ALGORITHM_NULL,

    TLS_BULK_CIPHER_ALGORITHM_RC4,
    TLS_BULK_CIPHER_ALGORITHM_RC2,
    TLS_BULK_CIPHER_ALGORITHM_DES,
    TLS_BULK_CIPHER_ALGORITHM_3DES,
    TLS_BULK_CIPHER_ALGORITHM_DES40,
    TLS_BULK_CIPHER_ALGORITHM_IDEA,

    TLS_BULK_CIPHER_ALGORITHM_AES128
};

///////////////////////////////////////////////////////////////////////
//   Enum:  
//
// Author: $author$
//   Date: 12/1/2007
///////////////////////////////////////////////////////////////////////
enum 
{
    TLS_CIPHER_TYPE_STREAM,
    TLS_CIPHER_TYPE_BLOCK
};

///////////////////////////////////////////////////////////////////////
//   Enum:  
//
// Author: $author$
//   Date: 12/1/2007
///////////////////////////////////////////////////////////////////////
enum 
{
    TLS_CIPHER_EXPORTABLE,
    TLS_CIPHER_UNEXPORTABE
};

///////////////////////////////////////////////////////////////////////
//   Enum:  
//
// Author: $author$
//   Date: 12/1/2007
///////////////////////////////////////////////////////////////////////
enum 
{
    TLS_CONNECTION_END_SERVER,
    TLS_CONNECTION_END_CLIENT
};

///////////////////////////////////////////////////////////////////////
//   Enum:  
//
// Author: $author$
//   Date: 11/24/2007
///////////////////////////////////////////////////////////////////////
enum 
{
    TLS_HANDSHAKE_TYPE_HELLO_REQUEST = 0,

    TLS_HANDSHAKE_TYPE_CLIENT_HELLO = 1,
    TLS_HANDSHAKE_TYPE_SERVER_HELLO = 2,

    TLS_HANDSHAKE_TYPE_CLIENT_KEY_EXCHANGE = 16,
    TLS_HANDSHAKE_TYPE_SERVER_KEY_EXCHANGE = 12,
    TLS_HANDSHAKE_TYPE_SERVER_HELLO_DONE = 14,

    TLS_HANDSHAKE_TYPE_CERTIFICATE = 11,
    TLS_HANDSHAKE_TYPE_CERTIFICATE_REQUEST = 13,
    TLS_HANDSHAKE_TYPE_CERTIFICATE_VERIFY = 15,

    TLS_HANDSHAKE_TYPE_FINISHED = 20,

    TLS_HANDSHAKE_TYPE_NONE = 255
};

///////////////////////////////////////////////////////////////////////
//   Enum:  
//
// Author: $author$
//   Date: 11/23/2007
///////////////////////////////////////////////////////////////////////
enum 
{
    TLS_CONTENT_TYPE_CHANGE_CIPHER_SPEC = 20,
    TLS_CONTENT_TYPE_ALERT              = 21,
    TLS_CONTENT_TYPE_HANDSHAKE          = 22,
    TLS_CONTENT_TYPE_APPLICATION_DATA   = 23
};

///////////////////////////////////////////////////////////////////////
//   Enum:  
//
// Author: $author$
//   Date: 11/30/2007
///////////////////////////////////////////////////////////////////////
enum 
{
    TLS_CHANGE_CIPHER_SPEC_TYPE_CHANGE_CIPHER_SPEC = 1
};

///////////////////////////////////////////////////////////////////////
//   Enum:  
//
// Author: $author$
//   Date: 11/21/2007
///////////////////////////////////////////////////////////////////////
enum 
{
    TLS_NULL_WITH_NULL_NULL                = 0x00,

    TLS_RSA_WITH_NULL_MD5                  = 0x01,
    TLS_RSA_WITH_NULL_SHA                  = 0x02,
    TLS_RSA_EXPORT_WITH_RC4_40_MD5         = 0x03,
    TLS_RSA_WITH_RC4_128_MD5               = 0x04,
    TLS_RSA_WITH_RC4_128_SHA               = 0x05,
    TLS_RSA_EXPORT_WITH_RC2_CBC_40_MD5     = 0x06,
    TLS_RSA_WITH_IDEA_CBC_SHA              = 0x07,
    TLS_RSA_EXPORT_WITH_DES40_CBC_SHA      = 0x08,
    TLS_RSA_WITH_DES_CBC_SHA               = 0x09,
    TLS_RSA_WITH_3DES_EDE_CBC_SHA          = 0x0A,

    TLS_DH_DSS_EXPORT_WITH_DES40_CBC_SHA   = 0x0B,
    TLS_DH_DSS_WITH_DES_CBC_SHA            = 0x0C,
    TLS_DH_DSS_WITH_3DES_EDE_CBC_SHA       = 0x0D,
    TLS_DH_RSA_EXPORT_WITH_DES40_CBC_SHA   = 0x0E,
    TLS_DH_RSA_WITH_DES_CBC_SHA            = 0x0F,
    TLS_DH_RSA_WITH_3DES_EDE_CBC_SHA       = 0x10,

    TLS_DHE_DSS_EXPORT_WITH_DES40_CBC_SHA  = 0x11,
    TLS_DHE_DSS_WITH_DES_CBC_SHA           = 0x12,
    TLS_DHE_DSS_WITH_3DES_EDE_CBC_SHA      = 0x13,
    TLS_DHE_RSA_EXPORT_WITH_DES40_CBC_SHA  = 0x14,
    TLS_DHE_RSA_WITH_DES_CBC_SHA           = 0x15,
    TLS_DHE_RSA_WITH_3DES_EDE_CBC_SHA      = 0x16,

    //
    // AES RFC-3268
    //

    TLS_RSA_WITH_AES_128_CBC_SHA           = 0x2F,
    TLS_DH_DSS_WITH_AES_128_CBC_SHA        = 0x30,
    TLS_DH_RSA_WITH_AES_128_CBC_SHA        = 0x31,
    TLS_DHE_DSS_WITH_AES_128_CBC_SHA       = 0x32,
    TLS_DHE_RSA_WITH_AES_128_CBC_SHA       = 0x33,
    TLS_DH_anon_WITH_AES_128_CBC_SHA       = 0x34,

    TLS_RSA_WITH_AES_256_CBC_SHA           = 0x35,
    TLS_DH_DSS_WITH_AES_256_CBC_SHA        = 0x36,
    TLS_DH_RSA_WITH_AES_256_CBC_SHA        = 0x37,
    TLS_DHE_DSS_WITH_AES_256_CBC_SHA       = 0x38,
    TLS_DHE_RSA_WITH_AES_256_CBC_SHA       = 0x39,
    TLS_DH_anon_WITH_AES_256_CBC_SHA       = 0x3A
};

///////////////////////////////////////////////////////////////////////
//   Enum:  
//
// Author: $author$
//   Date: 11/21/2007
///////////////////////////////////////////////////////////////////////
enum 
{
    TLS_COMPRESSION_METHOD_NULL = 0
};

#endif // _EVTLS_HPP
