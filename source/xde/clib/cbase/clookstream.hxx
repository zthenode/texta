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
 *   File: clookstream.hxx
 *
 * Author: $author$
 *   Date: 3/1/2008
 **********************************************************************
 */
#ifndef _CLOOKSTREAM_HXX
#define _CLOOKSTREAM_HXX

#include "cstream.hxx"
#include "cstring.hxx"

#undef CDB_CLASS
#define CDB_CLASS "cLookStreamT"
/**
 **********************************************************************
 *  Class: cLookStreamT
 *
 * Author: $author$
 *   Date: 3/1/2008
 **********************************************************************
 */
template
<class TWhat=CHAR,
 class TSize=TSIZE,
 class TLength=TLENGTH,
 TLength VUndefined=UNDEFINED_LENGTH,
 class TString=cString,
 class TExtends=cStream>
 
class cLookStreamT
: public TExtends
{
public:
    typedef TExtends cExtends;
    typedef cLookStreamT cDerives;

    TString m_look;
    TLength m_lookTell;
    TLength m_lookLength;
    const TWhat* m_lookChars;

    /**
     **********************************************************************
     * Constructor: cLookStreamT
     *
     *      Author: $author$
     *        Date: 3/1/2008
     **********************************************************************
     */
    cLookStreamT() 
    : m_lookTell(0),
      m_lookLength(0),
      m_lookChars(0)
    {
    }
    /**
     **********************************************************************
     * Function: Look
     *
     *   Author: $author$
     *     Date: 3/1/2008
     **********************************************************************
     */
    virtual TLength Look
    (TWhat* what, TSize size) 
    {
        TLength length = -e_ERROR_NOT_IMPLEMENTED;
        TLength tell = m_lookTell;
        TLength count = m_lookLength;
        const TWhat* chars = m_lookChars;

        m_lookChars = 0;
        m_lookLength = 0;
        m_lookTell = 0;

        if (0 < (length = CTHIS Read(what, size)))
        {
            if (length <= (count = m_look.Append(what, length)))
            if ((chars = m_look.HasChars(count)))
            {
                m_lookChars = chars;
                m_lookLength = count;
                m_lookTell = tell;
                return length;
            }
            m_look.Clear();
        }
        else
        {
            m_lookChars = chars;
            m_lookLength = count;
            m_lookTell = tell;
        }
        return length;
    }
    /**
     **********************************************************************
     * Function: See
     *
     *   Author: $author$
     *     Date: 3/2/2008
     **********************************************************************
     */
    virtual const TWhat* See
    (TLength& length) const 
    {
        const TWhat* what = 0;
        if (m_lookChars)
        {
            what = m_lookChars + m_lookTell;
            length = m_lookLength - m_lookTell;
        }
        else length = 0;
        return what;
    }
};
#undef CDB_CLASS

/**
 **********************************************************************
 *  Typedef: cLookStream
 *
 *  Author: $author$
 *    Date: 3/1/2008
 **********************************************************************
 */
typedef cLookStreamT
<CHAR,TSIZE,TLENGTH,UNDEFINED_LENGTH,
 cString,cStream>
cLookStream;

/**
 **********************************************************************
 *  Typedef: cCharLookStream
 *
 *  Author: $author$
 *    Date: 3/1/2008
 **********************************************************************
 */
typedef cLookStreamT
<char,TSIZE,TLENGTH,UNDEFINED_LENGTH,
 cCharString,cCharStream>
cCharLookStream;

/**
 **********************************************************************
 *  Typedef: cBYTELookStream
 *
 *  Author: $author$
 *    Date: 3/1/2008
 **********************************************************************
 */
typedef cLookStreamT
<BYTE,TSIZE,TLENGTH,UNDEFINED_LENGTH,
 cBYTEString,cBYTEStream>
cBYTELookStream;

/**
 **********************************************************************
 *  Typedef: cTCHARLookStream
 *
 *  Author: $author$
 *    Date: 3/1/2008
 **********************************************************************
 */
typedef cLookStreamT
<TCHAR,TSIZE,TLENGTH,UNDEFINED_LENGTH,
 cTCHARString,cTCHARStream>
cTCHARLookStream;

/**
 **********************************************************************
 *  Typedef: cWCHARLookStream
 *
 *  Author: $author$
 *    Date: 3/1/2008
 **********************************************************************
 */
typedef cLookStreamT
<WCHAR,TSIZE,TLENGTH,UNDEFINED_LENGTH,
 cWCHARString,cWCHARStream>
cWCHARLookStream;

#endif /* _CLOOKSTREAM_HXX */
