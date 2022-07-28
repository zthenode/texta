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
///   File: stream.hpp
///
/// Author: $author$
///   Date: 4/11/2015
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_NADIR_XOS_OS_FILE_STREAM_HPP
#define _XOS_NADIR_XOS_OS_FILE_STREAM_HPP

#include "xos/io/file/attached.hpp"
#include "xos/io/stream.hpp"
#include "xos/io/logger.hpp"

namespace xos {
namespace os {
namespace file {

typedef io::file::attacher stream_implements;
typedef io::file::attached stream_extends;
///////////////////////////////////////////////////////////////////////
///  Class: streamt
///////////////////////////////////////////////////////////////////////
template
<class TImplements = stream_implements, class TExtends = stream_extends>

class _EXPORT_CLASS streamt: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    streamt(FILE* detached = 0): Extends(detached) {
    }
    streamt(const streamt& copy): Extends(copy) {
    }
    virtual ~streamt() {
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool set_mode_is_binary(bool mode_is_binary = true) {
        FILE* detached = 0;
        if ((detached = this->attached_to())) {
#if defined(WINDOWS)
            int fd = -1;
            if (0 <= (fd = _fileno(detached))) {
                int mode = (mode_is_binary)?(_O_BINARY):(_O_TEXT);
                int err = 0;
                if (0 > (err = _setmode(fd, mode))) {
                    XOS_LOG_ERROR("failed " << errno << " on _setmode(fd = " << fd << ", mode = " << mode << ")");
                } else {
                    return true;
                }
            }
#else // defined(WINDOWS)
            return mode_is_binary;
#endif // defined(WINDOWS)
        }
        return false;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};
typedef streamt<> stream;

} // namespace file 
} // namespace os 
} // namespace xos 

#endif // _XOS_NADIR_XOS_OS_FILE_STREAM_HPP 
