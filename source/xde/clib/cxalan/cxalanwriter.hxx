/**
 **********************************************************************
 * Copyright (c) 1988-2008 $organization$
 *
 * This software is provided by the author and contributors ``as is'' 
 * and any express or implied warranties, including, but not limited to, 
 * the implied warranties of merchantability and fitness for a particular 
 * purpose are disclaimed. In no event shall the author or contributors 
 * be liable for any direct, indirect, incidental, special, exemplary, 
 * or consequential damages (including, but not limited to, procurement 
 * of substitute goods or services; loss of use, data, or profits; or 
 * business interruption) however caused and on any theory of liability, 
 * whether in contract, strict liability, or tort (including negligence 
 * or otherwise) arising in any way out of the use of this software, 
 * even if advised of the possibility of such damage.
 *
 *   File: cxalanwriter.hxx
 *
 * Author: $author$
 *   Date: 3/13/2008
 **********************************************************************
 */
#ifndef _CXALANWRITER_HXX
#define _CXALANWRITER_HXX

#include <string.h>
#include <PlatformSupport/Writer.hpp>
#include "nsxalan.hxx"
#include "cxalanoutputstream.hxx"
#include "cwriterinterface.hxx"

/**
 **********************************************************************
 *  Class: cXalanWriter
 *
 * Author: $author$
 *   Date: 3/13/2008
 **********************************************************************
 */
class cXalanWriter
: public nsXalan::Writer
{
public:
    typedef nsXalan::Writer cExtends;
    typedef cXalanWriter cDerives;

    nsXalan::CharVectorType m_charVector;

    cCharWriterInterface& m_writer;
    cXalanOutputStream m_outputStream;

    /**
     **********************************************************************
     * Constructor: cXalanWriter
     *
     *      Author: $author$
     *        Date: 3/13/2008
     **********************************************************************
     */
    cXalanWriter
    (cCharWriterInterface& writer)
    : m_writer(writer),
      m_outputStream(writer)
    {
    }
    /**
     **********************************************************************
     * Function: close
     *
     *   Author: $author$
     *     Date: 3/13/2008
     **********************************************************************
     */
    virtual void close() 
    {
    }
    /**
     **********************************************************************
     * Function: flush
     *
     *   Author: $author$
     *     Date: 3/13/2008
     **********************************************************************
     */
    virtual void flush() 
    {
    }
    /**
     **********************************************************************
     * Function: write
     *
     *   Author: $author$
     *     Date: 3/13/2008
     **********************************************************************
     */
    virtual void write
    (const char* s,
	 size_t theOffset = 0,
	 size_t theLength = UINT_MAX) 
    {
        char c;

        if (UINT_MAX == theLength)
            theLength = (unsigned int)(strlen(s));

        for (s+=theOffset; theLength; --theLength)
            if ((c=*s)!='\r')
                WriteChar(c);
    }
    /**
     **********************************************************************
     * Function: write
     *
     *   Author: $author$
     *     Date: 3/13/2008
     **********************************************************************
     */
    virtual void write(nsXalan::XalanDOMChar c) 
    {
        m_charVector.clear();
        nsXalan::TranscodeToLocalCodePage(&c, 1, m_charVector);
        WriteXalanCharVector(m_charVector);
    }
    /**
     **********************************************************************
     * Function: write
     *
     *   Author: $author$
     *     Date: 3/13/2008
     **********************************************************************
     */
    virtual void write
    (const nsXalan::XalanDOMChar* s,
	 nsXalan::XalanDOMString::size_type theOffset = 0,
	 nsXalan::XalanDOMString::size_type theLength = UINT_MAX) 
    {
        if (UINT_MAX == theLength)
            theLength = XalanDOMCharLength(s);

        m_charVector.clear();
        nsXalan::TranscodeToLocalCodePage(s+theOffset, theLength, m_charVector);
        WriteXalanCharVector(m_charVector);
    }
    /**
     **********************************************************************
     * Function: write
     *
     *   Author: $author$
     *     Date: 3/13/2008
     **********************************************************************
     */
    virtual void write
    (const nsXalan::XalanDOMString& s,
	 nsXalan::XalanDOMString::size_type theOffset = 0,
	 nsXalan::XalanDOMString::size_type theLength = UINT_MAX) 
    {
		const nsXalan::XalanDOMChar* c = s.c_str();

        if (UINT_MAX == theLength)
            theLength = (unsigned int)(s.length());

        m_charVector.clear();
        nsXalan::TranscodeToLocalCodePage(c+theOffset, theLength, m_charVector);
        WriteXalanCharVector(m_charVector);
    }
    /**
     **********************************************************************
     * Function: XalanDOMCharLength
     *
     *   Author: $author$
     *     Date: 3/13/2008
     **********************************************************************
     */
    unsigned int XalanDOMCharLength
    (const nsXalan::XalanDOMChar* s) const
    {
        unsigned int length;

        for (length=0; s[length]; length++);
        return length;
    }
    /**
     **********************************************************************
     * Function: WriteXalanCharVector
     *
     *   Author: $author$
     *     Date: 3/13/2008
     **********************************************************************
     */
    virtual void WriteXalanCharVector
    (nsXalan::CharVectorType& charVector)
    {
        nsXalan::CharVectorType::const_iterator cvi;
        char c;

        for (cvi = charVector.begin(); cvi != charVector.end(); cvi++)
        {
            if ((c=*cvi)!='\r')
				WriteChar(c);
        }
    }
    /**
     **********************************************************************
     * Function: WriteChar
     *
     *   Author: $author$
     *     Date: 3/13/2008
     **********************************************************************
     */
    virtual void WriteChar(char c)
	{
		m_outputStream.writeData(&c, 1);
	}
    /**
     **********************************************************************
     * Function: getStream
     *
     *   Author: $author$
     *     Date: 3/13/2008
     **********************************************************************
     */
    virtual nsXalan::XalanOutputStream* getStream() 
    {
        return &m_outputStream;
    }
    /**
     **********************************************************************
     * Function: getStream
     *
     *   Author: $author$
     *     Date: 3/13/2008
     **********************************************************************
     */
    virtual const nsXalan::XalanOutputStream* getStream() const
    {
        return &m_outputStream;
    }
};
#endif /* _CXALANWRITER_HXX */
