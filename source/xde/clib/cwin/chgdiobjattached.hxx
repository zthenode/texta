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
 *   File: chgdiobjattached.hxx
 *
 * Author: $author$
 *   Date: 11/3/2008
 **********************************************************************
 */
#ifndef _CHGDIOBJATTACHED_HXX
#define _CHGDIOBJATTACHED_HXX

#include "cwin.hxx"
#include "ccreatedattached.hxx"

typedef HGDIOBJ tNullHGDIOBJ;
#define vNullHGDIOBJ NULL_HGDIOBJ

/**
 **********************************************************************
 *  Typedef: cHGDIOBJAttachInterface
 *
 *  Author: $author$
 *    Date: 4/24/2008
 **********************************************************************
 */
typedef cAttachInterfaceT
<HGDIOBJ, cInterfaceBase>
cHGDIOBJAttachInterface;

/**
 **********************************************************************
 *  Typedef: cHGDIOBJDetachInterface
 *
 *  Author: $author$
 *    Date: 4/24/2008
 **********************************************************************
 */
typedef cDetachInterfaceT
<HGDIOBJ, cInterfaceBase>
cHGDIOBJDetachInterface;

/**
 **********************************************************************
 *  Typedef: cHGDIOBJAttachedInterface
 *
 *  Author: $author$
 *    Date: 4/24/2008
 **********************************************************************
 */
typedef cAttachedInterfaceT
<HGDIOBJ, cHGDIOBJAttachInterface, cHGDIOBJDetachInterface>
cHGDIOBJAttachedInterface;

/**
 **********************************************************************
 *  Typedef: cHGDIOBJAttached
 *
 *  Author: $author$
 *    Date: 4/24/2008
 **********************************************************************
 */
typedef cAttachedT
<HGDIOBJ, tNullHGDIOBJ, vNullHGDIOBJ, 
 cHGDIOBJAttachedInterface, cBase>
cHGDIOBJAttached;

/**
 **********************************************************************
 *  Typedef: cHGDIOBJCreatedAttached
 *
 *  Author: $author$
 *    Date: 4/25/2008
 **********************************************************************
 */
typedef cCreatedAttachedT
<HGDIOBJ,tNullHGDIOBJ,vNullHGDIOBJ,
 cHGDIOBJAttached, cCreatedImplement>
cHGDIOBJCreatedAttached;

#endif /* _CHGDIOBJATTACHED_HXX */
