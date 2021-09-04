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
 *   File: cxmldocumentparserinterface.hxx
 *
 * Author: $author$
 *   Date: 12/5/2008
 **********************************************************************
 */
#ifndef _CXMLDOCUMENTPARSERINTERFACE_HXX
#define _CXMLDOCUMENTPARSERINTERFACE_HXX

#include "cxmlnodeinterface.hxx"

#undef CDB_CLASS
#define CDB_CLASS "cXMLDocumentParserInterfaceT"
/**
 **********************************************************************
 *  Class: cXMLDocumentParserInterfaceT
 *
 * Author: $author$
 *   Date: 12/5/2008
 **********************************************************************
 */
template
<class TXMLNodeListInterface=cXMLNodeListInterface,
 class TInterface=cInterface,
 class TImplements=TInterface>
 
class c_INTERFACE_CLASS cXMLDocumentParserInterfaceT
: virtual public TImplements
{
public:
    typedef TImplements cImplements;
    typedef cXMLDocumentParserInterfaceT cDerives;

    /**
     **********************************************************************
     * Function: Parse
     *
     *   Author: $author$
     *     Date: 12/5/2008
     **********************************************************************
     */
    virtual const TXMLNodeListInterface* Parse
    (eError& error,
     cCharReaderInterface& reader,
     TLENGTH length=-1) = 0;
    /**
     **********************************************************************
     * Function: ParseNodes
     *
     *   Author: $author$
     *     Date: 12/5/2008
     **********************************************************************
     */
    virtual const TXMLNodeListInterface* ParseNodes
    (eError& error,
     const TXMLNodeListInterface& xmlNodeList) = 0;
    /**
     **********************************************************************
     * Function: Scan
     *
     *   Author: $author$
     *     Date: 12/5/2008
     **********************************************************************
     */
    virtual const TXMLNodeListInterface* Scan
    (eError& error,
     cCharReaderInterface& reader,
     TLENGTH length=-1) = 0;
};
#undef CDB_CLASS

/**
 **********************************************************************
 *  Class: cXMLDocumentParserInterface
 *
 * Author: $author$
 *   Date: 12/5/2008
 **********************************************************************
 */
class cXMLDocumentParserInterface
: public cXMLDocumentParserInterfaceT<>
{
public:
    typedef cXMLDocumentParserInterfaceT<> cExtends;
    typedef cXMLDocumentParserInterface cDerives;
};

#undef CDB_CLASS
#define CDB_CLASS "cXMLDocumentParserImplementT"
/**
 **********************************************************************
 *  Class: cXMLDocumentParserImplementT
 *
 * Author: $author$
 *   Date: 12/5/2008
 **********************************************************************
 */
template
<class TXMLNodeListInterface=cXMLNodeListInterface,
 class TXMLDocumentParserInterface=cXMLDocumentParserInterface,
 class TImplements=TXMLDocumentParserInterface>
 
class cXMLDocumentParserImplementT
: virtual public TImplements
{
public:
    typedef TImplements cImplements;
    typedef cXMLDocumentParserImplementT cDerives;

    /**
     **********************************************************************
     * Function: Parse
     *
     *   Author: $author$
     *     Date: 12/5/2008
     **********************************************************************
     */
    virtual const TXMLNodeListInterface* Parse
    (eError& error,
     cCharReaderInterface& reader,
     TLENGTH length=-1) 
    {
        const TXMLNodeListInterface* xmlNodeList = 0;
        if ((xmlNodeList = Scan(error, reader, length)))
            xmlNodeList = ParseNodes(error, *xmlNodeList);
        return xmlNodeList;
    }
    /**
     **********************************************************************
     * Function: ParseNodes
     *
     *   Author: $author$
     *     Date: 12/5/2008
     **********************************************************************
     */
    virtual const TXMLNodeListInterface* ParseNodes
    (eError& error,
     const TXMLNodeListInterface& xmlNodeList) 
    {
        const TXMLNodeListInterface* parsedXmlNodeList = 0;
        error = e_ERROR_NOT_IMPLEMENTED;
        return parsedXmlNodeList;
    }
    /**
     **********************************************************************
     * Function: Scan
     *
     *   Author: $author$
     *     Date: 12/5/2008
     **********************************************************************
     */
    virtual const TXMLNodeListInterface* Scan
    (eError& error,
     cCharReaderInterface& reader,
     TLENGTH length=-1) 
    {
        const TXMLNodeListInterface* xmlNodeList = 0;
        error = e_ERROR_NOT_IMPLEMENTED;
        return xmlNodeList;
    }
};
#undef CDB_CLASS

/**
 **********************************************************************
 *  Class: cXMLDocumentParserImplement
 *
 * Author: $author$
 *   Date: 12/5/2008
 **********************************************************************
 */
class cXMLDocumentParserImplement
: public cXMLDocumentParserImplementT<>
{
public:
    typedef cXMLDocumentParserImplementT<> cExtends;
    typedef cXMLDocumentParserImplement cDerives;
};

#endif /* _CXMLDOCUMENTPARSERINTERFACE_HXX */
