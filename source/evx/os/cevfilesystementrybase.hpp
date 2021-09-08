///////////////////////////////////////////////////////////////////////
//   File: cevfilesystementrybase.hpp
//
// Author: $author$
//   Date: 6/22/2007
//
//    $Id$
///////////////////////////////////////////////////////////////////////

#ifndef _CEVFILESYSTEMENTRYBASE_HPP
#define _CEVFILESYSTEMENTRYBASE_HPP

#include "evfilesystementrybase.hpp"
#include "cevstring.hpp"
#include "cevbase.hpp"

///////////////////////////////////////////////////////////////////////
//  Class: CEvFileSystemEntryBase
//
// Author: $author$
//   Date: 6/22/2007
///////////////////////////////////////////////////////////////////////
class CEvFileSystemEntryBase
: virtual public EvFileSystemEntryBase,
  public CEvBase
{
public:
    typedef EvFileSystemEntryBase CImplements;
    typedef CEvBase CExtends;
    typedef CEvFileSystemEntryBase CDerives;

    EvType m_type;
    ULONGLONG m_size;
    bool m_isArchive;
    bool m_isCompressed;
    bool m_isEncrypted;
    bool m_isHidden;
    bool m_isOffline;
    bool m_isReadOnly;
    bool m_isSystem;
    bool m_isTemporary;
    CEvString m_name;

    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvFileSystemEntryBase
    //
    //       Author: $author$
    //         Date: 6/22/2007
    ///////////////////////////////////////////////////////////////////////
    CEvFileSystemEntryBase
    (EvType type=EV_TYPE_NONE,
     const char* name=0, LONG length=-1) 
    : m_type(type),
      m_size(0),
      m_isArchive(false),
      m_isCompressed(false),
      m_isEncrypted(false),
      m_isHidden(false),
      m_isOffline(false),
      m_isReadOnly(false),
      m_isSystem(false),
      m_isTemporary(false) 
    {
        EvError error;
        if (name)
        if (0 > (length = SetName(name, length)))
            throw(error = -length);
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: SetName
    //
    //   Author: $author$
    //     Date: 5/4/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG SetName
    (const char* chars, LONG length=-1) 
    {
        m_name.Assign(chars, length);
        length = m_name.Length();
        return length;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: GetName
    //
    //   Author: $author$
    //     Date: 5/4/2007
    ///////////////////////////////////////////////////////////////////////
    virtual const char* GetName
    (LONG& length) const 
    {
        const char* chars = m_name.Chars(length);
        return chars;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: SetType
    //
    //   Author: $author$
    //     Date: 5/4/2007
    ///////////////////////////////////////////////////////////////////////
    virtual int SetType(EvType type) 
    {
        m_type = type;
        return m_type;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: GetType
    //
    //   Author: $author$
    //     Date: 5/4/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvType GetType() const 
    {
        return m_type;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: SetSize
    //
    //   Author: $author$
    //     Date: 7/17/2009
    ///////////////////////////////////////////////////////////////////////
    virtual LONGLONG SetSize
    (ULONGLONG size) 
    {
        m_size = size;
        return m_size;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: GetSize
    //
    //   Author: $author$
    //     Date: 7/17/2009
    ///////////////////////////////////////////////////////////////////////
    virtual ULONGLONG GetSize() const 
    {
        return m_size;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: SetIsDirectory
    //
    //   Author: $author$
    //     Date: 5/4/2007
    ///////////////////////////////////////////////////////////////////////
    virtual int SetIsDirectory(bool is=true) 
    {
        if (is)
            m_type |= EV_TYPE_DIRECTORY;
        else m_type &= ~((EvType)EV_TYPE_DIRECTORY);
        is = (EV_TYPE_DIRECTORY == (m_type & EV_TYPE_DIRECTORY));
        return is;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: GetIsDirectory
    //
    //   Author: $author$
    //     Date: 5/4/2007
    ///////////////////////////////////////////////////////////////////////
    virtual bool GetIsDirectory() const 
    {
        bool is = (EV_TYPE_DIRECTORY == (m_type & EV_TYPE_DIRECTORY));
        return is;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: SetIsArchive
    //
    //   Author: $author$
    //     Date: 5/22/2007
    ///////////////////////////////////////////////////////////////////////
    virtual int SetIsArchive
    (bool is=true) 
    {
        m_isArchive = is;
        return m_isArchive;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: GetIsArchive
    //
    //   Author: $author$
    //     Date: 5/22/2007
    ///////////////////////////////////////////////////////////////////////
    virtual bool GetIsArchive() const 
    {
        return m_isArchive;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: SetIsCompressed
    //
    //   Author: $author$
    //     Date: 5/22/2007
    ///////////////////////////////////////////////////////////////////////
    virtual int SetIsCompressed
    (bool is=true) 
    {
        m_isCompressed = is;
        return m_isCompressed;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: GetIsCompressed
    //
    //   Author: $author$
    //     Date: 5/22/2007
    ///////////////////////////////////////////////////////////////////////
    virtual bool GetIsCompressed() const 
    {
        return m_isCompressed;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: SetIsEncrypted
    //
    //   Author: $author$
    //     Date: 5/22/2007
    ///////////////////////////////////////////////////////////////////////
    virtual int SetIsEncrypted
    (bool is=true) 
    {
        m_isEncrypted = is;
        return m_isEncrypted;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: GetIsEncrypted
    //
    //   Author: $author$
    //     Date: 5/22/2007
    ///////////////////////////////////////////////////////////////////////
    virtual bool GetIsEncrypted() const 
    {
        return m_isEncrypted;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: SetIsHidden
    //
    //   Author: $author$
    //     Date: 5/22/2007
    ///////////////////////////////////////////////////////////////////////
    virtual int SetIsHidden
    (bool is=true) 
    {
        m_isHidden = is;
        return m_isHidden;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: GetIsHidden
    //
    //   Author: $author$
    //     Date: 5/22/2007
    ///////////////////////////////////////////////////////////////////////
    virtual bool GetIsHidden() const 
    {
        return m_isHidden;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: SetIsOffline
    //
    //   Author: $author$
    //     Date: 5/22/2007
    ///////////////////////////////////////////////////////////////////////
    virtual int SetIsOffline
    (bool is=true) 
    {
        m_isOffline = is;
        return m_isOffline;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: GetIsOffline
    //
    //   Author: $author$
    //     Date: 5/22/2007
    ///////////////////////////////////////////////////////////////////////
    virtual bool GetIsOffline() const 
    {
        return m_isOffline;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: SetIsReadOnly
    //
    //   Author: $author$
    //     Date: 5/22/2007
    ///////////////////////////////////////////////////////////////////////
    virtual int SetIsReadOnly
    (bool is=true) 
    {
        m_isReadOnly = is;
        return m_isReadOnly;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: GetIsReadOnly
    //
    //   Author: $author$
    //     Date: 5/22/2007
    ///////////////////////////////////////////////////////////////////////
    virtual bool GetIsReadOnly() const 
    {
        return m_isReadOnly;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: SetIsSystem
    //
    //   Author: $author$
    //     Date: 5/22/2007
    ///////////////////////////////////////////////////////////////////////
    virtual int SetIsSystem
    (bool is=true) 
    {
        m_isSystem = is;
        return m_isSystem;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: GetIsSystem
    //
    //   Author: $author$
    //     Date: 5/22/2007
    ///////////////////////////////////////////////////////////////////////
    virtual bool GetIsSystem() const 
    {
        return m_isSystem;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: SetIsTemporary
    //
    //   Author: $author$
    //     Date: 5/22/2007
    ///////////////////////////////////////////////////////////////////////
    virtual int SetIsTemporary
    (bool is=true) 
    {
        m_isTemporary = is;
        return m_isTemporary;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: GetIsTemporary
    //
    //   Author: $author$
    //     Date: 5/22/2007
    ///////////////////////////////////////////////////////////////////////
    virtual bool GetIsTemporary() const 
    {
        return m_isTemporary;
    }
};
#endif // _CEVFILESYSTEMENTRYBASE_HPP
