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
//   File: cXalanOutputStream.hpp
//
// Author: $author$
//   Date: 7/18/2011
///////////////////////////////////////////////////////////////////////
#ifndef _CXALANOUTPUTSTREAM_HPP
#define _CXALANOUTPUTSTREAM_HPP

#include <PlatformSupport/XalanOutputStream.hpp>
#include "cCharWriterInterface.hpp"
#include "nsXalan.hpp"

#define CXALANOUTPUTSTREAM_CR '\r'
#define CXALANOUTPUTSTREAM_LF '\n'

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

///////////////////////////////////////////////////////////////////////
// Typedef: cXalanOutputStreamExtend
//
//  Author: $author$
//    Date: 7/18/2011
///////////////////////////////////////////////////////////////////////
typedef nsXalan::XalanOutputStream
cXalanOutputStreamExtend;
///////////////////////////////////////////////////////////////////////
//  Class: cXalanOutputStream
//
// Author: $author$
//   Date: 7/18/2011
///////////////////////////////////////////////////////////////////////
class c_INSTANCE_CLASS cXalanOutputStream
: //virtual public cXalanOutputStreamImplement,
  public cXalanOutputStreamExtend
{
public:
    //typedef cXalanOutputStreamImplement cImplements;
    typedef cXalanOutputStreamExtend cExtends;
    typedef cXalanOutputStream cDerives;

    typedef void (cDerives::*mWriteChar)(char c);
    typedef void (cDerives::*mFlushChar)();

    cCharWriterInterface& m_writer;
    mWriteChar m_writeChar;
    mFlushChar m_flushChar;
    const char m_cr;

    ///////////////////////////////////////////////////////////////////////
    //  Constructor: cXalanOutputStream
    //
    //       Author: $author$
    //         Date: 7/18/2011
    ///////////////////////////////////////////////////////////////////////
    cXalanOutputStream    
    (cCharWriterInterface& writer)
    : m_writer(writer),
      m_writeChar(&cDerives::WriteChar),
      m_flushChar(&cDerives::FlushChar),
      m_cr(CXALANOUTPUTSTREAM_CR)
    {
    }
    ///////////////////////////////////////////////////////////////////////
    //  Destructor: ~cXalanOutputStream
    //
    //      Author: $author$
    //        Date: 7/18/2011
    ///////////////////////////////////////////////////////////////////////
    virtual ~cXalanOutputStream()
    {
    }

    ///////////////////////////////////////////////////////////////////////
    //  Function: writeData
    //
    //    Author: $author$
    //      Date: 7/18/2011
    ///////////////////////////////////////////////////////////////////////
    virtual void writeData
    (const char *theBuffer, 
     size_type theBufferLength)
    {
        if ((theBuffer))
        if ((m_writeChar))
        {
            for (; theBufferLength; --theBufferLength)
                (this->*m_writeChar)(*(theBuffer++));
        }
        else
        m_writer.Write
        (theBuffer, (ssize_t)(theBufferLength));
    }
    ///////////////////////////////////////////////////////////////////////
    //  Function: doFlush
    //
    //    Author: $author$
    //      Date: 7/18/2011
    ///////////////////////////////////////////////////////////////////////
    virtual void doFlush()
    {
        if ((m_flushChar))
            (this->*m_flushChar)();
        m_writer.Flush();
    }

    ///////////////////////////////////////////////////////////////////////
    //  Function: WriteChar
    //
    //    Author: $author$
    //      Date: 8/23/2011
    //
    // Hold any CR as pending to remove CR LF sequences
    ///////////////////////////////////////////////////////////////////////
    void WriteChar(char c)
    {
        if (CXALANOUTPUTSTREAM_CR != c)
            m_writer.Write(&c, 1);
        else
        {
            // Hold CR pending
            //
            m_writeChar = (&cDerives::CrWriteChar);
            m_flushChar = (&cDerives::CrFlushChar);
        }
    }
    ///////////////////////////////////////////////////////////////////////
    //  Function: FlushChar
    //
    //    Author: $author$
    //      Date: 8/23/2011
    ///////////////////////////////////////////////////////////////////////
    void FlushChar()
    {
    }

    ///////////////////////////////////////////////////////////////////////
    //  Function: CrWriteChar
    //
    //    Author: $author$
    //      Date: 8/23/2011
    //
    // Remove any CR before a LF, and continue to hold any CR as pending 
    // to remove CR LF sequences
    ///////////////////////////////////////////////////////////////////////
    void CrWriteChar(char c)
    {
        if (CXALANOUTPUTSTREAM_LF != c)
            // Write CR pending
            //
            m_writer.Write(&m_cr, 1);

        if (CXALANOUTPUTSTREAM_CR != c)
        {
            m_writer.Write(&c, 1);
            // Remove CR pending
            //
            m_writeChar = (&cDerives::WriteChar);
            m_flushChar = (&cDerives::FlushChar);
        }
        // else 
        // Keep CR pending
        //
    }
    ///////////////////////////////////////////////////////////////////////
    //  Function: CrFlushChar
    //
    //    Author: $author$
    //      Date: 8/23/2011
    ///////////////////////////////////////////////////////////////////////
    void CrFlushChar()
    {
        // Write CR pending
        //
        m_writer.Write(&m_cr, 1);
        // Remove CR pending
        //
        m_writeChar = (&cDerives::WriteChar);
        m_flushChar = (&cDerives::FlushChar);
    }
};

#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#endif // _CXALANOUTPUTSTREAM_HPP 
