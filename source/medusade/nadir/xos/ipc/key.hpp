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
///   File: key.hpp
///
/// Author: $author$
///   Date: 8/15/2016
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_NADIR_XOS_IPC_KEY_HPP
#define _XOS_NADIR_XOS_IPC_KEY_HPP

#include "xos/base/created.hpp"
#include "xos/base/creator.hpp"
#include "xos/base/attached.hpp"
#include "xos/base/attacher.hpp"

namespace xos {
namespace ipc {

typedef int key_index_t;
enum {
    key_index_first = 1,
    key_index_last  = 255
};
typedef int key_attached_t;
typedef int key_unattached_t;
enum { key_unattached = -1 };

typedef base::creator key_implements;
///////////////////////////////////////////////////////////////////////
///  Class: keyt
///////////////////////////////////////////////////////////////////////
template
<typename TAttached = key_attached_t,
 typename TUnattached = key_unattached_t,
 TUnattached VUnattached = key_unattached,
 typename TIndex = key_index_t,
 TIndex VIndexFirst = key_index_first,
 TIndex VIndexLast = key_index_last,
 class TImplements = key_implements>

class _EXPORT_CLASS keyt: virtual public TImplements {
public:
    typedef TImplements Implements;

    typedef TAttached attached_t;
    typedef TUnattached unattached_t;
    enum { unattached = VUnattached };

    typedef TIndex index_t;
    enum {
        index_first = VIndexFirst,
        index_last  = VIndexLast
    };

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};
typedef keyt<> key;

} // namespace ipc 
} // namespace xos 

#endif // _XOS_NADIR_XOS_IPC_KEY_HPP 
        

