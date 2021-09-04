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
 *   File: csemaphore.cxx
 *
 * Author: $author$
 *   Date: 2/5/2008
 **********************************************************************
 */
#include "csemaphore.hxx"
#include "csemaphoreinterface.hxx"

/**
 **********************************************************************
 *  Class: cSemaphoreInterface
 *
 * Author: $author$
 *   Date: 2/5/2008
 **********************************************************************
 */
/**
 **********************************************************************
 * Function: cSemaphoreInterface::CreateInstance
 *
 *   Author: $author$
 *     Date: 2/5/2008
 **********************************************************************
 */
cSemaphoreInterface* 
cSemaphoreInterface::CreateInstance(eError& error) 
{
    cSemaphoreInterface* instance = 0;
    error = e_ERROR_FAILED;
    if ((instance = new cSemaphore))
        error = e_ERROR_NONE;
    return instance;
}
/**
 **********************************************************************
 * Function: cSemaphoreInterface::DestroyInstance
 *
 *   Author: $author$
 *     Date: 2/5/2008
 **********************************************************************
 */
eError cSemaphoreInterface::DestroyInstance
(cSemaphoreInterface& instance) 
{
    eError error = instance.DeleteInstance();
    return error;
}
