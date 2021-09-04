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
 *   File: cxerceserrorhandler.hxx
 *
 * Author: $author$
 *   Date: 3/10/2008
 **********************************************************************
 */
#ifndef _CXERCESERRORHANDLER_HXX
#define _CXERCESERRORHANDLER_HXX

#include <sax/ErrorHandler.hpp>
#include <sax/SAXParseException.hpp>
#include <util/XMLString.hpp>

#include "cxercesexception.hxx"

/**
 **********************************************************************
 *  Class: cXercesErrorHandler
 *
 * Author: $author$
 *   Date: 3/10/2008
 **********************************************************************
 */
class cXercesErrorHandler
: public nsXerces::ErrorHandler
{
public:
    typedef nsXerces::ErrorHandler cExtends;
    typedef cXercesErrorHandler cDerives;

    /**
     **********************************************************************
     * Constructor: cXercesErrorHandler
     *
     *      Author: $author$
     *        Date: 3/10/2008
     **********************************************************************
     */
    cXercesErrorHandler() 
    {
    }
    /**
     **********************************************************************
     * Destructor: cXercesErrorHandler
     *
     *     Author: $author$
     *       Date: 3/10/2008
     **********************************************************************
     */
    virtual ~cXercesErrorHandler()
    {
    }
    /**
     **********************************************************************
     * Function: warning
     *
     *   Author: $author$
     *     Date: 3/10/2008
     **********************************************************************
     */
    virtual void warning
    (const nsXerces::SAXParseException& exception) 
    {
        cXercesException cexception
        (e_XERCES_EXCEPTION_TYPE_WARNING, exception);
        throw(cexception);
    }
    /**
     **********************************************************************
     * Function: error
     *
     *   Author: $author$
     *     Date: 3/10/2008
     **********************************************************************
     */
    virtual void error
    (const nsXerces::SAXParseException& exception) 
    {
        cXercesException cexception
        (e_XERCES_EXCEPTION_TYPE_ERROR, exception);
        throw(cexception);
    }
    /**
     **********************************************************************
     * Function: fatalError
     *
     *   Author: $author$
     *     Date: 3/10/2008
     **********************************************************************
     */
    virtual void fatalError
    (const nsXerces::SAXParseException& exception) 
    {
        cXercesException cexception
        (e_XERCES_EXCEPTION_TYPE_FATAL_ERROR, exception);
        throw(cexception);
    }
    /**
     **********************************************************************
     * Function: resetErrors
     *
     *   Author: $author$
     *     Date: 3/10/2008
     **********************************************************************
     */
    virtual void resetErrors() 
    {
    }
};
#endif /* _CXERCESERRORHANDLER_HXX */
