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
 *   File: cfilesystementryinterface.hxx
 *
 * Author: $author$
 *   Date: 9/10/2008
 **********************************************************************
 */
#ifndef _CFILESYSTEMENTRYINTERFACE_HXX
#define _CFILESYSTEMENTRYINTERFACE_HXX

#include "cinterfacebase.hxx"

#undef CDB_CLASS
#define CDB_CLASS "cFileSystemEntryInterfaceT"
/**
 **********************************************************************
 *  Class: cFileSystemEntryInterfaceT
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
 class TImplements=cInterfaceBase>
 
class c_INTERFACE_CLASS cFileSystemEntryInterfaceT
: virtual public TImplements
{
public:
    typedef TImplements cImplements;
    typedef cFileSystemEntryInterfaceT cDerives;
};
#undef CDB_CLASS

/**
 **********************************************************************
 *  Typedef: cFileSystemEntryInterface
 *
 *  Author: $author$
 *    Date: 9/10/2008
 **********************************************************************
 */
typedef cFileSystemEntryInterfaceT<>
cFileSystemEntryInterface;

#undef CDB_CLASS
#define CDB_CLASS "cFileSystemEntryImplementT"
/**
 **********************************************************************
 *  Class: cFileSystemEntryImplementT
 *
 * Author: $author$
 *   Date: 9/12/2008
 **********************************************************************
 */
template
<class TChar=CHAR, 
 class TSize=TSIZE,
 class TLength=TLENGTH,
 TLength VUndefinedLength=UNDEFINED_LENGTH,
 TChar VNullChar=NULL_CHAR,
 class TImplements=cFileSystemEntryInterface>
 
class cFileSystemEntryImplementT
: virtual public TImplements
{
public:
    typedef TImplements cImplements;
    typedef cFileSystemEntryImplementT cDerives;
};
#undef CDB_CLASS

/**
 **********************************************************************
 *  Typedef: cFileSystemEntryImplement
 *
 *  Author: $author$
 *    Date: 9/12/2008
 **********************************************************************
 */
typedef cFileSystemEntryImplementT<>
cFileSystemEntryImplement;

#endif /* _CFILESYSTEMENTRYINTERFACE_HXX */
