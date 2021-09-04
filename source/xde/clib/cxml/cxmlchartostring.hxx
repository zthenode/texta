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
 *   File: cxmlchartostring.hxx
 *
 * Author: $author$
 *   Date: 11/19/2008
 **********************************************************************
 */
#ifndef _CXMLCHARTOSTRING_HXX
#define _CXMLCHARTOSTRING_HXX

#include "cxmlstring.hxx"

/**
 **********************************************************************
 *  Class: cXMLCharToString
 *
 * Author: $author$
 *   Date: 11/19/2008
 **********************************************************************
 */
class cXMLCharToString
: public cString
{
public:
    typedef cString cExtends;
    typedef cXMLCharToString cDerives;
    /**
     **********************************************************************
     * Constructor: cXMLCharToString
     *
     *      Author: $author$
     *        Date: 11/19/2008
     **********************************************************************
     */
    cXMLCharToString
    (const cXMLChar* xmlChars=0,
     TLENGTH length=-1) 
    {
        eError error;
        if (xmlChars)
        if (0 > (length = AssignXMLCh(xmlChars, length)))
            throw(error = -length);
    }
    /**
     **********************************************************************
     * Function: AssignXMLCh
     *
     *   Author: $author$
     *     Date: 11/19/2008
     **********************************************************************
     */
    virtual TLENGTH AssignXMLCh
    (const cXMLChar* xmlChars,
     TLENGTH length=-1) 
    {
        TLENGTH count = 0;
        if (0 > (count = Clear()))
            return count;
        count = AppendXMLCh(xmlChars, length);
        return count;
    }
    /**
     **********************************************************************
     * Function: AppendXMLCh
     *
     *   Author: $author$
     *     Date: 11/19/2008
     **********************************************************************
     */
    virtual TLENGTH AppendXMLCh
    (const cXMLChar* xmlChars,
     TLENGTH length=-1) 
    {
        TLENGTH count = 0;
        TLENGTH count2;
        cXMLChar xmlChar;
        if (xmlChars)
        if (0 > length)
            while ((xmlChar = *(xmlChars++)) != 0)
            {
                if (0 > (count2 = PutXMLCh(xmlChar)))
                    return count2;
                count += count2;
            }
        else
        for (; 0 < length; --length)
        {
            xmlChar = *(xmlChars++);
            if (0 > (count2 = PutXMLCh(xmlChar)))
                return count2;
            count += count2;
        }
        return count;
    }
    /**
     **********************************************************************
     * Function: PutXMLCh
     *
     *   Author: $author$
     *     Date: 11/19/2008
     **********************************************************************
     */
    virtual TLENGTH PutXMLCh
    (const cXMLChar& xmlChar) 
    {
        CHAR c = xmlChar.GetCHAR();
        TLENGTH count = Put(c);
        return count;
    }
};
#endif /* _CXMLCHARTOSTRING_HXX */
