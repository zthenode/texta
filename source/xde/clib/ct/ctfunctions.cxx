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
 *   File: ctfunctions.cxx
 *
 * Author: $author$
 *   Date: 4/2/2008
 **********************************************************************
 */

#include "ctfunctions.hxx"
#include "cdigitizer.hxx"
#include "cdebug.hxx"

/**
 **********************************************************************
 *  Class: cParametersTFunction
 *
 * Author: $author$
 *   Date: 1/12/2009
 **********************************************************************
 */
class cParametersTFunction
: public cTFunction
{
public:
    typedef cTFunction cExtends;

    /**
     **********************************************************************
     * Constructor: cParametersTFunction
     *
     *      Author: $author$
     *        Date: 1/12/2009
     **********************************************************************
     */
    cParametersTFunction(const char* name, const char* description)
    : cExtends(name, description)
    {
        static cTFunctionParameter parameter[] 
        = {{"named",""},
           {"(before)",""},
           {"(between)",""},
           {"(after)",""},
           {"(expr)",""},
           {"name",""},
           {"value",""},
           {0,0}};
        m_parameters = (sizeof(parameter)/sizeof(cTFunctionParameter))-1;
        m_parameter = parameter;
    }
    /**
     **********************************************************************
     * Function: Expand
     *
     *   Author: $author$
     *     Date: 1/12/2009
     **********************************************************************
     */
    virtual eError Expand
    (cCharStreamInterface &result, cTInterface &t, 
     const cTFunctionArgumentList& arglist) const
    {
        cTVariableInterface *nameVariable=0, *valueVariable=0;
        cTFunctionArgument *before=0, *between=0, *after=0;
        cTFunctionArgument *expr=0, *nameVar=0, *valueVar=0;
        cTFunctionArgument *arg1;
        const char *named, *name, *value;
        int namedLength, nameLength, valueLength;
        const char* chars;
        TLENGTH length;

        DBT("() in...\n");

        //result.Write("parameters...");

        namedLength = 0;

        if (!(arg1 = arglist.GetFirstItem()))
            named = 0;
        else
        if ((named = arg1->GetBuffer(length)))
        if (1 > length)
            named = 0;
        else namedLength = length;

        name = named;
        nameLength = namedLength;

        if ((value = t.GetFirstParameter
            (valueLength, name, nameLength)))
        {
            //result.Write("parameter");
            if (arg1)
            if ((before = (arg1 = arg1->GetNextItem())))
            if ((between = (arg1 = arg1->GetNextItem())))
            if ((after = (arg1 = arg1->GetNextItem())))
            if ((expr = (arg1 = arg1->GetNextItem())))
            if ((nameVar = (arg1 = arg1->GetNextItem())))
            {
                if ((chars = nameVar->GetBuffer()))
                    nameVariable = t.GetVariable(chars);

                if ((valueVar = (arg1 = arg1->GetNextItem())))
                {
                    if ((chars = valueVar->GetBuffer()))
                        valueVariable = t.GetVariable(chars);
                }
            }

            do
            {
                if (nameVariable)
                    nameVariable->PushValue
                    (name, nameLength);

                if (valueVariable)
                    valueVariable->PushValue
                    (value, valueLength);

                if (before)
                if (0 < (length = before->GetLength()))
                if (0 <= (length = before->Seek(0)))
                    t.Expand(result, *before);

                if (!expr)
                    result.Write
                    (value, valueLength);
                else
                if (0 < (length = expr->GetLength()))
                if (0 <= (length = expr->Seek(0)))
                    t.Expand(result, *expr);

                name = named;
                nameLength = namedLength;

                if ((value = t.GetNextParameter
                   (valueLength, name, nameLength)))
                if (between)
                if (0 < (length = between->GetLength()))
                if (0 <= (length = between->Seek(0)))
                    t.Expand(result, *between);

                if (after)
                if (0 < (length = after->GetLength()))
                if (0 <= (length = after->Seek(0)))
                    t.Expand(result, *after);

                if (valueVariable)
                    valueVariable->PopValue();

                if (nameVariable)
                    nameVariable->PopValue();
            }
            while ((value));
        }

        DBT("() ...out\n");
        return e_ERROR_NONE;
    }
} g_cParametersTFunction
  ("parameters",
   "parameters(named,(before),(between),(after),(expr),name,value)");

/**
 **********************************************************************
 *  Class: cFunctionsTFunction
 *
 * Author: $author$
 *   Date: 4/3/2008
 **********************************************************************
 */
class cFunctionsTFunction
: public cTFunction
{
public:
    typedef cTFunction cExtends;

    /**
     **********************************************************************
     * Constructor: cFunctionsTFunction
     *
     *      Author: $author$
     *        Date: 4/3/2008
     **********************************************************************
     */
    cFunctionsTFunction(const char* name, const char* description)
    : cExtends(name, description)
    {
        static cTFunctionParameter parameter[] 
        = {{"(before)","do before each function"},
           {"(between)","do between each function"},
           {"(do)","do for each function"},
           {"name","variable name for function name"},
           {"desc","variable name for function description"},
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
     const cTFunctionArgumentList& arglist) const
    {
        const char *name = 0;
        const char *desc = 0;
        const char *name_var = 0;
        const char *desc_var = 0;
        cTVariableInterface *name_variable = 0;
        cTVariableInterface *desc_variable = 0;
        cTFunctionArgument *before = 0;
        cTFunctionArgument *between = 0;
        cTFunctionArgument *expr = 0;
        cTFunctionArgument *arg;
        cTFunctionInterface* function;
        const cTFunctionParameter* parameter;
        int parameters;

        if ((before = (arg = arglist.GetFirstItem())))
        if ((between = (arg = arg->GetNextItem())))
        if ((expr = (arg = arg->GetNextItem())))
        if ((arg = arg->GetNextItem()))
        {
            if ((name_var = arg->GetBuffer()))
                name_variable = t.GetVariable(name_var);

            if ((arg = arg->GetNextItem()))
            {
                if ((desc_var = arg->GetBuffer()))
                    desc_variable = t.GetVariable(desc_var);
            }
        }

        if ((function = t.GetFirstFunction()))
        do
        {
            name = function->GetName();
            desc = function->GetDescription(parameter, parameters);

            if (name_variable && name)
                name_variable->PushValue(name);

            if (desc_variable && desc)
                desc_variable->PushValue(desc);

            if (before)
            {
                t.Expand(result,*before);
                before->Seek(0);
            }

            if (expr)
            {
                t.Expand(result,*expr);
                expr->Seek(0);
            }
            else
            {
                if (name)
                    result.Write(name);

                if (desc)
                    result.WriteL(":", desc, NULL_POINTER);
            }

            if ((function = t.GetNextFunction()))
            if (between)
            {
                t.Expand(result,*between);
                between->Seek(0);
            }
            else if (!expr)
                    result.Write(";");

            if (desc_variable && desc)
                desc_variable->PopValue();

            if (name_variable && name)
                name_variable->PopValue();
        }
        while(function);

        return e_ERROR_NONE;
    }
} g_cFunctionsTFunction
  ("functions","functions((before), (between), (do), name, desc)");

/**
 **********************************************************************
 *  Class: cFunctionParametersTFunction
 *
 * Author: $author$
 *   Date: 4/3/2008
 **********************************************************************
 */
class cFunctionParametersTFunction
: public cTFunction
{
public:
    typedef cTFunction cExtends;

    /**
     **********************************************************************
     * Constructor: cFunctionParametersTFunction
     *
     *      Author: $author$
     *        Date: 4/3/2008
     **********************************************************************
     */
    cFunctionParametersTFunction(const char* name, const char* description)
    : cExtends(name, description)
    {
        static cTFunctionParameter parameter[] 
        = {{"function","function name"},
           {"(before)","do before each"},
           {"(between)","do between each"},
           {"(do)","do for each"},
           {"name","parameter name variable"},
           {"desc","parameter description variable"},
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
     const cTFunctionArgumentList& arglist) const
    {
        const char *name = 0;
        const char *desc = 0;
        const char *name_var = 0;
        const char *desc_var = 0;
        cTVariableInterface *name_variable = 0;
        cTVariableInterface *desc_variable = 0;
        cTFunctionArgument *fname = 0;
        cTFunctionArgument *before = 0;
        cTFunctionArgument *between = 0;
        cTFunctionArgument *expr = 0;
        cTFunctionArgument *arg;
        cTFunctionInterface* function;
        const cTFunctionParameter* parameter;
        int parameters;

        if ((fname = (arg = arglist.GetFirstItem())))
        if ((before = (arg = arg->GetNextItem())))
        if ((between = (arg = arg->GetNextItem())))
        if ((expr = (arg = arg->GetNextItem())))
        if ((arg = arg->GetNextItem()))
        {
            if ((name_var = arg->GetBuffer()))
                name_variable = t.GetVariable(name_var);

            if ((arg = arg->GetNextItem()))
            {
                if ((desc_var = arg->GetBuffer()))
                    desc_variable = t.GetVariable(desc_var);
            }
        }

        if (fname)
        if ((name = fname->GetBuffer()))
        if ((function = t.FindFunction(name)))
        if ((desc = function->GetDescription(parameter, parameters)))
        if (parameter && parameters)
        do
        {
            name = parameter->GetName();
            desc = parameter->GetDescription();

            if (name_variable && name)
                name_variable->PushValue(name);

            if (desc_variable && desc)
                desc_variable->PushValue(desc);

            if (before)
            {
                t.Expand(result,*before);
                before->Seek(0);
            }

            if (expr)
            {
                t.Expand(result,*expr);
                expr->Seek(0);
            }
            else
            {
                if (name)
                    result.Write(name);

                if (desc)
                    result.WriteL(":", desc, NULL_POINTER);
            }

            if ((function = t.GetNextFunction()))
            if (between)
            {
                t.Expand(result,*between);
                between->Seek(0);
            }
            else if (!expr)
                    result.Write(";");

            if (desc_variable && desc)
                desc_variable->PopValue();

            if (name_variable && name)
                name_variable->PopValue();

            parameter++;
        }
        while(--parameters);

        return e_ERROR_NONE;
    }
} g_cFunctionParametersTFunction
  ("function-parameters",
   "function-parameters(function, (before), (between), (do), name, desc)");

/**
 **********************************************************************
 *  Class: cImportTFunction
 *
 * Author: $author$
 *   Date: 4/2/2008
 **********************************************************************
 */
class cImportTFunction
: public cTFunction
{
public:
    typedef cTFunction cExtends;

    /**
     **********************************************************************
     * Constructor: cImportTFunction
     *
     *      Author: $author$
     *        Date: 4/2/2008
     **********************************************************************
     */
    cImportTFunction(const char* name, const char* description)
    : cExtends(name, description)
    {
        static cTFunctionParameter parameter[] 
        = {{"location,...","filename or uri to include literally"}, 
           {0,0}};

        m_parameter = parameter;
        m_parameters = sizeof(parameter)/sizeof(cTFunctionParameter)-1;
    }
    /**
     **********************************************************************
     * Function: Expand
     *
     *   Author: $author$
     *     Date: 4/2/2008
     **********************************************************************
     */
    virtual eError Expand
    (cCharStreamInterface &result, cTInterface &t, 
     const cTFunctionArgumentList& arglist) const
    {
        eError error;
        TLENGTH pathlen;
        const char *path;
        cTFunctionArgument *expr;
        cCharFile file;

        for (expr = arglist.GetFirstItem(); 
             expr; expr = expr->GetNextItem())
        {
            if ((path = expr->GetBuffer(pathlen)))
            if (0 < pathlen)
            if (!(error = file.Open(path, FILE_MODE_READ)))
            {
                result.WriteReader(file);
                file.Close();
            }
        }
        return e_ERROR_NONE;
    }
} g_cImportTFunction
  ("import","import(location,...)");

/**
 **********************************************************************
 *  Class: cIncludeTFunction
 *
 * Author: $author$
 *   Date: 4/3/2008
 **********************************************************************
 */
class cIncludeTFunction
: public cTFunction
{
public:
    typedef cTFunction cExtends;

    /**
     **********************************************************************
     * Constructor: cIncludeTFunction
     *
     *      Author: $author$
     *        Date: 4/3/2008
     **********************************************************************
     */
    cIncludeTFunction(const char* name, const char* description)
    : cExtends(name, description)
    {
        static cTFunctionParameter parameter[] 
        = {{"location,...","filename or uri to include expansion"}, 
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
     const cTFunctionArgumentList& arglist) const
    {
        eError error;
        TLENGTH pathlen;
        const char*path;
        cTFunctionArgument* expr;
        cCharFile file;

        for (expr = arglist.GetFirstItem(); 
             expr; expr = expr->GetNextItem())
        {
            if ((path = expr->GetBuffer(pathlen)))
            if (0 < pathlen)
            if (!(error = file.Open(path, FILE_MODE_READ)))
            {
                t.Expand(result,file);
                file.Close();
            }
        }
        return e_ERROR_NONE;
    }
} g_cIncludeTFunction
  ("include","include(location,...)");

/**
 **********************************************************************
 *  Class: cDoTFunction
 *
 * Author: $author$
 *   Date: 4/2/2008
 **********************************************************************
 */
class cDoTFunction
: public cTFunction
{
public:
    typedef cTFunction cExtends;

    /**
     **********************************************************************
     * Constructor: cDoTFunction
     *
     *      Author: $author$
     *        Date: 4/2/2008
     **********************************************************************
     */
    cDoTFunction(const char* name, const char* description)
    : cExtends(name, description)
    {
        static cTFunctionParameter parameter[] 
        = {{"(do),...","expansions to do"}, 
           {0,0}};

        m_parameter = parameter;
        m_parameters = sizeof(parameter)/sizeof(cTFunctionParameter)-1;
    }
    /**
     **********************************************************************
     * Function: Expand
     *
     *   Author: $author$
     *     Date: 4/2/2008
     **********************************************************************
     */
    virtual eError Expand
    (cCharStreamInterface &result, cTInterface &t, 
     const cTFunctionArgumentList& arglist) const
    {
        eError error;
        cTFunctionArgument *expr;

        for (expr = arglist.GetFirstItem(); 
             expr; expr = expr->GetNextItem())
        {
            if ((error = t.Expand(result, *expr)))
                return error;
        }
        return e_ERROR_NONE;
    }
} g_doTFunction
  ("do","do((do),...)");

/**
 **********************************************************************
 *  Class: cOrTFunction
 *
 * Author: $author$
 *   Date: 1/14/2009
 **********************************************************************
 */
class cOrTFunction
: public cTFunction
{
public:
    typedef cTFunction cExtends;

    /**
     **********************************************************************
     * Constructor: cOrTFunction
     *
     *      Author: $author$
     *        Date: 1/14/2009
     **********************************************************************
     */
    cOrTFunction(const char* name, const char* description)
    : cExtends(name, description)
    {
        static cTFunctionParameter parameter[] 
        = {{"cond","test condition"},
           {0,0}};
        m_parameters = (sizeof(parameter)/sizeof(cTFunctionParameter))-1;
        m_parameter = parameter;
    }
    /**
     **********************************************************************
     * Function: Expand
     *
     *   Author: $author$
     *     Date: 1/14/2009
     **********************************************************************
     */
    virtual eError Expand
    (cCharStreamInterface &result, cTInterface &t, 
     const cTFunctionArgumentList& arglist) const
    {
        cTFunctionArgument *cond;
        const char* chars;
        TLENGTH length;

        if ((cond = arglist.GetFirstItem()))
        {
            do
            {
                if ((chars = cond->GetBuffer(length)))
                if (0 < length)
                {
                    result.Write(chars, length);
                    break;
                }
            }
            while((cond = cond->GetNextItem()));
        }
        return e_ERROR_NONE;
    }
} g_cOrTFunction
  ("or","or(cond,...)");

/**
 **********************************************************************
 *  Class: cXorTFunction
 *
 * Author: $author$
 *   Date: 1/14/2009
 **********************************************************************
 */
class cXorTFunction
: public cTFunction
{
public:
    typedef cTFunction cExtends;

    /**
     **********************************************************************
     * Constructor: cXorTFunction
     *
     *      Author: $author$
     *        Date: 1/14/2009
     **********************************************************************
     */
    cXorTFunction(const char* name, const char* description)
    : cExtends(name, description)
    {
        static cTFunctionParameter parameter[] 
        = {{"cond","test condition"},
           {0,0}};
        m_parameters = (sizeof(parameter)/sizeof(cTFunctionParameter))-1;
        m_parameter = parameter;
    }
    /**
     **********************************************************************
     * Function: Expand
     *
     *   Author: $author$
     *     Date: 1/14/2009
     **********************************************************************
     */
    virtual eError Expand
    (cCharStreamInterface &result, cTInterface &t, 
     const cTFunctionArgumentList& arglist) const
    {
        bool one = false;
        cTFunctionArgument *cond;
        const char* chars;
        TLENGTH length;

        if ((cond = arglist.GetFirstItem()))
        {
            do
            {
                if (0 < (length = cond->GetLength()))
                if (one)
                    return e_ERROR_NONE;
                else one = true;
            }
            while((cond = cond->GetNextItem()));

            if ((cond = arglist.GetFirstItem()))
            do
            {
                if ((chars = cond->GetBuffer(length)))
                    result.Write(chars, length);
            }
            while((cond = cond->GetNextItem()));
        }
        return e_ERROR_NONE;
    }
} g_cXorTFunction
  ("xor","xor(cond,...)");

/**
 **********************************************************************
 *  Class: cAndTFunction
 *
 * Author: $author$
 *   Date: 1/14/2009
 **********************************************************************
 */
class cAndTFunction
: public cTFunction
{
public:
    typedef cTFunction cExtends;

    /**
     **********************************************************************
     * Constructor: cAndTFunction
     *
     *      Author: $author$
     *        Date: 1/14/2009
     **********************************************************************
     */
    cAndTFunction(const char* name, const char* description)
    : cExtends(name, description)
    {
        static cTFunctionParameter parameter[] 
        = {{"cond","test condition"},
           {0,0}};
        m_parameters = (sizeof(parameter)/sizeof(cTFunctionParameter))-1;
        m_parameter = parameter;
    }
    /**
     **********************************************************************
     * Function: Expand
     *
     *   Author: $author$
     *     Date: 1/14/2009
     **********************************************************************
     */
    virtual eError Expand
    (cCharStreamInterface &result, cTInterface &t, 
     const cTFunctionArgumentList& arglist) const
    {
        cTFunctionArgument *cond;
        const char* chars;
        TLENGTH length;

        if ((cond = arglist.GetFirstItem()))
        {
            do
            {
                if (0 >= (length = cond->GetLength()))
                    return e_ERROR_NONE;
            }
            while((cond = cond->GetNextItem()));

            if ((cond = arglist.GetFirstItem()))
            do
            {
                if ((chars = cond->GetBuffer(length)))
                    result.Write(chars, length);
            }
            while((cond = cond->GetNextItem()));
        }
        return e_ERROR_NONE;
    }
} g_cAndTFunction
  ("and","and(cond,...)");

/**
 **********************************************************************
 *  Class: cIfTFunction
 *
 * Author: $author$
 *   Date: 4/3/2008
 **********************************************************************
 */
class cIfTFunction
: public cTFunction
{
public:
    typedef cTFunction cExtends;

    /**
     **********************************************************************
     * Constructor: cIfTFunction
     *
     *      Author: $author$
     *        Date: 4/3/2008
     **********************************************************************
     */
    cIfTFunction(const char* name, const char* description)
    : cExtends(name, description)
    {
        static cTFunctionParameter parameter[] 
        = {{"cond","test condition"},
           {"(do)","do if cond"},
           {"(else)...","do else cond"},
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
     const cTFunctionArgumentList& arglist) const
    {
        eError error;
        cTFunctionArgument *cond;
        cTFunctionArgument *expr;

        if ((cond = arglist.GetFirstItem()))
        if ((expr = cond->GetNextItem()))
        if (cond->GetLength()>0)
        {
            if ((error = t.Expand(result, *expr)))
                return error;
        }
        else if ((expr = expr->GetNextItem()))
        {
            do
            {
                if ((error = t.Expand(result, *expr)))
                    return error;
            }
            while((expr = expr->GetNextItem()));
        }
        return e_ERROR_NONE;
    }
} g_cIfTFunction
  ("if","if(cond,(do),(else),...)");

/**
 **********************************************************************
 *  Class: cIfYesTFunction
 *
 * Author: $author$
 *   Date: 1/12/2009
 **********************************************************************
 */
class cIfYesTFunction
: public cTFunction
{
public:
    typedef cTFunction cExtends;

    /**
     **********************************************************************
     * Constructor: cIfYesTFunction
     *
     *      Author: $author$
     *        Date: 1/12/2009
     **********************************************************************
     */
    cIfYesTFunction(const char* name, const char* description)
    : cExtends(name, description)
    {
        static cTFunctionParameter parameter[] 
        = {{"cond","test condition"},
           {"(do)","do if cond is 'yes'"},
           {"(else)...","do else"},
           {0,0}};
        m_parameters = (sizeof(parameter)/sizeof(cTFunctionParameter))-1;
        m_parameter = parameter;
    }
    /**
     **********************************************************************
     * Function: Expand
     *
     *   Author: $author$
     *     Date: 1/12/2009
     **********************************************************************
     */
    virtual eError Expand
    (cCharStreamInterface &result, cTInterface &t, 
     const cTFunctionArgumentList& arglist) const
    {
        const char* yes = "yes";
        eError error;
        cTFunctionArgument *cond;
        cTFunctionArgument *expr;
        int unequal;

        if ((cond = arglist.GetFirstItem()))
        if ((expr = cond->GetNextItem()))
        if (!(unequal = cond->Compare(yes)))
        {
            if ((error = t.Expand(result, *expr)))
                return error;
        }
        else if ((expr = expr->GetNextItem()))
        {
            do
            {
                if ((error = t.Expand(result, *expr)))
                    return error;
            }
            while((expr = expr->GetNextItem()));
        }
        return e_ERROR_NONE;
    }
} g_cIfYesTFunction
  ("if-yes","if-yes(cond,(do),(else),...)");

/**
 **********************************************************************
 *  Class: cElseYesTFunction
 *
 * Author: $author$
 *   Date: 1/12/2009
 **********************************************************************
 */
class cElseYesTFunction
: public cTFunction
{
public:
    typedef cTFunction cExtends;

    /**
     **********************************************************************
     * Constructor: cElseYesTFunction
     *
     *      Author: $author$
     *        Date: 1/12/2009
     **********************************************************************
     */
    cElseYesTFunction(const char* name, const char* description)
    : cExtends(name, description)
    {
        static cTFunctionParameter parameter[] 
        = {{"cond","test condition"},
           {"(do)","do if cond is not 'yes'"},
           {"(else)...","do else"},
           {0,0}};
        m_parameters = (sizeof(parameter)/sizeof(cTFunctionParameter))-1;
        m_parameter = parameter;
    }
    /**
     **********************************************************************
     * Function: Expand
     *
     *   Author: $author$
     *     Date: 1/12/2009
     **********************************************************************
     */
    virtual eError Expand
    (cCharStreamInterface &result, cTInterface &t, 
     const cTFunctionArgumentList& arglist) const
    {
        const char* yes = "yes";
        eError error;
        cTFunctionArgument *cond;
        cTFunctionArgument *expr;
        TLENGTH length;
        int unequal;

        if ((cond = arglist.GetFirstItem()))
        if ((expr = cond->GetNextItem()))
        if ((0 < (length = cond->GetLength())) 
            && (unequal = cond->Compare(yes)))
        {
            if ((error = t.Expand(result, *expr)))
                return error;
        }
        else if ((expr = expr->GetNextItem()))
        {
            do
            {
                if ((error = t.Expand(result, *expr)))
                    return error;
            }
            while((expr = expr->GetNextItem()));
        }
        return e_ERROR_NONE;
    }
} g_cElseYesTFunction
  ("else-yes","else-yes(cond,(do),(else),...)");

/**
 **********************************************************************
 *  Class: cIfNoTFunction
 *
 * Author: $author$
 *   Date: 1/12/2009
 **********************************************************************
 */
class cIfNoTFunction
: public cTFunction
{
public:
    typedef cTFunction cExtends;

    /**
     **********************************************************************
     * Constructor: cIfNoTFunction
     *
     *      Author: $author$
     *        Date: 1/12/2009
     **********************************************************************
     */
    cIfNoTFunction(const char* name, const char* description)
    : cExtends(name, description)
    {
        static cTFunctionParameter parameter[] 
        = {{"cond","test condition"},
           {"(do)","do if cond is 'no'"},
           {"(else)...","do else"},
           {0,0}};
        m_parameters = (sizeof(parameter)/sizeof(cTFunctionParameter))-1;
        m_parameter = parameter;
    }
    /**
     **********************************************************************
     * Function: Expand
     *
     *   Author: $author$
     *     Date: 1/12/2009
     **********************************************************************
     */
    virtual eError Expand
    (cCharStreamInterface &result, cTInterface &t, 
     const cTFunctionArgumentList& arglist) const
    {
        const char* no = "no";
        eError error;
        cTFunctionArgument *cond;
        cTFunctionArgument *expr;
        int unequal;

        if ((cond = arglist.GetFirstItem()))
        if ((expr = cond->GetNextItem()))
        if (!(unequal = cond->Compare(no)))
        {
            if ((error = t.Expand(result, *expr)))
                return error;
        }
        else if ((expr = expr->GetNextItem()))
        {
            do
            {
                if ((error = t.Expand(result, *expr)))
                    return error;
            }
            while((expr = expr->GetNextItem()));
        }
        return e_ERROR_NONE;
    }
} g_cIfNoTFunction
  ("if-no","if-no(cond,(do),(else),...)");

/**
 **********************************************************************
 *  Class: cElseNoTFunction
 *
 * Author: $author$
 *   Date: 1/12/2009
 **********************************************************************
 */
class cElseNoTFunction
: public cTFunction
{
public:
    typedef cTFunction cExtends;

    /**
     **********************************************************************
     * Constructor: cElseNoTFunction
     *
     *      Author: $author$
     *        Date: 1/12/2009
     **********************************************************************
     */
    cElseNoTFunction(const char* name, const char* description)
    : cExtends(name, description)
    {
        static cTFunctionParameter parameter[] 
        = {{"cond","test condition"},
           {"(do)","do if cond is not 'no'"},
           {"(else)...","do else"},
           {0,0}};
        m_parameters = (sizeof(parameter)/sizeof(cTFunctionParameter))-1;
        m_parameter = parameter;
    }
    /**
     **********************************************************************
     * Function: Expand
     *
     *   Author: $author$
     *     Date: 1/12/2009
     **********************************************************************
     */
    virtual eError Expand
    (cCharStreamInterface &result, cTInterface &t, 
     const cTFunctionArgumentList& arglist) const
    {
        const char* no = "no";
        eError error;
        cTFunctionArgument *cond;
        cTFunctionArgument *expr;
        TLENGTH length;
        int unequal;

        if ((cond = arglist.GetFirstItem()))
        if ((expr = cond->GetNextItem()))
        if ((0 < (length = cond->GetLength())) 
            && (unequal = cond->Compare(no)))
        {
            if ((error = t.Expand(result, *expr)))
                return error;
        }
        else if ((expr = expr->GetNextItem()))
        {
            do
            {
                if ((error = t.Expand(result, *expr)))
                    return error;
            }
            while((expr = expr->GetNextItem()));
        }
        return e_ERROR_NONE;
    }
} g_cElseNoTFunction
  ("else-no","else-no(cond,(do),(else),...)");

/**
 **********************************************************************
 *  Class: cNotWhatTFunction
 *
 * Author: $author$
 *   Date: 5/30/2017
 **********************************************************************
 */
class cNotWhatTFunction: public cTFunction {
protected:
    const char* m_what;
public:
    typedef cTFunction cExtends;
    /**
     **********************************************************************
     * Constructor: cNotWhatTFunction
     *
     *      Author: $author$
     *        Date: 5/30/2017
     **********************************************************************
     */
    cNotWhatTFunction
    (const char* name, const char* description, const char* what)
    : cExtends(name, description), m_what(what) {
        static cTFunctionParameter parameter[]
        = {{"cond,...","return condition is not [what]"},
           {0,0}};
        m_parameters = (sizeof(parameter)/sizeof(cTFunctionParameter))-1;
        m_parameter = parameter;
    }
    /**
     **********************************************************************
     * Function: Expand
     *
     *   Author: $author$
     *     Date: 5/30/2017
     **********************************************************************
     */
    virtual eError Expand
    (cCharStreamInterface &result, cTInterface &t,
     const cTFunctionArgumentList& arglist) const {
        const char* what = 0;
        cTFunctionArgument *cond = 0;
        const char* chars = 0;
        TLENGTH length = 0;
        int unequal = 0;

        if ((cond = arglist.GetFirstItem())) {
            if (!(what = m_what)) {
                if ((what = cond->GetBuffer())) {
                    if (!(what[0])) {
                        what = 0;
                    }
                }
                cond = cond->GetNextItem();
            }
            if ((what) && (cond)) {
                do {
                    if ((0 < (length = cond->GetLength()))
                        && (unequal = cond->Compare(what))) {
                        if ((chars = cond->GetBuffer())) {
                            result.Write(chars, length);
                        }
                    }
                } while ((cond = cond->GetNextItem()));
            }
        }
        return e_ERROR_NONE;
    }
} g_cNotWhatTFunction
  ("not-what","not-what(what,cond,...)", 0);

/**
 **********************************************************************
 *  Class: cNotNoTFunction
 *
 * Author: $author$
 *   Date: 1/12/2009
 **********************************************************************
 */
class cNotNoTFunction: public cNotWhatTFunction {
public:
    typedef cNotWhatTFunction cExtends;
    /**
     **********************************************************************
     * Constructor: cNotNoTFunction
     *
     *      Author: $author$
     *        Date: 1/12/2009
     **********************************************************************
     */
    cNotNoTFunction(const char* name, const char* description)
    : cExtends(name, description, "no") {
        static cTFunctionParameter parameter[] 
        = {{"cond,...","return condition is not 'no'"},
           {0,0}};
        m_parameters = (sizeof(parameter)/sizeof(cTFunctionParameter))-1;
        m_parameter = parameter;
    }
} g_cNotNoTFunction
  ("not-no","not-no(cond,...)");

/**
 **********************************************************************
 *  Class: cNotYesTFunction
 *
 * Author: $author$
 *   Date: 5/30/2017
 **********************************************************************
 */
class cNotYesTFunction: public cNotWhatTFunction {
public:
    typedef cNotWhatTFunction cExtends;
    /**
     **********************************************************************
     * Constructor: cNotYesTFunction
     *
     *      Author: $author$
     *        Date: 5/30/2017
     **********************************************************************
     */
    cNotYesTFunction(const char* name, const char* description)
    : cExtends(name, description, "yes") {
        static cTFunctionParameter parameter[]
        = {{"cond,...","return condition is not 'yes'"},
           {0,0}};
        m_parameters = (sizeof(parameter)/sizeof(cTFunctionParameter))-1;
        m_parameter = parameter;
    }
} g_cNotYesTFunction
  ("not-yes","not-yes(cond,...)");

/**
 **********************************************************************
 *  Class: cElseTFunction
 *
 * Author: $author$
 *   Date: 4/5/2008
 **********************************************************************
 */
class cElseTFunction
: public cTFunction
{
public:
    typedef cTFunction cExtends;

    /**
     **********************************************************************
     * Constructor: cElseTFunction
     *
     *      Author: $author$
     *        Date: 4/5/2008
     **********************************************************************
     */
    cElseTFunction(const char* name, const char* description)
    : cExtends(name, description)
    {
        static cTFunctionParameter parameter[] 
        = {{"cond","test condition"},
           {"(do)","do else cond"},
           {"(else)...","do if cond"},
           {0,0}};
        m_parameters = (sizeof(parameter)/sizeof(cTFunctionParameter))-1;
        m_parameter = parameter;
    }
    /**
     **********************************************************************
     * Function: Expand
     *
     *   Author: $author$
     *     Date: 4/5/2008
     **********************************************************************
     */
    virtual eError Expand
    (cCharStreamInterface &result, cTInterface &t, 
     const cTFunctionArgumentList& arglist) const
    {
        eError error;
        cTFunctionArgument *cond;
        cTFunctionArgument *expr;

        if ((cond = arglist.GetFirstItem()))
        if ((expr = cond->GetNextItem()))
        if (cond->GetLength()<1)
        {
            if ((error = t.Expand(result, *expr)))
                return error;
        }
        else if ((expr = expr->GetNextItem()))
        {
            do
            {
                if ((error = t.Expand(result, *expr)))
                    return error;
            }
            while((expr = expr->GetNextItem()));
        }
        return e_ERROR_NONE;
    }
} g_cElseTFunction
  ("else","else(cond,(do),(else)...)");

/**
 **********************************************************************
 *  Class: cIfThenTFunction
 *
 * Author: $author$
 *   Date: 4/5/2008
 **********************************************************************
 */
class cIfThenTFunction
: public cTFunction
{
public:
    typedef cTFunction cExtends;

    /**
     **********************************************************************
     * Constructor: cIfThenTFunction
     *
     *      Author: $author$
     *        Date: 4/5/2008
     **********************************************************************
     */
    cIfThenTFunction(const char* name, const char* description)
    : cExtends(name, description)
    {
        static cTFunctionParameter parameter[] 
        = {{"did","do then test condition"},
           {"(do),...","do if did"},
           {0,0}};
        m_parameters = (sizeof(parameter)/sizeof(cTFunctionParameter))-1;
        m_parameter = parameter;
    }
    /**
     **********************************************************************
     * Function: Expand
     *
     *   Author: $author$
     *     Date: 4/5/2008
     **********************************************************************
     */
    virtual eError Expand
    (cCharStreamInterface &result, cTInterface &t, 
     const cTFunctionArgumentList& arglist) const
    {
        TLENGTH length;
        const char *buffer;
        eError error;
        cTFunctionArgument *cond;
        cTFunctionArgument *expr;

        if ((cond = arglist.GetFirstItem()))
        if ((buffer = cond->GetBuffer(length)))
        if (length > 0)
        {
            result.Write(buffer, length);

            if ((expr = cond->GetNextItem()))
            do
            {
                if (expr->GetLength()>0)
                if ((error = t.Expand(result, *expr)))
                    return error;
            }
            while((expr = expr->GetNextItem()));
        }
        return e_ERROR_NONE;
    }
} g_cIfThenTFunction
  ("if-then","if-then(did,(do),...)");

/**
 **********************************************************************
 *  Class: cElseThenTFunction
 *
 * Author: $author$
 *   Date: 4/3/2008
 **********************************************************************
 */
class cElseThenTFunction
: public cTFunction
{
public:
    typedef cTFunction cExtends;

    /**
     **********************************************************************
     * Constructor: cElseThenTFunction
     *
     *      Author: $author$
     *        Date: 4/3/2008
     **********************************************************************
     */
    cElseThenTFunction(const char* name, const char* description)
    : cExtends(name, description)
    {
        static cTFunctionParameter parameter[] 
        = {{"did","do then test condition"},
           {"(else),...","do else did"},
           {0,0}};
        m_parameters = (sizeof(parameter)/sizeof(cTFunctionParameter))-1;
        m_parameter = parameter;
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
     const cTFunctionArgumentList& arglist) const
    {
        eError error;
        TLENGTH length;
        const char* buffer;
        cTFunctionArgument* cond;
        cTFunctionArgument* expr;

        if ((cond = arglist.GetFirstItem()))
        {
            if ((buffer = cond->GetBuffer(length)))
            if (length > 0)
            {
                result.Write(buffer, length);
                return e_ERROR_NONE;
            }

            if ((expr = cond->GetNextItem()))
            do
            {
                if (expr->GetLength()>0)
                if ((error = t.Expand(result, *expr)))
                    return error;
            }
            while((expr = expr->GetNextItem()));
        }
        return e_ERROR_NONE;
    }
} g_cElseThenTFunction
  ("else-then","else-then(did,(else),...)");

/**
 **********************************************************************
 *  Class: cThenIfTFunction
 *
 * Author: $author$
 *   Date: 4/5/2008
 **********************************************************************
 */
class cThenIfTFunction
: public cTFunction
{
public:
    typedef cTFunction cExtends;

    /**
     **********************************************************************
     * Constructor: cThenIfTFunction
     *
     *      Author: $author$
     *        Date: 4/5/2008
     **********************************************************************
     */
    cThenIfTFunction(const char* name, const char* description)
    : cExtends(name, description)
    {
        static cTFunctionParameter parameter[] 
        = {{"todo","test condition then do"},
           {"(do),...","do if todo"},
           {0,0}};
        m_parameters = (sizeof(parameter)/sizeof(cTFunctionParameter))-1;
        m_parameter = parameter;
    }
    /**
     **********************************************************************
     * Function: Expand
     *
     *   Author: $author$
     *     Date: 4/5/2008
     **********************************************************************
     */
    virtual eError Expand
    (cCharStreamInterface &result, cTInterface &t, 
     const cTFunctionArgumentList& arglist) const
    {
        TLENGTH length;
        const char *buffer;
        eError error;
        cTFunctionArgument *cond;
        cTFunctionArgument *expr;

        if ((cond = arglist.GetFirstItem()))
        if ((buffer = cond->GetBuffer(length)))
        if (length > 0)
        {
            if ((expr = cond->GetNextItem()))
            do
            {
                if (expr->GetLength()>0)
                if ((error = t.Expand(result, *expr)))
                    return error;
            }
            while((expr = expr->GetNextItem()));

            result.Write(buffer, length);
        }
        return e_ERROR_NONE;
    }
} g_cThenIfTFunction
  ("then-if","then-if(todo,(do),...)");

/**
 **********************************************************************
 *  Class: cThenElseTFunction
 *
 * Author: $author$
 *   Date: 4/5/2008
 **********************************************************************
 */
class cThenElseTFunction
: public cTFunction
{
public:
    typedef cTFunction cExtends;

    /**
     **********************************************************************
     * Constructor: cThenElseTFunction
     *
     *      Author: $author$
     *        Date: 4/5/2008
     **********************************************************************
     */
    cThenElseTFunction(const char* name, const char* description)
    : cExtends(name, description)
    {
        static cTFunctionParameter parameter[] 
        = {{"todo","test condition then do"},
           {"(else),...","do else todo"},
           {0,0}};
        m_parameters = (sizeof(parameter)/sizeof(cTFunctionParameter))-1;
        m_parameter = parameter;
    }
    /**
     **********************************************************************
     * Function: Expand
     *
     *   Author: $author$
     *     Date: 4/5/2008
     **********************************************************************
     */
    virtual eError Expand
    (cCharStreamInterface &result, cTInterface &t, 
     const cTFunctionArgumentList& arglist) const
    {
        TLENGTH length;
        const char *buffer;
        eError error;
        cTFunctionArgument *cond;
        cTFunctionArgument *expr;

        if ((cond = arglist.GetFirstItem()))
        if ((buffer = cond->GetBuffer(length)))
        if (length > 0)
        {
            if ((expr = cond->GetNextItem()))
            do
            {
                if (expr->GetLength()<1)
                if ((error = t.Expand(result, *expr)))
                    return error;
            }
            while((expr = expr->GetNextItem()));

            result.Write(buffer, length);
        }
        return e_ERROR_NONE;
    }
} g_cThenElseTFunction
  ("then-else","then-else(todo,(else),...)");

/**
 **********************************************************************
 *  Class: cCaseTFunction
 *
 * Author: $author$
 *   Date: 12/28/2008
 **********************************************************************
 */
class cCaseTFunction
: public cTFunction
{
public:
    typedef cTFunction cExtends;

    /**
     **********************************************************************
     * Constructor: cCaseTFunction
     *
     *      Author: $author$
     *        Date: 12/28/2008
     **********************************************************************
     */
    cCaseTFunction(const char* name, const char* description)
    : cExtends(name, description)
    {
        static cTFunctionParameter parameter[] 
        = {{"when","conditional test"},
           {"(do),...","conditional expansion"},
           {"(otherwise)","otherwise expansion"},
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
        eError error;
        TLENGTH length;
        cTFunctionArgument *when;
        cTFunctionArgument *expr;

        if ((when = arglist.GetFirstItem()))
        if ((expr = when->GetNextItem()))
        {
            do
            {
                if (0 >= (length = when->GetLength()))
                {
                    if ((when = expr->GetNextItem()))
                    {
                        if ((expr = when->GetNextItem()))
                            continue;

                        else if ((error = t.Expand(result, *when)))
                                return error;
                    }
                    break;
                }

                if ((error = t.Expand(result, *expr)))
                    return error;

                break;
            }
            while (when);
        }
        else if ((error = t.Expand(result, *when)))
                return error;

        return e_ERROR_NONE;
    }
} g_cCaseTFunction
  ("case","case(when,(do)[[,...,when,(do),](otherwise)])");

/**
 **********************************************************************
 *  Class: cSwitchTFunction
 *
 * Author: $author$
 *   Date: 12/28/2008
 **********************************************************************
 */
class cSwitchTFunction
: public cTFunction
{
public:
    typedef cTFunction cExtends;

    /**
     **********************************************************************
     * Constructor: cSwitchTFunction
     *
     *      Author: $author$
     *        Date: 12/28/2008
     **********************************************************************
     */
    cSwitchTFunction(const char* name, const char* description)
    : cExtends(name, description)
    {
        static cTFunctionParameter parameter[] 
        = {{"cond","conditional value"},
           {"case","conditional match"},
           {"(do),...","conditional expansion"},
           {"(otherwise)","otherwise expansion"},
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
        int unequal;
        eError error;
        cTFunctionArgument *cond;
        cTFunctionArgument *match;
        cTFunctionArgument *expr;

        if ((cond = arglist.GetFirstItem()))
        if ((match = cond->GetNextItem()))
        {
            if ((expr = match->GetNextItem()))
            do
            {
                if ((unequal = cond->Compare(*match)))
                {
                    if ((match = expr->GetNextItem()))
                    if ((expr = match->GetNextItem()))
                        continue;

                    else if ((error = t.Expand(result, *match)))
                            return error;

                    break;
                }

                if ((error = t.Expand(result, *expr)))
                    return error;

                break;
            }
            while (match);
        }
        else if ((error = t.Expand(result, *cond)))
                return error;

        return e_ERROR_NONE;
    }
} g_cSwitchTFunction
  ("switch","switch(cond,case,(do)[[,...,case,(do),](otherwise)])");

/**
 **********************************************************************
 *  Class: cWithTFunction
 *
 * Author: $author$
 *   Date: 4/2/2008
 **********************************************************************
 */
class cWithTFunction
: public cTFunction
{
public:
    typedef cTFunction cExtends;

    /**
     **********************************************************************
     * Constructor: cWithTFunction
     *
     *      Author: $author$
     *        Date: 4/2/2008
     **********************************************************************
     */
    cWithTFunction(const char* name, const char* description)
    : cExtends(name, description)
    {
        static cTFunctionParameter parameter[] 
        = {{"name","variable name"},
           {"(value)","variable value expansion"},
           {"(do)","do expansion"},
           {0,0}};

        m_parameter = parameter;
        m_parameters = sizeof(parameter)/sizeof(cTFunctionParameter)-1;
    }
    /**
     **********************************************************************
     * Function: Expand
     *
     *   Author: $author$
     *     Date: 4/2/2008
     **********************************************************************
     */
    virtual eError Expand
    (cCharStreamInterface &result, cTInterface &t, 
     const cTFunctionArgumentList& arglist) const
    {
        TLENGTH length;
        const char* buffer;
        cTVariableInterface *variable;
        cTFunctionArgument *name;
        cTFunctionArgument *value;
        cTFunctionArgument *expr = 0;
        cCharBuffer value_result;

        if ((expr = (name = arglist.GetFirstItem())))
        {
            do
            {
                if (!(expr = (value = name->GetNextItem())))
                    expr = name;

                else if (!(expr = value->GetNextItem()))
                        expr = value;

                else
                {
                    if ((variable = GetVariable(t, *name)))
                    {
                        value_result.Clear();
                        t.Expand(value_result, *value);
                        if ((buffer = value_result.GetBuffer(length)))
                            variable->PushValue(buffer,length);
                    }
                    name = expr;
                    continue;
                }
                break;
            }
            while (name);

            if (expr)
            if (expr->GetLength()>0)
                t.Expand(result, *expr);

            if ((expr = (name = arglist.GetFirstItem())))
            do
            {
                if (!(expr = (value = name->GetNextItem())))
                    expr = name;

                else if (!(expr = value->GetNextItem()))
                        expr = value;

                else
                {
                    if ((buffer = value_result.GetBuffer(length)))
                    if ((variable = GetVariable(t, *name)))
                        variable->PopValue();

                    name = expr;
                    continue;
                }

                break;
            }
            while (name);
        }
        return e_ERROR_NONE;
    }
} g_cWithTFunction
  ("with","with([name,(value),...,](do))"),
  g_cWithTFunction2
  ("apply-x","apply-x([name,(value),...,](do))");

/**
 **********************************************************************
 *  Class: cApplyTFunction
 *
 * Author: $author$
 *   Date: 12/26/2008
 **********************************************************************
 */
class cApplyTFunction
: public cTFunction
{
public:
    typedef cTFunction cExtends;

    /**
     **********************************************************************
     * Constructor: cApplyTFunction
     *
     *      Author: $author$
     *        Date: 12/26/2008
     **********************************************************************
     */
    cApplyTFunction(const char* name, const char* description)
    : cExtends(name, description)
    {
        static cTFunctionParameter parameter[] 
        = {{"name","variable name"},
           {"value","variable value expansion"},
           {"(do)","do expansion"},
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
        TLENGTH length;
        const char* buffer;
        cTVariableInterface *variable;
        cTFunctionArgument *name;
        cTFunctionArgument *value;
        cTFunctionArgument *expr = 0;

        if ((expr = (name = arglist.GetFirstItem())))
        {
            do
            {
                if (!(expr = (value = name->GetNextItem())))
                    expr = name;

                else if (!(expr = value->GetNextItem()))
                        expr = value;

                else
                {
                    if ((buffer = value->GetBuffer(length)))
                    if ((variable = GetVariable(t, *name)))
                        variable->PushValue(buffer,length);

                    name = expr;
                    continue;
                }
                break;
            }
            while (name);

            if (expr)
            if (expr->GetLength()>0)
                t.Expand(result, *expr);

            if ((expr = (name = arglist.GetFirstItem())))
            do
            {
                if (!(expr = (value = name->GetNextItem())))
                    expr = name;

                else if (!(expr = value->GetNextItem()))
                        expr = value;

                else
                {
                    if ((buffer = value->GetBuffer(length)))
                    if ((variable = GetVariable(t, *name)))
                        variable->PopValue();

                    name = expr;
                    continue;
                }
                break;
            }
            while (name);
        }
        return e_ERROR_NONE;
    }
} g_cApplyTFunction
  ("apply","apply([name,value,...,](do))");

/**
 **********************************************************************
 *  Class: cEqualTFunction
 *
 * Author: $author$
 *   Date: 4/3/2008
 **********************************************************************
 */
class cEqualTFunction
: public cTFunction
{
public:
    typedef cTFunction cExtends;

    /**
     **********************************************************************
     * Constructor: cEqualTFunction
     *
     *      Author: $author$
     *        Date: 4/3/2008
     **********************************************************************
     */
    cEqualTFunction(const char* name, const char* description)
    : cExtends(name, description)
    {
        static cTFunctionParameter parameter[] 
        = {{"string,...","strings to compare"}, 
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
     const cTFunctionArgumentList& arglist) const
    {
        int unequal;
        TLENGTH length, length2;
        const char *buffer, *buffer2;
        cTFunctionArgument *arg;
        cCharComparer comparer;

        if ((arg = arglist.GetFirstItem()))
        if ((buffer = arg->GetBuffer(length)))
        {
            while((arg = arg->GetNextItem()))
            {
                if ((buffer2 = arg->GetBuffer(length2)))
                if (!(unequal = comparer.Compare
                    (buffer, length, buffer2, length2)))
                    continue;

                return e_ERROR_NONE;
            }

            if (length>0)
                result.Write(buffer, length);
        }
        return e_ERROR_NONE;
    }
} g_cEqualTFunction
  ("equal","equal(string,...)");

/**
 **********************************************************************
 *  Class: cUnequalTFunction
 *
 * Author: $author$
 *   Date: 4/6/2008
 **********************************************************************
 */
class cUnequalTFunction
: public cTFunction
{
public:
    typedef cTFunction cExtends;

    /**
     **********************************************************************
     * Constructor: cUnequalTFunction
     *
     *      Author: $author$
     *        Date: 4/6/2008
     **********************************************************************
     */
    cUnequalTFunction(const char* name, const char* description)
    : cExtends(name, description)
    {
        static cTFunctionParameter parameter[] 
        = {{"string,...","strings to compare"},
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
     const cTFunctionArgumentList& arglist) const
    {
        int unequal;
        TLENGTH length, length1, length2;
        const char *buffer, *buffer1, *buffer2;
        cTFunctionArgument *arg, *arg1, *arg2;
        cCharComparer comparer;

        if ((arg2 = (arg1 = arglist.GetFirstItem())))
        if ((buffer1 = arg1->GetBuffer(length1)))
        {
            while((arg2 = arg2->GetNextItem()))
            {
                if ((buffer2 = arg2->GetBuffer(length2)))
                if ((unequal = comparer.Compare
                    (buffer1, length1, buffer2, length2)))
                {
                    for (arg = arg1->GetNextItem(); 
                         arg && (arg != arg2); 
                         arg = arg->GetNextItem())
                    {
                        if ((buffer = arg->GetBuffer(length)))
                        if ((unequal = comparer.Compare
                            (buffer, length, buffer2, length2)))
                            continue;

                        unequal = false;
                    }

                    if (unequal)
                        continue;
                }

                return e_ERROR_NONE;
            }

            if (length>0)
                result.Write(buffer1, length1);
        }
        return e_ERROR_NONE;
    }
} g_cUnequalTFunction
  ("unequal","unequal(string,...)");

/**
 **********************************************************************
 *  Class: cLeftTFunction
 *
 * Author: $author$
 *   Date: 8/15/2008
 **********************************************************************
 */
class cLeftTFunction
: public cTFunction
{
public:
    typedef cTFunction cExtends;

    /**
     **********************************************************************
     * Constructor: cLeftTFunction
     *
     *      Author: $author$
     *        Date: 8/15/2008
     **********************************************************************
     */
    cLeftTFunction(const char* name, const char* description)
    : cExtends(name, description)
    {
        static cTFunctionParameter parameter[] 
        = {{"string","string"},
           {"pattern","pattern"},
           {0,0}};
        m_parameters = (sizeof(parameter)/sizeof(cTFunctionParameter))-1;
        m_parameter = parameter;
    }
    /**
     **********************************************************************
     * Function: Expand
     *
     *   Author: $author$
     *     Date: 8/15/2008
     **********************************************************************
     */
    virtual eError Expand
    (cCharStreamInterface &result, cTInterface &t, 
     const cTFunctionArgumentList& arglist) const
    {
        TLENGTH length1,length2;
        const char *buffer1, *buffer2;
        cTFunctionArgument *arg1, *arg2;

        if ((arg1 = arglist.GetFirstItem()))
        if ((arg2 = arg1->GetNextItem()))
        if ((buffer1 = arg1->GetBuffer(length1)))
        if ((buffer2 = arg2->GetBuffer(length2)))
        if ((length2 > 0) && (length2 < length1))
        if ((buffer2 = strstr(buffer1, buffer2)))
            result.Write(buffer1, (TLENGTH)(buffer2-buffer1));

        return e_ERROR_NONE;
    }
} g_cLeftTFunction
  ("left","left(string,pattern)");

/**
 **********************************************************************
 *  Class: cRightTFunction
 *
 * Author: $author$
 *   Date: 8/15/2008
 **********************************************************************
 */
class cRightTFunction
: public cTFunction
{
public:
    typedef cTFunction cExtends;

    /**
     **********************************************************************
     * Constructor: cRightTFunction
     *
     *      Author: $author$
     *        Date: 8/15/2008
     **********************************************************************
     */
    cRightTFunction(const char* name, const char* description)
    : cExtends(name, description)
    {
        static cTFunctionParameter parameter[] 
        = {{"string","string"},
           {"pattern","pattern"},
           {0,0}};
        m_parameters = (sizeof(parameter)/sizeof(cTFunctionParameter))-1;
        m_parameter = parameter;
    }
    /**
     **********************************************************************
     * Function: Expand
     *
     *   Author: $author$
     *     Date: 8/15/2008
     **********************************************************************
     */
    virtual eError Expand
    (cCharStreamInterface &result, cTInterface &t, 
     const cTFunctionArgumentList& arglist) const
    {
        TLENGTH length1,length2,length3;
        const char *buffer1, *buffer2;
        const char *found1, *found2;
        cTFunctionArgument *arg1, *arg2;

        if ((arg1 = arglist.GetFirstItem()))
        if ((arg2 = arg1->GetNextItem()))
        if ((buffer1 = arg1->GetBuffer(length1)))
        if ((buffer2 = arg2->GetBuffer(length2)))
        if ((length2 > 0) && (length2 < length1))
        if ((found1 = strstr(buffer1, buffer2)))
        {
            while ((found2 = strstr(found1+length2, buffer2)))
                found1 = found2;

            if (length1 > (length3 = ((TLENGTH)(found1-buffer1))+length2))
                result.Write(found1+length2, length1-length3);
        }
        return e_ERROR_NONE;
    }
} g_cRightTFunction
  ("right","right(string,pattern)");

/**
 **********************************************************************
 *  Class: cLeftOfRightTFunction
 *
 * Author: $author$
 *   Date: 12/25/2008
 **********************************************************************
 */
class cLeftOfRightTFunction
: public cTFunction
{
public:
    typedef cTFunction cExtends;

    /**
     **********************************************************************
     * Constructor: cLeftOfRightTFunction
     *
     *      Author: $author$
     *        Date: 12/25/2008
     **********************************************************************
     */
    cLeftOfRightTFunction(const char* name, const char* description)
    : cExtends(name, description)
    {
        static cTFunctionParameter parameter[] 
        = {{"string","string"},
           {"pattern","pattern"},
           {0,0}};
        m_parameters = (sizeof(parameter)/sizeof(cTFunctionParameter))-1;
        m_parameter = parameter;
    }
    /**
     **********************************************************************
     * Function: Expand
     *
     *   Author: $author$
     *     Date: 12/25/2008
     **********************************************************************
     */
    virtual eError Expand
    (cCharStreamInterface &result, cTInterface &t, 
     const cTFunctionArgumentList& arglist) const
    {
        TLENGTH length1,length2,length3;
        const char *buffer1, *buffer2;
        const char *found1, *found2;
        cTFunctionArgument *arg1, *arg2;

        if ((arg1 = arglist.GetFirstItem()))
        if ((arg2 = arg1->GetNextItem()))
        if ((buffer1 = arg1->GetBuffer(length1)))
        if ((buffer2 = arg2->GetBuffer(length2)))
        if ((length2 > 0) && (length2 < length1))
        if ((found1 = strstr(buffer1, buffer2)))
        {
            while ((found2 = strstr(found1+length2, buffer2)))
                found1 = found2;

            if (length1 > (length3 = ((TLENGTH)(found1-buffer1))))
                result.Write(buffer1, length3);
        }
        return e_ERROR_NONE;
    }
} g_cLeftOfRightTFunction
  ("left-of-right","left-of-right(string,pattern)");

/**
 **********************************************************************
 *  Class: cRightOfLeftTFunction
 *
 * Author: $author$
 *   Date: 12/25/2008
 **********************************************************************
 */
class cRightOfLeftTFunction
: public cTFunction
{
public:
    typedef cTFunction cExtends;

    /**
     **********************************************************************
     * Constructor: cRightOfLeftTFunction
     *
     *      Author: $author$
     *        Date: 12/25/2008
     **********************************************************************
     */
    cRightOfLeftTFunction(const char* name, const char* description)
    : cExtends(name, description)
    {
        static cTFunctionParameter parameter[] 
        = {{"string","string"},
           {"pattern","pattern"},
           {0,0}};
        m_parameters = (sizeof(parameter)/sizeof(cTFunctionParameter))-1;
        m_parameter = parameter;
    }
    /**
     **********************************************************************
     * Function: Expand
     *
     *   Author: $author$
     *     Date: 12/25/2008
     **********************************************************************
     */
    virtual eError Expand
    (cCharStreamInterface &result, cTInterface &t, 
     const cTFunctionArgumentList& arglist) const
    {
        TLENGTH length1,length2,length3;
        const char *buffer1, *buffer2;
        cTFunctionArgument *arg1, *arg2;

        if ((arg1 = arglist.GetFirstItem()))
        if ((arg2 = arg1->GetNextItem()))
        if ((buffer1 = arg1->GetBuffer(length1)))
        if ((buffer2 = arg2->GetBuffer(length2)))
        if ((length2 > 0) && (length2 < length1))
        if ((buffer2 = strstr(buffer1, buffer2)))
        if (length1 > (length3 = ((TLENGTH)(buffer2-buffer1))+length2))
            result.Write(buffer2+length2, length1-length3);

        return e_ERROR_NONE;
    }
} g_cRightOfLeftTFunction
  ("right-of-left","right-of-left(string,pattern)");

/**
 **********************************************************************
 *  Class: cLeftCharTFunction
 *
 * Author: $author$
 *   Date: 12/26/2008
 **********************************************************************
 */
class cLeftCharTFunction
: public cTFunction
{
public:
    typedef cTFunction cExtends;

    /**
     **********************************************************************
     * Constructor: cLeftCharTFunction
     *
     *      Author: $author$
     *        Date: 12/26/2008
     **********************************************************************
     */
    cLeftCharTFunction(const char* name, const char* description)
    : cExtends(name, description)
    {
        static cTFunctionParameter parameter[] 
        = {{"string",""},
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
        cTFunctionArgument *arg;
        const char *buffer;
        TLENGTH length;

        if ((arg = arglist.GetFirstItem()))
        if ((buffer = arg->GetBuffer(length)))
        if (length > 0)
            result.Write(buffer, 1);

        return e_ERROR_NONE;
    }
} g_cLeftCharTFunction
  ("left-char","left-char(string)");

/**
 **********************************************************************
 *  Class: cRightOfLeftCharTFunction
 *
 * Author: $author$
 *   Date: 12/26/2008
 **********************************************************************
 */
class cRightOfLeftCharTFunction
: public cTFunction
{
public:
    typedef cTFunction cExtends;

    /**
     **********************************************************************
     * Constructor: cRightOfLeftCharTFunction
     *
     *      Author: $author$
     *        Date: 12/26/2008
     **********************************************************************
     */
    cRightOfLeftCharTFunction(const char* name, const char* description)
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
        cTFunctionArgument *arg;
        const char *buffer;
        TLENGTH length;

        if ((arg = arglist.GetFirstItem()))
        if ((buffer = arg->GetBuffer(length)))
        if (length > 1)
            result.Write(buffer+1);

        return e_ERROR_NONE;
    }
} g_cRightOfLeftCharTFunction
  ("right-of-left-char","right-of-left-char(string)"),
  g_cRightOfLeftCharTFunction2
  ("right-chars","right-chars(string)");

/**
 **********************************************************************
 *  Class: cParseTFunction
 *
 * Author: $author$
 *   Date: 12/25/2008
 **********************************************************************
 */
class cParseTFunction
: public cTFunction
{
public:
    typedef cTFunction cExtends;

    /**
     **********************************************************************
     * Constructor: cParseTFunction
     *
     *      Author: $author$
     *        Date: 12/25/2008
     **********************************************************************
     */
    cParseTFunction(const char* name, const char* description)
    : cExtends(name, description)
    {
        static cTFunctionParameter parameter[] 
        = {{"string",""},
           {"delim",""},
           {"(before)",""},
           {"(between)",""},
           {"(after)",""},
           {"(expr)",""},
           {"var",""},
           {0,0}};
        m_parameters = (sizeof(parameter)/sizeof(cTFunctionParameter))-1;
        m_parameter = parameter;
    }
    /**
     **********************************************************************
     * Function: Expand
     *
     *   Author: $author$
     *     Date: 12/25/2008
     **********************************************************************
     */
    virtual eError Expand
    (cCharStreamInterface &result, cTInterface &t, 
     const cTFunctionArgumentList& arglist) const
    {
        cTFunctionArgument *before=0, *between=0, *after=0, *expr=0, *var=0;
        const char *string, *delim, *token, *name;
        cTFunctionArgument *arg1;
        TLENGTH delimLength, length;

        if ((arg1 = arglist.GetFirstItem()))
        if ((string = arg1->GetBuffer()))
        if ((arg1 = arg1->GetNextItem()))
        if ((delim = arg1->GetBuffer(delimLength)))
        {
            cTVariableInterface *variable = 0;

            if ((before = (arg1 = arg1->GetNextItem())))
            if ((between = (arg1 = arg1->GetNextItem())))
            if ((expr = (arg1 = arg1->GetNextItem())))
            if ((var = (arg1 = arg1->GetNextItem())))
            {
                if ((arg1 = arg1->GetNextItem()))
                {
                    after = expr;
                    expr = var;
                    var = arg1;
                }
                if ((name = var->GetBuffer()))
                    variable = t.GetVariable(name);
            }

            while ((token = strstr(string, delim)))
            {
                if (variable)
                    variable->PushValue
                    (string, (TLENGTH)(token-string));

                if (before)
                if (0 < (length = before->GetLength()))
                if (0 <= (length = before->Seek(0)))
                    t.Expand(result, *before);

                if (!expr)
                    result.Write
                    (string, (TLENGTH)(token-string));
                else
                if (0 < (length = expr->GetLength()))
                if (0 <= (length = expr->Seek(0)))
                    t.Expand(result, *expr);

                if ((string = token+delimLength)[0])
                if (between)
                if (0 < (length = between->GetLength()))
                if (0 <= (length = between->Seek(0)))
                    t.Expand(result, *between);

                if (after)
                if (0 < (length = after->GetLength()))
                if (0 <= (length = after->Seek(0)))
                    t.Expand(result, *after);

                if (variable)
                    variable->PopValue();
            }

            if (string[0])
            {
                if (variable)
                    variable->PushValue(string);

                if (before)
                if (0 < (length = before->GetLength()))
                if (0 <= (length = before->Seek(0)))
                    t.Expand(result, *before);

                if (!expr)
                    result.Write(string);
                else
                if (0 < (length = expr->GetLength()))
                if (0 <= (length = expr->Seek(0)))
                    t.Expand(result, *expr);

                if (after)
                if (0 < (length = after->GetLength()))
                if (0 <= (length = after->Seek(0)))
                    t.Expand(result, *after);

                if (variable)
                    variable->PopValue();
            }
        }
        return e_ERROR_NONE;
    }
} g_cParseTFunction
  ("parse","parse(string,delim[,(before)[,(between)[,[(after),](expr),var]]])");

/**
 **********************************************************************
 *  Class: cRParseTFunction
 *
 * Author: $author$
 *   Date: 12/25/2008
 **********************************************************************
 */
class cRParseTFunction
: public cTFunction
{
public:
    typedef cTFunction cExtends;

    /**
     **********************************************************************
     * Constructor: cRParseTFunction
     *
     *      Author: $author$
     *        Date: 12/25/2008
     **********************************************************************
     */
    cRParseTFunction(const char* name, const char* description)
    : cExtends(name, description)
    {
        static cTFunctionParameter parameter[] 
        = {{"string",""},
           {"delim",""},
           {"(before)",""},
           {"(between)",""},
           {"(after)",""},
           {"(expr)",""},
           {"var",""},
           {0,0}};
        m_parameters = (sizeof(parameter)/sizeof(cTFunctionParameter))-1;
        m_parameter = parameter;
    }
    /**
     **********************************************************************
     * Function: Expand
     *
     *   Author: $author$
     *     Date: 12/25/2008
     **********************************************************************
     */
    virtual eError Expand
    (cCharStreamInterface &result, cTInterface &t, 
     const cTFunctionArgumentList& arglist) const
    {
        cTFunctionArgument *before=0, *between=0, *after=0, *expr=0, *var=0;
        const char *string, *delim, *token, *name;
        cTFunctionArgument *arg1;
        TLENGTH delimLength, length;
        cString reversed;
        cString reversed2;

        if ((arg1 = arglist.GetFirstItem()))
        if ((string = arg1->GetBuffer()))
        if ((arg1 = arg1->GetNextItem()))
        if ((delim = arg1->GetBuffer(delimLength)))
        {
            cTVariableInterface *variable = 0;

            if ((before = (arg1 = arg1->GetNextItem())))
            if ((between = (arg1 = arg1->GetNextItem())))
            if ((expr = (arg1 = arg1->GetNextItem())))
            if ((var = (arg1 = arg1->GetNextItem())))
            {
                if ((arg1 = arg1->GetNextItem()))
                {
                    after = expr;
                    expr = var;
                    var = arg1;
                }
                if ((name = var->GetBuffer()))
                    variable = t.GetVariable(name);
            }

            while ((token = strstr(string, delim)))
            {
                const char* next = token+delimLength;
                reversed2.Assign(reversed.Chars(length));
                if ((next[0])) 
                {
                    reversed.Assign(delim);
                    reversed.Append(string, token-string);
                }
                else reversed.Assign(string, token-string);
                reversed.Append(reversed2.Chars(length));
                string = next;
            }
            if ((string[0])) 
            {
                reversed2.Assign(reversed.Chars(length));
                reversed.Assign(string);
                reversed.Append(reversed2.Chars(length));
            }
            string = reversed.Chars(length);
            while ((token = strstr(string, delim)))
            {
                if (variable)
                    variable->PushValue
                    (string, (TLENGTH)(token-string));

                if (before)
                if (0 < (length = before->GetLength()))
                if (0 <= (length = before->Seek(0)))
                    t.Expand(result, *before);

                if (!expr)
                    result.Write
                    (string, (TLENGTH)(token-string));
                else
                if (0 < (length = expr->GetLength()))
                if (0 <= (length = expr->Seek(0)))
                    t.Expand(result, *expr);

                if ((string = token+delimLength)[0])
                if (between)
                if (0 < (length = between->GetLength()))
                if (0 <= (length = between->Seek(0)))
                    t.Expand(result, *between);

                if (after)
                if (0 < (length = after->GetLength()))
                if (0 <= (length = after->Seek(0)))
                    t.Expand(result, *after);

                if (variable)
                    variable->PopValue();
            }

            if (string[0])
            {
                if (variable)
                    variable->PushValue(string);

                if (before)
                if (0 < (length = before->GetLength()))
                if (0 <= (length = before->Seek(0)))
                    t.Expand(result, *before);

                if (!expr)
                    result.Write(string);
                else
                if (0 < (length = expr->GetLength()))
                if (0 <= (length = expr->Seek(0)))
                    t.Expand(result, *expr);

                if (after)
                if (0 < (length = after->GetLength()))
                if (0 <= (length = after->Seek(0)))
                    t.Expand(result, *after);

                if (variable)
                    variable->PopValue();
            }
        }
        return e_ERROR_NONE;
    }
} g_cRParseTFunction
  ("reverse-parse","reverse-parse(string,delim[,(before)[,(between)[,[(after),](expr),var]]])");

/**
 **********************************************************************
 *  Class: cToUpperTFunction
 *
 * Author: $author$
 *   Date: 8/15/2008
 **********************************************************************
 */
class cToUpperTFunction
: public cTFunction
{
public:
    typedef cTFunction cExtends;

    /**
     **********************************************************************
     * Constructor: cToUpperTFunction
     *
     *      Author: $author$
     *        Date: 8/15/2008
     **********************************************************************
     */
    cToUpperTFunction(const char* name, const char* description)
    : cExtends(name, description)
    {
        static cTFunctionParameter parameter[] 
        = {{"string,...","strings to upper"},
           {0,0}};
        m_parameters = (sizeof(parameter)/sizeof(cTFunctionParameter))-1;
        m_parameter = parameter;
    }
    /**
     **********************************************************************
     * Function: Expand
     *
     *   Author: $author$
     *     Date: 8/15/2008
     **********************************************************************
     */
    virtual eError Expand
    (cCharStreamInterface &result, cTInterface &t, 
     const cTFunctionArgumentList& arglist) const
    {
        TLENGTH length1;
        const char *buffer1;
        cTFunctionArgument *arg1;

        if ((arg1 = arglist.GetFirstItem()))
        do
        {
            if ((buffer1 = arg1->GetBuffer(length1)))
            while(length1>0)
            {
                result.Put(toupper(*buffer1));
                buffer1++;
                --length1;
            }
        }
        while((arg1 = arg1->GetNextItem()));
        return e_ERROR_NONE;
    }
} g_cToUpperTFunction
  ("toupper","toupper(string,...)");

/**
 **********************************************************************
 *  Class: cToLowerTFunction
 *
 * Author: $author$
 *   Date: 8/15/2008
 **********************************************************************
 */
class cToLowerTFunction
: public cTFunction
{
public:
    typedef cTFunction cExtends;

    /**
     **********************************************************************
     * Constructor: cToLowerTFunction
     *
     *      Author: $author$
     *        Date: 8/15/2008
     **********************************************************************
     */
    cToLowerTFunction(const char* name, const char* description)
    : cExtends(name, description)
    {
        static cTFunctionParameter parameter[] 
        = {{"string,...","strings to lower"},
           {0,0}};
        m_parameters = (sizeof(parameter)/sizeof(cTFunctionParameter))-1;
        m_parameter = parameter;
    }
    /**
     **********************************************************************
     * Function: Expand
     *
     *   Author: $author$
     *     Date: 8/15/2008
     **********************************************************************
     */
    virtual eError Expand
    (cCharStreamInterface &result, cTInterface &t, 
     const cTFunctionArgumentList& arglist) const
    {
        TLENGTH length1;
        const char *buffer1;
        cTFunctionArgument *arg1;

        if ((arg1 = arglist.GetFirstItem()))
        do
        {
            if ((buffer1 = arg1->GetBuffer(length1)))
            while(length1>0)
            {
                result.Put(tolower(*buffer1));
                buffer1++;
                --length1;
            }
        }
        while((arg1 = arg1->GetNextItem()));
        return e_ERROR_NONE;
    }
} g_cToLowerTFunction
  ("tolower","tolower(string,...)");

/**
 **********************************************************************
 *  Class: cLengthTFunction
 *
 * Author: $author$
 *   Date: 12/28/2008
 **********************************************************************
 */
class cLengthTFunction
: public cTFunction
{
public:
    typedef cTFunction cExtends;

    /**
     **********************************************************************
     * Constructor: cLengthTFunction
     *
     *      Author: $author$
     *        Date: 12/28/2008
     **********************************************************************
     */
    cLengthTFunction(const char* name, const char* description)
    : cExtends(name, description)
    {
        static cTFunctionParameter parameter[] 
        = {{"string,...","strings to get length of"},
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
        TLENGTH length = 0;
        TLENGTH length1;
        const char *buffer1;
        cTFunctionArgument *arg1;
        cString string;

        if ((arg1 = arglist.GetFirstItem()))
        do
        {
            if (0 <= (length1 = arg1->GetLength()))
                length += length1;
        }
        while((arg1 = arg1->GetNextItem()));

        if (0 <= (length1 = string.AssignSigned(length)))
        if ((buffer1 = string.Chars(length1)))
            result.Write(buffer1, length1);

        return e_ERROR_NONE;
    }
} g_cLengthTFunction
  ("length","length(string,...)"),
  g_cLengthTFunction2
  ("strlen","strlen(string,...)");

/**
 **********************************************************************
 *  Class: cPaddTFunction
 *
 * Author: $author$
 *   Date: 12/28/2008
 **********************************************************************
 */
class cPaddTFunction
: public cTFunction
{
public:
    typedef cTFunction cExtends;

    /**
     **********************************************************************
     * Constructor: cPaddTFunction
     *
     *      Author: $author$
     *        Date: 12/28/2008
     **********************************************************************
     */
    cPaddTFunction(const char* name, const char* description)
    : cExtends(name, description)
    {
        static cTFunctionParameter parameter[] 
        = {{"string,...","strings to padd"},
           {"padding","padding to use"},
           {"length","padded length"},
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
        const char *buffer;
        TLENGTH count,length,bufflen,padlen;
        cTFunctionArgument *arg,*strarg,*padarg,*lenarg;
        cDigitizer digits;

        if ((strarg = (arg = arglist.GetFirstItem())))
        if ((padarg = (arg = arg->GetNextItem())))
        if ((lenarg = (arg = arg->GetNextItem())))
        {
            length = 0;

            do
            {
                if ((buffer = strarg->GetBuffer(count)))
                if (0 < count)
                if (0 < (count = result.Write(buffer,count)))
                    length += count;

                if ((arg = arg->GetNextItem()))
                {
                    strarg = padarg;
                    padarg = lenarg;
                    lenarg = arg;
                }
            }
            while (arg);

            if ((buffer = lenarg->GetBuffer(bufflen)))
            if (0 < bufflen)
            if (0 < (padlen = digits.Signed(count, buffer, bufflen)))
            if (length < padlen)
            if ((buffer = padarg->GetBuffer(bufflen)))
            if (0 < bufflen)
            {
                if (bufflen > padlen)
                    bufflen = padlen;

                do
                {
                    if (0 >= (count = result.Write(buffer, bufflen)))
                        break;
                }
                while((length += count) < padlen);
            }
        }
        return e_ERROR_NONE;
    }
} g_cPaddTFunction
  ("padd","padd(string,...,padding,padlen)"),
  g_cPaddTFunction2
  ("strpad","strpad(string,...,padding,padlen)");

/**
 **********************************************************************
 *  Class: cReplaceTFunction
 *
 * Author: $author$
 *   Date: 12/16/2012
 **********************************************************************
 */
class cReplaceTFunction
: public cTFunction
{
public:
    typedef cTFunction cExtends;

    /**
     **********************************************************************
     * Constructor: cReplaceTFunction
     *
     *      Author: $author$
     *        Date: 12/16/2012
     **********************************************************************
     */
    cReplaceTFunction(const char* name, const char* description)
    : cExtends(name, description)
    {
        static cTFunctionParameter parameter[] = {
            {"from", "find from"},
            {"to", "replace with to"},
            {"string,...", "in string(s)"},
            {0,0}};
        m_parameters = (sizeof(parameter)/sizeof(cTFunctionParameter))-1;
        m_parameter = parameter;
    }
    /**
     **********************************************************************
     * Function: Expand
     *
     *   Author: $author$
     *     Date: 12/16/2012
     **********************************************************************
     */
    virtual eError Expand
    (cCharStreamInterface &result, cTInterface &t, 
     const cTFunctionArgumentList& arglist) const
    {
        cTFunctionArgument *from,*to,*arg;
        const char *fromChars,*toChars,*chars;
        TLENGTH fromLength,toLength,length;

        if ((from = arglist.GetFirstItem()))
        if ((fromChars = from->GetBuffer(fromLength)))
        if ((to = from->GetNextItem()))
        if ((toChars = to->GetBuffer(toLength)))
        if ((0 < fromLength) && (fromLength == toLength))
        if ((arg = to->GetNextItem()))
        {
            const char* found;
            int i;
            do
            {
                if ((chars = arg->GetBuffer(length)))
                if (0 < length)
                for (i = 0; i < length; i++)
                {
                    if ((found = strchr(fromChars, chars[i])))
                        result.Write(toChars+(found-fromChars), 1);
                    else result.Write(chars+i, 1);
                }
            }
            while((arg = arg->GetNextItem()));
        }
        return e_ERROR_NONE;
    }
} g_cReplaceTFunction("replace","replace(from,to,string,...)");

/**
 **********************************************************************
 *  Class: cReplaceStringTFunction
 *
 * Author: $author$
 *   Date: 2/3/2018
 **********************************************************************
 */
class cReplaceStringTFunction
: public cTFunction
{
public:
    typedef cTFunction cExtends;

    /**
     **********************************************************************
     * Constructor: cReplaceStringTFunction
     *
     *      Author: $author$
     *        Date: 2/3/2018
     **********************************************************************
     */
    cReplaceStringTFunction(const char* name, const char* description)
    : cExtends(name, description)
    {
        static cTFunctionParameter parameter[] = {
            {"from", "find from"},
            {"to", "replace with to"},
            {"string,...", "in string(s)"},
            {0,0}};
        m_parameters = (sizeof(parameter)/sizeof(cTFunctionParameter))-1;
        m_parameter = parameter;
    }
    /**
     **********************************************************************
     * Function: Expand
     *
     *   Author: $author$
     *     Date: 2/3/2018
     **********************************************************************
     */
    virtual eError Expand
    (cCharStreamInterface &result, cTInterface &t, 
     const cTFunctionArgumentList& arglist) const
    {
        cTFunctionArgument *from,*to,*arg;
        const char *fromChars,*toChars,*chars;
        TLENGTH foundLength,fromLength,toLength,length;

        if ((from = arglist.GetFirstItem()))
        if ((fromChars = from->GetBuffer(fromLength)))
        if ((to = from->GetNextItem()))
        if ((toChars = to->GetBuffer(toLength)))
        if ((0 < fromLength) && (fromLength == toLength))
        if ((arg = to->GetNextItem()))
        {
            const char* found = 0;
            int i = 0;
            do {
                if ((chars = arg->GetBuffer(length)) && (0 < length)) {
                    for (i = 0; i < length; ) {
                        if ((found = strstr(chars+i, fromChars))) {
                            result.Write(chars, foundLength = (found - chars));
                            result.Write(toChars, toLength);
                            i = foundLength + toLength;
                        } else {
                            result.Write(chars+i, length - i);
                            break;
                        }
                    }
                }
            } while ((arg = arg->GetNextItem()));
        }
        return e_ERROR_NONE;
    }
} g_cReplaceStringTFunction("replace-string","replace-string(from,to,string,...)");

/**
 **********************************************************************
 *  Class: cGetenvTFunction
 *
 * Author: $author$
 *   Date: 12/16/2012
 **********************************************************************
 */
class cGetenvTFunction
: public cTFunction
{
public:
    typedef cTFunction cExtends;

    /**
     **********************************************************************
     * Constructor: cGetenvTFunction
     *
     *      Author: $author$
     *        Date: 12/16/2012
     **********************************************************************
     */
    cGetenvTFunction(const char* name, const char* description)
    : cExtends(name, description)
    {
        static cTFunctionParameter parameter[] = {
            {"string,...", "environment variable name(s)"},
            {0,0}};
        m_parameters = (sizeof(parameter)/sizeof(cTFunctionParameter))-1;
        m_parameter = parameter;
    }
    /**
     **********************************************************************
     * Function: Expand
     *
     *   Author: $author$
     *     Date: 12/16/2012
     **********************************************************************
     */
    virtual eError Expand
    (cCharStreamInterface &result, cTInterface &t, 
     const cTFunctionArgumentList& arglist) const
    {
        cTFunctionArgument *arg;
        const char* chars;
        TLENGTH length;

        if ((arg = arglist.GetFirstItem()))
        {
            do
            {
                if ((chars = arg->GetBuffer(length)))
                if (0 < length)
                if ((chars = getenv(chars)))
                if ((chars[0]))
                    result.Write(chars);
            }
            while((arg = arg->GetNextItem()));
        }
        return e_ERROR_NONE;
    }
} g_cGetenvTFunction("getenv", "getenv(string,...)");
