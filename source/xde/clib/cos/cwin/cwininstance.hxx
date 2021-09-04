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
 *   File: cwininstance.hxx
 *
 * Author: $author$
 *   Date: 4/28/2008
 **********************************************************************
 */
#ifndef _CWININSTANCE_HXX
#define _CWININSTANCE_HXX

#include "cattached.hxx"
#include "cwin.hxx"

typedef HANDLE tNullHINSTANCE;
#define vNullHINSTANCE NULL_HANDLE

/**
 **********************************************************************
 *  Typedef: cHINSTANCEAttachInterface
 *
 *  Author: $author$
 *    Date: 4/28/2008
 **********************************************************************
 */
typedef cAttachInterfaceT
<HINSTANCE, cInterfaceBase>
cHINSTANCEAttachInterface;

/**
 **********************************************************************
 *  Typedef: cHINSTANCEDetachInterface
 *
 *  Author: $author$
 *    Date: 4/28/2008
 **********************************************************************
 */
typedef cDetachInterfaceT
<HINSTANCE, cInterfaceBase>
cHINSTANCEDetachInterface;

/**
 **********************************************************************
 *  Typedef: cHINSTANCEAttachedInterface
 *
 *  Author: $author$
 *    Date: 4/28/2008
 **********************************************************************
 */
typedef cAttachedInterfaceT
<HINSTANCE, cHINSTANCEAttachInterface, cHINSTANCEDetachInterface>
cHINSTANCEAttachedInterface;

/**
 **********************************************************************
 *  Typedef: cHINSTANCEAttached
 *
 *  Author: $author$
 *    Date: 4/28/2008
 **********************************************************************
 */
typedef cAttachedT
<HINSTANCE, tNullHINSTANCE, vNullHINSTANCE, 
 cHINSTANCEAttachedInterface, cBase>
cHINSTANCEAttached;

/**
 **********************************************************************
 *  Class: cWinInstance
 *
 * Author: $author$
 *   Date: 4/28/2008
 **********************************************************************
 */
class cWinInstance
: public cHINSTANCEAttached
{
public:
    typedef cHINSTANCEAttached cExtends;
    typedef cWinInstance cDerives;
    /**
     **********************************************************************
     * Constructor: cWinInstance
     *
     *      Author: $author$
     *        Date: 4/28/2008
     **********************************************************************
     */
    cWinInstance
    (HINSTANCE attached=NULL_HANDLE) 
    : cExtends(attached)
    {
    }
    /**
     **********************************************************************
     * Destructor: cWinInstance
     *
     *     Author: $author$
     *       Date: 4/28/2008
     **********************************************************************
     */
    virtual ~cWinInstance()
    {
    }
};
#endif /* _CWININSTANCE_HXX */
