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
///   File: time.hpp
///
/// Author: $author$
///   Date: 1/9/2016
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_NADIR_XOS_OS_UNIX_TIME_HPP
#define _XOS_NADIR_XOS_OS_UNIX_TIME_HPP

#include "xos/base/date.hpp"
#include "xos/io/logger.hpp"

namespace xos {
namespace os {
namespace unix {

typedef base::date_implements time_implements;
typedef base::date time_extends;
///////////////////////////////////////////////////////////////////////
///  Class: time
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS time
: virtual public time_implements, public time_extends {
public:
    typedef time_implements Implements;
    typedef time_extends Extends;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    time(bool is_current, bool is_gmt, bool is_12 = true) {
        if ((is_current)) {
            if (!(get_current(is_gmt, is_12))) {
                XOS_LOG_ERROR("...failed on get_current(is_gmt = " << ((is_gmt)?("true"):("false")) << ", is_12 = " << ((is_12)?("true"):("false")) << ")");
            }
        }
    }
    time(const time_t &t, bool is_gmt, bool is_12 = true) {
        if (!(get(t, is_gmt, is_12))) {
            XOS_LOG_ERROR("..failed on get(t, is_gmt = " << ((is_gmt)?("true"):("false")) << ", is_12 = " << ((is_12)?("true"):("false")) << ")");
        }
    }
    time() {
    }
    virtual ~time() {
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool get_current(bool is_gmt, bool is_12 = true) {
        bool success = true;
        time_t t;
        ::time(&t);
        success = get(t, is_gmt, is_12);
        return success;
    }
    virtual bool get(const time_t &t, bool is_gmt, bool is_12 = true) {
        bool success = true;
        struct tm tm;
        if ((is_gmt)) {
            gmtime_r(&t, &tm);
        } else {
            localtime_r(&t, &tm);
        }
        year_ = tm.tm_year+1900;
        month_ = tm.tm_mon+1;
        day_ = tm.tm_mday;
        hour_ = tm.tm_hour;
        minute_ = tm.tm_min;
        second_ = tm.tm_sec;
        return success;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};

namespace current {

typedef unix::time time_extends;
///////////////////////////////////////////////////////////////////////
///  Class: time
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS time: public time_extends {
public:
    typedef time_extends Extends;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    time(bool is_gmt, bool is_12): Extends(true, is_gmt, is_12) {
    }
    time(bool is_gmt): Extends(true, is_gmt, true) {
    }
    time(): Extends(true, true) {
    }
    time(const time_t &t, bool is_gmt, bool is_12): Extends(t, is_gmt, is_12) {
    }
    time(const time_t &t, bool is_gmt): Extends(t, is_gmt, false) {
    }
    time(const time_t &t): Extends(t, true, false) {
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};

namespace gmt {

typedef current::time time_extends;
///////////////////////////////////////////////////////////////////////
///  Class: time
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS time: public time_extends {
public:
    typedef time_extends Extends;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    time(bool is_12): Extends(true, is_12) {
    }
    time(): Extends(true, false) {
    }
    time(const time_t &t, bool is_12): Extends(t, true, is_12) {
    }
    time(const time_t &t): Extends(t, true, false) {
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};

} // namespace gnt

} // namespace current

} // namespace unix 
} // namespace os 
} // namespace xos 

#endif // _XOS_NADIR_XOS_OS_UNIX_TIME_HPP 
