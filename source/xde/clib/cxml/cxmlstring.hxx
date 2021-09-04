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
 *   File: cxmlstring.hxx
 *
 * Author: $author$
 *   Date: 11/5/2008
 **********************************************************************
 */
#ifndef _CXMLSTRING_HXX
#define _CXMLSTRING_HXX

#include "cxmlchar.hxx"
#include "cstringbase.hxx"
#include "cstring.hxx"

#define CXMLSTRING_CSTRINGBASE_DEFAULT_SIZE 32

/**
 **********************************************************************
 * Typedef: cXMLCharReaderInterface
 *
 *  Author: $author$
 *    Date: 11/12/2008
 **********************************************************************
 */
typedef cReaderInterfaceT
<cXMLChar, TSIZE, TLENGTH, UNDEFINED_LENGTH,
 cInterfaceBase>
cXMLCharReaderInterface;
/**
 **********************************************************************
 * Typedef: cXMLCharWriterInterface
 *
 *  Author: $author$
 *    Date: 11/12/2008
 **********************************************************************
 */
typedef cWriterInterfaceT
<cXMLChar, TSIZE, TLENGTH, UNDEFINED_LENGTH,
 cInterfaceBase>
cXMLCharWriterInterface;
/**
 **********************************************************************
 * Typedef: cXMLCharReaderImplement
 *
 *  Author: $author$
 *    Date: 11/12/2008
 **********************************************************************
 */
typedef cReaderImplementT
<cXMLChar, TSIZE, TLENGTH, UNDEFINED_LENGTH,
 cXMLCharReaderInterface>
cXMLCharReaderImplement;
/**
 **********************************************************************
 * Typedef: cXMLCharWriterImplement
 *
 *  Author: $author$
 *    Date: 11/12/2008
 **********************************************************************
 */
typedef cWriterImplementT
<cXMLChar, TSIZE, TLENGTH, UNDEFINED_LENGTH,
 cXMLCharWriterInterface>
cXMLCharWriterImplement;
/**
 **********************************************************************
 * Typedef: cXMLCharStreamInterface
 *
 *  Author: $author$
 *    Date: 11/12/2008
 **********************************************************************
 */
typedef cStreamInterfaceT
<cXMLChar, TSIZE, TLENGTH, UNDEFINED_LENGTH,
 cXMLCharReaderInterface, cXMLCharWriterInterface>
cXMLCharStreamInterface;
/**
 **********************************************************************
 * Typedef: cXMLCharStreamImplement
 *
 *  Author: $author$
 *    Date: 11/12/2008
 **********************************************************************
 */
typedef cStreamImplementT
<cXMLChar, TSIZE, TLENGTH, UNDEFINED_LENGTH,
 cXMLCharReaderInterface, cXMLCharWriterInterface, 
 cXMLCharStreamInterface, cXMLCharReaderImplement, cXMLCharWriterImplement>
cXMLCharStreamImplement;
/**
 **********************************************************************
 * Typedef: cXMLCharStringInterface
 *
 *  Author: $author$
 *    Date: 11/12/2008
 **********************************************************************
 */
typedef cStringInterfaceT
<cXMLChar, TSIZE, TLENGTH, UNDEFINED_LENGTH, CHAR, NULL_CHAR,
 cXMLCharStreamInterface>
cXMLCharStringInterface;
/**
 **********************************************************************
 * Typedef: cXMLCharStringImplementBase
 *
 *  Author: $author$
 *    Date: 11/12/2008
 **********************************************************************
 */
typedef cStringImplementT
<cXMLChar, TSIZE, TLENGTH, UNDEFINED_LENGTH, CHAR, NULL_CHAR,
 cXMLCharStreamInterface, cXMLCharStringInterface, cXMLCharStreamImplement>
cXMLCharStringImplementBase;
/**
 **********************************************************************
 *  Class: cXMLCharStringImplement
 *
 * Author: $author$
 *   Date: 12/2/2008
 **********************************************************************
 */
class cXMLCharStringImplement
: virtual public cXMLCharStringImplementBase
{
public:
    typedef cXMLCharStringImplementBase cImplements;
    typedef cXMLCharStringImplement cDerives;
    /**
     **********************************************************************
     * Function: Assignc
     *
     *   Author: $author$
     *     Date: 12/2/2008
     **********************************************************************
     */
    virtual TLENGTH Assignc
    (const char* chars,
     TLENGTH length=-1) 
    {
        TLENGTH count = 0;
        if (0 > (count = Clear()))
            return count;
        count = Appendc(chars, length);
        return count;
    }
    /**
     **********************************************************************
     * Function: Appendc
     *
     *   Author: $author$
     *     Date: 12/2/2008
     **********************************************************************
     */
    virtual TLENGTH Appendc
    (const char* chars,
     TLENGTH length=-1) 
    {
        TLENGTH count = 0;
        char ch;
        cXMLChar xmlCh;
        if (0 > length)
        {
            for (; (ch = *chars); chars++, count++)
            {
                if (0 > (length = xmlCh.SetCHAR(ch)))
                    return length;
                if (0 > (length = Append(&xmlCh, 1)))
                    return length;
            }
        }
        else
        {
            for (; count < length; chars++, count++)
            {
                ch = *chars;
                if (0 > (length = xmlCh.SetCHAR(ch)))
                    return length;
                if (0 > (length = Append(&xmlCh, 1)))
                    return length;
            }
        }
        return count;
    }
};
/**
 **********************************************************************
 * Typedef: cXMLCharStringBase
 *
 *  Author: $author$
 *    Date: 11/12/2008
 **********************************************************************
 */
typedef cStringBaseT
<cXMLChar, TSIZE, TLENGTH, 
 CHAR, NULL_CHAR, UNDEFINED_LENGTH,
 CXMLSTRING_CSTRINGBASE_DEFAULT_SIZE>
cXMLCharStringBase;
/**
 **********************************************************************
 * Typedef: cXMLCharStringExtends
 *
 *  Author: $author$
 *    Date: 11/12/2008
 **********************************************************************
 */
typedef cStringT
<cXMLChar, TSIZE, TLENGTH, UNDEFINED_LENGTH, CHAR, NULL_CHAR,
 cXMLCharStreamInterface, cXMLCharStringImplement, cXMLCharStringBase>
cXMLCharStringExtends;

/**
 **********************************************************************
 *  Class: cXMLCharString
 *
 * Author: $author$
 *   Date: 12/12/2008
 **********************************************************************
 */
class cXMLCharString
: public cXMLCharStringExtends
{
public:
    typedef cXMLCharStringExtends cExtends;
    typedef cXMLCharString cDerives;
    /**
     **********************************************************************
     * Constructor: cXMLCharString
     *
     *      Author: $author$
     *        Date: 12/12/2008
     **********************************************************************
     */
    cXMLCharString
    (const cXMLChar* xmlChars=0,
     TLENGTH length=-1) 
    : cExtends(xmlChars, length)
    {
    }
    /**
     **********************************************************************
     * Function: Compare
     *
     *   Author: $author$
     *     Date: 12/12/2008
     **********************************************************************
     */
    inline int Compare
    (const cXMLCharString& toXmlCharString, TLENGTH length=-1) const 
    {
        int unequal = compare(toXmlCharString, length);
        return unequal;
    }
    /**
     **********************************************************************
     * Function: Compare
     *
     *   Author: $author$
     *     Date: 12/12/2008
     **********************************************************************
     */
    inline int Compare
    (const cXMLChar* toXmlChars, TLENGTH length=-1) const 
    {
        int unequal = compare(toXmlChars, length);
        return unequal;
    }
};

/**
 **********************************************************************
 * Typedef: cXMLStringInterface
 *
 *  Author: $author$
 *    Date: 11/24/2008
 **********************************************************************
 */
typedef cXMLCharStringInterface
cXMLStringInterface;

/**
 **********************************************************************
 * Typedef: cXMLStringImplement
 *
 *  Author: $author$
 *    Date: 12/14/2008
 **********************************************************************
 */
typedef cXMLCharStringImplement
cXMLStringImplement;

/**
 **********************************************************************
 * Typedef: cXMLString
 *
 *  Author: $author$
 *    Date: 11/5/2008
 **********************************************************************
 */
typedef cXMLCharString
cXMLString;

#endif /* _CXMLSTRING_HXX */
