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
 *   File: cchar.hxx
 *
 * Author: $author$
 *   Date: 11/3/2008
 **********************************************************************
 */
#ifndef _CCHAR_HXX
#define _CCHAR_HXX

#include "ccharinterface.hxx"
#include "cbase.hxx"

#undef CDB_CLASS
#define CDB_CLASS "cCharT"
/**
 **********************************************************************
 *  Class: cCharT
 *
 * Author: $author$
 *   Date: 11/3/2008
 **********************************************************************
 */
template
<class TChar=WCHAR,
 class TImplements=cCharImplement,
 class TExtends=cBase>
 
class cCharT
: virtual public TImplements,
  public TExtends
{
public:
    typedef TImplements cImplements;
    typedef TExtends cExtends;
    typedef cCharT cDerives;

    TChar m_char;

    /**
     **********************************************************************
     * Constructor: cCharT
     *
     *      Author: $author$
     *        Date: 11/3/2008
     **********************************************************************
     */
    cCharT(WCHAR c=0) 
    : m_char((TChar)(c))
    {
    }
    /**
     **********************************************************************
     * Constructor: cCharT
     *
     *      Author: $author$
     *        Date: 11/3/2008
     **********************************************************************
     */
    cCharT(char c) 
    : m_char((TChar)c)
    {
    }
    /**
     **********************************************************************
     * Constructor: cCharT
     *
     *      Author: $author$
     *        Date: 11/13/2008
     **********************************************************************
     */
    cCharT(TSIZE value) 
    : m_char((TChar)value)
    {
    }
    /**
     **********************************************************************
     * Constructor: cCharT
     *
     *      Author: $author$
     *        Date: 11/13/2008
     **********************************************************************
     */
    cCharT(TLENGTH value) 
    : m_char((TChar)value)
    {
    }

    /**
     **********************************************************************
     * Function: SetCHAR
     *
     *   Author: $author$
     *     Date: 11/3/2008
     **********************************************************************
     */
    virtual TLENGTH SetCHAR
    (CHAR c) 
    {
        TLENGTH count = 1;
        m_char = (TChar)(c);
        return count;
    }
    /**
     **********************************************************************
     * Function: GetCHAR
     *
     *   Author: $author$
     *     Date: 11/3/2008
     **********************************************************************
     */
    virtual CHAR GetCHAR() const 
    {
        CHAR c = (CHAR)(m_char);
        return c;
    }

    /**
     **********************************************************************
     * Function: SetTCHAR
     *
     *   Author: $author$
     *     Date: 11/3/2008
     **********************************************************************
     */
    virtual TLENGTH SetTCHAR
    (TCHAR c) 
    {
        TLENGTH count = 1;
        m_char = (TChar)(c);
        return count;
    }
    /**
     **********************************************************************
     * Function: GetTCHAR
     *
     *   Author: $author$
     *     Date: 11/3/2008
     **********************************************************************
     */
    virtual TCHAR GetTCHAR() const 
    {
        TCHAR c = (TCHAR)(m_char);
        return c;
    }

    /**
     **********************************************************************
     * Function: SetWCHAR
     *
     *   Author: $author$
     *     Date: 11/3/2008
     **********************************************************************
     */
    virtual TLENGTH SetWCHAR
    (WCHAR c) 
    {
        TLENGTH count = 1;
        m_char = (TChar)(c);
        return count;
    }
    /**
     **********************************************************************
     * Function: GetWCHAR
     *
     *   Author: $author$
     *     Date: 11/3/2008
     **********************************************************************
     */
    virtual WCHAR GetWCHAR() const 
    {
        WCHAR c = (WCHAR)(m_char);
        return c;
    }

    /**
     **********************************************************************
     * Function: operator !
     *
     *   Author: $author$
     *     Date: 11/12/2008
     **********************************************************************
     */
    virtual bool operator ! () const
    {
        bool value = !m_char;
        return value;
    }
    /**
     **********************************************************************
     * Function: operator !=
     *
     *   Author: $author$
     *     Date: 11/12/2008
     **********************************************************************
     */
    virtual bool operator != (cDerives c) const
    {
        bool value = m_char != c.m_char;
        return value;
    }
    /**
     **********************************************************************
     * Function: operator !=
     *
     *   Author: $author$
     *     Date: 11/12/2008
     **********************************************************************
     */
    virtual bool operator != (char c) const
    {
        bool value = m_char != c;
        return value;
    }
    /**
     **********************************************************************
     * Function: operator !=
     *
     *   Author: $author$
     *     Date: 11/12/2008
     **********************************************************************
     */
    virtual bool operator != (int value) const
    {
        bool rvalue = m_char != value;
        return rvalue;
    }
    /**
     **********************************************************************
     * Function: operator <=
     *
     *   Author: $author$
     *     Date: 11/12/2008
     **********************************************************************
     */
    virtual bool operator <= (cDerives c) const
    {
        bool value = m_char <= c.m_char;
        return value;
    }
    /**
     **********************************************************************
     * Function: operator >=
     *
     *   Author: $author$
     *     Date: 11/12/2008
     **********************************************************************
     */
    virtual bool operator >= (cDerives c) const
    {
        bool value = m_char >= c.m_char;
        return value;
    }
    /**
     **********************************************************************
     * Function: operator ==
     *
     *   Author: $author$
     *     Date: 11/12/2008
     **********************************************************************
     */
    virtual bool operator == (cDerives c) const
    {
        bool value = m_char == c.m_char;
        return value;
    }
    /**
     **********************************************************************
     * Function: operator <
     *
     *   Author: $author$
     *     Date: 11/12/2008
     **********************************************************************
     */
    virtual bool operator < (cDerives c) const
    {
        bool value = m_char < c.m_char;
        return value;
    }
    /**
     **********************************************************************
     * Function: operator >
     *
     *   Author: $author$
     *     Date: 11/12/2008
     **********************************************************************
     */
    virtual bool operator > (cDerives c) const
    {
        bool value = m_char > c.m_char;
        return value;
    }

    /**
     **********************************************************************
     * Function: operator +
     *
     *   Author: $author$
     *     Date: 11/12/2008
     **********************************************************************
     */
    virtual cDerives operator + (cDerives c) const
    {
        c.m_char = m_char + c.m_char;
        return c;
    }
    /**
     **********************************************************************
     * Function: operator +
     *
     *   Author: $author$
     *     Date: 11/12/2008
     **********************************************************************
     */
    virtual cDerives operator + (long value) const
    {
        cDerives c((TChar)(m_char + value));
        return c;
    }
    /**
     **********************************************************************
     * Function: operator +
     *
     *   Author: $author$
     *     Date: 11/12/2008
     **********************************************************************
     */
    virtual cDerives operator + (int value) const
    {
        cDerives c((TChar)(m_char + value));
        return c;
    }

    /**
     **********************************************************************
     * Function: operator -
     *
     *   Author: $author$
     *     Date: 11/12/2008
     **********************************************************************
     */
    virtual TLENGTH operator - (cDerives c) const
    {
        TLENGTH value = (TLENGTH)(m_char) - (TLENGTH)(c);
        return value;
    }

    /**
     **********************************************************************
     * Function: operator TLENGTH
     *
     *   Author: $author$
     *     Date: 11/12/2008
     **********************************************************************
     */
    virtual operator TLENGTH() const
    {
        TLENGTH value = (TLENGTH)(m_char);
        return value;
    }
    /**
     **********************************************************************
     * Function: operator TSIZE
     *
     *   Author: $author$
     *     Date: 11/12/2008
     **********************************************************************
     */
    virtual operator TSIZE() const
    {
        TSIZE value = (TSIZE)(m_char);
        return value;
    }
};
#undef CDB_CLASS

/**
 **********************************************************************
 * Typedef: cChar
 *
 *  Author: $author$
 *    Date: 11/3/2008
 **********************************************************************
 */
typedef cCharT<>
cChar;

#endif /* _CCHAR_HXX */
