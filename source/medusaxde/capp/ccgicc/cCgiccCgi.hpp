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
//   File: cCgiccCgi.hpp
//
// Author: $author$
//   Date: 6/27/2011
///////////////////////////////////////////////////////////////////////
#if !defined(_CCGICCCGI_HPP) || defined(CCGICCCGI_MEMBERS_ONLY)
#if !defined(_CCGICCCGI_HPP) && !defined(CCGICCCGI_MEMBERS_ONLY)
#define _CCGICCCGI_HPP
#endif // !defined(_CCGICCCGI_HPP) && !defined(CCGICCCGI_MEMBERS_ONLY) 

#if !defined(CCGICCCGI_MEMBERS_ONLY)
#include "cCgi.hpp"

#define CCGICCCGI_NAME "cCgiccCgi"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

///////////////////////////////////////////////////////////////////////
// Typedef: cCgiccCgiExtend
//
//  Author: $author$
//    Date: 6/27/2011
///////////////////////////////////////////////////////////////////////
typedef cCgi
cCgiccCgiExtend;
///////////////////////////////////////////////////////////////////////
//  Class: cCgiccCgi
//
// Author: $author$
//   Date: 6/27/2011
///////////////////////////////////////////////////////////////////////
class c_INSTANCE_CLASS cCgiccCgi
: //virtual public cCgiccCgiImplement,
  public cCgiccCgiExtend
{
public:
    //typedef cCgiccCgiImplement cImplements;
    typedef cCgiccCgiExtend cExtends;
    ///////////////////////////////////////////////////////////////////////
    //  Constructor: cCgiccCgi
    //
    //       Author: $author$
    //         Date: 6/27/2011
    ///////////////////////////////////////////////////////////////////////
    cCgiccCgi()
    : cExtends(CCGICCCGI_NAME)
    {
    }
    ///////////////////////////////////////////////////////////////////////
    //  Destructor: ~cCgiccCgi
    //
    //      Author: $author$
    //        Date: 6/27/2011
    ///////////////////////////////////////////////////////////////////////
    virtual ~cCgiccCgi()
    {
    }
#else // !defined(CCGICCCGI_MEMBERS_ONLY) 
#endif // !defined(CCGICCCGI_MEMBERS_ONLY) 

    ///////////////////////////////////////////////////////////////////////
    //  Function: Run
    //
    //    Author: $author$
    //      Date: 6/27/2011
    ///////////////////////////////////////////////////////////////////////
    virtual int Run
    (int argc,
     char** argv,
     char** env)
#if defined(CCGICCCGI_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CCGICCCGI_MEMBER_FUNCS_INTERFACE) 
    {
        int err = 0;
#if !defined(CCGICCCGI_MEMBER_FUNCS_IMPLEMENT)
        const char* envName;
        const char* envValue;
        eCgiEnv cgiEnv;
        cHttpFormFieldInterface* formField;
        cHttpFormFieldsIterator* atFormField;
        cString content;

        SetDebugLevelsFromForm();

        c_DB_ERROR("() in...");

        content = "<b>";
        content << GetName();
        content << "</b><br/><br/>";
        OutputContent(content);

        for (formField = GetFirstFormField(atFormField); formField; 
             formField = GetNextFormField(*atFormField))
        {
            content = "<b>";
            content << formField->GetName();
            content << " = &quot;</b>";
            content << formField->GetValue();
            content << "<b>&quot;</b><br/>";
            OutputContent(content);
        }

        content = "<br/>";
        OutputContent(content);

        if ((envName = GetLastCgiEnv(cgiEnv, envValue)))
        {
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
            while ((envName = GetPrevCgiEnv(cgiEnv, envValue)));
        }

        c_DB_ERROR("() ...out");

#else // !defined(CCGICCCGI_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CCGICCCGI_MEMBER_FUNCS_IMPLEMENT) 
        return err;
    }
#endif // defined(CCGICCCGI_MEMBER_FUNCS_INTERFACE) 

#if !defined(CCGICCCGI_MEMBERS_ONLY)
};


#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#else // !defined(CCGICCCGI_MEMBERS_ONLY) 
#endif // !defined(CCGICCCGI_MEMBERS_ONLY) 

#endif // !defined(_CCGICCCGI_HPP) || defined(CCGICCCGI_MEMBERS_ONLY) 
