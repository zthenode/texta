///////////////////////////////////////////////////////////////////////
/// Copyright (c) 1988-2020 $organization$
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
///   File: implement.hpp
///
/// Author: $author$
///   Date: 4/14/2020
///////////////////////////////////////////////////////////////////////
#ifndef XOS_LANGUAGE_TEXTA_PROCESSOR_IMPLEMENT_HPP
#define XOS_LANGUAGE_TEXTA_PROCESSOR_IMPLEMENT_HPP

#include "xos/language/texta/processor/exception.hpp"
#include "xos/language/texta/processor/observer.hpp"
#include "xos/base/logged.hpp"
#include "xos/base/logger.hpp"
#include "xos/io/reader.hpp"
#include "xos/io/writer.hpp"

namespace xos {
namespace language {
namespace texta {
namespace processor {

/// class implementt
template 
<class TOutput = io::char_writer, class TInput = io::char_reader, class TImplements = logged>
class exported implementt: virtual public TImplements {
public:
    typedef TImplements implements;
    typedef implementt derives;

    typedef processor::observer observer_t;
    
    typedef processor::exception exception_t;
    typedef processor::exception_status_t exception_status_t;
    enum { exception_exit = processor::exception_exit };

    typedef TOutput output_t;
    typedef TInput input_t;
    typedef typename input_t::sized_t char_t;
    typedef xos::stringt<char_t> string_t;
    
    /// init / fini
    virtual bool init() {
        return true;
    }
    virtual bool fini() {
        return true;
    }

    /// ...mark
    virtual char_t set_mark(char_t to) {
        return mark();
    }
    virtual char_t mark() const {
        return default_mark();
    }
    virtual char_t default_mark() const {
        return (char_t)'%';
    }

    /// ...observer
    virtual observer_t* set_observer(observer_t* to) const {
        return observer();
    }
    virtual observer_t* observer() const {
        return 0;
    }
    
    /// ...variable
    virtual const char_t* set_variable(const string_t& name, const string_t& to) {
        const char_t* value = 0;
        return value;
    }
    virtual const char_t* set_variable(const char_t* name, const char_t* to) {
        const char_t* value = 0;
        value = set_variable(string_t(name), string_t(to));
        return value;
    }
    virtual const char_t* variable(const string_t& name) {
        const char_t* value = 0;
        return value;
    }
    virtual const char_t* variable(const char_t* name) {
        const char_t* value = 0;
        value = variable(string_t(name));
        return value;
    }
    virtual const char_t* set_input_variable(const string_t& to) {
        const char_t* value = 0;
        value = set_variable(string_t(input_variable_name()), to);
        return value;
    }
    virtual const char_t* set_input_variable(const char_t* to) {
        const char_t* value = 0;
        value = set_input_variable(string_t(to));
        return value;
    }
    virtual const char_t* input_variable_name() const {
        const char_t* value = "input";
        return value;
    }
    
    /// expand
    virtual bool expand(output_t& out, input_t& in) {
        bool success = true;
        char_t c = 0;

        set_depth(0);
        try {
            success = expand(c, out, in);
        } catch (const exception_t& e) {
            LOGGER_IS_LOGGED_DEBUG("...caught exception_t e(" << e.status_to_chars() << ")");
            on_processor_exception(e);
            return true;
        }
        return success;
    }

    /// ...instance...
    static implement* get_instance() {
        implement* instance = derives::the_instance();
        return instance;
    }
    static void free_instance(implement* instance) {
    }
protected:
    static implement*& the_instance() {
        static implement* the_instance = 0;
        return the_instance;
    }

    /// expand
    virtual bool expand(char_t& nextc, output_t& out, input_t& in) {
        bool success = true;
        size_t this_depth = depth();
        try {
            this->exit();
        } catch (const exception_t& e) {
            LOGGER_IS_LOGGED_DEBUG("...caught exception_t e(" << e.status_to_chars() << ")");
            set_depth(this_depth);
            LOGGER_IS_LOGGED_DEBUG("throw exception_t e(" << e.status_to_chars() << ")");
            throw e;
        }
        return success;
    }

    /// exit
    virtual bool exit() {
        LOGGER_IS_LOGGED_DEBUG("...throw exception_t(exception_exit)...");
        throw exception_t(exception_exit);
        return true;
    }

    /// ...depth
    virtual size_t set_depth(size_t to) {
        return depth();
    }
    virtual size_t depth() const {
        return 0;
    }

    /// on_processor_exception
    virtual void on_processor_exception(const exception_t& e) {
    }
}; /// class implementt

/// class implement
class exported implement: virtual public implementt<> {
public:
    typedef implementt<> implements;
    typedef implement derives;

    typedef typename implements::exception_t exception_t;
    typedef typename implements::exception_status_t exception_status_t;
    enum { exception_exit = implements::exception_exit };

    typedef typename implements::output_t output_t;
    typedef typename implements::input_t input_t;
    typedef typename implements::char_t char_t;
    typedef typename implements::string_t string_t;
    
protected:
    /// on_processor_exception
    virtual void on_processor_exception(const exception_t& e) {
        observer_t* observer = 0;
        if ((observer = this->observer())) {
            observer->on_processor_exception(*this, e);
        }
    }
}; /// class implement

/// class extendt
template <class TExtends = xos::extend, class TImplements = processor::implement>
class exported extendt: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;
    typedef extendt derives;

    typedef typename implements::exception_t exception_t;
    typedef typename implements::exception_status_t exception_status_t;
    enum { exception_exit = implements::exception_exit };

    typedef typename implements::output_t output_t;
    typedef typename implements::input_t input_t;
    typedef typename implements::char_t char_t;
    typedef typename implements::string_t string_t;
    
    /// constructor / destructor
    extendt() {
        implements*& the_instance = implements::the_instance();
        if (!(the_instance)) {
            the_instance = this;
        }
    }
    virtual ~extendt() {
        implements*& the_instance = implements::the_instance();
        if ((the_instance == this)) {
            the_instance = 0;
        }
    }
private:
    extendt(const extendt& copy): extends(copy) {
    }
public:
protected:
}; /// class extendt
typedef extendt<> extend;

} /// namespace processor
} /// namespace texta
} /// namespace language
} /// namespace xos

#endif /// ndef XOS_LANGUAGE_TEXTA_PROCESSOR_IMPLEMENT_HPP 
