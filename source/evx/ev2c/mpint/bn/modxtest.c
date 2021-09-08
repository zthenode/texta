#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include <dbprintf.h>
#include <dbdump.h>
#include "bn_msb.h"

unsigned char g[]={
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x05,};

unsigned char n[]={
    0xc4,0x2f,0xe2,0x51,0x84,0x52,0x26,0x61,0x7e,0x78,0x1c,0x95,0x2c,0x22,0x9e,0x20,0x44,0xd3,0xbc,0x40,0xfc,0x5f,0xaa,0x58,0x34,0x33,0x38,0x8f,0x26,0x83,0xd2,0xc8,
    0x52,0x45,0xa4,0x46,0x12,0x4a,0xfa,0x6f,0x8c,0x06,0x54,0x05,0x68,0xa5,0x50,0xba,0x06,0xd1,0x00,0x49,0x96,0x08,0xa6,0xd2,0xda,0x2e,0x76,0xed,0xda,0xd2,0x6d,0x4b,};

unsigned char n1024[128] = {
  0xe1, 0xa1, 0x24, 0xe8, 0xd1, 0xb0, 0xd5, 0x81, 0xe7, 0xa5, 0x8a, 0x3b,
  0xb4, 0xb5, 0x84, 0xca, 0x71, 0x07, 0x36, 0x28, 0x67, 0x0b, 0x02, 0x1f,
  0x84, 0xc6, 0x70, 0x10, 0xed, 0xb1, 0x69, 0xa6, 0xc2, 0x1d, 0x7d, 0xe1,
  0x3f, 0xac, 0x8c, 0xd0, 0x04, 0x94, 0x9e, 0x5e, 0x47, 0xab, 0x7b, 0x2e,
  0x9f, 0x58, 0x69, 0x02, 0xb3, 0x6f, 0x4f, 0x79, 0xe6, 0x9c, 0x67, 0xb2,
  0xc7, 0x31, 0xf4, 0xeb, 0x9f, 0x83, 0xf9, 0xef, 0xec, 0x7e, 0xa4, 0x02,
  0x11, 0x11, 0x7d, 0x4f, 0x50, 0x57, 0x64, 0x3c, 0x22, 0x5c, 0x7d, 0x4d,
  0x8b, 0x41, 0xcf, 0x10, 0xf6, 0x23, 0x0f, 0x7b, 0xdf, 0xe6, 0x65, 0xff,
  0x63, 0x81, 0x25, 0x7f, 0xaa, 0x6e, 0xcd, 0x2c, 0xab, 0x91, 0xdf, 0x4d,
  0x22, 0xac, 0xc2, 0x8d, 0x78, 0x62, 0x21, 0x61, 0x73, 0xe8, 0x2b, 0x16,
  0x76, 0xa3, 0xa7, 0x2e, 0x87, 0xae, 0x32, 0x01, };
unsigned char e1024[3] = {
  0x01, 0x00, 0x01, };
unsigned char p1024[] = { 
  0xFB, 0xA4, 0xCE, 0x82, 0xCF, 0xC7, 0x2D, 0x88, 0xA5, 0xA2, 0x40, 
  0x9D, 0x9C, 0x64, 0x9F, 0x82, 0xBF, 0x5A, 0xD2, 0xCF, 0xFE, 0x7B, 
  0xDB, 0x31, 0x0E, 0xD7, 0x39, 0x6B, 0xC4, 0xFA, 0xC5, 0xEC, 0xAE, 
  0xC1, 0x38, 0xBF, 0x63, 0x10, 0x49, 0x53, 0x5A, 0xB3, 0x21, 0xA3, 
  0x57, 0x0E, 0x3D, 0xD6, 0xE6, 0x10, 0xD4, 0x1D, 0x34, 0x8B, 0xBD, 
  0x5A, 0x59, 0x09, 0xB7, 0x8B, 0x4D, 0xE3, 0x75, 0x39, };
unsigned char q1024[] = { 
  0xE5, 0x89, 0x0D, 0x34, 0xD1, 0x6C, 0x2B, 0xAE, 0x59, 0x96, 0x3B, 
  0x10, 0xA0, 0x46, 0x98, 0x41, 0x6F, 0x3F, 0x6B, 0x9B, 0xC3, 0x0E, 
  0x84, 0x30, 0x3C, 0xDE, 0xEF, 0x38, 0xD3, 0x76, 0x16, 0x89, 0x14, 
  0xD8, 0x05, 0xF4, 0xB4, 0x3A, 0xE5, 0x92, 0x01, 0xBB, 0xD7, 0x79, 
  0x2A, 0x46, 0xFE, 0xD3, 0x60, 0x28, 0x16, 0x94, 0xF0, 0xA5, 0x58, 
  0x8D, 0x9A, 0x8D, 0x16, 0x9C, 0xE8, 0x72, 0xAB, 0x09, };
unsigned char dmp1024[] = { 
  0xC3, 0xC9, 0x90, 0x5B, 0x3A, 0xA9, 0xEF, 0x85, 0x77, 0xC9, 0x6B, 
  0x98, 0xB5, 0x4B, 0x9C, 0xC7, 0xAF, 0x76, 0x4C, 0xBB, 0x43, 0x76, 
  0xBE, 0x2D, 0xC7, 0x2C, 0x31, 0x22, 0xE6, 0x59, 0x6E, 0x91, 0x1D, 
  0xCE, 0x7C, 0x06, 0x7C, 0x5E, 0xF9, 0x8D, 0xFE, 0xED, 0x8C, 0x68, 
  0x77, 0x9D, 0x3F, 0x03, 0xEA, 0x70, 0x81, 0x78, 0x4F, 0x9F, 0xC1, 
  0xAD, 0x7F, 0xC5, 0x0D, 0xA7, 0x36, 0xEC, 0x98, 0x11, };
unsigned char dmq1024[] = { 
  0x57, 0xCB, 0x4B, 0x04, 0xD7, 0xD1, 0x63, 0x07, 0xC5, 0xF6, 0x63, 
  0x53, 0x21, 0xAA, 0xBE, 0xD3, 0xD0, 0x64, 0x56, 0x99, 0x76, 0x4B, 
  0x18, 0x1E, 0x87, 0x39, 0xD2, 0x10, 0x4F, 0x39, 0x8C, 0xB7, 0x14, 
  0x04, 0xE8, 0x8A, 0x47, 0x61, 0x7B, 0xAB, 0x94, 0x04, 0x30, 0x0F, 
  0x85, 0x2F, 0x30, 0x8A, 0xD2, 0xED, 0xA2, 0x6D, 0x87, 0x7A, 0x06, 
  0xDB, 0xEA, 0xB0, 0x6A, 0x64, 0xCB, 0xB8, 0x08, 0x59, };
unsigned char iqmp1024[] = { 
  0x5F, 0xCF, 0xE7, 0x73, 0x40, 0xCA, 0xDF, 0x66, 0x0F, 0xF3, 0x2A, 
  0x38, 0x68, 0xCC, 0xBD, 0xF9, 0x59, 0xC9, 0xBB, 0xD8, 0x5D, 0xAA, 
  0x3C, 0x86, 0x83, 0xA1, 0xBA, 0x8B, 0xAE, 0x94, 0x24, 0x54, 0x16, 
  0xF4, 0xA0, 0x21, 0x07, 0x83, 0x71, 0xDC, 0xF2, 0x35, 0xFD, 0x2D, 
  0xD5, 0x7F, 0x92, 0xBF, 0xFB, 0x74, 0x8D, 0xB5, 0xB2, 0xBA, 0x63, 
  0xA8, 0x51, 0xE0, 0xFF, 0xBF, 0x9F, 0x11, 0xEA, 0x08, };
unsigned char i1024[] = { 
  0xA1, 0xA2, 0xA7, 0x73, 0xDD, 0xF2, 0xE1, 0x9D, 0x74, 0x09, 0xEA, 
  0x2C, 0x47, 0x61, 0xD6, 0x8B, 0x71, 0xFB, 0x79, 0xD8, 0x2C, 0x9A, 
  0x94, 0xCA, 0xD3, 0x7F, 0x2B, 0xD3, 0x3E, 0x3A, 0xC0, 0x11, 0x06, 
  0x2E, 0xDF, 0xD8, 0x22, 0x92, 0x5D, 0x1A, 0xE4, 0x6B, 0x60, 0x85, 
  0x1E, 0x1D, 0xAE, 0x2A, 0xD6, 0x78, 0xB2, 0xF5, 0x97, 0x84, 0x5E, 
  0xE7, 0x2B, 0x5F, 0x67, 0x94, 0x9F, 0x19, 0xAC, 0xB4, 0xC8, 0x5C, 
  0xB5, 0x00, 0xC6, 0x04, 0xD4, 0xDD, 0xE8, 0xE9, 0xCD, 0x8E, 0xBE, 
  0xE0, 0xB1, 0x24, 0xB3, 0x7D, 0x76, 0x34, 0xFF, 0x67, 0x2D, 0x69, 
  0x3F, 0xAD, 0x25, 0xAD, 0x71, 0xE2, 0x8D, 0x4F, 0x25, 0xDC, 0xF6, 
  0x59, 0xB1, 0xD6, 0x91, 0x88, 0xEF, 0xC0, 0x11, 0xA8, 0x37, 0xAF, 
  0xD3, 0xB7, 0x2F, 0xBE, 0x12, 0xC7, 0x2E, 0x79, 0xCE, 0x3E, 0x3A, 
  0xAE, 0xE2, 0xD7, 0xAE, 0x7C, 0x3F, 0x78, };
unsigned char ans1024[] = {
  0x00, 0x02, 0x2f, 0xa1, 0x5c, 0xd8, 0xa6, 0x1f, 0x63, 0x9f,
  0x5a, 0xb7, 0xbd, 0x5b, 0xff, 0x2f, 0x14, 0x62, 0xec, 0x7e,
  0xa7, 0x6b, 0x85, 0xdb, 0x3e, 0x08, 0x7b, 0x92, 0x61, 0xd4,
  0x9f, 0x09, 0x6c, 0xc0, 0x1f, 0xba, 0xee, 0xd8, 0x7f, 0x68,
  0xea, 0xc2, 0x1b, 0x62, 0xaa, 0x6b, 0xa4, 0x7e, 0x72, 0xda,
  0x80, 0x2d, 0xa0, 0x89, 0xcf, 0xcb, 0x88, 0xb2, 0x33, 0xc9,
  0x11, 0xa3, 0x3c, 0x60, 0x40, 0xfe, 0xa0, 0xf1, 0x84, 0x5b,
  0xac, 0x34, 0x49, 0xcf, 0x24, 0xb6, 0x03, 0xe5, 0x4e, 0x1d,
  0x1c, 0x0d, 0xd4, 0x90, 0xa6, 0x66, 0x64, 0xa4, 0x73, 0xce,
  0x9f, 0x7f, 0xab, 0xb0, 0x57, 0xc8, 0x0d, 0x62, 0x9c, 0x72,
  0xc3, 0x92, 0xaa, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03,
  0x03, 0x00, 0x0c, 0x14, 0x7a, 0xf1, 0x09, 0x7c, 0x24, 0x24,
  0x5d, 0xa9, 0x81, 0xc6, 0xdf, 0x6f, 0xf8, 0xda, };

unsigned char x[255];

void main(int argc,char **argv)
{
    BN_CTX *ctx;
    BIGNUM *a,*b,*c,*m,*e;
    unsigned i;

    if ((ctx=BN_CTX_new())!=NULL)
    {
        if ((a=BN_new())!=NULL)
        if ((b=BN_new())!=NULL)
        if ((c=BN_new())!=NULL)
        if ((m=BN_new())!=NULL)
        if ((e=BN_new())!=NULL)
        {
            BN_set_msb(a,g,sizeof(n));
            BN_set_msb(m,n,sizeof(n));
            BN_set_msb(e,n,sizeof(n));
//            b=BN_mod_inverse(e,m,ctx);
//            BN_mod_exp_mont(b,a,e,m,ctx,NULL);
            BN_mod_exp(b,a,e,m,ctx);
            BN_get_msb(b,x,sizeof(n));
            dbdump(x,sizeof(n));
        }
        BN_CTX_free(ctx);
    }
}