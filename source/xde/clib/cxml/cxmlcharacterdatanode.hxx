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
 *   File: cxmlcharacterdatanode.hxx
 *
 * Author: $author$
 *   Date: 12/3/2008
 **********************************************************************
 */
#ifndef _CXMLCHARACTERDATANODE_HXX
#define _CXMLCHARACTERDATANODE_HXX

#include "cxmlcharacterdatanodeinterface.hxx"
#include "cxmlnode.hxx"

#undef CDB_CLASS
#define CDB_CLASS "cXMLCharacterDataNodeT"
/**
 **********************************************************************
 *  Class: cXMLCharacterDataNodeT
 *
 * Author: $author$
 *   Date: 12/3/2008
 **********************************************************************
 */
template
<class TXMLNode=cXMLNode,
 class TXMLCharacterDataNodeImplement=cXMLCharacterDataNodeImplement,
 class TImplements=TXMLCharacterDataNodeImplement,
 class TExtends=TXMLNode>
 
class cXMLCharacterDataNodeT
: virtual public TImplements,
  public TExtends
{
public:
    typedef TImplements cImplements;
    typedef TExtends cExtends;
    typedef cXMLCharacterDataNodeT cDerives;

    cXMLString m_characterData;

    /**
     **********************************************************************
     * Constructor: cXMLCharacterDataNodeT
     *
     *      Author: $author$
     *        Date: 12/3/2008
     **********************************************************************
     */
    cXMLCharacterDataNodeT
    (eXMLNodeType nodeType=e_XML_NODE_TYPE_VALUE_NONE,
     const cXMLChar* chars=0, TLENGTH charsLength=-1)
    : cExtends(nodeType)
    {
        eError error;
        if (chars)
        if (0 > (charsLength = SetDataChars(chars, charsLength)))
            throw(error = -charsLength);
    }
    /**
     **********************************************************************
     * Constructor: cXMLCharacterDataNodeT
     *
     *      Author: $author$
     *        Date: 12/16/2008
     **********************************************************************
     */
    cXMLCharacterDataNodeT
    (eXMLNodeType nodeType,
     const char* chars, TLENGTH charsLength=-1)
    : cExtends(nodeType)
    {
        eError error;
        if (chars)
        if (0 > (charsLength = SetDataCharsc(chars, charsLength)))
            throw(error = -charsLength);
    }

    /**
     **********************************************************************
     * Function: SetDataCharsc
     *
     *   Author: $author$
     *     Date: 12/16/2008
     **********************************************************************
     */
    virtual TLENGTH SetDataCharsc
    (const char* chars,
     TLENGTH length=-1) 
    {
        TLENGTH count = m_characterData.Assignc(chars, length);
        return count;
    }
    /**
     **********************************************************************
     * Function: SetDataChars
     *
     *   Author: $author$
     *     Date: 12/3/2008
     **********************************************************************
     */
    virtual TLENGTH SetDataChars
    (const cXMLChar* xmlChars,
     TLENGTH length=-1) 
    {
        TLENGTH count = m_characterData.Assign(xmlChars, length);
        return count;
    }
    /**
     **********************************************************************
     * Function: DataChars
     *
     *   Author: $author$
     *     Date: 12/3/2008
     **********************************************************************
     */
    virtual const cXMLChar* DataChars
    (TLENGTH& length) const 
    {
        const cXMLChar* xmlChars = m_characterData.Chars(length);
        return xmlChars;
    }
    /**
     **********************************************************************
     * Function: Data
     *
     *   Author: $author$
     *     Date: 12/3/2008
     **********************************************************************
     */
    virtual const cXMLString* Data() const 
    {
        const cXMLString* xmlCharacterData = &m_characterData;
        return xmlCharacterData;
    }
};
#undef CDB_CLASS

/**
 **********************************************************************
 *  Class: cXMLCharacterDataNode
 *
 * Author: $author$
 *   Date: 12/3/2008
 **********************************************************************
 */
class cXMLCharacterDataNode
: public cXMLCharacterDataNodeT<>
{
public:
    typedef cXMLCharacterDataNodeT<> cExtends;
    typedef cXMLCharacterDataNode cDerives;
    /**
     **********************************************************************
     * Constructor: cXMLCharacterDataNode
     *
     *      Author: $author$
     *        Date: 12/3/2008
     **********************************************************************
     */
    cXMLCharacterDataNode
    (eXMLNodeType nodeType=e_XML_NODE_TYPE_VALUE_NONE,
     const cXMLChar* chars=0, TLENGTH charsLength=-1)
    : cExtends(nodeType, chars, charsLength) 
    {
    }
    /**
     **********************************************************************
     * Constructor: cXMLCharacterDataNode
     *
     *      Author: $author$
     *        Date: 12/16/2008
     **********************************************************************
     */
    cXMLCharacterDataNode
    (eXMLNodeType nodeType,
     const char* chars, TLENGTH charsLength=-1)
    : cExtends(nodeType, chars, charsLength) 
    {
    }
};
#endif /* _CXMLCHARACTERDATANODE_HXX */
