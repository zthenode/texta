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
 *   File: ctfunctionlist.hxx
 *
 * Author: $author$
 *   Date: 4/1/2008
 **********************************************************************
 */
#ifndef _CTFUNCTIONLIST_HXX
#define _CTFUNCTIONLIST_HXX

#include "clist.hxx"
#include "cinterfacebase.hxx"

class c_INTERFACE_CLASS cTFunctionInterface;

/**
 **********************************************************************
 *  Class: cTFunctionItem
 *
 * Author: $author$
 *   Date: 4/1/2008
 **********************************************************************
 */
class cTFunctionItem
: public cListItemT<cTFunctionItem,cBase>
{
public:
    typedef cListItemT<cTFunctionItem,cBase> cExtends;
    typedef cTFunctionItem cDerives;

    cTFunctionInterface &m_function;

    /**
     **********************************************************************
     * Constructor: cTFunctionItem
     *
     *      Author: $author$
     *        Date: 7/7/2003
     **********************************************************************
     */
    cTFunctionItem(cTFunctionInterface &function)
    : m_function(function) 
    {
    }
    /**
     **********************************************************************
     * Function: GetFunction
     *
     *   Author: $author$
     *     Date: 7/7/2003
     **********************************************************************
     */
    inline cTFunctionInterface& GetFunction() const
    {
        return (cTFunctionInterface&)(m_function);
    }
};

/**
 **********************************************************************
 *  Class: cTFunctionList
 *
 * Author: $author$
 *   Date: 4/1/2008
 **********************************************************************
 */
class cTFunctionList
: public cStaticListT<cTFunctionItem,cBase>
{
public:
    typedef cStaticListT<cTFunctionItem,cBase> cExtends;
    typedef cTFunctionList cDerives;
};
#endif /* _CTFUNCTIONLIST_HXX */
