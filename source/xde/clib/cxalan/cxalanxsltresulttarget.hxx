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
 *   File: cxalanxsltresulttarget.hxx
 *
 * Author: $author$
 *   Date: 3/13/2008
 **********************************************************************
 */
#ifndef _CXALANXSLTRESULTTARGET_HXX
#define _CXALANXSLTRESULTTARGET_HXX

#include <XSLT/XSLTResultTarget.hpp>
#include "cxalanwriter.hxx"

/**
 **********************************************************************
 *  Class: cXalanXSLTResultTarget
 *
 * Author: $author$
 *   Date: 3/13/2008
 **********************************************************************
 */
class cXalanXSLTResultTarget
: public nsXalan::XSLTResultTarget
{
public:
    typedef nsXalan::XSLTResultTarget cExtends;
    typedef cXalanXSLTResultTarget cDerives;

    cXalanWriter m_writer;

    /**
     **********************************************************************
     * Constructor: cXalanXSLTResultTarget
     *
     *      Author: $author$
     *        Date: 3/13/2008
     **********************************************************************
     */
    cXalanXSLTResultTarget
    (cCharWriterInterface& writer) 
    : m_writer(writer)
    {
        setCharacterStream(&m_writer);
    }
    /**
     **********************************************************************
     * Destructor: cXalanXSLTResultTarget
     *
     *     Author: $author$
     *       Date: 3/13/2008
     **********************************************************************
     */
    virtual ~cXalanXSLTResultTarget()
    {
    }
};
#endif /* _CXALANXSLTRESULTTARGET_HXX */
