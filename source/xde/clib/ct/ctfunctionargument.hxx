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
 *   File: ctfunctionargument.hxx
 *
 * Author: $author$
 *   Date: 4/1/2008
 **********************************************************************
 */
#ifndef _CTFUNCTIONARGUMENT_HXX
#define _CTFUNCTIONARGUMENT_HXX

#include "clist.hxx"
#include "cbuffer.hxx"

/**
 **********************************************************************
 *  Class: cTFunctionArgument
 *
 * Author: $author$
 *   Date: 4/1/2008
 **********************************************************************
 */
class cTFunctionArgument
: public cDynamicListItemT<cTFunctionArgument,cCharBuffer>
{
public:
    typedef cDynamicListItemT<cTFunctionArgument,cCharBuffer> cExtends;
    typedef cTFunctionArgument cDerives;
};

/**
 **********************************************************************
 *  Class: cTFunctionArgumentList
 *
 * Author: $author$
 *   Date: 4/1/2008
 **********************************************************************
 */
class cTFunctionArgumentList
: public cDynamicListT<cTFunctionArgument,cBase>
{
public:
    typedef cDynamicListT<cTFunctionArgument,cBase> cExtends;
    typedef cTFunctionArgumentList cDerives;
};
#endif /* _CTFUNCTIONARGUMENT_HXX */
