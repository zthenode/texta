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
//   File: cCgiCgi.hpp
//
// Author: $author$
//   Date: 11/23/2012
///////////////////////////////////////////////////////////////////////
#ifndef _CCGICGI_HPP
#define _CCGICGI_HPP

#include "cCgi.hpp"
#include "cHtmlMacro.hpp"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

///////////////////////////////////////////////////////////////////////
// Typedef: cCgiCgiImplement
//
//  Author: $author$
//    Date: 11/23/2012
///////////////////////////////////////////////////////////////////////
typedef cCgiImplement
cCgiCgiImplement;
///////////////////////////////////////////////////////////////////////
// Typedef: cCgiCgiExtend
//
//  Author: $author$
//    Date: 11/23/2012
///////////////////////////////////////////////////////////////////////
typedef cCgi
cCgiCgiExtend;
///////////////////////////////////////////////////////////////////////
//  Class: cCgiCgi
//
// Author: $author$
//   Date: 11/23/2012
///////////////////////////////////////////////////////////////////////
class c_EXPORT_CLASS cCgiCgi
: virtual public cCgiCgiImplement,
  public cCgiCgiExtend
{
public:
    typedef cCgiCgiImplement cImplements;
    typedef cCgiCgiExtend cExtends;

    ///////////////////////////////////////////////////////////////////////
    //  Constructor: cCgiCgi
    //
    //       Author: $author$
    //         Date: 11/23/2012
    ///////////////////////////////////////////////////////////////////////
    cCgiCgi()
    {
    }
    ///////////////////////////////////////////////////////////////////////
    //  Destructor: ~cCgiCgi
    //
    //      Author: $author$
    //        Date: 11/23/2012
    ///////////////////////////////////////////////////////////////////////
    virtual ~cCgiCgi()
    {
    }

    ///////////////////////////////////////////////////////////////////////
    //  Function: Run
    //
    //    Author: $author$
    //      Date: 7/28/2011
    ///////////////////////////////////////////////////////////////////////
    virtual int Run
    (int argc, char** argv, char** env)
    {
        char nullChar = 0;
        int errn = 0;
        int arg;
        const char* chars;
        const char* name;
        const char* value;
        eCgiEnv e;
        cHttpFormFieldsIterator* atField;
        cHttpFormFieldInterface* field;
        cString string;

        // Output the cgi name.
        //
        OutputContentL(HTML_, BODY_, H1_, GetName().c_str(), _H1, 0);

        if ((field = GetFirstFormField(atField)))
        {
            // Output the form fields.
            //
            OutputContentL(B_, "Form Fields", _B, UL_, BR, 0);
            do
            {
                const cString& name = field->GetName();
                const cString& value = field->GetValue();
                OutputContentL
                (B_, name.c_str(), " = \"", _B, 
                 value.c_str(), B_, "\"", _B, BR, 0);
            }
            while ((field = GetNextFormField(*atField)));
            OutputContentL(_UL, BR, 0);
        }

        // Output the CGI environment variables passed to main.
        //
        OutputContentL(B_, "Environment", _B, UL_, BR, 0);

        for (e=e_FIRST_CGI_ENV; e<=e_LAST_CGI_ENV; e++)
        {
            if (!(value = GetCgiEnv(e)))
                value = &nullChar;
                
            if ((name = GetCgiEnvName(e)))
            OutputContentL
            (B_, name, " = \"", _B, value, B_, "\"", _B, BR, 0);
        }
        OutputContentL(_UL, BR, 0);

        // Output the standard argments passed to main.
        //
        OutputContentL(B_, "Arguments", _B, UL_, BR, 0);

        for (arg=0; arg<argc; arg++)
        {
            string.Assign(arg);
            chars = string.Chars();
            OutputContentL
            (B_, "argv[", chars?chars:&nullChar, "] = \"",
             _B, argv[arg], B_, "\"", _B, BR, 0);
        }
        OutputContentL(_UL, BR, 0);
        
        OutputContentL(_HTML, _BODY, 0);
        return errn;
    }
};

#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#endif // _CCGICGI_HPP 
