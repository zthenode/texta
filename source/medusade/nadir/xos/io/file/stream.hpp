///////////////////////////////////////////////////////////////////////
/// Copyright (c) 1988-2021 $organization$
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
///   Date: 2/20/2021
///////////////////////////////////////////////////////////////////////
#ifndef XOS_NADIR_XOS_IO_FILE_STREAM_HPP
#define XOS_NADIR_XOS_IO_FILE_STREAM_HPP

#include "xos/io/stream.hpp"
#include "xos/io/file/opened.hpp"

namespace xos {
namespace io {
namespace file {

///////////////////////////////////////////////////////////////////////
/// class stream_implemnentst
///////////////////////////////////////////////////////////////////////
template 
<typename TWhat = void, typename TSized = char, typename TEnd = int, TEnd VEnd = 0,
 class TStream = xos::io::streamt<TWhat, TSized, TEnd, VEnd>, 
 class TOpener = xos::io::file::opened_implemnents>
class EXPORT_CLASS stream_implemnentst: virtual public TStream {
public:
    typedef TStream Implements;
    typedef stream_implemnentst Derives;

    typedef TWhat what_t;
    typedef TSized sized_t;
    typedef TEnd end_t;
    enum { end = VEnd };

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
}; /// class stream_implemnentst
typedef stream_implemnentst<> stream_implemnents;

///////////////////////////////////////////////////////////////////////
/// class streamt
///////////////////////////////////////////////////////////////////////
template 
<typename TWhat = void, typename TSized = char, typename TEnd = int, TEnd VEnd = 0,
 class TImplements = stream_implemnentst<TWhat, TSized, TEnd, VEnd>, 
 class TExtends = xos::io::file::openedt<TSized, TEnd, VEnd, TImplements> >
class EXPORT_CLASS streamt: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;
    typedef streamt Derives;

    typedef TWhat what_t;
    typedef TSized sized_t;
    typedef TEnd end_t;
    enum { end = VEnd };

    typedef typename TExtends::attached_t attached_t;
    typedef typename TExtends::unattached_t unattached_t;
    enum { unattached = TExtends::unattached };

    ///////////////////////////////////////////////////////////////////////
    /// constructor / destructor
    ///////////////////////////////////////////////////////////////////////
    streamt(FILE* attached, bool is_open): Extends(attached, is_open) {
    }
    streamt(FILE* attached): Extends(attached) {
    }
    streamt(const streamt& copy): Extends(copy) {
    }
    streamt() {
    }
    virtual ~streamt() {
        if (!(this->closed())) {
            xos::base::opener_exception e = xos::base::failed_to_close;
            throw (e);
        }
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    using Extends::open;
    virtual bool open(const wchar_t* name, const char* mode) {
        if (!(mode)) {
            mode = this->mode_read_binary();
        }
        if ((this->open(name, mode))) {
            return true;
        }
        return false;
    }
    virtual bool open(const char* name, const char* mode) {
        if (!(mode)) {
            mode = this->mode_read_binary();
        }
        if ((this->open(name, mode))) {
            return true;
        }
        return false;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
}; /// class streamt
typedef streamt<> stream;

} /// namespace file 
} /// namespace io 
} /// namespace xos 

#endif /// ndef XOS_NADIR_XOS_IO_FILE_STREAM_HPP 