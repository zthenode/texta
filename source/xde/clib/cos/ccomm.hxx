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
 *   File: ccomm.hxx
 *
 * Author: $author$
 *   Date: 1/4/2008
 **********************************************************************
 */
#ifndef _CCOMM_HXX
#define _CCOMM_HXX

#include "cdevice.hxx"
#include "cplatform_comm.h"
#include "cdebug.h"

#undef CDB_CLASS
#define CDB_CLASS "cCommT"
/**
 **********************************************************************
 *  Class: cCommT
 *
 * Author: $author$
 *   Date: 1/4/2008
 **********************************************************************
 */
template
<class TChar=CHAR,
 class TWhat=CHAR,
 class TSize=TSIZE,
 class TLength=TLENGTH,
 TLength VUndefined=UNDEFINED_LENGTH,
 class TExtends=cDevice>
 
class cCommT
: public TExtends
{
public:
    typedef TExtends cExtends;
    typedef cCommT cDerives;

    int m_baud, m_parity, m_bits, m_stop_bits;
    bool m_rtscts_flow_on, m_xonxoff_flow_on;

#if defined(WIN32) 
/* Windows
 */
    DCB m_dcb;
    COMMTIMEOUTS m_ct;
#else /* defined(WIN32) */
/* Unix
 */
    struct termio m_termios;
#endif /* defined(WIN32) */

    /**
     **********************************************************************
     * Constructor: cCommT
     *
     *      Author: $author$
     *        Date: 1/4/2008
     **********************************************************************
     */
    cCommT
    (int baud=DEFAULT_COMM_BAUD,
     int parity=DEFAULT_COMM_PARITY,
     int bits=DEFAULT_COMM_BITS,
     int stop_bits=DEFAULT_COMM_STOP_BITS,
     bool rtscts_flow_on=DEFAULT_COMM_RTSCTS_FLOW_ON,
     bool xonxoff_flow_on=DEFAULT_COMM_XONXOFF_FLOW_ON,
     DEVICE attached=INVALID_DEVICE)
	: cExtends(attached),
      m_baud(baud),
      m_parity(parity),
      m_bits(bits),
      m_stop_bits(stop_bits),
      m_rtscts_flow_on(rtscts_flow_on),
      m_xonxoff_flow_on(xonxoff_flow_on) 
    {
    }
    /**
     **********************************************************************
     * Destructor: cCommT
     *
     *     Author: $author$
     *       Date: 1/4/2008
     **********************************************************************
     */
    virtual ~cCommT()
    {
    }

    /**
     **********************************************************************
     * Function: Open
     *
     *   Author: $author$
     *     Date: 2/4/2009
     **********************************************************************
     */
    virtual eError Open
    (const TChar* name,
     int baud, int bits, 
     int stopBits, int parity,
     eOMode oMode=e_O_RDWR,
     eSMode sMode=e_S_IRWXU,
     bool onlyClosed=true) 
    {
        eError error = e_ERROR_FAILED;
        int count;
        if (0 > (count = SetBaud(baud)))
            CDBT("() failed to set baud\n");
        else
        if (0 > (count = SetBits(bits)))
            CDBT("() failed to set bits\n");
        else
        if (0 > (count = SetStopBits(stopBits)))
            CDBT("() failed to set stop bits\n");
        else
        if (0 > (count = SetParity(parity)))
            CDBT("() failed to set parity\n");
        else
        error = Open(name, oMode, sMode, onlyClosed);
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
        int value;

        CDBT("(\"%s\")...\n", name);

        if ((error = cExtends::Open(name, oMode, sMode)))
        {
            CDBE("() failed to open \"%s\"\n", name);
            return error;
        }

        CDBT("()... opened \"%s\"\n", name);

#if defined(WIN32) 
/* Windows
 */
        if (!GetCommTimeouts(m_attached, &m_ct))
        {
            CDBE("() failed to GetCommTimeouts\n");
            Close();
            return e_ERROR_FAILED;
        }

        m_ct.ReadIntervalTimeout = 0;
        m_ct.ReadTotalTimeoutConstant = 0;
        m_ct.ReadTotalTimeoutMultiplier = 0;
        m_ct.WriteTotalTimeoutConstant = 0;
        m_ct.WriteTotalTimeoutMultiplier = 0;

        if (!SetCommTimeouts(m_attached, &m_ct))
        {
            CDBE("() failed to SetCommTimeouts\n");
            Close();
            return e_ERROR_FAILED;
        }

        if ((value = GetCommState(m_dcb)))
        {
            Close();
            return e_ERROR_FAILED;
        }

        //m_dcb.fOutxCtsFlow = TRUE;
        m_dcb.fOutxCtsFlow = m_rtscts_flow_on;

        //m_dcb.fRtsControl = RTS_CONTROL_ENABLE;
        //m_dcb.fRtsControl = RTS_CONTROL_DISABLE;
        //m_dcb.fRtsControl = RTS_CONTROL_HANDSHAKE;
        //m_dcb.fRtsControl = RTS_CONTROL_TOGGLE;
        m_dcb.fRtsControl = m_rtscts_flow_on?RTS_CONTROL_HANDSHAKE:RTS_CONTROL_DISABLE;

        //m_dcb.fOutxDsrFlow = TRUE;
        m_dcb.fOutxDsrFlow = FALSE;

        //m_dcb.fDtrControl = DTR_CONTROL_ENABLE;
        m_dcb.fDtrControl = DTR_CONTROL_DISABLE;
        //m_dcb.fDtrControl = DTR_CONTROL_HANDSHAKE;

        //m_dcb.fDsrSensitivity = TRUE;
        m_dcb.fDsrSensitivity= FALSE;

        m_dcb.BaudRate = m_baud;
        m_dcb.ByteSize = m_bits;
        m_dcb.StopBits = m_stop_bits;
        m_dcb.Parity = m_parity;

        if ((value = SetCommState(m_dcb)))
        {
            Close();
            return e_ERROR_FAILED;
        }
        error = e_ERROR_NONE;
#else /* defined(WIN32) */
/* Unix
 */
        /* Clear all of the bits in the termio structure. 
         */
        memset(&m_termios, 0, sizeof(m_termios));

        /* Set the port to ignore modem control lines and enable
         * reading.
         */
        m_termios.c_cflag |= CLOCAL | CREAD;

        /* Set the baud rate for the port. 
         */
        m_termios.c_cflag |= m_baud;

        /* Set the parity for the port. 
         */
        m_termios.c_cflag |= m_parity;

        /* Set the data bits for the port. 
         */
        m_termios.c_cflag |= m_bits;

        /* Set the stop bits for the port. 
         */
        m_termios.c_cflag |= m_stop_bits;

        /* Set hardware flow control. 
         */
        if (m_rtscts_flow_on)
            m_termios.c_cflag |= CRTSCTS;

        /* Set software flow control. 
         */
        if (m_xonxoff_flow_on)
            m_termios.c_iflag |= IXON | IXOFF;

        /* Set the timeout value for read when there are no
         * characters on the port.
         */
        m_termios.c_cc[VTIME] = 0;

        /* Set the minimum number of characters that must be present
         * before read() returns.
         */
        m_termios.c_cc[VMIN] = 1;

        /* Configure the port using the termios values. 
         */
        if ((value = TcSetAttr(m_termios)))
        {
            CTHIS Close();
            return e_ERROR_FAILED;
        }
        error = e_ERROR_NONE;
#endif /* defined(WIN32) */

        return error;
    }

    /**
     **********************************************************************
     * Function: WriteRTS
     *
     *   Author: $author$
     *     Date: 1/6/2008
     **********************************************************************
     */
    virtual int WriteRTS
    (int value) 
    {
        int rvalue = -e_ERROR_NOT_IMPLEMENTED;

        if (INVALID_DEVICE == CTHIS m_attached)
            return -e_ERROR_NOT_ATTACHED;

#if defined(WIN32) 
/* Windows
 */
        if ((rvalue = GetCommState(m_dcb)))
            return rvalue;

        m_dcb.fRtsControl = value?RTS_CONTROL_ENABLE:RTS_CONTROL_DISABLE;

        if ((rvalue = SetCommState(m_dcb)))
            return rvalue;

        rvalue = value;
#else /* defined(WIN32) */
/* Unix
 */
#endif /* defined(WIN32) */
        return rvalue;
    }
    /**
     **********************************************************************
     * Function: ReadCTS
     *
     *   Author: $author$
     *     Date: 1/6/2008
     **********************************************************************
     */
    virtual int ReadCTS() 
    {
        int value = -e_ERROR_NOT_IMPLEMENTED;

        if (INVALID_DEVICE == CTHIS m_attached)
            return -e_ERROR_NOT_ATTACHED;

#if defined(WIN32) 
/* Windows
 */
        DWORD modem;

        if ((value = GetCommModemStatus(modem)))
            return value;

        value = (0 != (modem & MS_CTS_ON));
#else /* defined(WIN32) */
/* Unix
 */
#endif /* defined(WIN32) */
        return value;
    }

    /**
     **********************************************************************
     * Function: SetRTSCTSFlow
     *
     *   Author: $author$
     *     Date: 1/6/2008
     **********************************************************************
     */
    virtual int SetRTSCTSFlow
    (bool on=true) 
    {
        int ron = -e_ERROR_NOT_IMPLEMENTED;

        if (INVALID_DEVICE == CTHIS m_attached)
            return m_rtscts_flow_on = on;

#if defined(WIN32) 
/* Windows
 */
        if ((ron = GetCommState(m_dcb)))
            return ron;

         m_dcb.fOutxCtsFlow = on;
         m_dcb.fRtsControl = on?RTS_CONTROL_HANDSHAKE:RTS_CONTROL_DISABLE;

        if ((ron = SetCommState(m_dcb)))
            return ron;

        ron = (m_rtscts_flow_on = on);
#else /* defined(WIN32) */
/* Unix
 */
        if ((ron = TcSetAttrCFlag
            (m_termios, (CRTSCTS), (on?(CRTSCTS):0))))
            return ron;

        ron = (m_rtscts_flow_on = on);
#endif /* defined(WIN32) */
        return ron;
    }
    /**
     **********************************************************************
     * Function: GetRTSCTSFlow
     *
     *   Author: $author$
     *     Date: 1/6/2008
     **********************************************************************
     */
    virtual int GetRTSCTSFlow()
    {
        int ron = -e_ERROR_NOT_IMPLEMENTED;

        if (INVALID_DEVICE == CTHIS m_attached)
            return m_rtscts_flow_on;

#if defined(WIN32) 
/* Windows
 */
        if ((ron = GetCommState(m_dcb)))
            return ron;

        ron = (m_dcb.fOutxCtsFlow 
               && (RTS_CONTROL_HANDSHAKE == m_dcb.fRtsControl));
#else /* defined(WIN32) */
/* Unix
 */
#endif /* defined(WIN32) */
        return ron;
    }

    /**
     **********************************************************************
     * Function: SetBaud
     *
     *   Author: $author$
     *     Date: 1/6/2008
     **********************************************************************
     */
    virtual int SetBaud
    (int value) 
    {
        int rvalue = -e_ERROR_NOT_IMPLEMENTED;

        if (INVALID_DEVICE == CTHIS m_attached)
            return m_baud = value;

#if defined(WIN32) 
/* Windows
 */
        if ((rvalue = GetCommState(m_dcb)))
            return rvalue;

        m_dcb.BaudRate = value;

        if ((rvalue = SetCommState(m_dcb)))
            return rvalue;

        rvalue = (m_baud = value);
#else /* defined(WIN32) */
/* Unix
 */
        if ((rvalue = TcSetAttrCFlag
            (m_termios, (CBAUD), (value &= CBAUD))))
            return rvalue;

        rvalue = (m_baud = value);
#endif /* defined(WIN32) */
        return rvalue;
    }
    /**
     **********************************************************************
     * Function: GetBaud
     *
     *   Author: $author$
     *     Date: 1/6/2008
     **********************************************************************
     */
    virtual int GetBaud()
    {
        int value = -e_ERROR_NOT_IMPLEMENTED;

        if (INVALID_DEVICE == CTHIS m_attached)
            return m_baud;

#if defined(WIN32) 
/* Windows
 */
        if ((value = GetCommState(m_dcb)))
            return value;

        value = m_dcb.BaudRate;
#else /* defined(WIN32) */
/* Unix
 */
        if ((value = TcGetAttr(m_termios)))
            return value;

        value = (m_termios.c_cflag & CBAUD);
#endif /* defined(WIN32) */
        return value;
    }

    /**
     **********************************************************************
     * Function: SetParity
     *
     *   Author: $author$
     *     Date: 1/6/2008
     **********************************************************************
     */
    virtual int SetParity
    (int value) 
    {
        int rvalue = -e_ERROR_NOT_IMPLEMENTED;

        if (INVALID_DEVICE == CTHIS m_attached)
            return m_parity = value;

#if defined(WIN32) 
/* Windows
 */
        if ((rvalue = GetCommState(m_dcb)))
            return rvalue;

        m_dcb.StopBits = value;

        if ((rvalue = SetCommState(m_dcb)))
            return rvalue;

        rvalue = (m_parity = value);
#else /* defined(WIN32) */
/* Unix
 */
        if ((rvalue = TcSetAttrCFlag
            (m_termios, (PARENB | PARODD), (value &= (PARENB | PARODD)))))
            return rvalue;

        rvalue = (m_parity = value);
#endif /* defined(WIN32) */
        return rvalue;
    }
    /**
     **********************************************************************
     * Function: GetParity
     *
     *   Author: $author$
     *     Date: 1/6/2008
     **********************************************************************
     */
    virtual int GetParity()
    {
        int value = -e_ERROR_NOT_IMPLEMENTED;

        if (INVALID_DEVICE == CTHIS m_attached)
            return m_parity;

#if defined(WIN32) 
/* Windows
 */
        if ((value = GetCommState(m_dcb)))
            return value;

        value = m_dcb.Parity;
#else /* defined(WIN32) */
/* Unix
 */
        if ((value = TcGetAttr(m_termios)))
            return value;

        value = (m_termios.c_cflag & (PARENB | PARODD));
#endif /* defined(WIN32) */
        return value;
    }

    /**
     **********************************************************************
     * Function: SetBits
     *
     *   Author: $author$
     *     Date: 1/6/2008
     **********************************************************************
     */
    virtual int SetBits
    (int value) 
    {
        int rvalue = -e_ERROR_NOT_IMPLEMENTED;

        if (INVALID_DEVICE == CTHIS m_attached)
            return m_bits = value;

#if defined(WIN32) 
/* Windows
 */
        if ((rvalue = GetCommState(m_dcb)))
            return rvalue;

        m_dcb.ByteSize = value;

        if ((rvalue = SetCommState(m_dcb)))
            return rvalue;

        rvalue = (m_bits = value);
#else /* defined(WIN32) */
/* Unix
 */
        if ((rvalue = TcSetAttrCFlag
            (m_termios, (CSIZE), (value &= (CSIZE)))))
            return rvalue;

        rvalue = (m_bits = value);
#endif /* defined(WIN32) */
        return rvalue;
    }
    /**
     **********************************************************************
     * Function: GetBits
     *
     *   Author: $author$
     *     Date: 1/6/2008
     **********************************************************************
     */
    virtual int GetBits()
    {
        int value = -e_ERROR_NOT_IMPLEMENTED;

        if (INVALID_DEVICE == CTHIS m_attached)
            return m_bits;

#if defined(WIN32) 
/* Windows
 */
        if ((value = GetCommState(m_dcb)))
            return value;

        value = m_dcb.ByteSize;
#else /* defined(WIN32) */
/* Unix
 */
        if ((value = TcGetAttr(m_termios)))
            return value;

        value = (m_termios.c_cflag & (CSIZE));
#endif /* defined(WIN32) */
        return value;
    }

    /**
     **********************************************************************
     * Function: SetStopBits
     *
     *   Author: $author$
     *     Date: 1/6/2008
     **********************************************************************
     */
    virtual int SetStopBits
    (int value) 
    {
        int rvalue = -e_ERROR_NOT_IMPLEMENTED;

        if (INVALID_DEVICE == CTHIS m_attached)
            return m_stop_bits = value;

#if defined(WIN32) 
/* Windows
 */
        if ((rvalue = GetCommState(m_dcb)))
            return rvalue;

        m_dcb.StopBits = value;

        if ((rvalue = SetCommState(m_dcb)))
            return rvalue;

        rvalue = (m_stop_bits = value);
#else /* defined(WIN32) */
/* Unix
 */
        if ((rvalue = TcSetAttrCFlag
            (m_termios, (CSTOPB), (value &= (CSTOPB)))))
            return rvalue;

        rvalue = (m_stop_bits = value);
#endif /* defined(WIN32) */
        return rvalue;
    }
    /**
     **********************************************************************
     * Function: GetStopBits
     *
     *   Author: $author$
     *     Date: 1/6/2008
     **********************************************************************
     */
    virtual int GetStopBits()
    {
        int value = -e_ERROR_NOT_IMPLEMENTED;

        if (INVALID_DEVICE == CTHIS m_attached)
            return m_stop_bits;

#if defined(WIN32) 
/* Windows
 */
        if ((value = GetCommState(m_dcb)))
            return value;

        value = m_dcb.StopBits;
#else /* defined(WIN32) */
/* Unix
 */
        if ((value = TcGetAttr(m_termios)))
            return value;

        value = (m_termios.c_cflag & (CSTOPB));
#endif /* defined(WIN32) */
        return value;
    }

#if defined(WIN32) 
/* Windows
 */
    /**
     **********************************************************************
     * Function: SetCommState
     *
     *   Author: $author$
     *     Date: 1/6/2008
     **********************************************************************
     */
    virtual int SetCommState(DCB& dcb) const
    {
        int value = -e_ERROR_FAILED;
        if (::SetCommState(m_attached, &dcb))
            value = e_ERROR_NONE;
        else CDBE("() failed to SetCommState\n");
        return value;
    }
    /**
     **********************************************************************
     * Function: GetCommState
     *
     *   Author: $author$
     *     Date: 1/6/2008
     **********************************************************************
     */
    virtual int GetCommState(DCB& dcb) const 
    {
        int value = -e_ERROR_FAILED;
        if (::GetCommState(m_attached, &dcb))
            value = e_ERROR_NONE;
        else CDBE("() failed to GetCommState\n");
        return value;
    }
    /**
     **********************************************************************
     * Function: GetCommModemStatus
     *
     *   Author: $author$
     *     Date: 1/6/2008
     **********************************************************************
     */
    virtual int GetCommModemStatus(DWORD& modem) const
    {
        int value = -e_ERROR_FAILED;
        if (::GetCommModemStatus(m_attached, &modem))
            value = e_ERROR_NONE;
        else CDBE("() failed to GetCommModemStatus\n");
        return value;
    }
#else /* defined(WIN32) */
/* Unix
 */
    /**
     **********************************************************************
     * Function: TcSetAttrCFlag
     *
     *   Author: $author$
     *     Date: 1/6/2008
     **********************************************************************
     */
    virtual int TcSetAttrCFlag
    (struct termio& termios, int cflag, int value) 
    {
        int rvalue;

        if ((rvalue = TcGetAttr(termios)))
            return rvalue;

        m_termios.c_cflag &= ~(cflag);
        m_termios.c_cflag |= (value & cflag);

        if ((rvalue = TcSetAttr(m_termios)))
            return rvalue;

        rvalue = e_ERROR_NONE;
        return rvalue;
    }
    /**
     **********************************************************************
     * Function: TcSetAttr
     *
     *   Author: $author$
     *     Date: 1/6/2008
     **********************************************************************
     */
    virtual int TcSetAttr
    (struct termio& termios) 
    {
        int value = -e_ERROR_FAILED;
        int err;
        if ((err = ioctl(CTHIS m_attached, TCSETA, &termios)))
            CDBE("() failed on ioctl(..., TCSETA, ...)\n");
        else value = e_ERROR_NONE;
        return value;
    }
    /**
     **********************************************************************
     * Function: TcGetAttr
     *
     *   Author: $author$
     *     Date: 1/6/2008
     **********************************************************************
     */
    virtual int TcGetAttr
    (struct termio& termios) 
    {
        int value = -e_ERROR_FAILED;
        int err;
        if ((err = ioctl(CTHIS m_attached, TCGETA, &termios)))
            CDBE("() failed on ioctl(..., TCGETA, ...)\n");
        else value = e_ERROR_NONE;
        return value;
    }
#endif /* defined(WIN32) */
};
#undef CDB_CLASS

/**
 **********************************************************************
 * Typedef: cComm
 *
 *  Author: $author$
 *    Date: 1/5/2008
 **********************************************************************
 */
typedef cCommT
<char, char, TSIZE, TLENGTH, 
 UNDEFINED_LENGTH, cCharDevice>
cComm;

/**
 **********************************************************************
 * Typedef: cBYTEComm
 *
 *  Author: $author$
 *    Date: 2/5/2009
 **********************************************************************
 */
typedef cCommT
<char, BYTE, TSIZE, TLENGTH, 
 UNDEFINED_LENGTH, cBYTEDevice>
cBYTEComm;

#endif /* _CCOMM_HXX */
