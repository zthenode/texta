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
 *   File: cxmlnodenameinterface.hxx
 *
 * Author: $author$
 *   Date: 11/21/2008
 **********************************************************************
 */
#ifndef _CXMLNODENAMEINTERFACE_HXX
#define _CXMLNODENAMEINTERFACE_HXX

#include "cxmlnodeinterface.hxx"
#include "cxmlstring.hxx"

#define DEFAULT_CXMLNODENAME_SEPARATOR_CHAR ':'

#undef CDB_CLASS
#define CDB_CLASS "cXMLNodeNameInterfaceT"
/**
 **********************************************************************
 *  Class: cXMLNodeNameInterfaceT
 *
 * Author: $author$
 *   Date: 11/21/2008
 **********************************************************************
 */
template
<class TXMLChar=cXMLChar,
 class TXMLStringInterface=cXMLCharStringInterface,
 class TImplements=TXMLStringInterface>
 
class c_INTERFACE_CLASS cXMLNodeNameInterfaceT
: virtual public TImplements
{
public:
    typedef TImplements cImplements;
    typedef cXMLNodeNameInterfaceT cDerives;

    /**
     **********************************************************************
     * Function: AssignLocalName
     *
     *   Author: $author$
     *     Date: 11/24/2008
     **********************************************************************
     */
    virtual TLENGTH AssignLocalName
    (const TXMLChar* xmlChars,
     TLENGTH length=-1) = 0;
    /**
     **********************************************************************
     * Function: LocalNameChars
     *
     *   Author: $author$
     *     Date: 11/24/2008
     **********************************************************************
     */
    virtual const TXMLChar* LocalNameChars
    (TLENGTH& length) const = 0;
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
     TLENGTH length=-1) = 0;
    /**
     **********************************************************************
     * Function: UnqualifiedNameChars
     *
     *   Author: $author$
     *     Date: 11/24/2008
     **********************************************************************
     */
    virtual const TXMLChar* UnqualifiedNameChars
    (TLENGTH& length) const = 0;

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
     TLENGTH length=-1) = 0;
    /**
     **********************************************************************
     * Function: NamespacePrefixChars
     *
     *   Author: $author$
     *     Date: 11/25/2008
     **********************************************************************
     */
    virtual const TXMLChar* NamespacePrefixChars
    (TLENGTH& length) const = 0;
};
#undef CDB_CLASS

/**
 **********************************************************************
 *  Class: cXMLNodeNameInterface
 *
 * Author: $author$
 *   Date: 11/21/2008
 **********************************************************************
 */
class c_INTERFACE_CLASS cXMLNodeNameInterface
: virtual public cXMLNodeNameInterfaceT<>
{
public:
    typedef cXMLNodeNameInterfaceT<> cImplements;
    typedef cXMLNodeNameInterface cDerives;
}; 

#undef CDB_CLASS
#define CDB_CLASS "cXMLNodeNameImplementT"
/**
 **********************************************************************
 *  Class: cXMLNodeNameImplementT
 *
 * Author: $author$
 *   Date: 11/21/2008
 **********************************************************************
 */
template
<class TXMLChar=cXMLChar,
 class TXMLStringInterface=cXMLStringInterface,
 class TXMLNodeNameInterface=cXMLNodeNameInterface,
 class TImplements=TXMLNodeNameInterface>
 
class cXMLNodeNameImplementT
: virtual public TImplements
{
public:
    typedef TImplements cImplements;
    typedef cXMLNodeNameImplementT cDerives;
    /**
     **********************************************************************
     * Function: AssignLocalName
     *
     *   Author: $author$
     *     Date: 11/24/2008
     **********************************************************************
     */
    virtual TLENGTH AssignLocalName
    (const TXMLChar* xmlChars,
     TLENGTH length=-1) 
    {
        TLENGTH count = AssignUnqualifiedName(xmlChars, length);
        return count;
    }
    /**
     **********************************************************************
     * Function: LocalNameChars
     *
     *   Author: $author$
     *     Date: 11/24/2008
     **********************************************************************
     */
    virtual const TXMLChar* LocalNameChars
    (TLENGTH& length) const 
    {
        const TXMLChar* xmlChars = UnqualifiedNameChars(length);
        return xmlChars;
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
        const TXMLChar* xmlChars = 0;
        return xmlChars;
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
        const TXMLChar* xmlChars = 0;
        return xmlChars;
    }
};
#undef CDB_CLASS

/**
 **********************************************************************
 *  Class: cXMLNodeNameImplement
 *
 * Author: $author$
 *   Date: 11/21/2008
 **********************************************************************
 */
class cXMLNodeNameImplement
: virtual public cXMLNodeNameImplementT<>
{
public:
    typedef cXMLNodeNameImplementT<> cImplements;
    typedef cXMLNodeNameImplement cDerives;

    static cXMLChar m_namespacePrefixSeparatorXMLChar;
};

#endif /* _CXMLNODENAMEINTERFACE_HXX */
