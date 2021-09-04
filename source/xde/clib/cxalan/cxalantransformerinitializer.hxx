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
 *   File: cxalantransformerinitializer.hxx
 *
 * Author: $author$
 *   Date: 3/8/2008
 **********************************************************************
 */
#ifndef _CXALANTRANSFORMERINITIALIZER_HXX
#define _CXALANTRANSFORMERINITIALIZER_HXX

#include <PlatformSupport/XSLException.hpp>
#include <XalanTransformer/XalanTransformer.hpp>

#include "cxercesinitializer.hxx"
#include "nsxalan.hxx"
#include "cerror.h"

/**
 **********************************************************************
 *  Class: cXalanTransformerInitializer
 *
 * Author: $author$
 *   Date: 3/8/2008
 **********************************************************************
 */
class cXalanTransformerInitializer
{
public:
    typedef cXalanTransformerInitializer cDerives;

    static UINT m_instanceCount;
    static cXalanTransformerInitializer* m_instance;

    cXercesInitializer m_xercesInitializer;

    /**
     **********************************************************************
     * Constructor: cXalanTransformerInitializer
     *
     *      Author: $author$
     *        Date: 3/8/2008
     **********************************************************************
     */
    cXalanTransformerInitializer() 
    {
        eError error = e_ERROR_FAILED;

        if ((++m_instanceCount)<2)
        try
        {
            nsXalan::XalanTransformer::initialize();
        }
        catch(const nsXalan::XSLException&)
        {
            throw(error);
        }

        if (!m_instance)
            m_instance = this;
    }
    /**
     **********************************************************************
     * Destructor: cXalanTransformerInitializer
     *
     *     Author: $author$
     *       Date: 3/8/2008
     **********************************************************************
     */
    virtual ~cXalanTransformerInitializer()
    {
        eError error = e_ERROR_FAILED;

        if (this == m_instance)
            m_instance = 0;

        if (m_instanceCount<1)
            throw(error);

        if ((--m_instanceCount)<1)
            nsXalan::XalanTransformer::terminate();
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
    static cXalanTransformerInitializer* 
    GetInstance(eError& error) 
    {
        cXalanTransformerInitializer* instance = 0;
        if ((instance = new cXalanTransformerInitializer()))
            error = e_ERROR_NONE;
        else error = e_ERROR_NEW;
        return instance;
    }
};
#endif /* _CXALANTRANSFORMERINITIALIZER_HXX */
