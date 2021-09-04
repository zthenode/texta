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
//   File: cXsltCgi.cpp
//
// Author: $author$
//   Date: 7/27/2011
///////////////////////////////////////////////////////////////////////
#include "cXsltCgi.hpp"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

///////////////////////////////////////////////////////////////////////
//  Class: cXsltCgi
//
// Author: $author$
//   Date: 7/27/2011
///////////////////////////////////////////////////////////////////////
#if !defined(CXSLTCGI_NO_INSTANCE) 
cXsltCgi g_cXsltCgi;
#else // !defined(CXSLTCGI_NO_INSTANCE) 
#endif // !defined(CXSLTCGI_NO_INSTANCE) 

///////////////////////////////////////////////////////////////////////
//  Function: cXsltCgi::GetXsltPathParameterNames
//
//    Author: $author$
//      Date: 7/28/2011
///////////////////////////////////////////////////////////////////////
const char** cXsltCgi::GetXsltPathParameterNames() const
{
    static const char* names[] = 
    {"xsl_path",
     "xslt_path",
     "template_path",
     0};
    return names;
}
///////////////////////////////////////////////////////////////////////
//  Function: cXsltCgi::GetXmlPathParameterNames
//
//    Author: $author$
//      Date: 7/28/2011
///////////////////////////////////////////////////////////////////////
const char** cXsltCgi::GetXmlPathParameterNames() const
{
    static const char* names[] = 
    {"xml_path",
     "document_path",
     0};
    return names;
}
///////////////////////////////////////////////////////////////////////
//  Function: cXsltCgi::GetXsltFileParameterNames
//
//    Author: $author$
//      Date: 7/28/2011
///////////////////////////////////////////////////////////////////////
const char** cXsltCgi::GetXsltFileParameterNames() const
{
    static const char* names[] = 
    {"xsl_file",
     "xsl_filename",
     "xslt_file",
     "xslt_filename",
     "template_file",
     "template_filename",
     0};
    return names;
}
///////////////////////////////////////////////////////////////////////
//  Function: cXsltCgi::GetXmlFileParameterNames
//
//    Author: $author$
//      Date: 7/28/2011
///////////////////////////////////////////////////////////////////////
const char** cXsltCgi::GetXmlFileParameterNames() const
{
    static const char* names[] = 
    {"xml_file",
     "xml_filename",
     "document_file",
     "document_filename",
     0};
    return names;
}
///////////////////////////////////////////////////////////////////////
//  Function: cXsltCgi::GetContentTypeParameterNames
//
//    Author: $author$
//      Date: 8/2/2011
///////////////////////////////////////////////////////////////////////
const char** cXsltCgi::GetContentTypeParameterNames() const
{
    static const char* names[] = 
    {"content_type",
     0};
    return names;
}

#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 
