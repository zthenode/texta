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
//   File: cCgiccCgiMain.hpp
//
// Author: $author$
//   Date: 6/25/2011
///////////////////////////////////////////////////////////////////////
#if !defined(_CCGICCCGIMAIN_HPP) || defined(CCGICCCGIMAIN_MEMBERS_ONLY)
#if !defined(_CCGICCCGIMAIN_HPP) && !defined(CCGICCCGIMAIN_MEMBERS_ONLY)
#define _CCGICCCGIMAIN_HPP
#endif // !defined(_CCGICCCGIMAIN_HPP) && !defined(CCGICCCGIMAIN_MEMBERS_ONLY) 

#if !defined(CCGICCCGIMAIN_MEMBERS_ONLY)
#include "cCgiccMain.hpp"
#include "cCgiccMainCgiContentStream.hpp"
#include "cCgiccMainHttpFormFields.hpp"
#include "cCgiccMainHttpRequest.hpp"
#include "cCgiccMainCgiEnv.hpp"
#include "cCgi.hpp"
#include "cDebug.hpp"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

///////////////////////////////////////////////////////////////////////
// Typedef: cCgiccCgiMainImplement
//
//  Author: $author$
//    Date: 6/25/2011
///////////////////////////////////////////////////////////////////////
typedef cCgiccMainImplement
cCgiccCgiMainImplement;
///////////////////////////////////////////////////////////////////////
// Typedef: cCgiccCgiMainExtend
//
//  Author: $author$
//    Date: 6/25/2011
///////////////////////////////////////////////////////////////////////
typedef cCgiccMain
cCgiccCgiMainExtend;
///////////////////////////////////////////////////////////////////////
//  Class: cCgiccCgiMain
//
// Author: $author$
//   Date: 6/25/2011
///////////////////////////////////////////////////////////////////////
class c_INSTANCE_CLASS cCgiccCgiMain
: virtual public cCgiccCgiMainImplement,
  public cCgiccCgiMainExtend
{
public:
    typedef cCgiccCgiMainImplement cImplements;
    typedef cCgiccCgiMainExtend cExtends;

    cCgiccMainCgiContentStream m_cgiContentOutput;
    cCgiccMainHttpFormFields m_cgiFormFields;
    cCgiccMainHttpRequest m_cgiRequest;
    cCgiccMainCgiEnv m_cgiEnv;
    cCgiInterface* m_cgi;
    cCgiContentStreamInterface* m_oldCgiContentOutput;
    cStreamInterface* m_old_DEBUG_OUT;

    ///////////////////////////////////////////////////////////////////////
    //  Constructor: cCgiccCgiMain
    //
    //       Author: $author$
    //         Date: 6/25/2011
    ///////////////////////////////////////////////////////////////////////
    cCgiccCgiMain()
    : m_cgiContentOutput((*this)),
      m_cgiFormFields(*this),
      m_cgiRequest(*this),
      m_cgiEnv(*this),
      m_cgi(cCgiInterface::GetTheCgi()),
      m_oldCgiContentOutput((m_cgi)?(m_cgi->GetContentOutput()):(0)),
      m_old_DEBUG_OUT(c_DEBUG_GET_OUT())
    {
        c_DEBUG_SET_OUT(&m_cgiContentOutput);
    }
    ///////////////////////////////////////////////////////////////////////
    //  Destructor: ~cCgiccCgiMain
    //
    //      Author: $author$
    //        Date: 6/25/2011
    ///////////////////////////////////////////////////////////////////////
    virtual ~cCgiccCgiMain()
    {
        c_DEBUG_SET_OUT(m_old_DEBUG_OUT);
    }
#else // !defined(CCGICCCGIMAIN_MEMBERS_ONLY) 
#endif // !defined(CCGICCCGIMAIN_MEMBERS_ONLY) 

    ///////////////////////////////////////////////////////////////////////
    //  Function: Run
    //
    //    Author: $author$
    //      Date: 6/25/2011
    ///////////////////////////////////////////////////////////////////////
    virtual int Run
    (int argc,
     char** argv,
     char** env)
#if defined(CCGICCCGIMAIN_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CCGICCCGIMAIN_MEMBER_FUNCS_INTERFACE) 
    {
        int err = 0;
#if !defined(CCGICCCGIMAIN_MEMBER_FUNCS_IMPLEMENT)
        if ((m_cgi))
        {
            if (!(err = m_cgi->BeforeRun(argc, argv, env)))
            {
                int err2 = 0;

                err = m_cgi->Run(argc, argv, env);

                if ((err2 = m_cgi->AfterRun(argc, argv, env)))
                if (!(err))
                    err = err2;
            }
        }
        else
        {
            c_DB_ERROR("() m_cgi == 0");
            err = 1;
        }
#else // !defined(CCGICCCGIMAIN_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CCGICCCGIMAIN_MEMBER_FUNCS_IMPLEMENT) 
        return err;
    }
#endif // defined(CCGICCCGIMAIN_MEMBER_FUNCS_INTERFACE) 

    ///////////////////////////////////////////////////////////////////////
    //  Function: BeforeRun
    //
    //    Author: $author$
    //      Date: 6/25/2011
    ///////////////////////////////////////////////////////////////////////
    virtual int BeforeRun
    (int argc,
     char** argv,
     char** env)
#if defined(CCGICCCGIMAIN_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CCGICCCGIMAIN_MEMBER_FUNCS_INTERFACE) 
    {
        int err = 0;
#if !defined(CCGICCCGIMAIN_MEMBER_FUNCS_IMPLEMENT)
        if ((m_cgi))
        {
            eError error;
            if (!(error = m_cgi->Init
                (&m_cgiContentOutput, &m_cgiFormFields, &m_cgiRequest, &m_cgiEnv)))
            {
                if (!(error = m_cgiEnv.Init()))
                {
                    if (!(error = GetCgiccCgiEnvironment(*m_cgi)))
                    if (!(error = GetCgiccFormEntries(*m_cgi)))
                        return err;

                    m_cgiEnv.Finish();
                }
                m_cgi->Finish();
            }
            return err = (int)(error);
        }
        else
        {
            c_DB_ERROR("() m_cgi == 0");
            err = 1;
        }
#else // !defined(CCGICCCGIMAIN_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CCGICCCGIMAIN_MEMBER_FUNCS_IMPLEMENT) 
        return err;
    }
#endif // defined(CCGICCCGIMAIN_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    //  Function: AfterRun
    //
    //    Author: $author$
    //      Date: 6/25/2011
    ///////////////////////////////////////////////////////////////////////
    virtual int AfterRun
    (int argc,
     char** argv,
     char** env)
#if defined(CCGICCCGIMAIN_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CCGICCCGIMAIN_MEMBER_FUNCS_INTERFACE) 
    {
        int err = 0;
#if !defined(CCGICCCGIMAIN_MEMBER_FUNCS_IMPLEMENT)
        if ((m_cgi))
        {
            eError error;

            if ((error = m_cgiEnv.Finish()))
                err = (int)(error);

            if ((error = m_cgi->Finish()))
            if (!(err))
                err = (int)(error);
        }
        else
        {
            c_DB_ERROR("() m_cgi == 0");
            err = 1;
        }
#else // !defined(CCGICCCGIMAIN_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CCGICCCGIMAIN_MEMBER_FUNCS_IMPLEMENT) 
        return err;
    }
#endif // defined(CCGICCCGIMAIN_MEMBER_FUNCS_INTERFACE) 

    ///////////////////////////////////////////////////////////////////////
    //  Function: GetCgiccCgiEnvironment
    //
    //    Author: $author$
    //      Date: 6/29/2011
    ///////////////////////////////////////////////////////////////////////
    virtual eError GetCgiccCgiEnvironment(cCgiInterface& cgi)
#if defined(CCGICCCGIMAIN_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CCGICCCGIMAIN_MEMBER_FUNCS_INTERFACE) 
    {
        eError error = e_ERROR_NONE;
#if !defined(CCGICCCGIMAIN_MEMBER_FUNCS_IMPLEMENT)
        for (eCgiEnv e = e_FIRST_CGI_ENV; e <= e_LAST_CGI_ENV; e++)
        {
            const char* envValue;
            if ((envValue = m_cgiEnv.GetEnv(e)))
                m_cgiEnv.Set(e, envValue);
        }
#else // !defined(CCGICCCGIMAIN_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CCGICCCGIMAIN_MEMBER_FUNCS_IMPLEMENT) 
        return error;
    }
#endif // defined(CCGICCCGIMAIN_MEMBER_FUNCS_INTERFACE) 

    ///////////////////////////////////////////////////////////////////////
    //  Function: GetCgiccFormEntries
    //
    //    Author: $author$
    //      Date: 6/29/2011
    ///////////////////////////////////////////////////////////////////////
    virtual eError GetCgiccFormEntries(cCgiInterface& cgi)
#if defined(CCGICCCGIMAIN_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CCGICCCGIMAIN_MEMBER_FUNCS_INTERFACE) 
    {
        eError error = e_ERROR_NONE;
#if !defined(CCGICCCGIMAIN_MEMBER_FUNCS_IMPLEMENT)
        cgicc::FormEntries::const_iterator i = m_cgiccForm.begin();
        cgicc::FormEntries::const_iterator j = m_cgiccForm.end();

        for (; i != j; i++)
        {
            const cgicc::FormEntry& e = (*i);
            const cString name = e.getName();
            const cString value = e.getValue();
            bool isFromQueryString = false;

            if ((error = m_cgiFormFields.Add
                (name, value, isFromQueryString)))
                break;
        }
#else // !defined(CCGICCCGIMAIN_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CCGICCCGIMAIN_MEMBER_FUNCS_IMPLEMENT) 
        return error;
    }
#endif // defined(CCGICCCGIMAIN_MEMBER_FUNCS_INTERFACE) 

#if !defined(CCGICCCGIMAIN_MEMBERS_ONLY)
};


#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#else // !defined(CCGICCCGIMAIN_MEMBERS_ONLY) 
#endif // !defined(CCGICCCGIMAIN_MEMBERS_ONLY) 

#endif // !defined(_CCGICCCGIMAIN_HPP) || defined(CCGICCCGIMAIN_MEMBERS_ONLY) 
