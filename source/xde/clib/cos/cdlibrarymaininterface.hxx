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
 *   File: cdlibrarymaininterface.hxx
 *
 * Author: $author$
 *   Date: 5/24/2008
 **********************************************************************
 */
#ifndef _CDLIBRARYMAININTERFACE_HXX
#define _CDLIBRARYMAININTERFACE_HXX

#include "cplatform_dlibrary.h"
#include "cinterfacebase.hxx"

/**
 **********************************************************************
 *  Class: cDLibraryMainInterface
 *
 * Author: $author$
 *   Date: 5/24/2008
 **********************************************************************
 */
class c_INTERFACE_CLASS cDLibraryMainInterface
: virtual public cInterfaceBase
{
public:
    typedef cInterfaceBase cImplements;
    typedef cDLibraryMainInterface cDerives;

    /**
     **********************************************************************
     * Function: GetTheInstance
     *
     *   Author: $author$
     *     Date: 5/24/2008
     **********************************************************************
     */
    static cDLibraryMainInterface* 
    GetTheInstance(eError& error);

    /**
     **********************************************************************
     * Function: Initialize
     *
     *   Author: $author$
     *     Date: 5/24/2008
     **********************************************************************
     */
    virtual eError Initialize() = 0;
    /**
     **********************************************************************
     * Function: Finalize
     *
     *   Author: $author$
     *     Date: 5/24/2008
     **********************************************************************
     */
    virtual eError Finalize() = 0;
};

/**
 **********************************************************************
 *  Class: cDLibraryMainImplement
 *
 * Author: $author$
 *   Date: 5/24/2008
 **********************************************************************
 */
class cDLibraryMainImplement
: virtual public cDLibraryMainInterface
{
public:
    typedef cDLibraryMainInterface cImplements;
    typedef cDLibraryMainImplement cDerives;
    /**
     **********************************************************************
     * Function: Initialize
     *
     *   Author: $author$
     *     Date: 5/24/2008
     **********************************************************************
     */
    virtual eError Initialize() 
    {
        eError error = e_ERROR_NONE;
        return error;
    }
    /**
     **********************************************************************
     * Function: Finalize
     *
     *   Author: $author$
     *     Date: 5/24/2008
     **********************************************************************
     */
    virtual eError Finalize() 
    {
        eError error = e_ERROR_NONE;
        return error;
    }
};

#endif /* _CDLIBRARYMAININTERFACE_HXX */
