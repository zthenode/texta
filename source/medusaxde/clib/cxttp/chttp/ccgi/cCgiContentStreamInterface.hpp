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
//   File: cCgiContentStreamInterface.hpp
//
// Author: $author$
//   Date: 6/25/2011
///////////////////////////////////////////////////////////////////////
#if !defined(_CCGICONTENTSTREAMINTERFACE_HPP) || defined(CCGICONTENTSTREAMINTERFACE_MEMBERS_ONLY)
#if !defined(_CCGICONTENTSTREAMINTERFACE_HPP) && !defined(CCGICONTENTSTREAMINTERFACE_MEMBERS_ONLY)
#define _CCGICONTENTSTREAMINTERFACE_HPP
#endif // !defined(_CCGICONTENTSTREAMINTERFACE_HPP) && !defined(CCGICONTENTSTREAMINTERFACE_MEMBERS_ONLY) 

#if !defined(CCGICONTENTSTREAMINTERFACE_MEMBERS_ONLY)
#include "cCharStreamInterface.hpp"
#include "cString.hpp"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

///////////////////////////////////////////////////////////////////////
// Typedef: cCgiContentStreamInterfaceImplements
//
//  Author: $author$
//    Date: 6/25/2011
///////////////////////////////////////////////////////////////////////
typedef cCharStreamInterface
cCgiContentStreamInterfaceImplements;
///////////////////////////////////////////////////////////////////////
//  Class: cCgiContentStreamInterface
//
// Author: $author$
//   Date: 6/25/2011
///////////////////////////////////////////////////////////////////////
class c_INTERFACE_CLASS cCgiContentStreamInterface
: virtual public cCgiContentStreamInterfaceImplements
{
public:
    typedef cCgiContentStreamInterfaceImplements cImplements;
#else // !defined(CCGICONTENTSTREAMINTERFACE_MEMBERS_ONLY) 
#endif // !defined(CCGICONTENTSTREAMINTERFACE_MEMBERS_ONLY) 

#if !defined(CCGICONTENTSTREAMINTERFACE_MEMBERS_ONLY)
// include cCgiContentStream member functions interface
//
#define CCGICONTENTSTREAM_MEMBERS_ONLY
#define CCGICONTENTSTREAM_MEMBER_FUNCS_INTERFACE
#include "cCgiContentStream.hpp"
#undef CCGICONTENTSTREAM_MEMBER_FUNCS_INTERFACE
#undef CCGICONTENTSTREAM_MEMBERS_ONLY
};

#if !defined(CCGICONTENTSTREAMIMPLEMENT_MEMBERS_ONLY)
///////////////////////////////////////////////////////////////////////
// Typedef: cCgiContentStreamImplementImplements
//
//  Author: $author$
//    Date: 6/25/2011
///////////////////////////////////////////////////////////////////////
typedef cCharStreamImplement
cCgiContentStreamImplementImplements;
///////////////////////////////////////////////////////////////////////
//  Class: cCgiContentStreamImplement
//
// Author: $author$
//   Date: 6/25/2011
///////////////////////////////////////////////////////////////////////
class c_IMPLEMENT_CLASS cCgiContentStreamImplement
: virtual public cCgiContentStreamInterface
{
public:
    typedef cCgiContentStreamInterface cImplements;
#else // !defined(CCGICONTENTSTREAMIMPLEMENT_MEMBERS_ONLY) 
#endif // !defined(CCGICONTENTSTREAMIMPLEMENT_MEMBERS_ONLY) 

#if !defined(CCGICONTENTSTREAMIMPLEMENT_MEMBERS_ONLY)
// include cCgiContentStream interface member definitions
//
#define CCGICONTENTSTREAMINTERFACE_MEMBERS_ONLY
#include "cCgiContentStreamInterface.hpp"
#undef CCGICONTENTSTREAMINTERFACE_MEMBERS_ONLY

// include cCgiContentStream member functions implement
//
#define CCGICONTENTSTREAM_MEMBERS_ONLY
#define CCGICONTENTSTREAM_MEMBER_FUNCS_IMPLEMENT
#include "cCgiContentStream.hpp"
#undef CCGICONTENTSTREAM_MEMBER_FUNCS_IMPLEMENT
#undef CCGICONTENTSTREAM_MEMBERS_ONLY
};
#else // !defined(CCGICONTENTSTREAMIMPLEMENT_MEMBERS_ONLY) 
#endif // !defined(CCGICONTENTSTREAMIMPLEMENT_MEMBERS_ONLY) 

#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#else // !defined(CCGICONTENTSTREAMINTERFACE_MEMBERS_ONLY) 
#endif // !defined(CCGICONTENTSTREAMINTERFACE_MEMBERS_ONLY) 

#endif // !defined(_CCGICONTENTSTREAMINTERFACE_HPP) || defined(CCGICONTENTSTREAMINTERFACE_MEMBERS_ONLY) 
        

