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
//   File: cHttpServletCgi.hpp
//
// Author: $author$
//   Date: 10/14/2011
///////////////////////////////////////////////////////////////////////
#if !defined(_CHTTPSERVLETCGI_HPP) || defined(CHTTPSERVLETCGI_MEMBERS_ONLY)
#if !defined(_CHTTPSERVLETCGI_HPP) && !defined(CHTTPSERVLETCGI_MEMBERS_ONLY)
#define _CHTTPSERVLETCGI_HPP
#endif // !defined(_CHTTPSERVLETCGI_HPP) && !defined(CHTTPSERVLETCGI_MEMBERS_ONLY) 

#if !defined(CHTTPSERVLETCGI_MEMBERS_ONLY)
#include "cCgi.hpp"
#include "cHttpServletCgiHttpServletRequest.hpp"
#include "cHttpServletCgiHttpServletResponse.hpp"
#include "cHttpServletDLibrary.hpp"
#include "cHttpServletRequest.hpp"
#include "cHttpServletResponse.hpp"
#include "cFilePath.hpp"
#include "cTypes.hpp"
#include "cDebug.hpp"
#include <vector>

#if !defined(CHTTPSERVLETCGI_NAME) 
#define CHTTPSERVLETCGI_NAME \
    "cHttpServletCgi"
#endif // !defined(CHTTPSERVLETCGI_NAME) 

#if !defined(CHTTPSERVLETCGI_LOCATION_PATH_SEPARATOR) 
#define CHTTPSERVLETCGI_LOCATION_PATH_SEPARATOR \
    "/"
#endif // !defined(CHTTPSERVLETCGI_LOCATION_PATH_SEPARATOR) 

#if !defined(CHTTPSERVLETCGI_SERVLET_LOCATION_PATH_SEPARATOR) 
#define CHTTPSERVLETCGI_SERVLET_LOCATION_PATH_SEPARATOR \
    "/servlet/"
#endif // !defined(CHTTPSERVLETCGI_SERVLET_LOCATION_PATH_SEPARATOR) 

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

typedef std::vector<cHttpServletInterface*> cHttpServletInterfaces;
typedef std::vector<cHttpServletDLibrary*> cHttpServletDLibraries;

///////////////////////////////////////////////////////////////////////
// Typedef: cHttpServletCgi
//
//  Author: $author$
//    Date: 10/14/2011
///////////////////////////////////////////////////////////////////////
typedef cCgi
cHttpServletCgiExtend;
///////////////////////////////////////////////////////////////////////
//  Class: cHttpServletCgi
//
// Author: $author$
//   Date: 10/14/2011
///////////////////////////////////////////////////////////////////////
class c_INSTANCE_CLASS cHttpServletCgi
: //virtual public cHttpServletCgiImplement,
  public cHttpServletCgiExtend
{
public:
    //typedef cHttpServletCgiImplement cImplements;
    typedef cHttpServletCgiExtend cExtends;

    cString m_locationPathSeparator;
    cString m_servletLocationPathSeparator;
    cString m_contentType;
    cString m_content;

    cHttpServletDLibraries m_servletDLibraries;
    cString m_servletDLibraryExtensionSeparator;
    cString m_servletDLibraryExtension;
    cString m_servletDLibraryName;
    cString m_servletName;

    cHttpServletInterfaces m_servlets;
    cHttpServletInterface* m_servlet;

    cHttpServletCgiHttpServletRequest m_servletRequest;
    cHttpServletCgiHttpServletResponse m_servletResponse;

    ///////////////////////////////////////////////////////////////////////
    //  Constructor: cHttpServletCgi
    //
    //       Author: $author$
    //         Date: 10/14/2011
    ///////////////////////////////////////////////////////////////////////
    cHttpServletCgi
    (const char* name=CHTTPSERVLETCGI_NAME,
     const char* locationPathSeparator=CHTTPSERVLETCGI_LOCATION_PATH_SEPARATOR,
     const char* servletLocationPathSeparator=CHTTPSERVLETCGI_SERVLET_LOCATION_PATH_SEPARATOR,
     const char* servletDLibraryExtension=PLATFORM_DLIBRARY_EXTENSION,
     const char* servletDLibraryExtensionSeparator=PLATFORM_EXTENSION_SEPARATOR)
    : cExtends(name),
      m_locationPathSeparator(locationPathSeparator),
      m_servletLocationPathSeparator(servletLocationPathSeparator),
      m_servletDLibraryExtension(servletDLibraryExtension),
      m_servletDLibraryExtensionSeparator(servletDLibraryExtensionSeparator),
      m_servlet(0),
      m_servletRequest(*this),
      m_servletResponse(*this)
    {
    }
    ///////////////////////////////////////////////////////////////////////
    //  Destructor: ~cHttpServletCgi
    //
    //      Author: $author$
    //        Date: 10/14/2011
    ///////////////////////////////////////////////////////////////////////
    virtual ~cHttpServletCgi()
    {
    }
#else // !defined(CHTTPSERVLETCGI_MEMBERS_ONLY) 
#endif // !defined(CHTTPSERVLETCGI_MEMBERS_ONLY) 

#if !defined(CHTTPSERVLETCGI_MEMBERS_ONLY)
    ///////////////////////////////////////////////////////////////////////
    //  Function: RunRequest
    //
    //    Author: $author$
    //      Date: 10/14/2011
    ///////////////////////////////////////////////////////////////////////
    virtual int RunRequest
    (int argc,
     char** argv,
     char** env,
     eHttpRequestMethod requestMethod)
    {
        int errn = 0;
        eError error;
        if ((m_servlet))
        if ((error = m_servlet->DoRequest
            (m_servletRequest, m_servletResponse, requestMethod)))
            c_DB_ERROR("() failed on servlet->DoRequest()");
        return errn;
    }
    ///////////////////////////////////////////////////////////////////////
    //  Function: Run
    //
    //    Author: $author$
    //      Date: 10/14/2011
    ///////////////////////////////////////////////////////////////////////
    virtual int Run
    (int argc,
     char** argv,
     char** env)
    {
        int errn = 0;
        const char* contentTypeChars = 0;
        cCgiContentStreamInterface* contentOutput = 0;
        const char* servletDLibraryNameChars = 0;
        const char* servletNameChars = 0;
        cHttpServletDLibrary* servletDLibrary = 0;

        if ((contentTypeChars = m_contentType.HasChars()))
            SetContentType(contentTypeChars);
        else
        SetContentType(m_contentTypeHtml);

        SetDebugLevelsFromForm();

        if ((contentOutput = GetContentOutput()))
        {
            cCharWriterInterface& err = (cCharWriterInterface&)(*m_contentOutput);
            cCharWriterInterface& out = (cCharWriterInterface&)(*m_contentOutput);

            if ((servletNameChars = GetServletNameChars()))
            if ((servletDLibraryNameChars = GetServletDLibraryNameChars(servletNameChars)))
            if ((servletDLibrary = new cHttpServletDLibrary()))
            {
                eError error;

                if (!(error = servletDLibrary->Load(servletDLibraryNameChars)))
                {
                    if ((m_servlet = servletDLibrary->AcquireHttpServlet(error)))
                    {
                        eHttpRequestMethod requestMethod = GetHttpRequestMethod();
                        cWriterInterface* oldWriter = m_servletResponse.DelegateWrite(&out);

                        errn = RunMethod(argc, argv, env, requestMethod);

                        m_servletResponse.DelegateWrite(oldWriter);

                        if ((error = servletDLibrary->ReleaseHttpServlet(m_servlet)))
                            OutputContent("<b>failed to release http servlet<br/></b>");

                        m_servlet = 0;
                    }
                    else
                    OutputContent("<b>failed to acquire http servlet<br/></b>");

                    if ((servletDLibrary))
                        servletDLibrary->Unload();
                }
                else
                OutputContent("<b>failed to load http servlet dlibrary<br/></b>");

                if ((servletDLibrary))
                    delete servletDLibrary;

                return errn;
            }

            m_content = "<b>";
            m_content << m_name;
            m_content << "</b><br/>";
            OutputContent(m_content);
        }
        return errn;
    }
#else // !defined(CHTTPSERVLETCGI_MEMBERS_ONLY) 
#endif // !defined(CHTTPSERVLETCGI_MEMBERS_ONLY) 

    ///////////////////////////////////////////////////////////////////////
    //  Function: GetServletDLibraryNameChars
    //
    //    Author: $author$
    //      Date: 10/15/2011
    ///////////////////////////////////////////////////////////////////////
    virtual const char* GetServletDLibraryNameChars
    (const char* servletNameChars)
#if defined(CHTTPSERVLETCGI_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CHTTPSERVLETCGI_MEMBER_FUNCS_INTERFACE) 
    {
        const char* chars = 0;
#if !defined(CHTTPSERVLETCGI_MEMBER_FUNCS_IMPLEMENT)

        if ((servletNameChars))
        if (0 < (m_servletDLibraryName.Assign(servletNameChars)))
        if (0 <= (m_servletDLibraryName.Append(m_servletDLibraryExtensionSeparator)))
        if (0 <= (m_servletDLibraryName.Append(m_servletDLibraryExtension)))
            chars = m_servletDLibraryName.HasChars();

#else // !defined(CHTTPSERVLETCGI_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CHTTPSERVLETCGI_MEMBER_FUNCS_IMPLEMENT) 
        return chars;
    }
#endif // defined(CHTTPSERVLETCGI_MEMBER_FUNCS_INTERFACE) 

    ///////////////////////////////////////////////////////////////////////
    //  Function: GetServletNameChars
    //
    //    Author: $author$
    //      Date: 10/15/2011
    ///////////////////////////////////////////////////////////////////////
    virtual const char* GetServletNameChars()
#if defined(CHTTPSERVLETCGI_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CHTTPSERVLETCGI_MEMBER_FUNCS_INTERFACE) 
    {
        const char* chars = 0;
#if !defined(CHTTPSERVLETCGI_MEMBER_FUNCS_IMPLEMENT)
        const char* envChars = 0;
        const char* separatorChars = 0;
        const char* servletSeparatorChars = 0;
        const char* foundSeparatorChars = 0;
        ssize_t separatorLength = 0;

        if ((envChars = GetCgiEnv(e_CGI_ENV_PATH_INFO)))
        {
            if ((servletSeparatorChars = m_servletLocationPathSeparator.HasChars(separatorLength)))
            {
                if (!(foundSeparatorChars = cChars::FindFirst(envChars, servletSeparatorChars)))
                if ((separatorChars = m_locationPathSeparator.HasChars(separatorLength)))
                {
                    c_DB_INFO("() failed on cChars::FindFirst(\"" << envChars << "\", \"" << servletSeparatorChars << "\")");
                    if (!(foundSeparatorChars = cChars::FindLast(envChars, separatorChars)))
                        c_DB_ERROR("() failed on cChars::FindLast(\"" << envChars << "\", \"" << separatorChars << "\")");
                }
                else
                c_DB_ERROR("() failed on cChars::FindFirst(\"" << envChars << "\", \"" << servletSeparatorChars << "\")");
            }
            else
            if ((separatorChars = m_locationPathSeparator.HasChars(separatorLength)))
            {
                c_DB_INFO("() failed on m_servletLocationPathSeparator.HasChars()");
                if (!(foundSeparatorChars = cChars::FindLast(envChars, separatorChars)))
                    c_DB_ERROR("() failed on cChars::FindLast(\"" << envChars << "\", \"" << separatorChars << "\")");
            }
            else
            c_DB_ERROR("() failed on m_locationPathSeparator.HasChars()");

            if ((foundSeparatorChars))
            {
                if (((foundSeparatorChars += separatorLength)[0]))
                if (0 < (m_servletName.Assign(foundSeparatorChars)))
                if ((chars = m_servletName.HasChars()))
                {
                    c_DB_TRACE("() servlet name = \"" << chars << "\"");
                    return chars;
                }
            }
        }
        else
        c_DB_ERROR("() failed on GetCgiEnv(e_CGI_ENV_PATH_INFO)");

#else // !defined(CHTTPSERVLETCGI_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CHTTPSERVLETCGI_MEMBER_FUNCS_IMPLEMENT) 
        return chars;
    }
#endif // defined(CHTTPSERVLETCGI_MEMBER_FUNCS_INTERFACE) 

#if !defined(CHTTPSERVLETCGI_MEMBERS_ONLY)
};


#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#else // !defined(CHTTPSERVLETCGI_MEMBERS_ONLY) 
#endif // !defined(CHTTPSERVLETCGI_MEMBERS_ONLY) 

#endif // !defined(_CHTTPSERVLETCGI_HPP) || defined(CHTTPSERVLETCGI_MEMBERS_ONLY) 
