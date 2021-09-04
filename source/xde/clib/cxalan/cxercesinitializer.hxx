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
 *   File: cxercesinitializer.hxx
 *
 * Author: $author$
 *   Date: 3/8/2008
 **********************************************************************
 */
#ifndef _CXERCESINITIALIZER_HXX
#define _CXERCESINITIALIZER_HXX

#include <util/PlatformUtils.hpp>

#include "nsxerces.hxx"
#include "cerror.h"

/**
 **********************************************************************
 *  Class: cXercesInitializer
 *
 * Author: $author$
 *   Date: 3/8/2008
 **********************************************************************
 */
class cXercesInitializer
{
public:
    typedef cXercesInitializer cDerives;

    static UINT m_instanceCount;
    static cXercesInitializer *m_instance;

    /**
     **********************************************************************
     * Constructor: cXercesInitializer
     *
     *      Author: $author$
     *        Date: 3/8/2008
     **********************************************************************
     */
    cXercesInitializer() 
    {
        eError error = e_ERROR_FAILED;

        if ((++m_instanceCount)<2)
        try
        {
            nsXerces::XMLPlatformUtils::Initialize();
        }
        catch(const nsXerces::XMLException&)
        {
            throw(error);
        }

        if (!m_instance)
            m_instance = this;
    }
    /**
     **********************************************************************
     * Destructor: cXercesInitializer
     *
     *     Author: $author$
     *       Date: 3/8/2008
     **********************************************************************
     */
    virtual ~cXercesInitializer()
    {
        eError error = e_ERROR_FAILED;

        if (this == m_instance)
            m_instance = 0;

        if (m_instanceCount<1)
            throw(error);

        if ((--m_instanceCount)<1)
        try
        {
            nsXerces::XMLPlatformUtils::Terminate();
        }
        catch(const nsXerces::XMLException&)
        {
            throw(error);
        }
    }
    /**
     **********************************************************************
     * Function: FreeInstance
     *
     *   Author: $author$
     *     Date: 3/8/2008
     **********************************************************************
     */
    virtual eError FreeInstance() 
    {
        eError error = e_ERROR_NONE;
		delete this;
        return error;
    }
    /**
     **********************************************************************
     * Function: GetInstance
     *
     *   Author: $author$
     *     Date: 3/8/2008
     **********************************************************************
     */
    static cXercesInitializer* 
    GetInstance(eError& error) 
    {
        cXercesInitializer* instance;
        if ((instance = new cXercesInitializer()))
            error = e_ERROR_NONE;
        else error = e_ERROR_NEW;
        return instance;
    }
};
#endif /* _CXERCESINITIALIZER_HXX */
