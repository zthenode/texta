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
///   File: network_functions.cpp
///
/// Author: $author$
///   Date: 6/29/2022
///////////////////////////////////////////////////////////////////////
#include "texta/t/functions.hpp"
#include "talas/network/ethernet/os/address.hpp"
#include "talas/network/universal/unique/os/identifier.hpp"

namespace texta {
namespace t {

///////////////////////////////////////////////////////////////////////
/// class ethernet_function
///////////////////////////////////////////////////////////////////////
class EXPORT_CLASS ethernet_function: public function_extend {
public:
    typedef function_extend Extends;
    typedef ethernet_function Derives;

    typedef talas::network::ethernet::os::address ethernet_t;
    typedef typename ethernet_t::string_t ethernet_string_t;
    typedef typename ethernet_string_t::char_t ethernet_char_t;

    ///////////////////////////////////////////////////////////////////////
    /// constructor / destructor
    ///////////////////////////////////////////////////////////////////////
    ethernet_function(const char *name, const char *description): Extends(name, description) {
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool expand(output &out, processor &p, const function_argument_list &args) const {
        int ethernet_index = 0;
        ethernet_t ethernet;

        if ((ethernet.set_to_adapter(ethernet_index))) {
            const ethernet_string_t &ethernet_string = ethernet.actual_string();
            const ethernet_char_t *ethernet_chars = 0;
            size_t ethernet_length = 0;
            
            if ((ethernet_chars = ethernet_string.has_chars(ethernet_length))) {
                out.write(ethernet_chars, ethernet_length);
            }
        }
        return true;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
}; /// class ethernet_function
ethernet_function en("en", "en(number)");

///////////////////////////////////////////////////////////////////////
/// class uuid_function
///////////////////////////////////////////////////////////////////////
class EXPORT_CLASS uuid_function: public function_extend {
public:
    typedef function_extend Extends;
    typedef uuid_function Derives;

    typedef talas::network::universal::unique::os::identifier uuid_t;
    typedef typename uuid_t::string_t uuid_string_t;
    typedef typename uuid_string_t::char_t uuid_char_t;

    ///////////////////////////////////////////////////////////////////////
    /// constructor / destructor
    ///////////////////////////////////////////////////////////////////////
    uuid_function(const char *name, const char *description): Extends(name, description) {
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool expand(output &out, processor &p, const function_argument_list &args) const {
        int ethernet_index = 0;
        uuid_t uuid;

        if ((uuid.generate_time_based(ethernet_index))) {
            const uuid_string_t &uuid_string = uuid.string();
            const uuid_char_t *uuid_chars = 0;
            size_t uuid_length = 0;
            
            if ((uuid_chars = uuid_string.has_chars(uuid_length))) {
                out.write(uuid_chars, uuid_length);
            }
        }
        return true;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
}; /// class uuid_function
uuid_function uuid("uuid", "uuid(number)");

} /// namespace t 
} /// namespace texta 
