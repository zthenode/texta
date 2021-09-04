///////////////////////////////////////////////////////////////////////
// Copyright (c) 1988-2012 $organization$
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
//   File: cCgiCgiMain.hpp
//
// Author: $author$
//   Date: 11/23/2012
///////////////////////////////////////////////////////////////////////
#ifndef _CCGICGIMAIN_HPP
#define _CCGICGIMAIN_HPP

#include "cCgiMain.hpp"
#include "cCgiMainCgiContentStream.hpp"
#include "cCgiMainHttpFormFields.hpp"
#include "cCgiMainHttpRequest.hpp"
#include "cCgiMainCgiEnv.hpp"
#include "cCgi.hpp"
#include "cDebug.hpp"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

///////////////////////////////////////////////////////////////////////
// Typedef: cCgiCgiMainImplement
//
//  Author: $author$
//    Date: 11/23/2012
///////////////////////////////////////////////////////////////////////
typedef cCgiMainImplement
cCgiCgiMainImplement;
///////////////////////////////////////////////////////////////////////
// Typedef: cCgiCgiMainExtend
//
//  Author: $author$
//    Date: 11/23/2012
///////////////////////////////////////////////////////////////////////
typedef cCgiMain
cCgiCgiMainExtend;
///////////////////////////////////////////////////////////////////////
//  Class: cCgiCgiMain
//
// Author: $author$
//   Date: 11/23/2012
//
// cCgiMain implementation cCgiInterface
///////////////////////////////////////////////////////////////////////
class c_EXPORT_CLASS cCgiCgiMain
: virtual public cCgiCgiMainImplement,
  public cCgiCgiMainExtend
{
public:
    typedef cCgiCgiMainImplement cImplements;
    typedef cCgiCgiMainExtend cExtends;

    cCgiMainCgiContentStream m_cgiContentOutput;
    cCgiMainHttpFormFields m_cgiFormFields;
    cCgiMainHttpRequest m_cgiRequest;
    cCgiMainCgiEnv m_cgiEnv;

    ///////////////////////////////////////////////////////////////////////
    //  Constructor: cCgiCgiMain
    //
    //       Author: $author$
    //         Date: 11/23/2012
    ///////////////////////////////////////////////////////////////////////
    cCgiCgiMain()
    : m_cgiContentOutput(*this),
      m_cgiFormFields(*this),
      m_cgiRequest(*this),
      m_cgiEnv(*this)
    {
    }
    ///////////////////////////////////////////////////////////////////////
    //  Destructor: ~cCgiCgiMain
    //
    //      Author: $author$
    //        Date: 11/23/2012
    ///////////////////////////////////////////////////////////////////////
    virtual ~cCgiCgiMain()
    {
    }

    ///////////////////////////////////////////////////////////////////////
    //  Function: RunCgi
    //
    //    Author: $author$
    //      Date: 11/23/2012
    ///////////////////////////////////////////////////////////////////////
    virtual int RunCgi
    (int argc, char** argv, char** env)
    {
        int err = 0;
        cCgiInterface* cgi;
        if ((cgi = (cCgiInterface::GetTheCgi()))) 
        {
            cCgiContentStreamInterface* oldCgiContentOutput = cgi->GetContentOutput();
            cStreamInterface* old_DEBUG_OUT = c_DEBUG_GET_OUT();
            eError error;

            c_DEBUG_SET_OUT(&m_cgiContentOutput);

            if (!(error = cgi->Init(&m_cgiContentOutput, &m_cgiFormFields, &m_cgiRequest, &m_cgiEnv)))
            {
                if (!(error = GetCgiMainCgiEnvironment()))
                {
                    if (!(error = GetCgiMainHttpFormFields()))
                    {
                        if ((err = cgi->Run(argc, argv, env)))
                            c_DB_ERROR("() failed " << err << " on cgi->Run()");
                    } else {
                        c_DB_ERROR("() failed " << error << " on GetCgiMainHttpFormFields()");
                    }
                } else {
                    c_DB_ERROR("() failed " << error << " on GetCgiMainCgiEnvironment()");
                }
            } else {
                c_DB_ERROR("() failed " << error << " on cgi->Init(...)");
            }
            c_DEBUG_SET_OUT(old_DEBUG_OUT);
        } else {
            c_DB_ERROR("() failed 0 on cCgiInterface::GetTheCgi()");
        }
        return err;
    }
    ///////////////////////////////////////////////////////////////////////
    //  Function: GetCgiMainCgiEnvironment
    //
    //    Author: $author$
    //      Date: 11/23/2012
    ///////////////////////////////////////////////////////////////////////
    virtual eError GetCgiMainCgiEnvironment()
    {
        eError error = e_ERROR_NONE;
        const char* chars;

        if (!(error = m_cgiEnv.Init())) 
        {
            for (eCgiEnv e=e_FIRST_CGI_ENV; e<=e_LAST_CGI_ENV; e++)
            {
                if ((chars = GetCgiEnvValue(e)))
                if (!(m_cgiEnv.Set(e, chars)))
                {
                    c_DB_ERROR("() failed on m_cgiEnv.Set(" << e << ", \"" << chars << "\")");
                    return error = e_ERROR_FAILED;
                }
            }
        } else {
            c_DB_ERROR("() failed " << error << " on m_cgiEnv.Init()");
        }
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    //  Function: GetCgiMainHttpFormFields
    //
    //    Author: $author$
    //      Date: 11/23/2012
    ///////////////////////////////////////////////////////////////////////
    virtual eError GetCgiMainHttpFormFields()
    {
        eError error = e_ERROR_NONE;
        return error;
    }
    // cHttpFormFieldsCharStreamEvents implementation
    // ...
    ///////////////////////////////////////////////////////////////////////
    //  Function: OnReadFormFieldsInit
    //
    //    Author: $author$
    //      Date: 11/24/2012
    ///////////////////////////////////////////////////////////////////////
    virtual eError OnReadFormFieldsInit(bool isFromQueryString=false)
    {
        eError error = e_ERROR_NONE;
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    //  Function: OnReadFormFieldsFinal
    //
    //    Author: $author$
    //      Date: 11/24/2012
    ///////////////////////////////////////////////////////////////////////
    virtual eError OnReadFormFieldsFinal(bool isFromQueryString=false)
    {
        eError error = e_ERROR_NONE;
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    //  Function: OnReadFormField
    //
    //    Author: $author$
    //      Date: 11/24/2012
    ///////////////////////////////////////////////////////////////////////
    virtual eError OnReadFormField
    (const cString& name, const cString& value, bool isFromQueryString=false)
    {
        eError error = e_ERROR_NONE;
        m_cgiFormFields.Add(name, value, isFromQueryString);
        return error;
    }
    // ...
    // cHttpFormFieldsCharStreamEvents implementation
};

#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#endif // _CCGICGIMAIN_HPP 
        

