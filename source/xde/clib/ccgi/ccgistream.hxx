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
 *   File: ccgistream.hxx
 *
 * Author: $author$
 *   Date: 5/2/2008
 **********************************************************************
 */
#ifndef _CCGISTREAM_HXX
#define _CCGISTREAM_HXX

#include "ccgi.hxx"

/**
 **********************************************************************
 *  Class: cCGIStream
 *
 * Author: $author$
 *   Date: 4/1/2008
 **********************************************************************
 */
class cCGIStream
: public cCharStream
{
public:
    typedef cCharStream cExtends;
    typedef cCGIStream cDerives;

    cCGI& m_cgi;

    /**
     **********************************************************************
     * Constructor: cCGIStream
     *
     *      Author: $author$
     *        Date: 4/1/2008
     **********************************************************************
     */
    cCGIStream
    (cCGI& cgi)
    : m_cgi(cgi) 
    {
    }
    /**
     **********************************************************************
     * Function: Write
     *
     *   Author: $author$
     *     Date: 4/1/2008
     **********************************************************************
     */
    virtual TLENGTH Write
    (const char* chars, TLENGTH length=-1) 
    {
        TLENGTH count = m_cgi.OutputContent(chars, length);
        return count;
    }
};

#endif /* _CCGISTREAM_HXX */
