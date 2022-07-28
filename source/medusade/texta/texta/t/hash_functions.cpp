///////////////////////////////////////////////////////////////////////
/// Copyright (c) 1988-2022 $organization$
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
///   File: hash_functions.cpp
///
/// Author: $author$
///   Date: 6/28/2022
///////////////////////////////////////////////////////////////////////
#include "texta/t/functions.hpp"
#include "talas/crypto/hash/base.hpp"
#include "talas/crypto/hash/sha512.hpp"
#include "talas/crypto/hash/implementation/implementation.hpp"

namespace texta {
namespace t {

///////////////////////////////////////////////////////////////////////
/// class hash_function
///////////////////////////////////////////////////////////////////////
class EXPORT_CLASS hash_function: public function_extend {
public:
    typedef function_extend Extends;
    typedef hash_function Derives;

    typedef talas::crypto::hash::base algorithm_t;
    enum { hash_size = talas::crypto::hash::sha512::HASHSIZE };
    
    ///////////////////////////////////////////////////////////////////////
    /// constructor / destructor
    ///////////////////////////////////////////////////////////////////////
    hash_function(const char *name, const char *description): Extends(name, description) {
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool expand
    (algorithm_t &algorithm, 
     output &out, processor &p, const function_argument_list &args) const {
        function_argument *arg = 0;
        ssize_t size = 0;
        byte_t hash[hash_size];

        if (0 > (algorithm.initialize())) {
            return false;
        } else {
            if ((arg = args.first_argument())) {
                do {
                    const char *chars = 0;
                    size_t length = 0;
    
                    if ((chars = arg->has_chars(length))) {
                        if (0 > (size = algorithm.hash(chars, length))) {
                            return false;
                        }
                    }
                } while ((arg = arg->next_argument()));
            }
            if (0 > (size = algorithm.finalize(hash, hash_size))) {
                return false;
            } else {
                for (byte_t *byte = hash; size; --size, ++byte) {
                    byte_t b = *byte, n1 = (b >> 4), n2 = (b & 15);
                    char x1 = n2x(n1), x2 = n2x(n2);

                    if (0 > (out.write(&x1, 1))) {
                        return false;
                    } else {
                        if (0 > (out.write(&x2, 1))) {
                            return false;
                        }
                    }
                }
            }
        }
        return true;
    }
    inline char n2x(byte_t n) const {
        if (9 < n) {
            return 'a'+(n - 10);
        }
        return '0'+n;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
}; /// class hash_function

///////////////////////////////////////////////////////////////////////
/// class md5_function
///////////////////////////////////////////////////////////////////////
class EXPORT_CLASS md5_function: public hash_function {
public:
    typedef hash_function Extends;
    typedef md5_function Derives;

    typedef talas::crypto::hash::implementation::md5 algorithm_t;

    ///////////////////////////////////////////////////////////////////////
    /// constructor / destructor
    ///////////////////////////////////////////////////////////////////////
    md5_function(const char *name, const char *description): Extends(name, description) {
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool expand(output &out, processor &p, const function_argument_list &args) const {
        algorithm_t algorithm;
        return Extends::expand(algorithm, out, p, args);
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
}; /// class md5_function
md5_function md5("md5", "md5(string,...)");

///////////////////////////////////////////////////////////////////////
/// class sha1_function
///////////////////////////////////////////////////////////////////////
class EXPORT_CLASS sha1_function: public hash_function {
public:
    typedef hash_function Extends;
    typedef sha1_function Derives;

    typedef talas::crypto::hash::implementation::sha1 algorithm_t;

    ///////////////////////////////////////////////////////////////////////
    /// constructor / destructor
    ///////////////////////////////////////////////////////////////////////
    sha1_function(const char *name, const char *description): Extends(name, description) {
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool expand(output &out, processor &p, const function_argument_list &args) const {
        algorithm_t algorithm;
        return Extends::expand(algorithm, out, p, args);
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
}; /// class sha1_function
sha1_function sha1("sha1", "sha1(string,...)");

///////////////////////////////////////////////////////////////////////
/// class sha2_function
///////////////////////////////////////////////////////////////////////
class EXPORT_CLASS sha2_function: public hash_function {
public:
    typedef hash_function Extends;
    typedef sha2_function Derives;

    typedef talas::crypto::hash::implementation::sha256 algorithm_t;

    ///////////////////////////////////////////////////////////////////////
    /// constructor / destructor
    ///////////////////////////////////////////////////////////////////////
    sha2_function(const char *name, const char *description): Extends(name, description) {
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool expand(output &out, processor &p, const function_argument_list &args) const {
        algorithm_t algorithm;
        return Extends::expand(algorithm, out, p, args);
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
}; /// class sha2_function
sha2_function sha2("sha2", "sha2(string,...)"), 
              sha256("sha256", "sha256(string,...)");

///////////////////////////////////////////////////////////////////////
/// class sha5_function
///////////////////////////////////////////////////////////////////////
class EXPORT_CLASS sha5_function: public hash_function {
public:
    typedef hash_function Extends;
    typedef sha5_function Derives;

    typedef talas::crypto::hash::implementation::sha512 algorithm_t;

    ///////////////////////////////////////////////////////////////////////
    /// constructor / destructor
    ///////////////////////////////////////////////////////////////////////
    sha5_function(const char *name, const char *description): Extends(name, description) {
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool expand(output &out, processor &p, const function_argument_list &args) const {
        algorithm_t algorithm;
        return Extends::expand(algorithm, out, p, args);
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
}; /// class sha5_function
sha5_function sha5("sha5", "sha5(string,...)"), 
              sha512("sha512", "sha512(string,...)");

} /// namespace t 
} /// namespace texta 
