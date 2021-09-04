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
 *   File: ctcgi.hxx
 *
 * Author: $author$
 *   Date: 4/1/2008
 **********************************************************************
 */
#ifndef _CTCGI_HXX
#define _CTCGI_HXX

#include "ctemplatecgi.hxx"
#include "ccgistream.hxx"
#include "ccgi.hxx"
#include "ct.hxx"

#define DEFAULT_TEMPLATE_FILENAME_EXTENSION "t"
#define DEFAULT_TEMPLATE_FILENAME_NAME "t_filename"
#define DEFAULT_TEMPLATE_URI_NAME "t_uri"
#define DEFAULT_INPUT_NAME "input"

#define DEFAULT_CTCGI_NAME "tcgi"

/**
 **********************************************************************
 *  Class: cTCGIT
 *
 * Author: $author$
 *   Date: 1/12/2009
 **********************************************************************
 */
class cTCGIT
: public cT
{
public:
    typedef cT cExtends;
    typedef cTCGIT cDerives;

    cTParameterInterface& m_delegate;

    /**
     **********************************************************************
     * Constructor: cTCGIT
     *
     *      Author: $author$
     *        Date: 1/12/2009
     **********************************************************************
     */
    cTCGIT
    (cTParameterInterface& delegate,
     char mark=DEFAULT_T_MARK_CHAR) 
    : cExtends(mark),
      m_delegate(delegate)
    {
    }
    /**
     **********************************************************************
     * Function: GetFirstParameter
     *
     *   Author: $author$
     *     Date: 1/12/2009
     **********************************************************************
     */
    virtual const char* GetFirstParameter
    (int& length, const char*& named, int& namedLength) 
    {
        const char* chars = m_delegate.
        GetFirstParameter(length, named, namedLength);
        return chars;
    }
    /**
     **********************************************************************
     * Function: GetLastParameter
     *
     *   Author: $author$
     *     Date: 1/12/2009
     **********************************************************************
     */
    virtual const char* GetLastParameter
    (int& length, const char*& named, int& namedLength) 
    {
        const char* chars = m_delegate.
        GetLastParameter(length, named, namedLength);
        return chars;
    }
    /**
     **********************************************************************
     * Function: GetNextParameter
     *
     *   Author: $author$
     *     Date: 1/12/2009
     **********************************************************************
     */
    virtual const char* GetNextParameter
    (int& length, const char*& named, int& namedLength) 
    {
        const char* chars = m_delegate.
        GetNextParameter(length, named, namedLength);
        return chars;
    }
    /**
     **********************************************************************
     * Function: GetPrevParameter
     *
     *   Author: $author$
     *     Date: 1/12/2009
     **********************************************************************
     */
    virtual const char* GetPrevParameter
    (int& length, const char*& named, int& namedLength) 
    {
        const char* chars = m_delegate.
        GetPrevParameter(length, named, namedLength);
        return chars;
    }
};

/**
 **********************************************************************
 *  Class: cTCGI
 *
 * Author: $author$
 *   Date: 4/1/2008
 **********************************************************************
 */
class cTCGI
: virtual public cTParameterImplement,
  public cTemplateCGI
{
public:
    typedef cTemplateCGI cExtends;
    typedef cTCGI cDerives;

    const char* m_inputNameChars;

    cTCGIT m_t;

    cCGIStream m_cgiStream;
    cCharFile m_templateFile;

    cHTTPFormFieldIterator m_formFieldIterator;

    /**
     **********************************************************************
     * Constructor: cTCGI
     *
     *      Author: $author$
     *        Date: 4/1/2008
     **********************************************************************
     */
    cTCGI()
    : cExtends
      (DEFAULT_TEMPLATE_FILENAME_EXTENSION,
       DEFAULT_TEMPLATE_FILENAME_NAME,
       DEFAULT_TEMPLATE_URI_NAME,
       DEFAULT_CTCGI_NAME),

      m_inputNameChars(DEFAULT_INPUT_NAME),

      m_t((cTParameterInterface&)(*this)),

      m_cgiStream(*this)
    {
    }
    /**
     **********************************************************************
     * Destructor: cTCGI
     *
     *     Author: $author$
     *       Date: 4/1/2008
     **********************************************************************
     */
    virtual ~cTCGI()
    {
    }
    /**
     **********************************************************************
     * Function: RunCommandOrCGI
     *
     *   Author: $author$
     *     Date: 4/1/2008
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

        if (!(m_templateFileNameChars = GetTemplateFileName(length)))
        if (!(m_templateURIChars = GetTemplateURI(length)))
        {
            OutputContentL
            (H1_, m_cgiNameChars, _H1, 
             B_, "missing template source (\"", _B, m_templateFileNameNameChars, B_,
             "\" or \"", _B, m_templateURINameChars, B_, "\")", _B, BR, NULL_POINTER);
            return 1;
        }

        if ((chars = GetContentTypeText()))
            SetContentType(chars);

        if ((chars = GetContentTypeParameter(length)))
        {
            DBT("() setting content type to \"%s\"\n", chars);
            SetContentType(chars);
        }

        OutputContentType();

        if (!(error = m_t.Initialize()))
        {
            if (m_templateFileNameChars)
            if ((error = m_templateFile.Open
                (m_templateFileNameChars, FILE_MODE_READ)))
                OutputContentL
                (H1_, m_cgiNameChars, _H1, 
                 B_, "failed to open template file \"", _B, 
                 m_templateFileNameChars, B_, "\"", _B, BR, NULL_POINTER);
            else
            {
                m_t.SetVariable
                (m_inputNameChars,-1, 
                 m_templateFileNameChars,-1);

                SetTVariablesFromForm(m_t);

                try {
                    if ((error = m_t.Expand(m_cgiStream, m_templateFile))) {
                        OutputContentL
                        (H1_, m_cgiNameChars, _H1,
                         B_, "failed to expand template file \"", _B,
                         m_templateFileNameChars, B_, "\"", _B, BR, NULL_POINTER);
                    }
                } catch (const cTException& e) {
                    DBT("()...caught const cTException& e(%d)\n", e.Error());
                }

                m_templateFile.Close(true);
            }
            m_t.Finalize();
        }
        //err = RunDebug(argc, argv, env);
        return err;
    }
    /**
     **********************************************************************
     * Function: SetTVariablesFromForm
     *
     *   Author: $author$
     *     Date: 4/3/2008
     **********************************************************************
     */
    virtual tLength SetTVariablesFromForm(cTInterface& t) 
    {
        tLength count = 0;
        tLength  length;
        const tChar* name;
        const tChar* value;
        cHTTPFormFieldIterator end;
        cHTTPFormFieldIterator i;
        cHTTPFormFieldReference f;
        cTVariableInterface* v;

        if ((i = m_formFields.begin())
            != (end = m_formFields.end()))
        do
        {
            if ((f = (*i)))
            if ((name = f->GetName(length)) && (0 < length))
            if ((value = f->GetValue(length)))
            if ((v = t.SetVariable(name,-1, value,-1)))
                count++;
        }
        while ((++i) != end);
        return count;
    }
    /**
     **********************************************************************
     * Function: FindFirstFormField
     *
     *   Author: $author$
     *     Date: 1/11/2009
     **********************************************************************
     */
    virtual cHTTPFormFieldReference FindFirstFormField
    (cHTTPFormFieldIterator& i,
     const tChar* chars=0, tLength length=-1) 
    {
        cHTTPFormFieldIterator end = m_formFields.end();
        cHTTPFormFieldReference found, notFound;
        int unequal;

        if ((i = m_formFields.begin()) != end)
        do
        {
            if ((found = (*i)))
            if (!chars)
                return found;
            else
            if (!(unequal = found->CompareName(chars, length)))
                return found;
        }
        while ((++i) != end);
        return notFound;
    }
    /**
     **********************************************************************
     * Function: FindNextFormField
     *
     *   Author: $author$
     *     Date: 1/11/2009
     **********************************************************************
     */
    virtual cHTTPFormFieldReference FindNextFormField
    (cHTTPFormFieldIterator& i,
     const tChar* chars, tLength length=-1) 
    {
        cHTTPFormFieldIterator end = m_formFields.end();
        cHTTPFormFieldReference found, notFound;
        int unequal;

        if ((i) != (end))
        while ((++i) != end)
        {
            if ((found = (*i)))
            if (!chars)
                return found;
            else
            if (!(unequal = found->CompareName(chars, length)))
                return found;
        }
        return notFound;
    }

    /**
     **********************************************************************
     * Function: GetFirstParameter
     *
     *   Author: $author$
     *     Date: 1/12/2009
     **********************************************************************
     */
    virtual const char* GetFirstParameter
    (int& length, const char*& named, int& namedLength) 
    {
        const char* chars = 0;
        cHTTPFormFieldReference found;
        tLength tlength;

        if (!named)
            namedLength = 0;
        length = 0;

        if ((found = FindFirstFormField
            (m_formFieldIterator, named, namedLength)))
        {
            if (!named)
            if ((named = found->GetName(tlength)))
                namedLength = (int)(tlength);

            if ((chars = found->GetValue(tlength)))
                length = (int)(tlength);
        }
        return chars;
    }
    /**
     **********************************************************************
     * Function: GetNextParameter
     *
     *   Author: $author$
     *     Date: 1/12/2009
     **********************************************************************
     */
    virtual const char* GetNextParameter
    (int& length, const char*& named, int& namedLength) 
    {
        const char* chars = 0;
        cHTTPFormFieldReference found;
        tLength tlength;

        if (!named)
            namedLength = 0;
        length = 0;

        if ((found = FindNextFormField
            (m_formFieldIterator, named, namedLength)))
        {
            if (!named)
            if ((named = found->GetName(tlength)))
                namedLength = (int)(tlength);

            if ((chars = found->GetValue(tlength)))
                length = (int)(tlength);
        }
        return chars;
    }
};
#endif /* _CTCGI_HXX */
