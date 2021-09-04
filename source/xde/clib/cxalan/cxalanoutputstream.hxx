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
 *   File: cxalanoutputstream.hxx
 *
 * Author: $author$
 *   Date: 3/13/2008
 **********************************************************************
 */
#ifndef _CXALANOUTPUTSTREAM_HXX
#define _CXALANOUTPUTSTREAM_HXX

#include <PlatformSupport/XalanOutputStream.hpp>
#include "nsxalan.hxx"
#include "cwriterinterface.hxx"

/**
 **********************************************************************
 *  Class: cXalanOutputStream
 *
 * Author: $author$
 *   Date: 3/13/2008
 **********************************************************************
 */
class cXalanOutputStream
: public nsXalan::XalanOutputStream
{
public:
    typedef nsXalan::XalanOutputStream cExtends;
    typedef cXalanOutputStream cDerives;

    cCharWriterInterface& m_writer;

    /**
     **********************************************************************
     * Constructor: cXalanOutputStream
     *
     *      Author: $author$
     *        Date: 3/13/2008
     **********************************************************************
     */
    cXalanOutputStream
    (cCharWriterInterface& writer)
    : m_writer(writer)
    {
    }
    /**
     **********************************************************************
     * Destructor: cXalanOutputStream
     *
     *     Author: $author$
     *       Date: 3/13/2008
     **********************************************************************
     */
    virtual ~cXalanOutputStream()
    {
    }
    /**
     **********************************************************************
     * Function: writeData
     *
     *   Author: $author$
     *     Date: 3/13/2008
     **********************************************************************
     */
    virtual void writeData
    (const char *theBuffer, 
     size_type theBufferLength) 
    {
        m_writer.Write
        (theBuffer, (TLENGTH)(theBufferLength));
    }
    /**
     **********************************************************************
     * Function: doFlush
     *
     *   Author: $author$
     *     Date: 3/13/2008
     **********************************************************************
     */
    virtual void doFlush() 
    {
    }
}
;
#endif /* _CXALANOUTPUTSTREAM_HXX */
