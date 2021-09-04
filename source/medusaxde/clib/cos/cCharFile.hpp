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
//   File: cCharFile.hpp
//
// Author: $author$
//   Date: 6/2/2011
///////////////////////////////////////////////////////////////////////
#if !defined(_CCHARFILE_HPP) || defined(CCHARFILET_MEMBERS_ONLY)
#if !defined(_CCHARFILE_HPP) && !defined(CCHARFILET_MEMBERS_ONLY)
#define _CCHARFILE_HPP
#endif // !defined(_CCHARFILE_HPP) && !defined(CCHARFILET_MEMBERS_ONLY) 

#if !defined(CCHARFILET_MEMBERS_ONLY)
#include "cCharFileInterface.hpp"
#include "cFile.hpp"
#include "cDebug.hpp"
#include "cplatform_fcntl.h"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

class c_INSTANCE_CLASS cCharFile;

#undef CDB_CLASS
#define CDB_CLASS "cCharFileT"
///////////////////////////////////////////////////////////////////////
//  Class: cCharFileT
//
// Author: $author$
//   Date: 6/2/2011
///////////////////////////////////////////////////////////////////////
template
<class TImplement=cCharFileImplement,
 class TExtend=cFile,
 class TWhat=char>

class c_INSTANCE_CLASS cCharFileT
: virtual public TImplement,
  public TExtend
{
public:
    typedef TImplement cImplements;
    typedef TExtend cExtends;

// include cCharFileT interface member definitions
//
#define CCHARFILEINTERFACET_MEMBERS_ONLY
#include "cCharFileInterface.hpp"
#undef CCHARFILEINTERFACET_MEMBERS_ONLY

    ///////////////////////////////////////////////////////////////////////
    //  Constructor: cCharFileT
    //
    //       Author: $author$
    //         Date: 6/2/2011
    ///////////////////////////////////////////////////////////////////////
    cCharFileT
    (FILE* attached=0,
     bool isOpen=false)
    : cExtends(attached, isOpen)
    {
    }
    ///////////////////////////////////////////////////////////////////////
    //  Destructor: ~cCharFileT
    //
    //      Author: $author$
    //        Date: 6/2/2011
    ///////////////////////////////////////////////////////////////////////
    virtual ~cCharFileT()
    {
    }
#else // !defined(CCHARFILET_MEMBERS_ONLY) 
#endif // !defined(CCHARFILET_MEMBERS_ONLY) 

    ///////////////////////////////////////////////////////////////////////
    //  Function: ReadFormatted
    //
    //    Author: $author$
    //      Date: 6/3/2011
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t ReadFormatted
    (const char_t* format,
     ...)
#if defined(CCHARFILET_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CCHARFILET_MEMBER_FUNCS_INTERFACE) 
    {
        ssize_t count = -e_ERROR_FAILED;
#if !defined(CCHARFILET_MEMBER_FUNCS_IMPLEMENT)
        va_list va;
        va_start(va, format);
        count = ReadFormattedV(format, va);
        va_end(va);
#else // !defined(CCHARFILET_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CCHARFILET_MEMBER_FUNCS_IMPLEMENT) 
        return count;
    }
#endif // defined(CCHARFILET_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    //  Function: ReadFormattedV
    //
    //    Author: $author$
    //      Date: 6/3/2011
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t ReadFormattedV
    (const char_t* format,
     va_list va)
#if defined(CCHARFILET_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CCHARFILET_MEMBER_FUNCS_INTERFACE) 
    {
        ssize_t count = -e_ERROR_FAILED;
#if !defined(CCHARFILET_MEMBER_FUNCS_IMPLEMENT)
        FILE* attached;
        if ((attached = CTHIS Attached()))
        if ((format))
        //if (0 > (count = vfscanf(attached, format, va)))
            count = -e_ERROR_FAILED;
#else // !defined(CCHARFILET_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CCHARFILET_MEMBER_FUNCS_IMPLEMENT) 
        return count;
    }
#endif // defined(CCHARFILET_MEMBER_FUNCS_INTERFACE) 

    ///////////////////////////////////////////////////////////////////////
    //  Function: WriteFormatted
    //
    //    Author: $author$
    //      Date: 6/3/2011
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t WriteFormatted
    (const char_t* format,
     ...)
#if defined(CCHARFILET_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CCHARFILET_MEMBER_FUNCS_INTERFACE) 
    {
        ssize_t count = -e_ERROR_FAILED;
#if !defined(CCHARFILET_MEMBER_FUNCS_IMPLEMENT)
        va_list va;
        va_start(va, format);
        count = WriteFormattedV(format, va);
        va_end(va);
#else // !defined(CCHARFILET_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CCHARFILET_MEMBER_FUNCS_IMPLEMENT) 
        return count;
    }
#endif // defined(CCHARFILET_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    //  Function: WriteFormattedV
    //
    //    Author: $author$
    //      Date: 6/3/2011
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t WriteFormattedV
    (const char_t* format,
     va_list va)
#if defined(CCHARFILET_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CCHARFILET_MEMBER_FUNCS_INTERFACE) 
    {
        ssize_t count = -e_ERROR_FAILED;
#if !defined(CCHARFILET_MEMBER_FUNCS_IMPLEMENT)
        FILE* attached;
        if ((attached = CTHIS Attached()))
        if ((format))
        if (0 > (count = vfprintf(attached, format, va)))
            count = -e_ERROR_FAILED;
#else // !defined(CCHARFILET_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CCHARFILET_MEMBER_FUNCS_IMPLEMENT) 
        return count;
    }
#endif // defined(CCHARFILET_MEMBER_FUNCS_INTERFACE) 

    ///////////////////////////////////////////////////////////////////////
    //  Function: Write
    //
    //    Author: $author$
    //      Date: 6/2/2011
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t Write
    (const tWhat* what,
     ssize_t length=-1)
#if defined(CCHARFILET_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CCHARFILET_MEMBER_FUNCS_INTERFACE) 
    {
        ssize_t count = -e_ERROR_FAILED;
#if !defined(CCHARFILET_MEMBER_FUNCS_IMPLEMENT)
        FILE* attached;
        if ((attached = CTHIS Attached()))
        if ((what))
        if (0 > (length))
        {
            tWhat c;
            for (count = 0; ((c = *what) != 0); count += length, ++what)
            {
                if (0 > (length = fwrite(&c, sizeof(tWhat), 1, attached)))
                    return count = -e_ERROR_FAILED;                
            }
        }
        else
        if (1 > (length))
            return count = 0;
        else
        if (0 > (count = fwrite(what, sizeof(tWhat), length, attached)))
            count = -e_ERROR_FAILED;
#else // !defined(CCHARFILET_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CCHARFILET_MEMBER_FUNCS_IMPLEMENT) 
        return count;
    }
#endif // defined(CCHARFILET_MEMBER_FUNCS_INTERFACE) 

    ///////////////////////////////////////////////////////////////////////
    //  Function: SetBinaryMode
    //
    //    Author: $author$
    //      Date: 11/21/2012
    ///////////////////////////////////////////////////////////////////////
    virtual bool SetBinaryMode(bool toOn=true)
#if defined(CCHARFILET_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CCHARFILET_MEMBER_FUNCS_INTERFACE) 
    {
        bool isTrue = false;
#if !defined(CCHARFILET_MEMBER_FUNCS_IMPLEMENT)
        FILE* attached;
        if ((attached = CTHIS Attached())) {
#if defined(WINDOWS)
            int result;
            if (0 <= (result = _setmode
                (_fileno(attached), (toOn)?(_O_BINARY):(_O_TEXT))))
                isTrue = true;
#else //  defined(WINDOWS)
            isTrue = true;
#endif // defined(WINDOWS)
        }
#else // !defined(CCHARFILET_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CCHARFILET_MEMBER_FUNCS_IMPLEMENT) 
        return isTrue;
    }
#endif // defined(CCHARFILET_MEMBER_FUNCS_INTERFACE) 

#if !defined(CCHARFILET_MEMBERS_ONLY)
};
#undef CDB_CLASS

///////////////////////////////////////////////////////////////////////
// Typedef: cCharFileExtend
//
//  Author: $author$
//    Date: 6/2/2011
///////////////////////////////////////////////////////////////////////
typedef cCharFileT<cCharFileImplement,cFile,char>
cCharFileExtend;
///////////////////////////////////////////////////////////////////////
//  Class: cCharFile
//
// Author: $author$
//   Date: 6/2/2011
///////////////////////////////////////////////////////////////////////
class c_INSTANCE_CLASS cCharFile
: public cCharFileExtend
{
public:
    typedef cCharFileExtend cExtends;
    ///////////////////////////////////////////////////////////////////////
    //  Constructor: cCharFile
    //
    //       Author: $author$
    //         Date: 6/2/2011
    ///////////////////////////////////////////////////////////////////////
    cCharFile
    (FILE* attached=0,
     bool isOpen=false)
    : cExtends(attached, isOpen)
    {
    }
};

#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#else // !defined(CCHARFILET_MEMBERS_ONLY) 
#endif // !defined(CCHARFILET_MEMBERS_ONLY) 

#endif // !defined(_CCHARFILE_HPP) || defined(CCHARFILET_MEMBERS_ONLY) 
        

