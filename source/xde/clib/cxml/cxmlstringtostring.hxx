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
 *   File: cxmlstringtostring.hxx
 *
 * Author: $author$
 *   Date: 12/13/2008
 **********************************************************************
 */
#ifndef _CXMLSTRINGTOSTRING_HXX
#define _CXMLSTRINGTOSTRING_HXX

#include "cxmlchartostring.hxx"

/**
 **********************************************************************
 *  Class: cXMLStringToString
 *
 * Author: $author$
 *   Date: 12/13/2008
 **********************************************************************
 */
class cXMLStringToString
: public cXMLCharToString
{
public:
    typedef cXMLCharToString cExtends;
    typedef cXMLStringToString cDerives;
    /**
     **********************************************************************
     * Constructor: cXMLStringToString
     *
     *      Author: $author$
     *        Date: 12/13/2008
     **********************************************************************
     */
    cXMLStringToString
    (const cXMLString& xmlString,
     TLENGTH xmlStringLength=-1) 
    {
        eError error;
        if (0 > (xmlStringLength = AppendXML(xmlString, xmlStringLength)))
            throw(error = -xmlStringLength);
    }
    /**
     **********************************************************************
     * Constructor: cXMLStringToString
     *
     *      Author: $author$
     *        Date: 12/13/2008
     **********************************************************************
     */
    cXMLStringToString() 
    {
    }
    /**
     **********************************************************************
     * Function: AssignXML
     *
     *   Author: $author$
     *     Date: 12/13/2008
     **********************************************************************
     */
    virtual TLENGTH AssignXML
    (const cXMLString& xmlString,
     TLENGTH xmlStringLength=-1) 
    {
        TLENGTH count = 0;
        if (0 > (count = Clear()))
            return count;
        count = AppendXML(xmlString, xmlStringLength);
        return count;
    }
    /**
     **********************************************************************
     * Function: AppendXML
     *
     *   Author: $author$
     *     Date: 12/13/2008
     **********************************************************************
     */
    virtual TLENGTH AppendXML
    (const cXMLString& xmlString,
     TLENGTH xmlStringLength=-1) 
    {
        TLENGTH count = 0;
        TLENGTH xmlCharsLength;
        const cXMLChar* xmlChars;
        
        if ((xmlChars = xmlString.Chars(xmlCharsLength)))
        {
            if ((0 <= xmlCharsLength) && (0 <= xmlStringLength))
            if (xmlStringLength < xmlCharsLength)
                xmlCharsLength = xmlStringLength;

            count = AppendXMLCh(xmlChars, xmlCharsLength);
        }
        return count;
    }
};
#endif /* _CXMLSTRINGTOSTRING_HXX */
