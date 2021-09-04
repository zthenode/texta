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
 *   File: copened.hxx
 *
 * Author: $author$
 *   Date: 2/3/2008
 **********************************************************************
 */
#ifndef _COPENED_HXX
#define _COPENED_HXX

#include "ccloseinterface.hxx"
#include "cbase.hxx"

#undef CDB_CLASS
#define CDB_CLASS "cOpenedT"
/**
 **********************************************************************
 *  Class: cOpenedT
 *
 * Author: $author$
 *   Date: 2/3/2008
 **********************************************************************
 */
template
<class TExtends=cBase,
 class TImplements=cCloseInterface>
 
class cOpenedT
: virtual public TImplements,
  public TExtends
{
public:
    typedef TImplements cImplements;
    typedef TExtends cExtends;
    typedef cOpenedT cDerives;

    bool m_isOpen;

    /**
     **********************************************************************
     * Constructor: cOpenedT
     *
     *      Author: $author$
     *        Date: 2/3/2008
     **********************************************************************
     */
    cOpenedT(bool isOpen=false) 
    : m_isOpen(isOpen)
    {
    }
    /**
     **********************************************************************
     * Destructor: cOpenedT
     *
     *     Author: $author$
     *       Date: 2/3/2008
     **********************************************************************
     */
    virtual ~cOpenedT()
    {
        eError error;
        if (m_isOpen)
        if ((error = Close()))
            throw(error);
    }
    /**
     **********************************************************************
     * Function: Close
     *
     *   Author: $author$
     *     Date: 2/3/2008
     **********************************************************************
     */
    virtual eError Close
    (bool onlyOpened=false) 
    {
        eError error = e_ERROR_NOT_IMPLEMENTED;
        return error;
    }
    /**
     **********************************************************************
     * Function: Closed
     *
     *   Author: $author$
     *     Date: 2/3/2008
     **********************************************************************
     */
    virtual eError Closed
    (bool onlyClosed=false) 
    {
        eError error = e_ERROR_NONE;
        int isOpen;

        if (0 > (isOpen = GetIsOpen()))
            return error = -isOpen;
        else 
        if (isOpen)
        {
            if (onlyClosed)
                return e_ERROR_ALREADY_OPEN;
            error = Close(0 < isOpen);
        }
        return error;
    }
    /**
     **********************************************************************
     * Function: Opened
     *
     *   Author: $author$
     *     Date: 2/3/2008
     **********************************************************************
     */
    virtual int Opened
    (bool onlyOpened=false) const
    {
        int isOpen;

        if (0 <= (isOpen = GetIsOpen()))
        if (!isOpen)
        if (onlyOpened)
            return -e_ERROR_NOT_OPEN;

        return isOpen;
    }
    /**
     **********************************************************************
     * Function: SetIsOpen
     *
     *   Author: $author$
     *     Date: 2/3/2008
     **********************************************************************
     */
    virtual int SetIsOpen
    (bool is=true) 
    {
        int isOpen = (int)(m_isOpen = is);
        return isOpen;
    }
    /**
     **********************************************************************
     * Function: GetIsOpen
     *
     *   Author: $author$
     *     Date: 2/3/2008
     **********************************************************************
     */
    virtual int GetIsOpen() const 
    {
        int isOpen = (int)m_isOpen;
        return isOpen;
    }
};
#undef CDB_CLASS

/**
 **********************************************************************
 *  Typedef: cOpened
 *
 *  Author: $author$
 *    Date: 2/3/2008
 **********************************************************************
 */
typedef cOpenedT
<cBase, cCloseInterface>
cOpened;

#endif /* _COPENED_HXX */

