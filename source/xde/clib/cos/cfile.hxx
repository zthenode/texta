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
 *   File: cfile.hxx
 *
 * Author: $author$
 *   Date: 3/5/2008
 **********************************************************************
 */
#ifndef _CFILE_HXX
#define _CFILE_HXX

#include "cfileinterface.hxx"
#include "cfilestream.hxx"

#undef CDB_CLASS
#define CDB_CLASS "cFileT"
/**
 **********************************************************************
 *  Class: cFileT
 *
 * Author: $author$
 *   Date: 3/5/2008
 **********************************************************************
 */
template
<class TWhat=CHAR,
 class TSize=TSIZE,
 class TLength=TLENGTH,
 TLength VUndefinedLength=UNDEFINED_LENGTH,
 class TImplements=cFileInterface,
 class TExtends=cFILEStream>
 
class cFileT
: virtual public TImplements,
  public TExtends
{
public:
    typedef TImplements cImplements;
    typedef TExtends cExtends;
    typedef cFileT cDerives;
    /**
     **********************************************************************
     * Constructor: cFileT
     *
     *      Author: $author$
     *        Date: 3/5/2008
     **********************************************************************
     */
    cFileT(FILE* attached=INVALID_FILEP) 
    : cExtends(attached)
    {
    }
    /**
     **********************************************************************
     * Destructor: cFileT
     *
     *     Author: $author$
     *       Date: 3/5/2008
     **********************************************************************
     */
    virtual ~cFileT()
    {
    }
    /**
     **********************************************************************
     * Function: Open
     *
     *   Author: $author$
     *     Date: 3/18/2008
     **********************************************************************
     */
    virtual eError Open
    (const char* filename,
     const char* filemode="r",
     bool onlyClosed=false) 
    {
        eError error = e_ERROR_FAILED;
        eError error2;
        FILE* attached;
        bool opened;

        if ((opened = (INVALID_FILEP != (attached = CTHIS Attached()))))
        if (onlyClosed)
            error = e_ERROR_ALREADY_ATTACHED;
        else
        if ((error2 = Close(opened)))
            return error2;

        if ((opened = (INVALID_FILEP != (attached 
            = cplatform_fopen(filename, filemode)))))
        if ((error = CTHIS Attach(attached)))
            cplatform_fclose(attached);
        return error;
    }
    /**
     **********************************************************************
     * Function: Close
     *
     *   Author: $author$
     *     Date: 3/18/2008
     **********************************************************************
     */
    virtual eError Close
    (bool onlyOpen=false) 
    {
        eError error = e_ERROR_FAILED;
        FILE* attached;
        bool opened;
        int err;

        if (!(opened = (INVALID_FILEP != (attached = CTHIS Attached()))))
        if (onlyOpen)
            error = e_ERROR_NOT_ATTACHED;
        else
        return e_ERROR_NONE;

        if (!(err = cplatform_fclose(attached)))
            error = CTHIS Detach(attached);
        return error;
    }
    /**
     **********************************************************************
     * Function: Write
     *
     *   Author: $author$
     *     Date: 3/5/2008
     **********************************************************************
     */
    virtual TLength Write
    (const TWhat* what, TLength length=VUndefinedLength) 
    {
        TLength count = 0;
        size_t amount;
        FILE* attached;

        if (INVALID_FILEP == (attached = CTHIS Attached()))
            count = -e_ERROR_NOT_ATTACHED;
        else
        if (0 > length)
            for (count = 0; *what != 0; what++, count += length)
            {
                if (0 > (length = Write(what, 1)))
                    return length;
            }
        else
        if (0 < (amount = (size_t)(length)))
        if (length <= (TLength)(amount = cplatform_fwrite
            (what, sizeof(TWhat), amount, attached)))
            count = length;
        else count = -e_ERROR_WRITE;
        return count;
    }
    /**
     **********************************************************************
     * Function: Read
     *
     *   Author: $author$
     *     Date: 3/5/2008
     **********************************************************************
     */
    virtual TLength Read
    (TWhat* what, TSize size) 
    {
        TLength count = 0;
        size_t amount;
        FILE* attached;

        if (INVALID_FILEP == (attached = CTHIS Attached()))
            count = -e_ERROR_NOT_ATTACHED;
        else
        if (0 < (amount = (size_t)(size)))
        if (size <= (TSize)(amount = cplatform_fread
            (what, sizeof(TWhat), amount, attached)))
            count = (TLength)(size);
        else count = -e_ERROR_READ;
        return count;
    }
};
#undef CDB_CLASS

/**
 **********************************************************************
 *  Typedef: cFileExtends
 *
 *  Author: $author$
 *    Date: 10/20/2008
 **********************************************************************
 */
typedef cFileT
  <CHAR,TSIZE,TLENGTH,UNDEFINED_LENGTH,
   cFileInterface,cFILEStream>
cFileExtends;
/**
 **********************************************************************
 *  Class: cFile
 *
 * Author: $author$
 *   Date: 3/5/2008
 **********************************************************************
 */
class cFile
: public cFileExtends
{
public:
    typedef cFileExtends cExtends;
    typedef cFile cDerives;
    /**
     **********************************************************************
     * Constructor: cFile
     *
     *      Author: $author$
     *        Date: 3/5/2008
     **********************************************************************
     */
    cFile(FILE* attached=INVALID_FILEP) 
    : cExtends(attached) 
    {
    }
};

/**
 **********************************************************************
 *  Typedef: cCharFileExtends
 *
 *  Author: $author$
 *    Date: 10/20/2008
 **********************************************************************
 */
typedef cFileT
  <char,TSIZE,TLENGTH,UNDEFINED_LENGTH,
   cCharFileInterface,cCharFILEStream>
cCharFileExtends;
/**
 **********************************************************************
 *  Class: cCharFile
 *
 * Author: $author$
 *   Date: 3/5/2008
 **********************************************************************
 */
class cCharFile
: public cCharFileExtends
{
public:
    typedef cCharFileExtends cExtends;
    typedef cCharFile cDerives;
    /**
     **********************************************************************
     * Constructor: cCharFile
     *
     *      Author: $author$
     *        Date: 3/5/2008
     **********************************************************************
     */
    cCharFile(FILE* attached=INVALID_FILEP) 
    : cExtends(attached) 
    {
    }
};

/**
 **********************************************************************
 *  Typedef: cBYTEFileExtends
 *
 *  Author: $author$
 *    Date: 10/20/2008
 **********************************************************************
 */
typedef cFileT
  <BYTE,TSIZE,TLENGTH,UNDEFINED_LENGTH,
   cBYTEFileInterface,cBYTEFILEStream>
cBYTEFileExtends;
/**
 **********************************************************************
 *  Class: cBYTEFile
 *
 * Author: $author$
 *   Date: 10/20/2008
 **********************************************************************
 */
class cBYTEFile
: public cBYTEFileExtends
{
public:
    typedef cBYTEFileExtends cExtends;
    typedef cBYTEFile cDerives;
    /**
     **********************************************************************
     * Constructor: cBYTEFile
     *
     *      Author: $author$
     *        Date: 10/20/2008
     **********************************************************************
     */
    cBYTEFile
    (FILE* attached=INVALID_FILEP) 
    : cExtends(attached)
    {
    }
};
#endif /* _CFILE_HXX */
