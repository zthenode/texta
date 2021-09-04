/**
 **********************************************************************
 * Copyright (c) 1988-2020 $organization$
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
 *   File: cCryptoBase.hxx
 *
 * Author: $author$
 *   Date: 2/7/2020
 **********************************************************************
 */
#ifndef CCRYPTOBASE_HXX
#define CCRYPTOBASE_HXX

#include "cstring.hxx"

/**
 **********************************************************************
 *  Class: cCryptoBase
 *
 * Author: $author$
 *   Date: 2/7/2020
 **********************************************************************
 */
class cCryptoBase {
public:
    typedef cCryptoBase cDerives;
    /**
     **********************************************************************
     *  Destructor: cCryptoBase
     *
     *      Author: $author$
     *        Date: 2/7/2020
     **********************************************************************
     */
    virtual ~cCryptoBase() {
    }
}; /* class cCryptoBase */

/**
 **********************************************************************
 *  Class: cCryptoString
 *
 * Author: $author$
 *   Date: 2/7/2020
 **********************************************************************
 */
class cCryptoString: public cString {
public:
    typedef cString cExtends;
    typedef cCryptoString cDerives;
    typedef TLENGTH TLength;
    typedef TSIZE TSize;
    typedef char TChar;
    /**
     **********************************************************************
     *  cCryptoString / ~cCryptoString
     *
     *      Author: $author$
     *        Date: 2/7/2020
     **********************************************************************
     */
    cCryptoString() {
    }
    virtual ~cCryptoString() {
    }
    virtual TLength AssignHex(const BYTE* chars, TSize length) {
        TLength count = 0;
        if (0 <= (count = Clear())) {
            count = AppendHex(chars, length);
        }
        return count;
    }
    virtual TLength AppendHex(const BYTE* chars, TSize length) {
        TLength count = 0;
        if ((chars) && (0 < length)) {
            for (TLength amount = 0; (0 < length); --length, ++chars) {
                BYTE byte = *chars;
                if (1 <= (amount = AppendNibble((byte >> 4) & 15))) {
                    count += amount;
                    if (1 <= (amount = AppendNibble(byte & 15))) {
                        count += amount;
                    }
                }
            }
        }
        return count;
    }
    virtual TLength AppendNibble(BYTE byte) {
        const BYTE nibble = (byte & 15);
        const char digit = (10 > nibble)?('0' + nibble):('a' + nibble - 10);
        TLength count = AppendChars(&digit, 1);
        return count;
    }
}; /* class cCryptoString */

#endif /* ndef CCRYPTOBASE_HXX */
