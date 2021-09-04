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
 *   File: cwinatom.hxx
 *
 * Author: $author$
 *   Date: 4/30/2008
 **********************************************************************
 */
#ifndef _CWINATOM_HXX
#define _CWINATOM_HXX

#include "cwin.hxx"
#include "ccreatedattached.hxx"
#include "cdebug.hxx"

typedef ATOM tNullATOM;
#define vNullATOM NULL_ATOM

/**
 **********************************************************************
 *  Typedef: cATOMAttachInterface
 *
 *  Author: $author$
 *    Date: 4/30/2008
 **********************************************************************
 */
typedef cAttachInterfaceT
<ATOM, cInterfaceBase>
cATOMAttachInterface;

/**
 **********************************************************************
 *  Typedef: cATOMDetachInterface
 *
 *  Author: $author$
 *    Date: 4/30/2008
 **********************************************************************
 */
typedef cDetachInterfaceT
<ATOM, cInterfaceBase>
cATOMDetachInterface;

/**
 **********************************************************************
 *  Typedef: cATOMAttachedInterface
 *
 *  Author: $author$
 *    Date: 4/30/2008
 **********************************************************************
 */
typedef cAttachedInterfaceT
<ATOM, cATOMAttachInterface, cATOMDetachInterface>
cATOMAttachedInterface;

/**
 **********************************************************************
 *  Typedef: cATOMAttached
 *
 *  Author: $author$
 *    Date: 4/30/2008
 **********************************************************************
 */
typedef cAttachedT
<ATOM, tNullATOM, vNullATOM, 
 cATOMAttachedInterface, cBase>
cATOMAttached;

/**
 **********************************************************************
 *  Typedef: cATOMCreatedAttached
 *
 *  Author: $author$
 *    Date: 4/30/2008
 **********************************************************************
 */
typedef cCreatedAttachedT
<ATOM, tNullATOM, vNullATOM, 
 cATOMAttached, cCreatedImplement>
cATOMCreatedAttached;

/**
 **********************************************************************
 *  Class: cWinAtomInterface
 *
 * Author: $author$
 *   Date: 4/30/2008
 **********************************************************************
 */
class c_INTERFACE_CLASS cWinAtomInterface
: virtual public cATOMAttachedInterface
{
public:
    typedef cATOMAttachedInterface cImplements;
    typedef cWinAtomInterface cDerives;
};

/**
 **********************************************************************
 *  Class: cWinAtom
 *
 * Author: $author$
 *   Date: 4/30/2008
 **********************************************************************
 */
class cWinAtom
: virtual public cWinAtomInterface,
  public cATOMCreatedAttached
{
public:
    typedef cWinAtomInterface cImplements;
    typedef cATOMCreatedAttached cExtends;
    typedef cWinAtom cDerives;
    /**
     **********************************************************************
     * Constructor: cWinAtom
     *
     *      Author: $author$
     *        Date: 4/30/2008
     **********************************************************************
     */
    cWinAtom
    (ATOM attached=NULL_ATOM,
     bool isCreated=false) 
    : cExtends(attached, isCreated)
    {
    }
    /**
     **********************************************************************
     * Destructor: cWinAtom
     *
     *     Author: $author$
     *       Date: 4/30/2008
     **********************************************************************
     */
    virtual ~cWinAtom()
    {
        Destruct();
    }
    /**
     **********************************************************************
     * Function: Create
     *
     *   Author: $author$
     *     Date: 4/30/2008
     **********************************************************************
     */
    virtual eError Create
    (LPCTSTR name, bool onlyDestroyed=false) 
    {
        eError error = e_ERROR_FAILED;
        ATOM attached;

        if ((error = Destroyed(onlyDestroyed)))
            return error;

        if (NULL_ATOM == (attached = AddAtom(name)))
            DBE("() failed on AddAtom()\n");
        else
        if ((error = Attach(attached, true)))
            DestroyAttached(attached);
        return error;
    }
    /**
     **********************************************************************
     * Function: DestroyAttached
     *
     *   Author: $author$
     *     Date: 4/30/2008
     **********************************************************************
     */
    virtual eError DestroyAttached(ATOM attached) 
    {
        eError error = e_ERROR_FAILED;
        ATOM err;

        if ((err = DeleteAtom(attached)))
            DBE("() failed on DeleteAtom()\n");
        else
        error = e_ERROR_NONE;
        return error;
    }
};
#endif /* _CWINATOM_HXX */
