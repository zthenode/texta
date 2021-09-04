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
//   File: cVcprojXsltCgi.hpp
//
// Author: $author$
//   Date: 8/19/2011
///////////////////////////////////////////////////////////////////////
#if !defined(_CVCPROJXSLTCGI_HPP) || defined(CVCPROJXSLTCGI_MEMBERS_ONLY)
#if !defined(_CVCPROJXSLTCGI_HPP) && !defined(CVCPROJXSLTCGI_MEMBERS_ONLY)
#define _CVCPROJXSLTCGI_HPP
#endif // !defined(_CVCPROJXSLTCGI_HPP) && !defined(CVCPROJXSLTCGI_MEMBERS_ONLY) 

#if !defined(CVCPROJXSLTCGI_MEMBERS_ONLY)

#if !defined(CXSLTCGI_NAME) 
#define CXSLTCGI_NAME "cVcprojXsltCgi"
#else // !defined(CXSLTCGI_NAME) 
#endif // !defined(CXSLTCGI_NAME) 

#include "cDerivedXsltCgi.hpp"

#define CVCPROJXSLTCGI_PROJECT_TARGET_PARAM_NAME "project_target"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

///////////////////////////////////////////////////////////////////////
// Typedef: cVcprojXsltCgiExtend
//
//  Author: $author$
//    Date: 8/20/2011
///////////////////////////////////////////////////////////////////////
typedef cXsltCgi
cVcprojXsltCgiExtend;
///////////////////////////////////////////////////////////////////////
//  Class: cVcprojXsltCgi
//
// Author: $author$
//   Date: 8/20/2011
///////////////////////////////////////////////////////////////////////
class c_EXPORT_CLASS cVcprojXsltCgi
: public cVcprojXsltCgiExtend
{
public:
    typedef cVcprojXsltCgiExtend cExtends;

    cString m_projectTargetParamName;

    ///////////////////////////////////////////////////////////////////////
    //  Constructor: cVcprojXsltCgi
    //
    //       Author: $author$
    //         Date: 8/29/2011
    ///////////////////////////////////////////////////////////////////////
    cVcprojXsltCgi()
    : m_projectTargetParamName(CVCPROJXSLTCGI_PROJECT_TARGET_PARAM_NAME)
    {
    }
    ///////////////////////////////////////////////////////////////////////
    //  Function: SetXsltParams
    //
    //    Author: $author$
    //      Date: 8/22/2011
    ///////////////////////////////////////////////////////////////////////
    virtual eError SetXsltParams
    (cXsltProcessorInterface& xslt)
    {
        eError error = e_ERROR_NONE;
        const char** names;
        const char* name;

        if ((names = GetXsltPathParameterNames()))
        if ((error = SetXsltParamNamesToLiteral
            (xslt, names, m_xsltSourcePath)))
        {
            c_DB_ERROR("() failed on SetXsltParamNamesToLiteral(..., \"" << m_xsltSourcePath << "\")");
            return error;
        }

        if ((name = GetEnvPathTranslatedChars()))
        {
            cFilePath filePath(name);
            const cString& fileBase = filePath.m_fileBase;
            if (!(filePath.SeparateParts()))
            {
                if ((error = SetXsltParamToLiteral
                    (xslt, m_projectTargetParamName, fileBase)))
                {
                    c_DB_ERROR("() failed on SetXsltParamToLiteral(..., \"" << m_projectTargetParamName << "\", \"" << fileBase << "\")");
                    return error;
                }
            }
            else
            c_DB_ERROR("() failed on filePath.SeparateParts()");
        }

        error = cExtends::SetXsltParams(xslt);
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    //  Function: GetXsltEnvPathTranslatedSourceFileNameChars
    //
    //    Author: $author$
    //      Date: 8/20/2011
    ///////////////////////////////////////////////////////////////////////
    virtual const char* GetXsltEnvPathTranslatedSourceFileNameChars() const
    {
        const char* chars = 0;
        return chars;
    }
    ///////////////////////////////////////////////////////////////////////
    //  Function: GetXmlEnvPathTranslatedSourceFileNameChars
    //
    //    Author: $author$
    //      Date: 8/20/2011
    ///////////////////////////////////////////////////////////////////////
    virtual const char* GetXmlEnvPathTranslatedSourceFileNameChars() const
    {
        const char* chars = 0;
        return chars;
    }
};

#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#else // !defined(CVCPROJXSLTCGI_MEMBERS_ONLY) 
#endif // !defined(CVCPROJXSLTCGI_MEMBERS_ONLY) 

#endif // !defined(_CVCPROJXSLTCGI_HPP) || defined(CVCPROJXSLTCGI_MEMBERS_ONLY) 
        

