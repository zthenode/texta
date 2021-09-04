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
 *   File: cxslcgi.hxx
 *
 * Author: $author$
 *   Date: 3/26/2008
 **********************************************************************
 */
#ifndef _CXSLCGI_HXX
#define _CXSLCGI_HXX

#include "cplatform_path.h"
#include "ccgi.hxx"
#include "cdocumentnamelist.hxx"
#include "ctemplatenamelist.hxx"
#include "csplitter.hxx"
#include "cxmlreaderinterface.hxx"
#include "cxsltransformerinterface.hxx"

#define DEFAULT_FILENAME_EXTENSION_SEPARATOR_CHAR '.'
#define DEFAULT_DOCUMENT_FILENAME_EXTENSION "xml"
#define DEFAULT_TEMPLATE_FILENAME_EXTENSION "xsl"

#define DEFAULT_DOCUMENT_FILENAME_NAME "xml_filename"
#define DEFAULT_TEMPLATE_FILENAME_NAME "xsl_filename"

#define DEFAULT_DOCUMENT_URI_NAME "xml_uri"
#define DEFAULT_TEMPLATE_URI_NAME "xsl_uri"

/**
 **********************************************************************
 *  Class: cXSLCGI
 *
 * Author: $author$
 *   Date: 3/26/2008
 **********************************************************************
 */
class cXSLCGI
: public cCGI
{
public:
    typedef cCGI cExtends;
    typedef cXSLCGI cDerives;

    tChar m_filenameExtensionSeparatorChar;
    const tChar* m_documentFilenameExtensionChars;
    const tChar* m_templateFilenameExtensionChars;
    const tChar* m_documentFilenameNameChars;
    const tChar* m_templateFilenameNameChars;
    const tChar* m_documentURINameChars;
    const tChar* m_templateURINameChars;

    cCharSplitter m_splitter;
    
    const tChar* m_documentFilenameChars;
    cCharString m_documentFilename;
    cCharString m_absoluteDocumentFilename;

    const tChar* m_templateFilenameChars;
    cCharString m_templateFilename;
    cCharString m_absoluteTemplateFilename;

    const tChar* m_documentURIChars;
    cCharString m_documentURI;

    const tChar* m_templateURIChars;
    cCharString m_templateURI;

    cXSLTransformerInterface* m_xslTransformer;
    cCharString m_xslTransformerErrors;

    /**
     **********************************************************************
     * Constructor: cXSLCGI
     *
     *      Author: $author$
     *        Date: 3/26/2008
     **********************************************************************
     */
    cXSLCGI
    (const tChar* cgiNameChars="xslcgi")
    : cExtends(cgiNameChars),

      m_filenameExtensionSeparatorChar
      (DEFAULT_FILENAME_EXTENSION_SEPARATOR_CHAR),

      m_documentFilenameExtensionChars(DEFAULT_DOCUMENT_FILENAME_EXTENSION),
      m_templateFilenameExtensionChars(DEFAULT_TEMPLATE_FILENAME_EXTENSION),

      m_documentFilenameNameChars(DEFAULT_DOCUMENT_FILENAME_NAME),
      m_templateFilenameNameChars(DEFAULT_TEMPLATE_FILENAME_NAME),

      m_documentURINameChars(DEFAULT_DOCUMENT_URI_NAME),
      m_templateURINameChars(DEFAULT_TEMPLATE_URI_NAME)
    {
    }
    /**
     **********************************************************************
     * Destructor: cXSLCGI
     *
     *     Author: $author$
     *       Date: 3/26/2008
     **********************************************************************
     */
    virtual ~cXSLCGI()
    {
    }
    /**
     **********************************************************************
     * Function: RunCommandOrCGI
     *
     *   Author: $author$
     *     Date: 3/27/2008
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
        const tChar* chars;

        if (!(chars = GetContentTypeHTML()))
            return 1;

        SetContentType(chars);

        if (!(m_templateFilenameChars = GetTemplateFilename(length)))
        if (!(m_templateURIChars = GetTemplateURI(length)))
        {
            OutputContentL
            (H1_, m_cgiNameChars, _H1, 
             B_, "missing template source (\"", _B, m_templateFilenameNameChars, B_,
             "\" or \"", _B, m_templateURINameChars, B_, "\")", _B, BR, NULL_POINTER);
            return 1;
        }

        if (!(m_documentFilenameChars = GetDocumentFilename(length)))
        if (!(m_documentURIChars = GetDocumentURI(length)))
        {
            OutputContentL
            (H1_, m_cgiNameChars, _H1, 
             B_, "missing document source (\"", _B, m_documentFilenameNameChars, B_,
             "\" or \"", _B, m_documentURINameChars, B_, "\")", _B, BR, NULL_POINTER);
            return 1;
        }

        if ((m_xslTransformer = cXSLTransformerInterface::CreateInstance(error)))
        {
            if (!(error = m_xslTransformer->Initialize()))
            {
                eError xslTransformerError = e_ERROR_NONE;

                if (0 <= (length = SetXSLTLiteralParametersFromForm(*m_xslTransformer)))
                if (0 <= (length = m_xslTransformerErrors.Clear()))
                if (m_templateFilenameChars)
                if (m_documentFilenameChars)
                {
                    if ((m_documentFilenameChars = GetAbsoluteFilename
                        (length, m_absoluteDocumentFilename, 
                         m_documentFilenameChars, m_templateFilenameChars)))

                    if ((m_templateFilenameChars = GetAbsoluteFilename
                        (length, m_absoluteTemplateFilename, 
                         m_templateFilenameChars, m_documentFilenameChars)))

                        xslTransformerError = m_xslTransformer->TransformFile
                        (m_xslTransformerErrors, m_outputContentWriter,
                         m_templateFilenameChars, m_documentFilenameChars);
                }

                if (xslTransformerError)
                if ((chars = m_xslTransformerErrors.HasChars(length)))
                    OutputContentL
                    (H1_, m_cgiNameChars, _H1, 
                     B_, "XSL transformer error (", _B, chars, B_, ")", _B, BR, NULL_POINTER);

                m_xslTransformer->Finalize();
            }
            cXSLTransformerInterface::DestroyInstance(*m_xslTransformer);
        }
        return err;
    }
    /**
     **********************************************************************
     * Function: SetXSLTLiteralParametersFromForm
     *
     *   Author: $author$
     *     Date: 3/27/2008
     **********************************************************************
     */
    virtual tLength SetXSLTLiteralParametersFromForm
    (cXSLTransformerInterface& xslTransformer) 
    {
        tLength count = 0;
        tLength  length;
        const tChar* name;
        const tChar* value;
        cHTTPFormFieldIterator end;
        cHTTPFormFieldIterator i;
        cHTTPFormFieldReference f;
        eError error;

        if ((i = m_formFields.begin())
            != (end = m_formFields.end()))
        do
        {
            if ((f = (*i)))
            if ((name = f->GetName(length)) && (0 < length))
            if ((value = f->GetValue(length)))
            if ((error = xslTransformer.SetLiteralParameter(name, value)))
                return count = -error;
            else count++;
        }
        while ((++i) != end);
        return count;
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

        if ((chars = GetDocumentFilename(length)))
            OutputContentL(B_, "document filename=\"", _B, chars, B_, "\"", _B, BR, NULL_POINTER);

        if ((chars = GetTemplateFilename(length)))
            OutputContentL(B_, "template filename=\"", _B, chars, B_, "\"", _B, BR, NULL_POINTER);

        if ((chars = GetDocumentURI(length)))
            OutputContentL(B_, "document uri=\"", _B, chars, B_, "\"", _B, BR, NULL_POINTER);

        if ((chars = GetTemplateURI(length)))
            OutputContentL(B_, "template uri=\"", _B, chars, B_, "\"", _B, BR, NULL_POINTER);

        return err;
    }
    /**
     **********************************************************************
     * Function: GetDocumentFilenameBase
     *
     *   Author: $author$
     *     Date: 3/27/2008
     **********************************************************************
     */
    virtual const tChar* 
    GetDocumentFilenameBase
    (tLength& length, bool onlyFromDocumentNames=false) 
    {
        const tChar* chars = 0;
        const tChar* chars2 = 0;
        if ((chars = GetDocumentFilename
            (length, onlyFromDocumentNames)))
        if ((chars2 = m_splitter.RightOf
            (length, m_filenameExtensionSeparatorChar, chars, length)))
        {
            length = (tLength)(chars2 - chars - 1);
            return chars;
        }
        length = 0;
        return 0;
    }
    /**
     **********************************************************************
     * Function: GetDocumentFilename
     *
     *   Author: $author$
     *     Date: 3/26/2008
     **********************************************************************
     */
    virtual const tChar* 
    GetDocumentFilename
    (tLength& length, bool onlyFromDocumentNames=false) 
    {
        const tChar* chars = 0;
        const tChar* chars2;
        cDocumentFilenameItem* i;
        cHTTPFormFieldReference f;

        for (i = cDocumentFilenameList::m_instance.GetFirstItem();
             i; i = i->GetNextItem())
        {
            if ((f = m_formFields.FindField(i->m_name)))
            if ((chars = f->GetValue(length)))
                return chars;
        }

        if (!onlyFromDocumentNames)
        if ((chars2 = GetTemplateFilenameBase(length, true)))
        if (0 < (length = m_documentFilename.Assign(chars2, length)))
        if (0 < (length = m_documentFilename.Append(&m_filenameExtensionSeparatorChar, 1)))
        if (0 < (length = m_documentFilename.Append(m_documentFilenameExtensionChars)))
            chars = m_documentFilename.HasChars(length);

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
        if ((chars2 = m_splitter.RightOf
            (length, m_filenameExtensionSeparatorChar, chars, length)))
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
        if (0 < (length = m_documentURI.Append(&m_filenameExtensionSeparatorChar, 1)))
        if (0 < (length = m_documentURI.Append(m_documentFilenameExtensionChars)))
            chars = m_documentURI.HasChars(length);

        return chars;
    }
    /**
     **********************************************************************
     * Function: GetTemplateFilenameBase
     *
     *   Author: $author$
     *     Date: 3/27/2008
     **********************************************************************
     */
    virtual const tChar* 
    GetTemplateFilenameBase
    (tLength& length, bool onlyFromTemplateNames=false) 
    {
        const tChar* chars = 0;
        const tChar* chars2 = 0;
        if ((chars = GetTemplateFilename
            (length, onlyFromTemplateNames)))
        if ((chars2 = m_splitter.RightOf
            (length, m_filenameExtensionSeparatorChar, chars, length)))
        {
            length = (tLength)(chars2 - chars - 1);
            return chars;
        }
        length = 0;
        return 0;
    }
    /**
     **********************************************************************
     * Function: GetTemplateFilename
     *
     *   Author: $author$
     *     Date: 3/26/2008
     **********************************************************************
     */
    virtual const tChar* 
    GetTemplateFilename
    (tLength& length, bool onlyFromTemplateNames=false) 
    {
        const tChar* chars = 0;
        const tChar* chars2;
        cTemplateFilenameItem* i;
        cHTTPFormFieldReference f;

        for (i = cTemplateFilenameList::m_instance.GetFirstItem();
             i; i = i->GetNextItem())
        {
            if ((f = m_formFields.FindField(i->m_name)))
            if ((chars = f->GetValue(length)))
                return chars;
        }

        if (!(chars = CGIEnvHasChars
            (length, e_CGI_ENV_PATH_TRANSLATED)))
        if (!onlyFromTemplateNames)
        if ((chars2 = GetDocumentFilenameBase(length, true)))
        if (0 < (length = m_templateFilename.Assign(chars2, length)))
        if (0 < (length = m_templateFilename.Append(&m_filenameExtensionSeparatorChar, 1)))
        if (0 < (length = m_templateFilename.Append(m_templateFilenameExtensionChars)))
            chars = m_templateFilename.HasChars(length);

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
        if ((chars2 = m_splitter.RightOf
            (length, m_filenameExtensionSeparatorChar, chars, length)))
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
        if (0 < (length = m_templateURI.Append(&m_filenameExtensionSeparatorChar, 1)))
        if (0 < (length = m_templateURI.Append(m_templateFilenameExtensionChars)))
            chars = m_templateURI.HasChars(length);

        return chars;
    }
    /**
     **********************************************************************
     * Function: GetAbsoluteFilename
     *
     *   Author: $author$
     *     Date: 3/26/2008
     **********************************************************************
     */
    virtual const tChar* 
    GetAbsoluteFilename
    (tLength& length, cCharString& filename,
     const tChar* filenameChars, const tChar* absoluteFilenameChars) 
    {
        const tChar* chars = filenameChars;
        const tChar* absolutePathChars;
        tLength absolutePathLength;
        tChar separatorChar;

        if (absoluteFilenameChars)

        if (!(absolutePathChars = GetAbsoluteFilenamePath
            (absolutePathLength, separatorChar, filenameChars)))

        if ((absolutePathChars = GetAbsoluteFilenamePath
            (absolutePathLength, separatorChar, absoluteFilenameChars)))

        if (0 < (absolutePathLength = filename.Assign
            (absolutePathChars, absolutePathLength)))
        if (0 < (absolutePathLength = filename.Append(&separatorChar, 1)))
        if (0 < (absolutePathLength = filename.Append(filenameChars)))
        if ((absolutePathChars = filename.HasChars(absolutePathLength)))
        {
            chars = absolutePathChars;
            length = absolutePathLength;
        }
        return chars;
    }
    /**
     **********************************************************************
     * Function: GetAbsoluteFilenamePath
     *
     *   Author: $author$
     *     Date: 3/26/2008
     **********************************************************************
     */
    virtual const tChar* 
    GetAbsoluteFilenamePath
    (tLength& length, tChar& separatorChar,
     const tChar* absoluteFilenameChars) 
    {
        const tChar* chars = 0;
        const tChar* relativeFilenameChars = 0;
        tLength relativeLength;

        if (absoluteFilenameChars)

        if ((relativeFilenameChars = m_splitter.RightOf
            (relativeLength, 
             PLATFORM_DIRECTORY_SEPARATOR_CHAR, absoluteFilenameChars)))
             separatorChar = PLATFORM_DIRECTORY_SEPARATOR_CHAR;
        else
        if ((relativeFilenameChars = m_splitter.RightOf
            (relativeLength, 
             FOREIGN_DIRECTORY_SEPARATOR_CHAR, absoluteFilenameChars)))
             separatorChar = FOREIGN_DIRECTORY_SEPARATOR_CHAR;
        else
        if (PLATFORM_VOLUME_SEPARATOR_CHAR)
        if ((relativeFilenameChars = m_splitter.RightOf
            (relativeLength, 
             PLATFORM_VOLUME_SEPARATOR_CHAR, absoluteFilenameChars)))
             separatorChar = PLATFORM_VOLUME_SEPARATOR_CHAR;

        if (relativeFilenameChars)
        if (0 < (length = (tLength)(relativeFilenameChars - absoluteFilenameChars -1)))
            chars = absoluteFilenameChars;

        return chars;
    }
};
#endif /* _CXSLCGI_HXX */
