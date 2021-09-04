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
 *   File: cargmain.hxx
 *
 * Author: $author$
 *   Date: 11/15/2007
 **********************************************************************
 */
#ifndef _CARGMAIN_HXX
#define _CARGMAIN_HXX

#include "cmainarg.hxx"
#include "cmain.hxx"
#include "csplitter.hxx"

/**
 **********************************************************************
 *  Class: cArgMainT
 *
 * Author: $author$
 *   Date: 1/20/2008
 **********************************************************************
 */
template
<class TChar,
 class TSize,
 class TLength,
 class TString,
 class TSplitter,
 class TMainArg,
 class TMainArgList,
 class TMainArgItem,
 class TExtends>
 
class cArgMainT
: public TExtends
{
public:
    typedef TExtends cExtends;
    typedef cArgMainT cDerives;

    typedef TChar tChar;
    typedef TSize tSize;
    typedef TLength tLength;
    typedef TString tString;
    typedef TSplitter tSplitter;

    const TChar m_minus;
    const TChar m_equal;
    int m_unnamedArgs;
    TString m_argName;

    /**
     **********************************************************************
     * Constructor: cArgMainT
     *
     *      Author: $author$
     *        Date: 1/20/2008
     **********************************************************************
     */
    cArgMainT() 
    : m_minus('-'),
      m_equal('='),
      m_unnamedArgs(0)
    {
    }
    /**
     **********************************************************************
     * Function: Main
     *
     *   Author: $author$
     *     Date: 1/20/2008
     **********************************************************************
     */
    virtual int Main
    (int argc, const TChar** argv, const TChar** env) 
    {
        int err = 1;
        eError error;
        if (!(error = CTHIS StdAttach()))
        {
            if (0 <= (err = MainArgs(argc, argv, env)))
                err = CTHIS Run(argc, argv, env);
            CTHIS StdDetach();
        }
        return err;
    }
    /**
     **********************************************************************
     * Function: MainArgs
     *
     *   Author: $author$
     *     Date: 1/20/2008
     **********************************************************************
     */
    virtual int MainArgs
    (int argc, const TChar** argv, const TChar** env) 
    {
        int argn, argon, args=0;
        const TChar *arg;

        for (argon = argn = 0; argn < argc; argon = ++argn)
        {
            if (!(arg = argv[argn]))
                return -e_ERROR_NULL_PARAMETER;

            if ((argn = MainArg
                (args, argn, arg, argc, argv, env)) < argon)
            {
                if (argn >= 0)
                    return -e_ERROR_INVALID_RETURN;

                return argn;
            }
            ++args;
        }
        return args;
    }
    /**
     **********************************************************************
     * Function: MainArg
     *
     *   Author: $author$
     *     Date: 1/20/2008
     **********************************************************************
     */
    virtual int MainArg
    (int args, int argn, const TChar *arg, 
     int argc, const TChar** argv, const TChar** env) 
    {
        if (1 > argn)
            return MainArg0
            (args, argn, arg, argc, argv, env);

        if (m_minus != arg[0])
            argn = MainArgn
            (args, argn, arg, argc, argv, env);

        else 
        argn = MainArgSwitch
        (args, argn, arg+1, argc, argv, env);
        return argn;
    }
    /**
     **********************************************************************
     * Function: MainArgSwitch
     *
     *   Author: $author$
     *     Date: 1/20/2008
     **********************************************************************
     */
    virtual int MainArgSwitch
    (int args, int argn, const TChar *arg, 
     int argc, const TChar** argv, const TChar** env) 
    {
        if (m_minus != arg[0])
            argn = MainArgShort
            (args, argn, arg, argc, argv, env);
        else 
        argn = MainArgLong
        (args, argn, arg+1, argc, argv, env);
        return argn;
    }
    /**
     **********************************************************************
     * Function: MainArgShort
     *
     *   Author: $author$
     *     Date: 1/20/2008
     **********************************************************************
     */
    virtual int MainArgShort
    (int args, int argn, const TChar *arg, 
     int argc, const TChar** argv, const TChar** env) 
    {
        int argon = argn;
        TMainArg* mainArg;
        TChar argChar;
        const TChar* argNameChars;
        TLength argNameLength;

        if (0 < (argNameLength = m_argName.Assign(arg, 1)))
        if ((argNameChars = m_argName.HasChars(argNameLength)))
        {
            TMainArgList& list = GetList();
            if (!(argChar = *(++arg)))
                arg = 0;
            if ((mainArg = list.FindFirstArgByShortName(argNameChars)))
            if (argon <= (argn = mainArg->MainArg(args, argn, arg, argc, argv, env)))
                CTHIS SetDidMainArg();
        }
        return argn;
    }
    /**
     **********************************************************************
     * Function: MainArgLong
     *
     *   Author: $author$
     *     Date: 1/20/2008
     **********************************************************************
     */
    virtual int MainArgLong
    (int args, int argn, const TChar *arg, 
     int argc, const TChar** argv, const TChar** env) 
    {
        int argon = argn;
        TMainArg* mainArg;
        const TChar* argNameChars;
        TLength argNameLength;

        if (0 < (argNameLength = m_argName.Assign(arg)))
        if ((argNameChars = m_argName.HasChars(argNameLength)))
        {
            TMainArgList& list = GetList();
            arg = 0;
            if ((mainArg = list.FindFirstArgByName(argNameChars)))
            if (argon <= (argn = mainArg->MainArg(args, argn, arg, argc, argv, env)))
                CTHIS SetDidMainArg();
        }
        return argn;
    }
    /**
     **********************************************************************
     * Function: MainArg0
     *
     *   Author: $author$
     *     Date: 1/20/2008
     **********************************************************************
     */
    virtual int MainArg0
    (int args, int argn, const TChar *arg, 
     int argc, const TChar** argv, const TChar** env) 
    {
        return argn;
    }
    /**
     **********************************************************************
     * Function: MainArgn
     *
     *   Author: $author$
     *     Date: 1/20/2008
     **********************************************************************
     */
    virtual int MainArgn
    (int args, int argn, const TChar *arg, 
     int argc, const TChar** argv, const TChar** env) 
    {
        int unnamedArgn;
        tLength argNameLength;
        const tChar* argName;
        const tChar* argValue;
        tSplitter splitter;
        
        if (arg)
        if (arg[0])
        if ((argName = splitter.LeftOf
            (argNameLength, m_equal, arg)))
        if (0 < (argNameLength))
        if ((argValue = arg+argNameLength+1))
        if (0 < (argNameLength =  m_argName.Assign
            (argName, argNameLength)))
        if ((argName = m_argName.HasChars(argNameLength)))
        return argn = MainNamedArg
        (argName, argValue, args, argn, arg, argc, argv, env);

        unnamedArgn = m_unnamedArgs++;
        argn = MainUnnamedArgn
        (unnamedArgn, args, argn, arg, argc, argv, env);
        return argn;
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
    (const TChar *argName, const TChar *argValue,
     int args, int argn, const TChar *arg, 
     int argc, const TChar** argv, const TChar** env) 
    {
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
     int args, int argn, const TChar *arg, 
     int argc, const TChar** argv, const TChar** env) 
    {
        return argn;
    }
    /**
     **********************************************************************
     * Function: GetList
     *
     *   Author: $author$
     *     Date: 2/20/2007
     **********************************************************************
     */
    virtual TMainArgList& GetList() const = 0;
};

/**
 **********************************************************************
 * Typedef: cArgMainExtends
 *
 *  Author: $author$
 *    Date: 12/31/2008
 **********************************************************************
 */
typedef cArgMainT
<char, TSIZE, TLENGTH, 
 cCharString, cCharSplitter, cMainArgInterface, 
 cMainArgList, cMainArgItem, cMain>
cArgMainExtends;

/**
 **********************************************************************
 *  Class: cArgMain
 *
 * Author: $author$
 *   Date: 1/21/2008
 **********************************************************************
 */
class cArgMain
: public cArgMainExtends
{
public:
    typedef cArgMainExtends cExtends;
    typedef cArgMain cDerives;
    /**
     **********************************************************************
     * Function: GetList
     *
     *   Author: $author$
     *     Date: 2/20/2007
     **********************************************************************
     */
    virtual cMainArgList& GetList() const
    {
        return cMainArg::m_list;
    }
}; 

#endif /* _CARGMAIN_HXX */
