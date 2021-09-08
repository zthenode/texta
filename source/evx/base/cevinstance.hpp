///////////////////////////////////////////////////////////////////////
//   File: cevinstance.hpp
//
// Author: $author$
//   Date: 5/26/2007
///////////////////////////////////////////////////////////////////////

#ifndef _CEVINSTANCE_HPP
#define _CEVINSTANCE_HPP

#include "evinstance.hpp"
#include "cevbase.hpp"

#undef CDB_CLASS
#define CDB_CLASS "CEvInstanceT"
template
<class TExtends=CEvBase,
 class TImplements=EvInstance>
 
///////////////////////////////////////////////////////////////////////
//  Class: CEvInstanceT
//
// Author: $author$
//   Date: 5/26/2007
///////////////////////////////////////////////////////////////////////
class EV_EXPORT_CLASS CEvInstanceT
: virtual public TImplements,
  public TExtends
{
public:
    typedef TImplements CImplements;
    typedef TExtends CExtends;
    typedef CEvInstanceT CDerives;

    bool m_isStaticInstance;

    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvInstanceT
    //
    //       Author: $author$
    //         Date: 5/26/2007
    ///////////////////////////////////////////////////////////////////////
    CEvInstanceT(bool isStaticInstance=false) 
    : m_isStaticInstance(isStaticInstance)
    {
    }
    ///////////////////////////////////////////////////////////////////////
    // Destructor: ~CEvInstanceT
    //
    //      Author: $author$
    //        Date: 10/3/2007
    ///////////////////////////////////////////////////////////////////////
    virtual ~CEvInstanceT()
    {
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: Construct
    //
    //   Author: $author$
    //     Date: 5/26/2007
    ///////////////////////////////////////////////////////////////////////
    virtual void Construct(bool isStaticInstance=false) 
    {
        m_isStaticInstance = isStaticInstance;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: DeleteInstance
    //
    //   Author: $author$
    //     Date: 5/26/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError DeleteInstance() 
    {
        if (m_isStaticInstance)
            return EV_ERROR_NONE;
        return DeleteThis();
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: DeleteThis
    //
    //   Author: $author$
    //     Date: 5/26/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError DeleteThis()
    {
        if (m_isStaticInstance)
            return EV_ERROR_NOT_INSTANTIATED;
        delete this;
        return EV_ERROR_NONE;
        //return EV_ERROR_NOT_ALLOWED;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: SetIsStaticInstance
    //
    //   Author: $author$
    //     Date: 3/12/2008
    ///////////////////////////////////////////////////////////////////////
    virtual int SetIsStaticInstance(bool is=true) 
    {
        int isStaticInstance = (false != (m_isStaticInstance = is));
        return isStaticInstance;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: GetIsStaticInstance
    //
    //   Author: $author$
    //     Date: 3/12/2008
    ///////////////////////////////////////////////////////////////////////
    virtual bool GetIsStaticInstance() const 
    {
        return m_isStaticInstance;
    }
};
#undef CDB_CLASS

///////////////////////////////////////////////////////////////////////
//  Typedef: CEvInstance
//
//  Author: $author$
//    Date: 5/17/2008
///////////////////////////////////////////////////////////////////////
typedef CEvInstanceT
<CEvBase, EvInstance>
CEvInstance;

#endif // _CEVINSTANCE_HPP
