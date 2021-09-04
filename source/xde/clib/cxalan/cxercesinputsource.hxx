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
 *   File: cxercesinputsource.hxx
 *
 * Author: $author$
 *   Date: 3/14/2008
 **********************************************************************
 */
#ifndef _CXERCESINPUTSOURCE_HXX
#define _CXERCESINPUTSOURCE_HXX

#include <sax/InputSource.hpp>

#include "cxercesbininputstream.hxx"
#include "cxmlchstring.hxx"

/**
 **********************************************************************
 *  Class: cXercesInputSource
 *
 * Author: $author$
 *   Date: 3/14/2008
 **********************************************************************
 */
class cXercesInputSource
: public nsXerces::InputSource
{
public:
    typedef nsXerces::InputSource cExtends;
    typedef cXercesInputSource cDerives;

    cCharReaderInterface& m_reader;
    cXMLChString m_encoding;
    cXMLChString m_publicId;
    cXMLChString m_systemId;

    /**
     **********************************************************************
     * Constructor: cXercesInputSource
     *
     *      Author: $author$
     *        Date: 3/14/2008
     **********************************************************************
     */
    cXercesInputSource
    (cCharReaderInterface& reader) 
    : m_reader(reader) 
    {
    }
    /**
     **********************************************************************
     * Destructor: cXercesInputSource
     *
     *     Author: $author$
     *       Date: 3/14/2008
     **********************************************************************
     */
    virtual ~cXercesInputSource()
    {
    }
    /**
     **********************************************************************
     * Function: setEncoding
     *
     *   Author: $author$
     *     Date: 3/14/2008
     **********************************************************************
     */
    virtual void setEncoding
    (const XMLCh*const xmlChars) 
    {
        const XMLCh* xmlChs;
        if ((xmlChs = xmlChars))
            m_encoding.Assign(xmlChs);
        else m_encoding.Clear();
    }
    /**
     **********************************************************************
     * Function: getEncoding
     *
     *   Author: $author$
     *     Date: 3/14/2008
     **********************************************************************
     */
    virtual const XMLCh* getEncoding() const 
    {
        TLENGTH length = 0;
        const XMLCh* xmlChars = m_encoding.HasChars(length);
        return xmlChars;
    }
    /**
     **********************************************************************
     * Function: setPublicId
     *
     *   Author: $author$
     *     Date: 3/14/2008
     **********************************************************************
     */
    virtual void setPublicId
    (const XMLCh*const xmlChars) 
    {
        const XMLCh* xmlChs;
        if ((xmlChs = xmlChars))
            m_publicId.Assign(xmlChs);
        else m_publicId.Clear();
    }
    /**
     **********************************************************************
     * Function: getPublicId
     *
     *   Author: $author$
     *     Date: 3/14/2008
     **********************************************************************
     */
    virtual const XMLCh* getPublicId() const 
    {
        TLENGTH length = 0;
        const XMLCh* xmlChars = m_publicId.HasChars(length);
        return xmlChars;
    }
    /**
     **********************************************************************
     * Function: setSystemId
     *
     *   Author: $author$
     *     Date: 3/14/2008
     **********************************************************************
     */
    virtual void setSystemId
    (const XMLCh*const xmlChars) 
    {
        const XMLCh* xmlChs;
        if ((xmlChs = xmlChars))
            m_systemId.Assign(xmlChs);
        else m_systemId.Clear();
    }
    /**
     **********************************************************************
     * Function: getSystemId
     *
     *   Author: $author$
     *     Date: 3/14/2008
     **********************************************************************
     */
    virtual const XMLCh* getSystemId() const 
    {
        TLENGTH length = 0;
        const XMLCh* xmlChars = m_systemId.HasChars(length);
        return xmlChars;
    }
    /**
     **********************************************************************
     * Function: makeStream
     *
     *   Author: $author$
     *     Date: 3/14/2008
     **********************************************************************
     */
    virtual nsXerces::BinInputStream* makeStream() const 
    {
        nsXerces::BinInputStream* stream = new cXercesBinInputStream(m_reader);
        return stream;
    }
};
#endif /* _CXERCESINPUTSOURCE_HXX */
