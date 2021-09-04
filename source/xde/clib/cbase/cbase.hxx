/**
 **********************************************************************
 * Copyright (c) 1988-2007 $organization$
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
 *   File: cbase.hxx
 *
 * Author: $author$
 *   Date: 1/26/2007
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CBASE_HXX
#define _CBASE_HXX

#include "cplatform.h"
#include "cerror.h"

/**
 **********************************************************************
 *  Class: cBase
 *
 * Author: $author$
 *   Date: 1/26/2007
 **********************************************************************
 */
class cBase
{
public:
    /**
     **********************************************************************
     * Destructor: cBase
     *
     *     Author: $author$
     *       Date: 11/13/2007
     **********************************************************************
     */
    virtual ~cBase()
    {
    }
#if defined(__GNUC__) 
/* Gcc
 */
#else /* defined(__GNUC__) */
/* Otherwise
 */
#endif /* defined(__GNUC__) */
};

#endif /* _CBASE_HXX */
