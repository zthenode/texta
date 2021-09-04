/**
 **********************************************************************
 * Copyright (c) 1988-2020 $organization$
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
 *   File: ctliteralfunction.cxx
 *
 * Author: $author$
 *   Date: 5/14/2020
 **********************************************************************
 */
#include "ctliteralfunction.hxx"

/**
 **********************************************************************
 * Class: cTLiteralFunction
 *
 * Author: $author$
 *   Date: 5/14/2020
 **********************************************************************
 */
cTLiteralFunction 
    g_aposFunction("apos","apos(...)","\'"),
    g_bquotFunction("bpos","bpos(...)","\`"),
    g_quotFunction("quot","quot(...)","\"");

cTAfterLiteralFunction 
    g_lfFunction("cr","cr(...)","\r"),
    g_crFunction("lf","lf(...)","\n"),
    g_lnFunction("ln","ln(...)","\r\n");
