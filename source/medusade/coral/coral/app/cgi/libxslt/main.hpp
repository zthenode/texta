///////////////////////////////////////////////////////////////////////
/// Copyright (c) 1988-2015 $organization$
///
/// This software is provided by the author and contributors ``as is'' 
/// and any express or implied warranties, including, but not limited to, 
/// the implied warranties of merchantability and fitness for a particular 
/// purpose are disclaimed. In no event shall the author or contributors 
/// be liable for any direct, indirect, incidental, special, exemplary, 
/// or consequential damages (including, but not limited to, procurement 
/// of substitute goods or services; loss of use, data, or profits; or 
/// business interruption) however caused and on any theory of liability, 
/// whether in contract, strict liability, or tort (including negligence 
/// or otherwise) arising in any way out of the use of this software, 
/// even if advised of the possibility of such damage.
///
///   File: main.hpp
///
/// Author: $author$
///   Date: 1/15/2015
///////////////////////////////////////////////////////////////////////
#ifndef _CORAL_APP_CGI_LIBXSLT_MAIN_HPP
#define _CORAL_APP_CGI_LIBXSLT_MAIN_HPP

#include "coral/inet/cgi/main.hpp"
#include "coral/app/cgi/xslt.hpp"

#include "cXsltProcessorInterface.hpp"
#include "cXmlAttributeEncoder.hpp"
#include "cFileSystemEntry.hpp"
#include "cFilePath.hpp"
#include "cStringReader.hpp"
#include "cStringWriter.hpp"
#include "cString.hpp"
#include "cCharStream.hpp"
#include "cTypes.hpp"

namespace coral {
namespace app {
namespace cgi {

typedef cStream cCgiOutStreamExtends;
///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
class c_INTERFACE_CLASS cCgiOutStream: public cCgiOutStreamExtends {
public:
    typedef cCgiOutStreamExtends cExtends;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    cCgiOutStream(inet::cgi::main& cgi): m_cgi(cgi) {}
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t Write(const char* what, ssize_t length = -1) {
        ssize_t count = m_cgi.out(what, length);
        return count;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    inet::cgi::main& m_cgi;
};

typedef cCharStream cCgiContentStreamExtends;
///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
class c_INTERFACE_CLASS cCgiContentStream: public cCgiContentStreamExtends {
public:
    typedef cCgiContentStreamExtends cExtends;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    cCgiContentStream(inet::cgi::main& cgi): m_cgi(cgi) {}
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t Write(const char* what, ssize_t length = -1) {
        ssize_t count = m_cgi.out(what, length);
        return count;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    inet::cgi::main& m_cgi;
};

namespace libxslt {

typedef inet::cgi::main_implements main_implements;
typedef inet::cgi::main main_extends;
///////////////////////////////////////////////////////////////////////
///  Class: main
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS main: virtual public main_implements, public main_extends {
friend class cCgiContentStream;
public:
    typedef main_implements Implements;
    typedef main_extends Extends;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    main()
    : m_cgiName(CORAL_APP_CGI_XSLT_NAME),

      m_xmlSourceReader(m_xmlSourceString),
      m_xmlSourceWriter(m_xmlSourceString),

      m_xsltSourcePath(CORAL_APP_CGI_XSLT_XSLT_PATH),
      m_xmlSourcePath(CORAL_APP_CGI_XSLT_XML_PATH),

      m_xsltSourceFileName(CORAL_APP_CGI_XSLT_XSLT_FILENAME),
      m_xmlSourceFileName(CORAL_APP_CGI_XSLT_XML_FILENAME),

      m_xsltFileExtension(CORAL_APP_CGI_XSLT_XSLT_FILEEXTENSION),
      m_xmlFileExtension(CORAL_APP_CGI_XSLT_XML_FILEEXTENSION),

      m_fileExtensionSeparator(CORAL_APP_CGI_XSLT_FILEEXTENSION_SEPARATOR) {
    }
    virtual ~main() {
    }

protected:
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int run_cgi(int argc, char_t** argv, char_t** env) {
        int err = 0;
        cStreamInterface* oldDebug = c_DEBUG_GET_OUT();
        cCgiOutStream debug(*this);
        const char* contentTypeChars;
        cXsltProcessorInterface* xslt;
        eError error;

        c_DEBUG_SET_OUT(&debug);

        if (!(contentTypeChars = GetContentTypeChars())) {
            contentTypeChars = inet::http::content::type::name::of(inet::http::content::type::html);
        }
        if ((contentTypeChars)) {
            set_content_type(contentTypeChars);
        }
        out_content_type();

        if ((xslt = cXsltProcessorInterface::GetInstance(error))) {
            if (!(error = xslt->Init())) {
                const char* xsltSourceFileNameChars
                = GetXsltSourceFileNameChars(m_workingXsltSourceFileName);

                const char* xmlSourceFileNameChars
                = GetXmlSourceFileNameChars
                  (m_workingXmlSourceFileName, xsltSourceFileNameChars);

                if ((error = SetXsltParams(*xslt))) {
                    c_DB_ERROR("() failed on SetXsltParams()");
                } else {
                    cCgiContentStream content(*this);

                    if ((xsltSourceFileNameChars)) {
                        if ((xmlSourceFileNameChars)) {
                            const char* absoluteFileNameChars;
                            ssize_t absoluteFileNameLength;

                            if ((absoluteFileNameChars = GetAbsoluteFileNameChars
                                (absoluteFileNameLength, m_absoluteXmlSourceFileName,
                                 xmlSourceFileNameChars, xsltSourceFileNameChars))) {
                                 xmlSourceFileNameChars = absoluteFileNameChars;
                            }
                            if ((error = xslt->ProcessFiles
                                (content, content, xsltSourceFileNameChars, xmlSourceFileNameChars))) {
                                c_DB_ERROR("() failed on xslt->ProcessFiles(..., \"" << xsltSourceFileNameChars << "\", \"" << xmlSourceFileNameChars << "\")");
                            }
                        } else {
                            m_xmlSourceReader.Reset();
                            if ((error = xslt->Process
                                (content, content, xsltSourceFileNameChars,
                                 m_xmlSourceReader, xsltSourceFileNameChars))) {
                                c_DB_ERROR("() failed on xslt->Process(..., \"" << xsltSourceFileNameChars << "\", m_xmlSourceReader, \"" << xmlSourceFileNameChars << "\")");
                            }
                        }
                    }
                }
                xslt->Finish();
            }
            cXsltProcessorInterface::FreeInstance(xslt);
        }
        c_DEBUG_SET_OUT(oldDebug);
        return err;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual eError SetXsltParams(cXsltProcessorInterface& xslt) {
        eError error = e_ERROR_NONE;
        if ((error = SetXsltParam
             (xslt, GetCgiNameXsltParameterName(), GetCgiName())))
            c_DB_ERROR("() failed on SetXsltParam()");
        else
            if ((error = SetXsltParamsFromCgiEnv(xslt)))
                c_DB_ERROR("() failed on SetXsltParamsFromCgiEnv()");
            else
        if ((error = SetXsltParamsFromHttpFormFields(xslt)))
            c_DB_ERROR("() failed on SetXsltParamsFromHttpFormFields()");
        return error;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual eError SetXsltParamsFromHttpFormFields(cXsltProcessorInterface& xslt) {
        eError error = e_ERROR_NONE;
        cString xmlAttrValue;
        cStringWriter xmlAttrWriter(xmlAttrValue);
        cXmlAttributeEncoder xmlAttrEncoder(xmlAttrWriter);
        cString name;
        const char* chars;

        for (inet::http::form::fields::const_iterator i = form_.begin(); i != form_.end(); ++i) {
            const inet::http::form::field& f = *i;

            if ((chars = f.value().chars()) && (0 <= (xmlAttrValue.Clear()))
                && (0 <= (xmlAttrEncoder.Write(chars)))) {

                if ((chars = f.name().has_chars()) && (0 < (name.Assign(chars)))) {

                    if ((error = xslt.SetLiteralParameter(name, xmlAttrValue))) {
                        c_DB_ERROR("() failed on xslt.SetLiteralParameter(\"" << name << "\",\"" << xmlAttrValue << "\")");
                        break;
                    }
                }
            }
        }
        return error;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual eError SetXsltParamsFromCgiEnv(cXsltProcessorInterface& xslt) {
        eError error = e_ERROR_NONE;
        const char* prefix = 0;
        cString name;
        cString xmlAttrValue;
        cStringWriter xmlAttrWriter(xmlAttrValue);
        cXmlAttributeEncoder xmlAttrEncoder(xmlAttrWriter);

        if ((prefix = GetCgiEnvXsltParameterNamePrefix())) {
            for (inet::cgi::environment::variable::which_t
                 which = inet::cgi::environment::variable::first;
                 which <= inet::cgi::environment::variable::last; ++which) {
                const char* envName = inet::cgi::environment::variable::name::of(which);

                if ((envName) && (envName[0])) {
                    const char* envValue = environment_[which].chars();

                    name.Assign(prefix); name.Append(envName);
                    if ((envValue) && (0 <= (xmlAttrValue.Clear()))
                        && (0 <= (xmlAttrEncoder.Write(envValue)))) {

                        if ((error = xslt.SetLiteralParameter(name, xmlAttrValue))) {
                            c_DB_ERROR("() failed on xslt.SetLiteralParameter(\"" << name << "\",\"" << xmlAttrValue << "\")");
                            break;
                        }
                    }
                }
            }
        }
        return error;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual eError SetXsltParam
    (cXsltProcessorInterface& xslt, const char* nameChars, const char* valueChars) {
        eError error = e_ERROR_NONE;
        cString name, value;
        cString xmlAttrValue;
        cStringWriter xmlAttrWriter(xmlAttrValue);
        cXmlAttributeEncoder xmlAttrEncoder(xmlAttrWriter);

        if ((nameChars) && (nameChars[0])) {
            name.Assign(nameChars);
            if ((valueChars) && (valueChars[0])) {
                value.Assign(valueChars);
            }
            if (0 <= (xmlAttrEncoder.Write(value.Chars()))) {
                if ((error = xslt.SetLiteralParameter(name, xmlAttrValue))) {
                    c_DB_ERROR("() failed on xslt.SetLiteralParameter(\"" << name << "\",\"" << xmlAttrValue << "\")");
                }
            }
        }
        return error;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual const char* GetXsltSourceFileNameChars
    (cString& fileName, const char* xmlSourceFileNameChars=0) {
        const char* xsltSourceFileNameChars = 0;
        const char* chars;
        if ((chars = GetXsltSourceFileNameChars(xmlSourceFileNameChars)))
        if (0 <= (fileName.Assign(chars)))
            xsltSourceFileNameChars = fileName.HasChars();
        return xsltSourceFileNameChars;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual const char* GetXmlSourceFileNameChars
    (cString& fileName, const char* xsltSourceFileNameChars=0) {
        const char* xmlSourceFileNameChars = 0;
        const char* chars;
        if ((chars = GetXmlSourceFileNameChars(xsltSourceFileNameChars)))
        if (0 <= (fileName.Assign(chars)))
            xmlSourceFileNameChars = fileName.HasChars();
        return xmlSourceFileNameChars;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual const char* GetXsltSourceFileNameChars
    (const char* xmlSourceFileNameChars=0) {
        const char* xsltSourceFileNameChars = 0;
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
        return xsltSourceFileNameChars;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual const char* GetXmlSourceFileNameChars
    (const char* xsltSourceFileNameChars=0) {
        const char* xmlSourceFileNameChars = 0;
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
        return xmlSourceFileNameChars;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual const char* GetXsltEnvPathTranslatedSourceFileNameChars() const {
        inet::cgi::environment::variable::value&
        value = environment_[inet::cgi::environment::variable::PATH_TRANSLATED];
        const char* chars = value.has_chars();
         return chars;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual const char* GetDerivedFileNameChars
    (ssize_t& length, cString& fileName,
     const char* fileExtensionChars, const char* baseFileNameChars) {
        const char* chars = 0;
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
        return chars;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual const char* GetAbsoluteFileNameChars
    (ssize_t& length, cString& fileName,
     const char* fileNameChars, const char* absoluteFileNameChars) {
        const char* chars = 0;
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
        return chars;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual const char* GetAbsoluteFileNamePathChars
    (ssize_t& length, char& separatorChar, const char* absoluteFileNameChars) {
        const char* chars = 0;
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
        return chars;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual const char* GetContentTypeChars() {
        const char* contentTypeChars = 0;
        const char** names;
        const char* name;
        if ((names = GetContentTypeParameterNames()))
        if ((name = GetFormParameterValueChars(names)))
            return name;
        return contentTypeChars;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual const char* GetFormParameterValueChars
    (const char** names, bool isFromQueryString=false) const {
        const char* value = 0;
        inet::http::form::field* f;
        if ((f = form().find(names))) {
            value = (f->value().chars());
        }
        return value;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual const char* GetCgiNameXsltParameterName() const {
        const char* chars = CORAL_APP_CGI_XSLT_CGI_NAME_XSLT_PARAMETER_NAME;
        return chars;
    }
    virtual const char* GetCgiName() const {
        const char* chars = m_cgiName.Chars();
        return chars;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual const char* GetCgiEnvXsltParameterNamePrefix() const {
        const char* chars = CORAL_APP_CGI_XSLT_CGI_ENV_XSLT_PARAMETER_NAME_PREFIX;
        return chars;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual const char** GetXsltFileParameterNames() const {
        const char** names = param_template_file_names();
        return names;
    }
    virtual const char** GetXmlFileParameterNames() const {
        const char** names = param_document_file_names();
        return names;
    }
    virtual const char** GetContentTypeParameterNames() const {
        const char** names = param_content_type_names();
        return names;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual const char_t** param_content_type_names() const {
        static const char_t* names[] = {
            CORAL_APP_CGI_XSLT_PARAM_CONTENT_TYPE_NAMES
            0
        };
        return names;
    }
    virtual const char_t** param_document_file_names() const {
        static const char_t* names[] = {
            CORAL_APP_CGI_XSLT_PARAM_DOCUMENT_FILE_NAMES
            0
        };
        return names;
    }
    virtual const char_t** param_template_file_names() const {
        static const char_t* names[] = {
            CORAL_APP_CGI_XSLT_PARAM_TEMPLATE_FILE_NAMES
            0
        };
        return names;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    cString m_cgiName;

    cString m_xmlSourceString;
    cStringReader m_xmlSourceReader;
    cStringWriter m_xmlSourceWriter;

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
};

} // namespace libxslt 
} // namespace cgi 
} // namespace app 
} // namespace coral 

#endif // _CORAL_APP_CGI_LIBXSLT_MAIN_HPP 
