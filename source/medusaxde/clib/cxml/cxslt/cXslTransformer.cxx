/**
 **********************************************************************
 * Copyright (c) 1988-2017 $organization$
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
 *   File: cXslTransformer.cxx
 *
 * Author: $author$
 *   Date: 12/11/2017
 **********************************************************************
 */
#include "cXslTransformer.hxx"

/**
 **********************************************************************
 *  Class: cXslTransformer
 *
 * Author: $author$
 *   Date: 12/11/2017
 **********************************************************************
 */

/**
 **********************************************************************
 *  Class: cXSLTransformerInterface
 *
 * Author: $author$
 *   Date: 12/11/2017
 **********************************************************************
 */
/**
 **********************************************************************
 * Function: CreateInstance
 *
 *   Author: $author$
 *     Date: 12/11/2017
 **********************************************************************
 */
cXSLTransformerInterface* cXSLTransformerInterface::
CreateInstance(eError &error)
{
    cXslTransformer* xslt = 0;
    if ((xslt = new cXslTransformer())) {
        error = e_ERROR_NONE;
    } else {
        error = e_ERROR_NEW;
    }
    return xslt;
}
/**
 **********************************************************************
 * Function: DestroyInstance
 *
 *   Author: $author$
 *     Date: 3/13/2008
 **********************************************************************
 */
eError cXSLTransformerInterface::
DestroyInstance(cXSLTransformerInterface* instance)
{
    eError error = e_ERROR_FAILED;
    if ((instance)) {
        delete instance;
        error = e_ERROR_NONE;
    }
    return error;
}
