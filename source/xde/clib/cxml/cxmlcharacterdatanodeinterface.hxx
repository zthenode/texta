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
 *   File: cxmlcharacterdatanodeinterface.hxx
 *
 * Author: $author$
 *   Date: 12/3/2008
 **********************************************************************
 */
#ifndef _CXMLCHARACTERDATANODEINTERFACE_HXX
#define _CXMLCHARACTERDATANODEINTERFACE_HXX

#include "cxmlnodeinterface.hxx"

#undef CDB_CLASS
#define CDB_CLASS "cXMLCharacterDataNodeInterfaceT"
/**
 **********************************************************************
 *  Class: cXMLCharacterDataNodeInterfaceT
 *
 * Author: $author$
 *   Date: 12/3/2008
 **********************************************************************
 */
template
<class TXMLNodeInterface=cXMLNodeInterface,
 class TImplements=TXMLNodeInterface>
 
class c_INTERFACE_CLASS cXMLCharacterDataNodeInterfaceT
: virtual public TImplements
{
public:
    typedef TImplements cImplements;
    typedef cXMLCharacterDataNodeInterfaceT cDerives;
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
     TLENGTH length=-1) = 0;
    /**
     **********************************************************************
     * Function: DataChars
     *
     *   Author: $author$
     *     Date: 12/3/2008
     **********************************************************************
     */
    virtual const cXMLChar* DataChars
    (TLENGTH& length) const = 0;
    /**
     **********************************************************************
     * Function: Data
     *
     *   Author: $author$
     *     Date: 12/3/2008
     **********************************************************************
     */
    virtual const cXMLString* Data() const = 0;
};
#undef CDB_CLASS

/**
 **********************************************************************
 *  Class: cXMLCharacterDataNodeInterface
 *
 * Author: $author$
 *   Date: 12/3/2008
 **********************************************************************
 */
class c_INTERFACE_CLASS cXMLCharacterDataNodeInterface
: public cXMLCharacterDataNodeInterfaceT<>
{
public:
    typedef cXMLCharacterDataNodeInterfaceT<> cExtends;
    typedef cXMLCharacterDataNodeInterface cDerives;
};

#undef CDB_CLASS
#define CDB_CLASS "cXMLCharacterDataNodeImplementT"
/**
 **********************************************************************
 *  Class: cXMLCharacterDataNodeImplementT
 *
 * Author: $author$
 *   Date: 12/3/2008
 **********************************************************************
 */
template
<class TXMLCharacterDataNodeInterface=cXMLCharacterDataNodeInterface,
 class TImplements=TXMLCharacterDataNodeInterface>
 
class cXMLCharacterDataNodeImplementT
: virtual public TImplements
{
public:
    typedef TImplements cImplements;
    typedef cXMLCharacterDataNodeImplementT cDerives;
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
        TLENGTH count = 0;
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
        const cXMLChar* xmlChars = 0;
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
        const cXMLString* xmlCharacterData = 0;
        return xmlCharacterData;
    }
};
#undef CDB_CLASS

/**
 **********************************************************************
 *  Class: cXMLCharacterDataNodeImplement
 *
 * Author: $author$
 *   Date: 12/3/2008
 **********************************************************************
 */
class cXMLCharacterDataNodeImplement
: virtual public cInterface,
  public cXMLCharacterDataNodeImplementT<>
{
public:
    typedef cInterface cImplements;
    typedef cXMLCharacterDataNodeImplementT<> cExtends;
    typedef cXMLCharacterDataNodeImplement cDerives;
};

#endif /* _CXMLCHARACTERDATANODEINTERFACE_HXX */
