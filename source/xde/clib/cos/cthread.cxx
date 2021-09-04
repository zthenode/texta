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
 *   File: cthread.cxx
 *
 * Author: $author$
 *   Date: 2/14/2008
 **********************************************************************
 */
#include "cthread.hxx"
/**
 **********************************************************************
 *  Class: cInterface
 *
 * Author: $author$
 *   Date: 2/14/2008
 **********************************************************************
 */
/**
 **********************************************************************
 * Function: cInterface::CreateInstance
 *
 *   Author: $author$
 *     Date: 2/14/2008
 **********************************************************************
 */
cThreadInterface* 
cThreadInterface::CreateInstance(eError& error) 
{
    cThreadInterface* instance = 0;
    if ((instance = new cThread))
        error = e_ERROR_NONE;
    else error = e_ERROR_FAILED;
    return instance;
}
/**
 **********************************************************************
 * Function: cInterface::DestroyInstance
 *
 *   Author: $author$
 *     Date: 2/14/2008
 **********************************************************************
 */
eError cThreadInterface::DestroyInstance
(cThreadInterface& instance) 
{
    eError error = instance.DeleteInstance();
    return error;
}
