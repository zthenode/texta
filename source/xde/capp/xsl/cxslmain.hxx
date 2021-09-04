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
 *   File: cxslmain.hxx
 *
 * Author: $author$
 *   Date: 3/14/2008
 **********************************************************************
 */
#ifndef _CXSLMAIN_HXX
#define _CXSLMAIN_HXX

#include "cargmain.hxx"
#include "cxsltransformerinterface.hxx"

#define DEFAULT_TITLE_PARAMETER "title"
#define DEFAULT_TITLE_VALUE "cXSLMain"

#define DEFAULT_XSL_FILENAME "xsl.xsl"
#define DEFAULT_XML_FILENAME "xsl.xml"

/**
 **********************************************************************
 *  Class: cXSLMain
 *
 * Author: $author$
 *   Date: 3/14/2008
 **********************************************************************
 */
class cXSLMain
: public cArgMain
{
public:
    typedef cArgMain cExtends;
    typedef cXSLMain cDerives;

    const char *m_titleParameter, *m_titleValue, *m_xslFilename, *m_xmlFilename;
    cXSLTransformerInterface* m_xslTransformer;

    /**
     **********************************************************************
     * Constructor: cXSLMain
     *
     *      Author: $author$
     *        Date: 3/14/2008
     **********************************************************************
     */
    cXSLMain() 
    : m_titleParameter(DEFAULT_TITLE_PARAMETER), m_titleValue(DEFAULT_TITLE_VALUE),
      m_xslFilename(DEFAULT_XSL_FILENAME), m_xmlFilename(DEFAULT_XML_FILENAME),
      m_xslTransformer(0)
    {
    }
    /**
     **********************************************************************
     * Function: Run
     *
     *   Author: $author$
     *     Date: 3/14/2008
     **********************************************************************
     */
    virtual int Run
    (int argc,
     const char** argv,
     const char** env) 
    {
        int err = 0;
        eError error = e_ERROR_NONE;

        if ((m_xslTransformer = cXSLTransformerInterface::CreateInstance(error)))
        {
            if (!(error = m_xslTransformer->Initialize()))
            {
                m_xslTransformer->SetLiteralParameter(m_titleParameter, m_titleValue);
                m_xslTransformer->TransformFile
                (m_stdErr, m_stdOut, m_xslFilename, m_xmlFilename);
                m_xslTransformer->Finalize();
            }
            cXSLTransformerInterface::DestroyInstance(m_xslTransformer);
        }
        return err;
    }
};
#endif /* _CXSLMAIN_HXX */
