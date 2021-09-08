///////////////////////////////////////////////////////////////////////
//   File: cevcs.hpp
//
// Author: $author$
//   Date: 10/8/2007
//
//    $Id$
///////////////////////////////////////////////////////////////////////

#ifndef _CEVCS_HPP
#define _CEVCS_HPP

#include "evcs.hpp"
#include "evcsarchive.hpp"
#include "cevinstance.hpp"
#include "cevstring.hpp"

///////////////////////////////////////////////////////////////////////
//  Class: CEvcs
//
// Author: $author$
//   Date: 10/8/2007
///////////////////////////////////////////////////////////////////////
class CEvcs
: virtual public Evcs,
  public CEvInstance
{
public:
    typedef Evcs CImplements;
    typedef CEvInstance CExtends;
    typedef CEvcs CDerives;

    EvcsAllocator* m_allocator;
    EvcsArchive* m_archive;
    CEvString m_name;

    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvcs
    //
    //       Author: $author$
    //         Date: 10/8/2007
    ///////////////////////////////////////////////////////////////////////
    CEvcs
    (EvcsAllocator* allocator=0, 
     const char* name=0) 
    : m_allocator(allocator),
      m_archive(0)
    {
        EvError error;
        LONG length;

        if (name)
        if (0 > (length = m_name.Assign(name)))
            throw(error = -length);
    }
    ///////////////////////////////////////////////////////////////////////
    // Destructor: ~CEvcs
    //
    //      Author: $author$
    //        Date: 10/8/2007
    ///////////////////////////////////////////////////////////////////////
    virtual ~CEvcs()
    {
        EvError error;

        if (m_archive)
        if ((error = m_archive->Close()))
            throw(error);
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: OpenArchive
    //
    //   Author: $author$
    //     Date: 9/28/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvcsArchive* OpenArchive
    (EvError& error,
     const char* name=0,
     LONG length=-1) 
    {
        EvcsArchive* archive = 0;
        error = EV_ERROR_FAILED;

        if ((archive = m_archive))
            error = EV_ERROR_NONE;
        else
        if ((archive = EvcsArchive::Open(error, name, length)))
            m_archive = archive;
        return archive;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: CloseArchive
    //
    //   Author: $author$
    //     Date: 9/28/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError CloseArchive
    (EvcsArchive& archive) 
    {
        EvError error = EV_ERROR_FAILED;
        if (&archive == m_archive)
            error = EV_ERROR_NONE;
        return error;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: SetAllocator
    //
    //   Author: $author$
    //     Date: 5/24/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvcsAllocator* SetAllocator
    (EvcsAllocator* allocator) 
    {
        m_allocator = allocator;
        return m_allocator;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: GetAllocator
    //
    //   Author: $author$
    //     Date: 5/24/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvcsAllocator* GetAllocator() const 
    {
        return m_allocator;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: SetName
    //
    //   Author: $author$
    //     Date: 5/26/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG SetName
    (const char* chars, LONG length=-1) 
    {
        length = m_name.Assign(chars, length);
        return length;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: GetName
    //
    //   Author: $author$
    //     Date: 5/26/2007
    ///////////////////////////////////////////////////////////////////////
    virtual const char* GetName
    (LONG& length) const 
    {
        const char* chars = m_name.Chars(length);
        return chars;
    }
};
#endif // _CEVCS_HPP
