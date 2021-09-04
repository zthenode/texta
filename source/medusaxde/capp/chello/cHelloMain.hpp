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
//   File: cHelloMain.hpp
//
// Author: $author$
//   Date: 6/2/2011
///////////////////////////////////////////////////////////////////////
#if !defined(_CHELLOMAIN_HPP) || defined(CHELLOMAIN_MEMBERS_ONLY)
#if !defined(_CHELLOMAIN_HPP) && !defined(CHELLOMAIN_MEMBERS_ONLY)
#define _CHELLOMAIN_HPP
#endif // !defined(_CHELLOMAIN_HPP) && !defined(CHELLOMAIN_MEMBERS_ONLY) 

#if !defined(CHELLOMAIN_MEMBERS_ONLY)
#include "cOptMain.hpp"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

///////////////////////////////////////////////////////////////////////
// Typedef: cHelloMainExtend
//
//  Author: $author$
//    Date: 6/2/2011
///////////////////////////////////////////////////////////////////////
typedef cOptMain
cHelloMainExtend;
///////////////////////////////////////////////////////////////////////
//  Class: cHelloMain
//
// Author: $author$
//   Date: 6/2/2011
///////////////////////////////////////////////////////////////////////
class c_INSTANCE_CLASS cHelloMain
: //virtual public cHelloMainImplement,
  public cHelloMainExtend
{
public:
    //typedef cHelloMainImplement cImplements;
    typedef cHelloMainExtend cExtends;
    ///////////////////////////////////////////////////////////////////////
    //  Constructor: cHelloMain
    //
    //       Author: $author$
    //         Date: 6/2/2011
    ///////////////////////////////////////////////////////////////////////
    cHelloMain()
    {
    }
    ///////////////////////////////////////////////////////////////////////
    //  Destructor: ~cHelloMain
    //
    //      Author: $author$
    //        Date: 6/2/2011
    ///////////////////////////////////////////////////////////////////////
    virtual ~cHelloMain()
    {
    }
#else // !defined(CHELLOMAIN_MEMBERS_ONLY) 
#endif // !defined(CHELLOMAIN_MEMBERS_ONLY) 

    ///////////////////////////////////////////////////////////////////////
    //  Function: Run
    //
    //    Author: $author$
    //      Date: 6/2/2011
    ///////////////////////////////////////////////////////////////////////
    virtual int Run
    (int argc,
     char_t** argv,
     char_t** env)
#if defined(CHELLOMAIN_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CHELLOMAIN_MEMBER_FUNCS_INTERFACE) 
    {
        int err = 0;
#if !defined(CHELLOMAIN_MEMBER_FUNCS_IMPLEMENT)
        c_DB_TRACE("() in...");
        OutFormatted("Hello %s\n", (optind<argc)?(argv[optind]):(""));
        c_DB_TRACE("() ...out");
#else // !defined(CHELLOMAIN_MEMBER_FUNCS_IMPLEMENT)
#endif // !defined(CHELLOMAIN_MEMBER_FUNCS_IMPLEMENT) 
        return err;
    }
#endif // defined(CHELLOMAIN_MEMBER_FUNCS_INTERFACE) 

#if !defined(CHELLOMAIN_MEMBERS_ONLY)
};


#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#else // !defined(CHELLOMAIN_MEMBERS_ONLY) 
#endif // !defined(CHELLOMAIN_MEMBERS_ONLY) 

#endif // !defined(_CHELLOMAIN_HPP) || defined(CHELLOMAIN_MEMBERS_ONLY) 
        

