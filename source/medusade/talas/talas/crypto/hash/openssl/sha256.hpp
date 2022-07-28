///////////////////////////////////////////////////////////////////////
/// Copyright (c) 1988-2014 $organization$
///
/// This software is provided by the author and contributors ``as is''
/// and any express or implied warranties, including, but not limited to,
/// the implied warranties of merchantability and fitness for a particular
/// purpose are disclaimed. In no event shall the author or contributors
/// be liable for any direct, indirect, incidental, special, exemplary,
/// or consequential damages (including, but not limited to, procurement
/// of substitute goods or services; loss of use, data, or profits; or
/// business interruption) however caused and on any theory of liability,
/// whether in contract, strict liability, or tort (including negligence
/// or otherwise) arising in any way out of the use of this software,
/// even if advised of the possibility of such damage.
///
///   File: sha256.hpp
///
/// Author: $author$
///   Date: 11/11/2014
///////////////////////////////////////////////////////////////////////
#ifndef _TALAS_CRYPTO_HASH_OPENSSL_SHA256_HPP
#define _TALAS_CRYPTO_HASH_OPENSSL_SHA256_HPP

#include "talas/crypto/hash/sha256.hpp"

namespace talas {
namespace crypto {
namespace hash {
namespace openssl {

typedef hash::sha256_implements sha256_implements;
typedef hash::sha256 sha256_extends;
///////////////////////////////////////////////////////////////////////
///  Class: sha256
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS sha256: virtual public sha256_implements, public sha256_extends {
public:
    typedef sha256_implements Implements;
    typedef sha256_extends Extends;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    sha256() {
    }
    virtual ~sha256() {
    }

protected:
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual void initial();
    virtual void final();
    virtual void transform();
    virtual void update(const uint8_t* in, size_t inlen);

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    static uint32_t m_K[KONSTSIZE];
};

} // namespace openssl 
} // namespace hash 
} // namespace crypto 
} // namespace talas 

#endif // _TALAS_CRYPTO_HASH_OPENSSL_SHA256_HPP 
