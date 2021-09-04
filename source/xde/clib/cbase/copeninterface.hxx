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
 *   File: copeninterface.hxx
 *
 * Author: $author$
 *   Date: 1/3/2008
 **********************************************************************
 */
#ifndef _COPENINTERFACE_HXX
#define _COPENINTERFACE_HXX

#include "cinterfacebase.hxx"

/**
 **********************************************************************
 *  Class: cOpenInterfaceT
 *
 * Author: $author$
 *   Date: 1/3/2008
 **********************************************************************
 */
template
<class TChar=CHAR,
 class TMode=MODE,
 class TImplements=cInterfaceBase>
 
class c_INTERFACE_CLASS cOpenInterfaceT
: virtual public TImplements
{
public:
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
     const TMode mode,
     bool onlyClosed=true) = 0;
};

/**
 **********************************************************************
 * Typedef: cOpenInterface
 *
 *  Author: $author$
 *    Date: 1/3/2008
 **********************************************************************
 */
typedef cOpenInterfaceT
<CHAR,MODE,cInterfaceBase>
cOpenInterface;

/**
 **********************************************************************
 *  Class: cOpenImplementT
 *
 * Author: $author$
 *   Date: 1/3/2008
 **********************************************************************
 */
template
<class TChar=CHAR,
 class TMode=MODE,
 class TImplements=cOpenInterface>
 
class cOpenImplementT
: virtual public TImplements
{
public:
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
     const TMode mode,
     bool onlyClosed=true) 
    {
        eError error = e_ERROR_NOT_IMPLEMENTED;
        return error;
    }
};

/**
 **********************************************************************
 * Typedef: cOpenImplement
 *
 *  Author: $author$
 *    Date: 1/3/2008
 **********************************************************************
 */
typedef cOpenImplementT
<CHAR, MODE, cOpenInterface>
cOpenImplement;

#endif /* _COPENINTERFACE_HXX */
