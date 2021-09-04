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
 *   File: ctdatetfunctions.cxx
 *
 * Author: $author$
 *   Date: 12/26/2008
 **********************************************************************
 */

#include "cplatform_time.h"
#include "ctfunctions.hxx"
#include "cstring.hxx"

/**
 **********************************************************************
 *  Class: cDateTFunction
 *
 * Author: $author$
 *   Date: 12/26/2008
 **********************************************************************
 */
class cDateTFunction
: public cTFunction
{
public:
    typedef cTFunction cExtends;

    /**
     **********************************************************************
     * Constructor: cDateTFunction
     *
     *      Author: $author$
     *        Date: 12/26/2008
     **********************************************************************
     */
    cDateTFunction(const char* name, const char* description)
    : cExtends(name, description)
    {
        static cTFunctionParameter parameter[] 
        = {{"month",""},
           {"day",""},
           {"vear",""},
           {"(do)",""},
           {0,0}};
        m_parameters = (sizeof(parameter)/sizeof(cTFunctionParameter))-1;
        m_parameter = parameter;
    }
    /**
     **********************************************************************
     * Function: Expand
     *
     *   Author: $author$
     *     Date: 12/26/2008
     **********************************************************************
     */
    virtual eError Expand
    (cCharStreamInterface &result, cTInterface &t, 
     const cTFunctionArgumentList& arglist) const
    {
        cString string;
        const char* chars;
        TLENGTH count;
        time_t tt;
        struct tm *tm;

        time(&tt);
        tm=localtime(&tt);

        //itoa(tm->tm_mon+1,buff,10);

        if (0 < (count = string.AssignUnsigned(tm->tm_mon+1)))
        if ((chars = string.Chars(count)))
        if ((count = result.Write(chars, count)) >= 0)
        if ((count = result.Write("/", 1)) >= 0)
        {
            //itoa(tm->tm_mday,buff,10);

            if (0 < (count = string.AssignUnsigned(tm->tm_mday)))
            if ((chars = string.Chars(count)))
            if ((count = result.Write(chars, count)) >= 0)
            if ((count = result.Write("/", 1)) >= 0)
            {
                //itoa(tm->tm_year+1900,buff,10);

                if (0 < (count = string.AssignUnsigned(tm->tm_year+1900)))
                if ((chars = string.Chars(count)))
                    result.Write(chars, count);
            }
        }
        return e_ERROR_NONE;
    }
} g_cDateTFunction
  ("date","date([month,day,year,(do)])");

/**
 **********************************************************************
 *  Class: cMonthTFunction
 *
 * Author: $author$
 *   Date: 12/28/2008
 **********************************************************************
 */
class cMonthTFunction
: public cTFunction
{
public:
    typedef cTFunction cExtends;

    /**
     **********************************************************************
     * Constructor: cMonthTFunction
     *
     *      Author: $author$
     *        Date: 12/28/2008
     **********************************************************************
     */
    cMonthTFunction(const char* name, const char* description)
    : cExtends(name, description)
    {
        static cTFunctionParameter parameter[] 
        = {{"month",""},
           {"(do)",""},
           {0,0}};
        m_parameters = (sizeof(parameter)/sizeof(cTFunctionParameter))-1;
        m_parameter = parameter;
    }
    /**
     **********************************************************************
     * Function: Expand
     *
     *   Author: $author$
     *     Date: 12/28/2008
     **********************************************************************
     */
    virtual eError Expand
    (cCharStreamInterface &result, cTInterface &t, 
     const cTFunctionArgumentList& arglist) const
    {
        cString string;
        const char* chars;
        TLENGTH count;
        time_t tt;
        struct tm *tm;

        time(&tt);
        tm=localtime(&tt);

        //itoa(tm->tm_mon+1,buff,10);

        if (0 < (count = string.AssignUnsigned(tm->tm_mon+1)))
        if ((chars = string.Chars(count)))
            result.Write(chars, count);
        return e_ERROR_NONE;
    }
} g_cMonthTFunction
  ("month","month([month,(do)])");

/**
 **********************************************************************
 *  Class: cDayTFunction
 *
 * Author: $author$
 *   Date: 12/28/2008
 **********************************************************************
 */
class cDayTFunction
: public cTFunction
{
public:
    typedef cTFunction cExtends;

    /**
     **********************************************************************
     * Constructor: cDayTFunction
     *
     *      Author: $author$
     *        Date: 12/28/2008
     **********************************************************************
     */
    cDayTFunction(const char* name, const char* description)
    : cExtends(name, description)
    {
        static cTFunctionParameter parameter[] 
        = {{"day",""},
           {"(do)",""},
           {0,0}};
        m_parameters = (sizeof(parameter)/sizeof(cTFunctionParameter))-1;
        m_parameter = parameter;
    }
    /**
     **********************************************************************
     * Function: Expand
     *
     *   Author: $author$
     *     Date: 12/28/2008
     **********************************************************************
     */
    virtual eError Expand
    (cCharStreamInterface &result, cTInterface &t, 
     const cTFunctionArgumentList& arglist) const
    {
        cString string;
        const char* chars;
        TLENGTH count;
        time_t tt;
        struct tm *tm;

        time(&tt);
        tm=localtime(&tt);

        //itoa(tm->tm_mday,buff,10);

        if (0 < (count = string.AssignUnsigned(tm->tm_mday)))
        if ((chars = string.Chars(count)))
            result.Write(chars, count);
        return e_ERROR_NONE;
    }
} g_cDayTFunction
  ("day","day([day,(do)])");

/**
 **********************************************************************
 *  Class: cYearTFunction
 *
 * Author: $author$
 *   Date: 12/26/2008
 **********************************************************************
 */
class cYearTFunction
: public cTFunction
{
public:
    typedef cTFunction cExtends;

    /**
     **********************************************************************
     * Constructor: cYearTFunction
     *
     *      Author: $author$
     *        Date: 12/26/2008
     **********************************************************************
     */
    cYearTFunction(const char* name, const char* description)
    : cExtends(name, description)
    {
        static cTFunctionParameter parameter[] = {{0,0}};
        m_parameters = (sizeof(parameter)/sizeof(cTFunctionParameter))-1;
        m_parameter = parameter;
    }
    /**
     **********************************************************************
     * Function: Expand
     *
     *   Author: $author$
     *     Date: 12/26/2008
     **********************************************************************
     */
    virtual eError Expand
    (cCharStreamInterface &result, cTInterface &t, 
     const cTFunctionArgumentList& arglist) const
    {
        cString string;
        const char* chars;
        TLENGTH count;
        time_t tt;
        struct tm *tm;

        time(&tt);
        tm=localtime(&tt);

        //itoa(tm->tm_year+1900,buff,10);

        if (0 < (count = string.AssignUnsigned(tm->tm_year+1900)))
        if ((chars = string.Chars(count)))
            result.Write(chars, count);

        return e_ERROR_NONE;
    }
} g_cYearTFunction
  ("year","year([year,(do)])");
