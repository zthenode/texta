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
 *   File: cmaininterface.hxx
 *
 * Author: $author$
 *   Date: 1/16/2007
 *
 *    $Id$
 **********************************************************************
 */

#ifndef _CMAININTERFACE_HXX
#define _CMAININTERFACE_HXX

#include <stdio.h>
#include <stdarg.h>
#include "cinterfacebase.hxx"

/**
 **********************************************************************
 *  Class: cMainInterfaceT
 *
 * Author: $author$
 *   Date: 1/16/2007
 **********************************************************************
 */
template
<class TChar=CHAR,
 class TImplements=cInterfaceBase>

class cMainInterfaceT
: virtual public TImplements
{
public:
    typedef TImplements cImplements;
    /**
     **********************************************************************
     * Function: Main
     *
     *   Author: $author$
     *     Date: 1/16/2007
     **********************************************************************
     */
    virtual int Main
    (int argc, TChar** argv, TChar** env) = 0;
    /**
     **********************************************************************
     * Function: Main
     *
     *   Author: $author$
     *     Date: 1/16/2007
     **********************************************************************
     */
    virtual int Main
    (int argc, const TChar** argv, const TChar** env) = 0;
    /**
     **********************************************************************
     * Function: Run
     *
     *   Author: $author$
     *     Date: 1/16/2007
     **********************************************************************
     */
    virtual int Run
    (int argc, const TChar** argv, const TChar** env) = 0;
    /**
     **********************************************************************
     * Function: Usage
     *
     *   Author: $author$
     *     Date: 1/16/2007
     **********************************************************************
     */
    virtual int Usage
    (int argc, const TChar** argv, const TChar** env) = 0;
    /**
     **********************************************************************
     * Function: SetDidMain
     *
     *   Author: $author$
     *     Date: 3/15/2007
     **********************************************************************
     */
    virtual eError SetDidMain(bool did=true) = 0;
    /**
     **********************************************************************
     * Function: GetDidMain
     *
     *   Author: $author$
     *     Date: 3/15/2007
     **********************************************************************
     */
    virtual bool GetDidMain() const = 0;
};

/**
 **********************************************************************
 *  Class: cMainImplements
 *
 * Author: $author$
 *   Date: 1/18/2008
 **********************************************************************
 */
class c_INTERFACE_CLASS cMainImplements
: public cMainInterfaceT<CHAR, cInterfaceBase>
{
public:
    typedef cMainInterfaceT<CHAR, cInterfaceBase> cExtends;
    typedef cMainImplements cDerives;
    /**
     **********************************************************************
     * Function: GetMain
     *
     *   Author: $author$
     *     Date: 1/18/2008
     **********************************************************************
     */
    static cDerives* GetMain();
};
/**
 **********************************************************************
 *  Class: cMainImplementT
 *
 * Author: $author$
 *   Date: 2/13/2007
 **********************************************************************
 */
template
<class TChar=CHAR,
 class TImplements=cMainImplements>

class cMainImplementT
: virtual public TImplements
{
public:
    typedef TImplements cImplements;
    typedef cMainImplementT cDerives;

    /**
     **********************************************************************
     * Function: Main
     *
     *   Author: $author$
     *     Date: 2/13/2007
     **********************************************************************
     */
    virtual int Main
    (int argc, TChar** argv, TChar** env) 
    {
        const TChar** c_argv = (const TChar**)(argv);
        const TChar** c_env = (const TChar**)(env);
        int err = Main(argc, c_argv, c_env);
        return err;
    }
    /**
     **********************************************************************
     * Function: Main
     *
     *   Author: $author$
     *     Date: 2/13/2007
     **********************************************************************
     */
    virtual int Main
    (int argc, const TChar** argv, const TChar** env) 
    {
        int err = Run(argc, argv, env);
        return err;
    }
    /**
     **********************************************************************
     * Function: Run
     *
     *   Author: $author$
     *     Date: 2/13/2007
     **********************************************************************
     */
    virtual int Run
    (int argc, const TChar** argv, const TChar** env) 
    {
        int err = Usage(argc, argv, env);
        return err;
    }
    /**
     **********************************************************************
     * Function: Usage
     *
     *   Author: $author$
     *     Date: 2/13/2007
     **********************************************************************
     */
    virtual int Usage
    (int argc, const TChar** argv, const TChar** env) 
    {
        int err = 0;
        return err;
    }
    /**
     **********************************************************************
     * Function: SetDidMain
     *
     *   Author: $author$
     *     Date: 3/15/2007
     **********************************************************************
     */
    virtual eError SetDidMain(bool did=true) 
    {
        eError error = e_ERROR_NOT_IMPLEMENTED;
        return error;
    }
    /**
     **********************************************************************
     * Function: GetDidMain
     *
     *   Author: $author$
     *     Date: 3/15/2007
     **********************************************************************
     */
    virtual bool GetDidMain() const 
    {
        bool did = false;
        return did;
    }
};

/**
 **********************************************************************
 *  Class: cMainInterface
 *
 * Author: $author$
 *   Date: 1/18/2008
 **********************************************************************
 */
class c_INTERFACE_CLASS cMainInterface
: public cMainInterfaceT<char, cInterfaceBase>
{
public:
    typedef cMainInterfaceT<char, cInterfaceBase> cExtends;
    typedef cMainInterface cDerives;
    /**
     **********************************************************************
     * Function: GetMain
     *
     *   Author: $author$
     *     Date: 1/18/2008
     **********************************************************************
     */
    static cDerives* GetMain();
};
/**
 **********************************************************************
 *  Typedef: cMainImplement
 *
 *  Author: $author$
 *    Date: 1/18/2008
 **********************************************************************
 */
typedef cMainImplementT
<char, cMainInterface>
cMainImplement;

/**
 **********************************************************************
 *  Class: cTMainInterface
 *
 * Author: $author$
 *   Date: 1/18/2008
 **********************************************************************
 */
class c_INTERFACE_CLASS cTMainInterface
: public cMainInterfaceT<TCHAR, cInterfaceBase>
{
public:
    typedef cMainInterfaceT<TCHAR, cInterfaceBase> cExtends;
    typedef cTMainInterface cDerives;
    /**
     **********************************************************************
     * Function: GetMain
     *
     *   Author: $author$
     *     Date: 1/18/2008
     **********************************************************************
     */
    static cDerives* GetMain();
};
/**
 **********************************************************************
 *  Typedef: cTMainImplement
 *
 *  Author: $author$
 *    Date: 1/18/2008
 **********************************************************************
 */
typedef cMainImplementT
<TCHAR, cTMainInterface>
cTMainImplement;

/**
 **********************************************************************
 *  Class: cWMainInterface
 *
 * Author: $author$
 *   Date: 1/18/2008
 **********************************************************************
 */
class c_INTERFACE_CLASS cWMainInterface
: public cMainInterfaceT<WCHAR, cInterfaceBase>
{
public:
    typedef cMainInterfaceT<WCHAR, cInterfaceBase> cExtends;
    typedef cWMainInterface cDerives;
    /**
     **********************************************************************
     * Function: GetMain
     *
     *   Author: $author$
     *     Date: 1/18/2008
     **********************************************************************
     */
    static cDerives* GetMain();
};
/**
 **********************************************************************
 *  Typedef: cWMainImplement
 *
 *  Author: $author$
 *    Date: 1/18/2008
 **********************************************************************
 */
typedef cMainImplementT
<WCHAR, cWMainInterface>
cWMainImplement;

#endif /* _CMAININTERFACE_HXX */
