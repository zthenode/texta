///////////////////////////////////////////////////////////////////////
// Copyright (c) 1988-2012 $organization$
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
//   File: cCgiCatch.hpp
//
// Author: $author$
//   Date: 11/20/2012
///////////////////////////////////////////////////////////////////////
#ifndef _CCGICATCH_HPP
#define _CCGICATCH_HPP

#include "cCgiMain.hpp"

#define CCGICATCH_DEFAULT_CGI_NAME "ccgicatch"

#define CCGICATCH_DEFAULT_STDARG_ARGVNAME "argv"
#define CCGICATCH_DEFAULT_STDENV_ENVNAME "env"
#define CCGICATCH_DEFAULT_STDIN_STDINNAME "stdin"
#define CCGICATCH_DEFAULT_STDOUT_STDOUTNAME "stdout"

#define CCGICATCH_DEFAULT_CONTENT_TYPENAME c_http_content_type_html_name

#define CCGICATCH_CONTENT_BUFFER_SIZE 2048

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

///////////////////////////////////////////////////////////////////////
//  Class: cCgiCatch
//
// Author: $author$
//   Date: 11/20/2012
//
// This cgi catches the cgi environment passed to it, and it reflects it
// back as a response as well as writing it to a set of text files which
// can be used as inputs to cgis running in console mode.
///////////////////////////////////////////////////////////////////////
class c_EXPORT_CLASS cCgiCatch
: virtual public cCgiMainImplement,
  public cCgiMain
{
public:
    typedef cCgiMainImplement cImplements;
    typedef cCgiMain cExtends;

    const char* m_stdArgArgvNameChars;
    const char* m_stdEnvEnvNameChars;
    const char* m_stdInStdInNameChars;
    const char* m_stdOutStdOutNameChars;

    size_t m_contentLength;
    char m_contentBuffer[CCGICATCH_CONTENT_BUFFER_SIZE];

    ///////////////////////////////////////////////////////////////////////
    //  Constructor: cCgiCatch
    //
    //       Author: $author$
    //         Date: 11/20/2012
    ///////////////////////////////////////////////////////////////////////
    cCgiCatch
    (const char* cgiNameChars = CCGICATCH_DEFAULT_CGI_NAME,
     const char* contentTypeChars = CCGICATCH_DEFAULT_CONTENT_TYPENAME,

     const char* stdArgArgvNameChars = CCGICATCH_DEFAULT_STDARG_ARGVNAME,
     const char* stdEnvEnvNameChars = CCGICATCH_DEFAULT_STDENV_ENVNAME,
     const char* stdInStdInNameChars = CCGICATCH_DEFAULT_STDIN_STDINNAME,
     const char* stdOutStdOutNameChars = CCGICATCH_DEFAULT_STDOUT_STDOUTNAME,

     const char* stdArgFileNameChars = CCGICATCH_DEFAULT_STDARG_FILENAME,
     const char* stdEnvFileNameChars = CCGICATCH_DEFAULT_STDENV_FILENAME,
     const char* stdInFileNameChars = CCGICATCH_DEFAULT_STDIN_FILENAME,
     const char* stdOutFileNameChars = CCGICATCH_DEFAULT_STDOUT_FILENAME)
    : cExtends
      (cgiNameChars, contentTypeChars, 
       stdArgFileNameChars, stdEnvFileNameChars,
       stdInFileNameChars, stdOutFileNameChars),

      m_stdArgArgvNameChars(stdArgArgvNameChars),
      m_stdEnvEnvNameChars(stdEnvEnvNameChars),
      m_stdInStdInNameChars(stdInStdInNameChars),
      m_stdOutStdOutNameChars(stdInStdInNameChars),

      m_contentLength(0)
    {
    }
    ///////////////////////////////////////////////////////////////////////
    //  Destructor: ~cCgiCatch
    //
    //      Author: $author$
    //        Date: 11/20/2012
    ///////////////////////////////////////////////////////////////////////
    virtual ~cCgiCatch()
    {
    }

    ///////////////////////////////////////////////////////////////////////
    //  Function: RunCgi
    //
    //    Author: $author$
    //      Date: 11/20/2012
    ///////////////////////////////////////////////////////////////////////
    virtual int RunCgi
    (int argc, char** argv, char** env)
    {
        char nullChar = 0;
        int err = 0;
        int arg;
        eCgiEnv e;
        int unequal;
        ssize_t length;
        const char* chars;
        const char* name;
        const char* value;
        cString string;

        // Output the cgi name.
        //
        OutputContentL(HTML_, BODY_, H1_, m_cgiNameChars, _H1, 0);

        // Output the standard argments passed to main.
        //
        OutputContentL
        (B_, "Arguments", " (file is ", _B,"\"",
         m_stdArgFileNameChars, "\"", B_, ")", _B, UL_, BR, 0);

        for (arg=0; arg<argc; arg++)
        {
            string.Assign(arg);
            chars = string.Chars();
            OutputContentL
            (B_, m_stdArgArgvNameChars, "[", chars?chars:&nullChar, "] = \"",
             _B, argv[arg], B_, "\"", _B, BR, 0);
        }
        OutputContentL(_UL, BR, 0);
        
        // Output the CGI environment variables passed to main.
        //
        OutputContentL
        (B_, "Environment", " (file is ", _B,"\"",
         m_stdEnvFileNameChars, "\"", B_, ")", _B, UL_, BR, 0);

        for (e=e_FIRST_CGI_ENV; e<=e_LAST_CGI_ENV; e++)
        {
            if (!(value = GetCgiEnvValue(e)))
                value = &nullChar;
                
            if ((name = GetCgiEnvName(e)))
            OutputContentL
            (B_, name, " = \"", _B, value, B_, "\"", _B, BR, 0);
        }
        OutputContentL(_UL, BR, 0);

        // Output the content (stdin) passed to main.
        //
        if ((value = GetCgiEnvValue(e_CGI_ENV_REQUEST_METHOD)))
        if ((name = GetRequestMethodName(e_HTTP_REQUEST_METHOD_POST)))
        if (!(unequal = cChars::Compare(name, value)))
        if ((value = GetCgiEnvValue(e_CGI_ENV_CONTENT_LENGTH)))
        if ((name = GetCgiEnvName(e_CGI_ENV_CONTENT_LENGTH)))
        if (0 <= (m_contentLength = (cChars::ToUInt(value))))
        {
            OutputContentL
            (B_, m_stdInStdInNameChars, " (file is \"",
             _B, m_stdInFileNameChars, B_, "\")", _B, BR, 0);
        }

        OutputContentL(_HTML, _BODY, 0);
        return err;
    }

    ///////////////////////////////////////////////////////////////////////
    //  Function: CgiRun
    //
    //    Author: $author$
    //      Date: 11/20/2012
    ///////////////////////////////////////////////////////////////////////
    virtual int CgiRun
    (int argc, char** argv, char** env)
    {
        char nullChar = 0;
        int err = 0;
        int arg;
        eCgiEnv e;
        int unequal;
        ssize_t length;
        const char* chars;
        const char* name;
        const char* value;
        cString string;
        cCharFile file;

        // Output the cgi name.
        //
        OutputContentL(HTML_, BODY_, H1_, m_cgiNameChars, _H1, 0);

        // Output the standard argments passed to main.
        //
        OutputContentL
        (B_, "Arguments", " (file is ", _B,"\"",
         m_stdArgFileNameChars, "\"", B_, ")", _B, UL_, BR, 0);

        for (arg=0; arg<argc; arg++)
        {
            string.Assign(arg);
            chars = string.Chars();
            OutputContentL
            (B_, m_stdArgArgvNameChars, "[", chars?chars:&nullChar, "] = \"",
             _B, argv[arg], B_, "\"", _B, BR, 0);
        }
        OutputContentL(_UL, BR, 0);
        
        // Write the standard argments passed to main to a file.
        //
        if ((SafeOpenFileToWrite(file, m_stdArgFileNameChars, m_stdArgArgvNameChars)))
        {
            for (arg=0; arg<argc; arg++)
            {
                file.WriteFormatted
                ("%s[%d]=%s\n", m_stdArgArgvNameChars, arg, argv[arg]);
            }
            file.Close();
        }
         
        // Output the CGI environment variables passed to main.
        //
        OutputContentL
        (B_, "Environment", " (file is ", _B,"\"",
         m_stdEnvFileNameChars, "\"", B_, ")", _B, UL_, BR, 0);

        for (e=e_FIRST_CGI_ENV; e<=e_LAST_CGI_ENV; e++)
        {
            if (!(value = GetCgiEnvValue(e)))
                value = &nullChar;
                
            if ((name = GetCgiEnvName(e)))
            OutputContentL
            (B_, name, " = \"", _B, value, B_, "\"", _B, BR, 0);
        }
        OutputContentL(_UL, BR, 0);

        // Write the CGI environment variables passed to main to a file.
        //
        if ((name = GetCgiEnvName(e_FIRST_CGI_ENV)))
        if ((SafeOpenFileToWrite(file, m_stdEnvFileNameChars, name)))
        {
            for (e=e_FIRST_CGI_ENV; e<=e_LAST_CGI_ENV; e++)
            {
                if ((name = GetCgiEnvName(e)))
                if ((value = GetCgiEnvValue(e)))
                    file.WriteFormatted("%s=%s\n", name, value);
            }
            file.Close();
        }

        // Output the content (stdin) passed to main.
        //
        if ((value = GetCgiEnvValue(e_CGI_ENV_REQUEST_METHOD)))
        if ((name = GetRequestMethodName(e_HTTP_REQUEST_METHOD_POST)))
        if (!(unequal = cChars::Compare(name, value)))
        if ((value = GetCgiEnvValue(e_CGI_ENV_CONTENT_LENGTH)))
        if ((name = GetCgiEnvName(e_CGI_ENV_CONTENT_LENGTH)))
        if (0 <= (m_contentLength = (cChars::ToUInt(value))))
        {
            OutputContentL
            (B_, m_stdInStdInNameChars, " (file is \"",
             _B, m_stdInFileNameChars, B_, "\")", _B, BR, 0);

            // Write the content (stdin) passed to main to a file.
            //
            if ((m_stdIn.SetBinaryMode()))
            if ((SafeOpenFileToWrite(file, m_stdInFileNameChars, name)))
            {
                file.WriteFormatted("%s=%s\n", name, value);
                if (0 < (m_contentLength))
                do
                {
                    length = sizeof(m_contentBuffer);

                    if (0 < m_contentLength)
                    if (m_contentLength < (size_t)(length))
                        length = m_contentLength;

                    if (0 >= (length = (m_stdIn.Read(m_contentBuffer, length))))
                        break;

                    if (0 >= (length = (file.Write(m_contentBuffer, length))))
                        break;

                    if (0 < m_contentLength)
                        m_contentLength -= length;
                }
                while (0 < m_contentLength);   
                file.Close();
            }
        }

        OutputContentL(_HTML, _BODY, 0);
        return err;
    }

    ///////////////////////////////////////////////////////////////////////
    //  Function: SafeOpenFileToWrite
    //
    //    Author: $author$
    //      Date: 11/21/2012
    ///////////////////////////////////////////////////////////////////////
    virtual bool SafeOpenFileToWrite
    (cCharFile& file,
     const char* fileName,
     const char* safePattern,
     const char* readMode="r",
     const char* writeMode="w")
    {
        bool isTrue = false;
        eError error;
        char c,p;
        const char* pattern;
        ssize_t size;
        
        if ((pattern = safePattern))
        if ((p = *(pattern++)))
        {
            if (!(error = file.Open(fileName, readMode)))
            {
                if (0 != (size = file.GetSize()))
                do
                {
                    if (0 < (file.Read(&c, 1)))
                    if (c == p)
                        continue;
                        
                    file.Close();
                    return false;
                }
                while ((p = *(pattern++)));
                file.Close();
            }            
            isTrue = !(error = file.Open(fileName, writeMode));
        }
        return isTrue;
    }
};

#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#endif // _CCGICATCH_HPP 
