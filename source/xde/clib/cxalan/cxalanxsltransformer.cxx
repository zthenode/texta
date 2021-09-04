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
 *   File: cxalanxsltransformer.cxx
 *
 * Author: $author$
 *   Date: 3/13/2008
 **********************************************************************
 */

#include "cxalanxsltransformer.hxx"

/**
 **********************************************************************
 *  Class: cXSLTransformerInterface
 *
 * Author: $author$
 *   Date: 3/13/2008
 **********************************************************************
 */

/**
 **********************************************************************
 * Function: cXSLTransformerInterface::CreateInstance
 *
 *   Author: $author$
 *     Date: 3/13/2008
 **********************************************************************
 */
cXSLTransformerInterface* 
cXSLTransformerInterface::CreateInstance(eError& error) 
{
    cXSLTransformerInterface* instance = 0;
    if ((instance = new cXalanXSLTransformer(false)))
        error = e_ERROR_NONE;
    else error = e_ERROR_NEW;
    return instance;
}
/**
 **********************************************************************
 * Function: cXSLTransformerInterface::DestroyInstance
 *
 *   Author: $author$
 *     Date: 3/13/2008
 **********************************************************************
 */
eError cXSLTransformerInterface::DestroyInstance
(cXSLTransformerInterface& instance) 
{
    eError error = instance.DeleteInstance(true);
    return error;
}

/**
 **********************************************************************
 *  Class: cXalanXSLTransformer
 *
 * Author: $author$
 *   Date: 3/13/2008
 **********************************************************************
 */
