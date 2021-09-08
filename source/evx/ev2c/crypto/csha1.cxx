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
 *   File: csha1.cxx
 *
 * Author: $author$
 *   Date: $date$
 **********************************************************************
 */

#include "csha1.hxx"

#define ROTATE(a,n) (((a)<<(n))|(((a)&0xffffffff)>>(32-(n))))

#define K_00_19 0x5a827999L
#define K_20_39 0x6ed9eba1L
#define K_40_59 0x8f1bbcdcL
#define K_60_79 0xca62c1d6L

/* As  pointed out by Wei Dai <weidai@eskimo.com>, F() below can be
 * simplified to the code in F_00_19.  Wei attributes these optimisations
 * to Peter Gutmann's SHS code, and he attributes it to Rich Schroeppel.
 * #define F(x,y,z) (((x) & (y))  |  ((~(x)) & (z)))
 * I've just become aware of another tweak to be made, again from Wei Dai,
 * in F_40_59, (x&a)|(y&a) -> (x|y)&a
 */
#define F_00_19(b,c,d) ((((c) ^ (d)) & (b)) ^ (d)) 
#define F_20_39(b,c,d) ((b) ^ (c) ^ (d))
#define F_40_59(b,c,d) (((b) & (c)) | (((b)|(c)) & (d))) 
#define F_60_79(b,c,d) F_20_39(b,c,d)

#define UPDATE(a,i) \
	(a)=(X[(i)&0x0f]^X[((i)+2)&0x0f]^X[((i)+8)&0x0f]^X[((i)+13)&0x0f]); \
	X[(i)&0x0f]=(a)=ROTATE((a),1);

#define BODY_00_15(i,a,b,c,d,e,f) \
    (f)=X[i]+(e)+K_00_19+ROTATE((a),5)+F_00_19((b),(c),(d)); \
    (b)=ROTATE((b),30);

#define BODY_16_19(i,a,b,c,d,e,f) \
    UPDATE(f,i); \
    (f)+=(e)+K_00_19+ROTATE((a),5)+F_00_19((b),(c),(d)); \
    (b)=ROTATE((b),30);

#define BODY_20_39(i,a,b,c,d,e,f) \
    UPDATE(f,i); \
    (f)+=(e)+K_20_39+ROTATE((a),5)+F_20_39((b),(c),(d)); \
    (b)=ROTATE((b),30);

#define BODY_40_59(i,a,b,c,d,e,f) \
    UPDATE(f,i); \
    (f)+=(e)+K_40_59+ROTATE((a),5)+F_40_59((b),(c),(d)); \
    (b)=ROTATE((b),30);

#define BODY_60_79(i,a,b,c,d,e,f) \
    UPDATE(f,i); \
    (f)=X[(i)&0x0f]+(e)+K_60_79+ROTATE((a),5)+F_60_79((b),(c),(d)); \
    (b)=ROTATE((b),30);

/**
 **********************************************************************
 *  Class: CSHA1
 *
 * Author: $author$
 *   Date: $date$
 **********************************************************************
 */

/**
 **********************************************************************
 * Function: CSHA1::Initial
 *
 * Author: $author$
 *   Date: $date$
 *
 * Start SHA accumulation.  Set bit count to 0 and buffer to mysterious
 * initialization constants.
 **********************************************************************
 */
void CSHA1::Initial() 
{
    m_A = 0x67452301L;
    m_B = 0xefcdab89L;
    m_C = 0x98badcfeL;
    m_D = 0x10325476L;
    m_E = 0xc3d2e1f0L;
    m_L = 0;
    m_H = 0;
}
/**
 **********************************************************************
 * Function: CSHA1::Final
 *
 * Author: $author$
 *   Date: $date$
 *
 * Final wrapup - pad to 64-byte boundary with the bit pattern 
 * 1 0* (64-bit count of bits processed, MSB-first)
 **********************************************************************
 */
void CSHA1::Final() 
{
    unsigned count;
    BYTE *p;

    /* Compute number of bytes mod 64 
     */
    count = (m_L >> 3) & 0x3F;

    /* Set the first char of padding to 0x80.  This is safe since there is
     * always at least one byte free 
     */
    p = m_in + count;
    *p++ = 0x80;

    /* Bytes of padding needed to make 64 bytes 
     */
    count = 64 - 1 - count;

    /* Pad out to 56 mod 64 
     */
    if (count < 8) 
    {
	    /* Two lots of padding:  Pad the first block to 64 bytes 
         */
	    memset(p, 0, count);
	    Transform();

	    /* Now fill the next block with 56 bytes 
         */
	    memset(m_in, 0, 56);
    } 
    else 
    {
	    /* Pad block to 56 bytes 
         */
	    memset(p, 0, count - 8);
    }

    /* Append length in bits and transform 
     */
    U32ToMSB(m_in + 56, m_H);
    U32ToMSB(m_in + 60, m_L);
    Transform();

    U32ToMSB(m_hash, m_A);
    U32ToMSB(m_hash + 4, m_B);
    U32ToMSB(m_hash + 8, m_C);
    U32ToMSB(m_hash + 12, m_D);
    U32ToMSB(m_hash + 16, m_E);
    Initial();
}
/**
 **********************************************************************
 * Function: CSHA1::Update
 *
 * Author: $author$
 *   Date: $date$
 *
 * Update context to reflect the concatenation of another buffer
 * of bytes.
 **********************************************************************
 */
void CSHA1::Update(const BYTE *in, unsigned inlen) 
{
    uint32 t;
    BYTE *p;

    /* Update bitcount 
     */
    t = m_L;

    if ((m_L = (t + (inlen << 3)) & 0xffffffff) < t)
        /* Carry from low to high 
         */
	    m_H++;

    m_H += inlen >> 29;

    /* Bytes already in data 
     */
    t = (t >> 3) & 0x3f;

    /* Handle any leading odd-sized chunks 
     */
    if (t) 
    {
        p = m_in + t;
	    t = 64 - t;

	    if (inlen < t) 
        {
	        memcpy(p, in, inlen);
	        return;
	    }

	    memcpy(p, in, t);
	    Transform();
	    in += t;
	    inlen -= t;
    }

    /* Process data in 64-byte chunks 
     */
    while (inlen >= 64) 
    {
	    memcpy(m_in, in, 64);
	    Transform();
	    in += 64;
	    inlen -= 64;
    }

    /* Handle any remaining bytes of data. 
     */
    memcpy(m_in, in, inlen);
}
/**
 **********************************************************************
 * Function: CSHA1::Transform
 *
 * Author: $author$
 *   Date: $date$
 *
 * The core of the SHA algorithm, this alters an existing SHA hash to
 * reflect the addition of 16 longwords of new data. blocks
 * the data and converts bytes into longwords for this routine.
 **********************************************************************
 */
void CSHA1::Transform() 
{
    uint32 A,B,C,D,E,T;
    uint32 X[16];
    BYTE *p;
    unsigned i;
    
    for (p=m_in, i=0; i<16; i++, p+=4)
        X[i] = MSBToU32(p);

    A = m_A;
    B = m_B;
    C = m_C;
    D = m_D;
    E = m_E;

    BODY_00_15( 0,A,B,C,D,E,T);
    BODY_00_15( 1,T,A,B,C,D,E);
    BODY_00_15( 2,E,T,A,B,C,D);
    BODY_00_15( 3,D,E,T,A,B,C);
    BODY_00_15( 4,C,D,E,T,A,B);
    BODY_00_15( 5,B,C,D,E,T,A);
    BODY_00_15( 6,A,B,C,D,E,T);
    BODY_00_15( 7,T,A,B,C,D,E);
    BODY_00_15( 8,E,T,A,B,C,D);
    BODY_00_15( 9,D,E,T,A,B,C);
    BODY_00_15(10,C,D,E,T,A,B);
    BODY_00_15(11,B,C,D,E,T,A);
    BODY_00_15(12,A,B,C,D,E,T);
    BODY_00_15(13,T,A,B,C,D,E);
    BODY_00_15(14,E,T,A,B,C,D);
    BODY_00_15(15,D,E,T,A,B,C);
    BODY_16_19(16,C,D,E,T,A,B);
    BODY_16_19(17,B,C,D,E,T,A);
    BODY_16_19(18,A,B,C,D,E,T);
    BODY_16_19(19,T,A,B,C,D,E);

    BODY_20_39(20,E,T,A,B,C,D);
    BODY_20_39(21,D,E,T,A,B,C);
    BODY_20_39(22,C,D,E,T,A,B);
    BODY_20_39(23,B,C,D,E,T,A);
    BODY_20_39(24,A,B,C,D,E,T);
    BODY_20_39(25,T,A,B,C,D,E);
    BODY_20_39(26,E,T,A,B,C,D);
    BODY_20_39(27,D,E,T,A,B,C);
    BODY_20_39(28,C,D,E,T,A,B);
    BODY_20_39(29,B,C,D,E,T,A);
    BODY_20_39(30,A,B,C,D,E,T);
    BODY_20_39(31,T,A,B,C,D,E);
    BODY_20_39(32,E,T,A,B,C,D);
    BODY_20_39(33,D,E,T,A,B,C);
    BODY_20_39(34,C,D,E,T,A,B);
    BODY_20_39(35,B,C,D,E,T,A);
    BODY_20_39(36,A,B,C,D,E,T);
    BODY_20_39(37,T,A,B,C,D,E);
    BODY_20_39(38,E,T,A,B,C,D);
    BODY_20_39(39,D,E,T,A,B,C);

    BODY_40_59(40,C,D,E,T,A,B);
    BODY_40_59(41,B,C,D,E,T,A);
    BODY_40_59(42,A,B,C,D,E,T);
    BODY_40_59(43,T,A,B,C,D,E);
    BODY_40_59(44,E,T,A,B,C,D);
    BODY_40_59(45,D,E,T,A,B,C);
    BODY_40_59(46,C,D,E,T,A,B);
    BODY_40_59(47,B,C,D,E,T,A);
    BODY_40_59(48,A,B,C,D,E,T);
    BODY_40_59(49,T,A,B,C,D,E);
    BODY_40_59(50,E,T,A,B,C,D);
    BODY_40_59(51,D,E,T,A,B,C);
    BODY_40_59(52,C,D,E,T,A,B);
    BODY_40_59(53,B,C,D,E,T,A);
    BODY_40_59(54,A,B,C,D,E,T);
    BODY_40_59(55,T,A,B,C,D,E);
    BODY_40_59(56,E,T,A,B,C,D);
    BODY_40_59(57,D,E,T,A,B,C);
    BODY_40_59(58,C,D,E,T,A,B);
    BODY_40_59(59,B,C,D,E,T,A);

    BODY_60_79(60,A,B,C,D,E,T);
    BODY_60_79(61,T,A,B,C,D,E);
    BODY_60_79(62,E,T,A,B,C,D);
    BODY_60_79(63,D,E,T,A,B,C);
    BODY_60_79(64,C,D,E,T,A,B);
    BODY_60_79(65,B,C,D,E,T,A);
    BODY_60_79(66,A,B,C,D,E,T);
    BODY_60_79(67,T,A,B,C,D,E);
    BODY_60_79(68,E,T,A,B,C,D);
    BODY_60_79(69,D,E,T,A,B,C);
    BODY_60_79(70,C,D,E,T,A,B);
    BODY_60_79(71,B,C,D,E,T,A);
    BODY_60_79(72,A,B,C,D,E,T);
    BODY_60_79(73,T,A,B,C,D,E);
    BODY_60_79(74,E,T,A,B,C,D);
    BODY_60_79(75,D,E,T,A,B,C);
    BODY_60_79(76,C,D,E,T,A,B);
    BODY_60_79(77,B,C,D,E,T,A);
    BODY_60_79(78,A,B,C,D,E,T);
    BODY_60_79(79,T,A,B,C,D,E);

    m_A+=E; 
    m_B+=T;
    m_C+=A;
    m_D+=B;
    m_E+=C;
}
