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
//   File: cCgiccCgiInterface_TheMain.cpp
//
// Author: $author$
//   Date: 7/26/2011
///////////////////////////////////////////////////////////////////////
#include "cCgiccCgiMain.hpp"
#include "cDebug.hpp"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

///////////////////////////////////////////////////////////////////////
//  Function: cCgiInterface::TheMain
//
//    Author: $author$
//      Date: 7/26/2011
//
// cCgiInterface entry point to cCgicc implementation cCgiInterface
///////////////////////////////////////////////////////////////////////
int cCgiInterface::TheMain
(int argc, char** argv, char** env)
{
    int err = 0;
    eError error;

    if (!(error = c_DEBUG_INIT_LEVELS(e_DEBUG_LEVELS_ERROR)))
    {
        cCgiccCgiMain cgiccMain;

        err = cgiccMain.Main(argc, argv, env);
        c_DEBUG_FINISH();
    }
    return err;
}

#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 
