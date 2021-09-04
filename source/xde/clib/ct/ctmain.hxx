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
 *   File: ctmain.hxx
 *
 * Author: $author$
 *   Date: 12/29/2008
 **********************************************************************
 */
#ifndef _CTMAIN_HXX
#define _CTMAIN_HXX

#include "cargmain.hxx"
#include "ct.hxx"

#define DEFAULT_T_INPUT_VARIABLE_NAME "input"
#define DEFAULT_T_OUTPUT_VARIABLE_NAME "output"

/**
 **********************************************************************
 *  Class: cTMain
 *
 * Author: $author$
 *   Date: 12/29/2008
 **********************************************************************
 */
class cTMain
: public cArgMain
{
public:
    typedef cArgMain cExtends;
    typedef cTMain cDerives;

    const tChar* m_inputVariableNameChars;
    const tChar* m_outputVariableNameChars;

    tString m_inFileName;
    tString m_outFileName;

    tFile m_inFile;
    tFile m_outFile;

    cT m_t;

    /**
     **********************************************************************
     * Constructor: cTMain
     *
     *      Author: $author$
     *        Date: 12/29/2008
     **********************************************************************
     */
    cTMain() 
    : m_inputVariableNameChars(DEFAULT_T_INPUT_VARIABLE_NAME),
      m_outputVariableNameChars(DEFAULT_T_OUTPUT_VARIABLE_NAME)
    {
    }
    /**
     **********************************************************************
     * Function: Main
     *
     *   Author: $author$
     *     Date: 1/1/2009
     **********************************************************************
     */
    virtual int Main
    (int argc, const tChar** argv, const tChar** env) 
    {
        int err = 1;
        eError error;

        if ((error = m_t.Initialize()))
            DBE("() failed on m_t.Initialize()\n");
        else
        {
            try {
                err = cExtends::Main(argc, argv, env);
            } catch (const cTException& e) {
                DBT("()...caught const cTException& e(%d)\n", e.Error());
            }

            if ((error = m_t.Finalize()))
                DBE("() failed on m_t.Finalize()\n");
        }
        return err;
    }
    /**
     **********************************************************************
     * Function: Run
     *
     *   Author: $author$
     *     Date: 12/29/2008
     **********************************************************************
     */
    virtual int Run
    (int argc, const tChar** argv, const tChar** env) 
    {
        int err = 0;
        cCharStreamInterface* in = &m_stdIn;
        cCharStreamInterface* out = &m_stdOut;
        const tChar* chars;
        tLength length;
        eError error;

        if ((chars = m_inFileName.HasChars(length)))
        if ((error = m_inFile.Open(chars, FILE_MODE_READ)))
        {
            DBE("() failed to open file \"%s\"\n", chars);
            return 1;
        }
        else
        in = &m_inFile;

        if ((error = m_t.Expand(*out, *in)))
            DBE("() failed on m_t.Expand(*out, *in)\n");
        return err;
    }
    /**
     **********************************************************************
     * Function: MainNamedArg
     *
     *   Author: $author$
     *     Date: 1/1/2009
     **********************************************************************
     */
    virtual int MainNamedArg
    (const tChar *argName, const tChar *argValue,
     int args, int argn, const tChar *arg, 
     int argc, const tChar** argv, const tChar** env) 
    {
        tLength argNameLength = -1;
        tLength argValueLength = -1;
        m_t.SetValue(argName,argNameLength, argValue,argValueLength);
        return argn;
    }
    /**
     **********************************************************************
     * Function: MainUnnamedArgn
     *
     *   Author: $author$
     *     Date: 12/31/2008
     **********************************************************************
     */
    virtual int MainUnnamedArgn
    (int unnamedArgn,
     int args, int argn, const tChar *arg, 
     int argc, const tChar** argv, const tChar** env) 
    {
        tLength length;
        const tChar* chars;

        if (arg)
        if (arg[0])
        if (1 > unnamedArgn)
        {
            if (0 > (length = m_inFileName.Assign(arg)))
                DBE("() failed to assign input file = \"%s\"\n", arg);
            else
            if (m_inputVariableNameChars)
            if ((chars = m_inFileName.HasChars(length)))
                m_t.SetValue(m_inputVariableNameChars,-1, chars,length);
        }
        else
        if (2 > unnamedArgn)
        {
            if (0 > (length = m_outFileName.Assign(arg)))
                DBE("() failed to assign output file = \"%s\"\n", arg);
            else
            if (m_outputVariableNameChars)
            if ((chars = m_outFileName.HasChars(length)))
                m_t.SetValue(m_outputVariableNameChars,-1, chars,length);
        }
        return argn;
    }
};
#endif /* _CTMAIN_HXX */
