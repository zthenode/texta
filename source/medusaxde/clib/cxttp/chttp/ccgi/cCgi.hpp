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
//   File: cCgi.hpp
//
// Author: $author$
//   Date: 6/23/2011
///////////////////////////////////////////////////////////////////////
#if !defined(_CCGI_HPP) || defined(CCGI_MEMBERS_ONLY)
#if !defined(_CCGI_HPP) && !defined(CCGI_MEMBERS_ONLY)
#define _CCGI_HPP
#endif // !defined(_CCGI_HPP) && !defined(CCGI_MEMBERS_ONLY) 

#if !defined(CCGI_MEMBERS_ONLY)
#include "cCgiInterface.hpp"
#include "cInstanceBase.hpp"
#include "cDebug.hpp"

#define CCGI_NAME "cCgi"
#define CCGI_CONTENT_TYPE_XML "text/xml"
#define CCGI_CONTENT_TYPE_HTML "text/html"
#define CCGI_CONTENT_TYPE_TEXT "text/text"
#define CCGI_DEBUG_LEVELS_PARAM "debug-levels"

#define CCGI_CONTENT_TYPE_FIELD_NAME "content_type"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

///////////////////////////////////////////////////////////////////////
// Typedef: cCgiExtend
//
//  Author: $author$
//    Date: 6/23/2011
///////////////////////////////////////////////////////////////////////
typedef cInstanceBase
cCgiExtend;
///////////////////////////////////////////////////////////////////////
//  Class: cCgi
//
// Author: $author$
//   Date: 6/23/2011
///////////////////////////////////////////////////////////////////////
class c_INSTANCE_CLASS cCgi
: virtual public cCgiImplement,
  public cCgiExtend
{
public:
    typedef cCgiImplement cImplements;
    typedef cCgiExtend cExtends;

    //static cCgiInterface* m_theCgi;
    cCgiInterface* m_theOldCgi;

    cCgiContentStreamInterface* m_contentOutput;
    cCgiContentStreamInterface* m_oldContentOutput;
    cHttpFormFieldsInterface* m_formFields;
    cHttpFormFieldsInterface* m_oldFormFields;
    cHttpRequestInterface* m_request;
    cHttpRequestInterface* m_oldRequest;
    cCgiEnvInterface* m_env;
    cCgiEnvInterface* m_oldEnv;

    cString m_name;
    cString m_contentTypeXml;
    cString m_contentTypeHtml;
    cString m_contentTypeText;
    cString m_debugLevelsParam;

    cStreamInterface* m_oldDebugOut;

    ///////////////////////////////////////////////////////////////////////
    //  Constructor: cCgi
    //
    //       Author: $author$
    //         Date: 6/23/2011
    ///////////////////////////////////////////////////////////////////////
    cCgi
    (const char* name, 
     cCgiContentStreamInterface* contentOutput=0,
     cHttpFormFieldsInterface* formFields=0,
     cHttpRequestInterface* request=0,
     cCgiEnvInterface* env=0)
    : m_theOldCgi(GetTheCgi()),
      m_contentOutput(contentOutput),
      m_oldContentOutput(contentOutput),
      m_formFields(formFields),
      m_oldFormFields(formFields),
      m_request(request),
      m_oldRequest(request),
      m_env(env),
      m_oldEnv(env),
      m_name(CCGI_NAME),
      m_contentTypeXml(CCGI_CONTENT_TYPE_XML),
      m_contentTypeHtml(CCGI_CONTENT_TYPE_HTML),
      m_contentTypeText(CCGI_CONTENT_TYPE_TEXT),
      m_debugLevelsParam(CCGI_DEBUG_LEVELS_PARAM),
      m_oldDebugOut(c_DEBUG_GET_OUT())
    {
        SetTheCgi(this);

        if ((name))
            m_name.Assign(name);
    }
    ///////////////////////////////////////////////////////////////////////
    //  Constructor: cCgi
    //
    //       Author: $author$
    //         Date: 6/23/2011
    ///////////////////////////////////////////////////////////////////////
    cCgi
    (cCgiContentStreamInterface* contentOutput=0,
     cHttpFormFieldsInterface* formFields=0,
     cCgiEnvInterface* env=0)
    : m_theOldCgi(GetTheCgi()),
      m_contentOutput(contentOutput),
      m_oldContentOutput(contentOutput),
      m_formFields(formFields),
      m_oldFormFields(formFields),
      m_env(env),
      m_oldEnv(env),
      m_name(CCGI_NAME),
      m_contentTypeXml(CCGI_CONTENT_TYPE_XML),
      m_contentTypeHtml(CCGI_CONTENT_TYPE_HTML),
      m_contentTypeText(CCGI_CONTENT_TYPE_TEXT),
      m_debugLevelsParam(CCGI_DEBUG_LEVELS_PARAM),
      m_oldDebugOut(c_DEBUG_GET_OUT())
    {
        SetTheCgi(this);
    }
    ///////////////////////////////////////////////////////////////////////
    //  Destructor: ~cCgi
    //
    //      Author: $author$
    //        Date: 6/23/2011
    ///////////////////////////////////////////////////////////////////////
    virtual ~cCgi()
    {
        eError error;

        if (this == GetTheCgi())
            SetTheCgi(m_theOldCgi);

        if ((error = Finish()))
            throw (error);
    }
#else // !defined(CCGI_MEMBERS_ONLY) 
#endif // !defined(CCGI_MEMBERS_ONLY) 

    ///////////////////////////////////////////////////////////////////////
    //  Function: Init
    //
    //    Author: $author$
    //      Date: 6/29/2011
    ///////////////////////////////////////////////////////////////////////
    virtual eError Init
    (cCgiContentStreamInterface* contentOutput=0,
     cHttpFormFieldsInterface* formFields=0,
     cCgiEnvInterface* env=0)
#if defined(CCGI_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CCGI_MEMBER_FUNCS_INTERFACE) 
    {
        eError error = e_ERROR_NONE;
#if !defined(CCGI_MEMBER_FUNCS_IMPLEMENT)
        error = Init(contentOutput, formFields, 0, env);
#else // !defined(CCGI_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CCGI_MEMBER_FUNCS_IMPLEMENT) 
        return error;
    }
#endif // defined(CCGI_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    //  Function: Init
    //
    //    Author: $author$
    //      Date: 6/29/2011
    ///////////////////////////////////////////////////////////////////////
    virtual eError Init
    (cCgiContentStreamInterface* contentOutput,
     cHttpFormFieldsInterface* formFields,
     cHttpRequestInterface* request,
     cCgiEnvInterface* env=0)
#if defined(CCGI_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CCGI_MEMBER_FUNCS_INTERFACE) 
    {
        eError error = e_ERROR_NONE;
#if !defined(CCGI_MEMBER_FUNCS_IMPLEMENT)
        if ((contentOutput))
        {
            m_oldDebugOut = c_DEBUG_GET_OUT();
            c_DEBUG_SET_OUT(contentOutput);
            m_contentOutput = contentOutput;
        }

        if ((formFields))
            m_formFields = formFields;

        if ((request))
            m_request = request;

        if ((env))
            m_env = env;
#else // !defined(CCGI_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CCGI_MEMBER_FUNCS_IMPLEMENT) 
        return error;
    }
#endif // defined(CCGI_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    //  Function: Finish
    //
    //    Author: $author$
    //      Date: 6/29/2011
    ///////////////////////////////////////////////////////////////////////
    virtual eError Finish()
#if defined(CCGI_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CCGI_MEMBER_FUNCS_INTERFACE) 
    {
        eError error = e_ERROR_NONE;
#if !defined(CCGI_MEMBER_FUNCS_IMPLEMENT)
        m_env = m_oldEnv;
        m_request = m_oldRequest;
        m_formFields = m_oldFormFields;
        m_contentOutput = m_oldContentOutput;
        c_DEBUG_SET_OUT(m_oldDebugOut);
#else // !defined(CCGI_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CCGI_MEMBER_FUNCS_IMPLEMENT) 
        return error;
    }
#endif // defined(CCGI_MEMBER_FUNCS_INTERFACE) 

    ///////////////////////////////////////////////////////////////////////
    //  Function: RunRequest
    //
    //    Author: $author$
    //      Date: 10/27/2011
    ///////////////////////////////////////////////////////////////////////
    virtual int RunRequest
    (int argc,
     char** argv,
     char** env,
     eHttpRequestMethod method)
#if defined(CCGI_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CCGI_MEMBER_FUNCS_INTERFACE) 
    {
        int err = 0;
#if !defined(CCGI_MEMBER_FUNCS_IMPLEMENT)
#else // !defined(CCGI_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CCGI_MEMBER_FUNCS_IMPLEMENT) 
        return err;
    }
#endif // defined(CCGI_MEMBER_FUNCS_INTERFACE) 

    ///////////////////////////////////////////////////////////////////////
    //  Function: RunGet
    //
    //    Author: $author$
    //      Date: 10/27/2011
    ///////////////////////////////////////////////////////////////////////
    virtual int RunGet
    (int argc,
     char** argv,
     char** env)
#if defined(CCGI_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CCGI_MEMBER_FUNCS_INTERFACE) 
    {
        int err = 0;
#if !defined(CCGI_MEMBER_FUNCS_IMPLEMENT)
        err = RunRequest(argc, argv, env, e_HTTP_REQUEST_METHOD_GET);
#else // !defined(CCGI_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CCGI_MEMBER_FUNCS_IMPLEMENT) 
        return err;
    }
#endif // defined(CCGI_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    //  Function: RunPost
    //
    //    Author: $author$
    //      Date: 10/27/2011
    ///////////////////////////////////////////////////////////////////////
    virtual int RunPost
    (int argc,
     char** argv,
     char** env)
#if defined(CCGI_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CCGI_MEMBER_FUNCS_INTERFACE) 
    {
        int err = 0;
#if !defined(CCGI_MEMBER_FUNCS_IMPLEMENT)
        err = RunRequest(argc, argv, env, e_HTTP_REQUEST_METHOD_POST);
#else // !defined(CCGI_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CCGI_MEMBER_FUNCS_IMPLEMENT) 
        return err;
    }
#endif // defined(CCGI_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    //  Function: RunPut
    //
    //    Author: $author$
    //      Date: 10/27/2011
    ///////////////////////////////////////////////////////////////////////
    virtual int RunPut
    (int argc,
     char** argv,
     char** env)
#if defined(CCGI_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CCGI_MEMBER_FUNCS_INTERFACE) 
    {
        int err = 0;
#if !defined(CCGI_MEMBER_FUNCS_IMPLEMENT)
        err = RunRequest(argc, argv, env, e_HTTP_REQUEST_METHOD_PUT);
#else // !defined(CCGI_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CCGI_MEMBER_FUNCS_IMPLEMENT) 
        return err;
    }
#endif // defined(CCGI_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    //  Function: RunDelete
    //
    //    Author: $author$
    //      Date: 10/27/2011
    ///////////////////////////////////////////////////////////////////////
    virtual int RunDelete
    (int argc,
     char** argv,
     char** env)
#if defined(CCGI_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CCGI_MEMBER_FUNCS_INTERFACE) 
    {
        int err = 0;
#if !defined(CCGI_MEMBER_FUNCS_IMPLEMENT)
        err = RunRequest(argc, argv, env, e_HTTP_REQUEST_METHOD_DELETE);
#else // !defined(CCGI_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CCGI_MEMBER_FUNCS_IMPLEMENT) 
        return err;
    }
#endif // defined(CCGI_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    //  Function: RunTrace
    //
    //    Author: $author$
    //      Date: 10/27/2011
    ///////////////////////////////////////////////////////////////////////
    virtual int RunTrace
    (int argc,
     char** argv,
     char** env)
#if defined(CCGI_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CCGI_MEMBER_FUNCS_INTERFACE) 
    {
        int err = 0;
#if !defined(CCGI_MEMBER_FUNCS_IMPLEMENT)
        err = RunRequest(argc, argv, env, e_HTTP_REQUEST_METHOD_TRACE);
#else // !defined(CCGI_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CCGI_MEMBER_FUNCS_IMPLEMENT) 
        return err;
    }
#endif // defined(CCGI_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    //  Function: RunHead
    //
    //    Author: $author$
    //      Date: 10/27/2011
    ///////////////////////////////////////////////////////////////////////
    virtual int RunHead
    (int argc,
     char** argv,
     char** env)
#if defined(CCGI_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CCGI_MEMBER_FUNCS_INTERFACE) 
    {
        int err = 0;
#if !defined(CCGI_MEMBER_FUNCS_IMPLEMENT)
        err = RunRequest(argc, argv, env, e_HTTP_REQUEST_METHOD_HEAD);
#else // !defined(CCGI_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CCGI_MEMBER_FUNCS_IMPLEMENT) 
        return err;
    }
#endif // defined(CCGI_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    //  Function: RunOptions
    //
    //    Author: $author$
    //      Date: 10/27/2011
    ///////////////////////////////////////////////////////////////////////
    virtual int RunOptions
    (int argc,
     char** argv,
     char** env)
#if defined(CCGI_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CCGI_MEMBER_FUNCS_INTERFACE) 
    {
        int err = 0;
#if !defined(CCGI_MEMBER_FUNCS_IMPLEMENT)
        err = RunRequest(argc, argv, env, e_HTTP_REQUEST_METHOD_OPTIONS);
#else // !defined(CCGI_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CCGI_MEMBER_FUNCS_IMPLEMENT) 
        return err;
    }
#endif // defined(CCGI_MEMBER_FUNCS_INTERFACE) 

    ///////////////////////////////////////////////////////////////////////
    //  Function: RunMethod
    //
    //    Author: $author$
    //      Date: 10/27/2011
    ///////////////////////////////////////////////////////////////////////
    virtual int RunMethod
    (int argc,
     char** argv,
     char** env,
     eHttpRequestMethod method)
#if defined(CCGI_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CCGI_MEMBER_FUNCS_INTERFACE) 
    {
        int err = 0;
#if !defined(CCGI_MEMBER_FUNCS_IMPLEMENT)
        switch (method)
        {
        case e_HTTP_REQUEST_METHOD_GET:
            err = RunGet(argc, argv, env);
            break;
        case e_HTTP_REQUEST_METHOD_POST:
            err = RunPost(argc, argv, env);
            break;
        case e_HTTP_REQUEST_METHOD_PUT:
            err = RunPut(argc, argv, env);
            break;
        case e_HTTP_REQUEST_METHOD_DELETE:
            err = RunDelete(argc, argv, env);
            break;
        case e_HTTP_REQUEST_METHOD_TRACE:
            err = RunTrace(argc, argv, env);
            break;
        case e_HTTP_REQUEST_METHOD_HEAD:
            err = RunHead(argc, argv, env);
            break;
        case e_HTTP_REQUEST_METHOD_OPTIONS:
            err = RunOptions(argc, argv, env);
            break;
        }
#else // !defined(CCGI_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CCGI_MEMBER_FUNCS_IMPLEMENT) 
        return err;
    }
#endif // defined(CCGI_MEMBER_FUNCS_INTERFACE) 

    ///////////////////////////////////////////////////////////////////////
    //  Function: Run
    //
    //    Author: $author$
    //      Date: 6/23/2011
    ///////////////////////////////////////////////////////////////////////
    virtual int Run
    (int argc,
     char** argv,
     char** env)
#if defined(CCGI_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CCGI_MEMBER_FUNCS_INTERFACE) 
    {
        int err = 0;
#if !defined(CCGI_MEMBER_FUNCS_IMPLEMENT)
        eHttpRequestMethod requestMethod = GetHttpRequestMethod();
        err = RunMethod(argc, argv, env, requestMethod);
#else // !defined(CCGI_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CCGI_MEMBER_FUNCS_IMPLEMENT) 
        return err;
    }
#endif // defined(CCGI_MEMBER_FUNCS_INTERFACE) 

    ///////////////////////////////////////////////////////////////////////
    //  Function: BeforeRun
    //
    //    Author: $author$
    //      Date: 6/23/2011
    ///////////////////////////////////////////////////////////////////////
    virtual int BeforeRun
    (int argc,
     char** argv,
     char** env)
#if defined(CCGI_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CCGI_MEMBER_FUNCS_INTERFACE) 
    {
        int err = 0;
#if !defined(CCGI_MEMBER_FUNCS_IMPLEMENT)
#else // !defined(CCGI_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CCGI_MEMBER_FUNCS_IMPLEMENT) 
        return err;
    }
#endif // defined(CCGI_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    //  Function: AfterRun
    //
    //    Author: $author$
    //      Date: 6/23/2011
    ///////////////////////////////////////////////////////////////////////
    virtual int AfterRun
    (int argc,
     char** argv,
     char** env)
#if defined(CCGI_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CCGI_MEMBER_FUNCS_INTERFACE) 
    {
        int err = 0;
#if !defined(CCGI_MEMBER_FUNCS_IMPLEMENT)
#else // !defined(CCGI_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CCGI_MEMBER_FUNCS_IMPLEMENT) 
        return err;
    }
#endif // defined(CCGI_MEMBER_FUNCS_INTERFACE) 

    ///////////////////////////////////////////////////////////////////////
    //  Function: SetDebugLevelsFromForm
    //
    //    Author: $author$
    //      Date: 10/26/2011
    ///////////////////////////////////////////////////////////////////////
    virtual eDebugLevels SetDebugLevelsFromForm
    (bool isFromQueryString=false)
#if defined(CCGI_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CCGI_MEMBER_FUNCS_INTERFACE) 
    {
        eDebugLevels debugLevels = -1;
#if !defined(CCGI_MEMBER_FUNCS_IMPLEMENT)
        if (0 <= (debugLevels = GetDebugLevelsFromForm(isFromQueryString)))
            c_DEBUG_SET_LEVELS(debugLevels);
#else // !defined(CCGI_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CCGI_MEMBER_FUNCS_IMPLEMENT) 
        return debugLevels;
    }
#endif // defined(CCGI_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    //  Function: GetDebugLevelsFromForm
    //
    //    Author: $author$
    //      Date: 10/26/2011
    ///////////////////////////////////////////////////////////////////////
    virtual eDebugLevels GetDebugLevelsFromForm
    (bool isFromQueryString=false) const
#if defined(CCGI_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CCGI_MEMBER_FUNCS_INTERFACE) 
    {
        eDebugLevels debugLevels = -1;
#if !defined(CCGI_MEMBER_FUNCS_IMPLEMENT)
        cHttpFormFieldInterface* formField;
        if ((formField = FindDebugLevelsFormField(isFromQueryString)))
        {
            const cStringInterface& value = formField->GetValue();
            const char* valueChars;
            ssize_t valueLength;
            char c;
            if ((valueChars = value.HasChars(valueLength)))
            switch((c = *valueChars))
            {
            case '0':
                debugLevels = (e_DEBUG_LEVELS_NONE);
                break;
 
            case '1':
            case 'e':
                debugLevels = (e_DEBUG_LEVELS_ERROR);
                break;
 
            case '2':
            case 'w':
                debugLevels = (e_DEBUG_LEVELS_WARNING);
                break;
 
            case '3':
            case 'i':
                debugLevels = (e_DEBUG_LEVELS_INFO);
                break;
 
            case '4':
            case 'f':
                debugLevels = (e_DEBUG_LEVELS_FUNC);
                break;
 
            case '5':
            case 't':
                debugLevels = (e_DEBUG_LEVELS_TRACE);
                break;
 
            default:
                if ((c >= '0') && (c <= '9'))
                    debugLevels = (e_DEBUG_LEVELS_NONE + (c-'0'));
            }
        }
#else // !defined(CCGI_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CCGI_MEMBER_FUNCS_IMPLEMENT) 
        return debugLevels;
    }
#endif // defined(CCGI_MEMBER_FUNCS_INTERFACE) 

    ///////////////////////////////////////////////////////////////////////
    //  Function: FindDebugLevelsFormField
    //
    //    Author: $author$
    //      Date: 10/26/2011
    ///////////////////////////////////////////////////////////////////////
    virtual cHttpFormFieldInterface* FindDebugLevelsFormField
    (bool isFromQueryString=false) const
#if defined(CCGI_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CCGI_MEMBER_FUNCS_INTERFACE) 
    {
        cHttpFormFieldInterface* formField = 0;
#if !defined(CCGI_MEMBER_FUNCS_IMPLEMENT)
        cHttpFormFieldsIterator* atField = 0;
        formField = FindFirstFormField
        (atField, m_debugLevelsParam, isFromQueryString);
#else // !defined(CCGI_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CCGI_MEMBER_FUNCS_IMPLEMENT) 
        return formField;
    }
#endif // defined(CCGI_MEMBER_FUNCS_INTERFACE) 

    ///////////////////////////////////////////////////////////////////////
    //  Function: FindFirstFormField
    //
    //    Author: $author$
    //      Date: 8/9/2011
    ///////////////////////////////////////////////////////////////////////
    virtual cHttpFormFieldInterface* FindFirstFormField
    (cHttpFormFieldsIterator*& atField,
     const cString& named,
     bool isFromQueryString=false) const
#if defined(CCGI_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CCGI_MEMBER_FUNCS_INTERFACE) 
    {
        cHttpFormFieldInterface* formField = 0;
#if !defined(CCGI_MEMBER_FUNCS_IMPLEMENT)
        if ((m_formFields))
            formField = m_formFields->FindFirst
            (atField, named,isFromQueryString);
#else // !defined(CCGI_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CCGI_MEMBER_FUNCS_IMPLEMENT) 
        return formField;
    }
#endif // defined(CCGI_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    //  Function: FindNextFormField
    //
    //    Author: $author$
    //      Date: 8/9/2011
    ///////////////////////////////////////////////////////////////////////
    virtual cHttpFormFieldInterface* FindNextFormField
    (cHttpFormFieldsIterator& atField,
     const cString& named,
     bool isFromQueryString=false) const
#if defined(CCGI_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CCGI_MEMBER_FUNCS_INTERFACE) 
    {
        cHttpFormFieldInterface* formField = 0;
#if !defined(CCGI_MEMBER_FUNCS_IMPLEMENT)
        if ((m_formFields))
            formField = m_formFields->FindNext
            (atField, named,isFromQueryString);
#else // !defined(CCGI_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CCGI_MEMBER_FUNCS_IMPLEMENT) 
        return formField;
    }
#endif // defined(CCGI_MEMBER_FUNCS_INTERFACE) 

    ///////////////////////////////////////////////////////////////////////
    //  Function: FindLastFormField
    //
    //    Author: $author$
    //      Date: 8/9/2011
    ///////////////////////////////////////////////////////////////////////
    virtual cHttpFormFieldInterface* FindLastFormField
    (cHttpFormFieldsIterator*& atField,
     const cString& named,
     bool isFromQueryString=false) const
#if defined(CCGI_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CCGI_MEMBER_FUNCS_INTERFACE) 
    {
        cHttpFormFieldInterface* formField = 0;
#if !defined(CCGI_MEMBER_FUNCS_IMPLEMENT)
        if ((m_formFields))
            formField = m_formFields->FindLast
            (atField, named,isFromQueryString);
#else // !defined(CCGI_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CCGI_MEMBER_FUNCS_IMPLEMENT) 
        return formField;
    }
#endif // defined(CCGI_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    //  Function: FindPrevFormField
    //
    //    Author: $author$
    //      Date: 8/9/2011
    ///////////////////////////////////////////////////////////////////////
    virtual cHttpFormFieldInterface* FindPrevFormField
    (cHttpFormFieldsIterator& atField,
     const cString& named,
     bool isFromQueryString=false) const
#if defined(CCGI_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CCGI_MEMBER_FUNCS_INTERFACE) 
    {
        cHttpFormFieldInterface* formField = 0;
#if !defined(CCGI_MEMBER_FUNCS_IMPLEMENT)
        if ((m_formFields))
            formField = m_formFields->FindPrev
            (atField, named,isFromQueryString);
#else // !defined(CCGI_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CCGI_MEMBER_FUNCS_IMPLEMENT) 
        return formField;
    }
#endif // defined(CCGI_MEMBER_FUNCS_INTERFACE) 

    ///////////////////////////////////////////////////////////////////////
    //  Function: FindFirstFormField
    //
    //    Author: $author$
    //      Date: 6/23/2011
    ///////////////////////////////////////////////////////////////////////
    virtual cHttpFormFieldInterface* FindFirstFormField
    (const cString& named,
     bool isFromQueryString=false) const
#if defined(CCGI_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CCGI_MEMBER_FUNCS_INTERFACE) 
    {
        cHttpFormFieldInterface* formField = 0;
#if !defined(CCGI_MEMBER_FUNCS_IMPLEMENT)
        if ((m_formFields))
            formField = m_formFields->FindFirst(named,isFromQueryString);
#else // !defined(CCGI_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CCGI_MEMBER_FUNCS_IMPLEMENT) 
        return formField;
    }
#endif // defined(CCGI_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    //  Function: FindNextFormField
    //
    //    Author: $author$
    //      Date: 6/23/2011
    ///////////////////////////////////////////////////////////////////////
    virtual cHttpFormFieldInterface* FindNextFormField
    (const cHttpFormFieldInterface& fromFormField,
     const cString& named,
     bool isFromQueryString=false) const
#if defined(CCGI_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CCGI_MEMBER_FUNCS_INTERFACE) 
    {
        cHttpFormFieldInterface* formField = 0;
#if !defined(CCGI_MEMBER_FUNCS_IMPLEMENT)
        if ((m_formFields))
            formField = m_formFields->FindNext
            (fromFormField,named,isFromQueryString);
#else // !defined(CCGI_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CCGI_MEMBER_FUNCS_IMPLEMENT) 
        return formField;
    }
#endif // defined(CCGI_MEMBER_FUNCS_INTERFACE) 

    ///////////////////////////////////////////////////////////////////////
    //  Function: FindLastFormField
    //
    //    Author: $author$
    //      Date: 6/23/2011
    ///////////////////////////////////////////////////////////////////////
    virtual cHttpFormFieldInterface* FindLastFormField
    (const cString& named,
     bool isFromQueryString=false) const
#if defined(CCGI_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CCGI_MEMBER_FUNCS_INTERFACE) 
    {
        cHttpFormFieldInterface* formField = 0;
#if !defined(CCGI_MEMBER_FUNCS_IMPLEMENT)
        if ((m_formFields))
            formField = m_formFields->FindLast(named,isFromQueryString);
#else // !defined(CCGI_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CCGI_MEMBER_FUNCS_IMPLEMENT) 
        return formField;
    }
#endif // defined(CCGI_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    //  Function: FindPrevFormField
    //
    //    Author: $author$
    //      Date: 6/23/2011
    ///////////////////////////////////////////////////////////////////////
    virtual cHttpFormFieldInterface* FindPrevFormField
    (const cHttpFormFieldInterface& fromFormField,
     const cString& named,
     bool isFromQueryString=false) const
#if defined(CCGI_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CCGI_MEMBER_FUNCS_INTERFACE) 
    {
        cHttpFormFieldInterface* formField = 0;
#if !defined(CCGI_MEMBER_FUNCS_IMPLEMENT)
        if ((m_formFields))
            formField = m_formFields->FindPrev
            (fromFormField,named,isFromQueryString);
#else // !defined(CCGI_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CCGI_MEMBER_FUNCS_IMPLEMENT) 
        return formField;
    }
#endif // defined(CCGI_MEMBER_FUNCS_INTERFACE) 

    ///////////////////////////////////////////////////////////////////////
    //  Function: GetFirstFormField
    //
    //    Author: $author$
    //      Date: 7/26/2011
    ///////////////////////////////////////////////////////////////////////
    virtual cHttpFormFieldInterface* GetFirstFormField
    (cHttpFormFieldsIterator*& atField,
     bool isFromQueryString=false) const
#if defined(CCGI_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CCGI_MEMBER_FUNCS_INTERFACE) 
    {
        cHttpFormFieldInterface* formField = 0;
#if !defined(CCGI_MEMBER_FUNCS_IMPLEMENT)
        if ((m_formFields))
            formField = m_formFields->GetFirst(atField,isFromQueryString);
#else // !defined(CCGI_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CCGI_MEMBER_FUNCS_IMPLEMENT) 
        return formField;
    }
#endif // defined(CCGI_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    //  Function: GetNextFormField
    //
    //    Author: $author$
    //      Date: 7/26/2011
    ///////////////////////////////////////////////////////////////////////
    virtual cHttpFormFieldInterface* GetNextFormField
    (cHttpFormFieldsIterator& atField,
     bool isFromQueryString=false) const
#if defined(CCGI_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CCGI_MEMBER_FUNCS_INTERFACE) 
    {
        cHttpFormFieldInterface* formField = 0;
#if !defined(CCGI_MEMBER_FUNCS_IMPLEMENT)
        if ((m_formFields))
            formField = m_formFields->GetNext(atField,isFromQueryString);
#else // !defined(CCGI_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CCGI_MEMBER_FUNCS_IMPLEMENT) 
        return formField;
    }
#endif // defined(CCGI_MEMBER_FUNCS_INTERFACE) 

    ///////////////////////////////////////////////////////////////////////
    //  Function: GetLastFormField
    //
    //    Author: $author$
    //      Date: 7/26/2011
    ///////////////////////////////////////////////////////////////////////
    virtual cHttpFormFieldInterface* GetLastFormField
    (cHttpFormFieldsIterator*& atField,
     bool isFromQueryString=false) const
#if defined(CCGI_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CCGI_MEMBER_FUNCS_INTERFACE) 
    {
        cHttpFormFieldInterface* formField = 0;
#if !defined(CCGI_MEMBER_FUNCS_IMPLEMENT)
        if ((m_formFields))
            formField = m_formFields->GetLast(atField,isFromQueryString);
#else // !defined(CCGI_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CCGI_MEMBER_FUNCS_IMPLEMENT) 
        return formField;
    }
#endif // defined(CCGI_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    //  Function: GetPrevFormField
    //
    //    Author: $author$
    //      Date: 7/26/2011
    ///////////////////////////////////////////////////////////////////////
    virtual cHttpFormFieldInterface* GetPrevFormField
    (cHttpFormFieldsIterator& atField,
     bool isFromQueryString=false) const
#if defined(CCGI_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CCGI_MEMBER_FUNCS_INTERFACE) 
    {
        cHttpFormFieldInterface* formField = 0;
#if !defined(CCGI_MEMBER_FUNCS_IMPLEMENT)
        if ((m_formFields))
            formField = m_formFields->GetPrev(atField,isFromQueryString);
#else // !defined(CCGI_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CCGI_MEMBER_FUNCS_IMPLEMENT) 
        return formField;
    }
#endif // defined(CCGI_MEMBER_FUNCS_INTERFACE) 

    ///////////////////////////////////////////////////////////////////////
    //  Function: GetFirstFormField
    //
    //    Author: $author$
    //      Date: 6/27/2011
    ///////////////////////////////////////////////////////////////////////
    virtual cHttpFormFieldInterface* GetFirstFormField
    (bool isFromQueryString=false) const
#if defined(CCGI_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CCGI_MEMBER_FUNCS_INTERFACE) 
    {
        cHttpFormFieldInterface* formField = 0;
#if !defined(CCGI_MEMBER_FUNCS_IMPLEMENT)
        if ((m_formFields))
            formField = m_formFields->GetFirst(isFromQueryString);
#else // !defined(CCGI_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CCGI_MEMBER_FUNCS_IMPLEMENT) 
        return formField;
    }
#endif // defined(CCGI_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    //  Function: GetNextFormField
    //
    //    Author: $author$
    //      Date: 6/23/2011
    ///////////////////////////////////////////////////////////////////////
    virtual cHttpFormFieldInterface* GetNextFormField
    (const cHttpFormFieldInterface& fromFormField,
     bool isFromQueryString=false) const
#if defined(CCGI_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CCGI_MEMBER_FUNCS_INTERFACE) 
    {
        cHttpFormFieldInterface* formField = 0;
#if !defined(CCGI_MEMBER_FUNCS_IMPLEMENT)
        if ((m_formFields))
            formField = m_formFields->GetNext(fromFormField,isFromQueryString);
#else // !defined(CCGI_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CCGI_MEMBER_FUNCS_IMPLEMENT) 
        return formField;
    }
#endif // defined(CCGI_MEMBER_FUNCS_INTERFACE) 

    ///////////////////////////////////////////////////////////////////////
    //  Function: GetLastFormField
    //
    //    Author: $author$
    //      Date: 6/29/2011
    ///////////////////////////////////////////////////////////////////////
    virtual cHttpFormFieldInterface* GetLastFormField
    (bool isFromQueryString=false) const
#if defined(CCGI_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CCGI_MEMBER_FUNCS_INTERFACE) 
    {
        cHttpFormFieldInterface* formField = 0;
#if !defined(CCGI_MEMBER_FUNCS_IMPLEMENT)
        if ((m_formFields))
            formField = m_formFields->GetLast(isFromQueryString);
#else // !defined(CCGI_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CCGI_MEMBER_FUNCS_IMPLEMENT) 
        return formField;
    }
#endif // defined(CCGI_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    //  Function: GetPrevFormField
    //
    //    Author: $author$
    //      Date: 6/29/2011
    ///////////////////////////////////////////////////////////////////////
    virtual cHttpFormFieldInterface* GetPrevFormField
    (const cHttpFormFieldInterface& fromFormField,
     bool isFromQueryString=false) const
#if defined(CCGI_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CCGI_MEMBER_FUNCS_INTERFACE) 
    {
        cHttpFormFieldInterface* formField = 0;
#if !defined(CCGI_MEMBER_FUNCS_IMPLEMENT)
        if ((m_formFields))
            formField = m_formFields->GetPrev(fromFormField,isFromQueryString);
#else // !defined(CCGI_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CCGI_MEMBER_FUNCS_IMPLEMENT) 
        return formField;
    }
#endif // defined(CCGI_MEMBER_FUNCS_INTERFACE) 

    ///////////////////////////////////////////////////////////////////////
    //  Function: GetHttpRequestMethod
    //
    //    Author: $author$
    //      Date: 10/29/2011
    ///////////////////////////////////////////////////////////////////////
    virtual eHttpRequestMethod GetHttpRequestMethod() const
#if defined(CCGI_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CCGI_MEMBER_FUNCS_INTERFACE) 
    {
        eHttpRequestMethod requestMethod = e_HTTP_REQUEST_METHOD_NONE;
#if !defined(CCGI_MEMBER_FUNCS_IMPLEMENT)
        if ((m_request))
            requestMethod = m_request->GetRequestMethod();
#else // !defined(CCGI_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CCGI_MEMBER_FUNCS_IMPLEMENT) 
        return requestMethod;
    }
#endif // defined(CCGI_MEMBER_FUNCS_INTERFACE) 

    ///////////////////////////////////////////////////////////////////////
    //  Function: SetCgiEnv
    //
    //    Author: $author$
    //      Date: 6/28/2011
    ///////////////////////////////////////////////////////////////////////
    virtual const char* SetCgiEnv
    (eCgiEnv e, const char* toChars, ssize_t length=-1)
#if defined(CCGI_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CCGI_MEMBER_FUNCS_INTERFACE) 
    {
        const char* chars = 0;
#if !defined(CCGI_MEMBER_FUNCS_IMPLEMENT)
        if ((m_env))
        chars = (m_env->Set(e, toChars, length));
#else // !defined(CCGI_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CCGI_MEMBER_FUNCS_IMPLEMENT) 
        return chars;
    }
#endif // defined(CCGI_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    //  Function: GetCgiEnv
    //
    //    Author: $author$
    //      Date: 6/28/2011
    ///////////////////////////////////////////////////////////////////////
    virtual const char* GetCgiEnv
    (eCgiEnv e) const
#if defined(CCGI_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CCGI_MEMBER_FUNCS_INTERFACE) 
    {
        const char* chars = 0;
#if !defined(CCGI_MEMBER_FUNCS_IMPLEMENT)
        if ((m_env))
        chars = (m_env->Get(e));
#else // !defined(CCGI_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CCGI_MEMBER_FUNCS_IMPLEMENT) 
        return chars;
    }
#endif // defined(CCGI_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    //  Function: GetCgiEnvName
    //
    //    Author: $author$
    //      Date: 6/28/2011
    ///////////////////////////////////////////////////////////////////////
    virtual const char* GetCgiEnvName
    (eCgiEnv e) const
#if defined(CCGI_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CCGI_MEMBER_FUNCS_INTERFACE) 
    {
        const char* chars = 0;
#if !defined(CCGI_MEMBER_FUNCS_IMPLEMENT)
        if ((m_env))
        chars = (m_env->GetName(e));
#else // !defined(CCGI_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CCGI_MEMBER_FUNCS_IMPLEMENT) 
        return chars;
    }
#endif // defined(CCGI_MEMBER_FUNCS_INTERFACE) 

    ///////////////////////////////////////////////////////////////////////
    //  Function: GetFirstCgiEnv
    //
    //    Author: $author$
    //      Date: 6/29/2011
    ///////////////////////////////////////////////////////////////////////
    virtual const char* GetFirstCgiEnv
    (eCgiEnv& e, const char*& value) const
#if defined(CCGI_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CCGI_MEMBER_FUNCS_INTERFACE) 
    {
        const char* chars = 0;
#if !defined(CCGI_MEMBER_FUNCS_IMPLEMENT)
        if ((m_env))
        chars = (m_env->GetFirst(e, value));
#else // !defined(CCGI_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CCGI_MEMBER_FUNCS_IMPLEMENT) 
        return chars;
    }
#endif // defined(CCGI_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    //  Function: GetNextCgiEnv
    //
    //    Author: $author$
    //      Date: 6/29/2011
    ///////////////////////////////////////////////////////////////////////
    virtual const char* GetNextCgiEnv
    (eCgiEnv& e, const char*& value) const
#if defined(CCGI_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CCGI_MEMBER_FUNCS_INTERFACE) 
    {
        const char* chars = 0;
#if !defined(CCGI_MEMBER_FUNCS_IMPLEMENT)
        if ((m_env))
        chars = (m_env->GetNext(e, value));
#else // !defined(CCGI_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CCGI_MEMBER_FUNCS_IMPLEMENT) 
        return chars;
    }
#endif // defined(CCGI_MEMBER_FUNCS_INTERFACE) 

    ///////////////////////////////////////////////////////////////////////
    //  Function: GetLastCgiEnv
    //
    //    Author: $author$
    //      Date: 6/29/2011
    ///////////////////////////////////////////////////////////////////////
    virtual const char* GetLastCgiEnv
    (eCgiEnv& e, const char*& value) const
#if defined(CCGI_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CCGI_MEMBER_FUNCS_INTERFACE) 
    {
        const char* chars = 0;
#if !defined(CCGI_MEMBER_FUNCS_IMPLEMENT)
        if ((m_env))
        chars = (m_env->GetLast(e, value));
#else // !defined(CCGI_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CCGI_MEMBER_FUNCS_IMPLEMENT) 
        return chars;
    }
#endif // defined(CCGI_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    //  Function: GetPrevCgiEnv
    //
    //    Author: $author$
    //      Date: 6/29/2011
    ///////////////////////////////////////////////////////////////////////
    virtual const char* GetPrevCgiEnv
    (eCgiEnv& e, const char*& value) const
#if defined(CCGI_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CCGI_MEMBER_FUNCS_INTERFACE) 
    {
        const char* chars = 0;
#if !defined(CCGI_MEMBER_FUNCS_IMPLEMENT)
        if ((m_env))
        chars = (m_env->GetPrev(e, value));
#else // !defined(CCGI_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CCGI_MEMBER_FUNCS_IMPLEMENT) 
        return chars;
    }
#endif // defined(CCGI_MEMBER_FUNCS_INTERFACE) 

    ///////////////////////////////////////////////////////////////////////
    //  Function: OutputContent
    //
    //    Author: $author$
    //      Date: 6/26/2011
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t OutputContent
    (const cString& content)
#if defined(CCGI_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CCGI_MEMBER_FUNCS_INTERFACE) 
    {
        ssize_t count = 0;
#if !defined(CCGI_MEMBER_FUNCS_IMPLEMENT)
        const char* chars;
        ssize_t length;
        if ((chars = content.Chars(length)))
            count = OutputContent(chars, length);
#else // !defined(CCGI_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CCGI_MEMBER_FUNCS_IMPLEMENT) 
        return count;
    }
#endif // defined(CCGI_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    //  Function: OutputContentL
    //
    //    Author: $author$
    //      Date: 11/25/2012
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t OutputContentL
    (const char* chars, ...)
#if defined(CCGI_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CCGI_MEMBER_FUNCS_INTERFACE) 
    {
        ssize_t count = 0;
#if !defined(CCGI_MEMBER_FUNCS_IMPLEMENT)
        va_list va;
        va_start(va, chars);
        count = OutputContentV(chars, va);
        va_end(va);
#else // !defined(CCGI_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CCGI_MEMBER_FUNCS_IMPLEMENT) 
        return count;
    }
#endif // defined(CCGI_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    //  Function: OutputContentV
    //
    //    Author: $author$
    //      Date: 11/25/2012
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t OutputContentV
    (const char* chars, va_list va)
#if defined(CCGI_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CCGI_MEMBER_FUNCS_INTERFACE) 
    {
        ssize_t count = 0;
#if !defined(CCGI_MEMBER_FUNCS_IMPLEMENT)
        ssize_t count2;

        if (0 > (count = OutputContent(chars)))
            return count;

        if (0 > (count2 = VOutputContent(va)))
            return count2;

        count += count2;
#else // !defined(CCGI_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CCGI_MEMBER_FUNCS_IMPLEMENT) 
        return count;
    }
#endif // defined(CCGI_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    //  Function: VOutputContent
    //
    //    Author: $author$
    //      Date: 11/25/2012
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t VOutputContent
    (va_list va, ssize_t vaLength = -1)
#if defined(CCGI_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CCGI_MEMBER_FUNCS_INTERFACE) 
    {
        ssize_t count = 0;
#if !defined(CCGI_MEMBER_FUNCS_IMPLEMENT)
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
#else // !defined(CCGI_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CCGI_MEMBER_FUNCS_IMPLEMENT) 
        return count;
    }
#endif // defined(CCGI_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    //  Function: OutputContent
    //
    //    Author: $author$
    //      Date: 6/26/2011
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t OutputContent
    (const char* chars, ssize_t length=-1)
#if defined(CCGI_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CCGI_MEMBER_FUNCS_INTERFACE) 
    {
        ssize_t count = 0;
#if !defined(CCGI_MEMBER_FUNCS_IMPLEMENT)
        if ((m_contentOutput))
            count = m_contentOutput->Write(chars, length);
#else // !defined(CCGI_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CCGI_MEMBER_FUNCS_IMPLEMENT) 
        return count;
    }
#endif // defined(CCGI_MEMBER_FUNCS_INTERFACE) 

    ///////////////////////////////////////////////////////////////////////
    //  Function: SetContentType
    //
    //    Author: $author$
    //      Date: 6/26/2011
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t SetContentType
    (const cString& contentType)
#if defined(CCGI_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CCGI_MEMBER_FUNCS_INTERFACE) 
    {
        ssize_t count = 0;
#if !defined(CCGI_MEMBER_FUNCS_IMPLEMENT)
        if ((m_contentOutput))
            count = m_contentOutput->SetContentType(contentType);
#else // !defined(CCGI_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CCGI_MEMBER_FUNCS_IMPLEMENT) 
        return count;
    }
#endif // defined(CCGI_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    //  Function: GetContentType
    //
    //    Author: $author$
    //      Date: 11/25/2012
    ///////////////////////////////////////////////////////////////////////
    virtual cString GetContentType() const
#if defined(CCGI_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CCGI_MEMBER_FUNCS_INTERFACE) 
    {
        cString type;
#if !defined(CCGI_MEMBER_FUNCS_IMPLEMENT)
        if ((m_contentOutput))
            type = m_contentOutput->GetContentType();
#else // !defined(CCGI_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CCGI_MEMBER_FUNCS_IMPLEMENT) 
        return type;
    }
#endif // defined(CCGI_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    //  Function: GetContentTypeText
    //
    //    Author: $author$
    //      Date: 11/25/2012
    ///////////////////////////////////////////////////////////////////////
    virtual cString GetContentTypeText() const
#if defined(CCGI_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CCGI_MEMBER_FUNCS_INTERFACE) 
    {
        cString type;
#if !defined(CCGI_MEMBER_FUNCS_IMPLEMENT)
        if ((m_contentOutput))
            type = m_contentOutput->GetContentTypeText();
#else // !defined(CCGI_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CCGI_MEMBER_FUNCS_IMPLEMENT) 
        return type;
    }
#endif // defined(CCGI_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    //  Function: GetContentTypeHtml
    //
    //    Author: $author$
    //      Date: 11/25/2012
    ///////////////////////////////////////////////////////////////////////
    virtual cString GetContentTypeHtml() const
#if defined(CCGI_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CCGI_MEMBER_FUNCS_INTERFACE) 
    {
        cString type;
#if !defined(CCGI_MEMBER_FUNCS_IMPLEMENT)
        if ((m_contentOutput))
            type = m_contentOutput->GetContentTypeHtml();
#else // !defined(CCGI_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CCGI_MEMBER_FUNCS_IMPLEMENT) 
        return type;
    }
#endif // defined(CCGI_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    //  Function: GetContentTypeXml
    //
    //    Author: $author$
    //      Date: 11/25/2012
    ///////////////////////////////////////////////////////////////////////
    virtual cString GetContentTypeXml() const
#if defined(CCGI_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CCGI_MEMBER_FUNCS_INTERFACE) 
    {
        cString type;
#if !defined(CCGI_MEMBER_FUNCS_IMPLEMENT)
        if ((m_contentOutput))
            type = m_contentOutput->GetContentTypeXml();
#else // !defined(CCGI_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CCGI_MEMBER_FUNCS_IMPLEMENT) 
        return type;
    }
#endif // defined(CCGI_MEMBER_FUNCS_INTERFACE) 

    ///////////////////////////////////////////////////////////////////////
    //  Function: SetContentOutput
    //
    //    Author: $author$
    //      Date: 6/26/2011
    ///////////////////////////////////////////////////////////////////////
    virtual cCgiContentStreamInterface* SetContentOutput
    (cCgiContentStreamInterface* contentOutput)
#if defined(CCGI_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CCGI_MEMBER_FUNCS_INTERFACE) 
    {
#if !defined(CCGI_MEMBER_FUNCS_IMPLEMENT)
        m_contentOutput = (contentOutput);
#else // !defined(CCGI_MEMBER_FUNCS_IMPLEMENT) 
        contentOutput = 0;
#endif // !defined(CCGI_MEMBER_FUNCS_IMPLEMENT) 
        return contentOutput;
    }
#endif // defined(CCGI_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    //  Function: GetContentOutput
    //
    //    Author: $author$
    //      Date: 6/26/2011
    ///////////////////////////////////////////////////////////////////////
    virtual cCgiContentStreamInterface* GetContentOutput() const
#if defined(CCGI_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CCGI_MEMBER_FUNCS_INTERFACE) 
    {
        cCgiContentStreamInterface* contentOutput = 0;
#if !defined(CCGI_MEMBER_FUNCS_IMPLEMENT)
        contentOutput = (cCgiContentStreamInterface*)(m_contentOutput);
#else // !defined(CCGI_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CCGI_MEMBER_FUNCS_IMPLEMENT) 
        return contentOutput;
    }
#endif // defined(CCGI_MEMBER_FUNCS_INTERFACE) 

    ///////////////////////////////////////////////////////////////////////
    //  Function: SetFormFields
    //
    //    Author: $author$
    //      Date: 7/22/2011
    ///////////////////////////////////////////////////////////////////////
    virtual cHttpFormFieldsInterface* SetFormFields
    (cHttpFormFieldsInterface* formFields)
#if defined(CCGI_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CCGI_MEMBER_FUNCS_INTERFACE) 
    {
#if !defined(CCGI_MEMBER_FUNCS_IMPLEMENT)
        m_formFields = formFields;
#else // !defined(CCGI_MEMBER_FUNCS_IMPLEMENT) 
        formFields = 0;
#endif // !defined(CCGI_MEMBER_FUNCS_IMPLEMENT) 
        return formFields;
    }
#endif // defined(CCGI_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    //  Function: GetFormFields
    //
    //    Author: $author$
    //      Date: 7/22/2011
    ///////////////////////////////////////////////////////////////////////
    virtual cHttpFormFieldsInterface* GetFormFields() const
#if defined(CCGI_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CCGI_MEMBER_FUNCS_INTERFACE) 
    {
#if !defined(CCGI_MEMBER_FUNCS_IMPLEMENT)
        cHttpFormFieldsInterface* formFields = m_formFields;
#else // !defined(CCGI_MEMBER_FUNCS_IMPLEMENT) 
        cHttpFormFieldsInterface* formFields = 0;
#endif // !defined(CCGI_MEMBER_FUNCS_IMPLEMENT) 
        return formFields;
    }
#endif // defined(CCGI_MEMBER_FUNCS_INTERFACE) 

#if !defined(CCGI_MEMBER_FUNCS_IMPLEMENT)
    ///////////////////////////////////////////////////////////////////////
    //  Function: SetName
    //
    //    Author: $author$
    //      Date: 6/27/2011
    ///////////////////////////////////////////////////////////////////////
    virtual const cString& SetName
    (const cString& toName)
#if defined(CCGI_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CCGI_MEMBER_FUNCS_INTERFACE) 
    {
        m_name = (toName);
        return m_name;
    }
#endif // defined(CCGI_MEMBER_FUNCS_INTERFACE) 
#else // !defined(CCGI_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CCGI_MEMBER_FUNCS_IMPLEMENT) 
#if !defined(CCGI_MEMBER_FUNCS_IMPLEMENT)
    ///////////////////////////////////////////////////////////////////////
    //  Function: GetName
    //
    //    Author: $author$
    //      Date: 6/27/2011
    ///////////////////////////////////////////////////////////////////////
    virtual const cString& GetName() const
#if defined(CCGI_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CCGI_MEMBER_FUNCS_INTERFACE) 
    {
        return m_name;
    }
#endif // defined(CCGI_MEMBER_FUNCS_INTERFACE) 
#else // !defined(CCGI_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CCGI_MEMBER_FUNCS_IMPLEMENT) 

#if defined(CCGI_MEMBER_FUNCS_INTERFACE)
    ///////////////////////////////////////////////////////////////////////
    //  Function: SetTheCgi
    //
    //    Author: $author$
    //      Date: 7/26/2011
    ///////////////////////////////////////////////////////////////////////
    static cCgiInterface* SetTheCgi(cCgiInterface* theCgi);
#else // defined(CCGI_MEMBER_FUNCS_INTERFACE) 
#endif // defined(CCGI_MEMBER_FUNCS_INTERFACE) 
#if defined(CCGI_MEMBER_FUNCS_INTERFACE)
    ///////////////////////////////////////////////////////////////////////
    //  Function: GetTheCgi
    //
    //    Author: $author$
    //      Date: 6/23/2011
    ///////////////////////////////////////////////////////////////////////
    static cCgiInterface* GetTheCgi();
#else // defined(CCGI_MEMBER_FUNCS_INTERFACE) 
#endif // defined(CCGI_MEMBER_FUNCS_INTERFACE) 

#if defined(CCGI_MEMBER_FUNCS_INTERFACE)
    ///////////////////////////////////////////////////////////////////////
    //  Function: TheMain
    //
    //    Author: $author$
    //      Date: 7/26/2011
    ///////////////////////////////////////////////////////////////////////
    static int TheMain
    (int argc,
     char** argv,
     char** env);
#else // defined(CCGI_MEMBER_FUNCS_INTERFACE) 
#endif // defined(CCGI_MEMBER_FUNCS_INTERFACE) 

#if !defined(CCGI_MEMBERS_ONLY)
};

#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#else // !defined(CCGI_MEMBERS_ONLY) 
#endif // !defined(CCGI_MEMBERS_ONLY) 

#endif // !defined(_CCGI_HPP) || defined(CCGI_MEMBERS_ONLY) 
