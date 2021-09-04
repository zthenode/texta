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
 *   File: cwingdiobject.hxx
 *
 * Author: $author$
 *   Date: 4/24/2008
 **********************************************************************
 */
#ifndef _CWINGDIOBJECT_HXX
#define _CWINGDIOBJECT_HXX

#include "chgdiobjattached.hxx"
#include "cdebug.hxx"

/**
 **********************************************************************
 *  Class: cWinGDIObjectInterface
 *
 * Author: $author$
 *   Date: 4/27/2008
 **********************************************************************
 */
class c_INTERFACE_CLASS cWinGDIObjectInterface
: virtual public cHGDIOBJAttachedInterface
{
public:
    typedef cHGDIOBJAttachedInterface cImplements;
    typedef cWinGDIObjectInterface cDerives;
};

/**
 **********************************************************************
 *  Class: cWinGDIObject
 *
 * Author: $author$
 *   Date: 4/27/2008
 **********************************************************************
 */
class cWinGDIObject
: virtual public cWinGDIObjectInterface,
  public cHGDIOBJCreatedAttached
{
public:
    typedef cWinGDIObjectInterface cImplements;
    typedef cHGDIOBJCreatedAttached cExtends;
    typedef cWinGDIObject cDerives;

    /**
     **********************************************************************
     * Constructor: cWinGDIObject
     *
     *      Author: $author$
     *        Date: 4/27/2008
     **********************************************************************
     */
    cWinGDIObject
    (HGDIOBJ attached=NULL_HANDLE,
     bool isCreated=false) 
    : cExtends(attached, isCreated)
    {
    }
    /**
     **********************************************************************
     * Destructor: ~cWinGDIObject
     *
     *     Author: $author$
     *       Date: 4/27/2008
     **********************************************************************
     */
    virtual ~cWinGDIObject()
    {
        Destruct();
    }

    /**
     **********************************************************************
     * Function: GetStock
     *
     *   Author: $author$
     *     Date: 4/27/2008
     **********************************************************************
     */
    virtual eError GetStock
    (int id,
     bool onlyDestroyed=false) 
    {
        eError error = e_ERROR_FAILED;
        HGDIOBJ attached;

        if ((error = Destroyed(onlyDestroyed)))
            return error;

        if (NULL_HANDLE != (attached = GetStockObject(id)))
            error = Attach(attached, true);
        else
        DBE("() failed on GetStockObject()\n");
        return error;
    }
    /**
     **********************************************************************
     * Function: DestroyAttached
     *
     *   Author: $author$
     *     Date: 4/27/2008
     **********************************************************************
     */
    virtual eError DestroyAttached
    (HGDIOBJ attached) const
    {
        eError error = e_ERROR_FAILED;

        if (DeleteObject(attached))
            error = e_ERROR_NONE;
        else
        DBE("() failed on DeleteObject()\n");
        return error;
    }
};

#endif /* _CWINGDIOBJECT_HXX */
