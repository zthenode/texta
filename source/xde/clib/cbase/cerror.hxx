/**
 **********************************************************************
 * Copyright (c) 1988-2007 $organization$
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
 *   File: cerror.hxx
 *
 * Author: $author$
 *   Date: 1/13/2007
 *
 *    $Id$
 **********************************************************************
 */

#ifndef _CERROR_HXX
#define _CERROR_HXX

#include "cerror.h"
#include "cstring.hxx"
#include "cbase.hxx"

/**
 **********************************************************************
 *  Class: cErrorT
 *
 * Author: $author$
 *   Date: 8/25/2003
 **********************************************************************
 */
template 
<class TChar=CHAR,
 class TSize=TSIZE,
 class TLength=TLENGTH,
 class TString=cString,
 class TExtends=cBase>

class cErrorT
: public TExtends
{
public:
    typedef TExtends cIs;

    eError m_error;
    TString m_errorDescription;

    /**
     **********************************************************************
     * Constructor: cErrorT
     *
     *      Author: $author$
     *        Date: 8/25/2003
     **********************************************************************
     */
    cErrorT
    (eError error=e_ERROR_NONE, 
     const TChar* description=0,
     TLength descriptionLength=-1)
    : m_error(error) 
    {
        TLength length;

        if (description)
        if (0 > (length = m_errorDescription.Assign
            (description, descriptionLength)))
            throw(error = -length);
    }

    /**
     **********************************************************************
     * Function: SetLastError
     *
     *   Author: $author$
     *     Date: 7/16/2003
     **********************************************************************
     */
    virtual eError SetLastError
    (eError error, const TChar* description=0,
     TLength descriptionLength=-1)
    {
        TLength length;

        if (description)
        {
            if (0 > (length = m_errorDescription.Assign
                (description, descriptionLength)))
                return -error;
        }
        else if (0 < (length = m_errorDescription.Length()))
        {
            if (0 > (length = m_errorDescription.Clear()))
                return -error;
        }
        return m_error = error;
    }
    /**
     **********************************************************************
     * Function: GetLastError
     *
     *   Author: $author$
     *     Date: 7/16/2003
     **********************************************************************
     */
    virtual eError GetLastError
    (const TChar*& description) const
    {
        static TChar nullChar = 0;
        eError error;
        TLength length;
        const TChar* errorDescription;

        description = &nullChar;

        if ((error = m_error))
        if ((errorDescription = m_errorDescription.Chars(length)))
            description = errorDescription;
        return error;
    }
};

/**
 **********************************************************************
 *  Class: cError
 *
 * Author: $author$
 *   Date: 5/1/2008
 **********************************************************************
 */
class cError
: public cErrorT<char,TSIZE,TLENGTH,cCharString>
{
public:
    typedef cErrorT<char,TSIZE,TLENGTH,cCharString> cExtends;
};

/**
 **********************************************************************
 *  Class: cTError
 *
 * Author: $author$
 *   Date: 5/1/2008
 **********************************************************************
 */
class cTError
: public cErrorT<TCHAR,TSIZE,TLENGTH,cTCHARString>
{
public:
    typedef cErrorT<TCHAR,TSIZE,TLENGTH,cTCHARString> cExtends;
};

/**
 **********************************************************************
 *  Class: cWError
 *
 * Author: $author$
 *   Date: 5/1/2008
 **********************************************************************
 */
class cWError
: public cErrorT<WCHAR,TSIZE,TLENGTH,cWCHARString>
{
public:
    typedef cErrorT<WCHAR,TSIZE,TLENGTH,cWCHARString> cExtends;
};

#endif /* _CERROR_HXX */
