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
//   File: cplatform_setenv.cpp
//
// Author: $author$
//   Date: 7/23/2011
///////////////////////////////////////////////////////////////////////
#include "cplatform_setenv.c"
#include "cString.hpp"

#if defined(c_NAMESPACE)
using namespace c_NAMESPACE;
#endif // defined(c_NAMESPACE) 

#if defined(WINDOWS)
//
// Windows
//
int setenv(const char *name, const char *value, int overwrite)
{
    int err = 1;
    LPCTSTR lpName;
    LPCTSTR lpValue;
    cTString sName;
    cTString sValue;

    if ((name) && (value))
    {
        if ((!overwrite))
        if ((getenv(name)))
            return err;

        if (0 < (sName.Assign_char(name)))
        if (0 <= (sValue.Assign_char(value)))
        if ((lpName = sName.Chars()))
        if ((lpValue = sValue.Chars()))
        if ((SetEnvironmentVariable(lpName, lpValue)))
            err = 0;
    }
    return err;
}
#else // defined(WINDOWS)
#endif // defined(WINDOWS)
