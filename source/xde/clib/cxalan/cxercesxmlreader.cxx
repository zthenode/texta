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
 *   File: cxercesxmlreader.cxx
 *
 * Author: $author$
 *   Date: 3/15/2008
 **********************************************************************
 */

#include "cxercesxmlreader.hxx"

/**
 **********************************************************************
 *  Class: cXMLReaderInterface
 *
 * Author: $author$
 *   Date: 3/15/2008
 **********************************************************************
 */

/**
 **********************************************************************
 * Function: cXMLReaderInterface::CreateInstance
 *
 *   Author: $author$
 *     Date: 3/15/2008
 **********************************************************************
 */
cXMLReaderInterface* 
cXMLReaderInterface::CreateInstance(eError& error) 
{
    cXMLReaderInterface* instance = 0;
    if ((instance = new cXercesXMLReader(false)))
        error = e_ERROR_NONE;
    else error = e_ERROR_NEW;
    return instance;
}
/**
 **********************************************************************
 * Function: cXMLReaderInterface::DestroyInstance
 *
 *   Author: $author$
 *     Date: 3/15/2008
 **********************************************************************
 */
eError cXMLReaderInterface::DestroyInstance
(cXMLReaderInterface& instance) 
{
    eError error = instance.DeleteInstance();
    return error;
}

/**
 **********************************************************************
 *  Class: cXercesXMLReader
 *
 * Author: $author$
 *   Date: 3/15/2008
 **********************************************************************
 */
