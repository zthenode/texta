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
 *   File: csingleinstance.hxx
 *
 * Author: $author$
 *   Date: 1/15/2008
 **********************************************************************
 */
#ifndef _CSINGLEINSTANCE_HXX
#define _CSINGLEINSTANCE_HXX

#include "cerror.h"
#include "cbase.hxx"

/**
 **********************************************************************
 *  Class: cSingleInstanceT
 *
 * Author: $author$
 *   Date: 1/15/2008
 **********************************************************************
 */
template
<class TDerives,
 class TExtends=cBase>
 
class cSingleInstanceT
: public TExtends
{
public:
    typedef TExtends cExtends;
    typedef TDerives cDerives;

    static TDerives* m_instance;
    TDerives* m_oldInstance;

    /**
     **********************************************************************
     * Constructor: cSingleInstanceT
     *
     *      Author: $author$
     *        Date: 1/15/2008
     **********************************************************************
     */
    cSingleInstanceT(TDerives* instance) 
    : m_oldInstance(m_instance)
    {
        eError error;

        if (m_instance)
            throw (error = e_ERROR_ALREADY_INSTANTIATED);

        if (this != instance)
            throw (error = e_ERROR_INSTANTIATE);

        m_instance = instance;
    }
    /**
     **********************************************************************
     * Destructor: cSingleInstanceT
     *
     *     Author: $author$
     *       Date: 1/15/2008
     **********************************************************************
     */
    virtual ~cSingleInstanceT()
    {
        eError error;

        if (this != m_instance)
            throw (error = e_ERROR_NOT_INSTANTIATED);

        m_instance = m_oldInstance;
    }

    /**
     **********************************************************************
     * Function: GetInstance
     *
     *   Author: $author$
     *     Date: 1/15/2008
     **********************************************************************
     */
    static inline TDerives* GetInstance()
    {
        return m_instance;
    }
};
#endif /* _CSINGLEINSTANCE_HXX */
