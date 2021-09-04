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
//   File: cXalanXSLTInputSource.hpp
//
// Author: $author$
//   Date: 7/19/2011
///////////////////////////////////////////////////////////////////////
#ifndef _CXALANXSLTINPUTSOURCE_HPP
#define _CXALANXSLTINPUTSOURCE_HPP

#include <XSLT/XSLTInputSource.hpp>
#include <XalanDOM/XalanDOMString.hpp>
#include "nsXalan.hpp"
#include "cXercesBinInputStream.hpp"
#include "cDebug.hpp"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

///////////////////////////////////////////////////////////////////////
// Typedef: cXalanXSLTInputSourceExtend
//
//  Author: $author$
//    Date: 7/19/2011
///////////////////////////////////////////////////////////////////////
typedef nsXalan::XSLTInputSource
cXalanXSLTInputSourceExtend;
///////////////////////////////////////////////////////////////////////
//  Class: cXalanXSLTInputSource
//
// Author: $author$
//   Date: 7/19/2011
///////////////////////////////////////////////////////////////////////
class c_INSTANCE_CLASS cXalanXSLTInputSource
: //virtual public cXalanXSLTInputSourceImplement,
  public cXalanXSLTInputSourceExtend
{
public:
    //typedef cXalanXSLTInputSourceImplement cImplements;
    typedef cXalanXSLTInputSourceExtend cExtends;

    cCharReaderInterface& m_reader;
    cString m_fileName;

    ///////////////////////////////////////////////////////////////////////
    //  Constructor: cXalanXSLTInputSource
    //
    //       Author: $author$
    //         Date: 7/19/2011
    ///////////////////////////////////////////////////////////////////////
    cXalanXSLTInputSource
    (cCharReaderInterface& reader,
     const char* fileNameChars=0) 
    : m_reader(reader),
      m_fileName(fileNameChars)
    {
        if ((fileNameChars = m_fileName.HasChars()))
        {
            nsXalan::XalanDOMString systemId(fileNameChars);
            const nsXalan::XalanDOMChar* systemIdChars;
            if ((systemIdChars = systemId.c_str()))
                setSystemId(systemIdChars);
        }
    }

    ///////////////////////////////////////////////////////////////////////
    //  Function: makeStream
    //
    //    Author: $author$
    //      Date: 7/19/2011
    ///////////////////////////////////////////////////////////////////////
    virtual nsXerces::BinInputStream* makeStream() const
    {
        cXercesBinInputStream* stream = 0;
        if (!(stream = new cXercesBinInputStream(m_reader)))
            c_DB_ERROR("() failed on new cXercesBinInputStream()");
        return stream;
    }
};


#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#endif // _CXALANXSLTINPUTSOURCE_HPP 
        

