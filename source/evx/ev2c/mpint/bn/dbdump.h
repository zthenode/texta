/*
 * dbdump.h
 *
 * $author$
 *
 * 6/17/98
 */
#ifndef DBDUMP_H
#define DBDUMP_H

#ifndef DBDUMP_COLS
#define DBDUMP_COLS 32
#endif

#ifndef DBPRINTF
#define dbdump(buff,bytes)
#else
static void dbdump(const void *buff,unsigned long bytes)
{
    unsigned long i,j;

    for (j=0,i=0; i<bytes; i++)
    {
        if (j<DBDUMP_COLS) 
            j++;
        else 
        { 
            j=1; 
            dbprintf(("\n")); 
        }
        dbprintf(("%2.2x",((const unsigned char*)buff)[i]));
    }
    dbprintf(("\n"));
}
static void dbdump0x(const void *buff,unsigned long bytes)
{
    unsigned long i,j;

    for (j=0,i=0; i<bytes; i++)
    {
        if (j<DBDUMP_COLS) 
            j++;
        else 
        { 
            j=1; 
            dbprintf(("\n")); 
        }
        dbprintf(("0x%2.2x,",((const unsigned char*)buff)[i]));
    }
    dbprintf(("\n"));
}
#endif

#endif
