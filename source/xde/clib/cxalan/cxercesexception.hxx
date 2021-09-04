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
 *   File: cxercesexception.hxx
 *
 * Author: $author$
 *   Date: 3/10/2008
 **********************************************************************
 */
#ifndef _CXERCESEXCEPTION_HXX
#define _CXERCESEXCEPTION_HXX

#include <sax/SAXParseException.hpp>
#include <util/XMLString.hpp>

#include "nsxerces.hxx"
#include "cstring.hxx"
#include "cbase.hxx"
#include "cerror.h"

/**
 **********************************************************************
 *   Enum:  eXercesExceptionType
 *
 * Author: $author$
 *   Date: 3/10/2008
 **********************************************************************
 */
typedef int eXercesExceptionType;
enum
{
    e_FIRST_XERCES_EXCEPTION_TYPE,

    e_XERCES_EXCEPTION_TYPE_WARNING,
    e_XERCES_EXCEPTION_TYPE_ERROR,
    e_XERCES_EXCEPTION_TYPE_FATAL_ERROR,

    e_NEXT_XERCES_EXCEPTION_TYPE,
    e_LAST_XERCES_EXCEPTION_TYPE = e_NEXT_XERCES_EXCEPTION_TYPE-1,
    e_COUNT_XERCES_EXCEPTION_TYPE = e_LAST_XERCES_EXCEPTION_TYPE-e_FIRST_XERCES_EXCEPTION_TYPE+1
};

#define e_XERCES_EXCEPTION_TYPE_NAME_WARNING "WARNING"
#define e_XERCES_EXCEPTION_TYPE_NAME_ERROR "ERROR"
#define e_XERCES_EXCEPTION_TYPE_NAME_FATAL_ERROR "FATAL_ERROR"

/**
 **********************************************************************
 *  Class: cXercesException
 *
 * Author: $author$
 *   Date: 3/10/2008
 **********************************************************************
 */
class cXercesException
: public cBase
{
public:
    typedef cBase cExtends;
    typedef cXercesException cDerives;

    eXercesExceptionType m_type;
    nsXerces::SAXParseException m_parseException;

    /**
     **********************************************************************
     * Constructor: cXercesException
     *
     *      Author: $author$
     *        Date: 3/10/2008
     **********************************************************************
     */
    cXercesException
    (eXercesExceptionType type,
     const nsXerces::SAXParseException& parseException) 
    : m_type(type),
      m_parseException(parseException)
    {
    }
    /**
     **********************************************************************
     * Constructor: cXercesException
     *
     *      Author: $author$
     *        Date: 3/10/2008
     **********************************************************************
     */
    cXercesException
    (const cXercesException& exception) 
    : m_type(exception.m_type),
      m_parseException(exception.m_parseException)
    {
    }
    /**
     **********************************************************************
     * Destructor: cXercesException
     *
     *     Author: $author$
     *       Date: 3/10/2008
     **********************************************************************
     */
    virtual ~cXercesException()
    {
    }
    /**
     **********************************************************************
     * Function: ToString
     *
     *   Author: $author$
     *     Date: 3/10/2008
     **********************************************************************
     */
    virtual TLENGTH ToString
    (cCharString& string) 
    {
        TLENGTH length = Write(string);
        return length;
    }
    /**
     **********************************************************************
     * Function: Write
     *
     *   Author: $author$
     *     Date: 3/15/2008
     **********************************************************************
     */
    virtual TLENGTH Write
    (cCharWriterInterface& writer) 
    {
        TLENGTH length = 0;
        TLENGTH count;
        const XMLCh* xmlchs;
        XMLCh xmlch;
        char ch[2];

        if ((xmlchs = m_parseException.getMessage()))
        for (ch[1] = 0; (xmlch = xmlchs[length]); length += count)
        {
            nsXerces::XMLString::transcode(&xmlch, ch, 1);
            if (0 > (count = writer.Write(ch, 1)))
                return count;
        }
        return length;
    }
};

extern const char* g_xercesExceptionTypeName[e_COUNT_XERCES_EXCEPTION_TYPE];

#endif /* _CXERCESEXCEPTION_HXX */
