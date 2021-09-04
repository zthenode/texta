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
 *   File: cbufferinterface.hxx
 *
 * Author: $author$
 *   Date: 2/15/2007
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CBUFFERINTERFACE_HXX
#define _CBUFFERINTERFACE_HXX

#include "cstreaminterface.hxx"

/**
 **********************************************************************
 *  Class: cBufferInterfaceT
 *
 * Author: $author$
 *   Date: 2/15/2007
 **********************************************************************
 */
template
<class TWhat=CHAR,
 class TSize=TSIZE,
 class TLength=TLENGTH,
 TLength VUndefined=UNDEFINED_LENGTH,
 class TImplements=cStreamInterface>

class c_INTERFACE_CLASS cBufferInterfaceT
: virtual public TImplements
{
public:
    typedef TImplements cImplements;
    /**
     **********************************************************************
     * Function: GetBuffer
     *
     *   Author: $author$
     *     Date: 12/28/2008
     **********************************************************************
     */
    virtual const TWhat* GetBuffer
    (TLength& length) const = 0;
};

/**
 **********************************************************************
 * Typedef: cBufferInterface
 *
 *  Author: $author$
 *    Date: 1/4/2008
 **********************************************************************
 */
typedef cBufferInterfaceT
<CHAR, TSIZE, TLENGTH, UNDEFINED_LENGTH,
 cStreamInterface>
cBufferInterface;

#undef CDB_CLASS
#define CDB_CLASS "cBufferImplementT"
/**
 **********************************************************************
 *  Class: cBufferImplementT
 *
 * Author: $author$
 *   Date: 12/28/2008
 **********************************************************************
 */
template
<class TWhat=CHAR,
 class TSize=TSIZE,
 class TLength=TLENGTH,
 TLength VUndefined=UNDEFINED_LENGTH,
 class TBufferInterface=cBufferInterface,
 class TImplements=TBufferInterface>
 
class cBufferImplementT
: virtual public TImplements
{
public:
    typedef TImplements cImplements;
    typedef cBufferImplementT cDerives;
    /**
     **********************************************************************
     * Function: GetBuffer
     *
     *   Author: $author$
     *     Date: 12/28/2008
     **********************************************************************
     */
    virtual const TWhat* GetBuffer
    (TLength& length) const 
    {
        const TWhat* buffer = 0;
        length = -e_ERROR_NOT_IMPLEMENTED;
        return buffer;
    }
};
#undef CDB_CLASS

/*
 * char
 */

/**
 **********************************************************************
 *  Class: cCharBufferInterface
 *
 * Author: $author$
 *   Date: 2/15/2007
 **********************************************************************
 */
class c_INTERFACE_CLASS cCharBufferInterface
: virtual public cBufferInterfaceT
  <char, TSIZE, TLENGTH, UNDEFINED_LENGTH, 
   cCharStreamInterface>
{
public:
    typedef cBufferInterfaceT
    <char, TSIZE, TLENGTH, UNDEFINED_LENGTH, 
	 cCharStreamInterface> cImplements;
};

/*
 * BYTE
 */

/**
 **********************************************************************
 *  Class: cBYTEBufferInterface
 *
 * Author: $author$
 *   Date: 2/15/2007
 **********************************************************************
 */
class c_INTERFACE_CLASS cBYTEBufferInterface
: virtual public cBufferInterfaceT
  <BYTE, TSIZE, TLENGTH, UNDEFINED_LENGTH, 
   cBYTEStreamInterface>
{
public:
    typedef cBufferInterfaceT
    <BYTE, TSIZE, TLENGTH, UNDEFINED_LENGTH, 
	 cBYTEStreamInterface> cImplements;
};

/*
 * TCHAR
 */

/**
 **********************************************************************
 *  Class: cTCHARBufferInterface
 *
 * Author: $author$
 *   Date: 2/15/2007
 **********************************************************************
 */
class c_INTERFACE_CLASS cTCHARBufferInterface
: virtual public cBufferInterfaceT
  <TCHAR, TSIZE, TLENGTH, UNDEFINED_LENGTH, 
   cTCHARStreamInterface>
{
public:
    typedef cBufferInterfaceT
    <TCHAR, TSIZE, TLENGTH, UNDEFINED_LENGTH, 
	 cTCHARStreamInterface> cImplements;
};

#endif /* _CBUFFERINTERFACE_HXX */
