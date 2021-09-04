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
 *   File: cstringinterface.hxx
 *
 * Author: $author$
 *   Date: 1/7/2008
 **********************************************************************
 */
#ifndef _CSTRINGINTERFACE_HXX
#define _CSTRINGINTERFACE_HXX

#include "cstreaminterface.hxx"
#include "cplatform_string.h"

/**
 **********************************************************************
 *  Class: cStringInterfaceT
 *
 * Author: $author$
 *   Date: 1/7/2008
 **********************************************************************
 */
template
<class TChar=CHAR, 
 class TSize=TSIZE,
 class TLength=TLENGTH,
 TLength VUndefinedLength=UNDEFINED_LENGTH,
 class TNullChar=TChar,
 TNullChar VNullChar=NULL_CHAR,
 class TImplements=cStreamInterface>
 
class c_INTERFACE_CLASS cStringInterfaceT
: virtual public TImplements
{
public:
    typedef TImplements TStreamInterface;
    typedef TImplements cImplements;
    typedef cStringInterfaceT cDerives;

    /**
     **********************************************************************
     * Function: ReadLine
     *
     *   Author: $author$
     *     Date: 1/7/2008
     **********************************************************************
     */
    virtual TLength ReadLine
    (TStreamInterface& stream,
     TChar* chars, TSize size,
     bool hasCR=false) = 0;
    /**
     **********************************************************************
     * Function: WriteLine
     *
     *   Author: $author$
     *     Date: 1/7/2008
     **********************************************************************
     */
    virtual TLength WriteLine
    (TStreamInterface& stream,
     TLength length=VUndefinedLength,
     bool hasCR=false) = 0;

    /**
     **********************************************************************
     * Function: Read
     *
     *   Author: $author$
     *     Date: 1/7/2008
     **********************************************************************
     */
    virtual TLength Read
    (TStreamInterface& stream,
     TChar* chars, TSize size) = 0;
    /**
     **********************************************************************
     * Function: Write
     *
     *   Author: $author$
     *     Date: 1/7/2008
     **********************************************************************
     */
    virtual TLength Write
    (TStreamInterface& stream,
     TLength length=VUndefinedLength) = 0;

    /**
     **********************************************************************
     * Function: Assignc
     *
     *   Author: $author$
     *     Date: 1/7/2008
     **********************************************************************
     */
    virtual TLength Assignc
    (const char* chars,
     TLength length=VUndefinedLength) = 0;
    /**
     **********************************************************************
     * Function: Appendc
     *
     *   Author: $author$
     *     Date: 1/7/2008
     **********************************************************************
     */
    virtual TLength Appendc
    (const char* chars,
     TLength length=VUndefinedLength) = 0;
    /**
     **********************************************************************
     * Function: Assign
     *
     *   Author: $author$
     *     Date: 1/7/2008
     **********************************************************************
     */
    virtual TLength Assign
    (const TChar* chars,
     TLength length=VUndefinedLength) = 0;
    /**
     **********************************************************************
     * Function: Append
     *
     *   Author: $author$
     *     Date: 1/7/2008
     **********************************************************************
     */
    virtual TLength Append
    (const TChar* chars,
     TLength length=VUndefinedLength) = 0;
    /**
     **********************************************************************
     * Function: Clear
     *
     *   Author: $author$
     *     Date: 1/7/2008
     **********************************************************************
     */
    virtual TLength Clear() = 0;
    /**
     **********************************************************************
     * Function: AssignChars
     *
     *   Author: $author$
     *     Date: 9/5/2008
     **********************************************************************
     */
    virtual TLength AssignChars
    (const TChar* chars,
     TLength length=VUndefinedLength) = 0;
    /**
     **********************************************************************
     * Function: AppendChars
     *
     *   Author: $author$
     *     Date: 9/5/2008
     **********************************************************************
     */
    virtual TLength AppendChars
    (const TChar* chars,
     TLength length=VUndefinedLength) = 0;
    /**
     **********************************************************************
     * Function: ClearChars
     *
     *   Author: $author$
     *     Date: 9/5/2008
     **********************************************************************
     */
    virtual TLength ClearChars() = 0;
    /**
     **********************************************************************
     * Function: CaseComparec
     *
     *   Author: $author$
     *     Date: 1/7/2008
     **********************************************************************
     */
    virtual int CaseComparec
    (const char* chars,
     TLength length=VUndefinedLength) const = 0;
    /**
     **********************************************************************
     * Function: Comparec
     *
     *   Author: $author$
     *     Date: 1/7/2008
     **********************************************************************
     */
    virtual int Comparec
    (const char* chars,
     TLength length=VUndefinedLength) const = 0;
    /**
     **********************************************************************
     * Function: CaseCompare
     *
     *   Author: $author$
     *     Date: 1/7/2008
     **********************************************************************
     */
    virtual int CaseCompare
    (const TChar* chars,
     TLength length=VUndefinedLength) const = 0;
    /**
     **********************************************************************
     * Function: Compare
     *
     *   Author: $author$
     *     Date: 1/7/2008
     **********************************************************************
     */
    virtual int Compare
    (const TChar* chars,
     TLength length=VUndefinedLength) const = 0;
    /**
     **********************************************************************
     * Function: Length
     *
     *   Author: $author$
     *     Date: 1/7/2008
     **********************************************************************
     */
    virtual TLength Length() const = 0;
    /**
     **********************************************************************
     * Function: HasChars
     *
     *   Author: $author$
     *     Date: 1/7/2008
     **********************************************************************
     */
    virtual const TChar* HasChars
    (TLength& length) const = 0;
    /**
     **********************************************************************
     * Function: Chars
     *
     *   Author: $author$
     *     Date: 1/7/2008
     **********************************************************************
     */
    virtual const TChar* Chars
    (TLength& length) const = 0;
};

/**
 **********************************************************************
 * Typedef: cStringInterface
 *
 *  Author: $author$
 *    Date: 1/7/2008
 **********************************************************************
 */
typedef cStringInterfaceT
<CHAR, TSIZE, TLENGTH, UNDEFINED_LENGTH, 
 CHAR, NULL_CHAR,
 cStreamInterface>
cStringInterface;

/**
 **********************************************************************
 * Typedef: cCharStringInterface
 *
 *  Author: $author$
 *    Date: 1/7/2008
 **********************************************************************
 */
typedef cStringInterfaceT
<char, TSIZE, TLENGTH, UNDEFINED_LENGTH, 
 char, 0,
 cCharStreamInterface>
cCharStringInterface;

/**
 **********************************************************************
 * Typedef: cTStringInterface
 *
 *  Author: $author$
 *    Date: 1/7/2008
 **********************************************************************
 */
typedef cStringInterfaceT
<TCHAR, TSIZE, TLENGTH, UNDEFINED_LENGTH, 
 TCHAR, NULL_TCHAR,
 cTCHARStreamInterface>
cTCHARStringInterface,
cTStringInterface;

/**
 **********************************************************************
 * Typedef: cWStringInterface
 *
 *  Author: $author$
 *    Date: 1/7/2008
 **********************************************************************
 */
typedef cStringInterfaceT
<WCHAR, TSIZE, TLENGTH, UNDEFINED_LENGTH, 
 WCHAR, NULL_WCHAR,
 cWCHARStreamInterface>
cWCHARStringInterface,
cWStringInterface;

/**
 **********************************************************************
 * Typedef: cBYTEStringInterface
 *
 *  Author: $author$
 *    Date: 1/7/2008
 **********************************************************************
 */
typedef cStringInterfaceT
<BYTE, TSIZE, TLENGTH, UNDEFINED_LENGTH, 
 BYTE, 0,
 cBYTEStreamInterface>
cBYTEStringInterface;

/**
 **********************************************************************
 *  Class: cStringImplementT
 *
 * Author: $author$
 *   Date: 1/7/2008
 **********************************************************************
 */
template
<class TChar=CHAR, 
 class TSize=TSIZE,
 class TLength=TLENGTH,
 TLength VUndefinedLength=UNDEFINED_LENGTH,
 class TNullChar=TChar,
 TNullChar VNullChar=NULL_CHAR,
 class TStreamInterface=cStreamInterface,
 class TImplements=cStringInterface,
 class TExtends=cStreamImplement>
 
class cStringImplementT
: virtual public TImplements,
  virtual public TExtends
{
public:
    typedef TImplements cImplements;
    typedef TExtends cExtends;
    typedef cStringImplementT cDerives;

    /**
     **********************************************************************
     * Function: ReadLine
     *
     *   Author: $author$
     *     Date: 1/7/2008
     **********************************************************************
     */
    virtual TLength ReadLine
    (TStreamInterface& stream,
     TChar* chars, TSize size,
     bool hasCR=false) 
    {
        const TChar lf = (TChar)('\n');
        const TChar cr = (TChar)('\r');
        TLength count = -e_ERROR_NOT_IMPLEMENTED;
        TSize length;
        TChar c;

        for (length = 0; (length < size);)
        {
            if (0 > (count = stream.Read(chars+length, 1)))
                return count = -e_ERROR_READ;

            if ((c = chars[length]) != lf)
            {
                if (hasCR || (c != cr))
                    length++;
                continue;
            }
            break;
        }

        count = Assign(chars, length);
        return count;
    }
    /**
     **********************************************************************
     * Function: WriteLine
     *
     *   Author: $author$
     *     Date: 1/7/2008
     **********************************************************************
     */
    virtual TLength WriteLine
    (TStreamInterface& stream,
     TLength length=VUndefinedLength,
     bool hasCR=false) 
    {
        const TChar lf = (TChar)('\n');
        const TChar cr = (TChar)('\r');
        TLength count = -e_ERROR_NOT_IMPLEMENTED;

        if (0 <= (count = Write(stream, length)))
        if (0 < (length = stream.Write(&lf, 1)))
        if (0 < (count += length))
        if (hasCR)
        if (0 >= (length = stream.Write(&cr, 1)))
            return count = -e_ERROR_WRITE;

        return count;
    }

    /**
     **********************************************************************
     * Function: Read
     *
     *   Author: $author$
     *     Date: 1/7/2008
     **********************************************************************
     */
    virtual TLength Read
    (TStreamInterface& stream,
     TChar* chars, TSize size) 
    {
        TLength count = -e_ERROR_NOT_IMPLEMENTED;

        if (0 > (count = stream.Read(chars, size)))
            return count = -e_ERROR_FAILED;

        count = Assign(chars, count);
        return count;
    }
    /**
     **********************************************************************
     * Function: Write
     *
     *   Author: $author$
     *     Date: 1/7/2008
     **********************************************************************
     */
    virtual TLength Write
    (TStreamInterface& stream,
     TLength length=VUndefinedLength) 
    {
        TLength count = -e_ERROR_NOT_IMPLEMENTED;
        const TChar* chars;

        if (!(chars = HasChars(count)))
            return count;

        if ((0 > length) || (length > count))
            length = count;

        if (0 > (count = stream.Write(chars, length)))
            count = -e_ERROR_FAILED;
        return count;
    }

    /**
     **********************************************************************
     * Function: Write
     *
     *   Author: $author$
     *     Date: 1/7/2008
     **********************************************************************
     */
    virtual TLength Write
    (const TChar* chars,
     TLength length=VUndefinedLength) 
    {
        TLength count = Append(chars, length);
        return count;
    }

    /**
     **********************************************************************
     * Function: Assignc
     *
     *   Author: $author$
     *     Date: 1/7/2008
     **********************************************************************
     */
    virtual TLength Assignc
    (const char* chars,
     TLength length=VUndefinedLength) 
    {
        TLength count = -e_ERROR_NOT_IMPLEMENTED;
        return count;
    }
    /**
     **********************************************************************
     * Function: Appendc
     *
     *   Author: $author$
     *     Date: 1/7/2008
     **********************************************************************
     */
    virtual TLength Appendc
    (const char* chars,
     TLength length=VUndefinedLength) 
    {
        TLength count = -e_ERROR_NOT_IMPLEMENTED;
        return count;
    }
    /**
     **********************************************************************
     * Function: Assign
     *
     *   Author: $author$
     *     Date: 1/7/2008
     **********************************************************************
     */
    virtual TLength Assign
    (const TChar* chars,
     TLength length=VUndefinedLength) 
    {
        TLength count = AssignChars(chars, length);
        return count;
    }
    /**
     **********************************************************************
     * Function: AssignChars
     *
     *   Author: $author$
     *     Date: 9/5/2008
     **********************************************************************
     */
    virtual TLength AssignChars
    (const TChar* chars,
     TLength length=VUndefinedLength) 
    {
        TLength count = -e_ERROR_NOT_IMPLEMENTED;
        if (0 <= (count = ClearChars()))
            count = AppendChars(chars, length);
        return count;
    }
    /**
     **********************************************************************
     * Function: AssignL
     *
     *   Author: $author$
     *     Date: 5/1/2008
     **********************************************************************
     */
    virtual TLength AssignL
    (const TChar* chars, ...) 
    {
        TLength count = 0;
        TLength count2;
        va_list arg;

        va_start(arg, chars);

        if (0 <= (count = Assign(chars)))
        if (0 <= (count2 = AppendV(arg)))
            count += count2;

        va_end(arg);
        return count;
    }
    /**
     **********************************************************************
     * Function: Append
     *
     *   Author: $author$
     *     Date: 1/7/2008
     **********************************************************************
     */
    virtual TLength Append
    (const TChar* chars,
     TLength length=VUndefinedLength) 
    {
        TLength count = AppendChars(chars, length);
        return count;
    }
    /**
     **********************************************************************
     * Function: AppendChars
     *
     *   Author: $author$
     *     Date: 9/5/2008
     **********************************************************************
     */
    virtual TLength AppendChars
    (const TChar* chars,
     TLength length=VUndefinedLength) 
    {
        TLength count = -e_ERROR_NOT_IMPLEMENTED;
        return count;
    }
    /**
     **********************************************************************
     * Function: AppendL
     *
     *   Author: $author$
     *     Date: 5/1/2008
     **********************************************************************
     */
    virtual TLength AppendL
    (const TChar* chars, ...) 
    {
        TLength count = 0;
        TLength count2;
        va_list arg;

        va_start(arg, chars);

        if (0 <= (count = Append(chars)))
        if (0 <= (count2 = AppendV(arg)))
            count += count2;

        va_end(arg);
        return count;
    }
    /**
     **********************************************************************
     * Function: AppendV
     *
     *   Author: $author$
     *     Date: 5/1/2008
     **********************************************************************
     */
    virtual TLength AppendV(va_list va) 
    {
        TLength count = 0;
        TLength count2;
        const TChar* chars;

        while ((chars = va_arg(va, const TChar*)))
        {
            if (0 > (count2 = Append(chars)))
                return count2;
            count += count2;
        }
        return count;
    }
    /**
     **********************************************************************
     * Function: Clear
     *
     *   Author: $author$
     *     Date: 1/7/2008
     **********************************************************************
     */
    virtual TLength Clear() 
    {
        TLength count = ClearChars();
        return count;
    }
    /**
     **********************************************************************
     * Function: ClearChars
     *
     *   Author: $author$
     *     Date: 9/5/2008
     **********************************************************************
     */
    virtual TLength ClearChars() 
    {
        TLength count = -e_ERROR_NOT_IMPLEMENTED;
        return count;
    }
    /**
     **********************************************************************
     * Function: CopyTo
     *
     *   Author: $author$
     *     Date: 1/7/2008
     **********************************************************************
     */
    virtual TLength CopyTo
    (TChar* toChars, const TChar* chars, TSize size) const 
    {
        TLength count = (TLength)(size);
        memcpy(toChars, chars, sizeof(TChar)*size);
        return count;
    }
    /**
     **********************************************************************
     * Function: CaseComparec
     *
     *   Author: $author$
     *     Date: 1/7/2008
     **********************************************************************
     */
    virtual int CaseComparec
    (const char* chars,
     TLength length=VUndefinedLength) const 
    {
        int unequal = -e_ERROR_NOT_IMPLEMENTED-1;
        return unequal;
    }
    /**
     **********************************************************************
     * Function: Comparec
     *
     *   Author: $author$
     *     Date: 1/7/2008
     **********************************************************************
     */
    virtual int Comparec
    (const char* chars,
     TLength length=VUndefinedLength) const 
    {
        int unequal = -e_ERROR_NOT_IMPLEMENTED-1;
        return unequal;
    }
    /**
     **********************************************************************
     * Function: CaseCompare
     *
     *   Author: $author$
     *     Date: 1/7/2008
     **********************************************************************
     */
    virtual int CaseCompare
    (const TChar* chars,
     TLength length=VUndefinedLength) const
    {
        int unequal = -e_ERROR_NOT_IMPLEMENTED-1;
        return unequal;
    }
    /**
     **********************************************************************
     * Function: Compare
     *
     *   Author: $author$
     *     Date: 1/7/2008
     **********************************************************************
     */
    virtual int Compare
    (const TChar* chars,
     TLength length=VUndefinedLength) const
    {
        int unequal = -e_ERROR_NOT_IMPLEMENTED-1;
        return unequal;
    }
    /**
     **********************************************************************
     * Function: Length
     *
     *   Author: $author$
     *     Date: 1/7/2008
     **********************************************************************
     */
    virtual TLength Length() const 
    {
        TLength count = -e_ERROR_NOT_IMPLEMENTED;
        return count;
    }
    /**
     **********************************************************************
     * Function: LengthOf
     *
     *   Author: $author$
     *     Date: 1/7/2008
     **********************************************************************
     */
    virtual TLength LengthOf
    (const TChar* chars) const 
    {
        TLength count = -e_ERROR_NOT_IMPLEMENTED;
        for (count=0; *chars != VNullChar; count++)
            chars++;
        return count;
    }
    /**
     **********************************************************************
     * Function: HasChars
     *
     *   Author: $author$
     *     Date: 1/7/2008
     **********************************************************************
     */
    virtual const TChar* HasChars
    (TLength& length) const 
    {
        const TChar* chars = 0;
        if (!(chars = Chars(length)) || (0 >= length))
            chars = 0;
        return chars;
    }
    /**
     **********************************************************************
     * Function: Chars
     *
     *   Author: $author$
     *     Date: 1/7/2008
     **********************************************************************
     */
    virtual const TChar* Chars
    (TLength& length) const 
    {
        const TChar* chars = 0;
        return chars;
    }
};

/**
 **********************************************************************
 * Typedef: cStringImplement
 *
 *  Author: $author$
 *    Date: 1/7/2008
 **********************************************************************
 */
typedef cStringImplementT
<CHAR, TSIZE, TLENGTH, UNDEFINED_LENGTH, 
 CHAR, NULL_CHAR,
 cStreamInterface, cStringInterface, cStreamImplement>
cStringImplement;

/**
 **********************************************************************
 * Typedef: cCharStringImplement
 *
 *  Author: $author$
 *    Date: 1/7/2008
 **********************************************************************
 */
typedef cStringImplementT
<char, TSIZE, TLENGTH, UNDEFINED_LENGTH, 
 char, 0,
 cCharStreamInterface, cCharStringInterface, cCharStreamImplement>
cCharStringImplement;

/**
 **********************************************************************
 * Typedef: cTStringImplement
 *
 *  Author: $author$
 *    Date: 1/7/2008
 **********************************************************************
 */
typedef cStringImplementT
<TCHAR, TSIZE, TLENGTH, UNDEFINED_LENGTH, 
 TCHAR, NULL_TCHAR,
 cTCHARStreamInterface, cTStringInterface, cTCHARStreamImplement>
cTCHARStringImplement,
cTStringImplement;

/**
 **********************************************************************
 * Typedef: cWStringImplement
 *
 *  Author: $author$
 *    Date: 1/7/2008
 **********************************************************************
 */
typedef cStringImplementT
<WCHAR, TSIZE, TLENGTH, UNDEFINED_LENGTH, 
 WCHAR, NULL_WCHAR,
 cWCHARStreamInterface, cWStringInterface, cWCHARStreamImplement>
cWCHARStringImplement,
cWStringImplement;

/**
 **********************************************************************
 * Typedef: cBYTEStringImplement
 *
 *  Author: $author$
 *    Date: 1/7/2008
 **********************************************************************
 */
typedef cStringImplementT
<BYTE, TSIZE, TLENGTH, UNDEFINED_LENGTH, 
 BYTE, 0,
 cBYTEStreamInterface, cBYTEStringInterface, cBYTEStreamImplement>
cBYTEStringImplement;

#endif /* _CSTRINGINTERFACE_HXX */
