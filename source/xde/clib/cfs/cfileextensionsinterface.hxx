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
 *   File: cfileextensionsinterface.hxx
 *
 * Author: $author$
 *   Date: 10/4/2008
 **********************************************************************
 */
#ifndef _CFILEEXTENSIONSINTERFACE_HXX
#define _CFILEEXTENSIONSINTERFACE_HXX

#include "cstringinterface.hxx"

#undef CDB_CLASS
#define CDB_CLASS "cFileExtensionsInterfaceT"
/**
 **********************************************************************
 *  Class: cFileExtensionsInterfaceT
 *
 * Author: $author$
 *   Date: 10/4/2008
 **********************************************************************
 */
template
<class TChar=CHAR, 
 class TSize=TSIZE,
 class TLength=TLENGTH,
 TLength VUndefinedLength=UNDEFINED_LENGTH,
 TChar VNullChar=NULL_CHAR,
 class TImplements=cStringInterface>
 
class c_INTERFACE_CLASS cFileExtensionsInterfaceT
: virtual public TImplements
{
public:
    typedef TImplements cImplements;
    typedef cFileExtensionsInterfaceT cDerives;
    /**
     **********************************************************************
     * Function: GetFirstFileExtension
     *
     *   Author: $author$
     *     Date: 10/4/2008
     **********************************************************************
     */
    virtual const TChar* GetFirstFileExtension
    (TLength& length) = 0;
    /**
     **********************************************************************
     * Function: GetLastFileExtension
     *
     *   Author: $author$
     *     Date: 10/4/2008
     **********************************************************************
     */
    virtual const TChar* GetLastFileExtension
    (TLength& length) = 0;
    /**
     **********************************************************************
     * Function: GetNextFileExtension
     *
     *   Author: $author$
     *     Date: 10/4/2008
     **********************************************************************
     */
    virtual const TChar* GetNextFileExtension
    (TLength& length) = 0;
    /**
     **********************************************************************
     * Function: GetPrevFileExtension
     *
     *   Author: $author$
     *     Date: 10/4/2008
     **********************************************************************
     */
    virtual const TChar* GetPrevFileExtension
    (TLength& length) = 0;
};
#undef CDB_CLASS

/**
 **********************************************************************
 *  Typedef: cFileExtensionsInterface
 *
 *  Author: $author$
 *    Date: 10/13/2008
 **********************************************************************
 */
typedef cFileExtensionsInterfaceT<>
cFileExtensionsInterface;

#undef CDB_CLASS
#define CDB_CLASS "cFileExtensionsImplementT"
/**
 **********************************************************************
 *  Class: cFileExtensionsImplementT
 *
 * Author: $author$
 *   Date: 10/4/2008
 **********************************************************************
 */
template
<class TChar=CHAR, 
 class TSize=TSIZE,
 class TLength=TLENGTH,
 TLength VUndefinedLength=UNDEFINED_LENGTH,
 TChar VNullChar=NULL_CHAR,
 class TStringInterface=cStringInterface,
 class TImplements=cFileExtensionsInterface>
 
class cFileExtensionsImplementT
: virtual public TImplements
{
public:
    typedef TImplements cImplements;
    typedef cFileExtensionsImplementT cDerives;
    /**
     **********************************************************************
     * Function: GetFirstFileExtension
     *
     *   Author: $author$
     *     Date: 10/4/2008
     **********************************************************************
     */
    virtual const TChar* GetFirstFileExtension
    (TLength& length) 
    {
        const TChar* chars = 0;
        length = -e_ERROR_NOT_IMPLEMENTED;
        return chars;
    }
    /**
     **********************************************************************
     * Function: GetLastFileExtension
     *
     *   Author: $author$
     *     Date: 10/4/2008
     **********************************************************************
     */
    virtual const TChar* GetLastFileExtension
    (TLength& length) 
    {
        const TChar* chars = 0;
        length = -e_ERROR_NOT_IMPLEMENTED;
        return chars;
    }
    /**
     **********************************************************************
     * Function: GetNextFileExtension
     *
     *   Author: $author$
     *     Date: 10/4/2008
     **********************************************************************
     */
    virtual const TChar* GetNextFileExtension
    (TLength& length) 
    {
        const TChar* chars = 0;
        length = -e_ERROR_NOT_IMPLEMENTED;
        return chars;
    }
    /**
     **********************************************************************
     * Function: GetPrevFileExtension
     *
     *   Author: $author$
     *     Date: 10/4/2008
     **********************************************************************
     */
    virtual const TChar* GetPrevFileExtension
    (TLength& length) 
    {
        const TChar* chars = 0;
        length = -e_ERROR_NOT_IMPLEMENTED;
        return chars;
    }
};
#undef CDB_CLASS

#endif /* _CFILEEXTENSIONSINTERFACE_HXX */
