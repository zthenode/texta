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
 *   File: cacparsercgi.hxx
 *
 * Author: $author$
 *   Date: 7/31/2008
 **********************************************************************
 */
#ifndef _CACPARSERCGI_HXX
#define _CACPARSERCGI_HXX

#define DEFAULT_PARSERCGI_NAME "accgi"
#define DEFAULT_DOCUMENT_FILENAME_EXTENSION "ada"
#define DEFAULT_TEMPLATE_FILENAME_EXTENSION "accgi"

#include "cacparser.hxx"
#include "cparsercgi.hxx"

/**
 **********************************************************************
 *  Class: cACParserCGI
 *
 * Author: $author$
 *   Date: 7/31/2008
 **********************************************************************
 */
class cACParserCGI
: virtual public cLexerCGILexerDelegate,
  virtual public cACLexerDelegate,
  public cDocumentTemplateCGI
{
public:
    typedef cACLexerDelegate cImplements;
    typedef cDocumentTemplateCGI cExtends;
    typedef cACParserCGI cDerives;

    cCGIStream m_cgiStream;

    cLexerSource m_documentSource;
    cACParser m_documentParser;

    cLexerSource m_templateSource;
    cLexerCGILexer m_templateLexer;

    const char* m_beforeChars;
    const char* m_afterChars;

    cCharString m_before;
    cCharString m_after;

    /**
     **********************************************************************
     * Constructor: cACParserCGI
     *
     *      Author: $author$
     *        Date: 7/31/2008
     **********************************************************************
     */
    cACParserCGI
    (const tChar* cgiNameChars=DEFAULT_PARSERCGI_NAME,
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

      m_documentParser
      (*this, m_cgiStream, 
       m_documentFile, m_documentSource),

      m_templateLexer
      (*this, m_cgiStream, 
       m_templateFile, m_templateSource),

      m_beforeChars(DEFAULT_BEFORE_CHARS),
      m_afterChars(DEFAULT_AFTER_CHARS) 
    {
        tLength length;
        if (0 < (m_templateFileName.Assign(DEFAULT_TEMPLATE_FILENAME)))
            m_templateFileNameChars = m_templateFileName.Chars(length);
    }
    /**
     **********************************************************************
     * Function: RunCommandOrCGI
     *
     *   Author: $author$
     *     Date: 7/31/2008
     **********************************************************************
     */
    virtual int RunCommandOrCGI
    (int argc,
     const char** argv,
     const char** env) 
    {
        int err = 0;
        eError error;
        TLENGTH length;
        const char* text;
        const char* documentFileNameChars;
        const char* templateFileNameChars;

        DBF("()...\n");

        SetContentType(GetContentTypeHTML());

        if (!(documentFileNameChars = GetDocumentFileName(length, false, true)))
            return MissingDocumentFileName();

        if (!(templateFileNameChars = GetTemplateFileName(length, true)))
        if (!(templateFileNameChars = m_templateFileNameChars))
            DBW("() missing template filename\n");

        if ((error = m_documentFile.Open(documentFileNameChars)))
            return UnableToOpenFileName(documentFileNameChars);
        else
        {
            if (templateFileNameChars)
            {
                DBI("() template file is \"%s\"\n", templateFileNameChars);

                if ((error = m_templateFile.Open(templateFileNameChars)))
                    DBW("() unable to open template file \"%s\"\n", templateFileNameChars);
                else
                {
                    DBI("() yylex()...\n");
                    m_templateLexer.yylex();
                    DBI("() ...yylex()\n");
                    m_templateFile.Close();
                }
            }
            
            if ((text = HasChars(m_before,m_beforeChars)))
                OutputBeforeContentText(text);

            m_documentParser.yyparse();
            m_documentFile.Close();

            if ((text = HasChars(m_after,m_afterChars)))
                OutputAfterContentText(text);
        }
        return err;
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
        DBT("(%s)\n", text);
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
        DBT("(%s)\n", text);
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
     * Function: OutputBeforeContentText
     *
     *   Author: $author$
     *     Date: 8/14/2008
     **********************************************************************
     */
    virtual tLength OutputBeforeContentText
    (const char* chars, tLength length=-1) 
    {
        tLength count = TransformOutputContent(chars,length);
        return count;
    }
    /**
     **********************************************************************
     * Function: OutputAfterContentText
     *
     *   Author: $author$
     *     Date: 8/14/2008
     **********************************************************************
     */
    virtual tLength OutputAfterContentText
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
        tLength count = OutputEncodedContent(chars,length);
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
     * Function: OutputEncodedContent
     *
     *   Author: $author$
     *     Date: 8/16/2008
     **********************************************************************
     */
    virtual tLength OutputEncodedContent
    (const char* chars, tLength length=-1) 
    {
        tLength count = OutputHTMLEncodedContent(chars, length);
        return count;
    }
    /**
     **********************************************************************
     * Function: OutputPlainEncodedContent
     *
     *   Author: $author$
     *     Date: 8/16/2008
     **********************************************************************
     */
    virtual tLength OutputPlainEncodedContent
    (const char* chars, tLength length=-1) 
    {
        tLength count = CTHIS OutputContent(chars, length);
        return count;
    }
    /**
     **********************************************************************
     * Function: OutputHTMLEncodedContent
     *
     *   Author: $author$
     *     Date: 8/16/2008
     **********************************************************************
     */
    virtual tLength OutputHTMLEncodedContent
    (const char* chars, tLength length=-1) 
    {
        tLength count = 0;
        const char* t;
        const char* i;
        char c;

        for (t=chars, i=chars; (c=*i); i++)
        {
            if ('<' != c)
            if ('>' != c)
                continue;
            else 
            {
                if (0 < (length = (tLength)(i-t)))
                    CTHIS OutputContent(t, length);
                OutputHTMLEncodedGT(i);
            }
            else 
            {
                if (0 < (length = (tLength)(i-t)))
                    CTHIS OutputContent(t, length);
                OutputHTMLEncodedLT(i);
            }
            t = i+1;
        }
        if (0 < (length = (tLength)(i-t)))
            CTHIS OutputContent(t, length);
        return count;
    }
    /**
     **********************************************************************
     * Function: OutputHTMLEncodedLT
     *
     *   Author: $author$
     *     Date: 8/16/2008
     **********************************************************************
     */
    virtual tLength OutputHTMLEncodedLT
    (const char* chars, tLength length=-1) 
    {
        tLength count = CTHIS OutputContent("&lt;");
        return count;
    }
    /**
     **********************************************************************
     * Function: OutputHTMLEncodedGT
     *
     *   Author: $author$
     *     Date: 8/16/2008
     **********************************************************************
     */
    virtual tLength OutputHTMLEncodedGT
    (const char* chars, tLength length=-1) 
    {
        tLength count = CTHIS OutputContent("&gt;");
        return count;
    }

    /**
     **********************************************************************
     * Function: HasChars
     *
     *   Author: $author$
     *     Date: 8/16/2008
     **********************************************************************
     */
    virtual const tChar* HasChars
    (cCharString& string,
     const tChar*& stringChars) 
    {
        const tChar* chars = 0;
        tLength length;
        if (!(chars = stringChars))
            chars = (stringChars = string.HasChars(length));
        return chars;
    }
};
#endif /* _CACPARSERCGI_HXX */
