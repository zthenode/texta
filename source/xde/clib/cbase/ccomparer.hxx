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
 *   File: ccomparer.hxx
 *
 * Author: $author$
 *   Date: 3/19/2008
 **********************************************************************
 */
#ifndef _CCOMPARER_HXX
#define _CCOMPARER_HXX

#include "cinterfacebase.hxx"
#include "cbase.hxx"

#undef CDB_CLASS
#define CDB_CLASS "cComparerT"
/**
 **********************************************************************
 *  Class: cComparerT
 *
 * Author: $author$
 *   Date: 3/19/2008
 **********************************************************************
 */
template
<class TWhat=CHAR,
 class TLength=TLENGTH,
 TLength VUndefinedLength=UNDEFINED_LENGTH,
 class TNull=TWhat,
 TNull VNull=NULL_CHAR,
 class TImplements=cInterfaceBase,
 class TExtends=cBase>
 
class cComparerT
: virtual public TImplements,
  public TExtends
{
public:
    typedef TImplements cImplements;
    typedef TExtends cExtends;
    typedef cComparerT cDerives;
    /**
     **********************************************************************
     * Constructor: cComparerT
     *
     *      Author: $author$
     *        Date: 3/19/2008
     **********************************************************************
     */
    cComparerT() 
    {
    }
    /**
     **********************************************************************
     * Destructor: cComparerT
     *
     *     Author: $author$
     *       Date: 3/19/2008
     **********************************************************************
     */
    virtual ~cComparerT()
    {
    }
    /**
     **********************************************************************
     * Function: Compare
     *
     *   Author: $author$
     *     Date: 3/19/2008
     **********************************************************************
     */
    virtual int Compare
    (const TWhat* what,
     TLength length,
     const TWhat* toWhat,
     TLength toLength) const
    {
        int unequal = -e_ERROR_FAILED-1;

        if (what == toWhat)
            unequal = 0;
        else
        if (what)
        {
            if (toWhat)
            {
                if (0 > length)
                    length = LengthOf(what);

                if (0 > toLength)
                    toLength = LengthOf(toWhat);

                if (length > toLength)
                {
                    unequal = 1;
                    length = toLength;
                }
                else
                if (toLength > length)
                    unequal = -1;
                else
                unequal = 0;

                for (; 0 < length; --length, what++, toWhat++)
                {
                    if (*what > *toWhat)
                        return 1;
                    else
                    if (*what < *toWhat)
                        return -1;
                }
            }
            else
            unequal = 1;
        }
        else
        unequal = -1;
        return unequal;
    }
    /**
     **********************************************************************
     * Function: LengthOf
     *
     *   Author: $author$
     *     Date: 3/19/2008
     **********************************************************************
     */
    virtual TLength LengthOf
    (const TWhat* what) const
    {
        TLength count = 0;
        if (what)
        while ((*what++) != VNull)
            count++;
        return count;
    }
};
#undef CDB_CLASS

/**
 **********************************************************************
 *  Typedef: cComparer
 *
 *  Author: $author$
 *    Date: 4/2/2008
 **********************************************************************
 */
typedef cComparerT
<CHAR,TLENGTH,UNDEFINED_LENGTH,
 CHAR,NULL_CHAR,cInterfaceBase,cBase>
cComparer;

/**
 **********************************************************************
 *  Typedef: cCharComparer
 *
 *  Author: $author$
 *    Date: 4/2/2008
 **********************************************************************
 */
typedef cComparerT
<char,TLENGTH,UNDEFINED_LENGTH,
 char,0,cInterfaceBase,cBase>
cCharComparer;

/**
 **********************************************************************
 *  Typedef: cTCHARComparer
 *
 *  Author: $author$
 *    Date: 4/2/2008
 **********************************************************************
 */
typedef cComparerT
<TCHAR,TLENGTH,UNDEFINED_LENGTH,
 TCHAR,NULL_TCHAR,cInterfaceBase,cBase>
cTCHARComparer;

/**
 **********************************************************************
 *  Typedef: cComparer
 *
 *  Author: $author$
 *    Date: 4/2/2008
 **********************************************************************
 */
typedef cComparerT
<WCHAR,TLENGTH,UNDEFINED_LENGTH,
 WCHAR,NULL_WCHAR,cInterfaceBase,cBase>
cWCHARComparer;

#endif /* _CCOMPARER_HXX */
