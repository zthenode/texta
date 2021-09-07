///////////////////////////////////////////////////////////////////////
/// Copyright (c) 1988-2020 $organization$
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
///   File: cTInput.hpp
///
/// Author: $author$
///   Date: 4/16/2020
///////////////////////////////////////////////////////////////////////
#ifndef XOS_LANGUAGE_TEXTA_PROCESSOR_XDE_CTINPUT_HPP
#define XOS_LANGUAGE_TEXTA_PROCESSOR_XDE_CTINPUT_HPP

#include "xos/language/texta/processor/implement.hpp"
#include "cstream.hxx"

namespace xos {
namespace language {
namespace texta {
namespace processor {
namespace xde {

/// class cTInputt
template 
<class TInput = processor::implement::input_t, 
 class TExtends = cCharStream, class TImplements = typename TExtends::cImplements>
class cTInputt: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;
    typedef cTInputt derives;

    typedef TInput input_t;
    typedef typename input_t::sized_t sized_t;
    typedef TLENGTH TLength;
    typedef TSIZE TSize;
    typedef char TWhat;
    
    /// constructor / destructor
    cTInputt(const cTInputt& copy): input_(copy.input_) {
    }
    cTInputt(input_t& input): input_(input) {
    }
    virtual ~cTInputt() {
    }
    
    /// Read
    virtual TLength Read(TWhat* what, TSize size) {
        TLength count = 0;
        sized_t* sized = 0;

        if ((sized = what) && (size)) {
            ssize_t amount = 0;
            
            if (0 < (amount = input_.read(sized, size))) {
                count += amount;
            } else {
                if (0 > (amount)) {
                    count = -e_ERROR_FAILED;
                }
            }
        }
        return count;
    }

protected:
    input_t& input_;
}; /// class cTInputt
typedef cTInputt<> cTInput;

} /// namespace xde
} /// namespace processor
} /// namespace texta
} /// namespace language
} /// namespace xos

#endif /// ndef XOS_LANGUAGE_TEXTA_PROCESSOR_XDE_CTINPUT_HPP 
