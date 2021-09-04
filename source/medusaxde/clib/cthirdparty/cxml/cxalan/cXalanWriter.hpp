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
//   File: cXalanWriter.hpp
//
// Author: $author$
//   Date: 7/18/2011
///////////////////////////////////////////////////////////////////////
#ifndef _CXALANWRITER_HPP
#define _CXALANWRITER_HPP

#include <PlatformSupport/Writer.hpp>
#include "cXalanOutputStream.hpp"

#define CXALANWRITER_USE_OUTPUT_STREAM

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

///////////////////////////////////////////////////////////////////////
// Typedef: cXalanWriterExtend
//
//  Author: $author$
//    Date: 7/18/2011
///////////////////////////////////////////////////////////////////////
typedef nsXalan::Writer
cXalanWriterExtend;
///////////////////////////////////////////////////////////////////////
//  Class: cXalanWriter
//
// Author: $author$
//   Date: 7/18/2011
///////////////////////////////////////////////////////////////////////
class c_INSTANCE_CLASS cXalanWriter
: //virtual public cXalanWriterImplement,
  public cXalanWriterExtend
{
public:
    //typedef cXalanWriterImplement cImplements;
    typedef cXalanWriterExtend cExtends;

#if defined(CXALANWRITER_USE_OUTPUT_STREAM)
#else // defined(CXALANWRITER_USE_OUTPUT_STREAM)
    nsXalan::CharVectorType m_charVector;
    cCharWriterInterface& m_writer;
#endif // defined(CXALANWRITER_USE_OUTPUT_STREAM)

    cXalanOutputStream m_outputStream;

    ///////////////////////////////////////////////////////////////////////
    //  Constructor: cXalanWriter
    //
    //       Author: $author$
    //         Date: 7/18/2011
    ///////////////////////////////////////////////////////////////////////
    cXalanWriter
    (cCharWriterInterface& writer): 
#if defined(CXALANWRITER_USE_OUTPUT_STREAM)
#else // defined(CXALANWRITER_USE_OUTPUT_STREAM)
      m_writer(writer),
#endif // defined(CXALANWRITER_USE_OUTPUT_STREAM)
      m_outputStream(writer)
    {
    }
    ///////////////////////////////////////////////////////////////////////
    //  Destructor: ~cXalanWriter
    //
    //      Author: $author$
    //        Date: 7/18/2011
    ///////////////////////////////////////////////////////////////////////
    virtual ~cXalanWriter()
    {
    }

    ///////////////////////////////////////////////////////////////////////
    //  Function: close
    //
    //    Author: $author$
    //      Date: 7/18/2011
    ///////////////////////////////////////////////////////////////////////
    virtual void close()
    {
#if defined(CXALANWRITER_USE_OUTPUT_STREAM)
        m_outputStream.flush();
#else // defined(CXALANWRITER_USE_OUTPUT_STREAM)
#endif // defined(CXALANWRITER_USE_OUTPUT_STREAM)
    }
    ///////////////////////////////////////////////////////////////////////
    //  Function: flush
    //
    //    Author: $author$
    //      Date: 7/18/2011
    ///////////////////////////////////////////////////////////////////////
    virtual void flush()
    {
#if defined(CXALANWRITER_USE_OUTPUT_STREAM)
        m_outputStream.flush();
#else // defined(CXALANWRITER_USE_OUTPUT_STREAM)
        m_writer.Flush();
#endif // defined(CXALANWRITER_USE_OUTPUT_STREAM)
    }
    ///////////////////////////////////////////////////////////////////////
    //  Function: write
    //
    //    Author: $author$
    //      Date: 7/18/2011
    ///////////////////////////////////////////////////////////////////////
    virtual void write
    (const nsXalan::XalanDOMString& s,
     nsXalan::XalanDOMString::size_type theOffset = 0,
     nsXalan::XalanDOMString::size_type theLength = nsXalan::XalanDOMString::npos)
    {
		const nsXalan::XalanDOMChar* c = s.c_str();

        if ((nsXalan::XalanDOMString::npos) == theLength)
            theLength = (nsXalan::XalanDOMString::size_type)(s.length());

        if (theOffset < theLength)
        {
#if defined(CXALANWRITER_USE_OUTPUT_STREAM)
            m_outputStream.write(c+theOffset, theLength-theOffset);
#else // defined(CXALANWRITER_USE_OUTPUT_STREAM)
            m_charVector.clear();
            nsXalan::TranscodeToLocalCodePage
            (c+theOffset, theLength-theOffset, m_charVector);
            Write(m_charVector);
#endif // defined(CXALANWRITER_USE_OUTPUT_STREAM)
        }
    }
    ///////////////////////////////////////////////////////////////////////
    //  Function: write
    //
    //    Author: $author$
    //      Date: 7/18/2011
    ///////////////////////////////////////////////////////////////////////
    virtual void write
    (const nsXalan::XalanDOMChar* s,
	 nsXalan::XalanDOMString::size_type theOffset = 0,
	 nsXalan::XalanDOMString::size_type theLength = nsXalan::XalanDOMString::npos)
    {
        if ((nsXalan::XalanDOMString::npos) == theLength)
            theLength = Length(s);

        if (theOffset < theLength)
        {
#if defined(CXALANWRITER_USE_OUTPUT_STREAM)
            m_outputStream.write(s+theOffset, theLength-theOffset);
#else // defined(CXALANWRITER_USE_OUTPUT_STREAM)
            m_charVector.clear();
            nsXalan::TranscodeToLocalCodePage
            (s+theOffset, theLength-theOffset, m_charVector);
            Write(m_charVector);
#endif // defined(CXALANWRITER_USE_OUTPUT_STREAM)
        }
    }
    ///////////////////////////////////////////////////////////////////////
    //  Function: write
    //
    //    Author: $author$
    //      Date: 7/18/2011
    ///////////////////////////////////////////////////////////////////////
    virtual void write
    (const char* s,
	 size_t theOffset = 0,
	 size_t theLength = npos)
    {
        if ((npos) == theLength)
            theLength = (size_t)(strlen(s));

        if (theOffset < theLength)
        {
#if defined(CXALANWRITER_USE_OUTPUT_STREAM)
            m_outputStream.write
            (s+theOffset, (nsXalan::XalanOutputStream::size_type)(theLength));
#else // defined(CXALANWRITER_USE_OUTPUT_STREAM)
            for (s+=theOffset, theLength-=theOffset; 
                 theLength; --theLength, s++)
                Write(*s);
#endif // defined(CXALANWRITER_USE_OUTPUT_STREAM)
        }
    }
    ///////////////////////////////////////////////////////////////////////
    //  Function: write
    //
    //    Author: $author$
    //      Date: 7/18/2011
    ///////////////////////////////////////////////////////////////////////
    virtual void write(nsXalan::XalanDOMChar c)
    {
#if defined(CXALANWRITER_USE_OUTPUT_STREAM)
        m_outputStream.write(c);
#else // defined(CXALANWRITER_USE_OUTPUT_STREAM)
        m_charVector.clear();
        nsXalan::TranscodeToLocalCodePage(&c, 1, m_charVector);
        Write(m_charVector);
#endif // defined(CXALANWRITER_USE_OUTPUT_STREAM)
    }
    ///////////////////////////////////////////////////////////////////////
    //  Function: getStream
    //
    //    Author: $author$
    //      Date: 7/18/2011
    ///////////////////////////////////////////////////////////////////////
    virtual nsXalan::XalanOutputStream* getStream()
    {
        return &m_outputStream;
    }
    ///////////////////////////////////////////////////////////////////////
    //  Function: getStream
    //
    //    Author: $author$
    //      Date: 7/18/2011
    ///////////////////////////////////////////////////////////////////////
    virtual const nsXalan::XalanOutputStream* getStream() const
    {
        return &m_outputStream;
    }

    //
    //
    //

#if defined(CXALANWRITER_USE_OUTPUT_STREAM)
#else // defined(CXALANWRITER_USE_OUTPUT_STREAM)
    ///////////////////////////////////////////////////////////////////////
    //  Function: Write
    //
    //    Author: $author$
    //      Date: 7/18/2011
    ///////////////////////////////////////////////////////////////////////
    virtual void Write
    (const nsXalan::CharVectorType& charVector)
    {
        nsXalan::CharVectorType::const_iterator cvi;

        for (cvi = charVector.begin(); cvi != charVector.end(); cvi++)
            Write(*cvi);
    }
    ///////////////////////////////////////////////////////////////////////
    //  Function: Write
    //
    //    Author: $author$
    //      Date: 7/18/2011
    ///////////////////////////////////////////////////////////////////////
    virtual void Write(char c)
    {
        m_outputStream.writeData(&c, 1);
    }
 #endif // defined(CXALANWRITER_USE_OUTPUT_STREAM)
   ///////////////////////////////////////////////////////////////////////
    //  Function: Length
    //
    //    Author: $author$
    //      Date: 7/18/2011
    ///////////////////////////////////////////////////////////////////////
    virtual unsigned int Length
    (const nsXalan::XalanDOMChar* s) const
    {
        unsigned int length = 0;
        if ((s))
        for (length=0; s[length]; length++);
        return length;
    }
};

#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#endif // _CXALANWRITER_HPP 
