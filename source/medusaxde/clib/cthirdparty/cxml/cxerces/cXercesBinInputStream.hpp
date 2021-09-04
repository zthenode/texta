///////////////////////////////////////////////////////////////////////
// Copyright (c) 1988-2011 $organization$
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
//   File: cXercesBinInputStream.hpp
//
// Author: $author$
//   Date: 7/19/2011
///////////////////////////////////////////////////////////////////////
#ifndef _CXERCESBININPUTSTREAM_HPP
#define _CXERCESBININPUTSTREAM_HPP

#include <util/BinInputStream.hpp>
#include "nsXerces.hpp"
#include "cCharReaderInterface.hpp"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

///////////////////////////////////////////////////////////////////////
// Typedef: cXercesBinInputStreamExtend
//
//  Author: $author$
//    Date: 7/19/2011
///////////////////////////////////////////////////////////////////////
typedef nsXerces::BinInputStream
cXercesBinInputStreamExtend;
///////////////////////////////////////////////////////////////////////
//  Class: cXercesBinInputStream
//
// Author: $author$
//   Date: 7/19/2011
///////////////////////////////////////////////////////////////////////
class c_INSTANCE_CLASS cXercesBinInputStream
: //virtual public cXercesBinInputStreamImplement,
  public cXercesBinInputStreamExtend
{
public:
    //typedef cXercesBinInputStreamImplement cImplements;
    typedef cXercesBinInputStreamExtend cExtends;

    cCharReaderInterface& m_reader;
    unsigned int m_curPos;

    ///////////////////////////////////////////////////////////////////////
    //  Constructor: cXercesBinInputStream
    //
    //       Author: $author$
    //         Date: 7/19/2011
    ///////////////////////////////////////////////////////////////////////
    cXercesBinInputStream
    (cCharReaderInterface& reader) 
    : m_reader(reader),
      m_curPos(0)
    {
    }

    ///////////////////////////////////////////////////////////////////////
    //  Function: readBytes
    //
    //    Author: $author$
    //      Date: 7/19/2011
    ///////////////////////////////////////////////////////////////////////
    virtual unsigned int readBytes
    (XMLByte *const toFill, const unsigned int maxToRead) 
    {
		char* chars = (char*)(toFill);
		size_t size = (size_t)(maxToRead);
        unsigned int count = 0;
        ssize_t length;
        if (0 <= (length = m_reader.Read(chars, size)))
            m_curPos += (count = (unsigned int)(length));
        return count;
    }
    ///////////////////////////////////////////////////////////////////////
    //  Function: resetPos
    //
    //    Author: $author$
    //      Date: 7/19/2011
    ///////////////////////////////////////////////////////////////////////
    virtual unsigned int resetPos(unsigned int curPos=0)
    {
        unsigned int oldPos = m_curPos;
        m_curPos = curPos;
        return oldPos;
    }
    ///////////////////////////////////////////////////////////////////////
    //  Function: curPos
    //
    //    Author: $author$
    //      Date: 7/19/2011
    ///////////////////////////////////////////////////////////////////////
    virtual unsigned int curPos() const
    {
        return m_curPos;
    }
};


#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#endif // _CXERCESBININPUTSTREAM_HPP 
        

