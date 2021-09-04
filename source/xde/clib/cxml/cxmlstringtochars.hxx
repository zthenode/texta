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
 *   File: cxmlstringtochars.hxx
 *
 * Author: $author$
 *   Date: 12/14/2008
 **********************************************************************
 */
#ifndef _CXMLSTRINGTOCHARS_HXX
#define _CXMLSTRINGTOCHARS_HXX

#include "cxmlstringtostring.hxx"

/**
 **********************************************************************
 *  Class: cXMLStringToChars
 *
 * Author: $author$
 *   Date: 12/14/2008
 **********************************************************************
 */
class cXMLStringToChars
: virtual public cXMLStringImplement,
  public cBase
{
public:
    typedef cXMLStringImplement cImplements;
    typedef cBase cExtends;
    typedef cXMLStringToChars cDerives;

    cXMLStringToString m_xmlStringToString;

    /**
     **********************************************************************
     * Constructor: cXMLStringToChars
     *
     *      Author: $author$
     *        Date: 12/14/2008
     **********************************************************************
     */
    cXMLStringToChars
    (const cXMLChar* xmlChars=0,
     TLENGTH length=-1) 
    {
        eError error;
        if (xmlChars)
        if (0 > (length = Append(xmlChars, length)))
            throw(error = -length);
    }
    /**
     **********************************************************************
     * Function: Append
     *
     *   Author: $author$
     *     Date: 12/14/2008
     **********************************************************************
     */
    virtual TLENGTH Append
    (const cXMLChar* xmlChars,
     TLENGTH length=-1) 
    {
        TLENGTH count = m_xmlStringToString.
        AppendXMLCh(xmlChars, length);
        return count;
    }
    /**
     **********************************************************************
     * Function: Clear
     *
     *   Author: $author$
     *     Date: 12/14/2008
     **********************************************************************
     */
    virtual TLENGTH Clear() 
    {
        TLENGTH count = m_xmlStringToString.Clear();
        return count;
    }
    /**
     **********************************************************************
     * Function: chars
     *
     *   Author: $author$
     *     Date: 12/14/2008
     **********************************************************************
     */
    virtual const char* chars
    (TLENGTH& length) const 
    {
        const char* chars = m_xmlStringToString.Chars(length);
        return chars;
    }
};
#endif /* _CXMLSTRINGTOCHARS_HXX */
