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
 *   File: htmlmacro.h
 *
 * Author: $author$
 *   Date: 3/17/2008
 **********************************************************************
 */
#ifndef _HTMLMACRO_H
#define _HTMLMACRO_H

/* Content type dependant macros used for formatting
 * output back to the browser.
 */
#undef AMP
#undef LT
#undef GT
#undef BR
#undef H1_
#undef _H1
#undef B_
#undef _B
#undef UL_
#undef _UL

#define AMP (( (CTHIS GetContentType()==CTHIS GetContentTypeHTML()) || (CTHIS GetContentType()==CTHIS GetContentTypeXML()) )?"&amp;":"&")
#define LT (( (CTHIS GetContentType()==CTHIS GetContentTypeHTML()) || (CTHIS GetContentType()==CTHIS GetContentTypeXML()) )?"&lt;":"<")
#define GT (( (CTHIS GetContentType()==CTHIS GetContentTypeHTML()) || (CTHIS GetContentType()==CTHIS GetContentTypeXML()) )?"&gt;":">")
#define BR (( (CTHIS GetContentType()==CTHIS GetContentTypeHTML()) || (CTHIS GetContentType()==CTHIS GetContentTypeXML()) )?"<br>\n":"\n")
#define H1_ (( (CTHIS GetContentType()==CTHIS GetContentTypeHTML()) || (CTHIS GetContentType()==CTHIS GetContentTypeXML()) )?"<h1>\n":"")
#define _H1 (( (CTHIS GetContentType()==CTHIS GetContentTypeHTML()) || (CTHIS GetContentType()==CTHIS GetContentTypeXML()) )?"</h1>\n":"\n\n")
#define B_ (( (CTHIS GetContentType()==CTHIS GetContentTypeHTML()) || (CTHIS GetContentType()==CTHIS GetContentTypeXML()) )?"<b>":"")
#define _B (( (CTHIS GetContentType()==CTHIS GetContentTypeHTML()) || (CTHIS GetContentType()==CTHIS GetContentTypeXML()) )?"</b>":"")
#define UL_ (( (CTHIS GetContentType()==CTHIS GetContentTypeHTML()) || (CTHIS GetContentType()==CTHIS GetContentTypeXML()) )?"<ul>":"")
#define _UL (( (CTHIS GetContentType()==CTHIS GetContentTypeHTML()) || (CTHIS GetContentType()==CTHIS GetContentTypeXML()) )?"</ul>":"\n")
#define LI_ (( (CTHIS GetContentType()==CTHIS GetContentTypeHTML()) || (CTHIS GetContentType()==CTHIS GetContentTypeXML()) )?"<li>":"")
#define _LI (( (CTHIS GetContentType()==CTHIS GetContentTypeHTML()) || (CTHIS GetContentType()==CTHIS GetContentTypeXML()) )?"</li>":"\n")

#if defined(__cplusplus)
extern "C" {
#endif /* defined(__cplusplus) */

#if defined(__cplusplus)
}
#endif /* defined(__cplusplus) */

#endif /* _HTMLMACRO_H */
