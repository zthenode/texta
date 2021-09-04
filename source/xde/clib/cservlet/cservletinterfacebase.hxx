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
 *   File: cservletinterfacebase.hxx
 *
 * Author: $author$
 *   Date: 2/24/2008
 **********************************************************************
 */
#ifndef _CSERVLETINTERFACEBASE_HXX
#define _CSERVLETINTERFACEBASE_HXX

#include "cinterfacebase.hxx"

#undef CDB_CLASS
#define CDB_CLASS "cServletInterfaceBaseT"
/**
 **********************************************************************
 *  Class: cServletInterfaceBaseT
 *
 * Author: $author$
 *   Date: 2/24/2008
 **********************************************************************
 */
template
<class TImplements=cInterfaceBase>
 
class c_INTERFACE_CLASS cServletInterfaceBaseT
: virtual public TImplements
{
public:
    typedef TImplements cImplements;
    typedef cServletInterfaceBaseT cDerives;
};
#undef CDB_CLASS

/**
 **********************************************************************
 *  Class: cServletInterfaceBase
 *
 * Author: $author$
 *   Date: 2/25/2008
 **********************************************************************
 */
class c_INTERFACE_CLASS cServletInterfaceBase
: virtual public cServletInterfaceBaseT<cInterfaceBase>
{
    typedef cServletInterfaceBaseT<cInterfaceBase> cImplements;
};
#endif /* _CSERVLETINTERFACEBASE_HXX */
