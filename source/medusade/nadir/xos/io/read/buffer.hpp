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
///   File: buffer.hpp
///
/// Author: $author$
///   Date: 4/4/2016
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_NADIR_XOS_IO_READ_BUFFER_HPP
#define _XOS_NADIR_XOS_IO_READ_BUFFER_HPP

#include "xos/io/buffer.hpp"
#include "xos/io/reader.hpp"

namespace xos {
namespace io {
namespace read {

typedef io::reader buffer_reader;
typedef io::tellert<buffer_reader> buffer_teller;
typedef io::whencert<buffer_teller> buffer_whencer;
typedef io::seekert<buffer_whencer> buffer_seeker;
typedef buffer_seeker buffer_implements;
typedef io::buffert<buffer_implements> buffer_extends;
///////////////////////////////////////////////////////////////////////
///  Class: buffert
///////////////////////////////////////////////////////////////////////
template
<typename TWhat = void, typename TSized = char,
 class TImplements = buffer_implements, class TExtends = buffer_extends>
class _EXPORT_CLASS buffert: virtual public TImplements,public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;
    typedef TWhat what_t;
    typedef TSized sized_t;
    typedef typename Implements::whence_t whence_t;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    buffert(const sized_t* in = 0, ssize_t length = -1, size_t tell = 0)
    : Extends(length, tell), in_(in) {
    }
    virtual ~buffert() {
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t read(what_t* what, size_t size) {
        if ((what) && (size) && (in_)) {
            if (0 < (this->length_)) {
                if (((this->tell_ + size) >= (this->length_))) {
                    size = this->length_ - this->tell_;
                }
            }
            if ((size)) {
                this->copy(what, in_ + this->tell_, size);
                this->tell_ += size;
                return size;
            }
        }
        return 0;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t seek(ssize_t offset, whence_t whence) {
        if ((this->in_)) {
            if ((this->begin() == whence)) {
                // from begin
                if (0 > (this->length_)) {
                    // length < 0
                    if (0 > (offset)) {
                        // offset < 0
                    } else {
                        if (0 < (offset)) {
                            // offest > 0
                            return this->set_tell(offset);
                        } else {
                            // offset == 0
                            return this->set_tell(0);
                        }
                    }
                } else {
                    // length >= 0
                    if (0 > (offset)) {
                        // offset < 0
                    } else {
                        if (0 < (offset)) {
                            // offset > 0
                            if (this->length_ < (offset)) {
                                offset = this->length_;
                            }
                            return this->set_tell(offset);
                        } else {
                            // offset == 0
                            return this->set_tell(0);
                        }
                    }
                }
            } else {
                if ((this->current() == whence)) {
                    // from current
                    if (0 > (this->length_)) {
                        // length < 0
                        if (0 > (offset)) {
                            // offset < 0
                            if (0 > (this->tell_ - offset)) {
                                offset = this->tell_;
                            }
                            return this->set_tell(this->tell_ - offset);
                        } else {
                            if (0 < (offset)) {
                                // offest > 0
                                return this->set_tell(this->tell_ + offset);
                            } else {
                                // offset == 0
                                return this->tell();
                            }
                        }
                    } else {
                        // length >= 0
                        if (0 > (offset)) {
                            // offset < 0
                            if (0 > (this->tell_ - offset)) {
                                offset = this->tell_;
                            }
                            return this->set_tell(this->tell_ - offset);
                        } else {
                            if (0 < (offset)) {
                                // offset > 0
                                if (this->length_ < (this->tell_ + offset)) {
                                    offset = this->length_ - this->tell_;
                                }
                                return this->set_tell(this->tell_ + offset);
                            } else {
                                // offset == 0
                                return this->tell();
                            }
                        }
                    }
                } else {
                    if ((this->end() == whence)) {
                        // from end
                        if (0 > (this->length_)) {
                        } else {
                            if (0 > (offset)) {
                                // offset < 0
                            } else {
                                if (0 < (offset)) {
                                    // offset > 0
                                    if (0 > (this->length_ - offset)) {
                                        offset = this->length_;
                                    }
                                    return this->set_tell(this->length_ - offset);
                                } else {
                                    // offset == 0
                                    return this->set_tell(this->length_);
                                }
                            }
                        }
                    } else {
                    }
                }
            }
        }
        return -1;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual const sized_t* set_in(const sized_t* to, ssize_t length) {
        in_ = to;
        this->set_length(length);
        this->set_tell(0);
        return in_;
    }
    virtual const sized_t* set_in(const sized_t* to) {
        in_ = to;
        this->set_length(-1);
        this->set_tell(0);
        return in_;
    }
    virtual const sized_t* in(ssize_t& length) const {
        length = this->length();
        return in_;
    }
    virtual const sized_t* in() const {
        return in_;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    const sized_t* in_;
};

// char
typedef io::char_reader char_buffer_reader;
typedef io::tellert<char_buffer_reader> char_buffer_teller;
typedef io::whencert<char_buffer_teller> char_buffer_whencer;
typedef io::seekert<char_buffer_whencer> char_buffer_seeker;
typedef char_buffer_seeker char_buffer_implements;
typedef io::buffert<char_buffer_implements> char_buffer_extends;
typedef buffert<char, char, char_buffer_implements, char_buffer_extends> char_buffer;

// byte
typedef io::byte_reader byte_buffer_reader;
typedef io::tellert<byte_buffer_reader> byte_buffer_teller;
typedef io::whencert<byte_buffer_teller> byte_buffer_whencer;
typedef io::seekert<byte_buffer_whencer> byte_buffer_seeker;
typedef byte_buffer_seeker byte_buffer_implements;
typedef io::buffert<byte_buffer_implements> byte_buffer_extends;
typedef buffert<byte_t, byte_t, byte_buffer_implements, byte_buffer_extends> byte_buffer;

} // namespace read
} // namespace io 
} // namespace xos 

#endif // _XOS_NADIR_XOS_IO_READ_BUFFER_HPP 
