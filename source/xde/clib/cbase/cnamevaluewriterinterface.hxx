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
 *   File: cnamevaluewriterinterface.hxx
 *
 * Author: $author$
 *   Date: 3/20/2008
 **********************************************************************
 */
#ifndef _CNAMEVALUEWRITERINTERFACE_HXX
#define _CNAMEVALUEWRITERINTERFACE_HXX

#include "cnamevalueeventinterface.hxx"
#include "creaderinterface.hxx"

#undef CDB_CLASS
#define CDB_CLASS "cNameValueWriterInterfaceT"
/**
 **********************************************************************
 *  Class: cNameValueWriterInterfaceT
 *
 * Author: $author$
 *   Date: 3/20/2008
 **********************************************************************
 */
template
<class TWhat=CHAR,
 class TSize=TSIZE,
 class TLength=TLENGTH,
 class TReader=cReaderInterface,
 class TImplements=cNameValueEventInterface>
 
class c_INTERFACE_CLASS cNameValueWriterInterfaceT
: virtual public TImplements
{
public:
    typedef TImplements cImplements;
    typedef cNameValueWriterInterfaceT cDerives;
};
#undef CDB_CLASS

/**
 **********************************************************************
 *  Class: cNameValueWriterInterface
 *
 * Author: $author$
 *   Date: 3/20/2008
 **********************************************************************
 */
class c_INTERFACE_CLASS cNameValueWriterInterface
: virtual public cNameValueWriterInterfaceT
  <char,TSIZE,TLENGTH,
   cCharReaderInterface,cNameValueEventInterface>
{
public:
    typedef cNameValueWriterInterfaceT
    <char,TSIZE,TLENGTH,
     cCharReaderInterface,cNameValueEventInterface> cImplements;
};

#endif /* _CNAMEVALUEWRITERINTERFACE_HXX */
