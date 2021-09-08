///////////////////////////////////////////////////////////////////////
//   File: cevcpheaderheading.hpp
//
// Author: $author$
//   Date: 4/19/2007
//
//    $Id$
///////////////////////////////////////////////////////////////////////

#ifndef _CEVCPHEADERHEADING_HPP
#define _CEVCPHEADERHEADING_HPP

#include "evcpheaderheading.hpp"
#include "cevcpheaderline.hpp"
#include "cevcpheaderheadingwriter.hpp"
#include "cevcpheaderheadingevents.hpp"
#include "cevstringwriter.hpp"
#include "cevstringreader.hpp"
#include "cevstring.hpp"
#include "evdebug.h"

///////////////////////////////////////////////////////////////////////
//  Class: CEvcpHeaderHeading
//
// Author: $author$
//   Date: 4/18/2007
///////////////////////////////////////////////////////////////////////
class CEvcpHeaderHeading
: virtual public EvcpHeaderHeading,
  virtual public EvcpHeaderHeadingEvents,
  public CEvcpHeaderLine
{
public:
    typedef EvcpHeaderHeadingEvents CImplements;
    typedef CEvcpHeaderLine CExtends;
    typedef CEvcpHeaderHeading CDerives;

    static const char m_space;
    static const char m_slash;
    static const char m_dot;

    CEvStringReader m_stringReader;
    CEvStringWriter m_stringWriter;
    CEvcpHeaderHeadingWriter m_headingWriter;

    bool m_isResponse;

    CEvString m_protocol;
    CEvString m_protocolVersionMajor;
    CEvString m_protocolVersionMinor;

    CEvString m_requestAction;
    CEvString m_requestPath;

    CEvString m_responseStatus;
    CEvString m_responseDescription;
    
    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvcpHeaderHeading
    //
    //       Author: $author$
    //         Date: 4/19/2007
    ///////////////////////////////////////////////////////////////////////
    CEvcpHeaderHeading() 
    : m_stringReader(*this),
      m_stringWriter(*this),
      m_headingWriter(*this),
      m_isResponse(false)
    {
    }
    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvcpHeaderHeading
    //
    //       Author: $author$
    //         Date: 4/19/2007
    ///////////////////////////////////////////////////////////////////////
    CEvcpHeaderHeading(const CEvcpHeaderHeading& heading) 
    : m_stringReader(*this),
      m_stringWriter(*this),
      m_headingWriter(*this),
      m_isResponse(false),
      m_protocol(heading.GetProtocol()),
      m_protocolVersionMajor(heading.GetProtocolVersionMajor()),
      m_protocolVersionMinor(heading.GetProtocolVersionMinor())
    {
    }
    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvcpHeaderHeading
    //
    //       Author: $author$
    //         Date: 4/19/2007
    ///////////////////////////////////////////////////////////////////////
    CEvcpHeaderHeading(const EvcpHeaderHeading& heading) 
    : m_stringReader(*this),
      m_stringWriter(*this),
      m_headingWriter(*this),
      m_isResponse(false),
      m_protocol(heading.GetProtocol()),
      m_protocolVersionMajor(heading.GetProtocolVersionMajor()),
      m_protocolVersionMinor(heading.GetProtocolVersionMinor())
    {
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: Respond
    //
    //   Author: $author$
    //     Date: 4/20/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG Respond
    (EvCharWriter& writer, 
     const char* status,
     const char* description,
     LONG length=-1) 
    {
        LONG count = -EV_ERROR_FAILED;

        m_responseStatus.Assign(status);
        m_responseDescription.Assign(description);
        count = WriteResponse(writer, length);
        return count;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: Read
    //
    //   Author: $author$
    //     Date: 4/19/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG Read
    (EvCharReader& reader, LONG length=-1) 
    {
        LONG count = -EV_ERROR_FAILED;
        EvError error;

        DBT("() in...\n");

        if (0 < ClearAll())
            return -EV_ERROR_FAILED;

        if (0 < (count = ReadLine(reader, length)))
        if (0 > (length = m_stringReader.Reset()))
            return -EV_ERROR_FAILED;

        else if ((error = m_headingWriter.Initialize()))
                return -EV_ERROR_FAILED;

        else if (0 > (length = m_headingWriter.WriteReader(m_stringReader)))
                return -EV_ERROR_FAILED;

        else if ((error = m_headingWriter.Finalize()))
                return -EV_ERROR_FAILED;

        DBT("() ...out\n");
        return count;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: Write
    //
    //   Author: $author$
    //     Date: 5/19/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG Write
    (EvCharWriter& writer, LONG length=-1) 
    {
        LONG count = -EV_ERROR_FAILED;
        if (m_isResponse)
            count = WriteResponse(writer, length);
        else count = WriteRequest(writer, length);
        return count;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: WriteRequest
    //
    //   Author: $author$
    //     Date: 4/19/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG WriteRequest
    (EvCharWriter& writer, LONG length=-1) 
    {
        LONG count = -EV_ERROR_FAILED;
        LONG write, charsLength;
        const char* chars;

        if (0 <= (charsLength = ClearChars()))
        if ((chars = m_requestAction.Chars(charsLength)))
        if (0 < (write = m_stringWriter.Write(chars, charsLength)))
        if (0 < (write = m_stringWriter.Write(&m_space, 1)))
        if ((chars = m_requestPath.Chars(charsLength)))
        if (0 < (write = m_stringWriter.Write(chars, charsLength)))
        if (0 < (write = m_stringWriter.Write(&m_space, 1)))
        if ((chars = m_protocol.Chars(charsLength)))
        if (0 < (write = m_stringWriter.Write(chars, charsLength)))
        if (0 < (write = m_stringWriter.Write(&m_slash, 1)))
        if ((chars = m_protocolVersionMajor.Chars(charsLength)))
        if (0 < (write = m_stringWriter.Write(chars, charsLength)))
        if (0 < (write = m_stringWriter.Write(&m_dot, 1)))
        if ((chars = m_protocolVersionMinor.Chars(charsLength)))
        if (0 < (write = m_stringWriter.Write(chars, charsLength)))
            count = WriteLine(writer);
        return count;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: WriteResponse
    //
    //   Author: $author$
    //     Date: 4/19/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG WriteResponse
    (EvCharWriter& writer, LONG length=-1) 
    {
        LONG count = -EV_ERROR_FAILED;
        LONG write, charsLength;
        const char* chars;

        if (0 <= (charsLength = ClearChars()))
        if ((chars = m_protocol.Chars(charsLength)))
        if (0 < (write = m_stringWriter.Write(chars, charsLength)))
        if (0 < (write = m_stringWriter.Write(&m_slash, 1)))
        if ((chars = m_protocolVersionMajor.Chars(charsLength)))
        if (0 < (write = m_stringWriter.Write(chars, charsLength)))
        if (0 < (write = m_stringWriter.Write(&m_dot, 1)))
        if ((chars = m_protocolVersionMinor.Chars(charsLength)))
        if (0 < (write = m_stringWriter.Write(chars, charsLength)))
        if (0 < (write = m_stringWriter.Write(&m_space, 1)))
        if ((chars = m_responseStatus.Chars(charsLength)))
        if (0 < (write = m_stringWriter.Write(chars, charsLength)))
        if (0 < (write = m_stringWriter.Write(&m_space, 1)))
        if ((chars = m_responseDescription.Chars(charsLength)))
        if (0 < (write = m_stringWriter.Write(chars, charsLength)))
            count = WriteLine(writer);
        return count;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: ClearAll
    //
    //   Author: $author$
    //     Date: 5/17/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError ClearAll() 
    {
        EvError error = ClearRequest();
        EvError error2;
        LONG length;

        if ((error2 = ClearResponse()) && !error)
            error = error2;

        if ((error2 = ClearProtocol()) && !error)
            error = error2;

        if ((0 > (length = ClearLine())) && !error)
            error = -length;
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: ClearRequest
    //
    //   Author: $author$
    //     Date: 5/17/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError ClearRequest() 
    {
        EvError error = EV_ERROR_NONE;
        LONG length;
        if ((0 > (length = ClearRequestPath())) && !error)
            error = -length;
        if ((0 > (length = ClearRequestAction())) && !error)
            error = -length;
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: ClearRequestAction
    //
    //   Author: $author$
    //     Date: 5/17/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG ClearRequestAction() 
    {
        LONG length = m_requestAction.Clear();
        return length;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: ClearRequestPath
    //
    //   Author: $author$
    //     Date: 5/17/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG ClearRequestPath() 
    {
        LONG length = m_requestPath.Clear();
        return length;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: ClearResponse
    //
    //   Author: $author$
    //     Date: 5/17/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError ClearResponse() 
    {
        EvError error = EV_ERROR_NONE;
        LONG length;
        if ((0 > (length = ClearResponseDescription())) && !error)
            error = -length;
        if ((0 > (length = ClearResponseStatus())) && !error)
            error = -length;
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: ClearResponseStatus
    //
    //   Author: $author$
    //     Date: 5/17/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG ClearResponseStatus() 
    {
        LONG length = m_responseStatus.Clear();
        return length;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: ClearResponseDescription
    //
    //   Author: $author$
    //     Date: 5/17/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG ClearResponseDescription() 
    {
        LONG length = m_responseDescription.Clear();
        return length;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: ClearProtocol
    //
    //   Author: $author$
    //     Date: 5/17/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError ClearProtocol() 
    {
        EvError error = EV_ERROR_NONE;
        LONG length;

        if ((0 > (length = ClearProtocolVersionMinor())) && !error)
            error = -length;

        if ((0 > (length = ClearProtocolVersionMajor())) && !error)
            error = -length;

        if ((0 > (length = m_protocol.Clear())) && !error)
            error = -length;
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: ClearProtocolVersionMajor
    //
    //   Author: $author$
    //     Date: 5/17/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG ClearProtocolVersionMajor() 
    {
        LONG length = m_protocolVersionMajor.Clear();
        return length;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: ClearProtocolVersionMinor
    //
    //   Author: $author$
    //     Date: 5/17/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG ClearProtocolVersionMinor() 
    {
        LONG length = m_protocolVersionMinor.Clear();
        return length;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: CompareRequestPath
    //
    //   Author: $author$
    //     Date: 5/29/2007
    ///////////////////////////////////////////////////////////////////////
    virtual int CompareRequestPath
    (const char* tochars, LONG length=-1) const
    {
        int unequal = m_requestPath.Compare(tochars, length);
        return unequal;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: CompareResponseStatus
    //
    //   Author: $author$
    //     Date: 5/14/2007
    ///////////////////////////////////////////////////////////////////////
    virtual int CompareResponseStatus
    (const char* tochars, LONG length=-1) const
    {
        int unequal = m_responseStatus.Compare(tochars, length);
        return unequal;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: CompareUnsignedResponseStatus
    //
    //   Author: $author$
    //     Date: 5/14/2007
    ///////////////////////////////////////////////////////////////////////
    virtual int CompareUnsignedResponseStatus
    (ULONG tovalue) const
    {
        LONG length = -1;
        ULONG value = m_responseStatus.Unsigned(length);
        int unequal = 0;

        if (value > tovalue)
            unequal = 1;
        else if (value < tovalue)
                unequal = -1;
        return unequal;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: SetIsRequest
    //
    //   Author: $author$
    //     Date: 5/16/2007
    ///////////////////////////////////////////////////////////////////////
    virtual int SetIsRequest
    (bool is=true) 
    {
        m_isResponse = !is;
        return !m_isResponse;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: GetIsRequest
    //
    //   Author: $author$
    //     Date: 5/16/2007
    ///////////////////////////////////////////////////////////////////////
    virtual bool GetIsRequest() const 
    {
        return !m_isResponse;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: SetIsResponse
    //
    //   Author: $author$
    //     Date: 5/14/2007
    ///////////////////////////////////////////////////////////////////////
    virtual int SetIsResponse
    (bool is=true) 
    {
        m_isResponse = is;
        return m_isResponse;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: GetIsResponse
    //
    //   Author: $author$
    //     Date: 5/14/2007
    ///////////////////////////////////////////////////////////////////////
    virtual bool GetIsResponse() const 
    {
        return m_isResponse;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: SetProtocol
    //
    //   Author: $author$
    //     Date: 4/24/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG SetProtocol
    (const char* chars, LONG length=-1) 
    {
        m_protocol.Assign(chars, length);
        length = m_protocol.Length();
        return length;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: GetProtocol
    //
    //   Author: $author$
    //     Date: 4/21/2007
    ///////////////////////////////////////////////////////////////////////
    virtual const char* GetProtocol(LONG& length) const 
    {
        return m_protocol.Chars(length);
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: GetProtocol
    //
    //   Author: $author$
    //     Date: 4/21/2007
    ///////////////////////////////////////////////////////////////////////
    virtual const char* GetProtocol() const 
    {
        LONG length;
        return m_protocol.Chars(length);
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: SetProtocolVersionMajor
    //
    //   Author: $author$
    //     Date: 4/24/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG SetProtocolVersionMajor
    (const char* chars, LONG length=-1) 
    {
        m_protocolVersionMajor.Assign(chars, length);
        length = m_protocolVersionMajor.Length();
        return length;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: GetProtocolVersionMajor
    //
    //   Author: $author$
    //     Date: 4/21/2007
    ///////////////////////////////////////////////////////////////////////
    virtual const char* GetProtocolVersionMajor(LONG& length) const 
    {
        return m_protocolVersionMajor.Chars(length);
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: GetProtocolVersionMajor
    //
    //   Author: $author$
    //     Date: 4/21/2007
    ///////////////////////////////////////////////////////////////////////
    virtual const char* GetProtocolVersionMajor() const 
    {
        LONG length;
        return m_protocolVersionMajor.Chars(length);
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: SetProtocolVersionMinor
    //
    //   Author: $author$
    //     Date: 4/24/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG SetProtocolVersionMinor
    (const char* chars, LONG length=-1) 
    {
        m_protocolVersionMinor.Assign(chars, length);
        length = m_protocolVersionMinor.Length();
        return length;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: GetProtocolVersionMinor
    //
    //   Author: $author$
    //     Date: 4/21/2007
    ///////////////////////////////////////////////////////////////////////
    virtual const char* GetProtocolVersionMinor(LONG& length) const 
    {
        return m_protocolVersionMinor.Chars(length);
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: GetProtocolVersionMinor
    //
    //   Author: $author$
    //     Date: 4/21/2007
    ///////////////////////////////////////////////////////////////////////
    virtual const char* GetProtocolVersionMinor() const 
    {
        LONG length;
        return m_protocolVersionMinor.Chars(length);
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: SetRequestAction
    //
    //   Author: $author$
    //     Date: 4/24/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG SetRequestAction
    (const char* chars, LONG length=-1) 
    {
        m_requestAction.Assign(chars, length);
        length = m_requestAction.Length();
        return length;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: GetRequestAction
    //
    //   Author: $author$
    //     Date: 4/24/2007
    ///////////////////////////////////////////////////////////////////////
    virtual const char* GetRequestAction
    (LONG& length) const 
    {
        return m_requestAction.Chars(length);
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: SetRequestMethod
    //
    //   Author: $author$
    //     Date: 5/16/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG SetRequestMethod
    (const char* chars, LONG length=-1) 
    {
        m_requestAction.Assign(chars, length);
        length = m_requestAction.Length();
        return length;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: GetRequestMethod
    //
    //   Author: $author$
    //     Date: 5/16/2007
    ///////////////////////////////////////////////////////////////////////
    virtual const char* GetRequestMethod
    (LONG& length) const 
    {
        const char* chars = m_requestAction.Chars(length);
        return chars;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: SetRequestPath
    //
    //   Author: $author$
    //     Date: 4/24/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG SetRequestPath
    (const char* chars, LONG length=-1) 
    {
        m_requestPath.Assign(chars, length);
        length = m_requestPath.Length();
        return length;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: GetRequestPath
    //
    //   Author: $author$
    //     Date: 4/24/2007
    ///////////////////////////////////////////////////////////////////////
    virtual const char* GetRequestPath
    (LONG& length) const 
    {
        return m_requestPath.Chars(length);
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: SetResponseStatusUnsigned
    //
    //   Author: $author$
    //     Date: 5/1/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG SetResponseStatusUnsigned(ULONG value) 
    {
        LONG length;
        m_responseStatus.AssignUnsigned(value);
        length = m_responseStatus.Length();
        return length;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: GetResponseStatusUnsigned
    //
    //   Author: $author$
    //     Date: 5/1/2007
    ///////////////////////////////////////////////////////////////////////
    virtual ULONG GetResponseStatusUnsigned
    (LONG& length) const 
    {
        return m_responseStatus.Unsigned(length);
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: SetResponseStatus
    //
    //   Author: $author$
    //     Date: 4/24/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG SetResponseStatus
    (const char* chars, LONG length=-1) 
    {
        m_responseStatus.Assign(chars, length);
        length = m_responseStatus.Length();
        return length;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: GetResponseStatus
    //
    //   Author: $author$
    //     Date: 4/24/2007
    ///////////////////////////////////////////////////////////////////////
    virtual const char* GetResponseStatus
    (LONG& length) const 
    {
        return m_responseStatus.Chars(length);
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: SetResponseDescription
    //
    //   Author: $author$
    //     Date: 4/24/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG SetResponseDescription
    (const char* chars, LONG length=-1) 
    {
        m_responseDescription.Assign(chars, length);
        length = m_responseDescription.Length();
        return length;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: GetResponseDescription
    //
    //   Author: $author$
    //     Date: 4/24/2007
    ///////////////////////////////////////////////////////////////////////
    virtual const char* GetResponseDescription
    (LONG& length) const 
    {
        return m_responseDescription.Chars(length);
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: GetChars
    //
    //   Author: $author$
    //     Date: 4/25/2007
    ///////////////////////////////////////////////////////////////////////
    virtual const char* GetChars
    (LONG& length) const 
    {
        const char* chars = Chars(length);
        return chars;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: OnRequestAction
    //
    //   Author: $author$
    //     Date: 4/19/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError OnRequestAction(const char* chars) 
    {
        EvError error = EV_ERROR_NONE;
        SetRequestAction(chars);
        SetIsRequest();
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: OnRequestPath
    //
    //   Author: $author$
    //     Date: 4/19/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError OnRequestPath(const char* chars) 
    {
        EvError error = EV_ERROR_NONE;
        SetRequestPath(chars);
        SetIsRequest();
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: OnRequestProtocol
    //
    //   Author: $author$
    //     Date: 4/19/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError OnRequestProtocol(const char* chars) 
    {
        EvError error = EV_ERROR_NONE;
        SetProtocol(chars);
        SetIsRequest();
        return error;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: OnResponseProtocol
    //
    //   Author: $author$
    //     Date: 4/19/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError OnResponseProtocol(const char* chars) 
    {
        EvError error = EV_ERROR_NONE;
        SetProtocol(chars);
        SetIsResponse();
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: OnResponseStatus
    //
    //   Author: $author$
    //     Date: 4/19/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError OnResponseStatus(const char* chars) 
    {
        EvError error = EV_ERROR_NONE;
        SetResponseStatus(chars);
        SetIsResponse();
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: OnResponseDescription
    //
    //   Author: $author$
    //     Date: 4/19/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError OnResponseDescription(const char* chars) 
    {
        EvError error = EV_ERROR_NONE;
        SetResponseDescription(chars);
        SetIsResponse();
        return error;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: OnProtocolVersionMajor
    //
    //   Author: $author$
    //     Date: 4/19/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError OnProtocolVersionMajor(const char* chars) 
    {
        EvError error = EV_ERROR_NONE;
        SetProtocolVersionMajor(chars);
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: OnProtocolVersionMinor
    //
    //   Author: $author$
    //     Date: 4/19/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError OnProtocolVersionMinor(const char* chars) 
    {
        EvError error = EV_ERROR_NONE;
        SetProtocolVersionMinor(chars);
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: OnHeadingCR
    //
    //   Author: $author$
    //     Date: 5/16/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError OnHeadingCR
    (const char* chars) 
    {
        EvError error = EV_ERROR_NONE;
        SetHasCR();
        return error;
    }
};

#endif // _CEVCPHEADERHEADING_HPP
