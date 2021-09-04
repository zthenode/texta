///////////////////////////////////////////////////////////////////////
// Copyright (c) 1988-2013 $organization$
//
// This software is provided by the author and contributors ``as is'' 
// and any express or implied warranties, including, but not limited to, 
// the implied warranties of merchantability and fitness for a particular 
// purpose are disclaimed. In no event shall the author or contributors 
// be liable for any direct, indirect, incidental, special, exemplary, 
// or consequential damages (including, but not limited to, procurement 
// of substitute goods or services; loss of use, data, or profits; or 
// business interruption) however caused and on any theory of liability, 
// whether in contract, strict liability, or tort (including negligence 
// or otherwise) arising in any way out of the use of this software, 
// even if advised of the possibility of such damage.
//
//   File: cBufferWriter.hpp
//
// Author: $author$
//   Date: 8/20/2013
///////////////////////////////////////////////////////////////////////
#ifndef _CBUFFERWRITER_HPP
#define _CBUFFERWRITER_HPP

#include "cWriter.hpp"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

#undef CDB_CLASS
#define CDB_CLASS "cBufferWriterT"
///////////////////////////////////////////////////////////////////////
//  Class: cBufferWriterT
//
// Author: $author$
//   Date: 8/20/2013
///////////////////////////////////////////////////////////////////////
template
<class TWriterImplement=cWriterImplement,
 class TWriterInterface=cWriterInterface,
 class TWhat=char,
 class TExtend=cInstanceBase>

class c_INSTANCE_CLASS cBufferWriterT
: virtual public TWriterImplement, public TExtend {
public:
    typedef TWriterImplement cImplements;
    typedef TExtend cExtends;
    typedef TWhat tWhat;
    ///////////////////////////////////////////////////////////////////////
    //  Constructor: cBufferWriterT
    //
    //       Author: $author$
    //         Date: 8/20/2013
    ///////////////////////////////////////////////////////////////////////
    cBufferWriterT
    (TWhat& buffer, size_t size)
    : m_buffer(buffer), m_size(size) {
    }
    virtual ~cBufferWriterT() {
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t Write(const tWhat* what, ssize_t length=-1) {
        ssize_t count = -e_ERROR_FAILED;

        if (!length)
            return length;

        if (0 > length)
            return count;

        if (length > (count = (ssize_t)(m_size-m_tell)))
            length = count;

        for (count = 0; count < length; count++)
            (&m_buffer)[m_tell++] = what[count];

        return count;
    }
    virtual ssize_t Reset() {
        ssize_t count = m_tell;
        m_tell = 0;
        return count;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    TWhat& m_buffer;
    size_t m_size;
    size_t m_tell;
};
#undef CDB_CLASS

typedef cBufferWriterT
<cWriterImplement, cWriterInterface, char> cBufferWriter;

typedef cBufferWriterT
<cBYTEWriterImplement, cBYTEWriterInterface, BYTE> cBYTEBufferWriter;

#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#endif // _CBUFFERWRITER_HPP 
        

