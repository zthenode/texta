///////////////////////////////////////////////////////////////////////
// Copyright (c) 1988-2012 $organization$
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
//   File: cCgiMainCgiContentStream.hpp
//
// Author: $author$
//   Date: 11/23/2012
///////////////////////////////////////////////////////////////////////
#ifndef _CCGIMAINCGICONTENTSTREAM_HPP
#define _CCGIMAINCGICONTENTSTREAM_HPP

#include "cCgiMain.hpp"
#include "cCgiContentStream.hpp"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

///////////////////////////////////////////////////////////////////////
// Typedef: cCgiMainCgiContentStreamImplement
//
//  Author: $author$
//    Date: 11/23/2012
///////////////////////////////////////////////////////////////////////
typedef cCgiContentStreamImplement
cCgiMainCgiContentStreamImplement;
///////////////////////////////////////////////////////////////////////
// Typedef: cCgiMainCgiContentStreamExtend
//
//  Author: $author$
//    Date: 11/23/2012
///////////////////////////////////////////////////////////////////////
typedef cCgiContentStream
cCgiMainCgiContentStreamExtend;
///////////////////////////////////////////////////////////////////////
//  Class: cCgiMainCgiContentStream
//
// Author: $author$
//   Date: 11/23/2012
///////////////////////////////////////////////////////////////////////
class c_EXPORT_CLASS cCgiMainCgiContentStream
: virtual public cCgiMainCgiContentStreamImplement,
  public cCgiMainCgiContentStreamExtend
{
public:
    typedef cCgiMainCgiContentStreamImplement cImplements;
    typedef cCgiMainCgiContentStreamExtend cExtends;

    cCgiMain& m_cgiMain;

    ///////////////////////////////////////////////////////////////////////
    //  Constructor: cCgiMainCgiContentStream
    //
    //       Author: $author$
    //         Date: 11/23/2012
    ///////////////////////////////////////////////////////////////////////
    cCgiMainCgiContentStream
    (cCgiMain& cgiMain)
    : m_cgiMain(cgiMain)
    {
    }
    ///////////////////////////////////////////////////////////////////////
    //  Destructor: ~cCgiMainCgiContentStream
    //
    //      Author: $author$
    //        Date: 11/23/2012
    ///////////////////////////////////////////////////////////////////////
    virtual ~cCgiMainCgiContentStream()
    {
    }

    ///////////////////////////////////////////////////////////////////////
    //  Function: SetContentType
    //
    //    Author: $author$
    //      Date: 6/25/2011
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t SetContentType
    (const cString& contentType)
    {
        ssize_t count = 0;
        m_cgiMain.SetContentType(contentType.c_str());
        return count;
    }
    ///////////////////////////////////////////////////////////////////////
    //  Function: GetContentType
    //
    //    Author: $author$
    //      Date: 8/20/2013
    ///////////////////////////////////////////////////////////////////////
    virtual cString GetContentType() const
    {
        cString type(m_cgiMain.GetContentType());
        return type;
    }
    ///////////////////////////////////////////////////////////////////////
    //  Function: Write
    //
    //    Author: $author$
    //      Date: 11/23/2012
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t Write
    (const char* chars, ssize_t length=-1)
    {
        ssize_t count = m_cgiMain.OutputContent(chars, length);
        return count;
    }
    ///////////////////////////////////////////////////////////////////////
    //  Function: WriteFormattedV
    //
    //    Author: $author$
    //      Date: 11/23/2012
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t WriteFormattedV
    (const char_t* format,
     va_list va)
    {
        ssize_t count = m_cgiMain.OutputContentFormattedV(format, va);
        return count;
    }
};


#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#endif // _CCGIMAINCGICONTENTSTREAM_HPP 
        

