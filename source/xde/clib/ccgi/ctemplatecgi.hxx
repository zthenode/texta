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
 *   File: ctemplatecgi.hxx
 *
 * Author: $author$
 *   Date: 4/1/2008
 **********************************************************************
 */
#ifndef _CTEMPLATECGI_HXX
#define _CTEMPLATECGI_HXX

#include "cfilenamecgi.hxx"
#include "ctemplatenamelist.hxx"

/**
 **********************************************************************
 *  Class: cTemplateCGI
 *
 * Author: $author$
 *   Date: 4/1/2008
 **********************************************************************
 */
class cTemplateCGI
: public cFileNameCGI
{
public:
    typedef cFileNameCGI cExtends;
    typedef cTemplateCGI cDerives;

    const tChar* m_templateFileNameExtensionChars;
    const tChar* m_templateFileNameNameChars;
    const tChar* m_templateURINameChars;

    const tChar* m_templateFileNameChars;
    tLength m_templateFileNameLength;
    cCharString m_templateFileName;
    cCharString m_absoluteTemplateFileName;

    const tChar* m_templateURIChars;
    tLength m_templateURILength;
    cCharString m_templateURI;
    cCharString m_absoluteTemplateURI;

    cCharFile m_templateFile;

    /**
     **********************************************************************
     * Constructor: cTemplateCGI
     *
     *      Author: $author$
     *        Date: 4/1/2008
     **********************************************************************
     */
    cTemplateCGI
    (const tChar* templateFileNameExtensionChars,
     const tChar* templateFileNameNameChars,
     const tChar* templateURINameChars,
     const tChar* cgiNameChars,
     const tChar* templateFileNameChars=0,
     const tChar* templateURIChars=0)
    : cExtends(cgiNameChars),
      m_templateFileNameExtensionChars(templateFileNameExtensionChars),
      m_templateFileNameNameChars(templateFileNameNameChars),
      m_templateURINameChars(templateURINameChars),
      m_templateFileNameChars(templateFileNameChars),
      m_templateFileNameLength(templateFileNameChars?-1:0),
      m_templateURIChars(templateURIChars),
      m_templateURILength(templateURIChars?-1:0)
    {
    }

    /**
     **********************************************************************
     * Function: RunDebug
     *
     *   Author: $author$
     *     Date: 3/26/2008
     **********************************************************************
     */
    virtual int RunDebug
    (int argc,
     const char** argv,
     const char** env) 
    {
        int err = 0;
        tLength length;
        const tChar* chars;

        OutputContentType(GetContentTypeHTML());
        OutputContentL(H1_, m_cgiNameChars, _H1, NULL_POINTER);

        if ((chars = GetTemplateFileName(length)))
            OutputContentL(B_, "template filename=\"", _B, chars, B_, "\"", _B, BR, NULL_POINTER);

        if ((chars = GetTemplateURI(length)))
            OutputContentL(B_, "template uri=\"", _B, chars, B_, "\"", _B, BR, NULL_POINTER);

        return err;
    }

    /**
     **********************************************************************
     * Function: GetTemplateFileNameBase
     *
     *   Author: $author$
     *     Date: 3/27/2008
     **********************************************************************
     */
    virtual const tChar* 
    GetTemplateFileNameBase
    (tLength& length, bool onlyFromTemplateNames=false) 
    {
        const tChar* chars = 0;
        const tChar* chars2 = 0;

        if ((chars = GetTemplateFileName
            (length, onlyFromTemplateNames)))

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
     * Function: GetTemplateFileName
     *
     *   Author: $author$
     *     Date: 3/26/2008
     **********************************************************************
     */
    virtual const tChar* 
    GetTemplateFileName
    (tLength& length, bool onlyFromTemplateNames=false) 
    {
        const tChar* chars = 0;
        const tChar* chars2;
        cTemplateFileNameItem* i;
        cHTTPFormFieldReference f;

//#if !defined(NO_TEMPLATE_STATIC_MEMBERS) 
        for (i = cTemplateFileNameList::m_instance.GetFirstItem();
             i; i = i->GetNextItem())
        {
            if ((chars2 = i->m_name))
            {
                DBT("() looking for form field \"%s\"...\n", chars2);
                if ((f = m_formFields.FindField(chars2)))
                if ((chars = f->GetValue(length)))
                if (0 < length)
                {
                    DBT("() ...form field \"%s\" is \"%s\"\n", chars2, chars);
                    return chars;
                }
            }
        }
//#endif /* !defined(NO_TEMPLATE_STATIC_MEMBERS) */

        if (!onlyFromTemplateNames)
        if ((chars = CGIEnvHasChars
            (length, e_CGI_ENV_PATH_TRANSLATED)))
            DBT("() env PATH_TRANSLATED is \"%s\"\n", chars);
        else
        if ((chars2 = GetDocumentFileNameBase(length, true)))
        if (0 < (length = m_templateFileName.Assign(chars2, length)))
        if (0 < (length = m_templateFileName.Append(&m_fileNameExtensionSeparatorChar, 1)))
        if (0 < (length = m_templateFileName.Append(m_templateFileNameExtensionChars)))
            chars = m_templateFileName.HasChars(length);

        return chars;
    }
    /**
     **********************************************************************
     * Function: GetTemplateURIBase
     *
     *   Author: $author$
     *     Date: 3/27/2008
     **********************************************************************
     */
    virtual const tChar* 
    GetTemplateURIBase
    (tLength& length, bool onlyFromTemplateNames=false) 
    {
        const tChar* chars = 0;
        const tChar* chars2 = 0;
        if ((chars = GetTemplateURI
            (length, onlyFromTemplateNames)))
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
     * Function: GetTemplateURI
     *
     *   Author: $author$
     *     Date: 3/27/2008
     **********************************************************************
     */
    virtual const tChar* 
    GetTemplateURI
    (tLength& length, bool onlyFromTemplateNames=false) 
    {
        const tChar* chars = 0;
        const tChar* chars2;
        cTemplateURIItem* i;
        cHTTPFormFieldReference f;

        for (i = cTemplateURIList::m_instance.GetFirstItem();
             i; i = i->GetNextItem())
        {
            if ((f = m_formFields.FindField(i->m_name)))
            if ((chars = f->GetValue(length)))
                return chars;
        }

        if (!onlyFromTemplateNames)
        if ((chars2 = GetDocumentURIBase(length, true)))
        if (0 < (length = m_templateURI.Assign(chars2, length)))
        if (0 < (length = m_templateURI.Append(&m_fileNameExtensionSeparatorChar, 1)))
        if (0 < (length = m_templateURI.Append(m_templateFileNameExtensionChars)))
            chars = m_templateURI.HasChars(length);

        return chars;
    }

    /**
     **********************************************************************
     * Function: GetDocumentFileNameBase
     *
     *   Author: $author$
     *     Date: 3/27/2008
     **********************************************************************
     */
    virtual const tChar* 
    GetDocumentFileNameBase
    (tLength& length, bool onlyFromDocumentNames=false,
     bool notFromTemplateNames=false) 
    {
        const tChar* chars = 0;
        length = 0;
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
        length = 0;
        return chars;
    }

    /**
     **********************************************************************
     * Function: OpenTemplateFile
     *
     *   Author: $author$
     *     Date: 11/18/2008
     **********************************************************************
     */
    virtual int OpenTemplateFile
    (const tChar* fileNameChars) 
    {
        int err = 0;
        eError error;

        if ((error = m_templateFile.Open(fileNameChars)))
            return UnableToOpenFileName(fileNameChars);
        return err;
    }
    /**
     **********************************************************************
     * Function: MissingTemplateFileName
     *
     *   Author: $author$
     *     Date: 5/3/2008
     **********************************************************************
     */
    virtual int MissingTemplateFileName(int err=1) 
    {
        SetContentType(GetContentTypeHTML());
        OutputContentL
        (H1_, m_cgiNameChars, _H1, 
         B_, "missing template filename (\"", 
         _B, m_templateFileNameNameChars, B_, "\")", _B, BR, NULL_POINTER);
        return err;
    }
};
#endif /* _CTEMPLATECGI_HXX */
