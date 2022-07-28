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
///   Date: 1/22/2015
///////////////////////////////////////////////////////////////////////
#ifndef _CORAL_APP_CGI_T_MAIN_HPP
#define _CORAL_APP_CGI_T_MAIN_HPP

#include "coral/inet/cgi/main.hpp"
#include "cplatform.hpp"
#include "cfile.hxx"
#include "ct.hxx"
#include "htmlmacro.h"

#define DEFAULT_FILENAMECGI_FILENAME_NAME_SUFFIX "_filename"
#define DEFAULT_FILENAMECGI_URI_NAME_SUFFIX "_uri"

#define DEFAULT_TEMPLATE_FILENAME_EXTENSION "t"
#define DEFAULT_TEMPLATE_FILENAME_NAME "t_filename"
#define DEFAULT_TEMPLATE_URI_NAME "t_uri"
#define DEFAULT_INPUT_NAME "input"
#define DEFAULT_CTCGI_NAME "tcgi"

#define DEFAULT_TEMPLATE_FILENAME \
    DEFAULT_CTCGI_NAME \
    PLATFORM_EXTENSION_SEPARATOR \
    DEFAULT_TEMPLATE_FILENAME_EXTENSION

#define CORAL_APP_CGI_T_PARAM_TEMPLATE_FILE_NAMES \
    DEFAULT_TEMPLATE_FILENAME_NAME, \
    "t_file", \
    "template_file", \
    "template_filename", \
    "input_file", \
    "input_filename", \

#define CORAL_APP_CGI_T_PARAM_TEMPLATE_URI_NAMES \
    DEFAULT_TEMPLATE_URI_NAME, \
    "t", \
    "template", \
    "template_uri", \
    DEFAULT_INPUT_NAME, \
    "input_uri", \

#define CORAL_APP_CGI_T_PARAM_NAME_CONTENT_TYPE "content_type"
#define CORAL_APP_CGI_T_PARAM_CONTENT_TYPE_NAMES \
    CORAL_APP_CGI_T_PARAM_NAME_CONTENT_TYPE, \
    CORAL_INET_HTTP_MESSAGE_HEADER_NAME_CONTENT_TYPE, \

namespace coral {
namespace app {
namespace cgi {

typedef char tChar;
typedef TLENGTH tLength;
typedef inet::http::form::field cHTTPFormField;
typedef inet::http::form::fields::iterator cHTTPFormFieldIterator;

typedef cFormattedWriter cCgiOutWriterExtends;
///////////////////////////////////////////////////////////////////////
///  Class: cCgiOutWriter
///////////////////////////////////////////////////////////////////////
class c_INTERFACE_CLASS cCgiOutWriter: public cCgiOutWriterExtends {
public:
    typedef cCgiOutWriterExtends cExtends;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    cCgiOutWriter(inet::cgi::main& cgi): m_cgi(cgi) {
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual tLength WriteFormattedV(const char_t* format, va_list va) {
        tLength length = m_cgi.outfv(format, va);
        return length;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    inet::cgi::main& m_cgi;
};

typedef cCharStream cContentStreamExtends;
///////////////////////////////////////////////////////////////////////
///  Class: cContentStream
///////////////////////////////////////////////////////////////////////
class c_EXPORT_CLASS cContentStream: public cContentStreamExtends {
public:
    typedef cContentStreamExtends cExtends;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    cContentStream(inet::cgi::main& cgi): m_cgi(cgi) {
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual TLENGTH Write(const char* chars, TLENGTH length=-1) {
        TLENGTH count = m_cgi.out(chars, length);
        return count;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    inet::cgi::main& m_cgi;
};

typedef ::cT cTExtends;
///////////////////////////////////////////////////////////////////////
///  Class: cT
///////////////////////////////////////////////////////////////////////
class c_INTERFACE_CLASS cT: public cTExtends {
public:
    typedef cTExtends cExtends;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    cT(inet::cgi::main& cgi)
    : m_cgi(cgi), m_formFieldIterator(cgi.form().begin()) {
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual const char* GetFirstParameter
    (int& length, const char*& named, int& namedLength) {
        const char* chars = 0;
        length = 0;
        if ((m_formFieldIterator = m_cgi.form().begin()) != (m_cgi.form().end())) {
            do {
                cHTTPFormField& f = *m_formFieldIterator;
                if ((named) && (0 < (namedLength))) {
                    if ((f.name().compare(named, namedLength))) {
                        continue;
                    }
                } else {
                    named = f.name().chars();
                    namedLength = f.name().length();
                }
                chars = f.value().chars();
                length = f.value().length();
                break;
            } while ((++m_formFieldIterator) != (m_cgi.form().end()));
        }
        return chars;
    }
    virtual const char* GetNextParameter
    (int& length, const char*& named, int& namedLength) {
        const char* chars = 0;
        length = 0;
        if ((m_formFieldIterator) != (m_cgi.form().end())) {
            if ((++m_formFieldIterator) != (m_cgi.form().end())) {
                do {
                    cHTTPFormField& f = *m_formFieldIterator;
                    if ((named) && (0 < (namedLength))) {
                        if ((f.name().compare(named, namedLength))) {
                            continue;
                        }
                    } else {
                        named = f.name().chars();
                        namedLength = f.name().length();
                    }
                    chars = f.value().chars();
                    length = f.value().length();
                    break;
                } while ((++m_formFieldIterator) != (m_cgi.form().end()));
            }
        }
        return chars;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    inet::cgi::main& m_cgi;
    cHTTPFormFieldIterator m_formFieldIterator;
};

namespace t {

typedef inet::cgi::main_implements main_implements;
typedef inet::cgi::main main_extends;
///////////////////////////////////////////////////////////////////////
///  Class: main
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS main: virtual public main_implements, public main_extends {
public:
    typedef main_implements Implements;
    typedef main_extends Extends;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    main()
     : m_cgiNameChars(DEFAULT_CTCGI_NAME),
       m_directorySeparatorChar(PLATFORM_DIRECTORY_SEPARATOR_CHAR),
       m_fileNameExtensionSeparatorChar(PLATFORM_EXTENSION_SEPARATOR_CHAR),
       m_templateFileNameExtensionChars(DEFAULT_TEMPLATE_FILENAME_EXTENSION),
       m_templateFileNameNameChars(DEFAULT_TEMPLATE_FILENAME_NAME),
       m_templateURINameChars(DEFAULT_TEMPLATE_URI_NAME),
       m_templateFileNameChars(DEFAULT_TEMPLATE_FILENAME),
       m_templateFileNameLength(chars_t::count(m_templateFileNameChars)),
       m_templateURIChars(0),
       m_templateURILength(0),
       m_inputNameChars(DEFAULT_INPUT_NAME),
       m_inputNameLength(chars_t::count(m_inputNameChars)),
       m_t(*this),
       m_cgiStream(*this),
       m_formFieldIterator(form().begin())
    {
    }
    virtual ~main() {
    }

protected:
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int run_cgi(int argc, char_t** argv, char_t** env) {
        int err = 0;
        TDEBUG_LEVEL old_db_levels = GET_DEBUG_LEVELS();
        cFormattedWriter* old_db = DB_GET_WRITER();
        cCgiOutWriter db(*this);
        const char* chars;
        tLength length;
        eError error;

        SET_DEBUG_LEVELS(DEBUG_LEVELS_ERROR);
        DB_SET_WRITER(&db);

        if ((chars = GetContentTypeHTML()))
            SetContentType(chars);

        if (!(m_templateFileNameChars = GetTemplateFileName(length))) {
            if (!(m_templateURIChars = GetTemplateURI(length))) {
                OutputContentL
                (H1_, m_cgiNameChars, _H1,
                 B_, "missing template source (\"", _B, m_templateFileNameNameChars, B_,
                 "\" or \"", _B, m_templateURINameChars, B_, "\")", _B, BR, NULL_POINTER);
                return 1;
            }
        }

        if ((chars = GetContentTypeText()))
            SetContentType(chars);

        if ((chars = GetContentTypeParameter(length))) {
            DBT("() setting content type to \"%s\"\n", chars);
            SetContentType(chars);
        }

        OutputContentType();

        if (!(error = m_t.Initialize())) {
            if ((m_templateFileNameChars)) {
                if ((error = m_templateFile.Open
                    (m_templateFileNameChars, FILE_MODE_READ))) {
                    OutputContentL
                    (H1_, m_cgiNameChars, _H1,
                     B_, "failed to open template file \"", _B,
                     m_templateFileNameChars, B_, "\"", _B, BR, NULL_POINTER);
                } else {
                    m_t.SetVariable
                    (m_inputNameChars,-1, m_templateFileNameChars,-1);

                    SetTVariablesFromForm(m_t);

                    if ((error = m_t.Expand(m_cgiStream, m_templateFile))) {
                        OutputContentL
                        (H1_, m_cgiNameChars, _H1,
                         B_, "failed to expand template file \"", _B,
                         m_templateFileNameChars, B_, "\"", _B, BR, NULL_POINTER);
                    }
                    m_templateFile.Close(true);
                }
            } else {
            }
            m_t.Finalize();
        } else {
        }

        DB_SET_WRITER(old_db);
        SET_DEBUG_LEVELS(old_db_levels);
        return err;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual tLength SetTVariablesFromForm(cTInterface& t) {
        tLength count = 0;
        cHTTPFormFieldIterator end;
        cHTTPFormFieldIterator i;

        if ((i = form().begin()) != (end = form().end())) {
            const tChar* name;
            const tChar* value;
            cTVariableInterface* v;

            do {
                cHTTPFormField& f = *i;

                if ((name = f.name().has_chars())
                     && (value = f.value().has_chars())) {

                    if ((v = t.SetVariable(name,-1, value,-1))) {
                        count++;
                    }
                }
            } while ((++i) != end);
        }
        return count;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual tLength OutputContentType() {
        return out_content_type();
    }
    virtual const char* SetContentType(const char* chars) {
        chars = set_content_type(chars);
        return chars;
    }
    virtual const char* GetContentType() const {
        return content_type();
    }
    virtual const char* GetContentTypeText() const {
        const char* chars = inet::http::content::type::name::of(inet::http::content::type::text);
        return chars;
    }
    virtual const char* GetContentTypeHTML() const {
        const char* chars = inet::http::content::type::name::of(inet::http::content::type::html);
        return chars;
    }
    virtual const char* GetContentTypeXML() const {
        const char* chars = inet::http::content::type::name::of(inet::http::content::type::xml);
        return chars;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual const tChar* GetTemplateFileName
    (tLength& length, bool onlyFromTemplateNames=false) const {
        const tChar* chars = 0;
        const tChar* chars2;

        if (!(chars = GetFormParameterValueHasChars(length, param_template_file_names()))) {
            if (!(onlyFromTemplateNames)) {
                if ((chars = GetEnvPathTranslatedChars())) {
                    DBT("() env PATH_TRANSLATED is \"%s\"\n", chars);
                }
            }
        }
        return chars;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual const tChar* GetTemplateURI
    (tLength& length, bool onlyFromTemplateNames=false) const {
        const tChar* chars = 0;
        const tChar* chars2;

        if (!(chars = GetFormParameterValueChars(length, param_template_uri_names()))) {
            if (!(onlyFromTemplateNames)) {
                if ((chars2 = GetEnvPathInfoChars())) {
                    DBT("() env PATH_INFO is \"%s\"\n", chars);
                }
            }
        }
        return chars;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual const tChar* GetContentTypeParameter(tLength& length) {
        const tChar* chars = GetFormParameterValueChars
        (length, param_content_type_names());
        return chars;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual const char* GetEnvPathTranslatedChars() const {
        inet::cgi::environment::variable::value&
        value = environment_[inet::cgi::environment::variable::PATH_TRANSLATED];
        const char* chars = value.has_chars();
         return chars;
    }
    virtual const char* GetEnvPathInfoChars() const {
        inet::cgi::environment::variable::value&
        value = environment_[inet::cgi::environment::variable::PATH_INFO];
        const char* chars = value.has_chars();
         return chars;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual const char* GetFormParameterValueHasChars
    (tLength& length, const char** names, bool isFromQueryString=false) const {
        const char* value = 0;
        inet::http::form::field* f;
        if ((f = form().find(names))) {
            value = (f->value().has_chars());
            length = (f->value().length());
        }
        return value;
    }
    virtual const char* GetFormParameterValueChars
    (tLength& length, const char** names, bool isFromQueryString=false) const {
        const char* value = 0;
        inet::http::form::field* f;
        if ((f = form().find(names))) {
            value = (f->value().chars());
            length = (f->value().length());
        }
        return value;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual const char_t** param_template_file_names() const {
        static const char_t* names[] = {
            CORAL_APP_CGI_T_PARAM_TEMPLATE_FILE_NAMES
            0
        };
        return names;
    }
    virtual const char_t** param_template_uri_names() const {
        static const char_t* names[] = {
            CORAL_APP_CGI_T_PARAM_TEMPLATE_URI_NAMES
            0
        };
        return names;
    }
    virtual const char_t** param_content_type_names() const {
        static const char_t* names[] = {
            CORAL_APP_CGI_T_PARAM_CONTENT_TYPE_NAMES
            0
        };
        return names;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual tLength OutputContentL(const tChar* chars, ...) {
        tLength length = 0;
        va_list va;

        va_start(va, chars);
        outlv(chars, va);
        va_end(va);
        return length;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    const char* m_cgiNameChars;

    char m_directorySeparatorChar;
    char m_fileNameExtensionSeparatorChar;

    const char* m_templateFileNameExtensionChars;
    const char* m_templateFileNameNameChars;
    const char* m_templateURINameChars;

    const char* m_templateFileNameChars;
    tLength m_templateFileNameLength;
    cCharString m_templateFileName;
    cCharString m_absoluteTemplateFileName;

    const char* m_templateURIChars;
    tLength m_templateURILength;
    cCharString m_templateURI;
    cCharString m_absoluteTemplateURI;

    const char* m_inputNameChars;
    tLength m_inputNameLength;
    cCharString m_inputName;

    cT m_t;
    cContentStream m_cgiStream;
    cCharFile m_templateFile;
    cHTTPFormFieldIterator m_formFieldIterator;
};

} // namespace t 
} // namespace cgi 
} // namespace app 
} // namespace coral 

#endif // _CORAL_APP_CGI_T_MAIN_HPP 
