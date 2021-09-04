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
 *   File: ccharinterface.hxx
 *
 * Author: $author$
 *   Date: 11/3/2008
 **********************************************************************
 */
#ifndef _CCHARINTERFACE_HXX
#define _CCHARINTERFACE_HXX

#include "cinterfacebase.hxx"

#undef CDB_CLASS
#define CDB_CLASS "cCharInterfaceT"
/**
 **********************************************************************
 *  Class: cCharInterfaceT
 *
 * Author: $author$
 *   Date: 11/3/2008
 **********************************************************************
 */
template
<class TImplements=cInterfaceBase>
 
class c_INTERFACE_CLASS cCharInterfaceT
: virtual public TImplements
{
public:
    typedef TImplements cImplements;
    typedef cCharInterfaceT cDerives;
    /**
     **********************************************************************
     * Function: SetCHAR
     *
     *   Author: $author$
     *     Date: 11/3/2008
     **********************************************************************
     */
    virtual TLENGTH SetCHAR
    (CHAR c) = 0;
    /**
     **********************************************************************
     * Function: GetCHAR
     *
     *   Author: $author$
     *     Date: 11/3/2008
     **********************************************************************
     */
    virtual CHAR GetCHAR() const = 0;
    /**
     **********************************************************************
     * Function: SetTCHAR
     *
     *   Author: $author$
     *     Date: 11/3/2008
     **********************************************************************
     */
    virtual TLENGTH SetTCHAR
    (TCHAR c) = 0;
    /**
     **********************************************************************
     * Function: GetTCHAR
     *
     *   Author: $author$
     *     Date: 11/3/2008
     **********************************************************************
     */
    virtual TCHAR GetTCHAR() const = 0;
    /**
     **********************************************************************
     * Function: SetWCHAR
     *
     *   Author: $author$
     *     Date: 11/3/2008
     **********************************************************************
     */
    virtual TLENGTH SetWCHAR
    (WCHAR c) = 0;
    /**
     **********************************************************************
     * Function: GetWCHAR
     *
     *   Author: $author$
     *     Date: 11/3/2008
     **********************************************************************
     */
    virtual WCHAR GetWCHAR() const = 0;
};
#undef CDB_CLASS

/**
 **********************************************************************
 * Typedef: cCharInterface
 *
 *  Author: $author$
 *    Date: 11/3/2008
 **********************************************************************
 */
typedef cCharInterfaceT<>
cCharInterface;

#undef CDB_CLASS
#define CDB_CLASS "cCharImplementT"
/**
 **********************************************************************
 *  Class: cCharImplementT
 *
 * Author: $author$
 *   Date: 11/3/2008
 **********************************************************************
 */
template
<class TImplements=cCharInterface>
 
class cCharImplementT
: virtual public TImplements
{
public:
    typedef TImplements cImplements;
    typedef cCharImplementT cDerives;
    /**
     **********************************************************************
     * Function: SetCHAR
     *
     *   Author: $author$
     *     Date: 11/3/2008
     **********************************************************************
     */
    virtual TLENGTH SetCHAR
    (CHAR c) 
    {
        TLENGTH count = -e_ERROR_NOT_IMPLEMENTED;
        return count;
    }
    /**
     **********************************************************************
     * Function: GetCHAR
     *
     *   Author: $author$
     *     Date: 11/3/2008
     **********************************************************************
     */
    virtual CHAR GetCHAR() const 
    {
        CHAR c = 0;
        return c;
    }
    /**
     **********************************************************************
     * Function: SetTCHAR
     *
     *   Author: $author$
     *     Date: 11/3/2008
     **********************************************************************
     */
    virtual TLENGTH SetTCHAR
    (TCHAR c) 
    {
        TLENGTH count = -e_ERROR_NOT_IMPLEMENTED;
        return count;
    }
    /**
     **********************************************************************
     * Function: GetTCHAR
     *
     *   Author: $author$
     *     Date: 11/3/2008
     **********************************************************************
     */
    virtual TCHAR GetTCHAR() const 
    {
        TCHAR c = 0;
        return c;
    }
    /**
     **********************************************************************
     * Function: SetWCHAR
     *
     *   Author: $author$
     *     Date: 11/3/2008
     **********************************************************************
     */
    virtual TLENGTH SetWCHAR
    (WCHAR c) 
    {
        TLENGTH count = -e_ERROR_NOT_IMPLEMENTED;
        return count;
    }
    /**
     **********************************************************************
     * Function: GetWCHAR
     *
     *   Author: $author$
     *     Date: 11/3/2008
     **********************************************************************
     */
    virtual WCHAR GetWCHAR() const 
    {
        WCHAR c = 0;
        return c;
    }
};
#undef CDB_CLASS

/**
 **********************************************************************
 * Typedef: cCharImplement
 *
 *  Author: $author$
 *    Date: 11/3/2008
 **********************************************************************
 */
typedef cCharImplementT<>
cCharImplement;

#endif /* _CCHARINTERFACE_HXX */
