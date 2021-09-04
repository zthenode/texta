///////////////////////////////////////////////////////////////////////
// Copyright (c) 1988-2011 $organization$
//
// This software is provided by the author and contributors ``as is'' 
// and any express or implied warranties, including, but not limited to, 
// the implied warranties of merchantability and fitness for a particular 
// purpose are disclaimed. In no event shall the author or contributors 
// be liable for any direct, indirect, incidental, special, exemplary, 
// or consequential damages (including, but not limited to, procurement 
// of substitute goods or services; loss of use, data, or profits; or 
// business interruption) however caused and on any theory of liability, 
// whether in contract, strict liability, or tort (including negligence 
// or otherwise) arising in any way out of the use of this software, 
// even if advised of the possibility of such damage.
//
//   File: cCgiEnv.hpp
//
// Author: $author$
//   Date: 6/5/2011
///////////////////////////////////////////////////////////////////////
#if !defined(_CCGIENV_HPP) || defined(CCGIENV_MEMBERS_ONLY)
#if !defined(_CCGIENV_HPP) && !defined(CCGIENV_MEMBERS_ONLY)
#define _CCGIENV_HPP
#endif // !defined(_CCGIENV_HPP) && !defined(CCGIENV_MEMBERS_ONLY) 

#if !defined(CCGIENV_MEMBERS_ONLY)
#include "cCgiEnvInterface.hpp"
#include "cInstanceBase.hpp"
#include "cplatform_setenv.h"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

///////////////////////////////////////////////////////////////////////
// Typedef: cCgiEnvExtend
//
//  Author: $author$
//    Date: 6/5/2011
///////////////////////////////////////////////////////////////////////
typedef cInstanceBase
cCgiEnvExtend;
///////////////////////////////////////////////////////////////////////
//  Class: cCgiEnv
//
// Author: $author$
//   Date: 6/5/2011
///////////////////////////////////////////////////////////////////////
class c_INSTANCE_CLASS cCgiEnv
: virtual public cCgiEnvImplement,
  public cCgiEnvExtend
{
public:
    typedef cCgiEnvImplement cImplements;
    typedef cCgiEnvExtend cExtends;

    const char* m_nameChars[e_COUNT_CGI_ENV];
    const char* m_valueChars[e_COUNT_CGI_ENV];
    cString m_name[e_COUNT_CGI_ENV];
    cString m_value[e_COUNT_CGI_ENV];

    ///////////////////////////////////////////////////////////////////////
    //  Constructor: cCgiEnv
    //
    //       Author: $author$
    //         Date: 6/5/2011
    ///////////////////////////////////////////////////////////////////////
    cCgiEnv()
    {
        for (eCgiEnv e=e_FIRST_CGI_ENV; e<=e_LAST_CGI_ENV; e++)
            m_nameChars[e-e_FIRST_CGI_ENV] = (m_valueChars[e-e_FIRST_CGI_ENV] = 0);
    }
    ///////////////////////////////////////////////////////////////////////
    //  Destructor: ~cCgiEnv
    //
    //      Author: $author$
    //        Date: 6/5/2011
    ///////////////////////////////////////////////////////////////////////
    virtual ~cCgiEnv()
    {
        eError error;
        if ((error = Finish()))
            throw(error);
    }
#else // !defined(CCGIENV_MEMBERS_ONLY) 
#endif // !defined(CCGIENV_MEMBERS_ONLY) 

    ///////////////////////////////////////////////////////////////////////
    //  Function: Init
    //
    //    Author: $author$
    //      Date: 6/28/2011
    ///////////////////////////////////////////////////////////////////////
    virtual eError Init()
#if defined(CCGIENV_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CCGIENV_MEMBER_FUNCS_INTERFACE) 
    {
        eError error = e_ERROR_NONE;
#if !defined(CCGIENV_MEMBER_FUNCS_IMPLEMENT)
        eError error2;
        ssize_t count;
        const char* nameChars;

        for (eCgiEnv e=e_FIRST_CGI_ENV; e<=e_LAST_CGI_ENV; e++)
        {
            m_nameChars[e-e_FIRST_CGI_ENV] = 0;
            if ((nameChars = GetEnvName(e)))
            if (0 > (count = m_name[e-e_FIRST_CGI_ENV].Assign
                (m_nameChars[e-e_FIRST_CGI_ENV] = nameChars)))
            if (!error)
                error = (eError)(-count);
        }

        if ((error2 = Clear()))
        if (!error)
            error = (eError)(-count);

#else // !defined(CCGIENV_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CCGIENV_MEMBER_FUNCS_IMPLEMENT) 
        return error;
    }
#endif // defined(CCGIENV_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    //  Function: Finish
    //
    //    Author: $author$
    //      Date: 6/28/2011
    ///////////////////////////////////////////////////////////////////////
    virtual eError Finish()
#if defined(CCGIENV_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CCGIENV_MEMBER_FUNCS_INTERFACE) 
    {
        eError error = e_ERROR_NONE;
#if !defined(CCGIENV_MEMBER_FUNCS_IMPLEMENT)
        ssize_t count;

        error = Clear();

        for (eCgiEnv e=e_FIRST_CGI_ENV; e<=e_LAST_CGI_ENV; e++)
        {
            m_nameChars[e-e_FIRST_CGI_ENV] = 0;
            if (0 > (count = m_name[e-e_FIRST_CGI_ENV].Clear()))
            if (!error)
                error = (eError)(-count);
        }
#else // !defined(CCGIENV_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CCGIENV_MEMBER_FUNCS_IMPLEMENT) 
        return error;
    }
#endif // defined(CCGIENV_MEMBER_FUNCS_INTERFACE) 

    ///////////////////////////////////////////////////////////////////////
    //  Function: Clear
    //
    //    Author: $author$
    //      Date: 6/24/2011
    ///////////////////////////////////////////////////////////////////////
    virtual eError Clear()
#if defined(CCGIENV_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CCGIENV_MEMBER_FUNCS_INTERFACE) 
    {
        eError error = e_ERROR_NONE;
#if !defined(CCGIENV_MEMBER_FUNCS_IMPLEMENT)
        ssize_t count;
        for (eCgiEnv e=e_FIRST_CGI_ENV; e<=e_LAST_CGI_ENV; e++)
        {
            m_valueChars[e-e_FIRST_CGI_ENV] = 0;
            if (0 > (count = m_value[e-e_FIRST_CGI_ENV].Clear()))
            if (!error)
                error = (eError)(-count);
        }
#else // !defined(CCGIENV_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CCGIENV_MEMBER_FUNCS_IMPLEMENT) 
        return error;
    }
#endif // defined(CCGIENV_MEMBER_FUNCS_INTERFACE) 

    ///////////////////////////////////////////////////////////////////////
    //  Function: Set
    //
    //    Author: $author$
    //      Date: 6/28/2011
    ///////////////////////////////////////////////////////////////////////
    virtual const char* Set
    (const cString& toName, const char* toChars, ssize_t length=-1)
#if defined(CCGIENV_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CCGIENV_MEMBER_FUNCS_INTERFACE) 
    {
        const char* chars = 0;
#if !defined(CCGIENV_MEMBER_FUNCS_IMPLEMENT)
        for (eCgiEnv e = e_FIRST_CGI_ENV; e <= e_LAST_CGI_ENV; e++)
        {
            const char*& valueChars = m_valueChars[e-e_FIRST_CGI_ENV];
            cString& value = m_value[e-e_FIRST_CGI_ENV];
            cString& name = m_name[e-e_FIRST_CGI_ENV];

            if ((toName == name))
            if ((chars = (valueChars = toChars)))
            if (0 <= (length = ((cStringInterface&)(value)).Assign(toChars, length)))
                chars = (valueChars = value.Chars());
            else
            chars = (valueChars = 0);
        }
#else // !defined(CCGIENV_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CCGIENV_MEMBER_FUNCS_IMPLEMENT) 
        return chars;
    }
#endif // defined(CCGIENV_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    //  Function: Set
    //
    //    Author: $author$
    //      Date: 6/24/2011
    ///////////////////////////////////////////////////////////////////////
    virtual const char* Set
    (eCgiEnv e, const char* toChars, ssize_t length=-1)
#if defined(CCGIENV_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CCGIENV_MEMBER_FUNCS_INTERFACE) 
    {
        const char* chars = 0;
#if !defined(CCGIENV_MEMBER_FUNCS_IMPLEMENT)
        if ((e >= e_FIRST_CGI_ENV) && (e <= e_LAST_CGI_ENV))
        {
            const char*& valueChars = m_valueChars[e-e_FIRST_CGI_ENV];
            cString& value = m_value[e-e_FIRST_CGI_ENV];

            if ((chars = (valueChars = toChars)))
            if (0 <= (length = ((cStringInterface&)(value)).Assign(toChars, length)))
                chars = (valueChars = value.Chars());
            else
            chars = (valueChars = 0);
        }
#else // !defined(CCGIENV_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CCGIENV_MEMBER_FUNCS_IMPLEMENT) 
        return chars;
    }
#endif // defined(CCGIENV_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    //  Function: Get
    //
    //    Author: $author$
    //      Date: 6/24/2011
    ///////////////////////////////////////////////////////////////////////
    virtual const char* Get(eCgiEnv e) const
#if defined(CCGIENV_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CCGIENV_MEMBER_FUNCS_INTERFACE) 
    {
        const char* chars = 0;
#if !defined(CCGIENV_MEMBER_FUNCS_IMPLEMENT)
        if ((e >= e_FIRST_CGI_ENV) && (e <= e_LAST_CGI_ENV))
            chars = m_valueChars[e-e_FIRST_CGI_ENV];
#else // !defined(CCGIENV_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CCGIENV_MEMBER_FUNCS_IMPLEMENT) 
        return chars;
    }
#endif // defined(CCGIENV_MEMBER_FUNCS_INTERFACE) 

    ///////////////////////////////////////////////////////////////////////
    //  Function: GetName
    //
    //    Author: $author$
    //      Date: 6/24/2011
    ///////////////////////////////////////////////////////////////////////
    virtual const char* GetName(eCgiEnv e) const
#if defined(CCGIENV_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CCGIENV_MEMBER_FUNCS_INTERFACE) 
    {
        const char* chars = 0;
#if !defined(CCGIENV_MEMBER_FUNCS_IMPLEMENT)
        if ((e >= e_FIRST_CGI_ENV) && (e <= e_LAST_CGI_ENV))
            chars = m_nameChars[e-e_FIRST_CGI_ENV];
#else // !defined(CCGIENV_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CCGIENV_MEMBER_FUNCS_IMPLEMENT) 
        return chars;
    }
#endif // defined(CCGIENV_MEMBER_FUNCS_INTERFACE) 

    ///////////////////////////////////////////////////////////////////////
    //  Function: GetFirst
    //
    //    Author: $author$
    //      Date: 6/28/2011
    ///////////////////////////////////////////////////////////////////////
    virtual const char* GetFirst
    (eCgiEnv& e, const char*& valueChars) const
#if defined(CCGIENV_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CCGIENV_MEMBER_FUNCS_INTERFACE) 
    {
        const char* chars = 0;
#if !defined(CCGIENV_MEMBER_FUNCS_IMPLEMENT)
        e = e_FIRST_CGI_ENV;
        if ((e >= e_FIRST_CGI_ENV) && (e <= e_LAST_CGI_ENV))
        {
            chars = m_nameChars[e-e_FIRST_CGI_ENV];
            valueChars = m_valueChars[e-e_FIRST_CGI_ENV];
        }
#else // !defined(CCGIENV_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CCGIENV_MEMBER_FUNCS_IMPLEMENT) 
        return chars;
    }
#endif // defined(CCGIENV_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    //  Function: GetNext
    //
    //    Author: $author$
    //      Date: 6/28/2011
    ///////////////////////////////////////////////////////////////////////
    virtual const char* GetNext
    (eCgiEnv& e, const char*& valueChars) const
#if defined(CCGIENV_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CCGIENV_MEMBER_FUNCS_INTERFACE) 
    {
        const char* chars = 0;
#if !defined(CCGIENV_MEMBER_FUNCS_IMPLEMENT)
        if ((e >= e_FIRST_CGI_ENV) && (e < e_LAST_CGI_ENV))
        {
            chars = m_nameChars[(++e)-e_FIRST_CGI_ENV];
            valueChars = m_valueChars[e-e_FIRST_CGI_ENV];
        }
#else // !defined(CCGIENV_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CCGIENV_MEMBER_FUNCS_IMPLEMENT) 
        return chars;
    }
#endif // defined(CCGIENV_MEMBER_FUNCS_INTERFACE) 

    ///////////////////////////////////////////////////////////////////////
    //  Function: GetLast
    //
    //    Author: $author$
    //      Date: 6/28/2011
    ///////////////////////////////////////////////////////////////////////
    virtual const char* GetLast
    (eCgiEnv& e, const char*& valueChars) const
#if defined(CCGIENV_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CCGIENV_MEMBER_FUNCS_INTERFACE) 
    {
        const char* chars = 0;
#if !defined(CCGIENV_MEMBER_FUNCS_IMPLEMENT)
        e = e_LAST_CGI_ENV;
        if ((e >= e_FIRST_CGI_ENV) && (e <= e_LAST_CGI_ENV))
        {
            chars = m_nameChars[e-e_FIRST_CGI_ENV];
            valueChars = m_valueChars[e-e_FIRST_CGI_ENV];
        }
#else // !defined(CCGIENV_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CCGIENV_MEMBER_FUNCS_IMPLEMENT) 
        return chars;
    }
#endif // defined(CCGIENV_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    //  Function: GetPrev
    //
    //    Author: $author$
    //      Date: 6/28/2011
    ///////////////////////////////////////////////////////////////////////
    virtual const char* GetPrev
    (eCgiEnv& e, const char*& valueChars) const
#if defined(CCGIENV_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CCGIENV_MEMBER_FUNCS_INTERFACE) 
    {
        const char* chars = 0;
#if !defined(CCGIENV_MEMBER_FUNCS_IMPLEMENT)
        if ((e > e_FIRST_CGI_ENV) && (e <= e_LAST_CGI_ENV))
        {
            chars = m_nameChars[(--e)-e_FIRST_CGI_ENV];
            valueChars = m_valueChars[e-e_FIRST_CGI_ENV];
        }
#else // !defined(CCGIENV_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CCGIENV_MEMBER_FUNCS_IMPLEMENT) 
        return chars;
    }
#endif // defined(CCGIENV_MEMBER_FUNCS_INTERFACE) 

    ///////////////////////////////////////////////////////////////////////
    //  Function: SetEnv
    //
    //    Author: $author$
    //      Date: 6/24/2011
    ///////////////////////////////////////////////////////////////////////
    virtual const char* SetEnv
    (eCgiEnv e, const char* toChars, 
     ssize_t length=-1, bool overwrite=true)
#if defined(CCGIENV_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CCGIENV_MEMBER_FUNCS_INTERFACE) 
    {
        const char* chars = 0;
#if !defined(CCGIENV_MEMBER_FUNCS_IMPLEMENT)
        const char* nameChars;
        if ((nameChars = GetEnvName(e)))
        if ((toChars))
        if (0 <= (length))
        {
            cString toString(toChars, length);
            if ((toChars = toString.Chars()))
            if (!(setenv(nameChars, toChars, (overwrite)?(1):(0))))
                chars = getenv(nameChars);
        }
        else
        if (!(setenv(nameChars, toChars, (overwrite)?(1):(0))))
            chars = getenv(nameChars);
#else // !defined(CCGIENV_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CCGIENV_MEMBER_FUNCS_IMPLEMENT) 
        return chars;
    }
#endif // defined(CCGIENV_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    //  Function: GetEnv
    //
    //    Author: $author$
    //      Date: 7/23/2011
    ///////////////////////////////////////////////////////////////////////
    virtual const char* GetEnv(eCgiEnv e) const
#if defined(CCGIENV_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CCGIENV_MEMBER_FUNCS_INTERFACE) 
    {
        const char* chars = 0;
#if !defined(CCGIENV_MEMBER_FUNCS_IMPLEMENT)
        const char* nameChars;
        if ((nameChars = GetEnvName(e)))
            chars = getenv(nameChars);
#else // !defined(CCGIENV_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CCGIENV_MEMBER_FUNCS_IMPLEMENT) 
        return chars;
    }
#endif // defined(CCGIENV_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    //  Function: GetEnvName
    //
    //    Author: $author$
    //      Date: 11/23/2012
    ///////////////////////////////////////////////////////////////////////
    virtual const char* GetEnvName(eCgiEnv e) const
#if defined(CCGIENV_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CCGIENV_MEMBER_FUNCS_INTERFACE) 
    {
        const char* chars = 0;
#if !defined(CCGIENV_MEMBER_FUNCS_IMPLEMENT)
        if ((e >= e_FIRST_CGI_ENV) && (e <= e_LAST_CGI_ENV))
            chars = c_cgi_env_name[e-e_FIRST_CGI_ENV];
#else // !defined(CCGIENV_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CCGIENV_MEMBER_FUNCS_IMPLEMENT) 
        return chars;
    }
#endif // defined(CCGIENV_MEMBER_FUNCS_INTERFACE) 

#if !defined(CCGIENV_MEMBERS_ONLY)
};

#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#else // !defined(CCGIENV_MEMBERS_ONLY) 
#endif // !defined(CCGIENV_MEMBERS_ONLY) 

#endif // !defined(_CCGIENV_HPP) || defined(CCGIENV_MEMBERS_ONLY) 
