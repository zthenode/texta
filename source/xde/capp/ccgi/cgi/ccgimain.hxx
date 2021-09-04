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
 *   File: ccgimain.hxx
 *
 * Author: $author$
 *   Date: 3/2/2008
 **********************************************************************
 */
#ifndef _CCGIMAIN_HXX
#define _CCGIMAIN_HXX

#include "ccgi.hxx"

/**
 **********************************************************************
 *  Class: cCGIMain
 *
 * Author: $author$
 *   Date: 3/2/2008
 **********************************************************************
 */
class cCGIMain
: public cCGI
{
public:
    typedef cCGI cExtends;
    typedef cCGIMain cDerives;
    /**
     **********************************************************************
     * Constructor: cCGIMain
     *
     *      Author: $author$
     *        Date: 3/2/2008
     **********************************************************************
     */
    cCGIMain() 
    {
    }
    /**
     **********************************************************************
     * Function: RunCommandOrCGI
     *
     *   Author: $author$
     *     Date: 3/2/2008
     **********************************************************************
     */
    virtual int RunCommandOrCGI
    (int argc,
     const char** argv,
     const char** env) 
    {
        int err = 0;
        int arg;
        eCGIEnv e;
        TLENGTH length;
        const char* name;
        const char* value;
        cHTTPFormFieldReference f;
        cHTTPFormFieldIterator i,end;
        char buffer[32];

        OutputContentType(GetContentTypeHTML());
        OutputContentL(H1_, m_cgiNameChars, _H1, NULL_POINTER);

        if ((i = m_formFields.begin()) 
            != (end = m_formFields.end()))
        {
            OutputContentL
            (B_, "Form fields", _B, UL_, BR, NULL_POINTER);

            do
            {
                if ((f = *i))
                if ((name = f->GetName(length)))
                if ((value = f->GetValue(length)))
                OutputContentL(B_, name, " = \"", _B, value, B_, "\"", _B, BR, NULL_POINTER);
            }
            while ((++i) != end);
        }
        OutputContentL(_UL, BR, NULL_POINTER);

        OutputContentL
        (B_, "Environment variables", _B, UL_, BR, NULL_POINTER);

        /* Get the CGI environment variables.
         */
        for (e=e_FIRST_CGI_ENV; e<=e_LAST_CGI_ENV; e++)
        {
            if ((name = CGIEnvName(length, e)))
            if ((value = CGIEnv(length, e)))
            OutputContentL(B_, name, " = \"", _B, value, B_, "\"", _B, BR, NULL_POINTER);
        }
        OutputContentL(_UL, BR, NULL_POINTER);

        OutputContentL
        (B_, "Arguments", _B, UL_, BR, NULL_POINTER);

        /* Get the standard argments passed to main.
         */
        for (arg=0; arg<argc; arg++)
        {
            sprintf(buffer, "%d", arg);
            OutputContentL
            (B_, m_argvNameChars, "[", buffer, "] = \"",
             _B, argv[arg], B_, "\"", _B, BR, NULL_POINTER);
        }
        OutputContentL(_UL, BR, NULL_POINTER);

        return err;
    }
};
#endif /* _CCGIMAIN_HXX */
