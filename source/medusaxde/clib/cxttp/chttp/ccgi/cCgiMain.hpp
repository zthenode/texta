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
//   File: cCgiMain.hpp
//
// Author: $author$
//   Date: 11/21/2012
///////////////////////////////////////////////////////////////////////
#ifndef _CCGIMAIN_HPP
#define _CCGIMAIN_HPP

#include "cOptMain.hpp"
#include "cCgiEnv.hpp"
#include "cCgiEnvCharStream.hpp"
#include "cCgiEnvCharStreamEvents.hpp"
#include "cHttpFormFields.hpp"
#include "cHttpFormFieldsCharStream.hpp"
#include "cHttpFormFieldsCharStreamEvents.hpp"
#include "cHttpUrlEncodedCharStream.hpp"
#include "cStringStream.hpp"
#include "cTypes.hpp"
#include "cHtmlMacro.hpp"
#include "cCgiEnv.h"
#include "cCgi.h"
#include "cHttp.h"
#include "cplatform_setenv.h"

#define CCGIMAIN_DEFAULT_CGI_NAME "cCgiMain"
#define CCGIMAIN_DEFAULT_CONTENT_TYPE_NAME c_http_content_type_html_name

#define CCGICATCH_DEFAULT_STDARG_FILENAME "ccgistdarg.txt"
#define CCGICATCH_DEFAULT_STDENV_FILENAME "ccgistdenv.txt"
#define CCGICATCH_DEFAULT_STDIN_FILENAME "ccgistdin.txt"
#define CCGICATCH_DEFAULT_STDOUT_FILENAME "ccgistdout.txt"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

///////////////////////////////////////////////////////////////////////
// Typedef: cCgiMainImplement
//
//  Author: $author$
//    Date: 11/21/2012
///////////////////////////////////////////////////////////////////////
typedef cOptMainImplement
cCgiMainImplement;
///////////////////////////////////////////////////////////////////////
// Typedef: cCgiMainExtend
//
//  Author: $author$
//    Date: 11/21/2012
///////////////////////////////////////////////////////////////////////
typedef cOptMain
cCgiMainExtend;
///////////////////////////////////////////////////////////////////////
//  Class: cCgiMain
//
// Author: $author$
//   Date: 11/21/2012
///////////////////////////////////////////////////////////////////////
class c_EXPORT_CLASS cCgiMain
: virtual public cCgiEnvCharStreamEvents,
  virtual public cHttpFormFieldsCharStreamEvents,
  virtual public cCharStreamImplement,
  virtual public cCgiMainImplement,
  public cCgiMainExtend
{
public:
    typedef cCgiMainImplement cImplements;
    typedef cCgiMainExtend cExtends;
    typedef cCgiMain cDerives;

    typedef const char* (cDerives::*MGetCgiEnvValue)(eCgiEnv env) const;

    cCgiMain* m_oldCgiMain;

    cString m_cgiName;
    const char* m_cgiNameChars;

    cString m_contentType;
    const char* m_contentTypeChars;
    const char* m_outputContentTypeChars;

    const char* m_stdArgFileNameChars;
    const char* m_stdEnvFileNameChars;
    const char* m_stdInFileNameChars;
    const char* m_stdOutFileNameChars;

    MGetCgiEnvValue m_getCgiEnvValue;
    cCgiEnv m_consoleCgiEnv;
    cHttpFormFields m_httpFormFields;

    ///////////////////////////////////////////////////////////////////////
    //  Constructor: cCgiMain
    //
    //       Author: $author$
    //         Date: 11/21/2012
    ///////////////////////////////////////////////////////////////////////
    cCgiMain
    (const char* cgiNameChars = CCGIMAIN_DEFAULT_CGI_NAME,
     const char* contentTypeChars = CCGIMAIN_DEFAULT_CONTENT_TYPE_NAME,
     const char* stdArgFileNameChars = CCGICATCH_DEFAULT_STDARG_FILENAME,
     const char* stdEnvFileNameChars = CCGICATCH_DEFAULT_STDENV_FILENAME,
     const char* stdInFileNameChars = CCGICATCH_DEFAULT_STDIN_FILENAME,
     const char* stdOutFileNameChars = CCGICATCH_DEFAULT_STDOUT_FILENAME)
    : m_oldCgiMain(GetTheCgiMain()),
      m_cgiNameChars(cgiNameChars),
      m_contentTypeChars(contentTypeChars),
      m_outputContentTypeChars(0),
      m_stdArgFileNameChars(stdArgFileNameChars),
      m_stdEnvFileNameChars(stdEnvFileNameChars),
      m_stdInFileNameChars(stdInFileNameChars),
      m_stdOutFileNameChars(stdOutFileNameChars),
      m_getCgiEnvValue(0)
    {
        SetTheCgiMain(this);
    }
    ///////////////////////////////////////////////////////////////////////
    //  Destructor: ~cCgiMain
    //
    //      Author: $author$
    //        Date: 11/21/2012
    ///////////////////////////////////////////////////////////////////////
    virtual ~cCgiMain()
    {
        if ((this == (GetTheCgiMain())))
            SetTheCgiMain(m_oldCgiMain);
    }

    ///////////////////////////////////////////////////////////////////////
    //  Function: RunCgi
    //
    //    Author: $author$
    //      Date: 11/20/2012
    ///////////////////////////////////////////////////////////////////////
    virtual int RunCgi
    (int argc, char** argv, char** env)
    {
        int err = 0;
        OutputContentL(B_, m_cgiNameChars, _B, 0);
        return err;
    }
    ///////////////////////////////////////////////////////////////////////
    //  Function: CgiRun
    //
    //    Author: $author$
    //      Date: 11/20/2012
    ///////////////////////////////////////////////////////////////////////
    virtual int CgiRun
    (int argc, char** argv, char** env)
    {
        int err = 0;
        const char* name;
        const char* value;

        m_httpFormFields.Init();

        if ((value = GetCgiEnvValue(e_CGI_ENV_QUERY_STRING)))
        {
            cString string(value);
            cStringStream stream(string, -1);
            cHttpUrlEncodedCharStream uecs(&stream);
            cHttpFormFieldsCharStream cs(*this);
            cs.Read(&uecs, true);
        }

        if ((value = GetCgiEnvValue(e_CGI_ENV_REQUEST_METHOD)))
        if ((name = c_http_request_method_post_name))
        if (!(cChars::Compare(name, value)))
        if ((value = GetCgiEnvValue(e_CGI_ENV_CONTENT_TYPE)))
        if ((name = c_http_content_type_urlencoded_form_data_name))
        if (!(cChars::Compare(name, value)))
        {
            ssize_t contentLength = -1;

            if ((value = GetCgiEnvValue(e_CGI_ENV_CONTENT_LENGTH)))
                contentLength = cChars::ToUInt(value);

            if ((m_stdIn.SetBinaryMode())) 
            {
                cHttpUrlEncodedCharStream uecs(&m_stdIn, contentLength);
                cHttpFormFieldsCharStream cs(*this);
                cs.Read(&uecs);
            }
        }

        err = RunCgi(argc, argv, env);

        m_httpFormFields.Finish();
        return err;
    }
    ///////////////////////////////////////////////////////////////////////
    //  Function: ConsoleRun
    //
    //    Author: $author$
    //      Date: 11/25/2012
    ///////////////////////////////////////////////////////////////////////
    virtual int ConsoleRun
    (int argc, char** argv, char** env)
    {
        int err = 0;
        const char* name;
        const char* value;
        eError error;
        cCharFile file;

        m_consoleCgiEnv.Init();
        if (!(error = file.Open(m_stdEnvFileNameChars, "rb"))) 
        {
            cCgiEnvCharStream cs(*this);
            cs.Read(&file);
            file.Close();
        }
        m_getCgiEnvValue = &cDerives::ConsoleGetCgiEnvValue;

        m_httpFormFields.Init();

        if ((value = GetCgiEnvValue(e_CGI_ENV_QUERY_STRING)))
        {
            cString string(value);
            cStringStream stream(string, -1);
            cHttpUrlEncodedCharStream uecs(&stream);
            cHttpFormFieldsCharStream cs(*this);
            cs.Read(&uecs, true);
        }

        if ((value = GetCgiEnvValue(e_CGI_ENV_REQUEST_METHOD)))
        if ((name = c_http_request_method_post_name))
        if (!(cChars::Compare(name, value)))
        if ((value = GetCgiEnvValue(e_CGI_ENV_CONTENT_TYPE)))
        if ((name = c_http_content_type_urlencoded_form_data_name))
        if (!(cChars::Compare(name, value)))
        {
            ssize_t contentLength = -1;

            if ((value = GetCgiEnvValue(e_CGI_ENV_CONTENT_LENGTH)))
                contentLength = cChars::ToUInt(value);

            if (!(error = file.Open(m_stdInFileNameChars, "rb"))) 
            {
                cHttpUrlEncodedCharStream uecs(&file, contentLength);
                cHttpFormFieldsCharStream cs(*this);

                if (!(error = cs.ReadLine(&file)))
                    cs.Read(&uecs);
                file.Close();
            }
        }

        err = RunCgi(argc, argv, env);

        m_httpFormFields.Finish();
        m_consoleCgiEnv.Finish();
        return err;
    }
    ///////////////////////////////////////////////////////////////////////
    //  Function: ConsoleGetCgiEnvValue
    //
    //    Author: $author$
    //      Date: 11/21/2012
    ///////////////////////////////////////////////////////////////////////
    virtual const char* ConsoleGetCgiEnvValue(eCgiEnv env) const
    {
        const char* chars = m_consoleCgiEnv.Get(env);
        return chars;
    }

    ///////////////////////////////////////////////////////////////////////
    //  Function: Run
    //
    //    Author: $author$
    //      Date: 11/20/2012
    ///////////////////////////////////////////////////////////////////////
    virtual int Run
    (int argc, char** argv, char** env)
    {
        int err = 0;
        const char* name;

        if ((name = c_cgi_env_get_name(e_CGI_ENV_GATEWAY_INTERFACE)))
        if ((name = getenv(name)))
        if ((name[0]))
            return err = CgiRun(argc, argv, env);

        err = ConsoleRun(argc, argv, env);
        return err;
    }
    ///////////////////////////////////////////////////////////////////////
    //  Function: TheMain
    //
    //    Author: $author$
    //      Date: 11/21/2012
    ///////////////////////////////////////////////////////////////////////
    static int TheMain
    (int argc, char** argv, char** env)
    {
        int err = 0;
        cCgiMain* theCgiMain = 0;

        if ((theCgiMain = GetTheCgiMain())) 
        {
            cStreamInterface* old_DEBUG_OUT = c_DEBUG_GET_OUT();

            c_DEBUG_SET_OUT(theCgiMain);
            err = theCgiMain->Main(argc, argv, env);
            c_DEBUG_SET_OUT(old_DEBUG_OUT);
        }
        return err;
    }

    // cCgiEnvCharStreamEvents implementation
    // ...
    ///////////////////////////////////////////////////////////////////////
    //  Function: OnReadCgiEnvInit
    //
    //    Author: $author$
    //      Date: 11/24/2012
    ///////////////////////////////////////////////////////////////////////
    virtual eError OnReadCgiEnvInit()
    {
        eError error = e_ERROR_NONE;
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    //  Function: OnReadCgiEnvFinal
    //
    //    Author: $author$
    //      Date: 11/24/2012
    ///////////////////////////////////////////////////////////////////////
    virtual eError OnReadCgiEnvFinal()
    {
        eError error = e_ERROR_NONE;
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    //  Function: OnReadCgiEnv
    //
    //    Author: $author$
    //      Date: 11/24/2012
    ///////////////////////////////////////////////////////////////////////
    virtual eError OnReadCgiEnv
    (const cString& name, const cString& value)
    {
        eError error = e_ERROR_NONE;
        m_consoleCgiEnv.Set(name, value.c_str());
        return error;
    }
    // ...
    // cCgiEnvCharStreamEvents implementation

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
        m_httpFormFields.Add(name, value, isFromQueryString);
        return error;
    }
    // ...
    // cHttpFormFieldsCharStreamEvents implementation

    ///////////////////////////////////////////////////////////////////////
    //  Function: OutputContentFormatted
    //
    //    Author: $author$
    //      Date: 11/20/2012
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t OutputContentFormatted
    (const char* chars, ...)
    {
        ssize_t count = 0;
        va_list va;
        va_start(va, chars);
        count = OutputContentFormattedV(chars, va);
        va_end(va);
        return count;
    }
    ///////////////////////////////////////////////////////////////////////
    //  Function: OutputContentFormattedV
    //
    //    Author: $author$
    //      Date: 11/20/2012
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t OutputContentFormattedV
    (const char* chars, va_list va)
    {
        ssize_t count = 0;
        ssize_t count2;

        if (!m_outputContentTypeChars)
        if (0 >= (count = OutputContentType()))
            return count;

        if (chars)
        if (0 > (count2 = OutFormattedV(chars, va)))
            count = count2;
        else count += count2;

        return count;
    }
    ///////////////////////////////////////////////////////////////////////
    //  Function: OutputContentL
    //
    //    Author: $author$
    //      Date: 11/20/2012
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t OutputContentL
    (const char* chars, ...)
    {
        ssize_t count = 0;
        va_list va;
        va_start(va, chars);
        count = OutputContentV(chars, va);
        va_end(va);
        return count;
    }
    ///////////////////////////////////////////////////////////////////////
    //  Function: OutputContentV
    //
    //    Author: $author$
    //      Date: 11/20/2012
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t OutputContentV
    (const char* chars, va_list va)
    {
        ssize_t count = 0;
        ssize_t count2;

        if (0 > (count = OutputContent(chars)))
            return count;

        if (0 > (count2 = VOutputContent(va)))
            return count2;

        count += count2;
        return count;
    }
    ///////////////////////////////////////////////////////////////////////
    //  Function: VOutputContent
    //
    //    Author: $author$
    //      Date: 11/20/2012
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t VOutputContent
    (va_list va, ssize_t vaLength = -1)
    {
        ssize_t count = 0;
        ssize_t count2;

        const char* chars;
        
        if (0 > vaLength)
        {
            while (0 != (chars = va_arg(va, const char*)))
            {
                if (0 > (count2 = OutputContent(chars)))
                {
                    count = count2;
                    break;
                }
                count += count2;
            }
        }
        else 
        {
            while (0 < vaLength--)
            {
                if (0 != (chars = va_arg(va, const char*)))
                if (0 > (count2 = OutputContent(chars)))
                    count = count2;
                else
                {
                    count += count2;
                    continue;
                }
                break;
            }
        }
        return count;
    }
    ///////////////////////////////////////////////////////////////////////
    //  Function: OutputContent
    //
    //    Author: $author$
    //      Date: 11/20/2012
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t OutputContent
    (const char* chars, ssize_t length=-1)
    {
        ssize_t count = 0;
        ssize_t count2;

        if (0 > (count = OutputContentType()))
            return count;

        if (0 > (count2 = Output(chars, length)))
            return count2;

        count += count2;
        return count;
    }
    ///////////////////////////////////////////////////////////////////////
    //  Function: OutputContentType
    //
    //    Author: $author$
    //      Date: 11/20/2012
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t OutputContentType
    (const char* chars=0, ssize_t length=-1)
    {
        ssize_t count = 0;
        ssize_t count2;

        if (m_outputContentTypeChars)
            return 0;

        if (chars)
        {
            if (chars != m_contentTypeChars)
                SetContentType(chars, length);
        }
        else
        if (!(chars = GetContentType()))
            SetContentType(CCGIMAIN_DEFAULT_CONTENT_TYPE_NAME);

        if (m_contentTypeChars)
        if (m_contentTypeChars[0])
        if (0 < (count = Output(c_http_content_type_field_name)))
        {
            if (0 >= (count2 = Output(c_http_field_separator)))
                return count2;
            count += count2;
            if (0 >= (count = Output(m_contentTypeChars)))
                return count2;
            count += count2;
            if (0 >= (count = Output(c_http_newline)))
                return count2;
            count += count2;
            if (0 >= (count = Output(c_http_newline)))
                return count2;
            count += count2;
            m_outputContentTypeChars = m_contentTypeChars;
        }
        return count;
    }
    ///////////////////////////////////////////////////////////////////////
    //  Function: Output
    //
    //    Author: $author$
    //      Date: 11/20/2012
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t Output
    (const char* chars, ssize_t length=-1)
    {
        ssize_t count = Out(chars, length);
        return count;
    }
    // cCharStreamInterface implementation
    // ...
    ///////////////////////////////////////////////////////////////////////
    //  Function: Write
    //
    //    Author: $author$
    //      Date: 11/20/2012
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t Write
    (const char* chars, ssize_t length=-1)
    {
        ssize_t count = OutputContent(chars, length);
        return count;
    }
    // ...
    // cCharStreamInterface implementation

    ///////////////////////////////////////////////////////////////////////
    //  Function: SetContentType
    //
    //    Author: $author$
    //      Date: 11/20/2012
    ///////////////////////////////////////////////////////////////////////
    virtual const char* SetContentType
    (const char* chars=0, ssize_t length=-1)
    {
        if (!(chars)) {
            chars = CCGIMAIN_DEFAULT_CONTENT_TYPE_NAME;
            length = -1;
        }
        if (0 < (m_contentType.Assign(chars, length)))
        if ((chars = m_contentType.Chars()))
            m_contentTypeChars = chars;
        return m_contentTypeChars;
    }
    ///////////////////////////////////////////////////////////////////////
    //  Function: GetContentType
    //
    //    Author: $author$
    //      Date: 11/20/2012
    ///////////////////////////////////////////////////////////////////////
    virtual const char* GetContentType() const
    {
        return m_contentTypeChars;
    }

    ///////////////////////////////////////////////////////////////////////
    //  Function: SetContentTypeText
    //
    //    Author: $author$
    //      Date: 11/21/2012
    ///////////////////////////////////////////////////////////////////////
    virtual const char* SetContentTypeText()
    {
        return m_contentTypeChars = c_http_content_type_text_name;
    }
    ///////////////////////////////////////////////////////////////////////
    //  Function: GetContentTypeText
    //
    //    Author: $author$
    //      Date: 11/21/2012
    ///////////////////////////////////////////////////////////////////////
    virtual const char* GetContentTypeText() const
    {
        return c_http_content_type_text_name;
    }
    ///////////////////////////////////////////////////////////////////////
    //  Function: SetContentTypeHtml
    //
    //    Author: $author$
    //      Date: 11/21/2012
    ///////////////////////////////////////////////////////////////////////
    virtual const char* SetContentTypeHtml()
    {
        return m_contentTypeChars = c_http_content_type_html_name;
    }
    ///////////////////////////////////////////////////////////////////////
    //  Function: GetContentTypeHtml
    //
    //    Author: $author$
    //      Date: 11/21/2012
    ///////////////////////////////////////////////////////////////////////
    virtual const char* GetContentTypeHtml() const
    {
        return c_http_content_type_html_name;
    }
    ///////////////////////////////////////////////////////////////////////
    //  Function: SetContentTypeXml
    //
    //    Author: $author$
    //      Date: 11/21/2012
    ///////////////////////////////////////////////////////////////////////
    virtual const char* SetContentTypeXml()
    {
        return m_contentTypeChars = c_http_content_type_xml_name;
    }
    ///////////////////////////////////////////////////////////////////////
    //  Function: GetContentTypeXml
    //
    //    Author: $author$
    //      Date: 11/21/2012
    ///////////////////////////////////////////////////////////////////////
    virtual const char* GetContentTypeXml() const
    {
        return c_http_content_type_xml_name;
    }

    ///////////////////////////////////////////////////////////////////////
    //  Function: GetRequestMethodName
    //
    //    Author: $author$
    //      Date: 11/21/2012
    ///////////////////////////////////////////////////////////////////////
    virtual const char* GetRequestMethodName(eHttpRequestMethod method) const
    {
        const char* chars = 0;
        if ((method >= e_FIRST_HTTP_REQUEST_METHOD) 
            && (method <= e_LAST_HTTP_REQUEST_METHOD))
            chars = c_http_request_method_name[method-e_FIRST_HTTP_REQUEST_METHOD];
        return chars;
    }

    ///////////////////////////////////////////////////////////////////////
    //  Function: GetCgiContentType
    //
    //    Author: $author$
    //      Date: 11/23/2012
    ///////////////////////////////////////////////////////////////////////
    virtual eHttpContentType GetCgiContentType() const
    {
        eHttpContentType type;
        const char* value;
        const char* chars;
        int unequal;
        if ((value = GetCgiEnvValue(e_CGI_ENV_CONTENT_TYPE)))
        for (type = e_FIRST_HTTP_CONTENT_TYPE; 
             type <= e_LAST_HTTP_CONTENT_TYPE; type++) 
        {
            if ((chars = c_http_content_type_name[type-e_FIRST_HTTP_CONTENT_TYPE]))
            if (!(unequal = (cChars::Compare(value, chars))))
                return type;
        }
        return e_HTTP_CONTENT_TYPE_NONE;
    }
    ///////////////////////////////////////////////////////////////////////
    //  Function: GetCgiRequestMethod
    //
    //    Author: $author$
    //      Date: 11/23/2012
    ///////////////////////////////////////////////////////////////////////
    virtual eHttpRequestMethod GetCgiRequestMethod() const
    {
        eHttpRequestMethod method;
        const char* value;
        const char* chars;
        int unequal;
        if ((value = GetCgiEnvValue(e_CGI_ENV_REQUEST_METHOD)))
        for (method = e_FIRST_HTTP_REQUEST_METHOD; 
             method <= e_LAST_HTTP_REQUEST_METHOD; method++) 
        {
            if ((chars = c_http_request_method_name[method-e_FIRST_HTTP_REQUEST_METHOD]))
            if (!(unequal = (cChars::Compare(value, chars))))
                return method;
        }
        return e_HTTP_REQUEST_METHOD_NONE;
    }

    ///////////////////////////////////////////////////////////////////////
    //  Function: SetCgiEnvValue
    //
    //    Author: $author$
    //      Date: 11/23/2012
    ///////////////////////////////////////////////////////////////////////
    virtual const char* SetCgiEnvValue
    (eCgiEnv e, const char* toChars, 
     ssize_t length=-1, bool overwrite=true)
    {
        const char* chars = 0;
        const char* nameChars;
        if ((e >= e_FIRST_CGI_ENV) && (e <= e_LAST_CGI_ENV))
        if ((nameChars = GetCgiEnvName(e)))
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
        return chars;
    }
    ///////////////////////////////////////////////////////////////////////
    //  Function: GetCgiEnvValue
    //
    //    Author: $author$
    //      Date: 11/21/2012
    ///////////////////////////////////////////////////////////////////////
    virtual const char* GetCgiEnvValue(eCgiEnv env) const
    {
        const char* chars = 0;
        const char* name;
        if ((m_getCgiEnvValue))
            chars = (this->*m_getCgiEnvValue)(env);
        else
        if ((env >= e_FIRST_CGI_ENV) && (env <= e_LAST_CGI_ENV))
        if ((name = (GetCgiEnvName(env))))
            chars = getenv(name);
        return chars;
    }
    ///////////////////////////////////////////////////////////////////////
    //  Function: GetCgiEnvName
    //
    //    Author: $author$
    //      Date: 11/21/2012
    ///////////////////////////////////////////////////////////////////////
    virtual const char* GetCgiEnvName(eCgiEnv env) const
    {
        const char* chars = 0;
        if ((env >= e_FIRST_CGI_ENV) && (env <= e_LAST_CGI_ENV))
            chars = c_cgi_env_name[env-e_FIRST_CGI_ENV];
        return chars;
    }

    ///////////////////////////////////////////////////////////////////////
    //  Function: SetTheCgiMain
    //
    //    Author: $author$
    //      Date: 11/21/2012
    ///////////////////////////////////////////////////////////////////////
    static cCgiMain* SetTheCgiMain(cCgiMain* theCgiMain);
    ///////////////////////////////////////////////////////////////////////
    //  Function: GetTheCgiMain
    //
    //    Author: $author$
    //      Date: 11/21/2012
    ///////////////////////////////////////////////////////////////////////
    static cCgiMain* GetTheCgiMain();
};

#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#endif // _CCGIMAIN_HPP 
