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
 *   File: creferenced.hxx
 *
 * Author: $author$
 *   Date: 3/26/2007
 *
 **********************************************************************
 */
#ifndef _CREFERENCED_HXX
#define _CREFERENCED_HXX

#include "cplatform.h"
#include "cerror.hxx"

/**
 **********************************************************************
 *  Class: cReferenced
 *
 * Author: $author$
 *   Date: 3/26/2007
 **********************************************************************
 */
class cReferenced
{
public:
    typedef cReferenced cDerives;

    UINT m_referenced;

    /**
     **********************************************************************
     * Constructor: cReferenced
     *
     *      Author: $author$
     *        Date: 3/26/2007
     **********************************************************************
     */
    cReferenced(UINT referenced=0) 
    : m_referenced(referenced)
    {
    }
    /**
     **********************************************************************
     * Function: Increment
     *
     *   Author: $author$
     *     Date: 3/26/2007
     **********************************************************************
     */
    cReferenced Increment() 
    {
        return cReferenced(++m_referenced);
    }
    /**
     **********************************************************************
     * Function: Decrement
     *
     *   Author: $author$
     *     Date: 3/26/2007
     **********************************************************************
     */
    cReferenced Decrement() 
    {
        return cReferenced(--m_referenced);
    }
    /**
     **********************************************************************
     * Function: DeleteInstance
     *
     *   Author: $author$
     *     Date: 3/26/2007
     **********************************************************************
     */
    eError DeleteInstance()
    {
        eError error = e_ERROR_NONE;
        delete this;
        return error;
    }
    /**
     **********************************************************************
     * Function: NewInstance
     *
     *   Author: $author$
     *     Date: 3/26/2007
     **********************************************************************
     */
    static cReferenced* NewInstance(UINT referenced=0)
    {
        cReferenced* instance = new cReferenced(referenced);
        return instance;
    }
    /**
     **********************************************************************
     * Function: operator !=
     *
     *   Author: $author$
     *     Date: 3/26/2007
     **********************************************************************
     */
	bool operator != (UINT to) const
	{
		return !operator == (to);
	}
    /**
     **********************************************************************
     * Function: operator ==
     *
     *   Author: $author$
     *     Date: 3/26/2007
     **********************************************************************
     */
	bool operator == (UINT to) const
	{
		return (m_referenced == to);
	}	
};

#endif /* _CREFERENCED_HXX */
