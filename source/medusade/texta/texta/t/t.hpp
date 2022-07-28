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
///   File: t.hpp
///
/// Author: $author$
///   Date: 5/21/2016
///////////////////////////////////////////////////////////////////////
#ifndef _TEXTA_T_T_HPP
#define _TEXTA_T_T_HPP

#include "texta/io/writer.hpp"
#include "texta/io/reader.hpp"
#include "texta/base/base.hpp"

namespace texta {
namespace t {

typedef io::reader input_implements;
///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS input: virtual public input_implements {
public:
    typedef input_implements Implements;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};

typedef io::writer output_implements;
///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS output: virtual public output_implements {
public:
    typedef output_implements Implements;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    using Implements::write;
    virtual ssize_t write(const string& out) {
        const char* chars = out.chars();
        size_t length = out.length();
        ssize_t count = this->write(chars, length);
        return count;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};

typedef string result_extends;
///////////////////////////////////////////////////////////////////////
///  Class: result_implements
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS result_implements
: virtual public output, virtual public input {
};
///////////////////////////////////////////////////////////////////////
///  Class: result
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS result
: virtual public result_implements, public result_extends {
public:
    typedef result_implements Implements;
    typedef result_extends Extends;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    result(const char* chars): Extends(chars), tell_(0) {
    }
    result(const string& copy): Extends(copy), tell_(0) {
    }
    result(const result& copy): Extends(copy), tell_(0) {
    }
    result(): tell_(0) {
    }
    virtual ~result() {
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t write(const char* out, ssize_t length) {
        if (0 > (length)) {
            length = this->length();
            this->append(out);
            length = this->length() - length;
        } else {
            this->append(out, length);
        }
        return length;
    }
    virtual ssize_t read(char* in, size_t size) {
        ssize_t count = 0;
        if (size) {
            const char* chars = 0;
            if ((chars = this->chars())) {
                size_t length = this->length();
                if (tell_ + size > length) {
                    size = length - tell_;
                }
                if (size) {
                    chars_t::copy(in, chars + tell_, size);
                    tell_ += size;
                    count = size;
                }
            }
        }
        return count;
    }
    virtual size_t seek(size_t size) {
        size_t length = this->length();
        if (size > length) {
            size = length;
        }
        tell_ = size;
        return tell_;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    size_t tell_;
};

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS input_file_reader_implement
: virtual public input, virtual public io::file::attacher {
};
typedef io::file::readert
<input_file_reader_implement> input_file_reader;

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS input_file_implemnents
: virtual public input_file_reader,
  virtual public io::file::opened_implements {
};
typedef io::read::filet
<input_file_implemnents, io::file::opened> input_file;

} // namespace t
} // namespace texta

#endif // _TEXTA_T_T_HPP
