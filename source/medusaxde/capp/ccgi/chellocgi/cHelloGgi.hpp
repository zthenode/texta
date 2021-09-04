///////////////////////////////////////////////////////////////////////
// Copyright (c) 1988-2013 $organization$
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
//   File: cHelloGgi.hpp
//
// Author: $author$
//   Date: 8/11/2013
///////////////////////////////////////////////////////////////////////
#ifndef _CHELLOGGI_HPP
#define _CHELLOGGI_HPP

#include "cCgi.hpp"
#include "cHtmlMacro.hpp"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

typedef cCgiImplement cHelloGgiImplement;
typedef cCgi cHelloGgiExtend;
///////////////////////////////////////////////////////////////////////
//  Class: cHelloGgi
//
// Author: $author$
//   Date: 8/11/2013
///////////////////////////////////////////////////////////////////////
class c_EXPORT_CLASS cHelloGgi
: virtual public cHelloGgiImplement,
  public cHelloGgiExtend
{
public:
    typedef cHelloGgiImplement cImplements;
    typedef cHelloGgiExtend cExtends;

    virtual int Run
    (int argc, char** argv, char** env)
    {
        cHttpFormFieldInterface* field;
        cString name;

        if ((field = FindFirstFormField("name")))
            name = field->GetValue();

        OutputContentL
        (HTML_, BODY_, B_, "Hello ", _B, name.c_str(), BR , _HTML, _BODY, 0);
        return 0;
    }
};

#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#endif // _CHELLOGGI_HPP 
