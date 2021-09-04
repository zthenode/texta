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
 *   File: cio.cxx
 *
 * Author: $author$
 *   Date: 1/4/2008
 **********************************************************************
 */
#include "cio.hxx"

/**
 **********************************************************************
 * Function: OModeToPlatform
 *
 *   Author: $author$
 *     Date: 7/18/2003
 **********************************************************************
 */
eError OModeToPlatform(MODE &pmode, eOMode mode)
{
    eError error;
    int pflags;
    if (!(error = FlagsToPlatform(pflags, mode)))
        pmode = (MODE)(pflags);
    return error;
}
/**
 **********************************************************************
 * Function: SModeToPlatform
 *
 *   Author: $author$
 *     Date: 7/18/2003
 **********************************************************************
 */
eError SModeToPlatform(MODE_T &pmode, eSMode mode)
{
    eError error;
    int pmodes;
    if (!(error = ModesToPlatform(pmodes, mode)))
        pmode  = (MODE_T)(pmodes);
    return error;
}

/**
 **********************************************************************
 * Function: FlagsToPlatform
 *
 *   Author: $author$
 *     Date: 7/18/2003
 **********************************************************************
 */
eError FlagsToPlatform(int &pflags, int flags)
{
    int flag;

    pflags = 0;

    for (flag = e_FIRST_O; flag <= e_LAST_O; flag <<= 1)
    {
        if (flag & flags)
        if (FlagOnPlatform(flag))
            pflags |= FlagToPlatform(flag);
        else
        {
            pflags = flag;
            return e_ERROR_NOT_DEFINED;
        }
    }
    return e_ERROR_NONE;
}
/**
 **********************************************************************
 * Function: FlagOnPlatform
 *
 *   Author: $author$
 *     Date: 7/18/2003
 **********************************************************************
 */
int FlagOnPlatform(int flag)
{
    switch(flag)
    {
    case e_O_APPEND    : return HAS_IO_O_APPEND    ;
    case e_O_BINARY    : return HAS_IO_O_BINARY    ;
    case e_O_CREAT     : return HAS_IO_O_CREAT     ;
    case e_O_EXCL      : return HAS_IO_O_EXCL      ;
    case e_O_NONBLOCK  : return HAS_IO_O_NONBLOCK  ;
    case e_O_RANDOM    : return HAS_IO_O_RANDOM    ;
    case e_O_RDONLY    : return HAS_IO_O_RDONLY    ;
    case e_O_RDWR      : return HAS_IO_O_RDWR      ;
    case e_O_SEQUENTIAL: return HAS_IO_O_SEQUENTIAL;
    case e_O_SYNC      : return HAS_IO_O_SYNC      ;
    case e_O_TEMPORARY : return HAS_IO_O_TEMPORARY ;
    case e_O_TEXT      : return HAS_IO_O_TEXT      ;
    case e_O_TRUNC     : return HAS_IO_O_TRUNC     ;
    case e_O_WRONLY    : return HAS_IO_O_WRONLY    ;
    }
    return 0;
}
/**
 **********************************************************************
 * Function: FlagToPlatform
 *
 *   Author: $author$
 *     Date: 7/18/2003
 **********************************************************************
 */
int FlagToPlatform(int flag)
{
    switch(flag)
    {
    case e_O_APPEND    : return IO_O_APPEND    ;
    case e_O_BINARY    : return IO_O_BINARY    ;
    case e_O_CREAT     : return IO_O_CREAT     ;
    case e_O_EXCL      : return IO_O_EXCL      ;
    case e_O_NONBLOCK  : return IO_O_NONBLOCK  ;
    case e_O_RANDOM    : return IO_O_RANDOM    ;
    case e_O_RDONLY    : return IO_O_RDONLY    ;
    case e_O_RDWR      : return IO_O_RDWR      ;
    case e_O_SEQUENTIAL: return IO_O_SEQUENTIAL;
    case e_O_SYNC      : return IO_O_SYNC      ;
    case e_O_TEMPORARY : return IO_O_TEMPORARY ;
    case e_O_TEXT      : return IO_O_TEXT      ;
    case e_O_TRUNC     : return IO_O_TRUNC     ;
    case e_O_WRONLY    : return IO_O_WRONLY    ;
    }
    return 0;
}
/**
 **********************************************************************
 * Function: ModesToPlatform
 *
 *   Author: $author$
 *     Date: 7/18/2003
 **********************************************************************
 */
eError ModesToPlatform(int &pmodes, int modes)
{
    int mode;

    pmodes = 0;

    for (mode = e_FIRST_S; mode <= e_LAST_S; mode <<= 1)
    {
        if (mode & modes)
        if (ModeOnPlatform(mode))
            pmodes |= ModeToPlatform(mode);
        else
        {
            pmodes = mode;
            return e_ERROR_NOT_DEFINED;
        }
    }
    return e_ERROR_NONE;
}
/**
 **********************************************************************
 * Function: ModeOnPlatform
 *
 *   Author: $author$
 *     Date: 7/18/2003
 **********************************************************************
 */
int ModeOnPlatform(int mode)
{
    switch(mode)
    {
    case e_S_IREAD  : return HAS_IO_S_IREAD ;
    case e_S_IWRITE : return HAS_IO_S_IWRITE;
    case e_S_IEXEC  : return HAS_IO_S_IEXEC ;
    case e_S_IRGRP  : return HAS_IO_S_IRGRP ;
    case e_S_IWGRP  : return HAS_IO_S_IWGRP ;
    case e_S_IXGRP  : return HAS_IO_S_IXGRP ;
    case e_S_IROTH  : return HAS_IO_S_IROTH ;
    case e_S_IWOTH  : return HAS_IO_S_IWOTH ;
    case e_S_IXOTH  : return HAS_IO_S_IXOTH ;
    }
    return 0;
}
/**
 **********************************************************************
 * Function: ModeToPlatform
 *
 *   Author: $author$
 *     Date: 7/18/2003
 **********************************************************************
 */
int ModeToPlatform(int mode)
{
    switch(mode)
    {
    case e_S_IREAD  : return IO_S_IREAD ;
    case e_S_IWRITE : return IO_S_IWRITE;
    case e_S_IEXEC  : return IO_S_IEXEC ;
    case e_S_IRGRP  : return IO_S_IRGRP ;
    case e_S_IWGRP  : return IO_S_IWGRP ;
    case e_S_IXGRP  : return IO_S_IXGRP ;
    case e_S_IROTH  : return IO_S_IROTH ;
    case e_S_IWOTH  : return IO_S_IWOTH ;
    case e_S_IXOTH  : return IO_S_IXOTH ;
    }
    return 0;
}
