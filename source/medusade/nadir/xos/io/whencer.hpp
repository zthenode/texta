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
///   File: whencer.hpp
///
/// Author: $author$
///   Date: 4/4/2016
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_NADIR_XOS_IO_WHENCER_HPP
#define _XOS_NADIR_XOS_IO_WHENCER_HPP

#include "xos/io/whence.hpp"

namespace xos {
namespace io {

typedef base::implement_base whencer_implements;
///////////////////////////////////////////////////////////////////////
///  Class: whencert
///////////////////////////////////////////////////////////////////////
template
<class TImplements = whencer_implements,
 typename TWhence = whence_t, TWhence VBegin = whence_begin,
 TWhence VCurrent = whence_current, TWhence VEnd = whence_end>

class _EXPORT_CLASS whencert: virtual public TImplements {
public:
    typedef TImplements Implements;
    typedef TWhence whence_t;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual whence_t begin() const {
        return VBegin;
    }
    virtual whence_t current() const {
        return VCurrent;
    }
    virtual whence_t end() const {
        return VEnd;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};
typedef whencert<> whencer;

} // namespace io 
} // namespace xos 

#endif // _XOS_NADIR_XOS_IO_WHENCER_HPP 
