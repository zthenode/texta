/**
 **********************************************************************
 * Copyright (c) 1988-2007 $organization$
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
 *   File: main.cxx
 *
 * Author: $author$
 *   Date: 2/13/2007
 *
 *    $Id$
 **********************************************************************
 */

#include "cmain.hxx"
#include "cdebug.hxx"

/**
 **********************************************************************
 * Function: main
 *
 *   Author: $author$
 *     Date: 2/13/2007
 **********************************************************************
 */
int main(int argc, char** argv, char** env)
{
    DF(main)
    int err = 0;
    cMainInterface* theMain;

    SET_DEBUG_LEVELS(DEFAULT_DEBUG_LEVELS);

    DBF("() in...\n");

    if ((theMain = theMain->GetMain()))
        err = theMain->Main(argc, argv, env);
    else DBW("() GetMain() returned 0\n");

    DBF("() ...out\n");
    return err;
}
