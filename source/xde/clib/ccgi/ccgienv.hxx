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
 *   File: ccgienv.hxx
 *
 * Author: $author$
 *   Date: 3/19/2008
 **********************************************************************
 */
#ifndef _CCGIENV_HXX
#define _CCGIENV_HXX

#include "cnamevalueeventinterface.hxx"
#include "ccomparer.hxx"
#include "cstring.hxx"
#include "cdebug.h"
#include "ccgi.h"

#undef CDB_CLASS
#define CDB_CLASS "cCGIEnvT"
/**
 **********************************************************************
 *  Class: cCGIEnvT
 *
 * Author: $author$
 *   Date: 3/19/2008
 **********************************************************************
 */
template
<class TChar=CHAR,
 class TSize=TSIZE,
 class TLength=TLENGTH,
 TLength VUndefinedLength=UNDEFINED_LENGTH,
 class TNull=TChar,
 TNull VNull=NULL_CHAR,
 class TString=cString,
 class TImplements=cNameValueEventInterface,
 class TExtends=cBase>
 
class cCGIEnvT
: virtual public TImplements,
  public TExtends
{
public:
    typedef TImplements cImplements;
    typedef TExtends cExtends;
    typedef cCGIEnvT cDerives;

    typedef cComparerT
    <TChar, TLength, VUndefinedLength, 
     TNull, VNull> cComparer;

    const TChar* m_envNull;
    const TChar* m_env[e_COUNT_CGI_ENV];
    TString m_envValue[e_COUNT_CGI_ENV];

    cComparer m_comparer;

    /**
     **********************************************************************
     * Constructor: cCGIEnvT
     *
     *      Author: $author$
     *        Date: 3/19/2008
     **********************************************************************
     */
    cCGIEnvT()
    : m_envNull("")
    {
    }
    /**
     **********************************************************************
     * Destructor: cCGIEnvT
     *
     *     Author: $author$
     *       Date: 3/19/2008
     **********************************************************************
     */
    virtual ~cCGIEnvT()
    {
    }

    /**
     **********************************************************************
     * Function: OnNameValue
     *
     *   Author: $author$
     *     Date: 3/18/2008
     **********************************************************************
     */
    eError OnNameValue
    (const TChar* name,
     const TChar* value) 
    {
        eError error = e_ERROR_NONE;
        TLength length;
        eCGIEnv env;
        CDBT("() \"%s\"=\"%s\"\n", name, value);
        if (0 <= (env = EnvNamed(name)))
        if (0 > (length = SetEnvValue(env, value)))
            error = -length;
        return error;
    }
    /**
     **********************************************************************
     * Function: InitEnv
     *
     *   Author: $author$
     *     Date: 3/4/2008
     **********************************************************************
     */
    virtual int InitEnv()
    {
        int env;
        for (env = 0; env < e_COUNT_CGI_ENV; env++)
            m_env[env] = m_envNull;
        return env;
    }
    /**
     **********************************************************************
     * Function: GetEnv
     *
     *   Author: $author$
     *     Date: 3/4/2008
     **********************************************************************
     */
    virtual int GetEnv()
    {
		int count = 0;
        int env;
		const TChar* name;
		const TChar* value;

        for (env = 0; env < e_COUNT_CGI_ENV; env++)
        {
            if ((value = getenv(name = cgi_env_name[env])))
                count++;
            else value = m_envNull;
			m_env[env] = value;
            CDBT("() env \"%s\"=\"%s\"\n", name, value);
        }
        return count;
    }
    /**
     **********************************************************************
     * Function: SetEnvValue
     *
     *   Author: $author$
     *     Date: 3/19/2008
     **********************************************************************
     */
    virtual TLength SetEnvValue
    (eCGIEnv env, const TChar* chars, TLength length=-1) 
    {
        TLength count = 0;
        TLength count2;
        if ((env >= e_FIRST_CGI_ENV) 
            && (env <= e_LAST_CGI_ENV))
        if (0 <= (count2 = m_envValue
            [env -= e_FIRST_CGI_ENV].Assign(chars, length)))
        if ((chars = m_envValue[env].Chars(count2)))
        {
            CDBT("() env \"%s\"=\"%s\"\n", cgi_env_name[env], chars);
            m_env[env] = chars;
            count = count2;
        }
        return count;
    }
    /**
     **********************************************************************
     * Function: EnvNamed
     *
     *   Author: $author$
     *     Date: 3/19/2008
     **********************************************************************
     */
    virtual eCGIEnv EnvNamed
    (const TChar* name, TLength length=-1) const
    {
        eCGIEnv env;
        int unequal;

        for (env = e_FIRST_CGI_ENV; env <= e_LAST_CGI_ENV; env++)
        {
            if (!(unequal = m_comparer.Compare
                (name, length, cgi_env_name[env - e_FIRST_CGI_ENV], -1)))
                return env;
        }
        return -1;
    }
    /**
     **********************************************************************
     * Function: EnvName
     *
     *   Author: $author$
     *     Date: 3/7/2008
     **********************************************************************
     */
    virtual const TChar* EnvName
    (TLength& length, eCGIEnv env) const 
    {
        const TChar* chars = 0;
        length = 0;
        if ((env >= e_FIRST_CGI_ENV) 
            && (env <= e_LAST_CGI_ENV))
        if ((chars = cgi_env_name[env - e_FIRST_CGI_ENV]))
            length = m_comparer.LengthOf(chars);
        else chars = 0;
        return chars;
    }
    /**
     **********************************************************************
     * Function: EnvValue
     *
     *   Author: $author$
     *     Date: 3/17/2008
     **********************************************************************
     */
    virtual const TChar* EnvValue
    (TLength& length, eCGIEnv env) const 
    {
        const TChar* chars = 0;
        length = 0;
        if ((env >= e_FIRST_CGI_ENV) 
            && (env <= e_LAST_CGI_ENV))
        if (m_envNull != (chars = m_env[env - e_FIRST_CGI_ENV]))
            length = m_comparer.LengthOf(chars);
        return chars;
    }
    /**
     **********************************************************************
     * Function: Env
     *
     *   Author: $author$
     *     Date: 3/7/2008
     **********************************************************************
     */
    virtual const TChar* Env
    (TLength& length, eCGIEnv env) const 
    {
        const TChar* chars = 0;
        length = 0;
        if ((env >= e_FIRST_CGI_ENV) 
            && (env <= e_LAST_CGI_ENV))
        if (m_envNull != (chars = m_env[env -= e_FIRST_CGI_ENV]))
        {
            CDBT("() env \"%s\" is \"%s\"\n", cgi_env_name[env], chars);
            length = m_comparer.LengthOf(chars);
        }
        else chars = 0;
        return chars;
    }
};
#undef CDB_CLASS

/**
 **********************************************************************
 *  Class: cCGIEnv
 *
 * Author: $author$
 *   Date: 3/20/2008
 **********************************************************************
 */
class cCGIEnv
: public cCGIEnvT
  <char,TSIZE,TLENGTH,-1,
   char,0,cCharString,
   cNameValueEventInterface,cBase>
{
public:
    typedef cCGIEnvT
    <char,TSIZE,TLENGTH,-1,
     char,0,cCharString,
     cNameValueEventInterface,cBase> cExtends;
};
#endif /* _CCGIENV_HXX */
