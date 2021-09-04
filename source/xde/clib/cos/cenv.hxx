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
 *   File: cenv.hxx
 *
 * Author: $author$
 *   Date: 9/8/2008
 **********************************************************************
 */
#ifndef _CENV_HXX
#define _CENV_HXX

#include "cplatform_env.h"
#include "cstring.hxx"

#undef CDB_CLASS
#define CDB_CLASS "cEnvT"
/**
 **********************************************************************
 *  Class: cEnvT
 *
 * Author: $author$
 *   Date: 9/8/2008
 **********************************************************************
 */
template
<class TChar=CHAR, 
 class TSize=TSIZE,
 class TLength=TLENGTH,
 TLength VUndefinedLength=UNDEFINED_LENGTH,
 TChar VNullChar=NULL_CHAR,
 class TExtends=cString>
 
class cEnvT
: public TExtends
{
public:
    typedef TExtends cExtends;
    typedef cEnvT cDerives;

    TExtends m_name;

    /**
     **********************************************************************
     * Constructor: cEnvT
     *
     *      Author: $author$
     *        Date: 9/8/2008
     **********************************************************************
     */
    cEnvT
    (const TChar* nameChars=0,
     TLength nameLength=VUndefinedLength) 
    {
    }
    /**
     **********************************************************************
     * Function: Set
     *
     *   Author: $author$
     *     Date: 9/8/2008
     **********************************************************************
     */
    virtual TLength Set
    (const TChar* nameChars,
     TLength nameLength=VUndefinedLength) 
    {
        TLength length = 0;
        return length;
    }
    /**
     **********************************************************************
     * Function: Get
     *
     *   Author: $author$
     *     Date: 9/8/2008
     **********************************************************************
     */
    virtual const TChar* Get
    (TLength& length,
     const TChar* nameChars,
     TLength nameLength=VUndefinedLength) 
    {
        const TChar* chars = 0;

        length = 0;

        if (0 > (nameLength = m_name.Assign(nameChars, nameLength)))
        {
            length = nameLength;
            return chars;
        }
        if ((nameChars = m_name.HasChars(nameLength)))
        if ((nameChars = getenv(nameChars)))
        if (0 > (nameLength = Assign(nameChars)))
        {
            length = nameLength;
            return chars;
        }
        else
        chars = HasChars(length);
        return chars;
    }
};
#undef CDB_CLASS

/**
 **********************************************************************
 *  Typedef: cEnv
 *
 *  Author: $author$
 *    Date: 9/9/2008
 **********************************************************************
 */
typedef cEnvT<>
cEnv;

#endif /* _CENV_HXX */
