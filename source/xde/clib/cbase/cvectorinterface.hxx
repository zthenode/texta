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
 *   File: cvectorinterface.hxx
 *
 * Author: $author$
 *   Date: 3/13/2008
 **********************************************************************
 */
#ifndef _CVECTORINTERFACE_HXX
#define _CVECTORINTERFACE_HXX

#include "cinterfacebase.hxx"

#undef CDB_CLASS
#define CDB_CLASS "cVectorInterfaceT"
/**
 **********************************************************************
 *  Class: cVectorInterfaceT
 *
 * Author: $author$
 *   Date: 3/13/2008
 **********************************************************************
 */
template
<class TWhat=CHAR, 
 class TSize=TSIZE,
 class TLength=TLENGTH,
 TLength VUndefinedLength=UNDEFINED_LENGTH,
 class TImplements=cInterfaceBase>
 
class c_INTERFACE_CLASS cVectorInterfaceT
{
public:
    typedef cVectorInterfaceT cDerives;
};
#undef CDB_CLASS

/**
 **********************************************************************
 *  Typedef: cVectorInterface
 *
 *  Author: $author$
 *    Date: 3/13/2008
 **********************************************************************
 */
typedef cVectorInterfaceT
<CHAR,TSIZE,TLENGTH,UNDEFINED_LENGTH,cInterfaceBase>
cVectorInterface;

#endif /* _CVECTORINTERFACE_HXX */
