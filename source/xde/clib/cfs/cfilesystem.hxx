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
 *   File: cfilesystem.hxx
 *
 * Author: $author$
 *   Date: 9/11/2008
 **********************************************************************
 */
#ifndef _CFILESYSTEM_HXX
#define _CFILESYSTEM_HXX

#include "cplatform_stat.h"
#include "cfilesysteminterface.hxx"
#include "cfilesystementry.hxx"
#include "cstring.hxx"

#undef CDB_CLASS
#define CDB_CLASS "cFileSystemT"
/**
 **********************************************************************
 *  Class: cFileSystemT
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
 class TPathToCharString=cString,
 class TFileSystemEntry=cFileSystemEntry,
 class TFileSystemEntryInterface=cFileSystemEntryInterface,
 class TImplements=cFileSystemImplement,
 class TExtends=cBase>
 
class cFileSystemT
: virtual public TImplements,
  public TExtends
{
public:
    typedef TImplements cImplements;
    typedef TExtends cExtends;
    typedef cFileSystemT cDerives;

    TPathToCharString m_pathToCharName;
    TFileSystemEntry m_entry;

    /**
     **********************************************************************
     * Constructor: cFileSystemT
     *
     *      Author: $author$
     *        Date: 9/11/2008
     **********************************************************************
     */
    cFileSystemT() 
    {
    }
    /**
     **********************************************************************
     * Function: FindEntry
     *
     *   Author: $author$
     *     Date: 9/12/2008
     **********************************************************************
     */
    virtual TFileSystemEntryInterface* FindEntry
    (eError& error,
     const TChar* path,
     TLength pathLength=VUndefinedLength) 
    {
        TFileSystemEntryInterface* entry = 0;
        const char* pathChars;
        int err;

        error = e_ERROR_NOT_FOUND;

        if (0 > (pathLength = m_pathToCharName.Assign(path, pathLength)))
            error = -pathLength;
        else
        if ((pathChars = m_pathToCharName.HasChars(pathLength)))
        {
#if defined(WIN32) 
/* Windows
 */
        struct _stat st;
        if (!(err = _stat(pathChars, &st)))
#else /* defined(WIN32) */
/* Unix
 */
        struct stat st;
        if (!(err = stat(pathChars, &st)))
#endif /* defined(WIN32) */
            entry = &m_entry;
        }
        return entry;
    }
};
#undef CDB_CLASS

/**
 **********************************************************************
 *  Typedef: cFileSystem
 *
 *  Author: $author$
 *    Date: 9/11/2008
 **********************************************************************
 */
typedef cFileSystemT<>
cFileSystem;

#endif /* _CFILESYSTEM_HXX */
