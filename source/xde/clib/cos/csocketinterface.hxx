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
 *   File: csocketinterface.hxx
 *
 * Author: $author$
 *   Date: 2/19/2008
 **********************************************************************
 */
#ifndef _CSOCKETINTERFACE_HXX
#define _CSOCKETINTERFACE_HXX

#include "csocketstreaminterface.hxx"

#undef CDB_CLASS
#define CDB_CLASS "cSocketInterfaceT"
/**
 **********************************************************************
 *  Class: cSocketInterfaceT
 *
 * Author: $author$
 *   Date: 2/19/2008
 **********************************************************************
 */
template
<class TWhat=CHAR,
 class TSize=TSIZE,
 class TLength=TLENGTH,
 TLength VUndefinedLength=UNDEFINED_LENGTH,
 class TImplements=cSocketStreamInterface>
 
class c_INTERFACE_CLASS cSocketInterfaceT
: virtual public TImplements
{
public:
    typedef TImplements cImplements;
    typedef cSocketInterfaceT cDerives;
};
#undef CDB_CLASS

/**
 **********************************************************************
 *  Typedef: cSocketInterface
 *
 *  Author: $author$
 *    Date: 2/19/2008
 **********************************************************************
 */
typedef cSocketInterfaceT
<CHAR, TSIZE, TLENGTH, UNDEFINED_LENGTH,
 cSocketStreamInterface>
cSocketInterface;

/**
 **********************************************************************
 *  Typedef: cCharSocketInterface
 *
 *  Author: $author$
 *    Date: 2/19/2008
 **********************************************************************
 */
typedef cSocketInterfaceT
<char, TSIZE, TLENGTH, UNDEFINED_LENGTH,
 cCharSocketStreamInterface>
cCharSocketInterface;

/**
 **********************************************************************
 *  Typedef: cBYTESocketInterface
 *
 *  Author: $author$
 *    Date: 2/19/2008
 **********************************************************************
 */
typedef cSocketInterfaceT
<BYTE, TSIZE, TLENGTH, UNDEFINED_LENGTH,
 cBYTESocketStreamInterface>
cBYTESocketInterface;

/**
 **********************************************************************
 *  Typedef: cTCHARSocketInterface
 *
 *  Author: $author$
 *    Date: 2/19/2008
 **********************************************************************
 */
typedef cSocketInterfaceT
<TCHAR, TSIZE, TLENGTH, UNDEFINED_LENGTH,
 cTCHARSocketStreamInterface>
cTCHARSocketInterface;

/**
 **********************************************************************
 *  Typedef: cWCHARSocketInterface
 *
 *  Author: $author$
 *    Date: 2/19/2008
 **********************************************************************
 */
typedef cSocketInterfaceT
<WCHAR, TSIZE, TLENGTH, UNDEFINED_LENGTH,
 cWCHARSocketStreamInterface>
cWCHARSocketInterface;

#endif /* _CSOCKETINTERFACE_HXX */
