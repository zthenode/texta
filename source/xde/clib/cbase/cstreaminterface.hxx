/**
 **********************************************************************
 * Copyright (c) $year$ $author$
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
 *   File: cstreaminterface.hxx
 *
 * Author: $author$
 *   Date: $date$
 **********************************************************************
 */

#ifndef _CSTREAMINTERFACE_HXX
#define _CSTREAMINTERFACE_HXX

#include "creaderinterface.hxx"
#include "cwriterinterface.hxx"

/**
 **********************************************************************
 *  Class: cStreamInterfaceT
 *
 * Author: $author$
 *   Date: $date$
 **********************************************************************
 */
template
<class TWhat=CHAR,
 class TSize=TSIZE,
 class TLength=TLENGTH,
 TLength VUndefinedLength=UNDEFINED_LENGTH,
 class TImplementsReader=cReaderInterface,
 class TImplementsWriter=cWriterInterface>

class c_INTERFACE_CLASS cStreamInterfaceT
: virtual public TImplementsReader,
  virtual public TImplementsWriter
{
public:
	typedef TImplementsReader cImplementsReader;
	typedef TImplementsWriter cImplementsWriter;
    typedef TWhat tWhat;
    typedef TSize tSize;
    typedef TLength tLength;

    /**
     **********************************************************************
     * Function: WriteReader
     *
     *   Author: $author$
     *     Date: $date$
     **********************************************************************
     */
    virtual TLength WriteReader
    (TImplementsReader& reader,
     TLength length=VUndefinedLength) = 0;
    /**
     **********************************************************************
     * Function: GetReader
     *
     *   Author: $author$
     *     Date: $date$
     **********************************************************************
     */
    virtual TImplementsReader& GetReader() const = 0;
    /**
     **********************************************************************
     * Function: GetWriter
     *
     *   Author: $author$
     *     Date: $date$
     **********************************************************************
     */
    virtual TImplementsWriter& GetWriter() const = 0;
};

/**
 **********************************************************************
 * Typedef: cStreamInterface
 *
 * Author: $author$
 *   Date: $date$
 **********************************************************************
 */
typedef cStreamInterfaceT
<CHAR, TSIZE, TLENGTH, UNDEFINED_LENGTH,
 cReaderInterface, cWriterInterface>
cStreamInterface;

/**
 **********************************************************************
 *  Class: cStreamImplementT
 *
 * Author: $author$
 *   Date: $date$
 **********************************************************************
 */
template
<class TWhat=CHAR,
 class TSize=TSIZE,
 class TLength=TLENGTH,
 TLength VUndefinedLength=UNDEFINED_LENGTH,
 class TImplementsReader=cReaderInterface,
 class TImplementsWriter=cWriterInterface,
 class TImplements=cStreamInterface, 
 class TReaderImplement=cReaderImplement,
 class TWriterImplement=cWriterImplement>

class cStreamImplementT
: virtual public TReaderImplement,
  virtual public TWriterImplement,
  virtual public TImplements
{
public:
    typedef TImplements cImplements;
    /**
     **********************************************************************
     * Function: WriteReader
     *
     *   Author: $author$
     *     Date: $date$
     **********************************************************************
     */
    virtual TLength WriteReader
    (TImplementsReader& reader,
     TLength length=VUndefinedLength) 
    {
        TLength count = 0;
        TLength count2;
        TWhat what;

        if ((0 <= length) && (length != VUndefinedLength))
        while (count < length)
        {
            if (0 > (count2 = reader.Read(&what, 1)))
                break;
            else
            if (0 > (count2 = CTHIS Write(&what, 1)))
                return count2;
            else
            count += count2;
        }
        else
        while (0 < (count2 = reader.Read(&what, 1)))
        {
            if (0 > (count2 = CTHIS Write(&what, 1)))
                return count2;
            else
            count += count2;
        }
        return count;
    }
    /**
     **********************************************************************
     * Function: GetReader
     *
     *   Author: $author$
     *     Date: $date$
     **********************************************************************
     */
    virtual TImplementsReader& GetReader() const
    {
        return *(TImplementsReader*)(this);
    }
    /**
     **********************************************************************
     * Function: GetWriter
     *
     *   Author: $author$
     *     Date: $date$
     **********************************************************************
     */
    virtual TImplementsWriter& GetWriter() const
    {
        return *(TImplementsWriter*)(this);
    }
};

/**
 **********************************************************************
 * Typedef: cStreamImplement
 *
 * Author: $author$
 *   Date: $date$
 **********************************************************************
 */
typedef cStreamImplementT
<CHAR, TSIZE, TLENGTH, UNDEFINED_LENGTH, 
 cReaderInterface, cWriterInterface, 
 cStreamInterface, cReaderImplement, cWriterImplement>
cStreamImplement;

/*
 * char
 */

/**
 **********************************************************************
 *  Class: cCharStreamInterface
 *
 * Author: $author$
 *   Date: $date$
 **********************************************************************
 */
class c_INTERFACE_CLASS cCharStreamInterface
: virtual public cStreamInterfaceT
  <char, TSIZE, TLENGTH, UNDEFINED_LENGTH, 
   cCharReaderInterface, cCharWriterInterface>
{
public:
    typedef cStreamInterfaceT
    <char, TSIZE, TLENGTH, UNDEFINED_LENGTH, 
     cCharReaderInterface, cCharWriterInterface> cImplements;
};

/**
 **********************************************************************
 *  Class: cCharStreamImplement
 *
 * Author: $author$
 *   Date: $date$
 **********************************************************************
 */
class cCharStreamImplement
: virtual public cStreamImplementT
  <char, TSIZE, TLENGTH, UNDEFINED_LENGTH, 
   cCharReaderInterface, cCharWriterInterface, 
   cCharStreamInterface, cCharReaderImplement, cCharWriterImplement>
{
public:
    typedef cStreamImplementT
    <char, TSIZE, TLENGTH, UNDEFINED_LENGTH, 
     cCharReaderInterface, cCharWriterInterface, 
     cCharStreamInterface, cCharReaderImplement, cCharWriterImplement> cImplements;
};

/*
 * BYTE
 */

/**
 **********************************************************************
 *  Class: cBYTEStreamInterface
 *
 * Author: $author$
 *   Date: $date$
 **********************************************************************
 */
class c_INTERFACE_CLASS cBYTEStreamInterface
: virtual public cStreamInterfaceT
  <BYTE, TSIZE, TLENGTH, UNDEFINED_LENGTH, 
   cBYTEReaderInterface, cBYTEWriterInterface>
{
public:
    typedef cStreamInterfaceT
    <BYTE, TSIZE, TLENGTH, UNDEFINED_LENGTH, 
     cBYTEReaderInterface, cBYTEWriterInterface> cImplements;
};

/**
 **********************************************************************
 *  Class: cBYTEStreamImplement
 *
 * Author: $author$
 *   Date: $date$
 **********************************************************************
 */
class cBYTEStreamImplement
: virtual public cStreamImplementT
  <BYTE, TSIZE, TLENGTH, UNDEFINED_LENGTH,
   cBYTEReaderInterface, cBYTEWriterInterface, 
   cBYTEStreamInterface, cBYTEReaderImplement, cBYTEWriterImplement>
{
public:
    typedef cStreamImplementT
    <BYTE, TSIZE, TLENGTH, UNDEFINED_LENGTH, 
     cBYTEReaderInterface, cBYTEWriterInterface, 
     cBYTEStreamInterface, cBYTEReaderImplement, cBYTEWriterImplement> cImplements;
};

/*
 * TCHAR
 */

/**
 **********************************************************************
 *  Class: cTCHARStreamInterface
 *
 * Author: $author$
 *   Date: $date$
 **********************************************************************
 */
class c_INTERFACE_CLASS cTCHARStreamInterface
: virtual public cStreamInterfaceT
  <TCHAR, TSIZE, TLENGTH, UNDEFINED_LENGTH, 
   cTCHARReaderInterface, cTCHARWriterInterface>
{
public:
    typedef cStreamInterfaceT
    <TCHAR, TSIZE, TLENGTH, UNDEFINED_LENGTH, 
     cTCHARReaderInterface, cTCHARWriterInterface> cImplements;
};

/**
 **********************************************************************
 *  Class: cTCHARStreamImplement
 *
 * Author: $author$
 *   Date: $date$
 **********************************************************************
 */
class cTCHARStreamImplement
: virtual public cStreamImplementT
  <TCHAR, TSIZE, TLENGTH, UNDEFINED_LENGTH, 
   cTCHARReaderInterface, cTCHARWriterInterface, 
   cTCHARStreamInterface, cTCHARReaderImplement, cTCHARWriterImplement>
{
public:
    typedef cStreamImplementT
    <TCHAR, TSIZE, TLENGTH, UNDEFINED_LENGTH, 
     cTCHARReaderInterface, cTCHARWriterInterface, 
     cTCHARStreamInterface, cTCHARReaderImplement, cTCHARWriterImplement> cImplements;
};

/*
 * WCHAR
 */

/**
 **********************************************************************
 *  Class: cWCHARStreamInterface
 *
 * Author: $author$
 *   Date: $date$
 **********************************************************************
 */
class c_INTERFACE_CLASS cWCHARStreamInterface
: virtual public cStreamInterfaceT
  <WCHAR, TSIZE, TLENGTH, UNDEFINED_LENGTH, 
   cWCHARReaderInterface, cWCHARWriterInterface>
{
public:
    typedef cStreamInterfaceT
    <WCHAR, TSIZE, TLENGTH, UNDEFINED_LENGTH, 
     cWCHARReaderInterface, cWCHARWriterInterface> cImplements;
};

/**
 **********************************************************************
 *  Class: cWCHARStreamImplement
 *
 * Author: $author$
 *   Date: $date$
 **********************************************************************
 */
class cWCHARStreamImplement
: virtual public cStreamImplementT
  <WCHAR, TSIZE, TLENGTH, UNDEFINED_LENGTH, 
   cWCHARReaderInterface, cWCHARWriterInterface, 
   cWCHARStreamInterface, cWCHARReaderImplement, cWCHARWriterImplement>
{
public:
    typedef cStreamImplementT
    <WCHAR, TSIZE, TLENGTH, UNDEFINED_LENGTH, 
     cWCHARReaderInterface, cWCHARWriterInterface, 
     cWCHARStreamInterface, cWCHARReaderImplement, cWCHARWriterImplement> cImplements;
};

#endif /* _CSTREAMINTERFACE_HXX */
