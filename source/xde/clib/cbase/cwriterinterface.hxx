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
 *   File: cwriterinterface.hxx
 *
 * Author: $author$
 *   Date: 1/13/2007
 *
 *    $Id$
 **********************************************************************
 */

#ifndef _CWRITERINTERFACE_HXX
#define _CWRITERINTERFACE_HXX

#include <stdarg.h>
#include "cinterface.hxx"

/**
 **********************************************************************
 *  Class: cWriterInterfaceT
 *
 * Author: $author$
 *   Date: 1/13/2007
 **********************************************************************
 */
template
<class TWhat=CHAR,
 class TSize=TSIZE,
 class TLength=TLENGTH,
 TLength VUndefined=UNDEFINED_LENGTH,
 class TImplements=cInterfaceBase>

class c_INTERFACE_CLASS cWriterInterfaceT
: virtual public TImplements
{
public:
    /**
     **********************************************************************
     * Function: Write
     *
     *   Author: $author$
     *     Date: 1/13/2007
     **********************************************************************
     */
    virtual TLength Write
    (const TWhat* what, TLength length = VUndefined) = 0;
    /**
     **********************************************************************
     * Function: WriteL
     *
     *   Author: $author$
     *     Date: 3/7/2008
     **********************************************************************
     */
    virtual TLength WriteL
    (const TWhat* what, ...) = 0;
    /**
     **********************************************************************
     * Function: WriteV
     *
     *   Author: $author$
     *     Date: 3/16/2007
     **********************************************************************
     */
    virtual TLength WriteV
    (TWhat*const* vwhat, TLength vlength = VUndefined) = 0;
    /**
     **********************************************************************
     * Function: VWrite
     *
     *   Author: $author$
     *     Date: 3/16/2007
     **********************************************************************
     */
    virtual TLength VWrite
    (va_list va, TLength vlength = VUndefined) = 0;
    /**
     **********************************************************************
     * Function: Put
     *
     *   Author: $author$
     *     Date: 1/13/2007
     **********************************************************************
     */
    virtual TLength Put(TWhat what) = 0;
    /**
     **********************************************************************
     * Function: WriteFormattedV
     *
     *   Author: $author$
     *     Date: 12/12/2017
     **********************************************************************
     *
    virtual TLength WriteFormattedV
    (const TWhat* formatted, va_list va) = 0;*/
    /**
     **********************************************************************
     * Function: Flush
     *
     *   Author: $author$
     *     Date: 12/12/2017
     **********************************************************************
     *
    virtual TLength Flush() = 0;*/
};

/**
 **********************************************************************
 * Typedef: cWriterInterface
 *
 *  Author: $author$
 *    Date: 1/4/2008
 **********************************************************************
 */
typedef cWriterInterfaceT
<CHAR, TSIZE, TLENGTH, 
 UNDEFINED_LENGTH, cInterfaceBase>
cWriterInterface;

/**
 **********************************************************************
 *  Class: cWriterImplementT
 *
 * Author: $author$
 *   Date: 1/13/2007
 **********************************************************************
 */
template
<class TWhat=CHAR,
 class TSize=TSIZE,
 class TLength=TLENGTH,
 TLength VUndefined=UNDEFINED_LENGTH,
 class TImplements=cWriterInterface,
 class TExtends=cImplementBase>

class cWriterImplementT
: virtual public TImplements,
  virtual public TExtends
{
public:
    /**
     **********************************************************************
     * Function: Write
     *
     *   Author: $author$
     *     Date: 1/13/2007
     **********************************************************************
     */
    virtual TLength Write
    (const TWhat* what, TLength length = VUndefined) 
    {
        TLength count = -e_ERROR_NOT_IMPLEMENTED;
        return count;
    }
    /**
     **********************************************************************
     * Function: WriteL
     *
     *   Author: $author$
     *     Date: 3/7/2008
     **********************************************************************
     */
    virtual TLength WriteL
    (const TWhat* what, ...) 
    {
        TLength length = 0;
        TLength count;
        va_list va;

        va_start(va, what);

        if (0 <= (length = Write(what)))
        if (0 > (count = VWrite(va)))
            length = count;
        else length += count;
        va_end(va);
        return length;
    }
    /**
     **********************************************************************
     * Function: WriteV
     *
     *   Author: $author$
     *     Date: 3/16/2007
     **********************************************************************
     */
    virtual TLength WriteV
    (TWhat*const* vwhat, TLength vlength = VUndefined) 
    {
        TLength length = 0;
        TLength count;

        if (0 > vlength)
        {
            for (;0 != *vwhat; vwhat++, length += count)
            {
                if (0 >= (count = Write(*vwhat)))
                    break;
            }
        }
        else 
        {
            for (;0 < vlength; --vlength, vwhat++, length += count)
            {
                if (0 >= (count = Write(*vwhat)))
                    break;
            }
        }
        return length;
    }
    /**
     **********************************************************************
     * Function: VWrite
     *
     *   Author: $author$
     *     Date: 3/16/2007
     **********************************************************************
     */
    virtual TLength VWrite
    (va_list va, TLength vlength = VUndefined) 
    {
        TLength length = 0;
        TLength count;
        const TWhat* what;

        if (0 > vlength)
        {
            while (0 != (what = va_arg(va, const TWhat*)))
            {
                if (0 > (count = Write(what)))
                {
                    length = count;
                    break;
                }
                length += count;
            }
        }
        else 
        {
            while (0 < vlength--)
            {
                if (0 != (what = va_arg(va, const TWhat*)))
                if (0 > (count = Write(what)))
                    length = count;
                else
                {
                    length += count;
                    continue;
                }
                break;
            }
        }
        return length;
    }
    /**
     **********************************************************************
     * Function: Put
     *
     *   Author: $author$
     *     Date: 1/13/2007
     **********************************************************************
     */
    virtual TLength Put(TWhat what) 
    {
        TLength length = Write(&what, 1);
        return length;
    }
    /**
     **********************************************************************
     * Function: WriteFormattedV
     *
     *   Author: $author$
     *     Date: 12/12/2017
     **********************************************************************
     *
    virtual TLength WriteFormattedV
    (const TWhat* formatted, va_list va) 
    {
        TLength length = 0;
        return length;
    }*/
    /**
     **********************************************************************
     * Function: Flush
     *
     *   Author: $author$
     *     Date: 12/12/2017
     **********************************************************************
     *
    virtual TLength Flush() 
    {
        TLength length = 0;
        return length;
    }*/
};

/**
 **********************************************************************
 * Typedef: cWriterImplement
 *
 *  Author: $author$
 *    Date: 1/4/2008
 **********************************************************************
 */
typedef cWriterImplementT
<CHAR, TSIZE, TLENGTH, 
 UNDEFINED_LENGTH, cWriterInterface>
cWriterImplement;

/*
 * char
 */

/**
 **********************************************************************
 *  Class: cCharWriterInterface
 *
 * Author: $author$
 *   Date: 1/13/2007
 **********************************************************************
 */
class c_INTERFACE_CLASS cCharWriterInterface
: virtual public cWriterInterfaceT
  <char, TSIZE, TLENGTH, UNDEFINED_LENGTH, 
   cInterfaceBase>
{
public:
    typedef cWriterInterfaceT
    <char, TSIZE, TLENGTH, UNDEFINED_LENGTH, 
     cInterfaceBase> cImplements;
};

/**
 **********************************************************************
 *  Class: cCharWriterImplement
 *
 * Author: $author$
 *   Date: 1/13/2007
 **********************************************************************
 */
class cCharWriterImplement
: virtual public cWriterImplementT
  <char, TSIZE, TLENGTH, UNDEFINED_LENGTH, 
   cCharWriterInterface>
{
public:
    typedef cWriterImplementT
    <char, TSIZE, TLENGTH, UNDEFINED_LENGTH, 
     cCharWriterInterface> cImplements;
};

/*
 * BYTE
 */

/**
 **********************************************************************
 *  Class: cBYTEWriterInterface
 *
 * Author: $author$
 *   Date: 11/15/2007
 **********************************************************************
 */
class c_INTERFACE_CLASS cBYTEWriterInterface
: virtual public cWriterInterfaceT
  <BYTE, TSIZE, TLENGTH, UNDEFINED_LENGTH, 
   cInterfaceBase>
{
public:
    typedef cWriterInterfaceT
    <BYTE, TSIZE, TLENGTH, UNDEFINED_LENGTH, 
     cInterfaceBase> cImplements;
};

/**
 **********************************************************************
 *  Class: cBYTEWriterImplement
 *
 * Author: $author$
 *   Date: 11/15/2007
 **********************************************************************
 */
class cBYTEWriterImplement
: virtual public cWriterImplementT
  <BYTE, TSIZE, TLENGTH, UNDEFINED_LENGTH, 
   cBYTEWriterInterface>
{
public:
    typedef cWriterImplementT
    <BYTE, TSIZE, TLENGTH, UNDEFINED_LENGTH, 
     cBYTEWriterInterface> cImplements;
};

/*
 * TCHAR
 */

/**
 **********************************************************************
 *  Class: cTCHARWriterInterface
 *
 * Author: $author$
 *   Date: 1/13/2007
 **********************************************************************
 */
class c_INTERFACE_CLASS cTCHARWriterInterface
: virtual public cWriterInterfaceT
  <TCHAR, TSIZE, TLENGTH, UNDEFINED_LENGTH, 
   cInterfaceBase>
{
public:
    typedef cWriterInterfaceT
    <TCHAR, TSIZE, TLENGTH, UNDEFINED_LENGTH, 
     cInterfaceBase> cImplements;
};

/**
 **********************************************************************
 *  Class: cTCHARWriterImplement
 *
 * Author: $author$
 *   Date: 1/13/2007
 **********************************************************************
 */
class cTCHARWriterImplement
: virtual public cWriterImplementT
  <TCHAR, TSIZE, TLENGTH, UNDEFINED_LENGTH, 
   cTCHARWriterInterface>
{
public:
    typedef cWriterImplementT
    <TCHAR, TSIZE, TLENGTH, UNDEFINED_LENGTH, 
     cTCHARWriterInterface> cImplements;
};

/*
 * WCHAR
 */

/**
 **********************************************************************
 *  Class: cWCHARWriterInterface
 *
 * Author: $author$
 *   Date: 1/13/2007
 **********************************************************************
 */
class c_INTERFACE_CLASS cWCHARWriterInterface
: virtual public cWriterInterfaceT
  <WCHAR, TSIZE, TLENGTH, UNDEFINED_LENGTH, 
   cInterfaceBase>
{
public:
    typedef cWriterInterfaceT
    <WCHAR, TSIZE, TLENGTH, UNDEFINED_LENGTH, 
     cInterfaceBase> cImplements;
};

/**
 **********************************************************************
 *  Class: cWCHARWriterImplement
 *
 * Author: $author$
 *   Date: 1/13/2007
 **********************************************************************
 */
class cWCHARWriterImplement
: virtual public cWriterImplementT
  <WCHAR, TSIZE, TLENGTH, UNDEFINED_LENGTH, 
   cWCHARWriterInterface>
{
public:
    typedef cWriterImplementT
    <WCHAR, TSIZE, TLENGTH, UNDEFINED_LENGTH, 
     cWCHARWriterInterface> cImplements;
};

#endif /* _CWRITERINTERFACE_HXX */
