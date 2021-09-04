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
 *   File: clexertcgi.hxx
 *
 * Author: $author$
 *   Date: 8/13/2008
 **********************************************************************
 */
#ifndef _CLEXERTCGI_HXX
#define _CLEXERTCGI_HXX

#include "clexercgi.hxx"
#include "ct.hxx"

#define DEFAULT_DOCUMENT_FILENAME_NAME_NAME "document_filename_name"
#define DEFAULT_DOCUMENT_LOCATION_NAME_NAME "document_location_name"
#define DEFAULT_DOCUMENT_SCRIPT_NAME_NAME "document_script_name"
#define DEFAULT_DOCUMENT_FRAGMENT_NAME_NAME "document_fragment_name"

#if !defined(DEFAULT_DOCUMENT_LOCATION_NAME) 
#define DEFAULT_DOCUMENT_LOCATION_NAME "document_location"
#endif /* !defined(DEFAULT_DOCUMENT_LOCATION_NAME) */

#if !defined(DEFAULT_DOCUMENT_SCRIPT_NAME) 
#define DEFAULT_DOCUMENT_SCRIPT_NAME "document_script"
#endif /* !defined(DEFAULT_DOCUMENT_SCRIPT_NAME) */

#if !defined(DEFAULT_DOCUMENT_FRAGMENT_NAME) 
#define DEFAULT_DOCUMENT_FRAGMENT_NAME "document_fragment"
#endif /* !defined(DEFAULT_DOCUMENT_FRAGMENT_NAME) */

#undef CDB_CLASS
#define CDB_CLASS "cLexerTCGIT"
/**
 **********************************************************************
 *  Class: cLexerTCGIT
 *
 * Author: $author$
 *   Date: 8/13/2008
 **********************************************************************
 */
template
<class TLexer,
 class TLexerDelegate,
 class TLexerSource=cLexerSource,
 class TChar=CHAR,
 class TSize=TSIZE,
 class TLength=TLENGTH>
 
class cLexerTCGIT
: public cLexerCGIT
  <TLexer, TLexerDelegate, TLexerSource>
{
public:
    typedef cLexerCGIT
    <TLexer, TLexerDelegate, TLexerSource> cExtends;
    typedef cLexerTCGIT cDerives;

    typedef TChar tChar;
    typedef TSize tSize;
    typedef TLength tLength;

    const char* m_documentFileNameNameNameChars;
    const char* m_documentLocationNameNameChars;
    const char* m_documentLocationNameChars;
    const char* m_documentScriptNameNameChars;
    const char* m_documentScriptNameChars;
    const char* m_documentFragmentNameNameChars;
    const char* m_documentFragmentNameChars;
    const char* m_documentFragmentChars;

    cT m_t;
    cCharString m_untransformedContent;
    cCharString m_transformedContent;
    cCharString m_documentFragment;

    /**
     **********************************************************************
     * Constructor: cLexerTCGIT
     *
     *      Author: $author$
     *        Date: 8/13/2008
     **********************************************************************
     */
    cLexerTCGIT
    (const tChar* cgiNameChars=DEFAULT_LEXERCGI_NAME,
     const tChar* documentFileNameExtensionChars=DEFAULT_DOCUMENT_FILENAME_EXTENSION,
     const tChar* documentFileNameNameChars=DEFAULT_DOCUMENT_FILENAME_NAME,
     const tChar* documentURINameChars=DEFAULT_DOCUMENT_URI_NAME,
     const tChar* templateFileNameExtensionChars=DEFAULT_TEMPLATE_FILENAME_EXTENSION,
     const tChar* templateFileNameNameChars=DEFAULT_TEMPLATE_FILENAME_NAME,
     const tChar* templateURINameChars=DEFAULT_TEMPLATE_URI_NAME)
    : cExtends
      (cgiNameChars,
       documentFileNameExtensionChars,
       documentFileNameNameChars,
       documentURINameChars,
       templateFileNameExtensionChars,
       templateFileNameNameChars,
       templateURINameChars),

       m_documentFileNameNameNameChars
       (DEFAULT_DOCUMENT_FILENAME_NAME_NAME),

       m_documentLocationNameNameChars
       (DEFAULT_DOCUMENT_LOCATION_NAME_NAME),

       m_documentLocationNameChars
       (DEFAULT_DOCUMENT_LOCATION_NAME),

       m_documentScriptNameNameChars
       (DEFAULT_DOCUMENT_SCRIPT_NAME_NAME),

       m_documentScriptNameChars
       (DEFAULT_DOCUMENT_SCRIPT_NAME),

       m_documentFragmentNameNameChars
       (DEFAULT_DOCUMENT_FRAGMENT_NAME_NAME),

       m_documentFragmentNameChars
       (DEFAULT_DOCUMENT_FRAGMENT_NAME),

       m_documentFragmentChars(0)
    {
    }
    /**
     **********************************************************************
     * Function: RunCommandOrCGI
     *
     *   Author: $author$
     *     Date: 8/13/2008
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
        const char* documentLocationChars;
        const char* documentScriptChars;
        const char* documentFragmentChars;
        cTVariableInterface* tVariable;

        CTHIS SetContentType(CTHIS GetContentTypeHTML());

        if ((error = m_t.Initialize()))
            CTHIS OutputContentL
            (H1_, CTHIS m_cgiNameChars, _H1, 
             B_, "failed on m_t.Initialize()", _B, BR, NULL_POINTER);
        else
        {
            if (CTHIS m_documentFileNameNameChars)
            {
                if (CTHIS m_documentFileNameNameNameChars)
                    m_t.SetVariable
                    (CTHIS m_documentFileNameNameNameChars,-1,
                     CTHIS m_documentFileNameNameChars);

                if ((documentFileNameChars = 
                    CTHIS GetDocumentFileName(length, false, true)))
                    m_t.SetVariable
                    (CTHIS m_documentFileNameNameChars,-1,
                     documentFileNameChars, length);
            }

            if (CTHIS m_documentLocationNameChars)
            {
                if (CTHIS m_documentLocationNameNameChars)
                    m_t.SetVariable
                    (CTHIS m_documentLocationNameNameChars,-1,
                     CTHIS m_documentLocationNameChars);

                if ((documentLocationChars = 
                    CTHIS GetDocumentLocation(length)))
                    m_t.SetVariable
                    (CTHIS m_documentLocationNameChars,-1,
                     documentLocationChars, length);
            }

            if (CTHIS m_documentScriptNameChars)
            {
                if (CTHIS m_documentScriptNameNameChars)
                    m_t.SetVariable
                    (CTHIS m_documentScriptNameNameChars,-1,
                     CTHIS m_documentScriptNameChars);

                if ((documentScriptChars = 
                    CTHIS GetDocumentScript(length)))
                    m_t.SetVariable
                    (CTHIS m_documentScriptNameChars,-1,
                     documentScriptChars, length);
            }

            if (CTHIS m_documentFragmentNameChars)
            {
                if (CTHIS m_documentFragmentNameNameChars)
                    m_t.SetVariable
                    (CTHIS m_documentFragmentNameNameChars,-1,
                     CTHIS m_documentFragmentNameChars);
            }

            SetTVariablesFromForm(m_t);

            if (CTHIS m_documentFragmentNameChars)
            if ((tVariable = m_t.GetVariable(CTHIS m_documentFragmentNameChars)))
            if ((documentFragmentChars = tVariable->GetValue()))
            if (0 < (CTHIS m_documentFragment.Assign(documentFragmentChars)))
                CTHIS m_documentFragmentChars = CTHIS m_documentFragment.HasChars(length);

            err = cExtends::RunCommandOrCGI(argc, argv, env);
            m_t.Finalize();
        }
        return err;
    }
    /**
     **********************************************************************
     * Function: OnSetDocumentFileName
     *
     *   Author: $author$
     *     Date: 9/15/2008
     **********************************************************************
     */
    virtual tLength OnSetDocumentFileName
    (const tChar* chars, tLength length=-1) 
    {
        tLength count = length;
        if (CTHIS m_documentFileNameNameChars)
            m_t.SetVariable
            (CTHIS m_documentFileNameNameChars, -1, chars, length);
        return count;
    }
    /**
     **********************************************************************
     * Function: OnBeginT
     *
     *   Author: $author$
     *     Date: 5/11/2008
     **********************************************************************
     */
    virtual eError OnBeginT
    (const char* beginChars,
     const char* text,
     int token=-1) 
    {
        eError error = e_ERROR_NONE;
        if (beginChars)
        {
            if (CTHIS m_documentFragmentNameChars)
                m_t.SetVariable
                (CTHIS m_documentFragmentNameChars,-1, text);

            CTHIS TransformOutputContentText(beginChars);
        }
        CTHIS OnText(text);
        return error;
    }
    /**
     **********************************************************************
     * Function: SetTVariablesFromForm
     *
     *   Author: $author$
     *     Date: 4/3/2008
     **********************************************************************
     */
    virtual tLength SetTVariablesFromForm(cTInterface& t) 
    {
        tLength count = 0;
        tLength  length;
        const tChar* name;
        const tChar* value;
        cHTTPFormFieldIterator end;
        cHTTPFormFieldIterator i;
        cHTTPFormFieldReference f;
        cTVariableInterface* v;

        if ((i = CTHIS m_formFields.begin())
            != (end = CTHIS m_formFields.end()))
        do
        {
            if ((f = (*i)))
            if ((name = f->GetName(length)) && (0 < length))
            if ((value = f->GetValue(length)))
            if ((v = t.SetVariable(name,-1, value,-1)))
                count++;
        }
        while ((++i) != end);
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
        tLength count = 0;
        eError error;
        
        if (0 < (length = m_untransformedContent.Assign(chars, length)))
        if (0 <= (length = m_transformedContent.Clear()))
        if (!(error = m_t.Expand(m_transformedContent, m_untransformedContent)))
        if ((chars = m_transformedContent.HasChars(length)))
            count = CTHIS OutputContent(chars, length);
        return count;
    }
};
#undef CDB_CLASS

#endif /* _CLEXERTCGI_HXX */
