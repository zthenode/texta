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
 *   File: cfileinterface.hxx
 *
 * Author: $author$
 *   Date: 3/5/2008
 **********************************************************************
 */
#ifndef _CFILEINTERFACE_HXX
#define _CFILEINTERFACE_HXX

#include "cstreaminterface.hxx"
#include "cfileattachedinterface.hxx"

#undef CDB_CLASS
#define CDB_CLASS "cFileInterfaceT"
/**
 **********************************************************************
 *  Class: cFileInterfaceT
 *
 * Author: $author$
 *   Date: 3/5/2008
 **********************************************************************
 */
template
<class TChar=CHAR,
 class TSize=TSIZE,
 class TLength=TLENGTH,
 TLength VUndefinedLength=UNDEFINED_LENGTH,
 class TStreamInterface=cStreamInterface,
 class TAttachedInterface=cFILEAttachedInterface>
 
class c_INTERFACE_CLASS cFileInterfaceT
: virtual public TStreamInterface,
  virtual public TAttachedInterface
{
public:
    typedef TAttachedInterface cImplements;
    typedef cFileInterfaceT cDerives;
};
#undef CDB_CLASS

/**
 **********************************************************************
 *  Class: cFileInterface
 *
 * Author: $author$
 *   Date: 3/5/2008
 **********************************************************************
 */
class c_INTERFACE_CLASS cFileInterface
: virtual public cFileInterfaceT
  <CHAR,TSIZE,TLENGTH,UNDEFINED_LENGTH,
   cStreamInterface,cFILEAttachedInterface>
{
public:
    typedef cFileInterfaceT
    <CHAR,TSIZE,TLENGTH,UNDEFINED_LENGTH,
     cStreamInterface,cFILEAttachedInterface> cImplements;
};

/**
 **********************************************************************
 *  Class: cCharFileInterface
 *
 * Author: $author$
 *   Date: 3/5/2008
 **********************************************************************
 */
class c_INTERFACE_CLASS cCharFileInterface
: virtual public cFileInterfaceT
  <char,TSIZE,TLENGTH,UNDEFINED_LENGTH,
   cCharStreamInterface,cFILEAttachedInterface>
{
public:
    typedef cFileInterfaceT
    <char,TSIZE,TLENGTH,UNDEFINED_LENGTH,
     cCharStreamInterface,cFILEAttachedInterface> cImplements;
};

/**
 **********************************************************************
 *  Typedef: cBYTEFileInterface
 *
 *  Author: $author$
 *    Date: 10/20/2008
 **********************************************************************
 */
typedef cFileInterfaceT
<BYTE,TSIZE,TLENGTH,UNDEFINED_LENGTH,
 cBYTEStreamInterface,cFILEAttachedInterface>
cBYTEFileInterface;

#endif /* _CFILEINTERFACE_HXX */
