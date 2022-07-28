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
///   File: entry.hpp
///
/// Author: $author$
///   Date: 3/20/2015
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_NADIR_XOS_OS_WINDOWS_FS_DIRECTORY_ENTRY_HPP
#define _XOS_NADIR_XOS_OS_WINDOWS_FS_DIRECTORY_ENTRY_HPP

#include "xos/os/windows/fs/entry.hpp"
#include "xos/fs/directory/entry.hpp"

namespace xos {
namespace os {
namespace windows {
namespace fs {
namespace directory {

typedef xos::fs::directory::entry_implements entry_implements;
///////////////////////////////////////////////////////////////////////
///  Class: entry_extendst
///////////////////////////////////////////////////////////////////////
template
<typename TChar = char, typename TEnd = TChar, TEnd VEnd = 0,
 class TString = base::stringt<TChar, TEnd, VEnd>,
 class TExtends = xos::fs::directory::entryt
 <TChar, TEnd, VEnd, TString, fs::entryt<TChar, TEnd, VEnd> >, 
 class TImplements = fs::entry_implements>

class _EXPORT_CLASS entry_extendst: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;
};
typedef entry_extendst<> entry_extends;
///////////////////////////////////////////////////////////////////////
///  Class: entryt
///////////////////////////////////////////////////////////////////////
template
<typename TChar = char, typename TEnd = TChar, TEnd VEnd = 0,
 class TString = base::stringt<TChar, TEnd, VEnd>,
 class TExtends = entry_extendst<TChar, TEnd, VEnd>, 
 class TImplements = entry_implements>

class _EXPORT_CLASS entryt: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;

    typedef TString string_t; 
    typedef TChar char_t;
    typedef TEnd end_t;
    enum { end = VEnd };

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    entryt() {
    }
    entryt(const entryt& copy): Extends(copy) {
    }
    virtual ~entryt() {
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual entryt& assign(WIN32_FIND_DATAW find_data) {
        xos::base::string name(find_data.cFileName);
        this->set_name(name.chars());
        this->find_data_ = find_data;
        this->get_found_attributes();
        return *this;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
};
typedef entryt<> entry;

} // namespace directory 
} // namespace fs 
} // namespace windows 
} // namespace os 
} // namespace xos 

#endif // _XOS_NADIR_XOS_OS_WINDOWS_FS_DIRECTORY_ENTRY_HPP 
