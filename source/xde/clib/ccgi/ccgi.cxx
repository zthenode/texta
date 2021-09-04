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
 *   File: ccgi.cxx
 *
 * Author: $author$
 *   Date: 3/3/2008
 **********************************************************************
 */
#include "ccgi.hxx"
/**
 **********************************************************************
 *  Class: cCGIOutputContentWriter
 *
 * Author: $author$
 *   Date: 3/27/2008
 **********************************************************************
 */
/**
 **********************************************************************
 * Function: cCGIOutputContentWriter::Write
 *
 *   Author: $author$
 *     Date: 3/27/2008
 **********************************************************************
 */
cCGIOutputContentWriter::tLength 
cCGIOutputContentWriter::Write
(const tWhat* what, tLength length) 
{
    tLength count = m_cgi.OutputContent(what, length);
    return count;
}

/**
 **********************************************************************
 *  Class: cCGI
 *
 * Author: $author$
 *   Date: 3/3/2008
 **********************************************************************
 */
cCGI* cCGI::m_theCGI = 0;

/**
 **********************************************************************
 *  Class: cCGIMainArg
 *
 * Author: $author$
 *   Date: 3/24/2008
 **********************************************************************
 */
class cCGIMainArg
: public cMainArg
{
public:
    typedef cMainArg cExtends;
    typedef cCGIMainArg cDerives;
    /**
     **********************************************************************
     * Constructor: cCGIMainArg
     *
     *      Author: $author$
     *        Date: 3/24/2008
     **********************************************************************
     */
    cCGIMainArg
    (const char* shortName="g",
     const char* name="cgi",
     const char* description="CGI mode",
     const char* parameters="") 
    : cExtends(shortName, name, description, parameters)
    {
    }
    /**
     **********************************************************************
     * Function: MainArg
     *
     *   Author: $author$
     *     Date: 3/24/2008
     **********************************************************************
     */
    virtual int MainArg
    (int args,
     int argn,
     const char* arg,
     int argc,
     const char** argv,
     const char** env) 
    {
        int argon = argn;
        if (cCGI::m_theCGI)
            cCGI::m_theCGI->SetRunMode(e_CGI_RUN_MODE_CGI);
        return argon;
    }
} g_cgiCGIArg;

/**
 **********************************************************************
 *  Class: cCommandCGIMainArg
 *
 * Author: $author$
 *   Date: 3/24/2008
 **********************************************************************
 */
class cCommandCGIMainArg
: public cMainArg
{
public:
    typedef cMainArg cExtends;
    typedef cCommandCGIMainArg cDerives;
    /**
     **********************************************************************
     * Constructor: cCommandCGIMainArg
     *
     *      Author: $author$
     *        Date: 3/24/2008
     **********************************************************************
     */
    cCommandCGIMainArg
    (const char* shortName="c",
     const char* name="command",
     const char* description="Command mode",
     const char* parameters="") 
    : cExtends(shortName, name, description, parameters)
    {
    }
    /**
     **********************************************************************
     * Function: MainArg
     *
     *   Author: $author$
     *     Date: 3/24/2008
     **********************************************************************
     */
    virtual int MainArg
    (int args,
     int argn,
     const char* arg,
     int argc,
     const char** argv,
     const char** env) 
    {
        int argon = argn;
        if (cCGI::m_theCGI)
            cCGI::m_theCGI->SetRunMode(e_CGI_RUN_MODE_COMMAND);
        return argon;
    }
} g_commandCGIArg;
