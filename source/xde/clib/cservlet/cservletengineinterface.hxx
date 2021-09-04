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
 *   File: cservletengineinterface.hxx
 *
 * Author: $author$
 *   Date: 2/24/2008
 **********************************************************************
 */
#ifndef _CSERVLETENGINEINTERFACE_HXX
#define _CSERVLETENGINEINTERFACE_HXX

#include "cservletinterfacebase.hxx"

#undef CDB_CLASS
#define CDB_CLASS "cServletEngineInterfaceT"
/**
 **********************************************************************
 *  Class: cServletEngineInterfaceT
 *
 * Author: $author$
 *   Date: 2/24/2008
 **********************************************************************
 */
template
<class TImplements=cServletInterfaceBase>
 
class c_INTERFACE_CLASS cServletEngineInterfaceT
: virtual public TImplements
{
public:
    typedef TImplements cImplements;
    typedef cServletEngineInterfaceT cDerives;
};
#undef CDB_CLASS

#endif /* _CSERVLETENGINEINTERFACE_HXX */
