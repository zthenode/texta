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
 *   File: ccgi.hxx
 *
 * Author: $author$
 *   Date: 3/3/2008
 **********************************************************************
 */
#ifndef _CCGI_HXX
#define _CCGI_HXX

#include "cplatform_io.h"
#include "ccgiinterface.hxx"
#include "cargmain.hxx"
#include "ccgienv.hxx"
#include "chttpformfield.hxx"
#include "chttpurlencodedformfieldwriter.hxx"
#include "cnamevaluewriter.hxx"
#include "ccounter.hxx"
#include "ccomparer.hxx"
#include "cdigitizer.hxx"
#include "htmlmacro.h"

#define DEFAULT_CGI_NAME "cgi"
#define DEFAULT_CGI_ARGV_NAME "argv"
#define DEFAULT_CGI_ARGV_FILENAME "cgiargv.txt"
#define DEFAULT_CGI_ENV_FILENAME "cgienv.txt"
#define DEFAULT_CGI_STDIN_NAME "stdin"
#define DEFAULT_CGI_STDIN_FILENAME "cgistdin.txt"

#if defined(WIN32) 
#define DEFAULT_CGI_EXE_EXTENSION ".exe"
#else /* defined(WIN32) */
#define DEFAULT_CGI_EXE_EXTENSION ""
#endif /* defined(WIN32) */

#undef CDB_CLASS
#define CDB_CLASS "cCGIT"
/**
 **********************************************************************
 *  Class: cCGIT
 *
 * Author: $author$
 *   Date: 3/3/2008
 **********************************************************************
 */
template
<class TChar=CHAR,
 class TSize=TSIZE,
 class TLength=TLENGTH,
 TLength VUndefinedLength=UNDEFINED_LENGTH,
 class TNull=TChar,
 TNull VNull=NULL_CHAR,
 class THTTPFormFields=cHTTPFormFields,
 class TCGIEnv=cCGIEnv,
 class TImplements=cCGIInterface,
 class TExtends=cArgMain>
 
class cCGIT
: virtual public TImplements,
  public TExtends
{
public:
    typedef TImplements cImplements;
    typedef TExtends cExtends;
    typedef cCGIT cDerives;

    typedef TChar tChar;
    typedef TSize tSize;
    typedef TLength tLength;

    typedef cCounterT
    <TChar, TLength, 
     TNull, VNull> cCounter;

    typedef cComparerT
    <TChar, TLength, VUndefinedLength, 
     TNull, VNull> cComparer;

    typedef cDigitizerT
    <TChar, TLength, VUndefinedLength, 
     TNull, VNull> cDigitizer;

    const TChar* m_cgiNameChars;
    const TChar* m_argvNameChars;
    const TChar* m_argvFilenameChars;
    const TChar* m_envFilenameChars;
    const TChar* m_stdinNameChars;
    const TChar* m_stdinFilenameChars;

    eCGIRunMode m_runMode;

    eHTTPRequestMethod m_requestMethod;

    TLength m_contentLength;

    eHTTPContentType m_contentType;
    TLength m_contentTypeLength;
    const TChar* m_contentTypeChars;
    const TChar* m_outputContentTypeChars;

    TCGIEnv m_env;
    THTTPFormFields m_formFields;

    cCounter m_counter;
    cComparer m_comparer;
    cDigitizer m_digitizer;

    /**
     **********************************************************************
     * Constructor: cCGIT
     *
     *      Author: $author$
     *        Date: 3/3/2008
     **********************************************************************
     */
    cCGIT(const TChar* cgiNameChars=DEFAULT_CGI_ARGV_NAME) 
    : m_cgiNameChars(cgiNameChars),
      m_argvNameChars(DEFAULT_CGI_ARGV_NAME),
      m_argvFilenameChars(DEFAULT_CGI_ARGV_FILENAME),
      m_envFilenameChars(DEFAULT_CGI_ENV_FILENAME),
      m_stdinNameChars(DEFAULT_CGI_STDIN_NAME),
      m_stdinFilenameChars(DEFAULT_CGI_STDIN_FILENAME),
      m_runMode(e_CGI_RUN_MODE_NONE),
      m_requestMethod(e_HTTP_REQUEST_METHOD_NONE),
      m_contentLength(-1),
      m_contentType(e_HTTP_CONTENT_TYPE_NONE),
      m_contentTypeLength(0),
      m_contentTypeChars(0),
      m_outputContentTypeChars(0)
    {
        eError error;
        TLength length;
        int env;
        if (0 > (length = SetContentType()))
            throw(error = -length);
        if (0 > (env = InitCGIEnv()))
            throw(error = -env);
    }
    /**
     **********************************************************************
     * Destructor: cCGIT
     *
     *     Author: $author$
     *       Date: 3/3/2008
     **********************************************************************
     */
    virtual ~cCGIT()
    {
    }
    /**
     **********************************************************************
     * Function: Run
     *
     *   Author: $author$
     *     Date: 3/4/2008
     **********************************************************************
     */
    virtual int Run
    (int argc,
     const TChar** argv,
     const TChar** env) 
    {
        int err = 0;
        int count;
        const TChar* envValue;
        TLength length;
        eCGIRunMode runMode;

        CDBF("()...\n");

        if (0 > (count = GetCGIEnv()))
            return err = -count;

        if (e_CGI_RUN_MODE_CGI == (runMode = GetRunMode()))
            err = CGIRun(argc, argv, env);
        else
        if (e_CGI_RUN_MODE_COMMAND == (runMode))
            err = CommandRun(argc, argv, env);
        else
        if ((envValue = CGIEnv(length, e_CGI_ENV_GATEWAY_INTERFACE)))
            err = CGIRun(argc, argv, env);
        else 
        err = CommandRun(argc, argv, env);
        return err;
    }
    /**
     **********************************************************************
     * Function: CGIRun
     *
     *   Author: $author$
     *     Date: 3/4/2008
     **********************************************************************
     */
    virtual int CGIRun
    (int argc,
     const TChar** argv,
     const TChar** env) 
    {
        int err = 1;
        TUNSIGNED ulength;
        TLength length;
        const TChar* envValue;

        CDBF("()...\n");

        m_contentLength = -1;

        if ((envValue = CGIEnv
            (length, e_CGI_ENV_CONTENT_LENGTH))
            && (0 < length))
        if ((0 <= (ulength = m_digitizer.Unsigned
            (length, envValue, length)))
            && (0 < length))
            m_contentLength = (TLength)(ulength);
            err = RunCGI(argc, argv, env);
        return err;
    }
    /**
     **********************************************************************
     * Function: CommandRun
     *
     *   Author: $author$
     *     Date: 3/4/2008
     **********************************************************************
     */
    virtual int CommandRun
    (int argc,
     const TChar** argv,
     const TChar** env) 
    {
        int err =0;
        CDBF("()...\n");
        err = RunCommand(argc, argv, env);
        return err;
    }
    /**
     **********************************************************************
     * Function: RunCGI
     *
     *   Author: $author$
     *     Date: 3/4/2008
     **********************************************************************
     */
    virtual int RunCGI
    (int argc,
     const TChar** argv,
     const TChar** env) 
    {
        int err = 0;
        CDBF("()...\n");
        SetRunMode(e_CGI_RUN_MODE_CGI);
        err = RunCommandOrCGI(argc, argv, env);
        return err;
    }
    /**
     **********************************************************************
     * Function: RunCommand
     *
     *   Author: $author$
     *     Date: 3/4/2008
     **********************************************************************
     */
    virtual int RunCommand
    (int argc,
     const TChar** argv,
     const TChar** env) 
    {
        int err = 0;
        CDBF("()...\n");
        SetRunMode(e_CGI_RUN_MODE_COMMAND);
        err = RunCommandOrCGI(argc, argv, env);
        return err;
    }
    /**
     **********************************************************************
     * Function: RunCommandOrCGI
     *
     *   Author: $author$
     *     Date: 3/4/2008
     **********************************************************************
     */
    virtual int RunCommandOrCGI
    (int argc,
     const TChar** argv,
     const TChar** env) 
    {
        int err = 0;
        CDBF("()...\n");
        return err;
    }
    /**
     **********************************************************************
     * Function: OutputContentL
     *
     *   Author: $author$
     *     Date: 3/7/2008
     **********************************************************************
     */
    virtual TLength OutputContentL
    (const TChar* chars, ...) 
    {
        TLength length = 0;
        TLength count;
        va_list va;

        va_start(va, chars);

        if (0 <= (length = OutputContent(chars)))
        if (0 > (count = VOutputContent(va)))
            length = count;
        else length += count;
        va_end(va);
        return length;
    }
    /**
     **********************************************************************
     * Function: VOutputContent
     *
     *   Author: $author$
     *     Date: 3/7/2008
     **********************************************************************
     */
    virtual TLength VOutputContent
    (va_list va, TLength vlength=-1) 
    {
        TLength length = 0;
        TLength count;
        const TChar* chars;

        if (0 > vlength)
        {
            while (0 != (chars = va_arg(va, const TChar*)))
            {
                if (0 > (count = OutputContent(chars)))
                {
                    length = count;
                    break;
                }
                length += count;
            }
        }
        else 
        {
            while (0 < vlength--)
            {
                if (0 != (chars = va_arg(va, const TChar*)))
                if (0 > (count = OutputContent(chars)))
                    length = count;
                else
                {
                    length += count;
                    continue;
                }
                break;
            }
        }
        return length;
    }
    /**
     **********************************************************************
     * Function: OutputContent
     *
     *   Author: $author$
     *     Date: 3/6/2008
     **********************************************************************
     */
    virtual TLength OutputContent
    (const TChar* chars, TLength length=-1) 
    {
        TLength count = 0;
        TLength count2;

        if (!m_outputContentTypeChars)
        if (0 >= (count = OutputContentType()))
            return count;

        if (chars)
        if (0 > (count2 = Output(chars, length)))
            count = count2;
        else count += count2;
        return count;
    }
    /**
     **********************************************************************
     * Function: OutputContentType
     *
     *   Author: $author$
     *     Date: 3/6/2008
     **********************************************************************
     */
    virtual TLength OutputContentType
    (const TChar* chars=0, TLength length=-1) 
    {
        TLength count = 0;
        TLength count2;

        if (m_outputContentTypeChars)
            return 0;

        if (chars)
            SetContentType(chars, length);
        else
        if (!(chars = GetContentType()))
            SetContentType();

        if (m_contentTypeChars)
        if (m_contentTypeChars[0])
        if (0 < (count = Output(http_content_type_name)))
        {
            if (0 >= (count2 = Output(http_field_separator)))
                return count2;
            count += count2;
            if (0 >= (count = Output(m_contentTypeChars, m_contentTypeLength)))
                return count2;
            count += count2;
            if (0 >= (count = Output(http_newline)))
                return count2;
            count += count2;
            if (0 >= (count = Output(http_newline)))
                return count2;
            count += count2;
            m_outputContentTypeChars = m_contentTypeChars;
        }
        return count;
    }
    /**
     **********************************************************************
     * Function: Output
     *
     *   Author: $author$
     *     Date: 3/6/2008
     **********************************************************************
     */
    virtual TLength Output
    (const TChar* chars, TLength length=-1) 
    {
        TLength count = 0;
        if (0 > length)
            length = m_counter.LengthOf(chars);
        count = CTHIS Out(chars, length);
        return count;
    }
    /**
     **********************************************************************
     * Function: SetRunMode
     *
     *   Author: $author$
     *     Date: 3/5/2008
     **********************************************************************
     */
    virtual eCGIRunMode SetRunMode
    (eCGIRunMode runMode) 
    {
        m_runMode = runMode;
        return m_runMode;
    }
    /**
     **********************************************************************
     * Function: GetRunMode
     *
     *   Author: $author$
     *     Date: 3/5/2008
     **********************************************************************
     */
    virtual eCGIRunMode GetRunMode() const 
    {
        return m_runMode;
    }
    /**
     **********************************************************************
     * Function: GetCGIPathInfo
     *
     *   Author: $author$
     *     Date: 5/21/2008
     **********************************************************************
     */
    virtual const TChar* 
    GetCGIPathInfo(TLength& length) const 
    {
        eCGIEnv env = e_CGI_ENV_PATH_INFO;
        const TChar* chars = GetCGIEnvValue(length, env);
        return chars;
    }
    /**
     **********************************************************************
     * Function: GetCGIScriptName
     *
     *   Author: $author$
     *     Date: 5/22/2008
     **********************************************************************
     */
    virtual const TChar* 
    GetCGIScriptName(TLength& length) const 
    {
        eCGIEnv env = e_CGI_ENV_SCRIPT_NAME;
        const TChar* chars = GetCGIEnvValue(length, env);
        return chars;
    }
    /**
     **********************************************************************
     * Function: SetCGIEnvValue
     *
     *   Author: $author$
     *     Date: 3/19/2008
     **********************************************************************
     */
    virtual TLength SetCGIEnvValue
    (eCGIEnv env, const TChar* chars, TLength length=-1) 
    {
        TLength count = m_env.SetEnvValue(env, chars, length);
        return count;
    }
    /**
     **********************************************************************
     * Function: GetCGIEnvValue
     *
     *   Author: $author$
     *     Date: 5/21/2008
     **********************************************************************
     */
    virtual const TChar* GetCGIEnvValue
    (TLength& length, eCGIEnv env) const 
    {
        const TChar* chars = m_env.EnvValue(length, env);
        return chars;
    }
    /**
     **********************************************************************
     * Function: CGIEnvNamed
     *
     *   Author: $author$
     *     Date: 3/19/2008
     **********************************************************************
     */
    virtual eCGIEnv CGIEnvNamed
    (const TChar* name, TLength length=-1) const
    {
        eCGIEnv env = m_env.EnvNamed(name, length);
        return env;
    }
    /**
     **********************************************************************
     * Function: CGIEnvHasChars
     *
     *   Author: $author$
     *     Date: 3/24/2008
     **********************************************************************
     */
    virtual const TChar* CGIEnvHasChars
    (TLength& length, eCGIEnv env) const 
    {
        const TChar* chars;
        if ((chars = m_env.Env(length, env)))
        if (0 >= length)
            chars = 0;
        return chars;
    }
    /**
     **********************************************************************
     * Function: CGIEnv
     *
     *   Author: $author$
     *     Date: 3/7/2008
     **********************************************************************
     */
    virtual const TChar* CGIEnv
    (TLength& length, eCGIEnv env) const 
    {
        const TChar* chars = m_env.Env(length, env);
        return chars;
    }
    /**
     **********************************************************************
     * Function: CGIEnvValue
     *
     *   Author: $author$
     *     Date: 3/17/2008
     **********************************************************************
     */
    virtual const TChar* CGIEnvValue
    (TLength& length, eCGIEnv env) const 
    {
        const TChar* chars = m_env.EnvValue(length, env);
        return chars;
    }
    /**
     **********************************************************************
     * Function: CGIEnvName
     *
     *   Author: $author$
     *     Date: 3/7/2008
     **********************************************************************
     */
    virtual const TChar* CGIEnvName
    (TLength& length, eCGIEnv env) const 
    {
        const TChar* chars = m_env.EnvName(length, env);
        return chars;
    }
    /**
     **********************************************************************
     * Function: GetCGIEnv
     *
     *   Author: $author$
     *     Date: 3/4/2008
     **********************************************************************
     */
    virtual int GetCGIEnv()
    {
		int count = m_env.GetEnv();
        return count;
    }
    /**
     **********************************************************************
     * Function: InitCGIEnv
     *
     *   Author: $author$
     *     Date: 3/4/2008
     **********************************************************************
     */
    virtual int InitCGIEnv()
    {
        int env = m_env.InitEnv();
        return env;
    }
    /**
     **********************************************************************
     * Function: SetContentType
     *
     *   Author: $author$
     *     Date: 3/4/2008
     **********************************************************************
     */
    virtual TLength SetContentType
    (const TChar* contentTypeChars=0, TLength length=-1)
    {
        TLength count = 0;
        if (!contentTypeChars)
            contentTypeChars = http_content_type_text_name;
        m_contentTypeChars = contentTypeChars;
        if (0 <= length)
            count = (m_contentTypeLength = length);
        else 
        count = (m_contentTypeLength = m_counter.LengthOf(m_contentTypeChars));
        return count;
    }
    /**
     **********************************************************************
     * Function: GetContentType
     *
     *   Author: $author$
     *     Date: 3/17/2008
     **********************************************************************
     */
    virtual const TChar* GetContentType() const 
    {
        const TChar* chars = m_contentTypeChars;
        return chars;
    }
    /**
     **********************************************************************
     * Function: SetContentTypeText
     *
     *   Author: $author$
     *     Date: 3/17/2008
     **********************************************************************
     */
    virtual const TChar* SetContentTypeText() 
    {
        m_contentTypeChars = http_content_type_text_name;
        return m_contentTypeChars;
    }
    /**
     **********************************************************************
     * Function: GetContentTypeText
     *
     *   Author: $author$
     *     Date: 3/17/2008
     **********************************************************************
     */
    virtual const TChar* GetContentTypeText() const 
    {
        const TChar* chars = http_content_type_text_name;
        return chars;
    }
    /**
     **********************************************************************
     * Function: SetContentTypeHTML
     *
     *   Author: $author$
     *     Date: 3/17/2008
     **********************************************************************
     */
    virtual const TChar* SetContentTypeHTML() 
    {
        m_contentTypeChars = http_content_type_html_name;
        return m_contentTypeChars;
    }
    /**
     **********************************************************************
     * Function: GetContentTypeHTML
     *
     *   Author: $author$
     *     Date: 3/17/2008
     **********************************************************************
     */
    virtual const TChar* GetContentTypeHTML() const 
    {
        const TChar* chars = http_content_type_html_name;
        return chars;
    }
    /**
     **********************************************************************
     * Function: SetContentTypeXML
     *
     *   Author: $author$
     *     Date: 3/17/2008
     **********************************************************************
     */
    virtual const TChar* SetContentTypeXML() 
    {
        m_contentTypeChars = http_content_type_xml_name;
        return m_contentTypeChars;
    }
    /**
     **********************************************************************
     * Function: GetContentTypeXML
     *
     *   Author: $author$
     *     Date: 3/17/2008
     **********************************************************************
     */
    virtual const TChar* GetContentTypeXML() const 
    {
        const TChar* chars = http_content_type_xml_name;
        return chars;
    }
    /**
     **********************************************************************
     * Function: GetRequestMethodName
     *
     *   Author: $author$
     *     Date: 3/17/2008
     **********************************************************************
     */
    virtual const TChar* 
    GetRequestMethodName
    (TLength& length, eHTTPRequestMethod method) const
    {
        const TChar* chars = 0;
        length = 0;
        if ((method >= e_FIRST_HTTP_REQUEST_METHOD) 
            && (method <= e_LAST_HTTP_REQUEST_METHOD))
        if ((chars = http_request_method
             [method - e_FIRST_HTTP_REQUEST_METHOD]))
             length = m_counter.LengthOf(chars);
        return chars;
    }
    /**
     **********************************************************************
     * Function: GetContentLength
     *
     *   Author: $author$
     *     Date: 3/17/2008
     **********************************************************************
     */
    virtual TLength GetContentLength() const
    {
        return m_contentLength;
    }
};
#undef CDB_CLASS

/**
 **********************************************************************
 *  Typedef: cCGIExtends
 *
 *  Author: $author$
 *    Date: 3/22/2008
 **********************************************************************
 */
typedef cCGIT
<char, TSIZE, TLENGTH, -1, char, 0,
 cHTTPFormFields, cCGIEnv, cCGIInterface, cArgMain>
cCGIExtends;

class cCGI;

/**
 **********************************************************************
 *  Class: cCGIOutputContentWriter
 *
 * Author: $author$
 *   Date: 3/27/2008
 **********************************************************************
 */
class cCGIOutputContentWriter
: public cCharWriter
{
public:
    typedef cCharWriter cExtends;
    typedef cCGIOutputContentWriter cDerives;

    cCGI& m_cgi;

    /**
     **********************************************************************
     * Constructor: cCGIOutputContentWriter
     *
     *      Author: $author$
     *        Date: 3/27/2008
     **********************************************************************
     */
    cCGIOutputContentWriter(cCGI& cgi) 
    : m_cgi(cgi)
    {
    }
    /**
     **********************************************************************
     * Function: Write
     *
     *   Author: $author$
     *     Date: 3/27/2008
     **********************************************************************
     */
    virtual tLength Write
    (const tWhat* what, tLength length = -1);
};

/**
 **********************************************************************
 *  Class: cCGI
 *
 * Author: $author$
 *   Date: 3/22/2008
 **********************************************************************
 */
class cCGI
: public cCGIExtends
{
public:
    typedef cCGIExtends cExtends;
    typedef cCGI cDerives;

    typedef cCharFile tCharFile, tFile;
    typedef cCharString tCharString, tString;
    typedef cCharReaderInterface tCharReader, tReader;
    typedef cNameValueEventInterface tNameValueEventInterface;

    static cCGI* m_theCGI;
    cCGI* m_oldCGI;

    cCGIOutputContentWriter m_outputContentWriter;

    tString m_string;
    cNameValueWriter m_nameValueWriter;
    cHTTPURLEncodedFormFieldWriter m_urlEncodedFormFieldWriter;

    /**
     **********************************************************************
     * Constructor: cCGI
     *
     *      Author: $author$
     *        Date: 3/22/2008
     **********************************************************************
     */
    cCGI
    (const tChar* cgiNameChars=DEFAULT_CGI_NAME) 
    : cExtends(cgiNameChars),
      m_oldCGI(m_theCGI),
      m_outputContentWriter(*this)
    {
        m_theCGI = this;
    }
    /**
     **********************************************************************
     * Destructor: cCGI
     *
     *     Author: $author$
     *       Date: 3/22/2008
     **********************************************************************
     */
    virtual ~cCGI()
    {
        if (this == m_theCGI)
            m_theCGI = m_oldCGI;
    }

    /**
     **********************************************************************
     * Function: Main
     *
     *   Author: $author$
     *     Date: 3/2/2008
     **********************************************************************
     *
    virtual int Main
    (int argc,
     const char** argv,
     const char** env) 
    {
        int err = 0;
        DBF("() in...\n");
        err = cExtends::Main(argc, argv, env);
        DBF("()...out\n");
        return err;
    }*/

    /**
     **********************************************************************
     * Function: CGIRun
     *
     *   Author: $author$
     *     Date: 3/4/2008
     **********************************************************************
     */
    virtual int CGIRun
    (int argc,
     const char** argv,
     const char** env) 
    {
        int err = 1;
        eError error;
        TUNSIGNED ulength;
        tLength length;
        const tChar* chars;
        eCGIRunMode runMode;

        DBF("()...\n");

        m_contentLength = -1;

        if ((chars = CGIEnvHasChars
            (length, e_CGI_ENV_CONTENT_LENGTH)))

        if ((0 <= (ulength = m_digitizer.Unsigned
            (length, chars, length))) && (0 < length))
            m_contentLength = (tLength)(ulength);

        if (!(error = ReadURLEncodedFormFieldsFromQueryString()))

        if (!(error = ReadFormFieldsFromStdIn()))

        if (e_CGI_RUN_MODE_COMMAND == (runMode = GetRunMode()))
            err = RunCommand(argc, argv, env);
        else
        err = RunCGI(argc, argv, env);
        return err;
    }
    /**
     **********************************************************************
     * Function: CommandRun
     *
     *   Author: $author$
     *     Date: 3/2/2008
     **********************************************************************
     */
    virtual int CommandRun
    (int argc,
     const char** argv,
     const char** env) 
    {
        int err = 0;
        eError error;
        tLength length;
        const tChar* chars;
        cCharFile file;
        eCGIRunMode runMode;

        DBF("()...\n");

        if (!(error = ReadEnvFromFile(m_envFilenameChars)))
        if (!(error = ReadURLEncodedFormFieldsFromQueryString()))
        if ((chars = CGIEnvHasChars(length, e_CGI_ENV_REQUEST_METHOD)))
        {
            if (e_HTTP_REQUEST_METHOD_POST 
                == (m_requestMethod = HTTPRequestMethod(chars, length)))
            if ((chars = CGIEnvHasChars(length, e_CGI_ENV_CONTENT_TYPE)))
            if (e_HTTP_CONTENT_TYPE_URLENCODED_FORM_DATA
                == (m_contentType = HTTPContentType(chars, length)))
            if ((error = ReadURLEncodedFormFieldsFromFile(m_stdinFilenameChars)))
                return err;

            if (e_CGI_RUN_MODE_CGI == (runMode = GetRunMode()))
                err = RunCGI(argc, argv, env);
            else
            err = RunCommand(argc, argv, env);
        }
        return err;
    }
    /**
     **********************************************************************
     * Function: ReadFormFieldsFromStdIn
     *
     *   Author: $author$
     *     Date: 3/24/2008
     **********************************************************************
     */
    virtual eError ReadFormFieldsFromStdIn() 
    {
        eError error = e_ERROR_NONE;
        const tChar* chars;
        tLength length;

        if ((chars = CGIEnvHasChars(length, e_CGI_ENV_REQUEST_METHOD)))
        if (e_HTTP_REQUEST_METHOD_POST 
            == (m_requestMethod = HTTPRequestMethod(chars, length)))
        if ((chars = CGIEnvHasChars(length, e_CGI_ENV_CONTENT_TYPE)))
        {
#if defined(WIN32)
            FILE* file;
            int fileNo;
            int stdinNo;

            /* Set the stdin file mode to binary for WIN32.
             */
            if ((file = m_stdIn.GetAttached()))
            if (0 <= (fileNo = _fileno(file)))
            if (0 <= (stdinNo = _fileno(stdin)))
            if (fileNo == stdinNo)
            if (0 > _setmode(fileNo, _O_BINARY))
                return e_ERROR_FAILED;
#endif /* defined(WIN32) */

            if (e_HTTP_CONTENT_TYPE_URLENCODED_FORM_DATA
                == (m_contentType = HTTPContentType(chars, length)))
            {
                if ((error = ReadURLEncodedFormFields
                    (m_stdIn, m_contentLength)))
                    return error;
            }
            else
            if (e_HTTP_CONTENT_TYPE_MULTIPART_FORM_DATA
                == (m_contentType))
            {
                if ((error = ReadMultipartFormFields
                    (m_stdIn, m_contentLength)))
                    return error;
            }
        }
        return error;
    }
    /**
     **********************************************************************
     * Function: ReadEnvFromFile
     *
     *   Author: $author$
     *     Date: 3/22/2008
     **********************************************************************
     */
    virtual eError ReadEnvFromFile
    (const tChar* chars, tLength length=-1) 
    {
        eError error = e_ERROR_FAILED;
        tFile file;

        if (!(error = file.Open(chars, FILE_MODE_READ)))
        {
            error = ReadEnv(file);
            file.Close();
        }
        return error;
    }
    /**
     **********************************************************************
     * Function: ReadURLEncodedFormFieldsFromFile
     *
     *   Author: $author$
     *     Date: 3/22/2008
     **********************************************************************
     */
    virtual eError ReadURLEncodedFormFieldsFromFile
    (const tChar* chars, tLength length=-1) 
    {
        eError error = e_ERROR_FAILED;
        tFile file;

        if (!(error = file.Open(chars, FILE_MODE_READ)))
        {
            error = ReadURLEncodedFormFields(file);
            file.Close();
        }
        return error;
    }
    /**
     **********************************************************************
     * Function: ReadEnv
     *
     *   Author: $author$
     *     Date: 3/22/2008
     **********************************************************************
     */
    virtual eError ReadEnv
    (tReader& reader, tLength length=-1) 
    {
        eError error = e_ERROR_FAILED;
        if (!(error = m_nameValueWriter.Initialize()))
        {
            tNameValueEventInterface* oldDelegate = m_nameValueWriter.SetEventDelegate(&m_env);

            if (0 <= (length = m_nameValueWriter.Write(reader, length)))
                error = m_nameValueWriter.Finalize();

            m_nameValueWriter.SetEventDelegate(oldDelegate);
        }
        return error;
    }
    /**
     **********************************************************************
     * Function: ReadURLEncodedFormFieldsFromQueryString
     *
     *   Author: $author$
     *     Date: 3/24/2008
     **********************************************************************
     */
    virtual eError ReadURLEncodedFormFieldsFromQueryString() 
    {
        eError error = e_ERROR_NONE;
        const tChar* chars;
        tLength length;

        if ((chars = CGIEnvHasChars
            (length, e_CGI_ENV_QUERY_STRING)))
            error = ReadURLEncodedFormFields(chars, length);
        return error;
    }
    /**
     **********************************************************************
     * Function: ReadURLEncodedFormFields
     *
     *   Author: $author$
     *     Date: 3/24/2008
     **********************************************************************
     */
    virtual eError ReadURLEncodedFormFields
    (const tChar* chars, tLength length=-1) 
    {
        eError error = e_ERROR_FAILED;
        if (0 <= (length = m_string.Assign(chars, length)))
            error = ReadURLEncodedFormFields(m_string, length);
        return error;
    }
    /**
     **********************************************************************
     * Function: ReadMultipartFormFields
     *
     *   Author: $author$
     *     Date: 3/26/2008
     **********************************************************************
     */
    virtual eError ReadMultipartFormFields
    (tReader& reader, tLength length=-1) 
    {
        eError error = e_ERROR_NONE;
        return error;
    }
    /**
     **********************************************************************
     * Function: ReadURLEncodedFormFields
     *
     *   Author: $author$
     *     Date: 3/22/2008
     **********************************************************************
     */
    virtual eError ReadURLEncodedFormFields
    (tReader& reader, tLength length=-1) 
    {
        eError error = e_ERROR_FAILED;
        if (!(error = m_urlEncodedFormFieldWriter.Initialize()))
        {
            tNameValueEventInterface* oldDelegate = m_urlEncodedFormFieldWriter.SetEventDelegate(&m_formFields);

            if (0 <= (length = m_urlEncodedFormFieldWriter.Write(reader, length)))
                error = m_urlEncodedFormFieldWriter.Finalize();

            m_urlEncodedFormFieldWriter.SetEventDelegate(oldDelegate);
        }
        return error;
    }

    /**
     **********************************************************************
     * Function: GetHTTPFormFieldValue
     *
     *   Author: $author$
     *     Date: 5/22/2008
     **********************************************************************
     */
    virtual const tChar* 
    GetHTTPFormFieldValue
    (tLength& length, const tChar* name, 
     tLength nameLength=-1) const 
    {
        const tChar* chars = 0;
        cHTTPFormFieldReference f;
        if ((f = m_formFields.FindField(name, nameLength)))
            chars = f->GetValue(length);
        return chars;
    }

    /**
     **********************************************************************
     * Function: HTTPContentType
     *
     *   Author: $author$
     *     Date: 3/24/2008
     **********************************************************************
     */
    virtual eHTTPContentType HTTPContentType
    (const tChar* chars, tLength length=-1) const 
    {
        eHTTPContentType contentType;
        const char* contentTypeName;
        int unequal;

        for (contentType = e_FIRST_HTTP_CONTENT_TYPE;
             contentType <= e_LAST_HTTP_CONTENT_TYPE;
             contentType++)
        {
            if ((contentTypeName = http_content_type
                [contentType - e_FIRST_HTTP_CONTENT_TYPE]))
            if (!(unequal = m_comparer.Compare
                (contentTypeName, -1, chars, length)))
                return contentType;
        }
        return e_HTTP_CONTENT_TYPE_NONE;
    }
    /**
     **********************************************************************
     * Function: HTTPRequestMethod
     *
     *   Author: $author$
     *     Date: 3/22/2008
     **********************************************************************
     */
    virtual eHTTPRequestMethod HTTPRequestMethod
    (const tChar* chars, tLength length=-1) const
    {
        eHTTPRequestMethod requestMethod;
        const char* requestMethodName;
        int unequal;

        for (requestMethod = e_FIRST_HTTP_REQUEST_METHOD;
             requestMethod <= e_LAST_HTTP_REQUEST_METHOD;
             requestMethod++)
        {
            if ((requestMethodName = http_request_method
                [requestMethod - e_FIRST_HTTP_REQUEST_METHOD]))
            if (!(unequal = m_comparer.Compare
                (requestMethodName, -1, chars, length)))
                return requestMethod;
        }
        return e_HTTP_REQUEST_METHOD_NONE;
    }
};
#endif /* _CCGI_HXX */
