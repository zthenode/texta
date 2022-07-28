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
///   File: identifier.hpp
///
/// Author: $author$
///   Date: 6/29/2022
///////////////////////////////////////////////////////////////////////
#ifndef TALAS_NETWORK_UNIVERSAL_UNIQUE_IDENTIFIER_HPP
#define TALAS_NETWORK_UNIVERSAL_UNIQUE_IDENTIFIER_HPP

#include "talas/network/universal/unique/actual/identifier.hpp"
#include "xos/io/string/writer.hpp"
#include "xos/base/wrapped.hpp"

namespace talas {
namespace network {
namespace universal {
namespace unique {

///////////////////////////////////////////////////////////////////////
/// class identifiert
///////////////////////////////////////////////////////////////////////
template 
<class TActual = actual::identifier,
 class TStringWriter = xos::io::string::writer,
 class TWrapped = xos::base::wrappedt<TActual>,
 class TExtends = xos::base::wrappert<TWrapped>, 
 class TImplements = typename TExtends::Implements>

class exported identifiert: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;
    typedef identifiert derives;

    typedef TActual actual_t;
    typedef TStringWriter string_writer_t;
    typedef typename string_writer_t::string_t string_t;
    typedef typename string_t::char_t char_t;

    ///////////////////////////////////////////////////////////////////////
    /// constructor / destructor
    ///////////////////////////////////////////////////////////////////////
    identifiert(const identifiert& copy): extends(copy) {
    }
    identifiert() {
    }
    virtual ~identifiert() {
    }

    ///////////////////////////////////////////////////////////////////////
    /// generate / clear
    ///////////////////////////////////////////////////////////////////////
    virtual actual_t* generate(int ethernet_index) {
        return generate_time_based(ethernet_index);
    }
    virtual actual_t* generate() {
        return generate_time_based();
    }
    virtual actual_t* generate_time_based() {
        return generate_time_based(0);
    }
    virtual actual_t* generate_time_based(int ethernet_index) {
        return 0;
    }
    virtual void clear() {
        memset(&this->actual(), 0, sizeof(actual_t));
        string_.clear();
    }

    ///////////////////////////////////////////////////////////////////////
    /// ...string
    ///////////////////////////////////////////////////////////////////////
    virtual string_t& set_string(const actual_t& to) {
        string_writer_t writer(string_);
        string_.clear();
        writeX(writer);
        return (string_t&)string_;
    }
    virtual string_t& string() const {
        return (string_t&)string_;
    }

    ///////////////////////////////////////////////////////////////////////
    /// operator != / == / actual_t&
    ///////////////////////////////////////////////////////////////////////
    virtual bool operator != (const derives& to) const {
        return (0 != (memcmp(&this->actual(), &to.actual(), sizeof(actual_t))));
    }
    virtual bool operator == (const derives& to) const {
        return (0 == (memcmp(&this->actual(), &to.actual(), sizeof(actual_t))));
    }
    virtual operator actual_t&() const {
        return actual();
    }
    virtual actual_t& actual() const {
        return this->wrapped();
    }

protected:
    ///////////////////////////////////////////////////////////////////////
    /// writeX
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t writeX(string_writer_t& writer, char_t A = 'A', char_t separator = '-') const {
        actual_t& actual = this->actual();
        ssize_t count = 0, count2 = 0;

        if (0 < (count = writeX
            (writer, actual.m_timeLow.m_b, sizeof(actual.m_timeLow.m_b), A, separator))) {

            if (0 < (count2 = writeX
                (writer, actual.m_timeMid.m_b, sizeof(actual.m_timeMid.m_b), A, separator))) {
    
                count += count2;
                if (0 < (count2 = writeX
                    (writer, actual.m_timeHiAndVersion.m_b, sizeof(actual.m_timeHiAndVersion.m_b), A, separator))) {
        
                    count += count2;
                    if (0 < (count2 = writeX
                        (writer, actual.m_clockSeq.m_b, sizeof(actual.m_clockSeq.m_b), A, separator))) {
            
                        count += count2;
                        if (0 < (count2 = writeX
                            (writer, actual.m_node.m_b, sizeof(actual.m_node.m_b), A))) {
                            count += count2;
                        }
                    }
                }
            }
        }
        return count;
    }
    virtual ssize_t writeX
    (string_writer_t& writer, const uint8_t* value, size_t size, char_t A = 'A', char_t separator = 0) const {
        const bool upperCase = (A == 'A');
        ssize_t count = 0, count2 = 0;

        if (0 < (count = writer.writex(value, size, upperCase))) {
            if (separator) {
                if (0 < (count2 = writer.write(&separator, sizeof(separator)))) {
                    count += count2;
                }
            }
        }
        return count;
    }

    ///////////////////////////////////////////////////////////////////////
    /// ...to_msb
    ///////////////////////////////////////////////////////////////////////
    virtual uint8_t& time_to_msb(actual_t& actual) {
        to_msb(*actual.m_timeLow.m_b, actual.m_timeLow.m_l, sizeof(actual.m_timeLow.m_l));
        to_msb(*actual.m_timeMid.m_b, actual.m_timeMid.m_w, sizeof(actual.m_timeMid.m_w));
        to_msb(*actual.m_timeHiAndVersion.m_b, actual.m_timeHiAndVersion.m_w, sizeof(actual.m_timeHiAndVersion.m_w));
        return *actual.m_b;
    }
    virtual uint8_t& to_msb(uint8_t& to, unsigned long value, size_t size) const {
        unsigned long msbValue = 0;
        for (int b = 0; b < size; ++b) {
            msbValue <<= 8;
            msbValue |= (value & 0xFF);
            value >>= 8;
        }
        for (int b = 0; b < size; ++b) {
            (&to)[b] = (msbValue & 0xFF);
            msbValue >>= 8;
        }
        return to;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    string_t string_;
}; /// class identifiert
typedef identifiert<> identifier;

} /// namespace unique 
} /// namespace universal 
} /// namespace network 
} /// namespace talas 

#endif /// ndef TALAS_NETWORK_UNIVERSAL_UNIQUE_IDENTIFIER_HPP 