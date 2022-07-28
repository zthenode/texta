///////////////////////////////////////////////////////////////////////
/// Copyright (c) 1988-2015 $organization$
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
///   File: writer.hpp
///
/// Author: $author$
///   Date: 1/6/2015
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_NADIR_XOS_IO_MAIN_ARGV_WRITER_HPP
#define _XOS_NADIR_XOS_IO_MAIN_ARGV_WRITER_HPP

#include "xos/io/writer.hpp"
#include "xos/base/types.hpp"

namespace xos {
namespace io {
namespace main {
namespace argv {

typedef base::implement_base writer_implements;
typedef base::base writer_extends;
///////////////////////////////////////////////////////////////////////
///  Class: writert
///////////////////////////////////////////////////////////////////////
template
<typename TChar = char_t, typename TWhat = void,
 class TChars = base::typest<TChar>,
 class TWriter = io::writert<TWhat, TChar>,
 class TImplements = writer_implements, class TExtends = writer_extends>

class _EXPORT_CLASS writert: virtual public TImplements,public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;

    typedef TWriter writer_t;
    typedef TChars chars_t;
    typedef TChar char_t;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    writert(): cr_((char_t)'\r'), lf_((char_t)'\n') {
    }
    virtual ~writert() {
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t write(writer_t& writer, int argc, char_t** argv) {
        ssize_t count = 0;
        ssize_t amount = 0;
        if ((argv)) {
            const char_t* chars = 0;
            size_t length = 0;
            for (int i = 0; i < argc; ++i) {
                if ((chars = argv[i]) && (0 < (length = chars_t::count(chars)))) {
                    if (0 < (amount = writer.write(chars, length))) {
                        count += amount;
                        if (0 < (amount = writer.write(&cr_, 1))) {
                            count += amount;
                            if (0 < (amount = writer.write(&lf_, 1))) {
                                count += amount;
                            }
                        }
                    }
                }
            }
        }
        if (0 < (amount = writer.write(&cr_, 1))) {
            count += amount;
            if (0 < (amount = writer.write(&lf_, 1))) {
                count += amount;
            }
        }
        return count;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    const char_t cr_, lf_;
};
typedef writert<> writer;

} // namespace argv 
} // namespace main 
} // namespace io 
} // namespace xos 

#endif // _XOS_NADIR_XOS_IO_MAIN_ARGV_WRITER_HPP 
