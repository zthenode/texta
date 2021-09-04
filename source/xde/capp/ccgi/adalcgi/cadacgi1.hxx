/**
 **********************************************************************
 * Copyright (c) 1988-2008 $author$
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
 *   File: cadacgi.hxx
 *
 * Author: $author$
 *   Date: 6/14/2008
 **********************************************************************
 */
#ifndef _CADACGI_HXX
#define _CADACGI_HXX

#include "cdocumenttemplatecgi.hxx"
#include "ccgistream.hxx"
#include "cadalexer.hxx"

#define DEFAULT_ADACGI_NAME "adacgi"

#define DEFAULT_DOCUMENT_FILENAME_EXTENSION "ada"

#define DEFAULT_DOCUMENT_FILENAME_NAME \
    DEFAULT_DOCUMENT_FILENAME_EXTENSION \
    DEFAULT_FILENAMECGI_FILENAME_NAME_SUFFIX

#define DEFAULT_TEMPLATE_FILENAME_EXTENSION \
    DEFAULT_ADACGI_NAME

#define DEFAULT_TEMPLATE_FILENAME_NAME \
    DEFAULT_TEMPLATE_FILENAME_EXTENSION \
    DEFAULT_FILENAMECGI_FILENAME_NAME_SUFFIX

#define DEFAULT_DOCUMENT_URI_NAME \
    DEFAULT_DOCUMENT_FILENAME_EXTENSION \
    DEFAULT_FILENAMECGI_URI_NAME_SUFFIX

#define DEFAULT_TEMPLATE_URI_NAME \
    DEFAULT_TEMPLATE_FILENAME_EXTENSION \
    DEFAULT_FILENAMECGI_URI_NAME_SUFFIX

#define DEFAULT_DOCUMENT_FILENAME \
    DEFAULT_ADACGI_NAME \
    PLATFORM_EXTENSION_SEPARATOR \
    DEFAULT_DOCUMENT_FILENAME_EXTENSION

#define DEFAULT_TEMPLATE_FILENAME \
    DEFAULT_ADACGI_NAME \
    PLATFORM_EXTENSION_SEPARATOR \
    DEFAULT_TEMPLATE_FILENAME_EXTENSION

#define DEFAULT_COMMENT_COLOR_CHARS "teal"
#define DEFAULT_KEYWORD_COLOR_CHARS "blue"

#define DEFAULT_BEFORE_CHARS \
    "<html><head><style type=\"text/css\">" \
    "body {color: black; }" \
    "font.comment {color: "DEFAULT_COMMENT_COLOR_CHARS"; font-style:italic; }" \
    "font.keyword {color: "DEFAULT_KEYWORD_COLOR_CHARS"; font-weight: bolder; }" \
    "font.string {color: red; }" \
    "font.char {color: red; }" \
    "font.invalid {color: red; text-decoration: underline; }" \
    "</style></head><body><pre>"
#define DEFAULT_AFTER_CHARS "</pre></body></html>"

#define DEFAULT_BEGIN_COMMENT_CHARS "<font class=\"comment\">"
#define DEFAULT_BEGIN_KEYWORD_CHARS "<font class=\"keyword\">"
#define DEFAULT_BEGIN_STRING_CHARS "<font class=\"string\">"
#define DEFAULT_BEGIN_CHAR_CHARS "<font class=\"char\">"
#define DEFAULT_BEGIN_CHARS "<font class=\"invalid\">"
#define DEFAULT_END_CHARS "</font>"

/**
 **********************************************************************
 *  Class: cAdaCGI
 *
 * Author: $author$
 *   Date: 6/14/2008
 **********************************************************************
 */
class cAdaCGI
: virtual public cAdaLexerDelegate,
  public cDocumentTemplateCGI
{
public:
    typedef cAdaLexerDelegate cImplements;
    typedef cDocumentTemplateCGI cExtends;
    typedef cAdaCGI cDerives;

    cCGIStream m_cgiStream;

    cAdaLexer::cSource m_documentSource;
    cAdaLexer m_documentLexer;

    const char* m_beforeChars;
    cCharString m_before;

    const char* m_afterChars;
    cCharString m_after;

    const char* m_beginChars;
    cCharString m_begin;

    const char* m_endChars;
    cCharString m_end;

    const char* m_beginCommentChars;
    cCharString m_beginComment;

    const char* m_beginKeywordChars;
    cCharString m_beginKeyword;

    const char* m_beginStringChars;
    cCharString m_beginString;

    const char* m_beginCharChars;
    cCharString m_beginChar;

    /**
     **********************************************************************
     * Constructor: cAdaCGI
     *
     *      Author: $author$
     *        Date: 6/14/2008
     **********************************************************************
     */
    cAdaCGI
    (const tChar* cgiNameChars=DEFAULT_ADACGI_NAME,
     const tChar* documentFileNameExtensionChars=DEFAULT_DOCUMENT_FILENAME_EXTENSION,
     const tChar* documentFileNameNameChars=DEFAULT_DOCUMENT_FILENAME_NAME,
     const tChar* documentURINameChars=DEFAULT_DOCUMENT_URI_NAME,
     const tChar* templateFileNameExtensionChars=DEFAULT_TEMPLATE_FILENAME_EXTENSION,
     const tChar* templateFileNameNameChars=DEFAULT_TEMPLATE_FILENAME_NAME,
     const tChar* templateURINameChars=DEFAULT_TEMPLATE_URI_NAME)
    : cExtends
      (documentFileNameExtensionChars,
       documentFileNameNameChars,
       documentURINameChars,
       templateFileNameExtensionChars,
       templateFileNameNameChars,
       templateURINameChars,
       cgiNameChars),

      m_cgiStream(*this),

      m_documentLexer
      (*this, m_cgiStream, 
       m_documentFile, m_documentSource),

      m_beforeChars(DEFAULT_BEFORE_CHARS),
      m_afterChars(DEFAULT_AFTER_CHARS),

      m_beginChars(DEFAULT_BEGIN_CHARS),
      m_endChars(DEFAULT_END_CHARS),

      m_beginCommentChars(DEFAULT_BEGIN_COMMENT_CHARS),
      m_beginKeywordChars(DEFAULT_BEGIN_KEYWORD_CHARS),
      m_beginStringChars(DEFAULT_BEGIN_STRING_CHARS),
      m_beginCharChars(DEFAULT_BEGIN_CHAR_CHARS) 
    {
    }

    /**
     **********************************************************************
     * Function: RunCommandOrCGI
     *
     *   Author: $author$
     *     Date: 3/2/2008
     **********************************************************************
     */
    virtual int RunCommandOrCGI
    (int argc,
     const char** argv,
     const char** env) 
    {
        int err = 0;
        eError error;
        tLength length;
        const char* documentFileNameChars;
        //const char* templateFileNameChars;
        const char* text;

        DBF("()...\n");

        SetContentType(GetContentTypeHTML());

        if (!(documentFileNameChars = GetDocumentFileName(length, false, true)))
            return MissingDocumentFileName();
/*
        if (!(templateFileNameChars = GetTemplateFileName(length, true)))
        if (!(templateFileNameChars = m_templateFileNameChars))
            return MissingTemplateFileName();
*/
        if ((error = m_documentFile.Open(documentFileNameChars)))
            return  UnableToOpenFileName(documentFileNameChars);
        else
/*
        if ((error = m_templateFile.Open(templateFileNameChars)))
        {
            m_documentFile.Close();
            return  UnableToOpenFileName(templateFileNameChars);
        }
        else
*/
        {
/*
            m_templateLexer.yylex();
            m_templateFile.Close();
*/
            if ((text = m_beforeChars))
                OutputContent(text);

            m_documentLexer.yylex();
            m_documentFile.Close();

            if ((text = m_afterChars))
                OutputContent(text);
        }
        return err;
    }

    /**
     **********************************************************************
     * Function: OnBeginComment
     *
     *   Author: $author$
     *     Date: 5/11/2008
     **********************************************************************
     */
    virtual eError OnBeginComment
    (const char* text,
     int token=-1) 
    {
        eError error = OnBegin
        (m_beginCommentChars, text, token);
        return error;
    }
    /**
     **********************************************************************
     * Function: OnEndComment
     *
     *   Author: $author$
     *     Date: 5/11/2008
     **********************************************************************
     */
    virtual eError OnEndComment
    (const char* text,
     int token=-1) 
    {
        eError error = OnEnd
        (m_endChars, text, token);
        return error;
    }

    /**
     **********************************************************************
     * Function: OnReserved
     *
     *   Author: $author$
     *     Date: 5/11/2008
     **********************************************************************
     */
    virtual eError OnReserved
    (const char* text,
     int token=-1) 
    {
        eError error = On
        (m_beginKeywordChars, m_endChars, text, token);
        return error;
    }
    /**
     **********************************************************************
     * Function: OnString
     *
     *   Author: $author$
     *     Date: 5/11/2008
     **********************************************************************
     */
    virtual eError OnString
    (const char* text,
     int token=-1) 
    {
        eError error = On
        (m_beginStringChars, m_endChars, text, token);
        return error;
    }
    /**
     **********************************************************************
     * Function: OnChar
     *
     *   Author: $author$
     *     Date: 5/11/2008
     **********************************************************************
     */
    virtual eError OnChar
    (const char* text,
     int token=-1) 
    {
        eError error = On
        (m_beginCharChars, m_endChars, text, token);
        return error;
    }

    /**
     **********************************************************************
     * Function: OnBegin
     *
     *   Author: $author$
     *     Date: 5/11/2008
     **********************************************************************
     */
    virtual eError OnBegin
    (const char* chars,
     const char* text,
     int token=-1) 
    {
        eError error = e_ERROR_NONE;
        if (chars)
            OutputContent(chars);
        OutputContent(text);
        return error;
    }
    /**
     **********************************************************************
     * Function: OnEnd
     *
     *   Author: $author$
     *     Date: 5/11/2008
     **********************************************************************
     */
    virtual eError OnEnd
    (const char* chars,
     const char* text,
     int token=-1) 
    {
        eError error = e_ERROR_NONE;
        OutputContent(text);
        if (chars)
            OutputContent(chars);
        return error;
    }
    /**
     **********************************************************************
     * Function: On
     *
     *   Author: $author$
     *     Date: 5/11/2008
     **********************************************************************
     */
    virtual eError On
    (const char* beginChars,
     const char* endChars,
     const char* text,
     int token=-1) 
    {
        eError error = e_ERROR_NONE;
        if (beginChars)
            OutputContent(beginChars);
        OutputContent(text);
        if (endChars)
            OutputContent(endChars);
        return error;
    }

    /**
     **********************************************************************
     * Function: OnLT
     *
     *   Author: $author$
     *     Date: 5/11/2008
     **********************************************************************
     */
    virtual eError OnLT
    (const char* text,
     int token=-1) 
    {
        eError error = e_ERROR_NONE;
        OutputContent("&lt;");
        return error;
    }
    /**
     **********************************************************************
     * Function: OnGT
     *
     *   Author: $author$
     *     Date: 5/11/2008
     **********************************************************************
     */
    virtual eError OnGT
    (const char* text,
     int token=-1) 
    {
        eError error = e_ERROR_NONE;
        OutputContent("&gt;");
        return error;
    }
    /**
     **********************************************************************
     * Function: OnText
     *
     *   Author: $author$
     *     Date: 1/8/2006
     **********************************************************************
     */
    virtual eError OnText
    (const char* text,
     int token=-1) 
    {
        eError error = e_ERROR_NONE;
        OutputContent(text);
        return error;
    }
};
#endif /* _CADACGI_HXX */
