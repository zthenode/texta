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
 *   File: cthreaddeligate.hxx
 *
 * Author: $author$
 *   Date: 2/15/2008
 **********************************************************************
 */
#ifndef _CTHREADDELIGATE_HXX
#define _CTHREADDELIGATE_HXX

#include "cthreadinterface.hxx"
#include "cbase.hxx"

#undef CDB_CLASS
#define CDB_CLASS "cThreadDeligateT"
/**
 **********************************************************************
 *  Class: cThreadDeligateT
 *
 * Author: $author$
 *   Date: 2/15/2008
 **********************************************************************
 */
template
<class TExtends=cBase,
 class TImplements=cThreadInterface>
 
class cThreadDeligateT
: virtual public TImplements,
  public TExtends
{
public:
    typedef TImplements cImplements;
    typedef TExtends cExtends;
    typedef cThreadDeligateT cDerives;
    /**
     **********************************************************************
     * Function: DeleteInstance
     *
     *   Author: $author$
     *     Date: 2/14/2008
     **********************************************************************
     */
    virtual eError DeleteInstance()
    {
        eError error = e_ERROR_NOT_IMPLEMENTED;
        return error;
    }
    /**
     **********************************************************************
     * Function: SetDeligate
     *
     *   Author: $author$
     *     Date: 2/14/2008
     **********************************************************************
     */
    virtual eError SetDeligate
    (TImplements* deligate)
    {
        eError error = e_ERROR_NOT_IMPLEMENTED;
        return error;
    }
    /**
     **********************************************************************
     * Function: GetDeligate
     *
     *   Author: $author$
     *     Date: 2/14/2008
     **********************************************************************
     */
    virtual TImplements* GetDeligate() const
    {
        TImplements* deligate = 0;
        return deligate;
    }
};
#undef CDB_CLASS

/**
 **********************************************************************
 *  Typedef: cThreadDeligate
 *
 *  Author: $author$
 *    Date: 2/15/2008
 **********************************************************************
 */
typedef cThreadDeligateT
<cBase, cThreadInterface>
cThreadDeligate;

#endif /* _CTHREADDELIGATE_HXX */
