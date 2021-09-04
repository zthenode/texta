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
 *   File: creference.hxx
 *
 * Author: $author$
 *   Date: 3/26/2007
 *
 **********************************************************************
 */
#ifndef _CREFERENCE_HXX
#define _CREFERENCE_HXX

#include "creferenced.hxx"

/**
 **********************************************************************
 *  Class: cReferenceT
 *
 * Author: $author$
 *   Date: 3/26/2007
 **********************************************************************
 */
template
<class TInstance,
 class TReferenced=cReferenced>

class cReferenceT
{
public:
    typedef cReferenceT cDerives;

    TInstance* m_instance;
    TReferenced* m_referenced;

    /**
     **********************************************************************
     * Constructor: cReferenceT
     *
     *      Author: $author$
     *        Date: 3/26/2007
     **********************************************************************
     */
    cReferenceT(TInstance* instance=0) 
    : m_instance(instance),
      m_referenced(0)
    {
        if (m_instance)
            m_referenced = TReferenced::NewInstance(1);
    }
    /**
     **********************************************************************
     * Constructor: cReferenceT
     *
     *      Author: $author$
     *        Date: 3/26/2007
     **********************************************************************
     */
    cReferenceT(const cReferenceT<TInstance,TReferenced>& reference) 
    : m_instance(0),
      m_referenced(0)
    {
        if (reference.m_referenced != 0)
        {
            m_instance = reference.m_instance;
            m_referenced = reference.m_referenced;
            m_referenced->Increment();
        }
    }
    /**
     **********************************************************************
     * Constructor: cReferenceT
     *
     *      Author: $author$
     *        Date: 3/26/2007
     **********************************************************************
     */
    template<class TDerivedInstance>
    cReferenceT(const cReferenceT<TDerivedInstance>& reference) 
    : m_instance(0),
      m_referenced(0)
    {
        TInstance* instance;

        if ((instance = (TInstance*)(reference.operator->())) != 0)
        {
            m_instance = instance;
            m_referenced = reference.m_referenced;
            m_referenced->Increment();
        }
    }
    /**
     **********************************************************************
     *  Destructor: ~cReferenceT
     *
     *      Author: $author$
     *        Date: 3/26/2007
     **********************************************************************
     */
    ~cReferenceT()
    {
        Clear();
    }

    /**
     **********************************************************************
     * Function: Set
     *
     *   Author: $author$
     *     Date: 3/26/2007
     **********************************************************************
     */
    void Set(TInstance* instance) 
    {
        Clear();

        if ((m_instance = instance))
            m_referenced = TReferenced::NewInstance(1);
    }
    /**
     **********************************************************************
     * Function: Clear
     *
     *   Author: $author$
     *     Date: 3/26/2007
     **********************************************************************
     */
    void Clear() 
    {
        if (m_referenced)
        {
            if (m_instance)
            {
                if (m_referenced->Decrement() == 0)
                {
                    m_referenced->DeleteInstance();

                    m_instance->DeleteInstance();
                }
                m_instance = 0;
            }
            m_referenced = 0;
        }
    }

    /**
     **********************************************************************
     * Function: operator =
     *
     *   Author: $author$
     *     Date: 3/26/2007
     **********************************************************************
     */
    cReferenceT& operator = (const cReferenceT& reference) 
    {
        cReferenceT& thisReference = *this;

        if (&reference != &thisReference)
        {
            Clear();

            if (reference.m_referenced)
            {
                m_instance = reference.m_instance;
                m_referenced = reference.m_referenced;
                m_referenced->Increment();
            }
        }
        return thisReference;
    }

    /**
     **********************************************************************
     * Function: operator ==
     *
     *   Author: $author$
     *     Date: 3/26/2007
     **********************************************************************
     */
	bool operator == (const cReferenceT& to) const
	{
		return (m_instance == to.m_instance);
	}
    /**
     **********************************************************************
     * Function: operator !=
     *
     *   Author: $author$
     *     Date: 3/26/2007
     **********************************************************************
     */
	bool operator != (const cReferenceT& to) const
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
	bool operator == (void* to) const
	{
		return (((void*)(m_instance)) == to);
	}	
    /**
     **********************************************************************
     * Function: operator !=
     *
     *   Author: $author$
     *     Date: 3/26/2007
     **********************************************************************
     */
	bool operator != (void* to) const
	{
		return !operator == (to);
	}

    /**
     **********************************************************************
     * Function: operator ->
     *
     *   Author: $author$
     *     Date: 3/26/2007
     **********************************************************************
     */
    TInstance* operator -> () const
    {
        return m_instance;
    }
    /**
     **********************************************************************
     * Function: operator *
     *
     *   Author: $author$
     *     Date: 3/26/2007
     **********************************************************************
     */
    TInstance& operator * () const
    {
        return *m_instance;
    }
    /**
     **********************************************************************
     * Function: operator bool
     *
     *   Author: $author$
     *     Date: 3/26/2007
     **********************************************************************
     */
    operator bool () const
    {
        return (0 != m_instance);
    }
};

#endif /* _CREFERENCE_HXX */
