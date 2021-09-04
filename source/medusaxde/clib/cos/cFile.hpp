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
//   File: cFile.hpp
//
// Author: $author$
//   Date: 5/31/2011
///////////////////////////////////////////////////////////////////////
#if !defined(_CFILE_HPP) || defined(CFILET_MEMBERS_ONLY)
#if !defined(_CFILE_HPP) && !defined(CFILET_MEMBERS_ONLY)
#define _CFILE_HPP
#endif // !defined(_CFILE_HPP) && !defined(CFILET_MEMBERS_ONLY) 

#if !defined(CFILET_MEMBERS_ONLY)
#include "cFileInterface.hpp"
#include "cplatform_stat.h"
#include "cStream.hpp"
#include "cString.hpp"
#include "cDebug.hpp"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

#undef CDB_CLASS
#define CDB_CLASS "cFileT"
///////////////////////////////////////////////////////////////////////
//  Class: cFileT
//
// Author: $author$
//   Date: 5/31/2011
///////////////////////////////////////////////////////////////////////
template
<class TImplement=cFileImplement,
 class TExtend=cStream,
 class TWhat=char>

class c_INSTANCE_CLASS cFileT
: virtual public TImplement,
  public TExtend
{
public:
    typedef TImplement cImplements;
    typedef TExtend cExtends;

// include cFileT interface member definitions
//
#define CFILEINTERFACET_MEMBERS_ONLY
#include "cFileInterface.hpp"
#undef CFILEINTERFACET_MEMBERS_ONLY

    FILE* m_attached;
    bool m_isOpen;

    ///////////////////////////////////////////////////////////////////////
    //  Constructor: cFileT
    //
    //       Author: $author$
    //         Date: 5/31/2011
    ///////////////////////////////////////////////////////////////////////
    cFileT
    (FILE* attached=0,
     bool isOpen=false)
    : m_attached(attached), 
      m_isOpen(isOpen)
    {
    }
    ///////////////////////////////////////////////////////////////////////
    //  Destructor: ~cFileT
    //
    //      Author: $author$
    //        Date: 5/31/2011
    ///////////////////////////////////////////////////////////////////////
    virtual ~cFileT()
    {
        eError error;
        if ((error = Closed()))
        {
            c_DB_ERROR("() failed on Closed()");
            throw (error);
        }
    }
#else // !defined(CFILET_MEMBERS_ONLY) 
#endif // !defined(CFILET_MEMBERS_ONLY) 

    ///////////////////////////////////////////////////////////////////////
    //  Function: Open
    //
    //    Author: $author$
    //      Date: 5/31/2011
    ///////////////////////////////////////////////////////////////////////
    virtual eError Open
    (const wchar_t* fileName,
     const wchar_t* fileMode,
     bool onlyClosed=false)
#if defined(CFILET_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CFILET_MEMBER_FUNCS_INTERFACE) 
    {
        eError error = e_ERROR_FAILED;
#if !defined(CFILET_MEMBER_FUNCS_IMPLEMENT)
        cString name, mode;
        const char* nameChars;
        const char* modeChars;
        if ((fileName) && (fileMode))
        if (0 < (name.Assign(fileName)))
        if ((nameChars = name.HasChars()))
        if (0 < (mode.Assign(fileMode)))
        if ((modeChars = mode.HasChars()))
            error = Open(nameChars, modeChars);
#else // !defined(CFILET_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CFILET_MEMBER_FUNCS_IMPLEMENT) 
        return error;
    }
#endif // defined(CFILET_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    //  Function: Open
    //
    //    Author: $author$
    //      Date: 5/31/2011
    ///////////////////////////////////////////////////////////////////////
    virtual eError Open
    (const wchar_t* fileName,
     const char* fileMode,
     bool onlyClosed=false)
#if defined(CFILET_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CFILET_MEMBER_FUNCS_INTERFACE) 
    {
        eError error = e_ERROR_FAILED;
#if !defined(CFILET_MEMBER_FUNCS_IMPLEMENT)
        cString name;
        const char* nameChars;
        if ((fileName) && (fileMode))
        if (0 < (name.Assign(fileName)))
        if ((nameChars = name.HasChars()))
            error = Open(nameChars, fileMode);
#else // !defined(CFILET_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CFILET_MEMBER_FUNCS_IMPLEMENT) 
        return error;
    }
#endif // defined(CFILET_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    //  Function: Open
    //
    //    Author: $author$
    //      Date: 5/31/2011
    ///////////////////////////////////////////////////////////////////////
    virtual eError Open
    (const char* fileName,
     const char* fileMode,
     bool onlyClosed=false)
#if defined(CFILET_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CFILET_MEMBER_FUNCS_INTERFACE) 
    {
        eError error = e_ERROR_FAILED;
#if !defined(CFILET_MEMBER_FUNCS_IMPLEMENT)
        FILE* detached;
        eError error2;
        if ((error2 = Closed(onlyClosed)))
            return error2;
        if ((fileName) && (fileMode))
        if ((detached = fopen(fileName, fileMode)))
        {
            if (detached == (Attach(detached)))
                return error = e_ERROR_NONE;
            fclose(detached);
        }
        else
        c_DB_ERROR("() failed on fopen()");
#else // !defined(CFILET_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CFILET_MEMBER_FUNCS_IMPLEMENT) 
        return error;
    }
#endif // defined(CFILET_MEMBER_FUNCS_INTERFACE) 

    ///////////////////////////////////////////////////////////////////////
    //  Function: Closed
    //
    //    Author: $author$
    //      Date: 5/31/2011
    ///////////////////////////////////////////////////////////////////////
    virtual eError Closed
    (bool onlyClosed=false)
#if defined(CFILET_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CFILET_MEMBER_FUNCS_INTERFACE) 
    {
        eError error = e_ERROR_FAILED;
#if !defined(CFILET_MEMBER_FUNCS_IMPLEMENT)
        FILE* attached;
        bool isOpen;
        if ((attached = Attached()))
        {
            if ((onlyClosed))
                return error;

            if ((isOpen = GetIsOpen()))
                error = Close(isOpen);
            else
            {
                Detach();
                error = e_ERROR_NONE;
            }
        }
        else
        {
            SetIsOpen(false);
            error = e_ERROR_NONE;
        }
#else // !defined(CFILET_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CFILET_MEMBER_FUNCS_IMPLEMENT) 
        return error;
    }
#endif // defined(CFILET_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    //  Function: Close
    //
    //    Author: $author$
    //      Date: 5/31/2011
    ///////////////////////////////////////////////////////////////////////
    virtual eError Close
    (bool onlyOpen=false)
#if defined(CFILET_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CFILET_MEMBER_FUNCS_INTERFACE) 
    {
        eError error = e_ERROR_FAILED;
#if !defined(CFILET_MEMBER_FUNCS_IMPLEMENT)
#else // !defined(CFILET_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CFILET_MEMBER_FUNCS_IMPLEMENT) 
        return error;
    }
#endif // defined(CFILET_MEMBER_FUNCS_INTERFACE) 

    ///////////////////////////////////////////////////////////////////////
    //  Function: SetIsOpen
    //
    //    Author: $author$
    //      Date: 5/31/2011
    ///////////////////////////////////////////////////////////////////////
    virtual int SetIsOpen
    (bool isTrue)
#if defined(CFILET_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CFILET_MEMBER_FUNCS_INTERFACE) 
    {
        int isOpen = -e_ERROR_NOT_IMPLEMENTED;
#if !defined(CFILET_MEMBER_FUNCS_IMPLEMENT)
        isOpen = (m_isOpen = isTrue);
#else // !defined(CFILET_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CFILET_MEMBER_FUNCS_IMPLEMENT) 
        return isOpen;
    }
#endif // defined(CFILET_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    //  Function: GetIsOpen
    //
    //    Author: $author$
    //      Date: 5/31/2011
    ///////////////////////////////////////////////////////////////////////
    virtual bool GetIsOpen() const
#if defined(CFILET_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CFILET_MEMBER_FUNCS_INTERFACE) 
    {
        bool isOpen = false;
#if !defined(CFILET_MEMBER_FUNCS_IMPLEMENT)
        isOpen = (m_isOpen);
#else // !defined(CFILET_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CFILET_MEMBER_FUNCS_IMPLEMENT) 
        return isOpen;
    }
#endif // defined(CFILET_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    //  Function: IsOpen
    //
    //    Author: $author$
    //      Date: 5/31/2011
    ///////////////////////////////////////////////////////////////////////
    virtual bool IsOpen() const
#if defined(CFILET_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CFILET_MEMBER_FUNCS_INTERFACE) 
    {
        bool isOpen = false;
#if !defined(CFILET_MEMBER_FUNCS_IMPLEMENT)
        isOpen = (m_isOpen);
#else // !defined(CFILET_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CFILET_MEMBER_FUNCS_IMPLEMENT) 
        return isOpen;
    }
#endif // defined(CFILET_MEMBER_FUNCS_INTERFACE) 

    ///////////////////////////////////////////////////////////////////////
    //  Function: Attach
    //
    //    Author: $author$
    //      Date: 5/31/2011
    ///////////////////////////////////////////////////////////////////////
    virtual FILE* Attach
    (FILE* attachedTo, bool onlyDetached=false)
#if defined(CFILET_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CFILET_MEMBER_FUNCS_INTERFACE) 
    {
        FILE* attached = 0;
#if !defined(CFILET_MEMBER_FUNCS_IMPLEMENT)
        if (!(onlyDetached) || !(m_attached))
            attached = (m_attached = attachedTo);
#else // !defined(CFILET_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CFILET_MEMBER_FUNCS_IMPLEMENT) 
        return attached;
    }
#endif // defined(CFILET_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    //  Function: Detach
    //
    //    Author: $author$
    //      Date: 5/31/2011
    ///////////////////////////////////////////////////////////////////////
    virtual FILE* Detach()
#if defined(CFILET_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CFILET_MEMBER_FUNCS_INTERFACE) 
    {
        FILE* detached = 0;
#if !defined(CFILET_MEMBER_FUNCS_IMPLEMENT)
        detached = (m_attached);
        m_attached = 0;
#else // !defined(CFILET_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CFILET_MEMBER_FUNCS_IMPLEMENT) 
        return detached;
    }
#endif // defined(CFILET_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    //  Function: Attached
    //
    //    Author: $author$
    //      Date: 5/31/2011
    ///////////////////////////////////////////////////////////////////////
    virtual FILE* Attached() const
#if defined(CFILET_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CFILET_MEMBER_FUNCS_INTERFACE) 
    {
        FILE* attached = 0;
#if !defined(CFILET_MEMBER_FUNCS_IMPLEMENT)
        attached = (m_attached);
#else // !defined(CFILET_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CFILET_MEMBER_FUNCS_IMPLEMENT) 
        return attached;
    }
#endif // defined(CFILET_MEMBER_FUNCS_INTERFACE) 

    ///////////////////////////////////////////////////////////////////////
    //  Function: Read
    //
    //    Author: $author$
    //      Date: 6/1/2011
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t Read
    (tWhat* what,
     size_t size)
#if defined(CFILET_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CFILET_MEMBER_FUNCS_INTERFACE) 
    {
        ssize_t count = -e_ERROR_FAILED;
#if !defined(CFILET_MEMBER_FUNCS_IMPLEMENT)
        FILE* attached;
        if ((what))
        if ((attached = Attached()))
        if (1 > (size))
            return count = 0;
        else
        if (0 > (count = fread(what, sizeof(tWhat), size, attached)))
            count = -e_ERROR_FAILED;
#else // !defined(CFILET_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CFILET_MEMBER_FUNCS_IMPLEMENT) 
        return count;
    }
#endif // defined(CFILET_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    //  Function: Write
    //
    //    Author: $author$
    //      Date: 6/1/2011
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t Write
    (const tWhat* what,
     ssize_t length=-1)
#if defined(CFILET_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CFILET_MEMBER_FUNCS_INTERFACE) 
    {
        ssize_t count = -e_ERROR_FAILED;
#if !defined(CFILET_MEMBER_FUNCS_IMPLEMENT)
        FILE* attached;
        if ((what))
        if ((attached = Attached()))
        if (0 > (length))
            return count = -e_ERROR_FAILED;
        else
        if (1 > (length))
            return count = 0;
        else
        if (0 > (count = fwrite(what, sizeof(tWhat), length, attached)))
            count = -e_ERROR_FAILED;
#else // !defined(CFILET_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CFILET_MEMBER_FUNCS_IMPLEMENT) 
        return count;
    }
#endif // defined(CFILET_MEMBER_FUNCS_INTERFACE) 

    ///////////////////////////////////////////////////////////////////////
    //  Function: Flush
    //
    //    Author: $author$
    //      Date: 7/6/2011
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t Flush()
#if defined(CFILET_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CFILET_MEMBER_FUNCS_INTERFACE) 
    {
        ssize_t count = -e_ERROR_FAILED;
#if !defined(CFILET_MEMBER_FUNCS_IMPLEMENT)
        FILE* attached;
        if ((attached = Attached()))
        if (0 > (count = fflush(attached)))
            count = -e_ERROR_FAILED;
#else // !defined(CFILET_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CFILET_MEMBER_FUNCS_IMPLEMENT) 
        return count;
    }
#endif // defined(CFILET_MEMBER_FUNCS_INTERFACE) 

    ///////////////////////////////////////////////////////////////////////
    //  Function: GetSize
    //
    //    Author: $author$
    //      Date: 11/22/2012
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t GetSize()
#if defined(CFILET_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CFILET_MEMBER_FUNCS_INTERFACE) 
    {
        ssize_t count = -e_ERROR_FAILED;
#if !defined(CFILET_MEMBER_FUNCS_IMPLEMENT)
        FILE* attached;
        struct stat st;
        int err;
        if ((attached = Attached()))
        if (!(err = fstat(fileno(attached), &st)))
            count = st.st_size;
#else // !defined(CFILET_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CFILET_MEMBER_FUNCS_IMPLEMENT) 
        return count;
    }
#endif // defined(CFILET_MEMBER_FUNCS_INTERFACE) 
#if !defined(CFILET_MEMBERS_ONLY)
};
#undef CDB_CLASS

///////////////////////////////////////////////////////////////////////
// Typedef: cFileExtends
//
//  Author: $author$
//    Date: 6/2/2011
///////////////////////////////////////////////////////////////////////
typedef cFileT<cFileImplement,cStream,char>
cFileExtends;
///////////////////////////////////////////////////////////////////////
//  Class: cFile
//
// Author: $author$
//   Date: 6/2/2011
///////////////////////////////////////////////////////////////////////
class c_INSTANCE_CLASS cFile
: public cFileExtends
{
public:
    typedef cFileExtends cExtends;
    ///////////////////////////////////////////////////////////////////////
    //  Constructor: cFile
    //
    //       Author: $author$
    //         Date: 6/2/2011
    ///////////////////////////////////////////////////////////////////////
    cFile
    (FILE* attached=0,
     bool isOpen=false)
    : cExtends(attached,isOpen)
    {
    }
};

#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#else // !defined(CFILET_MEMBERS_ONLY) 
#endif // !defined(CFILET_MEMBERS_ONLY) 

#endif // !defined(_CFILE_HPP) || defined(CFILET_MEMBERS_ONLY) 
        

