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
 *   File: cvector.hxx
 *
 * Author: $author$
 *   Date: 3/13/2008
 **********************************************************************
 */
#ifndef _CVECTOR_HXX
#define _CVECTOR_HXX

#include <vector>
#include "cvectorinterface.hxx"
#include "cbase.hxx"

/**
 **********************************************************************
 * Typedef: cVectorExtends
 *
 *  Author: $author$
 *    Date: 3/13/2008
 **********************************************************************
 */
typedef std::vector<CHAR>
cVectorExtends;

#undef CDB_CLASS
#define CDB_CLASS "cVectorT"
/**
 **********************************************************************
 *  Class: cVectorT
 *
 * Author: $author$
 *   Date: 3/13/2008
 **********************************************************************
 */
template
<class TWhat=CHAR, 
 class TSize=TSIZE,
 class TLength=TLENGTH,
 TLength VUndefinedLength=UNDEFINED_LENGTH,
 class TImplements=cVectorInterface,
 class TExtends=cVectorExtends>
 
class cVectorT
: virtual public TImplements,
  public TExtends
{
public:
    typedef TImplements cImplements;
    typedef TExtends cExtends;
    typedef cVectorT cDerives;
    /**
     **********************************************************************
     * Constructor: cVectorT
     *
     *      Author: $author$
     *        Date: 3/13/2008
     **********************************************************************
     */
    cVectorT() 
    {
    }
    /**
     **********************************************************************
     * Destructor: cVectorT
     *
     *     Author: $author$
     *       Date: 3/13/2008
     **********************************************************************
     */
    virtual ~cVectorT()
    {
    }
    /**
     **********************************************************************
     * Function: Append
     *
     *   Author: $author$
     *     Date: 3/17/2008
     **********************************************************************
     */
    virtual TLength Append
    (const TWhat* what, TSize size) 
    {
        TLength count = 0;
        TLength length;
        if (what)
        if (0 <= (length = (TLength)(size)))
        for (count = 0; count < length; count++)
            CTHIS push_back(what[count]);
        return count;
    }
};
#undef CDB_CLASS

#endif /* _CVECTOR_HXX */
