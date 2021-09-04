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
//   File: cLibcMxdeCgi.hpp
//
// Author: $author$
//   Date: 9/30/2011
///////////////////////////////////////////////////////////////////////
#if !defined(_CLIBCMXDECGI_HPP) || defined(CLIBCMXDECGI_MEMBERS_ONLY)
#if !defined(_CLIBCMXDECGI_HPP) && !defined(CLIBCMXDECGI_MEMBERS_ONLY)
#define _CLIBCMXDECGI_HPP
#endif // !defined(_CLIBCMXDECGI_HPP) && !defined(CLIBCMXDECGI_MEMBERS_ONLY) 

#if !defined(CLIBCMXDECGI_MEMBERS_ONLY)
#include "cCgi.hpp"

#define CLIBCMXDECGI_NAME "cLibcMxdeCgi"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

///////////////////////////////////////////////////////////////////////
// Typedef: cLibcMxdeCgiExtend
//
//  Author: $author$
//    Date: 9/30/2011
///////////////////////////////////////////////////////////////////////
typedef cCgi
cLibcMxdeCgiExtend;
///////////////////////////////////////////////////////////////////////
//  Class: cLibcMxdeCgi
//
// Author: $author$
//   Date: 9/30/2011
///////////////////////////////////////////////////////////////////////
class c_INSTANCE_CLASS cLibcMxdeCgi
: //virtual public cLibcMxdeCgiImplement,
  public cLibcMxdeCgiExtend
{
public:
    //typedef cLibcMxdeCgiImplement cImplements;
    typedef cLibcMxdeCgiExtend cExtends;
    ///////////////////////////////////////////////////////////////////////
    //  Constructor: cLibcMxdeCgi
    //
    //       Author: $author$
    //         Date: 9/30/2011
    ///////////////////////////////////////////////////////////////////////
    cLibcMxdeCgi()
    : cExtends(CLIBCMXDECGI_NAME)
    {
    }
    ///////////////////////////////////////////////////////////////////////
    //  Destructor: ~cLibcMxdeCgi
    //
    //      Author: $author$
    //        Date: 9/30/2011
    ///////////////////////////////////////////////////////////////////////
    virtual ~cLibcMxdeCgi()
    {
    }
#else // !defined(CLIBCMXDECGI_MEMBERS_ONLY) 
#endif // !defined(CLIBCMXDECGI_MEMBERS_ONLY) 

    ///////////////////////////////////////////////////////////////////////
    //  Function: Run
    //
    //    Author: $author$
    //      Date: 9/30/2011
    ///////////////////////////////////////////////////////////////////////
    virtual int Run
    (int argc,
     char** argv,
     char** env)
#if defined(CLIBCMXDECGI_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CLIBCMXDECGI_MEMBER_FUNCS_INTERFACE) 
    {
        int err = 0;
#if !defined(CLIBCMXDECGI_MEMBER_FUNCS_IMPLEMENT)
        const char* envName;
        const char* envValue;
        eCgiEnv cgiEnv;
        cHttpFormFieldInterface* formField;
        cHttpFormFieldsIterator* atFormField;
        cString content;

        SetContentType(m_contentTypeHtml);

        content = "content_type";
        if ((formField = FindFirstFormField(atFormField, content)))
        if (0 < (content.Assign(formField->GetValue())))
        if (0 < (content.Length()))
            SetContentType(content);

        content = "<html><body>";
        OutputContent(content);

        content = "<b>";
        content << GetName();
        content << "</b><br/><br/>";
        OutputContent(content);

        if ((formField = GetFirstFormField(atFormField)))
        {
            content = "<b>HTTP Form Fields</b><ul>";
            OutputContent(content);

            do
            {
                content = "<b>";
                content << formField->GetName();
                content << " = &quot;</b>";
                content << formField->GetValue();
                content << "<b>&quot;</b><br/>";
                OutputContent(content);
            }
            while ((formField = GetNextFormField(*atFormField)));

            content = "</ul><br/>";
            OutputContent(content);
        }

        if ((envName = GetFirstCgiEnv(cgiEnv, envValue)))
        {
            content = "<b>CGI Environment Variables</b><ul>";
            OutputContent(content);

            do
            {
                content = "<b>";
                content << envName;
                content << " = ";
                content << ((envValue)?("&quot;"):(envValue));
                content << "</b>";
                content << ((envValue)?(envValue):(""));
                content << "<b>";
                content << ((envValue)?("&quot;"):(envValue));
                content << "</b><br/>";
                OutputContent(content);
            }
            while ((envName = GetNextCgiEnv(cgiEnv, envValue)));

            content = "</ul><br/>";
            OutputContent(content);
        }

        content = "</body></html>";
        OutputContent(content);
#else // !defined(CLIBCMXDECGI_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CLIBCMXDECGI_MEMBER_FUNCS_IMPLEMENT) 
        return err;
    }
#endif // defined(CLIBCMXDECGI_MEMBER_FUNCS_INTERFACE) 

#if !defined(CLIBCMXDECGI_MEMBERS_ONLY)
};


#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#else // !defined(CLIBCMXDECGI_MEMBERS_ONLY) 
#endif // !defined(CLIBCMXDECGI_MEMBERS_ONLY) 

#endif // !defined(_CLIBCMXDECGI_HPP) || defined(CLIBCMXDECGI_MEMBERS_ONLY) 
        

