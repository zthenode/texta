///////////////////////////////////////////////////////////////////////
/// Copyright (c) 1988-2018 $organization$
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
///   File: coder.hpp
///
/// Author: $author$
///   Date: 3/2/2018
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_BASE_CODER_HPP
#define _XOS_BASE_CODER_HPP

#include "xos/base/encoder.hpp"
#include "xos/base/decoder.hpp"

namespace xos {
namespace base {

typedef encoder codert_encoder_implements;
typedef decoder codert_decoder_implements;
///////////////////////////////////////////////////////////////////////
///  Class: codert
///////////////////////////////////////////////////////////////////////
template
<class TEncoderImplements = codert_encoder_implements, 
 class TDecoderImplements = codert_decoder_implements>

class _EXPORT_CLASS codert
: virtual public TEncoderImplements, virtual public TDecoderImplements {
public:
    typedef TEncoderImplements EncoderImplements;
    typedef TDecoderImplements DecoderImplements;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};
typedef codert<> coder;

} // namespace base 
} // namespace xos 

#endif // _XOS_BASE_CODER_HPP 
