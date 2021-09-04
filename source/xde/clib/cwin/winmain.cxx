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
 *   File: winmain.cxx
 *
 * Author: $author$
 *   Date: 4/28/2008
 **********************************************************************
 */

#include "cwinmain.hxx"
#include "cdebug.hxx"

/**
 **********************************************************************
 *    Function: WinMain
 *
 *      Author: $author$
 *        Date: 1/23/2004
 **********************************************************************
 */
int WINAPI WinMain
(HINSTANCE instance, HINSTANCE previnst, 
 LPCMDLINE cmdline, int cmdshow)
{
    int result = 1;
    cWinMain* winMain;

    if ((winMain = cWinMain::GetWinMain()))
        result = winMain->WinMain
        (instance, previnst, cmdline, cmdshow);
    else
    DBE("() cWinMain::GetWinMain() returned 0\n");
    return result;
}
