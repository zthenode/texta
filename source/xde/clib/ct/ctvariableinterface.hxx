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
 *   File: ctvariableinterface.hxx
 *
 * Author: $author$
 *   Date: 3/31/2008
 **********************************************************************
 */
#ifndef _CTVARIABLEINTERFACE_HXX
#define _CTVARIABLEINTERFACE_HXX

#include "ctinterfacebase.hxx"

/**
 **********************************************************************
 *  Class: cTVariableInterface
 *
 * Author: $author$
 *   Date: 3/31/2008
 **********************************************************************
 */
class c_INTERFACE_CLASS cTVariableInterface
: virtual public cInterfaceBase
{
public:
    typedef cInterfaceBase cImplements;
    typedef cTVariableInterface cDerives;
    /**
     **********************************************************************
     * Function: SetValue
     *
     *   Author: $author$
     *     Date: 7/8/2003
     **********************************************************************
     */
    virtual eError SetValue
    (const char *value, int valuelen=-1)=0;
    /**
     **********************************************************************
     * Function: GetValue
     *
     *   Author: $author$
     *     Date: 7/8/2003
     **********************************************************************
     */
    virtual const char *GetValue() const=0;
    /**
     **********************************************************************
     * Function: PushValue
     *
     *   Author: $author$
     *     Date: 7/8/2003
     **********************************************************************
     */
    virtual eError PushValue
    (const char *value, int valuelen=-1)=0;
    /**
     **********************************************************************
     * Function: PopValue
     *
     *   Author: $author$
     *     Date: 7/8/2003
     **********************************************************************
     */
    virtual eError PopValue()=0;
};
#endif /* _CTVARIABLEINTERFACE_HXX */
