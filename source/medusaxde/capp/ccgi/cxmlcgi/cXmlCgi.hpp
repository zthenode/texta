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
//   File: cXmlCgi.hpp
//
// Author: $author$
//   Date: 7/26/2011
///////////////////////////////////////////////////////////////////////
#if !defined(_CXMLCGI_HPP) || defined(CXMLCGI_MEMBERS_ONLY)
#if !defined(_CXMLCGI_HPP) && !defined(CXMLCGI_MEMBERS_ONLY)
#define _CXMLCGI_HPP
#endif // !defined(_CXMLCGI_HPP) && !defined(CXMLCGI_MEMBERS_ONLY) 

#if !defined(CXMLCGI_MEMBERS_ONLY)
#include "cCgi.hpp"
#include "cStringWriter.hpp"
#include "cXmlAttributeEncoder.hpp"
#include "cXmlTextEncoder.hpp"
#include "cCgiXmlWriter.hpp"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

///////////////////////////////////////////////////////////////////////
// Typedef: cXmlCgiExtend
//
//  Author: $author$
//    Date: 7/26/2011
///////////////////////////////////////////////////////////////////////
typedef cCgi
cXmlCgiExtend;
///////////////////////////////////////////////////////////////////////
//  Class: cXmlCgi
//
// Author: $author$
//   Date: 7/26/2011
///////////////////////////////////////////////////////////////////////
class c_INSTANCE_CLASS cXmlCgi
: //virtual public cXmlCgiImplement,
  public cXmlCgiExtend
{
public:
    //typedef cXmlCgiImplement cImplements;
    typedef cXmlCgiExtend cExtends;

    ///////////////////////////////////////////////////////////////////////
    //  Constructor: cXmlCgi
    //
    //       Author: $author$
    //         Date: 7/26/2011
    ///////////////////////////////////////////////////////////////////////
    cXmlCgi()
    {
    }
    ///////////////////////////////////////////////////////////////////////
    //  Destructor: ~cXmlCgi
    //
    //      Author: $author$
    //        Date: 7/26/2011
    ///////////////////////////////////////////////////////////////////////
    virtual ~cXmlCgi()
    {
    }
#else // !defined(CXMLCGI_MEMBERS_ONLY) 
#endif // !defined(CXMLCGI_MEMBERS_ONLY) 

#if !defined(CXMLCGI_MEMBERS_ONLY)
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
    {
        int err = 0;
        const char* envName;
        const char* envValue;
        eCgiEnv cgiEnv;
        cHttpFormFieldInterface* formField;
        cHttpFormFieldsIterator* atFormField;
        cString content;
        cStringWriter contentWriter(content);
        cXmlTextEncoder xmlText(contentWriter);
        cXmlAttributeEncoder xmlAttribute(contentWriter);

        SetContentType(m_contentTypeXml);

        if ((m_contentOutput))
        {
            cCharWriterInterface& contentWriter = (cCharWriterInterface&)(*m_contentOutput);
            cCgiXmlWriter xmlWriter(contentWriter);
            xmlWriter.Put(*this);
            return err;
        }

        content = "<?xml version=\"1.0\" encoding=\"utf-8\"?>\n";
        content << "<ccgi:cgi xmlns:ccgi=\"ccgi\" xmlns=\"ccgi\">\n";
        content << "<env>\n";
        OutputContent(content);

        if ((envName = GetFirstCgiEnv(cgiEnv, envValue)))
        {
            do
            {
                content = "<variable name=\"";
                //content << envName;
                xmlAttribute.Write(envName);
                content << "\">";
                //content << ((envValue)?(envValue):(""));
                xmlText.Write((envValue)?(envValue):(""));
                content << "</variable>\n";
                OutputContent(content);
            }
            while ((envName = GetNextCgiEnv(cgiEnv, envValue)));
        }

        content = "</env>\n";
        content << "<form>\n";
        OutputContent(content);

        for (formField = GetLastFormField(atFormField); formField; 
             formField = GetPrevFormField(*atFormField))
        {
            content = "<field name=\"";
            //content << formField->GetName();
            xmlAttribute.Write(formField->GetName().Chars());
            content << "\">";
            //content << formField->GetValue();
            xmlText.Write(formField->GetValue().Chars());
            content << "</field>\n";
            OutputContent(content);
        }

        content = "</form>\n";
        content << "</ccgi:cgi>\n";
        OutputContent(content);
        return err;
    }
};


#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#else // !defined(CXMLCGI_MEMBERS_ONLY) 
#endif // !defined(CXMLCGI_MEMBERS_ONLY) 

#endif // !defined(_CXMLCGI_HPP) || defined(CXMLCGI_MEMBERS_ONLY) 
        

