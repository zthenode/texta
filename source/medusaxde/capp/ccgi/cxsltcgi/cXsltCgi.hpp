///////////////////////////////////////////////////////////////////////
// Copyright (c) 1988-2011 $organization$
//
// This software is provided by the author and contributors ``as is'' 
// and any express or implied warranties, including, but not limited to, 
// the implied warranties of merchantability and fitness for a particular 
// purpose are disclaimed. In no event shall the author or contributors 
// be liable for any direct, indirect, incidental, special, exemplary, 
// or consequential damages (including, but not limited to, procurement 
// of substitute goods or services; loss of use, data, or profits; or 
// business interruption) however caused and on any theory of liability, 
// whether in contract, strict liability, or tort (including negligence 
// or otherwise) arising in any way out of the use of this software, 
// even if advised of the possibility of such damage.
//
//   File: cXsltCgi.hpp
//
// Author: $author$
//   Date: 7/27/2011
///////////////////////////////////////////////////////////////////////
#if !defined(_CXSLTCGI_HPP) || defined(CXSLTCGI_MEMBERS_ONLY)
#if !defined(_CXSLTCGI_HPP) && !defined(CXSLTCGI_MEMBERS_ONLY)
#define _CXSLTCGI_HPP
#endif // !defined(_CXSLTCGI_HPP) && !defined(CXSLTCGI_MEMBERS_ONLY) 

#if !defined(CXSLTCGI_MEMBERS_ONLY)

#if !defined(CXSLTCGI_NAME) 
#define CXSLTCGI_NAME "cXsltCgi"
#else // !defined(CXSLTCGI_NAME) 
#endif // !defined(CXSLTCGI_NAME) 

#if !defined(CXSLTCGI_PATH) 
#define CXSLTCGI_PATH \
    "/medusaxde/xsl" \
    CXSLTCGI_PATH_SEPARATOR \
    CXSLTCGI_NAME
#else // !defined(CXSLTCGI_PATH) 
#endif // !defined(CXSLTCGI_PATH) 

#if !defined(CXSLTCGI_XSLT_PATH) 
#define CXSLTCGI_XSLT_PATH CXSLTCGI_PATH
#else // !defined(CXSLTCGI_XSLT_PATH) 
#endif // !defined(CXSLTCGI_XSLT_PATH) 

#if !defined(CXSLTCGI_XML_PATH) 
#define CXSLTCGI_XML_PATH CXSLTCGI_PATH
#else // !defined(CXSLTCGI_XML_PATH) 
#endif // !defined(CXSLTCGI_XML_PATH) 

#if !defined(CXSLTCGI_FILEPATH) 
#define CXSLTCGI_FILEPATH \
    "../../../../../mxde/medusaxde/doc/xsl" \
    CXSLTCGI_FILEPATH_SEPARATOR \
    CXSLTCGI_NAME \
    CXSLTCGI_FILEPATH_SEPARATOR
#else // !defined(CXSLTCGI_FILEPATH) 
#endif // !defined(CXSLTCGI_FILEPATH) 

#if !defined(CXSLTCGI_XSLT_FILEPATH) 
#define CXSLTCGI_XSLT_FILEPATH CXSLTCGI_FILEPATH
#else // !defined(CXSLTCGI_XSLT_FILEPATH) 
#endif // !defined(CXSLTCGI_XSLT_FILEPATH) 

#if !defined(CXSLTCGI_XML_FILEPATH) 
#define CXSLTCGI_XML_FILEPATH CXSLTCGI_FILEPATH
#else // !defined(CXSLTCGI_XML_FILEPATH) 
#endif // !defined(CXSLTCGI_XML_FILEPATH) 

#if !defined(CXSLTCGI_XSLT_FILEBASE) 
#define CXSLTCGI_XSLT_FILEBASE CXSLTCGI_NAME
#else // !defined(CXSLTCGI_XSLT_FILEBASE) 
#endif // !defined(CXSLTCGI_XSLT_FILEBASE) 

#if !defined(CXSLTCGI_XML_FILEBASE) 
#define CXSLTCGI_XML_FILEBASE CXSLTCGI_NAME
#else // !defined(CXSLTCGI_XML_FILEBASE) 
#endif // !defined(CXSLTCGI_XML_FILEBASE) 

#define CXSLTCGI_PATH_SEPARATOR "/"
#define CXSLTCGI_FILEPATH_SEPARATOR "/"
#define CXSLTCGI_FILEEXTENSION_SEPARATOR "."
#define CXSLTCGI_XSLT_FILEEXTENSION "xslt"
#define CXSLTCGI_XML_FILEEXTENSION "xml"

#define CXSLTCGI_XSLT_FILENAME \
    CXSLTCGI_XSLT_FILEPATH \
    CXSLTCGI_XSLT_FILEBASE \
    CXSLTCGI_FILEEXTENSION_SEPARATOR \
    CXSLTCGI_XSLT_FILEEXTENSION

#define CXSLTCGI_XML_FILENAME \
    CXSLTCGI_XML_FILEPATH \
    CXSLTCGI_XML_FILEBASE \
    CXSLTCGI_FILEEXTENSION_SEPARATOR \
    CXSLTCGI_XML_FILEEXTENSION

#define CXSLTCGI_CGI_ENV_XSLT_PARAMETER_NAME_PREFIX "cgi_env_"

#include "cCgi.hpp"
#include "cCgiXmlWriter.hpp"
#include "cXsltProcessorInterface.hpp"
#include "cFileSystemEntry.hpp"
#include "cFilePath.hpp"
#include "cStringReader.hpp"
#include "cStringWriter.hpp"
#include "cString.hpp"
#include "cTypes.hpp"
#include "cDebug.hpp"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

///////////////////////////////////////////////////////////////////////
// Typedef: cXsltCgiExtend
//
//  Author: $author$
//    Date: 7/27/2011
///////////////////////////////////////////////////////////////////////
typedef cCgi
cXsltCgiExtend;
///////////////////////////////////////////////////////////////////////
//  Class: cXsltCgi
//
// Author: $author$
//   Date: 7/27/2011
///////////////////////////////////////////////////////////////////////
class c_INSTANCE_CLASS cXsltCgi
: //virtual public cXsltCgiImplement,
  public cXsltCgiExtend
{
public:
    //typedef cXsltCgiImplement cImplements;
    typedef cXsltCgiExtend cExtends;

    cString m_xmlSourceString;
    cStringReader m_xmlSourceReader;
    cStringWriter m_xmlSourceWriter;
    cCgiXmlWriter m_cgiXmlSourceWriter;

    cString m_xsltSourcePath;
    cString m_xmlSourcePath;

    cString m_xsltSourceFileName;
    cString m_xmlSourceFileName;

    cString m_xsltFileExtension;
    cString m_xmlFileExtension;
    cString m_fileExtensionSeparator;

    cFileSystemEntry m_fileSystemEntry;

    cString m_absoluteXsltSourceFileName;
    cString m_absoluteXmlSourceFileName;

    cString m_derivedXsltSourceFileName;
    cString m_derivedXmlSourceFileName;

    cString m_workingXsltSourceFileName;
    cString m_workingXmlSourceFileName;

    ///////////////////////////////////////////////////////////////////////
    //  Constructor: cXsltCgi
    //
    //       Author: $author$
    //         Date: 7/27/2011
    ///////////////////////////////////////////////////////////////////////
    cXsltCgi
    (const char* name=CXSLTCGI_NAME,
     const char* xsltSourceFileName=CXSLTCGI_XSLT_FILENAME,
     const char* xmlSourceFileName=CXSLTCGI_XML_FILENAME,
     const char* xsltFileExtension=CXSLTCGI_XSLT_FILEEXTENSION,
     const char* xmlFileExtension=CXSLTCGI_XML_FILEEXTENSION,
     const char* fileExtensionSeparator=CXSLTCGI_FILEEXTENSION_SEPARATOR,
     const char* xsltSourcePath=CXSLTCGI_XSLT_PATH,
     const char* xmlSourcePath=CXSLTCGI_XML_PATH)
    : cExtends(name),

      m_xmlSourceReader(m_xmlSourceString),
      m_xmlSourceWriter(m_xmlSourceString),
      m_cgiXmlSourceWriter(m_xmlSourceWriter),

      m_xsltSourcePath(xsltSourcePath),
      m_xmlSourcePath(xmlSourcePath),

      m_xsltSourceFileName(xsltSourceFileName),
      m_xmlSourceFileName(xmlSourceFileName),

      m_xsltFileExtension(xsltFileExtension),
      m_xmlFileExtension(xmlFileExtension),
      m_fileExtensionSeparator(fileExtensionSeparator)
    {
    }
    ///////////////////////////////////////////////////////////////////////
    //  Destructor: ~cXsltCgi
    //
    //      Author: $author$
    //        Date: 7/27/2011
    ///////////////////////////////////////////////////////////////////////
    virtual ~cXsltCgi()
    {
    }
#else // !defined(CXSLTCGI_MEMBERS_ONLY) 
#endif // !defined(CXSLTCGI_MEMBERS_ONLY) 

#if !defined(CXSLTCGI_MEMBERS_ONLY)
    ///////////////////////////////////////////////////////////////////////
    //  Function: Run
    //
    //    Author: $author$
    //      Date: 7/28/2011
    ///////////////////////////////////////////////////////////////////////
    virtual int Run
    (int argc,
     char** argv,
     char** env)
    {
        int errn = 0;
        const char* contentTypeChars;
        const char* xsltSourceFileNameChars;
        const char* xmlSourceFileNameChars;
        const char* absoluteFileNameChars;
        ssize_t absoluteFileNameLength;
        eError error;
        cXsltProcessorInterface* xslt;

        contentTypeChars = GetContentTypeChars();
        xsltSourceFileNameChars = GetXsltSourceFileNameChars(m_workingXsltSourceFileName);
        xmlSourceFileNameChars = GetXmlSourceFileNameChars(m_workingXmlSourceFileName, xsltSourceFileNameChars);

        if ((contentTypeChars))
            SetContentType(contentTypeChars);
        else
        SetContentType(m_contentTypeHtml);

        if ((m_contentOutput))
        {
            cCharWriterInterface& out = (cCharWriterInterface&)(*m_contentOutput);
            cCharWriterInterface& err = (cCharWriterInterface&)(*m_contentOutput);

            if ((xslt = cXsltProcessorInterface::GetInstance(error)))
            {
                if (!(error = xslt->Init()))
                {
                    if ((error = SetXsltParams(*xslt)))
                        c_DB_ERROR("() failed on SetXsltParams()");
                    else
                    if ((xsltSourceFileNameChars))
                    {
                        if ((xmlSourceFileNameChars))
                        {
                            if ((absoluteFileNameChars = GetAbsoluteFileNameChars
                                (absoluteFileNameLength, m_absoluteXmlSourceFileName, 
                                 xmlSourceFileNameChars, xsltSourceFileNameChars)))
                                 xmlSourceFileNameChars = absoluteFileNameChars;

                            if ((error = xslt->ProcessFiles
                                (err, out, xsltSourceFileNameChars, xmlSourceFileNameChars)))
                                c_DB_ERROR("() failed on xslt->ProcessFiles(err, out , \"" << xsltSourceFileNameChars << "\", \"" << xmlSourceFileNameChars << "\")");
                        }
                        else
                        {
                            m_cgiXmlSourceWriter.Put(*this);
                            m_xmlSourceReader.Reset();

                            if ((error = xslt->Process
                                (err, out, xsltSourceFileNameChars, 
                                 m_xmlSourceReader, xsltSourceFileNameChars)))
                                c_DB_ERROR("() failed on xslt->Process(err, out , \"" << xsltSourceFileNameChars << "\", m_xmlSourceReader, \"" << xmlSourceFileNameChars << "\")");
                        }
                    }
                    xslt->Finish();
                }
                cXsltProcessorInterface::FreeInstance(xslt);
            }
        }
        return errn;
    }
#else // !defined(CXSLTCGI_MEMBERS_ONLY) 
#endif // !defined(CXSLTCGI_MEMBERS_ONLY) 

    ///////////////////////////////////////////////////////////////////////
    //  Function: SetXsltParams
    //
    //    Author: $author$
    //      Date: 8/22/2011
    ///////////////////////////////////////////////////////////////////////
    virtual eError SetXsltParams
    (cXsltProcessorInterface& xslt)
#if defined(CXSLTCGI_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CXSLTCGI_MEMBER_FUNCS_INTERFACE) 
    {
        eError error = e_ERROR_NONE;
#if !defined(CXSLTCGI_MEMBER_FUNCS_IMPLEMENT)
        if ((error = SetXsltParamsFromCgiEnv(xslt)))
            c_DB_ERROR("() failed on SetXsltParamsFromCgiEnv()");
        else
        if ((error = SetXsltParamsFromHttpFormFields(xslt)))
            c_DB_ERROR("() failed on SetXsltParamsFromHttpFormFields()");
#else // !defined(CXSLTCGI_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CXSLTCGI_MEMBER_FUNCS_IMPLEMENT) 
        return error;
    }
#endif // defined(CXSLTCGI_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    //  Function: SetXsltParamsFromHttpFormFields
    //
    //    Author: $author$
    //      Date: 8/2/2011
    ///////////////////////////////////////////////////////////////////////
    virtual eError SetXsltParamsFromHttpFormFields
    (cXsltProcessorInterface& xslt)
#if defined(CXSLTCGI_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CXSLTCGI_MEMBER_FUNCS_INTERFACE) 
    {
        eError error = e_ERROR_NONE;
#if !defined(CXSLTCGI_MEMBER_FUNCS_IMPLEMENT)
        cHttpFormFieldsIterator* atField;
        cHttpFormFieldInterface* field;
        cString xmlAttrValue;
        cStringWriter xmlAttrWriter(xmlAttrValue);
        cXmlAttributeEncoder xmlAttrEncoder(xmlAttrWriter);

        if ((field = GetFirstFormField(atField)))
        do
        {
            const cString& name = field->GetName();
            const cString& value = field->GetValue();
            const char* chars;
            if ((chars = value.Chars()))
            if (0 <= (xmlAttrValue.Clear()))
            if (0 <= (xmlAttrEncoder.Write(chars)))
            if ((error = xslt.SetLiteralParameter(name, xmlAttrValue)))
            {
                c_DB_ERROR("() failed on xslt.SetLiteralParameter(\"" << name << "\",\"" << xmlAttrValue << "\")");
                break;
            }
        }
        while ((field = GetNextFormField(*atField)));

        //xslt.SetLiteralParameter("form", "1");

#else // !defined(CXSLTCGI_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CXSLTCGI_MEMBER_FUNCS_IMPLEMENT) 
        return error;
    }
#endif // defined(CXSLTCGI_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    //  Function: SetXsltParamsFromCgiEnv
    //
    //    Author: $author$
    //      Date: 8/20/2011
    ///////////////////////////////////////////////////////////////////////
    virtual eError SetXsltParamsFromCgiEnv
    (cXsltProcessorInterface& xslt)
#if defined(CXSLTCGI_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CXSLTCGI_MEMBER_FUNCS_INTERFACE) 
    {
        eError error = e_ERROR_NONE;
#if !defined(CXSLTCGI_MEMBER_FUNCS_IMPLEMENT)
        cString name;
        cString xmlAttrValue;
        cStringWriter xmlAttrWriter(xmlAttrValue);
        cXmlAttributeEncoder xmlAttrEncoder(xmlAttrWriter);
        const char* prefix;
        const char* envName;
        const char* envValue;
        eCgiEnv env;

        if ((prefix = GetCgiEnvXsltParameterNamePrefix()))
        for (envName = GetFirstCgiEnv(env, envValue); 
             envName; envName = GetNextCgiEnv(env, envValue))
        {
            name.Assign(prefix);
            name.Append(envName);
            if ((envValue))
            if (0 <= (xmlAttrValue.Clear()))
            if (0 <= (xmlAttrEncoder.Write(envValue)))
            if ((error = xslt.SetLiteralParameter(name, xmlAttrValue)))
            {
                c_DB_ERROR("() failed on xslt.SetLiteralParameter(\"" << name << "\",\"" << xmlAttrValue << "\")");
                break;
            }
        }
#else // !defined(CXSLTCGI_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CXSLTCGI_MEMBER_FUNCS_IMPLEMENT) 
        return error;
    }
#endif // defined(CXSLTCGI_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    //  Function: SetXsltParamNamesToLiteral
    //
    //    Author: $author$
    //      Date: 8/22/2011
    ///////////////////////////////////////////////////////////////////////
    virtual eError SetXsltParamNamesToLiteral
    (cXsltProcessorInterface& xslt,
     const char**names,
     const cString& value)
#if defined(CXSLTCGI_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CXSLTCGI_MEMBER_FUNCS_INTERFACE) 
    {
        eError error = e_ERROR_NONE;
#if !defined(CXSLTCGI_MEMBER_FUNCS_IMPLEMENT)
        cString name;
        cString xmlAttrValue;
        cStringWriter xmlAttrWriter(xmlAttrValue);
        cXmlAttributeEncoder xmlAttrEncoder(xmlAttrWriter);
        const char* nameChars;
        const char* valueChars;

        if ((names) && (valueChars = value.Chars()))
        if (0 <= (xmlAttrEncoder.Write(valueChars)))
        while (nameChars = *(names++))
        {
            name.Assign(nameChars);
            if ((error = xslt.SetLiteralParameter(name, xmlAttrValue)))
            {
                c_DB_ERROR("() failed on xslt.SetLiteralParameter(\"" << name << "\",\"" << xmlAttrValue << "\")");
                break;
            }
        }
#else // !defined(CXSLTCGI_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CXSLTCGI_MEMBER_FUNCS_IMPLEMENT) 
        return error;
    }
#endif // defined(CXSLTCGI_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    //  Function: SetXsltParamToLiteral
    //
    //    Author: $author$
    //      Date: 8/29/2011
    ///////////////////////////////////////////////////////////////////////
    virtual eError SetXsltParamToLiteral
    (cXsltProcessorInterface& xslt,
     const cString& name,
     const cString& value)
#if defined(CXSLTCGI_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CXSLTCGI_MEMBER_FUNCS_INTERFACE) 
    {
        eError error = e_ERROR_NONE;
#if !defined(CXSLTCGI_MEMBER_FUNCS_IMPLEMENT)
        cString xmlAttrValue;
        cStringWriter xmlAttrWriter(xmlAttrValue);
        cXmlAttributeEncoder xmlAttrEncoder(xmlAttrWriter);
        const char* valueChars;

        if ((valueChars = value.Chars()))
        if (0 <= (xmlAttrEncoder.Write(valueChars)))
        if ((error = xslt.SetLiteralParameter(name, xmlAttrValue)))
            c_DB_ERROR("() failed on xslt.SetLiteralParameter(\"" << name << "\",\"" << xmlAttrValue << "\")");

#else // !defined(CXSLTCGI_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CXSLTCGI_MEMBER_FUNCS_IMPLEMENT) 
        return error;
    }
#endif // defined(CXSLTCGI_MEMBER_FUNCS_INTERFACE) 

    ///////////////////////////////////////////////////////////////////////
    //  Function: GetXsltSourceFileNameChars
    //
    //    Author: $author$
    //      Date: 7/28/2011
    ///////////////////////////////////////////////////////////////////////
    virtual const char* GetXsltSourceFileNameChars
    (cString& fileName, const char* xmlSourceFileNameChars=0)
#if defined(CXSLTCGI_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CXSLTCGI_MEMBER_FUNCS_INTERFACE) 
    {
        const char* xsltSourceFileNameChars = 0;
#if !defined(CXSLTCGI_MEMBER_FUNCS_IMPLEMENT)
        const char* chars;
        if ((chars = GetXsltSourceFileNameChars(xmlSourceFileNameChars)))
        if (0 <= (fileName.Assign(chars)))
            xsltSourceFileNameChars = fileName.HasChars();
#else // !defined(CXSLTCGI_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CXSLTCGI_MEMBER_FUNCS_IMPLEMENT) 
        return xsltSourceFileNameChars;
    }
#endif // defined(CXSLTCGI_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    //  Function: GetXmlSourceFileNameChars
    //
    //    Author: $author$
    //      Date: 7/28/2011
    ///////////////////////////////////////////////////////////////////////
    virtual const char* GetXmlSourceFileNameChars
    (cString& fileName, const char* xsltSourceFileNameChars=0)
#if defined(CXSLTCGI_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CXSLTCGI_MEMBER_FUNCS_INTERFACE) 
    {
        const char* xmlSourceFileNameChars = 0;
#if !defined(CXSLTCGI_MEMBER_FUNCS_IMPLEMENT)
        const char* chars;
        if ((chars = GetXmlSourceFileNameChars(xsltSourceFileNameChars)))
        if (0 <= (fileName.Assign(chars)))
            xmlSourceFileNameChars = fileName.HasChars();
#else // !defined(CXSLTCGI_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CXSLTCGI_MEMBER_FUNCS_IMPLEMENT) 
        return xmlSourceFileNameChars;
    }
#endif // defined(CXSLTCGI_MEMBER_FUNCS_INTERFACE) 

    ///////////////////////////////////////////////////////////////////////
    //  Function: GetXsltSourceFileNameChars
    //
    //    Author: $author$
    //      Date: 7/28/2011
    ///////////////////////////////////////////////////////////////////////
    virtual const char* GetXsltSourceFileNameChars
    (const char* xmlSourceFileNameChars=0)
#if defined(CXSLTCGI_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CXSLTCGI_MEMBER_FUNCS_INTERFACE) 
    {
        const char* xsltSourceFileNameChars = 0;
#if !defined(CXSLTCGI_MEMBER_FUNCS_IMPLEMENT)
        const char** names;
        const char* name;

        //
        // Check form parameters for xslt filename
        //
        if ((names = GetXsltFileParameterNames()))
        if ((name = GetFormParameterValueChars(names)))
            return name;

        //
        // Check cgi path translated for xslt filename
        //
        if ((name = GetXsltEnvPathTranslatedSourceFileNameChars()))
        if ((name[0]))
            return name;

        //
        // return default xslt filename
        //
        xsltSourceFileNameChars = m_xsltSourceFileName.HasChars();
#else // !defined(CXSLTCGI_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CXSLTCGI_MEMBER_FUNCS_IMPLEMENT) 
        return xsltSourceFileNameChars;
    }
#endif // defined(CXSLTCGI_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    //  Function: GetXsltEnvPathTranslatedSourceFileNameChars
    //
    //    Author: $author$
    //      Date: 8/20/2011
    ///////////////////////////////////////////////////////////////////////
    virtual const char* GetXsltEnvPathTranslatedSourceFileNameChars() const
#if defined(CXSLTCGI_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CXSLTCGI_MEMBER_FUNCS_INTERFACE) 
    {
        const char* chars = 0;
#if !defined(CXSLTCGI_MEMBER_FUNCS_IMPLEMENT)
        const char* name;
        if ((name = GetCgiEnv(e_CGI_ENV_PATH_TRANSLATED)))
        if ((name[0]))
            return name;
#else // !defined(CXSLTCGI_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CXSLTCGI_MEMBER_FUNCS_IMPLEMENT) 
        return chars;
    }
#endif // defined(CXSLTCGI_MEMBER_FUNCS_INTERFACE) 

    ///////////////////////////////////////////////////////////////////////
    //  Function: GetXmlSourceFileNameChars
    //
    //    Author: $author$
    //      Date: 7/28/2011
    ///////////////////////////////////////////////////////////////////////
    virtual const char* GetXmlSourceFileNameChars
    (const char* xsltSourceFileNameChars=0)
#if defined(CXSLTCGI_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CXSLTCGI_MEMBER_FUNCS_INTERFACE) 
    {
        const char* xmlSourceFileNameChars = 0;
#if !defined(CXSLTCGI_MEMBER_FUNCS_IMPLEMENT)
        eFileSystemEntryType fileType;
        const char** names;
        const char* name;
        const char* ext;
        ssize_t length;

        //
        // Check form parameters for xml filename
        //
        if ((names = GetXmlFileParameterNames()))
        if ((name = GetFormParameterValueChars(names)))
            return name;

        //
        // See if xml filename derived from xslt filename exists
        //
        if ((name = xsltSourceFileNameChars))
        if ((ext = m_xmlFileExtension.HasChars()))
        if ((name = GetDerivedFileNameChars
            (length, m_derivedXmlSourceFileName, ext, name)))
        {
            if (e_FILE_SYSTEM_ENTRY_TYPE_FILE !=
                (fileType = m_fileSystemEntry.Exists(m_derivedXmlSourceFileName)))
            {
                if (!(m_xmlSourceFileName.HasChars()))
                    c_DB_ERROR("() failed fileType = " << fileType << " on m_fileSystemEntry.Exists(\"" << name << "\")");
            }
            else
            return name;
        }

        //
        // return default xml filename
        //
        xmlSourceFileNameChars = m_xmlSourceFileName.HasChars();
#else // !defined(CXSLTCGI_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CXSLTCGI_MEMBER_FUNCS_IMPLEMENT) 
        return xmlSourceFileNameChars;
    }
#endif // defined(CXSLTCGI_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    //  Function: GetXmlEnvPathTranslatedSourceFileNameChars
    //
    //    Author: $author$
    //      Date: 8/20/2011
    ///////////////////////////////////////////////////////////////////////
    virtual const char* GetXmlEnvPathTranslatedSourceFileNameChars() const
#if defined(CXSLTCGI_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CXSLTCGI_MEMBER_FUNCS_INTERFACE) 
    {
        const char* chars = 0;
#if !defined(CXSLTCGI_MEMBER_FUNCS_IMPLEMENT)
        const char* name;
        if ((name = GetCgiEnv(e_CGI_ENV_PATH_TRANSLATED)))
        if ((name[0]))
            return name;
#else // !defined(CXSLTCGI_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CXSLTCGI_MEMBER_FUNCS_IMPLEMENT) 
        return chars;
    }
#endif // defined(CXSLTCGI_MEMBER_FUNCS_INTERFACE) 

    ///////////////////////////////////////////////////////////////////////
    //  Function: GetEnvPathTranslatedChars
    //
    //    Author: $author$
    //      Date: 8/29/2011
    ///////////////////////////////////////////////////////////////////////
    virtual const char* GetEnvPathTranslatedChars() const
#if defined(CXSLTCGI_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CXSLTCGI_MEMBER_FUNCS_INTERFACE) 
    {
        const char* chars = 0;
#if !defined(CXSLTCGI_MEMBER_FUNCS_IMPLEMENT)
        const char* name;
        if ((name = GetCgiEnv(e_CGI_ENV_PATH_TRANSLATED)))
        if ((name[0]))
            return name;
#else // !defined(CXSLTCGI_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CXSLTCGI_MEMBER_FUNCS_IMPLEMENT) 
        return chars;
    }
#endif // defined(CXSLTCGI_MEMBER_FUNCS_INTERFACE) 

    ///////////////////////////////////////////////////////////////////////
    //  Function: GetContentTypeChars
    //
    //    Author: $author$
    //      Date: 8/2/2011
    ///////////////////////////////////////////////////////////////////////
    virtual const char* GetContentTypeChars()
#if defined(CXSLTCGI_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CXSLTCGI_MEMBER_FUNCS_INTERFACE) 
    {
        const char* contentTypeChars = 0;
#if !defined(CXSLTCGI_MEMBER_FUNCS_IMPLEMENT)
        const char** names;
        const char* name;
        if ((names = GetContentTypeParameterNames()))
        if ((name = GetFormParameterValueChars(names)))
            return name;
#else // !defined(CXSLTCGI_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CXSLTCGI_MEMBER_FUNCS_IMPLEMENT) 
        return contentTypeChars;
    }
#endif // defined(CXSLTCGI_MEMBER_FUNCS_INTERFACE) 

    ///////////////////////////////////////////////////////////////////////
    //  Function: GetFormParameterValueChars
    //
    //    Author: $author$
    //      Date: 8/9/2011
    ///////////////////////////////////////////////////////////////////////
    virtual const char* GetFormParameterValueChars
    (const char** names,
     bool isFromQueryString=false) const
#if defined(CXSLTCGI_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CXSLTCGI_MEMBER_FUNCS_INTERFACE) 
    {
        const char* value = 0;
#if !defined(CXSLTCGI_MEMBER_FUNCS_IMPLEMENT)
        const char* name;
        cHttpFormFieldInterface* field;

        if ((names))
        for (name = *names; name; name = *(++names))
        {
            if ((field = FindFirstFormField(name)))
            if ((value = field->GetValue().HasChars()))
                return value;
        }
#else // !defined(CXSLTCGI_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CXSLTCGI_MEMBER_FUNCS_IMPLEMENT) 
        return value;
    }
#endif // defined(CXSLTCGI_MEMBER_FUNCS_INTERFACE) 

    ///////////////////////////////////////////////////////////////////////
    //  Function: GetXsltPathParameterNames
    //
    //    Author: $author$
    //      Date: 7/28/2011
    ///////////////////////////////////////////////////////////////////////
    virtual const char** GetXsltPathParameterNames() const
#if defined(CXSLTCGI_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CXSLTCGI_MEMBER_FUNCS_INTERFACE) 
#if !defined(CXSLTCGI_MEMBER_FUNCS_IMPLEMENT)
    ;
#else // !defined(CXSLTCGI_MEMBER_FUNCS_IMPLEMENT) 
    {
        const char** names = 0;
        return names;
    }
#endif // !defined(CXSLTCGI_MEMBER_FUNCS_IMPLEMENT) 
#endif // defined(CXSLTCGI_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    //  Function: GetXmlPathParameterNames
    //
    //    Author: $author$
    //      Date: 7/28/2011
    ///////////////////////////////////////////////////////////////////////
    virtual const char** GetXmlPathParameterNames() const
#if defined(CXSLTCGI_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CXSLTCGI_MEMBER_FUNCS_INTERFACE) 
#if !defined(CXSLTCGI_MEMBER_FUNCS_IMPLEMENT)
    ;
#else // !defined(CXSLTCGI_MEMBER_FUNCS_IMPLEMENT) 
    {
        const char** names = 0;
        return names;
    }
#endif // !defined(CXSLTCGI_MEMBER_FUNCS_IMPLEMENT) 
#endif // defined(CXSLTCGI_MEMBER_FUNCS_INTERFACE) 

    ///////////////////////////////////////////////////////////////////////
    //  Function: GetXsltFileParameterNames
    //
    //    Author: $author$
    //      Date: 7/28/2011
    ///////////////////////////////////////////////////////////////////////
    virtual const char** GetXsltFileParameterNames() const
#if defined(CXSLTCGI_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CXSLTCGI_MEMBER_FUNCS_INTERFACE) 
#if !defined(CXSLTCGI_MEMBER_FUNCS_IMPLEMENT)
    ;
#else // !defined(CXSLTCGI_MEMBER_FUNCS_IMPLEMENT) 
    {
        const char** names = 0;
        return names;
    }
#endif // !defined(CXSLTCGI_MEMBER_FUNCS_IMPLEMENT) 
#endif // defined(CXSLTCGI_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    //  Function: GetXmlFileParameterNames
    //
    //    Author: $author$
    //      Date: 7/28/2011
    ///////////////////////////////////////////////////////////////////////
    virtual const char** GetXmlFileParameterNames() const
#if defined(CXSLTCGI_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CXSLTCGI_MEMBER_FUNCS_INTERFACE) 
#if !defined(CXSLTCGI_MEMBER_FUNCS_IMPLEMENT)
    ;
#else // !defined(CXSLTCGI_MEMBER_FUNCS_IMPLEMENT) 
    {
        const char** names = 0;
        return names;
    }
#endif // !defined(CXSLTCGI_MEMBER_FUNCS_IMPLEMENT) 
#endif // defined(CXSLTCGI_MEMBER_FUNCS_INTERFACE) 

    ///////////////////////////////////////////////////////////////////////
    //  Function: GetContentTypeParameterNames
    //
    //    Author: $author$
    //      Date: 8/2/2011
    ///////////////////////////////////////////////////////////////////////
    virtual const char** GetContentTypeParameterNames() const
#if defined(CXSLTCGI_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CXSLTCGI_MEMBER_FUNCS_INTERFACE) 
#if !defined(CXSLTCGI_MEMBER_FUNCS_IMPLEMENT)
    ;
#else // !defined(CXSLTCGI_MEMBER_FUNCS_IMPLEMENT) 
    {
        const char** names = 0;
        return names;
    }
#endif // !defined(CXSLTCGI_MEMBER_FUNCS_IMPLEMENT) 
#endif // defined(CXSLTCGI_MEMBER_FUNCS_INTERFACE) 

    ///////////////////////////////////////////////////////////////////////
    //  Function: GetCgiEnvXsltParameterNamePrefix
    //
    //    Author: $author$
    //      Date: 8/20/2011
    ///////////////////////////////////////////////////////////////////////
    virtual const char* GetCgiEnvXsltParameterNamePrefix() const
#if defined(CXSLTCGI_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CXSLTCGI_MEMBER_FUNCS_INTERFACE) 
    {
        const char* chars = 0;
#if !defined(CXSLTCGI_MEMBER_FUNCS_IMPLEMENT)
        chars = CXSLTCGI_CGI_ENV_XSLT_PARAMETER_NAME_PREFIX;
#else // !defined(CXSLTCGI_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CXSLTCGI_MEMBER_FUNCS_IMPLEMENT) 
        return chars;
    }
#endif // defined(CXSLTCGI_MEMBER_FUNCS_INTERFACE) 

    ///////////////////////////////////////////////////////////////////////
    //  Function: GetDerivedFileNameChars
    //
    //    Author: $author$
    //      Date: 8/9/2011
    ///////////////////////////////////////////////////////////////////////
    virtual const char* GetDerivedFileNameChars
    (ssize_t& length,
     cString& fileName,
     const char* fileExtensionChars,
     const char* baseFileNameChars)
#if defined(CXSLTCGI_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CXSLTCGI_MEMBER_FUNCS_INTERFACE) 
    {
        const char* chars = 0;
#if !defined(CXSLTCGI_MEMBER_FUNCS_IMPLEMENT)
        if ((fileExtensionChars) && (baseFileNameChars))
        {
            ssize_t count = -1;
            const char* dot;
            const char* ext;

            if ((dot = m_fileExtensionSeparator.HasChars()))
            if ((ext = cChars::FindLast(baseFileNameChars, dot)))
                count = (ext - baseFileNameChars);

            if ((count))
            {
                fileName.Assign(baseFileNameChars, count);
                if ((dot = m_fileExtensionSeparator.HasChars()))
                if ((ext = m_xmlFileExtension.HasChars()))
                    fileName.AppendL(dot, ext, 0);

                chars = fileName.HasChars(length);
            }
        }
#else // !defined(CXSLTCGI_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CXSLTCGI_MEMBER_FUNCS_IMPLEMENT) 
        return chars;
    }
#endif // defined(CXSLTCGI_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    //  Function: GetAbsoluteFileNameChars
    //
    //    Author: $author$
    //      Date: 8/8/2011
    ///////////////////////////////////////////////////////////////////////
    virtual const char* GetAbsoluteFileNameChars
    (ssize_t& length,
     cString& fileName,
     const char* fileNameChars,
     const char* absoluteFileNameChars)
#if defined(CXSLTCGI_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CXSLTCGI_MEMBER_FUNCS_INTERFACE) 
    {
        const char* chars = 0;
#if !defined(CXSLTCGI_MEMBER_FUNCS_IMPLEMENT)
        const char* absolutePathChars;
        ssize_t absolutePathLength;
        char separatorChar;

        if ((chars = fileNameChars))

        if (!(absolutePathChars = GetAbsoluteFileNamePathChars
            (absolutePathLength, separatorChar, fileNameChars)))

        if ((absoluteFileNameChars))

        if ((absolutePathChars = GetAbsoluteFileNamePathChars
            (absolutePathLength, separatorChar, absoluteFileNameChars)))

        if (0 < (absolutePathLength = fileName.Assign
            (absolutePathChars, absolutePathLength)))
        if (0 < (absolutePathLength = fileName.Append(&separatorChar, 1)))
        if (0 < (absolutePathLength = fileName.Append(fileNameChars)))
        if ((absolutePathChars = fileName.HasChars(absolutePathLength)))
        {
            chars = absolutePathChars;
            length = absolutePathLength;
        }
#else // !defined(CXSLTCGI_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CXSLTCGI_MEMBER_FUNCS_IMPLEMENT) 
        return chars;
    }
#endif // defined(CXSLTCGI_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    //  Function: GetAbsoluteFileNamePathChars
    //
    //    Author: $author$
    //      Date: 8/8/2011
    ///////////////////////////////////////////////////////////////////////
    virtual const char* GetAbsoluteFileNamePathChars
    (ssize_t& length,
     char& separatorChar,
     const char* absoluteFileNameChars)
#if defined(CXSLTCGI_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CXSLTCGI_MEMBER_FUNCS_INTERFACE) 
    {
        const char* chars = 0;
#if !defined(CXSLTCGI_MEMBER_FUNCS_IMPLEMENT)
        const char* relativeFileNameChars = 0;

        if ((absoluteFileNameChars))

        if ((PLATFORM_EXTENSION_SEPARATOR_CHAR != absoluteFileNameChars[0]) 
            && (FOREIGN_EXTENSION_SEPARATOR_CHAR != absoluteFileNameChars[0]))

        if ((relativeFileNameChars = cChars::FindLast
            (absoluteFileNameChars, (char)(PLATFORM_DIRECTORY_SEPARATOR_CHAR))))
            separatorChar = PLATFORM_DIRECTORY_SEPARATOR_CHAR;
        else
        if ((relativeFileNameChars = cChars::FindLast
            (absoluteFileNameChars, (char)(FOREIGN_DIRECTORY_SEPARATOR_CHAR))))
            separatorChar = FOREIGN_DIRECTORY_SEPARATOR_CHAR;
        else
        if ((PLATFORM_VOLUME_SEPARATOR_CHAR))
        if ((relativeFileNameChars = cChars::FindLast
            (absoluteFileNameChars, (char)(PLATFORM_VOLUME_SEPARATOR_CHAR))))
            separatorChar = PLATFORM_VOLUME_SEPARATOR_CHAR;

        if ((relativeFileNameChars))
        if ((chars = absoluteFileNameChars))
            length = relativeFileNameChars - absoluteFileNameChars;
#else // !defined(CXSLTCGI_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CXSLTCGI_MEMBER_FUNCS_IMPLEMENT) 
        return chars;
    }
#endif // defined(CXSLTCGI_MEMBER_FUNCS_INTERFACE) 

#if !defined(CXSLTCGI_MEMBERS_ONLY)
};


#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#else // !defined(CXSLTCGI_MEMBERS_ONLY) 
#endif // !defined(CXSLTCGI_MEMBERS_ONLY) 

#endif // !defined(_CXSLTCGI_HPP) || defined(CXSLTCGI_MEMBERS_ONLY) 
