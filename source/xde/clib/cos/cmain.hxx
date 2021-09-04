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
 *   File: cmain.hxx
 *
 * Author: $author$
 *   Date: 2/13/2007
 *
 *    $Id$
 **********************************************************************
 */

#ifndef _CMAIN_HXX
#define _CMAIN_HXX

#include "cmaininterface.hxx"
#include "cfile.hxx"
#include "cbase.hxx"

/**
 **********************************************************************
 *  Class: cMainT
 *
 * Author: $author$
 *   Date: 2/13/2007
 **********************************************************************
 */
template
<class TChar=CHAR,
 class TSize=TSIZE,
 class TLength=TLENGTH,
 class TFile=cFile,
 class TString=cString,
 class TStream=cStreamInterface,
 class TMain=cMainInterface,
 class TImplements=cMainImplement,
 class TExtends=cBase>

class cMainT
: virtual public TImplements,
  public TExtends
{
public:
    typedef TImplements cImplements;
    typedef TExtends cExtends;

    typedef TChar tChar;
    typedef TSize tSize;
    typedef TLength tLength;
    typedef TFile tFile;
    typedef TString tString;
    typedef TStream tStream;

    static TMain* m_theMain;
    TMain* m_oldMain;

    bool m_didMainArg;
    bool m_didUsage;

    TFile m_stdIn;
    TFile m_stdOut;
    TFile m_stdErr;

    TStream* m_in;
    TStream* m_out;
    TStream* m_err;

    /**
     **********************************************************************
     * Constructor: cMainT
     *
     *      Author: $author$
     *        Date: 3/15/2007
     **********************************************************************
     */
    cMainT() 
    : m_oldMain(m_theMain),
      m_didMainArg(false),
      m_didUsage(false),
      m_in(&m_stdIn),
      m_out(&m_stdOut),
      m_err(&m_stdErr)
    {
        m_theMain = (TMain*)(this);
    }
    /**
     **********************************************************************
     *  Destructor: ~cMainT
     *
     *      Author: $author$
     *        Date: 3/15/2007
     **********************************************************************
     */
    virtual ~cMainT()
    {
        if ((TMain*)(this) == m_theMain)
            m_theMain = m_oldMain;
    }
    /**
     **********************************************************************
     * Function: Main
     *
     *   Author: $author$
     *     Date: 3/7/2008
     **********************************************************************
     */
    virtual int Main
    (int argc, const TChar** argv, const TChar** env) 
    {
        int err = 1;
        eError error;
        if (!(error = StdAttach()))
        {
            err = this->Run(argc, argv, env);
            StdDetach();
        }
        return err;
    }
    /**
     **********************************************************************
     * Function: StdAttach
     *
     *   Author: $author$
     *     Date: 3/7/2008
     **********************************************************************
     */
    virtual eError StdAttach() 
    {
        eError error;
        FILE* file;
        if (!(error = m_stdIn.Attach(stdin)))
        {
            if (!(error = m_stdOut.Attach(stdout)))
            {
                if (!(error = m_stdErr.Attach(stderr)))
                    return error;
                m_stdOut.Detach(file);
            }
            m_stdIn.Detach(file);
        }
        return error;
    }
    /**
     **********************************************************************
     * Function: StdDetach
     *
     *   Author: $author$
     *     Date: 3/7/2008
     **********************************************************************
     */
    virtual eError StdDetach() 
    {
        eError error;
        eError error2;
        FILE* file;
        error = m_stdErr.Detach(file);
        if ((error2 = m_stdOut.Detach(file)) && !error)
            error = error2;
        if ((error2 = m_stdIn.Detach(file)) && !error)
            error = error2;
        return error;
    }
    /**
     **********************************************************************
     * Function: Err
     *
     *   Author: $author$
     *     Date: 3/6/2008
     **********************************************************************
     */
    virtual TLength Err
    (const TChar* chars, TLength length=-1) 
    {
        TLength count = 0;
        if (m_err)
            count = m_err->Write(chars, length);
        return count;
    }
    /**
     **********************************************************************
     * Function: Out
     *
     *   Author: $author$
     *     Date: 3/6/2008
     **********************************************************************
     */
    virtual TLength Out
    (const TChar* chars, TLength length=-1) 
    {
        TLength count = 0;
        if (m_out)
            count = m_out->Write(chars, length);
        return count;
    }
    /**
     **********************************************************************
     * Function: In
     *
     *   Author: $author$
     *     Date: 3/6/2008
     **********************************************************************
     */
    virtual TLength In
    (TChar* chars, TSize size) 
    {
        TLength count = 0;
        if (m_in)
            count = m_in->Read(chars, size);
        return count;
    }
    /**
     **********************************************************************
     * Function: SetDidUsage
     *
     *   Author: $author$
     *     Date: 3/17/2007
     **********************************************************************
     */
    virtual eError SetDidUsage(bool did=true) 
    {
        eError error = e_ERROR_NONE;
        m_didUsage = did;
        return error;
    }
    /**
     **********************************************************************
     * Function: GetDidUsage
     *
     *   Author: $author$
     *     Date: 3/17/2007
     **********************************************************************
     */
    virtual bool GetDidUsage() const 
    {
        return m_didUsage;
    }
    /**
     **********************************************************************
     * Function: SetDidMainArg
     *
     *   Author: $author$
     *     Date: 3/15/2007
     **********************************************************************
     */
    virtual eError SetDidMainArg(bool did=true) 
    {
        eError error = e_ERROR_NONE;
        m_didMainArg = did;
        return error;
    }
    /**
     **********************************************************************
     * Function: GetDidMainArg
     *
     *   Author: $author$
     *     Date: 3/15/2007
     **********************************************************************
     */
    virtual bool GetDidMainArg() const 
    {
        return m_didMainArg;
    }
};

/**
 **********************************************************************
 * Typedef: cMainExtends
 *
 *  Author: $author$
 *    Date: 12/31/2008
 **********************************************************************
 */
typedef cMainT
<char, TSIZE, TLENGTH, 
 cCharFile, cCharString, cCharStreamInterface,
 cMainInterface, cMainImplement, cBase>
cMainExtends;

/**
 **********************************************************************
 *  Class: cMain
 *
 * Author: $author$
 *   Date: 2/13/2007
 **********************************************************************
 */
class cMain
: public cMainExtends
{
public:
    typedef cMainExtends cExtends;
    typedef cMain cDerives;
};

#endif /* _CMAIN_HXX */
