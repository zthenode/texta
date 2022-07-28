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
///   File: which.hpp
///
/// Author: $author$
///   Date: 1/7/2015
///////////////////////////////////////////////////////////////////////
#ifndef _MEDUSA_INET_HTTP_CONTENT_TYPE_WHICH_HPP
#define _MEDUSA_INET_HTTP_CONTENT_TYPE_WHICH_HPP

#include "medusa/base/base.hpp"

namespace medusa {
namespace inet {
namespace http {
namespace content {
namespace type {

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
typedef int which_t;
enum {
    none = 0,

    text,
    html,
    xml,
    octet_stream,
    urlencoded_form_data,
    multipart_form_data,
    json,
    javascript,

    next,
    first = (none + 1),
    last = (next - 1),
    count = ((last - first) + 1)
};

} // namespace type
} // namespace content 
} // namespace http 
} // namespace inet 
} // namespace medusa 

#endif // _MEDUSA_INET_HTTP_CONTENT_TYPE_WHICH_HPP 
