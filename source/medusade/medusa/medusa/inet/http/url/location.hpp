///////////////////////////////////////////////////////////////////////
/// Copyright (c) 1988-2018 $organization$
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
///   File: location.hpp
///
/// Author: $author$
///   Date: 10/27/2018
///////////////////////////////////////////////////////////////////////
#ifndef _MEDUSA_INET_HTTP_URL_LOCATION_HPP
#define _MEDUSA_INET_HTTP_URL_LOCATION_HPP

#include "medusa/inet/http/url/part.hpp"
#include "medusa/inet/http/url/scheme.hpp"
#include "medusa/inet/http/url/authority.hpp"
#include "medusa/inet/http/url/path.hpp"
#include "medusa/inet/http/url/query.hpp"
#include "medusa/inet/http/url/fragment.hpp"

namespace medusa {
namespace inet {
namespace http {
namespace url {

typedef part::Implements location_implements;
typedef part location_extends;
///////////////////////////////////////////////////////////////////////
///  Class: location
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS location: virtual public location_implements, public location_extends {
public:
    typedef location_implements Implements;
    typedef location_extends Extends;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    location(const char_t* copy, size_t length): Extends(copy, length) { separate_parts(); }
    location(const char_t* copy): Extends(copy) { separate_parts(); }
    location(const string_t& copy): Extends(copy) { separate_parts(); }
    location(const location& copy): Extends(copy) { separate_parts(); }
    location() {}
    virtual ~location() {}

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t clear_parts() { 
        ssize_t count = 0;
        size_t length = 0;
        if ((length = scheme_.length())) {
            scheme_.clear();
            count += length;
        }
        if ((length = authority_.length())) {
            authority_.clear();
            count += length;
        }
        if ((length = path_.length())) {
            path_.clear();
            count += length;
        }
        if ((length = query_.length())) {
            query_.clear();
            count += length;
        }
        if ((length = fragment_.length())) {
            fragment_.clear();
            count += length;
        }
        return count; 
    }
    virtual ssize_t combine_parts() {
        ssize_t count = 0;
        size_t length = 0;
        const char_t* chars = 0;
        this->clear();
        if ((chars = scheme_.has_chars(length))) {
            this->append(chars, length);
            this->append(":");
            count = this->length();
        }
        if ((chars = authority_.has_chars(length))) {
            this->append("//");
            this->append(chars, length);
            count = this->length();
        }
        if ((chars = path_.has_chars(length))) {
            this->append("/");
            this->append(chars, length);
            count = this->length();
        }
        if ((chars = query_.has_chars(length))) {
            this->append("?");
            this->append(chars, length);
            count = this->length();
        }
        if ((chars = fragment_.has_chars(length))) {
            this->append("#");
            this->append(chars, length);
            count = this->length();
        }
        return count; 
    }
    virtual ssize_t separate_parts() { 
        return 0; 
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual const url::scheme& set_scheme(const string_t& to) { 
        scheme_.assign(to);
        scheme_.separate_parts();
        combine_parts();
        return scheme_; 
    }
    virtual const url::scheme& scheme() const { 
        return scheme_; 
    }
    virtual const url::authority& set_authority(const string_t& to) { 
        authority_.assign(to);
        authority_.separate_parts();
        combine_parts();
        return authority_; 
    }
    virtual const url::authority& authority() const { 
        return authority_; 
    }
    virtual const url::path& set_path(const string_t& to) { 
        path_.assign(to);
        path_.separate_parts();
        combine_parts();
        return path_; 
    }
    virtual const url::path& path() const { 
        return path_; 
    }
    virtual const url::query& set_query(const string_t& to) { 
        query_.assign(to);
        query_.separate_parts();
        combine_parts();
        return query_; 
    }
    virtual const url::query& query() const { 
        return query_; 
    }
    virtual const url::fragment& set_fragment(const string_t& to) { 
        fragment_.assign(to);
        fragment_.separate_parts();
        combine_parts();
        return fragment_; 
    }
    virtual const url::fragment& fragment() const { 
        return fragment_; 
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    url::scheme scheme_;
    url::authority authority_;
    url::path path_;
    url::query query_;
    url::fragment fragment_;
}; /// class _EXPORT_CLASS location

} /// namespace url
} /// namespace http
} /// namespace inet
} /// namespace medusa

#endif ///ndef _MEDUSA_INET_HTTP_URL_LOCATION_HPP
