/**
 **********************************************************************
 * Copyright (c) 1988-2008 $organization$
 *
 * This software is provided by the author and contributors ``as is'' 
 * and any express or implied warranties, including, but not limited to, 
 * the implied warranties of merchantability and fitness for a particular 
 * purpose are disclaimed. In no event shall the author or contributors 
 * be liable for any direct, indirect, incidental, special, exemplary, 
 * or consequential damages (including, but not limited to, procurement 
 * of substitute goods or services; loss of use, data, or profits; or 
 * business interruption) however caused and on any theory of liability, 
 * whether in contract, strict liability, or tort (including negligence 
 * or otherwise) arising in any way out of the use of this software, 
 * even if advised of the possibility of such damage.
 *
 *   File: cdevice.hxx
 *
 * Author: $author$
 *   Date: 1/3/2008
 **********************************************************************
 */
#ifndef _CDEVICE_HXX
#define _CDEVICE_HXX

#include "cdeviceinterface.hxx"
#include "cattached.hxx"
#include "cio.hxx"
#include "cbuffer.hxx"
#include "cdebug.h"

/**
 **********************************************************************
 * Typedef: cDEVICEAttached
 *
 *  Author: $author$
 *    Date: 1/3/2008
 **********************************************************************
 */
typedef cAttachedT
<DEVICE, DEVICE, INVALID_DEVICE,
 cDEVICEAttachedInterface, cBase>
cDEVICEAttached;

#undef CDB_CLASS
#define CDB_CLASS "cDeviceT"
/**
 **********************************************************************
 *  Class: cDeviceT
 *
 * Author: $author$
 *   Date: 1/3/2008
 **********************************************************************
 */
template
<class TChar=CHAR,
 class TWhat=CHAR,
 class TSize=TSIZE,
 class TLength=TLENGTH,
 TLength VUndefined=UNDEFINED_LENGTH,
 class TDeviceImplements=cDeviceImplement,
 class TStreamImplements=cStreamImplement,
 class TOpenedImplements=cOpenedImplement,
 class TExtends=cDEVICEAttached>
 
class cDeviceT
: virtual public TOpenedImplements,
  virtual public TStreamImplements,
  virtual public TDeviceImplements,
  public TExtends
{
public:
    typedef TExtends cExtends;

    /**
     **********************************************************************
     * Constructor: cDeviceT
     *
     *      Author: $author$
     *        Date: 1/3/2008
     **********************************************************************
     */
    cDeviceT
	(DEVICE attached=INVALID_DEVICE)
	: cExtends(attached)
    {
    }
    /**
     **********************************************************************
     * Destructor: cDeviceT
     *
     *     Author: $author$
     *       Date: 1/3/2008
     **********************************************************************
     */
    virtual ~cDeviceT()
    {
    }

    /**
     **********************************************************************
     * Function: Open
     *
     *   Author: $author$
     *     Date: 1/3/2008
     **********************************************************************
     */
    virtual eError Open
    (const TChar* name,
     const MODE mode,
     bool onlyClosed=true) 
    {
        eSMode sMode = e_S_IRWXU;
        eOMode oMode = (eOMode)(mode);
        eError error = Open
        (name, oMode, sMode, onlyClosed);
        return error;
    }
    /**
     **********************************************************************
     * Function: Open
     *
     *   Author: $author$
     *     Date: 1/3/2008
     **********************************************************************
     */
    virtual eError Open
    (const TChar* name,
     eOMode oMode=e_O_RDWR,
     eSMode sMode=e_S_IRWXU,
     bool onlyClosed=true) 
    {
        eError error = e_ERROR_NOT_IMPLEMENTED;
        eError error2;
		DEVICE attached;

        if (INVALID_DEVICE != (*this).m_attached)
        if (onlyClosed)
            return e_ERROR_ALREADY_ATTACHED;
        else 
        if ((error2 = Close(true)))
            return error2;

#if defined(WIN32) 
/* Windows
 */
        DWORD access=0;
        DWORD shared=0;
        PSECURITY_ATTRIBUTES security=NULL;
        DWORD creation=OPEN_EXISTING;
        DWORD attributes=0;
        HANDLE templatefile=NULL;

        if (0 != (oMode & (e_O_RDWR | e_O_RDONLY)))
            access |= GENERIC_READ;

        if (0 != (oMode & (e_O_RDWR | e_O_WRONLY)))
            access |= GENERIC_WRITE;

        if (0 == (oMode & e_O_EXCL))
            shared |= (FILE_SHARE_READ | FILE_SHARE_WRITE);

#if defined(TCHAR_NOT_CHAR)
/* WCHAR
 */
		cTCHARBuffer tbuffer(name);
		const TCHAR* tname = tbuffer.GetBuffer();

        if (INVALID_DEVICE == (attached = CreateFile
            (tname, access, shared, security, 
             creation, attributes, templatefile)))
            return e_ERROR_OPEN;
#else /* defined(TCHAR_NOT_CHAR) */
/* char
 */
        if (INVALID_DEVICE == (attached = CreateFile
            (name, access, shared, security, 
             creation, attributes, templatefile)))
            return e_ERROR_OPEN;
#endif /* defined(_WIN32_WCE) */

		(*this).m_attached = attached;
		error = e_ERROR_NONE;
#else /* defined(WIN32) */
/* Unix
 */
        MODE pOMode;
        MODE_T pSMode;

        if ((error = OModeToPlatform(pOMode, oMode)))
            return e_ERROR_INVALID_OPTION;

        if ((error = SModeToPlatform(pSMode, sMode)))
            return e_ERROR_INVALID_MODE;

        if (0 > (attached = open(name, pOMode, pSMode)))
            return e_ERROR_OPEN;

		(*this).m_attached = attached;
		error = e_ERROR_NONE;
#endif /* defined(WIN32) */

        return error;
    }
    /**
     **********************************************************************
     * Function: Close
     *
     *   Author: $author$
     *     Date: 1/3/2008
     **********************************************************************
     */
    virtual eError Close
    (bool onlyOpened=false) 
    {
        eError error = e_ERROR_NOT_IMPLEMENTED;

        if (INVALID_DEVICE == (*this).m_attached)
        if (onlyOpened)
            return e_ERROR_NOT_ATTACHED;
        else return e_ERROR_NONE;

#if defined(WIN32) 
/* Windows
 */
        if (!CloseHandle((*this).m_attached))
            return e_ERROR_CLOSE;
        else error = e_ERROR_NONE;
#else /* defined(WIN32) */
/* Unix
 */
        int err;
        if ((err = close((*this).m_attached)))
            return e_ERROR_CLOSE;
        else error = e_ERROR_NONE;
#endif /* defined(WIN32) */

        (*this).m_attached = INVALID_DEVICE;
        return error;
    }

    /**
     **********************************************************************
     * Function: Read
     *
     *   Author: $author$
     *     Date: 1/10/2007
     **********************************************************************
     */
    virtual TLength Read
    (TWhat* what, TSize size) 
    {
        TLength length = -e_ERROR_FAILED;

        if (INVALID_DEVICE == (*this).m_attached)
            return -e_ERROR_NOT_ATTACHED;
        
        if (1 > size)
            return 0;

#if defined(WIN32) 
/* Windows
 */
        DWORD read;
        if (ReadFile
            (CTHIS m_attached, what, 
             sizeof(TWhat)*size, &read, NULL))
            length = read;
        else return -e_ERROR_READ;
#else /* defined(WIN32) */
/* Unix
 */
        //CDBE("() read(..., ..., %d)...\n", sizeof(TWhat)*size);

        if (0 > (length = read
            (CTHIS m_attached, what, sizeof(TWhat)*size)))
        {
            //CDBE("() failed on read\n");
            return -e_ERROR_READ;
        }

        //CDBE("() ...read %d = \"%*s\"\n", length, length, what);
#endif /* defined(WIN32) */
        return length;
    }
    /**
     **********************************************************************
     * Function: Write
     *
     *   Author: $author$
     *     Date: 1/13/2007
     **********************************************************************
     */
    virtual TLength Write
    (const TWhat* what, TLength length = VUndefined) 
    {
        TLength count = -e_ERROR_FAILED;

        if (INVALID_DEVICE == (*this).m_attached)
            return -e_ERROR_NOT_ATTACHED;
        
        if (0 > length)
            length = GetLengthOf(what);

#if defined(WIN32) 
/* Windows
 */
        DWORD written;
        if (WriteFile
            ((*this).m_attached, what, 
             sizeof(TWhat)*length, &written, NULL))
            count = written;
        else return -e_ERROR_WRITE;
#else /* defined(WIN32) */
/* Unix
 */
        if (0 > (count = write
            ((*this).m_attached, what, sizeof(TWhat)*length)))
            return -e_ERROR_WRITE;
#endif /* defined(WIN32) */
        return count;
    }
    /**
     **********************************************************************
     * Function: GetLengthOf
     *
     *   Author: $author$
     *     Date: 1/6/2008
     **********************************************************************
     */
    virtual TLength GetLengthOf
    (const TWhat* what) 
    {
        TLength length;
        for (length=0; ((*what) != 0); length++)
            what++;
        return length;
    }
};
#undef CDB_CLASS

/**
 **********************************************************************
 * Typedef: cCharDevice
 *
 *  Author: $author$
 *    Date: 1/3/2008
 **********************************************************************
 */
typedef cDeviceT
<CHAR, CHAR, TSIZE, TLENGTH, UNDEFINED_LENGTH,
 cDeviceImplement, cStreamImplement, 
 cOpenedImplement, cDEVICEAttached>
cDevice;

/*
 * char
 */

/**
 **********************************************************************
 * Typedef: cCharDevice
 *
 *  Author: $author$
 *    Date: 1/3/2008
 **********************************************************************
 */
typedef cDeviceT
<char, char, TSIZE, TLENGTH, UNDEFINED_LENGTH,
 cCharDeviceImplement, cCharStreamImplement, 
 cOpenedImplement, cDEVICEAttached>
cCharDevice;

/*
 * BYTE
 */

/**
 **********************************************************************
 * Typedef: cBYTEDevice
 *
 *  Author: $author$
 *    Date: 1/3/2008
 **********************************************************************
 */
typedef cDeviceT
<char, BYTE, TSIZE, TLENGTH, UNDEFINED_LENGTH,
 cBYTEDeviceImplement, cBYTEStreamImplement, 
 cOpenedImplement, cDEVICEAttached>
cBYTEDevice;

#endif /* _CDEVICE_HXX */
