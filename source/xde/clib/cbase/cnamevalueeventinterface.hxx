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
 *   File: cnamevalueeventinterface.hxx
 *
 * Author: $author$
 *   Date: 3/18/2008
 **********************************************************************
 */
#ifndef _CNAMEVALUEEVENTINTERFACE_HXX
#define _CNAMEVALUEEVENTINTERFACE_HXX

#include "cinterfacebase.hxx"

#undef CDB_CLASS
#define CDB_CLASS "cNameValueEventInterfaceT"
/**
 **********************************************************************
 *  Class: cNameValueEventInterfaceT
 *
 * Author: $author$
 *   Date: 3/18/2008
 **********************************************************************
 */
template
<class TChar=CHAR,
 class TImplements=cInterfaceBase>
 
class c_INTERFACE_CLASS cNameValueEventInterfaceT
: virtual public TImplements
{
public:
    typedef TImplements cImplements;
    typedef cNameValueEventInterfaceT cDerives;
    /**
     **********************************************************************
     * Function: OnNameValue
     *
     *   Author: $author$
     *     Date: 3/18/2008
     **********************************************************************
     */
    virtual eError OnNameValue
    (const TChar* name,
     const TChar* value) = 0;
};
#undef CDB_CLASS

/**
 **********************************************************************
 *  Typedef: cNameValueEventInterface
 *
 *  Author: $author$
 *    Date: 3/18/2008
 **********************************************************************
 */
typedef cNameValueEventInterfaceT
<CHAR,cInterfaceBase>
cNameValueEventInterface;

/**
 **********************************************************************
 *  Typedef: cCharNameValueEventInterface
 *
 *  Author: $author$
 *    Date: 3/18/2008
 **********************************************************************
 */
typedef cNameValueEventInterfaceT
<char,cInterfaceBase>
cCharNameValueEventInterface;

#endif /* _CNAMEVALUEEVENTINTERFACE_HXX */
