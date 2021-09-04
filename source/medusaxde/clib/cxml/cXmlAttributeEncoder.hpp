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
//   File: cXmlAttributeEncoder.hpp
//
// Author: $author$
//   Date: 7/25/2011
///////////////////////////////////////////////////////////////////////
#if !defined(_CXMLATTRIBUTEENCODER_HPP) || defined(CXMLATTRIBUTEENCODERT_MEMBERS_ONLY)
#if !defined(_CXMLATTRIBUTEENCODER_HPP) && !defined(CXMLATTRIBUTEENCODERT_MEMBERS_ONLY)
#define _CXMLATTRIBUTEENCODER_HPP
#endif // !defined(_CXMLATTRIBUTEENCODER_HPP) && !defined(CXMLATTRIBUTEENCODERT_MEMBERS_ONLY) 

#if !defined(CXMLATTRIBUTEENCODERT_MEMBERS_ONLY)
#include "cCharWriter.hpp"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

#undef CDB_CLASS
#define CDB_CLASS "cXmlAttributeEncoderT"
///////////////////////////////////////////////////////////////////////
//  Class: cXmlAttributeEncoderT
//
// Author: $author$
//   Date: 7/25/2011
///////////////////////////////////////////////////////////////////////
template
<class TWriter=cCharWriter,
 class TChar=char,
 class TExtend=TWriter>

class c_INSTANCE_CLASS cXmlAttributeEncoderT
: public TExtend
{
public:
    typedef TExtend cExtends;
    typedef TWriter tWriter;
    typedef TChar tWhat;

    tWriter& m_writer;

    ///////////////////////////////////////////////////////////////////////
    //  Constructor: cXmlAttributeEncoderT
    //
    //       Author: $author$
    //         Date: 7/25/2011
    ///////////////////////////////////////////////////////////////////////
    cXmlAttributeEncoderT
    (tWriter& writer)
    : m_writer(writer)
    {
    }
    ///////////////////////////////////////////////////////////////////////
    //  Destructor: ~cXmlAttributeEncoderT
    //
    //      Author: $author$
    //        Date: 7/25/2011
    ///////////////////////////////////////////////////////////////////////
    virtual ~cXmlAttributeEncoderT()
    {
    }
#else // !defined(CXMLATTRIBUTEENCODERT_MEMBERS_ONLY) 
#endif // !defined(CXMLATTRIBUTEENCODERT_MEMBERS_ONLY) 

#if !defined(CXMLATTRIBUTEENCODERT_MEMBERS_ONLY)
    ///////////////////////////////////////////////////////////////////////
    //  Function: Write
    //
    //    Author: $author$
    //      Date: 7/25/2011
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t Write
    (const tWhat* what,
     ssize_t length=-1)
    {
        static const tWhat nullc = 0;
        ssize_t count = 0;
        ssize_t count2;
        tWhat c;
        if ((what))
        if (0 > (length))
        {
            for (c = *what; c != nullc; c = *++what, count += count2)
            {
                if (0 > (count2 = Put(c)))
                    return count2;
            }
        }
        else
        {
            for (; length; --length, count += count2)
            {
                c = *what++;
                if (0 > (count2 = Put(c)))
                    return count2;
            }
        }
        return count;
    }
    ///////////////////////////////////////////////////////////////////////
    //  Function: Put
    //
    //    Author: $author$
    //      Date: 7/25/2011
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t Put
    (const tWhat& what)
    {
        enum {
        ampAmpLen = 5,
        ampQuotLen = 6,
        ampAposLen = 6,
        };
        static const tWhat ampAmp[ampAmpLen]={(tWhat)('&'),(tWhat)('a'),(tWhat)('m'),(tWhat)('p'),(tWhat)(';')};
        static const tWhat ampApos[ampAposLen]={(tWhat)('&'),(tWhat)('a'),(tWhat)('p'),(tWhat)('o'),(tWhat)('s'),(tWhat)(';')};
        static const tWhat ampQuot[ampQuotLen]={(tWhat)('&'),(tWhat)('q'),(tWhat)('u'),(tWhat)('o'),(tWhat)('t'),(tWhat)(';')};
        ssize_t count = 0;
        switch ((char)(what))
        {
        case '&':
            count = m_writer.Write(ampAmp, ampAmpLen);
            break;
        case '\'':
            count = m_writer.Write(ampApos, ampAposLen);
            break;
        case '"':
            count = m_writer.Write(ampQuot, ampQuotLen);
            break;
        default:
            count = m_writer.Write(&what, 1);
        }
        return count;
    }
};
#undef CDB_CLASS

///////////////////////////////////////////////////////////////////////
// typedef: cXmlAttributeEncoder
//
//  Author: $author$
//    Date: 7/25/2011
///////////////////////////////////////////////////////////////////////
typedef cXmlAttributeEncoderT<cCharWriter, char> 
cXmlAttributeEncoder;

#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#else // !defined(CXMLATTRIBUTEENCODERT_MEMBERS_ONLY) 
#endif // !defined(CXMLATTRIBUTEENCODERT_MEMBERS_ONLY) 

#endif // !defined(_CXMLATTRIBUTEENCODER_HPP) || defined(CXMLATTRIBUTEENCODERT_MEMBERS_ONLY) 
