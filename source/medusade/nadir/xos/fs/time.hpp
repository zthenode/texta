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
///   File: time.hpp
///
/// Author: $author$
///   Date: 3/17/2015
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_NADIR_XOS_FS_TIME_HPP
#define _XOS_NADIR_XOS_FS_TIME_HPP

#include "xos/base/date.hpp"
#include "xos/base/types.hpp"

#define XOS_FS_TIME_WHICH_NAME_NONE "none"
#define XOS_FS_TIME_WHICH_NAME_MODIFIED "modified"
#define XOS_FS_TIME_WHICH_NAME_ACCESSED "accessed"
#define XOS_FS_TIME_WHICH_NAME_CHANGED "changed"
#define XOS_FS_TIME_WHICH_NAME_CREATED "created"

namespace xos {
namespace fs {

///////////////////////////////////////////////////////////////////////
///   Enum: time_when_which
///////////////////////////////////////////////////////////////////////
typedef int time_when_which;
enum {
    time_when_none     = 0,

    time_when_modified = 1,
    time_when_accessed = (1 << 1),
    time_when_changed  = (1 << 2),
    time_when_created  = (1 << 3),

    next_time_when,
    first_time_when = 1,
    last_time_when = (next_time_when - 1),

    time_when_any = (((last_time_when) << 1) - 1)
};

typedef base::implement_base time_when_implements;
typedef base::base time_when_extends;
///////////////////////////////////////////////////////////////////////
///  Class: time_whent
///////////////////////////////////////////////////////////////////////
template
<class TImplements=time_when_implements, class TExtends=time_when_extends>

class _EXPORT_CLASS time_whent: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    time_whent(time_when_which which = time_when_none): which_(which) {
    }
    time_whent(const time_whent& copy): which_(copy.which()) {
    }
    virtual ~time_whent() {
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual time_whent& operator |= (time_when_which which) {
        which_ |= which;
        return *this;
    }
    virtual time_whent& operator &= (time_when_which which) {
        which_ &= which;
        return *this;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual time_when_which which() const {
        return which_;
    }
    virtual operator time_when_which() const {
        return which_;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    static time_when_which of(const char* name) {
        if ((base::chars_t::compare(name, XOS_FS_TIME_WHICH_NAME_MODIFIED))) {
            if ((base::chars_t::compare(name, XOS_FS_TIME_WHICH_NAME_ACCESSED))) {
                if ((base::chars_t::compare(name, XOS_FS_TIME_WHICH_NAME_CHANGED))) {
                    if ((base::chars_t::compare(name, XOS_FS_TIME_WHICH_NAME_CREATED))) {
                        return time_when_none;
                    } else {
                        return time_when_created;
                    }
                } else {
                    return time_when_changed;
                }
            } else {
                return time_when_accessed;
            }
        } else {
            return time_when_modified;
        }
        return time_when_none;
    }
    static const char* name(time_when_which of) {
        switch (of) {
        case time_when_modified: return XOS_FS_TIME_WHICH_NAME_MODIFIED;
        case time_when_accessed: return XOS_FS_TIME_WHICH_NAME_ACCESSED;
        case time_when_changed: return XOS_FS_TIME_WHICH_NAME_CHANGED;
        case time_when_created: return XOS_FS_TIME_WHICH_NAME_CREATED;
        }
        return XOS_FS_TIME_WHICH_NAME_NONE;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    time_when_which which_;
};
typedef time_whent<> time_when;

typedef base::date_implements time_implements;
typedef base::date time_extends;
///////////////////////////////////////////////////////////////////////
///  Class: timet
///////////////////////////////////////////////////////////////////////
template
<class TImplements=time_implements, class TExtends=time_extends>

class _EXPORT_CLASS timet: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    timet(time_when when = time_when_none): when_(when) {
    }
    virtual ~timet() {
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual time_when when() const {
        return when_;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    time_when when_;
};
typedef timet<> time;

} // namespace fs 
} // namespace xos 

#endif // _XOS_NADIR_XOS_FS_TIME_HPP 
