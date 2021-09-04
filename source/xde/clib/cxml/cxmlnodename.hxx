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
 *   File: cxmlnodename.hxx
 *
 * Author: $author$
 *   Date: 11/26/2008
 **********************************************************************
 */
#ifndef _CXMLNODENAME_HXX
#define _CXMLNODENAME_HXX

#include "cxmlnodenameinterface.hxx"

#undef CDB_CLASS
#define CDB_CLASS "cXMLNodeNameT"
/**
 **********************************************************************
 *  Class: cXMLNodeNameT
 *
 * Author: $author$
 *   Date: 11/26/2008
 **********************************************************************
 */
template
<class TXMLChar=cXMLChar,
 class TXMLString=cXMLCharString,
 class TXMLNodeNameImplement=cXMLNodeNameImplement,
 class TImplements=TXMLNodeNameImplement,
 class TExtends=TXMLString>
 
class cXMLNodeNameT
: virtual public TImplements,
  public TExtends
{
public:
    typedef TImplements cImplements;
    typedef TExtends cExtends;
    typedef cXMLNodeNameT cDerives;

    TXMLString m_unqualifiedName;
    TXMLString m_namespacePrefix;

    /**
     **********************************************************************
     * Constructor: cXMLNodeNameT
     *
     *      Author: $author$
     *        Date: 11/26/2008
     **********************************************************************
     */
    cXMLNodeNameT
    (const TXMLChar* nameChars=0, TLENGTH nameLength=-1,
     const TXMLChar* namespacePrefixChars=0, TLENGTH namespacePrefixLength=-1) 
    {
        eError error;

        if (nameChars)
        if (0 > (nameLength = Assign(nameChars, nameLength)))
            throw(error = -nameLength);

        if (namespacePrefixChars)
        if (0 > (namespacePrefixLength = AssignNamespacePrefix
            (nameChars, namespacePrefixLength)))
            throw(error = -namespacePrefixLength);
    }

    /**
     **********************************************************************
     * Function: Assign
     *
     *   Author: $author$
     *     Date: 11/24/2008
     **********************************************************************
     */
    virtual TLENGTH Assign
    (const TXMLChar* xmlChars,
     TLENGTH length=-1) 
    {
        TLENGTH count = 0;
        TLENGTH length2;
        const TXMLChar* xmlChar;
        if (0 <= (count = AssignChars(xmlChars, length)))
        {
            if (0 < (length2 = m_namespacePrefix.Clear()))
                return length2;

            if (0 < (length2 = m_unqualifiedName.Clear()))
                return length2;

            if ((xmlChars = CTHIS HasChars(length)))
            for (xmlChar = xmlChars, length2 = 0; 
                 0 < length; --length, length2++, xmlChar++)
            {
                if (*xmlChar != CTHIS m_namespacePrefixSeparatorXMLChar)
                    continue;

                if (0 > (length2 = m_namespacePrefix.Assign(xmlChars, length2)))
                    return length2;

                if (0 > (length2 = m_unqualifiedName.Assign
                    (xmlChars += (length2+1), length -= (length2+1))))
                    return length2;

                break;
            }
        }
        return count;
    }
    /**
     **********************************************************************
     * Function: QualifiedName
     *
     *   Author: $author$
     *     Date: 11/27/2008
     **********************************************************************
     */
    virtual const TXMLString* QualifiedName() const 
    {
        const TXMLString* xmlString = (const TXMLString*)(this);
        return xmlString;
    }

    /**
     **********************************************************************
     * Function: AssignUnqualifiedName
     *
     *   Author: $author$
     *     Date: 11/24/2008
     **********************************************************************
     */
    virtual TLENGTH AssignUnqualifiedName
    (const TXMLChar* xmlChars,
     TLENGTH length=-1) 
    {
        TLENGTH count = 0;
        if (0 >= (count = m_unqualifiedName.Assign(xmlChars, length)))
        if (0 > (length = UpdateNamespacePrefix()))
            return length;
        return count;
    }
    /**
     **********************************************************************
     * Function: UnqualifiedNameChars
     *
     *   Author: $author$
     *     Date: 11/24/2008
     **********************************************************************
     */
    virtual const TXMLChar* UnqualifiedNameChars
    (TLENGTH& length) const 
    {
        const TXMLChar* xmlChars = m_unqualifiedName.Chars(length);
        return xmlChars;
    }
    /**
     **********************************************************************
     * Function: UnqualifiedName
     *
     *   Author: $author$
     *     Date: 11/27/2008
     **********************************************************************
     */
    virtual const TXMLString* UnqualifiedName() const 
    {
        const TXMLString* xmlString = &m_unqualifiedName;
        return xmlString;
    }

    /**
     **********************************************************************
     * Function: AssignNamespacePrefix
     *
     *   Author: $author$
     *     Date: 11/25/2008
     **********************************************************************
     */
    virtual TLENGTH AssignNamespacePrefix
    (const TXMLChar* xmlChars,
     TLENGTH length=-1) 
    {
        TLENGTH count = 0;
        if (0 <= (count = m_namespacePrefix.Assign(xmlChars, length)))
        if (0 > (length = UpdateNamespacePrefix()))
            return length;
        return count;
    }
    /**
     **********************************************************************
     * Function: NamespacePrefixChars
     *
     *   Author: $author$
     *     Date: 11/25/2008
     **********************************************************************
     */
    virtual const TXMLChar* NamespacePrefixChars
    (TLENGTH& length) const 
    {
        const TXMLChar* xmlChars = m_namespacePrefix.Chars(length);
        return xmlChars;
    }
    /**
     **********************************************************************
     * Function: NamespacePrefix
     *
     *   Author: $author$
     *     Date: 11/27/2008
     **********************************************************************
     */
    virtual const TXMLString* NamespacePrefix() const 
    {
        const TXMLString* xmlString = &m_namespacePrefix;
        return xmlString;
    }

    /**
     **********************************************************************
     * Function: UpdateNamespacePrefix
     *
     *   Author: $author$
     *     Date: 11/26/2008
     **********************************************************************
     */
    virtual TLENGTH UpdateNamespacePrefix() 
    {
        TLENGTH count = 0;
        const TXMLChar* xmlChars;
        TLENGTH length;

        if (0 > (length = CTHIS Clear()))
            return length;

        if ((xmlChars = m_namespacePrefix.HasChars(length)))
        if (0 > (length = Assign(xmlChars, length)))
            return length;
        else
        if (0 > (length = Append(&(CTHIS m_namespacePrefixSeparatorXMLChar), 1)))
            return length;

        if ((xmlChars = m_unqualifiedName.Chars(length)))
        if (0 > (length = Append(xmlChars, length)))
            return length;
        else
        count = length;

        return count;
    }
};
#undef CDB_CLASS

/**
 **********************************************************************
 *  Class: cXMLNodeName
 *
 * Author: $author$
 *   Date: 11/26/2008
 **********************************************************************
 */
class cXMLNodeName
: public cXMLNodeNameT<>
{
public:
    typedef cXMLNodeNameT<> cExtends;
    typedef cXMLNodeName cDerives;
    /**
     **********************************************************************
     * Constructor: cXMLNodeName
     *
     *      Author: $author$
     *        Date: 11/26/2008
     **********************************************************************
     */
    cXMLNodeName
    (const cXMLChar* nameChars=0, TLENGTH nameLength=-1,
     const cXMLChar* namespacePrefixChars=0, TLENGTH namespacePrefixLength=-1) 
    : cExtends
      (nameChars, nameLength,
       namespacePrefixChars, namespacePrefixLength)
    {
    }
};
#endif /* _CXMLNODENAME_HXX */
