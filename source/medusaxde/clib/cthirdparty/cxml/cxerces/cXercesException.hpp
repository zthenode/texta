///////////////////////////////////////////////////////////////////////
// Copyright (c) 1988-2011 $organization$
//
// This software is provided by the author and contributors ``as is'' 
// and any express or implied warranties, including, but not limited to, 
// the implied warranties of merchantability and fitness for a particular 
// purpose are disclaimed. In no event shall the author or contributors 
// be liable for any direct, indirect, incidental, special, exemplary, 
// or consequential damages (including, but not limited to, procurement 
// of substitute goods or services; loss of use, data, or profits; or 
// business interruption) however caused and on any theory of liability, 
// whether in contract, strict liability, or tort (including negligence 
// or otherwise) arising in any way out of the use of this software, 
// even if advised of the possibility of such damage.
//
//   File: cXercesException.hpp
//
// Author: $author$
//   Date: 7/18/2011
///////////////////////////////////////////////////////////////////////
#ifndef _CXERCESEXCEPTION_HPP
#define _CXERCESEXCEPTION_HPP

#include <sax/SAXParseException.hpp>
#include <util/XMLString.hpp>
#include "nsXerces.hpp"
#include "cCharWriterInterface.hpp"
#include "cStringInterface.hpp"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

///////////////////////////////////////////////////////////////////////
//    Enum: eXercesException
//
//  Author: $author$
//    Date: 7/18/2011
///////////////////////////////////////////////////////////////////////
typedef int eXercesExceptionType;
enum
{
    e_FIRST_XERCES_EXCEPTION_TYPE = 1,

    e_XERCES_EXCEPTION_TYPE_WARNING = e_FIRST_XERCES_EXCEPTION_TYPE,
    e_XERCES_EXCEPTION_TYPE_ERROR,
    e_XERCES_EXCEPTION_TYPE_FATAL_ERROR,

    e_NEXT_XERCES_EXCEPTION_TYPE,
    e_LAST_XERCES_EXCEPTION_TYPE = e_NEXT_XERCES_EXCEPTION_TYPE-1,
    e_COUNT_XERCES_EXCEPTION_TYPE = e_LAST_XERCES_EXCEPTION_TYPE-e_FIRST_XERCES_EXCEPTION_TYPE+1
};

#define e_XERCES_EXCEPTION_TYPE_NAME_NONE ""
#define e_XERCES_EXCEPTION_TYPE_NAME_WARNING "WARNING"
#define e_XERCES_EXCEPTION_TYPE_NAME_ERROR "ERROR"
#define e_XERCES_EXCEPTION_TYPE_NAME_FATAL_ERROR "FATAL_ERROR"

///////////////////////////////////////////////////////////////////////
//  Class: cXercesException
//
// Author: $author$
//   Date: 7/18/2011
///////////////////////////////////////////////////////////////////////
class c_INSTANCE_CLASS cXercesException
{
public:

    eXercesExceptionType m_type;
    nsXerces::SAXParseException m_parseException;

    ///////////////////////////////////////////////////////////////////////
    //  Constructor: cXercesException
    //
    //       Author: $author$
    //         Date: 7/18/2011
    ///////////////////////////////////////////////////////////////////////
    cXercesException    
    (eXercesExceptionType type,
     const nsXerces::SAXParseException& parseException) 
    : m_type(type),
      m_parseException(parseException)
    {
    }
    ///////////////////////////////////////////////////////////////////////
    //  Constructor: cXercesException
    //
    //       Author: $author$
    //         Date: 7/18/2011
    ///////////////////////////////////////////////////////////////////////
    cXercesException    
   (const cXercesException& exception) 
    : m_type(exception.m_type),
      m_parseException(exception.m_parseException)
    {
    }
    ///////////////////////////////////////////////////////////////////////
    //  Destructor: ~cXercesException
    //
    //      Author: $author$
    //        Date: 7/18/2011
    ///////////////////////////////////////////////////////////////////////
    virtual ~cXercesException()
    {
    }
    ///////////////////////////////////////////////////////////////////////
    //  Function: Append
    //
    //    Author: $author$
    //      Date: 7/18/2011
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t Append
    (cStringInterface& toString)
    {
        ssize_t length = 0;
        ssize_t count = 0;
        const XMLCh* xmlchs;
        XMLCh xmlch;
        char ch[2];

        if ((xmlchs = m_parseException.getMessage()))
        for (ch[1] = 0; (xmlch = xmlchs[length]); length += count)
        {
            nsXerces::XMLString::transcode(&xmlch, ch, 1);
            if (0 > (count = toString.Append(ch, 1)))
                return count;
        }
        return length;
    }
    ///////////////////////////////////////////////////////////////////////
    //  Function: Write
    //
    //    Author: $author$
    //      Date: 7/18/2011
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t Write
    (cCharWriterInterface& writer) const
    {
        ssize_t length = 0;
        ssize_t count = 0;
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
    ///////////////////////////////////////////////////////////////////////
    //  Function: TypeName
    //
    //    Author: $author$
    //      Date: 7/18/2011
    ///////////////////////////////////////////////////////////////////////
    static const char* TypeName
    (eXercesExceptionType type)
    {
        static const char* typeName[e_COUNT_XERCES_EXCEPTION_TYPE] = 
        {
            e_XERCES_EXCEPTION_TYPE_NAME_WARNING,
            e_XERCES_EXCEPTION_TYPE_NAME_ERROR,
            e_XERCES_EXCEPTION_TYPE_NAME_FATAL_ERROR
        };
        const char* chars = e_XERCES_EXCEPTION_TYPE_NAME_NONE;
        if ((e_FIRST_XERCES_EXCEPTION_TYPE <= type) 
            && (e_LAST_XERCES_EXCEPTION_TYPE >= type))
            chars = typeName[type];
        return chars;
    }
};

#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#endif // _CXERCESEXCEPTION_HPP 
        

