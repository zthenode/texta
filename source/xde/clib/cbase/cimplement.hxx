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
 *   File: cimplement.hxx
 *
 * Author: $author$
 *   Date: 1/10/2007
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CIMPLEMENT_HXX
#define _CIMPLEMENT_HXX

#include "cinterface.hxx"

/**
 **********************************************************************
 *  Class: cImplement
 *
 * Author: $author$
 *   Date: 1/10/2007
 **********************************************************************
 */
class cImplement
: virtual public cInterface
{
public:
    /**
     **********************************************************************
     * Function: HoldInstance
     *
     *   Author: $author$
     *     Date: 1/10/2007
     **********************************************************************
     */
    virtual eError HoldInstance()
    {
        return e_ERROR_NOT_ALLOWED;
    }
    /**
     **********************************************************************
     * Function: FreeInstance
     *
     *   Author: $author$
     *     Date: 1/10/2007
     **********************************************************************
     */
    virtual eError FreeInstance()
    {
        return e_ERROR_NOT_ALLOWED;
    }
    /**
     **********************************************************************
     * Function: DeleteInstance
     *
     *   Author: $author$
     *     Date: 1/10/2007
     **********************************************************************
     */
    virtual eError DeleteInstance()
    {
        return e_ERROR_NOT_ALLOWED;
    }

    /**
     **********************************************************************
     * Function: SetLastError
     *
     *   Author: $author$
     *     Date: 1/10/2007
     **********************************************************************
     */
    virtual eError SetLastError
    (eError error,const char *description=0, int length=-1)
    {
        return -e_ERROR_NOT_ALLOWED;
    }
    /**
     **********************************************************************
     * Function: GetLastError
     *
     *   Author: $author$
     *     Date: 1/10/2007
     **********************************************************************
     */
    virtual eError GetLastError
    (const char *&description, int &length) const
    {
        return -e_ERROR_NOT_ALLOWED;
    }
};

/**
 **********************************************************************
 *  Class: cStaticImplement
 *
 * Author: $author$
 *   Date: 1/10/2007
 **********************************************************************
 */
class cStaticImplement
: virtual public cInterface,
  virtual public cImplement
{
public:
    typedef cImplement cIs;

    int m_hold_instance;

    /**
     **********************************************************************
     * Constructor: cStaticImplement
     *
     *      Author: $author$
     *        Date: 1/10/2007
     **********************************************************************
     */
    cStaticImplement() 
    : m_hold_instance(0)
    {
    }
    /**
     **********************************************************************
     * Function: 
     *
     *   Author: $author$
     *     Date: 1/10/2007
     **********************************************************************
     */
};

/**
 **********************************************************************
 *  Class: cDynamicImplement
 *
 * Author: $author$
 *   Date: 1/10/2007
 **********************************************************************
 */
class cDynamicImplement
: virtual public cInterface,
  virtual public cStaticImplement
{
public:
    typedef cStaticImplement cIs;

    /**
     **********************************************************************
     * Constructor: cDynamicImplement
     *
     *      Author: $author$
     *        Date: 1/10/2007
     **********************************************************************
     */
    cDynamicImplement() 
    {
    }
    /**
     **********************************************************************
     * Function: HoldInstance
     *
     *   Author: $author$
     *     Date: 1/10/2007
     **********************************************************************
     */
    virtual eError HoldInstance()
    {
        m_hold_instance++;
        return e_ERROR_NONE;
    }
    /**
     **********************************************************************
     * Function: FreeInstance
     *
     *   Author: $author$
     *     Date: 1/10/2007
     **********************************************************************
     */
    virtual eError FreeInstance()
    {
        if (m_hold_instance>0)
        {
            --m_hold_instance;
            return e_ERROR_NONE;
        }
        return DeleteInstance();
    }
    /**
     **********************************************************************
     * Function: DeleteInstance
     *
     *   Author: $author$
     *     Date: 1/10/2007
     **********************************************************************
     */
    virtual eError DeleteInstance()=0;
};

#endif /* _CIMPLEMENT_HXX */
