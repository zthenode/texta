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
//   File: cHtmlMacro.hpp
//
// Author: $author$
//   Date: 11/21/2012
///////////////////////////////////////////////////////////////////////
#ifndef _CHTMLMACRO_HPP
#define _CHTMLMACRO_HPP

#undef HTML_
#undef _HTML
#undef BODY_
#undef _BODY
#undef BR
#undef H1_
#undef _H1
#undef B_
#undef _B
#undef UL_
#undef _UL

#define HTML_ ((GetContentType()==GetContentTypeHtml())?"<html>\n":"")
#define _HTML ((GetContentType()==GetContentTypeHtml())?"</html>\n":"\n\n")
#define BODY_ ((GetContentType()==GetContentTypeHtml())?"<body>":"")
#define _BODY ((GetContentType()==GetContentTypeHtml())?"</body>":"")
#define BR ((GetContentType()==GetContentTypeHtml())?"<br>\n":"\n")
#define LF "\n"
#define H1_ ((GetContentType()==GetContentTypeHtml())?"<h1>\n":"")
#define _H1 ((GetContentType()==GetContentTypeHtml())?"</h1>\n":"\n\n")
#define B_ ((GetContentType()==GetContentTypeHtml())?"<b>":"")
#define _B ((GetContentType()==GetContentTypeHtml())?"</b>":"")
#define UL_ ((GetContentType()==GetContentTypeHtml())?"<ul>":"")
#define _UL ((GetContentType()==GetContentTypeHtml())?"</ul>":"\n")
#define LI_ ((GetContentType()==GetContentTypeHtml())?"<li>":"")
#define _LI ((GetContentType()==GetContentTypeHtml())?"</li>":"\n")

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#endif // _CHTMLMACRO_HPP 
