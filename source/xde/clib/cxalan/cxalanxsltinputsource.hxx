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
 *   File: cxalanxsltinputsource.hxx
 *
 * Author: $author$
 *   Date: 3/14/2008
 **********************************************************************
 */
#ifndef _CXALANXSLTINPUTSOURCE_HXX
#define _CXALANXSLTINPUTSOURCE_HXX

#include <XSLT/XSLTInputSource.hpp>

#include "nsxalan.hxx"
#include "cxercesbininputstream.hxx"

/**
 **********************************************************************
 *  Class: cXalanXSLTInputSource
 *
 * Author: $author$
 *   Date: 3/14/2008
 **********************************************************************
 */
class cXalanXSLTInputSource
: public nsXalan::XSLTInputSource
{
public:
    typedef nsXalan::XSLTInputSource cExtends;
    typedef cXalanXSLTInputSource cDerives;

    cCharReaderInterface& m_reader;

    /**
     **********************************************************************
     * Constructor: cXalanXSLTInputSource
     *
     *      Author: $author$
     *        Date: 3/14/2008
     **********************************************************************
     */
    cXalanXSLTInputSource
    (cCharReaderInterface& reader) 
    : m_reader(reader) 
    {
    }
    /**
     **********************************************************************
     * Destructor: cXalanXSLTInputSource
     *
     *     Author: $author$
     *       Date: 3/14/2008
     **********************************************************************
     */
    virtual ~cXalanXSLTInputSource()
    {
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
#endif /* _CXALANXSLTINPUTSOURCE_HXX */
