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

#define DEFAULT_CONTENT_TYPE_NAME "content_type"

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

    tChar m_directorySeparatorChar;
    tChar m_filenameExtensionSeparatorChar;
    const tChar* m_documentFileNameExtensionChars;
    const tChar* m_templateFileNameExtensionChars;
    const tChar* m_documentFileNameNameChars;
    const tChar* m_templateFileNameNameChars;
    const tChar* m_documentURINameChars;
    const tChar* m_templateURINameChars;
    const tChar* m_contentTypeNameChars;

    cCharSplitter m_splitter;
    
    const tChar* m_documentFilePathChars;
    const tChar* m_documentFileNameChars;
    cCharString m_documentFilePath;
    cCharString m_documentFileName;
    cCharString m_absoluteDocumentFileName;

    const tChar* m_templateFilePathChars;
    const tChar* m_templateFileNameChars;
    cCharString m_templateFilePath;
    cCharString m_templateFileName;
    cCharString m_absoluteTemplateFileName;

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

      m_directorySeparatorChar
      (PLATFORM_DIRECTORY_SEPARATOR_CHAR),

      m_filenameExtensionSeparatorChar
      (DEFAULT_FILENAME_EXTENSION_SEPARATOR_CHAR),

      m_documentFileNameExtensionChars(DEFAULT_DOCUMENT_FILENAME_EXTENSION),
      m_templateFileNameExtensionChars(DEFAULT_TEMPLATE_FILENAME_EXTENSION),

      m_documentFileNameNameChars(DEFAULT_DOCUMENT_FILENAME_NAME),
      m_templateFileNameNameChars(DEFAULT_TEMPLATE_FILENAME_NAME),

      m_documentURINameChars(DEFAULT_DOCUMENT_URI_NAME),
      m_templateURINameChars(DEFAULT_TEMPLATE_URI_NAME),

      m_contentTypeNameChars(DEFAULT_CONTENT_TYPE_NAME)
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

        if ((chars = GetContentTypeParameter(length)))
        {
            DBT("() setting content type to \"%s\"\n", chars);
            SetContentType(chars);
        }

        if (!(m_templateFileNameChars = GetTemplateFileName(length)))
        if (!(m_templateURIChars = GetTemplateURI(length)))
        {
            OutputContentL
            (H1_, m_cgiNameChars, _H1, 
             B_, "missing template source (\"", _B, m_templateFileNameNameChars, B_,
             "\" or \"", _B, m_templateURINameChars, B_, "\")", _B, BR, NULL_POINTER);
            return 1;
        }

        if (!(m_documentFileNameChars = GetDocumentFileName(length)))
        if (!(m_documentURIChars = GetDocumentURI(length)))
        {
            OutputContentL
            (H1_, m_cgiNameChars, _H1, 
             B_, "missing document source (\"", _B, m_documentFileNameNameChars, B_,
             "\" or \"", _B, m_documentURINameChars, B_, "\")", _B, BR, NULL_POINTER);
            return 1;
        }

        if ((m_xslTransformer = cXSLTransformerInterface::CreateInstance(error)))
        {
            if ((error = m_xslTransformer->Initialize()))
            {
                OutputContentL
                (H1_, m_cgiNameChars, _H1, 
                 B_, "...failed on m_xslTransformer-", GT, "Initialize()", _B, BR, NULL_POINTER);
            }
            else
            {
                eError xslTransformerError = e_ERROR_NONE;

                m_xslTransformerErrors.Clear();        
                
                if (0 > (length = SetXSLTLiteralParametersFromForm
                    (m_xslTransformerErrors, *m_xslTransformer)))
                {
                    chars = m_xslTransformerErrors.Chars(length);
                    OutputContentL
                    (H1_, m_cgiNameChars, _H1, 
                     B_, "...failed on SetXSLTLiteralParametersFromForm", _B, BR, 
                     B_, "(\"", _B, chars, B_, "\",...)", _B, BR, NULL_POINTER);
                }
                else 
                if ((m_templateFileNameChars) && (m_documentFileNameChars))
                {
                    if ((m_documentFilePathChars = GetDocumentFilePath
                        (length)) && (0 < length))
                    {
                        DBT("() document path = \"%s\"\n", m_documentFilePathChars);

                        if (0 < (length = m_documentFilePath.Assign
                            (m_documentFilePathChars, length)))
                        if (0 < (length = m_documentFilePath.Append
                            (&m_directorySeparatorChar, 1)))
                        if (0 < (length = m_documentFilePath.Append
                            (m_documentFileNameChars)))
                        if ((m_documentFilePathChars = 
                             m_documentFilePath.HasChars(length)))
                        {
                            DBT("() document file = \"%s\"\n", m_documentFilePathChars);

                            m_documentFileNameChars = m_documentFilePathChars;
                        }
                    }

                    if ((m_templateFilePathChars = GetTemplateFilePath
                        (length)) && (0 < length))
                    {
                        DBT("() template path = \"%s\"\n", m_templateFilePathChars);

                        if (0 < (length = m_templateFilePath.Assign
                            (m_templateFilePathChars, length)))
                        if (0 < (length = m_templateFilePath.Append
                            (&m_directorySeparatorChar, 1)))
                        if (0 < (length = m_templateFilePath.Append
                            (m_templateFileNameChars)))
                        if ((m_templateFilePathChars = 
                             m_templateFilePath.HasChars(length)))
                        {
                            DBT("() template file = \"%s\"\n", m_templateFilePathChars);

                            m_templateFileNameChars = m_templateFilePathChars;
                        }
                    }

                    if ((m_documentFileNameChars = GetAbsoluteDocumentFileName
                        (length, m_absoluteDocumentFileName, 
                         m_documentFileNameChars, m_templateFileNameChars)))

                    if ((m_templateFileNameChars = GetAbsoluteTemplateFileName
                        (length, m_absoluteTemplateFileName, 
                         m_templateFileNameChars, m_documentFileNameChars)))
                    {
                        DBT("() template file =\"%s\"\n", m_templateFileNameChars);
                        DBT("() document file =\"%s\"\n", m_documentFileNameChars);

                        xslTransformerError = m_xslTransformer->TransformFile
                        (m_xslTransformerErrors, m_outputContentWriter,
                         m_templateFileNameChars, m_documentFileNameChars);
                        
                        if (xslTransformerError)
                        {
                            if ((chars = m_xslTransformerErrors.HasChars(length)))
                                OutputContentL
                                (H1_, m_cgiNameChars, _H1, 
                                 B_, "...XSL transformer error", _B, BR, B_, "(", _B, chars, B_, ")", _B, BR, BR,
                                 B_, "...on TransformFile", _B, BR, B_, "(..., xsl = \"", _B, m_templateFileNameChars, 
                                 B_, "\",", _B, BR, B_, " xml = \"", _B, m_documentFileNameChars, B_, "\")", _B, BR, NULL_POINTER);
                            else
                                OutputContentL
                                (H1_, m_cgiNameChars, _H1, 
                                 B_, "...failed on TransformFile", _B, BR, B_, "(..., xsl = \"", _B, m_templateFileNameChars, 
                                 B_, "\",", _B, BR, B_, " xml = \"", _B, m_documentFileNameChars, B_, "\")", _B, BR, NULL_POINTER);
                        }
                    }
                }
                if ((error  = m_xslTransformer->Finalize()))
                {
                    OutputContentL
                    (H1_, m_cgiNameChars, _H1, 
                     B_, "...failed on m_xslTransformer-", GT, "Finalize()", _B, BR, NULL_POINTER);
                }
            }
            cXSLTransformerInterface::DestroyInstance(m_xslTransformer);
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
    (cCharWriterInterface& errors, 
     cXSLTransformerInterface& xslTransformer) 
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
            {
                errors.WriteL
                ("...failed on xslTransformer.SetLiteralParameter",
                 "(name = \"", name, "\", value = \"", value ,"\")", NULL_POINTER);
                return count = -error;
            }
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

        if ((chars = GetDocumentFileName(length)))
            OutputContentL(B_, "document filename=\"", _B, chars, B_, "\"", _B, BR, NULL_POINTER);

        if ((chars = GetTemplateFileName(length)))
            OutputContentL(B_, "template filename=\"", _B, chars, B_, "\"", _B, BR, NULL_POINTER);

        if ((chars = GetDocumentURI(length)))
            OutputContentL(B_, "document uri=\"", _B, chars, B_, "\"", _B, BR, NULL_POINTER);

        if ((chars = GetTemplateURI(length)))
            OutputContentL(B_, "template uri=\"", _B, chars, B_, "\"", _B, BR, NULL_POINTER);

        return err;
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
    (tLength& length, bool onlyFromDocumentNames=false) 
    {
        const tChar* chars = 0;
        const tChar* chars2 = 0;
        if ((chars = GetDocumentFileName
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
     * Function: GetDocumentFileName
     *
     *   Author: $author$
     *     Date: 3/26/2008
     **********************************************************************
     */
    virtual const tChar* 
    GetDocumentFileName
    (tLength& length, bool onlyFromDocumentNames=false) 
    {
        const tChar* chars = 0;
        const tChar* chars2;
        cDocumentFileNameItem* i;
        cHTTPFormFieldReference f;

        for (i = cDocumentFileNameList::m_instance.GetFirstItem();
             i; i = i->GetNextItem())
        {
            if ((f = m_formFields.FindField(i->m_name)))
            if ((chars = f->GetValue(length)))
                return chars;
        }

        if (!onlyFromDocumentNames)
        if ((chars2 = GetTemplateFileNameBase(length, true)))
        if (0 < (length = m_documentFileName.Assign(chars2, length)))
        if (0 < (length = m_documentFileName.Append(&m_filenameExtensionSeparatorChar, 1)))
        if (0 < (length = m_documentFileName.Append(m_documentFileNameExtensionChars)))
            chars = m_documentFileName.HasChars(length);

        return chars;
    }
    /**
     **********************************************************************
     * Function: GetDocumentFilePath
     *
     *   Author: $author$
     *     Date: 12/29/2008
     **********************************************************************
     */
    virtual const tChar* GetDocumentFilePath
    (tLength& length,
     bool onlyFromTemplateNames=false) 
    {
        const tChar* chars = 0;
        cDocumentFilePathItem* i;
        cHTTPFormFieldReference f;

        for (i = cDocumentFilePathList::m_instance.GetFirstItem();
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
        if (0 < (length = m_documentURI.Append(m_documentFileNameExtensionChars)))
            chars = m_documentURI.HasChars(length);

        return chars;
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

        for (i = cTemplateFileNameList::m_instance.GetFirstItem();
             i; i = i->GetNextItem())
        {
            if ((f = m_formFields.FindField(i->m_name)))
            if ((chars = f->GetValue(length)))
                return chars;
        }

        if (!(chars = CGIEnvHasChars
            (length, e_CGI_ENV_PATH_TRANSLATED)))
        if (!onlyFromTemplateNames)
        if ((chars2 = GetDocumentFileNameBase(length, true)))
        if (0 < (length = m_templateFileName.Assign(chars2, length)))
        if (0 < (length = m_templateFileName.Append(&m_filenameExtensionSeparatorChar, 1)))
        if (0 < (length = m_templateFileName.Append(m_templateFileNameExtensionChars)))
            chars = m_templateFileName.HasChars(length);

        return chars;
    }
    /**
     **********************************************************************
     * Function: GetTemplateFilePath
     *
     *   Author: $author$
     *     Date: 12/29/2008
     **********************************************************************
     */
    virtual const tChar* 
    GetTemplateFilePath
    (tLength& length, bool onlyFromTemplateNames=false) 
    {
        const tChar* chars = 0;
        cTemplateFilePathItem* i;
        cHTTPFormFieldReference f;

        for (i = cTemplateFilePathList::m_instance.GetFirstItem();
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
        if (0 < (length = m_templateURI.Append(m_templateFileNameExtensionChars)))
            chars = m_templateURI.HasChars(length);

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
        const tChar* chars = GetAbsoluteFileName
        (length, filename, filenameChars, absoluteFileNameChars);
        return chars;
    }
    /**
     **********************************************************************
     * Function: GetAbsoluteDocumentFileName
     *
     *   Author: $author$
     *     Date: 5/1/2011
     **********************************************************************
     */
    virtual const tChar* 
    GetAbsoluteDocumentFileName
    (tLength& length, cCharString& filename,
     const tChar* filenameChars, const tChar* absoluteFileNameChars) 
    {
        const tChar* chars = GetAbsoluteFileName
        (length, filename, filenameChars, absoluteFileNameChars);
        return chars;
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
     * Function: GetAbsoluteFileName
     *
     *   Author: $author$
     *     Date: 3/26/2008
     **********************************************************************
     */
    virtual const tChar* 
    GetAbsoluteFileName
    (tLength& length, cCharString& filename,
     const tChar* filenameChars, const tChar* absoluteFileNameChars) 
    {
        const tChar* chars = filenameChars;
        const tChar* absolutePathChars;
        tLength absolutePathLength;
        tChar separatorChar;

        if (absoluteFileNameChars)

        if (!(absolutePathChars = GetAbsoluteFileNamePath
            (absolutePathLength, separatorChar, filenameChars)))

        if ((absolutePathChars = GetAbsoluteFileNamePath
            (absolutePathLength, separatorChar, absoluteFileNameChars)))

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

        if ((PLATFORM_EXTENSION_SEPARATOR_CHAR != absoluteFileNameChars[0]) 
            && (FOREIGN_EXTENSION_SEPARATOR_CHAR != absoluteFileNameChars[0]))

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
};
#endif /* _CXSLCGI_HXX */
