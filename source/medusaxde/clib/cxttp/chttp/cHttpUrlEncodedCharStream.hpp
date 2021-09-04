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
//   File: cHttpUrlEncodedCharStream.hpp
//
// Author: $author$
//   Date: 11/24/2012
///////////////////////////////////////////////////////////////////////
#ifndef _CHTTPURLENCODEDCHARSTREAM_HPP
#define _CHTTPURLENCODEDCHARSTREAM_HPP

#include "cXttpUrlEncodedCharStream.hpp"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

///////////////////////////////////////////////////////////////////////
// Typedef: cHttpUrlEncodedCharStreamImplement
//
//  Author: $author$
//    Date: 11/24/2012
///////////////////////////////////////////////////////////////////////
typedef cXttpUrlEncodedCharStreamImplement
cHttpUrlEncodedCharStreamImplement;
///////////////////////////////////////////////////////////////////////
// Typedef: cHttpUrlEncodedCharStreamExtend
//
//  Author: $author$
//    Date: 11/24/2012
///////////////////////////////////////////////////////////////////////
typedef cXttpUrlEncodedCharStream
cHttpUrlEncodedCharStreamExtend;
///////////////////////////////////////////////////////////////////////
//  Class: cHttpUrlEncodedCharStream
//
// Author: $author$
//   Date: 11/24/2012
///////////////////////////////////////////////////////////////////////
class c_EXPORT_CLASS cHttpUrlEncodedCharStream
: virtual public cHttpUrlEncodedCharStreamImplement,
  public cHttpUrlEncodedCharStreamExtend
{
public:
    typedef cHttpUrlEncodedCharStreamImplement cImplements;
    typedef cHttpUrlEncodedCharStreamExtend cExtends;

    ///////////////////////////////////////////////////////////////////////
    //  Constructor: cHttpUrlEncodedCharStream
    //
    //       Author: $author$
    //         Date: 11/24/2012
    ///////////////////////////////////////////////////////////////////////
    cHttpUrlEncodedCharStream
    (tStreamInterface* delegated=0, tLength contentLength=-1)
    : cExtends(delegated, contentLength)
    {
    }
};


#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#endif // _CHTTPURLENCODEDCHARSTREAM_HPP 
        

