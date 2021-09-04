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
 *   File: ccgicatch.hxx
 *
 * Author: $author$
 *   Date: 3/17/2008
 **********************************************************************
 */
#ifndef _CCGICATCH_HXX
#define _CCGICATCH_HXX

#include "cplatform_io.h"
#include "ccgi.hxx"

#if !defined(WIN32) 
#include <strings.h>
#define stricmp strcasecmp
#endif /* !defined(WIN32) */

/**
 **********************************************************************
 *  Class: cCGICatch
 *
 * Author: $author$
 *   Date: 3/17/2008
 **********************************************************************
 */
class cCGICatch
: public cCGI
{
public:
    typedef cCGI cExtends;
    typedef cCGICatch cDerives;

    char m_buffer[1024];

    /**
     **********************************************************************
     * Constructor: cCGICatch
     *
     *      Author: $author$
     *        Date: 3/17/2008
     **********************************************************************
     */
    cCGICatch
    (const tChar* cgiNameChars="cgicatch") 
    : cExtends(cgiNameChars)
    {
    }
    /**
     **********************************************************************
     * Destructor: cCGICatch
     *
     *     Author: $author$
     *       Date: 3/17/2008
     **********************************************************************
     */
    virtual ~cCGICatch()
    {
    }
    /**
     **********************************************************************
     * Function: CGIRun
     *
     *   Author: $author$
     *     Date: 3/2/2008
     **********************************************************************
     */
    virtual int CGIRun
    (int argc,
     const char** argv,
     const char** env) 
    {
        int err = 0;
        int arg;
        eCGIEnv e;
        TLENGTH length;
        TLENGTH contentLength;
        const char* name;
        const char* value;
        FILE* file;

        OutputContentType(GetContentTypeHTML());
        OutputContentL(H1_, m_cgiNameChars, _H1, NULL_POINTER);

        OutputContentL
        (B_, "Arguments (file is ", _B,"\"",
         m_argvFilenameChars, "\"", B_, ")", _B, UL_, BR, NULL_POINTER);

        /* Get the standard argments passed to main.
         */
        for (arg=0; arg<argc; arg++)
        {
            sprintf(m_buffer, "%d", arg);
            OutputContentL
            (B_, m_argvNameChars, "[", m_buffer, "] = \"",
             _B, argv[arg], B_, "\"", _B, BR, NULL_POINTER);
        }
        OutputContentL(_UL, BR, NULL_POINTER);

        /* Write the standard argments to a file.
         */
        if (NULL != (file = SafeOpenFile
            (m_argvFilenameChars, m_argvNameChars)))
        {
            for (arg=0; arg<argc; arg++)
            {
                fprintf
                (file, "%s[%d]=%s\n", 
                 m_argvNameChars, arg, argv[arg]);
            }

            fclose(file);
        }

        OutputContentL
        (B_, "Environment (file is ", _B,"\"",
         m_envFilenameChars, "\"", B_, ")", _B, UL_, BR, NULL_POINTER);

        /* Get the CGI environment variables.
         */
        for (e=e_FIRST_CGI_ENV; e<=e_LAST_CGI_ENV; e++)
        {
            if ((name = CGIEnvName(length, e)))
            if ((value = CGIEnv(length, e)))
            OutputContentL(B_, name, " = \"", _B, value, B_, "\"", _B, BR, NULL_POINTER);
        }
        OutputContentL(_UL, BR, NULL_POINTER);

        /* Write the CGI environment variables to a file.
         */
        if ((name = CGIEnvName(length, e_FIRST_CGI_ENV)))
        if (NULL != (file = SafeOpenFile(m_envFilenameChars, name)))
        {
            for (e=e_FIRST_CGI_ENV; e<=e_LAST_CGI_ENV; e++)
            {
                if ((name = CGIEnvName(length, e)))
                if ((value = CGIEnv(length, e)))
                    fprintf(file, "%s=%s\n", name, value);
            }
            fclose(file);
        }

        if ((value = CGIEnv(length, e_CGI_ENV_REQUEST_METHOD)))
        if ((name = GetRequestMethodName
            (length, e_HTTP_REQUEST_METHOD_POST)))
        if (!stricmp(name, value))
        if ((name = CGIEnvName(length, e_CGI_ENV_CONTENT_LENGTH)))
        if ((value = CGIEnvValue(length, e_CGI_ENV_CONTENT_LENGTH)))
        if (0 != (contentLength = GetContentLength()))
        {
            OutputContentL
            (B_, m_stdinNameChars, " (file is \"",
             _B, m_stdinFilenameChars, B_, "\")", _B, BR, NULL_POINTER);

            /* Write stdin to a file.
             */
            if (NULL != (file = SafeOpenFile(m_stdinFilenameChars, name)))
            {
                fprintf(file, "%s=%s\n", name, value);

#if defined(WIN32)
                /* Set the file mode to binary for WIN32.
                 */
                if (0 <= _setmode(_fileno(stdin), _O_BINARY))
                if (0 <= _setmode(_fileno(file), _O_BINARY))
#endif /* defined(WIN32) */
                do
                {
                    length = sizeof(m_buffer);

                    if (0 < contentLength)
                    if (contentLength < length)
                        length = contentLength;

                    if (0 >= (length = (TLENGTH)(fread
                        (m_buffer, 1, length, stdin))))
                        break;

                    if (0 >= (length = (TLENGTH)(fwrite
                        (m_buffer, 1, length, file))))
                        break;

                    if (0 < contentLength)
                        contentLength -= length;
                }
                while (0 != contentLength);
                fclose(file);
            }
        }
        return err;
    }
    /**
     **********************************************************************
     * Function: SafeOpenFile
     *
     *   Author: $author$
     *     Date: 3/17/2008
     **********************************************************************
     */
    FILE* SafeOpenFile
    (const char* filename, const char* pattern)
    {
        bool cantOpen = false;
        size_t count, length;
        FILE* file;
        char c;

        if (NULL != (file = fopen(filename, "r")))
        {
            if (0 >= (length = strlen(pattern)))
                cantOpen = true;
            else
            for (cantOpen = false; 0 < length; --length)
            {
                if (0 < (count = fread(&c, 1, 1, file)))
                if (c == *(pattern++))
                    continue;

                cantOpen = true;
                break;
            }

            fclose(file);

            if (cantOpen)
                return NULL;
        }

        file = fopen(filename, "w");
        return file;
    }
};
#endif /* _CCGICATCH_HXX */
