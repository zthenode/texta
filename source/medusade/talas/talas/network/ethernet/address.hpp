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
///   File: address.hpp
///
/// Author: $author$
///   Date: 6/29/2022
///////////////////////////////////////////////////////////////////////
#ifndef TALAS_NETWORK_ETHERNET_ADDRESS_HPP
#define TALAS_NETWORK_ETHERNET_ADDRESS_HPP

#include "talas/network/ethernet/actual/address.hpp"
#include "xos/base/logged.hpp"
#include "xos/base/wrapped.hpp"
#include "xos/base/string.hpp"

namespace talas {
namespace network {
namespace ethernet {

///////////////////////////////////////////////////////////////////////
/// class addresst
///////////////////////////////////////////////////////////////////////
template 
<class TActual = actual::address, 
 class TLogged = xos::base::logged,
 class TString = xos::base::string,
 class TWrapped = xos::base::wrappedt<TActual>,
 class TExtends = xos::base::wrappert<TWrapped, TLogged>, 
 class TImplements = typename TExtends::Implements>

class exported addresst: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;
    typedef addresst derives;

    typedef TActual actual_t;
    typedef TString string_t;
    
    ///////////////////////////////////////////////////////////////////////
    /// constructor / destructor
    ///////////////////////////////////////////////////////////////////////
    addresst(const addresst& copy): extends(copy) {
    }
    addresst() {
    }
    virtual ~addresst() {
    }

    ///////////////////////////////////////////////////////////////////////
    /// set / clear
    ///////////////////////////////////////////////////////////////////////
    virtual derives set(const actual_t& actual, const string_t& adapter_name, int adapter_index) {
        this->set_actual(actual);
        this->set_adapter_name(adapter_name);
        this->set_adapter_index(adapter_index);
        return *this;
    }
    virtual derives clear() {
        this->clear_actual();
        this->clear_adapter_name();
        this->clear_adapter_index();
        return *this;
    }

    ///////////////////////////////////////////////////////////////////////
    /// get_...
    ///////////////////////////////////////////////////////////////////////
    virtual const actual_t* get_first(string_t& adapter_name) const {
        return 0;
    }
    virtual const actual_t* get_last(string_t& adapter_name) const {
        return 0;
    }
    virtual const actual_t* get_next(string_t& adapter_name, const actual_t* to) const {
        return 0;
    }
    virtual const actual_t* get_prev(string_t& adapter_name, const actual_t* to) const {
        return 0;
    }

    ///////////////////////////////////////////////////////////////////////
    /// operator != / operator ==
    ///////////////////////////////////////////////////////////////////////
    virtual bool operator != (const derives& to) const {
        return (0 != (::memcmp(&this->actual(), &to.actual(), sizeof(actual_t))));
    }
    virtual bool operator == (const derives& to) const {
        return (0 == (::memcmp(&this->actual(), &to.actual(), sizeof(actual_t))));
    }

    ///////////////////////////////////////////////////////////////////////
    /// ...adapter...
    ///////////////////////////////////////////////////////////////////////
    virtual actual_t* set_to_adapter(const string_t& named) {
        return 0;
    }
    virtual actual_t* set_to_adapter(int index) {
        return 0;
    }
    virtual actual_t* set_to_adapter() {
        return set_to_first_adapter();
    }
    virtual actual_t* set_to_first_adapter() {
        return set_to_adapter(0);
    }
    virtual actual_t* set_to_last_adapter() {
        return set_to_adapter(-1);
    }
    virtual string_t& set_adapter_name(const string_t& to) {
        adapter_name_.assign(to);
        return adapter_name_;
    }
    virtual string_t& clear_adapter_name() {
        adapter_name_.clear();
        return adapter_name_;
    }
    virtual string_t& adapter_name() const {
        return (string_t&)adapter_name_;
    }
    virtual int& set_adapter_index(const int& to) {
        adapter_index_ = to;
        return (int&)adapter_index_;
    }
    virtual int& clear_adapter_index() {
        adapter_index_ = -1;
        return (int&)adapter_index_;
    }
    virtual int& adapter_index() const {
        return (int&)adapter_index_;
    }

    ///////////////////////////////////////////////////////////////////////
    /// ...actual...
    ///////////////////////////////////////////////////////////////////////
    virtual string_t& set_actual_string(const actual_t& actual) {
        const char *separator = 0, *separator_chars = ":";
        actual_string_.clear();
        for (size_t i = 0; i < sizeof(actual_t); ++i) {
            if (separator) {
                actual_string_.append(separator);
            } else {
                separator = separator_chars;
            }
            actual_string_.appendx(actual.m_b + i, 1, true);
        }
        return actual_string_;
    }
    virtual string_t& clear_actual_string() {
        actual_string_.clear();
        return actual_string_;
    }
    virtual string_t& actual_string() const {
        return (string_t&)actual_string_;
    }
    virtual size_t actual_size() const {
        return sizeof(actual_t);
    }
    virtual actual_t& set_actual(const actual_t& to) {
        ::memcpy(&this->actual(), &to, sizeof(actual_t));
        this->set_actual_string(to);
        return this->actual();
    }
    virtual actual_t& clear_actual() {
        ::memset(&this->actual(), 0, sizeof(actual_t));
        this->clear_actual_string();
        return this->actual();
    }
    virtual actual_t& actual() const {
        return this->wrapped();
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    string_t actual_string_, adapter_name_;
    int adapter_index_;
}; /// class addresst
typedef addresst<> address;

} /// namespace ethernet 
} /// namespace network 
} /// namespace talas 

#endif /// ndef TALAS_NETWORK_ETHERNET_ADDRESS_HPP 