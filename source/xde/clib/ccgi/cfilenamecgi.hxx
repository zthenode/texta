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
 *   File: cfilenamecgi.hxx
 *
 * Author: $author$
 *   Date: 5/1/2008
 **********************************************************************
 */
#ifndef _CFILENAMECGI_HXX
#define _CFILENAMECGI_HXX

#include "cplatform_path.h"
#include "ccgi.hxx"
#include "csplitter.hxx"

#define DEFAULT_FILENAMECGI_FILENAME_NAME_SUFFIX "_filename"
#define DEFAULT_FILENAMECGI_URI_NAME_SUFFIX "_uri"

#define DEFAULT_CONTENT_TYPE_NAME "content_type"

/**
 **********************************************************************
 *  Class: cFileNameCGI
 *
 * Author: $author$
 *   Date: 5/1/2008
 **********************************************************************
 */
class cFileNameCGI
: public cCGI
{
public:
    typedef cCGI cExtends;
    typedef cFileNameCGI cDerives;

    tChar m_directorySeparatorChar;
    tChar m_fileNameExtensionSeparatorChar;
    cCharSplitter m_splitter;
    
    const tChar* m_contentTypeNameChars;
    tCharString m_contentTypeName;

    const char* m_fileNameChars;
    cCharString m_fileName;

    /**
     **********************************************************************
     * Constructor: cFileNameCGI
     *
     *      Author: $author$
     *        Date: 5/1/2008
     **********************************************************************
     */
    cFileNameCGI
    (const tChar* cgiNameChars) 
    : cExtends(cgiNameChars),

      m_directorySeparatorChar
      (PLATFORM_DIRECTORY_SEPARATOR_CHAR),

      m_fileNameExtensionSeparatorChar
      (PLATFORM_EXTENSION_SEPARATOR_CHAR),

      m_contentTypeNameChars
      (DEFAULT_CONTENT_TYPE_NAME),

      m_fileNameChars(0)
    {
    }

    /**
     **********************************************************************
     * Function: GetContentTypeParameter
     *
     *   Author: $author$
     *     Date: 12/30/2008
     **********************************************************************
     */
    virtual const tChar* 
    GetContentTypeParameter(tLength& length) 
    {
        const tChar* chars = 0;
        const tChar* contentType;
        cHTTPFormFieldReference f;
        int unequal;

        if (m_contentTypeNameChars)
        if (m_contentTypeNameChars[0])
        {
        DBT("() find form field \"%s\"...\n", m_contentTypeNameChars);
        if ((f = m_formFields.FindField(m_contentTypeNameChars)))
        {
        DBT("() ...found form field \"%s\"\n", m_contentTypeNameChars);
        if ((chars = f->GetValue(length)))
        {
        DBT("() ...found form field \"%s\"=\"%s\"[%d]\n", m_contentTypeNameChars, chars, length);
        if (0 >= length)
            chars = 0;
        else
        if ((contentType = GetContentTypeHTML()))
        if (!(unequal = f->CompareValue(contentType)))
            chars = contentType;
        }
        }
        }
        return chars;
    }

    /**
     **********************************************************************
     * Function: GetFileName
     *
     *   Author: $author$
     *     Date: 3/26/2008
     **********************************************************************
     */
    virtual const tChar* 
    GetFileName(tLength& length) 
    {
        const tChar* chars = CGIEnvHasChars
        (length, e_CGI_ENV_PATH_TRANSLATED);
        return chars;
    }

    /**
     **********************************************************************
     * Function: GetURIBase
     *
     *   Author: $author$
     *     Date: 5/3/2008
     **********************************************************************
     */
    virtual const tChar* 
    GetURIBase
    (tLength& length, 
     const tChar* uriChars, tLength uriLength=-1) 
    {
        const tChar* chars = 0;

        if ((chars = m_splitter.RightOf
            (length, m_fileNameExtensionSeparatorChar, 
             uriChars, uriLength)))
        {
            length = (tLength)(chars - uriChars - 1);
            return chars;
        }
        length = 0;
        return 0;
    }

    /**
     **********************************************************************
     * Function: GetFileNameBase
     *
     *   Author: $author$
     *     Date: 5/2/2008
     **********************************************************************
     */
    virtual const tChar* 
    GetFileNameBase
    (tLength& length, 
     const tChar* fileNameChars, tLength fileNameLength=-1) 
    {
        const tChar* chars = 0;

        if ((chars = m_splitter.RightOf
            (length, m_fileNameExtensionSeparatorChar, 
             fileNameChars, fileNameLength)))
        {
            length = (tLength)(chars - fileNameChars - 1);
            return chars;
        }
        length = 0;
        return 0;
    }
    /**
     **********************************************************************
     * Function: GetAbsoluteFileName
     *
     *   Author: $author$
     *     Date: 3/26/2008
     **********************************************************************
     */
    virtual const tChar* 
    GetAbsoluteFileName
    (tLength& length, cCharString& fileName,
     const tChar* fileNameChars, const tChar* absoluteFileNameChars) 
    {
        const tChar* chars = fileNameChars;
        const tChar* absolutePathChars;
        tLength absolutePathLength;
        tChar separatorChar;

        if (absoluteFileNameChars)

        if (!(absolutePathChars = GetAbsoluteFileNamePath
            (absolutePathLength, separatorChar, fileNameChars)))

        if ((absolutePathChars = GetAbsoluteFileNamePath
            (absolutePathLength, separatorChar, absoluteFileNameChars)))

        if (0 < (absolutePathLength = fileName.Assign
            (absolutePathChars, absolutePathLength)))
        if (0 < (absolutePathLength = fileName.Append(&separatorChar, 1)))
        if (0 < (absolutePathLength = fileName.Append(fileNameChars)))
        if ((absolutePathChars = fileName.HasChars(absolutePathLength)))
        {
            chars = absolutePathChars;
            length = absolutePathLength;
        }
        return chars;
    }
    /**
     **********************************************************************
     * Function: GetAbsoluteFileNamePath
     *
     *   Author: $author$
     *     Date: 3/26/2008
     **********************************************************************
     */
    virtual const tChar* 
    GetAbsoluteFileNamePath
    (tLength& length, tChar& separatorChar,
     const tChar* absoluteFileNameChars) 
    {
        const tChar* chars = 0;
        const tChar* relativeFileNameChars = 0;
        tLength relativeLength;

        if (absoluteFileNameChars)

        if ((relativeFileNameChars = m_splitter.RightOf
            (relativeLength, 
             PLATFORM_DIRECTORY_SEPARATOR_CHAR, absoluteFileNameChars)))
             separatorChar = PLATFORM_DIRECTORY_SEPARATOR_CHAR;
        else
        if ((relativeFileNameChars = m_splitter.RightOf
            (relativeLength, 
             FOREIGN_DIRECTORY_SEPARATOR_CHAR, absoluteFileNameChars)))
             separatorChar = FOREIGN_DIRECTORY_SEPARATOR_CHAR;
        else
        if (PLATFORM_VOLUME_SEPARATOR_CHAR)
        if ((relativeFileNameChars = m_splitter.RightOf
            (relativeLength, 
             PLATFORM_VOLUME_SEPARATOR_CHAR, absoluteFileNameChars)))
             separatorChar = PLATFORM_VOLUME_SEPARATOR_CHAR;

        if (relativeFileNameChars)
        if (0 < (length = (tLength)(relativeFileNameChars - absoluteFileNameChars -1)))
            chars = absoluteFileNameChars;

        return chars;
    }

    /**
     **********************************************************************
     * Function: UnableToOpenFileName
     *
     *   Author: $author$
     *     Date: 5/3/2008
     **********************************************************************
     */
    virtual int UnableToOpenFileName
    (const tChar* fileNameChars, int err=1) 
    {
        SetContentType(GetContentTypeHTML());
        OutputContentL
        (H1_, m_cgiNameChars, _H1, 
         B_, "unable to open filename \"", 
         _B,fileNameChars, B_, "\"", _B, BR, NULL_POINTER);
        return err;
    }

    /**
     **********************************************************************
     * Function: RespondError
     *
     *   Author: $author$
     *     Date: 5/20/2008
     **********************************************************************
     */
    virtual int RespondError
    (const tChar* errorChars, int err=1) 
    {
        SetContentType(GetContentTypeHTML());
        OutputContentL
        (H1_, m_cgiNameChars, _H1, 
         B_, errorChars, _B, BR, NULL_POINTER);
        return err;
    }

    /**
     **********************************************************************
     * Function: RespondFormFields
     *
     *   Author: $author$
     *     Date: 5/21/2008
     **********************************************************************
     */
    virtual int RespondFormFields(int err=1) 
    {
        tLength length;
        const tChar* name;
        const tChar* value;
        cHTTPFormFieldReference f;
        cHTTPFormFieldIterator i,end;

        SetContentType(GetContentTypeHTML());

        OutputContentL
        (B_, "Form fields", _B, UL_, BR, NULL_POINTER);

        if ((i = m_formFields.begin()) 
            != (end = m_formFields.end()))
        {
            do
            {
                if ((f = *i))
                if ((name = f->GetName(length)))
                if ((value = f->GetValue(length)))
                OutputContentL(B_, name, " = \"", _B, value, B_, "\"", _B, BR, NULL_POINTER);
            }
            while ((++i) != end);
        }
        OutputContentL(_UL, BR, NULL_POINTER);

        return err;
    }
    /**
     **********************************************************************
     * Function: RespondCGIEnv
     *
     *   Author: $author$
     *     Date: 5/21/2008
     **********************************************************************
     */
    virtual int RespondCGIEnv(int err=1) 
    {
        eCGIEnv e;
        tLength length;
        const tChar* name;
        const tChar* value;

        OutputContentL
        (B_, "Environment variables", _B, UL_, BR, NULL_POINTER);

        /* Get the CGI environment variables.
         */
        for (e=e_FIRST_CGI_ENV; e<=e_LAST_CGI_ENV; e++)
        {
            if ((name = CGIEnvName(length, e)))
            if ((value = CGIEnv(length, e)))
            OutputContentL(B_, name, " = \"", _B, value, B_, "\"", _B, BR, NULL_POINTER);
        }
        OutputContentL(_UL, BR, NULL_POINTER);

        return err;
    }
    /**
     **********************************************************************
     * Function: RespondArg
     *
     *   Author: $author$
     *     Date: 5/21/2008
     **********************************************************************
     */
    virtual int RespondArg
    (int argc,
     const tChar** argv,
     const tChar** env,
     int err=1) 
    {
        int arg;
        char buffer[32];

        OutputContentL
        (B_, "Arguments", _B, UL_, BR, NULL_POINTER);

        /* Get the standard argments passed to main.
         */
        for (arg=0; arg<argc; arg++)
        {
            sprintf(buffer, "%d", arg);
            OutputContentL
            (B_, m_argvNameChars, "[", buffer, "] = \"",
             _B, argv[arg], B_, "\"", _B, BR, NULL_POINTER);
        }
        OutputContentL(_UL, BR, NULL_POINTER);
        return err;
    }
};
#endif /* _CFILENAMECGI_HXX */
