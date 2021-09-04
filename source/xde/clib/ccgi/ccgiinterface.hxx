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
 *   File: ccgiinterface.hxx
 *
 * Author: $author$
 *   Date: 3/3/2008
 **********************************************************************
 */
#ifndef _CCGIINTERFACE_HXX
#define _CCGIINTERFACE_HXX

#include "cmaininterface.hxx"

#undef CDB_CLASS
#define CDB_CLASS "cCGIInterfaceT"
/**
 **********************************************************************
 *  Class: cCGIInterfaceT
 *
 * Author: $author$
 *   Date: 3/3/2008
 **********************************************************************
 */
template
<class TChar=CHAR,
 class TImplements=cMainInterface>
 
class c_INTERFACE_CLASS cCGIInterfaceT
: virtual public TImplements
{
public:
    typedef TImplements cImplements;
    typedef cCGIInterfaceT cDerives;
};
#undef CDB_CLASS

/**
 **********************************************************************
 *  Class: cCGIInterface
 *
 * Author: $author$
 *   Date: 3/3/2008
 **********************************************************************
 */
class c_INTERFACE_CLASS cCGIInterface
: virtual public cCGIInterfaceT<char,cMainInterface>
{
public:
    typedef cCGIInterfaceT<char,cMainInterface> cImplements;
};
#endif /* _CCGIINTERFACE_HXX */
