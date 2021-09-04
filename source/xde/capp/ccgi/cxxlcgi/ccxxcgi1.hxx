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
 *   File: ccxxcgi.hxx
 *
 * Author: $author$
 *   Date: 5/1/2008
 **********************************************************************
 */
#ifndef _CCXXCGI_HXX
#define _CCXXCGI_HXX

#include "cdocumenttemplatecgi.hxx"
#include "ccgistream.hxx"

#include "ccxxlexer.hxx"
#undef _CYYLEXER_AGAIN
#include "ccxxcgilexer.hxx"

#define DEFAULT_CXXCGI_NAME "cxxcgi"

#define DEFAULT_DOCUMENT_FILENAME_EXTENSION "cxx"

#define DEFAULT_DOCUMENT_FILENAME_NAME \
    DEFAULT_DOCUMENT_FILENAME_EXTENSION \
    DEFAULT_FILENAMECGI_FILENAME_NAME_SUFFIX

#define DEFAULT_TEMPLATE_FILENAME_EXTENSION \
    DEFAULT_CXXCGI_NAME

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
    DEFAULT_CXXCGI_NAME \
    PLATFORM_EXTENSION_SEPARATOR \
    DEFAULT_DOCUMENT_FILENAME_EXTENSION

#define DEFAULT_TEMPLATE_FILENAME \
    DEFAULT_CXXCGI_NAME \
    PLATFORM_EXTENSION_SEPARATOR \
    DEFAULT_TEMPLATE_FILENAME_EXTENSION

#define DEFAULT_BEFORE_BEFORE_INCLUDE "<a href=\""
#define DEFAULT_AFTER_BEFORE_INCLUDE "\">"
#define DEFAULT_AFTER_INCLUDE "</a>"

/**
 **********************************************************************
 *  Class: cCXXCGI
 *
 * Author: $author$
 *   Date: 5/1/2008
 **********************************************************************
 */
class cCXXCGI
: virtual public cCXXCGILexer::cDelegate,
  virtual public cCXXLexer::cDelegate,
  public cDocumentTemplateCGI
{
public:
    typedef cDocumentTemplateCGI cExtends;
    typedef cCXXCGI cDerives;

    typedef eError (cDerives::*mOn)
    (const char* text, int token);

    mOn m_onText;
    mOn m_onAfter;

    cCGIStream m_cgiStream;

    cCXXLexer::cSource m_documentSource;
    cCXXLexer m_documentLexer;

    cCXXCGILexer::cSource m_templateSource;
    cCXXCGILexer m_templateLexer;

    cCharString m_beginText;
    cCharString m_endText;

    cCharString m_before;
    cCharString m_after;

    cCharString m_beforeBeforeInclude;
    cCharString m_afterBeforeInclude;
    cCharString m_afterInclude;

    cCharString m_beforeComment;
    cCharString m_afterComment;

    cCharString m_beforeCommentEOL;
    cCharString m_afterCommentEOL;

    cCharString m_beforeProcessor;
    cCharString m_afterProcessor;

    cCharString m_beforeKeyword;
    cCharString m_afterKeyword;

    cCharString m_beforeString;
    cCharString m_afterString;

    cCharString m_beforeChar;
    cCharString m_afterChar;

    cCharString m_includedName;
    cCharCounter m_charCounter;

    /**
     **********************************************************************
     * Constructor: cCXXCGI
     *
     *      Author: $author$
     *        Date: 5/1/2008
     **********************************************************************
     */
    cCXXCGI
    (const tChar* cgiNameChars=DEFAULT_CXXCGI_NAME,
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

      m_onText(&cDerives::OnCXXCGIBeginText),
      m_onAfter(&cDerives::OnCXXCGIAfterText),

      m_cgiStream(*this),

      m_documentLexer
      (*this, m_cgiStream, 
       m_documentFile, m_documentSource),

      m_templateLexer
      (*this, m_cgiStream, 
       m_templateFile, m_templateSource) 
    {
        m_templateFileNameChars = DEFAULT_TEMPLATE_FILENAME;

        m_beforeBeforeInclude.Assign(DEFAULT_BEFORE_BEFORE_INCLUDE);
        m_afterBeforeInclude.Assign(DEFAULT_AFTER_BEFORE_INCLUDE);
        m_afterInclude.Assign(DEFAULT_AFTER_INCLUDE);
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

        SetContentType(GetContentTypeHTML());

        if (!(documentFileNameChars = GetDocumentFileName(length, false, true)))
            return MissingDocumentFileName();

        if (!(templateFileNameChars = GetTemplateFileName(length, true)))
        if (!(templateFileNameChars = m_templateFileNameChars))
            return MissingTemplateFileName();

        if ((error = m_documentFile.Open(documentFileNameChars)))
            return  UnableToOpenFileName(documentFileNameChars);
        else
        if ((error = m_templateFile.Open(templateFileNameChars)))
        {
            m_documentFile.Close();
            return  UnableToOpenFileName(templateFileNameChars);
        }
        else
        {
            m_templateLexer.yylex();
            m_templateFile.Close();

            if ((text = m_beginText.HasChars(length)))
                OutputContent(text, length);
            else
            OutputContent
            ("<html><head></head><body><pre>");

            m_documentLexer.yylex();
            m_documentFile.Close();

            if ((text = m_endText.HasChars(length)))
                OutputContent(text, length);
            else
            OutputContent("</pre><body></html>");
        }
        return err;
    }

    /**
     **********************************************************************
     * Function: OnCXXCGIBeginBefore
     *
     *   Author: $author$
     *     Date: 5/4/2008
     **********************************************************************
     */
    virtual eError OnCXXCGIBeginBefore
    (const char* text,
     int token=-1) 
    {
        eError error = e_ERROR_NONE;
        m_before.Assign(text);
        m_after.Clear();
        return error;
    }
    /**
     **********************************************************************
     * Function: OnCXXCGIBeforeComment
     *
     *   Author: $author$
     *     Date: 5/4/2008
     **********************************************************************
     */
    virtual eError OnCXXCGIBeforeComment
    (const char* text,
     int token=-1) 
    {
        eError error = e_ERROR_NONE;
        const char* chars;
        tLength length;

        if ((chars = m_before.HasChars(length)))
            m_beforeComment.Assign(chars, length);
        else m_beforeComment.Clear();
        m_onAfter = &cDerives::OnCXXCGIAfterComment;
        return error;
    }
    /**
     **********************************************************************
     * Function: OnCXXCGIBeforeCommentEOL
     *
     *   Author: $author$
     *     Date: 5/4/2008
     **********************************************************************
     */
    virtual eError OnCXXCGIBeforeCommentEOL
    (const char* text,
     int token=-1) 
    {
        eError error = e_ERROR_NONE;
        const char* chars;
        tLength length;

        if ((chars = m_before.HasChars(length)))
            m_beforeCommentEOL.Assign(chars, length);
        else m_beforeCommentEOL.Clear();
        m_onAfter = &cDerives::OnCXXCGIAfterCommentEOL;
        return error;
    }
    /**
     **********************************************************************
     * Function: OnCXXCGIBeforeProcessor
     *
     *   Author: $author$
     *     Date: 5/4/2008
     **********************************************************************
     */
    virtual eError OnCXXCGIBeforeProcessor
    (const char* text,
     int token=-1) 
    {
        eError error = e_ERROR_NONE;
        const char* chars;
        tLength length;

        if ((chars = m_before.HasChars(length)))
            m_beforeProcessor.Assign(chars, length);
        else m_beforeProcessor.Clear();
        m_onAfter = &cDerives::OnCXXCGIAfterProcessor;
        return error;
    }
    /**
     **********************************************************************
     * Function: OnCXXCGIBeforeKeyword
     *
     *   Author: $author$
     *     Date: 5/4/2008
     **********************************************************************
     */
    virtual eError OnCXXCGIBeforeKeyword
    (const char* text,
     int token=-1) 
    {
        eError error = e_ERROR_NONE;
        const char* chars;
        tLength length;

        if ((chars = m_before.HasChars(length)))
            m_beforeKeyword.Assign(chars, length);
        else m_beforeKeyword.Clear();
        m_onAfter = &cDerives::OnCXXCGIAfterKeyword;
        return error;
    }
    /**
     **********************************************************************
     * Function: OnCXXCGIBeforeString
     *
     *   Author: $author$
     *     Date: 5/4/2008
     **********************************************************************
     */
    virtual eError OnCXXCGIBeforeString
    (const char* text,
     int token=-1) 
    {
        eError error = e_ERROR_NONE;
        const char* chars;
        tLength length;

        if ((chars = m_before.HasChars(length)))
            m_beforeString.Assign(chars, length);
        else m_beforeString.Clear();
        m_onAfter = &cDerives::OnCXXCGIAfterString;
        return error;
    }
    /**
     **********************************************************************
     * Function: OnCXXCGIBeforeChar
     *
     *   Author: $author$
     *     Date: 5/4/2008
     **********************************************************************
     */
    virtual eError OnCXXCGIBeforeChar
    (const char* text,
     int token=-1) 
    {
        eError error = e_ERROR_NONE;
        const char* chars;
        tLength length;

        if ((chars = m_before.HasChars(length)))
            m_beforeChar.Assign(chars, length);
        else m_beforeChar.Clear();
        m_onAfter = &cDerives::OnCXXCGIAfterChar;
        return error;
    }

    /**
     **********************************************************************
     * Function: OnCXXCGIAfterText
     *
     *   Author: $author$
     *     Date: 5/4/2008
     **********************************************************************
     */
    virtual eError OnCXXCGIAfterText
    (const char* text,
     int token=-1) 
    {
        eError error = e_ERROR_NONE;
        m_after.Append(text);
        return error;
    }
    /**
     **********************************************************************
     * Function: OnCXXCGIEndAfter
     *
     *   Author: $author$
     *     Date: 5/4/2008
     **********************************************************************
     */
    virtual eError OnCXXCGIEndAfter
    (const char* text,
     int token=-1) 
    {
        eError error = e_ERROR_NONE;
        if (m_onAfter)
            error = (this->*m_onAfter)(text, token);
        return error;
    }
    /**
     **********************************************************************
     * Function: OnCXXCGIAfterComment
     *
     *   Author: $author$
     *     Date: 5/4/2008
     **********************************************************************
     */
    eError OnCXXCGIAfterComment
    (const char* text,
     int token=-1) 
    {
        eError error = e_ERROR_NONE;
        const char* chars;
        tLength length;

        if ((chars = m_after.HasChars(length)))
            m_afterComment.Assign(chars, length);
        else m_afterComment.Clear();
        return error;
    }
    /**
     **********************************************************************
     * Function: OnCXXCGIAfterCommentEOL
     *
     *   Author: $author$
     *     Date: 5/4/2008
     **********************************************************************
     */
    eError OnCXXCGIAfterCommentEOL
    (const char* text,
     int token=-1) 
    {
        eError error = e_ERROR_NONE;
        const char* chars;
        tLength length;

        if ((chars = m_after.HasChars(length)))
            m_afterCommentEOL.Assign(chars, length);
        else m_afterCommentEOL.Clear();
        return error;
    }
    /**
     **********************************************************************
     * Function: OnCXXCGIAfterProcessor
     *
     *   Author: $author$
     *     Date: 5/4/2008
     **********************************************************************
     */
    eError OnCXXCGIAfterProcessor
    (const char* text,
     int token=-1) 
    {
        eError error = e_ERROR_NONE;
        const char* chars;
        tLength length;

        if ((chars = m_after.HasChars(length)))
            m_afterProcessor.Assign(chars, length);
        else m_afterProcessor.Clear();
        return error;
    }
    /**
     **********************************************************************
     * Function: OnCXXCGIAfterKeyword
     *
     *   Author: $author$
     *     Date: 5/4/2008
     **********************************************************************
     */
    eError OnCXXCGIAfterKeyword
    (const char* text,
     int token=-1) 
    {
        eError error = e_ERROR_NONE;
        const char* chars;
        tLength length;

        if ((chars = m_after.HasChars(length)))
            m_afterKeyword.Assign(chars, length);
        else m_afterKeyword.Clear();
        return error;
    }
    /**
     **********************************************************************
     * Function: OnCXXCGIAfterString
     *
     *   Author: $author$
     *     Date: 5/4/2008
     **********************************************************************
     */
    eError OnCXXCGIAfterString
    (const char* text,
     int token=-1) 
    {
        eError error = e_ERROR_NONE;
        const char* chars;
        tLength length;

        if ((chars = m_after.HasChars(length)))
            m_afterString.Assign(chars, length);
        else m_afterString.Clear();
        return error;
    }
    /**
     **********************************************************************
     * Function: OnCXXCGIAfterChar
     *
     *   Author: $author$
     *     Date: 5/4/2008
     **********************************************************************
     */
    eError OnCXXCGIAfterChar
    (const char* text,
     int token=-1) 
    {
        eError error = e_ERROR_NONE;
        const char* chars;
        tLength length;

        if ((chars = m_after.HasChars(length)))
            m_afterChar.Assign(chars, length);
        else m_afterChar.Clear();
        return error;
    }

    /**
     **********************************************************************
     * Function: OnCXXCGIEndBody
     *
     *   Author: $author$
     *     Date: 5/4/2008
     **********************************************************************
     */
    virtual eError OnCXXCGIEndBody
    (const char* text,
     int token=-1) 
    {
        eError error = e_ERROR_NONE;
        m_onText = &cDerives::OnCXXCGIEndText;
        return error;
    }

    /**
     **********************************************************************
     * Function: OnCXXCGIText
     *
     *   Author: $author$
     *     Date: 5/3/2008
     **********************************************************************
     */
    virtual eError OnCXXCGIText
    (const char* text,
     int token=-1) 
    {
        eError error = e_ERROR_NONE;
        if (m_onText)
            error = (this->*m_onText)(text, token);
        return error;
    }
    /**
     **********************************************************************
     * Function: OnCXXCGIBeginText
     *
     *   Author: $author$
     *     Date: 5/3/2008
     **********************************************************************
     */
    eError OnCXXCGIBeginText
    (const char* text,
     int token=-1) 
    {
        eError error = e_ERROR_NONE;
        m_beginText.Append(text);
        return error;
    }
    /**
     **********************************************************************
     * Function: OnCXXCGIEndText
     *
     *   Author: $author$
     *     Date: 5/3/2008
     **********************************************************************
     */
    eError OnCXXCGIEndText
    (const char* text,
     int token=-1) 
    {
        eError error = e_ERROR_NONE;
        m_endText.Append(text);
        return error;
    }

    /**
     **********************************************************************
     * Function: OnIncluded
     *
     *   Author: $author$
     *     Date: 5/12/2008
     **********************************************************************
     */
    virtual eError OnIncluded
    (const char* text,
     int token=-1) 
    {
        eError error = e_ERROR_NONE;
        const char* chars;
        TLENGTH length;

        if ((chars = m_beforeBeforeInclude.HasChars(length)))
            OutputContent(chars, length);

        if (2 < (length = m_charCounter.LengthOf(text)))
        if (0 < (length = m_includedName.Assign(text+1, length-2)))
        if ((chars = m_includedName.HasChars(length)))
        if ((chars = Exists(chars)))
            OutputContent(chars);

        if ((chars = m_afterBeforeInclude.HasChars(length)))
            OutputContent(chars, length);

        OnStringLiteral(text, token);

        if ((chars = m_afterInclude.HasChars(length)))
            OutputContent(chars, length);
        return error;
    }

    /**
     **********************************************************************
     * Function: OnBeginComment
     *
     *   Author: $author$
     *     Date: 1/8/2006
     **********************************************************************
     */
    virtual void OnBeginComment
    (const char* text, int token=-1) 
    {
        const char* before;
        tLength length;

        if (!(before = m_beforeComment.HasChars(length)))
            before = "<font class=\"comment\">";
        OutputContentL
        (before, text, NULL_POINTER);
    }
    /**
     **********************************************************************
     * Function: OnEndComment
     *
     *   Author: $author$
     *     Date: 1/8/2006
     **********************************************************************
     */
    virtual void OnEndComment
    (const char* text, int token=-1) 
    {
        const char* after;
        tLength length;

        if (!(after = m_afterComment.HasChars(length)))
            after = "</font>";
        OutputContentL
        (text, after, NULL_POINTER);
    }
    /**
     **********************************************************************
     * Function: OnComment
     *
     *   Author: $author$
     *     Date: 1/8/2006
     **********************************************************************
     */
    virtual void OnComment
    (const char* text, int token=-1) 
    {
        OutputContent(text);
    }
    /**
     **********************************************************************
     * Function: OnBeginCommentEOL
     *
     *   Author: $author$
     *     Date: 1/8/2006
     **********************************************************************
     */
    virtual void OnBeginCommentEOL
    (const char* text, int token=-1) 
    {
        const char* before;
        tLength length;

        if (!(before = m_beforeCommentEOL.HasChars(length)))
            before = "<font class=\"commenteol\">";
        OutputContentL
        (before, text, NULL_POINTER);
    }
    /**
     **********************************************************************
     * Function: OnEndCommentEOL
     *
     *   Author: $author$
     *     Date: 1/8/2006
     **********************************************************************
     */
    virtual void OnEndCommentEOL
    (const char* text, int token=-1) 
    {
        const char* after;
        tLength length;

        if (!(after = m_afterCommentEOL.HasChars(length)))
            after = "</font>";
        OutputContentL
        (text, after, NULL_POINTER);
    }
    /**
     **********************************************************************
     * Function: OnCommentEOL
     *
     *   Author: $author$
     *     Date: 1/8/2006
     **********************************************************************
     */
    virtual void OnCommentEOL
    (const char* text, int token=-1) 
    {
        OutputContent(text);
    }
    /**
     **********************************************************************
     * Function: OnProcessor
     *
     *   Author: $author$
     *     Date: 1/8/2006
     **********************************************************************
     */
    virtual void OnProcessor
    (const char* text, int token=-1) 
    {
        const char* before;
        const char* after;
        tLength length;

        if (!(before = m_beforeProcessor.HasChars(length)))
            before = "<font class=\"processor\">";
        if (!(after = m_afterProcessor.HasChars(length)))
            after = "</font>";
        OutputContentL
        (before, text, after, NULL_POINTER);
    }
    /**
     **********************************************************************
     * Function: OnReserved
     *
     *   Author: $author$
     *     Date: 1/8/2006
     **********************************************************************
     */
    virtual void OnReserved
    (const char* text, int token=-1) 
    {
        const char* before;
        const char* after;
        tLength length;

        if (!(before = m_beforeKeyword.HasChars(length)))
            before = "<font class=\"keyword\">";
        if (!(after = m_afterKeyword.HasChars(length)))
            after = "</font>";
        OutputContentL
        (before, text, after, NULL_POINTER);
    }
    /**
     **********************************************************************
     * Function: OnStringLiteral
     *
     *   Author: $author$
     *     Date: 5/2/2008
     **********************************************************************
     */
    virtual void OnStringLiteral
    (const char* text,
     int token=-1) 
    {
        const char* before;
        const char* after;
        tLength length;

        if (!(before = m_beforeString.HasChars(length)))
            before = "<font class=\"string\">";
        if (!(after = m_afterString.HasChars(length)))
            after = "</font>";
        OnString
        (before, text, after);
    }
    /**
     **********************************************************************
     * Function: OnCharLiteral
     *
     *   Author: $author$
     *     Date: 5/2/2008
     **********************************************************************
     */
    virtual void OnCharLiteral
    (const char* text,
     int token=-1) 
    {
        const char* before;
        const char* after;
        tLength length;

        if (!(before = m_beforeChar.HasChars(length)))
            before = "<font class=\"char\">";
        if (!(after = m_afterChar.HasChars(length)))
            after = "</font>";
        OnString
        (before, text, after);
    }
    /**
     **********************************************************************
     * Function: OnCommentLT
     *
     *   Author: $author$
     *     Date: 1/8/2006
     **********************************************************************
     */
    virtual void OnCommentLT
    (const char* text, int token=-1) 
    {
        OnLT(text, token);
    }
    /**
     **********************************************************************
     * Function: OnCommentGT
     *
     *   Author: $author$
     *     Date: 1/8/2006
     **********************************************************************
     */
    virtual void OnCommentGT
    (const char* text, int token=-1) 
    {
        OnGT(text, token);
    }
    /**
     **********************************************************************
     * Function: OnLT
     *
     *   Author: $author$
     *     Date: 1/8/2006
     **********************************************************************
     */
    virtual void OnLT
    (const char* text, int token=-1) 
    {
        OutputContent("&lt;");
    }
    /**
     **********************************************************************
     * Function: OnGT
     *
     *   Author: $author$
     *     Date: 1/8/2006
     **********************************************************************
     */
    virtual void OnGT
    (const char* text, int token=-1) 
    {
        OutputContent("&gt;");
    }
    /**
     **********************************************************************
     * Function: OnString
     *
     *   Author: $author$
     *     Date: 1/8/2006
     **********************************************************************
     */
    virtual void OnString
    (const char* before, 
     const char* text, 
     const char* after) 
    {
        const char* t;
        const char* i;
        char c;
        TLENGTH length;

        OutputContent(before);

        for (t=text, i=text; (c=*i); i++)
        {
            if ('<' != c)
            if ('>' != c)
                continue;
            else 
            {
                if (0 < (length = (TLENGTH)(i-t)))
                    OutputContent(t, length);
                OnGT(i);
            }
            else 
            {
                if (0 < (length = (TLENGTH)(i-t)))
                    OutputContent(t, length);
                OnLT(i);
            }
            t = i+1;
        }
        
        if (0 < (length = (TLENGTH)(i-t)))
            OutputContent(t, length);

        OutputContent(after);
    }
    /**
     **********************************************************************
     * Function: OnText
     *
     *   Author: $author$
     *     Date: 1/8/2006
     **********************************************************************
     */
    virtual void OnText
    (const char* text, int token=-1) 
    {
        OutputContent(text);
    }

    /**
     **********************************************************************
     * Function: Exists
     *
     *   Author: $author$
     *     Date: 5/12/2008
     **********************************************************************
     */
    virtual const char* Exists
    (const char* chars) 
    {
        const char* uriChars = chars;
        return uriChars;
    }
};

#endif /* _CCXXCGI_HXX */
