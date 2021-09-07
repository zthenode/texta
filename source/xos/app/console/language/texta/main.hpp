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
///   File: main.hpp
///
/// Author: $author$
///   Date: 4/14/2020
///////////////////////////////////////////////////////////////////////
#ifndef XOS_APP_CONSOLE_LANGUAGE_TEXTA_MAIN_HPP
#define XOS_APP_CONSOLE_LANGUAGE_TEXTA_MAIN_HPP

#include "xos/app/console/language/texta/main_opt.hpp"
#include "xos/language/texta/processor/implement.hpp"

namespace xos {
namespace app {
namespace console {
namespace language {
namespace texta {

/// class maint
template <class TExtends = main_opt, class TImplements = typename TExtends::implements>
class exported maint: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;
    typedef maint derives;

    typedef typename extends::file_t file_t;
    typedef typename extends::string_t string_t;
    typedef typename extends::char_t char_t;
    typedef typename extends::end_char_t end_char_t;
    enum { end_char = extends::end_char };

    /// constructor / destructor
    maint(): t_(0) {
    }
    virtual ~maint() {
    }
private:
    maint(const maint& copy): extends(copy) {
    }

protected:
    typedef xos::language::texta::processor::implement t_processor_t;
    typedef t_processor_t::input_t reader_t;
    typedef t_processor_t::output_t writer_t;
    typedef derives main_t;

    /// class reader
    class exported reader: virtual public reader_t {
    public:
        typedef reader_t implements;
        typedef typename implements::what_t what_t;
        typedef typename implements::sized_t sized_t;
        reader(main_t& main): main_(main) {
        }
        virtual ssize_t read(what_t* what, size_t size) {
            sized_t* sized = 0; ssize_t count = 0;
            if ((sized = ((sized_t*)what)) && (size)) {
                count = main_.in(sized, size);
            }
            return count;
        }    
    protected:
        main_t& main_;
    }; /// class reader

    /// class writer
    class exported writer: virtual public writer_t {
    public:
        typedef writer_t implements;
        typedef typename implements::what_t what_t;
        typedef typename implements::sized_t sized_t;
        writer(main_t& main): main_(main) {
        }
        virtual ssize_t write(const what_t* what, size_t size) {
            const sized_t* sized = 0; ssize_t count = 0;
            if ((sized = ((const sized_t*)what)) && (size)) {
                count = main_.out(sized, size);
            }
            return count;
        }    
    protected:
        main_t& main_;
    }; /// class writer

protected:
    /// ...run
    virtual int run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        t_processor_t* t = this->t();
        if ((t)) {
            derives::reader input(*this);
            derives::writer output(*this);
            t->expand(output, input);
        }
        return err;
    }
    virtual t_processor_t* t() {
        if (!(t_)) {
            if ((t_ = t_processor_t::get_instance())) {
                if (!(t_->init())) {
                    t_ = 0;
                }
            }
        }
        return t_;
    }
    
protected:
    t_processor_t* t_;
}; /// class maint
typedef maint<> main;

} /// namespace texta
} /// namespace language
} /// namespace console
} /// namespace app
} /// namespace xos

#endif /// ndef XOS_APP_CONSOLE_LANGUAGE_TEXTA_MAIN_HPP 
