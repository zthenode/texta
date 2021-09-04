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
 *   File: ctfilefunctions.cxx
 *
 * Author: $author$
 *   Date: 4/6/2008
 **********************************************************************
 */

#include "ctfunctions.hxx"

/**
 **********************************************************************
 *  Class: cFileDriveTFunction
 *
 * Author: $author$
 *   Date: 4/6/2008
 **********************************************************************
 */
class cFileDriveTFunction
: public cStringTFunction
{
public:
    typedef cStringTFunction cExtends;

    /**
     **********************************************************************
     * Constructor: cFileDriveTFunction
     *
     *      Author: $author$
     *        Date: 4/6/2008
     **********************************************************************
     */
    cFileDriveTFunction(const char* name, const char* description)
    : cExtends(name, description)
    {
        static cTFunctionParameter parameter[] 
        = {{"string,...",""},
           {0,0}};
        m_parameters = (sizeof(parameter)/sizeof(cTFunctionParameter))-1;
        m_parameter = parameter;
    }
    /**
     **********************************************************************
     * Function: Expand
     *
     *   Author: $author$
     *     Date: 4/6/2008
     **********************************************************************
     */
    virtual eError Expand
    (cCharStreamInterface &result, cTInterface &t, 
     const char* buffer, TLENGTH length) const
    {
        const char* part = 0;
        TLENGTH plength = 0;
        cCharSplitter splitter;

        if (length>0)
        {
            if (PLATFORM_VOLUME_SEPARATOR_CHAR)
            if ((part = splitter.RightOf
                (plength, PLATFORM_VOLUME_SEPARATOR_CHAR, buffer)))
                result.Write(buffer, length-plength-1);
        }
        return e_ERROR_NONE;
    }
} g_cFileDriveTFunction
  ("filedrive","filedrive(string,...)"),
  g_cFileVolumeTFunction
  ("filevolume","filevolume(string,...)");

/**
 **********************************************************************
 *  Class: cFilePathTFunction
 *
 * Author: $author$
 *   Date: 4/3/2008
 **********************************************************************
 */
class cFilePathTFunction
: public cStringTFunction
{
public:
    typedef cStringTFunction cExtends;

    /**
     **********************************************************************
     * Constructor: cFilePathTFunction
     *
     *      Author: $author$
     *        Date: 4/3/2008
     **********************************************************************
     */
    cFilePathTFunction(const char* name, const char* description)
    : cExtends(name, description)
    {
        static cTFunctionParameter parameter[] 
        = {{"string,...",""},
           {0,0}};
        m_parameter = parameter;
        m_parameters = sizeof(parameter)/sizeof(cTFunctionParameter)-1;
    }
    /**
     **********************************************************************
     * Function: Expand
     *
     *   Author: $author$
     *     Date: 4/3/2008
     **********************************************************************
     */
    virtual eError Expand
    (cCharStreamInterface &result, cTInterface &t, 
     const char* buffer, TLENGTH length) const
    {
        const char* part = 0;
        const char* part2 = 0;
        TLENGTH plength = 0;
        TLENGTH plength2 = 0;
        cCharSplitter splitter;

        if (length>0)
        {
            if (PLATFORM_DIRECTORY_SEPARATOR_CHAR)
                part = splitter.RightOf
                (plength, PLATFORM_DIRECTORY_SEPARATOR_CHAR, buffer);

            if (FOREIGN_DIRECTORY_SEPARATOR_CHAR)
            if ((part2 = splitter.RightOf
                (plength2, FOREIGN_DIRECTORY_SEPARATOR_CHAR, buffer)))
            if (!part || (part2 > part))
            {
                part = part2;
                plength = plength2;
            }

            if (part)
                result.Write(buffer, length-plength-1);
        }
        return e_ERROR_NONE;
    }
} g_cFilePathTFunction
  ("filepath","filepath(string,...)");

/**
 **********************************************************************
 *  Class: cFileNameTFunction
 *
 * Author: $author$
 *   Date: 4/6/2008
 **********************************************************************
 */
class cFileNameTFunction
: public cStringTFunction
{
public:
    typedef cStringTFunction cExtends;

    /**
     **********************************************************************
     * Constructor: cFileNameTFunction
     *
     *      Author: $author$
     *        Date: 4/6/2008
     **********************************************************************
     */
    cFileNameTFunction(const char* name, const char* description)
    : cExtends(name, description)
    {
        static cTFunctionParameter parameter[] 
        = {{"string,...",""},
           {0,0}};
        m_parameters = (sizeof(parameter)/sizeof(cTFunctionParameter))-1;
        m_parameter = parameter;
    }
    /**
     **********************************************************************
     * Function: Expand
     *
     *   Author: $author$
     *     Date: 4/6/2008
     **********************************************************************
     */
    virtual eError Expand
    (cCharStreamInterface &result, cTInterface &t, 
     const char* buffer, TLENGTH length) const
    {
        const char* part = 0;
        TLENGTH plength = 0;
        cCharSplitter splitter;

        if (length>0)
        {
            if (PLATFORM_DIRECTORY_SEPARATOR_CHAR)
            if (!(part = splitter.RightOf
                (plength, PLATFORM_DIRECTORY_SEPARATOR_CHAR, buffer)))
            if (FOREIGN_DIRECTORY_SEPARATOR_CHAR)
            if (!(part = splitter.RightOf
                (plength, FOREIGN_DIRECTORY_SEPARATOR_CHAR, buffer)))
            if (PLATFORM_VOLUME_SEPARATOR_CHAR)
                part = splitter.RightOf
                (plength, PLATFORM_VOLUME_SEPARATOR_CHAR, buffer);

            if (part) length = plength;
            else part = buffer;

            result.Write(part, length);
        }
        return e_ERROR_NONE;
    }
} g_cFileNameTFunction
  ("filename","filename(string,...)");

/**
 **********************************************************************
 *  Class: cFileBaseTFunction
 *
 * Author: $author$
 *   Date: 4/6/2008
 **********************************************************************
 */
class cFileBaseTFunction
: public cStringTFunction
{
public:
    typedef cStringTFunction cExtends;

    /**
     **********************************************************************
     * Constructor: cFileBaseTFunction
     *
     *      Author: $author$
     *        Date: 4/6/2008
     **********************************************************************
     */
    cFileBaseTFunction(const char* name, const char* description)
    : cExtends(name, description)
    {
        static cTFunctionParameter parameter[] 
        = {{"string,...",""},
           {0,0}};
        m_parameters = (sizeof(parameter)/sizeof(cTFunctionParameter))-1;
        m_parameter = parameter;
    }
    /**
     **********************************************************************
     * Function: Expand
     *
     *   Author: $author$
     *     Date: 4/6/2008
     **********************************************************************
     */
    virtual eError Expand
    (cCharStreamInterface &result, cTInterface &t, 
     const char* buffer, TLENGTH length) const
    {
        cCharSplitter splitter;
        const char* part;
        TLENGTH plength;

        if (length>0)
        {
            if (EXTENSION_SEPARATOR_CHAR)
            if ((part = splitter.RightOf
                (plength, EXTENSION_SEPARATOR_CHAR, buffer)))
                length -= (plength + 1);

            if (length > 0)
                result.Write(buffer, length);
        }
        return e_ERROR_NONE;
    }
} g_cFileBaseTFunction
  ("filebase","filebase(string,...)");

/**
 **********************************************************************
 *  Class: cFileExtensionTFunction
 *
 * Author: $author$
 *   Date: 4/6/2008
 **********************************************************************
 */
class cFileExtensionTFunction
: public cStringTFunction
{
public:
    typedef cStringTFunction cExtends;

    /**
     **********************************************************************
     * Constructor: cFileExtensionTFunction
     *
     *      Author: $author$
     *        Date: 4/6/2008
     **********************************************************************
     */
    cFileExtensionTFunction(const char* name, const char* description)
    : cExtends(name, description)
    {
        static cTFunctionParameter parameter[] 
        = {{"string,...","file path"},
           {0,0}};
        m_parameters = (sizeof(parameter)/sizeof(cTFunctionParameter))-1;
        m_parameter = parameter;
    }
    /**
     **********************************************************************
     * Function: Expand
     *
     *   Author: $author$
     *     Date: 4/6/2008
     **********************************************************************
     */
    virtual eError Expand
    (cCharStreamInterface &result, cTInterface &t, 
     const char* buffer, TLENGTH length) const
    {
        cCharSplitter splitter;
        const char* part;

        if (length>0)
        {
            if (EXTENSION_SEPARATOR_CHAR)
            if ((part = splitter.RightOf
                (length, EXTENSION_SEPARATOR_CHAR, buffer)))
            if (length > 0)
                result.Write(part, length);
        }
        return e_ERROR_NONE;
    }
} g_cFileExtensionTFunction
  ("fileextension","fileextension(string,...)");

/**
 **********************************************************************
 *  Class: cFileVolumeSeparatorTFunction
 *
 * Author: $author$
 *   Date: 9/5/2008
 **********************************************************************
 */
class cFileVolumeSeparatorTFunction
: public cTFunction
{
public:
    typedef cTFunction cExtends;

    /**
     **********************************************************************
     * Constructor: cFileVolumeSeparatorTFunction
     *
     *      Author: $author$
     *        Date: 9/5/2008
     **********************************************************************
     */
    cFileVolumeSeparatorTFunction(const char* name, const char* description)
    : cExtends(name, description)
    {
    }
    /**
     **********************************************************************
     * Function: Expand
     *
     *   Author: $author$
     *     Date: 9/5/2008
     **********************************************************************
     */
    virtual eError Expand
    (cCharStreamInterface &result, cTInterface &t, 
     const cTFunctionArgumentList& arglist) const
    {
        char separator;
        if ((separator = PLATFORM_VOLUME_SEPARATOR_CHAR))
            result.Write(&separator, 1);
        return e_ERROR_NONE;
    }
} g_cFileVolumeSeparatorTFunction
  ("filevolume-separator","filevolume-separator()");

/**
 **********************************************************************
 *  Class: cFilePathSeparatorTFunction
 *
 * Author: $author$
 *   Date: 9/5/2008
 **********************************************************************
 */
class cFilePathSeparatorTFunction
: public cTFunction
{
public:
    typedef cTFunction cExtends;
    /**
     **********************************************************************
     * Constructor: cFilePathSeparatorTFunction
     *
     *      Author: $author$
     *        Date: 9/5/2008
     **********************************************************************
     */
    cFilePathSeparatorTFunction(const char* name, const char* description)
    : cExtends(name, description)
    {
    }
    /**
     **********************************************************************
     * Function: Expand
     *
     *   Author: $author$
     *     Date: 9/5/2008
     **********************************************************************
     */
    virtual eError Expand
    (cCharStreamInterface &result, cTInterface &t, 
     const cTFunctionArgumentList& arglist) const
    {
        char separator;
        if ((separator = PLATFORM_DIRECTORY_SEPARATOR_CHAR))
            result.Write(&separator, 1);
        return e_ERROR_NONE;
    }
} g_cFilePathSeparatorTFunction
  ("filepath-separator","filepath-separator()");

/**
 **********************************************************************
 *  Class: cFileExtensionSeparatorTFunction
 *
 * Author: $author$
 *   Date: 9/5/2008
 **********************************************************************
 */
class cFileExtensionSeparatorTFunction
: public cTFunction
{
public:
    typedef cTFunction cExtends;

    /**
     **********************************************************************
     * Constructor: cFileExtensionSeparatorTFunction
     *
     *      Author: $author$
     *        Date: 9/5/2008
     **********************************************************************
     */
    cFileExtensionSeparatorTFunction(const char* name, const char* description)
    : cExtends(name, description)
    {
    }
    /**
     **********************************************************************
     * Function: Expand
     *
     *   Author: $author$
     *     Date: 9/5/2008
     **********************************************************************
     */
    virtual eError Expand
    (cCharStreamInterface &result, cTInterface &t, 
     const cTFunctionArgumentList& arglist) const
    {
        char separator;
        if ((separator = EXTENSION_SEPARATOR_CHAR))
            result.Write(&separator, 1);
        return e_ERROR_NONE;
    }
} g_cFileExtensionSeparatorTFunction
  ("fileextension-separator","fileextension-separator()");
