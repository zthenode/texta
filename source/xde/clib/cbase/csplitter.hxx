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
 *   File: csplitter.hxx
 *
 * Author: $author$
 *   Date: 3/21/2008
 **********************************************************************
 */
#ifndef _CSPLITTER_HXX
#define _CSPLITTER_HXX

#include "ccounter.hxx"
#include "cbase.hxx"

#undef CDB_CLASS
#define CDB_CLASS "cSplitterT"
/**
 **********************************************************************
 *  Class: cSplitterT
 *
 * Author: $author$
 *   Date: 3/21/2008
 **********************************************************************
 */
template
<class TChar=CHAR,
 class TLength=TLENGTH,
 class TExtends=cCounter>
 
class cSplitterT
: public TExtends
{
public:
    typedef TExtends cExtends;
    typedef cSplitterT cDerives;
    /**
     **********************************************************************
     * Function: LeftOf
     *
     *   Author: $author$
     *     Date: 1/1/2009
     **********************************************************************
     */
    virtual const TChar* LeftOf
    (TLength& count, TChar c, 
     const TChar* chars, TLength length=-1) const 
    {
        const TChar* found = 0;
        TLength tell;

        count = 0;

        if (0 > length)
        if (0 >= (length = this->LengthOf(chars)))
            return found;

        for (tell=0; tell<length; tell++)
        {
            if (c != chars[tell])
                continue;
            found = chars;
            count = tell;
            break;
        }
        return found;
    }
    /**
     **********************************************************************
     * Function: RightOf
     *
     *   Author: $author$
     *     Date: 3/7/2008
     **********************************************************************
     */
    virtual const TChar* RightOf
    (TLength& count, TChar c, 
     const TChar* chars, TLength length=-1) const
    {
        const TChar* found = 0;
        TLength tell;

        count = 0;

        if (0 > length)
        if (0 >= (length = this->LengthOf(chars)))
            return found;

        for (tell=length; 0<tell; --tell)
        {
            if (c != chars[tell-1])
                continue;
            found = chars+tell;
            count = length-tell;
            break;
        }
        return found;
    }
};
#undef CDB_CLASS

/**
 **********************************************************************
 *  Typedef: cSplitter
 *
 *  Author: $author$
 *    Date: 3/27/2008
 **********************************************************************
 */
typedef cSplitterT
<CHAR,TLENGTH,cCounter>
cSplitter;

/**
 **********************************************************************
 *  Typedef: cCharSplitter
 *
 *  Author: $author$
 *    Date: 3/27/2008
 **********************************************************************
 */
typedef cSplitterT
<char,TLENGTH,cCharCounter>
cCharSplitter;

#endif /* _CSPLITTER_HXX */
