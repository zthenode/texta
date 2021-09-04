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
 *   File: cwinhbitmapattached.hxx
 *
 * Author: $author$
 *   Date: 11/2/2008
 **********************************************************************
 */
#ifndef _CWINHBITMAPATTACHED_HXX
#define _CWINHBITMAPATTACHED_HXX

#include "cwin.hxx"
#include "ccreatedattached.hxx"

/*
 **********************************************************************
 * HBITMAP
 **********************************************************************
 */
typedef HBITMAP tNullHBITMAP;
#define vNullHBITMAP NULL_HANDLE

/**
 **********************************************************************
 *  Typedef: cHBITMAPAttachInterface
 *
 *  Author: $author$
 *    Date: 11/2/2008
 **********************************************************************
 */
typedef cAttachInterfaceT
<HBITMAP, cInterfaceBase>
cHBITMAPAttachInterface;

/**
 **********************************************************************
 *  Typedef: cHBITMAPDetachInterface
 *
 *  Author: $author$
 *    Date: 11/2/2008
 **********************************************************************
 */
typedef cDetachInterfaceT
<HBITMAP, cInterfaceBase>
cHBITMAPDetachInterface;

/**
 **********************************************************************
 *  Typedef: cHBITMAPAttachedInterface
 *
 *  Author: $author$
 *    Date: 11/2/2008
 **********************************************************************
 */
typedef cAttachedInterfaceT
<HBITMAP, cHBITMAPAttachInterface, cHBITMAPDetachInterface>
cHBITMAPAttachedInterface;

/**
 **********************************************************************
 *  Typedef: cHBITMAPAttached
 *
 *  Author: $author$
 *    Date: 11/2/2008
 **********************************************************************
 */
typedef cAttachedT
<HBITMAP, tNullHBITMAP, vNullHBITMAP, 
 cHBITMAPAttachedInterface, cBase>
cHBITMAPAttached;

/**
 **********************************************************************
 *  Typedef: cHBITMAPCreatedAttached
 *
 *  Author: $author$
 *    Date: 11/2/2008
 **********************************************************************
 */
typedef cCreatedAttachedT
<HBITMAP, tNullHBITMAP, vNullHBITMAP, 
 cHBITMAPAttached, cCreatedImplement>
cHBITMAPCreatedAttached;

#endif /* _CWINHBITMAPATTACHED_HXX */
