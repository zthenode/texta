///////////////////////////////////////////////////////////////////////
/// Copyright (c) 1988-2016 $organization$
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
///   File: path.hpp
///
/// Author: $author$
///   Date: 5/26/2016
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_NADIR_XOS_FS_PATH_HPP
#define _XOS_NADIR_XOS_FS_PATH_HPP

#include "xos/fs/path_separator.hpp"
#include "xos/fs/path_separator_events.hpp"
#include "xos/base/string.hpp"
#include "xos/io/logger.hpp"

namespace xos {
namespace fs {

///////////////////////////////////////////////////////////////////////
///  Class: patht
///////////////////////////////////////////////////////////////////////
template
<typename TChar = char, typename TEnd = TChar, TEnd VEnd = 0,
 class TString = base::stringt<TChar, TEnd, VEnd>,
 class TSeparatorEvents = path_separator_eventst<TChar, TEnd, VEnd>,
 class TSeparator = path_separatort<TChar, TEnd, VEnd, TString, TSeparatorEvents>,
 class TImplements = base::string_implements, class TExtends = TString>

class _EXPORT_CLASS patht
: virtual public TSeparatorEvents,
  virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;
    typedef patht Derives;

    typedef TSeparator separator_t;
    typedef TString string_t;
    typedef TChar char_t;
    typedef TEnd end_t;
    enum { end = VEnd};

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    patht(const wchar_t* chars, size_t length)
    : Extends(chars, length), volume_separator_((char_t)':'),
      directory_separator_((char_t)'/'), extension_separator_((char_t)'.'),
      is_network_(false), is_root_(false), is_root_directory_(false) {
        this->separate();
    }
    patht(const char* chars, size_t length)
    : Extends(chars, length), volume_separator_((char_t)':'),
      directory_separator_((char_t)'/'), extension_separator_((char_t)'.'),
      is_network_(false), is_root_(false), is_root_directory_(false) {
        this->separate();
    }
    patht(const wchar_t* chars)
    : Extends(chars), volume_separator_((char_t)':'),
      directory_separator_((char_t)'/'), extension_separator_((char_t)'.'),
      is_network_(false), is_root_(false), is_root_directory_(false) {
        this->separate();
    }
    patht(const char* chars)
    : Extends(chars), volume_separator_((char_t)':'),
      directory_separator_((char_t)'/'), extension_separator_((char_t)'.'),
      is_network_(false), is_root_(false), is_root_directory_(false) {
        this->separate();
    }
    patht(const patht& copy)
    : Extends(copy),
      volume_separator_(copy.volume_separator()),
      directory_separator_(copy.directory_separator()),
      extension_separator_(copy.extension_separator()),
      is_network_(copy.is_network()),
      is_root_(copy.is_root()),
      is_root_directory_(copy.is_root_directory()) {
    }
    patht()
    : volume_separator_((char_t)':'),
      directory_separator_((char_t)'/'), extension_separator_((char_t)'.'),
      is_network_(false), is_root_(false), is_root_directory_(false) {
    }
    virtual ~patht() {
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual patht& separate(const wchar_t* chars, size_t length) {
        this->assign(chars, length);
        this->separate();
        return *this;
    }
    virtual patht& separate(const char* chars, size_t length) {
        this->assign(chars, length);
        this->separate();
        return *this;
    }
    virtual patht& separate(const wchar_t* chars) {
        this->assign(chars);
        this->separate();
        return *this;
    }
    virtual patht& separate(const char* chars) {
        this->assign(chars);
        this->separate();
        return *this;
    }
    virtual patht& separate() {
        separator_t separator(*this);
        const char_t* chars = 0;
        size_t length = 0;
        clear_parts();
        if ((chars = this->chars(length))) {
            XOS_LOG_MESSAGE_DEBUG("path = \"" << chars << "\"");
            if (!(separator.separate(chars, length))) {
                clear_parts();
            }
        }
        return *this;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual patht& clear() {
        clear_parts();
        Extends::clear();
        return *this;
    }
    virtual patht& clear_parts() {
        is_network_ = is_root_ = is_root_directory_ = false;
        host_.clear();
        volume_.clear();
        directory_.clear();
        file_path_.clear();
        file_base_path_.clear();
        file_name_.clear();
        file_base_.clear();
        file_extension_.clear();
        return *this;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual const string_t& set_host(const char_t* chars, size_t length) {
        host_.assign(chars, length);
        return host_;
    }
    virtual const string_t& set_host(const char_t* chars) {
        host_.assign(chars);
        return host_;
    }
    virtual const string_t& host() const {
        return host_;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual const string_t& set_volume(const char_t* chars, size_t length) {
        volume_.assign(chars, length);
        return volume_;
    }
    virtual const string_t& set_volume(const char_t* chars) {
        volume_.assign(chars);
        return volume_;
    }
    virtual const string_t& volume() const {
        return volume_;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual const string_t& set_directory(const char_t* chars, size_t length) {
        directory_.assign(chars, length);
        return directory_;
    }
    virtual const string_t& set_directory(const char_t* chars) {
        directory_.assign(chars);
        return directory_;
    }
    virtual const string_t& directory() const {
        return directory_;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual const string_t& set_file_path(const char_t* chars, size_t length) {
        file_path_.assign(chars, length);
        return file_path_;
    }
    virtual const string_t& set_file_path(const char_t* chars) {
        file_path_.assign(chars);
        return file_path_;
    }
    virtual const string_t& file_path() const {
        return file_path_;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual const string_t& set_file_base_path(const char_t* chars, size_t length) {
        file_base_path_.assign(chars, length);
        return file_base_path_;
    }
    virtual const string_t& set_file_base_path(const char_t* chars) {
        file_base_path_.assign(chars);
        return file_base_path_;
    }
    virtual const string_t& file_base_path() const {
        return file_base_path_;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual const string_t& set_file_name(const char_t* chars, size_t length) {
        file_name_.assign(chars, length);
        return file_name_;
    }
    virtual const string_t& set_file_name(const char_t* chars) {
        file_name_.assign(chars);
        return file_name_;
    }
    virtual const string_t& file_name() const {
        return file_name_;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual const string_t& set_file_base(const char_t* chars, size_t length) {
        file_base_.assign(chars, length);
        return file_base_;
    }
    virtual const string_t& set_file_base(const char_t* chars) {
        file_base_.assign(chars);
        return file_base_;
    }
    virtual const string_t& file_base() const {
        return file_base_;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual const string_t& set_file_extension(const char_t* chars, size_t length) {
        file_extension_.assign(chars, length);
        return file_extension_;
    }
    virtual const string_t& set_file_extension(const char_t* chars) {
        file_extension_.assign(chars);
        return file_extension_;
    }
    virtual const string_t& file_extension() const {
        return file_extension_;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool& set_is_network(bool to) {
        return (bool&)is_network_;
    }
    virtual bool& is_network() const {
        return (bool&)is_network_;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool& set_is_root(bool to) {
        return (bool&)is_root_;
    }
    virtual bool& is_root() const {
        return (bool&)is_root_;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool& set_is_root_directory(bool to) {
        return (bool&)is_root_directory_;
    }
    virtual bool& is_root_directory() const {
        return (bool&)is_root_directory_;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual const char_t& volume_separator() const {
        return volume_separator_;
    }
    virtual const char_t& directory_separator() const {
        return directory_separator_;
    }
    virtual const char_t& extension_separator() const {
        return extension_separator_;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual void on_host(const char_t* chars, size_t length) {
        host_.assign(chars, length);
        XOS_LOG_MESSAGE_DEBUG("host = \"" << host_ << "\"");
    }
    virtual void on_volume(const char_t* chars, size_t length) {
        volume_.assign(chars, length);
        XOS_LOG_MESSAGE_DEBUG("volume = \"" << volume_ << "\"");
    }
    virtual void on_root_directory() {
        directory_assign(&directory_separator_, 1);
        XOS_LOG_MESSAGE_DEBUG("directory = \"" << directory_ << "\"");
    }
    virtual void on_current_directory() {
        on_append_directory();
        directory_append(&extension_separator_, 1);
        XOS_LOG_MESSAGE_DEBUG("directory = \"" << directory_ << "\"");
    }
    virtual void on_parent_directory() {
        on_append_directory();
        directory_append(&extension_separator_, 1);
        directory_append(&extension_separator_, 1);
        XOS_LOG_MESSAGE_DEBUG("directory = \"" << directory_ << "\"");
    }
    virtual void on_directory_name(const char_t* chars, size_t length) {
        on_append_directory();
        directory_append(chars, length);
        XOS_LOG_MESSAGE_DEBUG("directory = \"" << directory_ << "\"");
    }
    virtual void on_file_name(const char_t* chars, size_t length) {
        on_append_base();
        file_base_path_.append(chars, length);
        file_name_.assign(chars, length);
        XOS_LOG_MESSAGE_DEBUG("base = \"" << file_base_path_ << "\"");
        XOS_LOG_MESSAGE_DEBUG("file name = \"" << file_name_ << "\"");
    }
    virtual void on_file_base(const char_t* chars, size_t length) {
        on_append_base();
        file_base_path_.append(chars, length);
        file_name_.assign(chars, length);
        file_base_.assign(chars, length);
        XOS_LOG_MESSAGE_DEBUG("base = \"" << file_base_path_ << "\"");
        XOS_LOG_MESSAGE_DEBUG("file base = \"" << file_base_ << "\"");
    }
    virtual void on_file_extension(const char_t* chars, size_t length) {
        file_name_.append(&extension_separator_, 1);
        file_name_.append(chars, length);
        file_extension_.assign(chars, length);
        XOS_LOG_MESSAGE_DEBUG("file extension = \"" << file_extension_ << "\"");
    }

protected:
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual void on_append_directory() {
        const char_t* d_chars; size_t d_length;
        if ((d_chars = directory_.c_str()) && (d_length = directory_.length())) {
            if (directory_separator_ != (d_chars[d_length-1])) {
                directory_.append(&directory_separator_, 1);
            }
        }
        on_append_path();
        on_append_base();
    }
    virtual void on_append_path() {
        const char_t* d_chars; size_t d_length;
        if ((d_chars = file_path_.c_str()) && (d_length = file_path_.length())) {
            if (directory_separator_ != (d_chars[d_length-1])) {
                file_path_.append(&directory_separator_, 1);
            }
        }
    }
    virtual void on_append_base() {
        const char_t* d_chars; size_t d_length;
        if ((d_chars = file_base_path_.c_str()) && (d_length = file_base_path_.length())) {
            if (directory_separator_ != (d_chars[d_length-1])) {
                file_base_path_.append(&directory_separator_, 1);
            }
        }
    }
    virtual void directory_assign(const char_t* chars, size_t length) {
        directory_.assign(chars, length);
        file_path_.assign(chars, length);
        file_base_path_.assign(chars, length);
    }
    virtual void directory_append(const char_t* chars, size_t length) {
        directory_.append(chars, length);
        file_path_.append(chars, length);
        file_base_path_.append(chars, length);
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    const char_t volume_separator_, directory_separator_, extension_separator_;
    bool is_network_, is_root_, is_root_directory_;
    string_t host_, volume_, directory_,
             file_path_, file_base_path_,
             file_name_, file_base_, file_extension_;
};
typedef patht<> path;

} // namespace fs 
} // namespace xos 

#endif // _XOS_NADIR_XOS_FS_PATH_HPP 
