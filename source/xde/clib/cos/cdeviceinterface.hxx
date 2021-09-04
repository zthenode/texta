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
 *   File: cdeviceinterface.hxx
 *
 * Author: $author$
 *   Date: 1/3/2008
 **********************************************************************
 */
#ifndef _CDEVICEINTERFACE_HXX
#define _CDEVICEINTERFACE_HXX

#include "cplatform_ioctl.h"
#include "cplatform_device.h"
#include "cattachedinterface.hxx"
#include "copenedinterface.hxx"
#include "cstreaminterface.hxx"

/**
 **********************************************************************
 * Typedef: cDEVICEAttachInterface
 *
 *  Author: $author$
 *    Date: 1/3/2008
 **********************************************************************
 */
typedef cAttachInterfaceT
<DEVICE, cInterfaceBase>
cDEVICEAttachInterface;

/**
 **********************************************************************
 * Typedef: cDEVICEDetachInterface
 *
 *  Author: $author$
 *    Date: 1/3/2008
 **********************************************************************
 */
typedef cDetachInterfaceT
<DEVICE, cInterfaceBase>
cDEVICEDetachInterface;

/**
 **********************************************************************
 * Typedef: cDEVICEAttachedInterface
 *
 *  Author: $author$
 *    Date: 1/3/2008
 **********************************************************************
 */
typedef cAttachedInterfaceT
<DEVICE, cDEVICEAttachInterface, cDEVICEDetachInterface>
cDEVICEAttachedInterface;

/**
 **********************************************************************
 *  Class: cDeviceInterfaceT
 *
 * Author: $author$
 *   Date: 1/3/2008
 **********************************************************************
 */
template
<class TWhat=CHAR,
 class TSize=TSIZE,
 class TLength=TLENGTH,
 TLength VUndefined=UNDEFINED_LENGTH,
 class TStreamImplements=cStreamInterface,
 class TAttachedImplements=cDEVICEAttachedInterface,
 class TOpenedImplements=cOpenedInterface>
 
class c_INTERFACE_CLASS cDeviceInterfaceT
: virtual public TAttachedImplements,
  virtual public TOpenedImplements,
  virtual public TStreamImplements
  {
public:
    /**
     **********************************************************************
     * Function: Ioctl
     *
     *   Author: $author$
     *     Date: 1/3/2008
     **********************************************************************
     */
    virtual int Ioctl
    (int cmd, void *arg, int argsize, int retsize=-1) = 0;
    /**
     **********************************************************************
     * Function: Ioctl
     *
     *   Author: $author$
     *     Date: 1/3/2008
     **********************************************************************
     */
    virtual int Ioctl
    (int cmd) = 0;
};

/**
 **********************************************************************
 * Typedef: cDeviceInterface
 *
 *  Author: $author$
 *    Date: 1/3/2008
 **********************************************************************
 */
typedef cDeviceInterfaceT
<CHAR, TSIZE, TLENGTH, UNDEFINED_LENGTH,
 cStreamInterface, cDEVICEAttachedInterface, cOpenedInterface>
cDeviceInterface;

/**
 **********************************************************************
 *  Class: cDeviceImplementT
 *
 * Author: $author$
 *   Date: 1/3/2008
 **********************************************************************
 */
template
<class TWhat=CHAR,
 class TSize=TSIZE,
 class TLength=TLENGTH,
 TLength VUndefined=UNDEFINED_LENGTH,
 class TImplements=cDeviceInterface>
 
class cDeviceImplementT
: virtual public TImplements
{
public:
    /**
     **********************************************************************
     * Function: Ioctl
     *
     *   Author: $author$
     *     Date: 1/3/2008
     **********************************************************************
     */
    virtual int Ioctl
    (int cmd, void *arg, int argsize, int retsize=-1) 
    {
        int err = -e_ERROR_NOT_IMPLEMENTED;
        return err;
    }
    /**
     **********************************************************************
     * Function: Ioctl
     *
     *   Author: $author$
     *     Date: 1/3/2008
     **********************************************************************
     */
    virtual int Ioctl
    (int cmd) 
    {
        int err = -e_ERROR_NOT_IMPLEMENTED;
        return err;
    }
};

/**
 **********************************************************************
 * Typedef: cDeviceImplement
 *
 *  Author: $author$
 *    Date: 1/3/2008
 **********************************************************************
 */
typedef cDeviceImplementT
<CHAR, TSIZE, TLENGTH, UNDEFINED_LENGTH,
 cDeviceInterface>
cDeviceImplement;

/*
 * char
 */

/**
 **********************************************************************
 * Typedef: cCharDeviceInterface
 *
 *  Author: $author$
 *    Date: 1/3/2008
 **********************************************************************
 */
typedef cDeviceInterfaceT
<char, TSIZE, TLENGTH, UNDEFINED_LENGTH,
 cCharStreamInterface, cDEVICEAttachedInterface, cOpenedInterface>
cCharDeviceInterface;

/**
 **********************************************************************
 * Typedef: cCharDeviceImplement
 *
 *  Author: $author$
 *    Date: 1/3/2008
 **********************************************************************
 */
typedef cDeviceImplementT
<char, TSIZE, TLENGTH, UNDEFINED_LENGTH,
 cCharDeviceInterface>
cCharDeviceImplement;

/*
 * BYTE
 */

/**
 **********************************************************************
 * Typedef: cBYTEDeviceInterface
 *
 *  Author: $author$
 *    Date: 1/3/2008
 **********************************************************************
 */
typedef cDeviceInterfaceT
<BYTE, TSIZE, TLENGTH, UNDEFINED_LENGTH,
 cBYTEStreamInterface, cDEVICEAttachedInterface, cOpenedInterface>
cBYTEDeviceInterface;

/**
 **********************************************************************
 * Typedef: cBYTEDeviceImplement
 *
 *  Author: $author$
 *    Date: 1/3/2008
 **********************************************************************
 */
typedef cDeviceImplementT
<BYTE, TSIZE, TLENGTH, UNDEFINED_LENGTH,
 cBYTEDeviceInterface>
cBYTEDeviceImplement;

#endif /* _CDEVICEINTERFACE_HXX */
