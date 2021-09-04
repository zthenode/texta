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
//   File: cCgiccMainCgiContentStream.hpp
//
// Author: $author$
//   Date: 6/25/2011
///////////////////////////////////////////////////////////////////////
#if !defined(_CCGICCMAINCGICONTENTSTREAM_HPP) || defined(CCGICCMAINCGICONTENTSTREAM_MEMBERS_ONLY)
#if !defined(_CCGICCMAINCGICONTENTSTREAM_HPP) && !defined(CCGICCMAINCGICONTENTSTREAM_MEMBERS_ONLY)
#define _CCGICCMAINCGICONTENTSTREAM_HPP
#endif // !defined(_CCGICCMAINCGICONTENTSTREAM_HPP) && !defined(CCGICCMAINCGICONTENTSTREAM_MEMBERS_ONLY) 

#if !defined(CCGICCMAINCGICONTENTSTREAM_MEMBERS_ONLY)
#include "cCgiccMainInterface.hpp"
#include "cCgiContentStream.hpp"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

///////////////////////////////////////////////////////////////////////
// Typedef: cCgiccMainCgiContentStreamExtend
//
//  Author: $author$
//    Date: 6/25/2011
///////////////////////////////////////////////////////////////////////
typedef cCgiContentStream
cCgiccMainCgiContentStreamExtend;
///////////////////////////////////////////////////////////////////////
//  Class: cCgiccMainCgiContentStream
//
// Author: $author$
//   Date: 6/25/2011
///////////////////////////////////////////////////////////////////////
class c_INSTANCE_CLASS cCgiccMainCgiContentStream
: //virtual public cCgiccMainCgiContentStreamImplement,
  public cCgiccMainCgiContentStreamExtend
{
public:
    //typedef cCgiccMainCgiContentStreamImplement cImplements;
    typedef cCgiccMainCgiContentStreamExtend cExtends;

    cCgiccMainInterface& m_ccgiccMain;

    ///////////////////////////////////////////////////////////////////////
    //  Constructor: cCgiccMainCgiContentStream
    //
    //       Author: $author$
    //         Date: 6/25/2011
    ///////////////////////////////////////////////////////////////////////
    cCgiccMainCgiContentStream
    (cCgiccMainInterface& ccgiccMain)
    : m_ccgiccMain(ccgiccMain)
    {
    }
    ///////////////////////////////////////////////////////////////////////
    //  Destructor: ~cCgiccMainCgiContentStream
    //
    //      Author: $author$
    //        Date: 6/25/2011
    ///////////////////////////////////////////////////////////////////////
    virtual ~cCgiccMainCgiContentStream()
    {
    }
#else // !defined(CCGICCMAINCGICONTENTSTREAM_MEMBERS_ONLY) 
#endif // !defined(CCGICCMAINCGICONTENTSTREAM_MEMBERS_ONLY) 

#if !defined(CCGICCMAINCGICONTENTSTREAM_MEMBERS_ONLY)
    ///////////////////////////////////////////////////////////////////////
    //  Function: SetContentType
    //
    //    Author: $author$
    //      Date: 6/25/2011
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t SetContentType
    (const cString& contentType)
    {
        ssize_t count = m_ccgiccMain.SetContentType(contentType);
        return count;
    }
    ///////////////////////////////////////////////////////////////////////
    //  Function: Write
    //
    //    Author: $author$
    //      Date: 6/25/2011
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t Write
    (const char* chars, ssize_t length=-1)
    {
        ssize_t count = m_ccgiccMain.OutputContent(chars, length);
        return count;
    }
    ///////////////////////////////////////////////////////////////////////
    //  Function: WriteFormattedV
    //
    //    Author: $author$
    //      Date: 8/12/2011
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t WriteFormattedV
    (const char_t* format,
     va_list va)
    {
        ssize_t count = m_ccgiccMain.OutputContentFormattedV(format, va);
        return count;
    }
};


#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#else // !defined(CCGICCMAINCGICONTENTSTREAM_MEMBERS_ONLY) 
#endif // !defined(CCGICCMAINCGICONTENTSTREAM_MEMBERS_ONLY) 

#endif // !defined(_CCGICCMAINCGICONTENTSTREAM_HPP) || defined(CCGICCMAINCGICONTENTSTREAM_MEMBERS_ONLY) 
        

