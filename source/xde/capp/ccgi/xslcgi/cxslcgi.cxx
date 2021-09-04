/**
 **********************************************************************
 * Copyright (c) 1988-2008 $organization$
 *
 * This software is provided by the author and contributors ``as is'' 
 * and any express or implied warranties, including, but not limited to, 
 * the implied warranties of merchantability and fitness for a particular 
 * purpose are disclaimed. In no event shall the author or contributors 
 * be liable for any direct, indirect, incidental, special, exemplary, 
 * or consequential damages (including, but not limited to, procurement 
 * of substitute goods or services; loss of use, data, or profits; or 
 * business interruption) however caused and on any theory of liability, 
 * whether in contract, strict liability, or tort (including negligence 
 * or otherwise) arising in any way out of the use of this software, 
 * even if advised of the possibility of such damage.
 *
 *   File: cxslcgi.cxx
 *
 * Author: $author$
 *   Date: 3/26/2008
 **********************************************************************
 */
#include "cxslcgi.hxx"
/**
 **********************************************************************
 *  Class: cXSLCGI
 *
 * Author: $author$
 *   Date: 3/26/2008
 **********************************************************************
 */
cXSLCGI g_xslCGI;

cDocumentFilePathItem g_documentFilePathItem1("xml_path");
cDocumentFilePathItem g_documentFilePathItem2("xml_filepath");
cDocumentFilePathItem g_documentFilePathItem3("document_path");
cDocumentFilePathItem g_documentFilePathItem4("document_filepath");

cDocumentFileNameItem g_documentFileNameItem1("xml_file");
cDocumentFileNameItem g_documentFileNameItem2("xml_filename");
cDocumentFileNameItem g_documentFileNameItem3("document_file");
cDocumentFileNameItem g_documentFileNameItem4("document_filename");

cTemplateFilePathItem g_templateFilePathItem1("xsl_path");
cTemplateFilePathItem g_templateFilePathItem2("xsl_filepath");
cTemplateFilePathItem g_templateFilePathItem3("template_path");
cTemplateFilePathItem g_templateFilePathItem4("template_filepath");

cTemplateFileNameItem g_templateFileNameItem1("xsl_file");
cTemplateFileNameItem g_templateFileNameItem2("xsl_filename");
cTemplateFileNameItem g_templateFileNameItem3("template_file");
cTemplateFileNameItem g_templateFileNameItem4("template_filename");

cDocumentURIItem g_documentURIItem1("xml");
cDocumentURIItem g_documentURIItem2("xml_uri");
cDocumentURIItem g_documentURIItem3("document");
cDocumentURIItem g_documentURIItem4("document_uri");

cTemplateURIItem g_templateURIItem1("xsl");
cTemplateURIItem g_templateURIItem2("xsl_uri");
cTemplateURIItem g_templateURIItem3("template");
cTemplateURIItem g_templateURIItem4("template_uri");
