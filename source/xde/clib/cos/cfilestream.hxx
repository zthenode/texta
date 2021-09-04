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
 *   File: cfilestream.hxx
 *
 * Author: $author$
 *   Date: 3/5/2008
 **********************************************************************
 */
#ifndef _CFILESTREAM_HXX
#define _CFILESTREAM_HXX

#include "cfileattached.hxx"
#include "cstream.hxx"

/**
 **********************************************************************
 *  Typedef: cFILEStreamExtends
 *
 *  Author: $author$
 *    Date: 10/20/2008
 **********************************************************************
 */
typedef cStreamT
  <CHAR, TSIZE, TLENGTH, UNDEFINED_LENGTH, 
   cStreamImplement, cFILEAttached>
cFILEStreamExtends;
/**
 **********************************************************************
 *  Class: cFILEStream
 *
 * Author: $author$
 *   Date: 3/5/2008
 **********************************************************************
 */
class cFILEStream
: public cFILEStreamExtends
{
public:
    typedef cFILEStreamExtends cExtends;
    typedef cFILEStream cDerives;
    /**
     **********************************************************************
     * Constructor: cFILEStream
     *
     *      Author: $author$
     *        Date: 3/5/2008
     **********************************************************************
     */
    cFILEStream(FILE* attached=INVALID_FILEP) 
    {
        CTHIS m_attached = attached;
    }
};

/**
 **********************************************************************
 *  Typedef: cCharFILEStreamExtends
 *
 *  Author: $author$
 *    Date: 10/20/2008
 **********************************************************************
 */
typedef cStreamT
  <char,TSIZE,TLENGTH,UNDEFINED_LENGTH,
   cCharStreamImplement,cFILEAttached>
cCharFILEStreamExtends;
/**
 **********************************************************************
 *  Class: cCharFILEStream
 *
 * Author: $author$
 *   Date: 4/3/2008
 **********************************************************************
 */
class cCharFILEStream
: public cCharFILEStreamExtends
{
public:
    typedef cCharFILEStreamExtends cExtends;
    /**
     **********************************************************************
     * Constructor: cCharFILEStream
     *
     *      Author: $author$
     *        Date: 4/3/2008
     **********************************************************************
     */
    cCharFILEStream
    (FILE* attached=INVALID_FILEP) 
    {
    }
};

/**
 **********************************************************************
 *  Typedef: cBYTEFILEStreamExtends
 *
 *  Author: $author$
 *    Date: 10/20/2008
 **********************************************************************
 */
typedef cStreamT
<BYTE,TSIZE,TLENGTH,UNDEFINED_LENGTH,
 cBYTEStreamImplement,cFILEAttached>
cBYTEFILEStreamExtends;
/**
 **********************************************************************
 *  Class: cBYTEFILEStream
 *
 * Author: $author$
 *   Date: 10/20/2008
 **********************************************************************
 */
class cBYTEFILEStream
: public cBYTEFILEStreamExtends
{
public:
    typedef cBYTEFILEStreamExtends cExtends;
    typedef cBYTEFILEStream cDerives;
    /**
     **********************************************************************
     * Constructor: cBYTEFILEStream
     *
     *      Author: $author$
     *        Date: 10/20/2008
     **********************************************************************
     */
    cBYTEFILEStream
    (FILE* attached=INVALID_FILEP) 
    {
    }
};
#endif /* _CFILESTREAM_HXX */
