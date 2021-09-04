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
 *   File: cccharstring.hxx
 *
 * Author: $author$
 *   Date: 11/3/2008
 **********************************************************************
 */
#ifndef _CCCHARSTRING_HXX
#define _CCCHARSTRING_HXX

#include "cchar.hxx"
#include "cstring.hxx"
#include "cstringbase.hxx"

/**
 **********************************************************************
 * Typedef: ccCharReaderInterface
 *
 *  Author: $author$
 *    Date: 11/3/2008
 **********************************************************************
 */
typedef cReaderInterfaceT
<cChar, TSIZE, TLENGTH, UNDEFINED_LENGTH,
 cInterfaceBase>
ccCharReaderInterface;
/**
 **********************************************************************
 * Typedef: ccCharWriterInterface
 *
 *  Author: $author$
 *    Date: 11/3/2008
 **********************************************************************
 */
typedef cWriterInterfaceT
<cChar, TSIZE, TLENGTH, UNDEFINED_LENGTH,
 cInterfaceBase>
ccCharWriterInterface;
/**
 **********************************************************************
 * Typedef: ccCharReaderImplement
 *
 *  Author: $author$
 *    Date: 11/3/2008
 **********************************************************************
 */
typedef cReaderImplementT
<cChar, TSIZE, TLENGTH, UNDEFINED_LENGTH,
 ccCharReaderInterface>
ccCharReaderImplement;
/**
 **********************************************************************
 * Typedef: ccCharWriterImplement
 *
 *  Author: $author$
 *    Date: 11/3/2008
 **********************************************************************
 */
typedef cWriterImplementT
<cChar, TSIZE, TLENGTH, UNDEFINED_LENGTH,
 ccCharWriterInterface>
ccCharWriterImplement;
/**
 **********************************************************************
 * Typedef: ccCharStreamInterface
 *
 *  Author: $author$
 *    Date: 11/3/2008
 **********************************************************************
 */
typedef cStreamInterfaceT
<cChar, TSIZE, TLENGTH, UNDEFINED_LENGTH,
 ccCharReaderInterface, ccCharWriterInterface>
ccCharStreamInterface;
/**
 **********************************************************************
 * Typedef: ccCharStreamImplement
 *
 *  Author: $author$
 *    Date: 11/3/2008
 **********************************************************************
 */
typedef cStreamImplementT
<cChar, TSIZE, TLENGTH, UNDEFINED_LENGTH,
 ccCharReaderInterface, ccCharWriterInterface, 
 ccCharStreamInterface, ccCharReaderImplement, ccCharWriterImplement>
ccCharStreamImplement;
/**
 **********************************************************************
 * Typedef: ccCharStringInterface
 *
 *  Author: $author$
 *    Date: 11/3/2008
 **********************************************************************
 */
typedef cStringInterfaceT
<cChar, TSIZE, TLENGTH, UNDEFINED_LENGTH, CHAR, NULL_CHAR,
 ccCharStreamInterface>
ccCharStringInterface;
/**
 **********************************************************************
 * Typedef: ccCharStringImplement
 *
 *  Author: $author$
 *    Date: 11/3/2008
 **********************************************************************
 */
typedef cStringImplementT
<cChar, TSIZE, TLENGTH, UNDEFINED_LENGTH, CHAR, NULL_CHAR,
 ccCharStreamInterface, ccCharStringInterface, ccCharStreamImplement>
ccCharStringImplement;
/**
 **********************************************************************
 * Typedef: ccCharStringExtends
 *
 *  Author: $author$
 *    Date: 11/3/2008
 **********************************************************************
 */
typedef cStringBaseT
<cChar, TSIZE, TLENGTH, 
 CHAR, NULL_CHAR, UNDEFINED_LENGTH>
ccCharStringExtends;
/**
 **********************************************************************
 * Typedef: ccCharString
 *
 *  Author: $author$
 *    Date: 11/3/2008
 **********************************************************************
 */
typedef cStringT
<cChar, TSIZE, TLENGTH, UNDEFINED_LENGTH, CHAR, NULL_CHAR,
 ccCharStreamInterface, ccCharStringImplement, ccCharStringExtends>
ccCharString;

#endif /* _CCCHARSTRING_HXX */
