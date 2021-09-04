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
//   File: cXttpUrlEncodedCharStream.hpp
//
// Author: $author$
//   Date: 11/24/2012
///////////////////////////////////////////////////////////////////////
#ifndef _CXTTPURLENCODEDCHARSTREAM_HPP
#define _CXTTPURLENCODEDCHARSTREAM_HPP

#include "cCharStream.hpp"

#define CharIsX(x) \
    (((x) >= '0' && (x) <= '9') \
    || ((x) >= 'a' && (x) <= 'f') \
    || ((x) >= 'A' && (x) <= 'F'))

#define X2Char(x) \
    (((x) >= '0' && (x) <= '9')?((x)-'0') \
    :(((x) >= 'a' && (x) <= 'f')?((x)-'a'+10) \
    :((x)-'A'+10)))

#define Char2X(x) \
    (((x) >= 0 && (x) <= 9)?((x)+'0') \
    :(((x) >= 10 && (x) <= 15)?((x)+'a'-10) \
    :'.'))

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

///////////////////////////////////////////////////////////////////////
// Typedef: cXttpUrlEncodedCharStreamImplement
//
//  Author: $author$
//    Date: 11/24/2012
///////////////////////////////////////////////////////////////////////
typedef cCharStreamImplement
cXttpUrlEncodedCharStreamImplement;
///////////////////////////////////////////////////////////////////////
// Typedef: cXttpUrlEncodedCharStreamExtend
//
//  Author: $author$
//    Date: 11/24/2012
///////////////////////////////////////////////////////////////////////
typedef cCharStream
cXttpUrlEncodedCharStreamExtend;
///////////////////////////////////////////////////////////////////////
//  Class: cXttpUrlEncodedCharStream
//
// Author: $author$
//   Date: 11/24/2012
///////////////////////////////////////////////////////////////////////
class c_EXPORT_CLASS cXttpUrlEncodedCharStream
: virtual public cXttpUrlEncodedCharStreamImplement,
  public cXttpUrlEncodedCharStreamExtend
{
public:
    typedef cXttpUrlEncodedCharStreamImplement cImplements;
    typedef cXttpUrlEncodedCharStreamExtend cExtends;
    typedef cXttpUrlEncodedCharStream cDerives;

    typedef ssize_t tLength;
    typedef tLength (cDerives::*mGet)(tWhat& what);

    tLength m_contentLength;
    mGet m_get;
    tWhat m_percent;
    tWhat m_space;
    tWhat m_x1;
    tWhat m_x2;

    ///////////////////////////////////////////////////////////////////////
    //  Constructor: cXttpUrlEncodedCharStream
    //
    //       Author: $author$
    //         Date: 11/24/2012
    ///////////////////////////////////////////////////////////////////////
    cXttpUrlEncodedCharStream
    (tStreamInterface* delegated=0, tLength contentLength=-1)
    : cExtends(delegated),
      m_contentLength(contentLength),
      m_get(&cDerives::StartGet),
      m_percent('%'),
      m_space(' ')
    {
    }

    ///////////////////////////////////////////////////////////////////////
    //  Function: DelegateStream
    //
    //    Author: $author$
    //      Date: 11/24/2012
    ///////////////////////////////////////////////////////////////////////
    virtual tStreamInterface* DelegateStream
    (tStreamInterface* delegated=0, tLength contentLength=-1)
    {
        m_delegated = delegated;
        m_contentLength = contentLength;
        m_get = &cDerives::StartGet;
        return m_delegated;
    }

    ///////////////////////////////////////////////////////////////////////
    //  Function: Read
    //
    //    Author: $author$
    //      Date: 11/24/2012
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t Read(tWhat* what, size_t size)
    {
        ssize_t count = 0;
        tLength length;        
        if (what)
        while (size)
        {
            if (!(length = Get(*what)))
                break;
                
            if (0 > length)
                return length;
                
            count += length;
            what++;
            --size;
        }
        return count;
    }
    ///////////////////////////////////////////////////////////////////////
    //  Function: Write
    //
    //    Author: $author$
    //      Date: 11/24/2012
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t Write(const tWhat* what, ssize_t length=-1)
    {
        ssize_t count = -1;
        return count;
    }

    ///////////////////////////////////////////////////////////////////////
    //  Function: Get
    //
    //    Author: $author$
    //      Date: 11/24/2012
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t Get(tWhat& what)
    {
        ssize_t count = -1;
        if (m_get)
        for (count = 0; m_contentLength; )
        {
            if (0 < m_contentLength)
                --m_contentLength;
                
            if ((count = (this->*m_get)(what)))
                break;
        }
        return count;
    }
    ///////////////////////////////////////////////////////////////////////
    //  Function: StartGet
    //
    //    Author: $author$
    //      Date: 11/24/2012
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t StartGet(tWhat& what)
    {
        ssize_t count = -1;
        char c;

        if (0 < (count = DelegatedGet(what)))
        switch(c = (char)(what))
        {
        case '+':
            what = m_space;
            break;

        case '%':
            count = 0;
            m_get = &cDerives::X1Get;
            break;
        }
        return count;
    }
    ///////////////////////////////////////////////////////////////////////
    //  Function: X1Get
    //
    //    Author: $author$
    //      Date: 11/24/2012
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t X1Get(tWhat& what)
    {
        ssize_t count = -1;
        char c;

        if (0 < (count = DelegatedGet(what)))
        {
            c = (char)(what);
            if (CharIsX(c))
            {
                // %X
                //
                count = 0;
                m_x1 = (tWhat)(X2Char(c));
                m_get = &cDerives::X2Get;
            }
            else
            {
                // %[^X]
                //
                m_x1 = what;
                what = m_percent;
                m_get = &cDerives::XGet;
            }
        }
        return count;
    }
    ///////////////////////////////////////////////////////////////////////
    //  Function: X2Get
    //
    //    Author: $author$
    //      Date: 11/24/2012
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t X2Get(tWhat& what)
    {
        ssize_t count = -1;
        char c;

        if (0 < (count = DelegatedGet(what)))
        {
            c = (char)(what);
            if (CharIsX(c))
            {
                // %XX
                //
                m_x2 = (tWhat)(X2Char(c));
                what = (m_x1 << 4) | m_x2;
                m_get = &cDerives::StartGet;
            }
            else
            {
                // %X[^X]
                //
                m_x2 = what;
                what = m_x1;
                m_x1 = m_x2;
                m_get = &cDerives::XGet;
            }
        }
        return count;
    }
    ///////////////////////////////////////////////////////////////////////
    //  Function: XGet
    //
    //    Author: $author$
    //      Date: 11/24/2012
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t XGet(tWhat& what)
    {
        ssize_t count = -1;
        what = m_x1;
        m_get = &cDerives::StartGet;
        return count;
    }
    ///////////////////////////////////////////////////////////////////////
    //  Function: DelegatedGet
    //
    //    Author: $author$
    //      Date: 11/24/2012
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t DelegatedGet(tWhat& what)
    {
        ssize_t count = -1;
        if ((m_delegated))
            count = m_delegated->Read(&what, 1);
        return count;
    }
};

#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#endif // _CXTTPURLENCODEDCHARSTREAM_HPP 
