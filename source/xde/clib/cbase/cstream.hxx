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
 *   File: cstream.hxx
 *
 * Author: $author$
 *   Date: 1/16/2008
 **********************************************************************
 */
#ifndef _CSTREAM_HXX
#define _CSTREAM_HXX

#include "cstreaminterface.hxx"
#include "cstring.hxx"
#include "cbase.hxx"

/**
 **********************************************************************
 *  Class: cStreamT
 *
 * Author: $author$
 *   Date: 1/16/2008
 **********************************************************************
 */
template
<class TWhat=CHAR,
 class TSize=TSIZE,
 class TLength=TLENGTH,
 TLength VUndefinedLength=UNDEFINED_LENGTH,
 class TImplements=cStreamImplement,
 class TExtends=cBase>
 
class cStreamT
: virtual public TImplements,
  public TExtends
{
public:
    typedef TImplements cImplements;
    typedef TExtends cExtends;
    typedef cStreamT cDerives;

    /**
     **********************************************************************
     * Constructor: cStreamT
     *
     *      Author: $author$
     *        Date: 1/16/2008
     **********************************************************************
     */
    cStreamT() 
    {
    }
    /**
     **********************************************************************
     * Destructor: cStreamT
     *
     *     Author: $author$
     *       Date: 1/16/2008
     **********************************************************************
     */
    virtual ~cStreamT()
    {
    }
};

/**
 **********************************************************************
 *  Typedef: cStream
 *
 *  Author: $author$
 *    Date: 1/16/2008
 **********************************************************************
 */
typedef cStreamT
<CHAR, TSIZE, TLENGTH, UNDEFINED_LENGTH, 
 cStreamImplement, cBase>
cStream;

/**
 **********************************************************************
 *  Typedef: cCharStream
 *
 *  Author: $author$
 *    Date: 1/16/2008
 **********************************************************************
 */
typedef cStreamT
<char, TSIZE, TLENGTH, UNDEFINED_LENGTH, 
 cCharStreamImplement, cBase>
cCharStream;

/**
 **********************************************************************
 *  Typedef: cBYTEStream
 *
 *  Author: $author$
 *    Date: 1/16/2008
 **********************************************************************
 */
typedef cStreamT
<BYTE, TSIZE, TLENGTH, UNDEFINED_LENGTH, 
 cBYTEStreamImplement, cBase>
cBYTEStream;

/**
 **********************************************************************
 *  Typedef: cTCHARStream
 *
 *  Author: $author$
 *    Date: 1/16/2008
 **********************************************************************
 */
typedef cStreamT
<TCHAR, TSIZE, TLENGTH, UNDEFINED_LENGTH, 
 cTCHARStreamImplement, cBase>
cTCHARStream;

/**
 **********************************************************************
 *  Typedef: cWCHARStream
 *
 *  Author: $author$
 *    Date: 1/16/2008
 **********************************************************************
 */
typedef cStreamT
<WCHAR, TSIZE, TLENGTH, UNDEFINED_LENGTH, 
 cWCHARStreamImplement, cBase>
cWCHARStream;

#endif /* _CSTREAM_HXX */
