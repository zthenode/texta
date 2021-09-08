///////////////////////////////////////////////////////////////////////
//   File: cevcsarchivecontextevcpservlet.hpp
//
// Author: $author$
//   Date: 10/4/2007
//
//    $Id$
///////////////////////////////////////////////////////////////////////

#ifndef _CEVCSARCHIVECONTEXTEVCPSERVLET_HPP
#define _CEVCSARCHIVECONTEXTEVCPSERVLET_HPP

#include "cevcscontextevcpservlet.hpp"
#include "evcsarchive.hpp"
#include "cevcsentry.hpp"
#include "cevreadwritebuffer.hpp"

#define DEFAULT_CEVCSARCHIVECONTEXTEVCPSERVLET_NAME "EVCS_ARCHIVE_CONTEXT"
#define DEFAULT_EVCS_BLOCK_SIZE 4096

///////////////////////////////////////////////////////////////////////
//  Class: CEvcsArchiveContextEvcpServlet
//
// Author: $author$
//   Date: 10/4/2007
///////////////////////////////////////////////////////////////////////
class CEvcsArchiveContextEvcpServlet
: public CEvcsContextEvcpServlet
{
public:
    typedef CEvcsContextEvcpServlet CExtends;
    typedef CEvcsArchiveContextEvcpServlet CDerives;

    EvcsArchive* m_archive;

    bool m_isBinary;
    ULONG m_blockSize;
    ULONG m_blockLength;

    CEvCharReadWriteBuffer m_buffer;
    char* m_bufferChars;

    CEvcsEntry m_entry;

    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvcsArchiveContextEvcpServlet
    //
    //       Author: $author$
    //         Date: 10/4/2007
    ///////////////////////////////////////////////////////////////////////
    CEvcsArchiveContextEvcpServlet
    (const char* name=DEFAULT_CEVCSARCHIVECONTEXTEVCPSERVLET_NAME,
     LONG length=-1) 
    : CExtends(name, length),
      m_archive(0),
      m_isBinary(false),
      m_blockSize(DEFAULT_EVCS_BLOCK_SIZE),
      m_blockLength(0)
    {
    }
    ///////////////////////////////////////////////////////////////////////
    // Destructor: ~CEvcsArchiveContextEvcpServlet
    //
    //      Author: $author$
    //        Date: 10/4/2007
    ///////////////////////////////////////////////////////////////////////
    virtual ~CEvcsArchiveContextEvcpServlet()
    {
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: ConnectionInitialize
    //
    //   Author: $author$
    //     Date: 10/4/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError ConnectionInitialize
    (EvcpServletConnection& connection) 
    {
        EvError error = EV_ERROR_NONE;
        EvError error2;

        DBF("() in...\n");

        if (!(error = CExtends::ConnectionInitialize(connection)))
        if (!(m_archive = m_evcs->OpenArchive(error2)))
        {
            DBE("() failed to open evcs archive\n");
            CExtends::ConnectionFinalize(connection);
            error = EV_ERROR_FAILED;
        }
        DBF("() ...out\n");
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: ConnectionFinalize
    //
    //   Author: $author$
    //     Date: 10/4/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError ConnectionFinalize
    (EvcpServletConnection& connection) 
    {
        EvError error = EV_ERROR_NONE;
        DBF("() in...\n");
        error = CExtends::ConnectionFinalize(connection);
        DBF("() ...out\n");
        return error;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: AllocateBuffer
    //
    //   Author: $author$
    //     Date: 8/24/2007
    ///////////////////////////////////////////////////////////////////////
    virtual char* AllocateBuffer
    (ULONG bufferSize) 
    {
        char* chars = 0;
        EvError error2;
        LONG length;

        if (!(error2 = m_buffer.AllocateBuffer(bufferSize)))
            chars = m_buffer.GetWriteBuffer(length);
        return chars;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: FreeBuffer
    //
    //   Author: $author$
    //     Date: 8/24/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError FreeBuffer() 
    {
        EvError error = m_buffer.FreeBuffer();
        return error;
    }
};

#endif // _CEVCSARCHIVECONTEXTEVCPSERVLET_HPP
