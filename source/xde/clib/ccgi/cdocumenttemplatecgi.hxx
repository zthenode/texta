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
 *   File: cdocumenttemplatecgi.hxx
 *
 * Author: $author$
 *   Date: 3/27/2008
 **********************************************************************
 */
#ifndef _CDOCUMENTTEMPLATECGI_HXX
#define _CDOCUMENTTEMPLATECGI_HXX

#include "ctemplatecgi.hxx"
#include "cdocumentnamelist.hxx"
#include "ccgistream.hxx"

/**
 **********************************************************************
 *  Class: cDocumentTemplateCGI
 *
 * Author: $author$
 *   Date: 5/3/2008
 **********************************************************************
 */
class cDocumentTemplateCGI
: public cTemplateCGI
{
public:
    typedef cTemplateCGI cExtends;
    typedef cDocumentTemplateCGI cDerives;

    const tChar* m_documentFileNameExtensionChars;
    const tChar* m_documentFileNameNameChars;
    const tChar* m_documentURINameChars;

    const tChar* m_documentFileNameChars;
    tLength m_documentFileNameLength;
    cCharString m_documentFileName;
    cCharString m_absoluteDocumentFileName;

    const tChar* m_documentURIChars;
    tLength m_documentURILength;
    cCharString m_documentURI;
    cCharString m_absoluteDocumentURI;

    cCharFile m_documentFile;

    /**
     **********************************************************************
     * Constructor: cDocumentTemplateCGI
     *
     *      Author: $author$
     *        Date: 5/3/2008
     **********************************************************************
     */
    cDocumentTemplateCGI
    (const tChar* documentFileNameExtensionChars,
     const tChar* documentFileNameNameChars,
     const tChar* documentURINameChars,
     const tChar* templateFileNameExtensionChars,
     const tChar* templateFileNameNameChars,
     const tChar* templateURINameChars,
     const tChar* cgiNameChars,
     const tChar* templateFileNameChars=0,
     const tChar* templateURIChars=0,
     const tChar* documentFileNameChars=0,
     const tChar* documentURIChars=0)
    : cExtends
      (templateFileNameExtensionChars, 
       templateFileNameNameChars,
       templateURINameChars, 
       cgiNameChars, 
       templateFileNameChars,
       templateURIChars),

      m_documentFileNameExtensionChars(documentFileNameExtensionChars),
      m_documentFileNameNameChars(documentFileNameNameChars),
      m_documentURINameChars(documentURINameChars),
      m_documentFileNameChars(documentFileNameChars),
      m_documentFileNameLength(documentFileNameChars?-1:0),
      m_documentURIChars(documentURIChars),
      m_documentURILength(documentURIChars?-1:0) 
    {
    }

    /**
     **********************************************************************
     * Function: SetDocumentFileName
     *
     *   Author: $author$
     *     Date: 9/15/2008
     **********************************************************************
     */
    virtual tLength SetDocumentFileName
    (const tChar* chars, tLength length=-1) 
    {
        tLength count = 0;
        if (0 <= (count = m_documentFileName.Assign(chars, length)))
        if ((m_documentFileNameChars = m_documentFileName.HasChars(m_documentFileNameLength)))
            OnSetDocumentFileName(m_documentFileNameChars, m_documentFileNameLength);
        return count;
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
        return count;
    }
    /**
     **********************************************************************
     * Function: GetDocumentFileNameBase
     *
     *   Author: $author$
     *     Date: 5/3/2008
     **********************************************************************
     */
    virtual const tChar* 
    GetDocumentFileNameBase
    (tLength& length, bool onlyFromDocumentNames=false,
     bool notFromTemplateNames=false) 
    {
        const tChar* chars = 0;
        const tChar* chars2 = 0;

        if ((chars = GetDocumentFileName
            (length, onlyFromDocumentNames)))

        if ((chars2 = GetFileNameBase(length, chars, length)))
        {
            length = (tLength)(chars2 - chars - 1);
            return chars;
        }
        length = 0;
        return 0;
    }
    /**
     **********************************************************************
     * Function: GetDocumentFileName
     *
     *   Author: $author$
     *     Date: 5/3/2008
     **********************************************************************
     */
    virtual const tChar* 
    GetDocumentFileName
    (tLength& length, bool onlyFromDocumentNames=false,
     bool notFromTemplateNames=false) 
    {
        const tChar* chars = 0;
        const tChar* chars2;
        cDocumentFileNameItem* i;
        cHTTPFormFieldReference f;

        if (m_documentFileNameChars)
        {
            length = m_documentFileNameLength;
            return m_documentFileNameChars;
        }

        for (i = cDocumentFileNameList::m_instance.GetFirstItem();
             i; i = i->GetNextItem())
        {
            if ((f = m_formFields.FindField(i->m_name)))
            if ((chars = f->GetValue(length)))
                return chars;
        }

        if (m_documentFileNameNameChars)
        if ((f = m_formFields.FindField(m_documentFileNameNameChars)))
        if ((chars = f->GetValue(length)))
            return chars;

        if (!onlyFromDocumentNames)
        if (!(chars = CGIEnvHasChars
            (length, e_CGI_ENV_PATH_TRANSLATED)))
        if (!notFromTemplateNames)
        if ((chars2 = GetTemplateFileNameBase(length, true)))
        if (0 < (length = m_documentFileName.Assign(chars2, length)))
        if (0 < (length = m_documentFileName.Append(&m_fileNameExtensionSeparatorChar, 1)))
        if (0 < (length = m_documentFileName.Append(m_documentFileNameExtensionChars)))
            chars = m_documentFileName.HasChars(length);

        return chars;
    }

    /**
     **********************************************************************
     * Function: GetDocumentURIBase
     *
     *   Author: $author$
     *     Date: 3/27/2008
     **********************************************************************
     */
    virtual const tChar* 
    GetDocumentURIBase
    (tLength& length, bool onlyFromDocumentNames=false) 
    {
        const tChar* chars = 0;
        const tChar* chars2 = 0;
        if ((chars = GetDocumentURI
            (length, onlyFromDocumentNames)))
        if ((chars2 = GetURIBase
            (length, chars, length)))
        {
            length = (tLength)(chars2 - chars - 1);
            return chars;
        }
        length = 0;
        return 0;
    }
    /**
     **********************************************************************
     * Function: GetDocumentURI
     *
     *   Author: $author$
     *     Date: 3/27/2008
     **********************************************************************
     */
    virtual const tChar* 
    GetDocumentURI
    (tLength& length, bool onlyFromDocumentNames=false) 
    {
        const tChar* chars = 0;
        const tChar* chars2;
        cDocumentURIItem* i;
        cHTTPFormFieldReference f;

        for (i = cDocumentURIList::m_instance.GetFirstItem();
             i; i = i->GetNextItem())
        {
            if ((f = m_formFields.FindField(i->m_name)))
            if ((chars = f->GetValue(length)))
                return chars;
        }

        if (!onlyFromDocumentNames)
        if ((chars2 = GetTemplateURIBase(length, true)))
        if (0 < (length = m_documentURI.Assign(chars2, length)))
        if (0 < (length = m_documentURI.Append(&m_fileNameExtensionSeparatorChar, 1)))
        if (0 < (length = m_documentURI.Append(m_documentFileNameExtensionChars)))
            chars = m_documentURI.HasChars(length);

        return chars;
    }

    /**
     **********************************************************************
     * Function: GetDocumentLocation
     *
     *   Author: $author$
     *     Date: 8/14/2008
     **********************************************************************
     */
    virtual const tChar* 
    GetDocumentLocation(tLength& length) 
    {
        const tChar* chars = 0;

        if (!(chars = CGIEnvHasChars
            (length, e_CGI_ENV_PATH_INFO)))
            length = 0;
        return chars;
    }

    /**
     **********************************************************************
     * Function: GetDocumentScript
     *
     *   Author: $author$
     *     Date: 9/4/2008
     **********************************************************************
     */
    virtual const tChar* 
    GetDocumentScript(tLength& length) 
    {
        const tChar* chars = 0;

        if (!(chars = CGIEnvHasChars
            (length, e_CGI_ENV_SCRIPT_NAME)))
            length = 0;
        return chars;
    }

    /**
     **********************************************************************
     * Function: OpenDocumentFile
     *
     *   Author: $author$
     *     Date: 9/13/2008
     **********************************************************************
     */
    virtual int OpenDocumentFile
    (const tChar* fileNameChars) 
    {
        int err = 0;
        eError error;

        if ((error = m_documentFile.Open(fileNameChars)))
            return UnableToOpenFileName(fileNameChars);
        return err;
    }
    /**
     **********************************************************************
     * Function: MissingDocumentFileName
     *
     *   Author: $author$
     *     Date: 5/3/2008
     **********************************************************************
     */
    virtual int MissingDocumentFileName(int err=1) 
    {
        SetContentType(GetContentTypeHTML());
        OutputContentL
        (H1_, m_cgiNameChars, _H1, 
         B_, "missing document filename (\"", 
         _B, m_documentFileNameNameChars, B_, "\")", _B, BR, NULL_POINTER);
        return err;
    }
};
#endif /* _CDOCUMENTTEMPLATECGI_HXX */
