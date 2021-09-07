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
///   File: cTOutput.hpp
///
/// Author: $author$
///   Date: 4/16/2020
///////////////////////////////////////////////////////////////////////
#ifndef XOS_LANGUAGE_TEXTA_PROCESSOR_XDE_CTOUTPUT_HPP
#define XOS_LANGUAGE_TEXTA_PROCESSOR_XDE_CTOUTPUT_HPP

#include "xos/language/texta/processor/implement.hpp"
#include "cstream.hxx"

namespace xos {
namespace language {
namespace texta {
namespace processor {
namespace xde {

/// class cTOutputt
template 
<class TOutput = processor::implement::output_t, 
 class TExtends = cCharStream, class TImplements = typename TExtends::cImplements>
class cTOutputt: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;
    typedef cTOutputt derives;

    typedef TOutput output_t;
    typedef typename output_t::sized_t sized_t;
    typedef TLENGTH TLength;
    typedef TSIZE TSize;
    typedef char TWhat;
    
    /// constructor / destructor
    cTOutputt(const cTOutputt& copy): output_(copy.output_) {
    }
    cTOutputt(output_t& output): output_(output) {
    }
    virtual ~cTOutputt() {
    }
    
    /// Write
    virtual TLength Write(const TWhat* what, TLength length) {
        TLength count = 0;
        const sized_t* sized = 0;

        if ((sized = what)) {
            ssize_t amount = 0;
            
            if (0 < (length)) {
                if (0 < (amount = output_.write(sized, length))) {
                    count += amount;
                } else {
                    if (0 > (amount)) {
                        count = -e_ERROR_FAILED;
                    }
                }
            } else {
                if (0 > (length)) {
                    for (; *sized; ++sized) {
                        if (0 < (amount = output_.write(sized, 1))) {
                            count += amount;
                        } else {
                            if (0 >= (amount)) {
                                count = -e_ERROR_FAILED;
                                break;
                            }
                        }
                    }
                }
            }
        }
        return count;
    }

protected:
    output_t& output_;
}; /// class cTOutputt
typedef cTOutputt<> cTOutput;

} /// namespace xde
} /// namespace processor
} /// namespace texta
} /// namespace language
} /// namespace xos

#endif /// ndef XOS_LANGUAGE_TEXTA_PROCESSOR_XDE_CTOUTPUT_HPP 
