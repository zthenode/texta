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
///   File: implemented.hpp
///
/// Author: $author$
///   Date: 4/16/2020
///////////////////////////////////////////////////////////////////////
#ifndef XOS_LANGUAGE_TEXTA_PROCESSOR_XDE_IMPLEMENTED_HPP
#define XOS_LANGUAGE_TEXTA_PROCESSOR_XDE_IMPLEMENTED_HPP

#include "xos/language/texta/processor/xde/cTInput.hpp"
#include "xos/language/texta/processor/xde/cTOutput.hpp"
#include "xos/language/texta/processor/implement.hpp"
#include "ct.hxx"

namespace xos {
namespace language {
namespace texta {
namespace processor {
namespace xde {

/// class implementedt
template <class TExtends = processor::extend, class TImplements = typename TExtends::implements>
class exported implementedt: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;
    typedef implementedt derives;

    typedef typename extends::exception_t exception_t;
    typedef typename extends::exception_status_t exception_status_t;
    enum { exception_exit = extends::exception_exit };

    typedef typename extends::output_t output_t;
    typedef typename extends::input_t input_t;
    typedef typename extends::char_t char_t;
    typedef typename extends::string_t string_t;

    /// constructor / destructor
    implementedt() {
    }
    virtual ~implementedt() {
    }
private:
    implementedt(const implementedt& copy): extends(copy) {
    }

public:
    /// init / fini
    virtual bool init() {
        eError error = e_ERROR_NONE;

        LOGGER_IS_LOGGED_DEBUG("t_.Initialize()...");
        if ((error = t_.Initialize())) {
            LOGGER_IS_LOGGED_ERROR("...failed " << error << " = t_.Initialize()");
            return false;
        } else {
        }
        return true;
    }
    virtual bool fini() {
        eError error = e_ERROR_NONE;

        LOGGER_IS_LOGGED_DEBUG("t_.Finalize()...");
        if ((error = t_.Finalize())) {
            LOGGER_IS_LOGGED_ERROR("...failed " << error << "t_.Finalize()");
            return false;
        } else {
        }
        return true;
    }

    /// ...variable
    virtual const char_t* set_variable(const string_t& name, const string_t& to) {
        const char_t *chars = 0, *value = 0;
        size_t namelen = 0, valuelen = 0;

        if ((chars = name.has_chars(namelen)) && (value = to.chars(valuelen))) {
            cTVariableInterface* variable = 0;

            LOGGER_IS_LOGGED_DEBUG("t_.SetVariable(\"" << chars << "\", " << namelen << ", \"" << value << "\", " << valuelen << ")...");
            if (!(variable = t_.SetVariable(chars, namelen, value, valuelen))) {
                LOGGER_IS_LOGGED_ERROR("...failed on t_.SetVariable(\"" << chars << "\", " << namelen << ", \"" << value << "\", " << valuelen << ")");
            } else {
            }
        }
        value = variable(name);
        return value;
    }
    virtual const char_t* variable(const string_t& name) {
        const char_t *chars = 0, *value = 0;
        size_t namelen = 0;
        
        if ((chars = name.has_chars(namelen))) {
            cTVariableInterface* variable = 0;
            
            LOGGER_IS_LOGGED_DEBUG("t_.GetVariable(\"" << chars << "\", " << namelen << ")...");
            if (!(variable = t_.GetVariable(chars, namelen))) {
                LOGGER_IS_LOGGED_ERROR("...failed on t_.GetVariable(\"" << chars << "\", " << namelen << ")...");
            } else {
                value = variable->GetValue();
            }
        }
        return value;
    }

    /// expand
    virtual bool expand(output_t& output, input_t& input) {
        bool success = true;
        eError error = e_ERROR_NONE;
        cTOutput out(output);
        cTInput in(input);

        try {
            LOGGER_IS_LOGGED_DEBUG("t_.Expand(out, in)...")
            if ((error = t_.Expand(out, in))) {
                LOGGER_IS_LOGGED_ERROR("...failed " << error << " = t_.Expand(out, in)");
                success = false;
            } else {
            }
        } catch (const cTException& e) {
            LOGGER_IS_LOGGED_DEBUG("...caught cTException e()");
            if (e_ERROR_EXIT == (e.Error())) {
                LOGGER_IS_LOGGED_DEBUG("throw exception_t(exception_exit)...");
                throw exception_t(exception_exit);
            }
        }
        return success;
    }

protected:
    cT t_;
}; /// class implementedt
typedef implementedt<> implemented;

} /// namespace xde
} /// namespace processor
} /// namespace texta
} /// namespace language
} /// namespace xos

#endif /// ndef XOS_LANGUAGE_TEXTA_PROCESSOR_XDE_IMPLEMENTED_HPP 
