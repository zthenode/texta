/**
 **********************************************************************
 * Copyright (c) 1988-2011 $organization$
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
 *   File: cxdep2qtproxslcgi.hxx
 *
 * Author: $author$
 *   Date: 4/30/2011
 **********************************************************************
 */
#ifndef _CXDEP2QTPROXSLCGI_HXX
#define _CXDEP2QTPROXSLCGI_HXX

#include "cxslcgi.hxx"

#define CXDEP2QTPROXSLCGI_DEFAULT_DOCUMENT_FILENAME ""
#define CXDEP2QTPROXSLCGI_DEFAULT_TEMPLATE_FILENAME "XosDevelopmentProject-to-QtCreatorProject.xsl"

/**
 **********************************************************************
 *  Class: cXdep2QtProXslCgi
 *
 * Author: $author$
 *   Date: 4/30/2011
 **********************************************************************
 */
class cXdep2QtProXslCgi
: public cXSLCGI
{
public:
    typedef cXSLCGI cExtends;
    typedef cXdep2QtProXslCgi cDerives;
    
    const tChar* m_defaultDocumentFileNameChars;
    const tChar* m_defaultTemplateFileNameChars;

    /**
     **********************************************************************
     * Constructor: cXdep2QtProXslCgi
     *
     *      Author: $author$
     *        Date: 4/30/2011
     **********************************************************************
     */
    cXdep2QtProXslCgi
    (const tChar* defaultDocumentFileNameChars=CXDEP2QTPROXSLCGI_DEFAULT_DOCUMENT_FILENAME,
     const tChar* defaultTemplateFileNameChars=CXDEP2QTPROXSLCGI_DEFAULT_TEMPLATE_FILENAME)
    : m_defaultDocumentFileNameChars(defaultDocumentFileNameChars),
      m_defaultTemplateFileNameChars(defaultTemplateFileNameChars) 
    {
    }

    /**
     **********************************************************************
     * Function: GetDocumentFileName
     *
     *   Author: $author$
     *     Date: 5/1/2011
     **********************************************************************
     */
    virtual const tChar* 
    GetDocumentFileName
    (tLength& length, bool onlyFromDocumentNames=false) 
    {
        const tChar* chars = 0;

        if ((chars = GetFormDocumentFileName(length, onlyFromDocumentNames)))
        {
            DBT("() document file = \"%s\"\n", chars);
            return chars;
        }

        if ((chars = GetPathTranslatedDocumentFileName(length, onlyFromDocumentNames)))
        {
            DBT("() document file = \"%s\"\n", chars);
            return chars;
        }

        if ((chars = GetDefaultDocumentFileName(length, onlyFromDocumentNames)))
        {
            DBT("() document file = \"%s\"\n", chars);
            return chars;
        }

        return chars;
    }
    /**
     **********************************************************************
     * Function: GetFormDocumentFileName
     *
     *   Author: $author$
     *     Date: 5/1/2011
     **********************************************************************
     */
    virtual const tChar* 
    GetFormDocumentFileName
    (tLength& length, bool onlyFromDocumentNames=false) 
    {
        const tChar* chars = 0;
        cDocumentFileNameItem* i;
        cHTTPFormFieldReference f;

        for (i = cDocumentFileNameList::m_instance.GetFirstItem();
             i; i = i->GetNextItem())
        {
            if ((f = m_formFields.FindField(i->m_name)))
            if ((chars = f->GetValue(length)))
                return chars;
        }
        return chars;
    }
    /**
     **********************************************************************
     * Function: GetPathTranslatedDocumentFileName
     *
     *   Author: $author$
     *     Date: 5/1/2011
     **********************************************************************
     */
    virtual const tChar* 
    GetPathTranslatedDocumentFileName
    (tLength& length, bool onlyFromDocumentNames=false) 
    {
        const tChar* chars = GetPathTranslatedFileName(length, onlyFromDocumentNames);
        return chars;
    }
    /**
     **********************************************************************
     * Function: GetDefaultDocumentFileName
     *
     *   Author: $author$
     *     Date: 5/1/2011
     **********************************************************************
     */
    virtual const tChar* 
    GetDefaultDocumentFileName
    (tLength& length, bool onlyFromDocumentNames=false) 
    {
        const tChar* chars = 0;
        const tChar* chars2;

        if (!onlyFromDocumentNames)
        {
            if ((chars = m_defaultDocumentFileNameChars))
            if ((chars[0]))
            {
                for (length = 0; chars[length]; length++);
                return chars;
            }
            if ((chars2 = GetTemplateFileNameBase(length, true)))
            if (0 < (length = m_documentFileName.Assign(chars2, length)))
            if (0 < (length = m_documentFileName.Append(&m_filenameExtensionSeparatorChar, 1)))
            if (0 < (length = m_documentFileName.Append(m_documentFileNameExtensionChars)))
                chars = m_documentFileName.HasChars(length);
        }
        return chars;
    }

    /**
     **********************************************************************
     * Function: GetTemplateFileName
     *
     *   Author: $author$
     *     Date: 4/30/2011
     **********************************************************************
     */
    virtual const tChar* GetTemplateFileName
    (tLength& length, bool onlyFromTemplateNames=false) 
    {
        const tChar* chars = 0;

        if ((chars = GetFormTemplateFileName(length, onlyFromTemplateNames)))
        {
            DBT("() template file = \"%s\"\n", chars);
            return chars;
        }

        if (!(chars = m_defaultTemplateFileNameChars))
        if (!(chars[0]))
        if ((chars = GetPathTranslatedTemplateFileName(length, onlyFromTemplateNames)))
        {
            DBT("() template file = \"%s\"\n", chars);
            return chars;
        }

        if ((chars = GetDefaultTemplateFileName(length, onlyFromTemplateNames)))
        {
            DBT("() template file = \"%s\"\n", chars);
            return chars;
        }
        return chars;
    }
    /**
     **********************************************************************
     * Function: GetFormTemplateFileName
     *
     *   Author: $author$
     *     Date: 4/30/2011
     **********************************************************************
     */
    virtual const tChar* GetFormTemplateFileName
    (tLength& length, bool onlyFromTemplateNames=false) 
    {
        const tChar* chars = 0;
        cTemplateFileNameItem* i;
        cHTTPFormFieldReference f;

        for (i = cTemplateFileNameList::m_instance.GetFirstItem();
             i; i = i->GetNextItem())
        {
            if ((f = m_formFields.FindField(i->m_name)))
            if ((chars = f->GetValue(length)))
                return chars;
        }
        return chars;
    }
    /**
     **********************************************************************
     * Function: GetPathTranslatedTemplateFileName
     *
     *   Author: $author$
     *     Date: 5/1/2011
     **********************************************************************
     */
    virtual const tChar* GetPathTranslatedTemplateFileName
    (tLength& length, bool onlyFromTemplateNames=false) 
    {
        const tChar* chars = GetPathTranslatedFileName(length, onlyFromTemplateNames);
        return chars;
    }
    /**
     **********************************************************************
     * Function: GetDefaultTemplateFileName
     *
     *   Author: $author$
     *     Date: 3/26/2008
     **********************************************************************
     */
    virtual const tChar* 
    GetDefaultTemplateFileName
    (tLength& length, bool onlyFromTemplateNames=false) 
    {
        const tChar* chars = 0;
        const tChar* chars2;

        if (!onlyFromTemplateNames)
        {
            if ((chars = m_defaultTemplateFileNameChars))
            if ((chars[0]))
            {
                for (length = 0; chars[length]; length++);
                return chars;
            }
            if ((chars2 = GetDocumentFileNameBase(length, true)))
            if (0 < (length = m_templateFileName.Assign(chars2, length)))
            if (0 < (length = m_templateFileName.Append(&m_filenameExtensionSeparatorChar, 1)))
            if (0 < (length = m_templateFileName.Append(m_templateFileNameExtensionChars)))
                chars = m_templateFileName.HasChars(length);
        }
        return chars;
    }
    /**
     **********************************************************************
     * Function: GetAbsoluteTemplateFileName
     *
     *   Author: $author$
     *     Date: 5/1/2011
     **********************************************************************
     */
    virtual const tChar* 
    GetAbsoluteTemplateFileName
    (tLength& length, cCharString& filename,
     const tChar* filenameChars, const tChar* absoluteFileNameChars) 
    {
        const tChar* chars = filenameChars;
        if ((filenameChars != m_defaultTemplateFileNameChars))
            chars = GetAbsoluteFileName
            (length, filename, filenameChars, absoluteFileNameChars);
        return chars;
    }

    /**
     **********************************************************************
     * Function: GetPathTranslatedFileName
     *
     *   Author: $author$
     *     Date: 5/1/2011
     **********************************************************************
     */
    virtual const tChar* 
    GetPathTranslatedFileName
    (tLength& length, bool onlyFromDocumentNames=false) 
    {
        const tChar* chars = 0;
        if (!onlyFromDocumentNames)
        if ((chars = CGIEnvHasChars(length, e_CGI_ENV_PATH_TRANSLATED)))
            DBT("() fileName = \"%s\"\n", chars);
        return chars;
    }
};

#endif /* _CXDEP2QTPROXSLCGI_HXX */

