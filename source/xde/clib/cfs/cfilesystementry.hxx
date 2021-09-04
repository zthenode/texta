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
 *   File: cfilesystementry.hxx
 *
 * Author: $author$
 *   Date: 9/11/2008
 **********************************************************************
 */
#ifndef _CFILESYSTEMENTRY_HXX
#define _CFILESYSTEMENTRY_HXX

#include "cfilesystementryinterface.hxx"
#include "cbase.hxx"

#undef CDB_CLASS
#define CDB_CLASS "cFileSystemEntryT"
/**
 **********************************************************************
 *  Class: cFileSystemEntryT
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
 class TImplements=cFileSystemEntryImplement,
 class TExtends=cBase>
 
class cFileSystemEntryT
: virtual public TImplements,
  public TExtends
{
public:
    typedef TImplements cImplements;
    typedef TExtends cExtends;
    typedef cFileSystemEntryT cDerives;
    /**
     **********************************************************************
     * Constructor: cFileSystemEntryT
     *
     *      Author: $author$
     *        Date: 9/11/2008
     **********************************************************************
     */
    cFileSystemEntryT() 
    {
    }
};
#undef CDB_CLASS

/**
 **********************************************************************
 *  Typedef: cFileSystemEntry
 *
 *  Author: $author$
 *    Date: 9/11/2008
 **********************************************************************
 */
typedef cFileSystemEntryT<>
cFileSystemEntry;

#endif /* _CFILESYSTEMENTRY_HXX */
