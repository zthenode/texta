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
 *   File: ccrypto.hxx
 *
 * Author: $author$
 *   Date: $date$
 **********************************************************************
 */
#ifndef _CCRYPTO_HXX
#define _CCRYPTO_HXX

#include "cbase.hxx"
#include "error.hxx"

/**
 **********************************************************************
 *  Class: CCrypto
 *
 * Author: $author$
 *   Date: $date$
 **********************************************************************
 */
class CCrypto
: public CBase
{
public:
    typedef CBase CExtends;

    /**
     **********************************************************************
     *   Enum: 
     *
     * Author: $author$
     *   Date: $date$
     **********************************************************************
     */
    enum
    {
        FIRST_ERROR = ::FIRST_ERROR,

        _ERROR_KEY_SIZE = FIRST_ERROR,
        _ERROR_KEY_SIZE_UNDER,
        _ERROR_KEY_SIZE_OVER,

        _ERROR_IV_SIZE,
        _ERROR_IV_SIZE_UNDER,
        _ERROR_IV_SIZE_OVER,

        _ERROR_BLOCK_SIZE,
        _ERROR_BLOCK_SIZE_UNDER,
        _ERROR_BLOCK_SIZE_OVER,

        NEXT_ERROR,
        LAST_ERROR = NEXT_ERROR-1,

        ERRORS = LAST_ERROR-FIRST_ERROR+1
    };

    /**
     **********************************************************************
     * Function: LSBToU32
     *
     * Author: $author$
     *   Date: $date$
     **********************************************************************
     */
    static inline uint32 LSBToU32(const BYTE *buff)
	{
		return (((((((uint32)buff[3])<<8)|buff[2])<<8)|buff[1])<<8)|buff[0];
	}
    /**
     **********************************************************************
     * Function: U32ToLSB
     *
     * Author: $author$
     *   Date: $date$
     **********************************************************************
     */
    static inline BYTE *U32ToLSB(BYTE *buff, uint32 value)
    {
        *(buff)=(BYTE)(value&255);
        *(++buff)=(BYTE)((value>>=8)&255);
        *(++buff)=(BYTE)((value>>=8)&255);
        *(++buff)=(BYTE)((value>>=8)&255);
        return buff;
    }
    /**
     **********************************************************************
     * Function: MSBToU32
     *
     * Author: $author$
     *   Date: $date$
     **********************************************************************
     */
    static inline uint32 MSBToU32(const BYTE *buff)
    {
        return (((((((uint32)buff[0])<<8)|buff[1])<<8)|buff[2])<<8)|buff[3];
    }
    /**
     **********************************************************************
     * Function: U32ToMSB
     *
     * Author: $author$
     *   Date: $date$
     **********************************************************************
     */
    static inline BYTE *U32ToMSB(BYTE *buff, uint32 value)
    {
        *(buff+=3)=(BYTE)(value&255);
        *(--buff)=(BYTE)((value>>=8)&255);
        *(--buff)=(BYTE)((value>>=8)&255);
        *(--buff)=(BYTE)((value>>=8)&255);
        return buff;
    }
    /**
     **********************************************************************
     * Function: Copy8
     *
     * Author: $author$
     *   Date: $date$
     **********************************************************************
     */
    static inline BYTE *Copy8(BYTE *to, const BYTE *from)
    {
        *(to++) = *(from++);
        *(to++) = *(from++);
        *(to++) = *(from++);
        *(to++) = *(from++);
        *(to++) = *(from++);
        *(to++) = *(from++);
        *(to++) = *(from++);
        *(to++) = *(from++);
        return to;
    }
    /**
     **********************************************************************
     * Function: CopyRepeat
     *
     * Author: $author$
     *   Date: $date$
     **********************************************************************
     */
    static inline BYTE *CopyRepeat
    (BYTE *to, int tosize, 
     const BYTE *from, int fromsize)
    {
        for (int i=0; i<tosize; i+=fromsize)
        for (int j=0,k=i; (k<tosize) && (j<fromsize); k++,j++)
            to[k] = from[j];
        return to;
    }
};
#endif /* _CCRYPTO_HXX */
