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
//   File: cCgiccMain.hpp
//
// Author: $author$
//   Date: 5/20/2011
///////////////////////////////////////////////////////////////////////
#if !defined(_CCGICCMAIN_HPP) || defined(CCGICCMAIN_MEMBERS_ONLY)
#if !defined(_CCGICCMAIN_HPP) && !defined(CCGICCMAIN_MEMBERS_ONLY)
#define _CCGICCMAIN_HPP
#endif // !defined(_CCGICCMAIN_HPP) && !defined(CCGICCMAIN_MEMBERS_ONLY) 

#if !defined(CCGICCMAIN_MEMBERS_ONLY)
#include "cCgiccMainInterface.hpp"
#include "cCgiccFormEntries.hpp"
#include <cgicc/HTTPContentHeader.h>
#include <cgicc/Cgicc.h>

#define CCGICCMAIN_CGI_NAME "cCgiccMain"
#define CCGICCMAIN_CONTENT_TYPE_TEXT "text/plain"
#define CCGICCMAIN_CONTENT_TYPE_HTML "text/html"
#define CCGICCMAIN_CONTENT_TYPE_XML "text/xml"
#define CCGICCMAIN_CONTENT_TYPE CCGICCMAIN_CONTENT_TYPE_HTML

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

///////////////////////////////////////////////////////////////////////
// Typedef: cCgiccMainExtend
//
//  Author: $author$
//    Date: 5/20/2011
///////////////////////////////////////////////////////////////////////
typedef cInstanceBase
cCgiccMainExtend;

///////////////////////////////////////////////////////////////////////
//  Class: cCgiccMain
//
// Author: $author$
//   Date: 5/20/2011
///////////////////////////////////////////////////////////////////////
class c_INSTANCE_CLASS cCgiccMain
: virtual public cCgiccMainImplement,
  public cCgiccMainExtend
{
public:
    typedef cCgiccMainImplement cImplements;
    typedef cCgiccMainExtend cExtends;

    cgicc::Cgicc m_cgicc;
    const cgicc::CgiEnvironment& m_cgiccEnv;
    const cgicc::FormEntries& m_cgiccForm;

    const cString m_envRequestMethod;
    const cString m_envScriptName;
    const cString m_envPathTranslated;

    cString m_contentTypeText;
    cString m_contentTypeHtml;
    cString m_contentTypeXml;
    cString m_contentType;
    cString m_cgiName;

    bool m_outputContentType;

    ///////////////////////////////////////////////////////////////////////
    //  Constructor: cCgiccMain
    //
    //       Author: $author$
    //         Date: 5/20/2011
    ///////////////////////////////////////////////////////////////////////
    cCgiccMain()
    : m_cgiccEnv(m_cgicc.getEnvironment()),
      m_cgiccForm(m_cgicc.getElements()),

      m_envRequestMethod(m_cgiccEnv.getRequestMethod()),
      m_envScriptName(m_cgiccEnv.getScriptName()),
      m_envPathTranslated(m_cgiccEnv.getPathTranslated()),

      m_contentTypeText(CCGICCMAIN_CONTENT_TYPE_TEXT),
      m_contentTypeHtml(CCGICCMAIN_CONTENT_TYPE_HTML),
      m_contentTypeXml(CCGICCMAIN_CONTENT_TYPE_XML),
      m_contentType(CCGICCMAIN_CONTENT_TYPE),
      m_cgiName(CCGICCMAIN_CGI_NAME),

      m_outputContentType(false)
    {
    }
    ///////////////////////////////////////////////////////////////////////
    //  Destructor: ~cCgiccMain
    //
    //      Author: $author$
    //        Date: 5/20/2011
    ///////////////////////////////////////////////////////////////////////
    virtual ~cCgiccMain()
    {
    }
#else // !defined(CCGICCMAIN_MEMBERS_ONLY) 
#endif // !defined(CCGICCMAIN_MEMBERS_ONLY) 

    ///////////////////////////////////////////////////////////////////////
    //  Function: Main
    //
    //    Author: $author$
    //      Date: 6/25/2011
    ///////////////////////////////////////////////////////////////////////
    virtual int Main
    (int argc,
     char** argv,
     char** env)
#if defined(CCGICCMAIN_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CCGICCMAIN_MEMBER_FUNCS_INTERFACE) 
    {
        int err = 0;
#if !defined(CCGICCMAIN_MEMBER_FUNCS_IMPLEMENT)
        int err2 = 0;

        m_outputContentType = true;

        if (!(err = BeforeRun(argc, argv, env)))
        {
            err = Run(argc, argv, env);

            if ((err2 = AfterRun(argc, argv, env)))
            if (!(err))
                err = err2;
        }
#else // !defined(CCGICCMAIN_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CCGICCMAIN_MEMBER_FUNCS_IMPLEMENT) 
        return err;
    }
#endif // defined(CCGICCMAIN_MEMBER_FUNCS_INTERFACE) 

    ///////////////////////////////////////////////////////////////////////
    //  Function: Run
    //
    //    Author: $author$
    //      Date: 5/20/2011
    ///////////////////////////////////////////////////////////////////////
    virtual int Run
    (int argc,
     char** argv,
     char** env)
#if defined(CCGICCMAIN_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CCGICCMAIN_MEMBER_FUNCS_INTERFACE) 
    {
        int err = 0;
#if !defined(CCGICCMAIN_MEMBER_FUNCS_IMPLEMENT)
        cString content;

        OutputContentType(m_contentTypeHtml);

        content = "<b>";
        content << m_cgiName;
        content << "</b><br/>\n";
        Output(content);

        for (cgicc::FormEntries::const_iterator i = m_cgiccForm.begin(); i != m_cgiccForm.end(); i++)
        {
            const cgicc::FormEntry& e = (*i);
            const cString n = e.getName();
            const cString v = e.getValue();

            content = "<b>";
            content << n;
            content << "=\"</b>";
            content << v;
            content << "<b>\"</b><br/>";
            Output(content);
        }
#else // !defined(CCGICCMAIN_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CCGICCMAIN_MEMBER_FUNCS_IMPLEMENT) 
        return err;
    }
#endif // defined(CCGICCMAIN_MEMBER_FUNCS_INTERFACE) 
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
#if defined(CCGICCMAIN_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CCGICCMAIN_MEMBER_FUNCS_INTERFACE) 
    {
        int err = 0;
#if !defined(CCGICCMAIN_MEMBER_FUNCS_IMPLEMENT)
#else // !defined(CCGICCMAIN_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CCGICCMAIN_MEMBER_FUNCS_IMPLEMENT) 
        return err;
    }
#endif // defined(CCGICCMAIN_MEMBER_FUNCS_INTERFACE) 
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
#if defined(CCGICCMAIN_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CCGICCMAIN_MEMBER_FUNCS_INTERFACE) 
    {
        int err = 0;
#if !defined(CCGICCMAIN_MEMBER_FUNCS_IMPLEMENT)
#else // !defined(CCGICCMAIN_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CCGICCMAIN_MEMBER_FUNCS_IMPLEMENT) 
        return err;
    }
#endif // defined(CCGICCMAIN_MEMBER_FUNCS_INTERFACE) 

    ///////////////////////////////////////////////////////////////////////
    //  Function: OutputContent
    //
    //    Author: $author$
    //      Date: 5/25/2011
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t OutputContent
    (const cString& text)
#if defined(CCGICCMAIN_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CCGICCMAIN_MEMBER_FUNCS_INTERFACE) 
    {
        ssize_t count = 0;
#if !defined(CCGICCMAIN_MEMBER_FUNCS_IMPLEMENT)
        ssize_t count1 = 0;

        if ((m_outputContentType))
        if (0 > (count1 = OutputContentType()))
            return count1;

        if (0 <= (count = Output(text)))
            count += count1;
#else // !defined(CCGICCMAIN_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CCGICCMAIN_MEMBER_FUNCS_IMPLEMENT) 
        return count;
    }
#endif // defined(CCGICCMAIN_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    //  Function: OutputContent
    //
    //    Author: $author$
    //      Date: 5/26/2011
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t OutputContent
    (const char* chars, ssize_t length=-1)
#if defined(CCGICCMAIN_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CCGICCMAIN_MEMBER_FUNCS_INTERFACE) 
    {
        ssize_t count = 0;
#if !defined(CCGICCMAIN_MEMBER_FUNCS_IMPLEMENT)
        ssize_t count1 = 0;

        if ((m_outputContentType))
        if (0 > (count1 = OutputContentType()))
            return count1;

        if (0 <= (count = Output(chars, length)))
            count += count1;
#else // !defined(CCGICCMAIN_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CCGICCMAIN_MEMBER_FUNCS_IMPLEMENT) 
        return count;
    }
#endif // defined(CCGICCMAIN_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    //  Function: OutputContentFormattedV
    //
    //    Author: $author$
    //      Date: 8/12/2011
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t OutputContentFormattedV
    (const char* format,
     va_list va)
#if defined(CCGICCMAIN_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CCGICCMAIN_MEMBER_FUNCS_INTERFACE) 
    {
        ssize_t count = 0;
#if !defined(CCGICCMAIN_MEMBER_FUNCS_IMPLEMENT)
        ssize_t count1 = 0;

        if ((m_outputContentType))
        if (0 > (count1 = OutputContentType()))
            return count1;

        if (0 <= (count = OutputFormattedV(format, va)))
            count += count1;
#else // !defined(CCGICCMAIN_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CCGICCMAIN_MEMBER_FUNCS_IMPLEMENT) 
        return count;
    }
#endif // defined(CCGICCMAIN_MEMBER_FUNCS_INTERFACE) 

    ///////////////////////////////////////////////////////////////////////
    //  Function: OutputContentType
    //
    //    Author: $author$
    //      Date: 5/20/2011
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t OutputContentType()
#if defined(CCGICCMAIN_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CCGICCMAIN_MEMBER_FUNCS_INTERFACE) 
    {
        ssize_t count = 0;
#if !defined(CCGICCMAIN_MEMBER_FUNCS_IMPLEMENT)
        count = OutputContentType(m_contentType);
#else // !defined(CCGICCMAIN_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CCGICCMAIN_MEMBER_FUNCS_IMPLEMENT) 
        return count;
    }
#endif // defined(CCGICCMAIN_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    //  Function: OutputContentType
    //
    //    Author: $author$
    //      Date: 5/20/2011
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t OutputContentType
    (const cString& contentType)
#if defined(CCGICCMAIN_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CCGICCMAIN_MEMBER_FUNCS_INTERFACE) 
    {
        ssize_t count = 0;
#if !defined(CCGICCMAIN_MEMBER_FUNCS_IMPLEMENT)
        cgicc::HTTPContentHeader contentTypeHeader(contentType);
        std::stringstream outputStream;
        outputStream << contentTypeHeader;
        Output(outputStream.str());
        m_outputContentType = false;
#else // !defined(CCGICCMAIN_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CCGICCMAIN_MEMBER_FUNCS_IMPLEMENT) 
        return count;
    }
#endif // defined(CCGICCMAIN_MEMBER_FUNCS_INTERFACE) 

    ///////////////////////////////////////////////////////////////////////
    //  Function: Output
    //
    //    Author: $author$
    //      Date: 5/20/2011
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t Output
    (const cString& text)
#if defined(CCGICCMAIN_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CCGICCMAIN_MEMBER_FUNCS_INTERFACE) 
    {
        ssize_t count = 0;
#if !defined(CCGICCMAIN_MEMBER_FUNCS_IMPLEMENT)
        const char* chars;
        ssize_t length;
        if ((chars = text.HasChars(length)))
            count = Output(chars, length);
#else // !defined(CCGICCMAIN_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CCGICCMAIN_MEMBER_FUNCS_IMPLEMENT) 
        return count;
    }
#endif // defined(CCGICCMAIN_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    //  Function: Output
    //
    //    Author: $author$
    //      Date: 5/20/2011
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t Output
    (const char* chars,
     ssize_t length=-1)
#if defined(CCGICCMAIN_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CCGICCMAIN_MEMBER_FUNCS_INTERFACE) 
    {
        ssize_t count = 0;
#if !defined(CCGICCMAIN_MEMBER_FUNCS_IMPLEMENT)
        FILE* file;
        if ((file = stdout))
        if ((chars) && (0 != length))
        {
            if (0 > (length))
            {
                ssize_t count2 = 0;
                for (count = 0; (*chars) != 0; chars++, count += count2)
                {
                    if (0 > (count2 = fwrite(chars, sizeof(char), 1, file)))
                    {
                        count = count2;
                        break;
                    }
                }
            }
            else
            count = fwrite(chars, sizeof(char), length, file);
            fflush(file);
        }
#else // !defined(CCGICCMAIN_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CCGICCMAIN_MEMBER_FUNCS_IMPLEMENT) 
        return count;
    }
#endif // defined(CCGICCMAIN_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    //  Function: OutputFormattedV
    //
    //    Author: $author$
    //      Date: 8/12/2011
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t OutputFormattedV
    (const char* format,
     va_list va)
#if defined(CCGICCMAIN_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CCGICCMAIN_MEMBER_FUNCS_INTERFACE) 
    {
        ssize_t count = 0;
#if !defined(CCGICCMAIN_MEMBER_FUNCS_IMPLEMENT)
        FILE* file;
        if ((file = stdout))
            count = vfprintf(file, format, va);
#else // !defined(CCGICCMAIN_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CCGICCMAIN_MEMBER_FUNCS_IMPLEMENT) 
        return count;
    }
#endif // defined(CCGICCMAIN_MEMBER_FUNCS_INTERFACE) 

    ///////////////////////////////////////////////////////////////////////
    //  Function: SetContentType
    //
    //    Author: $author$
    //      Date: 5/26/2011
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t SetContentType
    (const cString& contentType)
#if defined(CCGICCMAIN_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CCGICCMAIN_MEMBER_FUNCS_INTERFACE) 
    {
        ssize_t count = 0;
#if !defined(CCGICCMAIN_MEMBER_FUNCS_IMPLEMENT)
        count = m_contentType.Assign(contentType);
#else // !defined(CCGICCMAIN_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CCGICCMAIN_MEMBER_FUNCS_IMPLEMENT) 
        return count;
    }
#endif // defined(CCGICCMAIN_MEMBER_FUNCS_INTERFACE) 

#if !defined(CCGICCMAIN_MEMBER_FUNCS_IMPLEMENT)
    ///////////////////////////////////////////////////////////////////////
    //  Function: GetRequestMethod
    //
    //    Author: $author$
    //      Date: 11/6/2011
    ///////////////////////////////////////////////////////////////////////
    virtual const cString& GetRequestMethod() const
#if defined(CCGICCMAIN_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CCGICCMAIN_MEMBER_FUNCS_INTERFACE) 
    {
        return m_envRequestMethod;
    }
#endif // defined(CCGICCMAIN_MEMBER_FUNCS_INTERFACE) 
#else // !defined(CCGICCMAIN_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CCGICCMAIN_MEMBER_FUNCS_IMPLEMENT) 

#if !defined(CCGICCMAIN_MEMBERS_ONLY)
};

#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#else // !defined(CCGICCMAIN_MEMBERS_ONLY) 
#endif // !defined(CCGICCMAIN_MEMBERS_ONLY) 

#endif // !defined(_CCGICCMAIN_HPP) || defined(CCGICCMAIN_MEMBERS_ONLY) 
