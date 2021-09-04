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
 *   File: creader.hxx
 *
 * Author: $author$
 *   Date: 3/18/2008
 **********************************************************************
 */
#ifndef _CREADER_HXX
#define _CREADER_HXX

#include "creaderinterface.hxx"
#include "cbase.hxx"

#undef CDB_CLASS
#define CDB_CLASS "cReaderT"
/**
 **********************************************************************
 *  Class: cReaderT
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
 class TDeligates=cReaderInterface,
 class TImplements=cReaderImplement,
 class TExtends=cBase>
 
class cReaderT
: virtual public TImplements,
  public TExtends
{
public:
    typedef TImplements cImplements;
    typedef TExtends cExtends;
    typedef cReaderT cDerives;
    /**
     **********************************************************************
     * Constructor: cReaderT
     *
     *      Author: $author$
     *        Date: 3/18/2008
     **********************************************************************
     */
    cReaderT() 
    {
    }
    /**
     **********************************************************************
     * Destructor: cReaderT
     *
     *     Author: $author$
     *       Date: 3/18/2008
     **********************************************************************
     */
    virtual ~cReaderT()
    {
    }
    /**
     **********************************************************************
     * Function: Read
     *
     *   Author: $author$
     *     Date: 1/10/2007
     **********************************************************************
     */
    virtual TLength Read
    (TWhat* what, TSize size) 
    {
        TLength length = -e_ERROR_NOT_ATTACHED;
        if (this->m_deligate)
            length = this->m_deligate->Read(what, size);
        return length;
    }
    /**
     **********************************************************************
     * Function: SetDeligate
     *
     *   Author: $author$
     *     Date: 3/18/2008
     **********************************************************************
     */
    virtual TDeligates* SetDeligate
    (TDeligates* deligate) 
    {
        TDeligates* oldDeligate = this->m_deligate;
        this->m_deligate = deligate;
        return oldDeligate;
    }
    /**
     **********************************************************************
     * Function: GetDeligate
     *
     *   Author: $author$
     *     Date: 3/18/2008
     **********************************************************************
     */
    virtual TDeligates* GetDeligate() const 
    {
        return this->m_deligate;
    }
};
#undef CDB_CLASS

/**
 **********************************************************************
 *  Typedef: cReader
 *
 *  Author: $author$
 *    Date: 3/18/2008
 **********************************************************************
 */
typedef cReaderT
<CHAR,TSIZE,TLENGTH,UNDEFINED_LENGTH,
 cReaderInterface,cReaderImplement,cBase>
cReader;

/**
 **********************************************************************
 *  Typedef: cCharReader
 *
 *  Author: $author$
 *    Date: 3/18/2008
 **********************************************************************
 */
typedef cReaderT
<char,TSIZE,TLENGTH,UNDEFINED_LENGTH,
 cCharReaderInterface,cCharReaderImplement,cBase>
cCharReader;

/**
 **********************************************************************
 *  Typedef: cTCHARReader
 *
 *  Author: $author$
 *    Date: 4/20/2008
 **********************************************************************
 */
typedef cReaderT
<TCHAR,TSIZE,TLENGTH,UNDEFINED_LENGTH,
 cTCHARReaderInterface,cTCHARReaderImplement,cBase>
cTCHARReader;

/**
 **********************************************************************
 *  Typedef: cWCHARReader
 *
 *  Author: $author$
 *    Date: 4/20/2008
 **********************************************************************
 */
typedef cReaderT
<WCHAR,TSIZE,TLENGTH,UNDEFINED_LENGTH,
 cWCHARReaderInterface,cWCHARReaderImplement,cBase>
cWCHARReader;

#endif /* _CREADER_HXX */
