///////////////////////////////////////////////////////////////////////
//   File: cevcsarchiveservlet.hpp
//
// Author: $author$
//   Date: 12/26/2007
///////////////////////////////////////////////////////////////////////

#ifndef _CEVCSARCHIVESERVLET_HPP
#define _CEVCSARCHIVESERVLET_HPP

#include "evcpservlet.hpp"
#include "cevcsservlet.hpp"
#include "evcsarchive.hpp"
#include "cevcsentry.hpp"
#include "cevreadwritebuffer.hpp"

#define DEFAULT_EVCS_BLOCK_SIZE 4096

///////////////////////////////////////////////////////////////////////
//  Class: CEvcsArchiveServlet
//
// Author: $author$
//   Date: 12/26/2007
///////////////////////////////////////////////////////////////////////
class CEvcsArchiveServlet
: public CEvcsServlet
{
public:
    typedef CEvcsServlet CExtends;
    typedef CEvcsArchiveServlet CDerives;
    
    EvcsArchive* m_archive;

    bool m_isBinary;
    ULONG m_blockSize;
    ULONG m_blockLength;

    CEvCharReadWriteBuffer m_buffer;
    char* m_bufferChars;

    CEvcsEntry m_entry;

    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvcsArchiveServlet
    //
    //       Author: $author$
    //         Date: 12/26/2007
    ///////////////////////////////////////////////////////////////////////
    CEvcsArchiveServlet
    (const char* name,
     LONG length=-1) 
    : CExtends(name, length),
      m_archive(0),
      m_isBinary(false),
      m_blockSize(DEFAULT_EVCS_BLOCK_SIZE),
      m_blockLength(0) 
    {
    }
    ///////////////////////////////////////////////////////////////////////
    // Destructor: ~CEvcsArchiveServlet
    //
    //      Author: $author$
    //        Date: 12/26/2007
    ///////////////////////////////////////////////////////////////////////
    virtual ~CEvcsArchiveServlet()
    {
    }
    
    ///////////////////////////////////////////////////////////////////////
    // Function: Initialize
    //
    //   Author: $author$
    //     Date: 12/26/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError Initialize(EvServletServer& server) 
    {
        EvError error = EV_ERROR_NONE;
        DBF("() in...\n");
        DBF("() ...out\n");
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: Finalize
    //
    //   Author: $author$
    //     Date: 12/26/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError Finalize(EvServletServer& server) 
    {
        EvError error = EV_ERROR_NONE;
        DBF("() in...\n");
        DBF("() ...out\n");
        return error;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: ConnectionInitialize
    //
    //   Author: $author$
    //     Date: 12/26/2007
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
    //     Date: 12/26/2007
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
    //     Date: 12/26/2007
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
    //     Date: 12/26/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError FreeBuffer() 
    {
        EvError error = m_buffer.FreeBuffer();
        return error;
    }
};

#endif // _CEVCSARCHIVESERVLET_HPP
