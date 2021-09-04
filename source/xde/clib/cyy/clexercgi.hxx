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
 *   File: clexercgi.hxx
 *
 * Author: $author$
 *   Date: 7/8/2008
 **********************************************************************
 */
#ifndef _CLEXERCGI_HXX
#define _CLEXERCGI_HXX

#include "cdocumenttemplatecgi.hxx"
#include "ccgistream.hxx"
#include "cfilepathfinder.hxx"
#include "cfilesystem.hxx"
#include "cfilepath.hxx"

#include "clexer.hxx"
#undef _CYYLEXER_AGAIN
#include "clexercgilexer.hxx"

#define DEFAULT_DOCUMENT_FILENAME_NAME \
    DEFAULT_DOCUMENT_FILENAME_EXTENSION \
    DEFAULT_FILENAMECGI_FILENAME_NAME_SUFFIX

#if !defined(DEFAULT_TEMPLATE_FILENAME_EXTENSION) 
#define DEFAULT_TEMPLATE_FILENAME_EXTENSION \
    DEFAULT_LEXERCGI_NAME
#else /* !defined(DEFAULT_TEMPLATE_FILENAME_EXTENSION) */
#endif /* !defined(DEFAULT_TEMPLATE_FILENAME_EXTENSION) */

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
    DEFAULT_LEXERCGI_NAME \
    PLATFORM_EXTENSION_SEPARATOR \
    DEFAULT_DOCUMENT_FILENAME_EXTENSION

#define DEFAULT_TEMPLATE_FILENAME \
    DEFAULT_LEXERCGI_NAME \
    PLATFORM_EXTENSION_SEPARATOR \
    DEFAULT_TEMPLATE_FILENAME_EXTENSION

#if !defined(DEFAULT_COLOR_CHARS) 
#define DEFAULT_COLOR_CHARS "black"
#endif
#if !defined(DEFAULT_COMMENT_COLOR_CHARS) 
#define DEFAULT_COMMENT_COLOR_CHARS "teal"
#endif
#if !defined(DEFAULT_COMMENTLN_COLOR_CHARS) 
#define DEFAULT_COMMENTLN_COLOR_CHARS "teal"
#endif
#if !defined(DEFAULT_COMMENTX_COLOR_CHARS) 
#define DEFAULT_COMMENTX_COLOR_CHARS "gray"
#endif
#if !defined(DEFAULT_KEYWORD_COLOR_CHARS) 
#define DEFAULT_KEYWORD_COLOR_CHARS "blue"
#endif
#if !defined(DEFAULT_KEYWORDX_COLOR_CHARS) 
#define DEFAULT_KEYWORDX_COLOR_CHARS "purple"
#endif
#if !defined(DEFAULT_KEYWORDY_COLOR_CHARS) 
#define DEFAULT_KEYWORDY_COLOR_CHARS "purple"
#endif
#if !defined(DEFAULT_INCLUDE_COLOR_CHARS) 
#define DEFAULT_INCLUDE_COLOR_CHARS "maroon"
#endif
#if !defined(DEFAULT_IMPORT_COLOR_CHARS) 
#define DEFAULT_IMPORT_COLOR_CHARS "maroon"
#endif
#if !defined(DEFAULT_DEFINE_COLOR_CHARS) 
#define DEFAULT_DEFINE_COLOR_CHARS "maroon"
#endif
#if !defined(DEFAULT_DEFINEX_COLOR_CHARS) 
#define DEFAULT_DEFINEX_COLOR_CHARS "maroon"
#endif
#if !defined(DEFAULT_PROCESSOR_COLOR_CHARS) 
#define DEFAULT_PROCESSOR_COLOR_CHARS "maroon"
#endif
#if !defined(DEFAULT_PROCESSORX_COLOR_CHARS) 
#define DEFAULT_PROCESSORX_COLOR_CHARS "maroon"
#endif
#if !defined(DEFAULT_TEXT_COLOR_CHARS) 
#define DEFAULT_TEXT_COLOR_CHARS "blue"
#endif
#if !defined(DEFAULT_STRING_COLOR_CHARS) 
#define DEFAULT_STRING_COLOR_CHARS "red"
#endif
#if !defined(DEFAULT_CHAR_COLOR_CHARS) 
#define DEFAULT_CHAR_COLOR_CHARS "red"
#endif
#if !defined(DEFAULT_INVALID_COLOR_CHARS) 
#define DEFAULT_INVALID_COLOR_CHARS "red"
#endif

#define DEFAULT_BEFORE_CHARS \
    "<html><head><style type=\"text/css\">\n" \
    "body {color: " DEFAULT_COLOR_CHARS "; }\n" \
    "a.definet {color: " DEFAULT_DEFINE_COLOR_CHARS "; }\n" \
    "a.definel {color: " DEFAULT_DEFINE_COLOR_CHARS "; text-decoration: underline; }\n" \
    "a.includel {color: " DEFAULT_INCLUDE_COLOR_CHARS "; text-decoration: underline; }\n" \
    "a.importl {color: " DEFAULT_IMPORT_COLOR_CHARS "; text-decoration: underline; }\n" \
    "font.comment {color: " DEFAULT_COMMENT_COLOR_CHARS "; font-style:italic; }\n" \
    "font.commentln {color: " DEFAULT_COMMENTLN_COLOR_CHARS "; font-style:italic; }\n" \
    "font.commentx {color: " DEFAULT_COMMENTX_COLOR_CHARS "; font-style:italic; }\n" \
    "font.keyword {color: " DEFAULT_KEYWORD_COLOR_CHARS "; font-weight: bolder; }\n" \
    "font.keywordx {color: " DEFAULT_KEYWORDX_COLOR_CHARS "; font-weight: bolder; }\n" \
    "font.keywordy {color: " DEFAULT_KEYWORDY_COLOR_CHARS "; font-weight: bolder; }\n" \
    "font.include {color: " DEFAULT_INCLUDE_COLOR_CHARS "; }\n" \
    "font.import {color: " DEFAULT_IMPORT_COLOR_CHARS "; }\n" \
    "font.define {color: " DEFAULT_DEFINE_COLOR_CHARS "; }\n" \
    "font.definex {color: " DEFAULT_DEFINEX_COLOR_CHARS "; }\n" \
    "font.processor {color: " DEFAULT_PROCESSOR_COLOR_CHARS "; }\n" \
    "font.processorx {color: " DEFAULT_PROCESSORX_COLOR_CHARS "; }\n" \
    "font.text {color: " DEFAULT_TEXT_COLOR_CHARS "; }\n" \
    "font.string {color: " DEFAULT_STRING_COLOR_CHARS "; }\n" \
    "font.char {color: " DEFAULT_CHAR_COLOR_CHARS "; }\n" \
    "font.invalid {color: " DEFAULT_INVALID_COLOR_CHARS "; text-decoration: underline; }\n" \
    "</style></head><body><pre>"
#define DEFAULT_AFTER_CHARS "</pre></body></html>\n"

#define DEFAULT_BEGIN_COMMENT_CHARS "<font class=\"comment\">"
#define DEFAULT_BEGIN_COMMENTLN_CHARS "<font class=\"commentln\">"
#define DEFAULT_BEGIN_COMMENTX_CHARS "<font class=\"commentx\">"
#define DEFAULT_BEGIN_PROCESSOR_CHARS "<font class=\"processor\">"
#define DEFAULT_BEGIN_PROCESSORX_CHARS "<font class=\"processorx\">"
#define DEFAULT_BEGIN_INCLUDE_CHARS "<font class=\"include\">"
#define DEFAULT_BEGIN_IMPORT_CHARS "<font class=\"import\">"
#define DEFAULT_BEGIN_DEFINE_CHARS "<font class=\"define\">"
#define DEFAULT_BEGIN_DEFINEX_CHARS "<font class=\"definex\">"
#define DEFAULT_BEGIN_KEYWORD_CHARS "<font class=\"keyword\">"
#define DEFAULT_BEGIN_KEYWORDX_CHARS "<font class=\"keywordx\">"
#define DEFAULT_BEGIN_KEYWORDY_CHARS "<font class=\"keywordy\">"
#define DEFAULT_BEGIN_TEXT_CHARS "<font class=\"text\">"
#define DEFAULT_BEGIN_STRING_CHARS "<font class=\"string\">"
#define DEFAULT_BEGIN_CHAR_CHARS "<font class=\"char\">"
#define DEFAULT_BEGIN_CHARS "<font class=\"invalid\">"
#define DEFAULT_END_CHARS "</font>"

#define DEFAULT_BEGIN_DEFINET_CHARS "<a class=\"definet\" name=\""
#define DEFAULT_BEGIN_DEFINEL_CHARS "<a class=\"definel\" href=\"#"
#define DEFAULT_BEGIN_INCLUDEL_CHARS "<a class=\"includel\" href=\""
#define DEFAULT_BEGIN_IMPORTL_CHARS "<a class=\"importl\" href=\""
#define DEFAULT_MIDDLET_CHARS "\">"
#define DEFAULT_ENDT_CHARS "</a>"
#define DEFAULT_MIDDLEL_CHARS DEFAULT_MIDDLET_CHARS
#define DEFAULT_ENDL_CHARS DEFAULT_ENDT_CHARS

#define DEFAULT_TEXT_CHARS ""

#undef CDB_CLASS
#define CDB_CLASS "cLexerCGIT"
/**
 **********************************************************************
 *  Class: cLexerCGIT
 *
 * Author: $author$
 *   Date: 7/8/2008
 **********************************************************************
 */
template
<class TLexer,
 class TLexerDelegate,
 class TLexerSource=cLexerSource>
 
class cLexerCGIT
: virtual public cLexerCGILexerDelegate,
  virtual public TLexerDelegate,
  public cDocumentTemplateCGI
{
public:
    typedef TLexerDelegate cImplements;
    typedef cDocumentTemplateCGI cExtends;
    typedef cLexerCGIT cDerives;

    typedef eError 
    (cDerives::*MOnCGIAfter)
    (const char* text, int token);

    cCGIStream m_cgiStream;

    TLexerSource m_documentSource;
    TLexer m_documentLexer;

    cLexerSource m_templateSource;
    cLexerCGILexer m_templateLexer;

    cFilePath m_filePath;
    cFileSystem m_fileSystem;
    cFilePathFinder m_filePathFinder;

    const char* m_beforeChars;
    cCharString m_before;

    const char* m_afterChars;
    cCharString m_after;

    const char* m_beginChars;
    cCharString m_begin;

    const char* m_middleChars;
    cCharString m_middle;

    const char* m_endChars;
    cCharString m_end;

    const char* m_middleTChars;
    cCharString m_middleT;

    const char* m_endTChars;
    cCharString m_endT;

    const char* m_middleLChars;
    cCharString m_middleL;

    const char* m_endLChars;
    cCharString m_endL;

    const char* m_beginCommentChars;
    cCharString m_beginComment;

    const char* m_beginCommentLNChars;
    cCharString m_beginCommentLN;

    const char* m_beginCommentXChars;
    cCharString m_beginCommentX;

    const char* m_beginProcessorChars;
    cCharString m_beginProcessor;

    const char* m_beginProcessorXChars;
    cCharString m_beginProcessorX;

    const char* m_beginDefineChars;
    cCharString m_beginDefine;

    const char* m_beginDefineXChars;
    cCharString m_beginDefineX;

    const char* m_beginDefineTChars;
    cCharString m_beginDefineT;

    const char* m_beginDefineLChars;
    cCharString m_beginDefineL;

    const char* m_beginIncludeLChars;
    cCharString m_beginIncludeL;

    const char* m_beginImportLChars;
    cCharString m_beginImportL;

    const char* m_beginKeywordChars;
    cCharString m_beginKeyword;

    const char* m_beginKeywordXChars;
    cCharString m_beginKeywordX;

    const char* m_beginKeywordYChars;
    cCharString m_beginKeywordY;

    const char* m_beginTextChars;
    cCharString m_beginText;

    const char* m_beginStringChars;
    cCharString m_beginString;

    const char* m_beginCharChars;
    cCharString m_beginChar;

    const char* m_textChars;
    cCharString m_text;

    const char* m_pathsChars;
    cCharString m_paths;

    const char* m_extensionsChars;
    cCharString m_extensions;

    cCharString m_string;

    MOnCGIAfter m_onCGIBetween;
    MOnCGIAfter m_onCGIAfter;

    /**
     **********************************************************************
     * Constructor: cLexerCGIT
     *
     *      Author: $author$
     *        Date: 7/8/2008
     **********************************************************************
     */
    cLexerCGIT
    (const tChar* cgiNameChars = DEFAULT_LEXERCGI_NAME,
     const tChar* documentFileNameExtensionChars = DEFAULT_DOCUMENT_FILENAME_EXTENSION,
     const tChar* documentFileNameNameChars = DEFAULT_DOCUMENT_FILENAME_NAME,
     const tChar* documentURINameChars = DEFAULT_DOCUMENT_URI_NAME,
     const tChar* templateFileNameExtensionChars = DEFAULT_TEMPLATE_FILENAME_EXTENSION,
     const tChar* templateFileNameNameChars = DEFAULT_TEMPLATE_FILENAME_NAME,
     const tChar* templateURINameChars = DEFAULT_TEMPLATE_URI_NAME)
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

      m_templateLexer
      (*this, m_cgiStream, 
       m_templateFile, m_templateSource),

      m_filePathFinder(m_fileSystem),

      m_beforeChars(DEFAULT_BEFORE_CHARS),
      m_afterChars(DEFAULT_AFTER_CHARS),

      m_beginChars(DEFAULT_BEGIN_CHARS),
      m_middleChars(DEFAULT_MIDDLEL_CHARS),
      m_endChars(DEFAULT_END_CHARS),

      m_middleTChars(DEFAULT_MIDDLET_CHARS),
      m_endTChars(DEFAULT_ENDT_CHARS),

      m_middleLChars(DEFAULT_MIDDLEL_CHARS),
      m_endLChars(DEFAULT_ENDL_CHARS),

      m_beginCommentChars(DEFAULT_BEGIN_COMMENT_CHARS),
      m_beginCommentLNChars(DEFAULT_BEGIN_COMMENTLN_CHARS),
      m_beginCommentXChars(DEFAULT_BEGIN_COMMENTX_CHARS),
      m_beginProcessorChars(DEFAULT_BEGIN_PROCESSOR_CHARS),
      m_beginProcessorXChars(DEFAULT_BEGIN_PROCESSORX_CHARS),
      m_beginDefineChars(DEFAULT_BEGIN_DEFINE_CHARS),
      m_beginDefineXChars(DEFAULT_BEGIN_DEFINEX_CHARS),
      m_beginDefineTChars(DEFAULT_BEGIN_DEFINET_CHARS),
      m_beginDefineLChars(DEFAULT_BEGIN_DEFINEL_CHARS),
      m_beginIncludeLChars(DEFAULT_BEGIN_INCLUDEL_CHARS),
      m_beginImportLChars(DEFAULT_BEGIN_IMPORTL_CHARS),
      m_beginKeywordChars(DEFAULT_BEGIN_KEYWORD_CHARS),
      m_beginKeywordXChars(DEFAULT_BEGIN_KEYWORDX_CHARS),
      m_beginKeywordYChars(DEFAULT_BEGIN_KEYWORDY_CHARS),
      m_beginTextChars(DEFAULT_BEGIN_TEXT_CHARS),
      m_beginStringChars(DEFAULT_BEGIN_STRING_CHARS),
      m_beginCharChars(DEFAULT_BEGIN_CHAR_CHARS),

      m_textChars(DEFAULT_BEGIN_CHARS),
      m_pathsChars(0),
      m_extensionsChars(0),
      m_onCGIBetween(0),
      m_onCGIAfter(0)
    {
        TLENGTH length;

        if (0 < (m_templateFileName.Assign(DEFAULT_TEMPLATE_FILENAME)))
            m_templateFileNameChars = m_templateFileName.Chars(length);
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
        const char* templateFileNameChars;
        const char* text;

        CDBF("()...\n");

        CTHIS SetContentType(CTHIS GetContentTypeHTML());

        if (!(documentFileNameChars = GetDocumentFileName(length, false, true)))
            return CTHIS MissingDocumentFileName();

        if (!(templateFileNameChars = GetTemplateFileName(length, true)))
        if (!(templateFileNameChars = m_templateFileNameChars))
            CDBW("() missing template filename\n");

        if (templateFileNameChars)
        {
            CDBI("() template file is \"%s\"\n", templateFileNameChars);

            if ((error = m_templateFile.Open(templateFileNameChars)))
                CDBW("() unable to open template file \"%s\"\n", templateFileNameChars);
            else
            {
                CDBI("() yylex()...\n");
                m_templateLexer.yylex();
                CDBI("() ...yylex()\n");
                m_templateFile.Close();
            }
        }
            
        if (!(err = OpenDocumentFile(documentFileNameChars)))
        {
            if (!(text = m_beforeChars))
                m_beforeChars = m_before.Chars(length);

            if ((text = m_beforeChars))
                OutputContentBeforeText(text);

            m_documentLexer.yylex();
            m_documentFile.Close();

            if (!(text = m_afterChars))
                m_afterChars = m_after.Chars(length);

            if ((text = m_afterChars))
                OutputContentAfterText(text);
        }
        return err;
    }

    /**
     **********************************************************************
     * Function: OpenDocumentFile
     *
     *   Author: $author$
     *     Date: 9/14/2008
     **********************************************************************
     */
    virtual int OpenDocumentFile
    (const char* fileNameChars) 
    {
        int err = 0;
        eError error;
        cFilePathInterface* fp;
        cFileSystemEntryInterface* fse;
        const char* chars;
        tLength length;

        if ((error = m_documentFile.Open(fileNameChars)))
        {
            if (m_pathsChars)
            if (0 < (length = m_filePath.Assign(fileNameChars)))
            if ((chars = m_filePath.GetFileName(length)))
            if ((fp = m_filePathFinder.FindFilePath
                (fse, chars, length, m_pathsChars)))
            if ((chars = fp->HasChars(length)))
            if (!(error = m_documentFile.Open(chars)))
            {
                SetDocumentFileName(chars, length);
                return err = 0;
            }

            return UnableToOpenFileName(fileNameChars);
        }
        return err;
    }

    /**
     **********************************************************************
     * Function: OutputContentBeforeText
     *
     *   Author: $author$
     *     Date: 8/14/2008
     **********************************************************************
     */
    virtual tLength OutputContentBeforeText
    (const char* chars, tLength length=-1) 
    {
        tLength count = TransformOutputContent(chars,length);
        return count;
    }
    /**
     **********************************************************************
     * Function: OutputContentAfterText
     *
     *   Author: $author$
     *     Date: 8/14/2008
     **********************************************************************
     */
    virtual tLength OutputContentAfterText
    (const char* chars, tLength length=-1) 
    {
        tLength count = TransformOutputContent(chars,length);
        return count;
    }
    /**
     **********************************************************************
     * Function: OutputContentText
     *
     *   Author: $author$
     *     Date: 8/14/2008
     **********************************************************************
     */
    virtual tLength OutputContentText
    (const char* chars, tLength length=-1) 
    {
        tLength count = CTHIS OutputContent(chars,length);
        return count;
    }
    /**
     **********************************************************************
     * Function: TransformOutputContentText
     *
     *   Author: $author$
     *     Date: 8/18/2008
     **********************************************************************
     */
    virtual tLength TransformOutputContentText
    (const char* chars, tLength length=-1) 
    {
        tLength count = TransformOutputContent(chars, length);
        return count;
    }
    /**
     **********************************************************************
     * Function: TransformOutputContent
     *
     *   Author: $author$
     *     Date: 8/13/2008
     **********************************************************************
     */
    virtual tLength TransformOutputContent
    (const char* chars, tLength length=-1) 
    {
        tLength count = CTHIS OutputContent(chars, length);
        return count;
    }

    /**
     **********************************************************************
     * Function: OnBeginRuleComment
     *
     *   Author: $author$
     *     Date: 8/18/2008
     **********************************************************************
     */
    virtual eError OnBeginRuleComment
    (const char* text,
     int token=-1) 
    {
        eError error = OnBeginComment(text, token);
        return error;
    }
    /**
     **********************************************************************
     * Function: OnEndRuleComment
     *
     *   Author: $author$
     *     Date: 8/18/2008
     **********************************************************************
     */
    virtual eError OnEndRuleComment
    (const char* text,
     int token=-1) 
    {
        eError error = OnEnd(text, token);
        return error;
    }
    /**
     **********************************************************************
     * Function: OnRuleCommentText
     *
     *   Author: $author$
     *     Date: 8/18/2008
     **********************************************************************
     */
    virtual eError OnRuleCommentText
    (const char* text,
     int token=-1) 
    {
        eError error = OnText(text, token);
        return error;
    }
    /**
     **********************************************************************
     * Function: OnBeginRuleT
     *
     *   Author: $author$
     *     Date: 8/18/2008
     **********************************************************************
     */
    virtual eError OnBeginRuleT
    (const char* text,
     int token=-1) 
    {
        eError error = OnText(text, token);
        return error;
    }
    /**
     **********************************************************************
     * Function: OnEndRuleT
     *
     *   Author: $author$
     *     Date: 8/18/2008
     **********************************************************************
     */
    virtual eError OnEndRuleT
    (const char* text,
     int token=-1) 
    {
        eError error = OnText(text, token);
        return error;
    }
    /**
     **********************************************************************
     * Function: OnRuleT
     *
     *   Author: $author$
     *     Date: 8/18/2008
     **********************************************************************
     */
    virtual eError OnRuleT
    (const char* text,
     int token=-1) 
    {
        eError error = OnDefineT(text, token);
        return error;
    }
    /**
     **********************************************************************
     * Function: OnBeginRuleL
     *
     *   Author: $author$
     *     Date: 8/18/2008
     **********************************************************************
     */
    virtual eError OnBeginRuleL
    (const char* text,
     int token=-1) 
    {
        eError error = OnText(text, token);
        return error;
    }
    /**
     **********************************************************************
     * Function: OnEndRuleL
     *
     *   Author: $author$
     *     Date: 8/18/2008
     **********************************************************************
     */
    virtual eError OnEndRuleL
    (const char* text,
     int token=-1) 
    {
        eError error = OnText(text, token);
        return error;
    }
    /**
     **********************************************************************
     * Function: OnAndRuleL
     *
     *   Author: $author$
     *     Date: 8/18/2008
     **********************************************************************
     */
    virtual eError OnAndRuleL
    (const char* text,
     int token=-1) 
    {
        eError error = OnText(text, token);
        return error;
    }
    /**
     **********************************************************************
     * Function: OnOrRuleL
     *
     *   Author: $author$
     *     Date: 8/18/2008
     **********************************************************************
     */
    virtual eError OnOrRuleL
    (const char* text,
     int token=-1) 
    {
        eError error = OnText(text, token);
        return error;
    }
    /**
     **********************************************************************
     * Function: OnRuleL
     *
     *   Author: $author$
     *     Date: 8/18/2008
     **********************************************************************
     */
    virtual eError OnRuleL
    (const char* text,
     int token=-1) 
    {
        eError error = OnDefineL(text, token);
        return error;
    }
    /**
     **********************************************************************
     * Function: OnRuleLString
     *
     *   Author: $author$
     *     Date: 8/18/2008
     **********************************************************************
     */
    virtual eError OnRuleLString
    (const char* text,
     int token=-1) 
    {
        eError error = OnString(text, token);
        return error;
    }
    /**
     **********************************************************************
     * Function: OnRuleLChar
     *
     *   Author: $author$
     *     Date: 8/18/2008
     **********************************************************************
     */
    virtual eError OnRuleLChar
    (const char* text,
     int token=-1) 
    {
        eError error = OnChar(text, token);
        return error;
    }
    /**
     **********************************************************************
     * Function: OnRuleText
     *
     *   Author: $author$
     *     Date: 8/18/2008
     **********************************************************************
     */
    virtual eError OnRuleText
    (const char* text,
     int token=-1) 
    {
        eError error = OnText(text, token);
        return error;
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
     * Function: OnBeginCommentLN
     *
     *   Author: $author$
     *     Date: 5/11/2008
     **********************************************************************
     */
    virtual eError OnBeginCommentLN
    (const char* text,
     int token=-1) 
    {
        eError error = OnBegin
        (m_beginCommentLNChars, text, token);
        return error;
    }
    /**
     **********************************************************************
     * Function: OnBeginCommentX
     *
     *   Author: $author$
     *     Date: 5/11/2008
     **********************************************************************
     */
    virtual eError OnBeginCommentX
    (const char* text,
     int token=-1) 
    {
        eError error = OnBegin
        (m_beginCommentXChars, text, token);
        return error;
    }
    /**
     **********************************************************************
     * Function: OnBeginProcessor
     *
     *   Author: $author$
     *     Date: 7/8/2008
     **********************************************************************
     */
    virtual eError OnBeginProcessor
    (const char* text,
     int token=-1) 
    {
        eError error = OnBegin
        (m_beginProcessorChars, text, token);
        return error;
    }
    /**
     **********************************************************************
     * Function: OnBeginProcessorX
     *
     *   Author: $author$
     *     Date: 7/8/2008
     **********************************************************************
     */
    virtual eError OnBeginProcessorX
    (const char* text,
     int token=-1) 
    {
        eError error = OnBegin
        (m_beginProcessorXChars, text, token);
        return error;
    }
    /**
     **********************************************************************
     * Function: OnBeginDefine
     *
     *   Author: $author$
     *     Date: 7/8/2008
     **********************************************************************
     */
    virtual eError OnBeginDefine
    (const char* text,
     int token=-1) 
    {
        eError error = OnBegin
        (m_beginDefineChars, text, token);
        return error;
    }
    /**
     **********************************************************************
     * Function: OnBeginDefineX
     *
     *   Author: $author$
     *     Date: 7/8/2008
     **********************************************************************
     */
    virtual eError OnBeginDefineX
    (const char* text,
     int token=-1) 
    {
        eError error = OnBegin
        (m_beginDefineXChars, text, token);
        return error;
    }
    /**
     **********************************************************************
     * Function: OnBeginCode
     *
     *   Author: $author$
     *     Date: 8/14/2008
     **********************************************************************
     */
    virtual eError OnBeginCode
    (const char* text,
     int token=-1) 
    {
        eError error = OnBeginText(text, token);
        return error;
    }
    /**
     **********************************************************************
     * Function: OnBeginText
     *
     *   Author: $author$
     *     Date: 7/8/2008
     **********************************************************************
     */
    virtual eError OnBeginText
    (const char* text,
     int token=-1) 
    {
        eError error = OnBegin
        (m_beginTextChars, text, token);
        return error;
    }
    /**
     **********************************************************************
     * Function: OnBeginTextAfter
     *
     *   Author: $author$
     *     Date: 7/8/2008
     **********************************************************************
     */
    virtual eError OnBeginTextAfter
    (const char* text,
     int token=-1) 
    {
        eError error = OnEnd
        (m_beginTextChars, text, token);
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
    (const char* text,
     int token=-1) 
    {
        eError error = OnEnd(m_endChars, text, token);
        return error;
    }
    /**
     **********************************************************************
     * Function: OnEndBefore
     *
     *   Author: $author$
     *     Date: 5/11/2008
     **********************************************************************
     */
    virtual eError OnEndBefore
    (const char* text,
     int token=-1) 
    {
        eError error = OnBegin
        (m_endChars, text, token);
        return error;
    }

    /**
     **********************************************************************
     * Function: OnComment
     *
     *   Author: $author$
     *     Date: 5/11/2008
     **********************************************************************
     */
    virtual eError OnComment
    (const char* text,
     int token=-1) 
    {
        eError error = On
        (m_beginCommentChars, m_endChars, text, token);
        return error;
    }
    /**
     **********************************************************************
     * Function: OnCommentX
     *
     *   Author: $author$
     *     Date: 5/11/2008
     **********************************************************************
     */
    virtual eError OnCommentX
    (const char* text,
     int token=-1) 
    {
        eError error = On
        (m_beginCommentXChars, m_endChars, text, token);
        return error;
    }
    /**
     **********************************************************************
     * Function: OnCommentLN
     *
     *   Author: $author$
     *     Date: 5/11/2008
     **********************************************************************
     */
    virtual eError OnCommentLN
    (const char* text,
     int token=-1) 
    {
        eError error = On
        (m_beginCommentLNChars, m_endChars, text, token);
        return error;
    }
    /**
     **********************************************************************
     * Function: OnProcessor
     *
     *   Author: $author$
     *     Date: 5/11/2008
     **********************************************************************
     */
    virtual eError OnProcessor
    (const char* text,
     int token=-1) 
    {
        eError error = On
        (m_beginProcessorChars, m_endChars, text, token);
        return error;
    }
    /**
     **********************************************************************
     * Function: OnProcessorX
     *
     *   Author: $author$
     *     Date: 5/11/2008
     **********************************************************************
     */
    virtual eError OnProcessorX
    (const char* text,
     int token=-1) 
    {
        eError error = On
        (m_beginProcessorXChars, m_endChars, text, token);
        return error;
    }
    /**
     **********************************************************************
     * Function: OnDefine
     *
     *   Author: $author$
     *     Date: 5/11/2008
     **********************************************************************
     */
    virtual eError OnDefine
    (const char* text,
     int token=-1) 
    {
        eError error = On
        (m_beginDefineChars, m_endChars, text, token);
        return error;
    }
    /**
     **********************************************************************
     * Function: OnDefineX
     *
     *   Author: $author$
     *     Date: 5/11/2008
     **********************************************************************
     */
    virtual eError OnDefineX
    (const char* text,
     int token=-1) 
    {
        eError error = On
        (m_beginDefineXChars, m_endChars, text, token);
        return error;
    }
    /**
     **********************************************************************
     * Function: OnDefineT
     *
     *   Author: $author$
     *     Date: 5/11/2008
     **********************************************************************
     */
    virtual eError OnDefineT
    (const char* text,
     int token=-1) 
    {
        eError error = OnT
        (m_beginDefineTChars, m_middleTChars,
         m_endTChars, text, token);
        return error;
    }
    /**
     **********************************************************************
     * Function: OnDefineL
     *
     *   Author: $author$
     *     Date: 5/11/2008
     **********************************************************************
     */
    virtual eError OnDefineL
    (const char* text,
     int token=-1) 
    {
        eError error = OnT
        (m_beginDefineLChars, m_middleLChars,
         m_endLChars, text, token);
        return error;
    }
    /**
     **********************************************************************
     * Function: OnIncludeL
     *
     *   Author: $author$
     *     Date: 9/4/2008
     **********************************************************************
     */
    virtual eError OnIncludeL
    (const char* text,
     int token=-1) 
    {
        eError error = OnStringT
        (m_beginIncludeLChars, m_middleLChars,
         m_endLChars, text, token);
        return error;
    }
    /**
     **********************************************************************
     * Function: OnImportL
     *
     *   Author: $author$
     *     Date: 9/4/2008
     **********************************************************************
     */
    virtual eError OnImportL
    (const char* text,
     int token=-1) 
    {
        eError error = OnT
        (m_beginImportLChars, m_middleLChars,
         m_endLChars, text, token);
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
     * Function: OnReservedX
     *
     *   Author: $author$
     *     Date: 5/11/2008
     **********************************************************************
     */
    virtual eError OnReservedX
    (const char* text,
     int token=-1) 
    {
        eError error = On
        (m_beginKeywordXChars, m_endChars, text, token);
        return error;
    }
    /**
     **********************************************************************
     * Function: OnReservedY
     *
     *   Author: $author$
     *     Date: 10/13/2008
     **********************************************************************
     */
    virtual eError OnReservedY
    (const char* text,
     int token=-1) 
    {
        eError error = On
        (m_beginKeywordYChars, m_endChars, text, token);
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
     * Function: OnCode
     *
     *   Author: $author$
     *     Date: 8/14/2008
     **********************************************************************
     */
    virtual eError OnCode
    (const char* text,
     int token=-1) 
    {
        eError error = OnText(text, token);
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
            OutputContentText(chars);
        OnText(text);
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
        OnText(text);
        if (chars)
            OutputContentText(chars);
        return error;
    }
    /**
     **********************************************************************
     * Function: OnStringT
     *
     *   Author: $author$
     *     Date: 9/8/2008
     **********************************************************************
     */
    virtual eError OnStringT
    (const char* beginChars,
     const char* middleChars,
     const char* endChars,
     const char* text,
     int token=-1) 
    {
        eError error = e_ERROR_NONE;
        const char* stringText = text;
        tLength length;
        const char* chars;
        cCharCounter counter;

        /*
         * remove string end delimeters
         */
        if (2 < (length = counter.LengthOf(text)))
        if (0 < (length = m_string.Assign(text+1, length-2)))
        if ((chars = m_string.HasChars(length)))
            stringText = chars;

        OnBeginT(beginChars, stringText, token);
        if (middleChars)
            OutputContentText(middleChars);
        OnText(text);
        if (endChars)
            OutputContentText(endChars);
        return error;
    }
    /**
     **********************************************************************
     * Function: OnT
     *
     *   Author: $author$
     *     Date: 5/11/2008
     **********************************************************************
     */
    virtual eError OnT
    (const char* beginChars,
     const char* middleChars,
     const char* endChars,
     const char* text,
     int token=-1) 
    {
        eError error = e_ERROR_NONE;
        OnBeginT(beginChars, text, token);
        if (middleChars)
            OutputContentText(middleChars);
        OnText(text);
        if (endChars)
            OutputContentText(endChars);
        return error;
    }
    /**
     **********************************************************************
     * Function: OnBeginT
     *
     *   Author: $author$
     *     Date: 9/5/2008
     **********************************************************************
     */
    virtual eError OnBeginT
    (const char* beginChars,
     const char* text,
     int token=-1) 
    {
        eError error = e_ERROR_NONE;
        if (beginChars)
            OnText(beginChars);
        OnText(text);
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
            OutputContentText(beginChars);
        OnText(text);
        if (endChars)
            OutputContentText(endChars);
        return error;
    }
    /**
     **********************************************************************
     * Function: OnText
     *
     *   Author: $author$
     *     Date: 5/11/2008
     **********************************************************************
     */
    virtual eError OnText
    (const char* text,
     int token=-1) 
    {
        eError error = e_ERROR_NONE;
        TLENGTH length;
        const char* t;
        const char* i;
        char c;

        for (t=text, i=text; (c=*i); i++) {
            if ('<' != c) {
                if ('>' != c) {
                    if ('&' != c) {
                        continue;
                    } else {
                        if (0 < (length = (TLENGTH)(i-t)))
                            OutputContentText(t, length);
                        OnAMP(i);
                    }
                 } else {
                    if (0 < (length = (TLENGTH)(i-t)))
                        OutputContentText(t, length);
                    OnGT(i);
                }
            } else {
                if (0 < (length = (TLENGTH)(i-t)))
                    OutputContentText(t, length);
                OnLT(i);
            }
            t = i+1;
        }
        if (0 < (length = (TLENGTH)(i-t)))
            OutputContentText(t, length);
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
        OutputContentText("&lt;");
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
        OutputContentText("&gt;");
        return error;
    }
    /**
     **********************************************************************
     * Function: OnAMP
     *
     *   Author: $author$
     *     Date: 11/19/2016
     **********************************************************************
     */
    virtual eError OnAMP
    (const char* text, int token=-1) {
        eError error = e_ERROR_NONE;
        OutputContentText("&amp;");
        return error;
    }
    /**
     **********************************************************************
     * Function: OnSkip
     *
     *   Author: $author$
     *     Date: 7/8/2008
     **********************************************************************
     */
    virtual eError OnSkip
    (const char* text,
     int token=-1) 
    {
        eError error = e_ERROR_NONE;
        return error;
    }

    /*
     * CGI rules
     */

    /**
     **********************************************************************
     * Function: OnCGIBeforeComment
     *
     *   Author: $author$
     *     Date: 8/10/2008
     **********************************************************************
     */
    virtual eError OnCGIBeforeComment
    (const char* text,
     int token=-1) 
    {
        eError error = e_ERROR_NONE;
        const char* chars;
        TLENGTH length;
        CDBF("(%s)\n", text);
        if ((chars = m_begin.HasChars(length)))
        if (0 < (length = m_beginComment.Assign(chars)))
        if ((chars = m_beginComment.HasChars(length)))
        {
            m_beginCommentChars = chars;
            m_beginCommentLNChars = chars;
            m_beginCommentXChars = chars;
        }
        return error;
    }
    /**
     **********************************************************************
     * Function: OnCGIBeforeCommentLN
     *
     *   Author: $author$
     *     Date: 8/10/2008
     **********************************************************************
     */
    virtual eError OnCGIBeforeCommentLN
    (const char* text,
     int token=-1) 
    {
        eError error = e_ERROR_NONE;
        const char* chars;
        TLENGTH length;
        CDBF("(%s)\n", text);
        if ((chars = m_begin.HasChars(length)))
        if (0 < (length = m_beginCommentLN.Assign(chars)))
        if ((chars = m_beginCommentLN.HasChars(length)))
            m_beginCommentLNChars = chars;
        return error;
    }
    /**
     **********************************************************************
     * Function: OnCGIBeforeProcessor
     *
     *   Author: $author$
     *     Date: 8/10/2008
     **********************************************************************
     */
    virtual eError OnCGIBeforeProcessor
    (const char* text,
     int token=-1) 
    {
        eError error = e_ERROR_NONE;
        const char* chars;
        TLENGTH length;
        CDBF("(%s)\n", text);
        if ((chars = m_begin.HasChars(length)))
        if (0 < (length = m_beginProcessor.Assign(chars)))
        if ((chars = m_beginProcessor.HasChars(length)))
        {
            m_beginProcessorChars = chars;
            m_beginProcessorXChars = chars;
        }
        return error;
    }
    /**
     **********************************************************************
     * Function: OnCGIBeforeDefine
     *
     *   Author: $author$
     *     Date: 8/10/2008
     **********************************************************************
     */
    virtual eError OnCGIBeforeDefine
    (const char* text,
     int token=-1) 
    {
        eError error = e_ERROR_NONE;
        const char* chars;
        TLENGTH length;
        CDBF("(%s)\n", text);
        if ((chars = m_begin.HasChars(length)))
        if (0 < (length = m_beginDefine.Assign(chars)))
        if ((chars = m_beginDefine.HasChars(length)))
        {
            m_beginDefineChars = chars;
            m_beginDefineXChars = chars;
        }
        return error;
    }
    /**
     **********************************************************************
     * Function: OnCGIBeforeDefineT
     *
     *   Author: $author$
     *     Date: 8/18/2008
     **********************************************************************
     */
    virtual eError OnCGIBeforeDefineT
    (const char* text,
     int token=-1) 
    {
        eError error = e_ERROR_NONE;
        const char* chars;
        TLENGTH length;
        CDBF("(%s)\n", text);
        m_onCGIBetween = &cDerives::OnCGIBetweenDefineT;
        m_onCGIAfter = &cDerives::OnCGIAfterDefineT;
        if ((chars = m_begin.HasChars(length)))
        if (0 < (length = m_beginDefineT.Assign(chars)))
        if ((chars = m_beginDefineT.HasChars(length)))
            m_beginDefineTChars = chars;
        return error;
    }
    /**
     **********************************************************************
     * Function: OnCGIBetweenDefineT
     *
     *   Author: $author$
     *     Date: 8/21/2008
     **********************************************************************
     */
    eError OnCGIBetweenDefineT
    (const char* text,
     int token=-1) 
    {
        eError error = e_ERROR_NONE;
        const char* chars;
        TLENGTH length;
        CDBF("(%s)\n", text);
        m_onCGIBetween = 0;
        if ((chars = m_middle.HasChars(length)))
        if (0 < (length = m_middleT.Assign(chars)))
        if ((chars = m_middleT.HasChars(length)))
            m_middleTChars = chars;
        m_middle.Clear();
        m_middleChars = DEFAULT_MIDDLEL_CHARS;
        return error;
    }
    /**
     **********************************************************************
     * Function: OnCGIAfterDefineT
     *
     *   Author: $author$
     *     Date: 8/21/2008
     **********************************************************************
     */
    eError OnCGIAfterDefineT
    (const char* text,
     int token=-1) 
    {
        eError error = e_ERROR_NONE;
        const char* chars;
        TLENGTH length;
        CDBF("(%s)\n", text);
        m_onCGIAfter = 0;
        if ((chars = m_end.HasChars(length)))
        if (0 < (length = m_endT.Assign(chars)))
        if ((chars = m_endT.HasChars(length)))
            m_endTChars = chars;
        m_end.Clear();
        m_endChars = DEFAULT_END_CHARS;
        return error;
    }
    /**
     **********************************************************************
     * Function: OnCGIBeforeDefineL
     *
     *   Author: $author$
     *     Date: 8/18/2008
     **********************************************************************
     */
    virtual eError OnCGIBeforeDefineL
    (const char* text,
     int token=-1) 
    {
        eError error = e_ERROR_NONE;
        const char* chars;
        TLENGTH length;
        CDBF("(%s)\n", text);
        m_onCGIBetween = &cDerives::OnCGIBetweenDefineL;
        m_onCGIAfter = &cDerives::OnCGIAfterDefineL;
        if ((chars = m_begin.HasChars(length)))
        if (0 < (length = m_beginDefineL.Assign(chars)))
        if ((chars = m_beginDefineL.HasChars(length)))
            m_beginDefineLChars = chars;
        return error;
    }
    /**
     **********************************************************************
     * Function: OnCGIBetweenDefineL
     *
     *   Author: $author$
     *     Date: 8/24/2008
     **********************************************************************
     */
    eError OnCGIBetweenDefineL
    (const char* text,
     int token=-1) 
    {
        eError error = OnCGIBetweenL(text, token);
        return error;
    }
    /**
     **********************************************************************
     * Function: OnCGIAfterDefineL
     *
     *   Author: $author$
     *     Date: 8/24/2008
     **********************************************************************
     */
    eError OnCGIAfterDefineL
    (const char* text,
     int token=-1) 
    {
        eError error = OnCGIAfterL(text, token);
        return error;
    }
    /**
     **********************************************************************
     * Function: OnCGIBeforeImportL
     *
     *   Author: $author$
     *     Date: 10/2/2008
     **********************************************************************
     */
    virtual eError OnCGIBeforeImportL
    (const char* text,
     int token=-1) 
    {
        eError error = e_ERROR_NONE;
        const char* chars;
        TLENGTH length;
        CDBF("(%s)\n", text);
        m_onCGIBetween = &cDerives::OnCGIBetweenImportL;
        m_onCGIAfter = &cDerives::OnCGIAfterImportL;
        if ((chars = m_begin.HasChars(length)))
        if (0 < (length = m_beginImportL.Assign(chars)))
        if ((chars = m_beginImportL.HasChars(length)))
            m_beginImportLChars = chars;
        return error;
    }
    /**
     **********************************************************************
     * Function: OnCGIBetweenImportL
     *
     *   Author: $author$
     *     Date: 10/2/2008
     **********************************************************************
     */
    eError OnCGIBetweenImportL
    (const char* text,
     int token=-1) 
    {
        eError error = OnCGIBetweenL(text, token);
        return error;
    }
    /**
     **********************************************************************
     * Function: OnCGIAfterImportL
     *
     *   Author: $author$
     *     Date: 10/2/2008
     **********************************************************************
     */
    eError OnCGIAfterImportL
    (const char* text,
     int token=-1) 
    {
        eError error = OnCGIAfterL(text, token);
        return error;
    }
    /**
     **********************************************************************
     * Function: OnCGIBeforeIncludeL
     *
     *   Author: $author$
     *     Date: 9/4/2008
     **********************************************************************
     */
    virtual eError OnCGIBeforeIncludeL
    (const char* text,
     int token=-1) 
    {
        eError error = e_ERROR_NONE;
        const char* chars;
        TLENGTH length;
        CDBF("(%s)\n", text);
        m_onCGIBetween = &cDerives::OnCGIBetweenIncludeL;
        m_onCGIAfter = &cDerives::OnCGIAfterIncludeL;
        if ((chars = m_begin.HasChars(length)))
        if (0 < (length = m_beginIncludeL.Assign(chars)))
        if ((chars = m_beginIncludeL.HasChars(length)))
            m_beginIncludeLChars = chars;
        return error;
    }
    /**
     **********************************************************************
     * Function: OnCGIBetweenIncludeL
     *
     *   Author: $author$
     *     Date: 9/4/2008
     **********************************************************************
     */
    eError OnCGIBetweenIncludeL
    (const char* text,
     int token=-1) 
    {
        eError error = OnCGIBetweenL(text, token);
        return error;
    }
    /**
     **********************************************************************
     * Function: OnCGIAfterIncludeL
     *
     *   Author: $author$
     *     Date: 9/4/2008
     **********************************************************************
     */
    eError OnCGIAfterIncludeL
    (const char* text,
     int token=-1) 
    {
        eError error = OnCGIAfterL(text, token);
        return error;
    }

    /**
     **********************************************************************
     * Function: OnCGIBetweenL
     *
     *   Author: $author$
     *     Date: 10/2/2008
     **********************************************************************
     */
    eError OnCGIBetweenL
    (const char* text,
     int token=-1) 
    {
        eError error = e_ERROR_NONE;
        const char* chars;
        TLENGTH length;
        CDBF("(%s)\n", text);
        m_onCGIBetween = 0;
        if ((chars = m_middle.HasChars(length)))
        if (0 < (length = m_middleL.Assign(chars)))
        if ((chars = m_middleL.HasChars(length)))
            m_middleLChars = chars;
        m_middle.Clear();
        m_middleChars = DEFAULT_MIDDLEL_CHARS;
        return error;
    }
    /**
     **********************************************************************
     * Function: OnCGIAfterL
     *
     *   Author: $author$
     *     Date: 10/2/2008
     **********************************************************************
     */
    eError OnCGIAfterL
    (const char* text,
     int token=-1) 
    {
        eError error = e_ERROR_NONE;
        const char* chars;
        TLENGTH length;
        CDBF("(%s)\n", text);
        m_onCGIAfter = 0;
        if ((chars = m_end.HasChars(length)))
        if (0 < (length = m_endL.Assign(chars)))
        if ((chars = m_endL.HasChars(length)))
            m_endLChars = chars;
        m_end.Clear();
        m_endChars = DEFAULT_END_CHARS;
        return error;
    }

    /**
     **********************************************************************
     * Function: OnCGIBeforeKeyword
     *
     *   Author: $author$
     *     Date: 8/10/2008
     **********************************************************************
     */
    virtual eError OnCGIBeforeKeyword
    (const char* text,
     int token=-1) 
    {
        eError error = e_ERROR_NONE;
        const char* chars;
        TLENGTH length;
        CDBF("(%s)\n", text);
        if ((chars = m_begin.HasChars(length)))
        if (0 < (length = m_beginKeyword.Assign(chars)))
        if ((chars = m_beginKeyword.HasChars(length)))
        {
            m_beginKeywordChars = chars;
            m_beginKeywordXChars = chars;
            m_beginKeywordYChars = chars;
        }
        return error;
    }
    /**
     **********************************************************************
     * Function: OnCGIBeforeKeywordX
     *
     *   Author: $author$
     *     Date: 8/10/2008
     **********************************************************************
     */
    virtual eError OnCGIBeforeKeywordX
    (const char* text,
     int token=-1) 
    {
        eError error = e_ERROR_NONE;
        const char* chars;
        TLENGTH length;
        CDBF("(%s)\n", text);
        if ((chars = m_begin.HasChars(length)))
        if (0 < (length = m_beginKeywordX.Assign(chars)))
        if ((chars = m_beginKeywordX.HasChars(length)))
        {
            m_beginKeywordXChars = chars;
            m_beginKeywordYChars = chars;
        }
        return error;
    }
    /**
     **********************************************************************
     * Function: OnCGIBeforeKeywordY
     *
     *   Author: $author$
     *     Date: 8/10/2008
     **********************************************************************
     */
    virtual eError OnCGIBeforeKeywordY
    (const char* text,
     int token=-1) 
    {
        eError error = e_ERROR_NONE;
        const char* chars;
        TLENGTH length;
        CDBF("(%s)\n", text);
        if ((chars = m_begin.HasChars(length)))
        if (0 < (length = m_beginKeywordY.Assign(chars)))
        if ((chars = m_beginKeywordY.HasChars(length)))
        {
            m_beginKeywordYChars = chars;
        }
        return error;
    }
    /**
     **********************************************************************
     * Function: OnCGIBeforeString
     *
     *   Author: $author$
     *     Date: 8/10/2008
     **********************************************************************
     */
    virtual eError OnCGIBeforeString
    (const char* text,
     int token=-1) 
    {
        eError error = e_ERROR_NONE;
        const char* chars;
        TLENGTH length;
        CDBF("(%s)\n", text);
        if ((chars = m_begin.HasChars(length)))
        if (0 < (length = m_beginString.Assign(chars)))
        if ((chars = m_beginString.HasChars(length)))
            m_beginStringChars = chars;
        return error;
    }
    /**
     **********************************************************************
     * Function: OnCGIBeforeChar
     *
     *   Author: $author$
     *     Date: 8/10/2008
     **********************************************************************
     */
    virtual eError OnCGIBeforeChar
    (const char* text,
     int token=-1) 
    {
        eError error = e_ERROR_NONE;
        const char* chars;
        TLENGTH length;
        CDBF("(%s)\n", text);
        if ((chars = m_begin.HasChars(length)))
        if (0 < (length = m_beginChar.Assign(chars)))
        if ((chars = m_beginChar.HasChars(length)))
            m_beginCharChars = chars;
        return error;
    }

    /**
     **********************************************************************
     * Function: OnBeginCGIBeforeAny
     *
     *   Author: $author$
     *     Date: 8/10/2008
     **********************************************************************
     */
    virtual eError OnBeginCGIBeforeAny
    (const char* text,
     int token=-1) 
    {
        eError error = e_ERROR_NONE;
        CDBF("(%s)\n", text);
        m_begin.Assign(text);
        m_middle.Clear();
        m_end.Clear();
        m_endChars = DEFAULT_END_CHARS;
        return error;
    }
    /**
     **********************************************************************
     * Function: OnCGIBeforeAny
     *
     *   Author: $author$
     *     Date: 8/10/2008
     **********************************************************************
     */
    virtual eError OnCGIBeforeAny
    (const char* text,
     int token=-1) 
    {
        eError error = e_ERROR_NONE;
        CDBF("(%s)\n", text);
        m_begin.Append(text);
        return error;
    }

    /**
     **********************************************************************
     * Function: OnEndCGIAfterAny
     *
     *   Author: $author$
     *     Date: 8/10/2008
     **********************************************************************
     */
    virtual eError OnEndCGIAfterAny
    (const char* text,
     int token=-1) 
    {
        eError error = e_ERROR_NONE;
        const char* chars;
        TLENGTH length;
        CDBF("(%s)\n", text);
        if ((chars = m_end.HasChars(length)))
            m_endChars = chars;
        if (m_onCGIAfter)
           (this->*m_onCGIAfter)(text, token);
        return error;
    }
    /**
     **********************************************************************
     * Function: OnCGIAfterAnyText
     *
     *   Author: $author$
     *     Date: 8/10/2008
     **********************************************************************
     */
    virtual eError OnCGIAfterAnyText
    (const char* text,
     int token=-1) 
    {
        eError error = e_ERROR_NONE;
        CDBF("(%s)\n", text);
        m_end.Append(text);
        return error;
    }

    /**
     **********************************************************************
     * Function: OnEndCGIBetweenAny
     *
     *   Author: $author$
     *     Date: 8/10/2008
     **********************************************************************
     */
    virtual eError OnEndCGIBetweenAny
    (const char* text,
     int token=-1) 
    {
        eError error = e_ERROR_NONE;
        const char* chars;
        TLENGTH length;
        CDBF("(%s)\n", text);
        if ((chars = m_middle.HasChars(length)))
            m_middleChars = chars;
        if (m_onCGIBetween)
           (this->*m_onCGIBetween)(text, token);
        return error;
    }
    /**
     **********************************************************************
     * Function: OnCGIBetweenAnyText
     *
     *   Author: $author$
     *     Date: 8/10/2008
     **********************************************************************
     */
    virtual eError OnCGIBetweenAnyText
    (const char* text,
     int token=-1) 
    {
        eError error = e_ERROR_NONE;
        CDBF("(%s)\n", text);
        m_middle.Append(text);
        return error;
    }

    /**
     **********************************************************************
     * Function: OnCGIBeforeText
     *
     *   Author: $author$
     *     Date: 8/10/2008
     **********************************************************************
     */
    virtual eError OnCGIBeforeText
    (const char* text,
     int token=-1) 
    {
        eError error = e_ERROR_NONE;
        CDBT("(%s)\n", text);
        if (m_beforeChars)
        {
            m_before.Clear();
            m_beforeChars = 0;
        }
        m_before.Append(text);
        return error;
    }
    /**
     **********************************************************************
     * Function: OnCGIAfterText
     *
     *   Author: $author$
     *     Date: 8/10/2008
     **********************************************************************
     */
    virtual eError OnCGIAfterText
    (const char* text,
     int token=-1) 
    {
        eError error = e_ERROR_NONE;
        CDBT("(%s)\n", text);
        if (m_afterChars)
        {
            m_after.Clear();
            m_afterChars = 0;
        }
        m_after.Append(text);
        return error;
    }

    /**
     **********************************************************************
     * Function: OnBeginCGIText
     *
     *   Author: $author$
     *     Date: 8/15/2008
     **********************************************************************
     */
    virtual eError OnBeginCGIText
    (const char* text,
     int token=-1) 
    {
        eError error = e_ERROR_NONE;
        CDBT("(%s)\n", text);
        m_text.Clear();
        return error;
    }
    /**
     **********************************************************************
     * Function: OnEndCGIText
     *
     *   Author: $author$
     *     Date: 8/15/2008
     **********************************************************************
     */
    virtual eError OnEndCGIText
    (const char* text,
     int token=-1) 
    {
        eError error = e_ERROR_NONE;
        tLength length;
        CDBT("(%s)\n", text);
        m_textChars = m_text.HasChars(length);
        return error;
    }
    /**
     **********************************************************************
     * Function: OnCGIText
     *
     *   Author: $author$
     *     Date: 8/14/2008
     **********************************************************************
     */
    virtual eError OnCGIText
    (const char* text,
     int token=-1) 
    {
        eError error = e_ERROR_NONE;
        CDBT("(%s)\n", text);
        if (m_textChars)
        {
            m_text.Clear();
            m_textChars = 0;
        }
        m_text.Append(text);
        return error;
    }

    /**
     **********************************************************************
     * Function: OnBeginCGIPath
     *
     *   Author: $author$
     *     Date: 9/14/2008
     **********************************************************************
     */
    virtual eError OnBeginCGIPath
    (const char* text,
     int token=-1) 
    {
        eError error = e_ERROR_NONE;
        CDBT("(%s)\n", text);
        m_paths.Clear();
        return error;
    }
    /**
     **********************************************************************
     * Function: OnEndCGIPath
     *
     *   Author: $author$
     *     Date: 9/14/2008
     **********************************************************************
     */
    virtual eError OnEndCGIPath
    (const char* text,
     int token=-1) 
    {
        eError error = e_ERROR_NONE;
        tLength length;
        CDBT("(%s)\n", text);
        m_pathsChars = m_paths.HasChars(length);
        return error;
    }
    /**
     **********************************************************************
     * Function: OnCGIPath
     *
     *   Author: $author$
     *     Date: 9/14/2008
     **********************************************************************
     */
    virtual eError OnCGIPath
    (const char* text,
     int token=-1) 
    {
        eError error = e_ERROR_NONE;
        CDBT("(%s)\n", text);
        m_paths.Append(text);
        return error;
    }

    /**
     **********************************************************************
     * Function: OnBeginCGIExtension
     *
     *   Author: $author$
     *     Date: 10/2/2008
     **********************************************************************
     */
    virtual eError OnBeginCGIExtension
    (const char* text,
     int token=-1) 
    {
        eError error = e_ERROR_NONE;
        CDBT("(%s)\n", text);
        m_extensions.Clear();
        return error;
    }
    /**
     **********************************************************************
     * Function: OnEndCGIExtension
     *
     *   Author: $author$
     *     Date: 10/2/2008
     **********************************************************************
     */
    virtual eError OnEndCGIExtension
    (const char* text,
     int token=-1) 
    {
        eError error = e_ERROR_NONE;
        tLength length;
        CDBT("(%s)\n", text);
        m_extensionsChars = m_extensions.HasChars(length);
        return error;
    }
    /**
     **********************************************************************
     * Function: OnCGIExtension
     *
     *   Author: $author$
     *     Date: 10/2/2008
     **********************************************************************
     */
    virtual eError OnCGIExtension
    (const char* text,
     int token=-1) 
    {
        eError error = e_ERROR_NONE;
        CDBT("(%s)\n", text);
        m_extensions.Append(text);
        return error;
    }
};
#undef CDB_CLASS

#endif /* _CLEXERCGI_HXX */
