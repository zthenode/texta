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
//   File: cCgiXmlWriter.hpp
//
// Author: $author$
//   Date: 7/27/2011
///////////////////////////////////////////////////////////////////////
#if !defined(_CCGIXMLWRITER_HPP) || defined(CCGIXMLWRITER_MEMBERS_ONLY)
#if !defined(_CCGIXMLWRITER_HPP) && !defined(CCGIXMLWRITER_MEMBERS_ONLY)
#define _CCGIXMLWRITER_HPP
#endif // !defined(_CCGIXMLWRITER_HPP) && !defined(CCGIXMLWRITER_MEMBERS_ONLY) 

#if !defined(CCGIXMLWRITER_MEMBERS_ONLY)
#include "cCgiXmlWriterInterface.hpp"
#include "cStringWriter.hpp"
#include "cXmlAttributeEncoder.hpp"
#include "cXmlTextEncoder.hpp"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

///////////////////////////////////////////////////////////////////////
// Typedef: cCgiXmlWriterExtend
//
//  Author: $author$
//    Date: 7/27/2011
///////////////////////////////////////////////////////////////////////
typedef cInstanceBase
cCgiXmlWriterExtend;
///////////////////////////////////////////////////////////////////////
//  Class: cCgiXmlWriter
//
// Author: $author$
//   Date: 7/27/2011
///////////////////////////////////////////////////////////////////////
class c_INSTANCE_CLASS cCgiXmlWriter
: virtual public cCgiXmlWriterImplement,
  public cCgiXmlWriterExtend
{
public:
    typedef cCgiXmlWriterImplement cImplements;
    typedef cCgiXmlWriterExtend cExtends;

    cCharWriterInterface& m_writer;

    ///////////////////////////////////////////////////////////////////////
    //  Constructor: cCgiXmlWriter
    //
    //       Author: $author$
    //         Date: 7/27/2011
    ///////////////////////////////////////////////////////////////////////
    cCgiXmlWriter
    (cCharWriterInterface& writer)
    : m_writer(writer)
    {
    }
    ///////////////////////////////////////////////////////////////////////
    //  Destructor: ~cCgiXmlWriter
    //
    //      Author: $author$
    //        Date: 7/27/2011
    ///////////////////////////////////////////////////////////////////////
    virtual ~cCgiXmlWriter()
    {
    }
#else // !defined(CCGIXMLWRITER_MEMBERS_ONLY) 
#endif // !defined(CCGIXMLWRITER_MEMBERS_ONLY) 

    ///////////////////////////////////////////////////////////////////////
    //  Function: Put
    //
    //    Author: $author$
    //      Date: 7/27/2011
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t Put
    (const cCgiInterface& cgi)
#if defined(CCGIXMLWRITER_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CCGIXMLWRITER_MEMBER_FUNCS_INTERFACE) 
    {
        ssize_t count = 0;
#if !defined(CCGIXMLWRITER_MEMBER_FUNCS_IMPLEMENT)
        cString content;
        cStringWriter contentWriter(content);
        cXmlTextEncoder xmlText(contentWriter);
        cXmlAttributeEncoder xmlAttribute(contentWriter);
        eCgiEnv cgiEnv;
        const char* envName;
        const char* envValue;
        cHttpFormFieldsIterator* atFormField;
        cHttpFormFieldInterface* formField;
        ssize_t count2;

        content = "<?xml version=\"1.0\" encoding=\"utf-8\"?>\n";
        content << "<ccgi:cgi xmlns:ccgi=\"ccgi\" xmlns=\"ccgi\">\n";
        content << "<env>\n";

        if (0 < (count2 = m_writer.Write(content.Chars())))
            count += count2;;

        for (envName = cgi.GetFirstCgiEnv(cgiEnv, envValue);
             envName; envName = cgi.GetNextCgiEnv(cgiEnv, envValue))
        {
            content = "<variable name=\"";
            xmlAttribute.Write(envName);
            content << "\">";
            xmlText.Write((envValue)?(envValue):(""));
            content << "</variable>\n";

            if (0 < (count2 = m_writer.Write(content.Chars())))
                count += count2;;
        }

        content = "</env>\n";
        content << "<form>\n";

        if (0 < (count2 = m_writer.Write(content.Chars())))
            count += count2;;

        for (formField = cgi.GetFirstFormField(atFormField); 
             formField; formField = cgi.GetNextFormField(*atFormField))
        {
            content = "<field name=\"";
            xmlAttribute.Write(formField->GetName().Chars());
            content << "\">";
            xmlText.Write(formField->GetValue().Chars());
            content << "</field>\n";

            if (0 < (count2 = m_writer.Write(content.Chars())))
                count += count2;;
        }

        content = "</form>\n";
        content << "</ccgi:cgi>\n";

        if (0 < (count2 = m_writer.Write(content.Chars())))
            count += count2;;

#else // !defined(CCGIXMLWRITER_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CCGIXMLWRITER_MEMBER_FUNCS_IMPLEMENT) 
        return count;
    }
#endif // defined(CCGIXMLWRITER_MEMBER_FUNCS_INTERFACE) 

#if !defined(CCGIXMLWRITER_MEMBERS_ONLY)
};

#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#else // !defined(CCGIXMLWRITER_MEMBERS_ONLY) 
#endif // !defined(CCGIXMLWRITER_MEMBERS_ONLY) 

#endif // !defined(_CCGIXMLWRITER_HPP) || defined(CCGIXMLWRITER_MEMBERS_ONLY) 
