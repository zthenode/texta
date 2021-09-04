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
 *   File: cwinattached.hxx
 *
 * Author: $author$
 *   Date: 5/30/2008
 **********************************************************************
 */
#ifndef _CWINATTACHED_HXX
#define _CWINATTACHED_HXX

#include "cwinhbitmapattached.hxx"
#include "cwin.hxx"
#include "ccreatedattached.hxx"

/*
 **********************************************************************
 * HWND
 **********************************************************************
 */
typedef HANDLE tNullHWND;
#define vNullHWND NULL_HANDLE

/**
 **********************************************************************
 *  Typedef: cHWNDAttachInterface
 *
 *  Author: $author$
 *    Date: 4/28/2008
 **********************************************************************
 */
typedef cAttachInterfaceT
<HWND, cInterfaceBase>
cHWNDAttachInterface;

/**
 **********************************************************************
 *  Typedef: cHWNDDetachInterface
 *
 *  Author: $author$
 *    Date: 4/28/2008
 **********************************************************************
 */
typedef cDetachInterfaceT
<HWND, cInterfaceBase>
cHWNDDetachInterface;

/**
 **********************************************************************
 *  Typedef: cHWNDAttachedInterface
 *
 *  Author: $author$
 *    Date: 4/28/2008
 **********************************************************************
 */
typedef cAttachedInterfaceT
<HWND, cHWNDAttachInterface, cHWNDDetachInterface>
cHWNDAttachedInterface;

/**
 **********************************************************************
 *  Typedef: cHWNDAttached
 *
 *  Author: $author$
 *    Date: 4/28/2008
 **********************************************************************
 */
typedef cAttachedT
<HWND, tNullHWND, vNullHWND, 
 cHWNDAttachedInterface, cBase>
cHWNDAttached;

/**
 **********************************************************************
 *  Typedef: cHWNDCreatedAttached
 *
 *  Author: $author$
 *    Date: 4/29/2008
 **********************************************************************
 */
typedef cCreatedAttachedT
<HWND, tNullHWND, vNullHWND, 
 cHWNDAttached, cCreatedImplement>
cHWNDCreatedAttached;

/*
 **********************************************************************
 * HMENU
 **********************************************************************
 */
typedef HMENU tNullHMENU;
#define vNullHMENU NULL_HANDLE

/**
 **********************************************************************
 *  Typedef: cHMENUAttachInterface
 *
 *  Author: $author$
 *    Date: 10/30/2008
 **********************************************************************
 */
typedef cAttachInterfaceT
<HMENU, cInterfaceBase>
cHMENUAttachInterface;

/**
 **********************************************************************
 *  Typedef: cHMENUDetachInterface
 *
 *  Author: $author$
 *    Date: 10/30/2008
 **********************************************************************
 */
typedef cDetachInterfaceT
<HMENU, cInterfaceBase>
cHMENUDetachInterface;

/**
 **********************************************************************
 *  Typedef: cHMENUAttachedInterface
 *
 *  Author: $author$
 *    Date: 10/30/2008
 **********************************************************************
 */
typedef cAttachedInterfaceT
<HMENU, cHMENUAttachInterface, cHMENUDetachInterface>
cHMENUAttachedInterface;

/**
 **********************************************************************
 *  Typedef: cHMENUAttached
 *
 *  Author: $author$
 *    Date: 10/30/2008
 **********************************************************************
 */
typedef cAttachedT
<HMENU, tNullHMENU, vNullHMENU, 
 cHMENUAttachedInterface, cBase>
cHMENUAttached;

/**
 **********************************************************************
 *  Typedef: cHMENUCreatedAttached
 *
 *  Author: $author$
 *    Date: 10/30/2008
 **********************************************************************
 */
typedef cCreatedAttachedT
<HMENU, tNullHMENU, vNullHMENU, 
 cHMENUAttached, cCreatedImplement>
cHMENUCreatedAttached;

/*
 **********************************************************************
 * HDC
 **********************************************************************
 */
typedef HANDLE tNullHDC;
#define vNullHDC NULL_HANDLE

/**
 **********************************************************************
 *  Typedef: cHDCAttachInterface
 *
 *  Author: $author$
 *    Date: 4/23/2008
 **********************************************************************
 */
typedef cAttachInterfaceT
<HDC, cInterfaceBase>
cHDCAttachInterface;

/**
 **********************************************************************
 *  Typedef: cHDCDetachInterface
 *
 *  Author: $author$
 *    Date: 4/23/2008
 **********************************************************************
 */
typedef cDetachInterfaceT
<HDC, cInterfaceBase>
cHDCDetachInterface;

/**
 **********************************************************************
 *  Typedef: cHDCAttachedInterface
 *
 *  Author: $author$
 *    Date: 4/23/2008
 **********************************************************************
 */
typedef cAttachedInterfaceT
<HDC, cHDCAttachInterface, cHDCDetachInterface>
cHDCAttachedInterface;

/**
 **********************************************************************
 *  Typedef: cHDCAttached
 *
 *  Author: $author$
 *    Date: 4/23/2008
 **********************************************************************
 */
typedef cAttachedT
<HDC, tNullHDC, vNullHDC, 
 cHDCAttachedInterface, cBase>
cHDCAttached;

/**
 **********************************************************************
 *  Typedef: cHDCCreatedAttached
 *
 *  Author: $author$
 *    Date: 4/24/2008
 **********************************************************************
 */
typedef cCreatedAttachedT
<HDC, tNullHDC, vNullHDC,
 cHDCAttached, cCreatedImplement>
cHDCCreatedAttached;

#endif /* _CWINATTACHED_HXX */
