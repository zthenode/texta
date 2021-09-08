/**
 **********************************************************************
 * Copyright (c) $year$ $author$
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
 *   Date: $date$
 **********************************************************************
 */
#ifndef __CBASE_HXX
#define __CBASE_HXX

#include "platform.hxx"
#include "error.hxx"

/**
 **********************************************************************
 *  Class: CBase
 *
 * Author: $author$
 *   Date: $date$
 **********************************************************************
 */
class CBase
{
public:
#if defined(__GNUC__) 
/* Gcc
 */
    /**
     **********************************************************************
     * Destructor: CBase
     *
     * Author: $author$
     *   Date: $date$
     **********************************************************************
     */
    virtual ~CBase()
    {
    }
#else /* defined(__GNUC__) */
/* Otherwise
 */
#endif /* defined(__GNUC__) */
};

#endif /* __CBASE_HXX */
