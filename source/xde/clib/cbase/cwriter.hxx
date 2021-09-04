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
 *   File: cwriter.hxx
 *
 * Author: $author$
 *   Date: 3/18/2008
 **********************************************************************
 */
#ifndef _CWRITER_HXX
#define _CWRITER_HXX

#include "cwriterinterface.hxx"
#include "cbase.hxx"

#undef CDB_CLASS
#define CDB_CLASS "cWriterT"
/**
 **********************************************************************
 *  Class: cWriterT
 *
 * Author: $author$
 *   Date: 3/18/2008
 **********************************************************************
 */
template
<class TWhat=CHAR,
 class TSize=TSIZE,
 class TLength=TLENGTH,
 TLength VUndefinedLength=UNDEFINED_LENGTH,
 class TDelegates=cWriterInterface,
 class TImplements=cWriterImplement,
 class TExtends=cBase>
 
class cWriterT
: virtual public TImplements,
  public TExtends
{
public:
    typedef TImplements cImplements;
    typedef TExtends cExtends;
    typedef cWriterT cDerives;

    typedef TWhat tWhat;
    typedef TSize tSize;
    typedef TLength tLength;

    TDelegates* m_delegate;

    /**
     **********************************************************************
     * Constructor: cWriterT
     *
     *      Author: $author$
     *        Date: 3/18/2008
     **********************************************************************
     */
    cWriterT
    (TDelegates* delegate=0)
    : m_delegate(delegate)
    {
    }
    /**
     **********************************************************************
     * Destructor: cWriterT
     *
     *     Author: $author$
     *       Date: 3/18/2008
     **********************************************************************
     */
    virtual ~cWriterT()
    {
    }
    /**
     **********************************************************************
     * Function: Write
     *
     *   Author: $author$
     *     Date: 1/13/2007
     **********************************************************************
     */
    virtual TLength Write
    (const TWhat* what, TLength length = VUndefinedLength) 
    {
        TLength count = -e_ERROR_NOT_ATTACHED;
        if (m_delegate)
            count = m_delegate->Write(what, length);
        return count;
    }
    /**
     **********************************************************************
     * Function: SetDelegate
     *
     *   Author: $author$
     *     Date: 3/18/2008
     **********************************************************************
     */
    virtual TDelegates* SetDelegate
    (TDelegates* delegate) 
    {
        TDelegates* oldDelegate = m_delegate;
        m_delegate = delegate;
        return oldDelegate;
    }
    /**
     **********************************************************************
     * Function: GetDelegate
     *
     *   Author: $author$
     *     Date: 3/18/2008
     **********************************************************************
     */
    virtual TDelegates* GetDelegate() const 
    {
        return m_delegate;
    }
};
#undef CDB_CLASS

/**
 **********************************************************************
 *  Typedef: cWriter
 *
 *  Author: $author$
 *    Date: 3/18/2008
 **********************************************************************
 */
typedef cWriterT
<CHAR,TSIZE,TLENGTH,UNDEFINED_LENGTH,
 cWriterInterface,cWriterImplement,cBase>
cWriter;

/**
 **********************************************************************
 *  Typedef: cCharWriter
 *
 *  Author: $author$
 *    Date: 3/18/2008
 **********************************************************************
 */
typedef cWriterT
<char,TSIZE,TLENGTH,UNDEFINED_LENGTH,
 cCharWriterInterface,cCharWriterImplement,cBase>
cCharWriter;

/**
 **********************************************************************
 *  Typedef: cTCHARWriter
 *
 *  Author: $author$
 *    Date: 3/18/2008
 **********************************************************************
 */
typedef cWriterT
<TCHAR,TSIZE,TLENGTH,UNDEFINED_LENGTH,
 cTCHARWriterInterface,cTCHARWriterImplement,cBase>
cTCHARWriter;

/**
 **********************************************************************
 *  Typedef: cWCHARWriter
 *
 *  Author: $author$
 *    Date: 3/18/2008
 **********************************************************************
 */
typedef cWriterT
<WCHAR,TSIZE,TLENGTH,UNDEFINED_LENGTH,
 cWCHARWriterInterface,cWCHARWriterImplement,cBase>
cWCHARWriter;

/**
 **********************************************************************
 *  Typedef: cBYTEWriter
 *
 *  Author: $author$
 *    Date: 3/18/2008
 **********************************************************************
 */
typedef cWriterT
<BYTE,TSIZE,TLENGTH,UNDEFINED_LENGTH,
 cBYTEWriterInterface,cBYTEWriterImplement,cBase>
cBYTEWriter;

#endif /* _CWRITER_HXX */
