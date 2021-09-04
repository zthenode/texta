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
 *   File: cfilesysteminterface.hxx
 *
 * Author: $author$
 *   Date: 9/10/2008
 **********************************************************************
 */
#ifndef _CFILESYSTEMINTERFACE_HXX
#define _CFILESYSTEMINTERFACE_HXX

#include "cfilesystementryinterface.hxx"

#undef CDB_CLASS
#define CDB_CLASS "cFileSystemInterfaceT"
/**
 **********************************************************************
 *  Class: cFileSystemInterfaceT
 *
 * Author: $author$
 *   Date: 9/10/2008
 **********************************************************************
 */
template
<class TChar=CHAR, 
 class TSize=TSIZE,
 class TLength=TLENGTH,
 TLength VUndefinedLength=UNDEFINED_LENGTH,
 TChar VNullChar=NULL_CHAR,
 class TFileSystemEntryInterface=cFileSystemEntryInterface,
 class TImplements=cInterfaceBase>
 
class c_INTERFACE_CLASS cFileSystemInterfaceT
: virtual public TImplements
{
public:
    typedef TImplements cImplements;
    typedef cFileSystemInterfaceT cDerives;
    /**
     **********************************************************************
     * Function: FindEntry
     *
     *   Author: $author$
     *     Date: 9/11/2008
     **********************************************************************
     */
    virtual TFileSystemEntryInterface* FindEntry
    (eError& error,
     const TChar* path,
     TLength pathLength=VUndefinedLength) = 0;
};
#undef CDB_CLASS

/**
 **********************************************************************
 *  Typedef: cFileSystemInterface
 *
 *  Author: $author$
 *    Date: 9/11/2008
 **********************************************************************
 */
typedef cFileSystemInterfaceT<>
cFileSystemInterface;

#undef CDB_CLASS
#define CDB_CLASS "cFileSystemImplementT"
/**
 **********************************************************************
 *  Class: cFileSystemImplementT
 *
 * Author: $author$
 *   Date: 9/11/2008
 **********************************************************************
 */
template
<class TChar=CHAR, 
 class TSize=TSIZE,
 class TLength=TLENGTH,
 TLength VUndefinedLength=UNDEFINED_LENGTH,
 TChar VNullChar=NULL_CHAR,
 class TFileSystemEntryInterface=cFileSystemEntryInterface,
 class TImplements=cFileSystemInterface>
 
class cFileSystemImplementT
: virtual public TImplements
{
public:
    typedef TImplements cImplements;
    typedef cFileSystemImplementT cDerives;
    /**
     **********************************************************************
     * Function: FindEntry
     *
     *   Author: $author$
     *     Date: 9/11/2008
     **********************************************************************
     */
    virtual TFileSystemEntryInterface* FindEntry
    (eError& error,
     const TChar* path,
     TLength pathLength=VUndefinedLength) 
    {
        TFileSystemEntryInterface* entry = 0;
        error = e_ERROR_NOT_IMPLEMENTED;
        return entry;
    }
};
#undef CDB_CLASS

/**
 **********************************************************************
 *  Typedef: cFileSystemImplement
 *
 *  Author: $author$
 *    Date: 9/11/2008
 **********************************************************************
 */
typedef cFileSystemImplementT<>
cFileSystemImplement;

#endif /* _CFILESYSTEMINTERFACE_HXX */
