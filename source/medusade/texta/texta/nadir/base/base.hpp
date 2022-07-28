///////////////////////////////////////////////////////////////////////
/// Copyright (c) 1988-2017 $organization$
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
///   File: base.hpp
///
/// Author: $author$
///   Date: 5/21/2017
///////////////////////////////////////////////////////////////////////
#ifndef _TEXTA_NADIR_BASE_BASE_HPP
#define _TEXTA_NADIR_BASE_BASE_HPP

#include "nadir/base/base.hpp"
#include "nadir/base/created.hpp"
#include "nadir/base/opened.hpp"
#include "nadir/base/chars.hpp"
#include "nadir/base/array.hpp"
#include "nadir/base/string.hpp"
#include "nadir/base/to_string.hpp"
#include "nadir/io/reader.hpp"
#include "nadir/io/writer.hpp"
#include "nadir/io/crt/file.hpp"

namespace texta {

typedef nadir::implement_base implement_base;
typedef nadir::base base;

typedef nadir::pointer_t pointer_t;
typedef nadir::unsigned_t unsigned_t;
typedef nadir::signed_t signed_t;

typedef nadir::chars_t chars_t;
typedef nadir::tchars_t tchars_t;
typedef nadir::wchars_t wchars_t;

typedef nadir::char_array char_array;
typedef nadir::tchar_array tchar_array;
typedef nadir::wchar_array wchar_array;
typedef char_array array;

typedef nadir::char_string char_string;
typedef nadir::tchar_string tchar_string;
typedef nadir::wchar_string wchar_string;
typedef char_string string;

typedef nadir::chars_to_string chars_to_string;
typedef nadir::chars_to_tstring chars_to_tstring;
typedef nadir::chars_to_wstring chars_to_wstring;

namespace io {

typedef nadir::io::char_reader reader;
typedef nadir::io::char_writer writer;
typedef nadir::io::char_stream stream;

namespace file {

typedef nadir::openert<io::stream> opener;
typedef nadir::io::crt::file_attached_t attached_t;
typedef nadir::attachert<attached_t, int, 0, opener> attacher;
typedef nadir::attachedt<attached_t, int, 0, attacher, base> attached;
typedef attacher opened_implements;
typedef nadir::openedt<attached_t, int, 0, opened_implements, attached> opened;
///////////////////////////////////////////////////////////////////////
///  Class: readert
///////////////////////////////////////////////////////////////////////
template
<class TReader,
 class TImplements = nadir::attachert<attached_t, int, 0, TReader> >
class _EXPORT_CLASS readert: virtual public TImplements {
public:
    typedef TImplements Implements;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};

} // namespace file

namespace read {

template <class TImplements, class TExtends>
class _EXPORT_CLASS filet: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;
    typedef file::attached_t attached_t;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    filet(attached_t attached = 0, bool is_open = false)
    : Extends(attached, is_open) {
    }
    virtual ~filet() {
        if (!(this->closed())) {
        }
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    using Extends::open;
    virtual bool open(const char* name) {
        const char* mode = this->mode_read_binary();
        if ((this->open(name, mode))) {
            return true;
        }
        return false;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};

} // namespace read

} // namespace io

} // namespace texta

#endif // _TEXTA_NADIR_BASE_BASE_HPP 
