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
 *   File: cxmlchstring.hxx
 *
 * Author: $author$
 *   Date: 12/24/2008
 **********************************************************************
 */
#ifndef _CXMLCHSTRING_HXX
#define _CXMLCHSTRING_HXX

#include <sax/InputSource.hpp>
#include "cstring.hxx"

#define NULL_XMLCh 0

/**
 **********************************************************************
 *  Class: cXMLChReaderInterface
 *
 * Author: $author$
 *   Date: 3/14/2008
 **********************************************************************
 */
class c_INTERFACE_CLASS cXMLChReaderInterface
: virtual public cReaderInterfaceT
  <XMLCh, TSIZE, TLENGTH, UNDEFINED_LENGTH, 
   cInterfaceBase>
{
public:
    typedef cReaderInterfaceT
    <XMLCh, TSIZE, TLENGTH, UNDEFINED_LENGTH, 
     cInterfaceBase> cImplements;
};
/**
 **********************************************************************
 *  Class: cXMLChReaderImplement
 *
 * Author: $author$
 *   Date: 3/14/2008
 **********************************************************************
 */
class cXMLChReaderImplement
: virtual public cReaderImplementT
  <XMLCh, TSIZE, TLENGTH, UNDEFINED_LENGTH, 
   cXMLChReaderInterface>
{
public:
    typedef cReaderImplementT
    <XMLCh, TSIZE, TLENGTH, UNDEFINED_LENGTH, 
     cXMLChReaderInterface> cImplements;
};

/**
 **********************************************************************
 *  Class: cXMLChWriterInterface
 *
 * Author: $author$
 *   Date: 3/14/2008
 **********************************************************************
 */
class c_INTERFACE_CLASS cXMLChWriterInterface
: virtual public cWriterInterfaceT
  <XMLCh, TSIZE, TLENGTH, UNDEFINED_LENGTH, 
   cInterfaceBase>
{
public:
    typedef cWriterInterfaceT
    <XMLCh, TSIZE, TLENGTH, UNDEFINED_LENGTH, 
     cInterfaceBase> cImplements;
};
/**
 **********************************************************************
 *  Class: cXMLChWriterImplement
 *
 * Author: $author$
 *   Date: 3/14/2008
 **********************************************************************
 */
class cXMLChWriterImplement
: virtual public cWriterImplementT
  <XMLCh, TSIZE, TLENGTH, UNDEFINED_LENGTH, 
   cXMLChWriterInterface>
{
public:
    typedef cWriterImplementT
    <XMLCh, TSIZE, TLENGTH, UNDEFINED_LENGTH, 
     cXMLChWriterInterface> cImplements;
};

/**
 **********************************************************************
 *  Class: cXMLChStreamInterface
 *
 * Author: $author$
 *   Date: 3/14/2008
 **********************************************************************
 */
class c_INTERFACE_CLASS cXMLChStreamInterface
: virtual public cStreamInterfaceT
  <XMLCh, TSIZE, TLENGTH, UNDEFINED_LENGTH, 
   cXMLChReaderInterface, cXMLChWriterInterface>
{
public:
    typedef cStreamInterfaceT
    <XMLCh, TSIZE, TLENGTH, UNDEFINED_LENGTH, 
     cXMLChReaderInterface, cXMLChWriterInterface> cImplements;
};
/**
 **********************************************************************
 *  Class: cXMLChStreamImplement
 *
 * Author: $author$
 *   Date: 3/14/2008
 **********************************************************************
 */
class cXMLChStreamImplement
: virtual public cStreamImplementT
  <XMLCh, TSIZE, TLENGTH, UNDEFINED_LENGTH,
   cXMLChReaderInterface, cXMLChWriterInterface,
   cXMLChStreamInterface, cXMLChReaderImplement, cXMLChWriterImplement>
{
public:
    typedef cStreamImplementT
    <XMLCh, TSIZE, TLENGTH, UNDEFINED_LENGTH,
     cXMLChReaderInterface, cXMLChWriterInterface,
     cXMLChStreamInterface, cXMLChReaderImplement, cXMLChWriterImplement> cImplements;
};

/**
 **********************************************************************
 * Typedef: cXMLChStringInterface
 *
 *  Author: $author$
 *    Date: 3/14/2008
 **********************************************************************
 */
typedef cStringInterfaceT
<XMLCh, TSIZE, TLENGTH, UNDEFINED_LENGTH, XMLCh, NULL_XMLCh,
 cXMLChStreamInterface>
cXMLChStringInterface;
/**
 **********************************************************************
 * Typedef: cXMLChStringImplement
 *
 *  Author: $author$
 *    Date: 3/14/2008
 **********************************************************************
 */
typedef cStringImplementT
<XMLCh, TSIZE, TLENGTH, UNDEFINED_LENGTH, XMLCh, NULL_XMLCh,
 cXMLChStreamInterface, cXMLChStringInterface, cXMLChStreamImplement>
cXMLChStringImplement;

/**
 **********************************************************************
 * Typedef: cXMLChStringExtends
 *
 *  Author: $author$
 *    Date: 1/7/2008
 **********************************************************************
 */
typedef std::basic_string<XMLCh>
cXMLChStringExtends;
/**
 **********************************************************************
 * Typedef: cXMLChString
 *
 *  Author: $author$
 *    Date: 1/7/2008
 **********************************************************************
 */
typedef cStringT
<XMLCh, TSIZE, TLENGTH, UNDEFINED_LENGTH, XMLCh, NULL_XMLCh, 
 cXMLChStreamInterface, cXMLChStringImplement, cXMLChStringExtends>
cXMLChString;

#endif /* _CXMLCHSTRING_HXX */
