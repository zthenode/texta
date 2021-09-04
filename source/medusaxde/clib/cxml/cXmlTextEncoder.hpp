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
//   File: cXmlTextEncoder.hpp
//
// Author: $author$
//   Date: 7/25/2011
///////////////////////////////////////////////////////////////////////
#if !defined(_CXMLTEXTENCODER_HPP) || defined(CXMLTEXTENCODERT_MEMBERS_ONLY)
#if !defined(_CXMLTEXTENCODER_HPP) && !defined(CXMLTEXTENCODERT_MEMBERS_ONLY)
#define _CXMLTEXTENCODER_HPP
#endif // !defined(_CXMLTEXTENCODER_HPP) && !defined(CXMLTEXTENCODERT_MEMBERS_ONLY) 

#if !defined(CXMLTEXTENCODERT_MEMBERS_ONLY)
#include "cCharWriter.hpp"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

#undef CDB_CLASS
#define CDB_CLASS "cXmlTextEncoderT"
///////////////////////////////////////////////////////////////////////
//  Class: cXmlTextEncoderT
//
// Author: $author$
//   Date: 7/25/2011
///////////////////////////////////////////////////////////////////////
template
<class TWriter=cCharWriter,
 class TChar=char,
 class TExtend=TWriter>

class c_INSTANCE_CLASS cXmlTextEncoderT
: public TExtend
{
public:
    typedef TExtend cExtends;
    typedef TWriter tWriter;
    typedef TChar tWhat;

    tWriter& m_writer;

    ///////////////////////////////////////////////////////////////////////
    //  Constructor: cXmlTextEncoderT
    //
    //       Author: $author$
    //         Date: 7/25/2011
    ///////////////////////////////////////////////////////////////////////
    cXmlTextEncoderT
    (tWriter& writer)
    : m_writer(writer)
    {
    }
    ///////////////////////////////////////////////////////////////////////
    //  Destructor: ~cXmlTextEncoderT
    //
    //      Author: $author$
    //        Date: 7/25/2011
    ///////////////////////////////////////////////////////////////////////
    virtual ~cXmlTextEncoderT()
    {
    }
#else // !defined(CXMLTEXTENCODERT_MEMBERS_ONLY) 
#endif // !defined(CXMLTEXTENCODERT_MEMBERS_ONLY) 

#if !defined(CXMLTEXTENCODERT_MEMBERS_ONLY)
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
        ampLtLen = 4,
        ampGtLen = 4,
        };
        static const tWhat ampAmp[ampAmpLen]={(tWhat)('&'),(tWhat)('a'),(tWhat)('m'),(tWhat)('p'),(tWhat)(';')};
        static const tWhat ampLt[ampLtLen]={(tWhat)('&'),(tWhat)('l'),(tWhat)('t'),(tWhat)(';')};
        static const tWhat ampGt[ampGtLen]={(tWhat)('&'),(tWhat)('g'),(tWhat)('t'),(tWhat)(';')};
        ssize_t count = 0;
        switch ((char)(what))
        {
        case '&':
            count = m_writer.Write(ampAmp, ampAmpLen);
            break;
        case '<':
            count = m_writer.Write(ampLt, ampLtLen);
            break;
        case '>':
            count = m_writer.Write(ampGt, ampGtLen);
            break;
        default:
            count = m_writer.Write(&what, 1);
        }
        return count;
    }
};
#undef CDB_CLASS

///////////////////////////////////////////////////////////////////////
// typedef: cXmlTextEncoder
//
//  Author: $author$
//    Date: 7/25/2011
///////////////////////////////////////////////////////////////////////
typedef cXmlTextEncoderT<cCharWriter, char> 
cXmlTextEncoder;

#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#else // !defined(CXMLTEXTENCODERT_MEMBERS_ONLY) 
#endif // !defined(CXMLTEXTENCODERT_MEMBERS_ONLY) 

#endif // !defined(_CXMLTEXTENCODER_HPP) || defined(CXMLTEXTENCODERT_MEMBERS_ONLY) 
