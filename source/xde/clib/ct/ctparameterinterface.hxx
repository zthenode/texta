/**
 **********************************************************************
 * Copyright (c) 1988-2009 $organization$
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
 *   File: ctparameterinterface.hxx
 *
 * Author: $author$
 *   Date: 1/12/2009
 **********************************************************************
 */
#ifndef _CTPARAMETERINTERFACE_HXX
#define _CTPARAMETERINTERFACE_HXX

#include "ctinterfacebase.hxx"

/**
 **********************************************************************
 *  Class: cTParameterInterface
 *
 * Author: $author$
 *   Date: 1/12/2009
 **********************************************************************
 */
class c_INTERFACE_CLASS cTParameterInterface
: virtual public cInterfaceBase
{
public:
    typedef cInterfaceBase cExtends;
    typedef cTParameterInterface cDerives;

    /**
     **********************************************************************
     * Function: GetFirstParameter
     *
     *   Author: $author$
     *     Date: 1/12/2009
     **********************************************************************
     */
    virtual const char* GetFirstParameter
    (int& length, const char*& named, int& namedLength) = 0;
    /**
     **********************************************************************
     * Function: GetLastParameter
     *
     *   Author: $author$
     *     Date: 1/12/2009
     **********************************************************************
     */
    virtual const char* GetLastParameter
    (int& length, const char*& named, int& namedLength) = 0;
    /**
     **********************************************************************
     * Function: GetNextParameter
     *
     *   Author: $author$
     *     Date: 1/12/2009
     **********************************************************************
     */
    virtual const char* GetNextParameter
    (int& length, const char*& named, int& namedLength) = 0;
    /**
     **********************************************************************
     * Function: GetPrevParameter
     *
     *   Author: $author$
     *     Date: 1/12/2009
     **********************************************************************
     */
    virtual const char* GetPrevParameter
    (int& length, const char*& named, int& namedLength) = 0;
};

/**
 **********************************************************************
 *  Class: cTParameterImplement
 *
 * Author: $author$
 *   Date: 1/12/2009
 **********************************************************************
 */
class cTParameterImplement
: virtual public cTParameterInterface
{
public:
    typedef cTParameterInterface cImplements;
    typedef cTParameterImplement cDerives;

    /**
     **********************************************************************
     * Function: GetFirstParameter
     *
     *   Author: $author$
     *     Date: 1/12/2009
     **********************************************************************
     */
    virtual const char* GetFirstParameter
    (int& length, const char*& named, int& namedLength) 
    {
        const char* chars = 0;
        length = -e_ERROR_NOT_IMPLEMENTED;
        return chars;
    }
    /**
     **********************************************************************
     * Function: GetLastParameter
     *
     *   Author: $author$
     *     Date: 1/12/2009
     **********************************************************************
     */
    virtual const char* GetLastParameter
    (int& length, const char*& named, int& namedLength) 
    {
        const char* chars = 0;
        length = -e_ERROR_NOT_IMPLEMENTED;
        return chars;
    }
    /**
     **********************************************************************
     * Function: GetNextParameter
     *
     *   Author: $author$
     *     Date: 1/12/2009
     **********************************************************************
     */
    virtual const char* GetNextParameter
    (int& length, const char*& named, int& namedLength) 
    {
        const char* chars = 0;
        length = -e_ERROR_NOT_IMPLEMENTED;
        return chars;
    }
    /**
     **********************************************************************
     * Function: GetPrevParameter
     *
     *   Author: $author$
     *     Date: 1/12/2009
     **********************************************************************
     */
    virtual const char* GetPrevParameter
    (int& length, const char*& named, int& namedLength) 
    {
        const char* chars = 0;
        length = -e_ERROR_NOT_IMPLEMENTED;
        return chars;
    }
};

#endif /* _CTPARAMETERINTERFACE_HXX */
