///////////////////////////////////////////////////////////////////////
/// Copyright (c) 1988-2015 $organization$
///
/// This software is provided by the author and contributors ``as is'' 
/// and any express or implied warranties, including, but not limited to, 
/// the implied warranties of merchantability and fitness for a particular 
/// purpose are disclaimed. In no event shall the author or contributors 
/// be liable for any direct, indirect, incidental, special, exemplary, 
/// or consequential damages (including, but not limited to, procurement 
/// of substitute goods or services; loss of use, data, or profits; or 
/// business interruption) however caused and on any theory of liability, 
/// whether in contract, strict liability, or tort (including negligence 
/// or otherwise) arising in any way out of the use of this software, 
/// even if advised of the possibility of such damage.
///
///   File: xslt.hpp
///
/// Author: $author$
///   Date: 1/16/2015
///////////////////////////////////////////////////////////////////////
#ifndef _CORAL_APP_CGI_XSLT_HPP
#define _CORAL_APP_CGI_XSLT_HPP

#include "coral/inet/http/header.hpp"

#define CORAL_APP_CGI_XSLT_PATH_SEPARATOR "/"
#define CORAL_APP_CGI_XSLT_FILEPATH_SEPARATOR "/"
#define CORAL_APP_CGI_XSLT_FILEEXTENSION_SEPARATOR "."
#define CORAL_APP_CGI_XSLT_XSLT_FILEEXTENSION "xslt"
#define CORAL_APP_CGI_XSLT_XML_FILEEXTENSION "xml"

#if !defined(CORAL_APP_CGI_XSLT_NAME)
#define CORAL_APP_CGI_XSLT_NAME "xsltcgi"
#else // !defined(CORAL_APP_CGI_XSLT_NAME)
#endif // !defined(CORAL_APP_CGI_XSLT_NAME)

#if !defined(CORAL_APP_CGI_XSLT_PATH)
#define CORAL_APP_CGI_XSLT_PATH \
    "/coral/xsl" \
    CORAL_APP_CGI_XSLT_PATH_SEPARATOR \
    CORAL_APP_CGI_XSLT_NAME
#else // !defined(CORAL_APP_CGI_XSLT_PATH)
#endif // !defined(CORAL_APP_CGI_XSLT_PATH)

#if !defined(CORAL_APP_CGI_XSLT_XSLT_PATH)
#define CORAL_APP_CGI_XSLT_XSLT_PATH CORAL_APP_CGI_XSLT_PATH
#else // !defined(CORAL_APP_CGI_XSLT_XSLT_PATH)
#endif // !defined(CORAL_APP_CGI_XSLT_XSLT_PATH)

#if !defined(CORAL_APP_CGI_XSLT_XML_PATH)
#define CORAL_APP_CGI_XSLT_XML_PATH CORAL_APP_CGI_XSLT_PATH
#else // !defined(CORAL_APP_CGI_XSLT_XML_PATH)
#endif // !defined(CORAL_APP_CGI_XSLT_XML_PATH)

#if !defined(CORAL_APP_CGI_XSLT_FILEPATH)
#define CORAL_APP_CGI_XSLT_FILEPATH \
    "../templates/xsl" \
    CORAL_APP_CGI_XSLT_FILEPATH_SEPARATOR \
    CORAL_APP_CGI_XSLT_NAME \
    CORAL_APP_CGI_XSLT_FILEPATH_SEPARATOR
#else // !defined(CORAL_APP_CGI_XSLT_FILEPATH)
#endif // !defined(CORAL_APP_CGI_XSLT_FILEPATH)

#if !defined(CORAL_APP_CGI_XSLT_XSLT_FILEPATH)
#define CORAL_APP_CGI_XSLT_XSLT_FILEPATH CORAL_APP_CGI_XSLT_FILEPATH
#else // !defined(CORAL_APP_CGI_XSLT_XSLT_FILEPATH)
#endif // !defined(CORAL_APP_CGI_XSLT_XSLT_FILEPATH)

#if !defined(CORAL_APP_CGI_XSLT_XML_FILEPATH)
#define CORAL_APP_CGI_XSLT_XML_FILEPATH CORAL_APP_CGI_XSLT_FILEPATH
#else // !defined(CORAL_APP_CGI_XSLT_XML_FILEPATH)
#endif // !defined(CORAL_APP_CGI_XSLT_XML_FILEPATH)

#if !defined(CORAL_APP_CGI_XSLT_XSLT_FILEBASE)
#define CORAL_APP_CGI_XSLT_XSLT_FILEBASE CORAL_APP_CGI_XSLT_NAME
#else // !defined(CORAL_APP_CGI_XSLT_XSLT_FILEBASE)
#endif // !defined(CORAL_APP_CGI_XSLT_XSLT_FILEBASE)

#if !defined(CORAL_APP_CGI_XSLT_XML_FILEBASE)
#define CORAL_APP_CGI_XSLT_XML_FILEBASE CORAL_APP_CGI_XSLT_NAME
#else // !defined(CORAL_APP_CGI_XSLT_XML_FILEBASE)
#endif // !defined(CORAL_APP_CGI_XSLT_XML_FILEBASE)

#define CORAL_APP_CGI_XSLT_XSLT_FILENAME \
    CORAL_APP_CGI_XSLT_XSLT_FILEPATH \
    CORAL_APP_CGI_XSLT_XSLT_FILEBASE \
    CORAL_APP_CGI_XSLT_FILEEXTENSION_SEPARATOR \
    CORAL_APP_CGI_XSLT_XSLT_FILEEXTENSION

#define CORAL_APP_CGI_XSLT_XML_FILENAME \
    CORAL_APP_CGI_XSLT_XML_FILEPATH \
    CORAL_APP_CGI_XSLT_XML_FILEBASE \
    CORAL_APP_CGI_XSLT_FILEEXTENSION_SEPARATOR \
    CORAL_APP_CGI_XSLT_XML_FILEEXTENSION

#define CORAL_APP_CGI_XSLT_CGI_ENV_XSLT_PARAMETER_NAME_PREFIX "cgi_env_"

#define CORAL_APP_CGI_XSLT_CGI_NAME_XSLT_PARAMETER_NAME "cgi_name"

#define CORAL_APP_CGI_XSLT_PARAM_NAME_CONTENT_TYPE "content_type"
#define CORAL_APP_CGI_XSLT_PARAM_CONTENT_TYPE_NAMES \
    CORAL_APP_CGI_XSLT_PARAM_NAME_CONTENT_TYPE, \
    CORAL_INET_HTTP_MESSAGE_HEADER_NAME_CONTENT_TYPE, \

#define CORAL_APP_CGI_XSLT_PARAM_NAME_DOCUMENT_FILE "document_file"
#define CORAL_APP_CGI_XSLT_PARAM_NAME_XML_FILE "xml_file"
#define CORAL_APP_CGI_XSLT_PARAM_NAME_XML "xml"
#define CORAL_APP_CGI_XSLT_PARAM_DOCUMENT_FILE_NAMES \
    CORAL_APP_CGI_XSLT_PARAM_NAME_DOCUMENT_FILE, \
    CORAL_APP_CGI_XSLT_PARAM_NAME_XML_FILE, \
    CORAL_APP_CGI_XSLT_PARAM_NAME_XML, \

#define CORAL_APP_CGI_XSLT_PARAM_NAME_TEMPLATE_FILE "template_file"
#define CORAL_APP_CGI_XSLT_PARAM_NAME_XSLT_FILE "xslt_file"
#define CORAL_APP_CGI_XSLT_PARAM_NAME_XSLT "xslt"
#define CORAL_APP_CGI_XSLT_PARAM_NAME_XSL_FILE "xsl_file"
#define CORAL_APP_CGI_XSLT_PARAM_NAME_XSL "xsl"
#define CORAL_APP_CGI_XSLT_PARAM_TEMPLATE_FILE_NAMES \
    CORAL_APP_CGI_XSLT_PARAM_NAME_TEMPLATE_FILE, \
    CORAL_APP_CGI_XSLT_PARAM_NAME_XSLT_FILE, \
    CORAL_APP_CGI_XSLT_PARAM_NAME_XSLT, \
    CORAL_APP_CGI_XSLT_PARAM_NAME_XSL_FILE, \
    CORAL_APP_CGI_XSLT_PARAM_NAME_XSL, \

namespace coral {
namespace app {
namespace cgi {
namespace xslt {

} // namespace xslt 
} // namespace cgi 
} // namespace app 
} // namespace coral 

#endif // _CORAL_APP_CGI_XSLT_HPP 
