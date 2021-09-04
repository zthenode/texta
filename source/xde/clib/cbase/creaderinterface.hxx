/**
 **********************************************************************
 * Copyright (c) 1988-2007 $organization$
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
 *   File: creaderinterface.hxx
 *
 * Author: $author$
 *   Date: 1/10/2007
 *
 *    $Id$
 **********************************************************************
 */

#ifndef _CREADERINTERFACE_HXX
#define _CREADERINTERFACE_HXX

#include "cinterface.hxx"

/**
 **********************************************************************
 *  Class: cReaderInterfaceT
 *
 * Author: $author$
 *   Date: 1/10/2007
 **********************************************************************
 */
template
<class TWhat=CHAR,
 class TSize=TSIZE,
 class TLength=TLENGTH,
 TLength VUndefined=UNDEFINED_LENGTH,
 class TImplements=cInterfaceBase>

class c_INTERFACE_CLASS cReaderInterfaceT
: virtual public TImplements
{
public:
    typedef TWhat tWhat;
    typedef TSize tSize;
    typedef TLength tLength;

    /**
     **********************************************************************
     * Function: Look
     *
     *   Author: $author$
     *     Date: 2/29/2008
     **********************************************************************
     */
    virtual TLength Look
    (TWhat* what, TSize size) = 0;
    /**
     **********************************************************************
     * Function: Read
     *
     *   Author: $author$
     *     Date: 1/10/2007
     **********************************************************************
     */
    virtual TLength Read
    (TWhat* what, TSize size) = 0;
    /**
     **********************************************************************
     * Function: Peek
     *
     *   Author: $author$
     *     Date: 2/29/2008
     **********************************************************************
     */
    virtual TLength Peek(TWhat& what) = 0;
    /**
     **********************************************************************
     * Function: Get
     *
     *   Author: $author$
     *     Date: 1/10/2007
     **********************************************************************
     */
    virtual TLength Get(TWhat& what) = 0;
    /**
     **********************************************************************
     * Function: See
     *
     *   Author: $author$
     *     Date: 3/2/2008
     **********************************************************************
     */
    virtual const TWhat* See
    (TLength& length) const = 0;
};

/**
 **********************************************************************
 * Typedef: cReaderInterface
 *
 *  Author: $author$
 *    Date: 1/4/2008
 **********************************************************************
 */
typedef cReaderInterfaceT
<CHAR, TSIZE, TLENGTH, 
 UNDEFINED_LENGTH, cInterfaceBase>
cReaderInterface;

/**
 **********************************************************************
 *  Class: cReaderImplementT
 *
 * Author: $author$
 *   Date: 1/10/2007
 **********************************************************************
 */
template
<class TWhat=CHAR,
 class TSize=TSIZE,
 class TLength=TLENGTH,
 TLength VUndefined=UNDEFINED_LENGTH,
 class TImplements=cReaderInterface,
 class TExtends=cImplementBase>

class cReaderImplementT
: virtual public TImplements,
  virtual public TExtends
{
public:
    /**
     **********************************************************************
     * Function: Look
     *
     *   Author: $author$
     *     Date: 2/29/2008
     **********************************************************************
     */
    virtual TLength Look
    (TWhat* what, TSize size) 
    {
        TLength length = -e_ERROR_NOT_IMPLEMENTED;
        return length;
    }
    /**
     **********************************************************************
     * Function: Read
     *
     *   Author: $author$
     *     Date: 1/10/2007
     **********************************************************************
     */
    virtual TLength Read
    (TWhat* what, TSize size) 
    {
        TLength length = -e_ERROR_NOT_IMPLEMENTED;
        return length;
    }
    /**
     **********************************************************************
     * Function: Peek
     *
     *   Author: $author$
     *     Date: 2/29/2008
     **********************************************************************
     */
    virtual TLength Peek(TWhat& what) 
    {
        TLength length = Look(&what, 1);
        return length;
    }
    /**
     **********************************************************************
     * Function: Get
     *
     *   Author: $author$
     *     Date: 1/10/2007
     **********************************************************************
     */
    virtual TLength Get(TWhat& what) 
    {
        TLength length = Read(&what, 1);
        return length;
    }
    /**
     **********************************************************************
     * Function: See
     *
     *   Author: $author$
     *     Date: 3/2/2008
     **********************************************************************
     */
    virtual const TWhat* See
    (TLength& length) const 
    {
        const TWhat* what = 0;
        length = 0;
        return what;
    }
};

/**
 **********************************************************************
 * Typedef: cReaderImplement
 *
 *  Author: $author$
 *    Date: 1/4/2008
 **********************************************************************
 */
typedef cReaderImplementT
<CHAR, TSIZE, TLENGTH, 
 UNDEFINED_LENGTH, cReaderInterface>
cReaderImplement;

/*
 * char
 */

/**
 **********************************************************************
 *  Class: cCharReaderInterface
 *
 * Author: $author$
 *   Date: 1/10/2007
 **********************************************************************
 */
class c_INTERFACE_CLASS cCharReaderInterface
: virtual public cReaderInterfaceT
  <char, TSIZE, TLENGTH, UNDEFINED_LENGTH, 
   cInterfaceBase>
{
public:
    typedef cReaderInterfaceT
    <char, TSIZE, TLENGTH, UNDEFINED_LENGTH, 
     cInterfaceBase> cImplements;
};

/**
 **********************************************************************
 *  Class: cCharReaderImplement
 *
 * Author: $author$
 *   Date: 1/13/2007
 **********************************************************************
 */
class cCharReaderImplement
: virtual public cReaderImplementT
  <char, TSIZE, TLENGTH, UNDEFINED_LENGTH, 
   cCharReaderInterface>
{
public:
    typedef cReaderImplementT
    <char, TSIZE, TLENGTH, UNDEFINED_LENGTH, 
     cCharReaderInterface> cImplements;
};

/*
 * BYTE
 */

/**
 **********************************************************************
 *  Class: cBYTEReaderInterface
 *
 * Author: $author$
 *   Date: 11/15/2007
 **********************************************************************
 */
class c_INTERFACE_CLASS cBYTEReaderInterface
: virtual public cReaderInterfaceT
  <BYTE, TSIZE, TLENGTH, UNDEFINED_LENGTH, 
   cInterfaceBase>
{
public:
    typedef cReaderInterfaceT
    <BYTE, TSIZE, TLENGTH, UNDEFINED_LENGTH, 
     cInterfaceBase> cImplements;
};

/**
 **********************************************************************
 *  Class: cBYTEReaderImplement
 *
 * Author: $author$
 *   Date: 11/15/2007
 **********************************************************************
 */
class cBYTEReaderImplement
: virtual public cReaderImplementT
  <BYTE, TSIZE, TLENGTH, UNDEFINED_LENGTH, 
   cBYTEReaderInterface>
{
public:
    typedef cReaderImplementT
    <BYTE, TSIZE, TLENGTH, UNDEFINED_LENGTH, 
     cBYTEReaderInterface> cImplements;
};

/*
 * TCHAR
 */

/**
 **********************************************************************
 *  Class: cTCHARReaderInterface
 *
 * Author: $author$
 *   Date: 1/10/2007
 **********************************************************************
 */
class c_INTERFACE_CLASS cTCHARReaderInterface
: virtual public cReaderInterfaceT
  <TCHAR, TSIZE, TLENGTH, UNDEFINED_LENGTH, 
   cInterfaceBase>
{
public:
    typedef cReaderInterfaceT
    <TCHAR, TSIZE, TLENGTH, UNDEFINED_LENGTH, 
     cInterfaceBase> cImplements;
};

/**
 **********************************************************************
 *  Class: cTCHARReaderImplement
 *
 * Author: $author$
 *   Date: 1/13/2007
 **********************************************************************
 */
class cTCHARReaderImplement
: virtual public cReaderImplementT
  <TCHAR, TSIZE, TLENGTH, UNDEFINED_LENGTH, 
   cTCHARReaderInterface>
{
public:
    typedef cReaderImplementT
    <TCHAR, TSIZE, TLENGTH, UNDEFINED_LENGTH, 
     cTCHARReaderInterface> cImplements;
};

/*
 * WCHAR
 */

/**
 **********************************************************************
 *  Class: cWCHARReaderInterface
 *
 * Author: $author$
 *   Date: 1/10/2007
 **********************************************************************
 */
class c_INTERFACE_CLASS cWCHARReaderInterface
: virtual public cReaderInterfaceT
  <WCHAR, TSIZE, TLENGTH, UNDEFINED_LENGTH, 
   cInterfaceBase>
{
public:
    typedef cReaderInterfaceT
    <WCHAR, TSIZE, TLENGTH, UNDEFINED_LENGTH, 
     cInterfaceBase> cImplements;
};

/**
 **********************************************************************
 *  Class: cWCHARReaderImplement
 *
 * Author: $author$
 *   Date: 1/13/2007
 **********************************************************************
 */
class cWCHARReaderImplement
: virtual public cReaderImplementT
  <WCHAR, TSIZE, TLENGTH, UNDEFINED_LENGTH, 
   cWCHARReaderInterface>
{
public:
    typedef cReaderImplementT
    <WCHAR, TSIZE, TLENGTH, UNDEFINED_LENGTH, 
     cWCHARReaderInterface> cImplements;
};

#endif /* _CREADERINTERFACE_HXX */
