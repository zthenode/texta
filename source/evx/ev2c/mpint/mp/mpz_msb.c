/**
 **********************************************************************
 * Copyright (c) 1988-2005 $author$.
 *
 * This software is provided by the author and contributors ``as is'' and
 * any express or implied warranties, including, but not limited to, the
 * implied warranties of merchantability and fitness for a particular purpose
 * are disclaimed.  In no event shall the author or contributors be liable
 * for any direct, indirect, incidental, special, exemplary, or consequential
 * damages (including, but not limited to, procurement of substitute goods
 * or services; loss of use, data, or profits; or business interruption)
 * however caused and on any theory of liability, whether in contract, strict
 * liability, or tort (including negligence or otherwise) arising in any way
 * out of the use of this software, even if advised of the possibility of
 * such damage.
 *
 *   File: mpz_msb.c
 *
 * Author: $author$
 *   Date: 2/1/2005
 *
 *    $Id$
 **********************************************************************
 */

#include <mpz_msb.h>
#include <gmp-impl.h>

/**
 **********************************************************************
 * Function: mpz_get_msb
 *
 *   Author: $author$
 *     Date: 2/1/2005
 **********************************************************************
 */
mp_size_t
#if __STDC__
mpz_get_msb (unsigned char *str, mp_size_t size, mpz_srcptr x)
#else
mpz_get_msb (str, size, x)
     unsigned char *str;
     mp_size_t size;
     mpz_srcptr x;
#endif
{
  int i;
  mp_size_t s;
  mp_size_t xsize = ABS (x->_mp_size);
  mp_srcptr xp = x->_mp_d;
  mp_size_t out_bytesize;
  mp_size_t n_bytes_fill;
  mp_size_t n_bytes_remain;
  mp_size_t n_limbs_remain;
  mp_limb_t hi_limb;
  int n_bytes_in_hi_limb;

  if (xsize == 0)
    return 0;

  /* Count the bytes in most significant limb. */    
  hi_limb = xp[xsize - 1];                 
  for (i = BYTES_PER_MP_LIMB - 1; i > 0; i--)
    {
      if ((hi_limb >> i * BITS_PER_CHAR) != 0)
	break;
    }
  n_bytes_in_hi_limb = i + 1;
  n_limbs_remain = xsize - 1;
  n_bytes_remain = BYTES_PER_MP_LIMB * n_limbs_remain;
  out_bytesize =  n_bytes_in_hi_limb + n_bytes_remain;

  if (size < 1)
    size = out_bytesize;
    
  if (out_bytesize > size)
   {
    /* Truncate the number to fit inside the buffer. */
    if (n_bytes_remain < size)
      n_bytes_in_hi_limb = size - n_bytes_remain;
    else 
     {
      n_limbs_remain = size / BYTES_PER_MP_LIMB;
      n_bytes_in_hi_limb = size % BYTES_PER_MP_LIMB;
      n_bytes_remain = size - n_bytes_in_hi_limb;
      hi_limb = xp[n_limbs_remain];                 
     }
    out_bytesize = size;
   }
   
  if ((str == 0) || (out_bytesize < 1))
    return out_bytesize;
  
  if ((n_bytes_fill = size - out_bytesize) > 0)
    /* Output 0 filler above most significant byte. */
    for (s = 0; s < n_bytes_fill; s++, str++)
      *str = 0;
    
  /* Output from the most significant limb to the least significant limb,
     with each limb also output in decreasing significance order
     (big endian).  */

  /* Output the most significant limb separately, since we will only
     output some of its bytes.  */
  for (i = n_bytes_in_hi_limb - 1; i >= 0; i--, str++)
    *str = ((hi_limb >> (i * BITS_PER_CHAR)) % (1 << BITS_PER_CHAR));

  /* Output the remaining limbs.  */
  for (s = n_limbs_remain - 1; s >= 0; s--)
    {
      mp_limb_t x_limb;

      x_limb = xp[s];
      for (i = BYTES_PER_MP_LIMB - 1; i >= 0; i--, str++)
	*str = ((x_limb >> (i * BITS_PER_CHAR)) % (1 << BITS_PER_CHAR));
    }
  return out_bytesize;
}

/**
 **********************************************************************
 * Function: mpz_set_msb
 *
 *   Author: $author$
 *     Date: 2/1/2005
 **********************************************************************
 */
mp_size_t
#if __STDC__
mpz_set_msb (mpz_ptr x, const unsigned char *str, mp_size_t size)
#else
mpz_set_msb (x, str, size)
     mpz_ptr x;
     const unsigned char *str;
     mp_size_t size;
#endif
{
  int i;
  mp_size_t s;
  mp_size_t xsize;
  mp_ptr xp;
  unsigned char c;
  mp_limb_t x_limb;

  if (str == 0)
    return 0;

  xsize = (size + BYTES_PER_MP_LIMB - 1) / BYTES_PER_MP_LIMB;

  if (xsize == 0)
    {
      x->_mp_size = 0;
      return 0;
    }

  if (x->_mp_alloc < xsize)
    _mpz_realloc (x, xsize);
  xp = x->_mp_d;

  x_limb = 0;
  for (i = (size - 1) % BYTES_PER_MP_LIMB; i >= 0; i--, str++)
    {
      c = *str;
      x_limb = (x_limb << BITS_PER_CHAR) | c;
    }
  xp[xsize - 1] = x_limb;

  for (s = xsize - 2; s >= 0; s--)
    {
      x_limb = 0;
      for (i = BYTES_PER_MP_LIMB - 1; i >= 0; i--, str++)
	{
	  c = *str;
	  x_limb = (x_limb << BITS_PER_CHAR) | c;
	}
      xp[s] = x_limb;
    }

  MPN_NORMALIZE (xp, xsize);
  x->_mp_size = xsize;
  return size;
}
